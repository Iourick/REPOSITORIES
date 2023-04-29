//---------------------------------------------------------------------------


#pragma hdrstop
#include <vcl.h>
#include <float.h>
#include <dir.h>
#include "DiagrSet.h"
#include <math.h>
#include <string.h>
#include "Comp.h"
#include <stdio.h>
#include <stdlib.h>
#include "YrWriteShapeFile.h"
#include "URPolyLine.h"
#include "UrPointXY.h"
#include "Diagr.h"
#include "MatrixProccess.h"
#include "Gauss.h"


 TDiagrSet::~TDiagrSet()
{

 if(mpDiagr)
 {
	 free (mpDiagr);
 }
}
// ����������� �����������
TDiagrSet::TDiagrSet (const TDiagrSet &R2)
 {
 //
  mNumDiagr = R2.mNumDiagr;


  if (mpDiagr)
  {
   //	free (mpDiagr);
	mpDiagr = NULL;
  }
  if (R2.mpDiagr)
  {
   mpDiagr = (TDiagr*)malloc(mNumDiagr * sizeof(TDiagr));
   memcpy(mpDiagr, R2.mpDiagr, mNumDiagr * sizeof(TDiagr));
  }

 }

 // �������� ������������
 TDiagrSet TDiagrSet::operator=(TDiagrSet  R2)
{
 //
  mNumDiagr = R2.mNumDiagr;


  if (mpDiagr)
  {
	free (mpDiagr);
	mpDiagr = NULL;
  }
  if (R2.mpDiagr)
  {
   mpDiagr = (TDiagr*)malloc(mNumDiagr * sizeof(TDiagr));
   memcpy(mpDiagr, R2.mpDiagr, mNumDiagr * sizeof(TDiagr));
  }
	return *this ;
}

 TDiagrSet::TDiagrSet()
 {
   mNumDiagr = 0;
   mpDiagr = NULL;
 }
// ����� �����������
 TDiagrSet::TDiagrSet(const int NumDiagr, double *arrAlfaDiagr)
 {
  mNumDiagr =  NumDiagr;
  mpDiagr =  (TDiagr*)malloc(mNumDiagr * sizeof(TDiagr));
  for (int i =0; i < mNumDiagr; i++)
  {
   mpDiagr[i] = TDiagr(arrAlfaDiagr[i]) ;
  }
 }

 // ����� �����������2
 TDiagrSet::TDiagrSet(const int NumDiagr, TDiagr *pDiagr)
 {
  mNumDiagr =  NumDiagr;
  mpDiagr =  (TDiagr*)malloc(mNumDiagr * sizeof(TDiagr));
  for (int i =0; i < mNumDiagr; i++)
  {
   mpDiagr[i] = pDiagr[i] ;
  }
 }

 /// ������� ������ ��� ������� ���������� ������
 //INPUT:
 // pcmpSZv - ������ ��������� ��������, �����������
 // OUTPUT:
 // pZTarg - ����������� �����  ��������� ����
 // pZAnt -  ����������� �����  ��������� ��������
 // palfTrg - ���� ����
 // palfAnp -  ���� ��������
 int  _fastcall TDiagrSet::MMP_GroupRelax(TComp *pcmpSZv, TComp *pZTarg, TComp *pZAnt, double *palfTrg, double *palfAnp )
 {

  int ireturn = -3;
  double alfTargTemp = *palfTrg, alfAntTemp =*palfAnp;
  for (int i = 0; i < 1000; i++)
  {
	// ���������� ������������� ��������� ��� ������������� ����� ����� �������
	// 2 ����� ������� ���������������� ��� ����������� 2-�� �������

  if(! find_ZTarg_and_ZAnt( pcmpSZv, pZTarg, pZAnt, *palfTrg, *palfAnp ) )
  {
   return -3;
  }

	///

	int irez =  find_AlfTarg_and_AlfAnt( pcmpSZv, *pZTarg, *pZAnt, &alfTargTemp, &alfAntTemp  );

	 if (irez !=0)
	 {
	  return irez ;
	 }


		double del = sqrt((alfTargTemp - *palfTrg) * (alfTargTemp - *palfTrg) + (alfAntTemp -*palfAnp)* (alfAntTemp -*palfAnp));
		*palfTrg =alfTargTemp ;
		*palfAnp = alfAntTemp ;
	if (del< 0.00001)
	{
	 ireturn = 0;

	 break ;
	}

  }

  return ireturn;
}


 // ���������� ������� ������� ���
