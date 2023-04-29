//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop
#include "Triang.h"
#include "URPolygon.h"
#include "URPointXY.h"
#include <stdio.h>
#include <math.h>
#include <float.h>
#include "MatrixProccess.h"
#include <stdlib.h>
#include "ArcParab.h"
#include "URPolyLine.h"
#include "Circle.h"
#include "YrRastr.h"




//---------------------------------------------------------------------------

#pragma package(smart_init)

extern const double TOLRNC = 0.0000000001;
//http://www.esri.com/library/whitepapers/pdfs/shapefile.pdf
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

//---------------------------------------------------------------------------

__fastcall TURPolygon::~TURPolygon()
{
	if(Parts) delete []Parts ;
	Parts = NULL ;
	if(Points) delete []Points ;
	Points = NULL ;
}
//---------------------------------------------------------------------------


  TURPolygon ::TURPolygon()
{

	NumParts = 0 ;
	NumPoints = 0 ;
	Parts = NULL ;
	Points = NULL ;

}
//--------------------------------------------------

// ����������� �����������
 TURPolygon ::TURPolygon (const TURPolygon &R)
 {
	NumParts  = R.NumParts ;
	if( Parts != NULL)
	{
   //	delete []Parts;
	Parts = NULL;
	}

	if( Points != NULL)
	{
   //	delete []Points;
	Points = NULL;//
	}

	if(R.Parts != NULL)
	{
		Parts = new int[R.NumParts];

		if(Parts == NULL)
		{
		ShowMessage(L"Not memory for Parts") ;
		Abort() ;
		}

		memcpy( Parts,R.Parts, R.NumParts  * sizeof(int));
	}

	NumPoints = R.NumPoints ;


	if(R.Points != NULL)
	{
		Points = new TURPointXY[R.NumPoints];
		if(Points == NULL)
		{
		ShowMessage(L"Not memory for Points") ;
		Abort() ;
		}
		memcpy( Points,R.Points, R.NumPoints  * sizeof(TURPointXY));
	}

 }
 // �������� ������������
 TURPolygon &TURPolygon::operator=(const TURPolygon  &R)
 {
	if( Parts != NULL)
	{
	delete []Parts;
	Parts = NULL;
	}

	if( Points != NULL)
	{
	delete []Points;
	Points = NULL;//
	}
	NumParts  = R.NumParts ;
	if (Parts != NULL) Parts = NULL;
	if(R.Parts != NULL)
	{
		Parts = new int[R.NumParts];
		if(Parts == NULL) 	   {
		ShowMessage(L"Not memory for Parts") ;
		Abort() ;
	}
	memcpy( Parts,R.Parts, R.NumParts  * sizeof(int));
	}

	NumPoints = R.NumPoints ;
	if (Points != NULL)
	{
	 Points = NULL ;
	}//
	if(R.Points != NULL)
	{
		Points = new TURPointXY[R.NumPoints];
		if(Points == NULL)
		{
		ShowMessage(L"Not memory for Points") ;
		Abort() ;
		}
		memcpy( Points,R.Points, R.NumPoints  * sizeof(TURPointXY));
	}

	return *this ;
 }
//--------------------------------------------------
TURPolygon ::TURPolygon( double *arrBox, const int iNumParts,const int iNumPoints,int *iarrParts
					,TURPointXY *arrPoints)
{
  //1
  if (arrBox != NULL) memcpy(Box,arrBox,4 * sizeof(double));
  ///////////////////////////////////////////////////////////

  //2
   NumParts = iNumParts ;
   //3
   NumPoints = iNumPoints ;
   //4

	Parts = NULL;

   if(iarrParts != NULL)
   {
	   Parts = new int[iNumParts];
	   if(Parts == NULL)
	   {
		   ShowMessage(L"Not memory for Parts") ;
		   return ;
	   }
		memcpy( Parts,iarrParts, iNumParts  * sizeof(int));
   }
   //5


	Points = NULL ;


   if(arrPoints != NULL)
   {
	   Points = new TURPointXY[iNumPoints];
	   if(Points == NULL)
	   {
		   ShowMessage(L"Not memory for Points") ;
		  return ;
	   }
		memcpy( Points,arrPoints, iNumPoints  * sizeof(TURPointXY));
   }
   //6

}

//-------------------------------------------------------------
TURPolygon ::TURPolygon(  const int iNumParts,const int iNumPoints,int *iarrParts
					,TURPointXY *arrPoints)
{

  //2
   NumParts = iNumParts ;
   //3
   NumPoints = iNumPoints ;
   //4
   if (Parts != NULL)
   {
   //	delete [] Parts;
	Parts = NULL;
   }

   if(iarrParts != NULL)
   {
	   Parts = new int[iNumParts];
	   if(Parts == NULL)
	   {
		   ShowMessage(L"Not memory for Parts") ;
		   Abort() ;
	   }
		memcpy( Parts,iarrParts, iNumParts  * sizeof(int));
   }
   //5
   if (Points != NULL)
   {
   //	delete [] Points;
	Points = NULL ;
   }

   if(arrPoints != NULL)
   {
	   Points = new TURPointXY[iNumPoints];
	   if(Points == NULL)
	   {
		   ShowMessage(L"Not memory for Points") ;
		   Abort() ;
	   }
		memcpy( Points,arrPoints, iNumPoints  * sizeof(TURPointXY));
   }
   //6
	  calcVectSq()  ;
	  calcBoundBox();
}

TURPolygon ::TURPolygon(  const int iNumParts,const int iNumPoints,int *iarrParts)

{

	//2
	NumParts = iNumParts ;
	//3
	NumPoints = iNumPoints ;
	//4
	Parts = NULL;


	if(iarrParts != NULL)
	{
	Parts = new int[iNumParts];
	if(Parts == NULL)
	{
	ShowMessage(L"Not memory for Parts") ;
	Abort() ;
	}
	memcpy( Parts,iarrParts, iNumParts  * sizeof(int));
	}
	//5
	Points = NULL ;


	Points = new TURPointXY[iNumPoints];
	if(Points == NULL)
	{
	ShowMessage(L"Not memory for Points") ;
	Abort() ;
	}

	memset ( Points, 0, iNumPoints  * sizeof(TURPointXY));

}
//-------------------------------------------------

TURPolygon::TURPolygon(  const int iNumParts,const int iNumPoints,int *iarrParts
					,double *arr)
{
   TURPointXY *arrPoints = new TURPointXY[ iNumPoints] ;
   for (int i =0; i < iNumPoints; i++)
   {
	arrPoints[i].X = arr[ 2*i ];
	arrPoints[i].Y = arr[ 2*i +1 ];
   }
  //2
   NumParts = iNumParts ;
   //3
   NumPoints = iNumPoints ;
   //4
   if (Parts != NULL)
   {
   //	delete [] Parts;
	Parts = NULL;
   }

   if(iarrParts != NULL)
   {
	   Parts = new int[iNumParts];
	   if(Parts == NULL)
	   {
		   ShowMessage(L"Not memory for Parts") ;
		   Abort() ;
	   }
		memcpy( Parts,iarrParts, iNumParts  * sizeof(int));
   }
   //5
   if (Points != NULL)
   {
   //	delete [] Points;
	Points = NULL ;
   }

   if(arrPoints != NULL)
   {
	   Points = new TURPointXY[iNumPoints];
	   if(Points == NULL)
	   {
		   ShowMessage(L"Not memory for Points") ;
		   Abort() ;
	   }
		memcpy( Points,arrPoints, iNumPoints  * sizeof(TURPointXY));
   }
   delete []arrPoints;
   //6
	  calcVectSq()  ;
	  calcBoundBox();
}

TURPolygon ::TURPolygon(  const int iNumPoints,double * px, double *py)
{

  //2
   NumParts = 1 ;
   //3
   NumPoints = iNumPoints ;
   //4
   if (Parts != NULL)
   {
   //	delete [] Parts;
	Parts = NULL;
   }


	   Parts = new int[NumParts];
	   if(Parts == NULL)
	   {
		   ShowMessage(L"Not memory for Parts") ;
		   Abort() ;
	   }
	   Parts[0] = 0;


   //5
   if (Points != NULL)
   {
   //	delete [] Points;
	Points = NULL ;
   }

   if((px != NULL) && (py != NULL) )
   {
	   Points = new TURPointXY[iNumPoints];
	   if(Points == NULL)
	   {
		   ShowMessage(L"Not memory for Points") ;
		   Abort() ;
	   }
	   for (int i =0; i < iNumPoints; i++)
	   {
		 Points[i].X = px[i];
		 Points[i].Y = py[i];
	   }

   }
   //6

	  calcVectSq()  ;
	  calcBoundBox();
}
// ����� ������
TURPolygon :: TURPolygon(  const int iNumPoints,TURPointXY  *arrPoints)

 {
   NumParts = 1 ;
   //3
   NumPoints = iNumPoints ;
   //4
   Parts = NULL;





	   Parts = new int[NumParts];
	   if(Parts == NULL)
	   {
		   ShowMessage(L"Not memory for Parts") ;
		   return ;
	   }
	   Parts[0] = 0;



	Points = NULL ;
   if(arrPoints != NULL)
   {
	   Points = new TURPointXY[iNumPoints];
	   if(Points == NULL)
	   {
		   ShowMessage(L"Not memory for Points") ;
		   Abort() ;
	   }
	   for (int i =0; i < iNumPoints; i++)
	   {
		 Points[i].X = arrPoints[i].X;
		 Points[i].Y = arrPoints[i].Y;

	   }

   }


 }
  // ����� ������
 TURPolygon ::TURPolygon(  const int iNumTr, TTriang *parrTr)
{
	NumParts = iNumTr;
	NumPoints = 4 * NumParts ;
	Parts = NULL;
	Parts = new int[NumParts];
	if(Parts == NULL)
	   {
		   ShowMessage(L"Not memory for Parts") ;
		   return ;
	   }
	Points = NULL ;
	Points = new TURPointXY[NumPoints];
	if(Points == NULL)
	 {
		   ShowMessage(L"Not memory for Points") ;
		   Abort() ;
	  }
	for (int i = 0; i < NumParts; i++)
	{
	  Parts [i] = 4*i;
	  memcpy( &Points[4*i],parrTr[i].m_pVert,4 * sizeof(TURPointXY));

	}


}

  // ����� ������
 TURPolygon ::TURPolygon( TURPolygon *parrPlg, const int lenarrPlg)
{
	NumParts = 0;
	NumPoints = 0 ;
	for (int i =0; i < lenarrPlg; i++)
	{
	  NumParts += parrPlg[i].NumParts;
	  NumPoints +=  parrPlg[i].NumPoints;
	}
	Parts = NULL;
	Parts = new int[NumParts];
	if(Parts == NULL)
	   {
		   ShowMessage(L"Not memory for Parts") ;
		   return ;
	   }
	Points = NULL ;
	Points = new TURPointXY[NumPoints];
	if(Points == NULL)
	 {
		   ShowMessage(L"Not memory for Points") ;
		   Abort() ;
	  }

	   memcpy(Parts, parrPlg[0].Parts,sizeof(int)* parrPlg[0].NumParts);
	  int n0 = 0 ;
	  int iPartsTemp = parrPlg[0].NumParts;
	for (int i = 1; i < lenarrPlg; i++)
	{
	  n0 += parrPlg[i-1].NumPoints;
	  int it = n0 ;

		for (int j = 0; j < parrPlg[i].NumParts;  j++)
		{
		Parts[iPartsTemp] = it + parrPlg[i].Parts[j];
		it =+ parrPlg[i].Parts[j];
		iPartsTemp++;
		}
	}
   	n0 =0;
	for (int i = 0; i < lenarrPlg; i++)
	{
	  memcpy( &Points[n0], parrPlg[i].Points,sizeof(TURPointXY) * parrPlg[i].NumPoints);
	  n0 +=  parrPlg[i].NumPoints;
	}
}

	// ����� ������
 TURPolygon ::TURPolygon( TURPolygon* plgP, const int i0,int *piarrNegNums,const int lenarrNegNums)
 {
   NumParts = 1 + lenarrNegNums ;
   //3
   NumPoints = 0 ;
	 Parts = NULL;
	   Parts = new int[NumParts];
	   if(Parts == NULL)
	   {
		   ShowMessage(L"Not memory for Parts") ;
		   return ;
	   }
	NumPoints =  ( i0 == ((*plgP).NumParts -1))?((*plgP).NumPoints - (*plgP).Parts[i0] ):( (*plgP).Parts[i0 +1] - (*plgP).Parts[i0] );
   Parts[0] = 0;
   for (int j = 0; j < lenarrNegNums; j++)
   {
	  int jt =  piarrNegNums[j] ;
	  int quanP = ( jt == ((*plgP).NumParts -1))?((*plgP).NumPoints - (*plgP).Parts[jt] ):( (*plgP).Parts[jt +1] - (*plgP).Parts[jt] );
	  Parts[j +1] = NumPoints;
	  NumPoints +=  quanP;
   }

	Points = NULL ;

   if(NumPoints != 0)
   {
	   Points = new TURPointXY[NumPoints];
	   if(Points == NULL)
	   {
		   ShowMessage(L"Not memory for Points") ;
		   Abort() ;
	   }
	   int quantP0 =  ( i0 == ((*plgP).NumParts -1))?((*plgP).NumPoints - (*plgP).Parts[i0] ):( (*plgP).Parts[i0 +1] - (*plgP).Parts[i0] );
	   memcpy(Points, &(*plgP).Points[(*plgP).Parts[i0]],quantP0* sizeof(TURPointXY)) ;
	   for (int j = 0; j < lenarrNegNums; j++)
		{
		int jt =  piarrNegNums[j] ;
		int quanP1 = ( jt == ((*plgP).NumParts -1))?((*plgP).NumPoints - (*plgP).Parts[jt] ):( (*plgP).Parts[jt +1] - (*plgP).Parts[jt] );
		memcpy( &Points[Parts[j + 1]],&(*plgP).Points[(*plgP).Parts[jt]],quanP1* sizeof(TURPointXY)) ;
		}

   }
   //6


 }
 // ����� ������
TURPolygon :: TURPolygon(  const int iNumPoints)

 {
   NumParts = 1 ;
   //3
   NumPoints = iNumPoints ;

	Parts = NULL;



	   Parts = new int[NumParts];
	   if(Parts == NULL)
	   {
		   ShowMessage(L"Not memory for Parts") ;
		   Abort() ;
	   }
	   Parts[0] = 0;




	Points = NULL ;


	   Points = new TURPointXY[iNumPoints];
	   if(Points == NULL)
	   {
		   ShowMessage(L"Not memory for Points") ;

	   }
 }
 // ����� ������
TURPolygon :: TURPolygon( const int iNumParts, const int iNumPoints)

 {
   NumParts = iNumParts ;
   //3
   NumPoints = iNumPoints ;

	Parts = NULL;



	   Parts = new int[NumParts];
	   if(Parts == NULL)
	   {
		   ShowMessage(L"Not memory for Parts") ;
		   Abort() ;
	   }




	Points = NULL ;



	   Points = new TURPointXY[iNumPoints];
	   if(Points == NULL)
	   {
		   ShowMessage(L"Not memory for Points") ;

	   }

 }
// ����� ������ �������� rectangle
TURPolygon ::TURPolygon(  const TURPointXY pntTopRight,const TURPointXY pntBottomLeft)
{
	NumParts =1; ;
	NumPoints =5;
	Parts = new int[1];;
	Parts[0] = 0;
	Points = new TURPointXY[NumPoints];
	Points[0] = pntTopRight;
	Points[4] = Points[0];
	Points[1] = TURPointXY(pntTopRight.X, pntBottomLeft.Y);
	Points[2] = pntBottomLeft;
	Points[3] = TURPointXY(pntBottomLeft.X, pntTopRight.Y);
}


// ��������  ���������� �� TCircle
// � ����������� �����  iNUM
TURPolygon::TURPolygon(const TCircle Circle , const int iNUM)
{
	NumParts = 1; ;
	NumPoints = iNUM +1;
	Parts = new int[1];
	Parts[0] = 0;

	Points = new TURPointXY[NumPoints];

 double valFiCur = 0. ;
 const double valDelFi = 2. * M_PI / ((double)iNUM );

 for (int i =0; i < iNUM; i++)
 {
	 Points[i].X = Circle.mR * cos(valFiCur) + Circle.mPntCentre.X ;
	 Points[i].Y = Circle.mR * sin(valFiCur) + Circle.mPntCentre.Y ;
   valFiCur += valDelFi ;
 }
 Points[iNUM ] = Points[0] ;

}


// ����� ������ �������� �� ASCII
TURPolygon::TURPolygon (wchar_t*FileName)
{
	calcPointsOfPolygonFromASCII(FileName,&NumParts,&NumPoints );
	Parts =  new int [NumParts];
	if (Parts == NULL)
	{
	ShowMessage(L" Not possuble to create Parts") ;
	Abort() ;
	}
	fillPartsOfPolygonFromASCII(FileName, NumParts,NumPoints,Parts) ;
	Points = new TURPointXY[ NumPoints ];
	if(!Points )
	{
	ShowMessage(L" Not possuble to create Points") ;
	Abort() ;
	}
	ReadPolygonFromASCII(FileName) ;
}
void TURPolygon::calcPointsOfPolygonFromASCII(wchar_t*FileName,int *quanParts
					,int *quanPoints)
{
	FILE  *fr ;

	fr=_wfopen(FileName,L"r");
	if(!fr)
	{
	ShowMessage (L"ERROR\nReadPolyLyneFromASCII for PolyLine\nFile is not opened !") ;
	return   ;
	}
	*quanParts = 0;
	char str[1000];
	while(fgets(str,1001,fr))
	{
		if ( strstr(str,"END")!= NULL ) break;
		int iPntCur = 0 ;
		while(fgets(str,1001,fr) )
		{
			if ( strstr(str,"END")!= NULL )
			{
			break ;
			}
			else iPntCur++;
		}

		*quanParts = *quanParts +1;
		*quanPoints = *quanPoints + iPntCur;

	}

	fclose(fr);
	return  ;

}
void TURPolygon::fillPartsOfPolygonFromASCII(wchar_t*FileName, const int quanParts
					,const int quanPoints,int *piarrParts)
{
  FILE  *fr ;

	 fr=_wfopen(FileName,L"r");
	 if(!fr)
	 {
	  ShowMessage (L"ERROR\nReadPolyLyneFromASCII for PolyLine\nFile is not opened !") ;
	  return   ;
	 }
		piarrParts[0] = 0;
		char str[1000];

		int iCur = 0;
		for (int i =0; i < quanParts -1 ; i++)  // ��� 03.-1.13
		{

		  fgets(str,1001,fr);
		  while(fgets(str,1001,fr) )
		  {

		   if ( strstr(str,"END") != NULL)
			{
			  fgets(str,1001,fr);
			  //iCur++;
			  piarrParts[i + 1] =  iCur++;
			  break ;
			}
			else iCur++;
		  }


		}


	  fclose(fr);
	  return  ;
}
bool TURPolygon::ReadPolygonFromASCII(wchar_t*FileName)
{
	FILE  *fr ;

	fr=_wfopen(FileName,L"r");
	if(!fr)
	{
	ShowMessage (L"ERROR\nReadPolyLyneFromASCII for PolyLine\nFile is not opened !") ;
	return  1 ;
	}
	char str[1000];
	int numPoint = 0;
	for (int i = 0; i < NumParts; i++)
	{


		fgets(str,1001,fr);

		int StartInd = Parts[i] ;
		int EndInd = NumPoints ;
		if(i < NumParts-1) EndInd = Parts[i+1] ;
		for(int j = StartInd; j < EndInd; j++)
		{
			fgets(str,1001,fr);

			char *pstr = str;
			while(pstr[0] == ' ')pstr++;

			char str1[1000];
			char *pstr1  = strchr(pstr,' ');
			pstr1[0] = 0;
			Points[ numPoint ].X = atof(pstr);

			pstr1++;
			char *pstr2  = strchr(pstr1,' ');
			pstr2[0] = 0 ;
			pstr2++;
			Points[ numPoint ].Y = atof(pstr1);
			pstr2[strlen(pstr2)-1] = 0;
			numPoint++;
		}

		fgets(str,1001,fr);

	}

	fclose(fr);
	return true ;


}

 // �������   �����
 // ���������� true ���� ����� v ��������� ������ ������ �������� � false � �������� ������

bool TURPolygon::PtInPlygon( TURPointXY v) // ���������� � �������� ������� FillPolygon 21/12/2012
{
	 int icount_pl = 0,icount_mn = 0,i=0;
	 int icount_rightVert = 0;
	 int icount_leftVert = 0;
	double x0 = -10000000.;

	 for (int numP = 0; numP < NumParts; numP++)
	 {
		TURPointXY *pVertPoints = &Points[Parts[numP]];
		int quantVert;
		if( (numP + 1) == NumParts)
		{
			quantVert = NumPoints - Parts[numP];
		}
		else
		{
		  quantVert = Parts[numP +1] - Parts[numP ];
		}


	   for (i=0; i < (quantVert -1) ;++i)
		{


			 if (fabs(pVertPoints[i].Y -v.Y ) < TOLRNC)
			 {
			   if ( (pVertPoints[i].X - TOLRNC ) > v.X)
			   {
			   icount_pl++;
			   icount_rightVert++;
			   continue;
			   }
				else
					if ((pVertPoints[i].X + TOLRNC ) < v.X)
					{
					icount_mn++;
					icount_leftVert++;
					continue;
					}
					else return false ;  // ����� ��������� � ��������

			 }
			 if (fabs(pVertPoints[i +1 ].Y -v.Y ) < TOLRNC)
			 {
			   if ( (pVertPoints[i + 1].X - TOLRNC ) > v.X)
			   {
			   icount_pl++;
			   icount_rightVert++;
			   continue;
			   }
				else
					if ((pVertPoints[i +1].X + TOLRNC ) < v.X)
					{
					icount_mn++;
					icount_leftVert++;
					continue;
					}
					else return false ;  // ����� ��������� � ��������

			 }


			if ( TURPolygon::HorizCutSegment(pVertPoints[i].X, pVertPoints[i].Y,pVertPoints[i +1].X
			, pVertPoints[i +1].Y, v.Y, x0))

			{
				if ( (x0 - TOLRNC) > v.X)icount_pl++;
				else
					if ( (x0 + TOLRNC) < v.X) icount_mn++;
					else return false ; // ����� �� �����

			}
		}


	 }
	 icount_pl = icount_pl -  icount_rightVert/2;
	 icount_mn = icount_mn - icount_leftVert /2;

	 if (icount_pl >0 )
	{
		if(icount_pl%2 == 1) return true;
		else return false;
	}
	else
	{
		if( icount_mn > 0)
		{

			if(icount_mn%2 == 1) return true;
			else return false;
		}
		else
			return false;
	}
}
// ����������:
// 0 - ����� ��� ��������
// 1 - ����� � ����� ��������
// 3  - ����� p0  ����� �� ����� ��������
// 4  - �����  p0  �������� �������� ��������

