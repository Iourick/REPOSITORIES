//---------------------------------------------------------------------------

#ifndef AM_2DH
#define AM_2DH

class TComp;
class TSingleSign;
class TAM_2D
{
public:

// �-�� ����������� �� �����������
	int mNumEmitCols;
	// �-�� ����������� �� �����������
	int mNumEmitRows;
	// ���������� ����� ������������ �� �����������
	double mdCol;
	// ���������� ����� ������������ �� ���������
	double mdRow;

	//  ��� ���� ����������
	double mSigEmitNoise ;
	//  ��� ���� �� ���������( 1 + delta)
	double mSigEmitAmplFact ;
	// ���������� ������������ ��������
	double mOtklCoefUs;
	// ���������� ��� �� ���� ����
	 double mOtklBetta;
	// ���������� ��� ��  ����  �����
	 double mOtklEps;

 __fastcall  TAM_2D() ;
// ����������� �����������
__fastcall  TAM_2D (const TAM_2D &R2) ;
 // ����� ������
 __fastcall TAM_2D(const int NumEmitCols,const int NumEmitRows
	  ,const double dCol,const double dRow, const double SigEmitNoise);
// ����� ������ 2
 __fastcall TAM_2D(const int NumEmitCols,const int NumEmitRows
	  ,const double dCol,const double dRow, const double SigEmitNoise
	  , const double OtklCoefUs, const double OklBetta
	  , const double OtklEps );

// ����� ������ 3
 __fastcall TAM_2D(const int NumEmitCols,const int NumEmitRows
	  ,const double dCol,const double dRow, const double SigEmitNoise
	  ,const double SigEmitAmplFact);

 // �������� ������������
 TAM_2D   &operator=(const TAM_2D  &R2) ;

 TComp fncIdealDiagr (const double valBetta,const double valEps,const double valLambda) ;
 TComp fncImitateSingleTargMeasure(const double valBetta,const double valEps ,const double valLambda
	 , const double valAmpl, const double valPhase, TComp * pcmpEmitMeasures);

 void createVertIdealDiagrGraphs(const double valLambda, wchar_t *wchFoldName1 ) ;

 //TComp fncImitateMultiTargMeasure ( TSingleSign signTarg, TSingleSign *parrsignFalse, int quantFalseSign
  //	 ,const double valLambda, TComp * pcmpTrueEmitMeasures, TComp * pcmpNoisedEmitMeasures) ;

 TComp fncImitateSingleTargMeasure (const TSingleSign Sign, const double valLambda
	   , TComp * pcmpTrueEmitMeasures, TComp * pcmpNoisedEmitMeasures)  ;


 static TAM_2D create_AM_5P10(const double valSigNoise);

 double calcSumDisp()  ;

 double calcSumAmplFactDisp();

 double calcSquare();


};
//---------------------------------------------------------------------------
#endif
