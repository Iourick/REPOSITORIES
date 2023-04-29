//---------------------------------------------------------------------------

#ifndef Far_2DH
#define Far_2DH
#include "AM_2D.h"

class TAM_2D;
class TComp;
class TSingleSign;

class TEtalonSign;
class TFar;

class TFar_2D
{
public:

	// �-�� ��  �� �����������
	int mNumAMCols;
	// �-�� �� �� ���������
	int mNumAMRows;
	// ���������� ����� �� �� �����������
	double mdAMCol;
	// ���������� ����� �� �� ���������
	double mdAMRow;
	// ����� �����
	double mLambda ;
	// ������ ��
	TAM_2D *mpAm2D;
	// ��� ������ ����������� ���������
	double mDistSKZ;
	// ��������� ������ �����������
	bool *mpbarrAM;

	__fastcall ~TFar_2D() ;
 __fastcall  TFar_2D() ;
// ����������� �����������
 __fastcall  TFar_2D (const TFar_2D &R2) ;
 // ����� ������
__fastcall TFar_2D(int NumAMCols, int NumAMRows, double Lambda ,double dAMCol
	 ,double dAMRow , TAM_2D *pAm2D );
 // ����� ������
__fastcall TFar_2D(int NumAMCols, int NumAMRows, double Lambda ,double dAMCol
	 ,double dAMRow , TAM_2D am2D );

__fastcall TFar_2D(int NumAMCols, int NumAMRows, double Lambda ,double dAMCol
	 ,double dAMRow , TAM_2D am2D, bool *pbarrAM , const double DistSKZ) ;

// �������� ������������
TFar_2D   &operator=(const TFar_2D  &R2) ;
  // ����� ������
 __fastcall TFar_2D(int NumAMCols, int NumAMRows, double Lambda ,double dAMCol
	 ,double dAMRow , TAM_2D am2D, bool *pbarrAM );

 TComp fncIdealDiagr (const double valBetta,const double valEps)  ;

void createVertIdealDiagrGraphs( wchar_t *wchFoldName1 );

void fncImitateMeasuresArray (const double valAmpl,const double valPhase
 ,const double valBetta,const double valEps, TComp *pcmpAmMeasures);

 void createNormCoefGraphs_For_5P10( wchar_t *wchFoldName1 )  ;

static TFar_2D create_5P10(const double valSigNoise, const double valLambda ) ;

void calcEstRSM(TComp *pcmpAmMeasures, double *pEstBet, double *pSigBet
	 , double *pEstEps, double *pSigEps) ;
TComp calcRigthDiagr(TComp *pcmpAmMeasures, double *pDisp);

TComp calcLeftDiagr(TComp *pcmpAmMeasures, double *pDisp);

TComp calcUpperDiagr(TComp *pcmpAmMeasures, double *pDisp)  ;

TComp calcDownDiagr(TComp *pcmpAmMeasures, double *pDisp) ;

void calcEstBetRSM(TComp *pcmpAmMeasures, double *pEstBet, double *pSigBet) ;

void calcEstEpsRSM(TComp *pcmpAmMeasures, double *pEstEps, double *pSigEps) ;

double fncPeleng(TComp cmpUp,TComp cmpDown, TComp *pcmp_dPel_po_dSUp
   , TComp *pcmp_dPel_po_dSDown);

void fncImitateMeasuresArray (const TSingleSign Sign, TComp *pcmpTrueAmMeasures, TComp *pcmpNoisedAmMeasures);

