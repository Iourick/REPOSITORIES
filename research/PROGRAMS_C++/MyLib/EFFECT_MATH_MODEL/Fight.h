//---------------------------------------------------------------------------

#ifndef FightH
#define FightH
//---------------------------------------------------------------------------
#include "Target.h"
#include "Vessel.h"
#include "TraceFlt.h"
#include "EtalonSign.h"
#include "TransmitAnt.h"
#include "Environment.h"
#include <math.h>
#include "OutPutAeroShot.h"

enum enumTypeOfControlAlgorithm{OPTIMAL,STANDART};
//#define LEN_ARR_SCATTERS 10

class TVessel ;
class TTarget ;
class TTraceFlt ;
class TEtalonSign;
class TEnvironment;
class TTOutPutAeroShot;
class TFight
{
public:
// �������
	TVessel mVessel;
//  ����
	TTarget mTarget;
// ������ �������������
	TTraceFlt mTraceFlt;
// ��������� ������
	TEtalonSign mEtalonSign;
//  ������� ����� (�����, �����)
  TEnvironment mEnvironment;


// ������� �����
	double mT;

// �������������
   double mTExtrap ;
   double mTargDesBet;
   double mTargDesEps;
   double mTargDesR ;
   double mSigTargDesBet;
   double mSigTargDesEps;
   double mSigTargDesR ;
   double marrVSExtrap_KGSK[6];
   double marrSigExtrapPosit_KGSK[3];
   double mSigModulV_KGSK ;
	 ///

	 // ������� ������� �������� (������ ������� ��������, �������� �� ������ ������� ����)
	 double mAntCoeff;

	 // ������������� ������
	// double mMissSimulated;

	 // ������������� Nedolet
	// double mPereletSimulated;

	 // �����
	 // �-�� ����� � �������
	int mQuantPntReport ;
	 // �������� ����������������� �������
	int mLenMemoryAlloc ;
	// ����� ������
	double *mparrBuff    ;
	//  ���� � ����� � �������
	wchar_t *mpwcharrFoldReport ;




	~TFight() ;
	// ����������� �� ���������
	TFight () ;
	// ����������� �����������
	TFight  (const TFight  &R) ;
	// �������� ������������
	TFight  &operator=(const TFight   &R2) ;

	// ����� �����������
 //	TFight (const TVessel Vessel, const TTarget Target
 //	,const double TExtrap, wchar_t *pwcharrFoldReport);

 //  TFight (const TVessel Vessel, const TTarget Target
 //		,const double TExtrap, TEtalonSign ETalonSignal,wchar_t *pwcharrFoldReport);

	TFight (const TVessel Vessel, const TTarget Target
		,const double TExtrap, TEtalonSign ETalonSignal
		, TEnvironment Environment,wchar_t *pwcharrFoldReport);

	 TFight (const TVessel Vessel, const TTarget Target
		,const double TExtrap, TEtalonSign ETalonSignal
		, TEnvironment Environment, const double VAlAntCoeff, wchar_t *pwcharrFoldReport);

//TFight (const TVessel Vessel, const TTarget Target
   //		,const double TExtrap, TEtalonSign ETalonSignal
	//	, TEnvironment Environment,const double  VAlMissSimulated,const double  VAlNedoletSimulated
	//	,const double VAlAntCoeff, wchar_t *pwcharrFoldReport);

	void __fastcall SimulatePositionASphSK(double &valR,double &valV,double &valU) ;

	void __fastcall SimulatePositionKGSK(double *arrPosKGSK) ;

	static void __fastcall Recalc_ASK_INTO_ASphSK(double *arrPosASK, double &valR,double &valV,double &valU) ;

	void  __fastcall RecalcVect_KGSK_INTO_ASK_True (double *arrKGSK,double *arrASK,int lenarrKGSK ) ;

	void  __fastcall RecalcVect_PSK_AS_INTO_GSK (double *arrPSK_AS,double *arrGSK,int lenarrKGSK ) ;

	void  __fastcall RecalcVect_GSK_INTO_PSK_AS_True (double *arrGSK,double *arrPSK_AS,int lenarrKGSK ) ;

