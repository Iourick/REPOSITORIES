﻿//---------------------------------------------------------------------------

#include "URPolyLine.h"
#include "UrPointXY.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <math.h>
#include <float.h>
#include "URPolyLineZ.h"
#include "Equations.h"
#include "ArcEllipse.h"
#include "ArcParab.h"
#include "Sector.h"
#include "Circle.h"
#include "Hyperbola.h"

#include "Line.h"
#include "MatrixProccess.h"
#include "URPolygon.h"
#include <QLineF>

 TURPolyLine::~TURPolyLine()
{
    if(Parts) delete []Parts ;
	Parts = NULL ;
    if(Points) delete [] Points ;
	Points = NULL ;
  //	if(iPoints) delete iPoints ;
   //	iPoints = NULL ;
}
//---------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
 TURPolyLine ::TURPolyLine()
{
	NumParts = 0 ;
	NumPoints = 0 ;
	Parts = NULL ;
	Points = NULL ;
}

 // парам констр
TURPolyLine :: TURPolyLine( const int iNumParts, const int iNumPoints)

 {
   NumParts = iNumParts ;
   //3
   NumPoints = iNumPoints ;

	   Parts = new int[NumParts];
	   if(Parts == NULL)
	   {
             //ShowMessage  (L"Not memory for Parts") ;
		   //Abort() ;
       }

	   Points = new TURPointXY[iNumPoints];
	   if(Points == NULL)
	   {
             //ShowMessage  (L"Not memory for Points") ;

	   }

 }

 TURPolyLine ::TURPolyLine(  const int iNumParts,const int iNumPoints,int *iarrParts
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
             //ShowMessage  (L"Not memory for Parts") ;
		   //Abort() ;
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
             //ShowMessage  (L"Not memory for Points") ;
		   //Abort() ;
	   }
		memcpy( Points,arrPoints, iNumPoints  * sizeof(TURPointXY));
   }

}


// парам констр
TURPolyLine::TURPolyLine(double *parrx,double *parry,const int quanPoints)
{
	NumParts  = 1;
   NumPoints =quanPoints;
 //  if (Parts != NULL) Parts = NULL; // delete [] Parts;
	Parts = new int [1];
	if (Parts == NULL)
	 {
       {
             //ShowMessage  (L"Not memory for Parts") ;
		   //Abort() ;
	   }
	}
	 Parts[0] = 0;
 //  if (Points != NULL) Points = NULL ;// delete [] Points;

	  Points = new TURPointXY[quanPoints];
	   if(Points == NULL)
	   {
             //ShowMessage  (L"Not memory for Points") ;
		   //Abort() ;
	   }
	for (int i =0; i < quanPoints; i++)
	{
	 Points[i].X = parrx[i];
	 Points[i].Y = parry[i];
	}
	calcBoundBox();

}

 // парам констр
 TURPolyLine ::TURPolyLine( TURPolyLine *parrPln, const int lenarrPln)
{
	NumParts = 0;
	NumPoints = 0 ;
	for (int i =0; i < lenarrPln; i++)
	{
	  NumParts += parrPln[i].NumParts;
	  NumPoints +=  parrPln[i].NumPoints;
	}
    //Parts = NULL;
	Parts = new int[NumParts];
	if(Parts == NULL)
	   {
             //ShowMessage  (L"Not memory for Parts") ;
		   return ;
	   }
    //Points = NULL ;
	Points = new TURPointXY[NumPoints];
	if(Points == NULL)
	 {
             //ShowMessage  (L"Not memory for Points") ;
		   //Abort() ;
	  }

	   memcpy(Parts, parrPln[0].Parts,sizeof(int)* parrPln[0].NumParts);
	  int n0 = 0 ;
	  int iPartsTemp = parrPln[0].NumParts;
	for (int i = 1; i < lenarrPln; i++)
	{
	  n0 += parrPln[i-1].NumPoints;
	  int it = n0 ;

		for (int j = 0; j < parrPln[i].NumParts;  j++)
		{
		Parts[iPartsTemp] = it + parrPln[i].Parts[j];
		it =+ parrPln[i].Parts[j];
		iPartsTemp++;
		}
	}
	n0 =0;
	for (int i = 0; i < lenarrPln; i++)
	{
	  memcpy( &Points[n0], parrPln[i].Points,sizeof(TURPointXY) * parrPln[i].NumPoints);
	  n0 +=  parrPln[i].NumPoints;
	}

}

 //---------------------------------------------------------

 TURPolyLine ::TURPolyLine(  const int iNumParts,const int iNumPoints,int *iarrParts
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
   //  Parts = NULL;
    }

    if(iarrParts != NULL)
    {
        Parts = new int[iNumParts];
        if(Parts == NULL)
        {
              //ShowMessage  (L"Not memory for Parts") ;
            //Abort() ;
        }
         memcpy( Parts,iarrParts, iNumParts  * sizeof(int));
    }
    //5
    if (Points != NULL)
    {
    //	delete [] Points;
   //  Points = NULL ;
    }

    if(arrPoints != NULL)
    {
        Points = new TURPointXY[iNumPoints];
        if(Points == NULL)
        {
              //ShowMessage  (L"Not memory for Points") ;
            //Abort() ;
        }
         memcpy( Points,arrPoints, iNumPoints  * sizeof(TURPointXY));
    }
    delete []arrPoints;
    //6

       calcBoundBox();
 }
//--------------------------------------------------------------
// параметр конструкто создания из математической линии эллипса
TURPolyLine::TURPolyLine(  const TArcEllipse arcEll,const int iNumPoints)
{
	//2
	NumParts = 1 ;
	//3
	NumPoints = iNumPoints ;
	//4
	if (Parts != NULL)
	{
	//	delete [] Parts;
    //Parts = NULL;
	}


	Parts = new int[1];
	if(Parts == NULL)
	{
      //ShowMessage  (L"Not memory for Parts") ;
	//Abort() ;
	}
	Parts [0] = 0;


	//5
	if (Points != NULL)
	{
	//	delete [] Points;
    //Points = NULL ;
	}


	Points = new TURPointXY[iNumPoints];
	if(Points == NULL)
	{
      //ShowMessage  (L"Not memory for Points") ;
	//Abort() ;
	}

   double valSt = (arcEll.m_x1 -arcEll.m_x0) /((double) iNumPoints);
   double valx = arcEll.m_x0 ;

   for (int i =0; i < iNumPoints; i++)
   {
	 Points[i].X =  valx;
	 Points[i].Y =  arcEll.mb * sqrt(arcEll.ma* arcEll.ma - valx*valx)/ arcEll.ma;
	 valx += valSt ;

   }

}


// параметр конструкто создания из математической линии гиперболы
TURPolyLine::TURPolyLine(  const THyperbola hyperb,const int iNumPoints0, const double VAlDiap)
{
	//2
	NumParts = 2 ;
	//3
	int iNumPointsHalfBranch = iNumPoints0/2 ;
	int iNumPointsBranch =  iNumPointsHalfBranch *2 + 1 ;
	NumPoints = iNumPointsBranch *2;
	//4
	if (Parts != NULL)
	{
	//	delete [] Parts;
    //Parts = NULL;
	}


	Parts = new int[2];
	if(Parts == NULL)
	{
      //ShowMessage  (L"Not memory for Parts") ;
	//Abort() ;
	}
	Parts [0] = 0;
	Parts [1] = iNumPointsBranch ;


	//5
	if (Points != NULL)
	{
	//	delete [] Points;
    //Points = NULL ;
	}


	Points = new TURPointXY[NumPoints];
	if(Points == NULL)
	{
      //ShowMessage  (L"Not memory for Points") ;
	//Abort() ;
	}

   double valSt = (VAlDiap - hyperb.ma) /((double) iNumPointsHalfBranch);

   for (int i =0; i < iNumPointsHalfBranch ; i++)
   {
	 double valx = - VAlDiap + ((double)i)* valSt ;
	 Points[i].X =  valx;
	 Points[i].Y =  hyperb.mb * sqrt(-hyperb.ma* hyperb.ma + valx*valx)/ hyperb.ma;
	 Points[iNumPointsBranch -1 -i].X =  Points[i].X;
	 Points[iNumPointsBranch -1 -i].Y =  -Points[i].Y;
	 valx += valSt ;
   }

   Points[iNumPointsHalfBranch].X =  - hyperb.ma;
   Points[iNumPointsHalfBranch].Y = 0.;

   for (int i =0; i < iNumPointsBranch ; i++)
   {
	 Points[iNumPointsBranch + i].X =  -Points[i].X;
	 Points[iNumPointsBranch + i].Y =  Points[i].Y ;
   }


}