// INPUT:
// pcmpSZv   - ������ ��������� �� ���������� (����������� �����)
// cmpZ1  - ����������� ����������� ��������� ����
// cmpZ2  - ����������� ����������� ��������� ��������
// alfTrg - ���� ����� ����
// alfAnp - ���� ����� ��������
double  _fastcall TDiagrSet::calcFncObj_MMP(TComp *pcmpSZv,TComp cmpZTrg, TComp cmpZAnp, double alfTrg, double alfAnp )
{

 double valRez = 0.;
 for (int i =0; i < mNumDiagr; i++)
 {
   double valPartTemp =   mpDiagr[i].calcFncObjPartial_MMP(  pcmpSZv[i],  cmpZTrg,  cmpZAnp,  alfTrg,  alfAnp );
   valRez +=  valPartTemp ;
 }
return valRez;
}


// ���������� ����������� ������������ ���������  ���� � �������� ��� ������������� �����
// ��������� ���� � ��������
// ��� ������������� �����
// INPUT:
// pcmpSZv   - ������ ��������� �� ���������� (����������� �����)
// alfTrg- ���� ����� ����  � ��������
// alfAnp - ���� ����� �������� � ��������

// OUTPUT:
// *pZTarg -  ����������� ��������� ����
// *pZAnt   - ����������� ���������  ��������
// ����������:
//  -1 - ���� �-�� �������� quantDiagr< 3
// -2 - ����� ������� ����� ���������
// -3 - ���� ����� �� �������
bool  _fastcall TDiagrSet::find_ZTarg_and_ZAnt( TComp *pcmpSZv, TComp *pZTarg, TComp *pZAnp, double alfTrg, double alfAnp )
{
// ���������� ������������� ��������� ��� ������������� �����
	// 2 ����� ������� ���������������� ��� ����������� 2-�� �������
	double arrZ[4] ={0.};

	double arrAATSum[16] ={0.}, arrAATCur[16] ={0.}, arrATSSum[4]={0.}, arrATSCur[4]={0.}, arrT0[16] ={0.}
	, arrT1[4]={0.}, arrAATSumInv[16]={0.};
	for (int i =0; i < mNumDiagr; i++)
	{
	 mpDiagr[i].calc_ATA_andATS(pcmpSZv[i], alfTrg,  alfAnp, arrAATCur, arrATSCur );
	 MtrxSumMatrx(arrAATSum, arrAATCur,4, 4, arrT0) ;
	 memcpy(arrAATSum,arrT0, 16 * sizeof(double));
	 MtrxSumMatrx(arrATSSum, arrATSCur,4, 1, arrT1) ;
	 memcpy(arrATSSum,arrT1, 4 * sizeof(double));

	}
  if(!	InverseMtrx4(arrAATSum, arrAATSumInv)) return false ;
  MtrxMultMatrx(arrAATSumInv,4, 4, arrATSSum ,1, arrZ) ;
  (*pZTarg).m_Re = arrZ[0] ;
  (*pZTarg).m_Im = arrZ[1] ;
  (*pZAnp).m_Re = arrZ[2] ;
  (*pZAnp).m_Im = arrZ[3] ;
	return true;
}
// ���������� ����������� ����� ���� � �������� ��� ������������� ������� ���������
// ��� ������������� �����
// INPUT:
// pcmpSZv   - ������ ��������� �� ���������� (����������� �����)
// ZTarg -  ����������� ��������� ����
// ZAnt   - ����������� ���������  ��������
// *alfTrg  - �� ����
// *alfAnp  - �� ��������
// OUTPUT:
// arrMilradAngles[0] - ���� ����� ����   � ��������
// arrMilradAngles[1]  - ���� ����� �������� � ������������
// ����������:
//  -1 - ���� �-�� �������� quantDiagr< 3
// -2 - ����� ������� ����� ���������
// -3 - ���� ����� �� �������
// ZTarg
// ZAnt
int  _fastcall TDiagrSet::find_AlfTarg_and_AlfAnt( TComp *pcmpSZv, TComp ZTarg, TComp ZAnt, double *alfTrg, double *alfAnp )
{
  int i = 0;
  double arr_FGreek[2] ={0.},arr_dFGreek[4] ={0.},arr_dFGreekInv[4] ={0.} ;
  double arrX[2] ={0.}, arrXT[2] ={0.}; // ������ � ���������
  arrX[0] = *alfTrg ;
  arrX[1] = *alfAnp;
  double del = -2.;

  for (i = 0; i < 100; i++)
  {

	double arr_F00[2] ={0.},arr_dF00[4] ={0.}, arrDelX[2] ={0.} ;

	calc_F_and_dF_po_dAlf ( pcmpSZv, ZTarg,  ZAnt, arrX[0], arrX[1] , arr_FGreek, arr_dFGreek ) ;
	///
	double temp0 = arr_dFGreek[0]/ 1000000. * arr_dFGreek[3]/ 1000000. - arr_dFGreek[1]/ 1000000. * arr_dFGreek[2]/ 1000000.;

	////
	if(!InverseMtrx2(arr_dFGreek, arr_dFGreekInv))
	{
     *alfTrg = arrX[0]   ;
	 *alfAnp = arrX[1]  ;
	 return -2;
	}
	MtrxMultMatrx(arr_dFGreekInv ,2, 2, arr_FGreek,1, arrDelX) ;
	del = NormVect(arrDelX, 2);
	double arrT[2] ={0.};
	MtrxMinusMatrx(arrX, arrDelX,1, 2, arrXT) ;
	memcpy( arrX, arrXT, 2 * sizeof(double));
	if (del< 0.000001)
	{

	  *alfTrg = arrX[0]   ;
	  *alfAnp = arrX[1]  ;
	  return 0;
	}
 }

  return -3;
}