int TURPolygon::PntInPolygon( TURPointXY v ) // NEW 21.12.2012
{
	 int  i=0;
	 int icount_rightIntersects = 0;
	 int icount_leftIntersects = 0;
	double x0 = -10000000.;

	 for (int numP = 0; numP < NumParts; numP++)
	 {
		TURPointXY *pVertPoints = &Points[Parts[numP]];
		int quantVert;
		if( (numP + 1) == NumParts)
		{
			quantVert = NumPoints - Parts[numP];
		}
		else
		{
		  quantVert = Parts[numP +1] - Parts[numP ];
		}

	 // ���� pVertPoints[0] ����� �� �����������
		int iBegin = 0;
		int iEnd = (quantVert -1) ;
		if (fabs(pVertPoints[0].Y -v.Y ) < TOLRNC)
		{

			//����� ������ ������� ����� �� ������� �������, �� ������� �� �����������
			for ( iBegin = 1; iBegin < (quantVert -1);  iBegin++)
			{
			  if (fabs(pVertPoints[iBegin].Y -v.Y ) < TOLRNC)
			  {
				  if ((v.X - pVertPoints[iBegin -1].X) * (v.X - pVertPoints[iBegin ].X) < -TOLRNC)
				  {
					return 3;
				  }
				  if (fabs((v.X - pVertPoints[iBegin -1].X) * (v.X - pVertPoints[iBegin ].X)) < TOLRNC)
				  {
					return 4;
				  }

			  }
			  else
			  {
				  break ;
			  }
			}
			///

				//����� ������ ������� ����� ������ ������� ������� , �� ������� �� �����������
				int j = 0;
			for ( j = (quantVert -2); j > 0;  j--)
			{
			  if (fabs(pVertPoints[j].Y -v.Y ) < TOLRNC)
			  {
				  if ((v.X - pVertPoints[j + 1].X) * (v.X - pVertPoints[j ].X) < -TOLRNC)
				  {
					return 3;
				  }
				  if (fabs((v.X - pVertPoints[j + 1].X) * (v.X - pVertPoints[j].X)) < TOLRNC)
				  {
					return 4;
				  }

			  }
			  else
			  {
                  iEnd =  j ;
				  break ;
			  }
			}
			///
		  if ((fncSIGN_(pVertPoints[iEnd].Y -v.Y ) != (fncSIGN_(pVertPoints[iBegin].Y -v.Y )) ) )
		  {
			 if (pVertPoints[iEnd].X > v.X)
			 {
				icount_rightIntersects++;
			 }
			 else
			 {
			   icount_leftIntersects++;
			 }

		  }

		}

	 ///  ����� � ����������

	   for (i= iBegin; i < iEnd  ; i++)
		{
			// ��������� ������, ����� ������� pVertPoints[i] ����� �� �����������
			if (fabs(pVertPoints[i].Y -v.Y ) < TOLRNC)
			{
			if (fabs(pVertPoints[i].X -v.X ) < TOLRNC)
			{
			 return 4;
			}
			int iTemp = i + 1 ;

			for ( iTemp = (i + 1); iTemp < iEnd;  iTemp++)
			{


			  if (fabs(pVertPoints[iTemp].Y -v.Y ) < TOLRNC)
			  {

				  if ((v.X - pVertPoints[iTemp -1].X) * (v.X - pVertPoints[iTemp ].X) < -TOLRNC)
				  {
					return 3;
				  }
				  if (fabs((v.X - pVertPoints[iTemp -1].X) * (v.X - pVertPoints[iTemp ].X)) < TOLRNC)
				  {
					return 4;
				  }

			  }
			  else
			  {

				  break ;
			  }
			}
			///

			if ( fncSIGN_(pVertPoints[i -1].Y -v.Y ) != fncSIGN_(pVertPoints[iTemp].Y -v.Y ))
			{


				if (fabs( v.Y - pVertPoints[iTemp].Y) > TOLRNC)
				{
				if ( (pVertPoints[i].X - TOLRNC) > v.X  )icount_rightIntersects++;
				else
					if ( (pVertPoints[i].X + TOLRNC) < v.X ) icount_leftIntersects++;
					else return 3 ; // ����� �� �����
				}

			}
			i = iTemp -1 ;
			continue ;
		   }
		   /// ����� ���������

		  if ( TURPolygon::HorizCutSegment(pVertPoints[i].X, pVertPoints[i].Y,pVertPoints[i +1].X
			, pVertPoints[i +1].Y, v.Y, x0))

			{
				if (fabs( v.Y - pVertPoints[i +1].Y) > TOLRNC)
				{
				if ( (x0 - TOLRNC) > v.X)icount_rightIntersects++;
				else
					if ( (x0 + TOLRNC) < v.X) icount_leftIntersects++;
					else return 3 ; // ����� �� �����
				}

			}

		 }
		}
		   if (icount_rightIntersects > 0)
		   {
			   if ((icount_rightIntersects %2)== 0 )
			   {
			   return 0;
			   }
			   else
			   {
			   return 1;
			   }
		   }

		   if (icount_leftIntersects > 0)
		   {
			   if ((icount_leftIntersects %2)== 0 )
			   {
			   return 0;
			   }
			   else
			   {
			   return 1;
			   }
		   }

		   return 0;

}


bool TURPolygon::HorizCutSegment(const double x1,const double y1,const double x2,const double y2, // �������
							const double y0,double &x0 // ����������� y0
								)

{
	x0=-1000000000.;
	if((y1-y0)*(y2-y0) > 0.){ return false;}
	if (fabs(y1-y0)< TOLRNC) {x0= x1; return true;}
	if (fabs(y2-y0)< TOLRNC) {x0= x2; return true;}
	if (fabs(x1 - x2)< TOLRNC) {x0= x2;
	return true;}
	x0 = (y0 - y1)*(x2 - x1)/(y2-y1) + x1;
	return true;
}

// ����������� ����� � �������(��������)
// ����������:
// 0 - �� ����������
// 1 - ����������
// 2  - ������ �������� ����� ������� ��������
// 3  - ����� p0,    ����� ������ ��������
// 4  - �����  p0  �������� �������� ��������
// 5  - ������� ����� �� �����
int TURPolygon::LineCutSegment(const TURPointXY p1, const TURPointXY p2// �������
							,const TURPointXY p0,const double k0 // ������ k0 - ������� �������
							,TURPointXY &pCut // ����� �����������
								)

{
	TTriang  tTr(p0,p1,p2);

	if ( fabs(p1.X - p2.X) <= TOLRNC) // �������  ������������
	{
		if (fabs( p0.X - p1.X) <= TOLRNC)
		{
		  double miny = min_d(p1.Y,p2.Y);
		  double maxy = max_d(p1.Y,p2.Y);
		  double a = maxy - miny;
		  double b = p0.Y - miny;
		  switch (PntInSegment( a,b))
		  {
		   case 0: // p0 ����� ������ ��������
			pCut = p0;
			return 3;

		   case 1:   // �������� ����� �������
		   pCut = p0;
		   return 2;

		   case 2:    // �������� ����� �������
		   pCut = p0;
		   return 2;

		   case 3:
		   return 0 ;  // �� ����������

		  default:
		   break;
              ;
		  }
		}
		else
		{
		pCut.X = p1.X;
		pCut.Y = p0.Y + ( p1.X - p0.X ) * k0;
		double miny = min_d(p1.Y,p2.Y);
		double maxy = max_d(p1.Y,p2.Y);
		double a = maxy - miny;
		double b = pCut.Y - miny;
	    switch (PntInSegment( a,b))
		  {
		   case 0: // ���������� �� ����� �����
		   return 1;

		   case 1:  // �������� ����� �������
		   return 2;

		   case 2:  // �������� ����� �������
		   return 2;

		   case 3:
		   return 0 ; // �� ����������

		  default:
		   break;
              ;
		  }
		}
   }
  else // ������� �� ������������
  {
	  double alf0 = atan(k0);
	  double k1 = (p2.Y - p1.Y)/ (p2.X - p1.X) ;
	  if(fabs( k1 - k0) <= TOLRNC) //���� ������� ���������
	  {
		 // double alf1 = atan( (p1.Y -p0.Y)/ (p1.X -p0.X));
		 // if ( dist(p0,p1) * sin(fabs(alf1 - alf0))<= TOLRNC) return 5 ; //����� �������� ����� �������
		  if (fabs(tTr.calcSq()) <= 0.5 * TOLRNC * dist(p1,p2))
		  {
		  return 5 ;   //������ �������� ����� p1, p2 ���������� ������
		  }
		  else return 0; // �� ����������. ������ ����������� ��������
	  }
	  else
	  {
		pCut.X = (p1.Y - k1*p1.X + p0.X * k0 - p0.Y)/(k0- k1);
		pCut.Y =  p0.Y + ( pCut.X - p0.X) * k0 ;

		const double tol =  TOLRNC * cos(alf0);
		if (
			 (pCut.X <=  (max_d(p1.X,p2.X) - tol) )
		   &&(pCut.X >= (min_d(p1.X,p2.X) + tol))
			)
			{
			  if(dist(pCut,p0) <=  TOLRNC) return 3;
			  else  return 1 ;//  ����������
			}
		if (
			  (pCut.X > (max_d(p1.X,p2.X) + tol))
			||(pCut.X < (min_d(p1.X,p2.X) - tol))
			) return 0;// �� ����������
		 else
		 {
			 if(dist(pCut,p0) <=  TOLRNC) return 4; // �������� ��������
			 else
			  return 2;  //�������� ����� �������
         }


      }
	}
	return -1;
}

// ����������� ����� (��������������� �������)� �������(��������)
// ����������:
// 0 - �� ����������
// 1 - ����������
// 2  - ������ �������� ����� ������� ��������
// 3  - ����� p0,    ����� ������ ��������
// 4  - �����  p0  �������� �������� ��������
// 5  - ������� ����� �� �����
int TURPolygon::ParametricLineCutSegment( TURPointXY p1,  TURPointXY p2// �������
							, TURPointXY p0, double *arrV //
							,TURPointXY &pCut // ����� �����������
								)

{


	if ( fabs(arrV[0]) <= TOLRNC) // ����� ��������������
	{
	  //�������� � �� ���������� �� ��./2
	   TURPointXY p1_new,  p2_new// �������
							, p0_new  //
							,pCut_new ;
	   double arrV_new [2] = {0.} ;
	   // ������� ��������
	   double arrMtxPer [4] = {0.,1.,-1.,0.};
	   p1_new = p1.fncLinTrasform( arrMtxPer);
	   p2_new = p2.fncLinTrasform( arrMtxPer);
	   p0_new = p0.fncLinTrasform( arrMtxPer);
	   MtrxMultMatrx(arrMtxPer,2, 2, arrV,1, arrV_new) ;
	   double k0 = arrV_new [1]/ arrV_new [0];
	   int iReturn =  LineCutSegment(p1_new,  p2_new// �������
							, p0_new, k0 // ������ k0 - ������� �������
							,pCut_new // ����� �����������
								);
	  arrMtxPer [1] = -1.;
	  arrMtxPer [2] = 1.;
	  pCut = pCut_new.fncLinTrasform( arrMtxPer);
	  return iReturn ;
	}
   else // ����� �� ������������
   {
	 double k0 = arrV [1]/ arrV [0];
	 return LineCutSegment(p1,  p2// �������
							, p0, k0 // ������ k0 - ������� �������
							,pCut // ����� �����������
								);
  }
}
 //����� � � ������� [0;a]
// ����������
// 0 - ���� � ��������
// 1 - ���� x == 0
// 2- ���� x == 1
// 3 - ���� �� ����������� ��������
int TURPolygon::PntInSegment(double a,double x)
{
   double b =  (x+TOLRNC)*(x-a -TOLRNC);
  if(b > 0)return 3;
  else
	if ( (x - TOLRNC)*(x-a + TOLRNC)< 0 ) return 0;
	else
	  if (fabs(x) < TOLRNC) return 1;
	  else return 2;
}

double TURPolygon::calcVectSq()
{
 double sum = 0;
	for (int n= 0; n < NumParts; n++)
	{
	   sum +=   calcPartSq(n);
	}
	return sum;
}

double TURPolygon::calcPartSq(const int n)
{
	if (n >= NumParts)
	{
	   ShowMessage(L"Error calcPartSq: n >= NumParts");
	   Abort() ;
	}
	TURPointXY *pPXY = (TURPointXY *)&Points [Parts[n]];
	int quanP = ( n == (NumParts -1))?(NumPoints - Parts[n] ):( Parts[n +1] - Parts[n] );
	double S =0 ;
	for (int i =0; i < (quanP - 1); i++)
	{
	   S = S + TURPointXY::calcVectS(pPXY[i],pPXY[i + 1]);
	}
	return -S;

}
double TURPolygon::calcLeng()
{
 double sum = 0;
	for (int n= 0; n < NumParts; n++)
	{
	   sum +=   calcPartLeng(n);
	}
	return sum;
}

double TURPolygon::calcPartLeng(const int n)
{
	if (n >= NumParts)
	{
	   ShowMessage(L"Error calcPartSq: n >= NumParts");
	   Abort() ;
	}
	TURPointXY *pPXY = (TURPointXY *)&Points [Parts[n]];
	int quanP = ( n == (NumParts -1))?(NumPoints - Parts[n] ):( Parts[n +1] - Parts[n] );
	double S =0 ;
	for (int i =0; i < (quanP - 1); i++)
	{

	   S = S + dist(&pPXY[i],&pPXY[i + 1]);
	}
	return S;

}
double TURPolygon::dist(TURPointXY*p0, TURPointXY*p1)
{
  return sqrt(((*p0).X -(*p1).X) * ((*p0).X -(*p1).X) + ((*p0).Y -(*p1).Y) * ((*p0).Y -(*p1).Y)) ;
}
void TURPolygon::calcBoundBox()
{
	 double xMin = 1000000000 ;
	 double xMax = -1000000000 ;
	 double yMin =  1000000000 ;
	 double yMax =  - 1000000000 ;
	 for (int i =0; i < NumPoints; i++)
	 {
	   if (Points[i].X > xMax) xMax =  Points[i].X;
	   if (Points[i].X < xMin) xMin =  Points[i].X;
	   if (Points[i].Y > yMax) yMax =  Points[i].Y;
	   if (Points[i].Y < yMin) yMin =  Points[i].Y;

	 }
	Box[0] =  xMin;
	Box[1] =  yMin;
	Box[2] =  xMax ;
	//Box[3] =  yMax;
	//Box[3] =  yMax;
	Box[3] =  yMax;

}
void TURPolygon::getExtent(double &xmin0,double &xmax0,double &ymin0,double &ymax0)
{
  calcBoundBox();
  xmin0 = Box[0];
  xmax0 = Box[2];
  ymin0 = Box[1];
  ymax0 = Box[3];
}

int  TURPolygon::WriteToASCII(wchar_t*FileName)

 // TURPolygonZ L( *this) ;
 // L.WriteToASCII(FileName) ;
 // ������  �  ���� ������� ASCII
// PolyLineZ
/*{
Double[4] Box // Bounding Box
Integer NumParts // Number of Parts
Integer NumPoints // Total Number of Points
Integer[NumParts] Parts // Index to First Point in Part
Point[NumPoints] Points // Points for All Parts
Double[2] Z Range // Bounding Z Range
Double[NumPoints] Z Array // Z Values for All Points
Double[2] M Range // Bounding Measure Range
Double[NumPoints] M Array // Measures
}
The fields for a PolyLineZ are described in detail below:
Box The Bounding Box for the PolyLineZ stored in the order Xmin, Ymin,
Xmax, Ymax.
NumParts The number of parts in the PolyLineZ.
NumPoints The total number of points for all parts.
Parts An array of length NumParts. Stores, for each part, the index of its first
point in the points array. Array indexes are with respect to 0.
Points An array of length NumPoints. The points for each part in the PolyLineZ
are stored end to end. The points for Part 2 follow the points for Part 1, and
so on. The parts array holds the array index of the starting point for each
part. There is no delimiter in the points array between parts.
Z Range The minimum and maximum Z values for the PolyLineZ stored in the order
Zmin, Zmax.
Z Array An array of length NumPoints. The Z values for each part in the PolyLineZ
are stored end to end. The Z values for Part 2 follow the Z values for Part 1,
and so on. The parts array holds the array index of the starting point for
each part. There is no delimiter in the Z array between parts.
M Range The minimum and maximum measures for the PolyLineZ stored in the order
Mmin, Mmax.
M Array An array of length NumPoints. The measures for each part in the PolyLineZ
are stored end to end. The measures for Part 2 follow the measures for Part*/
{



    FILE  *fw ;

	 fw=_wfopen(FileName,L"w");
	 if(!fw)
	 {
	  ShowMessage (L"ERROR\nWriteToASCII for PolyLine\nFile is not opened !") ;
	  return  1 ;
	 }
	const double valZ = 0;

	 for (int i = 0; i < NumParts; i++)
	 {


		fprintf(fw,"%i\n", 1) ;

		int StartInd = Parts[i] ;
		int EndInd = (i == (NumParts -1))?NumPoints : Parts[i +1] ;

		for(int j = StartInd; j < EndInd; j++)
		{
		   if( !fprintf(fw,"%f %f %f\n", Points[j].X,Points[j].Y,valZ)) return 2 ;
		}

	   fprintf(fw,"END\n") ;
	 }

	 fprintf(fw,"END\n") ;
	 fclose(fw);


	return 0 ;

}


int  TURPolygon::WriteToASCII__(wchar_t*FileName)

 // TURPolygonZ L( *this) ;
 // L.WriteToASCII(FileName) ;
 // ������  �  ���� ������� ASCII
// PolyLineZ
/*{
Double[4] Box // Bounding Box
Integer NumParts // Number of Parts
Integer NumPoints // Total Number of Points
Integer[NumParts] Parts // Index to First Point in Part
Point[NumPoints] Points // Points for All Parts
Double[2] Z Range // Bounding Z Range
Double[NumPoints] Z Array // Z Values for All Points
Double[2] M Range // Bounding Measure Range
Double[NumPoints] M Array // Measures
}
The fields for a PolyLineZ are described in detail below:
Box The Bounding Box for the PolyLineZ stored in the order Xmin, Ymin,
Xmax, Ymax.
NumParts The number of parts in the PolyLineZ.
NumPoints The total number of points for all parts.
Parts An array of length NumParts. Stores, for each part, the index of its first
point in the points array. Array indexes are with respect to 0.
Points An array of length NumPoints. The points for each part in the PolyLineZ
are stored end to end. The points for Part 2 follow the points for Part 1, and
so on. The parts array holds the array index of the starting point for each
part. There is no delimiter in the points array between parts.
Z Range The minimum and maximum Z values for the PolyLineZ stored in the order
Zmin, Zmax.
Z Array An array of length NumPoints. The Z values for each part in the PolyLineZ
are stored end to end. The Z values for Part 2 follow the Z values for Part 1,
and so on. The parts array holds the array index of the starting point for
each part. There is no delimiter in the Z array between parts.
M Range The minimum and maximum measures for the PolyLineZ stored in the order
Mmin, Mmax.
M Array An array of length NumPoints. The measures for each part in the PolyLineZ
are stored end to end. The measures for Part 2 follow the measures for Part*/
{



    FILE  *fw ;

	 fw=_wfopen(FileName,L"w");
	 if(!fw)
	 {
	  ShowMessage (L"ERROR\nWriteToASCII for PolyLine\nFile is not opened !") ;
	  return  1 ;
	 }

	  fprintf(fw," %i  \n", NumParts) ;
	  fprintf(fw," %i  \n\n", NumPoints);

	  fprintf(fw,"%f %c %f \n", Points[0].X,L',',Points[0].Y) ;

	  for (int i = 1; i < NumPoints; i++)
	  {
		  fprintf(fw,"%c %f %c %f\n",',', Points[i].X,',',Points[i].Y) ;
	  }
	  fprintf(fw," \n\n", "};"  );

	  ///


	  fprintf(fw,"%i  \n", Parts[0]) ;

	  for (int i = 1; i < NumParts; i++)
	  {
		  fprintf(fw,"%c %i \n", ',',Parts[i]) ;
	  }


	 fclose(fw);


	return 0 ;

}

	//����������� ���������
	TURPolygon 	 TURPolygon::InterSectPlg(TURPolygon &urplgP1,TURPolygon &urplgP2)
	{
	 int lenArrTr1 = 1000 ;
	 TTriang *parrTr1 = (TTriang *)malloc(lenArrTr1 *sizeof(TTriang));
	 int quantTr1 = 0 ;
	 urplgP1.DisassemblePlg(&parrTr1,&quantTr1) ;

	 int lenArrTr2 = 1000 ;
	  TTriang *parrTr2 = (TTriang *)malloc(lenArrTr2 *sizeof(TTriang));
	 int quantTr2 = 0 ;
	 urplgP1.DisassemblePlg(&parrTr2,&quantTr2) ;

	 int lenArrOutTr = 1000 ;
	 TTriang *parrOutTr = (TTriang *)malloc(lenArrOutTr *sizeof(TTriang));
	 int quantOutTr = 0 ;

	 InterSectArrPlg( quantTr1,parrTr1, quantTr2,parrTr2,
		  quantOutTr,parrOutTr) ;
	 free(parrTr2);
	 free(parrTr1);

	 int lenPlgArr =100;
	TURPolygon *pPlgRez = (TURPolygon *)malloc(lenPlgArr * sizeof(TURPolygon));
	TURPolygon **ppPlgRez = &pPlgRez;
	TTriang  **pparrOutTr = &parrOutTr;
	AssemblePlgFromTriangleArr_1(pparrOutTr ,quantOutTr,ppPlgRez,&lenPlgArr) ;

	TURPolygon normalPlg =  NormalizePolygon(*ppPlgRez,lenPlgArr) ;

	free( parrOutTr );
	free(pPlgRez);
	return normalPlg ;
	}

	// ����������� ���������
	TURPolygon 	 TURPolygon::UnitePlg(TURPolygon &urplgP1,TURPolygon &urplgP2)
	{
	return  TURPolygon (3) ;
	}

	// ��������� �� �������� P0 ������� P1
	TURPolygon 	 TURPolygon::PlgMinusPlg(TURPolygon &urplgP0,TURPolygon &urplgP1)
	{


	int quantTr0 = 100;
	TTriang *pTr0 = (TTriang *)malloc(quantTr0 * sizeof(TTriang));
	TTriang **ppTr0 = &pTr0;
	int quantTr1 = 100;
	TTriang *pTr1 = (TTriang *)malloc(quantTr1 * sizeof(TTriang));
	TTriang **ppTr1 = &pTr1;
	int lenArrTrRez = 100;
	TTriang *pTrRez = (TTriang *)malloc(lenArrTrRez * sizeof(TTriang));
	TTriang **ppTrRez = &pTrRez;
	urplgP0.DisassemblePlg(ppTr0,&quantTr0) ;
	urplgP1.DisassemblePlg(ppTr1,&quantTr1) ;



	//������������ *ppTr0 ������ ���� �������������, a *ppTr1 �������������
	// ���������  ��������������� ������������� *ppTr1
	//� ���� ��� ������������� - ��������� ����������� ������ � ������� �� ���
	 if (quantTr1 > 0)
	 {
		if (pTr1[0].calcSq()> 0)
		{
		   for (int i =0; i < quantTr1; i++)
		   {
			  pTr1[i].ChangeDir();
		   }
		}
	 }
	TriangleArrMinusTriangleArr( pTr0,quantTr0,pTr1,quantTr1, ppTrRez,&lenArrTrRez);

	TTriang::FinishDisassembleTriangleArr(ppTrRez,&lenArrTrRez);

	int lenPlgArr =100;
	TURPolygon *pPlgRez = (TURPolygon *)malloc(lenPlgArr * sizeof(TURPolygon));
	TURPolygon **ppPlgRez = &pPlgRez;
	AssemblePlgFromTriangleArr_1(ppTrRez,lenArrTrRez,ppPlgRez,&lenPlgArr) ;


	TURPolygon normalPlg =  NormalizePolygon(*ppPlgRez,lenPlgArr) ;


	free(pPlgRez);
	delete [] pTr0;
	delete [] pTr1;
	delete [] pTrRez;
	return  normalPlg ;

	}

