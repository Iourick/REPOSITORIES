//---------------------------------------------------------------------------

#include <vcl.h>
#include <string.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#include "FormCoastTargs.h"

#include "YrString.h"
#include <stdio.h>
#include <typeinfo.h>
#include <stdlib.h>
#include "AM_2D.h"
#include "Far_2D.h"
#include "Comp.h"
#include "Faceta.h"
#include "Far.h"
#include "Diagrams.h"
#include "Gauss.h"

#include "MatrixProccess.h"


#include "Target.h"
#include "YrWrite.h"

#include "Sins.h"
#include "DriverMech.h"

#include "Measurer.h"
#include "YrWriteShapeFile.h"

#include "InitTargData.h"
#include "CalcCorMatrx.h"

#include "Environment.h"
#include "Equations.h"
#include "MyShellTraj.h"

#include "SincDgr.h"
#include "URPointZ.h"
#include "ShellBody.h"
#include "ControlSyst.h"
#include "Line.h"
#include "CoastTargPicturte.h"
#include "NeighbourhoodAppPoint.h"
#include "CoastTargNeibourhood.h"
#include "URFigure.h"
#include "URMultiPoint.h"
#include "ProbabilityTheory.h"


static int I_ENTER_COUNT = 0;
extern const double VAL_C;
extern TYrRastr rstrUZP_OGS_St_L10_H0;
extern const	double arrSPrived[];
extern const double VAl_YZP_ForOpenManPower_Calibro130 ;
extern const double VAl_YZP_ForOpenManPower_Calibro100 ;

TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
bCorrection = false;
menumTypeOfControlAlgorithm = STANDART;
RadioGroup2->ItemIndex = 1;

RadioGroup1->ItemIndex = 1;
miIdexRadioGroup1 =  RadioGroup1->ItemIndex;

mQuantShells = 150;
LabeledEdit1->Text =   mQuantShells;

ComboBox3->ItemIndex = 1;
LabeledEdit2->Text = 500;

ComboBox1->ItemIndex = 0;
LabeledEdit6->Text = 130;


// ����������� �������� �
createInputGridForPointTargs();

 mSig13GroupD  = 80;

 mSig13GroupBet = 36;



mSig2GroupD = 54.;

