//---------------------------------------------------------------------------

#ifndef FarH
#define FarH
#include "Faceta.h"
class TComp;
class TFaceta;
class TFar
{
public:


 // ���������� ������� (�����)
 int m_N;
 // ���������� ����� ��������
 double  m_D;
 // ����� �����
 double	 mLambda ;
 // ������
 TFaceta mFaceta;



 TFar() ;


// ����������� �����������
 TFar(const TFar &R) ;
 TFar operator=(TFar  R2) ;
 // ����� ������
 __fastcall TFar(const int N,const double D,const double Lambda
   ,TFaceta Faceta);
 // ����� ������
 __fastcall TFar(const int N);
 

};
#endif