// ��������� �������� ��  ������ ���������������� ������������� �������������
// ��������� ������ bool *barrPartInPart ������������ ��������� ����� � ������� i � ����� � ������� j
// ����� ������������ ��� ������������� ����� � ��� ������ �� ��� ��������� ������� �������
// ������� ����������� �� �������������
// ���������� �������������� � ������  (*pparrTr)[]
void TURPolygon::DisassemblePlg( TTriang **pparrTr //��������� �� ��������� �� ������ ������������� ������� quantTr
								 ,int *quantTr  //  �� ����� � ������� ���������� ����� ����������������� ������ ��� ������ *pparrTr
												// �� ������ ����� �������  *pparrTr
								 //, const int lenArrTr // ���������� �������� ����������������� ������ parrTr
								)
	{
//    �������� ������� barrPartInPart
	  int *piarrNegNums = new int [NumParts];
	   // barrPartInPart[i,j] = true ���� i ������ j
	   bool *barrPartInPart = new bool [NumParts * NumParts];
	   for (int i  = 0; i  < NumParts; i++)
	   for (int j =  0; j <  NumParts; j++)
	   {
		  if (i == j)
		  {
			 barrPartInPart[ i *NumParts + j] = true;
			 continue;
		  }
		  barrPartInPart[ i *NumParts + j] = IsPartIncludedInPart(i,j);

	   }
///
	   int lenMemory = *quantTr;
	   int  quantTrCurrent = 0;

	  TURPolygon tmpPlg  ( NumParts,NumPoints,Parts ,Points) ;// ����� �������� this
// ���������� "�������" ���������, ��������� �� �� ������������ � ����������� � ������� (*pparrTr)[]
	  for (int i = 0; i < NumParts; i++)
	  {
// ������� ������� ���������� � �������������� �����
// ��� ������� �������������� ����� �������� ������� �������
		 if (calcPartSq(i) <= 0)  continue ;
// ����� ������������� ������ �������� � ���� i (�������� FillArrayNegNums, �������� � ���� i )
		 int lenarrNegNums = -1;
		  FillArrayNegNums(i,piarrNegNums,&lenarrNegNums, barrPartInPart);
// �������� �������� ��������
		  TURPolygon plgSimple(&tmpPlg ,i,piarrNegNums,lenarrNegNums);
// ��������� �������� �������� �� ������������ � ����������� �� � ������� (*parrTrTemp)[]
// ������ lenArrTrTemp
		  int lenArrTrTemp = 1000;
		   TTriang *parrTrTemp = (TTriang *)malloc(lenArrTrTemp* sizeof(TTriang ));
		   TTriang **pparrTrTemp = &parrTrTemp;

	   //	  plgSimple.WriteToASCII( L"D:\\GeoProcC++\\FILES\\plgSimple.txt"); // ��� �������

		  plgSimple.DisassembleSimplePlg(pparrTrTemp, &lenArrTrTemp);

		//   TURPolygon  plgTrianglesCurr( lenArrTrTemp ,parrTrTemp); // ��� �������
		//  plgTrianglesCurr.WriteToASCII( L"D:\\GeoProcC++\\FILES\\plgTrianglesCurr.txt");  // ��� �������
 // ��������� ������ ����������������� ������ ��� ������  (*parrTrTemp)[]
		  if ( (quantTrCurrent + lenArrTrTemp) > lenMemory)
		  {

		*pparrTr = (TTriang *)realloc(*pparrTr, ((quantTrCurrent + lenArrTrTemp)/1000 + 1) * 1000* sizeof(TTriang));

			lenMemory = ((quantTrCurrent + lenArrTrTemp)/1000 + 1) * 1000;
		  }
//  ���������� ������� �������������, ����������� � ���������� ��������� �������� ��������, � ������  (*parrTrTemp)[]
		  TTriang * parrTr = *pparrTr ;
		  memcpy( &parrTr[quantTrCurrent],parrTrTemp, lenArrTrTemp * sizeof(TTriang));
		  quantTrCurrent += lenArrTrTemp ;
		  if (parrTrTemp) free(parrTrTemp);



	  }
	  *quantTr =  quantTrCurrent ;
	  (*pparrTr) =(TTriang*) realloc(*pparrTr, (*quantTr)* sizeof(TTriang));
	  delete [] piarrNegNums;
	  delete [] barrPartInPart;

  }
  // ���� Part[i] ������  Part[j] ���������� trtue, ����� false
 bool TURPolygon::IsPartIncludedInPart(const int i,const int  j)
 {
		int quanP = ( j == (NumParts -1))?(NumPoints - Parts[j] ):( Parts[j +1] - Parts[j] );
		TURPolygon Ring (  quanP, &Points[Parts[j]]);
		int i0 = Ring.PntInPolygon(Points[Parts[i]]);
		int i1 = Ring.PntInPolygon(Points[Parts[i] + 1]);
	 // return	( Ring.PntInPolygon(Points[Parts[j]]) * Ring.PntInPolygon(Points[Parts[j] + 1]) >0 )?true:false;
	  return	( i0 * i1 >0 )?true:false;


 }
 void TURPolygon::FillArrayNegNums(const int num0,int *piarrNegNums,int *lenarrNegNums,bool *barrPartInPart)
 {

	  *lenarrNegNums = 0;
	 int numTemp = 0;
	  bool *pbarrUsed = new bool [NumParts];
	  memset(pbarrUsed,0, NumParts * sizeof(bool)) ;
	 for (int i = 0; i < NumParts; i++)
	 {
		 if (i == num0)  continue ;
		 if (calcPartSq(i) >= 0)
		 {
		 pbarrUsed[i] = true ;
		  continue;
		 }
		 if (pbarrUsed[i]) continue;
		 if(!barrPartInPart[i * NumParts + num0]) continue;
		 else
		 {
			 bool bSuit = true;
			for (int j = 0; j < NumParts; j++)
			{
			  if (j == i)continue;

			  if ( !barrPartInPart[i* NumParts +j]) continue;
			 //  if ( barrPartInPart[i,j] && (! barrPartInPart[num0,j]))
			  if (  barrPartInPart[num0 * NumParts + j] )continue;
			  else

			   {
				bSuit  = false;
				break;
			   }

			}
			if (!bSuit) continue;
			else
			{
			 piarrNegNums [numTemp] = i;
			 pbarrUsed[i] = true;
			 numTemp ++;
			}
		 }
	 }
	 *lenarrNegNums = numTemp;
	 delete [] pbarrUsed ;
 }

 // ��������� "��������" �������� �� ���������������� ������������� ������������
 // ������� ���������� �������, ������� ������ �� ������ ��������������� ����� � ���������� �������������
 // ������, ������� ������ ���� ����������� ������� � ���� ������������ ������������� ����
 // **ppTrRez - ����� ������ (���������) � �������� �������� ��������� �� ������ �������������� �������������
 void TURPolygon::DisassembleSimplePlg(TTriang **ppTrRez, int *lenArrTr)
 {

	// ��������� �������� �� ������
	int quanP = ( 0 == (NumParts -1))?NumPoints :( Parts[1] - Parts[0] );
	TURPolygon urplgRing0 (quanP,Points) ;
	TURPolygon *urplgRings = NULL;
	if (NumParts > 1)
	{

		urplgRings = new TURPolygon[NumParts -1] ;
		for (int n = 1; n < NumParts; n++)
		{
		int quanP = ( n == (NumParts -1))?(NumPoints - Parts[n] ):( Parts[n +1] - Parts[n] );
		urplgRings[n-1] = TURPolygon (  quanP, &Points[Parts[n]]);
		}
	}
	const int quantNegPlg = NumParts -1 ;
	// ������ ������ ����������� �� ������������ ������������, ������� ������������ � ������ parrTrGen

	TTriang *parrTrNeg = new TTriang [ NumPoints - urplgRing0.NumPoints - (NumParts-1) *3 ]; 	int quantTrNeg = 0;

	for (int i = 0 ; i < quantNegPlg; i++)
	{

	urplgRings[i].TriangulateRing(&parrTrNeg[quantTrNeg]);
	quantTrNeg += urplgRings[i].NumPoints -3 ;

	}
	//
	int quantTrPosit = urplgRing0.NumPoints - 3;// ������� ����� ������� pTrRez


	TTriang * parrTrPosit = new TTriang[ quantTrPosit];


	urplgRing0.TriangulateRing(parrTrPosit);

	// ��� �������
   //	TURPolygon urplgRing0_Triang ( quantTrPosit,parrTrPosit);
   //	urplgRing0_Triang.WriteToASCII(L"D:\\GeoProcC++\\FILES\\urplgRing0_Triang.txt");
	///


	TriangleArrMinusTriangleArr(parrTrPosit,quantTrPosit,parrTrNeg,quantTrNeg
											   ,ppTrRez, lenArrTr);
	*ppTrRez = (TTriang*)realloc( *ppTrRez,  (*lenArrTr) * sizeof(TTriang));
   //	*lenArrTr = lenArrTrTemp ;
	delete [] parrTrPosit;
	delete [] parrTrNeg;
	if (urplgRings != NULL) delete [] urplgRings ;

	}

	//  ��������� ������ �� ������������
   bool TURPolygon::TriangulateRing(TTriang *parrTr)
   {
	  if (NumParts != 1)   return false;
	  const int iSignPlgSq =  (calcPartSq(0) > 0) ?1:-1;

	  TURPolygon tempRing ( NumParts,NumPoints,Parts ,Points) ;
	  for (int i = 0; i < NumPoints -4; i++)
	  {
		 for (int j = 0; j < (tempRing.NumPoints-1); j++)
		 {
		   TTriang tTr(tempRing.Points[j],tempRing.Points[(j +1)%(tempRing.NumPoints-1)],tempRing.Points [(j + 2)% (tempRing.NumPoints-1)]);
		   if (tTr.calcSq()* iSignPlgSq <= 0 ) continue ;
		  if( tempRing.IsChordCutRing(  j)) continue ;
		   if (tTr.PntInTriangle(tempRing.Points[(j +3)%(tempRing.NumPoints-1)]) != 0)   continue;


		   parrTr [ i] = tTr;

		  tempRing = tempRing.ExcludePointFromRing((j +1)% (tempRing.NumPoints -1));
		  break ;

		 }
	  }
	   TTriang tTr(tempRing.Points[0],tempRing.Points[1],tempRing.Points[2]);
	   parrTr [ NumPoints -4] = tTr;
	   return true ;
   }
 // ����������� 2-� ������
  int TURPolygon::IntersectTwoLine( const TURPointXY p0,const  TURPointXY p1
					,const TURPointXY p2,const TURPointXY p3, TURPointXY *p)

// ����� ����� ����������� ���� ������ �� ���������
// 1-�� ������ ������ ������� p0 � p3
// 2-�� ������ ������ ������� p1 � p2
// x,y - [output]
// ���������� 0 ���� ������ �����������
//1 ���� ������������
// 2 ���� ���������
{

	 const double x0 = p0.X ;
	 const double y0 = p0.Y ;
	 const double x1 = p1.X;
	 const double y1 = p1.Y ;
	 const double x2 = p2.X ;
	 const double y2 = p2.Y ;
	 const double x3 = p3.X ;
	 const double y3 = p3.Y ;
	if( (fabs(x3 - x0)< TOLRNC) &&  (fabs(x2 - x1)< TOLRNC) )
	{
	 if (fabs(x0 - x1) < TOLRNC) return 2;
	 else return 0;
	}
		if (fabs(x3 - x0)< TOLRNC)
		{
			(*p).Y = (y2 - y1) / (x2 - x1) * (x0 - x1)+ y1;
			(*p).X = x0;
			return 1;
		}
		if (fabs(x2 - x1)< TOLRNC)
		{
			(*p).Y = (y3 - y0) / (x3 - x0) * (x1 - x0) + y0;
			(*p).X = x1;
			return 1;
		}
		double k0 =  (y3 - y0) / (x3 - x0);
		double k1 =  (y2 - y1) / (x2 - x1);
		if (fabs((y3 - y0) *(x2 - x1) - (y2 - y1) * (x3 - x0)) < TOLRNC)
		{
		  if (fabs((y3 - y0) *(x2 - x3) - (y2 - y3) * (x3 - x0)) < TOLRNC) return 2;
		  else return 0;
		}
		if (fabs(k1 - k0) < TOLRNC)
		{
		 if (fabs(y0 + k0 * ( x1 - x0) - y1) < TOLRNC) return 2;
		 else return 0 ;
		}
			(*p).X = (y1-y0 + k0 *x0 - k1 * x1) / (k0 - k1 );
			(*p).Y = y0 + k0 *( (*p).X-x0);
		return 1;

}

// ����������� 2-� ��������
//���������� true ���� ������� ������� � false � ��������� ������
//���� true: ���� ������� ����� �� ����� ������ - �� p0 -p1 - ������� �����������
// ���� �� ������� ������, �� p0 - ����� �����������, � p1 = NULL
 bool TURPolygon::IntersectTwoSegments(
					const TURPointXY p00,const  TURPointXY p01 //1-�� �������
					,const TURPointXY p10,const TURPointXY p11  // 2-�� �������
					, TURPointXY *p0  // ����� �����������
					, TURPointXY *p1  // ����� �����������
					)
{

	   TURPointXY p0Min,p0Max,p1Min,p1Max;
   switch (TURPolygon::IntersectTwoLine(  p00, p10,p11, p01, p0) )
   {
	   case 0: // �� ������������
	   p0 = NULL;
	   p1 = NULL;
	   return false ;

	   case 1:  // ������������� � ����� ����� ������ �� �����������
	   if ( !(
		   ((*p0).X <=  max_d(p00.X,p01.X) + TOLRNC  )
		&& ((*p0).X >=  min_d(p00.X,p01.X) - TOLRNC )
		&& ((*p0).X <=  max_d(p10.X,p11.X) + TOLRNC )
		&& ((*p0).X >=  min_d(p10.X,p11.X) - TOLRNC )
		))
	   {
		  p0 = NULL ;
		  return false;
	   }
	   else return true;


	   case 2: // ������ ��������� ����� ������� ���������
	   if(fabs(p00.X - p01.X) < TOLRNC)// ������ ������������
	   {
		 if( p00.Y > p01.Y)
		  {
			p0Max = p00;
			p0Min = p01;
		  }
		  else
		  {
			p0Max = p01;
			p0Min = p00;
		  }
		 if( p10.Y > p11.Y)
		  {
			p1Max = p10;
			p1Min = p11;
		  }
		  else
		  {
			p1Max = p11;
			p1Min = p10;
		  }
		  // p0 - ������� �� 2-� ����������
		  if (p0Max.Y > p1Max.Y) *p0 = p1Max;
		  else *p0 = p0Max;

		  // p1 - ������� �� 2-� ���������
		  if (p0Min.Y > p1Min.Y) *p1 = p0Min;
		  else *p1 = p1Min;

		  if ((*p0).Y > (*p1).Y) return true;
		  else
		  {
			p0 = NULL;
			p1 = NULL;
			return false;
		  }
	  }
	  else  // ������ �� ������������
	  {
		 if( p00.X > p01.X)
		  {
			p0Max = p00;
			p0Min = p01;
		  }
		  else
		  {
			p0Max = p01;
			p0Min = p00;
		  }
		 if( p10.X > p11.X)
		  {
			p1Max = p10;
			p1Min = p11;
		  }
		  else
		  {
			p1Max = p11;
			p1Min = p10;
		  }
		  // p0 - ������� �� 2-� ����������
		  if (p0Max.X > p1Max.X) *p0 = p1Max;
		  else *p0 = p0Max;

		  // p1 - ������� �� 2-� ���������
		  if (p0Min.X > p1Min.X) *p1 = p0Min;
		  else *p1 = p1Min;

		  if ((*p0).X > (*p1).X) return true;
		  else
		  {
			p0 = NULL;
			p1 = NULL;
			return false;
		  }
	  }


	  default: break;
	}
	return false; // 11-01-2017
}

// ���������� �� ����� ����������� ����� j � ������ j+2 ����� ���� �����
// ����� j, j+1, j+2, j-1
bool TURPolygon::IsChordCutRing( const int j)
{
   TURPointXY p0,p1;
   int ipCaseType ;
	for (int i = 0; i < NumPoints -1; i++)
	{
	  if (     ( i == j)
			|| ( i == (j + 1 )% (NumPoints -1) )
			|| ( i == (j + 2 )% (NumPoints -1))
			|| ( i == (j - 1 +NumPoints -1 )% (NumPoints -1))
		 ) continue;

	 // if (IntersectTwoSegments(Points [j ], Points [(j + 2)% (NumPoints-1)],Points[i],Points[(i +1)% (NumPoints-1) ],&p0,&p1 )) return true ;
	if( TTriang::IntersectTwoSegments(
				Points [j ], Points [(j + 2)% (NumPoints-1)],Points[i],Points[(i +1)% (NumPoints-1) ],&p0
					, &ipCaseType //
					) )return true ;
	}
	return false ;
}

TURPolygon TURPolygon::ExcludePointFromRing(const int numberPoint)
{
	TURPolygon rezPlg (NumPoints-1,Points);
   //	rezPlg.NumPoints = rezPlg.NumPoints -1;
	if ( (numberPoint == 0) || (numberPoint == (NumPoints- 1)) )
	{
	 for (int i =0; i < NumPoints- 1; i++) rezPlg.Points[i] = Points[i+1];
	 rezPlg.Points[ NumPoints- 2] =  rezPlg.Points[0]  ;
	 return  rezPlg;
	}
	for (int i =numberPoint; i < NumPoints- 1; i++) rezPlg.Points[i] = Points[i+1];


	  // ��� �������
	  //	rezPlg.WriteSetSHPFiles(L"D:\\PROJECTS_C++\\IMPULS\\FILES\\rezPlgIns.shp",&rezPlg, 1 );
   //	TURPointXY::WriteSetSHPFiles(L"D:\\PROJECTS_C++\\IMPULS\\FILES\\Point_rezPlgIns.shp"
  //	   ,rezPlg.Points, rezPlg.NumPoints) ;

	   ///


   /*	TURPointXY *urpntP = new TURPointXY [ NumPoints -1];
	if (numberPoint == 0)
	{
	   memcpy(urpntP,&Points[1],(NumPoints -1)* sizeof (TURPointXY));
	   urpntP[NumPoints -2] = urpntP[0];
	   TURPolygon rezPlg(NumPoints -1,urpntP);
	   delete [] urpntP;
	   return rezPlg;
	}
	memcpy(urpntP,Points,numberPoint* sizeof (TURPointXY));
	memcpy(&urpntP[numberPoint],&Points[numberPoint + 1],(NumPoints -1 - numberPoint)* sizeof (TURPointXY));
	TURPolygon rezPlg(NumPoints -1,urpntP);
	delete [] urpntP; */
	return rezPlg;
}

	// ����������� ������� ������������ parrInpTr1 � �������� parrInpTr2 � ���� ������� ����������������� �������������
	void TURPolygon::InterSectArrPlg(const int quantTr1,TTriang *parrInpTr1,const int quantTr2,TTriang *parrInpTr2,
	int &quantOutTr,TTriang *parrOutTr)
	{

	}
	double TURPolygon::dist(TURPointXY p0 ,TURPointXY p1)
	{
		return (double)sqrt( (p0.X - p1.X)*(p0.X - p1.X)+ (p0.Y - p1.Y)*(p0.Y - p1.Y)) ;
	}

void  TURPolygon::subtractEqualVerts()
 {
		bool bPr;

	 int NumPoints0 = NumPoints;
	 for (int i =0; i < NumPoints; i++)
	 {
        bPr = false ;
		for (int j =0; j < NumPoints0 -1; j++)
		{

		if (dist(Points[j + 1],Points[j ]) <= TOLRNC )
		{

		bPr = true ;
		memcpy( &Points[j + 1],&Points[j + 2],(NumPoints0 -j -1) * sizeof(TURPointXY));
		NumPoints0--;
		}
		}
        if (!bPr)
		{
		NumPoints = NumPoints0;
		break;
		}

	 }

 }
 // �� ������, ������� ������������ �� ���� �������  pTr0 ���������������� ��������������
 // ������  lenArrTr0, ���������� ������(�������) �������������� � ���� ������������������
 //������� ������������  pTr1 ������  lenArrTr1.
 // pTr0 ������� �� ������������� �������������
 // pTr1 ������� �� ������������� �������������
 // ������  *ppTrRez ���������� � ������ *ppTrRez.
 // �� �������� ����������� �������  *ppTrRez ���������� ������ ����������� �������  pTr1.
//  ����������� ��������� ������������ �� ����������� �������� ������ ������������������
 //  ���� ������ ������������ � ������ *ppTrRez � ��������� ����������� �����.
 // ������� ����������z   �� ��� ���, ���� �� ���� �� ������������ ������� *ppTrRez � ������� pTr1
 // �� ����� ������������

 void  TURPolygon::TriangleArrMinusTriangleArr(TTriang * pTr0,const int lenArrTr0
						,TTriang *pTr1,const int lenArrTr1,TTriang **ppTrRez, int *lenArrTrRez)
 {
	//
	int lenArrTrTemp = lenArrTr0;// ������� ����� ������� pTrRez
	int lenMemory =  *lenArrTrRez;
	if( lenMemory <  lenArrTr0)
	{
	lenMemory = ( (lenArrTr0 + 1000)/1000 + 1)* 1000 ;
	*ppTrRez =  ( TTriang*)realloc( *ppTrRez, lenMemory * sizeof(TTriang) );
	}
   //	int lenMemory =((urplgRing0.NumPoints - 3)+1000)/1000 *1000; //������� ������, ���������� ��� pTrRez
  //	*ppTrRez = (TTriang *)realloc(*ppTrRez,lenMemory *sizeof( TTriang));
   //	TTriang *pTrRez = *ppTrRez;
	memcpy( *ppTrRez, pTr0,lenArrTr0 * sizeof(TTriang));

	TTriang arrTrCur[6];
	int quantCur = -1;
	int iCounter = 0;

	if (lenArrTr1 > 0)
	{
		while(1)
		{
		iCounter++;
		bool bAgain = false;
		int iCounti = 0;
			for (int i = 0; i < lenArrTrTemp; i++)
			{
			iCounti++;

				for (int j = 0; j < lenArrTr1 ; j++)
				{

				TTriang ::SubTwoTrsToTrs( &((*ppTrRez)[i]), &pTr1[j], arrTrCur,quantCur ) ;


					switch(quantCur)
					{
					case 0 :  //�������� ������������
					memcpy(&((*ppTrRez)[i]),&((*ppTrRez)[i + 1]),(lenArrTrTemp -1 -i)* sizeof( TTriang));
					lenArrTrTemp --;
					bAgain = true;
					break;
					case -2 : //������������ �� ������������ - ������ �� ������
					continue;

					default:

					(*ppTrRez)[i] =  arrTrCur[0];
					if( lenMemory <  lenArrTrTemp +  quantCur)
					{
					lenMemory += 1000 ;
					*ppTrRez =  ( TTriang*)realloc( *ppTrRez, lenMemory*sizeof(TTriang) );

					}
					memcpy(&((*ppTrRez)[lenArrTrTemp ]),&arrTrCur[ 1],(quantCur -1 )* sizeof( TTriang));
					lenArrTrTemp += quantCur -1 ;

					bAgain = true;

					break;
					}
				if (bAgain) break;
				}
			if (bAgain) break;
			}
		if(!bAgain)break;
		}
	}
	*ppTrRez = (TTriang*)realloc( *ppTrRez,  lenArrTrTemp * sizeof(TTriang));
	*lenArrTrRez = lenArrTrTemp ;

   return ;
 }

 // ����� ��� ��� �������������  *ppTr  ������  quantOutTr
 // �� ���� ��������� ������ ������������� ��������� *ppPlgRez ������   lenPlgArr
 // �������� ������������, � � �������� ���������� ����� � �������
 // ��� ����� ���������� � ��������������� ������� � �����
void  TURPolygon::AssemblePlgFromTriangleArr_1(TTriang **ppTr
	   ,const int quantOutTr, TURPolygon **ppPlgRez, int *lenPlgArr)
{
  int quanTrTemp =quantOutTr ;

  int quantPlgTemp =  0;
  int lenMemory =  * lenPlgArr ;
  while(1)
  {
	if (quanTrTemp  == 0 )   break ;
	if ((quantPlgTemp ) > lenMemory )
	{
		*ppPlgRez =(TURPolygon*)realloc( *ppPlgRez,(lenMemory + 100) * sizeof (TURPolygon));
		lenMemory +=100 ;
	}
	(*ppPlgRez)[ quantPlgTemp ] = TURPolygon(1, &(*ppTr)[0]);
	quanTrTemp--;
	if (quanTrTemp == 0) break ;
	memcpy(&(*ppTr)[0],&(*ppTr)[ 1], quanTrTemp * sizeof( TTriang));


	while(1)
	{
	int numVert = -1;
	int numPart = -1;
	int  numVertTr = -1;
	bool bGoToNextPlg = true;
	//(*ppPlgRez)[ quantPlgTemp ].WriteToASCII(L"C:\\GEOPROCESSING_C++\\FILES\\plgRezTempCircle.txt") ;
	for (int j = 0; j  < quanTrTemp; j++)
	{
		if ((*ppPlgRez)[ quantPlgTemp ].JuncTriangle(&(*ppTr)[j], &numVertTr,&numVert, &numPart))
		{
        ((*ppPlgRez)[quantPlgTemp ]).AddVert((*ppTr)[j].m_pVert[(numVertTr + 2)%3],numVert, numPart );

		memcpy(&(*ppTr)[j],&(*ppTr)[j + 1], (quanTrTemp -j -1) * sizeof( TTriang));
		bGoToNextPlg = false;
		quanTrTemp--;
	   //	quantPlgTemp++;
		break;
		}
		else continue;
	}
	if (bGoToNextPlg) break;

	}
	quantPlgTemp++;
  }
  *lenPlgArr = quantPlgTemp;
return ;
}

// �������� ����������� ������������� ������ � ��������
// ���� �������������� - �� ���������� true � �������� ������
// ������  �����  �������� � ������������
// ���� �� �������������� �� ���������� false
// Input:  *pTr - �����������
// Output: ���� ������������� ��������
//  numVertTr - ������ ������� �����, �������� ����� ������������
//  numPartPlg - ����� ���������� ��������, � �������� ����� ������������ �������  numVertTr
//  numVertPlg - ����� ������� ������������,
// ����� ������� ����� ������������ ������� ������������
// ����� �������, ����� ������������ ������� ���� ����� ������ �����  �������� � ������� numPartPlg
// � ����� ������� � �������   numVertPlg �������� ������� ������������
bool TURPolygon::JuncTriangle(TTriang *pTr,int * numVertTr,int * numVertPlg,int *numPartPlg)
{
   for (int i = 0; i < NumParts; i++)
   {
	 int quanP = ( i == (NumParts -1))?(NumPoints - Parts[i] ):( Parts[i +1] - Parts[i] );
	 for (int j = 0; j < (quanP -1); j++)
	 {
	 for (int k = 0; k < 3; k++)
	 {
		TURPointXY p0;
		int ipCaseType = -10 ;

		if(TTriang ::IntersectTwoSegments(
		Points[Parts[i] + j],Points[ Parts[i] + j + 1] //1-�� �������
		,(*pTr).m_pVert[k],(*pTr).m_pVert[k + 1] // 2-�� �������
		, &p0  // ����� �����������
		, &ipCaseType //
		) )
		{
			if (ipCaseType == 4)
			{
			* numVertTr = k;
			*numPartPlg = i;
			* numVertPlg = Parts[i] + j ;
			return true;
			}
		}
	 }
	 }
   }
  return false; ;
}
// ���������� ������� pntP � ��������
// ������� ����������� � �������� ������� � �������   numPart
// ����� ������� � ������� numVert (� ��������� ������ ���������� ��������)
void TURPolygon::AddVert(TURPointXY pntP,const int numVert, const int numPart )
{
  NumPoints ++;
  for (int i = numPart +1 ; i < NumParts ; i++) Parts [i]++;
   TURPolygon tPlg( NumParts ,NumPoints,Parts,Points);
   memcpy( tPlg.Points,Points,numVert * sizeof( TURPointXY));
   tPlg.Points[numVert +1 ] =  pntP;
   memcpy( &(tPlg.Points[numVert + 2 ]) ,&(Points[numVert +1]),(NumPoints - numVert-2) * sizeof( TURPointXY));
	*this = tPlg;
}
////
TURPolygon TURPolygon::NormalizePolygon(TURPolygon *parrPlg,const int lenarrPlg  )
{
 TURPolygon *parrSimplePlg = new TURPolygon[lenarrPlg];
 for (int i = 0; i < lenarrPlg; i++)
 {
   parrSimplePlg[i] = parrPlg[i].NormalizeRing();
 }
TURPolygon rezPlg(parrSimplePlg, lenarrPlg);
 delete [] parrSimplePlg ;
	return rezPlg;
}
///