mSig2GroupBet = 19.;
fillInputGrid();

}
//---------------------------------------------------------------------------

	//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{

	drawManPowerPoligon();
 // drawRealFar();

}
//---------------------------------------------------------------------------
void __fastcall TForm2::drawManPowerPoligon()
{  /*
				Image1->Canvas->Polygon()
		Image1->Canvas->Brush->Color=clSilver;//clRed;
	  Image1->Canvas->Pen->Width=1;
	  Image1->Canvas->Pen->Color= clBlack;//clWhite;


		miWidth = Image1->Width;
	  miHeight =Image1->Height;

	  mdx=(double)miWidth/mNumCols;
	  mdy=(double)miHeight/mNumRows;

		TRect rec(0,miHeight,miWidth,0);

		Image1->Canvas->FillRect(rec);

	//  TRect rec1(0,mNumRows *miHeight, mNumCols *miWidth, 0);


  for( int i =0; i < mNumRows; i++)
	  for(int j=0; j < mNumCols; j++)
	  {
		  DrawCell_(i, j);
	  }
	  Image1->Canvas->Pen->Width= 5;
	  Image1->Canvas->MoveTo(rec.Left,rec.Top);
	  Image1->Canvas->LineTo(rec.Right,rec.Top);
	  Image1->Canvas->LineTo(rec.Right,rec.Bottom);
	  Image1->Canvas->LineTo(rec.Left,rec.Bottom);
	  Image1->Canvas->LineTo(rec.Left,rec.Top);

	  ///
  	  Image1->Canvas->Pen->Width= 7;
	  Image1->Canvas->MoveTo(rec.Left,rec.Top/2);
	  Image1->Canvas->LineTo(rec.Right,rec.Top/2);
	  Image1->Canvas->MoveTo(rec.Right/2,rec.Top);
	  Image1->Canvas->LineTo(rec.Right/2,rec.Bottom);
		Image1->Canvas->Pen->Width= 1;
		*/
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



void __fastcall TForm2::RadioGroup1Exit(TObject *Sender)
{
		if ((RadioGroup1->ItemIndex) != miIdexRadioGroup1)
		{
		 miIdexRadioGroup1 = RadioGroup1->ItemIndex;
		 bCorrection = !bCorrection;
		}
}
//---------------------------------------------------------------------------


void __fastcall TForm2::RadioGroup1Click(TObject *Sender)
{
		 if ((RadioGroup1->ItemIndex) != miIdexRadioGroup1)
		{
		 miIdexRadioGroup1 = RadioGroup1->ItemIndex;
		 bCorrection = !bCorrection;
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
			wchar_t arwch[2] ={0};
			String s_22  =arwch;
			LabeledEdit4->Text  = -1;//s_22;
			LabeledEdit3->Text  = s_22;
			LabeledEdit5->Text  = s_22;
			LabeledEdit7->Text  = s_22;
		// �������� ���� � ����� � �������
		if (!mpwchOutFile0) {
		if (I_ENTER_COUNT > 4)
		Close();

		ShowMessage(L"������� ���� � ����� � ���������");
		I_ENTER_COUNT++;
		return;
		}
		wcscpy(mwchOutFold, mpwchOutFile0);
		wchar_t *pwchr = wcsrchr(mwchOutFold, L'\\');
		pwchr[0] = 0;
	 //	String wchFoldName = mwchOutFold;
		fncInputData() ;
	//	double arrShellScatteringsCorMtrx_GSK[36] = {0.};

		double valSKZPromach = -1.0,   valProb = -1.0, valProb_Monte_Carlo = 0.;
		double arrShellVeloAppointmPoint_GSK [3] ={0.};

		TURPointXY *ppntArrAimingPoints = new TURPointXY[mQuantShells];
		int * piarrRepeatAimingPoints = new int [mQuantShells];
		memset(piarrRepeatAimingPoints, 0, mQuantShells * sizeof(int));
		memset(ppntArrAimingPoints , 0, mQuantShells * sizeof(TURPointXY));
		int iQuantAimingPoints = -1;
	//	if (! mFight.calcSuccessProbCoast(mQuantShells, bCorrection, mQuantIspit, mKillingRange
	//	, &valSKZPromach , arrShellScatteringsCorMtrx_GSK  ,arrShellVeloAppointmPoint_GSK, &valProb
	//	,menumTypeOfControlAlgorithm, ppntArrAimingPoints, piarrRepeatAimingPoints, &iQuantAimingPoints  )
		//	)
		double arrScatterCorMtrx_1_and_3_Groups[36] = {0.}, arrScatterCorMtrx_2_Group[36] = {0.};
			if (! mFight.calcSuccessProbCoast(mQuantShells, bCorrection, mQuantIspit, mKillingRange
		, &valSKZPromach ,arrScatterCorMtrx_1_and_3_Groups,arrScatterCorMtrx_2_Group ,arrShellVeloAppointmPoint_GSK, &valProb
		,menumTypeOfControlAlgorithm, ppntArrAimingPoints, piarrRepeatAimingPoints, &iQuantAimingPoints, &valProb_Monte_Carlo  )
			)

		{
			LabeledEdit4->Text  = -1;
			LabeledEdit3->Text  = -1;
			LabeledEdit5->Text  = -1;
			LabeledEdit7->Text  = -1;
			return;
		}

		///
		 //	TURFigure  Figure, *pFigure;
		//	Polygon00 = TURPolygon ( *ppPlg0, iObjQuant);
		//	TURPolygon *pPolygon00 = &(mFight.mTarget. ;
		 //	pFigure = (TURFigure*)(pPolygon00);

		 //	TCoastTargNeighbourhood  CoastTargNeighbourhood ( pFigure ,
			//	mTargCellSize ,  mAimCellSize , arrMtrxCorrFluct, arrMtrxCorrSyst
			// ,mKillingRange, mQuantShells, 1.) ;
			// 1. �������� ���� �������:
		 const	double VAlPsi = atan2(arrShellVeloAppointmPoint_GSK[1], arrShellVeloAppointmPoint_GSK[0]);
		 ///

		 // 2. ������������ ��������� ������ �������
		double arrScatterCorMtrxSum[4] = {0.};
		MtrxSumMatrx(arrScatterCorMtrx_1_and_3_Groups, arrScatterCorMtrx_2_Group, 2, 2, arrScatterCorMtrxSum) ;
		 ///

		 // 3. �������� ������ ������� � ������� ��������� ��������������� �� ���� (��� ���������� �� ���� ������� ���� PI/2 - mBearing0)
		 double arrBearingK[4] = {0.}, arrRotate[4] ={0.}, arrTemp[4] ={0.};
		 arrRotate[0] = cos(M_PI/2. - mBearing0);
		 arrRotate[1] = -sin(M_PI/2. - mBearing0);
		 arrRotate[2] = -arrRotate[1];
		 arrRotate[3] = arrRotate[0];

		 MtrxMultMatrx(arrRotate,2, 2, arrScatterCorMtrx_2_Group ,2, arrTemp) ;
		 MtrxMultMatrxTransp(arrTemp,2, 2, arrRotate,2, arrBearingK) ;
		 ///

		int	ia = (valProb * 1000);
		LabeledEdit4->Text  =(( double)ia)/ 1000.;

		ia = (valProb_Monte_Carlo * 1000);
		LabeledEdit13->Text  =(( double)ia)/ 1000.;

		ia = (sqrt(arrBearingK[0]) * 100);
		LabeledEdit3->Text  =(( double)ia)/ 100.;

		ia = (sqrt(arrBearingK[3]) * 100);
		LabeledEdit5->Text  =(( double)ia)/ 100.;

		ia = (mKillingRange * 100);
	 LabeledEdit7->Text  =(( double)ia)/ 100.;
 //------------------------------------------------------------------

		//	const String s_30 = wchFoldName;
		//	String s_31 = s_30 + L"TargPntArray.shp";
		//	TURPointXY::WriteSetSHPFiles(s_31.w_str()  , CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints);

		//	s_31 = s_30 + L"AimPntArray.shp";
		//	TURPointXY::WriteSetSHPFiles(s_31.w_str()  , CoastTargNeighbourhood.mMultPntAim.Points, CoastTargNeighbourhood.mMultPntAim.NumPoints);
			 //	�������� ���� �������:
		//	const	double VAlPsi =0.;
			///
		/*	createNibourAppointmPointPictureForCoastTarg(wchOutFold,arrMtrxCorrFluct, arrMtrxCorrSyst
			, pFigure, 0., VAlPsi);


			s_31 = s_30 + L"RstrBiasAims.flt";
			CoastTargNeighbourhood.mRstrBiasAims.WriteMeAsFltFile(s_31.w_str());
			s_31 = s_30 + L"RstrProbBias.flt";
			CoastTargNeighbourhood.mRstrProbBias.WriteMeAsFltFile(s_31.w_str());

			s_31 = s_30 + L"PlgAim.shp";
			CoastTargNeighbourhood.mPlgAim.WriteSetSHPFiles(s_31.w_str()
			, &(CoastTargNeighbourhood.mPlgAim), 1);

			 TYrRastr rstrAimPoints = TYrRastr( CoastTargNeighbourhood.mPlgAim
			 , mAimCellSize,  0., CoastTargNeighbourhood.mMultPntAim.Points[0]);
			s_31 = s_30 + L"rstrAimPointsTemp.flt";
			rstrAimPoints.WriteMeAsFltFile(s_31.w_str());
			///
		*/
			//-----------------------------------------------------------------------------------

			///////




	 createNibourAppointmPointPictureForCoastTarg(mwchOutFold,arrScatterCorMtrx_1_and_3_Groups, arrScatterCorMtrx_2_Group
		 , mFight.mTarget.mpArrPlanePolygon[0].mPolygon, mTargCourse0, VAlPsi);
 // ���������� ����� ������������



 double  arrMtxPer0[4] = {0.};
 arrMtxPer0[0] = cos(mTargCourse0);
 arrMtxPer0[1] = sin(mTargCourse0);
 arrMtxPer0[2] = -arrMtxPer0[1];
 arrMtxPer0[3] = cos(mTargCourse0);

	wchar_t wchFoldName[300] ={0}, wchFileAimingPoints[300] ={0} ;
	// ,wchFileLineDiagram_X[300] ={0} ,wchFileAxesDiagram_X[300] ={0}
	//	,wchFileLineDiagram_Y[300] ={0} ,wchFileAxesDiagram_Y[300] ={0} ;
	wcscpy(  wchFoldName,  mwchOutFold);
	wcscat(wchFoldName, L"\\");

	wcscpy(  wchFileAimingPoints,  wchFoldName);
	wcscat(wchFileAimingPoints, L"AimingPoints.shp");
	ppntArrAimingPoints[0].WriteSetSHPFiles(wchFileAimingPoints,ppntArrAimingPoints, iQuantAimingPoints) ;

	TURPointZ *pPointZ = new TURPointZ[iQuantAimingPoints];
	for (int i =0; i < iQuantAimingPoints; i++)
	{
		pPointZ[i].X = ppntArrAimingPoints[i].X;
		pPointZ[i].Y = ppntArrAimingPoints[i].Y;
		pPointZ[i].Z = (double)piarrRepeatAimingPoints[i];
	}
	wcscpy(  wchFileAimingPoints,  wchFoldName);
	wcscat(wchFileAimingPoints, L"AimingPointsZ.shp");
	pPointZ[0].WriteSetSHPFiles(wchFileAimingPoints,pPointZ, iQuantAimingPoints) ;
	delete []ppntArrAimingPoints;
	delete piarrRepeatAimingPoints;
	delete []pPointZ;

}



//----------------------------------------------------------------------------------------------
void __fastcall TForm2::fncInputData()
{
	mQuantShells = StrToInt(LabeledEdit1->Text);
	mQuantIspit = StrToInt(LabeledEdit2->Text);
	
	//if (wcschr(s_22.w_str(), L','))
 //	{


		// ����
		// ���� �������, ����

		mBearing0 = StrTo_Dbl_(LabeledEdit23->Text) * M_PI / 180.;
		// ������, �
		mElev0 = 0.;

		// ���������, �



		 mDist0 = StrTo_Dbl_(ComboBox5->Text) * 1000.;
		 if (mDist0 > 20000.)
		 {
	   mDist0 = 20000.;
		 }
	   
		//
		mTargZenitAng0 =  M_PI/2.;
		// ���� �����
		mTargCourse0 = StrTo_Dbl_(LabeledEdit29->Text) * M_PI / 180.;

		///
		mVelocity0 = 0.01; // ��� ������� ��� ����, �����  ����� ����������� ��������� ���������� ��������� ���� � ���


		double valAUDelayT = StrTo_Dbl_(LabeledEdit50->Text)/ 1000.;
		mSigAUDelayT = sqrt(TProbabilityTheory::calcDispRavnomern(valAUDelayT) );


		mSigDrivAY_U  =  StrTo_Dbl_(LabeledEdit52->Text) / 1000.;
		mSigDrivAY_dU_po_dt  =  StrTo_Dbl_(LabeledEdit53->Text) / 1000.;

	//}
 //	else
	//{
		// ���������������
		// mWidthDgr =  StrTo_Dbl_(LabeledEdit3->Text) * M_PI/3000./2. ;
 //	}


   //	LabeledEdit22->Text = mElev0 ;
   // ��. ���������� ShellBody (mEnumShellType). ShellBody ���������� ����� ��������� �����������
	switch( ComboBox1->ItemIndex)
		{
			case 0:
			mEnumShellType = CALIBRO_130;
			menumCannonType = A_192M;
			LabeledEdit6->Text = 130;
			break;

			case 1:
			mEnumShellType = CALIBRO_100;
			menumCannonType = A_190_01;
			LabeledEdit6->Text = 100;
			ComboBox2->ItemIndex = 0;
			ComboBox3->ItemIndex = 0;

			break;

			default:
			mEnumShellType = CALIBRO_UNKNOWN;
			menumCannonType = CANNON_UNKNOWN;
			break;
		}


	///
		// ��� ����������
		switch(ComboBox2->ItemIndex)
		{
			case 0:
			mDetonatorType = D4MRM;
			break;
			case 1:
			mDetonatorType = MFIVU;
			break;
			default:

			break;
		}

		///

		TDetonator Detonator (mDetonatorType);
		mShellBody = TShellBody(mEnumShellType, Detonator ) ;
		mArtCannon =  TArtCannon (menumCannonType, mSigAUDelayT )  ;
		mArtComplex  = TArtComplex (mArtCannon, 	mSigDrivAY_U , mSigDrivAY_dU_po_dt )  ;




	LabeledEdit49->Text =  mArtCannon.mRateOfFire;

	switch(ComboBox3->ItemIndex)
	{
	case 0:
	mEnumTargType = OPEN_MANPOWER_LIE;
	break;

	case 1:
	mEnumTargType = OPEN_MANPOWER_STAND;
	break ;

	case 2:
	mEnumTargType = 	BULLET_PROOF_LIE;
	break;

	case 3:
	mEnumTargType = BULLET_PROOF_STAND;
	break;

	case 4:
	mEnumTargType = COVERED_MANPOWER_ENTRENCH;
	break;

	case 5:
	mEnumTargType = COVERED_MANPOWER_TRENCH;
	break;

	case 6:
	mEnumTargType = MANPOWER_ARMOURED_CARRIER;
	break;

	case 7:
	mEnumTargType = MANPOWER_CAR;
	break;

	case 8:
	mEnumTargType = PLATOON_POINT ;
	break;
	default:
	break;
	}


	mInitTargData = TInitTargData(mBearing0, mTargCourse0, mTargZenitAng0,
		mVelocity0, mDist0, mElev0, 0.);
   const double TCur0 = 0.;
	double arrWSkz[3] = {0.};

	TTraject Traj0(TCur0,  arrWSkz, mInitTargData );
	TTarget Target(Traj0,mEnumTargType, mTargEPR, NULL) ;
	mVessel  =TVessel(        mShellBody, mFar_2D , mTransmitAnt
								, mDriverSigBet, mDriverSigEps, mDriverDynamicSigBet, mDriverDynamicSigEps
								, mMaxSig_Q,  mMaxSig_Psi,  mMaxSig_Tet, mMaxSig_dQdt,  mMaxSig_dPsidt, mMaxSig_dTetdt   // ����
								, mMaxSig_H, mMaxSig_VH, mK1, mSigV, mEnvironment
								, mVesselWidth , mVesselLength, marrFarParallacs, mMaxQ ,mT_Q
								, mMaxPsi, mT_Psi , mMaxTet, mT_Tet, mMaxVert,  mQ0, mVVess, mInitTargData
								, mMaxAmp_AftFlexure, mT_AftFlexure, mMaxAmp_BoardFlexure, mT_BoardFlexure
								,  mControlSyst,marrArtParral, mArtComplex, NULL ) ;
	mFight = TFight( mVessel, Target ,mVessel.mControlSyst.mFiltT,mEtalonSign,  mEnvironment, NULL ) ;


 LabeledEdit51->Text = double( int(mVessel.mArtComplex.mArtCannon.mAngGroupedFire * 100000.) )/ 100.;

	 mKillingRange = -1.;
	 if (mShellBody.mDetonator.mEnumDetonatorType == D4MRM )
	 {
			mKillingRange = sqrt( VAl_YZP_ForOpenManPower_Calibro130 /M_PI);
			if(mShellBody.mEnumShellType == CALIBRO_100)
			{
			mKillingRange  = sqrt( VAl_YZP_ForOpenManPower_Calibro100 /M_PI);
			}
	 }

	 if (mShellBody.mDetonator.mEnumDetonatorType == MFIVU )
	 {
		int index =  ( ComboBox3->ItemIndex) * 12 +  ( ComboBox5->ItemIndex)  * 4 +   ComboBox4->ItemIndex  ;
		mKillingRange =  sqrt(arrSPrived[index]/M_PI);
	 }
	 if(RadioGroup3->ItemIndex == 1)
	 {
		TURPolygon *purPlg =  (TURPolygon *)malloc(sizeof( TURPolygon)* 10);
		TURPolygon **ppurPlg = &purPlg;
		int quantPlg =1;
		TURPolygon::ReadSHPFile(mpwchSHP_TargFile,ppurPlg,  &quantPlg)  ;
		mPlgTarg = (*ppurPlg)[0];
		mFight.mTarget.mpArrPlanePolygon[0].mPolygon = mPlgTarg;
		free(purPlg);
	 }
	 if(RadioGroup1->ItemIndex == 1)
	 {
		 bCorrection = true;
	 }
	 else
	 {
         bCorrection = false;
     }
}

//---------------------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
 OpenDialog3->Filter = L"����� � ��������� (*.shp)|*.shp" ;

	if (OpenDialog3->Execute())
	{
	mpwchOutFile0 =  (OpenDialog3->FileName).w_str();

	}
	Edit2->Text =  mpwchOutFile0;
}
//---------------------------------------------------------------------------


// ---------------------------------------------------------------------------

void __fastcall TForm2::create5P10()
{
   	//���������
	 double valEtalonAmp = 500.;
	//���������
	 double valEtalonDist = 12000.;
	//���
	 double valEtalonAPR = 1.;
	//��� ����� ���� ��������� ��������� 5�10
	 double valNoiseSKZ_5P10 = 18.735;
	// ��� �������� ������� �������� ��������� ��������� 5�10
	 double valEtalonSigAmplFact_5P10 = 0.01;
	//
	// �������� �� ��������
	 double valEtalonPowerPrd = 4000.;
	// �� �� ��������
	 double valEtalonKYPrd = 840.;
	// �������� �� �����
	 double valEtalonKYPriem = 5200.;

	 mEtalonSign = TEtalonSign( valEtalonAmp, valEtalonDist,  valEtalonAPR,
			 valNoiseSKZ_5P10, valEtalonSigAmplFact_5P10, valEtalonPowerPrd,  valEtalonKYPrd
			,  valEtalonKYPriem);

	///

	// �������
	// ������ �� ��
	// �-�� ����������� �� �����������
	 int iNumEmitCols = 8;
	// �-�� ����������� �� ���������
	 int iNumEmitRows = 8;
		// ����� �����
		double valLambda = VAL_C / 8.* 100. / 1000000000.;

			// ���������� ����� ������������
		double valdEmitCol = valLambda * 0.55;
		double valdEmitRow = valLambda * 0.55;


	// ������ �� ���
	// �-�� ��  �� �����������
	 int iNumAMCols = 8;
	// �-�� �� �� ���������
	 int iNumAMRows = 8;
		// ���������� ����� �� �� ���������
	double valdAMRow = ((double)iNumEmitRows) *  valdEmitRow;
	// ���������� ����� �� �� �����������
	double valdAMCol = ((double)iNumEmitCols) *  valdEmitCol;
	// ��� ���� � ��������� ���������
	bool barrAM [5000] = {0};
	 for (int i = 0; i < 5000; i++)
	{
		barrAM[i] = true;
	}


//	double arrArtParral[3] ={0.},  arrFarParallacs[3] ={0.};



	// �������� �� ��������
	 double valPowerPrd =4000.;
	// �� �� ��������
	 double valKYPrd = 3000.;
	 mTransmitAnt.mKYPrd  =valKYPrd;
	 mTransmitAnt.mPowerPrd = valPowerPrd;


	///

const double SigEmitNoise =  valNoiseSKZ_5P10 / sqrt(((double)(8 * 16 * 28)));
	const double SigEmitAmplFact = valEtalonSigAmplFact_5P10 / sqrt
		(((double)(8 * 16 * 28)));
 TAM_2D AM_2D(iNumEmitCols, iNumEmitRows,  valdEmitCol,  valdEmitRow,
		SigEmitNoise, SigEmitAmplFact);

	mFar_2D = TFar_2D(iNumAMCols, iNumAMRows,  valLambda,  valdAMCol,  valdAMRow,
		AM_2D, barrAM);

	for (int i = 0; i < iNumAMCols * iNumAMRows; i++) {

		if (!barrAM[i]) {
			mFar_2D.mpAm2D[i].mOtklCoefUs = 1.;
			mFar_2D.mpAm2D[i].mSigEmitNoise = 0.;
		}
	}


	//-------------------------------------------------------------------
	// ��� ������� ������ ���� (����� �����)
	mSigSins = 0.00041;

	// ��� ������� ������ ������ �������� ����� (����� �����)
	mSig_d_po_dt_Sins = 0.00116;

	// ������� ���
	 mVesselWidth = 0.; // ������(�)
	 mVesselLength = 0. ;

	mMaxQ =     3./180.*M_PI; /// ������������ ���� ���������� �� ������������ �����(��������� ���� ��������)
	mT_Q = 18.; // ������ ��������
	mMaxPsi =      3./180.*M_PI;// ������������ ���� ������� �����(���������)
	mT_Psi = 12; // ������ ������� �����
	mMaxTet =      12./180.*M_PI; //������������ ���� ��������� �����(���������)
	mT_Tet = 6; // ������ �������� �����
	mMaxVert =     1. ;

	// ���������� ��������  ������� ������
	 mQ0 = 0. ; // ����������� ����
	 mVVess = 20. * 0.514 ;// �������� ������� ������ 20 �����
 //	 double arrDelt[4] = {0.};


	mMaxAmp_AftFlexure  = 1. * M_PI/180.;
	// ������ ��������� ��������� ������
	mT_AftFlexure = 4.;
	//������������ ��������� ��������� ������ ������� � ��� �� 100 �
	mMaxAmp_BoardFlexure =  1. * M_PI/180.;
	// ������ ��������� ��������� ������
	mT_BoardFlexure = 2.;

		 // 3.1 �������� ����
	mMaxSig_Q      =     mSigSins ; //0.000582;
	mMaxSig_Psi    =      mSigSins ; //0.00145;
	mMaxSig_Tet    =    mSigSins ; // 0.00145;
	mMaxSig_dQdt   =      mSig_d_po_dt_Sins ;
	mMaxSig_dPsidt =      mSig_d_po_dt_Sins ;
	mMaxSig_dTetdt =      mSig_d_po_dt_Sins ;
	mK1         = 0.01 ;
	mSigV       =      0.2 * sqrt(2.) ;
	mSigH       =      0.1 ;
	mMaxSig_H =     0.1 ;
	mMaxSig_VH =     0.05 ;

    	// 3.3 �������� �������
	mDriverSigBet  =      0.00021 ;
	mDriverSigEps  =      0.00021 ;
	mDriverDynamicSigBet =      0.0003141;
	mDriverDynamicSigEps =      0.0003141;

		// �������� ����� �����������
	mMeasT = 0.02;

	// �������� ����
	mSinsDelayT = 0.02;

		// ���� ������� ���
	mRzvT = 0.00001;
	mControlSyst = TControlSyst(mMeasT, mSinsDelayT,mRzvT );

}
void __fastcall TForm2::Panel3Click(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ComboBox3Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ComboBox1Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ComboBox2Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ComboBox4Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ComboBox5Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LabeledEdit23Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LabeledEdit29Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LabeledEdit1Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LabeledEdit2Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LabeledEdit49Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LabeledEdit51Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LabeledEdit52Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LabeledEdit53Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LabeledEdit50Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------



void __fastcall TForm2::RadioGroup2Click(TObject *Sender)
{
	switch(RadioGroup2->ItemIndex)
	{
		case 0:
		menumTypeOfControlAlgorithm = OPTIMAL;

		menumTypeOfControlAlgorithm =  STANDART;
		RadioGroup2->ItemIndex = 1;
		break;

		case 1:
		menumTypeOfControlAlgorithm = STANDART;
		break;


		default:
		break;

	}

}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioGroup3Click(TObject *Sender)
{
	if(RadioGroup3->ItemIndex == 1)
	{
	OpenDialog1->Filter = L"����� � ��������� (*.shp)|*.shp" ;

	if (OpenDialog1->Execute())
	{
	mpwchSHP_TargFile =  (OpenDialog1->FileName).w_str();

	}
	}
   //	Edit2->Text =  mpwchOutFile0;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::createInputGridForPointTargs()
{
		 StringGrid2->Cells[0][1] = L"����� ����";
		 StringGrid2->Cells[0][2] = L"����� �����";
		 StringGrid2->Cells[1][0]  = L"�� �����";

		 StringGrid2->Cells[2][0]  = L"�� ����";

		 StringGrid2->ColWidths[0]= 70;
		 StringGrid2->ColWidths[1]= 70;
		 StringGrid2->ColWidths[2]= 70;
		 StringGrid2->Width =   StringGrid2->ColWidths[0] +  StringGrid2->ColWidths[1] +  StringGrid2->ColWidths[2];
		 StringGrid2->Height = 4 * StringGrid2->RowHeights[0] ;
}
 //---------------------------------------------------------------------------
// ���������� �������� ���������� �� �����
void __fastcall TForm2::InputGridData()
{

		mSig13GroupD  = StrTo_Dbl_(StringGrid2->Cells[1][1] );

		 mSig13GroupBet = StrTo_Dbl_(StringGrid2->Cells[2][1]);//


		// 8. ������ ����, �������
		mSig2GroupD = StrTo_Dbl_(StringGrid2->Cells[1][2]);
		// 9. ������ ��������, �������
		mSig2GroupBet = StrTo_Dbl_(StringGrid2->Cells[2][2]);



}
//--------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm2::fillInputGrid()
{

		StringGrid2->Cells[1][1] = mSig13GroupD ;
		StringGrid2->Cells[1][2] = mSig2GroupD;//mSig13GroupBet;

		StringGrid2->Cells[2][1] = mSig13GroupBet ;//mSig2GroupD;
		StringGrid2->Cells[2][2] =  mSig2GroupBet;

}

//--------------------------------------------------------------------------


void __fastcall TForm2::StringGrid2Exit(TObject *Sender)
{
  InputGridData();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)
{
 OpenDialog2->Filter = L"����� � ��������� (*.shp)|*.shp" ;

	if (OpenDialog2->Execute())
	{
	mpwchSHP_TargFile =  (OpenDialog2->FileName).w_str();

	}
	Edit6->Text =  mpwchSHP_TargFile;
	mStringFileDataPoints = mpwchSHP_TargFile;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button6Click(TObject *Sender)
{
	OpenDialog1->Filter = L"����� � ��������� (*.shp)|*.shp" ;

	if (OpenDialog1->Execute())
	{
	mpwchOutFileForPointGroupTarg =  (OpenDialog1->FileName).w_str();

	}
	Edit9->Text =  mpwchOutFileForPointGroupTarg;

}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button7Click(TObject *Sender)
{
	 //	TURPointXY Points1[7];
		//	Points1[0] =  TURPointXY(-60., -60.);

		//	Points1[1] =  TURPointXY(-20., -20.);
		//	Points1[2] =  TURPointXY(20., 20.);
		 //	Points1[3] =  TURPointXY(60., 60.);
		//	Points1[4] =  TURPointXY(-60., -60.);

		   //	Points1[4].sortPointsArray_X (Points1, 5);
	// TURMultiPoint MultiPoint(Points1, 5), *pMultiPoint;
	// pMultiPoint = &MultiPoint;
	// TURFigure *pFig = (TURFigure*)pMultiPoint;
 //	 pFig ->WriteSetSHPFiles(L"E:\\Ametist\\06-03-2018\\Temp\\obj.shp") ;

	wchar_t arwch[2] ={0};
			String s_22  =arwch;
			LabeledEdit4->Text  = -1;//s_22;
			LabeledEdit3->Text  = s_22;
			LabeledEdit5->Text  = s_22;
			LabeledEdit7->Text  = s_22;
		// �������� ���� � ����� � �������
		if (!mpwchSHP_TargFile) {
		if (I_ENTER_COUNT > 4)
		Close();

		ShowMessage(L"������� ���� � SHP ����� ����");
		I_ENTER_COUNT++;
		return;
		}


			// �������� ���� � ����� � �������
		if (!mpwchOutFileForPointGroupTarg)
		{
		if (I_ENTER_COUNT > 4)
		Close();

		ShowMessage(L"������� ���� � ����� � ���������");
		I_ENTER_COUNT++;
		return;
		}

		wchar_t wchFoldName[300] ={0}, wchOutFold[300] = {0};
		wcscpy(wchOutFold, mpwchOutFileForPointGroupTarg);
		wchar_t *pwchr = wcsrchr(wchOutFold, L'\\');
		pwchr[0] = 0;


	wcscpy(  wchFoldName,  wchOutFold);
	wcscat(wchFoldName, L"\\");

	 //	String wchFoldName = mwchOutFold;
	//	fncInputData() ;
	 InputGridData() ;
	 mKillingRange = sqrt(StrTo_Dbl_(Edit4->Text)/ M_PI );
	 mSigLocation = StrTo_Dbl_(Edit3->Text);
	 mQuantShells = StrToInt(Edit8->Text);
	 mQuantIspit =  StrToInt(LabeledEdit9->Text);
	 mAimCellSize = StrTo_Dbl_(Edit10->Text); //  ��� ������������� SHP ������� ������������ ���  ������������� ��� � ������ �����
	 mTargCellSize  = StrTo_Dbl_(Edit12->Text);


	 double arrMtrxCorrFluct[4] = {0.};
	 double arrMtrxCorrSyst[4] = {0.};
	 double arrMtrxCorrSum[4] ={0.};
	 arrMtrxCorrFluct [0] =  mSig2GroupD * mSig2GroupD ;
	 arrMtrxCorrFluct [3] =  mSig2GroupBet * mSig2GroupBet ;
	 arrMtrxCorrSyst[0] =  mSig13GroupD * mSig13GroupD +  mSigLocation* mSigLocation ;
	 arrMtrxCorrSyst [3] =  mSig13GroupBet * mSig13GroupBet + mSigLocation* mSigLocation;
		MtrxSumMatrx(arrMtrxCorrFluct, arrMtrxCorrSyst,2, 2,arrMtrxCorrSum) ;

	 //double sigDSum = sqrt(mSig13GroupD * mSig13GroupD + mSig2GroupD * mSig2GroupD + mSigLocation* mSigLocation);
	// double sigBetSum = sqrt(mSig13GroupBet * mSig13GroupBet + mSig2GroupBet * mSig2GroupBet + mSigLocation* mSigLocation);

	// double arrMtrxCorrSum[4] ={0.};
	// arrMtrxCorrSum[3] = sigBet * sigBet;
	// arrMtrxCorrSum[0] = sigD * sigD;

 //	 TCoastTargNeighbourhood  CoastTargNeighbourhood ( mpwchSHP_TargFile ,
		//	mTargCellSize ,  mAimCellSize , arrMtrxCorr,
		//	mKillingRange, mQuantShells ) ;


	 // ����������� ���� ������� SHP � �-�� ��������
	 TURFigure  Figure, *pFigure;
	 int iShapeType = -1  // ���
	 , iObjQuant = -1;       // �-��
	 Figure.find_Objects_Type_And_Quant(mpwchSHP_TargFile, &iShapeType, &iObjQuant)  ;

	 int lenObjArr =1;
		TURPointXY *pPnt0 =  (TURPointXY *)malloc(sizeof( TURPointXY)* lenObjArr);
		TURPointXY **ppPnt0 = &pPnt0;

		TURPolyLine *pPln0 =  (TURPolyLine *)malloc(sizeof( TURPolyLine)* lenObjArr);
		TURPolyLine **ppPln0 = &pPln0;

		TURPolygon *pPlg0 =  (TURPolygon *)malloc(sizeof( TURPolygon)* lenObjArr);
		TURPolygon **ppPlg0 = &pPlg0;

		TURMultiPoint MultiPoint00, *pMultiPoint00;
	 ///



		TURPolygon Polygon00, *pPolygon00;
		TURPolyLine PolyLine00, *pPolyLine00;
		TURPointXY  PointXY00(1.,1.), *pPointXY00;
		switch(iShapeType)
		{
			case 1:
			TURPointXY::ReadSHPFile(mpwchSHP_TargFile,ppPnt0,  &iObjQuant) ;
			 MultiPoint00 =  TURMultiPoint(*ppPnt0, iObjQuant);
			 pMultiPoint00 = &MultiPoint00;
			 pFigure = (TURFigure*)(pMultiPoint00);
			break;

			case 3:
			TURPolyLine::ReadSHPFile(mpwchSHP_TargFile,ppPln0,  &iObjQuant) ;
			PolyLine00 =  TURPolyLine( *ppPln0, iObjQuant);
			pPolyLine00 = &PolyLine00;
			pFigure = (TURFigure*) (pPolyLine00);

			break;

			case 5:
			TURPolygon::ReadSHPFile(mpwchSHP_TargFile,ppPlg0,  &iObjQuant) ;
			Polygon00 = TURPolygon ( *ppPlg0, iObjQuant);
			pPolygon00 = &Polygon00 ;
			pFigure = (TURFigure*)(pPolygon00);

			break;

			default:
			ShowMessage(L"Error in Data SHP File");
			free(pPnt0);
			free(pPln0);
			free(pPlg0);
			return;

		}
			free(pPnt0);
			free(pPln0);
			free(pPlg0);



			 TCoastTargNeighbourhood  CoastTargNeighbourhood ( pFigure ,
				mTargCellSize ,  mAimCellSize , arrMtrxCorrSum
			 ,mKillingRange, mQuantShells ) ;
			const String s_30 = wchFoldName;
			String s_31 = s_30 + L"TargPntArray.shp";
			TURPointXY::WriteSetSHPFiles(s_31.w_str()  , CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints);

			s_31 = s_30 + L"AimPntArray.shp";
			TURPointXY::WriteSetSHPFiles(s_31.w_str()  , CoastTargNeighbourhood.mMultPntAim.Points, CoastTargNeighbourhood.mMultPntAim.NumPoints);
			 //	�������� ���� �������:
			const	double VAlPsi =0.;
			///
			createNibourAppointmPointPictureForCoastTarg(wchOutFold,arrMtrxCorrSum
			, pFigure, 0., VAlPsi);



		 //	TCoastTargNeighbourhood CoastTargNeighbourhood(arrMtrxCorr, mKillingRange, mQuantShells ,  *ppAimPntArray,
		//	 *ppTargPntArray, lenTargPntArray, lenAimPntArray) ;
		//	free (pTargPntArray);
		 //	free (pAimPntArray);

			double valObj = -1;
			TURPointXY *pPntArrAimingPoints = new TURPointXY[CoastTargNeighbourhood.mMultPntAim.NumPoints];
			int *piarrRepeatQuants = new int [CoastTargNeighbourhood.mMultPntAim.NumPoints];
			memset( pPntArrAimingPoints, 0, CoastTargNeighbourhood.mMultPntAim.NumPoints * sizeof(TURPointXY));
			memset ( piarrRepeatQuants, 0, CoastTargNeighbourhood.mMultPntAim.NumPoints * sizeof(int));
			int iQuantAimingPoints = -1;

			CoastTargNeighbourhood.calcOptimalArray_Of_AimPoints( pPntArrAimingPoints
			,&iQuantAimingPoints, piarrRepeatQuants, &valObj) ;
			double valProb  = ( ((double)(CoastTargNeighbourhood.mMultPntTarg.NumPoints)) -  valObj)/ ((double)(CoastTargNeighbourhood.mMultPntTarg.NumPoints));
			int	ia = (valProb * 1000);
			LabeledEdit8->Text  =(( double)ia)/ 1000.;
			int iii=0;

			// ����� �����-�����
			TCoastTargNeighbourhood CoastTargNeighbourhood0 ( arrMtrxCorrFluct, arrMtrxCorrSyst, mKillingRange, mQuantShells,  pPntArrAimingPoints,
			CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints, iQuantAimingPoints);
			double valProbMonteCarlo  =CoastTargNeighbourhood0.estimateStrategy_MonteCarlo(mQuantIspit, piarrRepeatQuants);
			ia = (valProbMonteCarlo  * 1000);
			LabeledEdit12->Text  =(( double)ia)/ 1000.;


			///



	TURPointZ *pPointZ = new TURPointZ[iQuantAimingPoints];
	for (int i =0; i < iQuantAimingPoints; i++)
	{
		pPointZ[i].X = pPntArrAimingPoints[i].X;
		pPointZ[i].Y = pPntArrAimingPoints[i].Y;
		pPointZ[i].Z = (double)piarrRepeatQuants[i];
	}

		String s_25 = s_30 + L"AimingPoints_GSK_Z.shp";
		pPointZ[0].WriteSetSHPFiles(s_25.w_str(),pPointZ, iQuantAimingPoints) ;





		int iDim = pFigure ->calcDimension(20) ;
		if (iDim == 1)  // ��� �������� ����
		{

			// ���������� ���� �������� �������

			int num0 = -1,  num1 = -1;
		 //	double valDiam = TURPointXY::calcDiam(CoastTargNeighbourhood.mpPntArrTarg, CoastTargNeighbourhood.mQuantPointsTarg, &num0,  &num1);
			double valDiam = CoastTargNeighbourhood.mMultPntTarg.calcDiam(&num0,  &num1);
			double valAngRotate = -atan2(CoastTargNeighbourhood.mMultPntTarg.Points[num1].Y - CoastTargNeighbourhood.mMultPntTarg.Points[num0].Y
			,CoastTargNeighbourhood.mMultPntTarg.Points[num1].X - CoastTargNeighbourhood.mMultPntTarg.Points[num0].X);
			double *parrAimingPoints_X = new double[iQuantAimingPoints];
			memset(parrAimingPoints_X, 0, iQuantAimingPoints * sizeof(double));
			TURPointXY pnt0(0.,0.);
			TURPointXY pntSdvig0(- CoastTargNeighbourhood.mMultPntTarg.Points[num0].X, - CoastTargNeighbourhood.mMultPntTarg.Points[num0].Y);
			for (int i = 0; i < iQuantAimingPoints; i++)
			{
			// TURPointXY pnt(pPointZ[i].X - CoastTargNeighbourhood.mpPntArrTarg[num0].X, pPointZ[i].Y - CoastTargNeighbourhood.mpPntArrTarg[num0].Y);
			TURPointXY pnt(pPointZ[i].X + pntSdvig0.X, pPointZ[i].Y + pntSdvig0.Y);


			pnt.LinearTransformation(valAngRotate , pnt0,1. );

			parrAimingPoints_X [i]= pnt.X;
			pPntArrAimingPoints[i] =  pnt; // ����� ������������ � ���� ����
			int iiii=0;
			}


			////////
			//  �������� ���������� �������� ������ ����� ������������ �� ���� X , Y
			// �������� ��������� �� ��� X � ���� ����
			TURPolyLine plnDiagr_X = TURPolyLine::createLineDiagram(parrAimingPoints_X ,piarrRepeatQuants,iQuantAimingPoints);

			wchar_t wchFileLineDiagram_X0[300] ={0};
			wcscpy(wchFileLineDiagram_X0,  wchFoldName);
			wcscat(wchFileLineDiagram_X0, L"LineDiagram_X0.shp");
			plnDiagr_X.WriteSetSHPFiles(wchFileLineDiagram_X0,&plnDiagr_X, 1) ;
			plnDiagr_X = plnDiagr_X.MultScalar(-1. );

			//	mFight.mTarget.mpArrPlanePolygon[0].mPolygon.calcBoundBox();
			plnDiagr_X.calcBoundBox();
			double valYMin0 =  plnDiagr_X.Box[1];
			double valYMin = 0.;
			// mFight.mTarget.mpArrPlanePolygon[0].mPolygon.Box[1];
			///

			// ��� ���������

			//	TURPointXY pointBeginX(mFight.mTarget.mpArrPlanePolygon[0].mPolygon.Box[0] -10., 0.);
			TURPointXY pointBeginX(0. -10., 0.);
			//	TURPointXY pointEndX(mFight.mTarget.mpArrPlanePolygon[0].mPolygon.Box[2] + 10., 0.);
			TURPointXY pointEndX(valDiam + 10., 0.);
			TURPointXY pointBeginY(0., 0.);
			TURPointXY pointEndY(0., valYMin0 - 10.);
			TURPolyLine plnAxesX =  TURPolyLine::fncCreateAxes(pointBeginX, pointEndX
							 ,pointBeginY,  pointEndY,0.0001);
			///
			TURPointXY pntSdvig (0., valYMin - 10.);

			double  arrMtxPer[4] = {0.};
			double valTargCourse0 = -valAngRotate;
			arrMtxPer[0] = cos(valTargCourse0);
			arrMtxPer[1] = -sin(valTargCourse0);
			arrMtxPer[2] = -arrMtxPer[1];
			arrMtxPer[3] = cos(valTargCourse0);

			//	plnDiagr_X = plnDiagr_X.SdvigTransform( pntSdvig );
			//	plnDiagr_X = plnDiagr_X.fncLinTransform(arrMtxPer ) ;
			plnDiagr_X = plnDiagr_X.SdvigTransform( pntSdvig );
			plnDiagr_X.LinearTransformation(-valAngRotate , pnt0,1. );
			plnDiagr_X = plnDiagr_X.SdvigTransform( CoastTargNeighbourhood.mMultPntTarg.Points[num0] );


			plnAxesX = plnAxesX.SdvigTransform( pntSdvig );
			plnAxesX.LinearTransformation(-valAngRotate , pnt0,1. );
			plnAxesX = plnAxesX.SdvigTransform( CoastTargNeighbourhood.mMultPntTarg.Points[num0] );

			wchar_t wchFileLineDiagram_X[300] ={0}, wchFileAxesDiagram_X[300] ={0};
			wcscpy(  wchFileLineDiagram_X,  wchFoldName);
			wcscat(wchFileLineDiagram_X, L"LineDiagram_X.shp");
			plnDiagr_X.WriteSetSHPFiles(wchFileLineDiagram_X,&plnDiagr_X, 1) ;

			wcscpy(wchFileAxesDiagram_X,  wchFoldName);
			wcscat(wchFileAxesDiagram_X, L"Axes_X.shp");
			plnAxesX.WriteSetSHPFiles(wchFileAxesDiagram_X,&plnAxesX, 1) ;
			///

			// ���������� ������� ����������� ���������
			  // ���������� ������� ����������� ��������� ������ ����� ����

			   // ������� ����� ���� � ���� ����
				 double *parrTargPoints_X  = new double [CoastTargNeighbourhood.mMultPntTarg.NumPoints];
			for (int i = 0; i < CoastTargNeighbourhood.mMultPntTarg.NumPoints; i++)
			{

			TURPointXY pnt(CoastTargNeighbourhood.mMultPntTarg.Points[i].X + pntSdvig0.X, CoastTargNeighbourhood.mMultPntTarg.Points[i].Y + pntSdvig0.Y);
			pnt.LinearTransformation(valAngRotate , pnt0,1. );

			//parrTargPoints_X [i]= pnt.X;
			CoastTargNeighbourhood.mMultPntTarg.Points[i] = pnt;
			int iiii=0;
			}
			TURPointXY pnt1;
			pnt1.sortPointsArray_X (CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints);


			TCoastTargNeighbourhood CoastTargNeighbourhood0 ( arrMtrxCorrSum ,mKillingRange, mQuantShells,  pPntArrAimingPoints,
			CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints, iQuantAimingPoints);

			double *parrProb = new double[CoastTargNeighbourhood.mMultPntTarg.NumPoints];
			double *parrX = new double [iQuantAimingPoints];
			memset(parrX, 0, iQuantAimingPoints * sizeof(double));
			for (int i = 0; i < iQuantAimingPoints; i++)
			{
			parrX  [i] = ((double) piarrRepeatQuants[i]);
			}

			double *parr_L = new double [CoastTargNeighbourhood.mMultPntTarg.NumPoints  * iQuantAimingPoints ];
			CoastTargNeighbourhood0.createMatrxL(mKillingRange/ 10., parr_L) ;


			for (int j = 0; j < CoastTargNeighbourhood0.mMultPntTarg.NumPoints ; j++)
			{
			 parrProb[j] =  1. - CoastTargNeighbourhood0.calcFi_i(parr_L,parrX, j);

			}

			for (int i = 0; i < CoastTargNeighbourhood0.mMultPntTarg.NumPoints ; i++)
			{
				parrTargPoints_X [i]= CoastTargNeighbourhood0.mMultPntTarg.Points[i].X;
			}

			wchar_t wchFileGraphProb[300] ={0};
			wcscpy(  wchFileGraphProb,  wchFoldName);
			wcscat(wchFileGraphProb, L"GraphProb.shp");
		  //	plnDiagr_X.WriteSetSHPFiles(wchFileGraphProb,&plnDiagr_X, 1) ;
			 double scalex = 1.;
			 double scaley = 100.;
			TYrWriteShapeFile::CreateShpFile(wchFileGraphProb, parrProb, parrTargPoints_X
			,CoastTargNeighbourhood0.mMultPntTarg.NumPoints, scalex, scaley) ;

			wchar_t wchFileTargPoints0[300] ={0};
			wcscpy( wchFileTargPoints0,  wchFoldName);
			wcscat(wchFileTargPoints0, L"TargPoints0.shp");
			CoastTargNeighbourhood0.mMultPntTarg.Points[0].WriteSetSHPFiles(wchFileTargPoints0
			    ,CoastTargNeighbourhood0.mMultPntTarg.Points, CoastTargNeighbourhood0.mMultPntTarg.NumPoints) ;


			delete parrTargPoints_X;
			delete parr_L;
			delete parrProb;
			delete parrX;
			delete parrAimingPoints_X ;
			delete []pPntArrAimingPoints;
			delete piarrRepeatQuants ;
			return;
		}


		delete []pPointZ;


		if (typeid(*pFigure ).name() == typeid(Polygon00).name())// 2-������	 �������
		{
			TURPolygon *pPlgTarg_GSK =  (TURPolygon*)pFigure;
			double valTargCellSize = 5.;
			TYrRastr RastrProbab( *pPlgTarg_GSK, valTargCellSize,  1.);

			int quantTargPoints = RastrProbab.calcQuantValuablePiksels();

			TURPointXY *pPntArrTarg = new TURPointXY [quantTargPoints];
			int icur = 0;
			for (int j = 0; j < RastrProbab.ncols * RastrProbab.nrows; j++)
			{
			if (RastrProbab.pflt_rastr[j] > 0.)
			{
			pPntArrTarg[icur] =  RastrProbab.getCellCentre(j);
			icur++;
			}
			}



			TCoastTargNeighbourhood CoastTargNeighbourhood0 ( arrMtrxCorrSum ,mKillingRange, mQuantShells,  pPntArrAimingPoints,
			pPntArrTarg, quantTargPoints, iQuantAimingPoints);

			delete []pPntArrTarg;

			double *parrProb = new double[quantTargPoints];

			double *parrX = new double [iQuantAimingPoints];
			memset(parrX, 0, iQuantAimingPoints * sizeof(double));
			for (int i = 0; i < iQuantAimingPoints; i++)
			{
			parrX  [i] = ((double) piarrRepeatQuants[i]);
			}
			double *parr_L = new double [CoastTargNeighbourhood0.mMultPntTarg.NumPoints * CoastTargNeighbourhood0.mMultPntAim.NumPoints ];
			CoastTargNeighbourhood0.createMatrxL(mKillingRange/ 10., parr_L) ;

			icur = 0;
			for (int j = 0; j < RastrProbab.ncols * RastrProbab.nrows; j++)
			{
			if (RastrProbab.pflt_rastr[j] > 0.)
			{
			RastrProbab.pflt_rastr[j] =  1. - CoastTargNeighbourhood0.calcFi_i(parr_L,parrX, icur);

			icur++;
			}
			}

			String s_27 = s_30 + L"RastrProb.flt";
			RastrProbab.WriteMeAsFltFile(s_27.w_str());

			delete parrProb;
			delete parrX;
			delete parr_L;
			delete []pPntArrAimingPoints;
			delete piarrRepeatQuants ;
			return;
		}
		delete []pPntArrAimingPoints;
		delete piarrRepeatQuants ;
		//////////////////////////////////////////////////////////////////////////////////


}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button9Click(TObject *Sender)
{

		 wchar_t arwch[2] ={0};
			String s_22  =arwch;
			LabeledEdit4->Text  = -1;//s_22;
			LabeledEdit3->Text  = s_22;
			LabeledEdit5->Text  = s_22;
			LabeledEdit7->Text  = s_22;
		// �������� ���� � ����� � �������
		if (!mpwchSHP_TargFile) {
		if (I_ENTER_COUNT > 4)
		Close();

		ShowMessage(L"������� ���� � SHP ����� ����");
		I_ENTER_COUNT++;
		return;
		}


			// �������� ���� � ����� � �������
		if (!mpwch_PointZ_File_AimingPoints)
		{
		if (I_ENTER_COUNT > 4)
		Close();

		ShowMessage(L"������� ���� � ����� � ���������");
		I_ENTER_COUNT++;
		return;
		}




	   //	String wchFoldName = mwchOutFold;
	//	fncInputData() ;
	// InputGridData() ;
	 mKillingRange = sqrt(StrTo_Dbl_(Edit4->Text)/ M_PI );
	 mSigLocation = StrTo_Dbl_(Edit3->Text);
	 mQuantShells = StrToInt(Edit8->Text);
	 mQuantIspit =  StrToInt(LabeledEdit9->Text);
	 mAimCellSize = StrTo_Dbl_(Edit10->Text); // ��� ��� ������ ����������� ������������
	 mTargCellSize  = StrTo_Dbl_(Edit12->Text);

	 //double sigD = sqrt(mSig13GroupD * mSig13GroupD + mSig2GroupD * mSig2GroupD + mSigLocation* mSigLocation);
	// double sigBet = sqrt(mSig13GroupBet * mSig13GroupBet + mSig2GroupBet * mSig2GroupBet + mSigLocation* mSigLocation);
	 double arrMtrxCorrFluct[4] = {0.};
	 double arrMtrxCorrSyst[4] = {0.};
	 double arrMtrxCorrSum[4] ={0.};
	 arrMtrxCorrFluct [0] =  mSig2GroupD * mSig2GroupD ;
	 arrMtrxCorrFluct [3] =  mSig2GroupBet * mSig2GroupBet ;
	 arrMtrxCorrSyst[0] =  mSig13GroupD * mSig13GroupD +  mSigLocation* mSigLocation ;
	 arrMtrxCorrSyst [3] =  mSig13GroupBet * mSig13GroupBet + mSigLocation* mSigLocation;
	 MtrxSumMatrx(arrMtrxCorrFluct, arrMtrxCorrSyst,2, 2,arrMtrxCorrSum) ;



	// double arrMtrxCorr[4] ={0.};
	// arrMtrxCorr[3] = sigBet * sigBet;
	// arrMtrxCorr[0] = sigD * sigD;

 //	 TCoastTargNeighbourhood  CoastTargNeighbourhood ( mpwchSHP_TargFile ,
		//	mTargCellSize ,  mAimCellSize , arrMtrxCorr,
		//	mKillingRange, mQuantShells ) ;


	 // ����������� ���� ������� SHP � �-�� ��������
	 TURFigure  Figure, *pFigure;
	 int iShapeType = -1  // ���
	 , iObjQuant = -1;       // �-��
	 Figure.find_Objects_Type_And_Quant(mpwchSHP_TargFile, &iShapeType, &iObjQuant)  ;

	 int lenObjArr =1;
		TURPointXY *pPnt0 =  (TURPointXY *)malloc(sizeof( TURPointXY)* lenObjArr);
		TURPointXY **ppPnt0 = &pPnt0;

		TURPolyLine *pPln0 =  (TURPolyLine *)malloc(sizeof( TURPolyLine)* lenObjArr);
		TURPolyLine **ppPln0 = &pPln0;

		TURPolygon *pPlg0 =  (TURPolygon *)malloc(sizeof( TURPolygon)* lenObjArr);
		TURPolygon **ppPlg0 = &pPlg0;

		TURMultiPoint MultiPoint00, *pMultiPoint00;
	 ///



		TURPolygon Polygon00, *pPolygon00;
		TURPolyLine PolyLine00, *pPolyLine00;
		TURPointXY  PointXY00(1.,1.), *pPointXY00;
		switch(iShapeType)
		{
			case 1:
			TURPointXY::ReadSHPFile(mpwchSHP_TargFile,ppPnt0,  &iObjQuant) ;
			 MultiPoint00 =  TURMultiPoint(*ppPnt0, iObjQuant);
			 pMultiPoint00 = &MultiPoint00;
			 pFigure = (TURFigure*)(pMultiPoint00);
			break;

			case 3:
			TURPolyLine::ReadSHPFile(mpwchSHP_TargFile,ppPln0,  &iObjQuant) ;
			PolyLine00 =  TURPolyLine( *ppPln0, iObjQuant);
			pPolyLine00 = &PolyLine00;
			pFigure = (TURFigure*) (pPolyLine00);

			break;

			case 5:
			TURPolygon::ReadSHPFile(mpwchSHP_TargFile,ppPlg0,  &iObjQuant) ;
			Polygon00 = TURPolygon ( *ppPlg0, iObjQuant);
			pPolygon00 = &Polygon00 ;
			pFigure = (TURFigure*)(pPolygon00);

			break;

			default:
			ShowMessage(L"Error in Data SHP File");
			free(pPnt0);
			free(pPln0);
			free(pPlg0);
			return;

		}
			free(pPnt0);
			free(pPln0);
			free(pPlg0);

			// �������� �������   ����� URPointZ ����� ������������
			int quantPointsAims =1;
		TURPointZ  *pPointZ =  (TURPointZ *)malloc(sizeof( TURPointZ)* quantPointsAims);
		TURPointZ  **ppPointZ = &pPointZ;
			TURPointZ::ReadSHPFile(mpwch_PointZ_File_AimingPoints, ppPointZ,  &quantPointsAims) ;

			double *parrStrategy = new double [quantPointsAims];
			int *piarrStrategy = new int [quantPointsAims];
			TURPointXY *pPntArrAim = new  TURPointXY [quantPointsAims];
			for (int i = 0; i < quantPointsAims; i++)
			{
			 parrStrategy[i] = (*ppPointZ)[i].Z;
			 pPntArrAim[i].X =  (*ppPointZ)[i].X;
			 pPntArrAim[i].Y =  (*ppPointZ)[i].Y;
			 piarrStrategy[i] = int(parrStrategy[i] + 0.001);
			}


			 TCoastTargNeighbourhood CoastTargNeighbourhood(pFigure ,  	mTargCellSize,mAimCellSize
				, pPntArrAim, quantPointsAims, arrMtrxCorrFluct, arrMtrxCorrSyst
			 ,mKillingRange, mQuantShells ) ;

			 double valObj = (&CoastTargNeighbourhood)->calcEfficiencyOfStrategy_With_SystMtrx_Var1(parrStrategy) ;

			 double valProb  = ( ((double)(CoastTargNeighbourhood.mMultPntTarg.NumPoints)) -  valObj)
			 / ((double)(CoastTargNeighbourhood.mMultPntTarg.NumPoints));

			 double valProb_Monte_Carlo = CoastTargNeighbourhood.estimateStrategy_MonteCarlo(mQuantIspit, piarrStrategy);
			int	ia = (valProb * 1000);
			LabeledEdit10->Text  =(( double)ia)/ 1000.;

			ia = (valProb_Monte_Carlo * 1000);
			LabeledEdit14->Text  =(( double)ia)/ 1000.;

			double valShootsQuant = 0.;
			for (int i = 0; i < quantPointsAims; i++)
			{
				valShootsQuant +=  parrStrategy[i];
			}

			if(valShootsQuant!= mQuantShells)
			{
			ShowMessage(L"ERROR in .SHP POINTZ: valShootsQuant!= mQuantShells\Check POintZ file");
			}
			ia = valShootsQuant;
			LabeledEdit11->Text  = ia;

		wchar_t wchFoldName[300] ={0}, wchOutFold[300] = {0};
		wcscpy(wchOutFold, mpwchOutFileForPointGroupTarg);
		wchar_t *pwchr = wcsrchr(wchOutFold, L'\\');
		pwchr[0] = 0;


	wcscpy(  wchFoldName,  wchOutFold);
	wcscat(wchFoldName, L"\\");
	const String s_30 = wchFoldName;


			String s_31 = s_30 + L"TargPntArray.shp";
			TURPointXY::WriteSetSHPFiles(s_31.w_str(), CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints);

			s_31 = s_30 + L"AimPntArray.shp";
			TURPointXY::WriteSetSHPFiles(s_31.w_str()  , CoastTargNeighbourhood.mMultPntAim.Points,CoastTargNeighbourhood.mMultPntAim.NumPoints);
			 //	�������� ���� �������:
			const	double VAlPsi =0.;
			///
			createNibourAppointmPointPictureForCoastTarg(wchOutFold,arrMtrxCorrSum
			, pFigure, 0., VAlPsi);

			int iDim = pFigure ->calcDimension(20) ;
			if (iDim == 1)
		{

			// ���������� ���� �������� �������

			int num0 = -1,  num1 = -1;
		//double valDiam = TURPointXY::calcDiam(CoastTargNeighbourhood.mpPntArrTarg, CoastTargNeighbourhood.mQuantPointsTarg, &num0,  &num1);
			double valDiam = CoastTargNeighbourhood.mMultPntTarg.calcDiam(&num0,  &num1);
			double valAngRotate = -atan2(CoastTargNeighbourhood.mMultPntTarg.Points[num1].Y - CoastTargNeighbourhood.mMultPntTarg.Points[num0].Y
			,CoastTargNeighbourhood.mMultPntTarg.Points[num1].X - CoastTargNeighbourhood.mMultPntTarg.Points[num0].X);
			double *parrAimingPoints_X = new double[quantPointsAims];
			memset(parrAimingPoints_X, 0, quantPointsAims * sizeof(double));
			TURPointXY pnt0(0.,0.);
			TURPointXY pntSdvig0(- CoastTargNeighbourhood.mMultPntTarg.Points[num0].X, - CoastTargNeighbourhood.mMultPntTarg.Points[num0].Y);
			for (int i = 0; i < quantPointsAims; i++)
			{
			// TURPointXY pnt(pPointZ[i].X - CoastTargNeighbourhood.mpPntArrTarg[num0].X, pPointZ[i].Y - CoastTargNeighbourhood.mpPntArrTarg[num0].Y);
			TURPointXY pnt(pPointZ[i].X + pntSdvig0.X, pPointZ[i].Y + pntSdvig0.Y);


			pnt.LinearTransformation(valAngRotate , pnt0,1. );

			parrAimingPoints_X [i]= pnt.X;
			pPntArrAim[i] =  pnt; // ����� ������������ � ���� ����
			int iiii=0;
			}


			////////

			// ���������� ������� ����������� ���������
			  // ���������� ������� ����������� ��������� ������ ����� ����

			   // ������� ����� ���� � ���� ����
				 double *parrTargPoints_X  = new double [CoastTargNeighbourhood.mMultPntTarg.NumPoints];
			for (int i = 0; i < CoastTargNeighbourhood.mMultPntTarg.NumPoints; i++)
			{

			TURPointXY pnt(CoastTargNeighbourhood.mMultPntTarg.Points[i].X + pntSdvig0.X, CoastTargNeighbourhood.mMultPntTarg.Points[i].Y + pntSdvig0.Y);
			pnt.LinearTransformation(valAngRotate , pnt0,1. );

			//parrTargPoints_X [i]= pnt.X;
			CoastTargNeighbourhood.mMultPntTarg.Points[i] = pnt;
			int iiii=0;
			}
			TURPointXY pnt1;
			pnt1.sortPointsArray_X (CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints);


			TCoastTargNeighbourhood CoastTargNeighbourhood0 ( arrMtrxCorrSum ,mKillingRange, mQuantShells,  pPntArrAim,
			CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints, quantPointsAims);

			double *parrProb = new double[CoastTargNeighbourhood.mMultPntTarg.NumPoints];


			double *parr_L = new double [CoastTargNeighbourhood.mMultPntTarg.NumPoints  * quantPointsAims ];
			CoastTargNeighbourhood0.createMatrxL(mKillingRange/ 10., parr_L) ;


			for (int j = 0; j < CoastTargNeighbourhood0.mMultPntTarg.NumPoints; j++)
			{
			 parrProb[j] =  1. - CoastTargNeighbourhood0.calcFi_i(parr_L,parrStrategy, j);

			}

			for (int i = 0; i < CoastTargNeighbourhood0.mMultPntTarg.NumPoints; i++)
			{
				parrTargPoints_X [i]= CoastTargNeighbourhood0.mMultPntTarg.Points[i].X;
			}

			wchar_t wchFileGraphProb[300] ={0};
			wcscpy(  wchFileGraphProb,  wchFoldName);
			wcscat(wchFileGraphProb, L"GraphProb.shp");
		  //	plnDiagr_X.WriteSetSHPFiles(wchFileGraphProb,&plnDiagr_X, 1) ;
			 double scalex = 1.;
			 double scaley = 100.;
			TYrWriteShapeFile::CreateShpFile(wchFileGraphProb, parrProb, parrTargPoints_X
			,CoastTargNeighbourhood0.mMultPntTarg.NumPoints, scalex, scaley) ;

			wchar_t wchFileTargPoints0[300] ={0};
			wcscpy( wchFileTargPoints0,  wchFoldName);
			wcscat(wchFileTargPoints0, L"TargPoints0.shp");
			 CoastTargNeighbourhood0.mMultPntTarg.Points[0].WriteSetSHPFiles(wchFileTargPoints0
			 ,CoastTargNeighbourhood0.mMultPntTarg.Points, CoastTargNeighbourhood0.mMultPntTarg.NumPoints) ;


			delete parrTargPoints_X;
			delete parr_L;
			delete parrProb;
		//delete parrX;
			delete parrAimingPoints_X ;
			delete []pPntArrAim;
			delete  parrStrategy;
			delete piarrStrategy;

			 free(pPointZ );
			return;
		}


		if (typeid(*pFigure ).name() == typeid(Polygon00).name())// 2-������	 �������
		{
			TURPolygon *pPlgTarg_GSK =  (TURPolygon*)pFigure;
			double valTargCellSize = 5.;
			TYrRastr RastrProbab( *pPlgTarg_GSK, valTargCellSize,  1.);

			int quantTargPoints = RastrProbab.calcQuantValuablePiksels();

			TURPointXY *pPntArrTarg = new TURPointXY [quantTargPoints];
			int icur = 0;
			for (int j = 0; j < RastrProbab.ncols * RastrProbab.nrows; j++)
			{
			if (RastrProbab.pflt_rastr[j] > 0.)
			{
			pPntArrTarg[icur] =  RastrProbab.getCellCentre(j);
			icur++;
			}
			}



			TCoastTargNeighbourhood CoastTargNeighbourhood0 ( arrMtrxCorrSum ,mKillingRange, mQuantShells,  pPntArrAim,
			pPntArrTarg, quantTargPoints, quantPointsAims);

			delete []pPntArrTarg;

		   //	double *parrProb = new double[quantTargPoints];

		   //	double *parrX = new double [quantPointsAims];
		  //	memset(parrX, 0, quantPointsAims * sizeof(double));
		   //	for (int i = 0; i < quantPointsAims; i++)
		   //	{
		   //	parrX  [i] = ((double) piarrRepeatQuants[i]);
		   //	}
			double *parr_L = new double [CoastTargNeighbourhood0.mMultPntTarg.NumPoints  * CoastTargNeighbourhood0.mMultPntAim.NumPoints ];
			CoastTargNeighbourhood0.createMatrxL(mKillingRange/ 10., parr_L) ;

			icur = 0;
			for (int j = 0; j < RastrProbab.ncols * RastrProbab.nrows; j++)
			{
			if (RastrProbab.pflt_rastr[j] > 0.)
			{
			RastrProbab.pflt_rastr[j] =  1. - CoastTargNeighbourhood0.calcFi_i(parr_L,parrStrategy, icur);

			icur++;
			}
			}

			String s_27 = s_30 + L"RastrProb.flt";
			RastrProbab.WriteMeAsFltFile(s_27.w_str());

		  //	delete parrProb;
		   //	delete parrX;
			delete parr_L;
			delete  parrStrategy;
			 delete  []pPntArrAim;
			 free(pPointZ );
			 //	delete []pPntArrAimingPoints;
		   //	delete piarrRepeatQuants ;
			return;
		}


			 delete  parrStrategy;
			 delete  []pPntArrAim;
			 free(pPointZ );
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button8Click(TObject *Sender)
{
	OpenDialog4->Filter = L"����� � ��������� (*.shp)|*.shp" ;

	if (OpenDialog4->Execute())
	{
	mpwch_PointZ_File_AimingPoints =  (OpenDialog4->FileName).w_str();

	}
	Edit15->Text =  mpwch_PointZ_File_AimingPoints;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{

	OpenDialog5->Filter = L"����� � ��������� (*.shp)|*.shp" ;

	if (OpenDialog5->Execute())
	{
	mpwchOutFileForPointGroupTarg =  (OpenDialog5->FileName).w_str();

	}
	Edit14->Text =  mpwchOutFileForPointGroupTarg;


}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button10Click(TObject *Sender)
{

	wchar_t arwch[2] ={0};
			String s_22  =arwch;
			LabeledEdit4->Text  = -1;//s_22;
			LabeledEdit3->Text  = s_22;
			LabeledEdit5->Text  = s_22;
			LabeledEdit7->Text  = s_22;
		// �������� ���� � ����� � �������
		if (!mpwchSHP_TargFile) {
		if (I_ENTER_COUNT > 4)
		Close();

		ShowMessage(L"������� ���� � SHP ����� ����");
		I_ENTER_COUNT++;
		return;
		}


			// �������� ���� � ����� � �������
		if (!mpwchOutFileForPointGroupTarg)
		{
		if (I_ENTER_COUNT > 4)
		Close();

		ShowMessage(L"������� ���� � ����� � ���������");
		I_ENTER_COUNT++;
		return;
		}

		wchar_t wchFoldName[300] ={0}, wchOutFold[300] = {0};
		wcscpy(wchOutFold, mpwchOutFileForPointGroupTarg);
		wchar_t *pwchr = wcsrchr(wchOutFold, L'\\');
		pwchr[0] = 0;


	wcscpy(  wchFoldName,  wchOutFold);
	wcscat(wchFoldName, L"\\");

	 //	String wchFoldName = mwchOutFold;
	//	fncInputData() ;
	 InputGridData() ;
	 mKillingRange = sqrt(StrTo_Dbl_(Edit4->Text)/ M_PI );
	 mSigLocation = StrTo_Dbl_(Edit3->Text);
	 mQuantShells = StrToInt(Edit8->Text);
	 mQuantIspit =  StrToInt(LabeledEdit9->Text);
	 mAimCellSize = StrTo_Dbl_(Edit10->Text); //  ��� ������������� SHP ������� ������������ ���  ������������� ��� � ������ �����
	 mTargCellSize  = StrTo_Dbl_(Edit12->Text);


	 double arrMtrxCorrFluct[4] = {0.};
	 double arrMtrxCorrSyst[4] = {0.};
	 double arrMtrxCorrSum[4] ={0.};
	 arrMtrxCorrFluct [0] =  mSig2GroupD * mSig2GroupD ;
	 arrMtrxCorrFluct [3] =  mSig2GroupBet * mSig2GroupBet ;
	 arrMtrxCorrSyst[0] =  mSig13GroupD * mSig13GroupD +  mSigLocation* mSigLocation ;
	 arrMtrxCorrSyst [3] =  mSig13GroupBet * mSig13GroupBet + mSigLocation* mSigLocation;
	 MtrxSumMatrx(arrMtrxCorrFluct, arrMtrxCorrSyst,2, 2,arrMtrxCorrSum) ;



	 // ����������� ���� ������� SHP � �-�� ��������
	 TURFigure  Figure, *pFigure;
	 int iShapeType = -1  // ���
	 , iObjQuant = -1;       // �-��
	 Figure.find_Objects_Type_And_Quant(mpwchSHP_TargFile, &iShapeType, &iObjQuant)  ;

	 int lenObjArr =1;
		TURPointXY *pPnt0 =  (TURPointXY *)malloc(sizeof( TURPointXY)* lenObjArr);
		TURPointXY **ppPnt0 = &pPnt0;

		TURPolyLine *pPln0 =  (TURPolyLine *)malloc(sizeof( TURPolyLine)* lenObjArr);
		TURPolyLine **ppPln0 = &pPln0;

		TURPolygon *pPlg0 =  (TURPolygon *)malloc(sizeof( TURPolygon)* lenObjArr);
		TURPolygon **ppPlg0 = &pPlg0;

		TURMultiPoint MultiPoint00, *pMultiPoint00;
	 ///



		TURPolygon Polygon00, *pPolygon00;
		TURPolyLine PolyLine00, *pPolyLine00;
		TURPointXY  PointXY00(1.,1.), *pPointXY00;
		switch(iShapeType)
		{
			case 1:
			TURPointXY::ReadSHPFile(mpwchSHP_TargFile,ppPnt0,  &iObjQuant) ;
			 MultiPoint00 =  TURMultiPoint(*ppPnt0, iObjQuant);
			 pMultiPoint00 = &MultiPoint00;
			 pFigure = (TURFigure*)(pMultiPoint00);
			break;

			case 3:
			TURPolyLine::ReadSHPFile(mpwchSHP_TargFile,ppPln0,  &iObjQuant) ;
			PolyLine00 =  TURPolyLine( *ppPln0, iObjQuant);
			pPolyLine00 = &PolyLine00;
			pFigure = (TURFigure*) (pPolyLine00);

			break;

			case 5:
			TURPolygon::ReadSHPFile(mpwchSHP_TargFile,ppPlg0,  &iObjQuant) ;
			Polygon00 = TURPolygon ( *ppPlg0, iObjQuant);
			pPolygon00 = &Polygon00 ;
			pFigure = (TURFigure*)(pPolygon00);

			break;

			default:
			ShowMessage(L"Error in Data SHP File");
			free(pPnt0);
			free(pPln0);
			free(pPlg0);
			return;

		}
			free(pPnt0);
			free(pPln0);
			free(pPlg0);



			 TCoastTargNeighbourhood  CoastTargNeighbourhood ( pFigure ,
				mTargCellSize ,  mAimCellSize , arrMtrxCorrFluct, arrMtrxCorrSyst
			 ,mKillingRange, mQuantShells, 1.) ;
			const String s_30 = wchFoldName;
			String s_31 = s_30 + L"TargPntArray.shp";
			TURPointXY::WriteSetSHPFiles(s_31.w_str()  , CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints);

			s_31 = s_30 + L"AimPntArray.shp";
			TURPointXY::WriteSetSHPFiles(s_31.w_str()  , CoastTargNeighbourhood.mMultPntAim.Points, CoastTargNeighbourhood.mMultPntAim.NumPoints);
			 //	�������� ���� �������:
			const	double VAlPsi =0.;
			///
			createNibourAppointmPointPictureForCoastTarg(wchOutFold,arrMtrxCorrFluct, arrMtrxCorrSyst
			, pFigure, 0., VAlPsi);


				s_31 = s_30 + L"RstrBiasAims.flt";
			CoastTargNeighbourhood.mRstrBiasAims.WriteMeAsFltFile(s_31.w_str());
			///
			///




			double valObj = -1;
			TURPointXY *pPntArrAimingPoints = new TURPointXY[CoastTargNeighbourhood.mMultPntAim.NumPoints];
			int *piarrRepeatQuants = new int [CoastTargNeighbourhood.mMultPntAim.NumPoints];
			memset( pPntArrAimingPoints, 0, CoastTargNeighbourhood.mMultPntAim.NumPoints * sizeof(TURPointXY));
			memset ( piarrRepeatQuants, 0, CoastTargNeighbourhood.mMultPntAim.NumPoints * sizeof(int));
			int iQuantAimingPoints = -1;

			CoastTargNeighbourhood.calcOptimalArray_Of_AimPoints_With_SystMtrx( pPntArrAimingPoints
			,&iQuantAimingPoints, piarrRepeatQuants, &valObj) ;


			double valProb  = ( ((double)(CoastTargNeighbourhood.mMultPntTarg.NumPoints)) -  valObj)
				/ ((double)(CoastTargNeighbourhood.mMultPntTarg.NumPoints));
			int	ia = (valProb * 1000);
			LabeledEdit8->Text  =(( double)ia)/ 1000.;
			int iii=0;

			// ����� �����-�����
			TCoastTargNeighbourhood CoastTargNeighbourhood0 ( arrMtrxCorrFluct, arrMtrxCorrSyst, mKillingRange, mQuantShells,  pPntArrAimingPoints,
			CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints, iQuantAimingPoints);
			double valProbMonteCarlo  =CoastTargNeighbourhood0.estimateStrategy_MonteCarlo(mQuantIspit, piarrRepeatQuants);
			ia = (valProbMonteCarlo  * 1000);
			LabeledEdit12->Text  =(( double)ia)/ 1000.;


			///



	TURPointZ *pPointZ = new TURPointZ[iQuantAimingPoints];
	for (int i =0; i < iQuantAimingPoints; i++)
	{
		pPointZ[i].X = pPntArrAimingPoints[i].X;
		pPointZ[i].Y = pPntArrAimingPoints[i].Y;
		pPointZ[i].Z = (double)piarrRepeatQuants[i];
	}

		String s_25 = s_30 + L"AimingPoints_GSK_Z.shp";
		pPointZ[0].WriteSetSHPFiles(s_25.w_str(),pPointZ, iQuantAimingPoints) ;





		int iDim = pFigure ->calcDimension(20) ;
		if (iDim == 1)  // ��� �������� ����
		{

			// ���������� ���� �������� �������

			int num0 = -1,  num1 = -1;
		 //	double valDiam = TURPointXY::calcDiam(CoastTargNeighbourhood.mpPntArrTarg, CoastTargNeighbourhood.mQuantPointsTarg, &num0,  &num1);
			double valDiam = CoastTargNeighbourhood.mMultPntTarg.calcDiam(&num0,  &num1);
			double valAngRotate = -atan2(CoastTargNeighbourhood.mMultPntTarg.Points[num1].Y - CoastTargNeighbourhood.mMultPntTarg.Points[num0].Y
			,CoastTargNeighbourhood.mMultPntTarg.Points[num1].X - CoastTargNeighbourhood.mMultPntTarg.Points[num0].X);
			double *parrAimingPoints_X = new double[iQuantAimingPoints];
			memset(parrAimingPoints_X, 0, iQuantAimingPoints * sizeof(double));
			TURPointXY pnt0(0.,0.);
			TURPointXY pntSdvig0(- CoastTargNeighbourhood.mMultPntTarg.Points[num0].X, - CoastTargNeighbourhood.mMultPntTarg.Points[num0].Y);
			for (int i = 0; i < iQuantAimingPoints; i++)
			{
			// TURPointXY pnt(pPointZ[i].X - CoastTargNeighbourhood.mpPntArrTarg[num0].X, pPointZ[i].Y - CoastTargNeighbourhood.mpPntArrTarg[num0].Y);
			TURPointXY pnt(pPointZ[i].X + pntSdvig0.X, pPointZ[i].Y + pntSdvig0.Y);


			pnt.LinearTransformation(valAngRotate , pnt0,1. );

			parrAimingPoints_X [i]= pnt.X;
			pPntArrAimingPoints[i] =  pnt; // ����� ������������ � ���� ����
			int iiii=0;
			}


			////////
			//  �������� ���������� �������� ������ ����� ������������ �� ���� X , Y
			// �������� ��������� �� ��� X � ���� ����
			TURPolyLine plnDiagr_X = TURPolyLine::createLineDiagram(parrAimingPoints_X ,piarrRepeatQuants,iQuantAimingPoints);

			wchar_t wchFileLineDiagram_X0[300] ={0};
			wcscpy(wchFileLineDiagram_X0,  wchFoldName);
			wcscat(wchFileLineDiagram_X0, L"LineDiagram_X0.shp");
			plnDiagr_X.WriteSetSHPFiles(wchFileLineDiagram_X0,&plnDiagr_X, 1) ;
			plnDiagr_X = plnDiagr_X.MultScalar(-1. );

			//	mFight.mTarget.mpArrPlanePolygon[0].mPolygon.calcBoundBox();
			plnDiagr_X.calcBoundBox();
			double valYMin0 =  plnDiagr_X.Box[1];
			double valYMin = 0.;
			// mFight.mTarget.mpArrPlanePolygon[0].mPolygon.Box[1];
			///

			// ��� ���������

			//	TURPointXY pointBeginX(mFight.mTarget.mpArrPlanePolygon[0].mPolygon.Box[0] -10., 0.);
			TURPointXY pointBeginX(0. -10., 0.);
			//	TURPointXY pointEndX(mFight.mTarget.mpArrPlanePolygon[0].mPolygon.Box[2] + 10., 0.);
			TURPointXY pointEndX(valDiam + 10., 0.);
			TURPointXY pointBeginY(0., 0.);
			TURPointXY pointEndY(0., valYMin0 - 10.);
			TURPolyLine plnAxesX =  TURPolyLine::fncCreateAxes(pointBeginX, pointEndX
							 ,pointBeginY,  pointEndY,0.0001);
			///
			TURPointXY pntSdvig (0., valYMin - 10.);

			double  arrMtxPer[4] = {0.};
			double valTargCourse0 = -valAngRotate;
			arrMtxPer[0] = cos(valTargCourse0);
			arrMtxPer[1] = -sin(valTargCourse0);
			arrMtxPer[2] = -arrMtxPer[1];
			arrMtxPer[3] = cos(valTargCourse0);

			//	plnDiagr_X = plnDiagr_X.SdvigTransform( pntSdvig );
			//	plnDiagr_X = plnDiagr_X.fncLinTransform(arrMtxPer ) ;
			plnDiagr_X = plnDiagr_X.SdvigTransform( pntSdvig );
			plnDiagr_X.LinearTransformation(-valAngRotate , pnt0,1. );
			plnDiagr_X = plnDiagr_X.SdvigTransform( CoastTargNeighbourhood.mMultPntTarg.Points[num0] );


			plnAxesX = plnAxesX.SdvigTransform( pntSdvig );
			plnAxesX.LinearTransformation(-valAngRotate , pnt0,1. );
			plnAxesX = plnAxesX.SdvigTransform( CoastTargNeighbourhood.mMultPntTarg.Points[num0] );

			wchar_t wchFileLineDiagram_X[300] ={0}, wchFileAxesDiagram_X[300] ={0};
			wcscpy(  wchFileLineDiagram_X,  wchFoldName);
			wcscat(wchFileLineDiagram_X, L"LineDiagram_X.shp");
			plnDiagr_X.WriteSetSHPFiles(wchFileLineDiagram_X,&plnDiagr_X, 1) ;

			wcscpy(wchFileAxesDiagram_X,  wchFoldName);
			wcscat(wchFileAxesDiagram_X, L"Axes_X.shp");
			plnAxesX.WriteSetSHPFiles(wchFileAxesDiagram_X,&plnAxesX, 1) ;
			///

			// ���������� ������� ����������� ���������
			  // ���������� ������� ����������� ��������� ������ ����� ����

			   // ������� ����� ���� � ���� ����
				 double *parrTargPoints_X  = new double [CoastTargNeighbourhood.mMultPntTarg.NumPoints];
			for (int i = 0; i < CoastTargNeighbourhood.mMultPntTarg.NumPoints; i++)
			{

			TURPointXY pnt(CoastTargNeighbourhood.mMultPntTarg.Points[i].X + pntSdvig0.X, CoastTargNeighbourhood.mMultPntTarg.Points[i].Y + pntSdvig0.Y);
			pnt.LinearTransformation(valAngRotate , pnt0,1. );

			//parrTargPoints_X [i]= pnt.X;
			CoastTargNeighbourhood.mMultPntTarg.Points[i] = pnt;
			int iiii=0;
			}
			TURPointXY pnt1;
			pnt1.sortPointsArray_X (CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints);


			TCoastTargNeighbourhood CoastTargNeighbourhood0 ( arrMtrxCorrSum ,mKillingRange, mQuantShells,  pPntArrAimingPoints,
			CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints, iQuantAimingPoints);

			double *parrProb = new double[CoastTargNeighbourhood.mMultPntTarg.NumPoints];
			double *parrX = new double [iQuantAimingPoints];
			memset(parrX, 0, iQuantAimingPoints * sizeof(double));
			for (int i = 0; i < iQuantAimingPoints; i++)
			{
			parrX  [i] = ((double) piarrRepeatQuants[i]);
			}

			double *parr_L = new double [CoastTargNeighbourhood.mMultPntTarg.NumPoints  * iQuantAimingPoints ];
			CoastTargNeighbourhood0.createMatrxL(mKillingRange/ 10., parr_L) ;


			for (int j = 0; j < CoastTargNeighbourhood.mMultPntTarg.NumPoints; j++)
			{
			 parrProb[j] =  1. - CoastTargNeighbourhood0.calcFi_i(parr_L,parrX, j);

			}

			for (int i = 0; i < CoastTargNeighbourhood0.mMultPntTarg.NumPoints; i++)
			{
				parrTargPoints_X [i]= CoastTargNeighbourhood0.mMultPntTarg.Points[i].X;
			}

			wchar_t wchFileGraphProb[300] ={0};
			wcscpy(  wchFileGraphProb,  wchFoldName);
			wcscat(wchFileGraphProb, L"GraphProb.shp");
		  //	plnDiagr_X.WriteSetSHPFiles(wchFileGraphProb,&plnDiagr_X, 1) ;
			 double scalex = 1.;
			 double scaley = 100.;
			TYrWriteShapeFile::CreateShpFile(wchFileGraphProb, parrProb, parrTargPoints_X
			,CoastTargNeighbourhood0.mMultPntTarg.NumPoints, scalex, scaley) ;

			wchar_t wchFileTargPoints0[300] ={0};
			wcscpy( wchFileTargPoints0,  wchFoldName);
			wcscat(wchFileTargPoints0, L"TargPoints0.shp");
			 CoastTargNeighbourhood0.mMultPntTarg.Points[0].WriteSetSHPFiles(wchFileTargPoints0
			 ,CoastTargNeighbourhood0.mMultPntTarg.Points, CoastTargNeighbourhood0.mMultPntTarg.NumPoints) ;


			delete parrTargPoints_X;
			delete parr_L;
			delete parrProb;
			delete parrX;
			delete parrAimingPoints_X ;
			delete []pPntArrAimingPoints;
			delete piarrRepeatQuants ;
			return;
		}


		delete []pPointZ;


		if (typeid(*pFigure ).name() == typeid(Polygon00).name())// 2-������	 �������
		{
			TURPolygon *pPlgTarg_GSK =  (TURPolygon*)pFigure;
			double valTargCellSize = 5.;
			TYrRastr RastrProbab( *pPlgTarg_GSK, valTargCellSize,  1.);

			int quantTargPoints = RastrProbab.calcQuantValuablePiksels();

			TURPointXY *pPntArrTarg = new TURPointXY [quantTargPoints];
			int icur = 0;
			for (int j = 0; j < RastrProbab.ncols * RastrProbab.nrows; j++)
			{
			if (RastrProbab.pflt_rastr[j] > 0.)
			{
			pPntArrTarg[icur] =  RastrProbab.getCellCentre(j);
			icur++;
			}
			}



			TCoastTargNeighbourhood CoastTargNeighbourhood0 ( arrMtrxCorrSum ,mKillingRange, mQuantShells,  pPntArrAimingPoints,
			pPntArrTarg, quantTargPoints, iQuantAimingPoints);

			delete []pPntArrTarg;

			double *parrProb = new double[quantTargPoints];

			double *parrX = new double [iQuantAimingPoints];
			memset(parrX, 0, iQuantAimingPoints * sizeof(double));
			for (int i = 0; i < iQuantAimingPoints; i++)
			{
			parrX  [i] = ((double) piarrRepeatQuants[i]);
			}
			double *parr_L = new double [CoastTargNeighbourhood0.mMultPntTarg.NumPoints  * CoastTargNeighbourhood0.mMultPntAim.NumPoints];
			CoastTargNeighbourhood0.createMatrxL(mKillingRange/ 10., parr_L) ;

			icur = 0;
			for (int j = 0; j < RastrProbab.ncols * RastrProbab.nrows; j++)
			{
			if (RastrProbab.pflt_rastr[j] > 0.)
			{
			RastrProbab.pflt_rastr[j] =  1. - CoastTargNeighbourhood0.calcFi_i(parr_L,parrX, icur);

			icur++;
			}
			}

			String s_27 = s_30 + L"RastrProb.flt";
			RastrProbab.WriteMeAsFltFile(s_27.w_str());

			delete parrProb;
			delete parrX;
			delete parr_L;
			delete []pPntArrAimingPoints;
			delete piarrRepeatQuants ;
			return;
		}
		delete []pPntArrAimingPoints;
		delete piarrRepeatQuants ;
		//////////////////////////////////////////////////////////////////////////////////

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button11Click(TObject *Sender)
{

	wchar_t arwch[2] ={0};
			String s_22  =arwch;
			LabeledEdit4->Text  = -1;//s_22;
			LabeledEdit3->Text  = s_22;
			LabeledEdit5->Text  = s_22;
			LabeledEdit7->Text  = s_22;
		// �������� ���� � ����� � �������
		if (!mpwchSHP_TargFile) {
		if (I_ENTER_COUNT > 4)
		Close();

		ShowMessage(L"������� ���� � SHP ����� ����");
		I_ENTER_COUNT++;
		return;
		}


			// �������� ���� � ����� � �������
		if (!mpwchOutFileForPointGroupTarg)
		{
		if (I_ENTER_COUNT > 4)
		Close();

		ShowMessage(L"������� ���� � ����� � ���������");
		I_ENTER_COUNT++;
		return;
		}

		wchar_t wchFoldName[300] ={0}, wchOutFold[300] = {0};
		wcscpy(wchOutFold, mpwchOutFileForPointGroupTarg);
		wchar_t *pwchr = wcsrchr(wchOutFold, L'\\');
		pwchr[0] = 0;


	wcscpy(  wchFoldName,  wchOutFold);
	wcscat(wchFoldName, L"\\");

	 //	String wchFoldName = mwchOutFold;
	//	fncInputData() ;
	 InputGridData() ;
	 mKillingRange = sqrt(StrTo_Dbl_(Edit4->Text)/ M_PI );
	 mSigLocation = StrTo_Dbl_(Edit3->Text);
	 mQuantShells = StrToInt(Edit8->Text);
	 mQuantIspit =  StrToInt(LabeledEdit9->Text);
	 mAimCellSize = StrTo_Dbl_(Edit10->Text); //  ��� ������������� SHP ������� ������������ ���  ������������� ��� � ������ �����
	 mTargCellSize  = StrTo_Dbl_(Edit12->Text);


	 double arrMtrxCorrFluct[4] = {0.};
	 double arrMtrxCorrSyst[4] = {0.};
	 double arrMtrxCorrSum[4] ={0.};
	 arrMtrxCorrFluct [0] =  mSig2GroupD * mSig2GroupD ;
	 arrMtrxCorrFluct [3] =  mSig2GroupBet * mSig2GroupBet ;
	 arrMtrxCorrSyst[0] =  mSig13GroupD * mSig13GroupD +  mSigLocation* mSigLocation ;
	 arrMtrxCorrSyst [3] =  mSig13GroupBet * mSig13GroupBet + mSigLocation* mSigLocation;
	 MtrxSumMatrx(arrMtrxCorrFluct, arrMtrxCorrSyst,2, 2,arrMtrxCorrSum) ;



	 // ����������� ���� ������� SHP � �-�� ��������
	 TURFigure  Figure, *pFigure;
	 int iShapeType = -1  // ���
	 , iObjQuant = -1;       // �-��
	 Figure.find_Objects_Type_And_Quant(mpwchSHP_TargFile, &iShapeType, &iObjQuant)  ;

	 int lenObjArr =1;
		TURPointXY *pPnt0 =  (TURPointXY *)malloc(sizeof( TURPointXY)* lenObjArr);
		TURPointXY **ppPnt0 = &pPnt0;

		TURPolyLine *pPln0 =  (TURPolyLine *)malloc(sizeof( TURPolyLine)* lenObjArr);
		TURPolyLine **ppPln0 = &pPln0;

		TURPolygon *pPlg0 =  (TURPolygon *)malloc(sizeof( TURPolygon)* lenObjArr);
		TURPolygon **ppPlg0 = &pPlg0;

		TURMultiPoint MultiPoint00, *pMultiPoint00;
	 ///



		TURPolygon Polygon00, *pPolygon00;
		TURPolyLine PolyLine00, *pPolyLine00;
		TURPointXY  PointXY00(1.,1.), *pPointXY00;
		switch(iShapeType)
		{
			case 1:
			TURPointXY::ReadSHPFile(mpwchSHP_TargFile,ppPnt0,  &iObjQuant) ;
			 MultiPoint00 =  TURMultiPoint(*ppPnt0, iObjQuant);
			 pMultiPoint00 = &MultiPoint00;
			 pFigure = (TURFigure*)(pMultiPoint00);
			break;

			case 3:
			TURPolyLine::ReadSHPFile(mpwchSHP_TargFile,ppPln0,  &iObjQuant) ;
			PolyLine00 =  TURPolyLine( *ppPln0, iObjQuant);
			pPolyLine00 = &PolyLine00;
			pFigure = (TURFigure*) (pPolyLine00);

			break;

			case 5:
			TURPolygon::ReadSHPFile(mpwchSHP_TargFile,ppPlg0,  &iObjQuant) ;
			Polygon00 = TURPolygon ( *ppPlg0, iObjQuant);
			pPolygon00 = &Polygon00 ;
			pFigure = (TURFigure*)(pPolygon00);

			break;

			default:
			ShowMessage(L"Error in Data SHP File");
			free(pPnt0);
			free(pPln0);
			free(pPlg0);
			return;

		}
			free(pPnt0);
			free(pPln0);
			free(pPlg0);



			 TCoastTargNeighbourhood  CoastTargNeighbourhood ( pFigure ,
				mTargCellSize ,  mAimCellSize , arrMtrxCorrFluct, arrMtrxCorrSyst
			 ,mKillingRange, mQuantShells, 1.) ;
			const String s_30 = wchFoldName;
			String s_31 = s_30 + L"TargPntArray.shp";
			TURPointXY::WriteSetSHPFiles(s_31.w_str()  , CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints);

			s_31 = s_30 + L"AimPntArray.shp";
			TURPointXY::WriteSetSHPFiles(s_31.w_str()  , CoastTargNeighbourhood.mMultPntAim.Points, CoastTargNeighbourhood.mMultPntAim.NumPoints);
			 //	�������� ���� �������:
			const	double VAlPsi =0.;
			///
			createNibourAppointmPointPictureForCoastTarg(wchOutFold,arrMtrxCorrFluct, arrMtrxCorrSyst
			, pFigure, 0., VAlPsi);


			s_31 = s_30 + L"RstrBiasAims.flt";
			CoastTargNeighbourhood.mRstrBiasAims.WriteMeAsFltFile(s_31.w_str());
			s_31 = s_30 + L"RstrProbBias.flt";
			CoastTargNeighbourhood.mRstrProbBias.WriteMeAsFltFile(s_31.w_str());

			s_31 = s_30 + L"PlgAim.shp";
			CoastTargNeighbourhood.mPlgAim.WriteSetSHPFiles(s_31.w_str()
			, &(CoastTargNeighbourhood.mPlgAim), 1);

			 TYrRastr rstrAimPoints = TYrRastr( CoastTargNeighbourhood.mPlgAim
			 , mAimCellSize,  0., CoastTargNeighbourhood.mMultPntAim.Points[0]);
			s_31 = s_30 + L"rstrAimPointsTemp.flt";
			rstrAimPoints.WriteMeAsFltFile(s_31.w_str());
			///
			///




			double valObj = -1;
			TURPointXY *pPntArrAimingPoints = new TURPointXY[CoastTargNeighbourhood.mMultPntAim.NumPoints];
			int *piarrRepeatQuants = new int [CoastTargNeighbourhood.mMultPntAim.NumPoints];
			memset( pPntArrAimingPoints, 0, CoastTargNeighbourhood.mMultPntAim.NumPoints * sizeof(TURPointXY));
			memset ( piarrRepeatQuants, 0, CoastTargNeighbourhood.mMultPntAim.NumPoints * sizeof(int));
			int iQuantAimingPoints = -1;

			CoastTargNeighbourhood.calcOptimalArray_Of_AimPoints_With_SystMtrx( pPntArrAimingPoints
			,&iQuantAimingPoints, piarrRepeatQuants, &valObj) ;


			double valProb  = ( ((double)(CoastTargNeighbourhood.mMultPntTarg.NumPoints)) -  valObj)
				/ ((double)(CoastTargNeighbourhood.mMultPntTarg.NumPoints));
			int	ia = (valProb * 1000);
			LabeledEdit8->Text  =(( double)ia)/ 1000.;
			int iii=0;

			// �������� ������ � �������������� ����

			 for (int i = 0; i < iQuantAimingPoints; i++)
			 {
			   int icur = rstrAimPoints.getPixelNum(pPntArrAimingPoints[i]) ;
			   rstrAimPoints.pflt_rastr[icur] = ((double)piarrRepeatQuants[i]);
			 }
			s_31 = s_30 + L"rstrAimPoints.flt";
			rstrAimPoints.WriteMeAsFltFile(s_31.w_str());
			 ///


			// ����� �����-�����
			TCoastTargNeighbourhood CoastTargNeighbourhood0 ( arrMtrxCorrFluct, arrMtrxCorrSyst, mKillingRange, mQuantShells,  pPntArrAimingPoints,
			CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints, iQuantAimingPoints);
			double valProbMonteCarlo  =CoastTargNeighbourhood0.estimateStrategy_MonteCarlo(mQuantIspit, piarrRepeatQuants);
			ia = (valProbMonteCarlo  * 1000);
			LabeledEdit12->Text  =(( double)ia)/ 1000.;


			///



	TURPointZ *pPointZ = new TURPointZ[iQuantAimingPoints];
	for (int i =0; i < iQuantAimingPoints; i++)
	{
		pPointZ[i].X = pPntArrAimingPoints[i].X;
		pPointZ[i].Y = pPntArrAimingPoints[i].Y;
		pPointZ[i].Z = (double)piarrRepeatQuants[i];
	}

		String s_25 = s_30 + L"AimingPoints_GSK_Z.shp";
		pPointZ[0].WriteSetSHPFiles(s_25.w_str(),pPointZ, iQuantAimingPoints) ;





		int iDim = pFigure ->calcDimension(20) ;
		if (iDim == 1)  // ��� �������� ����
		{

			// ���������� ���� �������� �������

			int num0 = -1,  num1 = -1;
		 //	double valDiam = TURPointXY::calcDiam(CoastTargNeighbourhood.mpPntArrTarg, CoastTargNeighbourhood.mQuantPointsTarg, &num0,  &num1);
			double valDiam = CoastTargNeighbourhood.mMultPntTarg.calcDiam(&num0,  &num1);
			double valAngRotate = -atan2(CoastTargNeighbourhood.mMultPntTarg.Points[num1].Y - CoastTargNeighbourhood.mMultPntTarg.Points[num0].Y
			,CoastTargNeighbourhood.mMultPntTarg.Points[num1].X - CoastTargNeighbourhood.mMultPntTarg.Points[num0].X);
			double *parrAimingPoints_X = new double[iQuantAimingPoints];
			memset(parrAimingPoints_X, 0, iQuantAimingPoints * sizeof(double));
			TURPointXY pnt0(0.,0.);
			TURPointXY pntSdvig0(- CoastTargNeighbourhood.mMultPntTarg.Points[num0].X, - CoastTargNeighbourhood.mMultPntTarg.Points[num0].Y);
			for (int i = 0; i < iQuantAimingPoints; i++)
			{
			// TURPointXY pnt(pPointZ[i].X - CoastTargNeighbourhood.mpPntArrTarg[num0].X, pPointZ[i].Y - CoastTargNeighbourhood.mpPntArrTarg[num0].Y);
			TURPointXY pnt(pPointZ[i].X + pntSdvig0.X, pPointZ[i].Y + pntSdvig0.Y);


			pnt.LinearTransformation(valAngRotate , pnt0,1. );

			parrAimingPoints_X [i]= pnt.X;
			pPntArrAimingPoints[i] =  pnt; // ����� ������������ � ���� ����
			int iiii=0;
			}


			////////
			//  �������� ���������� �������� ������ ����� ������������ �� ���� X , Y
			// �������� ��������� �� ��� X � ���� ����
			TURPolyLine plnDiagr_X = TURPolyLine::createLineDiagram(parrAimingPoints_X ,piarrRepeatQuants,iQuantAimingPoints);

			wchar_t wchFileLineDiagram_X0[300] ={0};
			wcscpy(wchFileLineDiagram_X0,  wchFoldName);
			wcscat(wchFileLineDiagram_X0, L"LineDiagram_X0.shp");
			plnDiagr_X.WriteSetSHPFiles(wchFileLineDiagram_X0,&plnDiagr_X, 1) ;
			plnDiagr_X = plnDiagr_X.MultScalar(-1. );

			//	mFight.mTarget.mpArrPlanePolygon[0].mPolygon.calcBoundBox();
			plnDiagr_X.calcBoundBox();
			double valYMin0 =  plnDiagr_X.Box[1];
			double valYMin = 0.;
			// mFight.mTarget.mpArrPlanePolygon[0].mPolygon.Box[1];
			///

			// ��� ���������

			//	TURPointXY pointBeginX(mFight.mTarget.mpArrPlanePolygon[0].mPolygon.Box[0] -10., 0.);
			TURPointXY pointBeginX(0. -10., 0.);
			//	TURPointXY pointEndX(mFight.mTarget.mpArrPlanePolygon[0].mPolygon.Box[2] + 10., 0.);
			TURPointXY pointEndX(valDiam + 10., 0.);
			TURPointXY pointBeginY(0., 0.);
			TURPointXY pointEndY(0., valYMin0 - 10.);
			TURPolyLine plnAxesX =  TURPolyLine::fncCreateAxes(pointBeginX, pointEndX
							 ,pointBeginY,  pointEndY,0.0001);
			///
			TURPointXY pntSdvig (0., valYMin - 10.);

			double  arrMtxPer[4] = {0.};
			double valTargCourse0 = -valAngRotate;
			arrMtxPer[0] = cos(valTargCourse0);
			arrMtxPer[1] = -sin(valTargCourse0);
			arrMtxPer[2] = -arrMtxPer[1];
			arrMtxPer[3] = cos(valTargCourse0);

			//	plnDiagr_X = plnDiagr_X.SdvigTransform( pntSdvig );
			//	plnDiagr_X = plnDiagr_X.fncLinTransform(arrMtxPer ) ;
			plnDiagr_X = plnDiagr_X.SdvigTransform( pntSdvig );
			plnDiagr_X.LinearTransformation(-valAngRotate , pnt0,1. );
			plnDiagr_X = plnDiagr_X.SdvigTransform( CoastTargNeighbourhood.mMultPntTarg.Points[num0] );


			plnAxesX = plnAxesX.SdvigTransform( pntSdvig );
			plnAxesX.LinearTransformation(-valAngRotate , pnt0,1. );
			plnAxesX = plnAxesX.SdvigTransform( CoastTargNeighbourhood.mMultPntTarg.Points[num0] );

			wchar_t wchFileLineDiagram_X[300] ={0}, wchFileAxesDiagram_X[300] ={0};
			wcscpy(  wchFileLineDiagram_X,  wchFoldName);
			wcscat(wchFileLineDiagram_X, L"LineDiagram_X.shp");
			plnDiagr_X.WriteSetSHPFiles(wchFileLineDiagram_X,&plnDiagr_X, 1) ;

			wcscpy(wchFileAxesDiagram_X,  wchFoldName);
			wcscat(wchFileAxesDiagram_X, L"Axes_X.shp");
			plnAxesX.WriteSetSHPFiles(wchFileAxesDiagram_X,&plnAxesX, 1) ;
			///

			// ���������� ������� ����������� ���������
			  // ���������� ������� ����������� ��������� ������ ����� ����

			   // ������� ����� ���� � ���� ����
				 double *parrTargPoints_X  = new double [CoastTargNeighbourhood.mMultPntTarg.NumPoints];
			for (int i = 0; i < CoastTargNeighbourhood.mMultPntTarg.NumPoints; i++)
			{

			TURPointXY pnt(CoastTargNeighbourhood.mMultPntTarg.Points[i].X + pntSdvig0.X, CoastTargNeighbourhood.mMultPntTarg.Points[i].Y + pntSdvig0.Y);
			pnt.LinearTransformation(valAngRotate , pnt0,1. );

			//parrTargPoints_X [i]= pnt.X;
			CoastTargNeighbourhood.mMultPntTarg.Points[i] = pnt;
			int iiii=0;
			}
			TURPointXY pnt1;
			pnt1.sortPointsArray_X (CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints);


			TCoastTargNeighbourhood CoastTargNeighbourhood0 ( arrMtrxCorrSum ,mKillingRange, mQuantShells,  pPntArrAimingPoints,
			CoastTargNeighbourhood.mMultPntTarg.Points, CoastTargNeighbourhood.mMultPntTarg.NumPoints, iQuantAimingPoints);

			double *parrProb = new double[CoastTargNeighbourhood.mMultPntTarg.NumPoints];
			double *parrX = new double [iQuantAimingPoints];
			memset(parrX, 0, iQuantAimingPoints * sizeof(double));
			for (int i = 0; i < iQuantAimingPoints; i++)
			{
			parrX  [i] = ((double) piarrRepeatQuants[i]);
			}

			double *parr_L = new double [CoastTargNeighbourhood.mMultPntTarg.NumPoints  * iQuantAimingPoints ];
			CoastTargNeighbourhood0.createMatrxL(mKillingRange/ 10., parr_L) ;


			for (int j = 0; j < CoastTargNeighbourhood.mMultPntTarg.NumPoints; j++)
			{
			 parrProb[j] =  1. - CoastTargNeighbourhood0.calcFi_i(parr_L,parrX, j);

			}

			for (int i = 0; i < CoastTargNeighbourhood0.mMultPntTarg.NumPoints; i++)
			{
				parrTargPoints_X [i]= CoastTargNeighbourhood0.mMultPntTarg.Points[i].X;
			}

			wchar_t wchFileGraphProb[300] ={0};
			wcscpy(  wchFileGraphProb,  wchFoldName);
			wcscat(wchFileGraphProb, L"GraphProb.shp");
		  //	plnDiagr_X.WriteSetSHPFiles(wchFileGraphProb,&plnDiagr_X, 1) ;
			 double scalex = 1.;
			 double scaley = 100.;
			TYrWriteShapeFile::CreateShpFile(wchFileGraphProb, parrProb, parrTargPoints_X
			,CoastTargNeighbourhood0.mMultPntTarg.NumPoints, scalex, scaley) ;

			wchar_t wchFileTargPoints0[300] ={0};
			wcscpy( wchFileTargPoints0,  wchFoldName);
			wcscat(wchFileTargPoints0, L"TargPoints0.shp");
			 CoastTargNeighbourhood0.mMultPntTarg.Points[0].WriteSetSHPFiles(wchFileTargPoints0
			 ,CoastTargNeighbourhood0.mMultPntTarg.Points, CoastTargNeighbourhood0.mMultPntTarg.NumPoints) ;


			delete parrTargPoints_X;
			delete parr_L;
			delete parrProb;
			delete parrX;
			delete parrAimingPoints_X ;
			delete []pPntArrAimingPoints;
			delete piarrRepeatQuants ;
			return;
		}


		delete []pPointZ;


		if (typeid(*pFigure ).name() == typeid(Polygon00).name())// 2-������	 �������
		{
			TURPolygon *pPlgTarg_GSK =  (TURPolygon*)pFigure;
			double valTargCellSize = 5.;
			TYrRastr RastrProbab( *pPlgTarg_GSK, valTargCellSize,  1.);

			int quantTargPoints = RastrProbab.calcQuantValuablePiksels();

			TURPointXY *pPntArrTarg = new TURPointXY [quantTargPoints];
			int icur = 0;
			for (int j = 0; j < RastrProbab.ncols * RastrProbab.nrows; j++)
			{
			if (RastrProbab.pflt_rastr[j] > 0.)
			{
			pPntArrTarg[icur] =  RastrProbab.getCellCentre(j);
			icur++;
			}
			}



			TCoastTargNeighbourhood CoastTargNeighbourhood0 ( arrMtrxCorrSum ,mKillingRange, mQuantShells,  pPntArrAimingPoints,
			pPntArrTarg, quantTargPoints, iQuantAimingPoints);

			delete []pPntArrTarg;

			double *parrProb = new double[quantTargPoints];

			double *parrX = new double [iQuantAimingPoints];
			memset(parrX, 0, iQuantAimingPoints * sizeof(double));
			for (int i = 0; i < iQuantAimingPoints; i++)
			{
			parrX  [i] = ((double) piarrRepeatQuants[i]);
			}
			double *parr_L = new double [CoastTargNeighbourhood0.mMultPntTarg.NumPoints  * CoastTargNeighbourhood0.mMultPntAim.NumPoints];
			CoastTargNeighbourhood0.createMatrxL(mKillingRange/ 10., parr_L) ;

			icur = 0;
			for (int j = 0; j < RastrProbab.ncols * RastrProbab.nrows; j++)
			{
			if (RastrProbab.pflt_rastr[j] > 0.)
			{
			RastrProbab.pflt_rastr[j] =  1. - CoastTargNeighbourhood0.calcFi_i(parr_L,parrX, icur);

			icur++;
			}
			}

			String s_27 = s_30 + L"RastrProb.flt";
			RastrProbab.WriteMeAsFltFile(s_27.w_str());

			delete parrProb;
			delete parrX;
			delete parr_L;
			delete []pPntArrAimingPoints;
			delete piarrRepeatQuants ;
			return;
		}
		delete []pPntArrAimingPoints;
		delete piarrRepeatQuants ;
		//////////////////////////////////////////////////////////////////////////////////

}
//---------------------------------------------------------------------------