void  _fastcall TDiagrSet::calc_F_and_dF_po_dAlf ( TComp *pcmpSZv, TComp ZTarg, TComp ZAnt
, double alfTrg, double alfAnp, double* arr_FGreek,double* arr_dFGreek )
{
	double arr_Part_F[2] ={0.},arr_Part_dF[4] ={0.}, arrT[2]={0.}, arrT1[4]={0.};
	memset(arr_FGreek, 0, 2 * sizeof(double));
	memset(arr_dFGreek , 0, 4 * sizeof(double));
	for (int i =0; i < mNumDiagr; i++)
	{
	 mpDiagr[i].calcPartial_F_and_dF_po_dAlf(pcmpSZv[i], ZTarg,  ZAnt
		, alfTrg, alfAnp , arr_Part_F, arr_Part_dF ) ;
	 MtrxSumMatrx(arr_FGreek, arr_Part_F,1, 2, arrT) ;
	 memcpy(arr_FGreek,arrT, 2 * sizeof(double));
	 MtrxSumMatrx(arr_dFGreek, arr_Part_dF,2, 2, arrT1) ;
	 memcpy(arr_dFGreek,arrT1, 4 * sizeof(double));

	}
}


/// ������� ������ ��� ������� �������
// ������������ �������� ��������� ����� ������� �������� �������� ���������
// ����� ����� ������ ��������� � ������� �������� 2-� ���������� ���������
// ������������  palfTrg  � palfAnp
// ������� ����� �������������� ���������� �������, ��� ������ �� ������ ����������
// palfTrg  � palfAnp ������ ���������� � ������� ����������� ����������� ����������� �������
 //INPUT:
 // pcmpSZv - ������ ��������� ��������, �����������
 // palfTrg  � palfAnp - ��������� ������������ ���� ���� � ��������
 // OUTPUT:
 // pZTarg - ����������� �����  ��������� ����
 // pZAnt -  ����������� �����  ��������� ��������
 // palfTrg - ���� ����
 // palfAnp -  ���� ��������
 int  _fastcall TDiagrSet::solvNewtonMeth_Razn(const double valSigNoise,TComp *pcmpSZv, TComp *pZTarg, TComp *pZAnt
	   , double *palfTrg, double *palfAnp, double *arrMtrxCorr )
 {

  int breturn = -3;
  int i = 0;
  double arr_FGreek[2] ={0.},arr_dFGreek[4] ={0.},arr_dFGreekInv[4] ={0.} ;
  double arrX[2] ={0.}, arrXT[2] ={0.}; // ������ � ���������
  arrX[0] = *palfTrg ;
  arrX[1] = *palfAnp;
  double del = -2.;

  for (i = 0; i < 100; i++)
  {

	double arr_F00[2] ={0.},arr_dF00[4] ={0.}, arrDelX[2] ={0.}, arrDelX1[2] ={0.} ;

	calc_vectG_and_mtrxH_NewtonMeth_Razn (pcmpSZv
		,  arrX[0], arrX[1], arr_FGreek,  arr_dFGreek, pZTarg, pZAnt   ) ;
		 //	 �������� ������� ������� ��� �������!!!
		double parrRez[4] ={0.}, parrRez1[4] ={0.};
		MatrxMultScalar(arr_dFGreek, 2, 2, 0.000001,parrRez);
		double valPos = arr_dFGreek[0] *arr_dFGreek[3] - arr_dFGreek[1] * arr_dFGreek[2];
		if (!((arr_dFGreek[0] > 0.)&&(valPos > 0.)))
		{
		 breturn = -3;
		 break;
		}
	///

   //	if(!InverseMtrx2(parrRez, parrRez1))
	if(!InverseMtrx2(arr_dFGreek, arr_dFGreekInv))
	{
	 *palfTrg = arrX[0]   ;
	 *palfAnp = arrX[1]  ;
	 breturn = -2;
	 break;
	}
   //	MatrxMultScalar(parrRez1, 2, 2, 1000000.,arr_dFGreekInv);
	MtrxMultMatrx(arr_dFGreekInv ,2, 2, arr_FGreek,1, arrDelX) ;
	del = NormVect(arrDelX, 2);
	double arrT[2] ={0.};
  //	MatrxMultScalar(arrDelX, 2, 1, 0.1,arrDelX1);
	MatrxMultScalar(arrDelX, 2, 1, 0.2,arrDelX1);
	memcpy( arrDelX, arrDelX1, 2 * sizeof(double));
	MtrxMinusMatrx(arrX, arrDelX,1, 2, arrXT) ;
	memcpy( arrX, arrXT, 2 * sizeof(double));
	if (del< 0.00001 )
	{

	  *palfTrg = arrX[0]   ;
	  *palfAnp = arrX[1]  ;
	  //calcMtrxCorrel(valSigNoise, *palfTrg, *palfAnp, *pZTarg,  *pZAnt, arr_dFGreekInv, arrMtrxCorr);
	  calcMtrxCorrel_Mistake(valSigNoise, *palfTrg, *palfAnp, *pZTarg,  *pZAnt, arr_dFGreekInv, arrMtrxCorr);
	  breturn= 0;
	  break;
	}
 }

  return breturn;

}


