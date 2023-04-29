//---------------------------------------------------------------------------


#pragma hdrstop

#include "CoatTargNeibourhood.h"
#include <string.h>
#include <math.h>
#include <float.h>
#include "MatrixProccess.h"
#include "Detonator.h"
#include "Gauss.h"
#include "CalcCorMatrx.h"
#include "YrRastr.h"
#include "Gauss.h"
#include "URPolygon.h"
#include "URPointXY.h"
#include "ProbabilityTheory.h"
#include "GameTheory.h"
#include "Fight.h"
#include "LinOptimization.h"


//-------------------------------------------------------------------------
// ��������� ����������� �� ������������ �������� ����� ������������
// ����   �������������� ������ ������������ ����� ������������� �� ����� ������
// INPUT:
// parrMtrxCorr[4] -������� ������� ������  ���������  �����  ������� � �������� ��������� ���� (��� X ��������� � ������, �� ������� ����������� �����)
// VAlKillingRange  - ������ ���������
// QUantShells  - �-�� ���������
// In - �-�� ����� ����� �� ������ ������������
// parrTargX [LEnarrX] -  ������ ����� ���� �� ��� X �������� ��������� ����
// OUTPUT:
//  parrAimingPoints [mQuantShells]-  ������ ��������� ����� ������������ �� ��� X � ������� ��������� ����
//  piarrRepeatQuants [mQuantShells] - ������ ���������� ����� ������������ �� ��� X
//  *pQuantAimingPoints- �- �� ��������� ����� ������������ �� ��� X
//  ppntArrAimingPoints_SKT[mQuantShells]-  ������ ��������� ����� ������������ � �������� ��������� ����
// ��� �������� parrAimingPoints,  piarrRepeatQuants �  ppntArrAimingPoints ������ ���� ��������������� ������������  ������
//  mQuantShells, �� �� ����������� ������ ���������, ��������� ���������� ���� ��������
//  ����� �������� ������ *pQuantAimingPoints ���������
//  *pvalProb - ����������� ���������
void TCoastTargNeighbourhood::calcOptimalDestructionProb_For_GroupLinedPoints (const int  QAantIspit, double *parrMtrxCorr
	,const double VAlKillingRange, const int QUantShells,const int  In, double *parrTargX, const int LEnarrX
	, double *parrAimingPoints, int *piarrRepeatQuants, int *pQuantAimingPoints, TURPointXY *ppntArrAimingPoints_SKT
	, double *pvalProb, TURPointXY *pPntArrDensity)
{
	double valObj= -1.;

	calcOptimalArray_Of_AimPoints_ForGroupLinedPoints( parrMtrxCorr
	, VAlKillingRange, QUantShells, In, parrTargX,  LEnarrX
	, parrAimingPoints, piarrRepeatQuants, pQuantAimingPoints, valObj, pPntArrDensity );


	*pvalProb =  ((double)LEnarrX -  valObj)/ ((double)LEnarrX);






	 //		for (int i = 0; i < QUantShells; i++)
	 //	{
	//		ppntArrCorrecting[i] = ppntArrCorrecting[i].LinTransform(valRotateAng,pntSdvig, valRastigenie ) ;
 //		}
	 //	 ppntArrCorrecting[0].WriteSetSHPFiles(L"E:\\Ametist\\22-02-2018\\NEW\\ppntArrCorrecting_GSK.shp", ppntArrCorrecting,QUantShells);

	///


	double arrF[4] = {0.} , arrMtrxLamb[4] = {0.};
	 CalcProperVectors2(parrMtrxCorr, arrF , arrMtrxLamb) ;
	///
	double valProbSum = 0.;
	for (int i =0; i < (*pQuantAimingPoints); i++ )
	{
		ppntArrAimingPoints_SKT[i].X = parrAimingPoints[i];
		ppntArrAimingPoints_SKT[i].Y = 0.;
	}
	///
	/*
	int *piarrSuccess = new int [LEnarrX];
		double valSum = 0.;
	for (int i =0; i < QAantIspit; i++)
	{
		memset(piarrSuccess, 0, LEnarrX * sizeof(int));

	 //	rastrTarg.WriteMeAsFltFile(L"E:\\PROJECTS_C++\\TARAN\\New\\rastrTarg.flt"); //!!!!!
	//	ppntArrCorrecting[0].WriteSetSHPFiles(L"E:\\PROJECTS_C++\\TARAN\\New\\ppntArrCorrecting.shp", ppntArrCorrecting,QUantShells);
	//	plgTarg0.WriteSetSHPFiles(L"E:\\PROJECTS_C++\\TARAN\\New\\plgTarg01.shp", &plgTarg0,1); //!!!!!


		for (int j = 0; j < (*pQuantAimingPoints); j++)
		{


			// ����������� ������� �������� � ������������� �������� � ����
			double  arrPos_GSK[2] = {0.};
			double arrCorrecting [2] = {0.};
			arrCorrecting [0] = parrAimingPoints[j];
			arrCorrecting [1] = 0.;
			for (int m =0; m < piarrRepeatQuants[j]; m++)
			{

			getGaussVector(2,  arrCorrecting, arrF, arrMtrxLamb, arrPos_GSK);

			TURPointXY pntFall ( arrPos_GSK[0],  arrPos_GSK[1] );  // ����� �������
		 //	pntFall.WriteSetSHPFiles(L"E:\\Ametist\\22-02-2018\\NEW\\pntFallCur.shp", &pntFall,1);
		 //	pntFall.WriteSetSHPFiles(L"E:\\Ametist\\22-02-2018\\NEW\\pntAimCur.shp", &ppntArrCorrecting[j],1);

			for (int n  = 0; n < LEnarrX; n++)
			{
				double dist = sqrt((arrPos_GSK[0] - parrTargX[n]) * (arrPos_GSK[0] - parrTargX[n]) + arrPos_GSK[1] * arrPos_GSK[1]);
				if (dist <= VAlKillingRange)
				{
					piarrSuccess[n] = 1;
				}
			}


			}
	  }
	  double valSum = 0.;

		for (int nn = 0; nn < LEnarrX; nn++)
		{
		if (piarrSuccess[nn]  > 0.001)
		{
			valSum += 1.;
		}
		}
		double valPTemp = valSum / ((double)LEnarrX );
		valProbSum +=  valPTemp;

		 //	rastrTargCur.WriteMeAsFltFile(L"E:\\Ametist\\22-02-2018\\COAST_1D\\plgTarg0.flt"); //!!!!!
	}
	*pvalProb =  valProbSum/((double)QAantIspit);
	delete piarrSuccess; */
}

