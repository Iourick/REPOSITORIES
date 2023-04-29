//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include <dir.h>
#include "YrString.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Comp.h"

#include "Gauss.h"

#include "MatrixProccess.h"

#include "YrWrite.h"

#include "YrWriteShapeFile.h"

#include "CalcCorMatrx.h"

#include "Environment.h"
#include "Equations.h"
#include "MyShellTraj.h"

#include "URPointZ.h"
#include "ShellBody.h"
#include "Target.h"
#include "InitTargData.h"
#include "Traject.h"
#include "EtalonSign.h"
#include "Vessel.h"
#include "Fight.h"

#include "Line.h"
#include "UrPointXY.h"
#include "Constants.h"
#include "YrRead.h"

#include "LearnShellTraj.h"
#include "LearnShellBody.h"
#include "URPolyLine.h"
#include "Table_76.h"


	static int I_ENTER_COUNT = 0;

	extern TURPolyLine PLN_CxEtal;
	extern const TURPolyLine  PLN_MxOmegax;
	extern const TURPolyLine PLN_Knm_76;
	extern  const TURPolyLine PLN_MxOmx_76;
	extern const TURPolyLine PLN_Cx_76;
	extern const TURPolyLine PLN_Knm;
	extern const TURPolyLine PLN_Cz_76 ;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
ComboBox4->ItemIndex = 4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::fncInputData()
{
   //���� ������������ � ���
	 mEpsGSK =  StrTo_Dbl_(LabeledEdit6->Text) *M_PI / 180. ;
	 mBetGSK =  StrTo_Dbl_(LabeledEdit7->Text) *M_PI / 180.  ;

	// �������� �������
	 mVVess =  StrTo_Dbl_(LabeledEdit11->Text) ;

	// �������� �������
	 mVShell =  StrTo_Dbl_(LabeledEdit9->Text);
	
}



void __fastcall TForm1::Button1Click(TObject *Sender)
{
	// ���� � ����������� � ���������
	if (!mpwchGraphDir0)
	{
	 if (I_ENTER_COUNT > 4) Close();


	 ShowMessage(L"������� ���� � ����� � ���������") ;
	 I_ENTER_COUNT++;
	 return;
	}
	wcscpy(mpwchGraphDir,mpwchGraphDir0);
	wchar_t *pwchr = wcsrchr(mpwchGraphDir, L'\\');
	pwchr[0] = 0;

  ///
 fncInputData();

 double arrVessVelocity_GSK [3] = {0.};
 double valEp_KGSK = -1.,valBet_KGSK = -1.0;


	 const int QUANT_COLS_BUFF = 7;
	 wchar_t *wcharrFileNames = new wchar_t[QUANT_COLS_BUFF * 30];
	 memset(wcharrFileNames, 0,  QUANT_COLS_BUFF * 30 * sizeof( wchar_t)) ;

	 wcscpy( &wcharrFileNames[ 0 * 30], L"Q");
	 wcscpy( &wcharrFileNames[ 1 * 30], L"Eps_GSK");
	 wcscpy( &wcharrFileNames[ 2* 30],  L"Bet_GSK");
	 wcscpy( &wcharrFileNames[ 3 * 30], L"Eps_KGSK");
	 wcscpy( &wcharrFileNames[ 4 * 30], L"Bet_KGSK");
	 wcscpy( &wcharrFileNames[ 5 * 30], L"DelEps");
	 wcscpy( &wcharrFileNames[ 6 * 30], L"DelBet");
	 double *pscaleY = new double  [QUANT_COLS_BUFF] ;
	 for (int i = 1; i < QUANT_COLS_BUFF; i++) pscaleY[i] = 1000.;
	 pscaleY[0] = 1.;

	 const int QUANT_ROWS_BUFF = 181;

	 double *parrBuff = new double [ QUANT_COLS_BUFF * QUANT_ROWS_BUFF ];

	 for (int i = 0; i < QUANT_ROWS_BUFF ; i++)
	 {
		double valQ = M_PI / 180. * ((double)i);
		arrVessVelocity_GSK[0] = mVVess * sin (  valQ);
		arrVessVelocity_GSK[1] = mVVess * cos (  valQ);


		 TFight::transform_EpsBetGSK_to_EpsBetKGSK(arrVessVelocity_GSK, mVShell
		  ,mEpsGSK,mBetGSK, &valEp_KGSK, &valBet_KGSK)  ;
		  parrBuff [ i * QUANT_COLS_BUFF ] =  valQ * 180./ M_PI;
		  parrBuff [ i * QUANT_COLS_BUFF + 1] = mEpsGSK;
		  parrBuff [ i * QUANT_COLS_BUFF + 2] = mBetGSK;
		  parrBuff [ i * QUANT_COLS_BUFF + 3] = valEp_KGSK;
		  parrBuff [ i * QUANT_COLS_BUFF + 4] = valBet_KGSK;
		  parrBuff [ i * QUANT_COLS_BUFF + 5] = (valEp_KGSK - mEpsGSK);
		  parrBuff [ i * QUANT_COLS_BUFF + 6] = (valBet_KGSK - mBetGSK);
	 }




	 for (int i = 1; i < QUANT_COLS_BUFF; i++)
	 {
	 TYrWriteShapeFile::WriteOneReport(mpwchGraphDir  // ���� � �����
								  ,parrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS_BUFF // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,QUANT_ROWS_BUFF  //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,30// ������������ ����� ����� ����������
								  ,0  // ����� ���������� �� ��� X
								  ,i // ����� ���������� �� ��� Y
								  ,1. //  ������� �� ��� X
								  ,pscaleY[i]  // ������� �� ��� Y
								   )  ;
	 }


	wchar_t wchFileName [300] = {0} ;
	wcscpy(wchFileName, mpwchGraphDir );
	wcscat(wchFileName, L"\\Axes.shp");
	TYrWriteShapeFile::CreateShpAxes(wchFileName,-40000.,40000,-40000.,40000) ;
	////

   delete []parrBuff;
   delete []wcharrFileNames;
  }



//---------------------------------------------------------------------------