TURPolygon TURPolygon::NormalizeRing()
{
   int lenMemory = 100;
   int quantRings = 0 ;
   TURPolygon *parrRings  = (TURPolygon*)malloc(lenMemory* sizeof( TURPolygon)) ;

   while(NumPoints > 1)
   {

	   for (int i =0; i < NumPoints; i++)
	   {
		 int iCircleBegin = -1;
		  for (int j = i - 1;j  >= 0; j--)
		  {
		   if ((fabs(Points[i].X - Points[j].X) > TOLRNC )
			||(fabs(Points[i].Y - Points[j].Y) > TOLRNC ) )continue;
			else
			{
			  iCircleBegin = j;
			  break;
			}
		  }
		  if (iCircleBegin  > -1)
		  {

			if ( (quantRings + 1 ) >  lenMemory )
			{
			 lenMemory += 100;
			  realloc(parrRings,lenMemory * sizeof(TURPolygon)) ;
			}
			if ((i - iCircleBegin) > 2 )
			{
			  parrRings[ quantRings ] =  TURPolygon(i - iCircleBegin+ 1,&Points[ iCircleBegin]) ;
			  quantRings++;
			}
			memcpy(&Points[ iCircleBegin ], &Points[ i], (NumPoints   - i) * sizeof(TURPointXY)) ;
			NumPoints = NumPoints - (i - iCircleBegin ) ;
			break;
		  }
	   }
   }
   for (int i = 0; i < quantRings; i++)
   {
	 parrRings[i].ExcludeExcessVertexesFromRing() ;
   }
   TURPolygon rezPlg(parrRings, quantRings) ;
   free(parrRings);
	return rezPlg;
}

///
	//http://www.esri.com/library/whitepapers/pdfs/shapefile.pdf
	// http://www.dbase.com/Knowledgebase/INT/db7_file_fmt.htm
	//http://www.clicketyclick.dk/databases/xbase/format/dbf.html#DBF_STRUCT

// ��������� ������� ���������� ������ � 4 ������� ����� (32 ���� ������)
//  input : chstr - ��������� �� ������ char[4]
// output: chstr - ��������� �� ������  char[4] c ���������� �������� ����������
// ������  chstr[0] = chstr[3] ; chstr1] = chstr[2] ;  chstr[2] = chstr[1] ; chstr[3] = chstr[0] ;
void TURPolygon::ChangeByteOrder(int * pi0)
{
  char c;
  char * chstr = (char*)pi0;
  c = chstr[0];
  chstr[0] = chstr[3] ;
  chstr[3]  = c;
  c = chstr[1];
 chstr[1] = chstr[2] ;
  chstr[2]  = c;

}

void TURPolygon::WriteSetSHPFiles(wchar_t *wchFileName,TURPolygon *purPlg, const int quantPlg)
{

    int lenFileName = wcslen( wchFileName);

	if (!((wchFileName[lenFileName -1] == L'p')
	   && (wchFileName[lenFileName -2] == L'h')
	   && (wchFileName[lenFileName -3] == L's')))
	   {
		 ShowMessage(L" Error file name") ;
		 return;
	   }
	 wchar_t wchDBFFileName [200] ,wchSHXFileName [200] ;
	wcscpy(wchSHXFileName, wchFileName);
	wchSHXFileName[lenFileName -1] =  L'x' ;
	wcscpy(wchDBFFileName, wchFileName);
	wchDBFFileName [lenFileName -1] = L'f';
	wchDBFFileName [lenFileName -2] = L'b';
	wchDBFFileName [lenFileName -3] = L'd';
	WriteDBASEFile(wchDBFFileName,purPlg,  quantPlg) ;
	WriteMainFile(wchFileName,purPlg,  quantPlg) ;
	WriteIndexFile(wchSHXFileName,purPlg,  quantPlg) ;
}
void TURPolygon::WriteDBASEFile(wchar_t *wchFileName,TURPolygon *purPlg, const int quantPlg)
{
	FILE  *fw ;

	fw=_wfopen(wchFileName,L"wb");
	if(!fw) ShowMessage (L"TYrWrite::PutPointsToCsvFile\nFile is not opened !") ;
	//1. version number and Date of last update  - ������ 0-3  �����
	// char ch = '\x03';
	int i0 = 201421059;
	fwrite(&i0,sizeof(int),1 ,fw) ;
	// 2. Number of records  in data file   4-7 �����
	int numRecords = quantPlg ;
	   fwrite(&numRecords,sizeof(int),1 ,fw) ;
	// 3. bytes 8 -31
	int iarr[] = {2556001,0,0,0,0,22272};
	   fwrite(iarr,sizeof(int),6 ,fw) ;
	// 4. �������� ����� bytes 32-95
	int iarr1[] = {1346455635
	   ,1699503941
	   ,1174431598
	   ,0
	   ,2835
	   ,0
	   ,0
	   ,0
	   ,1346455635
	   ,1916886853
	   ,1174430053
	   ,0
	   ,2835
	   ,0
	   ,0
	   ,0};
	      fwrite(iarr1,sizeof(int),16 ,fw) ;
	// 5.  Terminator (0Dh) byte 96
	char ch = '\x0D';
	   fwrite(&ch,1,1 ,fw) ;
	//
	for (int i =0 ; i < quantPlg; i++)
	{
	ch = '\x20';
	   fwrite(&ch,1,1 ,fw) ;
	char carr1[40] ={0};
	double a= purPlg[i].calcLeng();
	double b = purPlg[i].calcVectSq()  ;
	sprintf_s(carr1, 40, "%19.11e%19.11e",a,b);

	   fwrite(carr1,1,38 ,fw) ;
	}
	fclose(fw);
}

void TURPolygon::WriteMainFile(wchar_t *wchFileName,TURPolygon *purPlg, const int quantPlg)
{
   const int SHAPE_TYPE =5 ;
  FILE  *fw ;

	 fw=_wfopen(wchFileName,L"wb");
	 if(!fw) ShowMessage (L"TYrWrite::PutPointsToCsvFile\nFile is not opened !") ;

	 // Main File HEADER
	 //*************************************************************************************
	 //1. step.  byte 0 - 23
	 // its are 6 integer values, getting by copying real shp file
	 int iarr[6] = {170328064
					,0
					,0
					,0
					,0
					,0 };
	   fwrite(iarr,sizeof(int),6 ,fw) ;
	   ///

	   // 2. The value for file length is the total length of the file in 16-bit words (including the fifty
		//16-bit words that make up the header).   Byte4s 24-27
		int iFileLeng = 100;
		for (int i = 0; i < quantPlg; i++)
		{
		   iFileLeng += 52 + 4 * purPlg[i].NumParts + 16 * purPlg[i].NumPoints ;
		}
		iFileLeng = iFileLeng/2;
		ChangeByteOrder(& iFileLeng);
		   fwrite(&iFileLeng,sizeof(int),1 ,fw) ;
		///

		// 3. version = 1000 shapetype =5  bytes 28-35
		   iarr[0] =  1000;
		   iarr[1] =  SHAPE_TYPE ;
		      fwrite(iarr,sizeof(int),2 ,fw) ;
		   ///

		// 4. Bounding box
		double Box[8] = {0};
		purPlg[0].calcBoundBox()  ;
		memcpy(Box,purPlg[0].Box,4 * sizeof(double));
		for (int i =0 ; i < quantPlg; i++)
		{
		   purPlg[i].calcBoundBox()  ;
		   if (purPlg[i].Box[0] <  Box[0]) Box[0] =  purPlg[i].Box[0];
		   if (purPlg[i].Box[1] <  Box[1]) Box[1] =  purPlg[i].Box[1];
		   if (purPlg[i].Box[2] >  Box[2]) Box[2] =  purPlg[i].Box[2];
		   if (purPlg[i].Box[3] >  Box[3]) Box[3] =  purPlg[i].Box[3];
		}
		   fwrite(Box,sizeof(double),8 ,fw) ;
		///******************************************************************************************
		///******************************************************************************************

	   // RECORDS
	   for (int i = 0; i < quantPlg; i++)
	   {
		  // 1. Record Headers
		   // Byte 0 Record Number Record Number Integer Big
		   int iRecNum = i;
		   ChangeByteOrder(& iRecNum);
		   //Byte 4 Content Length Content Length Integer Big
		   int iContLeng = (44 + 4 *  purPlg[i].NumParts + 16 * purPlg[i].NumPoints)/2 ;
		   ChangeByteOrder(& iContLeng);
		   iarr[0] =  iRecNum;
		   iarr[1] =  iContLeng ;
		      fwrite(iarr,sizeof(int),2 ,fw) ;
		   //*****************************************************
		   //********** Content *******************************************
				int ishapetype =   SHAPE_TYPE ;
			   fwrite(&ishapetype ,sizeof(int),1 ,fw) ;
			   fwrite(purPlg[i].Box,sizeof(double),4 ,fw) ;
			   fwrite(&(purPlg[i].NumParts),sizeof(int),1 ,fw) ;
			   fwrite(&(purPlg[i].NumPoints), sizeof(int),1 ,fw) ;

			   fwrite(purPlg[i].Parts, sizeof(int),purPlg[i].NumParts ,fw) ;
			for (int j = 0; j < purPlg[i].NumPoints; j++)
			{
			      fwrite(&(purPlg[i].Points[j].X),sizeof(double),1 ,fw) ;
			      fwrite(&(purPlg[i].Points[j].Y),sizeof(double),1 ,fw) ;
			}

	   }

  fclose(fw);
}
void TURPolygon::WriteIndexFile(wchar_t *wchFileName,TURPolygon *purPlg, const int quantPlg)
{
  FILE  *fw ;
	const int SHAPE_TYPE = 5;
	 fw=_wfopen(wchFileName,L"wb");
	 if(!fw) ShowMessage (L"TYrWrite::PutPointsToCsvFile\nFile is not opened !") ;
	  // Ibdex(SHX) File HEADER
	 //*************************************************************************************
	 //1. step.  byte 0 - 23
	 // its are 6 integer values, getting by copying real shp file
	 int iarr[6] = {170328064
					,0
					,0
					,0
					,0
					,0 };
	   fwrite(iarr,sizeof(int),6 ,fw) ;
	   ///

	   // 2. The value for file length is the total length of the file in 16-bit words (including the fifty
		//16-bit words that make up the header).   Byte4s 24-27
		int iFileLeng = ( 100 + quantPlg *8 )/2 ;;
		ChangeByteOrder(& iFileLeng);
		   fwrite(&iFileLeng,sizeof(int),1 ,fw) ;
		///

		// 3. version = 1000 shapetype =5  bytes 28-35
		   iarr[0] =  1000;
		   iarr[1] =  SHAPE_TYPE ;
		      fwrite(iarr,sizeof(int),2 ,fw) ;
		   ///

		// 4. Bounding box
		double Box[8] = {0};
		purPlg[0].calcBoundBox()  ;
		memcpy(Box,purPlg[0].Box,4 * sizeof(double));
		for (int i =0 ; i < quantPlg; i++)
		{
		   purPlg[i].calcBoundBox()  ;
		   if (purPlg[i].Box[0] <  Box[0]) Box[0] =  purPlg[i].Box[0];
		   if (purPlg[i].Box[1] <  Box[1]) Box[1] =  purPlg[i].Box[1];
		   if (purPlg[i].Box[2] >  Box[2]) Box[2] =  purPlg[i].Box[2];
		   if (purPlg[i].Box[3] >  Box[3]) Box[3] =  purPlg[i].Box[3];
		}
		   fwrite(Box,sizeof(double),8 ,fw) ;
		///******************************************************************************************
		///******************************************************************************************
	   // RECORDS
	   int offset = 100;
	   for (int i = 0; i < quantPlg; i++)
	   {
		  int ioffset = offset/2;
		  ChangeByteOrder(& ioffset);
		   int iContLeng = (44 + 4 *  purPlg[i].NumParts + 16 * purPlg[i].NumPoints)/2 ;
		   ChangeByteOrder(& iContLeng);
		      fwrite(&ioffset,sizeof(int),1 ,fw) ;
		      fwrite(&iContLeng,sizeof(int),1 ,fw) ;
		   offset +=  52 + 4 *  purPlg[i].NumParts + 16 * purPlg[i].NumPoints ;
	   }

	   fclose(fw);

}
void TURPolygon::ReadSHPFile(wchar_t *wchFileName,TURPolygon **ppurPlg,  int *pquantPlg)
{
	 int lenFileName = wcslen( wchFileName);

	if (!((wchFileName[lenFileName -1] == L'p')
	   && (wchFileName[lenFileName -2] == L'h')
	   && (wchFileName[lenFileName -3] == L's')))
	   {
		 ShowMessage(L" Error file name") ;
		 return;
	   }
	wchar_t  wchSHXFileName[200] ;
	wcscpy(wchSHXFileName, wchFileName);
	wchSHXFileName[lenFileName -1] =  L'x' ;
	FILE  *fr0 ;

	 fr0=_wfopen(wchSHXFileName,L"rb");
	 if(!fr0) ShowMessage (L"TURPolygon::ReadSHPFile\nFile is not opened !") ;
	  int offset0 = 32;
	  int ishapetype = -1;

	  fseek(fr0,offset0,SEEK_SET);
	  fread(&ishapetype ,sizeof(int), 1,fr0) ;
	  if (ishapetype != 5)
	  {
		ShowMessage(L" There is not polygon in shape file") ;
		 return;
	  }
	  offset0 = 24;
	  fseek(fr0,offset0,SEEK_SET);
	  int lenSHXFile = -1;
	  fread(&lenSHXFile ,sizeof(int), 1,fr0) ;
	  ChangeByteOrder( &lenSHXFile);
	  int quantPlg =( 2 *  lenSHXFile - 100 )/ 8 ;
	   *ppurPlg = (TURPolygon *)realloc( *ppurPlg, quantPlg * sizeof( TURPolygon)) ;
	   *pquantPlg =  quantPlg ;

		FILE  *fr1 ;

	 fr1=_wfopen(wchFileName,L"rb");
	 if(!fr1) ShowMessage (L"TURPolygon::ReadSHPFile\nFile is not opened !") ;
	 int offset1 = -1;
	 int iNumParts = -1;
	 int iNumPoints = -1 ;
	 for (int i = 0; i < quantPlg; i++)
	 {
	   offset0 = 100 + 8 * i;
	   fseek(fr0,offset0,SEEK_SET);
	   fread(&offset1 ,sizeof(int), 1,fr0) ;
	   ChangeByteOrder( &offset1);
	   offset1 = 2 * offset1 + 44;
	   fseek(fr1,offset1,SEEK_SET);
	   fread(&iNumParts ,sizeof(int), 1,fr1) ;
	   fread(&iNumPoints ,sizeof(int), 1,fr1) ;

		TURPolygon pPlg( iNumParts, iNumPoints);
	   fread(pPlg.Parts ,sizeof(int), iNumParts,fr1) ;
	   for (int j = 0; j < iNumPoints; j++)
	   {
		 double x,y;

		 fread(& x ,sizeof(double), 1,fr1) ;
		 fread(& y ,sizeof(double), 1,fr1) ;

		 pPlg.Points[j].X  = x;
		 pPlg.Points[j].Y  = y;

	   }
		(*ppurPlg)[i ] = pPlg;

	 }

	 fclose(fr0);
	 fclose(fr1);

}
// �������� ������ ���������� � ������� � �����  pointCentre
// ��������  valR � ����� �� ���� valDelFi �
TURPolygon TURPolygon::fncCreateSector(const TURPointXY pointCentre, const double valR,
					const double valFi0,const double valFi1,const int iNUM)
{
 const int NPoints = iNUM + 2;
 TURPointXY  *parrPoints = new TURPointXY  [ NPoints] ;
 double valFiCur = valFi0 ;
 const double valDelFi = (valFi1 - valFi0)/ ((double)iNUM -1.);
 parrPoints[0] = pointCentre ;
 for (int i =0; i < iNUM; i++)
 {
   parrPoints[i+1].X = valR * cos(valFiCur) + pointCentre.X ;
   parrPoints[i+1].Y = valR * sin(valFiCur) + pointCentre.Y ;
   valFiCur += valDelFi ;
 }
 parrPoints[NPoints -1] = pointCentre ;
 TURPolygon plgRez = TURPolygon(NPoints, parrPoints);
 delete []parrPoints ;
 return  plgRez ;
}

// �������� ��������� � ������� � �����  pointCentre
// ��������  valR � ����� �� ���� iNUM
// valWidthMilrad -  ������ ��������� � ������������
// valRotAng - ���� �������� ������������ �����������
// ������� ����������� ������ ��� �������
TURPolygon TURPolygon::fncCreateDiagr(const TURPointXY pointCentre, const double valR,
					const double valRotAng ,const double valWidth,const int iNUM)
{
  const double valTET0707 = 1.39115573;
  double coeff =  valTET0707 / valWidth;
  double valTetCrit = M_PI/coeff *3.;
 const int NPoints = iNUM + 2;
 TURPointXY  *parrPoints = new TURPointXY  [ NPoints] ;

 const double valDelFi = 2. * valTetCrit/ ((double)iNUM -1.);
 parrPoints[0] = TURPointXY(0.,0.);//pointCentre ;
 for (int i =0; i < iNUM; i++)
 {
   double valTetCur =  - valTetCrit + ((double)(i + 1.))* valDelFi;
   double valRCur = fabs(sin( coeff *valTetCur )/coeff/ valTetCur)  *valR;
   parrPoints[i+1].X = valRCur * cos(valTetCur) ;
   parrPoints[i+1].Y = valRCur * sin(valTetCur) ;
 }
 parrPoints[NPoints -1] = pointCentre ;
 TURPolygon plgRez = TURPolygon(NPoints, parrPoints-1);
  TURPolygon plgRez1 = plgRez.LinTransform(valRotAng , pointCentre,1. ) ;
 delete []parrPoints ;
 return  plgRez1 ;
}
// ��������  ���������� � ������� � �����  pointCentre  �
// ��������  valR � ����������� �����  iNUM
TURPolygon TURPolygon::fncCreateCircle(const TURPointXY pointCentre
	 ,const double valR, const int iNUM)
{

 TURPointXY  *parrPoints = new TURPointXY  [ iNUM + 1] ;
 double valFiCur = 0. ;
 const double valDelFi = 2. * M_PI / ((double)iNUM );

 for (int i =0; i < iNUM; i++)
 {
   parrPoints[i].X = valR * cos(valFiCur) + pointCentre.X ;
   parrPoints[i].Y = valR * sin(valFiCur) + pointCentre.Y ;
   valFiCur += valDelFi ;
 }
 parrPoints[iNUM ] = parrPoints[0] ;
 TURPolygon plgRez = TURPolygon(iNUM + 1, parrPoints);
 delete []parrPoints ;
 return  plgRez ;
}

// �������� ������ ���������� � ������� � �����  pointCentre
// ��������  valR � ����� �� ���� valDelFi �
TURPolygon TURPolygon::fncSimpleSectorsIntersection( TURPolygon plgInterSect,TURPolygon plgSect0
			   ,TURPolygon plgSect1, TURPointXY *pPointCentre
					,const double valR)
{
 int iNum0 =  plgInterSect.fncFindNumMainVertex (pPointCentre[0], pPointCentre[1], valR) ;
 int iNumNext = iNum0 + 1, iNumPrev = iNum0 - 1;
 if (iNum0 == 0)  iNumPrev =  plgInterSect.NumPoints - 2 ;

 if (iNum0 == (plgInterSect.NumPoints - 1))
 {
  iNumNext = 1;
  iNum0 = 0;
  iNumPrev = plgInterSect.NumPoints - 2 ;
 }

 TURPointXY arrPoints[5];
 int QuantPoints = 2;
 arrPoints[0] = plgInterSect.Points[ iNum0];
 arrPoints[1] = plgInterSect.Points[ iNumNext];
 //int iNumCircle = 0;
 //TURPolygon *pPlg = &plgSect0; // ����� �� ������� �����
 TURPolygon *pPlgRest = &plgSect1; // ����� ������ �����
// ����� ������ ������� ��������  plgInterSect �� ������� �� ������� ���������� plgSect0
// int ibegin = -1 ;
 int ist = 0;
 for ( ist = 0; ist < plgInterSect.NumPoints-2; ist++)
 {
   if (plgSect0.PntInPolygon(plgInterSect.Points[(iNumNext + ist)%(plgInterSect.NumPoints-1)]) ==1)
   {
	// ibegin = (iNumNext + ist)%(plgInterSect.NumPoints-1);
	// iNumCircle = 1;
	// pPlg = &plgSect1;  // ����� �� ������� �����
	 pPlgRest = &plgSect0;  // ����� ������ �����
	 break;
   }
 }
 ///
 //int iNumTheRestCircle = (iNumCircle + 1)%2 ;
 int NumPoint2 = -1;

 for (int i = ist + 1; i < (plgInterSect.NumPoints-3); i++)
 {
   int j = (iNumNext + i ) % (plgInterSect.NumPoints - 1)  ;

  if ( (*pPlgRest).PntInPolygon(plgInterSect.Points[j]) > 1)
   {
   NumPoint2 = j;
   break ;
   }
 }
  if (NumPoint2 >= 0)
  {
	arrPoints[2] = plgInterSect.Points[ NumPoint2];
	arrPoints[3] = plgInterSect.Points[iNumPrev ];
	arrPoints[4] = arrPoints[0];
	QuantPoints = 5 ;
  }
  else
  {
	arrPoints[2] = plgInterSect.Points[iNumPrev ];;
	arrPoints[3] = arrPoints[0];

	QuantPoints = 4 ;
  }


 TURPolygon  plgRez = TURPolygon (  QuantPoints,arrPoints);
 return   plgRez ;
}

//���������� ������ �������� ������� �������� ����������� 2-� �������� � ����������� ���������
int TURPolygon::fncFindNumMainVertex ( const TURPointXY pointCentre0,const TURPointXY pointCentre1,const double valR)
{
  int iNumRez = -1;
  const double val_r = valR * cos(M_PI / 20.) - 0.001;
 for (int i = 0; i < NumPoints; i++)
 {
   if (dist(Points[i] ,pointCentre0) > val_r ) continue ;
   if (dist(Points[i] ,pointCentre1) > val_r ) continue ;
   iNumRez = i;
   break ;
 }
 return iNumRez ;
}

// ���� ���������� ����� ������ point � �������� ����������  pointCentre
// ������ ������� valR � ������ ������� val_r = valR * cos(M_PI / 20.) - 0.00001;
// �� ������� ����������� true � ��������� ������ false
bool TURPolygon::fncIsOnCircle (const TURPointXY point, const TURPointXY pointCentre,const double valR)
{
const double val_r = valR * cos(M_PI / 20.) - 0.00001;
const double valRR = valR + 0.000001;
 const double val_d = dist(point ,pointCentre);
  if ((val_d > val_r )&& (val_d < valRR)) return true;
  else return false ;

}

