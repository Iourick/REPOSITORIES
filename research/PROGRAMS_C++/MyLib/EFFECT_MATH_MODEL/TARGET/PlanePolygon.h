//---------------------------------------------------------------------------

#ifndef PlanePolygonH
#define PlanePolygonH
#include "Plane.h"
#include "URPolygon.h"

enum enumTypeTargBody {PLANE_BODY,AXIALLY_SYMMETRICAL_BODY};
class TPlane;
class TURPolygon;
class TPlanePolygon
{
public:
 enumTypeTargBody menumTypeTargBody;
 TPlane mPlane; // ���������
 TURPolygon mPolygon; //������� � ���������
  TPlanePolygon();
 // ����������� �����������
 TPlanePolygon (const TPlanePolygon &R) ;
 // �������� ������������
 TPlanePolygon &operator=( const TPlanePolygon  &R);
 // �������� ������
 TPlanePolygon( const TPlane Plane, const TURPolygon Polygon, const enumTypeTargBody EnumTypeTargBody);
  // �������� ������
 TPlanePolygon( double* arrS0, double* arrF, const TURPolygon Polygon, const enumTypeTargBody EnumTypeTargBody);

 bool isLineIntersectPlanePolygon(double *arrPos, double *arrVelo);

 TURPolygon createShadowPlg_For_PlaneBody(double *arrTargV,  double *arrVectMissV);

 TURPolygon createShadowPlg(double *arrTargV,  double *arrVectMissV);

 TURPolygon createProjectionOfPolygon_To_CartinPlane(double *arrTargV, double *arrVectMissV);

 TURPolygon createProjectionOf_PlaneBodyPolygon_To_CartinPlane(double *arrTargV, double *arrVectMissV);

 double calcDistanse(double *arrPosOtnSSK);
};
#endif
