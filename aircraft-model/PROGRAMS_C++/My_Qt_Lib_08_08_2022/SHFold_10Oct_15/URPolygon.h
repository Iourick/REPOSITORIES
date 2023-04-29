﻿//---------------------------------------------------------------------------

#ifndef URPolygonH
#define URPolygonH


#include <stdio.h>
#include <math.h>
#include "URFigure.h"

 class TURPointXY  ;
 class TTriang ;
 class TCircle;
 class QPolygonF;
 extern const double TOLRNC;
 //class TURPolygonZ ;
//---------------------------------------------------------------------------
 /*
    Polygon A polygon consists of one or more rings. A ring is a connected sequence of four or more
points that form a closed, non-self-intersecting loop. A polygon may contain multiple
outer rings. The order of vertices or orientation for a ring indicates which side of the ring
is the interior of the polygon. The neighborhood to the right of an observer walking along
the ring in vertex order is the neighborhood inside the polygon. Vertices of rings defining
holes in polygons are in a counterclockwise direction. Vertices for a single, ringed
polygon are, therefore, always in clockwise order. The rings of a polygon are referred to
as its parts.
Because this specification does not forbid consecutive points with identical coordinates,
shapefile readers must handle such cases. On the other hand, the degenerate, zero length
or zero area parts that might result are not allowed.
The Polygon structure is identical to the PolyLine structure, as follows:
Polygon
{
Double[4] Box // Bounding Box
Integer NumParts // Number of Parts
Integer NumPoints // Total Number of Points
Integer[NumParts] Parts // Index to First Point in Part
Point[NumPoints] Points // Points for All Parts
}
The fields for a polygon are described in detail below:
Box The Bounding Box for the polygon stored in the order Xmin, Ymin, Xmax,
Ymax.
NumParts The number of rings in the polygon.
NumPoints The total number of points for all rings.

ESRI White Paper 9
Parts An array of length NumParts. Stores, for each ring, the index of its first
point in the points array. Array indexes are with respect to 0.
Points An array of length NumPoints. The points for each ring in the polygon are
stored end to end. The points for Ring 2 follow the points for Ring 1, and so
on. The parts array holds the array index of the starting point for each ring.
There is no delimiter in the points array between rings.
 */

class TURPolygon : public TURFigure
{
public:

	double Box[4] ;		// Bounding Box
	int NumParts ;
	int NumPoints ;
	int *Parts ;
	TURPointXY *Points ;

  //	__fastcall TURPolygon() ;
   //	__fastcall TURPolygon(const GPolygon &obj) ;
     ~TURPolygon() ;

  //	TURPolygon &operator = (const TURPolygon &obj) ;



   //	__fastcall TURPolygon ::~TURPolygon ();
  // virtual ~TURPolygon ();
	 TURPolygon () ;

	 // конструктор копирования
	  TURPolygon  (const TURPolygon  &R) ;
	  // оператор присваивания
      TURPolygon  &operator=(const TURPolygon   &R2) ;
	  // парам констр
	  TURPolygon  ( double *arrBox, const int iNumParts,const int iNumPoints,int *iarrParts
					,TURPointXY *arrPoints);
	  // парам констр
      TURPolygon (  const int iNumParts,const int iNumPoints,const int *iarrParts
                    ,const double *arr);

	  // парам констр
	  TURPolygon  (  const int iNumParts,const int iNumPoints,int *iarrParts
					,TURPointXY *arrPoints) ;
		  // парам констр
	 TURPolygon (  const int iNumPoints,double * px, double *py);
	  // парам констр
	 TURPolygon (  const int iNumPoints,TURPointXY  *arrPoints);
	 TURPolygon ( TURPolygon* plgP, const int i,int *piarrNegNums,const int lenarrNegums) ;

	 TURPolygon(const TCircle Circle , const int iNUM);

	 // парам констр
	 TURPolygon (  const int iNumPoints) ;
	// парам констр
	 TURPolygon ( const int iNumParts, const int iNumPoints) ;

