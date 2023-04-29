//---------------------------------------------------------------------------

#ifndef HelicH
#define HelicH
#include "Rotor.h"
// ����� ��������� ��������
// � ��������� ����� ���� 2 �����
// � ������� ����� ���� � ������� 0 ��������� ������� ����, � � ������� 1 ������
// � ����� ��-8 ���� � ������� 0 �������� ������� ����, � � ������� 1 �������
class TRotor;
class THelic
{
public:
	//  ����� ���������
	TRotor marrRotor[2];
	// ������� ��������� ������
	double marrRotorOmega[2];
	// ����� ���������
	double mHelicMass;






 __fastcall  THelic() ;
// ����������� �����������
__fastcall  THelic (const THelic &R2) ;

 // �������� ������������
 THelic   operator=(THelic  R2) ;

  // ����� ������
  __fastcall THelic(TRotor *arrRotor, double *arrRotorOmega
   ,const double HelicMass);

double calcCt(const double TKel0,const double HeliH) ;

double calc_C_y_alfa(const double TKel0,const double HeliH) ;



};
#endif
