//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "Blade.h"
#include "Helic.h"
#include "Rotor.h"


class TBlade;
class THelic;
class TRotor;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *Button1;
	TLabeledEdit *LabeledEdit1;
	TLabeledEdit *LabeledEdit2;
	TLabeledEdit *LabeledEdit5;
	TLabeledEdit *LabeledEdit6;
	TPanel *Panel2;
	TLabeledEdit *LabeledEdit8;
	TLabeledEdit *LabeledEdit9;
	TLabeledEdit *LabeledEdit10;
	TButton *Button2;
	TLabeledEdit *LabeledEdit11;
	TLabeledEdit *LabeledEdit12;
	TLabeledEdit *LabeledEdit13;
	TLabeledEdit *LabeledEdit14;
	TLabeledEdit *LabeledEdit15;
	TLabeledEdit *LabeledEdit3;
	TLabeledEdit *LabeledEdit4;
	TLabeledEdit *LabeledEdit7;
	TLabeledEdit *LabeledEdit16;
	TLabeledEdit *LabeledEdit17;
	TLabeledEdit *LabeledEdit18;
	TLabeledEdit *LabeledEdit19;
	TLabeledEdit *LabeledEdit20;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	// ����������� �� ����������� �����
	double mTKel0 ;
	// ������
	double mHeliH ;
	// ������� ���������� �����
	double mBladeOmega;
	// ������ �����
	double mBladeR ;
	// ����� ���������
	double mHelicMass;

	// ���������� ��  ������ ��
	double mRadHorizHsarnir;
	// ������ ������������� �������  ������� ����� � ������ ��������
	double mPofile_d0;
	// ������ ������������� �������  ������� ������ �� ������ ��������
	double mPofile_d1;
		// ����� �������
	double mBladeM;

		// ����� �������
	double mBlade_b;
	// �-�� ��������
	int mQuantBlades;

	// �������
	TBlade mBlade;

	// ��������
	THelic mHelic;


	void __fastcall fncInputData();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
