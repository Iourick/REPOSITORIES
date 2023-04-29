//---------------------------------------------------------------------------


#pragma hdrstop

#include "TraceFlt.h"
#include <string.h>
#include <stdlib.h>

//---------------------------------------------------------------------------
TTraceFlt::TTraceFlt()
{
	 mTf = 0;
//  ����� ������� ��������� �� ������ mTf
	memset(marrVS_KGSK, 0, 6 * sizeof(double)) ;

 //	����� ������� ��������� � ��� �� ������ mTf

	memset(marrVS_ASK, 0, 6 * sizeof(double)) ;
//  3.������������ �������������� ������� ������ ���������� � ���
	memset(marrK_KGSK, 0, 36 * sizeof(double)) ;
	for (int i = 0; i < 3; i++)
	{
	marrK_KGSK[ 6 * i + i ] = 1000000. ;
	marrK_KGSK[ 6 * i + i + 3] = 100000. ;
	marrK_KGSK[ 6 * (i + 3) + i] = 100000. ;
	marrK_KGSK[ 6 * (i + 3) + i + 3] = 100000. ;

	}
//  4.������� �������� �� ��� � ��� �� ������ mTf

	memset(marrK_KGSK, 0, 9 * sizeof(double)) ;

 // 5.����������� ������� �������� �� ��� � ��� �� ������ mTf

	memset(marrFExt_ASK_V_PSK, 0, 36 * sizeof(double)) ;

//  6.������� �������� �� ��� � ���� �� ������ mTf

	memset(marrF_PSK_V_KGSK, 0, 9 * sizeof(double)) ;

 // 7. ����������� ������� �������� ��  ��� � ���� ��� ������ mTf

	memset(marrFExt_PSK_V_KGSK, 0, 36 * sizeof(double)) ;

	// 8.
	mbInit = false ;

}




// ����������� �����������
 TTraceFlt ::TTraceFlt (const TTraceFlt &R)
 {
	mTf = R.mTf;
	memcpy(marrVS_KGSK, R.marrVS_KGSK, 6 * sizeof(double)) ;
	memcpy(marrVS_ASK, R.marrVS_ASK, 6 * sizeof(double)) ;

	memcpy(marrK_KGSK, R.marrK_KGSK, 36 * sizeof(double)) ;
	memcpy(marrK_ASK, R.marrK_ASK, 36 * sizeof(double)) ;

	memcpy(marrF_ASK_V_PSK, R.marrF_ASK_V_PSK, 9 * sizeof(double)) ;
	memcpy(marrFExt_ASK_V_PSK, R.marrFExt_ASK_V_PSK, 36 * sizeof(double)) ;
	memcpy(marrF_PSK_V_KGSK, R.marrF_PSK_V_KGSK, 9 * sizeof(double)) ;
	memcpy(marrFExt_PSK_V_KGSK, R.marrFExt_PSK_V_KGSK, 36 * sizeof(double)) ;
	memcpy(marrMu, R.marrMu, 5 * sizeof(double)) ;
	memcpy(marrF_ASK_V_KGSK, R.marrF_ASK_V_KGSK, 9 * sizeof(double)) ;
	memcpy(marrFExt_ASK_V_KGSK, R.marrFExt_ASK_V_KGSK, 36 * sizeof(double)) ;

	mbInit = R.mbInit ;
 }
 // �������� ������������
 TTraceFlt &TTraceFlt::operator=(const TTraceFlt  &R)
 {
	mTf = R.mTf;
	memcpy(marrVS_KGSK, R.marrVS_KGSK, 6 * sizeof(double)) ;
	memcpy(marrVS_ASK, R.marrVS_ASK, 6 * sizeof(double)) ;

	memcpy(marrK_KGSK, R.marrK_KGSK, 36 * sizeof(double)) ;
	memcpy(marrK_ASK, R.marrK_ASK, 36 * sizeof(double)) ;

	memcpy(marrF_ASK_V_PSK, R.marrF_ASK_V_PSK, 9 * sizeof(double)) ;
	memcpy(marrFExt_ASK_V_PSK, R.marrFExt_ASK_V_PSK, 36 * sizeof(double)) ;
	memcpy(marrF_PSK_V_KGSK, R.marrF_PSK_V_KGSK, 9 * sizeof(double)) ;
	memcpy(marrFExt_PSK_V_KGSK, R.marrFExt_PSK_V_KGSK, 36 * sizeof(double)) ;
	memcpy(marrMu, R.marrMu, 5 * sizeof(double)) ;
	memcpy(marrF_ASK_V_KGSK, R.marrF_ASK_V_KGSK, 9 * sizeof(double)) ;
	memcpy(marrFExt_ASK_V_KGSK, R.marrFExt_ASK_V_KGSK, 36 * sizeof(double)) ;

	mbInit = R.mbInit ;
	return *this ;
 }

   // ����� ����������� 1
 /*  TTraceFlt::TTraceFlt(const double Bearing, const double TargCourse
	, const double TargZenitAng,  const double V, const double H ,
	const double R,const double valT)
{
	 mTf = valT;
//  2.����� ������� ��������� �� ������ mTf
	memset(marrVS_KGSK, 0, 6 * sizeof(double)) ; //!!!!����������!!!!!!
	double valeps = asin( H/R) ;


   double  arrVectSostGSK[6] = {0} ;
   arrVectSostGSK[0] = R * cos(valeps) * sin(Bearing) ;
   arrVectSostGSK[1] = R * cos(valeps) * cos(Bearing) ;
   arrVectSostGSK[2] = H ;
   arrVectSostGSK[3] = V * sin(TargZenitAng) * sin(TargCourse) ;
   arrVectSostGSK[4] = V * sin(TargZenitAng) * cos(TargCourse) ;
   arrVectSostGSK[5] = V * cos(TargZenitAng) ;
//  3.������������ �������������� ������� ������ ���������� � ���
	memset(marrK_KGSK, 0, 36 * sizeof(double)) ;
	for (int i = 0; i < 3; i++)
	{
	marrK_KGSK[ 6 * i + i ] = 1000000. ;
	marrK_KGSK[ 6 * i + i + 3] = 100000. ;
	marrK_KGSK[ 6 * (i + 3) + i] = 100000. ;
	marrK_KGSK[ 6 * (i + 3) + i + 3] = 100000. ;

	}
//  4.������� �������� �� ��� � ��� �� ������ mTf

	memset(marrK_KGSK, 0, 9 * sizeof(double)) ; //!!!!!!

 // 5.����������� ������� �������� �� ��� � ��� �� ������ mTf

	memset(marrFExt_ASK_V_PSK, 0, 36 * sizeof(double)) ; //!!!!!

//  6.������� �������� �� ��� � ���� �� ������ mTf

	memset(marrF_PSK_V_KGSK, 0, 9 * sizeof(double)) ; //!!!!!!

 // 7. ����������� ������� �������� ��  ��� � ���� ��� ������ mTf

	memset(marrFExt_PSK_V_KGSK, 0, 36 * sizeof(double)) ; //!!!!!!!

	// 8.
	mbInit = true ;

}  */


#pragma package(smart_init)
