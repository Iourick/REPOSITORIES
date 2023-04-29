//---------------------------------------------------------------------------


#pragma hdrstop

#include "OutPutAeroShot.h"
#include  <string.h>

//---------------------------------------------------------------------------
TOutPutAeroShot::TOutPutAeroShot()

{
//   ����� ��������
 mTshot = 0.;
//   �������� �����
 mTfly = 0.;
//  ������ ��������� ������� �� ������ �������� � ���
memset(marrVS_GSK_Vessel, 0, 6 * sizeof(double));

// ������ ��������� ���� ������� �� ������ �������� � ���
memset(marrVS_GSK_Targ, 0, 6 * sizeof(double));

//  ���� � ����
 mEpsKGSK =0.;
// ���� � ����
 mBetKGSK =0.;
// �������� ������� �������� ������� ��������� ���� � ��� �� ������ �������
memset(marrKTarg, 0, 36 * sizeof(double));

// �������� ������� �������� ������� ��������� ������� � ���  �� ������ �������
memset(marrKShell, 0, 36 * sizeof(double));

// ������ �������
memset(marrMiss, 0, 6 * sizeof(double));


}

//---------------------------------------------------------------------------


// ����������� �����������
 TOutPutAeroShot ::TOutPutAeroShot (const TOutPutAeroShot &R)
 {
	//   ����� ��������
 mTshot = R.mTshot;
//   �������� �����
 mTfly = R.mTfly;
//  ������ ��������� ������� �� ������ �������� � ���
memcpy(marrVS_GSK_Vessel, R.marrVS_GSK_Vessel, 6 * sizeof(double));

// ������ ��������� ���� ������� �� ������ �������� � ���
memcpy(marrVS_GSK_Targ, R.marrVS_GSK_Targ, 6 * sizeof(double));

//  ���� � ����
 mEpsKGSK = R.mEpsKGSK;
// ���� � ����
 mBetKGSK = R.mBetKGSK;
// �������� ������� �������� ������� ��������� ���� � ��� �� ������ �������
memcpy(marrKTarg, R.marrKTarg, 36 * sizeof(double));

// �������� ������� �������� ������� ��������� ������� � ���  �� ������ �������
memcpy(marrKShell, R.marrKShell, 36 * sizeof(double));

memcpy( marrMiss, R. marrMiss, 6 * sizeof(double));


 }

 // �������� ������������
 TOutPutAeroShot &TOutPutAeroShot::operator=(const TOutPutAeroShot  &R)
 {
	//   ����� ��������
 mTshot = R.mTshot;
//   �������� �����
 mTfly = R.mTfly;
//  ������ ��������� ������� �� ������ �������� � ���
memcpy(marrVS_GSK_Vessel, R.marrVS_GSK_Vessel, 6 * sizeof(double));

// ������ ��������� ���� ������� �� ������ �������� � ���
memcpy(marrVS_GSK_Targ, R.marrVS_GSK_Targ, 6 * sizeof(double));

//  ���� � ����
 mEpsKGSK = R.mEpsKGSK;
// ���� � ����
 mBetKGSK = R.mBetKGSK;
// �������� ������� �������� ������� ��������� ���� � ��� �� ������ �������
memcpy(marrKTarg, R.marrKTarg, 36 * sizeof(double));

// �������� ������� �������� ������� ��������� ������� � ���  �� ������ �������
memcpy(marrKShell, R.marrKShell, 36 * sizeof(double));
memcpy( marrMiss, R. marrMiss, 6 * sizeof(double));

	return *this ;
 }




// ���������������� �����������
 TOutPutAeroShot::TOutPutAeroShot( const double Tshot
		,const double Tfly, double *arrVS_GSK_Vessel, double *arrVS_GSK_Targ
		,const double EpsKGSK,const double BetKGSK, double *arrKTarg
		,double *arrKShell, double *arrMiss)
{
   mTshot = Tshot;
   mTfly = Tfly;
   memcpy(marrVS_GSK_Vessel, arrVS_GSK_Vessel, 6 * sizeof(double));

// ������ ��������� ���� ������� �� ������ �������� � ���
memcpy(marrVS_GSK_Targ, arrVS_GSK_Targ, 6 * sizeof(double));
//  ���� � ����
 mEpsKGSK =  EpsKGSK;
// ���� � ����
 mBetKGSK =  BetKGSK;
// �������� ������� �������� ������� ��������� ���� � ��� �� ������ �������
memcpy(marrKTarg,  arrKTarg, 36 * sizeof(double));

// �������� ������� �������� ������� ��������� ������� � ���  �� ������ �������
memcpy(marrKShell,  arrKShell, 36 * sizeof(double));

memcpy(marrMiss,  arrMiss, 6 * sizeof(double));

}

//---------------------------------------------------------------------------

 //---------------------------------------------------------------------
//
void   TOutPutAeroShot::swap( TOutPutAeroShot *a0,  TOutPutAeroShot *a1)
{
	TOutPutAeroShot b = *a1;
	*a1 = *a0 ;
	*a0 = b ;
}

//---------------------------------------------------------------------
// ��������� ��������� ����������� ������� �� ��������
void   TOutPutAeroShot:: flipArray( TOutPutAeroShot *parr, const int len)
{
	for (int i = 0; i < len/ 2; i++)
	{
		 swap(&parr[i], &parr[len - 1 -i]) ;

	}
}



#pragma package(smart_init)