	 // парам констр
  //	 TURPolygon  (const TURPolygonZ &R) ;
	 // парам констр
	 TURPolygon  (wchar_t*FileName);
	// парам констр
	 TURPolygon (  const int iNumTr, TTriang *parrTr);
	  // парам констр
	 TURPolygon( TURPolygon *parrPlg, const int lenarrPlg);
	 // парам констр создания rectangle
     TURPolygon(  const TURPointXY pntTopRight,const TURPointXY pntBottomLeft);

     // парам констр создания
    // TURPolygon (QPolygonF &qplg);
	// функции члены

	static int fncSIGN_ (double x)
	{
		if (fabs(x) < TOLRNC) return 0 ;

		return ( x > 0.)?1:-1;
	}
	static void calcPointsOfPolygonFromASCII(wchar_t*FileName,int *quanParts
					,int *quanPoints) ;

	static void fillPartsOfPolygonFromASCII(wchar_t*FileName, const int quanParts
					,const int quanPoints,int *piarrParts)  ;

	bool ReadPolygonFromASCII(wchar_t*FileName) ;


	 static bool HorizCutSegment(const double x1,const double y1,const double x2,const double y2,
							const double y0,double &x0);

	 static int LineCutSegment(const TURPointXY p1, const TURPointXY p2// сегмент
							,const TURPointXY p0,const double k0 // прямая k0 - тангенс наклона
							,TURPointXY &pCut // точка пересечения
								);
	 bool PtInPlygon( TURPointXY v) ;
	 // возвращает:
// 0 - не пересекает
// 1 - пересекает
// 3  - точка p0  лежит на ребре полигона
// 4  - точка  p0  является вершиной полигона

	 int PntInPolygon( TURPointXY p0); // NEW 26.09.2012

	 double calcPartSq(const int n) ;

	 double calcVectSq()  ;

	 double calcLeng();

	 double calcPartLeng(const int n);

	 static double dist(TURPointXY*p0, TURPointXY*p1) ;

	 virtual void calcBoundBox();

	 void getExtent(double &xmin0,double &xmax0,double &ymin0,double &ymax0);

	  int WriteToASCII(wchar_t*FileName) ;      

	  int  WriteToASCII__(wchar_t*FileName);

	  //пересечение полигонов
	  static TURPolygon InterSectPlg(TURPolygon &urplgP1,TURPolygon &urplgP2);

	  // объединение полигонов
	  static TURPolygon UnitePlg(TURPolygon &urplgP1,TURPolygon &urplgP2);

	  // вычитание из полигона P1 полигон H2
	  static TURPolygon PlgMinusPlg(TURPolygon &urplgP1,TURPolygon &urplgP2);

	  // разбиение полигона на элементарные треугольники
	  void DisassemblePlg( TTriang **pparrTr //указатель на указатель на массив треугольников длинойи quantTr
								 ,int *quantTr  // к-во треугольников
								// , const int lenArrTr // начальгная величина зарезервированной памяти parrTr
								);
	  //
	  static void InterSectArrPlg(const int quantTr1,TTriang *parrInpTr1,const int quantTr2,TTriang *parrInpTr2,
		  int &quantOutTr,TTriang *parrOutTr);

	  static TURPolygon AssemblePlgFromTriangleArr(const int quantTr,TTriang *parrInpTr);

		bool TriangulateRing(TTriang *parrTrTemp);

static int IntersectTwoLine( const TURPointXY p0,const  TURPointXY p1
					,const TURPointXY p2,const TURPointXY p3, TURPointXY *p);

// пересечение 2-х отрезков
//возвращает true если отрезки пересек и false в противном случае
//если true: если отрезки лежат на одной прямой - то p0 -p1 - отрезок пересечение
// если не наодной прямой, то p0 - точка пересечения, а p1 = NULL
 static bool IntersectTwoSegments(
					const TURPointXY p00,const  TURPointXY p01 //1-ый сегмент
					,const TURPointXY p10,const TURPointXY p11  // 2-ой сегмент
					, TURPointXY *p0  // точка пересечения
					, TURPointXY *p1  // точка пересечения
					);

 static double max_d(double a,double b)
  {
	  return (a > b)?a:b;
  } ;