// ���������� ������ ������� �� ����� ������ � ������ � ������������ �����   TOLRNC
void TURPolygon::ExcludeExcessVertexesFromRing()
{
   //1 ���������� ������  � ������������ �����   TOLRNC
   bool bChange = true;
   while( bChange )
   {
	 bChange = false ;
	 for (int i = 0; i < (NumPoints -2); i++)
	 {
		if (dist(Points[i] ,Points[i + 1]) > TOLRNC)
		{
		  continue ;
		}
		else
		{
		   ExcludePointFromRing(i+1) ;
		   bChange = true;
		   break ;
        }
	 }
   }

   /// ����� 1


  bChange = true;
  while( bChange )
  {
   bChange = false ;
   bool bBreake = false;
   for (int i =1; i < NumPoints -2 ; i++)
   {
	TTriang trnTr = TTriang( Points[i - 1],  Points[i],Points[i + 1]);
	double valTemp = trnTr.calcSq();
	if ( 2. * fabs(valTemp)/ dist(Points[i - 1] ,Points[i + 1]) > TOLRNC) continue ;
	else
	{
	  bChange = true;

	  /// ��� �������
   //	   Points[i ].WriteSetSHPFiles(L"D:\\PROJECTS_C++\\IMPULS\\FILES\\ExcludingPoint.shp"
   //	   ,&Points[i ], 1) ;
	  ///
	  TURPolygon plgTemp = ExcludePointFromRing(i) ;

	  *this = plgTemp ;

	  // ��� �������
	 //	(*this).WriteSetSHPFiles(L"D:\\PROJECTS_C++\\IMPULS\\FILES\\this.shp",this, 1 );
	 //	TURPointXY::WriteSetSHPFiles(L"D:\\PROJECTS_C++\\IMPULS\\FILES\\Point_thisPlg.shp"
	//   ,(*this).Points, (*this).NumPoints) ;
	  ///
	  bBreake = true;
	  break ;
	}
   }
   if (bBreake) continue;


   TTriang trnTr = TTriang( Points[NumPoints - 2],  Points[0],Points[1]);
   if ( 2. * trnTr.calcSq()/ dist(Points[NumPoints - 2] ,Points[ 1]) > TOLRNC) continue ;
	else
	{
	  bChange = true;
	  TURPolygon plgTemp = ExcludePointFromRing(0) ;
	  *this = plgTemp ;
	  continue ;
	}

  }
}


// ���������� ��������� ������ ������� ������, ����������� �������� �������.
// INPUT:
// pointLine - ����� �� ������
// arrVectLine - ������ �������� ������ � ��������� ����
//OUTPUT:
// pntSegm0, pntSegm1 - ���������� ��������
// ������ ����������  true ���� ����� ���������� ������� � false � ��������� ������
//
bool TURPolygon::fncFindSecantSegm( TURPointXY pointLine, double *arrVectLine
	   ,TURPointXY &pntSegm0,TURPointXY &pntSegm1)
{
   TURPointXY pntArrSecant[4] ;

   TURPointXY pCut;
   if (fabs(arrVectLine[0]) > TOLRNC)
   {
	   return fncFindSecantSegm_NotVerticalLine( pointLine, arrVectLine
	   ,pntSegm0,pntSegm1);
   }
   else
   {
	// ������� ���� ������ � �������� ��������� ���������� �� ��/2
	TURPointXY pointLine_new, pntSegm0_new,pntSegm1_new ;
	double arrVectLine_new [2] ={0.} ;
	// ������� ��������
	double arrMtxPer[4] = {0.,1.,-1., 0.} ;
	pointLine_new = pointLine.fncLinTrasform(arrMtxPer);
	MtrxMultMatrx(arrMtxPer,2, 2, arrVectLine,1, arrVectLine_new) ;
	TURPolygon plg_new = *this;
	for (int i =0; i < NumPoints; i++)
	{
	 plg_new.Points[i] =  Points[i].fncLinTrasform(arrMtxPer );
	}
	bool bReturn = plg_new.fncFindSecantSegm_NotVerticalLine( pointLine_new, arrVectLine_new
	,pntSegm0_new,pntSegm1_new);
	arrMtxPer[ 1] = -1.;
	arrMtxPer [2] = 1.;
	pntSegm0 = pntSegm0_new.fncLinTrasform(arrMtxPer);
	pntSegm1 = pntSegm1_new.fncLinTrasform(arrMtxPer);
	return bReturn ;

   }

}
// ���������� ��������� ������ ������� ������, ����������� �������� �������.
// ������ �� ������������!!!
// INPUT:
// pointLine - ����� �� ������
// arrVectLine - ������ �������� ������ � ��������� ����
//OUTPUT:
// pntSegm0, pntSegm1 - ���������� ��������
// ������ ����������  true ���� ����� ���������� ������� � false � ��������� ������
//
bool TURPolygon::fncFindSecantSegm_NotVerticalLine( TURPointXY pointLine, double *arrVectLine
	   ,TURPointXY &pntSegm0,TURPointXY &pntSegm1)
{
   TURPointXY pntArrSecant[4] ;
   int iNumSecant = 0 ;

   int irez = -1;
   TURPointXY pCut;
    double k0 = -1.;
   if (fabs(arrVectLine[0]) > TOLRNC) k0 = arrVectLine[1] / arrVectLine[0] ;
   else
   {
	   ShowMessage(L"TURPolygon::fncFindSecantSegm_NotVerticalLine.Line is vertical.") ;
	   return false ;
   }


	 for (int i  = 0; i < (NumPoints - 1); i++)
	 {
	   // ����������� ����� � �������(��������)
		// ����������:
		// 0 - �� ����������
		// 1 - ����������
		// 2  - ������ �������� ����� ������� ��������
		// 3  - ����� p0,    ����� ������ ��������
		// 4  - �����  p0  �������� �������� ��������
		// 5  - ������� ����� �� �����
	   irez =  LineCutSegment(Points[i], Points[i + 1]// �������
							,pointLine, k0 // ������ k0 - ������� �������
							,pCut // ����� �����������
								);
		switch (irez)
		{
		case 0:
		break ;

		case 1:
		case 2:
		case 3:
		case 4:
		pntArrSecant[iNumSecant] =  pCut;
		iNumSecant++ ;

		break ;
		case 5:
		return false ;

		default:
			;
		}
	 }
	 if (iNumSecant> 4)
	 {
	  ShowMessage(L"Error TURPolygon::fncFindSecantSegm") ;
	  return false ;
	 }
	 int iNumSecant0 = -1 ;
	 fncRemoveEqualNeighbourFromPointsArray(pntArrSecant, iNumSecant, iNumSecant0);
	 if (iNumSecant0 < 2)
	 {
	   return false ;
	 }
	 if (iNumSecant0 == 3)
	 {
	  ShowMessage(L"Error TURPolygon::fncFindSecantSegm_1") ;
	  return false ;
	 }

   pntSegm0 = pntArrSecant[0] ;
   pntSegm1 = pntArrSecant[1] ;
   return true ;
}

void TURPolygon::fncRemoveEqualNeighbourFromPointsArray(TURPointXY *pPntArr, const int lenarr, int &lenarrOut)
{
  lenarrOut = lenarr ;
  while(1)
  {

   bool bChange = false ;
   for (int i =0; i < lenarrOut; i++)
   {
	 if ( TURPointXY::fncIsPointsEqual(pPntArr[i], pPntArr[(i + 1)% lenarrOut ]) )
	 {
		bChange = true ;
		if ((i == (lenarrOut -1)) || (i == (lenarrOut -2)) )
		{
		  lenarrOut--;

		  break;
		}


		memcpy( &pPntArr[i + 1], &pPntArr[i + 2], (lenarrOut - i - 2) * sizeof( TURPointXY)) ;
		lenarrOut--;

	 }
   }
   if (!bChange) break ;


  }
}

// ���������� ���� ���� ������������� ���� ������� � �������  iNumVertex
// � ���� OX  ��� Ring
double TURPolygon::fncFindBisectorAng(const int iNumVertex)
{
  TURPointXY pnt0, pnt1 ;
  int iNumVertex1 = iNumVertex ;
  if (iNumVertex1 == (NumPoints -1)) iNumVertex1 = 0;



  if (iNumVertex1 == 0)
  {
	pnt0 = Points [ NumPoints -2] - Points [ iNumVertex1 ] ;
  }
  else
  {
  pnt0 = Points [ iNumVertex1 -1] - Points [ iNumVertex1 ] ;
  }
  pnt1 = Points [ iNumVertex1 + 1 ] - Points [ iNumVertex1 ];

  double valFi0 = -1000., valFi1 = -1000.;

   Atan2_(pnt0.Y, pnt0.X,  &valFi0) ;
   Atan2_(pnt1.Y, pnt1.X,  &valFi1) ;

   return (valFi0 + valFi1) / 2. ;


}

// ����������� ����� ������������ ����� �������� ��������� � ��������
// iNumVertex0   � iNumVertex1
// pntBsctVertex - ����� ����������� ����� �� ������� ����� �����
// valBsctAng - ���� ����� ������������� � ���� OX
// ���������� false ���� ����� �����������
// � true � ��������� ������
 bool TURPolygon::fncFindBisectorLine(const int iNumVertex0, const int iNumVertex1
				   ,double &valBsctAng, TURPointXY &pntBsctVertex)
{
  TURPointXY pnt ;
// ����������� 2-� ������
// ����� ����� ����������� ���� ������ �� ���������
// 1-�� ������ ������ ������� p0 � p3
// 2-�� ������ ������ ������� p1 � p2
// x,y - [output]
// ���������� 0 ���� ������ �����������
//1 ���� ������������
// 2 ���� ���������
   if (0 == IntersectTwoLine( Points[iNumVertex0],Points[iNumVertex1]
					,Points[(iNumVertex1 + 1)% (NumPoints  -1)]
					,Points[(iNumVertex0 + 1)% (NumPoints  -1)], &pnt))
   {
	   return false ;
   }
   pntBsctVertex = pnt ;
   TURPointXY pnt0, pnt1;
   pnt0 = Points[iNumVertex0] - pntBsctVertex ;
   pnt1 = Points[iNumVertex1] - pntBsctVertex ;
   double valFi0 = -1000., valFi1 = -1000.;

   Atan2_(pnt0.Y, pnt0.X,  &valFi0) ;
   Atan2_(pnt1.Y, pnt1.X,  &valFi1) ;

   valBsctAng =  (valFi0 + valFi1) / 2. ;
   return true ;

}
// ���� ����� ���� X � ������ x,y �������� ����������� - ������� ������� �������
// ���� �� -Pi �� PI
// ���� x=0 � y = 0, �� ���� ����������� � ������� ���������� false
// � ���� ������ true
bool   TURPolygon::Atan2_(const double y, const double x,  double *prez)
{
	 // �������� �� ����������������
	if (fabs(x) < 0.000000001)
	{
	   if (fabs(y) < 0.000000001)
	   {
		*prez = 0.;
		return false;
	   }
	   else
	   {
		 *prez = SignD(y) * M_PI/2. ;
		return true;
	   }
	}

	 *prez =  atan2(y, x);
	 return true ;

}

// ������
double TURPolygon::SignD(const double valOm)
 {
   if (fabs (valOm) < 0.000000000001) return 0 ;

   return ( valOm > 0 )?1:-1;
 }

//INPUT:
// pntCentre - ����� ����������
// valR - ������ ����������
// pntSegm0, pntSegm1 - �������
//
// OUTPUT:
// pntRez  - ����� �������

int   TURPolygon::fncCheckPositionCircle_and_Edge( TURPointXY pntCentre
	,const double valR,   TURPointXY pntSegm0,   TURPointXY pntSegm1
	, TURPointXY &pntRez )
{
// ������ ������������ ������, �� ������� ����� ����� ��������
  if (fabs( pntSegm1.X - pntSegm0.X) < 0.00001)
  {
	return fncCheckProperPositionCircle_and_VerticalEdge( pntCentre
	, valR,   pntSegm0,   pntSegm1
	, pntRez );
  }
  ///

  // ������ ������ � ��������������, ����� �������� �� ���� ��/2 - alfa
  double valFi = - M_PI / 2. + atan( (pntSegm1.Y- pntSegm0.Y)/ (pntSegm1.X- pntSegm0.X)) ;
  double arrMtxPer[4] = {0.};
  arrMtxPer[0] =  cos (valFi ) ;
  arrMtxPer[1] =  sin (valFi ) ;
  arrMtxPer[2] = -sin (valFi ) ;
  arrMtxPer[3] =  cos (valFi ) ;
  TURPointXY pntCentre_new,pntSegm0_new, pntSegm1_new, pntRez_new;
   pntCentre_new = pntCentre.fncLinTrasform(arrMtxPer) ;
   pntSegm0_new = pntSegm0.fncLinTrasform(arrMtxPer) ;
   pntSegm1_new = pntSegm1.fncLinTrasform(arrMtxPer) ;
   int iReturn = fncCheckProperPositionCircle_and_VerticalEdge( pntCentre_new
	,valR, pntSegm0_new,  pntSegm1_new, pntRez_new ) ;

	if (iReturn == 1)
	{
	  arrMtxPer[1] = -arrMtxPer[1] ;
	  arrMtxPer[2] = -arrMtxPer[2];
	  pntRez =  pntRez_new.fncLinTrasform(arrMtxPer) ;
	}

  return iReturn;
}


int   TURPolygon::fncCheckProperPositionCircle_and_VerticalEdge(const TURPointXY pntCentre
	,const double valR,  const TURPointXY pntSegm0,  const TURPointXY pntSegm1
	, TURPointXY &pntRez )
{
   if (fabs( pntSegm1.X - pntSegm0.X) > TOLRNC)
   {
	   ShowMessage(L"Edge is not vertical.TURPolygon::fncCheckProperPositionCircle_and_VericalEdge ") ;
	   return 0 ;
  }
  double valDelx =  fabs( pntSegm1.X - pntCentre.X);
	if (fabs(valDelx -valR) <= TOLRNC) // ������ �������� ����������
	{
		if ((pntCentre.Y - pntSegm0.Y) * (pntCentre.Y - pntSegm1.Y) < -TOLRNC)
		{ // ������� �������� ���������� � ����� ������� ����� ������ �������
		pntRez.X = pntSegm0.X;
		pntRez.Y = pntCentre.Y ;
		return 1;
		}
		else return 0; // �������� �������� ������������ ������� � ����������
	}

	if (valDelx > valR ) return 2 ;//  �� ������������. ������������ ������
	return 0; //  �� ������������. ������������ �� ������
}

// ���������� ���������� ��������� � ���� �������  iNumVert0 � iNumVert1
bool TURPolygon::fncFindEscribedCircle(const int iNumVert0,const int iNumVert1, TURPointXY &pntCentre, double &valR)
{


		double valBisectAng0 = fncFindBisectorAng(iNumVert0) ;
		double valBisectAng1 = fncFindBisectorAng(iNumVert1) ;
		double arrVectLine0[2] ={0.},  arrVectLine1[2] ={0.};
		arrVectLine0[0] = cos(valBisectAng0) ;
		arrVectLine0[1] = sin(valBisectAng0) ;
		arrVectLine1[0] = cos(valBisectAng1) ;
		arrVectLine1[1] = sin(valBisectAng1) ;
		TURPointXY pointLineOut ;
		if( fncIntersectTwoParametricLines( Points[iNumVert0], arrVectLine0
		,Points[iNumVert1], arrVectLine1
		,pntCentre ) != 1) return false ;
		TURPointXY p1,p0;
		p1 = Points[(iNumVert0 + 1)% (NumPoints -1)] - Points[iNumVert0 ];

		if (iNumVert0 == 0)
		{
		 p0= Points[NumPoints - 2] - Points[0];
		}
		else
		{
		p0 = Points[(iNumVert0 - 1)] - Points[iNumVert0 ];
		}
		double valCosFi = TURPointXY::ScalMult( p1,p0)/ p1.Norm()/ p0.Norm();
		double valFi = acos( valCosFi) ;
		valR = dist(pntCentre , Points[iNumVert0]) * sin( valFi / 2.) ;
		return true ;
 }

int TURPolygon::fncIntersectTwoParametricLines( TURPointXY pointLine0, double *arrVectLine0
		, TURPointXY pointLine1, double *arrVectLine1
		,TURPointXY &pointLineOut)
{
 if (fabs (arrVectLine0[0]) < TOLRNC)
 {
	 return fncIntersectParametricLine_AND_Vert( pointLine0
		, pointLine1, arrVectLine1
		,pointLineOut);
 }
 else
 {
		// �������� ������ � ������ ������������ ������ ����� �������� �� �� -��/2  + Alf
		 double valFi = - M_PI / 2. + atan( arrVectLine0[1]/ arrVectLine0[0]) ;
	  double arrMtxPer[4] = {0.};
	  arrMtxPer[0] =  cos (valFi ) ;
	  arrMtxPer[1] =  sin (valFi ) ;
	  arrMtxPer[2] = -sin (valFi ) ;
	  arrMtxPer[3] =  cos (valFi ) ;

	  TURPointXY pointLine0_new,pointLine1_new, pntCrclCentre_new, pointLineOut_new;
	  double arrVectLine0_new[2] = {0.} ;
	  double arrVectLine1_new[2] = {0.} ;
	  pointLine0_new = pointLine0.fncLinTrasform(arrMtxPer);
	  pointLine1_new = pointLine1.fncLinTrasform(arrMtxPer);

	  MtrxMultMatrx(arrMtxPer,2, 2, arrVectLine0,1, arrVectLine0_new) ;
	  MtrxMultMatrx(arrMtxPer,2, 2, arrVectLine1,1, arrVectLine1_new) ;
	  int irez = fncIntersectParametricLine_AND_Vert( pointLine0_new
		, pointLine1_new, arrVectLine1_new
		,pointLineOut_new);
	 if ( irez != 1) return irez ;

	  arrMtxPer[1] = -arrMtxPer[1] ;
	  arrMtxPer[2] = -arrMtxPer[2] ;
	  pointLineOut = pointLineOut_new.fncLinTrasform(arrMtxPer);
	  return irez ;

 }

}



int TURPolygon::fncIntersectParametricLine_AND_Vert(const TURPointXY pointLine0
		,const TURPointXY pointLine1, double *arrVectLine1
		,TURPointXY &pointLineOut)
{
	if ( fabs(arrVectLine1[0]) < TOLRNC)
	{
	  if (dist(pointLine0, pointLine1 )< TOLRNC)
	  {
		pointLineOut = pointLine0;
		return 0;
	  }
	  else
	  {
		  return -1;
	  }
	}
	pointLineOut.X = pointLine0.X ;
	pointLineOut.Y = pointLine1.Y +  arrVectLine1[1]/ arrVectLine1[0] * (pointLine0.X - pointLine1.X) ;
	return 1;

}
// �������� �������������� ��������
TURPolygon   TURPolygon::fncLinTransform(double * arrMtxPer )
{
  TURPolygon PlgRez = *this;
  for (int i = 0; i < NumPoints; i++)
  {
	 PlgRez.Points[i] = Points[i].fncLinTrasform( arrMtxPer );
  }

  return PlgRez;
}

// �������� �������������� ��������
double   TURPolygon::fncCalcOutsideCircleAng(const TURPointXY pntCrclCentre, double valR)
{
  double valOutAng = 0.;
  for (int i = 0; i < NumPoints -1; i++)
  {
	valOutAng += fncCalcOutsideEdgeAng( pntCrclCentre,  valR,  i);
  }
  return valOutAng;
}

double TURPolygon::fncCalcOutsideEdgeAng(const TURPointXY pntCrclCentre, double valR, const int iEdgeNum)
{
	TURPointXY arrPntRez [2] ;
  if( fncSegmentCutCircle(  pntCrclCentre, valR// ����������
							, Points[iEdgeNum],   Points[iEdgeNum + 1]
							,arrPntRez // ����� ����� � �����������
								) >= 200 )
   {
	 TURPointXY p0 = arrPntRez[0] - pntCrclCentre ;
	 TURPointXY p1 = arrPntRez[1] - pntCrclCentre ;
	 return acos(TURPointXY::ScalMult(p0,p1) / p0.Norm()/ p1.Norm());
   }
	return 0. ;
}

// ����������� ��������������� ����� � ����������
// ���������� 0 ���� �� ������������
// 1 ���� ��������
// 2 ���� 2 ����� �����������
// arrPntRez- ������ ����� �����������
int TURPolygon::fncParametricLineCutCircle( TURPointXY pntCrclCentre,double valR// ����������
							,TURPointXY pointLine, double *arrVectLine // �����
							,TURPointXY *arrPntRez // ����� ����� � �����������
								)
{
	if (fabs(arrVectLine[0]) < TOLRNC)
	{
	  return fncParametricVerticalLineCutCircle(  pntCrclCentre, valR// ����������
							, pointLine, arrVectLine // �����
							,arrPntRez // ����� ����� � �����������
								);
	}
	else
	{
		// �������� ������ � ������ ������������ ������ ����� �������� �� �� ��/2
		 double valFi = - M_PI / 2. + atan( arrVectLine[1]/ arrVectLine[0]) ;
	  double arrMtxPer[4] = {0.};
	  arrMtxPer[0] =  cos (valFi ) ;
	  arrMtxPer[1] =  sin (valFi ) ;
	  arrMtxPer[2] = -sin (valFi ) ;
	  arrMtxPer[3] =  cos (valFi ) ;

	  TURPointXY pointLine_new, pntCrclCentre_new, arrPntRez_new[2];
	  double arrVectLine_new[2] = {0.} ;
	  pointLine_new = pointLine.fncLinTrasform(arrMtxPer);
	  pntCrclCentre_new = pntCrclCentre.fncLinTrasform(arrMtxPer);
	  MtrxMultMatrx(arrMtxPer,2, 2, arrVectLine,1, arrVectLine_new) ;

	  int ireturn = fncParametricLineCutCircle(  pntCrclCentre_new, valR// ����������
							, pointLine_new, arrVectLine_new // �����
							,arrPntRez_new // ����� ����� � �����������
								);
	 if (ireturn > 0)
	 {
	  arrMtxPer[1] = -arrMtxPer[1] ;
	  arrMtxPer[2] = -arrMtxPer[2] ;
	  arrPntRez[0] =  arrPntRez_new[0].fncLinTrasform(arrMtxPer);
	  arrPntRez[1] =  arrPntRez_new[1].fncLinTrasform(arrMtxPer);

	 }
	 return ireturn;


	}

}

// ����������� ��������������� ������������ ����� � ����������
// ���������� 0 ���� �� ������������
// 1 ���� ��������
// 2 ���� 2 ����� �����������
// arrPntRez- ������ ����� �����������
int TURPolygon::fncParametricVerticalLineCutCircle( TURPointXY pntCrclCentre,double valR// ����������
							,TURPointXY pointLine, double *arrVectLine // �����
							,TURPointXY *arrPntRez // ����� ����� � �����������
							)
{
	if (fabs(arrVectLine[0]) > TOLRNC)
	{
		ShowMessage(L"Line is not vertical. TURPolygon::fncParametricVerticalLineCutCircle") ;
		return 0 ;
	}
	double valDiscr =  valR * valR - (pointLine.X - pntCrclCentre.X) * (pointLine.X - pntCrclCentre.X);
	if (fabs (valDiscr) < TOLRNC * TOLRNC)
	{
	  arrPntRez[0].X =  pointLine.X;
	  arrPntRez[0].Y =  pntCrclCentre.Y ;
	  return 1;
	}
	if (valDiscr > 0.)
	{
	  arrPntRez[0].X =  pointLine.X;
	  arrPntRez[0].Y =  pntCrclCentre.Y - sqrt( valDiscr);
	  arrPntRez[1].X =  pointLine.X;
	  arrPntRez[1].Y =  pntCrclCentre.Y + sqrt( valDiscr);
	  return 2;
	}
 return -1 ;
}


// �����������  ������� � �����
// ���������� 0 ���� �� ������������
// 10 ���� ��������  ������ �������
// 11 ����� pntSegm0 �� ����������,  pntSegm1 �������, ���� ������� �������
// 12 ����� pntSegm1 �� ����������,  pntSegm0 �������, ���� ������� �������
// 201 ����� pntSegm0 ������,  pntSegm1 �������, 2 ����� �����������
// 210 ����� pntSegm1 �����,  pntSegm0 �������, 2 ����� �����������
// 200 ����� pntSegm1 ������,  pntSegm0 ������, 2 ����� �����������
// 211 ����� pntSegm1 �������,  pntSegm0 �������, 2 ����� �����������
// arrPntRez- ������� ���� �����������,
int TURPolygon::fncSegmentCutCircle( TURPointXY pntCrclCentre,double valR// ����������
							, TURPointXY pntSegm0,  TURPointXY pntSegm1
							,TURPointXY *arrPntRez // ����� ����� � �����������
								)
{
	if (fabs(pntSegm0.X -pntSegm1.X ) < TOLRNC)
	{
	  return fncVerticalSegmentCutCircle( pntCrclCentre, valR// ����������
							, pntSegm0,   pntSegm1
							,arrPntRez // ����� ����� � �����������
								) ;
	}
	else
	{
   	// �������� ������ � ������ ������������ ������ ����� �������� �� �� -��/2 + FI
		 double valFi = - M_PI / 2. + atan( (pntSegm0.Y -pntSegm1.Y )/ (pntSegm0.X -pntSegm1.X )) ;
	  double arrMtxPer[4] = {0.};
	  arrMtxPer[0] =  cos (valFi ) ;
	  arrMtxPer[1] =  sin (valFi ) ;
	  arrMtxPer[2] = -sin (valFi ) ;
	  arrMtxPer[3] =  cos (valFi ) ;
	  TURPointXY pntSegm0_new = pntSegm0.fncLinTrasform(arrMtxPer) ;
	  TURPointXY pntSegm1_new = pntSegm1.fncLinTrasform(arrMtxPer) ;
	  TURPointXY pntCrclCentre_new = pntCrclCentre.fncLinTrasform(arrMtxPer) ;
	   TURPointXY arrPntRez_new [2] ;
	  int ireturn =  fncVerticalSegmentCutCircle( pntCrclCentre_new, valR// ����������
							, pntSegm0_new,   pntSegm1_new
							,arrPntRez_new // ����� ����� � �����������
								) ;
	if (ireturn > 0)
	{
	  arrMtxPer[1] = -arrMtxPer[1] ;
	  arrMtxPer[2] = -arrMtxPer[2] ;
	  arrPntRez [0] = arrPntRez_new[0].fncLinTrasform(arrMtxPer) ;
	  arrPntRez [1] = arrPntRez_new[1].fncLinTrasform(arrMtxPer) ;
	}
	return  ireturn;

  // ��������� � �� , ����� ������ ���� ������������  - �������
	 }
}



