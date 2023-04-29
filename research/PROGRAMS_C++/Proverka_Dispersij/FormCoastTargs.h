//---------------------------------------------------------------------------

#ifndef FormCoastTargsH
#define FormCoastTargsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>


#include "SingleSign.h"
#include "InitTargData.h"
#include "EtalonSign.h"
#include "Target.h"
#include "TransmitAnt.h"
#include "AM_2D.h"
#include "Far_2D.h"
#include "URPointZ.h"

#include "Environment.h"
#include "MyShellTraj.h"
#include "ControlSyst.h"
#include "ArtCannon.h"
#include "ArtComplex.h"
#include "Vessel.h"
#include "Fight.h"
#include "ArtCannon.h"

#include "YrRastr.h"
#include <Grids.hpp>






// enum enumTargetType;
 //enum enumShellType;
// enum enumCannonType;
//---------------------------------------------------------------------------
class TAM_2D;
class TFar_2D;
class TURPointZ;
class  TSingleSign;
class TInitTargData;
class TEtalonSign;
class TTransmitAnt;
class TWind;
class TEnvironment;
class TControlSyst;
class TArtCannon;
class TArtComplex;
class TVessel;
class TFight;
//----------------

//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel2;
	TLabeledEdit *LabeledEdit1;
	TLabeledEdit *LabeledEdit2;
	TRadioGroup *RadioGroup1;
	TButton *Button2;
	TLabeledEdit *LabeledEdit3;
	TLabeledEdit *LabeledEdit4;
	TLabeledEdit *LabeledEdit5;
	TPanel *Panel7;
	TLabel *Label8;
	TLabeledEdit *LabeledEdit29;
	TLabeledEdit *LabeledEdit23;
	TOpenDialog *OpenDialog1;
	TPanel *Panel3;
	TLabel *Label9;
	TLabel *Label7;
	TLabel *Label4;
	TLabel *Label5;
	TComboBox *ComboBox3;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TPanel *Panel10;
	TLabel *Label1;
	TLabeledEdit *LabeledEdit49;
	TLabeledEdit *LabeledEdit51;
	TLabeledEdit *LabeledEdit52;
	TLabeledEdit *LabeledEdit53;
	TLabeledEdit *LabeledEdit50;
	TLabeledEdit *LabeledEdit6;
	TButton *Button1;
	TPanel *Panel4;
	TLabel *Label3;
	TButton *Button4;
	TEdit *Edit2;
	TLabel *Label2;
	TComboBox *ComboBox4;
	TComboBox *ComboBox5;
	TLabel *Label6;
	TLabeledEdit *LabeledEdit7;
	TRadioGroup *RadioGroup2;
	TPanel *Panel1;
	TLabel *Label10;
	TStringGrid *StringGrid2;
	TEdit *Edit3;
	TEdit *Edit1;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit7;
	TEdit *Edit8;
	TLabeledEdit *LabeledEdit9;
	TOpenDialog *OpenDialog2;
	TRadioGroup *RadioGroup3;
	TOpenDialog *OpenDialog3;
	TPanel *Panel6;
	TLabel *Label14;
	TEdit *Edit10;
	TEdit *Edit11;
	TEdit *Edit12;
	TEdit *Edit13;
	TPanel *Panel8;
	TLabel *Label15;
	TButton *Button8;
	TEdit *Edit15;
	TButton *Button9;
	TLabeledEdit *LabeledEdit10;
	TLabel *Label16;
	TPanel *Panel9;
	TButton *Button5;
	TEdit *Edit6;
	TLabel *Label11;
	TPanel *Panel5;
	TLabel *Label12;
	TLabel *Label13;
	TButton *Button6;
	TEdit *Edit9;
	TButton *Button7;
	TLabeledEdit *LabeledEdit8;
	TLabeledEdit *LabeledEdit11;
	TButton *Button3;
	TEdit *Edit14;
	TLabel *Label17;
	TOpenDialog *OpenDialog4;
	TOpenDialog *OpenDialog5;
	TLabeledEdit *LabeledEdit12;
	TButton *Button10;
	TButton *Button11;
	TLabeledEdit *LabeledEdit13;
	TLabeledEdit *LabeledEdit14;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall RadioGroup1Exit(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Panel3Click(TObject *Sender);
	void __fastcall ComboBox3Change(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall ComboBox4Change(TObject *Sender);
	void __fastcall ComboBox5Change(TObject *Sender);
	void __fastcall LabeledEdit23Change(TObject *Sender);
	void __fastcall LabeledEdit29Change(TObject *Sender);
	void __fastcall LabeledEdit1Change(TObject *Sender);
	void __fastcall LabeledEdit2Change(TObject *Sender);
	void __fastcall LabeledEdit49Change(TObject *Sender);
	void __fastcall LabeledEdit51Change(TObject *Sender);
	void __fastcall LabeledEdit52Change(TObject *Sender);
	void __fastcall LabeledEdit53Change(TObject *Sender);
	void __fastcall LabeledEdit50Change(TObject *Sender);
	void __fastcall RadioGroup2Click(TObject *Sender);
	void __fastcall RadioGroup3Click(TObject *Sender);
	void __fastcall StringGrid2Exit(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);

	void __fastcall FormShow(TObject *Sender);

	void __fastcall drawManPowerPoligon();

	// �������� ����������
	enumTypeOfControlAlgorithm menumTypeOfControlAlgorithm;
	// ������� ������������� ����
	bool bCorrection;
	// ������� ������������� ����
	int miIdexRadioGroup1;
	//
 //	���������� ��������
 int mQuantIspit;


	// ���� � ����� � ���������
	wchar_t *mpwchOutFile0;
	// ���� � ����� � ���������  ����������� ������� ��������
	wchar_t mwchOutFold[400]; //
	// ���� � ����� � ��������� ����
	wchar_t *mpwchSHP_TargFile; //
	//
	TURPolygon mPlgTarg;
	
	String mStringFileDataPoints;

		// ���� � ����� � ������������ ��� ��������  ��������� ����
	wchar_t *mpwchOutFileForPointGroupTarg; //
	// ������

	//��� ����������
	enumDetonatorType mDetonatorType;
	enumShellType mEnumShellType;
	enumCannonType menumCannonType;
	//
	//�-�� ��������
	int mQuantShells;

	///

	// ����

	//��� ����
	enumTargetType  mEnumTargType;
	//���� �������, ����
	double mBearing0;
	//������, �
	double mElev0;
	//��������, �/�
	double mVelocity0;
	//���������, �
	double mDist0;
	//  ���
	TYrRastr mRastrUZP;

	//��� ���� ��������, �/�/�
 	double mWSkz;
	//
	double mTargZenitAng0;
	//���� �����
	double mTargCourse0;
	// ��� ����
	double mTargEPR ;

	// �������� � ������ ��
	double mSigAUDelayT;

	// �����������
	// ���� ��������
	double mRateOfFire;

	// 	��������� ��������� ������� �����
	double  mSigDrivAY_U ;

	// 	��������� ��������� �������� ��������  �����
	double  mSigDrivAY_dU_po_dt ;

	// ��� ������� ������ ���� (����� �����)
	double	mSigSins;

	// ��� ������� ������ ������ �������� ����� (����� �����)
	double	mSig_d_po_dt_Sins;

	// ������� ���
	double mVesselWidth ; // ������(�)
	double mVesselLength ;
	double marrFarParallacs[3] ;

	double mMaxQ ; /// ������������ ���� ���������� �� ������������ �����(��������� ���� ��������)
	double mT_Q; // ������ ��������
	double mMaxPsi ;// ������������ ���� ������� �����(���������)
	double mT_Psi ; // ������ ������� �����
	double mMaxTet ; //������������ ���� ��������� �����(���������)
	double mT_Tet; // ������ �������� �����
	double mMaxVert  ;

	// ���������� ��������  ������� ������
	double mQ0  ; // ����������� ����
	double mVVess  ;// �������� ������� ������ 20 �����
	double marrDelt[4] ;//  ��������� ����

	//������������ ��������� ��������� ������ ������� � ��� �� 100 �
	double mMaxAmp_AftFlexure;
	// ������ ��������� ��������� ������
	double mT_AftFlexure;
	//������������ ��������� ��������� ������ ������� � ��� �� 100 �
	double mMaxAmp_BoardFlexure;
	// ������ ��������� ��������� ������
	double mT_BoardFlexure;

	// 3.1 �������� ����
	TSins mSins ;
	double mMaxSig_Q ;
	double mMaxSig_Psi  ;
	double mMaxSig_Tet  ;
	double mMaxSig_dQdt ;
	double mMaxSig_dPsidt ;
	double mMaxSig_dTetdt ;
	double mK1         ;
	double mSigV      ;
	double mSigH     ;
	double mMaxSig_H ;
	double mMaxSig_VH ;
	// ��� ��������� ����������


	// ������
	double mDriverSigBet ;// �������� ��������� ���� Bet �������
	double mDriverSigEps ;// �������� ��������� ���� Eps  ������� (���� �����)
	double mDriverDynamicSigBet ;// �������� ��������� ���� �����  �������
	double mDriverDynamicSigEps ;// ��������  ������� ��������� ���� �����

	//
	 double marrArtParral[3]; // ������ ���������� ��
	//���� ����������
	// �������� ����� �����������
	double mMeasT;

	// �������� ����
	double mSinsDelayT;
  // ���� ������� ���
  double mRzvT;

	TControlSyst mControlSyst;
	TFar_2D mFar_2D;
	TArtCannon mArtCannon ;
	TArtComplex mArtComplex;  // ��
	TTransmitAnt mTransmitAnt;
	TEtalonSign mEtalonSign;
	TVessel mVessel;
	TFight mFight;
	TEnvironment mEnvironment;
	TInitTargData mInitTargData;
	TShellBody mShellBody;

	// ����������� ������ ���������
	double mKillingRange;

	// ��� ��������� �������� ����
	double mSig13GroupD; // ��� ������ ������ �� ���������
	double mSig13GroupBet; // ��� ������ ������ �� ����
	double mSig2GroupD; // ��� ����� ������ �� ���������
	double mSig2GroupBet; // ��� ����� ������ �� ����
	double mSigLocation;// ��� ������ ����������� ��������� �����
	double mAimCellSize; //  ��� ������������� SHP ������� ������������ ���  ������������� ��� � ������ �����
	double mTargCellSize; //  ��� ������������� SHP ������� ���� ��� ������������� ��� � ������ �����

		// ���� URPointZ � ������� ������������ ��� ������ � ������ ������
	wchar_t *mpwch_PointZ_File_AimingPoints; //

	void __fastcall fncInputData();
	void __fastcall create5P10();
	void __fastcall createInputGridForPointTargs();
	void __fastcall InputGridData();
	void __fastcall fillInputGrid();

};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------

//TYrRastr(int nc,int nr,double xll,double yll,double cs,double nd,const bool irastr)


#endif