//-------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
// ���������� ������� ����������� ����� ������������ �� ����� ��� ��� ��������� �������� ����
// ������������� �� ����� ������ OX
// ������ ���� � ���� ������ ����� �� ���  OX

// �� ������� ������� ����������� ����� �� In �������������� ���� �� ����� ����� ������������
// INPUT:

// VAlSig - ��� ����� �������
// VAlKillingRange - ������ ���������
// QUantShells  - �-�� ���������
//  In  - �-�� ������� ����� ������������
// parrx[LEnarrX] - ����� ����
//OUTPUT:
//  parrAimingPoints -  ������ ��������� ����� ������������
//  piarrRepeatQuants - ������ ���������� ����� ������������
//  *pQuantAimingPoints - �- �� ��������� ����� ������������
bool TCoastTargNeighbourhood::calcOptimalArray_Of_AimPoints_ForGroupLinedPoints(double *arrElK
	,const double VAlKillingRange, const int QUantShells,const int  In, double *parrZ, const int LEnarrZ
	, double *parrAimingPoints, int *piarrRepeatQuants, int *pQuantAimingPoints, double &valObj, TURPointXY *pPntArrDensity)

{
	int iNumArgMin = -1;
	double valMinX = MinDoubleArray(parrZ, LEnarrZ, &iNumArgMin) ;

	double valMalX = MaxDoubleArray(parrZ, LEnarrZ, &iNumArgMin) ;

	const double VAlL = valMalX -  valMinX;


	// ���������� �����
	double *parrt = new double [In];
	memset(parrt, 0, In * sizeof(double));
	for (int i = 0; i < In; i++)
	{
		parrt[i] = valMinX  +  + ((double)i) * VAlL / ((double)In  -1.);
	}
	///

	// ������������ �������
	double *parr_L = new double  [In * LEnarrZ];
	const double VAlStepIntegr = VAlKillingRange /10.;
	///
	 for (int i = 0; i < LEnarrZ; i++)
	{
		for (int j = 0; j < In; j++)
		{
			//double valp = TProbabilityTheory::calcIntegralNormalDensity(parrt[i], VAlSig, parrZ[j] - VAlKillingRange
		 //		, parrZ[j] + VAlKillingRange, VAlStepIntegr);
		 double valp = TProbabilityTheory::calcIntegralNormalDensity_2D(parrZ[i] - parrt[j], 0.
			 ,arrElK,   VAlKillingRange, VAlStepIntegr);
			parr_L[i * In + j] = log(1. - valp)  ;
		}
	}
	///
	double *parrX = new double [In];
	memset(parrX, 0, sizeof(double) * In);
	parrX [In /2] =  (double)QUantShells;

	double *parrXZv = new double [In];
	memset(parrXZv, 0, sizeof(double) * In);

	double valEps = 0.005 ;
	double valObj0 = calcFGr(parr_L,  LEnarrZ ,In, parrX);
	bool brez = false;
	for (int i = 0; i < 500; i++)
	{
	 // ����������   ��  ���
		 // ������� �������
			double *parr_f= new double [In];
			double *arrGrad= new double [In];
			double *arr_d2FGr_po_dx= new double [In * In];
			double *parrRez = new double [In];
			calcGradFGr(parr_L,  LEnarrZ, In, parrX, arrGrad);
			calc_d2FGr_po_dx(parr_L,  LEnarrZ, In, parrX, arr_d2FGr_po_dx);
			MtrxMultMatrx(arr_d2FGr_po_dx, In, In, parrX,1, parrRez) ;
			MatrxMultScalar(parrRez, In, 1, 2., parrRez);
			MtrxSumMatrx(parrRez, arrGrad,In, 1, parr_f) ;
			///
			int nvars = In;
			int bvars = 0;
			int nrows = 0;
			double  arr_a[1] = {0.}, arr_b[1] = {0.};
			int  nrows_eq = 1;
			double *a_eq = new double [nvars];
			double *lb = new double [nvars];
			memset (lb, 0, sizeof(double) * In);
			double *ub  = new double [nvars];
			for (int i =0; i < nvars; i++)
			{
				a_eq[i] = 1.;
				ub [i] =  (double)QUantShells;
			}

			double b_eq[1] = {0.};
			b_eq[0] = (double)QUantShells;

			int ix [1];
			double fval = -1;
			int irez = LinNumericalSolver(  nvars, bvars, parr_f, nrows,
							arr_a, arr_b, nrows_eq,	a_eq, b_eq, lb,
							ub, ix, parrXZv, fval);

			double *parrRez0 = new double [In];
			valObj = calcMinObjectFunc_AlongWithLine(parr_L,  LEnarrZ, In, parrX, parrXZv, parrRez0);
		 //	MtrxMinusMatrx(parrX, parrRez0,1, In, parrXZv);
		//	double delt = NormVect(parrXZv, In);

			if (fabs(valObj - valObj0) < valEps)
			{
				brez = true;
				break;
			}
			memcpy(parrX,parrRez0, In * sizeof(double));
			valObj0 = valObj;
			delete []parr_f;
			delete []arrGrad;
			delete []arr_d2FGr_po_dx;
			delete []parrRez;
			delete []a_eq ;
			delete []lb ;
			delete []ub;
			delete []parrRez0;

	}
	for (int i = 0; i < In; i++)
	{
	 pPntArrDensity[i].X =  parrt[i];
	 pPntArrDensity[i].Y = parrX [i];
	}
	delete []parrXZv;

		int *piarr_q = new int [In];   // �-�� ���������� ����� �������� � ������� i
	double *parr_z =  new double[In];
	int iSum = 0;
	for (int i = 0; i < In; i++)
	{
		piarr_q[i] =  QUantShells * parrX[i];
		iSum +=  piarr_q[i];
		parr_z [i] =  ((double)QUantShells) * parrX[i] -piarr_q[i];
	}
	///

	int iJ = QUantShells - iSum;
	for (int i = 0; i < iJ; i++)
	{
		int j = -1;
		MaxDoubleArray(parr_z, In, &j) ;
		piarr_q [ j]++;
		parr_z[j] = -1.;
	}
	///

	*pQuantAimingPoints = 0;
	int icur = 0;
	for (int i = 0; i < In; i++)
	{
	  if (piarr_q[i] > 0)
	  {
		piarrRepeatQuants[icur] =  piarr_q[i];
		parrAimingPoints [icur] = parrt[i];
		icur++;

	  }
	}
	*pQuantAimingPoints = icur;


	delete []piarr_q;
	delete []parrX;
	delete []parrt;
	return brez;


}