  static double min_d(double a,double b)
  {
	  return (a > b)? b : a;
  } ;

 bool IsChordCutRing( const int j);

 TURPolygon ExcludePointFromRing(const int numberPoint) ;

 static double dist(TURPointXY p0 ,TURPointXY p1);

 void  subtractEqualVerts();

 static int PntInSegment(double a,double x);

 void FillArrayNegNums(const int num0,int *piarrNegNums,int *lenarrNegNums,bool *barrPartInPart);

 void DisassembleSimplePlg(TTriang **ppTrRez, int *lenArrTr);

  bool IsPartIncludedInPart(const int i,const int  j) ;

 static void  TriangleArrMinusTriangleArr(TTriang * pTr0,const int lenArrTr0,TTriang *ppTr1,const int lenArrTr1
											   ,TTriang **ppTrRez, int *lenArrTrRez);

static void  AssemblePlgFromTriangleArr_1(TTriang **ppTr, const int quantOutTr
	 , TURPolygon **ppPlgRez, int * lenPlgArr) ;

 bool  JuncTriangle(TTriang *pTr,int * numVertTr,int * numVertPlg,int *numPartPlg)  ;

void AddVert(TURPointXY pntP,const int numVert, const int numPart );

static TURPolygon NormalizePolygon(TURPolygon *parrPlg,const int lenarrPlg  );

TURPolygon NormalizeRing();

// изменение порядка следования байтов в 4 байтном слове (32 бита массив)
//  input : chstr - указатель на массив char[4]
// output: chstr - указатель на массив  char[4] c измененным порядком следования
// байтов  char[0] = char[3] ; char[1] = char[2] ;  char[2] = char[1] ; char[3] = char[0] ;
static void ChangeByteOrder(int * pi0) ;

  
static void WriteDBASEFile(wchar_t *wchFileName,TURPolygon *purPlg, const int quantPlg) ;

static void WriteMainFile(wchar_t *wchFileName,TURPolygon *purPlg, const int quantPlg) ;
static void WriteIndexFile(wchar_t *wchFileName,TURPolygon *purPlg, const int quantPlg) ;
static void WriteSetSHPFiles(wchar_t *wchFileName,TURPolygon *purPlg, const int quantPlg) ;

static void ReadSHPFile(wchar_t *wchFileName,TURPolygon **ppurPlg,  int *pquantPlg)  ;

static TURPolygon fncCreateSector(const TURPointXY pointCentre, const double valR,
					const double valFi0,const double valFi1,const int iNUM) ;

int fncFindNumMainVertex ( const TURPointXY pointCentre0,const TURPointXY pointCentre1,const double valR) ;

static TURPolygon fncSimpleSectorsIntersection( TURPolygon plgInterSect,TURPolygon plgSect0
			   ,TURPolygon plgSect1, TURPointXY *pPointCentre
					,const double valR) ;

static bool fncIsOnCircle (const TURPointXY point, const TURPointXY pointCentre,const double valR) ;

void ExcludeExcessVertexesFromRing();

bool fncFindSecantSegm( TURPointXY pointLine, double *arrVectLine
	   ,TURPointXY &pntSegm0,TURPointXY &pntSegm1) ;

static void fncRemoveEqualNeighbourFromPointsArray(TURPointXY *pPntArr, const int lenarr, int &lenarrOut);

double fncFindBisectorAng(const int iNumVertex) ;

static bool   Atan2_(const double y, const double x,  double *prez);

static double SignD(const double valOm);

static int fncCheckPositionCircle_and_Edge( TURPointXY pntCentre
	,const double valR,   TURPointXY pntSegm0,   TURPointXY pntSegm1
	, TURPointXY &pntRez ) ;

static int   fncCheckProperPositionCircle_and_VerticalEdge(const TURPointXY pntCentre
	,const double valR,  const TURPointXY pntSegm0,  const TURPointXY pntSegm1
	, TURPointXY &pntRez ) ;

static TURPolygon fncCreateCircle(const TURPointXY pointCentre
	 ,const double valR, const int iNUM) ;

bool fncFindBisectorLine(const int iNumVertex0, const int iNumVertex1
				   ,double &valBsctAng, TURPointXY &pntBsctVertex);

bool fncFindSecantSegm_NotVerticalLine( TURPointXY pointLine, double *arrVectLine
	   ,TURPointXY &pntSegm0,TURPointXY &pntSegm1) ;

static int ParametricLineCutSegment( TURPointXY p1,  TURPointXY p2// сегмент
							, TURPointXY p0, double *arrV //
							,TURPointXY &pCut // точка пересечения
							);

TURPolygon  fncLinTransform(double * arrMtxPer )  ;

double   fncCalcOutsideCircleAng(const TURPointXY pointLine, double valR);

double   fncCalcOutsideEdgeAng(const TURPointXY pointLine, double valR, const int iEdgeNum) ;

static int fncParametricVerticalLineCutCircle( TURPointXY pntCrclCentre,double valR// окружность
							,TURPointXY pointLine, double *arrVectLine // линия
							,TURPointXY *arrPntRez // точек ассив а пересечения
							) ;

static int fncParametricLineCutCircle( TURPointXY pntCrclCentre,double valR// окружность
							,TURPointXY pointLine, double *arrVectLine // линия
							,TURPointXY *arrPntRez // точек ассив а пересечения
								)  ;

static int fncSegmentCutCircle( TURPointXY pntCrclCentre,double valR// окружность
							, TURPointXY pntSegm0,  TURPointXY pntSegm1
							,TURPointXY *arrPntRez // точек ассив а пересечения
								);

static int fncVerticalSegmentCutCircle( TURPointXY pntCrclCentre,double valR// окружность
							,const TURPointXY pntSegm0,  const TURPointXY pntSegm1
							,TURPointXY *arrPntRez // точек ассив а пересечения
								) ;


static int fncIntersectConvexPlgns( TURPolygon &plgInp0,TURPolygon &plgInp1, TURPolygon &plgOut);

bool IsConv();

static bool IncludeAllIntersectingPoints( TURPolygon &plgP0, TURPolygon &plgP1) ;