/// ������� ������ ��� ������� �������  � ��������� �� ��������� ��������  �� ����
// ������������� ��������
// valXMax - ������������ �������� �� ���� (���),
// valStepX - ��� ��������  (���)
 //INPUT:
 // pcmpSZv - ������ ��������� ��������, �����������
 // valXMax - ������������ �������� �� ���� (���),
// valStepX - ��� ��������  (���)
 // valSigNoise - ��� ����
 // OUTPUT:
 // pZTarg - ����������� �����  ��������� ����
 // pZAnt -  ����������� �����  ��������� ��������
 // palfTrg - ���� ����
 // palfAnp -  ���� ��������
 // arrMtrxCorr[4] - ������� ������� ������ ���������� ����� ���� � ��������
 int  _fastcall TDiagrSet::solvNewtonMeth_RaznPerebor(const double valSigNoise
  , const double valXMax,const double valStepX, TComp *pcmpSZv, TComp *pZTarg, TComp *pZAnt
	   , double *palfTrg, double *palfAnp, double *arrMtrxCorr )
 {
  int breturn = -3;

  const int iN = valXMax/ valStepX;
  TComp cmpZTargTemp(0.,0.), cmpZAntTemp(0.,0.);
  double alfTrgTemp = 0., alfAnpTemp = 0., arrMtrxCorrTemp[4] ={0.};
  double objMin = 1000000000.;

  for ( int i = 0; i < iN; i++)
  {
  alfTrgTemp = ((double)i) *  valStepX;
  alfAnpTemp =  -alfTrgTemp ;
  int irez = solvNewtonMeth_Razn( valSigNoise, pcmpSZv,& cmpZTargTemp, &cmpZAntTemp
	   , &alfTrgTemp, &alfAnpTemp, arrMtrxCorrTemp );

  if (irez != 0) continue;
  breturn  =irez;
  double objTemp = calcFncObj_MMP(pcmpSZv,cmpZTargTemp, cmpZAntTemp , alfTrgTemp, alfAnpTemp);
  if (objTemp < objMin)
  {
	*pZTarg =  cmpZTargTemp   ;
	*pZAnt = cmpZAntTemp;
	*palfTrg = alfTrgTemp;
	*palfAnp = alfAnpTemp ;
	memcpy(arrMtrxCorr , arrMtrxCorrTemp, 4 * sizeof(double));
	objMin = objTemp ;

  }
  }

  return breturn;

}