void TCoastTargNeighbourhood::calcGradFGr(double *parr_L, const int LEnarrZ
				 ,const int In,double * parrX,double * arrGrad)
{
	memset(arrGrad, 0, In * sizeof(double));
	double *arrFi = new double [LEnarrZ];
	for (int i =0; i < LEnarrZ; i++)
	{
		 arrFi[i]  = calcFi_i(parr_L, LEnarrZ
				 , In, parrX, i);

	}
	MtrxMultMatrx(arrFi,1, LEnarrZ, parr_L,In, arrGrad) ;
	delete []arrFi;
}

void TCoastTargNeighbourhood::calc_d2FGr_po_dx(double *parr_L, const int LEnarrZ
				 ,const int In,double * parrX,double * arr_d2FGr_po_dx)
{
	memset(arr_d2FGr_po_dx, 0, In *In * sizeof(double));
	double *arrTemp = new double [In *In];
	double *arrTemp0 = new double [In *In];
	for (int i =0; i < LEnarrZ; i++)
	{
		 double valTemp = calcFi_i(parr_L, LEnarrZ, In, parrX, i);
		 MtrxMultMatrx(&parr_L [ i * In],In, 1, &parr_L [ i * In],In, arrTemp) ;
		 MatrxMultScalar(arrTemp, In, In, valTemp,arrTemp0);
		 MtrxSumMatrx(arr_d2FGr_po_dx, arrTemp0,In, In, arrTemp) ;
		 memcpy(arr_d2FGr_po_dx, arrTemp, In * In * sizeof(double));
	}

	delete []arrTemp;
	delete []arrTemp0;
}

