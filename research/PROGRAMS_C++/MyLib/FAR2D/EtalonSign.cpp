//---------------------------------------------------------------------------


#pragma hdrstop
#include <math.h>

#include "EtalonSign.h"


__fastcall  TEtalonSign::TEtalonSign()
{
  // ��������
	mEtalonAmp =0.;
 //���������
	mEtalonDist =0.;
 //���
	mEtalonEPR =0.;
 //��� ����� ���� ��������� ��������� 5�10
	mNoiseSKZ_5P10 =0.;
 // ��� �������� ������� �������� ��������� ��������� 5�10
	mEtalonSigAmplFact_5P10 =0.;
 // �������� �� ��������
	mEtalonPowerPrd =0.;
 // �� �� ��������
	mEtalonKYPrd =0.;
 // �������� �� �����
	mEtalonKYPriem =0.;

}
// ����������� �����������
__fastcall  TEtalonSign::TEtalonSign (const TEtalonSign &R)
 {
	// ��������
	mEtalonAmp = R.mEtalonAmp;
	//���������
	mEtalonDist = R.mEtalonDist;
	//���
	mEtalonEPR = R.mEtalonEPR;
	//��� ����� ���� ��������� ��������� 5�10
	mNoiseSKZ_5P10 = R.mNoiseSKZ_5P10;
	// ��� �������� ������� �������� ��������� ��������� 5�10
	mEtalonSigAmplFact_5P10 = R.mEtalonSigAmplFact_5P10;
	mEtalonPowerPrd = R. mEtalonPowerPrd;
	mEtalonKYPrd = R.mEtalonKYPrd;
	mEtalonKYPriem = R.mEtalonKYPriem;
 }

 // �������� ������������
  TEtalonSign &TEtalonSign::operator=(const TEtalonSign  &R)
 {
	// ��������
	mEtalonAmp = R.mEtalonAmp;
	//���������
	mEtalonDist = R.mEtalonDist;
	//���
	mEtalonEPR = R.mEtalonEPR;
	//��� ����� ���� ��������� ��������� 5�10
	mNoiseSKZ_5P10 = R.mNoiseSKZ_5P10;
	// ��� �������� ������� �������� ��������� ��������� 5�10
	mEtalonSigAmplFact_5P10 = R.mEtalonSigAmplFact_5P10;
	mEtalonPowerPrd = R. mEtalonPowerPrd;
	mEtalonKYPrd = R.mEtalonKYPrd;
	mEtalonKYPriem = R.mEtalonKYPriem;
	 return *this ;
 }

 // ����� ������ 1
 __fastcall TEtalonSign::TEtalonSign(const double EtalonAmp,const double EtalonDist, const double EtalonAPR
   , const double NoiseSKZ_5P10, const double EtalonSigAmplFact_5P10)
 {
	 mEtalonAmp = EtalonAmp;
	 mEtalonDist = EtalonDist;;
	 mEtalonEPR = EtalonAPR;
	 mNoiseSKZ_5P10 = NoiseSKZ_5P10;
	 mEtalonSigAmplFact_5P10 = EtalonSigAmplFact_5P10;
 }

  // ����� ������ 2
 __fastcall TEtalonSign::TEtalonSign(const double EtalonAmp,const double EtalonDist, const double EtalonAPR
   , const double NoiseSKZ_5P10, const double EtalonSigAmplFact_5P10, const double EtalonPowerPrd,  const double  EtalonKYPrd
   , const double EtalonKYPriem)
 {
	 mEtalonAmp = EtalonAmp;
	 mEtalonDist = EtalonDist;;
	 mEtalonEPR = EtalonAPR;
	 mNoiseSKZ_5P10 = NoiseSKZ_5P10;
	 mEtalonSigAmplFact_5P10 = EtalonSigAmplFact_5P10;
	 mEtalonPowerPrd = EtalonPowerPrd;
	 mEtalonKYPrd = EtalonKYPrd;
	 mEtalonKYPriem = EtalonKYPriem;
 }
// ��������� ���/������
 double TEtalonSign::calcNWaveEtalon()
 {

 //return  sqrt( mNoiseSKZ_5P10 *  mNoiseSKZ_5P10 /  mEtalonAmp/  mEtalonAmp
 //		 +  mEtalonSigAmplFact_5P10 *  mEtalonSigAmplFact_5P10);
 return    mNoiseSKZ_5P10 /  mEtalonAmp;
 }


#pragma package(smart_init)