// ����������� ������� � ����� ����������
// ���������� 0 ���� �� ������������
// 10 ���� ��������  ������ �������
// 11 �����  pntSegm0 (=arrPntRez[0]) �� ����������,  pntSegm1 �������, ���� ������� �������
// 12 ����� pntSegm1 �� ���������� (=arrPntRez[0] ),  pntSegm0 �������, ���� ������� �������
// 13 ����� pntSegm0 �� ���������� (=arrPntRez[0] ),  pntSegm1 ������, ���� ������� ������
// 14 ����� pntSegm1 (=arrPntRez[0] )�� ���������� ,  pntSegm0 ������, ���� ������� ������
// 15 ������� � �����  pntSegm1 (=arrPntRez[0] )
// 16 ������� � �����  pntSegm0 (=arrPntRez[0] )
// 17 ����� pntSegm0 ������ ,  ����� pntSegm1 �������, 1 ����� �����������
// 18 ����� pntSegm1������ ,  ����� pntSegm0 �������, 1 ����� �����������
// 20  ����� pntSegm0 �������,  pntSegm1 �������, 2 ����� �����������
// 21 ����� pntSegm0 �� ���������� (=arrPntRez[0] ),  ����� pntSegm1 �� ���������� (=arrPntRez[1] ) 2 ����� �����������
// 23  ����� pntSegm1 �� ���������� (=arrPntRez[1] ),  pntSegm0 �������, 2 ����� �����������
// 22  ����� pntSegm0 �� ���������� (=arrPntRez[1] ),  pntSegm1 �������, 2 ����� �����������
// arrPntRez- ������� ���� �����������,
int TURPolygon::fncSegmentCutCircleLine( TURPointXY pntCrclCentre,double valR// ����������
							, TURPointXY pntSegm0,  TURPointXY pntSegm1
							,TURPointXY *arrPntRez // ����� ����� � �����������
								)
{
	if (fabs(pntSegm0.X -pntSegm1.X ) < TOLRNC)
	{
	  return fncVerticalSegmentCutCircleLine( pntCrclCentre, valR// ����������
							, pntSegm0,   pntSegm1
							,arrPntRez // ����� ����� � �����������
								) ;
	}
	else
	{
   	// �������� ������ � ������ ������������ ������ ����� �������� �� �� -��/2 + FI
		 double valFi = - M_PI / 2. + atan( (pntSegm0.Y -pntSegm1.Y )/ (pntSegm0.X -pntSegm1.X )) ;
	  double arrMtxPer[4] = {0.};
	  arrMtxPer[0] =  cos (valFi ) ;
	  arrMtxPer[1] =  sin (valFi ) ;
	  arrMtxPer[2] = -sin (valFi ) ;
	  arrMtxPer[3] =  cos (valFi ) ;
	  TURPointXY pntSegm0_new = pntSegm0.fncLinTrasform(arrMtxPer) ;
	  TURPointXY pntSegm1_new = pntSegm1.fncLinTrasform(arrMtxPer) ;
	  TURPointXY pntCrclCentre_new = pntCrclCentre.fncLinTrasform(arrMtxPer) ;
	   TURPointXY arrPntRez_new [2] ;
	  int ireturn =  fncVerticalSegmentCutCircleLine( pntCrclCentre_new, valR// ����������
							, pntSegm0_new,   pntSegm1_new
							,arrPntRez_new // ����� ����� � �����������
								) ;
	if (ireturn > 0)
	{
	  arrMtxPer[1] = -arrMtxPer[1] ;
	  arrMtxPer[2] = -arrMtxPer[2] ;
	  arrPntRez [0] = arrPntRez_new[0].fncLinTrasform(arrMtxPer) ;
	  arrPntRez [1] = arrPntRez_new[1].fncLinTrasform(arrMtxPer) ;
	}
	return  ireturn;

  // ��������� � �� , ����� ������ ���� ������������  - �������
	 }
}

// ����������� ������������� ������� � ����������
// ���������� 0 ���� �� ������������
// 10 ���� ��������  ������ �������
// 11 ����� pntSegm0 �� ����������,  pntSegm1 �������, ���� ������� �������
// 12 ����� pntSegm1 �� ����������,  pntSegm0 �������, ���� ������� �������
// 201 ����� pntSegm0 ������,  pntSegm1 �������, 2 ����� �����������
// 210 ����� pntSegm1 �����,  pntSegm0 �������, 2 ����� �����������
// 200 ����� pntSegm1 ������,  pntSegm0 ������, 2 ����� �����������
// 211 ����� pntSegm1 �������,  pntSegm0 �������, 2 ����� �����������
// arrPntRez- ������� ���� �����������,
int TURPolygon::fncVerticalSegmentCutCircle( TURPointXY pntCrclCentre,double valR// ����������
							,const TURPointXY pntSegm0,  const TURPointXY pntSegm1
							,TURPointXY *arrPntRez // ����� ����� � �����������
								)
{
	if (fabs(pntSegm0.X -pntSegm1.X ) > TOLRNC)
	{
	 ShowMessage(L"Segment is not vertical. TURPolygon::fncVeticalSegmentCutCircle") ;
	 return 0;
	}
	double arrVectLine [2] ={0.} ;
	arrVectLine [0] = pntSegm1.X -  pntSegm0.X;
	arrVectLine [1] = pntSegm1.Y -  pntSegm0.Y;
	TURPointXY arrPntRezLine [2] ;

	// ����������� ��������������� ������������ ����� � ����������
// ���������� 0 ���� �� ������������
// 1 ���� ��������
// 2 ���� 2 ����� �����������
// arrPntRez- ������ ����� �����������
	 int irez = fncParametricVerticalLineCutCircle(  pntCrclCentre, valR// ����������
							,pntSegm0, arrVectLine // �����
							,arrPntRez // ����� ����� � �����������
							) ;
	double a0 = 0., b0 = 0., b1= 0. ;
	int i_Rez = -1;
	switch (irez)
	{
	case 0:
	return 0 ;

	case 1:
	if ((arrPntRez[0].Y - pntSegm0.Y) * (arrPntRez[0].Y - pntSegm1.Y) <= TOLRNC) return 10;
	else return 0;

	case 2:
	a0 = arrPntRez[1].Y - arrPntRez[0].Y ;
	b0 = pntSegm0.Y - arrPntRez[0].Y ;
	b1 = pntSegm1.Y - arrPntRez[0].Y ;
	i_Rez = TTriang ::IntersectTwoSegmInLine( a0,  b0,  b1);
	  switch( i_Rez)
	  {
		 //
		  case 2:     // ����� pntSegm1 ������,  pntSegm0 ������, 2 ����� �����������
		  case 4:
		  case 14:
		  case 16:
		  case 6:
		  case 5:
		  case 10:
		  case 17:
		  case 18:
		  arrPntRez[0] = pntSegm0;
		  arrPntRez[1] = pntSegm1;
		  return 200;

		  case 1:     //  ����� pntSegm0 ������,  pntSegm1 �������, 2 ����� �����������
		  case 7:
		  arrPntRez [1] = pntSegm0 ;
		  return 201;

		  case 13:     //  ����� pntSegm0 ������,  pntSegm1 �������, 2 ����� �����������
		  case 19:
		   arrPntRez [0] = pntSegm0 ;
		  return 201;

		  case 0:  // ����� pntSegm1 �����,  pntSegm0 �������, 2 ����� �����������
		  case 8:
		  arrPntRez [0] = pntSegm1 ;
		  return 210 ;

		  case 12:   // ����� pntSegm1 �����,  pntSegm0 �������, 2 ����� �����������
		  case 20:
		  arrPntRez [1] = pntSegm1 ;
		  return 210 ;

		  case 3:   // 211 ����� pntSegm1 �������,  pntSegm0 �������, 2 ����� �����������
		  case 15:
		  return 211 ;

		  case 9:
		  case 21:
		  return 11;

		  case 22:
		  return 12 ;


		  default:
		  return 0 ;
		  ;
      }



    default:
		;
	}
	return -2 ;
}



// ����������� ������������� ������� � ����� ����������
// ���������� 0 ���� �� ������������
// 10 ���� ��������  ������ �������
// 11 �����  pntSegm0 (=arrPntRez[0]) �� ����������,  pntSegm1 �������, ���� ������� �������
// 12 ����� pntSegm1 �� ���������� (=arrPntRez[0] ),  pntSegm0 �������, ���� ������� �������
// 13 ����� pntSegm0 �� ���������� (=arrPntRez[0] ),  pntSegm1 ������, ���� ������� ������
// 14 ����� pntSegm1 (=arrPntRez[0] )�� ���������� ,  pntSegm0 ������, ���� ������� ������
// 15 ������� � �����  pntSegm1 (=arrPntRez[0] )
// 16 ������� � �����  pntSegm0 (=arrPntRez[0] )
// 17 ����� pntSegm1 ������ ,  ����� pntSegm0 �������, 1 ����� �����������
// 18 ����� pntSegm1������ ,  ����� pntSegm0 �������, 1 ����� �����������
// 20  ����� pntSegm0 �������,  pntSegm1 �������, 2 ����� �����������
// 21 ����� pntSegm0 �� ���������� (=arrPntRez[0] ),  ����� pntSegm1 �� ���������� (=arrPntRez[1] ) 2 ����� �����������
// 23  ����� pntSegm1 �� ���������� (=arrPntRez[1] ),  pntSegm0 �������, 2 ����� �����������
// 22  ����� pntSegm0 �� ���������� (=arrPntRez[1] ),  pntSegm1 �������, 2 ����� �����������
// arrPntRez- ������� ���� �����������,
int TURPolygon::fncVerticalSegmentCutCircleLine( TURPointXY pntCrclCentre,double valR// ����������
							,const TURPointXY pntSegm0,  const TURPointXY pntSegm1
							,TURPointXY *arrPntRez // ����� ����� � �����������
								)
{
	if (fabs(pntSegm0.X -pntSegm1.X ) > TOLRNC)
	{
	 ShowMessage(L"Segment is not vertical. TURPolygon::fncVeticalSegmentCutCircle") ;
	 return 0;
	}
	double arrVectLine [2] ={0.} ;
	arrVectLine [0] = pntSegm1.X -  pntSegm0.X;
	arrVectLine [1] = pntSegm1.Y -  pntSegm0.Y;
	TURPointXY arrPntRezLine [2] ;
	double miny = min_d(pntSegm0.Y ,pntSegm1.Y) ;
	double maxy = max_d(pntSegm0.Y ,pntSegm1.Y);
	// ����������� ��������������� ������������ ����� � ����������
// ���������� 0 ���� �� ������������
// 1 ���� ��������
// 2 ���� 2 ����� �����������
// arrPntRez- ������ ����� �����������
	 int irez = fncParametricVerticalLineCutCircle(  pntCrclCentre, valR// ����������
							,pntSegm0, arrVectLine // �����
							,arrPntRez // ����� ����� � �����������
							) ;
	double a0 = 0., b0 = 0., b1= 0. ;
	int i_Rez = -1;
	switch (irez)
	{
	case 0:
	return 0 ;


	case 1:
	if ( !(arrPntRez[0].Y  <= (miny -TOLRNC))&&(arrPntRez[0].Y  >= (maxy -TOLRNC))) return 0;
	if (fabs(arrPntRez[0].Y - miny) <= TOLRNC)
	{
	  if (fabs(pntSegm0.Y - miny) <= TOLRNC)
	  {
		  return 15;
	  }
	  else
	  {
		  return 16;
	  }
	}
	if (fabs(arrPntRez[0].Y - maxy) <= TOLRNC)
	{
	   if (fabs(pntSegm0.Y - maxy) <= TOLRNC)
	  {
		  return 15;
	  }
	  else
	  {
		  return 16;
	  }
	}
	return 10;




	case 2:
	a0 = arrPntRez[1].Y - arrPntRez[0].Y ;
	b0 = pntSegm0.Y - arrPntRez[0].Y ;
	b1 = pntSegm1.Y - arrPntRez[0].Y ;
	i_Rez = TTriang ::IntersectTwoSegmInLine( a0,  b0,  b1);
	  switch( i_Rez)
	  {
		//
		case 9:
		case 21:
		arrPntRez[0] = pntSegm1;
		return 11;

		case 4:
		case 16:
		arrPntRez[0] = pntSegm0;
		arrPntRez[1] = pntSegm1;
		return 21;

		case 6:
		case 18:
		arrPntRez[0]= pntSegm1;
		return 14;

		case 5:
		case 17:
		arrPntRez[0]= pntSegm0 ;
		return 13;

		case 10:
		case 22:
		arrPntRez[0]= pntSegm0 ;
		return 11;

		case 1:     //  ����� pntSegm0 ������,  pntSegm1 �������, 2 ����� �����������
		case 13:
		return 13;


		//  ����� pntSegm0 ������,  pntSegm1 �������, 2 ����� �����������
		case 19:
		case 7:
		return 22;

		case 0:  // ����� pntSegm1 �����,  pntSegm0 �������, 1 ����� �����������
		//if (fabs(arrPntRez[0].Y - pntSegm0.Y)<= TOLRNC) arrPntRez[0] = arrPntRez[1];
		arrPntRez[0] = arrPntRez[1];
		return 18;


		case 12:
		return 17;


		case 8:  // 23  ����� pntSegm1 �� ���������� (=arrPntRez[1] ),  pntSegm0 �������, 2 ����� �����������
		case 20:
		return 23 ;


		case 3:   // 20  ����� pntSegm0 �������,  pntSegm1 �������, 2 ����� �����������
		case 15:
		return 20;


		default:
		return 0 ;
		;
      }



    default:
		;
	}

	return -1 ;

}



double TURPolygon::fncCalcProbability( TURPointXY pntCrclCentre)
{
	int iNSteps = 1000;
	double valStep = 10./ ( (double)iNSteps) ;
	double rTemp = 0. ;
	double valIntegr = 0. ;

	for (int i = 0; i < iNSteps; i++)
	{
	  rTemp +=  valStep ;
	  double valFiInside = fncCalcInsideCircleAng( pntCrclCentre,  rTemp);
	  double valLInSide = rTemp *valFiInside ;
	  valIntegr += valLInSide  * exp(-rTemp * rTemp / 2.) * valStep ;
	}
	// ��� �������
   //	double valt = 1. -  exp(-valR0 * valR0 / 2.);
	///


	return valIntegr / 2./M_PI  ;

}


int TURPolygon::fncIntersectConvexPlgns( TURPolygon &plgInp0,TURPolygon &plgInp1, TURPolygon &plgOut)
{
  if(  !(plgInp0.IsConv() && plgInp1.IsConv() ) )return -2;
  TURPolygon plgArrP[2] ;
  plgArrP[0] = plgInp0;
  plgArrP[1] = plgInp1;

  TURPolygon plgArrPTemp[2] ;
  plgArrPTemp[0] = plgInp0;
  plgArrPTemp[1] = plgInp1;

  if (!IncludeAllIntersectingPoints( plgArrP[0],plgArrP[1])) return -1 ;
  TURPointXY *ppntArr = new TURPointXY [ plgArrP[0].NumPoints + plgArrP[1].NumPoints ] ;




  int iNumPoints = 0 ;
  int iNumCurPlg = 0;
  int iNumRestPlg = 1;

  // ����� ������ �������� ��������� 0 �������������� �������� 1
  int iNum0 = fncFindNumFirstCommonVert(plgArrP[0], plgArrP[1]);
  if (iNum0 < 0)
  {
  return -1; // �� ������������
  }

  iNumPoints = 1;
  ppntArr [0] =  plgArrP[iNumCurPlg].Points[iNum0];


  for (int i = 0; i < 2 *(plgArrP[0].NumPoints + plgArrP[1].NumPoints ); i++)
  {

	 int iNum1 = (iNum0 + 1) % plgArrP[iNumCurPlg].NumPoints ;

	 if(plgArrPTemp[iNumRestPlg].PntInPolygon( plgArrP[iNumCurPlg].Points[iNum1]) > 0)
	 {
	   int iTemp =  iNum0 ;
	   iNum0 = iNum1 ;
	   iNum1 = iTemp ;
	   ppntArr [iNumPoints] =  plgArrP[iNumCurPlg].Points[iNum0];
	   iNumPoints++;
	   if (dist(ppntArr [iNumPoints -1]  ,ppntArr [0] )< TOLRNC)
	   {
		 break ;
	   }
	 }
	 else
	 {
		 iNumCurPlg = (1 + iNumCurPlg)% 2;
		 iNumRestPlg = (1 + iNumRestPlg )% 2;
		 iNum0 = plgArrP[iNumCurPlg].findNumVertex(ppntArr [iNumPoints -1]);
		 if (iNum0 < 0) return -1;
		 continue;
	 }
  }

  plgOut = TURPolygon( iNumPoints, ppntArr) ;
  plgOut.ExcludeExcessVertexesFromRing() ;
  delete [] ppntArr ;
  return  1 ;
}

 int TURPolygon::findNumVertex(TURPointXY pntP)
 {

  for (int i =0; i < (NumPoints - 1); i++)
  {
	if (dist(Points[i]  ,pntP )< TOLRNC) return i ;
  }
  return -1;
 }




 // ����� ������ ������ �������� ��������� plg0 �������������� �������� plg1
int TURPolygon::fncFindNumFirstCommonVert(TURPolygon plg0,TURPolygon plg1)
{


  int iNum0 = -1;
  for (int i = 0; i <  (plg0.NumPoints - 1 ); i++)
  {

	// ����������:
// 0 - ����� ��� ��������
// 1 - ����� � ����� ��������
// 3  - ����� p0  ����� �� ����� ��������
// 4  - �����  p0  �������� �������� ��������


   if(plg1.PntInPolygon( plg0.Points[i]) > 0)
   {
	 iNum0 = i ;
	 break;
   }
  }
	return iNum0;
}


bool TURPolygon::IsConv()
{
	return true ;
}

// ���� �������� �� ������������ ��������, �� ���������� false
// ������ ��� �������� ������!!!
bool TURPolygon::IncludeAllIntersectingPoints( TURPolygon &plgP0, TURPolygon &plgP1)
{
	while(1)
	{
		bool bChange = false ;
		for ( int i = 0; i < (plgP0.NumPoints-1) ; i++)
		{
		  for (int j = 0; j < (plgP1.NumPoints-1); j++)
		  {
			// ����������� 2-� ��������
			//���������� true ���� ������� ������� � false � ��������� ������
			//���� true: ���� ������� ����� �� ����� ������ - �� p0 -p1 - ������� �����������
			// ���� �� ������� ������, �� p0 - ����� �����������, � p1 = NULL
			TURPointXY pntT0,pntT1,pntT2,pntT3,pntT4, pntP0 ;

			int ipCaseType = -20;
			if( TTriang::IntersectTwoSegments(
			plgP0.Points[i], 	plgP0.Points[i + 1]//1-�� �������
			,plgP1.Points[j], 	plgP1.Points[j + 1]  // 2-�� �������
			, &pntP0 // ����� �����������
			, &ipCaseType //
						  )
			)
					{
					  switch( ipCaseType)
					  {
						  case 0:
						  case 1:
						  case 2:
						  case 3:
						  case 4:
						  case 5:
						  case 6:
						  case 7:
						  case 8:
						  case 9:
						  case 10:
						  return false; // �������� �� ������������ ��������

						  case 11:
						  break ;

						  case 12:
						   pntT0 = plgP1.Points[j + 1] ;//  ���� �������� � �������  plgP0
						   pntT1 =  plgP0.Points[i] ;   //  ���� �������� � �������  plgP1
						   plgP0.AddVert(pntT0,i, 1 );
						   plgP1.AddVert(pntT1,j, 1 );
						   bChange = true ;
						   break ;
						   case 13:
						   pntT0 = plgP1.Points[j ] ;//  ���� �������� � �������  plgP0
						   pntT1 =  plgP0.Points[i + 1] ;   //  ���� �������� � �������  plgP1
						   plgP0.AddVert(pntT0,i, 1 );
						   plgP1.AddVert(pntT1,j, 1 );
						   bChange = true ;
						   break;

						   case 14:
						   plgP0.AddVert(plgP1.Points[j + 1],i, 1 );
						   plgP0.AddVert(plgP1.Points[j ],i, 1 );
						   bChange = true ;
						   break;

						   case 15:
						   plgP1.AddVert(plgP0.Points[i + 1], j, 1 );
						   plgP1.AddVert(plgP0.Points[i ], j, 1 );
						   bChange = true ;
						   break;

						   case 16:
						   break;

						   case 17:
						   plgP0.AddVert(plgP1.Points[j + 1],i, 1 );
						   bChange = true ;
						   break;

						   case 18:
						   plgP0.AddVert(plgP1.Points[j],i, 1 );
						   bChange = true ;
						   break;

						   case 19:
						   plgP1.AddVert(plgP0.Points[i + 1] , j, 1 );
						   bChange = true ;
						   break;

						   case 20:
						   plgP1.AddVert(plgP0.Points[i ] , j, 1 );
						   bChange = true ;
						   break;

						   case 21:
						   case 22:
						   case 23:
						   break;

						   case 24:
						   plgP0.AddVert(pntP0, i, 1 );
						   plgP1.AddVert(pntP0, j, 1 );
						   bChange = true ;
						   break;

						   case 25:
						   plgP1.AddVert(plgP0.Points[i + 1], j, 1 );
						   bChange = true ;
						   break;

						   case 26:
						   plgP1.AddVert(plgP0.Points[i ], j, 1 );
						   bChange = true ;
						   break;

						   case 27:
						   plgP0.AddVert(plgP1.Points[j +1],i, 1 );
						   plgP1.AddVert(pntP0, j, 1 );
						   bChange = true ;
						   break;

						   case 28:
						   plgP0.AddVert(plgP1.Points[j ],i, 1 );
						   plgP1.AddVert(pntP0, j, 1 );
						   bChange = true ;
						   break;

						  default:
						  break ;
					  }
				 }
				 if(bChange) break ;
		  }
		  if(bChange) break ;
		}
	   if ( !bChange) break ;


	}

	return true ;
}

