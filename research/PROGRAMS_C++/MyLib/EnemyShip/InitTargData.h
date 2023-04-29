//---------------------------------------------------------------------------

#ifndef InitTargDataH
#define InitTargDataH
//---------------------------------------------------------------------------
// �������� ������ �� ��������� ������� ����
class TInitTargData
{
public:
	//  ���� ������� ���� � ���
	double mBearing ;
	// ���� ����� ���� � ���
	double mTargCourse ;
	// ���� ����� ������� �������� ���� � ����������� � �����
	double mTargZenitAng ;
	//- ��������
	double mV;
	// ���������,
	double mR ;
	// ������
	double mH ;
	//
	double mT ;

	 __fastcall ~TInitTargData() ;
	// ����������� �� ���������
	TInitTargData () ;
	// ����������� �����������
	TInitTargData  (const TInitTargData  &R) ;
	// �������� ������������
	TInitTargData  operator=(TInitTargData   R2) ;

	// ����� �����������1
	TInitTargData (const double Bearing, const double TargCourse, const double TargZenitAng ,const double V
	 ,const double  R,const double H, const double T);




}  ;
#endif
