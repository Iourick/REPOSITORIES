//---------------------------------------------------------------------------

#ifndef StabSyst2H
#define StabSyst2H
class TComp ;
class TStabSyst2
{
public:
	double mh ;        // ��� �� �������
	double msigm_w ;   //  ��� w
	double msigm_mmo ; //  ��� ���
	double msigm_bmo ; //  ��� ���
	double marrA [4] ;    // ������� �������� �� ���� ����;
	double marrB [2];    // � ������ ������ � ������ �������
	double marrC [2] ;   // �������  ����������
	double msigm_fl; // �������������� ������� ufl � ������ ����� � ��������� x1 = x1 + h * x2 + h * h /2 * w + ufl



	__fastcall ~TStabSyst2() ;

	TStabSyst2 () ;

	// ����������� �����������
	TStabSyst2  (const TStabSyst2  &R) ;
	// �������� ������������
	TStabSyst2  &operator=(const TStabSyst2   &R2) ;
	// ����� ������
	TStabSyst2(  const double h,const double sigm_w, const double sigm_mmo
	,const double sigm_bmo ) ;
	// ����� ������
	// ����� ������
	TStabSyst2(  const double h,const double sigm_w, const double sigm_mmo
	,const double sigm_bmo, const double sigm_fl) ;

	// ������� �����
	void StabSolutionKalm( double *arrK,double * arrP,TComp &rt1,TComp &rt2,
	double &valT1, double &valT2);

	double  SolvCharactEqKlm(const double c);

	static int  CalcProperVectors(double * arrKInp,double *arrV , double *arrLamb);
	void FltKlm( double *arrK,double * arrP);

	void OneStepFltrKlm( double *arrKInp,double *arrKOut,double * arrP);

	bool CalcAccuracyKlm_Real(const double sigm_w,const double sigm_mmo,const double sigm_bmo
	,double *arrK, double *arrPStab
	,const double psi1,const double psi2,double *arrKTol , double **pparrK,int * plenparrarrK) ;

	bool CalcFuncMaximumKlm_Real( const double sigm_w,const double sigm_mmo
	,const double sigm_bmo ,double *arrK, double *arrPStab
	, double &psi1, double &psi2,double *arrKTol , double **pparrK,int * plenparrarrK);

	bool OneStepRecalcTol( const double psi1,const double psi2,const double sigm_w
	,const double  sigm_mmo,const double sigm_bmo,  double *arrP
	,double *arrKInp,double *arrKOut,double *arrS,double *arrQ);

	static bool  CalcCoeff(double fi,double sigm,double *arrK,double *arrS);

	bool FindRoots(double *arrP
	, double *arrS,double *arrQ, TComp &rt1,TComp &rt2);

	void StabSolutionKalm_Real( double *arrK,double * arrP,TComp &rt1,TComp &rt2,
	double &valT1, double &valT2,double **pparrOut, int *plenparrOut, double **pparrWeight0
	, double **pparrWeight1,int * plenparrWeight);

	double  SolvCharactEqKlm_Real(const double mu) ;

	void FltKlm_Real(  double *arrK,double * arrP);

	void OneStepFltrKlm_Real(double *arrKInp,double *arrKOut,double * arrP);

	void CalcWeightArray(double * arrP, double **pparrWeight0
	,double **pparrWeight1, int *plenparrWeight) ;

	static double maxDoubleArr(double *parr, const int lenarr, int &irez);

	static void CreateShpFile(wchar_t*pstrNameFile, double *parrInf
	,const int lenarr, const int quantRows,const double h,double &scalex,double &scaley);

	static void CreateShpAxes(wchar_t *wchFileName,const double xmin,const double xmax
	,const double ymin,const double ymax) ;

	void fncStabSolDynamicFltKlm_flAdd(double  *arrKStab,double *arrPStab);

	void 	OneStepFltKlm_flAdd(double *arrK,double *arrP);

	void  fncStabSolDynamicFltKlm_flAdd(double  *arrKStab,double *arrPStab
		,double **pparrOut, int *plenparrOut) ;