/*
void __fastcall TForm1::Button2Click(TObject *Sender)
{

    fncInputData() ;
	double *arrData  = new double [NUmRows_Table_76 * NUmCols_Table_76];
	int num76 = NUmCols_Table_76;
	int numRows = NUmRows_Table_76;
	memcpy(arrData, constArr_Table_76, NUmRows_Table_76 * NUmCols_Table_76 * sizeof(double));

	int numTabCols = 15;   // �-�� �������� ������� ������� � �������� �����������
	double *arrTab  = new double [numTabCols * numRows];  // ������� �������



  for (int i = 0; i < numRows; i++)
  {
	arrTab[ i *numTabCols] =  arrData[ i * num76 +4]; // T ��������
	arrTab[ i *numTabCols +1] =  arrData[ i * num76 +1] * M_PI/ 3000.; // Tetta0
	arrTab[ i *numTabCols +2] =  arrData[ i * num76 ];  //Dk
	arrTab[ i *numTabCols +3] =  arrData[ i * num76 +5];  // Vk
	arrTab[ i *numTabCols +4] =  (arrData[ i * num76 +2] + arrData[ i * num76 +3] / 60.) * M_PI /180.;    // Tettak
	arrTab[ i *numTabCols +5] =  arrData[ i * num76 +10]; //Zk

	arrTab[ i *numTabCols +6] =    arrData[ i * num76 +11];// �������� ������������ �� ��� ����� 10�/�

	arrTab[ i *numTabCols +7] =  arrData[ i * num76 +12]; // �������� ��������� �� ���������� ������ ������� �� 10%

	arrTab[ i *numTabCols +8] =  arrData[ i * num76 +13]; // �������� ��������� �� ���������� ��� �������� �� 1%

	arrTab[ i *numTabCols +9] =  arrData[ i * num76 +14]; // �������� ��������� �� ���������� ���� ����� �� 10 �/�

	arrTab[ i *numTabCols +10] =  arrData[ i * num76 +15]; // �������� ��������� �� ���������� �����0 �� 1 ��

	arrTab[ i *numTabCols +11] =  arrData[ i * num76 +16]; // �������� ������ �� ���������� �����0 �� 1 ��

	arrTab[ i *numTabCols +12] =    arrData[ i * num76 +7] / 0.674; // ��� �������� ���������

	arrTab[ i *numTabCols +13] =    arrData[ i * num76 +8] / 0.674;  // ��� �������� �����������

	arrTab[ i *numTabCols +14] =    arrData[ i * num76 +9] / 0.674;  // ��� �������� �������

  }
  delete []arrData;





double arrVessVelocity_GSK [3] ={0.};
   TLearnShellTraj LearnShellTraj (arrVessVelocity_GSK, mLearnShellBody,  0.,  0. );

  TURPolyLine plnCx, plnKnm, plnMxOmx,plnCz;
  double arrDisp[5] = {0.};
 // double rez = LearnShellTraj.findOptimalTab_Cx_76_(arrTab, numRows, numTabCols, &plnCx, &plnKnm, &plnMxOmx, arrDisp);
//  plnCx.WriteToASCII__(L"E:\\REPORT_BARRIER\\CxLearn4.txt");

 // TURPolyLine plnCix (1, numRows +2);   // ���� �������� 0 ���� � 90 ����

 // LearnShellTraj.calcSoglasCoeffsCix_76(arrTab, numRows, numTabCols, &plnCix);
 // plnCix.WriteToASCII__(L"E:\\REPORT_BARRIER\\CIxLearn0.txt");
	  //double rez = LearnShellTraj.findOptimalTab_MxOmegax_76_(arrTab, numRows, numTabCols &plnMxOmx, arrDisp) ;
	//  plnMxOmx.WriteToASCII__(L"E:\\REPORT_BARRIER\\plnMxOmx4.txt");


  //	  double rez = LearnShellTraj.findOptimalTab_Knm_76_(arrTab, numRows, numTabCols, &plnKnm, arrDisp) ;
   //	  plnKnm.WriteToASCII__(L"E:\\REPORT_BARRIER\\plnKnm4.txt");

   double rez = LearnShellTraj.findOptimalTab_Cz_76_(arrTab, numRows, numTabCols, &plnCz, arrDisp) ;
	  plnCz.WriteToASCII__(L"E:\\REPORT_BARRIER\\plnCz4.txt");
	  LabeledEdit15->Text = rez;
	 delete []arrTab;

	 delete []arrData;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
   OpenDialog3->Filter = L"SHP ���� � ���������� � ���������: (*.shp)|*.shp" ;

	if (OpenDialog3->Execute())
	{
	mpwchGraphDir0 =  (OpenDialog3->FileName).w_str();

	}
	Edit1->Text =  mpwchGraphDir0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
/*
 // ���� � ��������
if (!mpwchTableFile0)
	{
	 if (I_ENTER_COUNT > 4) Close();


	 ShowMessage(L"������� ���� � ����� � ���������") ;
	 I_ENTER_COUNT++;
	 return;
	}
	wcscpy(mpwchTableFile,mpwchTableFile0);

	///


	// ���� � ����������� � ���������
	if (!mpwchGraphDir0)
	{
	 if (I_ENTER_COUNT > 4) Close();


	 ShowMessage(L"������� ���� � ����� � ���������") ;
	 I_ENTER_COUNT++;
	 return;
	}
	wcscpy(mpwchGraphDir,mpwchGraphDir0);
	wchar_t *pwchr = wcsrchr(mpwchGraphDir, L'\\');
	pwchr[0] = 0;

  ///

  // ���� ������
	  fncInputData() ;
	///

   wcscpy(mpwchTableFile,  L"E:\\REPORT_BARRIER\\76TableEarth.csv" );
	// ������ ����� � �������� � ������������ ������� �������

	 int numRows = TYrRead::YrCalcRows(mpwchTableFile) - 1;

	 double *arrData  = new double [17 * numRows];

	 int numCols = 15;
	 double *arrTab  = new double [numCols * numRows];
	 double *arrTabRez  = new double [numCols * numRows];
	 int nrows = -1;
	 TYrRead::YrReadTabCSV_1(mpwchTableFile // ���� � ��������
					,1 // �-�� ������� �����
					,0 // �-�� ������� c�������
					,numRows // �-�� ����� �������������� ����� �������
					,17 // �-�� �������� �������������� ����� �������
					,&nrows  // �-�� ����������� �����
					,arrData  // ������ � ������� ����������� ����������
					) ;

TYrWrite::WriteReportForFloatMassiveTXT_(L"E:\\REPORT_BARRIER\\tab1.txt",arrData,
										  17,numRows) ;
										  */


 /*
	// ���� � ����������� � ���������
	if (!mpwchGraphDir0)
	{
	 if (I_ENTER_COUNT > 4) Close();


	 ShowMessage(L"������� ���� � ����� � ���������") ;
	 I_ENTER_COUNT++;
	 return;
	}
	wcscpy(mpwchGraphDir,mpwchGraphDir0);
	wchar_t *pwchr = wcsrchr(mpwchGraphDir, L'\\');
	pwchr[0] = 0;

  ///
	fncInputData() ;
	double *arrData  = new double [NUmRows_Table_76 * NUmCols_Table_76];
	int num76 = NUmCols_Table_76;
	int numRows = NUmRows_Table_76;
	memcpy(arrData, constArr_Table_76, NUmRows_Table_76 * NUmCols_Table_76 * sizeof(double));

	int numTabCols = 15;   // �-�� �������� ������� ������� � �������� �����������
	double *arrTab  = new double [numTabCols * numRows];  // ������� �������

	int numRezTabCols = 20;  // �-�� ��������  ������� � ������������ ��������
	double *arrTabRez  = new double [numRezTabCols * numRows];
	//int nrows = -1;
	// TYrRead::YrReadTabCSV_1(mpwchTableFile // ���� � ��������
	//				,1 // �-�� ������� �����
	//				,0 // �-�� ������� c�������
	//				,numRows // �-�� ����� �������������� ����� �������
	//				,17 // �-�� �������� �������������� ����� �������
	//				,&nrows  // �-�� ����������� �����
	//			,arrData  // ������ � ������� ����������� ����������
	//			) ;

  for (int i = 0; i < numRows; i++)
  {
	arrTab[ i *numTabCols] =  arrData[ i * num76 +4]; // T ��������
	arrTab[ i *numTabCols +1] =  arrData[ i * num76 +1] * M_PI/ 3000.; // Tetta0
	arrTab[ i *numTabCols +2] =  arrData[ i * num76 ];  //Dk
	arrTab[ i *numTabCols +3] =  arrData[ i * num76 +5];  // Vk
	arrTab[ i *numTabCols +4] =  (arrData[ i * num76 +2] + arrData[ i * num76 +3] / 60.) * M_PI /180.;    // Tettak
	arrTab[ i *numTabCols +5] =  arrData[ i * num76 +10]; //Zk

	arrTab[ i *numTabCols +6] =    arrData[ i * num76 +11];// �������� ������������ �� ��� ����� 10�/�

	arrTab[ i *numTabCols +7] =  arrData[ i * num76 +12]; // �������� ��������� �� ���������� ������ ������� �� 10%

	arrTab[ i *numTabCols +8] =  arrData[ i * num76 +13]; // �������� ��������� �� ���������� ��� �������� �� 1%

	arrTab[ i *numTabCols +9] =  arrData[ i * num76 +14]; // �������� ��������� �� ���������� ���� ����� �� 10 �/�

	arrTab[ i *numTabCols +10] =  arrData[ i * num76 +15]; // �������� ��������� �� ���������� �����0 �� 1 ��

	arrTab[ i *numTabCols +11] =  arrData[ i * num76 +16]; // �������� ������ �� ���������� �����0 �� 1 ��

	arrTab[ i *numTabCols +12] =    arrData[ i * num76 +7] / 0.674; // ��� �������� ���������

	arrTab[ i *numTabCols +13] =    arrData[ i * num76 +8] / 0.674;  // ��� �������� �����������

	arrTab[ i *numTabCols +14] =    arrData[ i * num76 +9] / 0.674;  // ��� �������� �������

  }
  delete []arrData;
 

  double sum = 0.;
  for (int i =0; i < numRows; i++)
  {
	sum +=  arrTab[ i *numTabCols +10]  * arrTab[ i *numTabCols +10] ;
  }
  sum = sqrt(sum / 1200./numRows);
  LabeledEdit1->Text = sum;
  double arrVessVelocity_GSK [3] ={0.};
  TLearnShellTraj LearnShellTraj (arrVessVelocity_GSK, mLearnShellBody,  0.,  0. );

  double valDispD = 0.;
  double valDispZ = 0.;

  // ��������� ������ ��� �����������


  for (int i =0; i < numRows; i++)
  {
	double arrVesselVelocity[3] = {0.};
	double valDHoriz = -1.;
	TLearnShellTraj ShellTrajCur(arrVesselVelocity, mLearnShellBody, arrTab [i *numTabCols +1] , M_PI/2.);
	ShellTrajCur.fncMoveShell_TO_ZeroAlt(mEnvironment,0.001, valDHoriz );

	valDispD +=  (ShellTrajCur.marrStrSK_VS[0] -  arrTab[ i *numTabCols +2]) * (ShellTrajCur.marrStrSK_VS[0] -  arrTab[ i *numTabCols +2]);
	valDispZ +=  (ShellTrajCur.marrStrSK_VS[2] -  arrTab[ i *numTabCols +5]) * (ShellTrajCur.marrStrSK_VS[2] -  arrTab[ i *numTabCols +5]);

	arrTabRez[ i *numRezTabCols] =  arrTab [i *numTabCols]; // T ��������
	arrTabRez[ i *numRezTabCols +1] =  arrTab [i *numTabCols +1]; // Tetta0
	arrTabRez[ i *numRezTabCols +2] =  ShellTrajCur.marrStrSK_VS[0];  //Dk
	arrTabRez[ i *numRezTabCols +3] =  ShellTrajCur.marrStrSK_VS [6];  // Vk
	arrTabRez[ i *numRezTabCols +4] =  ShellTrajCur.marrStrSK_VS [7];    // Tettak
	arrTabRez[ i *numRezTabCols +5] =  ShellTrajCur.marrStrSK_VS[2]; //Zk


	TLearnShellTraj ShellTrajCur1(arrVesselVelocity, mLearnShellBody, arrTab [i *numTabCols +1] , M_PI/2.);
	TEnvironment Environment(10., 0.,0.);
	ShellTrajCur1.fncMoveShell_TO_ZeroAlt(Environment,0.001, valDHoriz );
	arrTabRez[ i *numRezTabCols +6] =     fabs(ShellTrajCur1.marrStrSK_VS[2] -ShellTrajCur.marrStrSK_VS[2]);// �������� ������������ �� ��� ����� 10�/�


	TLearnShellTraj ShellTrajCur2(arrVesselVelocity, mLearnShellBody, arrTab [i *numTabCols +1] , M_PI/2.);
	ShellTrajCur2.marrStrSK_VS[5] = ShellTrajCur2.marrStrSK_VS[5] * 0.9;
	ShellTrajCur2.fncMoveShell_TO_ZeroAlt(mEnvironment,0.001,  valDHoriz );
	arrTabRez[ i *numRezTabCols +7] =  ShellTrajCur2.marrStrSK_VS[0] - ShellTrajCur.marrStrSK_VS[0]; // �������� ��������� �� ���������� ������ ������� �� 10%


	TLearnShellTraj ShellTrajCur3(arrVesselVelocity, mLearnShellBody, arrTab [i *numTabCols +1] , M_PI/2.);
	ShellTrajCur3.marrStrSK_VS[6] = ShellTrajCur3.marrStrSK_VS[6] * 1.01;
	ShellTrajCur3.fncMoveShell_TO_ZeroAlt(mEnvironment,0.001, valDHoriz );
	arrTabRez[ i *numRezTabCols +8] =    ShellTrajCur3.marrStrSK_VS[0] - ShellTrajCur.marrStrSK_VS[0]; // �������� ��������� �� ���������� ��� �������� �� 1%


	TLearnShellTraj ShellTrajCur4(arrVesselVelocity, mLearnShellBody, arrTab [i *numTabCols +1] , M_PI/2.);
	TEnvironment Environment1(10., -M_PI /2.,0.);
	ShellTrajCur4.fncMoveShell_TO_ZeroAlt(Environment1,0.001, valDHoriz );
	arrTabRez[ i *numRezTabCols +9] =   ShellTrajCur4.marrStrSK_VS[0] - ShellTrajCur.marrStrSK_VS[0];; // �������� ��������� �� ���������� ���� ����� �� 10 �/�


	TLearnShellTraj ShellTrajCur5(arrVesselVelocity, mLearnShellBody, arrTab [i *numTabCols +1] , M_PI/2.);
	ShellTrajCur5.marrStrSK_VS[7] += M_PI / 3000.;
	ShellTrajCur5.fncMoveShell_TO_ZeroAlt(mEnvironment,0.001, valDHoriz );
	arrTabRez[ i *numRezTabCols +10] = ShellTrajCur5.marrStrSK_VS[0] - ShellTrajCur.marrStrSK_VS[0];// �������� ��������� �� ���������� �����0 �� 1 ��


	TLearnShellTraj ShellTrajCur10(arrVesselVelocity, mLearnShellBody, arrTab [i *numTabCols +1] , M_PI/2.);
	ShellTrajCur10.marrStrSK_VS[7] += M_PI / 3000.;
	ShellTrajCur10.fncMovePhasVector(mEnvironment, 0.001, ShellTrajCur.mTCur);
	arrTabRez[ i *numRezTabCols +11] = ShellTrajCur10.marrStrSK_VS[1] - ShellTrajCur.marrStrSK_VS[1];// �������� ������ �� ���������� �����0 �� 1 ��

	double valPartDerivD__po_Tetta0 = ShellTrajCur.fncPartialDerivD_TochkiPadenia_po_Tetta0(arrTab [i *numTabCols +1]);
	double valPartDerivD__po_M = ShellTrajCur.fncPartialDerivD_TochkiPadenia_po_Mass(arrTab [i *numTabCols +1]);
	double valPartDerivD__po_V0 = ShellTrajCur.fncPartialDerivD_TochkiPadenia_po_V0(arrTab [i *numTabCols +1]);
	double valPartDerivD__po_Cx = ShellTrajCur.fncPartialDerivD_TochkiPadenia_po_Cx(arrTab [i *numTabCols +1]);
	double valPartDerivZ__po_Psi0 = ShellTrajCur.fncPartialDerivZ_TochkiPadenia_po_Psi0(arrTab [i *numTabCols +1]);

	arrTabRez[ i *numRezTabCols +12] =    sqrt (
	valPartDerivD__po_Tetta0 *mSigTechAU * valPartDerivD__po_Tetta0 *mSigTechAU
   + valPartDerivD__po_M * mLearnShellBody.mDispMass0 * valPartDerivD__po_M
   + valPartDerivD__po_V0 * valPartDerivD__po_V0 * mLearnShellBody.mDispV0
   + valPartDerivD__po_Cx *	mLearnShellBody.mDispCx * valPartDerivD__po_Cx); // ��� �������� ���������

	arrTabRez[ i *numRezTabCols +13] =   fabs( valPartDerivZ__po_Psi0 * mSigTechAU);  // ��� �������� �����������

	arrTabRez[ i *numRezTabCols +14] =    arrData[ i * num76 +9] / 0.674;  // ��� �������� �������

	arrTabRez[ i *numRezTabCols +15 ] = valPartDerivD__po_Tetta0 * 0.001;

	arrTabRez[ i *numRezTabCols +16 ]  = valPartDerivD__po_M* 0.01;

	arrTabRez[ i *numRezTabCols +17] = valPartDerivD__po_V0;

	arrTabRez[ i *numRezTabCols +18] = valPartDerivD__po_Cx * 0.01;

	arrTabRez[ i *numRezTabCols +19] = valPartDerivZ__po_Psi0 * 0.001;
  }
  LabeledEdit2->Text = sqrt(valDispZ /((double)numRows)) ;
  LabeledEdit3->Text = sqrt(valDispD /((double)numRows)) ;
 //���������� ��������    �������

	const int QUANT_COLS1 = numTabCols, QUANT_POINTS  = numRows ;

	const int lenName =30 ;// ������������ ����� ����� ����������

	wchar_t *pwcharrFileNames1 = new wchar_t [ QUANT_COLS1 * lenName] ;
	memset (pwcharrFileNames1, 0, QUANT_COLS1 * lenName* sizeof(wchar_t)) ;

	wcscpy( &pwcharrFileNames1[ 0 * 30], L"Tab_t_flight");
	wcscpy( &pwcharrFileNames1[ 1 * 30], L"Tab_Tetta0");
	wcscpy( &pwcharrFileNames1[ 2* 30],  L"Tab_Dk");
	wcscpy( &pwcharrFileNames1[ 3 * 30], L"Tab_Vk");
	wcscpy( &pwcharrFileNames1[ 4 * 30], L"Tab_Tettak");
	wcscpy( &pwcharrFileNames1[ 5 * 30], L"Tab_Zk");
	wcscpy( &pwcharrFileNames1[ 6 * 30], L"Tab_PoprZ_BokWind_10");
	wcscpy( &pwcharrFileNames1[ 7 * 30], L"Tab_PoprD_Pi_10");
	wcscpy( &pwcharrFileNames1[ 8 * 30], L"Tab_PoprD_v0_10");
	wcscpy( &pwcharrFileNames1[ 9 * 30], L"Tab_PoprD_prodWind_10");
	wcscpy( &pwcharrFileNames1[ 10 * 30], L"Tab_PoprD_Tetta0_1td");
	wcscpy( &pwcharrFileNames1[ 11 * 30], L"Tab_PoprH_Tetta0_1td");
	wcscpy( &pwcharrFileNames1[ 12 * 30], L"Tab_SKZ_D");
	wcscpy( &pwcharrFileNames1[ 13 * 30], L"Tab_SKZ_Z");
	wcscpy( &pwcharrFileNames1[ 14 * 30], L"Tab_SKZ_H");

	double *pscaleY1 = new double  [QUANT_COLS1] ;
	pscaleY1[0] = 1; // �����
	pscaleY1[1] = 1000; // tetta0
	pscaleY1[2] = 0.01; // Dk
	pscaleY1[3] = 0.1; // Vk
	pscaleY1[4] = 1000.; // tettak
	pscaleY1[5] = 10.; // Zk
	pscaleY1[6] = 1.;
	pscaleY1[7] = 0.01;
	pscaleY1[8] = 1.;
	pscaleY1[9] = 0.01;
	pscaleY1[10] = 1;
	pscaleY1[11] = 1.;
	pscaleY1[12] = 1.;
	pscaleY1[13] = 1.;
	pscaleY1[14] = 1.;


   for (int j = 2; j < QUANT_COLS1 ; j++)
	 {


	TYrWriteShapeFile::WriteOneReport(mpwchGraphDir  // ���� � �����
								  , arrTab // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS1 // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,QUANT_POINTS //  - �-�� �����
								  ,pwcharrFileNames1 //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,lenName // ������������ ����� ����� ����������
								  ,1  // ����� ���������� �� ��� X
								  ,j  // ����� ���������� �� ��� Y
								  ,pscaleY1[1]//  ������� �� ��� X
								  ,pscaleY1[j]  // ������� �� ��� Y
								   );
	 }


	 //------------------------------------------------------------------

	 //���������� ��������   ��������


	const int QUANT_COLS2 = numRezTabCols ;
	double *pscaleY2 = new double  [QUANT_COLS2] ;
	pscaleY2[0] = 1; // �����
	pscaleY2[1] = 1000; // tetta0
	pscaleY2[2] = 0.01; // Dk
	pscaleY2[3] = 0.1; // Vk
	pscaleY2[4] = -1000.; // tettak
	pscaleY2[5] = 10.; // Zk
	pscaleY2[6] = 1.;
	pscaleY2[7] = 0.01;
	pscaleY2[8] = 1.;
	pscaleY2[9] = 0.01;
	pscaleY2[10] = 1;
	pscaleY2[11] = 1.;
	pscaleY2[12] = 1.;
	pscaleY2[13] = 1.;
	pscaleY2[14] = 1.;
	pscaleY2[15] = 1.;
	pscaleY2[16] = 1.;
	pscaleY2[17] = 1.;
	pscaleY2[18] = 1.;
	pscaleY2[19] = 1.;

	wchar_t *pwcharrFileNames2 = new wchar_t [ QUANT_COLS2 * lenName] ;
	memset (pwcharrFileNames2, 0, QUANT_COLS2 * lenName* sizeof(wchar_t)) ;

	wcscpy( &pwcharrFileNames2[ 0 * 30], L"Rez_t_flight");
	wcscpy( &pwcharrFileNames2[ 1 * 30], L"Rez_Tetta0");
	wcscpy( &pwcharrFileNames2[ 2* 30],  L"Rez_Dk");
	wcscpy( &pwcharrFileNames2[ 3 * 30], L"Rez_Vk");
	wcscpy( &pwcharrFileNames2[ 4 * 30], L"Rez_Tettak");
	wcscpy( &pwcharrFileNames2[ 5 * 30], L"Rez_Zk");
	wcscpy( &pwcharrFileNames2[ 6 * 30], L"Rez_PoprZ_BokWind_10");
	wcscpy( &pwcharrFileNames2[ 7 * 30], L"Rez_PoprD_Pi_10");
	wcscpy( &pwcharrFileNames2[ 8 * 30], L"Rez_PoprD_v0_10");
	wcscpy( &pwcharrFileNames2[ 9 * 30], L"Rez_PoprD_prodWind_10");
	wcscpy( &pwcharrFileNames2[ 10 * 30], L"Rez_PoprD_Tetta0_1td");
	wcscpy( &pwcharrFileNames2[ 11 * 30], L"Rez_PoprH_Tetta0_1td");
	wcscpy( &pwcharrFileNames2[ 12 * 30], L"Rez_SKZ_D");
	wcscpy( &pwcharrFileNames2[ 13 * 30], L"Rez_SKZ_Z");
	wcscpy( &pwcharrFileNames2[ 14 * 30], L"Rez_SKZ_H");
	wcscpy( &pwcharrFileNames2[ 15 * 30], L"DerivD__po_Tetta0");
	wcscpy( &pwcharrFileNames2[ 16 * 30], L"DerivD__po_M");
	wcscpy( &pwcharrFileNames2[ 17 * 30], L"DerivD__po_V0");
	wcscpy( &pwcharrFileNames2[ 18 * 30], L"DerivD__po_Cx");
	wcscpy( &pwcharrFileNames2[ 19 * 30], L"DerivZ__po_Psi0");


   for (int j = 2; j < QUANT_COLS2 ; j++)
	 {


	TYrWriteShapeFile::WriteOneReport(mpwchGraphDir  // ���� � �����
								  , arrTabRez // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS2 // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,QUANT_POINTS //  - �-�� �����
								  ,pwcharrFileNames2 //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,lenName // ������������ ����� ����� ����������
								  ,1  // ����� ���������� �� ��� X
								  ,j  // ����� ���������� �� ��� Y
								  ,pscaleY2[1]//  ������� �� ��� X
								  ,pscaleY2[j]  // ������� �� ��� Y
								   );
	 }


  wchar_t wchFileName4[300] = {0} ;
  wcscpy(wchFileName4, mpwchGraphDir );
  wcscat(wchFileName4, L"\\Axes.shp");
  TYrWriteShapeFile::CreateShpAxes(wchFileName4,-40000.,40000,-40000.,40000) ;


  TURPolyLine plnt = PLN_CxEtal;
  TURPolyLine plnCxEtal = plnt.MultScalar(10. );

  plnt = PLN_Knm;
  TURPolyLine plnKnmEt =  plnt.MultScalar(10. );


   plnt =  PLN_Cx_76;
   TURPolyLine plnCx76 = plnt.MultScalar(10. );


  plnt =  PLN_MxOmx_76;
  TURPolyLine plnMxOmx76 =  plnt.MultScalar(10. );

  plnt =  PLN_Knm_76;
  TURPolyLine plnKnm76 = plnt.MultScalar(10. );

  plnt = PLN_MxOmegax ;
  TURPolyLine plnMxOmxEt =  plnt.MultScalar(100. );

  plnt = PLN_Cz_76 ;
  TURPolyLine plnCz_76 =  plnt.MultScalar(100. );

  wcscpy(wchFileName4, mpwchGraphDir );
  wcscat(wchFileName4, L"\\plnCxEtal.shp");
  plnCxEtal.WriteSetSHPFiles(wchFileName4,&plnCxEtal, 1) ;


  wcscpy(wchFileName4, mpwchGraphDir );
  wcscat(wchFileName4, L"\\plnKnmEtal.shp");
  plnKnmEt.WriteSetSHPFiles(wchFileName4,&plnKnmEt, 1) ;

  wcscpy(wchFileName4, mpwchGraphDir );
  wcscat(wchFileName4, L"\\plnCx76.shp");
  plnCx76.WriteSetSHPFiles(wchFileName4,&plnCx76, 1) ;

  wcscpy(wchFileName4, mpwchGraphDir );
  wcscat(wchFileName4, L"\\plnKnm76.shp");
  plnKnm76.WriteSetSHPFiles(wchFileName4,&plnKnm76, 1) ;

  wcscpy(wchFileName4, mpwchGraphDir );
  wcscat(wchFileName4, L"\\plnMxOmxEal.shp");
  plnMxOmxEt.WriteSetSHPFiles(wchFileName4,&plnMxOmxEt, 1) ;


  wcscpy(wchFileName4, mpwchGraphDir );
  wcscat(wchFileName4, L"\\PLN_MxOmx_76.shp");
  plnMxOmx76.WriteSetSHPFiles(wchFileName4,&plnMxOmx76, 1) ;

  wcscpy(wchFileName4, mpwchGraphDir );
  wcscat(wchFileName4, L"\\plnCz_76.shp");
  plnCz_76.WriteSetSHPFiles(wchFileName4,&plnCz_76 , 1) ;




	delete []pwcharrFileNames1;
	delete []pwcharrFileNames2;
	delete []pscaleY1;
	delete []pscaleY2;
	delete []arrData;
	delete []arrTab;
	delete []arrTabRez;
//}
//---------------------------------------------------------------------------
}

*/







