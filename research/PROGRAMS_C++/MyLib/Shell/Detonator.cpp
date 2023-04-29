//---------------------------------------------------------------------------


#pragma hdrstop
#include <string.h>
#include "Detonator.h"

// ������ ������� AR_51_LM
const double SENSIBLE_RADIUS_AR_51_LM = 3.;

//---------------------------------------------------------------------------
TDetonator::TDetonator()
{
 mEnumDetonatorType = AR32A;
 memset(marrDetonatorParams, 0, LEN_DOUBLE_ARR_DETONATOR_PARAMS * sizeof(double));
 memset(miarrDetonatorParams, 0, LEN_INT_ARR_DETONATOR_PARAMS * sizeof(int));
}

//---------------------------------------------------------------------------


// ����������� �����������
 TDetonator ::TDetonator (const TDetonator &R)
 {
	 mEnumDetonatorType = R.mEnumDetonatorType ;
	 memcpy(marrDetonatorParams, R.marrDetonatorParams,LEN_DOUBLE_ARR_DETONATOR_PARAMS * sizeof(double));
	 memcpy(miarrDetonatorParams, R.miarrDetonatorParams,LEN_INT_ARR_DETONATOR_PARAMS * sizeof(int));
 }

 // �������� ������������
 TDetonator &TDetonator::operator=(const TDetonator  &R)
 {
	 mEnumDetonatorType = R.mEnumDetonatorType ;
	 memcpy(marrDetonatorParams, R.marrDetonatorParams,LEN_DOUBLE_ARR_DETONATOR_PARAMS * sizeof(double));
	 memcpy(miarrDetonatorParams, R.miarrDetonatorParams,LEN_INT_ARR_DETONATOR_PARAMS * sizeof(int));

	return *this ;
 }

// ���������������� �����������
 TDetonator::TDetonator(enumDetonatorType  EnumDetonatorType, double *arrDetonatorParams
 , int *iarrDetonatorParams)
{
	mEnumDetonatorType = EnumDetonatorType;
	memcpy(marrDetonatorParams, arrDetonatorParams,LEN_DOUBLE_ARR_DETONATOR_PARAMS * sizeof(double));
	memcpy(miarrDetonatorParams, iarrDetonatorParams,LEN_INT_ARR_DETONATOR_PARAMS * sizeof(int));
}


// ���������������� �����������
 TDetonator::TDetonator(enumDetonatorType  EnumDetonatorType)
{
	mEnumDetonatorType = EnumDetonatorType;
	memset(marrDetonatorParams, 0,LEN_DOUBLE_ARR_DETONATOR_PARAMS * sizeof(double));
	memset(miarrDetonatorParams, 0,LEN_INT_ARR_DETONATOR_PARAMS * sizeof(int));
	switch(EnumDetonatorType)
	{
	case AR51_LM:
	marrDetonatorParams[0] = SENSIBLE_RADIUS_AR_51_LM; // ������ ����������������
	break;

	case BARRIER:
	marrDetonatorParams[0] =  3./ 1000.; // �������
	marrDetonatorParams[1] =  0.0025; // ����� ���������� ������ ������� ������������
	break;

	default:
	break;
	};
}




//---------------------------------------------------------------------------


#pragma package(smart_init)
