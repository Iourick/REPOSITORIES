//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>

#include "MainForm.h"
#include "YrString.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	fncInputData();
	double valCt = mHelic.calcCt(mTKel0,  mHeliH)  ;
	LabeledEdit6->Text =  valCt;

	double val__C_y_alfa = mHelic.calc_C_y_alfa(mTKel0,  mHeliH) ;
	LabeledEdit18->Text =   val__C_y_alfa;

	double val_Gamma_L =  mHelic.calc_Gamma_L(mTKel0,  mHeliH) ;
	LabeledEdit20->Text = val_Gamma_L;
	  int iii =0;
}
//---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

void __fastcall TForm1::fncInputData()
{
	// ����������� �� ����������� �����
	  mTKel0 = StrTo_Dbl_(LabeledEdit1->Text) + 273.15;
	// ������
	  mHeliH  = StrTo_Dbl_(LabeledEdit2->Text);
	// ������� ���������� �����
	  mBladeOmega = StrTo_Dbl_(LabeledEdit3->Text) * 2. * M_PI;
	// ������ �����
	  mBladeR  = StrTo_Dbl_(LabeledEdit4->Text);
	// ����� ���������
	  mHelicMass = StrTo_Dbl_(LabeledEdit5->Text);

	  // ������ ������ ��
	mRadHorizHsarnir = StrTo_Dbl_(LabeledEdit8->Text);
	// ������ ������������� �������  ������� ����� � ������ ��������
	mPofile_d0 = StrTo_Dbl_(LabeledEdit9->Text);
	// ������ ������������� �������  ������� ������ �� ������ ��������
	mPofile_d1 = StrTo_Dbl_(LabeledEdit10->Text);
	mBladeM  = StrTo_Dbl_(LabeledEdit12->Text);

	mBlade_b = StrTo_Dbl_(LabeledEdit13->Text);

	mQuantBlades = StrToInt(LabeledEdit19->Text);

	// �������
	 mBlade = TBlade(mBladeR, mRadHorizHsarnir, mPofile_d0, mPofile_d1, mBladeM, mBlade_b);

	// ��������
	TRotor arrRotor[2];
	TPlane BasePLane; // ���� �� ��������� ���� ����� ������� !!!!!!!
	arrRotor[0] =  TRotor(mBlade, 3,  BasePLane) ;
	arrRotor[1] =  TRotor(mBlade, 3,  BasePLane) ;

	double arrRotorOmega[2] = {0.};
	arrRotorOmega [0] =  mBladeOmega;
	arrRotorOmega [1] =  -mBladeOmega;
    mHelic = THelic(arrRotor, arrRotorOmega, mHelicMass);



}

//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
  fncInputData();
  double val_rQ =  mBlade.calc_rQ() ;
  LabeledEdit11->Text =  val_rQ;

  double val_X_CentreMass = mBlade.calc_X_BladeCentreMass() ;
   LabeledEdit7->Text =  val_X_CentreMass;

   double val_Sg = mBlade.calc_X_StatMoment_Sg();
   LabeledEdit14->Text =  val_Sg ;

   double val_I0 = mBlade.calcInertiaMoment0();
   LabeledEdit15->Text =  val_I0 ;

	double val_I = mBlade.calcInertiaMoment();
   LabeledEdit16->Text =  val_I ;

   double val_HorSharnir_I = mBlade.calcInertiaMomentHorSharnir();
   LabeledEdit17->Text =  val_HorSharnir_I ;

   int iii=0;
	}
//---------------------------------------------------------------------------