/// ������� ������ ��� �������  ��������  �� ����� iQUANT_STEPSxiQUANT_STEPS �� ����� ���� � ��������
// ��� 4-� ��������� ��������
 //INPUT:
 // iQUANT_STEPS - ����� ��������� �� ������ ����������
 // pcmpSZv - ������ ��������� ��������, �����������
 // valSigNoise - ��� ����
 // OUTPUT:
 // pZTarg - ����������� �����  ��������� ����
 // pZAnt -  ����������� �����  ��������� ��������
 // palfTrg - ���� ����
 // palfAnp -  ���� ��������
 // arrMtrxCorr[4] - ������� ������� ������ ���������� ����� ���� � ��������
 // parrObj[iQUANT_STEPS *iQUANT_STEPS] - ������ �������� ������� �������
 // *pvalMinObj - ������� ������� �������������
 int  _fastcall TDiagrSet::solveMinMMP_Perebor_Na_Setke(const double valSigNoise
  , const int iQUANT_STEPS, TComp *pcmpSZv, TComp *pZTarg, TComp *pZAnt
	   , double *palfTrg, double *palfAnp, double *arrMtrxCorr, double *parrObj , double *pvalMinObj )
 {
  if(mNumDiagr != 4) return -3;
  // ������ �������� �� � ���� �������� (���� ���������)
  const double VAL_Width = mpDiagr[0].mFar.mLambda / mpDiagr[0].mFar.mFaceta.m_n/  mpDiagr[0].mFar.mFaceta.m_d;

  const double VALNu =  2.* M_PI* mpDiagr[0].mFar.m_D / mpDiagr[0].mFar.mLambda ;
  const double VALDiapazon = VALNu * sin(VAL_Width);
  const double VALStep = 2. * VALDiapazon / ((double)iQUANT_STEPS - 1.);// ��� �� ���������� �����
  double valMu0 = -VALDiapazon; // ���� ���� ����
  double valMu1 = -VALDiapazon; // ���� ���� ��������

  TComp cmpZTargTemp(0.,0.), cmpZAntTemp(0.,0.);
  double alfTrgTemp = 0., alfAnpTemp = 0., arrMtrxCorrTemp[4] ={0.};
  double objMin = 1000000000.;

  for ( int i = 0; i < iQUANT_STEPS; i++)
  for ( int j =0; j < iQUANT_STEPS; j++)
  {
	valMu0 = -VALDiapazon + ((double)i) * VALStep;
	valMu1 = -VALDiapazon + ((double)j) * VALStep;
	double temp0 = valMu0 /VALNu;
	if (temp0 < -0.99999999999) temp0 = -0.99999999999;
	if (temp0 > 0.99999999999) temp0 = 0.99999999999;
	double alfTrg = asin( temp0);

	double temp1 = valMu1 /VALNu;
	if (temp1 < -0.99999999999) temp1= -0.99999999999;
	if (temp1 > 0.99999999999) temp1 = 0.99999999999;
	double alfAnp  = asin( temp1);
	TComp cmpZTrg;
	TComp cmpZAnp ;
	find_ZTarg_and_ZAnt(pcmpSZv, &cmpZTrg, &cmpZAnp , alfTrg,  alfAnp );
	parrObj[ i * iQUANT_STEPS + j] =  calcFncObj_MMP(pcmpSZv, cmpZTrg,  cmpZAnp,  alfTrg,  alfAnp );
  }
  int inum = -1;
  *pvalMinObj = dblArrMin( parrObj,iQUANT_STEPS * iQUANT_STEPS, &inum) ;
  int i0 =  inum/iQUANT_STEPS;
  int j0 =  inum % iQUANT_STEPS;
  valMu0 = -VALDiapazon + ((double)i0) * VALStep;
  valMu1 = -VALDiapazon + ((double)j0) * VALStep;
  double temp0 = valMu0 /VALNu;
	if (temp0 < -0.99999999999) temp0 = -0.99999999999;
	if (temp0 > 0.99999999999) temp0 = 0.99999999999;
	*palfTrg = asin( temp0);

	double temp1 = valMu1 /VALNu;
	if (temp1 < -0.99999999999) temp1= -0.99999999999;
	if (temp1 > 0.99999999999) temp1 = 0.99999999999;
	*palfAnp  = asin( temp1);

   find_ZTarg_and_ZAnt(pcmpSZv, pZTarg, pZAnt ,*palfTrg,  *palfAnp );

   /// ������� ������ ��� ������� �������
// ������������ �������� ��������� ����� ������� �������� �������� ���������
// ����� ����� ������ ��������� � ������� �������� 2-� ���������� ���������
// ������������  palfTrg  � palfAnp
// ������� ����� �������������� ���������� �������, ��� ������ �� ������ ����������
// palfTrg  � palfAnp ������ ���������� � ������� ����������� ����������� ����������� �������
 //INPUT:
 // pcmpSZv - ������ ��������� ��������, �����������
 // palfTrg  � palfAnp - ��������� ������������ ���� ���� � ��������
 // OUTPUT:
 // pZTarg - ����������� �����  ��������� ����
 // pZAnt -  ����������� �����  ��������� ��������
 // palfTrg - ���� ����
 // palfAnp -  ���� ��������
 solvNewtonMeth_Razn(valSigNoise,pcmpSZv, pZTarg, pZAnt
   	   , palfTrg, palfAnp, arrMtrxCorr ) ;

  return 0;

}