// параметр конструкто создания из математической линии параболы
TURPolyLine ::TURPolyLine(  const TArcParab arcPrbl,const int iNumPoints)
{
	//2
	NumParts = 1 ;
	//3
	NumPoints = iNumPoints ;
	//4
	if (Parts != NULL)
	{
	//	delete [] Parts;
//	Parts = NULL;
	}


	Parts = new int[1];
	if(Parts == NULL)
	{
      //ShowMessage  (L"Not memory for Parts") ;
	//Abort() ;
	}
	Parts [0] = 0;


	//5
	if (Points != NULL)
	{
	//	delete [] Points;
    //Points = NULL ;
	}


	Points = new TURPointXY[iNumPoints];
	if(Points == NULL)
	{
      //ShowMessage  (L"Not memory for Points") ;
	//Abort() ;
	}

   double valSt = (arcPrbl.m_x1 -arcPrbl.m_x0) /((double) iNumPoints);
   double valx = arcPrbl.m_x0 ;

   for (int i =0; i < iNumPoints; i++)
   {
	 Points[i].X =  valx ;
	 double vala = 0., valb = 0., valc = 0. ;
	 vala = - 1. / 2./ arcPrbl.ml ;
	 valb = arcPrbl.ma / arcPrbl.ml ;
	 valc = ( arcPrbl.ml * arcPrbl.ml - arcPrbl.ma * arcPrbl.ma) / 2. / arcPrbl.ml ;
	 Points[i].Y =vala * valx* valx +  valb * valx + valc ;
	 valx += valSt ;

   }

}

// параметр конструкто создания из математической линии окружности
TURPolyLine ::TURPolyLine(  const TCircle Circle,const int iNumPoints)
{
	//2
	NumParts = 1 ;
	//3
	NumPoints = iNumPoints ;
	//4
	if (Parts != NULL)
	{
	//	delete [] Parts;
//	Parts = NULL;
	}


	Parts = new int[1];
	if(Parts == NULL)
	{
      //ShowMessage  (L"Not memory for Parts") ;
	//Abort() ;
	}
	Parts [0] = 0;


	//5
	if (Points != NULL)
	{
	//	delete [] Points;
    //Points = NULL ;
	}


	Points = new TURPointXY[iNumPoints];
	if(Points == NULL)
	{
      //ShowMessage  (L"Not memory for Points") ;
	//Abort() ;
	}

  double valSt = 2. * M_PI /((double) iNumPoints);
   double valFi = 0.;

   for (int i =0; i < iNumPoints; i++)
   {
	 Points[i].X =  Circle.mPntCentre.X + Circle.mR * cos(valFi)  ;
	 Points[i].Y =  Circle.mPntCentre.Y + Circle.mR * sin(valFi)  ;
	 valFi += valSt ;

   }

}
// параметр конструкто создания из математической линии сектора окружности
TURPolyLine ::TURPolyLine(  const TSector Sect,const int iNumPoints)
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


	Parts = new int[1];
	if(Parts == NULL)
	{
      //ShowMessage  (L"Not memory for Parts") ;
	//Abort() ;
	}
	Parts [0] = 0;


	//5
	if (Points != NULL)
	{
	//	delete [] Points;
	Points = NULL ;
	}


	Points = new TURPointXY[iNumPoints];
	if(Points == NULL)
	{
      //ShowMessage  (L"Not memory for Points") ;
	//Abort() ;
	}

   double valSt = (Sect.mFi1 -Sect.mFi0) /((double) iNumPoints);
   double valFi = Sect.mFi0 ;

   for (int i =0; i < iNumPoints; i++)
   {
	 Points[i].X =  Sect.mPntCentre.X + Sect.mR * cos(valFi)  ;
	 Points[i].Y =  Sect.mPntCentre.Y + Sect.mR * sin(valFi)  ;
	 valFi += valSt ;
	/* double vala = 0., valb = 0., valc = 0. ;
	 vala = - 1. / 2./ arcPrbl.ml ;
	 valb = arcPrbl.ma / arcPrbl.ml ;
	 valc = ( arcPrbl.ml * arcPrbl.ml - arcPrbl.ma * arcPrbl.ma) / 2. / arcPrbl.ml ;
	 Points[i].Y =vala * valx* valx +  valb * valx + valc ;
	 valx += valSt ; */

   }

}

 // оператор присваивания
 TURPolyLine &TURPolyLine::operator=(const TURPolyLine  &R)
 {
	NumParts  = R.NumParts ;
    //if (Parts != NULL) Parts = NULL;
	if(R.Parts != NULL)
	{
		Parts = new int[R.NumParts];
		if(Parts == NULL) 	   {
          //ShowMessage  (L"Not memory for Parts") ;
		//Abort() ;
	}
	memcpy( Parts,R.Parts, R.NumParts  * sizeof(int));
	}

	NumPoints = R.NumPoints ;
    //if (Points != NULL) Points = NULL ;//delete [] Points;
	if(R.Points != NULL)
	{
		Points = new TURPointXY[R.NumPoints];
		if(Points == NULL)
		{
          //ShowMessage  (L"Not memory for Points") ;
		//Abort() ;
		}
		memcpy( Points,R.Points, R.NumPoints  * sizeof(TURPointXY));
	}

	return *this ;
 }

 // конструктор копирования
 TURPolyLine::TURPolyLine (const TURPolyLine &R)
 {
	NumParts  = R.NumParts ;
    //Parts = NULL;

	if(R.Parts != NULL)
	{
		Parts = new int[R.NumParts];

		if(Parts == NULL)
		{
          //ShowMessage  (L"Not memory for Parts") ;
		//Abort() ;
		}

		memcpy( Parts,R.Parts, R.NumParts  * sizeof(int));
	}

	NumPoints = R.NumPoints ;

    //Points = NULL;//
	if(R.Points != NULL)
	{
		Points = new TURPointXY[R.NumPoints];
		if(Points == NULL)
		{
          //ShowMessage  (L"Not memory for Points") ;
		//Abort() ;
		}
		memcpy( Points,R.Points, R.NumPoints  * sizeof(TURPointXY));
	}


 }
//-----------------------------------------------------------------------------------
// парам констр
TURPolyLine::TURPolyLine (const TURPolyLineZ &R)
{
  memcpy(Box,R.Box,4 * sizeof(double));
   NumParts  = R.NumParts ;
   if (Parts != NULL) delete [] Parts;
   if(R.Parts != NULL)    {
	   Parts = new int[R.NumParts];
	   if(Parts == NULL) 	   {
             //ShowMessage  (L"Not memory for Parts") ;
		   //Abort() ;
	   }
		memcpy( Parts,R.Parts, R.NumParts  * sizeof(int));
   }

   NumPoints = R.NumPoints ;
   if (Points != NULL) delete [] Points;
   if(R.Points != NULL)
   {
	  Points = new TURPointXY[R.NumPoints];
	   if(Points == NULL)
	   {
             //ShowMessage  (L"Not memory for Points") ;
		   //Abort() ;
	   }
		memcpy( Points,R.Points, R.NumPoints  * sizeof(TURPointXY));
   }
}
//-----------------------------------------------------------------------------------
// парам констр
TURPolyLine::TURPolyLine(wchar_t*FileName)
{
  TURPolyLineZ R( FileName) ;
  memcpy(Box,R.Box,4 * sizeof(double));
   NumParts  = R.NumParts ;
   if (Parts != NULL) delete [] Parts;
   if(R.Parts != NULL)    {
	   Parts = new int[R.NumParts];
	   if(Parts == NULL) 	   {
             //ShowMessage  (L"Not memory for Parts") ;
		   //Abort() ;
	   }
		memcpy( Parts,R.Parts, R.NumParts  * sizeof(int));
   }

   NumPoints = R.NumPoints ;
   if (Points != NULL) delete [] Points;
   if(R.Points != NULL)
   {
	  Points = new TURPointXY[R.NumPoints];
	   if(Points == NULL)
	   {
             //ShowMessage  (L"Not memory for Points") ;
		   //Abort() ;
	   }
		memcpy( Points,R.Points, R.NumPoints  * sizeof(TURPointXY));
   }
}