//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
OpenDialog3->Filter = L"SHP ���� � ���������� � ���������: (*.shp)|*.shp" ;

	if (OpenDialog3->Execute())
	{
	mpwchGraphDir0 =  (OpenDialog3->FileName).w_str();

	}
	Edit2->Text =  mpwchGraphDir0;
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button2Click(TObject *Sender)
{
	// ���� � ����������� � ���������
	if (!mpwchGraphDir0)
	{
	 if (I_ENTER_COUNT > 4) Close();


	 ShowMessage(L"������� ���� � ����� � ���������") ;
	 I_ENTER_COUNT++;
	 return;
	}
	wcscpy(mpwchGraphDir,mpwchGraphDir0);
	wchar_t *pwchr = wcsrchr(mpwchGraphDir, L'\\');
	pwchr[0] = 0;

  ///
 fncInputData();

 TFight Fight;
 Fight.mVessel.mControlSyst.mSinsDelayT= 0.02;
 Fight.mVessel.mArtComplex.mArtCannon.mRabT = StrTo_Dbl_(LabeledEdit1->Text) *M_PI / 1000. ;
 memset(Fight.mVessel.marrArtParral, 0, 3 * sizeof(double));
	// ��� ������� ������ ���� (����� �����)
	double valSigSins = 0.00041;

	// ��� ������� ������ ������ �������� ����� (����� �����)
		double valSig_d_po_dt_Sins = 0.00116;
   //	mSig_d_po_dt_Sins = 0.0004;



	Fight.mVessel.mMaxQ =     3./180.*M_PI; /// ������������ ���� ���������� �� ������������ �����(��������� ���� ��������)
	Fight.mVessel.mT_Q = 18.; // ������ ��������
	Fight.mVessel.mMaxPsi =      3./180.*M_PI;// ������������ ���� ������� �����(���������)
	Fight.mVessel.mT_Psi = 12; // ������ ������� �����
	Fight.mVessel.mMaxTet =      12./180.*M_PI; //������������ ���� ��������� �����(���������)
	Fight.mVessel.mT_Tet = 6; // ������ �������� �����
	Fight.mVessel.mMaxVert =     1. ;




	Fight.mVessel.mAmp_AftFlexure  = 1. * M_PI/180.;
	// ������ ��������� ��������� ������
	Fight.mVessel.mT_AftFlexure = 4.;
	//������������ ��������� ��������� ������ ������� � ��� �� 100 �
	Fight.mVessel.mAmp_BoardFlexure =  1. * M_PI/180.;
	// ������ ��������� ��������� ������
	Fight.mVessel.mT_BoardFlexure = 2.;
	Fight.mVessel.marrArtParral[1]=  StrTo_Dbl_(LabeledEdit2->Text);

		 // 3.1 �������� ����
	Fight.mVessel.mSins.mMaxSig_Q      =     0.000582;
	Fight.mVessel.mSins.mMaxSig_Psi    =      valSigSins ; //0.00145;
	Fight.mVessel.mSins.mMaxSig_Tet    =    valSigSins ; // 0.00145;
	Fight.mVessel.mSins.mMaxSig_dQdt   =      valSig_d_po_dt_Sins ;
	Fight.mVessel.mSins.mMaxSig_dPsidt =      valSig_d_po_dt_Sins ;
	Fight.mVessel.mSins.mMaxSig_dTetdt =      valSig_d_po_dt_Sins ;
	Fight.mVessel.mSins.mK1         = 0.01 ;
	Fight.mVessel.mSins.mSigV       =      0.2 * sqrt(2.) ;

	Fight.mVessel.mSins.mSig_H =     0.1 ;
	Fight.mVessel.mSins.mSig_VH =     0.05 ;

	Fight.mVessel.mQ0   =   StrTo_Dbl_(LabeledEdit18->Text) *M_PI / 180.;
	Fight.mVessel.mVVess =  StrTo_Dbl_(LabeledEdit11->Text) ;
	Fight.mVessel.mShellBody.mV0 = StrTo_Dbl_(LabeledEdit9->Text) ;
	memset(Fight.mVessel.marrVectSost,0,6 * sizeof(double));
	Fight.mVessel.marrVectSost[3] = Fight.mVessel.mVVess * sin(Fight.mVessel.mQ0 );
	Fight.mVessel.marrVectSost[4] = Fight.mVessel.mVVess * cos(Fight.mVessel.mQ0 );



	double valPsi0 =   StrTo_Dbl_(LabeledEdit19->Text) *M_PI / 180.;
	double valTet0 =   StrTo_Dbl_(LabeledEdit17->Text) *M_PI / 180.;
	 double valGSKEps0 =  StrTo_Dbl_(LabeledEdit6->Text) *M_PI / 180.;
	 double valGSKBet0  =  StrTo_Dbl_(LabeledEdit7->Text) *M_PI / 180.;

 double valTExtrap =  Fight.mVessel.mControlSyst.mSinsDelayT/2.
	 +  Fight.mVessel.mArtComplex.mArtCannon.mRabT;




 double valDispDeltaPsiExtr = 0., valDispDeltaTetExtr = 0., valDispDeltaQExtr = 0. ;
 double valDispDEltaExtrIS_Psi = 0., valDispDEltaExtrIS_Tet = 0.
 , valDispDEltaExtrIS_Q = 0. ; // ��������� ������ ������������� ����� ����
 double valDispDEltaExtrDeform_Psi = 0., valDispDEltaExtrDeform_Tet = 0. ; // ��������� ������ ��������� ����������� ������� �������
 // ���������� ��������� ������ �������������� �������� ����� ����
 Fight.mVessel.calcDispExtrapDeckAngles_SINS(valTExtrap, &valDispDEltaExtrIS_Psi, &valDispDEltaExtrIS_Tet, &valDispDEltaExtrIS_Q);
 Fight.mVessel.calcDispExtrapDeckAngles_Deform( &valDispDEltaExtrDeform_Psi, &valDispDEltaExtrDeform_Tet);




 valDispDeltaPsiExtr  =  valDispDEltaExtrIS_Psi ;
 valDispDeltaTetExtr  =  valDispDEltaExtrIS_Tet  ;
 valDispDeltaQExtr  =  valDispDEltaExtrIS_Q ;

// valDispDeltaPsiExtr  =   valDispDEltaExtrDeform_Psi ;
 //valDispDeltaTetExtr  =   valDispDEltaExtrDeform_Tet ;
// valDispDeltaQExtr  =  0. ;


 // ���������� ��������� ������ ���������� ����� ��������� Eps � Bet ��� ����� ��������
 double valDispEps = 0., valDispBet = 0.;


 double arrK_DelBetDelEpsGSK[4] = {0.};

 double valKGSKEps=0., valKGSKBet =0., valk = 0.;;








	 // I.  ������� �� ��������� Eps
	 int QUANT_COLS_BUFF = 4;
	 wchar_t *wcharrFileNames = new wchar_t[QUANT_COLS_BUFF * 30];
	 memset(wcharrFileNames, 0,  QUANT_COLS_BUFF * 30 * sizeof( wchar_t)) ;
	 wcscpy( &wcharrFileNames[ 0 * 30], L"Eps");
	 wcscpy( &wcharrFileNames[ 1 * 30], L"Sig_Eps_GSK");
	 wcscpy( &wcharrFileNames[ 2* 30],  L"Sig_Bet_GSK");
	 wcscpy( &wcharrFileNames[ 3 * 30], L"ro");

	 double *pscaleY = new double  [QUANT_COLS_BUFF] ;
	 for (int i = 1; i < QUANT_COLS_BUFF; i++) pscaleY[i] = 1.;
	 //pscaleY[0] = 1.;

	 const int QUANT_ROWS_BUFF = 90;

	 double *parrBuff = new double [ QUANT_COLS_BUFF * QUANT_ROWS_BUFF ];

	 for (int i = 0; i < QUANT_ROWS_BUFF ; i++)
	 {
		double valGSKEps = M_PI / 180. * ((double)i);
		TFight::transform_EpsBetGSK_to_EpsBetKGSK(&(Fight.mVessel.marrVectSost[3]), Fight.mVessel.mShellBody.mV0
		,valGSKEps, valGSKBet0, &valKGSKEps,&valKGSKBet,&valk);

		Fight.calcCorMtrx_OshibokOtrabotki_EpsBet(valKGSKEps, valKGSKBet
		,valDispDeltaPsiExtr,valDispDeltaTetExtr, valDispDeltaQExtr
		,valPsi0 ,valTet0,Fight.mVessel.mQ0, arrK_DelBetDelEpsGSK);

		valDispBet = arrK_DelBetDelEpsGSK [0];
		valDispEps = arrK_DelBetDelEpsGSK [3];
		parrBuff [ i * QUANT_COLS_BUFF ] =  valGSKEps * 180./ M_PI;
		  parrBuff [ i * QUANT_COLS_BUFF + 1] = sqrt(valDispEps) * 10000.;
		  parrBuff [ i * QUANT_COLS_BUFF + 2] = sqrt(valDispBet) * 10000.;
		  parrBuff [ i * QUANT_COLS_BUFF + 3] = arrK_DelBetDelEpsGSK [1]
		  / sqrt(arrK_DelBetDelEpsGSK [0])/ sqrt(arrK_DelBetDelEpsGSK [3])*10;

	 }




	 for (int i = 1; i < QUANT_COLS_BUFF; i++)
	 {
	 TYrWriteShapeFile::WriteOneReport(mpwchGraphDir  // ���� � �����
								  ,parrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS_BUFF // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,QUANT_ROWS_BUFF  //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,30// ������������ ����� ����� ����������
								  ,0  // ����� ���������� �� ��� X
								  ,i // ����� ���������� �� ��� Y
								  ,1. //  ������� �� ��� X
								  ,pscaleY[i]  // ������� �� ��� Y
								   )  ;
	 }
	////

	// II.  ������� �� ��������� Bet

	 wcscpy( &wcharrFileNames[ 0 * 30], L"Bet");


	 for (int i = 0; i < QUANT_ROWS_BUFF ; i++)
	 {
		double valGSKBet = M_PI / 180. * ((double)i);
		TFight::transform_EpsBetGSK_to_EpsBetKGSK(&(Fight.mVessel.marrVectSost[3]), Fight.mVessel.mShellBody.mV0
		,valGSKEps0, valGSKBet, &valKGSKEps,&valKGSKBet,&valk);

		Fight.calcCorMtrx_OshibokOtrabotki_EpsBet(valKGSKEps, valKGSKBet
		,valDispDeltaPsiExtr,valDispDeltaTetExtr, valDispDeltaQExtr
		,valPsi0 ,valTet0,Fight.mVessel.mQ0, arrK_DelBetDelEpsGSK);

		valDispBet = arrK_DelBetDelEpsGSK [0];
		valDispEps = arrK_DelBetDelEpsGSK [3];
		parrBuff [ i * QUANT_COLS_BUFF ] =  valGSKBet * 180./ M_PI;
		  parrBuff [ i * QUANT_COLS_BUFF + 1] = sqrt(valDispEps) * 10000.;
		  parrBuff [ i * QUANT_COLS_BUFF + 2] = sqrt(valDispBet) * 10000.;
		  parrBuff [ i * QUANT_COLS_BUFF + 3] = arrK_DelBetDelEpsGSK [1]
		  / sqrt(arrK_DelBetDelEpsGSK [0])/ sqrt(arrK_DelBetDelEpsGSK [3])*10;

	 }




	 for (int i = 1; i < QUANT_COLS_BUFF; i++)
	 {
	 TYrWriteShapeFile::WriteOneReport(mpwchGraphDir  // ���� � �����
								  ,parrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS_BUFF // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,QUANT_ROWS_BUFF  //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,30// ������������ ����� ����� ����������
								  ,0  // ����� ���������� �� ��� X
								  ,i // ����� ���������� �� ��� Y
								  ,1. //  ������� �� ��� X
								  ,pscaleY[i]  // ������� �� ��� Y
								   )  ;
	 }
	////







	// III.  ������� �� ��������� Psi

	 wcscpy( &wcharrFileNames[ 0 * 30], L"Psi");

	  double valStep = 12./90.;
	 for (int i = 0; i < QUANT_ROWS_BUFF ; i++)
	 {
		double valPsi = M_PI / 180. * (-6. + ((double)i) * valStep);
		TFight::transform_EpsBetGSK_to_EpsBetKGSK(&(Fight.mVessel.marrVectSost[3]), Fight.mVessel.mShellBody.mV0
		,valGSKEps0, valGSKBet0, &valKGSKEps,&valKGSKBet,&valk);

		Fight.calcCorMtrx_OshibokOtrabotki_EpsBet(valKGSKEps, valKGSKBet
		,valDispDeltaPsiExtr,valDispDeltaTetExtr, valDispDeltaQExtr
		,valPsi ,valTet0,Fight.mVessel.mQ0, arrK_DelBetDelEpsGSK);

		valDispBet = arrK_DelBetDelEpsGSK [0];
		valDispEps = arrK_DelBetDelEpsGSK [3];
		parrBuff [ i * QUANT_COLS_BUFF ] =  valPsi * 180./ M_PI;
		  parrBuff [ i * QUANT_COLS_BUFF + 1] = sqrt(valDispEps) * 10000.;
		  parrBuff [ i * QUANT_COLS_BUFF + 2] = sqrt(valDispBet) * 10000.;
		  parrBuff [ i * QUANT_COLS_BUFF + 3] = arrK_DelBetDelEpsGSK [1]
		  / sqrt(arrK_DelBetDelEpsGSK [0])/ sqrt(arrK_DelBetDelEpsGSK [3])*10;

	 }




	 for (int i = 1; i < QUANT_COLS_BUFF; i++)
	 {
	 TYrWriteShapeFile::WriteOneReport(mpwchGraphDir  // ���� � �����
								  ,parrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS_BUFF // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,QUANT_ROWS_BUFF  //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,30// ������������ ����� ����� ����������
								  ,0  // ����� ���������� �� ��� X
								  ,i // ����� ���������� �� ��� Y
								  ,1. //  ������� �� ��� X
								  ,pscaleY[i]  // ������� �� ��� Y
								   )  ;
	 }
	////

	// IIII.  ������� �� ��������� Tet

	 wcscpy( &wcharrFileNames[ 0 * 30], L"Tet");

	   valStep = 32./90.;
	 for (int i = 0; i < QUANT_ROWS_BUFF ; i++)
	 {
		double valTet = M_PI / 180. * (-16. + ((double)i) * valStep);
		TFight::transform_EpsBetGSK_to_EpsBetKGSK(&(Fight.mVessel.marrVectSost[3]), Fight.mVessel.mShellBody.mV0
		,valGSKEps0, valGSKBet0, &valKGSKEps,&valKGSKBet,&valk);

		Fight.calcCorMtrx_OshibokOtrabotki_EpsBet(valKGSKEps, valKGSKBet
		,valDispDeltaPsiExtr,valDispDeltaTetExtr, valDispDeltaQExtr
		,valPsi0 ,valTet,Fight.mVessel.mQ0, arrK_DelBetDelEpsGSK);

		valDispBet = arrK_DelBetDelEpsGSK [0];
		valDispEps = arrK_DelBetDelEpsGSK [3];
		parrBuff [ i * QUANT_COLS_BUFF ] =  valTet * 180./ M_PI;
		  parrBuff [ i * QUANT_COLS_BUFF + 1] = sqrt(valDispEps) * 10000.;
		  parrBuff [ i * QUANT_COLS_BUFF + 2] = sqrt(valDispBet) * 10000.;
		  parrBuff [ i * QUANT_COLS_BUFF + 3] = arrK_DelBetDelEpsGSK [1]
		  / sqrt(arrK_DelBetDelEpsGSK [0])/ sqrt(arrK_DelBetDelEpsGSK [3])*10;

	 }




	 for (int i = 1; i < QUANT_COLS_BUFF; i++)
	 {
	 TYrWriteShapeFile::WriteOneReport(mpwchGraphDir  // ���� � �����
								  ,parrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS_BUFF // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,QUANT_ROWS_BUFF  //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,30// ������������ ����� ����� ����������
								  ,0  // ����� ���������� �� ��� X
								  ,i // ����� ���������� �� ��� Y
								  ,1. //  ������� �� ��� X
								  ,pscaleY[i]  // ������� �� ��� Y
								   )  ;
	 }
	////





	///
	wchar_t wchFileName [300] = {0} ;
	wcscpy(wchFileName, mpwchGraphDir );
	wcscat(wchFileName, L"\\Axes.shp");
	TYrWriteShapeFile::CreateShpAxes(wchFileName,-40000.,40000,-40000.,40000) ;
	////

   delete []parrBuff;
   delete []wcharrFileNames;

}
//---------------------------------------------------------------------------

