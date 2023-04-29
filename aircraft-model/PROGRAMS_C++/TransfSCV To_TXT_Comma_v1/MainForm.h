//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include "UrPointXY.h"
#include <ExtCtrls.hpp>


//---------------------------------------------------------------------------
const int NN = 10000;
class TURPointXY;

class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button3;
	TEdit *Edit1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TButton *Button2;
	TLabel *Label3;
	TLabel *Label4;
	TButton *Button8;
	TButton *Button7;
	TOpenDialog *OpenDialog2;
	TOpenDialog *OpenDialog3;
	TOpenDialog *OpenDialog4;
	TLabeledEdit *LabeledEdit19;
	TComboBox *ComboBox4;
	TLabel *Label14;

	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);

	void __fastcall Button8Click(TObject *Sender);


	void __fastcall Button7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
wchar_t *pchInpFileNameDEM;
//wchar_t *pchInpFileNameSetnull;
//wchar_t *pchInpFileNameChangePoints;
//wchar_t *pchInpFileNameDigPoints;
wchar_t *pchInpFileNameDigPoints_Rez;

//double marr [NN];
int mNum�ols;
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