double   TURPolygon::fncCalcInsideCircleAng(const TURPointXY pntCrclCentre, double valR)
{
  double *parrFi = new double [ 2 * NumPoints ];
  memset(parrFi, 0,  2 * NumPoints * sizeof(double));
  TURPointXY *parrpntRez = new  TURPointXY[ 2 * NumPoints ];
  memset (parrFi, 0,  2 * NumPoints * sizeof(double));
  int quantPoints = 0;
  TURPointXY arrPntRez[2] ;
  for (int i = 0; i < (NumPoints -1); i++)
  {
	// ����������� ������� � ����������
// ����������� ������������� ������� � ����������
// ���������� 0 ���� �� ������������
// 10 ���� ��������  ������ �������
// 11 ����� pntSegm0 �� ����������,  pntSegm1 �������, ���� ������� �������
// 12 ����� pntSegm1 �� ����������,  pntSegm0 �������, ���� ������� �������
// 201 ����� pntSegm0 ������,  pntSegm1 �������, 2 ����� �����������
// 210 ����� pntSegm1 �����,  pntSegm0 �������, 2 ����� �����������
// 200 ����� pntSegm1 ������,  pntSegm0 ������, 2 ����� �����������
// 211 ����� pntSegm1 �������,  pntSegm0 �������, 2 ����� �����������
// arrPntRez- ������� ���� �����������,
	int irez = fncSegmentCutCircle(  pntCrclCentre, valR// ����������
							, Points[i],  Points[i + 1]
							,arrPntRez // ����� ����� � �����������
								);
	switch( irez)
	{
		case 0:
		continue ;

		case 10:
		parrpntRez[quantPoints] = arrPntRez[0] ;
		quantPoints++;
		continue ;

		case 11 :
		parrpntRez[quantPoints] = arrPntRez[0] ;
		quantPoints++;
		break;

		case 12:
		parrpntRez[quantPoints] = arrPntRez[1] ;
		quantPoints++;
		break;

		case 201:
		if ( dist(arrPntRez[0],Points[i]) <   TOLRNC)
		{
		   parrpntRez[quantPoints] = arrPntRez[1] ;
		}
		else
		{
		  parrpntRez[quantPoints] = arrPntRez[0] ;
		}
		quantPoints++;
		break;

		case 210:
		if ( dist(arrPntRez[0],Points[i + 1]) <   TOLRNC)
		{
		   parrpntRez[quantPoints] = arrPntRez[1] ;
		}
		else
		{
		  parrpntRez[quantPoints] = arrPntRez[0] ;
		}
		quantPoints++;

		break;

		case 200:

		if (( fabs(dist( arrPntRez[0],pntCrclCentre) - valR)) < TOLRNC)
		{
		  parrpntRez[quantPoints] = arrPntRez[0];
		  quantPoints++;
		}
		if (( fabs(dist( arrPntRez[1],pntCrclCentre) - valR)) < TOLRNC)
		{
		  parrpntRez[quantPoints] = arrPntRez[1];
		  quantPoints++;
		}
		break;

		case 211:
		parrpntRez[quantPoints] = arrPntRez[0] ;
		parrpntRez[quantPoints+ 1] = arrPntRez[1] ;
		quantPoints = quantPoints + 2;
		break;

		default:
		break;
    }
  }
  for (int i = 0; i < quantPoints; i++)
  {
	parrFi[i] = fncCalcFi(parrpntRez[i] ,pntCrclCentre) ;
  }
  qsort(parrFi, quantPoints, sizeof(double),cmp_);

  // 2.
  bool bChange = true;
  while(bChange)
  {
	 bChange = false ;
	 for (int i = 0; i < quantPoints -1; i++)
	 {
	   if (fabs (parrFi[i + 1] - parrFi[i]) <   TOLRNC)
	   {
		 memcpy( &parrFi[i + 1],  &parrFi[i + 2] , (quantPoints - i - 2) * sizeof(double)) ;
		 quantPoints --;
		 bChange = true;
		 break ;

	   }
	 }
	 if ( fabs(parrFi[quantPoints -1] - parrFi[0] - 2. * M_PI) < TOLRNC)
	 {
		 quantPoints --;
		 bChange = true;
	 }
  }
	///

	// 3.

	double valFiRez = 0.;
	for (int i = 0; i < (quantPoints -1); i++)
	{
	  double fi = (parrFi[i] + parrFi[i + 1])/ 2. ;
	  TURPointXY pntTemp(pntCrclCentre.X + valR * cos(fi),pntCrclCentre.Y + valR * sin(fi));
	  if (PntInPolygon( pntTemp) >0 ) valFiRez  += (parrFi[i + 1] - parrFi[i ] );
	}
	double fi = parrFi[0] / 2. ;
	if (fabs( fi)< TOLRNC)
	{
	  fi = parrFi[quantPoints -1] + ( 2. * M_PI - parrFi[quantPoints -1])/ 2.;
	}
    TURPointXY pntTemp(pntCrclCentre.X + valR * cos(fi),pntCrclCentre.Y + valR * sin(fi));
	if (PntInPolygon( pntTemp) >0 ) valFiRez  += (parrFi[0] + 2. * M_PI - parrFi[quantPoints -1]) ;
  delete parrFi ;
  delete [] parrpntRez ;
  return valFiRez;
}
double   TURPolygon::fncCalcFi(const TURPointXY pntP,const TURPointXY pntCrclCentre)
{
   // ���� ����� ���� X � ������ x,y �������� ����������� - ������� ������� �������
   // ���� �� -Pi �� PI
   // ���� x=0 � y = 0, �� ���� ����������� � ������� ���������� false
   // � ���� ������ true
   double prez = 0.;
   TURPolygon::Atan2_(pntP.Y - pntCrclCentre.Y, pntP.X - pntCrclCentre.X,  &prez) ;
   if (prez < 0.) prez += 2 * M_PI;

	return prez  ;
}

// ������� ��� ���������������


// ���������� � ������� ��������� ������������  ������������ ���� �������� ����������
// ����� ���
// �������� ��������� !!!
//  INPUT:
//  pntCrclCentre - ����� ����������
// OUTPUT:
// pntSegm0, pntSegm1 - �����, ���� ������� � ����������
// ���������� false ���� ����� ���������� ����� ������ ���������
// true � ��������� ������
bool   TURPolygon::fncFindMaxSegm(TURPointXY pntCrclCentre  // ����� ����������
			, TURPointXY &pntSegm0, TURPointXY &pntSegm1 )
 {
    	 // ����������:
// 0 - �� ����������
// 1 - ����������
// 3  - ����� p0  ����� �� ����� ��������
// 4  - �����  p0  �������� �������� ��������

	 if ( PntInPolygon( pntCrclCentre) == 1) return false;
   // ��� ������ ������� ������ ���������� �� ������� ���� ������� �����
   // ���� ����������� �� �� ���������� � ������ �������� -  ��������
   // ��������� ����� ���� ������ ������� ����������� � ���������
   // �������� ����� ������� ����
   //

   // ���������� �������
   double valArc = 0.;  // ������ ����

   ///
   TURPointXY pntSeg0,pntSeg1 ;
   for (int i = 0 ; i < (NumPoints -1); i++)
   {
	 double valR = dist(Points[i], pntCrclCentre) ;
	 TURPointXY arrPntRez [2];

	 for (int j1  = 0; j1 < NumPoints -3; j1++)
	 {
		int j  = ( i + 1 + j1)% (NumPoints-1);
		// ����������� ������� � ����������
// ����������� ������������� ������� � ����������
// ���������� 0 ���� �� ������������
// 10 ���� ��������  ������ �������
// 11 ����� pntSegm0 �� ����������,  pntSegm1 �������, ���� ������� �������
// 12 ����� pntSegm1 �� ����������,  pntSegm0 �������, ���� ������� �������
// 201 ����� pntSegm0 ������,  pntSegm1 �������, 2 ����� �����������
// 210 ����� pntSegm1 �����,  pntSegm0 �������, 2 ����� �����������
// 200 ����� pntSegm1 ������,  pntSegm0 ������, 2 ����� �����������
// 211 ����� pntSegm1 �������,  pntSegm0 �������, 2 ����� �����������
// arrPntRez- ������� ���� �����������,
		int irez = fncSegmentCutCircle(  pntCrclCentre, valR// ����������
			  , Points [  j ] , Points [ ( j + 1)%(NumPoints -1)]
							,arrPntRez // ����� ����� � �����������
								);
		TURPointXY p0, p1 ;
		switch(irez)
		{
			case 10:
			case 11:
			case 12:
			case 201:
			case 210:
				p0 = Points[i] - pntCrclCentre;
				p1 = arrPntRez[0] - pntCrclCentre;
				if(  (TURPointXY::calcAng(p0,p1)) *  valR > valArc  )
				{
				pntSeg1 =  arrPntRez[0] ;
				pntSeg0 =  Points[i];
				}
				break ;
			case 211:
			case 200:
			case 0:
			default:
			break ;
        }

	 }
   }
   pntSegm0 = pntSeg0 ;
   pntSegm1 = pntSeg1 ;
   return true ;
 }
//����������  ��������� ������������ ���������� � ����� ���� � ������� ���������
// INPUT:
// pntCrclCentre  - ����� ����������
// OUTPUT:
// pntSegm0, pntSegm1 - ����� �������� �����, �������� � ���� ���������
//
//
//
//
 bool   TURPolygon::fncFindMaxArc(TURPointXY pntCrclCentre  // ����� ����������
			, TURPointXY &pntSegm0, TURPointXY &pntSegm1  )
{
	if (!fncFindMaxSegm( pntCrclCentre  // ����� ����������
			,pntSegm0, pntSegm1 )) return false ;

	TURPointXY pntPnt = TURPointXY::ParamPoint(pntSegm0, pntSegm1, 0.5);
	double valR =  pntPnt.Norm();
	int quantPoints = 0 ;
	for (int i = 0 ; i < (NumPoints -1); i++)
   {
	 TURPointXY arrPntRez [2];
		// ����������� ������� � ����������
// ����������� ������������� ������� � ����������
// ���������� 0 ���� �� ������������
// 10 ���� ��������  ������ �������
// 11 ����� pntSegm0 �� ����������,  pntSegm1 �������, ���� ������� �������
// 12 ����� pntSegm1 �� ����������,  pntSegm0 �������, ���� ������� �������
// 201 ����� pntSegm0 ������,  pntSegm1 �������, 2 ����� �����������
// 210 ����� pntSegm1 �����,  pntSegm0 �������, 2 ����� �����������
// 200 ����� pntSegm1 ������,  pntSegm0 ������, 2 ����� �����������
// 211 ����� pntSegm1 �������,  pntSegm0 �������, 2 ����� �����������
// arrPntRez- ������� ���� �����������,
     int irez = fncSegmentCutCircle(  pntCrclCentre, valR// ����������
			  , Points [  i ] , Points [ i + 1]
							,arrPntRez // ����� ����� � �����������
								) ;
   switch (irez)
   {
   case 10:
   case 11:
   case 12:
   case 201:
   case 210:
   case 200:
   case 211:
	if(  quantPoints == 0 )
		  {
			pntSegm0 =  arrPntRez[0] ;
			quantPoints++;
		  }
	 else{
			if(  quantPoints == 1 )
			{
			pntSegm1 =  arrPntRez[0] ;
			quantPoints++;
			}
		  }

   break ;

	 default:
   break;
	   ;
   }

   if (quantPoints == 2) break ;


   }
	if (quantPoints!= 2) return false ;
	return true ;
}

// ���������� �������� �������� ������ �����
TURPolygon   TURPolygon::Conv(TURPointXY *parrPnts0 // ������ �����, input
			, const int lenarr0 // ����� ������� ����� , input
				)
{
	TURPointXY *parrPnts = new TURPointXY [lenarr0];
	memcpy(parrPnts, parrPnts0, sizeof(TURPointXY)* lenarr0 );
	int lenarr = -1;
	TURPointXY::subtractEqualPoints(parrPnts // ������ �����, input
			,  lenarr0 //  ����� ������� ����� , input
			, TOLRNC // ��������
			, &lenarr // �-�� ������������ �����
				) ;
	int numPoints = 0;


	if (lenarr < 3)
	{
      TURPointXY pPntTemp[3];
	  if (lenarr == 1)
	  {

	  pPntTemp[0] = parrPnts [0];
	  pPntTemp[1] = parrPnts [0];
	  pPntTemp[2] = parrPnts [0];
	  }
	  if (lenarr == 2)
	  {
	  TURPointXY pPntTemp[3];
	  pPntTemp[0] = parrPnts [0];
	  pPntTemp[1] = parrPnts [1];
	  pPntTemp[2] = parrPnts [0];
	  }

	  return TURPolygon(3, pPntTemp);
	}


	int *piarrNumPoints = (int *)malloc(sizeof(int ) * (lenarr + 1));
// ���������� ������ ���� ������ �������� ��������
	findTwoFirstVertexes(parrPnts // ������ �����, input
			, lenarr // ����� ������� ����� , input
			 ,piarrNumPoints );
 //parrPnts[0].WriteSetSHPFiles(L"E:\\Ametist\\28-03-2018\\COAST\\Optimal_Strat_Rez\\parrPnts[piarrNumPoints[0]].shp", &parrPnts[piarrNumPoints[0]], 1);
//parrPnts[0].WriteSetSHPFiles(L"E:\\Ametist\\28-03-2018\\COAST\\Optimal_Strat_Rez\\parrPnts[piarrNumPoints[1]].shp", &parrPnts[piarrNumPoints[1]], 1);
   numPoints = 2 ;
///
  for (int i = 0; i < lenarr; i++)
  {
	piarrNumPoints[numPoints] =  findNextVertex( parrPnts, lenarr, piarrNumPoints, numPoints);
 //	 parrPnts[0].WriteSetSHPFiles(L"E:\\Ametist\\28-03-2018\\COAST\\Optimal_Strat_Rez\\parrPnts[piarrNumPoints[numPoints]].shp", &parrPnts[piarrNumPoints[numPoints]], 1);

	numPoints++;
	if (piarrNumPoints[numPoints-1] == piarrNumPoints[0]) break;


  }
   TURPointXY  *arrPoints =  (TURPointXY  *)malloc(sizeof(TURPointXY ) * numPoints);
   for (int i=0; i < numPoints; i++)
	 {
	 arrPoints[i] = parrPnts [piarrNumPoints[i]] ;
	 }
  TURPolygon plg(numPoints, arrPoints);
  if(plg.calcVectSq()<0.)
  {
	plg.flip();
  }


	free(piarrNumPoints);
	free(arrPoints) ;
	delete []parrPnts;
	return  plg;
}


//  ���������� ������ ���� ������ �������� ��������
// ������ ������ ��������
//
//
void TURPolygon::findTwoFirstVertexes(TURPointXY *parrPnts // ������ �����, input
			, const int lenarr // ����� ������� ����� , input
			, int *piarrnum  // ������ ������� ������� � ������ ������, otput
			  )
{

   for (int i =0; i < lenarr; i++)
   {
	 for (int j = i + 1; j < lenarr; j++)
	 {
		 if (IsConvEdge(parrPnts,lenarr, i,j))
	   {
		 piarrnum [0] = i;
		 piarrnum [1] = j;
		 return;
	   }
	 }
   }
}

// �������� ��� ������� ����������� ����� � �������� i � j
// �������� ������ �������� ��������
bool TURPolygon::IsConvEdge( TURPointXY *parrPnts // ������ �����, input
			, const int lenarr // ����� ������� ����� , input
			, const int i0 // ����� ������ �������
			, const int j0 // ����� ������ �������
			)
{

  bool bInit =  false;
  int iSign = 0;
  for (int i =0  ; i < lenarr; i++)
  {
	if ((i == i0)|| (i == j0)) continue;
	TTriang triang(parrPnts[i0], parrPnts[j0], parrPnts[i]);
	int iSignSq =  fncSIGN_ (triang.calcSq());
	if (iSignSq == 0) continue ;

	if ( !bInit)
	{
	  iSign = iSignSq ;
	  bInit = true ;
	  continue ;
	}
	if (iSign * iSignSq < 0 )
	{
	return false;
	}

  }
  return true ;
}

/*
// ����������� ��������� ������� �������� ��������
int TURPolygon::findNextVertex( TURPointXY *parrPnts // ������ �����, input
			, const int lenarr // ����� ������� ����� , input
			 ,int * piarrNumPoints // ������ ������� ��� ��������� ������
			 , const int numPoints // ����� �������  ������� ��� ��������� ������
			 )
{
	int i0 =  piarrNumPoints[ numPoints-1] ;

	for (int j = 0; j < lenarr; j++)
	{
		if (IsBelongedToIntArray(j,&piarrNumPoints[1], numPoints -1))continue ;
		// 09.03.2018
	  /*	TTriang triang( parrPnts[piarrNumPoints[ numPoints-2]], parrPnts[i0], parrPnts[j]);
		if( fabs(triang.calcSq()) < 0.00000001)
		{ // 3 ����� �� ������
		 if ((TURPointXY::dist(triang.m_pVert[0],triang.m_pVert[2]) > (TURPointXY::dist(triang.m_pVert[0],triang.m_pVert[1]))
		 {
		   piarrNumPoints[ numPoints-1] = j;
		 }
		 return -1;
		}
		//
		*/
	  /*	if (( numPoints== 2)&& (j == piarrNumPoints[0])) continue;

		if (IsConvEdge(parrPnts,lenarr, i0,j))
		{
		return j;
		}
	}

	return -1;
}
*/

// ����������� ��������� ������� �������� ��������
int TURPolygon::findNextVertex( TURPointXY *parrPnts // ������ �����, input
			, const int lenarr // ����� ������� ����� , input
			 ,int * piarrNumPoints // ������ ������� ��� ��������� ������
			 , const int numPoints // ����� �������  ������� ��� ��������� ������
			 )
{
	int i0 =  piarrNumPoints[ numPoints-1] ;

	for (int j1 = 0; j1 < lenarr; j1++)
	{
		int j = (i0 + 1 + j1)% lenarr ;
		if (IsBelongedToIntArray(j,&piarrNumPoints[1], numPoints -1))continue ;

		if (( numPoints== 2)&& (j == piarrNumPoints[0])) continue;

		if (IsConvEdge(parrPnts,lenarr, i0,j))
		{
		TTriang triang(parrPnts[piarrNumPoints[numPoints -2]], parrPnts[piarrNumPoints[numPoints -1]], parrPnts[j]);
		int iSignSq =  fncSIGN_ (triang.calcSq());
		if (iSignSq == 0)
		{
		  double d1 = dist(parrPnts[piarrNumPoints[numPoints -2]],parrPnts[j]);
		  double d2 = dist(parrPnts[piarrNumPoints[numPoints -2]],parrPnts[piarrNumPoints[numPoints -1]]);
		 // parrPnts[0].WriteSetSHPFiles(L"E:\\Ametist\\28-03-2018\\COAST\\Optimal_Strat_Rez\\parrPnts[piarrNumPoints[numPoints -2]].shp", &parrPnts[piarrNumPoints[numPoints -2]], 1);
		//  parrPnts[0].WriteSetSHPFiles(L"E:\\Ametist\\28-03-2018\\COAST\\Optimal_Strat_Rez\\parrPnts[piarrNumPoints[numPoints -1]].shp", &parrPnts[piarrNumPoints[numPoints -1]], 1);
		 // parrPnts[0].WriteSetSHPFiles(L"E:\\Ametist\\28-03-2018\\COAST\\Optimal_Strat_Rez\\parrPnts[j].shp", &parrPnts[j], 1);

		 if (dist(parrPnts[piarrNumPoints[numPoints -2]],parrPnts[j]) <= dist(parrPnts[piarrNumPoints[numPoints -2]],parrPnts[piarrNumPoints[numPoints -1]]))
		 {
          continue;
		 }
		}
		return j;
		}
	}

	return -1;
}


//
bool TURPolygon::IsBelongedToIntArray(const int j // ����������� �����
									 ,int *piarrNumPoints // ������ �������
									 ,const int numPoints // ����� �������  �������
									   )
{
   for (int i = 0; i < numPoints; i++)
   {
	if (j == piarrNumPoints[i]) return true;

   }
	return false;
}


// ��������� ������� ���������� ������ �� ���������������
void TURPolygon::flip()
{
	for (int n= 0; n < NumParts; n++)
	{
		 flipPart(n);
	}
}
// ��������� ������� ���������� ������ � ��������� ��������� � ������ n
void TURPolygon::flipPart(const int n)
{
  if (n >= NumParts)
	{
		 ShowMessage(L"Error flipPart: n >= NumParts");
	   Abort() ;
	}
	TURPointXY *pPXY = (TURPointXY *)&Points [Parts[n]];
	int quanP = ( n == (NumParts -1))?(NumPoints - Parts[n] ):( Parts[n +1] - Parts[n] );

	for (int i =0; i < (quanP /2); i++)
	{
	   TURPointXY pnt = pPXY [quanP -1 - i];
	   pPXY [quanP -1 - i] =  pPXY [i];
	   pPXY [i] = pnt ;
	}

}

 /*******************************************************************************************************************************/
 /*******************************************************************************************************************************/
 /*******************************************************************************************************************************/
 /*********** ������� �� �������� � ����� ********************************************************************************************************************/
 /*******************************************************************************************************************************/
 /*******************************************************************************************************************************/


int cmp_(const void * a,  const void *b)
{
	double c = *((double*)a ) ;
	double d = *((double*)b ) ;
	if (c == d) return 0;
	return (c > d)?1:-1;

}

// ������ ������ �� ������ ����� � ������� -  pointLine �  arrVectLine
// ��������� ����� ��������� � ������� ���������� ������������� �������
//� ������� ������� �� �������� ������
// ppointLine = NULL
// arrVTransf = NULL
bool   fncFindMaxEscibedCircle( TURPointXY *ppointLine, double *arrVTransf, TURPolygon plgPlg,
	TURPointXY &pntCentre, double &valR)
{
	if ((plgPlg.NumPoints < 4)|| (plgPlg.NumPoints > 5))
	{
	ShowMessage (L"ERROR#2  TURPolygon::fncFindMaxCircle")  ;
	return false;
	}

	TURPointXY pntArrCentre[6];
	double arrR[6] = {0.} ;
	int quantCentres = 0;
	TURPointXY pCut ;
	if (plgPlg.NumPoints == 4)
	{
	return plgPlg.fncFindEscribedCircle(0, 1,  pntCentre, valR);
	}

	TURPointXY pntCentreTemp;
	double valRTemp ;
	bool bSuit = true;
	for (int i = 0; i < 4 ; i++)
	{

		if (!plgPlg.fncFindEscribedCircle(i, i + 1,  pntCentreTemp, valRTemp)) return false ;
		bSuit = true;
		for (int j = 0; j < 2; j++)
		{
		int j1 = (i + 2 + j) % 4;
		TURPointXY arrPntRez[2];
		// ����������� ������� � �����
		// ���������� 0 ���� �� ������������
		// 10 ���� ��������  ������ �������
		// 11 ����� pntSegm0 �� ����������,  pntSegm1 �������, ���� ������� �������
		// 12 ����� pntSegm1 �� ����������,  pntSegm0 �������, ���� ������� �������
		// 201 ����� pntSegm0 ������,  pntSegm1 �������, 2 ����� �����������
		// 210 ����� pntSegm1 �����,  pntSegm0 �������, 2 ����� �����������
		// 200 ����� pntSegm1 ������,  pntSegm0 ������, 2 ����� �����������
		// 211 ����� pntSegm1 �������,  pntSegm0 �������, 2 ����� �����������
		// arrPntRez- ������� ���� �����������,
		int irez =  plgPlg.fncSegmentCutCircle( pntCentreTemp, valRTemp// ����������
			,plgPlg.Points [j1],  plgPlg.Points [(j1 + 1)%4]
			,arrPntRez // ����� ����� � �����������
				);
		switch(irez)
		{
		case 10:
		case 11:
		case 12:
		case 0:
		break;


		case 201:
		case 210:
		case 200:
		case 211:
		bSuit = false;
		break;
		default:
		break ;

		}
		if (!bSuit)break ;

		}

		if (bSuit)
		{
		arrR[quantCentres]  = valRTemp;
		pntArrCentre[quantCentres] = pntCentreTemp;
		quantCentres++ ;
		}
	}

	for (int i = 0; i < 2 ; i++)
	{
	if (!plgPlg.fncFindEscribedCircle(i, (i + 2)%4,  pntCentreTemp, valRTemp)) continue ;
	bSuit = true;

	for (int j = 0; j < 2; j++)
	{
	int j0 = ( i + 1 + j) % 4;
	int j1 = ( i + 3 + j) % 4;
	TURPointXY arrPntRez[2];
	// ����������� ������� � ����������
	// ����������� ������������� ������� � ����������
	// ���������� 0 ���� �� ������������
	// 10 ���� ��������  ������ �������
	// 11 ����� pntSegm0 �� ����������,  pntSegm1 �������, ���� ������� �������
	// 12 ����� pntSegm1 �� ����������,  pntSegm0 �������, ���� ������� �������
	// 201 ����� pntSegm0 ������,  pntSegm1 �������, 2 ����� �����������
	// 210 ����� pntSegm1 �����,  pntSegm0 �������, 2 ����� �����������
	// 200 ����� pntSegm1 ������,  pntSegm0 ������, 2 ����� �����������
	// 211 ����� pntSegm1 �������,  pntSegm0 �������, 2 ����� �����������
	// arrPntRez- ������� ���� �����������,
	int irez =  plgPlg.fncSegmentCutCircle( pntCentreTemp, valRTemp// ����������
		,plgPlg.Points [j0],  plgPlg.Points [j1 ]
		,arrPntRez // ����� ����� � �����������
			);
	switch(irez)
	{
	case 10:
	case 11:
	case 12:
	case 0:
	break;

	case 201:
	case 210:
	case 200:
	case 211:
	bSuit = false;
	break;
	default:
	break ;

	}
	if (!bSuit)break ;

	}

	if (bSuit)
	{
	arrR[quantCentres]  = valRTemp;
	pntArrCentre[quantCentres] = pntCentreTemp;
	quantCentres++ ;
	}
	}



	if (quantCentres < 1 )
	{
	ShowMessage(L"ERROR#1 TURPolygon::fncFindMaxCircle");
	return false;
	}
	int iNumArgMax = -1;
	valR = MaxDoubleArray(arrR, quantCentres, &iNumArgMax ) ;
	pntCentre =  pntArrCentre[iNumArgMax] ;
	return true;
}