	static void  __fastcall CalcToleranceSpherical(double *arrSInp , double *arrKInp
	, double &sigB, double &sigE, double &sigR  );

	static double  __fastcall CalcDispLinTransf (double * arrGradF, double *arrKInp )  ;


	//void  __fastcall getTargDes_PSK_True(const double valTExtrap,double &valTargDesEps,double &valTargDesBet);
	static void  __fastcall CreateMatrL6 (const double h, double *arrL) ;

	void  __fastcall calcVect_f(const double h, const double valQ
	, const double valV, const double valH, double *arr_f)  ;

	void  __fastcall getTargDes_PSK_True(const double valTExtrap
	,double &valTargDesBet,double &valTargDesEps,double &valTargDesR, double *arrVSExtrap_PSK) ;

	void __fastcall TrackFiltration(TZamer InpASKZamer, const double valTExtrap ,const int TypeOfFilter
	,double &valTargDesBet,double &valTargDesEps ,double &valTargDesR
	, double & SigTargDesBet,double & SigTargDesEps,double & SigTargDesR
	, double *arrVSExtrap_GSK, double *arrSigExtrapPosit_GSK, double &SigModulV_GSK ) ;

	static  void  __fastcall DesintegrateMatrK(double *arrInp , double *arrOut );

	static  void  __fastcall IntegrateMatrK(double *arrInp , double *arrOut )   ;

	static double  __fastcall Norm3(double *parr) ;

	void  __fastcall RecalcVect_ASK_Seem_INTO_GSK (double *arrASK,double *arrGSK,int lenarrASK ) ;

	//void  __fastcall RealcCorMtrx_Bet_Eps_VRU_ASK_Seem_INTO_GSK (double *arrCorrMtrx_GSK ) ;

	void  __fastcall RecalcVect_ASK_Seem_INTO_GSK (const double valVZv
	,const double valRZv, const double valUZv, double *valX_KGSKZv
	,double *valY_KGSKZv,double *valZ_KGSKZv);



	void  __fastcall RecalcVect_ASK_Seem_INTO_PSK_CT_Seem (double *arrASK,double *arrPSK_Seem,int lenarrASK )  ;

	void  __fastcall RecalcVect_GSK_INTO_PSK_CT_True (double *arrGSK,double *arrPSK_AS,int lenarrKGSK ) ;

	void  __fastcall RecalcVect_ASK_Seem_INTO_KGSK_Seem (double *arrASK,double *arrKGSK,int lenarrASK ) ;

	void  __fastcall RecalcVect_PSK_CT_Seem_INTO_KGSK_Seem(double *arrPSK,double *arrKGSK,int lenarrPSK ) ;

	void  __fastcall RecalcVect_ASK_Seem_INTO_PSK_AS_Seem (double *arrASK,double *arrPSK_Seem,int lenarrASK ) ;

	void  __fastcall getTargDes_From_KGSK_PSK_AS_True(const double valDelTExtrap, double *arrVS_KGSK
	,double &valTargDesBet,double &valTargDesEps,double &valTargDesR, double *arrVSExtrap_PSK) ;

	void  __fastcall RecalcVect_KGSK_INTO_PSK_AS_Seem (double *arrKGSK,double *arrPSK,int lenarrKGSK )  ;

	void  __fastcall RecalcVect_PSK_AS_Seem_INTO_ASK_Seem (double *arrPSK,double *arrASK,int lenarrPSK ) ;

	void  __fastcall RecalcVect_KGSK_INTO_ASK_Seem (double *arrKGSK,double *arrASK,int lenarrKGSK ) ;

	void updateReportData(TZamer InpASKZamer) ;

	void WriteReport() ;

	bool recalcFight( const double valT,const double valTExtrap);

	static void recalcCoord_INTO_Spherical(double *arrInp, double &valR, double &valBet, double &valEps) ;

	void WriteReport(wchar_t *pwcharrPath)  ;

	bool calcFirstShotTime(const double VAlDistFireBegin,  double *pvalFireBeginTime);