double  _fastcall TDiagrSet::dblArrMin( double *arr,const int LENArr, int *pinum)
{
	double valreturn =  DBL_MAX;

	*pinum = -1;
	for (int i = 0; i < LENArr; i++)
	{
	  if (arr[i] < valreturn )
	  {
		valreturn =  arr[i];
		*pinum = i;

	  }
	}
	return valreturn;
}

// ���������� �������������� ������� ������ ���������� �� ���� � � ��������
// INPUT:
// alfTrg - �� ����
// alfAnp - �� ��������
// cmpZTarg - ����� ��������� ����
// cmpZAnt  - ����� ��������� ��������
// arr_dFGreekInv[4] - ������� ����� � ����� (alfTrg, alfAnp )
// OUTPUT:
// arrMtrxCorr[4] - �������������� �������
//
void  _fastcall TDiagrSet::calcMtrxCorrel(const double valSigNoise,const double alfTrg, const double alfAnp
  , const TComp cmpZTarg,const TComp cmpZAnt,double* arr_dFGreekInv,double* arrMtrxCorr)
{
   // ���������� ����� ������ HR
   double *parrHsRSum = new double [mpDiagr[0].mFar.m_N  * 4];
   memset(parrHsRSum, 0, mpDiagr[0].mFar.m_N  * 4 * sizeof(double));
   double *parrHsRTemp = new double [mpDiagr[0].mFar.m_N * 4];
   double *parrHsRTemp1 = new double [mpDiagr[0].mFar.m_N * 4];
   double *parrTemp2 = new double [mpDiagr[0].mFar.m_N * 4];
   double *parrTemp3 = new double [mpDiagr[0].mFar.m_N * 4];
   for (int j = 0; j < mNumDiagr; j++)
   {
	 mpDiagr[j].calcMtrxHR( alfTrg,  alfAnp,  cmpZTarg, cmpZAnt,parrHsRTemp) ;
	 MtrxSumMatrx(parrHsRTemp, parrHsRSum,mpDiagr[0].mFar.m_N  * 4, 1, parrHsRTemp1) ;
	 memcpy(parrHsRSum, parrHsRTemp1, sizeof(double) *mpDiagr[0].mFar.m_N  * 4  );
   }
   ///

   // ��������� ����� �� �������  arr_dFGreekInv
	MtrxMultMatrx(arr_dFGreekInv,2, 2, parrHsRSum, mpDiagr[0].mFar.m_N * 2, parrTemp2) ;
	///

	//
	memcpy(parrTemp3, parrTemp2,  mpDiagr[0].mFar.m_N  * 4 * sizeof(double));
	///
	double arrRez0[4] ={0.};
	MtrxMultMatrxTransp(parrTemp2,2, mpDiagr[0].mFar.m_N * 2, parrTemp3, 2 , arrRez0) ;
	MatrxMultScalar(arrRez0, 2, 2, valSigNoise * valSigNoise, arrMtrxCorr);

   delete parrHsRTemp;
   delete parrHsRSum;
   delete parrHsRTemp1;
   delete parrTemp2 ;
   delete parrTemp3 ;
}

// ���������� �������������� ������� ������ ���������� �� ���� � � ��������
// �������, ��� ������ �������� ��������������� ����� �����
// INPUT:
// alfTrg - �� ����
// alfAnp - �� ��������
// cmpZTarg - ����� ��������� ����
// cmpZAnt  - ����� ��������� ��������
// arr_dFGreekInv[4] - ������� ����� � ����� (alfTrg, alfAnp )
// OUTPUT:
// arrMtrxCorr[4] - �������������� �������
//
void  _fastcall TDiagrSet::calcMtrxCorrel_Mistake(const double valSigNoise,const double alfTrg, const double alfAnp
  , const TComp cmpZTarg,const TComp cmpZAnt,double* arr_dFGreekInv,double* arrMtrxCorr)
{
   // ���������� ����� ������ HR
	double arrHs[4] = {0.}, arrT0[4] = {0.}, arrT1[4] = {0.}, arrT2[4] = {0.}, arrSum[4] = {0.};
   for (int j = 0; j < mNumDiagr; j++)
   {
	 mpDiagr[j].calcMtrxHs( alfTrg,  alfAnp,  cmpZTarg, cmpZAnt,arrHs) ;
	 memcpy(arrT0, arrHs, 4 * sizeof(double));
	 MtrxMultMatrxTransp(arrHs,2,  2, arrT0, 2 , arrT1 );
	 MtrxSumMatrx(arrSum, arrT1,2, 2 , arrT2) ;
	 memcpy(arrSum, arrT2, sizeof(double) * 4  );
   }
   ///

   // ��������� ����� �� �������  arr_dFGreekInv
	MtrxMultMatrx(arr_dFGreekInv,2, 2, arrSum,  2, arrT2) ;
	MtrxMultMatrxTransp( arrT2,2,  2, arr_dFGreekInv, 2 , arrT1) ;
	MatrxMultScalar( arrT1, 2, 2, valSigNoise * valSigNoise, arrMtrxCorr);
}