 int findNumVertex(TURPointXY pntP) ;

 static int fncFindNumFirstCommonVert(TURPolygon plg0,TURPolygon plg1);

double   fncCalcInsideCircleAng(const TURPointXY pntCrclCentre, double valR) ;

 static double   fncCalcFi(const TURPointXY pntP,const TURPointXY pntCrclCentre) ;

 double fncCalcProbability( TURPointXY pntCrclCentre)  ;

int fncIntersectTwoParametricLines( TURPointXY pointLine0, double *arrVectLine0
		, TURPointXY pointLine1, double *arrVectLine1
		,TURPointXY &pointLineOut);


bool fncFindEscribedCircle(const int iNumVert0,const int iNumVert1, TURPointXY &pntCentre, double &valR) ;

int fncIntersectParametricLine_AND_Vert(const TURPointXY pointLine0
		,const TURPointXY pointLine1, double *arrVectLine1
		,TURPointXY &pointLineOut) ;


 bool   fncFindMaxSegm(TURPointXY pntCrclCentre  // центр окружности
			, TURPointXY &pntSegm0, TURPointXY &pntSegm1 );

static int fncSegmentCutCircleLine( TURPointXY pntCrclCentre,double valR// окружность
							, TURPointXY pntSegm0,  TURPointXY pntSegm1
							,TURPointXY *arrPntRez // точек ассив а пересечения
								);
 bool   fncFindMaxArc(TURPointXY pntCrclCentre  // центр окружности
			, TURPointXY &pntSegm0, TURPointXY &pntSegm1  );