double TCoastTargNeighbourhood::calcMinObjectFunc_AlongWithLine(double *parr_L, const int LEnarrZ
				 ,const int In,double * parrX, double * parrXZv, double *parrRez)
{
	double *arrTemp0 = new double [In];
	double *arrTemp1 = new double [In];
	double *arrTemp2 = new double [In];
	double valF =  calcFGr(parr_L, LEnarrZ , In, parrX) ;
	int iC = 10000;
	for (int i = 1; i < iC; i++)
	{
	 double lamb = ((double)i) / ((double)iC -1.);
	 MatrxMultScalar(parrX, 1, In, (1. - lamb),arrTemp0);
	 MatrxMultScalar(parrXZv, 1, In,  lamb,arrTemp1);
	 MtrxSumMatrx(arrTemp0, arrTemp1 ,1, In, arrTemp2) ;
	 double valFTemp = calcFGr(parr_L,  LEnarrZ
				 , In,arrTemp2);
		if(valFTemp >= valF)
		{
			break;
		}
		memcpy(parrRez, arrTemp2, In * sizeof(double));
		valF = valFTemp;
	}


	delete []arrTemp0;
	delete []arrTemp1;
	delete []arrTemp2;
	return valF;
}

double TCoastTargNeighbourhood::calcFi_i(double *parr_L, const int LEnarrZ
				 ,const int In,double * parrX, const int NUmi)
{
	double temp = ScalProduct(parrX , &parr_L[NUmi * In], In) ;

	return exp(temp);
}

double TCoastTargNeighbourhood::calcFGr(double *parr_L, const int LEnarrZ
				 ,const int In,double * parrX)
{
	double sum = 0.;
	for (int i =0; i < LEnarrZ; i++)
	{
		 sum+= calcFi_i(parr_L, LEnarrZ , In, parrX, i);
	}
	return sum;
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