	//******************************************************************************************************************//
	//******************************************************************************************************************//
	//******************************************************************************************************************//
	//************ ������� ����������� ����������        ******************************************************************************************************//
	//******************************************************************************************************************//
	//******************************************************************************************************************//
	//******************************************************************************************************************//

	public:
	void  CalcCorrMatrGolubev(double  *arrKTemp,double *arrPTemp
	,double **pparrOut, int *plenparrOut, double **pparrWeight0
	,double **pparrWeight1,int * plenparrWeight);
	void CalcCorrMatrGolubev_flAdd(double  *arrKStab,double *arrPStab) ;


	void FindMaxMin ( double *arrP
	,double &fiRez1,double &fiRez2,double *arrS,double *arrQ);

	bool CalcFuncMinimum(double fi1,double fi2,double *arrK, double *arrP,double *arrS,double *arrQ) ;

	bool FindMinMax(double *arrPStab, double &fi1, double & fi2
	, double &psi1, double &psi2,double *arrKMinMax );

	bool CalcFuncMaximum(double *arrK, double *arrPStab,const double fi1,const double fi2
	, double &psi1, double &psi2,double *arrKTol ) ;
	bool F_MaxForKlmFilt( const double sigm_u
	,const double sigm_bmo ,double *arrK, double *arrPStab
	, double *valPsi,double *valLamb,double * valMu,
	double *arrKTol , double **pparrK,int * plenparrarrK) ;

	bool CalcToleranceKalmFilt( const double sigm_u, const double sigm_bmo  ,double *arrK, double *arrPStab
	,const double LambCur,const double MuCur, const double PsiCur
	,double*  arrKTol , double **pparrK,int * plenparrarrK);
	bool CorrMtrxExtendedRecalc(const double sigm_u,const double sigm_bmo , double *arrP
	, const double LambCur, const double MuCur,  const double PsiCur ,double *arrKExtend ,double * arrS);
	bool Klm_Real_WhiteNoiseInput(const double sigm_wksi,const double sigm_bmo
	,double *arrK ,double *arrKRez );

  

	bool CaseOfDegeneracy(double *arrKRez ,int *iarrParamsRez );
	static  double pf(double x,int *iarrPar,double *arrPar);
	static double func(double x,int *iarrPar,double *arrPar) ;
	bool TangMethod(double &x,double (*f)( double x, int *iarrPar,double *arrPar)
	,double (*pf)( double x,int *iarrPar,double *arrPar),int *iarrPar
	,double *arrPar,const double eps) ;
	 void  fncStabSolDynamicGolubev_flAdd(double  *arrKStab,double *arrPStab
		,double **pparrOut, int *plenparrOut)  ;

     void ExtrapolStepFltrKlm_Real(const double hExtr,double *arrKInp,double *arrKextr);
     void 	OneStepGolubev_flAdd(double *arrK,double *arrP);
      void 	ExtrapolStepGolubev_flAdd(const double hExtr,double *arrK,double *arrKExtr);


	void 	OneStepGolubev(double *arrK,double *arrP);
	void 	OneStepGolubevExtrapolation(double *arrK, double valExtrT, double *arrKExtr)  ;


	 private:
	bool OneStepAlfaBettaFlt(double fi1,double fi2,double *arrKInp,double *arrKOut, double *arrP
	,double *arrS,double *arrQ) ;



	bool CalcAccuracy(double *arrK, double *arrPStab,const double fi1,const double fi2
	,const double psi1,const double psi2,double *arrKTol ) ;

	int FSIGN(const double x);
	void RecalcExtendedMtrx(const double valS1,const double valS2,const double sigm_u,const double sigm_bmo , double *arrP
	, const double LambCur, const double MuCur,  const double FiCur ,double *arrKExtend ,double *arrKExtendOut);

	bool IsRootGood(const double sigm_w , const double LambCur, const double MuCur
	,const double FiCur ,double *arrKExtend,const double s0, const double s1 );
	void CalcMatrK(double x,int *iarrPar,double *arrKTemp);



};
#endif