// парам констр
TURPolyLine::TURPolyLine(TURPointXY * pPoints,const int quanPoints)
{
	NumParts  = 1;
   NumPoints =quanPoints;
   if (Parts != NULL) Parts = NULL; // delete [] Parts;
	Parts = new int [1];
	if (Parts == NULL)
	 {
       {
             //ShowMessage  (L"Not memory for Parts") ;
		   //Abort() ;
	   }
	}
	 Parts[0] = 0;
   if (Points != NULL) Points = NULL ;// delete [] Points;

	  Points = new TURPointXY[quanPoints];
	   if(Points == NULL)
	   {
             //ShowMessage  (L"Not memory for Points") ;
		   //Abort() ;
	   }
		memcpy( Points,pPoints, quanPoints * sizeof(TURPointXY));
	calcBoundBox();

}

// параметр конструкто создания 2 точек
TURPolyLine::TURPolyLine( const TURPointXY  pnt1, const TURPointXY  pnt2)
{
   NumParts  = 1;
   NumPoints = 2;

   TURPointXY arrPoints[2];
   arrPoints[0] = pnt1;
   arrPoints[1] = pnt2;
     if (Parts != NULL)
     {
     Parts = NULL;
     delete [] Parts;
     }
   Parts = new int [1];
   if (Parts == NULL)
   {
     {
         //ShowMessage  (L"Not memory for Parts") ;
       //Abort() ;
     }
   }
   Parts[0] = 0;
   if (Points != NULL) Points = NULL ;// delete [] Points;

   Points = new TURPointXY[NumPoints];
   if(Points == NULL)
   {
         //ShowMessage  (L"Not memory for Points") ;
       //Abort() ;
   }
    memcpy( Points,arrPoints, NumPoints * sizeof(TURPointXY));
    calcBoundBox();
}

//----------------------------------------------

// параметр конструкто создания 2 точек
TURPolyLine::TURPolyLine( QLineF &qline)
{
   NumParts  = 1;
   NumPoints = 2;

   TURPointXY arrPoints[2];
   arrPoints[0] = TURPointXY(qline.p1().x(),qline.p1().y());
   arrPoints[1] = TURPointXY(qline.p2().x(),qline.p2().y());

   Parts = new int [1];

   Parts[0] = 0;

   Points = new TURPointXY[NumPoints];

    memcpy( Points,arrPoints, NumPoints * sizeof(TURPointXY));
    calcBoundBox();
}


//--------------------------------------------------------------------------------

int TURPolyLine::WriteToASCII(wchar_t*FileName)
{
  TURPolyLineZ L( *this) ;
  L.WriteToASCII(FileName) ;
  return 0 ;

}
bool TURPolyLine::ReadFromASCII(wchar_t*FileName)
{
  TURPolyLineZ R( FileName) ;
   memcpy(Box,R.Box,4 * sizeof(double));
   NumParts  = R.NumParts ;
   if (Parts != NULL) delete [] Parts;
   if(R.Parts != NULL)    {
	   Parts = new int[R.NumParts];
	   if(Parts == NULL) 	   {
             //ShowMessage  (L"Not memory for Parts") ;
		   //Abort() ;
	   }
		memcpy( Parts,R.Parts, R.NumParts  * sizeof(int));
   }

   NumPoints = R.NumPoints ;
   if (Points != NULL) delete [] Points;
   if(R.Points != NULL)
   {
	  Points = new TURPointXY[R.NumPoints];
	   if(Points == NULL)
	   {
             //ShowMessage  (L"Not memory for Points") ;
		   //Abort() ;
	   }
		memcpy( Points,R.Points, R.NumPoints  * sizeof(TURPointXY));
   }
   calcBoundBox();
   return true;
}

void TURPolyLine::calcBoundBox()
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
	Box[3] =  yMax;

}

double TURPolyLine::calcLeng()
{
 double sum = 0;
	for (int n= 0; n < NumParts; n++)
	{
	   sum +=   calcPartLeng(n);
	}
	return sum;
}

double TURPolyLine::calcPartLeng(const int n)
{
	if (n >= NumParts)
	{
         //ShowMessage  (L"Error calcPartSq: n >= NumParts");TURPointXY *pPXY = (TURPointXY *)&Points [Parts[n]];pntV

	   //Abort() ;
	}
    //TURPointXY *pPXY = (TURPointXY *)&Points [Parts[n]];
    TURPointXY *pPXY = &(Points [Parts[n]]);
	int quanP = ( n == (NumParts -1))?(NumPoints - Parts[n] ):( Parts[n +1] - Parts[n] );
	double S =0 ;
	for (int i =0; i < (quanP - 1); i++)
	{

	   S = S + dist(&pPXY[i],&pPXY[i + 1]);
	}
	return S;

}
double TURPolyLine::dist(TURPointXY*p0, TURPointXY*p1)
{
    double d = ((*p0).X -(*p1).X) * ((*p0).X -(*p1).X) + ((*p0).Y -(*p1).Y) * ((*p0).Y -(*p1).Y);
    if (d < 0.)
    {
        d=0.;
    }
  return sqrt(d) ;
}
	//http://www.esri.com/library/whitepapers/pdfs/shapefile.pdf
	// http://www.dbase.com/Knowledgebase/INT/db7_file_fmt.htm
	//http://www.clicketyclick.dk/databases/xbase/format/dbf.html#DBF_STRUCT

// изменение порядка следования байтов в 4 байтном слове (32 бита массив)
//  input : chstr - указатель на массив char[4]
// output: chstr - указатель на массив  char[4] c измененным порядком следования
// байтов  chstr[0] = chstr[3] ; chstr1] = chstr[2] ;  chstr[2] = chstr[1] ; chstr[3] = chstr[0] ;
void TURPolyLine::ChangeByteOrder(int * pi0)
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