	bool calcAppointmentPoint(double *pEps0, double *pBet0,double *arrVessVelocity_GSK
   , double *arrTargVS_KGSK0,double *arrPositionAY_KGSK
 , double * valKGSKEps, double * valKGSKBet, double * valTFlight, double *arrVectAppointmentPointGSK, double *valMiss);

 static void transform_EpsBetKGSK_to_EpsBetGSK(double *arrVessVelocity_GSK, const double VAlShellV0
	 ,const double  VAlEpsKGSK0,const double    VAlKGSKBet0
			 , double *valGSKEps0,double *valGSKBet0);



void shift(double VAlTime);

bool calcFirstShotTime_(const double VAlDistFireBegin,  double *pvalFireBeginTime,  double *pvalMostRemoteAppPointDist);

void calcDist_and_DerivDist_AppointmentPoint( const double VAlT, double *pval_Dist, double *pval_derivDist);

double calcDistAppointmentPoint( const double VAlT);


void calcProbability_For_Fixed_AppointmentPoint_AirTargs(const double VAlTCurrentShot, const double VAlTFlight
	 ,const double VAlKGSKEps, const double VAlKGSKBet,double *pvalProb,double  *pvalDispMiss,double *pvalDispNedolet
	 ,double *arrCorMtrxCartinSK, double *pvalDisp_GSK_Z, TURPolygon *pPlgProjection);

void calcAeroTargRezultProbability(double *arrProbab, double *arrDist, const int IQuantShots
	, double *pvalProb, double *pvalGladkProb);

void fillShellVozmDispMatr (const double VAlKGSKEps, const double VAlKGSKBet, double *arrMtrxShellDisp);

void fillShellVozmDispMatr (const bool bCOrrection, const double VAlKGSKEps
	 , const double VAlKGSKBet, double *arrMtrxShellDisp);

void calcCorMtrx_OshibokOtrabotki_EpsBet(const double VAlKGSKEps, const double VAlKGSKBet
	 ,const double VAlDispDEltaPsi, const double VAlDispDEltaTet, const double VAlDispDEltaQ
	 ,const double VAlPsi, const double VAlTet, const double VAlQ
	, double *arrK_DelBetDelEpsGSK);

void extrapolateTrueTargVS_And_ScatteringCorrMatrx_KGSK(const double VAlTExtrp
 			 , double *arrTargExtrpScatteringsCorMtrx_GSK,  double *arrTargExtrpVS_GSK) ;

double calcT_BeginSopr(const double VAlDistBeginSopr);

bool calcSuccessProbSeaTarg(const int QuantShells,const double VAlHAntenna
	   ,double *pvalSKZPromach, double *arrCoMtrx_1_and_3_Groups, double *arrCoMtrx_2_Group
		,double *pvalKGSKEps, double *pvalKGSKBet, double *pvalTFlight
		,double *arrVectMiss_GSK, double *pvalProb,  double *pvalProb0);



void calcCorMtrx_First_And_Third_Group(const bool bCOrrection ,const double VAlKGSKEps,  const double VAlKGSKBet, const double VAlTFlight
	, double* arrCorMtrxGSK_1_and_3_Groups, double *arrShellVS_GSK) ;

void calcCorMtrx_Second_Group(const double VAlObservTime, const double VAlExtrapTime,  double* arrCoMtrx_2_Group) ;

bool calcAppointmentPoint(double *pEps0, double *pBet0,double *arrVessVelocity_GSK
	, double *arrTargVS_KGSK0,double *arrPositionAY_KGSK
	, double * valKGSKEps, double * valKGSKBet, double * valTFlight, double *arrVectAppointmentPointGSK, double *valMiss
	, double *arrShellVeloAppointmPoint_GSK,  double *arrTargVeloAppointmPoint_GSK);



bool findAppointmentPoint_NewtonMeth(double *arrVessVelocity_GSK
	, double *arrTargVS_KGSK0,double *arrPositionAY_KGSK
	, double * valKGSKEps, double * valKGSKBet, double * valTFlight, double *arrVectAppointmentPointGSK, double *valMiss
	, double *arrShellVeloAppointmPoint_GSK,  double *arrTargVeloAppointmPoint_GSK);

bool calcSuccessProbCoast(const int QUantShells,const  bool bCOrrection
		,const int QAantIspit, const double VAlKillingRange, double *pvalSKZPromach
		, double *arrScatterCorMtrx_1_and_3_Groups, double *arrScatterCorMtrx_2_Group, double *arrShellVeloAppointmPoint_GSK, double *pvalProb
		,enumTypeOfControlAlgorithm EnumTypeOfControlAlgorithm, TURPointXY *ppntArrAimingPoints, int *piarrRepeatAimingPoints
		, int* piQuantAimingPoints, double *pvalProb_Monte_Carlo);

bool calcShotTime(const double VAlAppointmentPointDist,  double *pvalFireTime);


bool calcSuccessProbAero(double *pvalDistFireBegin, const double VAlDistFireFinish0
   ,const double VAlHAntenna, double *pvalDistBeginSopr, double *pvalSigE, double *pvalSigQ, double *pvalFireBeginTime
   , int *piQuantShots,double *arrProbab, double *arrSKZPromach,double * arrSKZNedolet, double *arrSKZ_GSK_Z
   , double *arrCorMtrxCartinSK, double *arrDist, TURPolygon *plgArrProjection
	, const double ILenArr, double *pvalProb, double *pvalGladkProb);

void fillShellVozmDispMatr_ShootingEarth (double *arrMtrxShellDisp);


//static void calc_EpsKGSK0_BetKGSK0_(double *arrVessVelocity_GSK, const double VAlShellV0
 //  ,const double  VAlEpsGSK0,const double    VAlGSKBet0
 //			 , double *valEps0,double *valBet0);

static void transform_EpsBetGSK_to_EpsBetKGSK(double *arrVessVelocity_GSK, const double VAlShellV0
   ,const double  VAlEpsGSK0,const double    VAlGSKBet0
			 , double *valEps0,double *valBet0);

static void transform_EpsBetGSK_to_EpsBetKGSK(double *arrVessVelocity_GSK, const double VAlShellV0
   ,const double  VAlEpsGSK0,const double    VAlGSKBet0
			 , double *valEps0,double *valBet0,double *valk);

bool calcSuccessProbAero(double *pvalDistFireBegin, const double VAlDistFireFinish0
   ,const double VAlHAntenna, double *pvalDistBeginSopr, double *pvalSigE, double *pvalSigQ, double *pvalFireBeginTime
   , int *piQuantShots,double *arrProbab, double *arrSKZPromach,double * arrSKZNedolet, double *arrSKZ_GSK_Z
   , double *arrCorMtrxCartinSK, double *arrDist, TURPolygon *plgArrProjection
	, const double ILenArr, double *pvalProb, double *pvalGladkProb, TOutPutAeroShot *parrOutPutAeroShot);

void calcProbability_For_Fixed_AppointmentPoint_AirTargs(const double VAlTCurrentShot
 ,const double VAlTFlight,const double VAlKGSKEps, const double VAlKGSKBet,double *pvalProb
 ,double  *pvalDispMiss,double *pvalDispNedolet,double *arrCorMtrxCartinSK
 ,double *pvalDisp_GSK_Z, TURPolygon *pPlgProjection, double *arrKTarg, double *arrKShell
 , double *arrMiss);

 void calcTargPosKGSK(const double valTExtr, double *arrTrueTargPosKGSK) ;


}  ;



void fncInit_Eps0_Bet0(double *arrVSTarg_KGSK0, double val_Shell_V0, double& Eps0, double& Bet0);

void transformVectNaprCos_To_EpsBet(double *arr_g, double* pvalEps0, double* pvalBet0) ;

SIGN_D(double x)
{
  if (fabs(x)< 0.000000000001)
  {
	return 0.;
  }
	return (x > 0.)? 1.:-1.;
}

double MAX__(double a , double b)
 {
 return (a > b)? a:b;
 }

 double MIN__(double a , double b)
 {
 return (a < b)? a:b;
 }

#endif
