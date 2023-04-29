//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"

#include "Diagrams.h"
#include "YrString.h"
#include "MatrixProccess.h"
#include <math.h>
#include <dir.h>
#include "Equations.h"
#include "Gauss.h"
#include "UrPointXY.h"
#include "URPolyLine.h"
#include "YrWriteShapeFile.h"
#include "Faceta.h"
#include "Far.h"
#include "URPolygon.h"
#include "DiagrSinX.h"
#include "DiagrSet.h"
#include "Diagr.h"
#include "PicturesForReport1.h"
#include "AntFar.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
static int I_ENTER_COUNT = 0  ;
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{


	  String s_22 = LabeledEdit3->Text;
		if (wcschr(s_22.w_str(), L',') )
		{
		// 1.������ ���������
		mWidthDgr =  StrTo_Dbl_(LabeledEdit3->Text) * M_PI/3000./2. ;
		//2. ��� ����
		mNoiseSkz =  StrTo_Dbl_(LabeledEdit2->Text);
		// 3.������ �������
		mAltCoord  = StrTo_Dbl_(LabeledEdit4->Text);

		//7. ��������� ����
		mDistTarg = StrTo_Dbl_(Edit3->Text);
        // ����� �����
		 mLambda=StrTo_Dbl_(LabeledEdit1->Text);
		}
		else
		{
		// ������ ���������
		mWidthDgr =  StrTo_Dbl_(LabeledEdit3->Text) * M_PI/3000./2. ;
		}



		///
/////////////////////////////////////////////////////////////////////////////////
	   // �������� ������
	   createInputGridForTarg_and_Antp();
	   createOutputGridForTarg_and_Antp();
	   createOutputGridForRezAnglesUM_Targ_and_Antp();
	   createOutputGridForTrueAnglesUM_Targ_and_Antp();

	   ///

	   // ��������� ������ �� ���� � ���������
	   // ������ ����
		 mAltTarg = 100.;//StrTo_Dbl_(LabeledEdit5->Text);
		// 6.������ ��������
		 mAltAntp = -100.;//StrTo_Dbl_(LabeledEdit11->Text);


		// 8. ������ ����, �������
		mSignLevTarg = 800.;//StrTo_Dbl_(LabeledEdit7->Text);
		// 9. ������ ��������, �������
		mSignLevAntp = 800.;//StrTo_Dbl_(LabeledEdit12->Text);

		// 11. ���� ���� ��������� ����
		 mPhaseTarg = 0.;

	   //12. ���� ���� ��������� ��������
		mPhaseAntp = 0.;

		fillInputGrids();


		// 11. ������� ���������� ����
		mcmpKTarg.m_Re= mSignLevTarg * cos(mPhaseTarg) ;
		mcmpKTarg.m_Im= mSignLevTarg * sin(mPhaseTarg) ;
	   //12. ����� ��������� ��������
		mcmpKAntp.m_Re= mSignLevAntp * cos(mPhaseAntp) ;
		mcmpKAntp.m_Im= mSignLevAntp * sin(mPhaseAntp) ;




		// ����������� ���� ����� ��������
	   int	ia = mDownAngVeer *3000./M_PI* 100.;
		LabeledEdit10->Text = ia / 100.;

    	ComboBox1->ItemIndex = 3;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	/*   const int QuantIzlutch = 16;
	   const double ValDistIzlutch = 0.02;
	   const int QuantAM = 4;
	   const double ValLengthBoardAM = 0.04;
	   TURPolygon plgFarHood;
	   wchar_t nameFold[300]  =  L"D:\\PROJECTS_C++\\���_������2\\New\\FARPict";
	  createFarPict(nameFold,  QuantIzlutch, ValDistIzlutch,  QuantAM,  ValLengthBoardAM ) ;


	   return;  */
	fncInputData();




    // �������� ���� � ����� � �������
	if (!mpwchOutFile0)
	{
	 if (I_ENTER_COUNT > 4) Close();


	 ShowMessage(L"������� ���� � ����� � ���������") ;
	 I_ENTER_COUNT++;
	 return;
	}
	wcscpy(mwchOutFold,mpwchOutFile0);
	wchar_t *pwchr = wcsrchr(mwchOutFold, L'\\');
	pwchr[0] = 0;

	createPicture1(mwchOutFold );
	wchar_t wchFileName000[300]= {0};
	wcscpy( wchFileName000,  mwchOutFold);
	wcscat(wchFileName000, L"\\FARPict");
	_wmkdir(wchFileName000);
	 TYrWriteShapeFile::PictFar(wchFileName000) ;
  // return;
   // ����� ������� ����� ������ - �������� 2-� ��������
		double alfUMTrg  = calcUMTarg();
		double alfUMAntp = calcUMAntp();
	 // �������� ������ ��������
	  TDiagrSet DiagrSet;
	  CreateDiagrSet( &DiagrSet);
	 // const int mNumDiagr  = 7 ; // ����� ��������

	  TComp *pcmpSZv = new TComp[mNumDiagr] ; // ������ ��������� ��������
	  TComp *pcmpS = new TComp[mNumDiagr] ; // ������ ��������� ��������
	 /* TDiagr *pDiagr = new TDiagr[mNumDiagr] ;

	  TFar Far;

	  // �������� 1-�� ��������� - ���������� � ����� ������������ 0.007 ���
	  int iTypeOfDiagram = 1;   // ��� ��������� - ����������
	  double parrPar[2] ={0.}; // ������ ���������� ����������� ���������
	  parrPar[0] = 0.007; // ���� ������������ ���������� ���������
	  pDiagr[0] = TDiagr( Far, iTypeOfDiagram, parrPar) ;  // ���������� � ����� ������������ 0.007 ���

		  // �������� 2-�� ��������� - ���������� � ����� ������������ -0.007 ���
	  parrPar[0] = -0.007; // ���� ������������ ���������� ���������
	  pDiagr[1] = TDiagr( Far, iTypeOfDiagram, parrPar) ;  // ���������� � ����� ������������ 0.007 ���

		  // �������� 3 -�� ��������� - ����������� � ����� ���������� 0.01 ���
	  iTypeOfDiagram = 0;   // ��� ��������� - ����������
	  parrPar[0] =0.; // ���� ������������
	  parrPar[0] = 0.01; // ���� ����������
	  pDiagr[2] = TDiagr( Far, iTypeOfDiagram, parrPar) ;  // ���������� � ����� ������������ 0.007 ���

		  // �������� 4 -�� ��������� - ����������� � ����� ���������� 0.01 ���
	  parrPar[0] = -0.01; // ���� ����������
	  pDiagr[3] = TDiagr( Far, iTypeOfDiagram, parrPar) ;  // ���������� � ����� ������������ 0.007 ���

		  // �������� 5 -�� ��������� - c�������� � ����� ������������ 0 ���
	  pDiagr[4] = TDiagr( 0.) ;
		  // �������� 6 -�� ��������� - c�������� � ����� ������������ 0.01 ���
	  pDiagr[5] = TDiagr( -0.01) ;
		  // �������� 7 -�� ��������� - c�������� � ����� ������������ 0.01 ���
	  pDiagr[6] = TDiagr( 0.01) ;
   ///

	// �������� ����������� ��������
	TDiagrSet DiagrSet( NumDiagr, pDiagr);
	///
	*/
	// ���������� �������� ��������
	   DiagrSet.createDiagrGraphs(mwchOutFold);
	///
	// ���������� ������� ��������� ���������
		//  ���������� �������� ��������  ��������
	for (int i =0; i < mNumDiagr ; i++)
	{
	  TComp cmpF1 = DiagrSet.mpDiagr[i].fncF(alfUMTrg);
	  TComp cmpF2 = DiagrSet.mpDiagr[i].fncF(alfUMAntp);
	  pcmpS[i] = mcmpKTarg * cmpF1 +  mcmpKAntp * cmpF2 ;
	  pcmpSZv[i].m_Re = pcmpS[i].m_Re +  getGauss(0., mNoiseSkz/sqrt(2.) );
	  pcmpSZv[i].m_Im = pcmpS[i].m_Im +  getGauss(0., mNoiseSkz/sqrt(2.) );

	}

	TComp cmpZTarg, cmpZAnt;
	double arrMtrxCorr[4] ={0.};
	alfUMTrg  = 0.005;
	alfUMAntp = -0.005;
	const double valXMax = 0.01;
	const double valStepX = 0.001;
 //  int irez = 	DiagrSet.solvNewtonMeth_Razn( mNoiseSkz,pcmpSZv, &cmpZTarg, &cmpZAnt, &alfUMTrg, &alfUMAntp, arrMtrxCorr  );
   int irez = DiagrSet.solvNewtonMeth_RaznPerebor( mNoiseSkz,valXMax, valStepX,pcmpSZv
   , &cmpZTarg, &cmpZAnt, &alfUMTrg, &alfUMAntp, arrMtrxCorr  );


  if (irez == 0)
  {
	double valUMTargRez = alfUMTrg * 3000./ M_PI;
	double valUMAntpRez = alfUMAntp  * 3000./ M_PI;
	// ���� �����
	int ib =  valUMTargRez * 100.;
	StringGrid5->Cells[0][1] = ib/ 100.;

	ib =  sqrt(arrMtrxCorr [0])* 3000./ M_PI * 100.;
	StringGrid5->Cells[1][1] = ib/ 100.;

	ib =  valUMAntpRez* 100.;
	StringGrid5->Cells[0][2] = ib/ 100.;

	ib =  sqrt(arrMtrxCorr [3])* 3000./ M_PI * 100.;
	StringGrid5->Cells[1][2] = ib/ 100.;
	// ������
	ib = ( mAltCoord + mDistTarg * tan(alfUMTrg)) * 100.;
	StringGrid3->Cells[1][1] =  ib/ 100.;
	ib = (mAltCoord + mDistTarg * tan(alfUMAntp)) * 100.;
	StringGrid3->Cells[1][2] = ib/ 100.;

	// ������  ������
	ib = cmpZTarg.modul()* 100.;
	StringGrid3->Cells[2][1] =   ib/ 100.;
	ib = cmpZAnt.modul()* 100.;
	StringGrid3->Cells[2][2] =   ib/ 100.;
	// ������
	ib = cmpZTarg.phase()* 180./ M_PI* 100.;
	StringGrid3->Cells[3][1] =   ib/ 100.;
	ib = cmpZAnt.phase()* 180./ M_PI* 100.;
	StringGrid3->Cells[3][2] =  ib/ 100.;
  }

	 // delete [] pDiagr ;

	 // ���������� ������� ������ ���� ���������
	 int NIsp =100, numPoints = 0;
	 TURPointXY *ppnts  =  new TURPointXY [NIsp];
	 double alfUMTrg0  = calcUMTarg();
	 double alfUMAntp0 = calcUMAntp();
	 int irez0 = -100;
	 for (int i = 0; i < NIsp; i++)
	 {
		for (int j =0; j < mNumDiagr ; j++)
		{
		TComp cmpF1 = DiagrSet.mpDiagr[j].fncF(alfUMTrg0);
		TComp cmpF2 = DiagrSet.mpDiagr[j].fncF(alfUMAntp0);
		pcmpS[j] = mcmpKTarg * cmpF1 +  mcmpKAntp * cmpF2 ;
		pcmpSZv[j].m_Re = pcmpS[j].m_Re +  getGauss(0., mNoiseSkz/sqrt(2.) );
		pcmpSZv[j].m_Im = pcmpS[j].m_Im +  getGauss(0., mNoiseSkz/sqrt(2.) );

		}
		alfUMTrg  = 0.008;
		alfUMAntp = -0.008;

		irez0 = DiagrSet.solvNewtonMeth_RaznPerebor( mNoiseSkz,valXMax, valStepX,pcmpSZv
		, &cmpZTarg, &cmpZAnt, &alfUMTrg, &alfUMAntp, arrMtrxCorr  );
		if(irez0 == 0)
		{
		  ppnts[numPoints].X = numPoints;
		  ppnts[numPoints].Y = alfUMTrg *3000./ M_PI ;
		  numPoints++;
		}

	 }
	 TURPointXY  pnt1(0., calcUMTarg()*3000./ M_PI);
	 TURPointXY  pnt2((double)numPoints, calcUMTarg()*3000./ M_PI);
	 TURPolyLine line(   pnt1,   pnt2) ;
	 wchar_t wchrStatFold[300] ={0};
	 wcscpy( wchrStatFold, mwchOutFold);
	 wcscat(wchrStatFold, L"\\Stat");
	 _wmkdir(wchrStatFold);

	  wchar_t wchFileName[300] ={0};
	wcscpy( wchFileName,  wchrStatFold);
	wcscat(wchFileName, L"\\Axes.shp");

	 TYrWriteShapeFile::CreateShpArrowedAxes(wchFileName,0.,(double)numPoints + 5.
	 ,-50.,20.,2.) ;


	 wcscpy( wchFileName,  wchrStatFold);
	wcscat(wchFileName, L"\\line.shp");
	line.WriteSetSHPFiles(wchFileName, &line, 1) ;
	 wcscpy( wchFileName,  wchrStatFold);
	wcscat(wchFileName, L"\\pnts.shp");
	TURPointXY::WriteSetSHPFiles(wchFileName, ppnts, numPoints) ;


	 delete []ppnts;
	  delete [] pcmpSZv ;
	  delete [] pcmpS ;
  return;




}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
SaveDialog1->Filter = L"����� � ��������� (*.shp)|*.shp" ;


  if (SaveDialog1->Execute())
  {
	//ShowMessage( (SaveDialog1->FileName).w_str()) ;
   mpwchOutFile0 =  (SaveDialog1->FileName).w_str();

  }
  Button1->Caption =  mpwchOutFile0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::fncInputData()
{


	   String s_22 = LabeledEdit3->Text;
		if (wcschr(s_22.w_str(), L',') )
		{
		// 1.������ ���������
		mWidthDgr =  StrTo_Dbl_(LabeledEdit3->Text) * M_PI/3000./2. ;
		//2. ��� ����
		mNoiseSkz =  StrTo_Dbl_(LabeledEdit2->Text);
		// 3.������ �������
		mAltCoord  = StrTo_Dbl_(LabeledEdit4->Text);

		//7. ��������� ����
		mDistTarg = StrTo_Dbl_(Edit3->Text);
        // ����� �����
		 mLambda=StrTo_Dbl_(LabeledEdit1->Text);

		}
		else
		{
		// ������ ���������
		mWidthDgr =  StrTo_Dbl_(LabeledEdit3->Text) * M_PI/3000./2. ;
		}

/////////////////////////////////////////////////////////////////////////////////


		miTypeDiagrSet = ComboBox1->ItemIndex;

	   // ��������� ������ �� ���� � ���������
	   InputGridDataTarg_and_Antp();
	   ///






	//����������� ���� ����� ����
      //����������� ���� ����� ����

		int ia = calcCritUMTarg() *3000./M_PI * 100.;
		LabeledEdit9->Text = ia / 100.;

		// ����������� ���� ����� ��������
		ia = calcMinUMAntp() *3000./M_PI* 100.;
		LabeledEdit10->Text = ia / 100.;




 updatRezGrids();
 updatRezTrueAngUMGrid() ;
}




