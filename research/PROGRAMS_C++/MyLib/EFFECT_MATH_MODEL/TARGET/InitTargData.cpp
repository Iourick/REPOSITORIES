//---------------------------------------------------------------------------


#pragma hdrstop

#include "InitTargData.h"
#include "Traject.h"
#include <math.h>
#include "MatrixProccess.h"
extern  double PI ;

TInitTargData::TInitTargData()
{
	//-  ���� ������� ���� � ���
	mBearing = PI/2.;
	// ���� ����� ���� � ���
	mTargCourse = 1.5 * PI;
	// ���� ����� ������� �������� ���� � ����������� � �����
	mTargZenitAng = PI/2. ;
	//- ��������
	mV  = 1000. ;
	// ���������,
	mR =20000. ;
	// ������
	mH = 1000. ;
	// �����
	mT = 0. ;

}

//---------------------------------------------------------------------------
  __fastcall TInitTargData::~TInitTargData()
{

}

// ����������� �����������
 TInitTargData ::TInitTargData (const TInitTargData &R)
 {
	mBearing  =  R.mBearing ;
	mTargCourse = R.mTargCourse;
	mTargZenitAng = R.mTargZenitAng ;
	mV   = R.mV ;
	mR = R.mR ;
	mH = R.mH ;
	mT = R.mT ;

 }
 // �������� ������������
 TInitTargData &TInitTargData::operator=(const TInitTargData  &R)
 {
	mBearing  =  R.mBearing ;
	mTargCourse = R.mTargCourse;
	mTargZenitAng = R.mTargZenitAng ;
	mV   = R.mV ;
	mR = R.mR ;
	mH = R.mH ;
	mT = R.mT ;



	return *this ;
 }

  // ����� �����������1
 TInitTargData::TInitTargData (const double Bearing, const double TargCourse, const double TargZenitAng ,const double V
	 ,const double  R,const double H, const double T)
 {
   mBearing  = Bearing ;
	mTargCourse = TargCourse ;
	mTargZenitAng = TargZenitAng;
	mV   = V ;
	mR = R ;
	mH = H ;
	mT = T ;

 }



//---------------------------------------------------------------------------
 // ����� �����������2
 //Q0  ; // ����������� ����  ��������
 //	 VVess  ;// �������� ������� ������
 TInitTargData::TInitTargData (const double Bearing, const double TargZenitAng ,const double V
	 ,const double  R,const double H, const double T, const double Q0, const double VVess )
 {
   mBearing  = Bearing ;
  //	mTargCourse = TargCourse ;
	mTargZenitAng = TargZenitAng;
	mV   = V ;
	mR = R ;
	mH = H ;
	mT = T ;
	// ���������� ����� ����,
	// ����� �������������� ���������� ���� ������������ � ����������� �������
	//1. �������������� �������� �������� ����
	double vTarg = V *sin (TargZenitAng);

	// 2. ������ �������� ������� � ����� ���������
	double arrVVess[2] = {0.};
	arrVVess[0] = VVess * sin(Q0);
	arrVVess[1] = VVess * cos(Q0);

	// 3.  ��������� ������ ��������� ���� � ��������� OXY ���
	double S0 = sqrt(R * R - H * H);
	double arrS0[2] = {0.};
	arrS0[0] = S0 * sin (Bearing);
	arrS0[1] = S0 * cos (Bearing);

	// 4. ����� ������� ����
	double scal = ScalProduct(arrS0 , arrVVess, 2) ;
	double temp = vTarg * vTarg -  VVess * VVess;
	double tfly =  (-scal + sqrt(scal * scal + S0 * S0 *temp))/temp;

	// ������ ������������ ��������� ����
	double arrCos[2] = {0.};
	arrCos[0] = -(arrS0[0] -  tfly * arrVVess[0])/tfly / vTarg;
	arrCos[1] = -(arrS0[1] -  tfly * arrVVess[1])/tfly / vTarg;

	mTargCourse = atan2(arrCos[0], arrCos[1]);

 }



#pragma package(smart_init)
