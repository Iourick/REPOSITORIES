//---------------------------------------------------------------------------

#ifndef CircleCylinderH
#define CircleCylinderH
#include "SimpleBody_3D.h"
// ����� ���������     �������� ������� � ���������� R � ������� h
// ��������� � �������� R ����������� � ������������ ��������� OXZ
// �������� ����������� ��������� ������ �����:
// OX - � �����
// OY - �����
// OZ - �� ���
// ������ ��������� ��������� � ������� ���������
class TPlane;
class TCircleCylinder : public TSimpleBody_3D
{
public:

	double mR;
	double mH;
   //	double mM; // �����



   //	__fastcall ~TCircleCylinder() ;


	 TCircleCylinder () ;

	 // ����������� �����������
	  TCircleCylinder  (const TCircleCylinder  &R) ;

	  // �������� ������������
	  TCircleCylinder  operator=(TCircleCylinder   R2) ;

	  TCircleCylinder(const TPlane Plane, const double R, const double H,const double M);

	  virtual double calcCapacity() ;

	  virtual void calcCentreOfGravity(double *arrCentreGrav)  ;

	  virtual  void calcInertiaMtrx(double *arrInertMtrx) ;




};

#endif