//--------------------------------------------------------------------
int  _fastcall TDiagrSet::calc_vectG_and_mtrxH_NewtonMeth_Razn (TComp *pcmpSZv, double alfTrg, double alfAnp
		,double* arr_FGreek, double*  arr_dFGreek , TComp*  pcmpZTarg,TComp* pcmpZAnp  )
 {

	 calc_vectF_from_Alfa( pcmpSZv,  alfTrg, alfAnp,  arr_FGreek, pcmpZTarg, pcmpZAnp  );
	 double delt = 0.0000001;
	 double arr_FGreekTemp[2] ={0.}, arrT0[2] ={0.};
	 TComp cmpZTarg0(0.,0.), cmpZAnp0(0.,0.);
	 calc_vectF_from_Alfa( pcmpSZv,  alfTrg + delt, alfAnp,  arr_FGreekTemp ,&cmpZTarg0, &cmpZAnp0  );
	 MtrxMinusMatrx(arr_FGreekTemp , arr_FGreek, 1, 2, arrT0);
	 MatrxDivideScalar(arrT0, 1, 2, delt,arr_dFGreek);

	 calc_vectF_from_Alfa( pcmpSZv,  alfTrg , alfAnp + delt,  arr_FGreekTemp ,&cmpZTarg0, &cmpZAnp0  );
	 MtrxMinusMatrx(arr_FGreekTemp , arr_FGreek, 1, 2, arrT0);
	 MatrxDivideScalar(arrT0, 1, 2, delt,&arr_dFGreek[2]);
	 arr_dFGreek [2] =arr_dFGreek [1] ;
	 return 0;
 }


void  _fastcall TDiagrSet::calc_vectF_from_Alfa( TComp *pcmpSZv, double alfTrg, double alfAnp
  ,double* arr_FGreek, TComp*  pcmpZTarg,TComp* pcmpZAnp  )
{
  // TComp cmpZTarg(0.,0.), cmpZAnp (0.,0.);
  find_ZTarg_and_ZAnt( pcmpSZv, pcmpZTarg, pcmpZAnp,  alfTrg,  alfAnp );

  double arr_dFGreek[4] ={0.}; // ����� �� �������������
  calc_F_and_dF_po_dAlf ( pcmpSZv, *pcmpZTarg, *pcmpZAnp,  alfTrg,  alfAnp
	  ,  arr_FGreek, arr_dFGreek );
}

// �������� ���������
// INPUT:
//valNoiseSkz  - ��� ����
// alfTrg - �.�. ����, ���
// alfAnp - �.�. ��������, ���
// cmpZTarg - ������� ��������� ����
// cmpZAnt - ������� ��������� ��������
// OUTPUT:
// pcmpS - ������ ��������� �������
// pcmpSZv - ������ ���������

void  _fastcall TDiagrSet::imitateMeasures( TComp *pcmpS,TComp *pcmpSZv, double alfTrg, double alfAnp
  ,TComp cmpZTarg, TComp cmpZAnt,double valNoiseSkz )
{
	for (int i =0; i < mNumDiagr ; i++)
	{
	  TComp cmpF1 = mpDiagr[i].fncF(alfTrg);
	  TComp cmpF2 = mpDiagr[i].fncF(alfAnp);
	  pcmpS[i] = cmpZTarg * cmpF1 +  cmpZAnt * cmpF2 ;
	  pcmpSZv[i].m_Re = pcmpS[i].m_Re +  getGauss(0., valNoiseSkz/sqrt(2.) );
	  pcmpSZv[i].m_Im = pcmpS[i].m_Im +  getGauss(0., valNoiseSkz/sqrt(2.) );

	}

}