void __fastcall TForm1::LabeledEdit4Change(TObject *Sender)
{

fncInputData();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::LabeledEdit5Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LabeledEdit6Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LabeledEdit11Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------



// ���� ���� ����� ���� ������������ ������������ ������ ����� ����, �� ������� �������� ���
double  __fastcall TForm1::calcCritUMTarg()
{
 return (-atan(mAltCoord/ mDistTarg)+   mWidthDgr) ;
}

// ���� ������ ���� ������ ����, �� ������� �������� �� �����
double  __fastcall TForm1::calcCritElevTarg()
{
	return mAltCoord - mDistTarg * tan(atan(mAltCoord/ mDistTarg)-  calcCritUMTarg());
}
 // ���������� ��������� ���� ����� �������� ������������ ������������
double  __fastcall TForm1::calcMinUMAntp()
{
 return - atan((calcCritElevTarg() + mAltCoord)/ mDistTarg) ;
}


//---------------------------------------------------------------------------

void __fastcall TForm1::LabeledEdit15Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LabeledEdit16Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LabeledEdit17Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LabeledEdit18Change(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------
// ���������� ���� ����� ���� ��������� ������������ ������������
double  __fastcall TForm1::calcUMTarg()
{
return atan((mAltTarg- mAltCoord)/ mDistTarg);
}
//---------------------------------------------------------------------------
// ���������� ���� ����� ��������� ��������� ������������ ������������
double  __fastcall TForm1::calcUMAntp()
{
return atan((mAltAntp- mAltCoord)/ mDistTarg);
}


//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Exit(TObject *Sender)
{
	mDistTarg = StrTo_Dbl_(Edit3->Text );
	//����������� ���� ����� ����
		mUpAngVeer =  calcCritUMTarg();
		mDownAngVeer = calcMinUMAntp();
		int ia = mUpAngVeer *3000./M_PI * 100.;
		LabeledEdit9->Text = ia / 100.;

		// ����������� ���� ����� ��������
		ia = mDownAngVeer *3000./M_PI* 100.;
		LabeledEdit10->Text = ia / 100.;


		// ��������� ����� ������� ����� ����� ����� ��������

    updatRezGrids();
	fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid2Exit(TObject *Sender)
{
  updatRezTrueAngUMGrid() ;

 // updateVeerDiagrams();
  updatRezGrids();
  fncInputData();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::createInputGridForTarg_and_Antp()
{
	   StringGrid2->Cells[0][1] = L"����";
	   StringGrid2->Cells[0][2] = L"�������";
	   StringGrid2->Cells[1][0]  = L"������, �.";

	   StringGrid2->Cells[2][0]  = L"������,����.";
	   StringGrid2->Cells[3][0]  = L"���.���� ����.,����";
	   StringGrid2->ColWidths[0]= 150;
	   StringGrid2->ColWidths[1]= 130;
	   StringGrid2->ColWidths[2]= 130;
	   StringGrid2->ColWidths[3]= 130;
}


//---------------------------------------------------------------------------
void __fastcall TForm1::createOutputGridForTarg_and_Antp()
{
	   StringGrid3->Cells[0][1] = L"����";
	   StringGrid3->Cells[0][2] = L"�������";
	   StringGrid3->Cells[1][0]  = L"������, �.";

	   StringGrid3->Cells[2][0]  = L"������,����.";
	   StringGrid3->Cells[3][0]  = L"���.���� ����.,����";
	   StringGrid3->ColWidths[0]= 150;
	   StringGrid3->ColWidths[1]= 130;
	   StringGrid3->ColWidths[2]= 130;
	   StringGrid3->ColWidths[3]= 130;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::createOutputGridForTrueAnglesUM_Targ_and_Antp()
{

	   StringGrid4->Cells[0][0]  = L"���� �����, �.�.";

	   StringGrid4->ColWidths[0]= 80;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::createOutputGridForRezAnglesUM_Targ_and_Antp()
{

	   StringGrid5->Cells[0][0]  = L"���� �����, �.�.";
	   StringGrid5->Cells[1][0]  = L"C��, �.�.";

	   StringGrid5->ColWidths[0]= 80;
	   StringGrid5->ColWidths[1]= 80;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::fillInputGrids()
{

		StringGrid2->Cells[1][1] = mAltTarg ;
		StringGrid2->Cells[1][2] = mAltAntp;

		StringGrid2->Cells[2][1] = mSignLevTarg;
		StringGrid2->Cells[2][2] = mSignLevAntp;
		StringGrid2->Cells[3][1] = mPhaseTarg;
		StringGrid2->Cells[3][2] = mPhaseAntp;
		int ia = atan((mAltTarg- mAltCoord)/ mDistTarg)*3000./M_PI * 100.;
		StringGrid4->Cells[0][1] = ((double)ia)/ 100.;
		ia =  atan((mAltAntp- mAltCoord)/ mDistTarg)*3000./M_PI * 100.;
		StringGrid4->Cells[0][2] = ((double)ia)/ 100.;
}

//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
// ���������� ���������� � ������ � ������������ ����� ��������
void __fastcall TForm1::updatRezGrids()
{
		for (int i= 1; i < 3; i++)
		for (int j= 1; j < StringGrid3->ColCount  ; j++)
		{
		 StringGrid3->Cells[j][i]= L"";
		}
		for (int i= 1; i < 3; i++)
		for (int j= 0; j < StringGrid5->ColCount  ; j++)
		{
		 StringGrid5->Cells[j][i]= L"";
		}
}
//--------------------------------------------------------------------------
// ���������� ���������� � ����� � ��������� ������ ���� � ��������
void __fastcall TForm1::updatRezTrueAngUMGrid()
{
		int ia = atan((mAltTarg- mAltCoord)/ mDistTarg)*3000./M_PI * 100.;
		StringGrid4->Cells[0][1] = ia / 100.;
		ia = atan((mAltAntp- mAltCoord)/ mDistTarg)*3000./M_PI * 100.;
		StringGrid4->Cells[0][2] =  ia / 100.;
}
//--------------------------------------------------------------------------
// ���������� �������� ���������� �� ����� � ������� ���� � ��������
void __fastcall TForm1::InputGridDataTarg_and_Antp()
{
 // ��������� ������ �� ���� � ���������
	   // ������ ����
		mAltTarg = StrTo_Dbl_(StringGrid2->Cells[1][1] );
		// 6.������ ��������
		 mAltAntp =StrTo_Dbl_(StringGrid2->Cells[1][2]);


		// 8. ������ ����, �������
		mSignLevTarg = StrTo_Dbl_(StringGrid2->Cells[2][1]);
		// 9. ������ ��������, �������
		mSignLevAntp = StrTo_Dbl_(StringGrid2->Cells[2][2]);

		// 11. ���� ���� ��������� ����
		 mPhaseTarg = StrTo_Dbl_(StringGrid2->Cells[3][1]) * M_PI / 180.;
		 mcmpKTarg.m_Re = mSignLevTarg * cos(mPhaseTarg) ;
		 mcmpKTarg.m_Im = mSignLevTarg * sin(mPhaseTarg) ;


	   //12. ���� ���� ��������� ��������
		mPhaseAntp = StrTo_Dbl_(StringGrid2->Cells[3][2]) * M_PI / 180.;
		mcmpKAntp.m_Re = mSignLevAntp * cos(mPhaseAntp) ;
		mcmpKAntp.m_Im = mSignLevAntp * sin(mPhaseAntp) ;

 updatRezGrids();
 updatRezTrueAngUMGrid() ;


}
//--------------------------------------------------------------------------

void __fastcall TForm1::LabeledEdit1Exit(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::LabeledEdit2Exit(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::LabeledEdit3Exit(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LabeledEdit4Exit(TObject *Sender)
{
fncInputData();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CreateDiagrSet( TDiagrSet *pDiagrSet0)
{
// 16 ��������� ���������
  if (miTypeDiagrSet == 0)
  {
	int iNumDiagr = 16;
	double *parrAlfaDiagr = new double [ iNumDiagr] ;
	memset(parrAlfaDiagr, 0, iNumDiagr * sizeof(double));
	double del = 0.02/ ((double)(iNumDiagr-1));
	for (int i = 0; i < iNumDiagr; i++)
	{
	 parrAlfaDiagr[i] = -0.01 + ((double)i) * del;
	}
	TDiagrSet DiagrSet(iNumDiagr, parrAlfaDiagr);
	*pDiagrSet0 =  DiagrSet;
	delete parrAlfaDiagr;
	mNumDiagr = iNumDiagr;
	return;
  }
 ///
 // 4 ��������� ���������
  if (miTypeDiagrSet == 1)
  {
	int iNumDiagr = 4;
	double *parrAlfaDiagr = new double [ iNumDiagr] ;
	memset(parrAlfaDiagr, 0, iNumDiagr * sizeof(double));
	double del = 0.02/ ((double)(iNumDiagr-1));
	for (int i = 0; i < iNumDiagr; i++)
	{
	 parrAlfaDiagr[i] = -0.01 + ((double)i) * del;
	}
	TDiagrSet DiagrSet(iNumDiagr, parrAlfaDiagr);
	*pDiagrSet0 =  DiagrSet;
	delete parrAlfaDiagr;
	mNumDiagr = iNumDiagr;
	return;
  }
 ///
 //
  if (miTypeDiagrSet == 2)
  {
	  TFar Far;
	  mNumDiagr = 7;
	  TDiagr *pDiagr =  (TDiagr *)malloc(mNumDiagr * sizeof( TDiagr)) ;
	  // �������� 1-�� ��������� - ���������� � ����� ������������ 0.007 ���
	  int iTypeOfDiagram = 1;   // ��� ��������� - ����������
	  double parrPar[2] ={0.}; // ������ ���������� ����������� ���������
	  parrPar[0] = 0.007; // ���� ������������ ���������� ���������
	  pDiagr[0] = TDiagr( Far, iTypeOfDiagram, parrPar) ;  // ���������� � ����� ������������ 0.007 ���

		  // �������� 2-�� ��������� - ���������� � ����� ������������ -0.007 ���
	  parrPar[0] = -0.007; // ���� ������������ ���������� ���������
	  pDiagr[1] = TDiagr( Far, iTypeOfDiagram, parrPar) ;  // ���������� � ����� ������������ 0.007 ���

		  // �������� 3 -�� ��������� - ����������� � ����� ���������� 0.01 ���
	  iTypeOfDiagram = 0;   // ��� ��������� - ����������
	  parrPar[0] =0.; // ���� ������������
	  parrPar[0] = 0.01; // ���� ����������
	  pDiagr[2] = TDiagr( Far, iTypeOfDiagram, parrPar) ;  // ���������� � ����� ������������ 0.007 ���

		  // �������� 4 -�� ��������� - ����������� � ����� ���������� 0.01 ���
	  parrPar[0] = -0.01; // ���� ����������
	  pDiagr[3] = TDiagr( Far, iTypeOfDiagram, parrPar) ;  // ���������� � ����� ������������ 0.007 ���

		  // �������� 5 -�� ��������� - c�������� � ����� ������������ 0 ���
	  pDiagr[4] = TDiagr( 0.) ;
		  // �������� 6 -�� ��������� - c�������� � ����� ������������ 0.01 ���
	  pDiagr[5] = TDiagr( -0.01) ;
		  // �������� 7 -�� ��������� - c�������� � ����� ������������ 0.01 ���
	  pDiagr[6] = TDiagr( 0.01) ;
   ///

	// �������� ����������� ��������

	TDiagrSet DiagrSet( mNumDiagr, pDiagr);
	*pDiagrSet0 =  DiagrSet;
	free( pDiagr);
	return;
  }
  // 4 ��������� ���������
  if (miTypeDiagrSet == 3)
  {
	TFar Far;
	mNumDiagr = 4;
	TDiagr *pDiagr =  (TDiagr *)malloc(mNumDiagr * sizeof( TDiagr)) ;
	TComp arrCmpElCurrent[4];
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));

	// �������� 1-�� ���������
	arrCmpElCurrent [0] = TComp(1./4.,0.);
	pDiagr[0] = TDiagr(Far, arrCmpElCurrent);

	// �������� 2-�� ���������
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));
	arrCmpElCurrent [1] = TComp(1./4.,0.);
	pDiagr[1] = TDiagr(Far, arrCmpElCurrent);

	// �������� 3 -�� ���������
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));
	arrCmpElCurrent [2] = TComp(1./4.,0.);
	pDiagr[2] = TDiagr(Far, arrCmpElCurrent);

	// �������� 4 -�� ���������
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));
	arrCmpElCurrent [3] = TComp(1./4.,0.);
	pDiagr[3] = TDiagr(Far, arrCmpElCurrent);
	// �������� ����������� ��������

	TDiagrSet DiagrSet( mNumDiagr, pDiagr);
	*pDiagrSet0 =  DiagrSet;
	free( pDiagr);
	return;
  }

   // 2 ��������� + ���������
  if (miTypeDiagrSet == 4)
  {
	TFar Far;
	mNumDiagr = 3;
	TDiagr *pDiagr =  (TDiagr *)malloc(mNumDiagr * sizeof( TDiagr)) ;
	TComp arrCmpElCurrent[4];
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));

	// �������� 1-�� ���������  -  ���������������
	arrCmpElCurrent [0] = TComp(2./5.,0.);
	arrCmpElCurrent [1] = TComp(1./5.,0.);
	arrCmpElCurrent [2] = arrCmpElCurrent [1] ;
	arrCmpElCurrent [3] = arrCmpElCurrent [1] ;
	pDiagr[0] = TDiagr(Far, arrCmpElCurrent);

	// �������� 2-�� ��������� -  ���������������
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));
	arrCmpElCurrent [3] = TComp(2./5.,0.);
	arrCmpElCurrent [1] = TComp(1./5.,0.);
	arrCmpElCurrent [2] = arrCmpElCurrent [1] ;
	arrCmpElCurrent [0] = arrCmpElCurrent [1] ;
	pDiagr[1] = TDiagr(Far, arrCmpElCurrent);

	// �������� 3 -�� ���������  - ���������
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));
	arrCmpElCurrent [3] = TComp(1./4.,0.);
	arrCmpElCurrent [1] = TComp(1./4.,0.);
	arrCmpElCurrent [2] = TComp(1./4.,0.);
	arrCmpElCurrent [0] = TComp(1./4.,0.);
	pDiagr[2] = TDiagr(Far, arrCmpElCurrent);


	// �������� ����������� ��������

	TDiagrSet DiagrSet( mNumDiagr, pDiagr);
	*pDiagrSet0 =  DiagrSet;
	free( pDiagr);
	return;
  }

   // 2 ��������������� + ����������
  if (miTypeDiagrSet == 5)
  {
	TFar Far;
	mNumDiagr = 3;
	TDiagr *pDiagr =  (TDiagr *)malloc(mNumDiagr * sizeof( TDiagr)) ;
	TComp arrCmpElCurrent[4];
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));

	// �������� 1-�� ���������  - ���������������
	arrCmpElCurrent [0] = TComp(2./5.,0.);
	arrCmpElCurrent [1] = TComp(1./5.,0.);
	arrCmpElCurrent [2] = arrCmpElCurrent [1] ;
	arrCmpElCurrent [3] = arrCmpElCurrent [1] ;
	pDiagr[0] = TDiagr(Far, arrCmpElCurrent);

	// �������� 2-�� ��������� - ���������������
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));
	arrCmpElCurrent [3] = TComp(2./5.,0.);
	arrCmpElCurrent [1] = TComp(1./5.,0.);
	arrCmpElCurrent [2] = arrCmpElCurrent [1] ;
	arrCmpElCurrent [0] = arrCmpElCurrent [1] ;
	pDiagr[1] = TDiagr(Far, arrCmpElCurrent);

	// �������� 3 -�� ���������  - ����������
	const int iTypeOfDiagram = 0;
	double parrPar[2] = {0.};
	pDiagr[2] = TDiagr( Far,  iTypeOfDiagram, parrPar);


	// �������� ����������� ��������

	TDiagrSet DiagrSet( mNumDiagr, pDiagr);
	*pDiagrSet0 =  DiagrSet;
	free( pDiagr);
	return;
  }

	// 2 ��������������� + ���������� + ���������
  if (miTypeDiagrSet == 6)
  {
	TFar Far;
	mNumDiagr = 4;
	TDiagr *pDiagr =  (TDiagr *)malloc(mNumDiagr * sizeof( TDiagr)) ;
	TComp arrCmpElCurrent[4];
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));

	// �������� 1-�� ���������  - ���������������
	arrCmpElCurrent [0] = TComp(2./5.,0.);
	arrCmpElCurrent [1] = TComp(1./5.,0.);
	arrCmpElCurrent [2] = arrCmpElCurrent [1] ;
	arrCmpElCurrent [3] = arrCmpElCurrent [1] ;
	pDiagr[0] = TDiagr(Far, arrCmpElCurrent);

	// �������� 2-�� ��������� - ���������������
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));
	arrCmpElCurrent [3] = TComp(2./5.,0.);
	arrCmpElCurrent [1] = TComp(1./5.,0.);
	arrCmpElCurrent [2] = arrCmpElCurrent [1] ;
	arrCmpElCurrent [0] = arrCmpElCurrent [1] ;
	pDiagr[1] = TDiagr(Far, arrCmpElCurrent);


	// �������� 3 -�� ���������  - ���������
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));
	arrCmpElCurrent [3] = TComp(1./4.,0.);
	arrCmpElCurrent [1] = TComp(1./4.,0.);
	arrCmpElCurrent [2] = TComp(1./4.,0.);
	arrCmpElCurrent [0] = TComp(1./4.,0.);
	pDiagr[2] = TDiagr(Far, arrCmpElCurrent);


	// �������� 4 -�� ���������  - ����������
	const int iTypeOfDiagram = 0;
	double parrPar[3] = {0.};
	pDiagr[3] = TDiagr( Far, iTypeOfDiagram, parrPar);


	// �������� ����������� ��������

	TDiagrSet DiagrSet( mNumDiagr, pDiagr);
	*pDiagrSet0 =  DiagrSet;
	free( pDiagr);
	return;
  }

	// ����� =  ���������� + ��������� + ������������
  if (miTypeDiagrSet == 7)
  {
	TFar Far;
	mNumDiagr = 3;
	TDiagr *pDiagr =  (TDiagr *)malloc(mNumDiagr * sizeof( TDiagr)) ;
	TComp arrCmpElCurrent[4];
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));



	// �������� 1 -�� ���������  - ���������
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));
	arrCmpElCurrent [3] = TComp(1./4.,0.);
	arrCmpElCurrent [1] = TComp(1./4.,0.);
	arrCmpElCurrent [2] = TComp(1./4.,0.);
	arrCmpElCurrent [0] = TComp(1./4.,0.);
	pDiagr[0] = TDiagr(Far, arrCmpElCurrent);


	// �������� 2 -� ���������  - ����������
	const int iTypeOfDiagram = 0;
	double parrPar[2] = {0.};
	pDiagr[1] = TDiagr( Far,  iTypeOfDiagram, parrPar);

	 // �������� 3 -�� ���������  - ������������
	memset(arrCmpElCurrent, 0, 4 *sizeof(TComp));
	arrCmpElCurrent [0] = TComp(1./3.,0.);
	arrCmpElCurrent [3] = TComp(1./3.,0.);
	arrCmpElCurrent [1] = TComp(1./6.,0.);
	arrCmpElCurrent [2] = TComp(1./6.,0.);

	pDiagr[2] = TDiagr(Far, arrCmpElCurrent);


	// �������� ����������� ��������

	TDiagrSet DiagrSet( mNumDiagr, pDiagr);
	*pDiagrSet0 =  DiagrSet;
	free( pDiagr);
	return;
  }
  // 8 ���������
	if (miTypeDiagrSet == 8)
  {
	TFaceta Faceta(16) ;
	 // ���������� ������� (�����)
  int N = 8;
 // ���������� ����� ��������
  double D = 32.8;
 // ����� �����
  double Lambda = 3.15;;
	 TFar Far( N, D, Lambda, Faceta);
	mNumDiagr = N;
	TDiagr *pDiagr =  (TDiagr *)malloc(mNumDiagr * sizeof( TDiagr)) ;
	TComp arrCmpElCurrent[8];


	for (int j =0; j < mNumDiagr; j++)
	{
	memset(arrCmpElCurrent, 0, 8 *sizeof(TComp));
	arrCmpElCurrent [j] = TComp(1./8.,0.);
	pDiagr[j] = TDiagr(Far, arrCmpElCurrent);
	}


	TDiagrSet DiagrSet( mNumDiagr, pDiagr);
	*pDiagrSet0 =  DiagrSet;
	free( pDiagr);
	return;
  }

   // 16 ���������
	if (miTypeDiagrSet == 9)
  {

	TFaceta Faceta(16) ;
	 // ���������� ������� (�����)
  int N = 16;
 // ���������� ����� ��������
  double D = 32.8;
 // ����� �����
  double Lambda = 3.15;;
	 TFar Far( N, D, Lambda, Faceta);
	mNumDiagr = N;
	TDiagr *pDiagr =  (TDiagr *)malloc(mNumDiagr * sizeof( TDiagr)) ;
	TComp *arrCmpElCurrent = new TComp[N];


	for (int j =0; j < mNumDiagr; j++)
	{
	memset(arrCmpElCurrent, 0, mNumDiagr *sizeof(TComp));
	arrCmpElCurrent [j] = TComp(1./mNumDiagr,0.);
	pDiagr[j] = TDiagr(Far, arrCmpElCurrent);
	}


	TDiagrSet DiagrSet( mNumDiagr, pDiagr);
	*pDiagrSet0 =  DiagrSet;
	delete []arrCmpElCurrent ;
	free( pDiagr);
	return;
  }

   // 32 ���������
	if (miTypeDiagrSet == 10)
  {

	TFaceta Faceta(16) ;
	 // ���������� ������� (�����)
  int N = 32;
 // ���������� ����� ��������
  double D = 32.8;
 // ����� �����
  double Lambda = 3.15;;
	 TFar Far( N, D, Lambda, Faceta);
	mNumDiagr = N;
	TDiagr *pDiagr =  (TDiagr *)malloc(mNumDiagr * sizeof( TDiagr)) ;
	TComp *arrCmpElCurrent = new TComp[N];


	for (int j =0; j < mNumDiagr; j++)
	{
	memset(arrCmpElCurrent, 0, mNumDiagr *sizeof(TComp));
	arrCmpElCurrent [j] = TComp(1./mNumDiagr,0.);
	pDiagr[j] = TDiagr(Far, arrCmpElCurrent);
	}


	TDiagrSet DiagrSet( mNumDiagr, pDiagr);
	*pDiagrSet0 =  DiagrSet;
	delete []arrCmpElCurrent ;
	free( pDiagr);
	return;
  }
}