 void fncAddNoise_To_TrueMeasuresArray (TComp *pcmpTrueAmMeasures, TComp *pcmpNoisedAmMeasures);


TComp calcNormCoeffFor_1_and_4_Rows_5P10(const double ValBetta )  ;

void calcEstEpsRSM_5P10_Correction_1_and_4_Rows(TComp *pcmpAmMeasures
  , const double ValBet, double *pEstEps, double *pSigEps)  ;

void fncImitateMultiTargMeasure ( TSingleSign signTarg, TSingleSign *parrsignFalse, int quantFalseSign
	 , TComp * pcmpTrueAmMeasures, TComp * pcmpNoisedAMMeasures) ;

bool calcEstRSM_5P10_Correction_InAccordanceWithModel(TComp *pcmpAmMeasures
  , double *pEstBet, double *pSigBet, double *pEstEps, double *pSigEps);

void calcEstBetRSM_5P10_StepCorrection_Left_and_Right_Diagr( TComp *pcmpAmMeasures
  , const double ValEstEps,  double *pEstBet, double *pSigBet)  ;

bool calcEstIterRSM( const TComp CmpUp	,const TComp CmpDown
	,const double ValDispUp, const double ValDispDown
   ,const TComp CmpRight, const TComp CmpLeft
   ,const double ValDispRight, const double ValDispLeft
  , double *pEstBet, double *pSigBet, double *pXiSq4Bet
  , double *pEstEps, double *pSigEps, double *pXiSq4Eps)  ;

void calcIdealEstRSM(const TComp CmpUp,const TComp CmpDown, const double ValDispUp
, const double ValDispDown, const double ValD, double *pEstEps, double *pSigEps, double *pXiSq4Eps);

void fncStep_CorrectBet_RightAndLeftDiagr_RSM(  const TComp CmpRight, const TComp CmpLeft
  ,const double ValEstEps, double *pvalEstBet0, double *pvalSigBet0, double *pvalXiSq4Bet);

void fncStep_CorrectEps_UpAndDownDiagr_RSM (const TComp CmpUp	,const TComp CmpDown
	,const double ValEstBet, double *pvalEstEps0, double *pvalSigEps0, double *pvalXiSq4Eps) ;

TComp fnc_fUp( const double ValEstBet, const double ValEstEps) ;

TComp fnc_fDown( const double ValEstBet, const double ValEstEps)  ;

double fnc_qml( const double ValEstBet, const double ValEstEps, const int Num_m, const int Num_l)  ;

TComp fnc_fRight( const double ValEstBet, const double ValEstEps)  ;

TComp fnc_fLeft( const double ValEstBet, const double ValEstEps);

void createSystemErrorGraphs_RSM( wchar_t *wchFoldName1 ) ;

void createSystemErrorGraphsFixedBetta_RSM(const double ValBet,wchar_t *wchFoldName1 )  ;

void createSystemErrorGraphsFixedEps_RSM( const double ValEps, wchar_t *wchFoldName1 )  ;


double calcIdealXiSq4_For_RSM( TComp CmpUp, TComp CmpDown, const double ValDispUp
, const double ValDispDown, const double ValD, const double ValEstEps);

double calcRealXi4Sq_Bet_RSM (const TComp CmpUp	,const TComp CmpDown
	,const double ValEstBet,const double ValEstEps);

double calcRealXi4Sq_Eps_RSM (const TComp CmpUp	,const TComp CmpDown
	,const double ValEstBet,const double ValEstEps);


void calcQuarterDiagrams(TComp *pcmpAmMeasures,TComp *pcmparrQuaterMeasures, double *parrQuaterDisp);

double calcRealXi8Sq_RSM (TComp *pcmparrQuaterMeasures, double *parrQuaterDisp
	,const double ValEstBet,const double ValEstEps) ;

void calcFuncRoQuarters( const double ValEstBet, const double ValEstEps, TComp *pamparrRoQuarters);

 void createMonteCarloRSM( const TSingleSign SingleSig,const int Nisp
   , const int QuantMeasXi2, bool *barrRealAM, wchar_t *wchFoldName1 );

double  calcSigEtalonRSM_Eps(TEtalonSign EtalonSign, double valEps) ;

double  calcSigEtalonRSM_Bet(TEtalonSign EtalonSign, double valBet) ;

int calcQuantWorkingAM();

double  calcNWaveEtalon (TEtalonSign EtalonSign);

//double calc_TwoTargsResolutionDist(const double VAlTargH, const double VAlTargEPR
 // ,const double PowerPrd, const double KYPrd, const TEtalonSign ETalonSign , const double VAlHAntenna, double *pvalSigTarg );
/*
double calc_TwoTargsZahvatDist(const double VAlTargH, const double VAlTargEPR
  ,const double PowerPrd, const double KYPrd, const TEtalonSign ETalonSign , const double VAlHAntenna
  , bool *bLat  , double *pvalSigE ,double *pvalSigQ  ); */

 /*bool calc_SKZ_LAT(const double VAlTargD,const double VAlTargH
  ,const double VAlHAntenna, const double VAlAntNormalAng, const double VAlTargEPR
  , const TEtalonSign EtalonSign ,const double PowerPrd,const double KYPrd, double valAntpPhaze
  , double *pvalSigE ,double *pvalSigQ  );*/


double calcKYPriem();
double calcSumDisp();
double  calcCurrentSignalAmpl (const double VAlTargD, const double VAlTargEPR
   ,const double PowerPrd, const double KYPrd, const TEtalonSign EtalonSign);
double calcAppertHor();

double calcAppertVert();

void fncEstimateCourseAngs_For_TwoTargs (TComp *cmparrAmMeasures,const double VAlEstEpsTarg, const double VAlEstEpsAntp
	  , TComp CMpKTarg ,  TComp CMpKAntp , double *arrMtrxCorrEps,
	  double *pvalEstBetTarg, double *pvalEstBetAntp , double *arrMtrxCorrBet);

bool calc_SKZ_SingleTarg(const double VAlTargD
 , const double VAlAntNormalAng, const double VAlTargEPR
  , const TEtalonSign EtalonSign ,const double PowerPrd,const double KYPrd
	, double *pvalSigE ,double *pvalSigQ  );

bool calc_SKZ_LAT(const double VAlCoefAntp,const double VAlTargD,const double VAlTargH
  ,const double VAlHAntenna, const double VAlAntNormalAng, const double VAlTargEPR
  , const TEtalonSign EtalonSign ,const double PowerPrd,const double KYPrd, double valAntpPhaze
	, double *pvalSigE ,double *pvalSigQ  );

double calc_TwoTargsResolutionDist(const double VAlCoefAntp,const double VAlTargH, const double VAlTargEPR
  ,const double PowerPrd, const double KYPrd, const TEtalonSign ETalonSign , const double VAlHAntenna, double *pvalSigTarg );

double calc_TwoTargsZahvatDist(const double VAlCoefAntp,const double VAlTargH, const double VAlTargEPR
  ,const double PowerPrd, const double KYPrd, const TEtalonSign ETalonSign , const double VAlHAntenna
  , bool *bLat  , double *pvalSigE ,double *pvalSigQ  );
};
#endif