void TURPolyLine::WriteSetSHPFiles(wchar_t *wchFileName,TURPolyLine *purPlg, const int quantPlg)
{

    int lenFileName = wcslen( wchFileName);

	if (!((wchFileName[lenFileName -1] == L'p')
	   && (wchFileName[lenFileName -2] == L'h')
	   && (wchFileName[lenFileName -3] == L's')))
	   {
           //ShowMessage  (L" Error file name") ;
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
void TURPolyLine::WriteDBASEFile(wchar_t *wchFileName,TURPolyLine *purPoline, const int quantPolyline)
{
	 FILE  *fw ;

	 fw=_wfopen(wchFileName,L"wb");
   //	 if(!fw) //  //ShowMessage   (L"TYrWrite::PutPointsToCsvFile\nFile is not opened !") ;
	  //1. version number and Date of last update  - первые 0-3  байта
	  // char ch = '\x03';
	 int i0 = 201421059;
		fwrite(&i0,sizeof(int),1 ,fw) ;
		// 2. Number of records  in data file   4-7 байты
		int numRecords = quantPolyline ;
		    fwrite(&numRecords,sizeof(int),1 ,fw) ;
		// 3. bytes 8 -31
		int iarr[] = {1310785,0,0,0,0,22272};
		   fwrite(iarr,sizeof(int),6 ,fw) ;
		// 4. описание полей bytes 32-63
		int iarr1[] = {1346455635
					   ,1699503941
					   ,1174431598
					   ,0
					   ,2835
					   ,0
					   ,0
					   ,0
					   };
		    fwrite(iarr1,sizeof(int),8 ,fw) ;
	  // 5.  Terminator (0Dh) byte 64
	  char ch = '\x0D';
	      fwrite(&ch,1,1 ,fw) ;
	   //
	   for (int i =0 ; i < quantPolyline; i++)
	   {
		ch = '\x20';
		   fwrite(&ch,1,1 ,fw) ;
		char carr1[40] ={0};
		double a=  purPoline[i].calcLeng();
		sprintf_s(carr1, 40, "%19.11e",a);
		   fwrite(carr1,1,19 ,fw) ;
	   }
	 fclose(fw);
}

void TURPolyLine::WriteMainFile(wchar_t *wchFileName,TURPolyLine *purPoline, const int quantPoliline)
{
   const int SHAPE_TYPE =3 ;
  FILE  *fw ;

	 fw=_wfopen(wchFileName,L"wb");
   //	 if(!fw) //  //ShowMessage   (L"TYrWrite::PutPointsToCsvFile\nFile is not opened !") ;

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
		for (int i = 0; i < quantPoliline; i++)
		{
		   iFileLeng += 52 + 4 * purPoline[i].NumParts + 16 * purPoline[i].NumPoints ;
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
		purPoline[0].calcBoundBox()  ;
		memcpy(Box,purPoline[0].Box,4 * sizeof(double));
		for (int i =0 ; i < quantPoliline; i++)
		{
		   purPoline[i].calcBoundBox()  ;
		   if (purPoline[i].Box[0] <  Box[0]) Box[0] =  purPoline[i].Box[0];
		   if (purPoline[i].Box[1] <  Box[1]) Box[1] =  purPoline[i].Box[1];
		   if (purPoline[i].Box[2] >  Box[2]) Box[2] =  purPoline[i].Box[2];
		   if (purPoline[i].Box[3] >  Box[3]) Box[3] =  purPoline[i].Box[3];
		}
		   fwrite(Box,sizeof(double),8 ,fw) ;
		///******************************************************************************************
		///******************************************************************************************

	   // RECORDS
	   for (int i = 0; i < quantPoliline; i++)
	   {
		  // 1. Record Headers
		   // Byte 0 Record Number Record Number Integer Big
		   int iRecNum = i;
		   ChangeByteOrder(& iRecNum);
		   //Byte 4 Content Length Content Length Integer Big
		   int iContLeng = (44 + 4 *  purPoline[i].NumParts + 16 * purPoline[i].NumPoints)/2 ;
		   ChangeByteOrder(& iContLeng);
		   iarr[0] =  iRecNum;
		   iarr[1] =  iContLeng ;
		      fwrite(iarr,sizeof(int),2 ,fw) ;
		   //*****************************************************
		   //********** Content *******************************************
				int ishapetype =   SHAPE_TYPE ;
			   fwrite(&ishapetype ,sizeof(int),1 ,fw) ;
			   fwrite(purPoline[i].Box,sizeof(double),4 ,fw) ;
			   fwrite(&(purPoline[i].NumParts),sizeof(int),1 ,fw) ;
			   fwrite(&(purPoline[i].NumPoints), sizeof(int),1 ,fw) ;

			   fwrite(purPoline[i].Parts, sizeof(int),purPoline[i].NumParts ,fw) ;
			for (int j = 0; j < purPoline[i].NumPoints; j++)
			{
			      fwrite(&(purPoline[i].Points[j].X),sizeof(double),1 ,fw) ;
			      fwrite(&(purPoline[i].Points[j].Y),sizeof(double),1 ,fw) ;
			}

	   }

  fclose(fw);
}
void TURPolyLine::WriteIndexFile(wchar_t *wchFileName,TURPolyLine *purPoline, const int quantPoliline)
{
  FILE  *fw ;
	const int SHAPE_TYPE = 3;
	 fw=_wfopen(wchFileName,L"wb");
   //	 if(!fw) //  //ShowMessage   (L"TYrWrite::PutPointsToCsvFile\nFile is not opened !") ;
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
		int iFileLeng = ( 100 + quantPoliline *8 )/2 ;;
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
		purPoline[0].calcBoundBox()  ;
		memcpy(Box,purPoline[0].Box,4 * sizeof(double));
		for (int i =0 ; i < quantPoliline ; i++)
		{
		   purPoline[i].calcBoundBox()  ;
		   if (purPoline[i].Box[0] <  Box[0]) Box[0] =  purPoline[i].Box[0];
		   if (purPoline[i].Box[1] <  Box[1]) Box[1] =  purPoline[i].Box[1];
		   if (purPoline[i].Box[2] >  Box[2]) Box[2] =  purPoline[i].Box[2];
		   if (purPoline[i].Box[3] >  Box[3]) Box[3] =  purPoline[i].Box[3];
		}
		   fwrite(Box,sizeof(double),8 ,fw) ;
		///******************************************************************************************
		///******************************************************************************************
	   // RECORDS
	   int offset = 100;
	   for (int i = 0; i < quantPoliline; i++)
	   {
		  int ioffset = offset/2;
		  ChangeByteOrder(& ioffset);
		   int iContLeng = (44 + 4 *  purPoline[i].NumParts + 16 * purPoline[i].NumPoints)/2 ;
		   ChangeByteOrder(& iContLeng);
		      fwrite(&ioffset,sizeof(int),1 ,fw) ;
		      fwrite(&iContLeng,sizeof(int),1 ,fw) ;
		   offset +=  52 + 4 *  purPoline[i].NumParts + 16 * purPoline[i].NumPoints ;
	   }

	   fclose(fw);

}

 /*******************************************************************************************************************************/

void TURPolyLine::WriteSetSHPFiles(wchar_t *wchFileName)
{
	 TURPolyLine *purPoline = new TURPolyLine[NumParts];
	 for (int i = 0; i < NumParts; i++)
	 {
	  purPoline [i] =  extractSimplePart(i);
	 }
	int lenFileName = wcslen( wchFileName);

	if (!((wchFileName[lenFileName -1] == L'p')
	   && (wchFileName[lenFileName -2] == L'h')
	   && (wchFileName[lenFileName -3] == L's')))
	   {
           //ShowMessage  (L" Error file name") ;
		 return;
	   }
	 wchar_t wchDBFFileName [200] ,wchSHXFileName [200] ;
	wcscpy(wchSHXFileName, wchFileName);
	wchSHXFileName[lenFileName -1] =  L'x' ;
	wcscpy(wchDBFFileName, wchFileName);
	wchDBFFileName [lenFileName -1] = L'f';
	wchDBFFileName [lenFileName -2] = L'b';
	wchDBFFileName [lenFileName -3] = L'd';
	WriteDBASEFile(wchDBFFileName,purPoline,  NumParts) ;
	WriteMainFile(wchFileName,purPoline,  NumParts) ;
	WriteIndexFile(wchSHXFileName,purPoline,  NumParts) ;
	delete []purPoline;
}
 /*******************************************************************************************************************************/
void TURPolyLine::ReadSHPFile(wchar_t *wchFileName,TURPolyLine **ppurLine,  int *pquantPoliline)
{
	 int lenFileName = wcslen( wchFileName);

	if (!((wchFileName[lenFileName -1] == L'p')
	   && (wchFileName[lenFileName -2] == L'h')
	   && (wchFileName[lenFileName -3] == L's')))
	   {
           //ShowMessage  (L" Error file name") ;
		 return;
	   }
	wchar_t  wchSHXFileName[200] ;
	wcscpy(wchSHXFileName, wchFileName);
	wchSHXFileName[lenFileName -1] =  L'x' ;
	FILE  *fr0 ;

	 fr0=_wfopen(wchSHXFileName,L"rb");
  //	 if(!fr0) //  //ShowMessage   (L"TURPolyLine::ReadSHPFile\nFile is not opened !") ;
	  int offset0 = 32;
	  int ishapetype = -1;

	  fseek(fr0,offset0,SEEK_SET);
	   fread(&ishapetype ,sizeof(int), 1,fr0) ;
	  if (ishapetype != 3)
	  {
          //ShowMessage  (L" There is not polygon in shape file") ;
		 return;
	  }
	   offset0 = 24;
	  fseek(fr0,offset0,SEEK_SET);
	  int lenSHXFile = -1;
	    fread(&lenSHXFile ,sizeof(int), 1,fr0) ;
	  ChangeByteOrder( &lenSHXFile);
	  int quantPoliline =( 2 *  lenSHXFile - 100 )/ 8 ;
	   *ppurLine = (TURPolyLine *)realloc( *ppurLine, quantPoliline * sizeof( TURPolyLine)) ;
	   *pquantPoliline =  quantPoliline ;

		FILE  *fr1 ;

	 fr1=_wfopen(wchFileName,L"rb");
   //	 if(!fr1) //  //ShowMessage   (L"TURPolyLine::ReadSHPFile\nFile is not opened !") ;
	 int offset1 = -1;
	 int iNumParts = -1;
	 int iNumPoints = -1 ;
	 for (int i = 0; i < quantPoliline; i++)
	 {
	   offset0 = 100 + 8 * i;
	   fseek(fr0,offset0,SEEK_SET);
		 fread(&offset1 ,sizeof(int), 1,fr0) ;
	   ChangeByteOrder( &offset1);
	   offset1 = 2 * offset1 + 44;
	   fseek(fr1,offset1,SEEK_SET);
	     fread(&iNumParts ,sizeof(int), 1,fr1) ;
	     fread(&iNumPoints ,sizeof(int), 1,fr1) ;

		TURPolyLine pLine( iNumParts, iNumPoints);
	     fread(pLine.Parts ,sizeof(int), iNumParts,fr1) ;
	   for (int j = 0; j < iNumPoints; j++)
	   {
		 double x,y;
		//   fread(& ((*ppurPlg)[i ].Points[j].X) ,sizeof(double), 1,fr1) ;
		//   fread(& ((*ppurPlg)[i ].Points[j].Y) ,sizeof(double), 1,fr1) ;
		   fread( &x ,sizeof(double), 1,fr1) ;
		   fread( &y ,sizeof(double), 1,fr1) ;
		 pLine.Points[j].X  = x;
		 pLine.Points[j].Y  = y;
	   }
		(*ppurLine)[i ] = pLine;

	 }

	 fclose(fr0);
	 fclose(fr1);

}



// линейное преобразование полилинии
TURPolyLine   TURPolyLine::fncLinTransform(double * arrMtxPer )
{
  TURPolyLine PlnRez = *this;//TURPolyLine (1,NumPoints);
  for (int i = 0; i < NumPoints; i++)
  {
	 PlnRez.Points[i] = Points[i].fncLinTrasform( arrMtxPer );
  }

  return PlnRez;
}

 
 // Создание сетора окружности с центром в точке  pointCentre
// радиусом  valR с шагом по углу valDelFi и
TURPolyLine TURPolyLine::fncCreateSector(const TURPointXY pointCentre, const double valR,
					const double valFi0,const double valFi1,const int NPoints)
{

 TURPointXY  *parrPoints = new TURPointXY  [ NPoints] ;
 double valFiCur = valFi0 ;
 const double valDelFi = (valFi1 - valFi0)/ ((double)NPoints -1.);
 parrPoints[0] = pointCentre ;
 for (int i =0; i < NPoints; i++)
 {
   parrPoints[i].X = valR * cos(valFiCur) + pointCentre.X ;
   parrPoints[i].Y = valR * sin(valFiCur) + pointCentre.Y ;
   valFiCur += valDelFi ;
 }

 TURPolyLine plnRez = TURPolyLine(parrPoints, NPoints);
 delete []parrPoints ;
 return  plnRez ;
}

// Создание стрелки
TURPolyLine TURPolyLine::fncCreateArrow(const TURPointXY pointBegin, const TURPointXY pointEnd
					,const double valLength,const double valAng)
{
	const int iNumParts = 3;
	const int iNumPoints = 6 ;
	int iarrParts[3] = {0,2, 4};
	TURPointXY arrPoints[6];
	 arrPoints[0] = pointBegin;
	 arrPoints[1] = pointEnd;
	 arrPoints[2] = pointEnd;
	 arrPoints[4] = pointEnd;
	 TURPointXY pntTr0(-valLength, valLength*tan(valAng));
	 TURPointXY pntTr1(-valLength, -valLength*tan(valAng));
	// double  valAngRot = 0.;
	 if(fabs(pointBegin.X - pointEnd.X ) < 0.0001)
	 {
	  arrPoints[3] = TURPointXY(pointEnd.X -valLength * tan(valAng) , pointEnd.Y -  Sign(pointEnd.Y -pointBegin.Y)* valLength);
	  arrPoints[5] = TURPointXY(pointEnd.X +valLength * tan(valAng) , pointEnd.Y -  Sign(pointEnd.Y -pointBegin.Y)* valLength);
	 }
	 else
	 {
	  double  valAngRot = atan2(pointEnd.Y- pointBegin.Y, pointEnd.X- pointBegin.X);
	  arrPoints[3] = pntTr0.LinTransform(  valAngRot , pointEnd,1. );
	  arrPoints[5] = pntTr1.LinTransform(  valAngRot , pointEnd,1. );
	 }
	return TURPolyLine( iNumParts, iNumPoints,iarrParts ,arrPoints) ;
}

// Создание осей координат сос стрелками
TURPolyLine TURPolyLine::fncCreateAxes(const TURPointXY pointBeginX, const TURPointXY pointEndX
									   ,const TURPointXY pointBeginY, const TURPointXY pointEndY
									  ,const double valLength)
{
	const double valAng = 10. /180. *M_PI;
	const int iNumParts = 6;
	const int iNumPoints = 12 ;
	int iarrParts[6] = {0,2, 4,6,8,10};
	TURPointXY arrPoints[12];
	TURPolyLine ArrowX = fncCreateArrow( pointBeginX,  pointEndX, valLength, valAng);
	TURPolyLine ArrowY = fncCreateArrow( pointBeginY,  pointEndY, valLength, valAng);
	memcpy(arrPoints, ArrowX.Points, 6 * sizeof( TURPointXY));
	memcpy(&arrPoints[6], ArrowY.Points, 6 * sizeof( TURPointXY));

	return TURPolyLine( iNumParts, iNumPoints,iarrParts ,arrPoints) ;
}

// линейное преобразование полигона  пергруженная
// INPUT:
// valAng - угол поворота
// pntSdvig - точка куда перемещается центр полигона
// valRastigenie - коэффициент растяжения
// OUTPUT:
// возвращает преобразованный полигон
TURPolyLine   TURPolyLine::LinTransform(const double  valAng , const TURPointXY pntSdvig,const double valRastigenie )
{
  double arrMtxPer[4] = {0.};
  arrMtxPer[0] = cos(valAng);
  arrMtxPer[1] = -sin(valAng);
  arrMtxPer[2] = -arrMtxPer[1];
  arrMtxPer[ 3] = arrMtxPer[0];

  TURPolyLine PlnTemp1 = RastiagenieTransform( valRastigenie  );
  TURPolyLine PlnTemp2 = PlnTemp1.fncLinTransform( arrMtxPer );
  TURPolyLine PlnRez   =  PlnTemp2.SdvigTransform(pntSdvig) ;

  return PlnRez;
}


// сдвиг полигона на вектор  pntSdvig
TURPolyLine   TURPolyLine::SdvigTransform(const TURPointXY pntSdvig )
{
  TURPolyLine PlgRez = *this;
  for (int i = 0; i < NumPoints; i++)
  {
	 PlgRez.Points[i].X += pntSdvig.X;
	 PlgRez.Points[i].Y += pntSdvig.Y;
  }
  return PlgRez;
}
// растяжение полигона с коэффициентом valRastigenie
TURPolyLine   TURPolyLine::RastiagenieTransform( const double valRastigenie )
{
  TURPolyLine PlgRez = *this;
  for (int i = 0; i < NumPoints; i++)
  {
	 PlgRez.Points[i].X = PlgRez.Points[i].X *valRastigenie;
	 PlgRez.Points[i].Y = PlgRez.Points[i].Y *valRastigenie ;
  }
  return PlgRez;
}
double TURPolyLine::Sign(const double x)
{
	if (x > 0.)
	{
	   return 1.;
	}
	if (x < 0.)
	{
	   return -1.;
	}
	return 0.;
}


// создание сетки
TURPolyLine   TURPolyLine::createFishNet(const double ValLeft, const double ValRight
   ,const double ValDown,const double ValUp, const double ValCellSizeWidth, const double ValCellSizeHeight )
{
	int iNumParts1 =  (ValRight -  ValLeft +0.000001)/ ValCellSizeWidth;
	int iNumParts0 =  (ValUp -  ValDown +0.000001)/ ValCellSizeHeight;
	const int iNumParts = iNumParts0  + iNumParts1 ;
	const int iNumPoints = 2 * iNumParts;
	int *iarrParts = new int[iNumParts];
	TURPointXY *arrPoints = new TURPointXY[2 * iNumParts];
	for (int i =0; i < iNumParts; i++)
	{
	 iarrParts[i] = 2 * i;
	}
	for (int i =0; i < iNumParts0; i++)
	{
		arrPoints[i * 2]= TURPointXY(ValLeft, ValDown + ((double)i) *  ValCellSizeHeight );
		arrPoints[i * 2 + 1]= TURPointXY(ValRight, ValDown + ((double)i) *  ValCellSizeHeight );
	}
	for (int i =0; i < iNumParts1; i++)
	{
		arrPoints[(iNumParts0 + i) * 2]= TURPointXY(ValLeft + ((double)i) * ValCellSizeWidth, ValDown );
		arrPoints[(iNumParts0 + i) * 2 + 1]= TURPointXY(ValLeft + ((double)i) * ValCellSizeWidth, ValUp);
	}
	TURPolyLine ln( iNumParts, iNumPoints,iarrParts,arrPoints) ;
	delete iarrParts;
	delete  []arrPoints;
	return ln;
}


// создание графика функции тангенса на интервале -p1/2  до pi/2
void   TURPolyLine::createTangGraph(wchar_t*FileName, const int NUmPoints )
{
	TURPolyLine plnRez(1, NUmPoints) ;
	const double STep = M_PI/ ((double)( NUmPoints + 2));
	for (int i =0; i < NUmPoints; i++)
	{
	 plnRez.Points[i].X = -M_PI/2. + ((double)(1+i)) * STep;
	  plnRez.Points[i].Y = tan( plnRez.Points[i].X);
	}
	plnRez.WriteSetSHPFiles(FileName, &plnRez, 1 ) ;
	return ;
}

void   TURPolyLine::createOddPolinomGraph(wchar_t* FileName, int iNPolinom, double *arrCoeff, double valDiapazon )
{
	const int NUmPoints = 10000;
	TURPolyLine plnRez(1, NUmPoints) ;
	int lenarr = iNPolinom/2 +1;
	const double STep = valDiapazon/ ((double)( NUmPoints + 1));
	for (int i =0; i < NUmPoints; i++)
	{
	 plnRez.Points[i].X = ((double)(1+i)) * STep;

	 plnRez.Points[i].Y = fncOddPolinom1(arrCoeff,  lenarr, plnRez.Points[i].X);
	}
	plnRez.WriteSetSHPFiles(FileName, &plnRez, 1 ) ;
	return ;
}

void   TURPolyLine::createOddPolinomMinusZGraph(wchar_t* FileName, int iNPolinom, double *arrCoeff, double valDiapazon )
{
	const int NUmPoints = 10000;
	TURPolyLine plnRez(1, NUmPoints) ;
	int lenarr = iNPolinom/2 +1;
	const double STep = valDiapazon/ ((double)( NUmPoints + 1));
	for (int i =0; i < NUmPoints; i++)
	{
	 plnRez.Points[i].X = ((double)(1+i)) * STep;

	 plnRez.Points[i].Y = fncOddPolinom1MinusZ(arrCoeff,  lenarr, plnRez.Points[i].X);
	}
	plnRez.WriteSetSHPFiles(FileName, &plnRez, 1 ) ;
	return ;
}


 double fncOddPolinom1(double *arrCoeff, int lenarr, double valArg)
 {

   double valTemp =  valArg;
   double valSum = 0.;
   for (int i = 0; i < lenarr; i++)
   {
	 valSum +=  valTemp *  arrCoeff[i];
	 valTemp = valTemp * valArg * valArg;
   }
   return valSum;
 }

 double fncOddPolinom1MinusZ(double *arrCoeff, int lenarr, double valArg)
 {

   double valTemp =  1./valArg;
   double valSum = 0.;
   for (int i = 0; i < lenarr; i++)
   {
	 valSum +=  valTemp *  arrCoeff[i];
	 valTemp = valTemp /( valArg * valArg);
   }
   return valSum;
 }


 void   TURPolyLine::createPolinomGraph(wchar_t* FileName, int iNPolinom, double *arrCoeff, double valDiapazon0, double valDiapazon1 )
{
	const int NUmPoints = 10000;
	TURPolyLine plnRez(1, NUmPoints) ;

	const double STep = fabs(valDiapazon0- valDiapazon1)/ ((double)( NUmPoints + 1));
	double valBegin = (valDiapazon0 < valDiapazon1)? valDiapazon0:valDiapazon1;
	for (int i =0; i < NUmPoints; i++)
	{
	 plnRez.Points[i].X = valBegin + ((double)(1+i)) * STep;

	 plnRez.Points[i].Y = fncPolinom1(arrCoeff,  iNPolinom +1, plnRez.Points[i].X);
	}
	plnRez.WriteSetSHPFiles(FileName, &plnRez, 1 ) ;
	return ;
}

double fncPolinom1(double *arrCoeff, int lenarrCoeff, double valArg)
 {

   double valTemp =  1.;
   double valSum = 0.;
   for (int i = 0; i < lenarrCoeff ; i++)
   {
	 valSum +=  valTemp *  arrCoeff[i];
	 valTemp = valTemp * valArg ;
   }
   return valSum;
 }

 TURPolyLine TURPolyLine::create_SinX_Div_X_Line( TURPointXY pntSdvig, double scalex, double scaley, int numRoot)
{
	double valStep =0.01;


	const double VAlDiap = numRoot * M_PI;  // диапахзон графика по обобщ координате плюс минус
	int iNumPoints = VAlDiap / valStep;
	 iNumPoints = 2 * iNumPoints + 1;
	 TURPolyLine pln( 1,  iNumPoints) ;

   for (int i=0 ; i < iNumPoints; i++)
  {
   double valGenAngCur = -VAlDiap + ((double)i ) * valStep;

   pln.Points[i].X   =  valGenAngCur * scalex + pntSdvig.X;
   pln.Points[i].Y = fncDiagrSinx_div_x__(valGenAngCur ) * scaley + pntSdvig.Y;
  }
  return pln;
}

// нахожэдение точки лежащей на расстоянии VAlDist
// от нулевой точки по траектории полилинии
bool TURPolyLine::calcWayPoint( const double VAlDist, TURPointXY &pntRez)
{
  if (NumParts > 1)
  {
   return false;
  }
  bool breturn = false;
  int iNum = -1;
  for (int i = 1; i < NumPoints; i++)
  {
   TURPolyLine plnTemp(Points, i +1);
   double length = plnTemp.calcLeng();
   if (length >= VAlDist)
   {
	iNum = i;
	breturn = true;
	break;   
   }
  }
  if (!breturn)
  {
	return false;
  }

  double valLength0 = 0.;
  if (iNum > 1)
  {
	TURPolyLine plnTemp1(Points, iNum );
	valLength0 = plnTemp1.calcLeng();
  }

  double valDist1 = VAlDist -  valLength0;
  TURPolyLine plnTemp(Points[iNum -1], Points[iNum]);
  double valLength1 = plnTemp.calcLeng();

  pntRez =   TURPointXY::ParamPoint(Points[iNum -1],Points[iNum],valDist1/ valLength1); // p1 + alf*(p2-p1)
  return true;
}

double TURPolyLine::LinearValueApprox(double x)
{
	 calcBoundBox();
	 if (NumPoints == 0)
	 {
	 return 0.;
	 }
   if (x < Box[0])
   {
			if (Points[NumPoints-1].X > Points[0].X)
			{
			return Points[0].Y;
			}
			else
			{
			return Points[NumPoints-1].Y;
			}
	 }

   if (x > Box[2])
   {
			if (Points[NumPoints-1].X > Points[0].X)
			{
			 return Points[NumPoints-1].Y;
			}
			else
			{
			return Points[0].Y;
			}
	 }
   ///
   double valReturn = -1.;                               // 11.01.2018
   for (int i =0; i < NumPoints -1; i++)
   {
			if ((x - Points[i].X)*(x - Points[i +1].X) <= 0.)
			{

				if ((fabs(Points[i].X -  Points[i + 1].X )< 2.* DBL_MIN))
				{
				 valReturn =  (Points[i].Y  + Points[i +1].Y) /2.;  // 11.01.2018
				 break;                                             // 11.01.2018
			   //	return (Points[i].Y  + Points[i +1].Y) /2.;     // 11.01.2018
				}

				double valTang  =  (Points[i].Y -  Points[i + 1].Y )/(Points[i].X -  Points[ i + 1].X );  // 11.01.2018
				valReturn =  valTang * (x -  Points[i].X) + Points[i].Y;                                     // 11.01.2018
				break;                                                                                    // 11.01.2018
			   //	return   valTang * (x -  Points[i].X) + Points[i].Y;      // 11.01.2018
			}
	 }

   return valReturn;       // 11.01.2018

}


// аппроксимация производной функции в точке x
double TURPolyLine::LinearDerivApprox(double x)
{
calcBoundBox();
if (x < Box[0])
   {
			if (Points[NumPoints-1].X > Points[0].X)
			{
			return Points[0].Y;
			}
			else
			{
			return 0.;
			}
	 }

   if (x > Box[2])
   {
			if (Points[NumPoints-1].X > Points[0].X)
			{
			 return Points[NumPoints-1].Y;
			}
			else
			{
			return 0.;
			}
	 }
   double valReturn = -1.0;
   for (int i =0; i < NumPoints-1; i++)
   {
		if (((fabs(Points[i].X -  Points[i + 1].X )< 2.* DBL_MIN)) <=0.)
		{
			if (fabs(Points[0].X -  Points[1].X )< 2.* DBL_MIN)
			{
			  valReturn =  1000000000.;
			  break;
			// return  1000000000.;
			}
			valReturn =  (Points[i].Y -  Points[i + 1].Y )/(Points[i].X -  Points[ i + 1].X );
			break;
		  //	return (Points[i].Y -  Points[i + 1].Y )/(Points[i].X -  Points[ i + 1].X );
		}
   }
  return valReturn;
}


// нормализация полилинии модуля диаграммы
// максимум делается  valMax

TURPolyLine TURPolyLine::nomalizationDiagr(double valMax, double *pXMax)
{
  TURPolyLine plnRez = *this;
  int irez = -1;
  double valMaxCur = -100000000000.;
  for (int i = 0; i < NumPoints; i++)
  {
	if (Points[i].Y > valMaxCur)
	{
	 valMaxCur = Points[i].Y;
	 irez = i;
	}
  }
  *pXMax = Points[irez].X;
  double temp = valMax /valMaxCur;
  for (int i = 0; i < NumPoints; i++)
  {
	plnRez.Points[i].Y *=  temp;
   //	plnRez.Points[i].X -= (*pXMax);
  }

  return plnRez;

}

// коррекция полилигии аргумента диаграммы
TURPolyLine TURPolyLine::RepaireArg()
{
	TURPolyLine plnRez = *this;
	double valAdd = 0.;
	for (int i = 1; i < NumPoints; i++)
	{
	  if (fabs(fabs(Points[i-1].Y - Points[i].Y) - 2. * M_PI)< 0.2)
	  {
		 valAdd += 2. * M_PI * Sign( Points[i-1].Y - Points[i].Y );
	  }
	  plnRez.Points[i].Y += valAdd;
	}
	return plnRez;
}

void TURPolyLine::stretchDiagrAlongXY(double valCoeffX, double valCoeffY)
{
	for (int i = 0; i < NumPoints; i++)
	{
	  Points[i].X *= valCoeffX;
	  Points[i].Y *= valCoeffY;
	}
}


// нахождение ширины нормированной диаграммы по уровню 0,707
double TURPolyLine::calcDiagrWidth()
{
	double valMax = -1000.;
	for (int i =0; i < NumPoints; i++)
	{
	if (Points[i].Y > valMax )
	{
	valMax =  Points[i].Y ;
	}
	}
	double valF707 = sqrt(2.) * valMax/ 2.;
	double arrTEt707[2] ={0.};
	int icur = 0;
	for (int i =0; i < (NumPoints -1); i++)
	{
	  if ((valF707 - Points[i].Y) * (valF707 -Points[i + 1].Y) <= 0.)
	  {
		if (fabs(Points[i].Y - Points[i + 1].Y)< 0.00000000001)
		{
		 arrTEt707[icur] = (Points[i].X +  Points[i + 1].X) /2.;
		}
		else
		{
		  arrTEt707[icur] = Points[i].X + ( Points[i + 1].X -  Points[i].X ) /(Points[i+1].Y - Points[i].Y)*( valF707 - Points[i].Y);
		}
		icur++;
		if (icur > 1)
		{
		break;
		}
		}

	}

	return fabs ( arrTEt707[1] - arrTEt707[0]);
}

 // нахождение аргмаксимума простой полилилинии (графика)
int TURPolyLine::calcGraphArgMax()
{
	double valMax = -10000000000.;
	int iargMax = -1;
	for (int i = 0; i < NumPoints; i++)
	{
	   if (Points[i].Y > valMax)
	   {
		valMax = Points[i].Y;
		iargMax = i;
	   }
	}

	return iargMax  ;
}

//------------------------------------------------------------------
//  создание линейчатой диаграммы
// задан набор точек parrAimingPoints_X [iQuantAimingPoints_X] по оси X
// в количестве iQuantAimingPoints_X
// задача заключается в том, чтобы построить вертикальные линии в количестве iQuantAimingPoints_X
// каждая из которых начинаетя в точке  (parrAimingPoints_X [i],  ((double)piarrRepeatQuants_X[i] ))
// и заканчивается в точке  (parrAimingPoints_X [i],  0)
TURPolyLine TURPolyLine::createLineDiagram(
		 double *parrAimingPoints_X , int *piarrRepeatQuants_X
		 , const int iQuantAimingPoints_X)
{


	const int iNumParts = iQuantAimingPoints_X ;
	const int iNumPoints = 2 * iNumParts;
	int *iarrParts = new int [iNumParts];
	TURPointXY *arrPoints = new TURPointXY[iNumPoints * 2];
	for (int i =0; i < iNumParts ; i++)
	{
	  iarrParts[i] = 2 * i;
	  arrPoints [2 * i] = TURPointXY (parrAimingPoints_X [i],  ((double)piarrRepeatQuants_X[i] ));
	  arrPoints [2 * i + 1] = TURPointXY (parrAimingPoints_X [i],0.);

	}

	TURPolyLine plnReturn ( iNumParts, iNumPoints,iarrParts
			,arrPoints);

	delete iarrParts ;
	delete []arrPoints;
	return plnReturn;
}

//----------------------------------------------------------

//------------------------------------------------------------------
//  создание линейчатой диаграммы   ПЕРЕГРУЖЕННАЯ !!!
// задан набор точек parrAimingPoints_X [iQuantAimingPoints_X] по оси X
// в количестве iQuantAimingPoints_X
// задача заключается в том, чтобы построить вертикальные линии в количестве iQuantAimingPoints_X
// каждая из которых начинаетя в точке  (parrAimingPoints_X [i],  parrRepeatQuants_X[i] ))
// и заканчивается в точке  (parrAimingPoints_X [i],  0)
TURPolyLine TURPolyLine::createLineDiagram(
		 double *parrAimingPoints_X , double *parrRepeatQuants_X
		 , const int iQuantAimingPoints_X)
{


	const int iNumParts = iQuantAimingPoints_X ;
	const int iNumPoints = 2 * iNumParts;
	int *iarrParts = new int [iNumParts];
	TURPointXY *arrPoints = new TURPointXY[iNumPoints * 2];
	for (int i =0; i < iNumParts ; i++)
	{
	  iarrParts[i] = 2 * i;
		arrPoints [2 * i] = TURPointXY (parrAimingPoints_X [i],  parrRepeatQuants_X[i] );
	  arrPoints [2 * i + 1] = TURPointXY (parrAimingPoints_X [i],0.);

	}

	TURPolyLine plnReturn ( iNumParts, iNumPoints,iarrParts
			,arrPoints);

	delete iarrParts ;
	delete []arrPoints;
	return plnReturn;
}

//----------------------------------------------------------
//
// сдвиг полигона на вектор  pntSdvig
TURPolyLine   TURPolyLine::MultScalar(const double VAla )
{
  TURPolyLine PlgRez = *this;
  for (int i = 0; i < NumPoints; i++)
  {
	 PlgRez.Points[i].Y *= VAla;
  }
  return PlgRez;
}


void TURPolyLine::createTargPointsArray(const int valTargCellSize, TURPointXY **ppTargPntArray, int *plenTargPntArray)
{
  int lenCur = 0;
  for (int i =0; i < NumParts; i++)
  {
   TURPolyLine   PolyLine = extractSimplePart(i);
   int quantPoints = PolyLine.calcLeng() /valTargCellSize + 1;
   if ((lenCur + quantPoints) > (*plenTargPntArray))
   {
	 *ppTargPntArray =  (TURPointXY *)realloc(*ppTargPntArray, (lenCur + quantPoints ) * sizeof(TURPointXY));
	 *plenTargPntArray = lenCur + quantPoints  ;
   }
   (&PolyLine)->fillTargPointsArray( valTargCellSize,  &((*ppTargPntArray)[lenCur]));
   lenCur +=  quantPoints ;

  }
  *ppTargPntArray =  (TURPointXY *)realloc(*ppTargPntArray, lenCur  * sizeof(TURPointXY));
  *plenTargPntArray = lenCur ;
}

/*******************************************************************************************************************************/
 int  TURPolyLine::calcQuantsNetPoints(const double  VAlCellSize)
 {
	 return 0;
 }

 //---------------------------------------------------------------------------------------------
 // извлечение из составного   полилинии  простой с номером n
TURPolyLine   TURPolyLine::extractSimplePart(const int n)
{
	if (n >= NumParts)
	{
         //ShowMessage  (L"Error calcPartSq: n >= NumParts");
	   //Abort() ;
	}

	int quanP = ( n == (NumParts -1))?(NumPoints - Parts[n] ):( Parts[n +1] - Parts[n] );
	TURPolyLine pln(&Points[Parts[n]], quanP);

	return pln;

}
 //---------------------------------------------------------------------------------------------

int TURPolyLine::calcQuantApproximatingPoints(const double valTargCellSize)
{
	return 0;
}

void TURPolyLine::fillTargPointsArray( const double valTargCellSize,  TURPointXY *pPntArr)
{
  int quantPoints = calcLeng() /valTargCellSize + 1;
 // double valStep =  quantPoints *
  for (int i =0; i < quantPoints; i++)
  {
	double valCurveLengthCur = ((double)i) * valTargCellSize ;
	int n = 0;
	double del_l = 0.;
	double sum = 0;
	for (n =0; n < NumPoints; n++)
	{
	  double vald = dist(&(Points[n]), &(Points[n + 1]));
	  sum +=  vald;
	  if (sum >= valCurveLengthCur)
	  {
	   del_l = valCurveLengthCur - sum +  vald;
	   break;
	  }
	}
	double valD =  dist(&(Points[n]), &(Points[n + 1]));
	pPntArr[i].X = Points[n].X + del_l/ valD * (Points[n + 1].X - Points[n].X);
	pPntArr[i].Y = Points[n].Y + del_l/ valD * (Points[n + 1].Y - Points[n].Y);

  }
}


 /*******************************************************************************************************************************/


void TURPolyLine::createUnatedPointsArray(TURPointXY **ppunatedPoints, int *quantUnitedPoints)
{
 *ppunatedPoints = (TURPointXY *)realloc(*ppunatedPoints, NumPoints * sizeof( TURPointXY));
 *quantUnitedPoints = NumPoints;
 memcpy(*ppunatedPoints, Points, NumPoints * sizeof( TURPointXY));

}

 /*******************************************************************************************************************************/
void   TURPolyLine::LinearTransformation(const double  valAng , const TURPointXY pntSdvig,const double valRastigenie )
{
TURPolyLine plnCur = LinTransform(  valAng ,  pntSdvig, valRastigenie ) ;
*this =  plnCur;
}
//---------------------------------------------------------------
/// нахождение выпуклой оболочки
void   TURPolyLine::ConvexShell(TURPolygon *pPolgConv)
{
	*pPolgConv =   TURPolygon::Conv(Points // массив точек, input
			, NumPoints // длина массива точек , input
				)  ;
}

TURPolyLine TURPolyLine::createUZP_Skaliga_AirPlane(const double VAlR1,const double VAllProbMean, const int NUmPoints)
{
	const double VAlR = VAlR1 * 1.1;
	double valStep =  VAlR / (((double)NUmPoints) -1.);
	TURPolyLine plnRez(1, NUmPoints);
	for (int i = 0; i < NUmPoints; i++)
	{
	 plnRez.Points[i].X = valStep * ((double)i);
	 plnRez.Points[i].Y = fncScaligaPlaneLaw__( VAlR1,  VAllProbMean, plnRez.Points[i].X);
	}
	plnRez.Points[NUmPoints-1].Y  = 0.;
	return plnRez;
}

//---------------------------------------------------------------------------
// вычисление вероятности пораж самол в соответствии с программой скалыги
// INPUT:
// VAlR1 - дальность осреднениря
// VAlProbMean - средняя вероятность
// VAlMiss - промах
double TURPolyLine::fncScaligaPlaneLaw__(const double VAlR1, const double VAlProbMean, const double VAlMiss)
{
		double eps,x,Fx,x1,x2,Fx1,So;
		eps = 0.001;
		const double VAlR = VAlR1 * 1.1;
		x = 18.0;
		Fx = (VAlR * VAlR * VAlProbMean) / (1.0 - exp(-VAlR * VAlR/x)) - x;
		for (int  i=1; (fabs(Fx) > eps); i++)
		{
		x1 = Fx + x;
		Fx1 = (VAlR * VAlR * VAlProbMean) / (1.0 - exp(-VAlR * VAlR/x1)) - x1;
		x2 = Fx1 + x1;
		x = (x * x2 - x1*x1) / (x2 - 2 * x1 +x);
		Fx = (VAlR * VAlR * VAlProbMean) / (1.0 - exp(-VAlR * VAlR/x)) - x;
		}
		So=sqrt(0.5*x);
		if(VAlMiss >= VAlR) return 0.;
		else return exp(-VAlMiss  * VAlMiss/(2.*So*So));
}


//---------------------------------------------------------------------------


double TURPolyLine::fncDiagrSinx_div_x__(double tet)
{
if (fabs(tet)< 0.0000001) return 1.;

return sin(tet)/tet;
}

//---------------------------------------------
// линейное преобразование полигона
// INPUT:
// valAng - угол поворота
// pntCentre - точка центра полигона
// pntSdvig - точка куда перемещается центр полигона
// valRastigenie - коэффициент растяжения
// OUTPUT:
// возвращает преобразованный полигон
TURPolyLine   TURPolyLine::LinTransform(const double  valAng, const TURPointXY pntCentre
  , const TURPointXY pntSdvig,const double valRastigenie )
{
  double arrMtxPer[4] = {0.};
  arrMtxPer[0] = cos(valAng);
  arrMtxPer[1] = -sin(valAng);
  arrMtxPer[2] = -arrMtxPer[1];
  arrMtxPer[ 3] = arrMtxPer[0];
  TURPointXY pntSdvig1( -pntCentre.X,-pntCentre.Y) ;
  TURPolyLine PlgTemp0 = SdvigTransform( pntSdvig1 );
  TURPolyLine PlgTemp1 = PlgTemp0.RastiagenieTransform( valRastigenie  );
  TURPolyLine PlgTemp2 = PlgTemp1.fncLinTransform( arrMtxPer );
  TURPolyLine PlgRez   =  PlgTemp2.SdvigTransform(pntSdvig) ;
  return PlgRez;
}

//-----------------------------------

// симметричное отражение полигона относительно оси OY
TURPolyLine   TURPolyLine::SimOtragenieY_and_flip()
{
  TURPolyLine PlgRez = *this;
  for (int i = 0; i < NumPoints; i++)
  {

	 PlgRez.Points[i].X = -PlgRez.Points[i].X ;
	}
	PlgRez.flip();
  return PlgRez;
}

//------------------------

// изменение порядка следования вершин на противоположный
void TURPolyLine::flip()
{
	for (int n= 0; n < NumParts; n++)
	{
		 flipPart(n);
	}
}
// изменение порядка следования вершин в частичном полигоене с ноером n
void TURPolyLine::flipPart(const int n)
{
  if (n >= NumParts)
	{
           //ShowMessage  (L"Error flipPart: n >= NumParts");
	   //Abort() ;
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

//-------------------------------------------------

int  TURPolyLine::WriteToASCII__(wchar_t*FileName)


 // Запись  в  файл формата ASCII


{

    FILE  *fw ;

     fw=_wfopen(FileName,L"w");
     if(!fw)
     {
      //  //ShowMessage   (L"ERROR\nWriteToASCII for PolyLine\nFile is not opened !") ;
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

TURPolyLine   TURPolyLine::setUpGraph( const TURPointXY pntDate00
,const double  valAng ,const double valCoeffX,const double valCoeffY )
{
  double arrMtxPer[4] = {0.};
  arrMtxPer[0] = cos(valAng);
  arrMtxPer[1] = -sin(valAng);
  arrMtxPer[2] = -arrMtxPer[1];
  arrMtxPer[ 3] = arrMtxPer[0];
  // 1.
   TURPointXY pnt (-pntDate00.X, -pntDate00.Y);
   TURPolyLine PlnTemp1 =  SdvigTransform(pnt) ;
   ///

   // 2.
    TURPolyLine PlnTemp2 = PlnTemp1.fncLinTransform( arrMtxPer );
    ///

    // 3.
     PlnTemp2.stretchDiagrAlongXY( valCoeffX, valCoeffY) ;
     ///


  return PlnTemp2;
}