 static int fncVerticalSegmentCutCircleLine( TURPointXY pntCrclCentre,double valR// окружность
							,const TURPointXY pntSegm0,  const TURPointXY pntSegm1
							,TURPointXY *arrPntRez // точек ассив а пересечения
								);
static TURPolygon  Conv(TURPointXY *parrPnts // массив точек, input
			, const int lenarr // длина массива точек , input
			  )  ;

static void findTwoFirstVertexes(TURPointXY *parrPnts // массив точек, input
			, const int lenarr // длина массива точек , input
			, int *piarrnum  // массив номеров прервой и второй вершин, otput
			  ) ;

static int findNextVertex( TURPointXY *parrPnts // массив точек, input
			, const int lenarr // длина массива точек , input
			 ,int * piarrNumPoints // массив номеров уже найденных вершин
			 , const int numPoints // длина массива  номеров уже найденных вершин
			 ) ;

static bool IsConvEdge( TURPointXY *parrPnts // массив точек, input
			, const int lenarr // длина массива точек , input
			, const int i // номер первой вершины
			, const int j // номер второй вершины
			)  ;


void flip();

void flipPart(const int n);

static bool IsBelongedToIntArray(const int j // проверяемый номер
									 ,int *piarrNumPoints // массив номеров
									 ,const int numPoints // длина массива  номеров
									   );

TURPolygon  LinTransform(const double  valAng, const TURPointXY pntSdvig
  , const TURPointXY pntCentre,const double valRastigenie );

TURPolygon   RastiagenieTransform( const double valRastigenie );

TURPolygon   SdvigTransform(const TURPointXY pntSdvig );

TURPolygon   SimOtragenieTransform();

static TURPolygon  createEllips(const double vala, const double valb
	 ,const TURPointXY pntCentre, const int numPoints ) ;

TURPolygon   LinTransform(const double  valAng , const TURPointXY pntSdvig,const double valRastigenie ) ;

static TURPolygon fncCreateDiagr(const TURPointXY pointCentre, const double valR,
					const double valRotAng ,const double valWidthMilrad,const int iNUM) ;

static TURPolygon createFarHood( const double valHeight, const double  valWidth, const double  valRad);

static TURPolygon fncCreateParallelogramm(TURPointXY pntLowLeft,const double VALx,const double VALy
 ,const double VAL_al1 );

static TURPolygon createPictParabAnt( const double valScale);

TURPolygon SimOtragenieY_and_flip();

TURPolygon extractSimplePolygon(const int n);

int calcQuantApproximatingPoints(const double valTargCellSize);

void addTargPointsArray(const double valTargCellSize,  TURPointXY **ppTargPntArray
   ,int *lenMemoryResedved, int *lenMemoryCur ) ;

virtual void createTargPointsArray( const double valTargCellSize, TURPointXY **ppTargPntArray, int *lenTargPntArray);

virtual void WriteSetSHPFiles(wchar_t *wchFileName);

virtual void createUnatedPointsArray(TURPointXY **ppunatedPoints, int *quantUnitedPoints) ;

virtual void   LinearTransformation(const double  valAng , const TURPointXY pntSdvig,const double valRastigenie );

virtual void   ConvexShell(TURPolygon *pPolgConv);

static TURPolygon   createEllips(double *arrElK, const double VAlCoeff, const int  NUmPoints);

static TURPolygon   createRect(double *Box)  ;

static void   swap(TURPolygon *a0, TURPolygon *a1);

static void   flipArray(TURPolygon *parr, const int len);

TURPointXY calcCentreMass(const double cellsize);

static TURPolygon createCassiniOval(const double vala, const double valc
     , const int numPoints );

void calcInertiaMtrx(const TURPointXY pntCentre, const double cs, double *mtrxInertia);

double calcSx(const double cs);

double calcSy(const double cs);

double calcJx(const double cs, const double VAlY0);

double calcJy(const double cs, const double VAlY0);

static TURPolygon fncCreateEllipse_(const TURPointXY pointCentre
     ,const double a,const double b, const int iNUM);

//double  calcMaxY();

};
 int cmp_(const void * a,  const void *b);

 bool   fncFindMaxEscibedCircle( TURPointXY *ppointLine, double *arrVTransf, TURPolygon plgPlg,
	TURPointXY &pntCentre, double &valR)  ;

 bool   fncFindMaxCircle(TURPointXY *ppointLine, double *arrVectLine , TURPolygon plgPlg
		,TURPointXY &pntCentre, double &valR) ;



#endif