void  _fastcall TDiagrSet::createDiagrGraphs(wchar_t *wchFoldName1 )
{

	wchar_t wchFoldName[300] ={0};
	wcscpy(  wchFoldName,  wchFoldName1);
	wcscat(wchFoldName, L"\\");
	for (int i =0; i <  mNumDiagr; i++)
	{
	 wchar_t wchFoldNameTemp[300] ={0};
	 wcscpy(  wchFoldNameTemp,  wchFoldName);
	 String s_22 = wchFoldNameTemp;
	 s_22 += L"GraphDiagr_";
	 s_22 += i;
	 _wmkdir(s_22.w_str()) ;
	 mpDiagr[i].createDiagrGraphs(s_22.w_str()) ;
	}
   /*	double step = M_PI / 3000./ 10.;
	const int nBuffRows = 1500 *2;
	const int nBuffCols = 8;
	double  *parrBuff = new double [nBuffRows  * nBuffCols] ;
	memset(parrBuff, 0, nBuffRows * nBuffCols * sizeof(double));

	const int lenName = 30;
	wchar_t wcharrFileNames [240] ={0};
	wcscpy( wcharrFileNames, L"Tetta");
	wcscpy( &wcharrFileNames[30], L"ModF");
	wcscpy( &wcharrFileNames[60], L"F_Re");
	wcscpy( &wcharrFileNames[90], L"F_Im");

	wcscpy( &wcharrFileNames[120], L"dF_Re");
	wcscpy( &wcharrFileNames[150], L"dF_Im");
	wcscpy( &wcharrFileNames[180], L"d2F_Re");
	wcscpy( &wcharrFileNames[210], L"d2F_Im");
  for (int i=0 ; i < nBuffRows; i++)
  {
   double tet = step * ((double) (-nBuffRows/2 +i));
   parrBuff[ i * nBuffCols] = tet ;

   TComp cmp = fncF( tet);
   TComp cmp1 = dF_po_dTet( tet);
   TComp cmp2 = d2F_po_dTet2( tet);
   parrBuff[ i * nBuffCols + 1]= cmp.modul();
   parrBuff[ i * nBuffCols + 2]= cmp.m_Re;
   parrBuff[ i * nBuffCols + 3]= cmp.m_Im;

   parrBuff[ i * nBuffCols + 4]= cmp1.m_Re;
   parrBuff[ i * nBuffCols + 5]= cmp1.m_Im;
   parrBuff[ i * nBuffCols + 6]= cmp2.m_Re;
   parrBuff[ i * nBuffCols + 7]= cmp2.m_Im;

  }

 // double scalex = 100.;
  double *pscaley = new double [nBuffCols] ;
  pscaley[0] = 100.;
  pscaley[1] = 100.;
  pscaley[2] = 100.;
  pscaley[3] = 100.;
  pscaley[4] = 1.;
  pscaley[5] = 1.;
  pscaley[6] = 0.1;
  pscaley[7] = 0.1;
  for (int i=1; i < nBuffCols; i++)
  {

  TYrWriteShapeFile::WriteOneReport(                 wchFoldName  // ���� � �����
								  , parrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  , nBuffCols // - �-�� ���������� � ������� ��������� ���������� � ������
								  , nBuffRows //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,lenName // ������������ ����� ����� ����������
								  ,0  // ����� ���������� �� ��� X
								  ,i  // ����� ���������� �� ��� Y
								  ,1000. //  ������� �� ��� X
								  ,pscaley[i]// ������� �� ��� Y
								   ) ;
  }

	delete parrBuff;
	delete pscaley;
	wchar_t wchAxesFileName[300] ={0};
	wcscpy(  wchAxesFileName,  wchFoldName);
	wcscat(wchAxesFileName, L"AxesArr.shp");
	TYrWriteShapeFile::CreateShpArrowedAxes(wchAxesFileName,-150., 150.
	 ,-pscaley[0] * 1.1,pscaley[0] * 1.1, 50000.*step) ;
	TURPointXY pPoints[2];
	pPoints[0] =  TURPointXY (-100., pscaley[0]* sqrt(2.)/2.);
	pPoints[1] =  TURPointXY (100., pscaley[0] * sqrt(2.)/2.);
	TURPolyLine pln( pPoints,2) ;

	wcscpy(  wchAxesFileName,  wchFoldName);
	wcscat(wchAxesFileName, L"Line0.shp");
	TURPolyLine::WriteSetSHPFiles(wchAxesFileName,&pln, 1) ;
	*/
 }


double  _fastcall SIGN__(double a)
{
	return (a > 0.)?1:-1;
}

#pragma package(smart_init)