// ������ ������ �� ������ ����� � ������� -  pointLine �  arrVectLine
// ��������� ����� ��������� � ������� ���������� ������������� �������
//� ������� ������� �� �������� ������
bool   fncFindMaxCircle( TURPointXY *ppointLine, double *arrVectLine, TURPolygon plgPlg
	  ,TURPointXY &pntCentre, double &valR)
{
	TURPointXY pointLine = *ppointLine ;
	if ((plgPlg.NumPoints < 4)|| (plgPlg.NumPoints > 5))
	{
	  ShowMessage (L"ERROR#2  TURPolygon::fncFindMaxCircle")  ;
	  return false;
	}
	TURPointXY pntSegm0,pntSegm1 ;
	if (!plgPlg.fncFindSecantSegm( pointLine, arrVectLine
	   ,pntSegm0,pntSegm1))
	{
	  ShowMessage(L"ERROR# 0 TURPolygon::fncFindMaxCircle");
	  return false;
	}
	TURPointXY pntArrCentre[6];
	double arrR[6] = {0.} ;
	int quantCentres = 0;
	TURPointXY pCut ;

	 double valBisectAng = 0.;
	 for (int i = 0; i < (plgPlg.NumPoints-1) ; i++)
	 {
		valBisectAng = plgPlg.fncFindBisectorAng(i) ;

		 double arrVectBisectLine [2] = {0.};
		 arrVectBisectLine[0] = cos(valBisectAng) ;
		 arrVectBisectLine[1] = sin(valBisectAng) ;
		 // ����������� ����� � �������(��������)
		// ����������:
		// 0 - �� ����������
		// 1 - ����������
		// 2  - ������ �������� ����� ������� ��������
		// 3  - ����� p0,    ����� ������ ��������
		// 4  - �����  p0  �������� �������� ��������
		// 5  - ������� ����� �� �����
	 int  irez = plgPlg.ParametricLineCutSegment(pntSegm0,pntSegm1// �������
							,plgPlg.Points[i],arrVectBisectLine // ������
							,pCut // ����� �����������
								) ;
		 bool bProper = true;
		 if (irez == 1)
		 {
		   TTriang tr1 = TTriang( plgPlg.Points[i],plgPlg.Points[i + 1],pCut);
		   // ������
		  double val_r = 2. * fabs(tr1.calcSq())/ TURPointXY::dist(plgPlg.Points[i],plgPlg.Points[i + 1]);
		   for (int j = 0; j < (plgPlg.NumPoints-1); j++)
		   {
			  TURPointXY pntRez;
			  if (!plgPlg.fncCheckPositionCircle_and_Edge(pCut
			  ,val_r,  plgPlg.Points[j],plgPlg.Points[j + 1] , pntRez ))
			  {
				 bProper = false ;
				 break;
			  }

		   }
			if (bProper)
			{
			 pntArrCentre[quantCentres] =  pCut ;
			 arrR[quantCentres] = val_r ;
			 quantCentres++ ;
			}
		 }


	 }

	 if(plgPlg.NumPoints == 5)
	 {
	   for (int i = 0; i < 2 ; i++)
	   {
		double valBisectAng = 0;
		TURPointXY pntBsctVertex ;
		if (plgPlg.fncFindBisectorLine(i, i + 2
		   ,valBisectAng, pntBsctVertex))
		{


         double arrVectBisectLine [2] = {0.};
		 arrVectBisectLine[0] = cos(valBisectAng) ;
		 arrVectBisectLine[1] = sin(valBisectAng) ;
		// ����������� ����� � �������(��������)
		// ����������:
		// 0 - �� ����������
		// 1 - ����������
		// 2  - ������ �������� ����� ������� ��������
		// 3  - ����� p0,    ����� ������ ��������
		// 4  - �����  p0  �������� �������� ��������
		// 5  - ������� ����� �� �����
		int  irez = plgPlg.ParametricLineCutSegment(pntSegm0,pntSegm1// �������
					,pntBsctVertex,arrVectBisectLine //
					,pCut // ����� �����������
						) ;
		bool bProper = true;
		if (irez == 1)
		{
		TTriang tr1 = TTriang( plgPlg.Points[i],plgPlg.Points[i + 1],pCut);
		// ������
		double val_r = 2. * fabs(tr1.calcSq())/ TURPointXY::dist(plgPlg.Points[i],plgPlg.Points[i + 1]);
		for (int j = 0; j < (plgPlg.NumPoints-1); j++)
		{
		TURPointXY pntRez;
		if (!plgPlg.fncCheckPositionCircle_and_Edge(pCut
		,val_r,  plgPlg.Points[j],plgPlg.Points[j + 1] , pntRez ))
		{
		 bProper = false ;
		 break;
		}

		}
		if (bProper)
		{
		pntArrCentre[quantCentres] =  pCut ;
		arrR[quantCentres] = val_r ;
		quantCentres++ ;
		}
		}


		}
       }
	 }

	if (quantCentres < 1 )
	{
	  ShowMessage(L"ERROR#1 TURPolygon::fncFindMaxCircle");
	  return false ;
	}
	int iNumArgMax = -1;
	valR = MaxDoubleArray(arrR, quantCentres, &iNumArgMax ) ;
	pntCentre =  pntArrCentre[iNumArgMax] ;
	return true ;
}


// �������� �������������� ��������
// INPUT:
// valAng - ���� ��������
// pntCentre - ����� ������ ��������
// pntSdvig - ����� ���� ������������ ����� ��������
// valRastigenie - ����������� ����������
// OUTPUT:
// ���������� ��������������� �������
TURPolygon   TURPolygon::LinTransform(const double  valAng, const TURPointXY pntCentre
  , const TURPointXY pntSdvig,const double valRastigenie )
{
  double arrMtxPer[4] = {0.};
  arrMtxPer[0] = cos(valAng);
  arrMtxPer[1] = -sin(valAng);
  arrMtxPer[2] = -arrMtxPer[1];
  arrMtxPer[ 3] = arrMtxPer[0];
  TURPointXY pntSdvig1( -pntCentre.X,-pntCentre.Y) ;
  TURPolygon PlgTemp0 = SdvigTransform( pntSdvig1 );
  TURPolygon PlgTemp1 = PlgTemp0.RastiagenieTransform( valRastigenie  );
  TURPolygon PlgTemp2 = PlgTemp1.fncLinTransform( arrMtxPer );
  TURPolygon PlgRez   =  PlgTemp2.SdvigTransform(pntSdvig) ;
  return PlgRez;
}

// �������� �������������� ��������  ������������
// INPUT:
// valAng - ���� ��������
// pntSdvig - ����� ���� ������������ ����� ��������
// valRastigenie - ����������� ����������
// OUTPUT:
// ���������� ��������������� �������
TURPolygon   TURPolygon::LinTransform(const double  valAng , const TURPointXY pntSdvig,const double valRastigenie )
{
  double arrMtxPer[4] = {0.};
  arrMtxPer[0] = cos(valAng);
  arrMtxPer[1] = -sin(valAng);
  arrMtxPer[2] = -arrMtxPer[1];
  arrMtxPer[ 3] = arrMtxPer[0];

  TURPolygon PlgTemp1 = RastiagenieTransform( valRastigenie  );

  TURPolygon PlgTemp2 = PlgTemp1.fncLinTransform( arrMtxPer );

  TURPolygon PlgRez   =  PlgTemp2.SdvigTransform(pntSdvig) ;


  return PlgRez;
}

// ����� �������� �� ������  pntSdvig
TURPolygon   TURPolygon::SdvigTransform(const TURPointXY pntSdvig )
{
  TURPolygon PlgRez = *this;
  for (int i = 0; i < NumPoints; i++)
  {
	 PlgRez.Points[i].X += pntSdvig.X;
	 PlgRez.Points[i].Y += pntSdvig.Y;
  }
  return PlgRez;
}
// ���������� �������� � ������������� valRastigenie
TURPolygon   TURPolygon::RastiagenieTransform( const double valRastigenie )
{
  TURPolygon PlgRez = *this;
  for (int i = 0; i < NumPoints; i++)
  {
	 PlgRez.Points[i].X = PlgRez.Points[i].X *valRastigenie;
	 PlgRez.Points[i].Y = PlgRez.Points[i].Y *valRastigenie ;
  }
  return PlgRez;
}

// ������������ ��������� �������� ������������ ��� OX
TURPolygon   TURPolygon::SimOtragenieTransform()
{
  TURPolygon PlgRez = *this;
  for (int i = 0; i < NumPoints; i++)
  {

	 PlgRez.Points[i].Y = -PlgRez.Points[i].Y ;
  }
  return PlgRez;
}
// ��������� ������� � ����� �������������� ���� ��������� � ��������� vala(�� X) � valb(�� Y)
//
TURPolygon  TURPolygon::createEllips(const double vala, const double valb
	 ,const TURPointXY pntCentre, const int numPoints )
{
  TURPointXY *pnts = new TURPointXY[numPoints *2 -1];
  for (int i=0; i < numPoints-1 ; i++)
  {
	pnts[i].X = -vala + 2. * vala/((double)( numPoints-1.)) * ((double)i) ;
	double t = (1. -  pnts[i].X * pnts[i].X/vala /vala);
	if (t < 0.) t =0;
	pnts[i].Y = sqrt(t)* valb ;
	pnts[2 *numPoints -2 - i].X = pnts[i].X;
	pnts[2 *numPoints -2 - i].Y = -pnts[i].Y;
  }
  pnts[numPoints-1].X = -vala + 2. * vala/((double)( numPoints-1.)) * ((double)(numPoints-1));
  double t = (1. -  pnts[numPoints-1].X * pnts[numPoints-1].X/vala /vala);
  if (t < 0.) t =0;
  pnts[numPoints-1].Y = sqrt(t)* valb ;
  for (int i =0; i < numPoints *2 -1; i++)
  {
   pnts[i].X += pntCentre.X;
   pnts[i].Y += pntCentre.Y;
  }
  TURPolygon plgRez(  numPoints *2 -1,pnts);
  delete []pnts  ;
  return plgRez;
}

// ������� ������ ���
TURPolygon TURPolygon::createFarHood( const double valHeight, const double  valWidth, const double  valRad)
{

	int iNumLine = 1000;
	int iNumPoints = iNumLine * 2 +3;
	TURPointXY  *parrPoints = new TURPointXY  [iNumPoints];

	parrPoints [0] = TURPointXY( -valWidth/ 2., valHeight/ 2.);
	parrPoints [iNumPoints -1] =  parrPoints [0];
	parrPoints [iNumPoints -2] = TURPointXY( -valWidth/ 2., -valHeight/ 2.);
	TURPointXY pntCntr (valWidth/ 2. -  valRad, valHeight/ 2.-  valRad);
	double delFi = M_PI/ 2./ ((double)(iNumLine-2));
	for (int i =0; i < iNumLine; i++)
	{
	   double valFi = delFi *((double)i);
	parrPoints [1 + i]  =  TURPointXY( pntCntr.X + valRad *sin(valFi), pntCntr.Y + valRad *cos(valFi) );
	 parrPoints [iNumPoints -3 -i]  =  TURPointXY( parrPoints [1 + i].X, -parrPoints [1 + i].Y );

	}
	TURPolygon plg = TURPolygon(  iNumPoints ,parrPoints);
	delete []parrPoints;
	return  plg;
}

// ��������  ��������������� �� �������� ������������ ��� y
//INPUT
//pntLowLeft - ����� ������ �����
// VALx - ����� ������� �� ��� x
// VALy - ����� ������� �� ��� y
// VAL_al1  - ���� ����� �������� �� ��� x � ������������
TURPolygon TURPolygon::fncCreateParallelogramm(TURPointXY pntLowLeft,const double VALx,const double VALy
 ,const double VAL_al1 )

{
  TURPolygon plgRez(  5) ;
  plgRez.Points[0] =pntLowLeft;
  plgRez.Points[4] =pntLowLeft;
  plgRez.Points[1] = TURPointXY(pntLowLeft.X,pntLowLeft.Y + VALy);
  plgRez.Points[2] = TURPointXY(plgRez.Points[1].X + VALx * cos(VAL_al1), plgRez.Points[1].Y + VALx * sin(VAL_al1));
  plgRez.Points[3] = TURPointXY(plgRez.Points[2].X , plgRez.Points[2].Y -VALy);

 return  plgRez ;
}

// ������� ������ ���
TURPolygon TURPolygon::createPictParabAnt( const double valScale)
{
 TArcParab tempPrb(0.,20.);
 TURPointXY  arrPntSgm[2] ;
  arrPntSgm[0] =  TURPointXY(1.,0.);
  arrPntSgm[1] =  TURPointXY(-1.,0.);
  TURPointXY  arrPntRez[2] ;
 int irez = tempPrb.fncLineIntersectParab (arrPntSgm[0], arrPntSgm[1],arrPntRez);
 if (irez == 2)
  {
	tempPrb.m_x0 = min_(arrPntRez[0].X,arrPntRez[1].X) ;
	tempPrb.m_x1 = max_(arrPntRez[0].X,arrPntRez[1].X) ;
  }
  const int iN = 2000;
  TURPolyLine line(tempPrb,iN);

  TURPolygon plgRez(iN + 1);
  memcpy(plgRez.Points, line.Points, iN * sizeof (TURPointXY));
  plgRez.Points[iN] = plgRez.Points[0];
  for (int i = 0; i < plgRez.NumPoints; i++)
  {
   plgRez.Points[i].Y =  plgRez.Points[i].Y * valScale;
  }

  double arrMtxPer[4] = {0.,-1.,1.,0.
  } ;

   TURPolygon plgRez1 = plgRez.fncLinTransform( arrMtxPer ) ;

   for (int i =0; i < plgRez1.NumPoints; i++)
   {
	 plgRez1.Points[i].X = -plgRez1.Points[i].X;
	 }
   return plgRez1;

}

// ������������ ��������� �������� ������������ ��� OY
TURPolygon   TURPolygon::SimOtragenieY_and_flip()
{
  TURPolygon PlgRez = *this;
  for (int i = 0; i < NumPoints; i++)
  {

	 PlgRez.Points[i].X = -PlgRez.Points[i].X ;
	}
	PlgRez.flip();
  return PlgRez;
}

// ���������� �� ���������� �������� �������� � ������� n
TURPolygon   TURPolygon::extractSimplePolygon(const int n)
{
	if (n >= NumParts)
	{
	   ShowMessage(L"Error calcPartSq: n >= NumParts");
	   Abort() ;
	}

	int quanP = ( n == (NumParts -1))?(NumPoints - Parts[n] ):( Parts[n +1] - Parts[n] );
	TURPolygon plg(quanP,&Points[Parts[n]]);

	return plg;

}

 /*******************************************************************************************************************************/


void TURPolygon::createTargPointsArray( const double VAlCellSize, TURPointXY **ppTargPntArray, int *plenTargPntArray)
{
  int lenMemoryResedved = *plenTargPntArray;
  int lenMemoryCur = 0;
  for (int i =0; i < NumParts; i++)
  {
   TURPolygon   Polygon = extractSimplePolygon(i);
   Polygon.addTargPointsArray( VAlCellSize,  ppTargPntArray,&lenMemoryResedved, &lenMemoryCur );

  }
  *ppTargPntArray =  (TURPointXY *)realloc(*ppTargPntArray, lenMemoryCur * sizeof(TURPointXY));
  *plenTargPntArray = lenMemoryCur ;
}

/*******************************************************************************************************************************/

int TURPolygon::calcQuantApproximatingPoints(const double valTargCellSize)
{
	return 0;
}

void TURPolygon::addTargPointsArray(const double valTargCellSize,  TURPointXY **ppTargPntArray
   ,int *lenMemoryResedved, int *lenMemoryCur )
{
	TYrRastr rastrTarg( *this,  valTargCellSize, 1);
	int INum = rastrTarg.calcQuantValuablePiksels()   ;

	if (( (*lenMemoryCur) + INum) > (*lenMemoryResedved))
	{
		*ppTargPntArray =  (TURPointXY *)realloc(*ppTargPntArray, ((*lenMemoryCur) + INum) * sizeof(TURPointXY));
		(*lenMemoryResedved) = (*lenMemoryCur) + INum;

	}
	TURPointXY *pPoint = &((*ppTargPntArray)[*lenMemoryCur]);
	int icur = 0;
	for (int i =0; i <  rastrTarg.ncols * rastrTarg.nrows; i++)
	{
		if (rastrTarg.pflt_rastr[i] > 0.5)
		{
			pPoint[icur] = rastrTarg.getCellCentre(i) ;
			icur++;
			if (icur == INum)
			{
			break;
			}
		}
	}

	(*lenMemoryCur) +=  INum ;
}

 /*******************************************************************************************************************************/

void TURPolygon::WriteSetSHPFiles(wchar_t *wchFileName)
{
	 TURPolygon *purPlg = new TURPolygon[NumParts];
	 for (int i = 0; i < NumParts; i++)
	 {
	  purPlg [i] =  extractSimplePolygon(i);
	 }
	int lenFileName = wcslen( wchFileName);

	if (!((wchFileName[lenFileName -1] == L'p')
	   && (wchFileName[lenFileName -2] == L'h')
	   && (wchFileName[lenFileName -3] == L's')))
	   {
		 ShowMessage(L" Error file name") ;
		 return;
	   }
	 wchar_t wchDBFFileName [200] ,wchSHXFileName [200] ;
	wcscpy(wchSHXFileName, wchFileName);
	wchSHXFileName[lenFileName -1] =  L'x' ;
	wcscpy(wchDBFFileName, wchFileName);
	wchDBFFileName [lenFileName -1] = L'f';
	wchDBFFileName [lenFileName -2] = L'b';
	wchDBFFileName [lenFileName -3] = L'd';
	WriteDBASEFile(wchDBFFileName,purPlg,  NumParts) ;
	WriteMainFile(wchFileName,purPlg,  NumParts) ;
	WriteIndexFile(wchSHXFileName,purPlg,  NumParts) ;
	delete []purPlg;
}

 /*******************************************************************************************************************************/


void TURPolygon::createUnatedPointsArray(TURPointXY **ppunatedPoints, int *quantUnitedPoints)
{
 *ppunatedPoints = (TURPointXY *)realloc(*ppunatedPoints, (NumPoints - NumParts) * sizeof( TURPointXY));
 *quantUnitedPoints = (NumPoints - NumParts);
 int numCur = 0;
 for (int i =0; i < NumParts; i++)
 {
   int quanP = ( i == (NumParts -1))?(NumPoints - Parts[i] ):( Parts[i +1] - Parts[i] );
   memcpy(&((*ppunatedPoints)[numCur]), &Points[Parts[i]], (quanP -1) *sizeof(TURPointXY));
   numCur += (quanP -1);
 }

}

 /*******************************************************************************************************************************/


// �������� �������������� ��������  ������������
// INPUT:
// valAng - ���� ��������
// pntSdvig - ����� ���� ������������ ����� ��������
// valRastigenie - ����������� ����������
// OUTPUT:
// ���������� ��������������� �������
void   TURPolygon::LinearTransformation(const double  valAng , const TURPointXY pntSdvig,const double valRastigenie )
{
	TURPolygon plgCur = LinTransform( valAng ,  pntSdvig, valRastigenie ) ;
	*this = plgCur;
}

//-----------------------------------------------------------------------------
// ���������� �������� ��������   ��������
void   TURPolygon::ConvexShell(TURPolygon *pPolgConv)
{
	*pPolgConv =   Conv(Points // ������ �����, input
			, NumPoints // ����� ������� ����� , input
				)  ;
}


//-----------------------------------------------------------------------------
// C������� ������� �������� ������ ��������  arrElK
// �� ������ VAlCoeff
// ����� ������ NUmPoints
//
//
TURPolygon   TURPolygon::createEllips(double *arrElK, const double VAlCoeff, const int  NUmPoints)
{
	//   arrF - ������� ����������� ��������  ������ �������
	double arrF[4] = {0.} , arrMtrxLamb[4] = {0.};
	CalcProperVectors2(arrElK, arrF , arrMtrxLamb) ;

	 ///

	 // ������� ��������� ��������������, ������������ ������   ��������� ��������� ����� �������
	 // �� ����������� ������� ����������������� ��������� ��������� ���������
	double arrLinTrasf [4] ={0.}, arrLambSq[4] ={0.};
	arrLambSq[0] =  sqrt(arrMtrxLamb[0]);
	arrLambSq[3] =  sqrt(arrMtrxLamb[3]);
	MtrxMultMatrx(arrF,2, 2, arrLambSq,2, arrLinTrasf) ;
	///

	// 2. ������������ ������� ��������� �� ������ 1
	 TURPointXY  pntSdvig(0.,0.);
	TURPolygon plgCircle1 = TURPolygon::fncCreateCircle(pntSdvig,VAlCoeff, NUmPoints) ; // ��� ��������� ����
	TURPolygon plgonEll = plgCircle1.fncLinTransform(arrLinTrasf );// ��� ��� �������� ��������������
	return plgonEll;
}
//-----------------------------------------------
//�������� �������������� �� �������� Box
//
TURPolygon   TURPolygon::createRect(double *Box)
{
  const int iNumPoints = 5;
  double  px [5] = {0.};
  double  py [5] = {0.};
  px [0] = Box[0];
  px [1] = Box[0];
  px [2] = Box[2];
  px [3] = Box[2];
  px [4] = Box[0];

  py[0] =  Box[1];
  py[1] =  Box[3];
  py[2] =  Box[3];
  py[3] =  Box[1];
  py[4] =  Box[1];

 return TURPolygon (   iNumPoints, px, py);
}

//---------------------------------------------------------------------
//
void   TURPolygon::swap(TURPolygon *a0, TURPolygon *a1)
{
	TURPolygon b = *a1;
	*a1 = *a0 ;
	*a0 = b ;
}

//---------------------------------------------------------------------
// ��������� ��������� ����������� ������� �� ��������
void   TURPolygon:: flipArray(TURPolygon *parr, const int len)
{
	for (int i = 0; i < len/ 2; i++)
	{
		 swap(&parr[i], &parr[len - 1 -i]) ;

	}
}

//-----------------------------------------------------
// ���������� �� ����� �� �������� ��������
double TURPolygon::calcDistFromPoint(const TURPointXY pnt)
{
 if (PntInPolygon( pnt)> 0)
 {
	return 0.;
 }


 double valDist = 10000000000.;
 for (int i =0; i < (NumPoints -1); i++)
 {

   double temp = calcDistBetweenPointAndSegment(Points[i], Points[i+1],pnt);


   if (temp < valDist )
   {
	 valDist = temp;
   }
 }
return valDist;
}

//-----------------------------------------------------
// ���������� �� ������� ���� �� �����, ���������� 2-�� �������
double TURPolygon::calcDistBetweenPointAndLine(const TURPointXY pntLn0, const TURPointXY pntLn1
	   ,const TURPointXY pnt,TURPointXY *pPntProj )
{
 double arry[2] = {0.}, arrv [2] = {0.};
 arry[0] =pntLn0.X - pnt.X ;
 arry[1] =pntLn0.Y - pnt.Y ;


 arrv[0] =pntLn1.X - pntLn0.X ;
 arrv[1] =pntLn1.Y - pntLn0.Y ;
 NormalizeVect(arrv, 2);

 double valScal = ScalProduct(arry , arrv, 2) ;
 double arrt[2] = {0.}, arrt0[2] = {0.};
 MatrxMultScalar(arrv, 1, 2, valScal,arrt);
 (*pPntProj).X = pntLn0.X - valScal * arrv[0];
 (*pPntProj).Y = pntLn0.Y - valScal * arrv[1];

 double valNormy2= NormVect2(arry) * NormVect2(arry);


return _sqrt_(valNormy2 - valScal * valScal);
}

//-----------------------------------------------------
// ���������� �� ����� �� ��������, ����������� 2-�� �������
double TURPolygon::calcDistBetweenPointAndSegment(const TURPointXY pntSegm0, const TURPointXY pntSegm1
	   ,const TURPointXY pnt )
{

   if (TURPointXY::dist(pntSegm0,pntSegm1) < 0.00001)
   {
	 return TURPointXY::dist(pntSegm0,pnt) ;
   }
   TURPointXY pntProj;
   double temp = calcDistBetweenPointAndLine(pntSegm0, pntSegm1, pnt,&pntProj );
   double arr0[2] = {0.}, arr1[2] = {0.};
   arr0[0] = pnt.X - pntSegm0.X;
   arr0[1] = pnt.Y - pntSegm0.Y;
   arr1[0] = pntSegm1.X - pntSegm0.X;
   arr1[1] = pntSegm1.Y - pntSegm0.Y;
   double valScal0 = ScalProduct(arr0 , arr1, 2) ;

   double arr2[2] = {0.}, arr3[2] = {0.};
   arr2[0] = pnt.X - pntSegm1.X;
   arr2[1] = pnt.Y - pntSegm1.Y;
   arr3[0] = pntSegm0.X - pntSegm1.X;
   arr3[1] = pntSegm0.Y - pntSegm1.Y;
   double valScal1 = ScalProduct(arr2 , arr3, 2) ;

   if ((valScal0> 0.) && (valScal1> 0.))
   {
	return temp;
   }




   double x0 = _sqrt_((pntSegm0.X - pnt.X) * (pntSegm0.X - pnt.X) + (pntSegm0.Y - pnt.Y) * (pntSegm0.Y - pnt.Y));//TURPointXY::dist(pntSegm0,pnt) ;
   double x1 = _sqrt_((pntSegm1.X - pnt.X) * (pntSegm1.X - pnt.X) + (pntSegm1.Y - pnt.Y) * (pntSegm1.Y - pnt.Y));
   double x00 = x0;//(temp0 < temp1)?temp0:temp1;
   if (x1 < x00)
   {
	  x00 = x1;
   }

return x00;

}

#pragma package(smart_init)
