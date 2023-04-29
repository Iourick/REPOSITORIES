﻿//---------------------------------------------------------------------------


//#pragma hdrstop

#include "YrRastr.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "YrWrite.h"
#include <math.h>
#include "UrPointXY.h"
#include "URPolygon.h"
//---------------------------------------------------------------------------
//#pragma package(smart_init)
extern const double NODATA = -999999.0;
extern const double NODATA1 = -999998.0;
const double PI = 3.1415 ;
const double DNIL  = -1000000001.0;
const double DNIL1 = -100000000.0 ;
const double EPSSING = 1.0E-32  ;
const double EPS  = 0.0000000000000001 ;

 TYrRastr::~ TYrRastr()
{

  if( pflt_rastr != NULL)delete [] pflt_rastr ;
  //  pflt_rastr = NULL;
}

 TYrRastr ::TYrRastr()
:   ncols(0)
   , nrows(0)
   ,xllcorner(0)
   ,yllcorner(0)
   ,cellsize(0)
   ,nodata(NODATA)
   //,prastr(NULL)
   ,pflt_rastr(NULL)

{
  strcpy(byteorder, "byteorder     LSBFIRST") ;
}
TYrRastr ::TYrRastr(wchar_t *wFileName)
{
	nodata = NODATA ;
	pflt_rastr = NULL ;
	strcpy(byteorder, "byteorder     LSBFIRST") ;
	wcscpy(wMyFltFile ,wFileName) ;
	double nodata_t; // из wFileName


	// Чтение .HDR файла
	int len = wcslen(wFileName) ;
	if ( !(( wFileName[len - 1] == 't') && (wFileName[len - 2] == 'l') // проверка, что
	&& (wFileName[len - 3] == 'f') ) )  // указанный файл имеет расширение .flt
	{
	//String St = wFileName ;
	//ShowMessage (L"TYrRead::ReadHdrFileFromFltFile\nExtention of " + St + L"is wrong") ;

	}
	wchar_t* HdrFileName = new wchar_t[len] ;
	wcscpy( HdrFileName, wFileName) ;
	HdrFileName[len - 1] = 'r';
	HdrFileName[len - 2] = 'd';
	HdrFileName[len - 3] = 'h';

	FILE *fr0 ;	if ((fr0 = _wfopen(HdrFileName,L"r"))== NULL)	{
	//String St =  HdrFileName ;
	//ShowMessage (L" ERROR ! Not possible to open " +St) ;

	}	int ncols1,nrows1;	double xllcorner1,yllcorner1,cellsize1,NODATA_value1 ;	char  str_xll[50],str_yll[50],str_sell[50],str_nodat[50];	if	(	( fscanf(fr0,"ncols         %d\n",&ncols1)== 0)	||(  fscanf(fr0,"nrows         %d\n",&nrows1 ) == 0)	|| ( fscanf(fr0,"xllcorner     %s\n",str_xll) == 0)	|| ( fscanf(fr0,"yllcorner     %s\n",str_yll)== 0 )	|| ( fscanf(fr0,"cellsize      %s\n",str_sell )== 0)	|| ( fscanf(fr0,"NODATA_value  %s\n",str_nodat  ) == 0 )	)	{	//ShowMessage (L"Error in format of HDR File");

	}	replace(str_xll);	replace(str_yll);	replace(str_sell);	replace(str_nodat);	fclose(fr0) ;	delete  [] HdrFileName ;	ncols =ncols1;	nrows =nrows1;	xllcorner =atof(str_xll);	yllcorner = atof(str_yll);	cellsize = atof(str_sell);	nodata_t = atof(str_nodat);
	// Конец чтения
	pflt_rastr = new double [ nrows * ncols ] ;
	if ( pflt_rastr == NULL)
	{
	//ShowMessage (L"Not memory for pflt_rastr in  TYrRastr ::TYrRastr(wchar_t *wFileName)") ;
	//Abort() ;

	}
	// Чтение FLT файла
	//   В файле . flt массив хранится в порядке слева направо, сверху вниз
	//   У нас принято хранить слева направо снизу вверх (в порядке возрастания координат X и Y)
	//  Т е  parrZ[0] - это левый нижний элемент

	float *Ztemp = new float [ nrows * ncols] ;
	if (Ztemp == NULL)
	{
	//ShowMessage (L"TYrRead::ReadFltFile\nThere are not memory for Ztemp" ) ;

	}

	FILE *fr ;
	if (	(fr=_wfopen(wFileName,L"rb")) == NULL)
	{
	//String s_22 =  L"TYrRead::ReadFltFile\nNot possible to open file" ;
	//ShowMessage (s_22) ;

	}
	fread(Ztemp,sizeof(float),nrows * ncols,fr) ;
	fclose(fr);
	int i1 = 0;
	int j1 = 0;

	for ( i1 = 0; i1 < nrows; i1++)
	for ( j1 = 0; j1 < ncols; j1++)
	{
	pflt_rastr[i1*ncols + j1]=  (double) Ztemp[(nrows-1-i1)*ncols +j1] ;
	if (fabs( pflt_rastr[i1*ncols + j1]/2 - nodata_t/2) < 1.) pflt_rastr[i1*ncols + j1] = nodata ;

	}
	delete [] Ztemp ;
}

// извлечение растра с центом в точке pntP0 и длиной 2 * do
TYrRastr::TYrRastr(wchar_t *wFileName,const TURPointXY pntP0,const double d0)
{
	nodata = NODATA ;
	pflt_rastr = NULL ;
	strcpy(byteorder, "byteorder     LSBFIRST") ;
	wcscpy(wMyFltFile ,wFileName) ;




	 int ncols2, nrows2;
	 double   xllcorner2,yllcorner2;
	 char  pbyteorder[50];
	ReadHDRFile (wFileName,&ncols2, &nrows2, &xllcorner2,&yllcorner2, &cellsize, &nodata, pbyteorder)  ;

	ncols =(int)( 2 * d0/ cellsize);
    nrows =  ncols;
	int ii1 =  (pntP0.X - d0 - xllcorner2)/ cellsize ;
	int jj1 =  (pntP0.Y - d0 - yllcorner2)/ cellsize ;
	xllcorner =  ((double)ii1)  * cellsize + xllcorner2 ;
	yllcorner =  ((double)jj1)  * cellsize + yllcorner2;
	 xllcorner = ( xllcorner >= xllcorner2)?xllcorner :xllcorner2;
	 yllcorner = ( yllcorner >= yllcorner2)?yllcorner :yllcorner2;
	 if(( xllcorner + 2 *d0) > (xllcorner2 + ncols2 * cellsize))
	 {
	   ncols = (xllcorner2 + ncols2 * cellsize -xllcorner) /cellsize;
	 }
	 if(( yllcorner + 2 *d0) > (yllcorner2 + nrows2 * cellsize))
	 {
	   nrows = (yllcorner2 + nrows2 * cellsize -yllcorner) /cellsize;
	 }



	pflt_rastr = new double [ nrows * ncols ] ;
	if ( pflt_rastr == NULL)
	{
	//ShowMessage (L"Not memory for pflt_rastr in  TYrRastr ::TYrRastr(wchar_t *wFileName)") ;
	//Abort() ;

	}
	// Чтение FLT файла
	//   В файле . flt массив хранится в порядке слева направо, сверху вниз
	//   У нас принято хранить слева направо снизу вверх (в порядке возрастания координат X и Y)
	//  Т е  parrZ[0] - это левый нижний элемент


	FILE *fr ;
	if (	(fr=_wfopen(wFileName,L"rb")) == NULL)
	{
	//String s_22 =  L"TYrRead::ReadFltFile\nNot possible to open file" ;
	//ShowMessage (s_22) ;

	}
	//  int n0 = nrows2 -1 - int(( yllcorner - yllcorner2)/ cellsize );
	int n0 = (yllcorner2 + nrows2 * cellsize - yllcorner - nrows * cellsize + cellsize/2)/cellsize;
	  int m0 =  int(( xllcorner - xllcorner2 + cellsize/2)/ cellsize );
	  long offset;
	  float * pf = new float [ ncols];
	 for (int i =0 ; i < nrows; i++)
	 {
	   offset = ((n0 + i) * ncols2 + m0 )* sizeof(float);
	   fseek(fr,offset,SEEK_SET);
		fread(pf,sizeof(float), ncols,fr) ;
		for (int j = 0;j < ncols; j++)
		{
		 pflt_rastr[(nrows - i-1)* ncols  + j] = (double)pf[j];
		 if (fabs( pflt_rastr[(nrows - i-1)* ncols  + j]/2 - nodata/2) < 1.) pflt_rastr[(nrows - i-1)* ncols  + j] = nodata ;
		}


	 }

	  fclose(fr);

	  delete pf;


}


/*
TYrRastr ::TYrRastr(wchar_t *wFileName,const int numBand)
{


	 nodata = NODATA ;
   //	 prastr = NULL ;
	  pflt_rastr = NULL ;
	strcpy(byteorder, "byteorder     LSBFIRST") ;

   double nodata_t;
   int   quanMass = -1 ;
    TYrRead::ReadHdrFileFromIkdFile(wFileName, &nrows,& ncols, & xllcorner , & yllcorner
							 ,&cellsize, &nodata_t,&quanMass ) ;


  if (numBand  > ( quanMass -1))
  {
	  //ShowMessage (L"TYrRastr ::TYrRastr. Error: Number of band too big" ) ;
	  //Abort() ;
  }
 // //String s_22 = L"TYrRastr ::TYrRastr(wchar_t *wFileName)\n  ncols = " ;
   //	 //ShowMessage (s_22 +  ncols + L"nrows = " + nrows + L"xllcorner = " + xllcorner + L"yllcorner  = " + yllcorner + L"cellsize = "  + cellsize) ;
	//  s_22 =  wFileName;
    //  //ShowMessage (s_22) ;
  pflt_rastr = new double [ nrows * ncols ] ;
  if ( pflt_rastr == NULL)
  {
	 //ShowMessage (L"Not memory for pflt_rastr in  TYrRastr ::TYrRastr(wchar_t *wFileName)") ;
	 //Abort() ;

  }
	 long long int llnrows =  nrows ;
	 long long int llncols = ncols ;
	 long long llnumBand =  numBand ;
	 long long llszof = sizeof(double);

	 TFileStream *fs = new TFileStream(wFileName, fmOpenRead) ;
	  fs->Seek(llnrows * llncols * llnumBand * llszof, soBeginning) ;
	// fs->Write(Buffer, 2000000000) ;
	 fs->Read(pflt_rastr, nrows * ncols *  sizeof(double)) ;
	// fs->Seek(5000000000, soBeginning) ;
	 delete fs ;


}
	*/
// усли irastr = true то память резервируется
TYrRastr ::TYrRastr(int nc,int nr,double xll,double yll,double cs,double nd,const bool irastr)
{
    nodata = NODATA ;
   //	prastr = NULL ;
	pflt_rastr = NULL ;
	strcpy(byteorder, "byteorder     LSBFIRST") ;
	ncols = nc;
	nrows = nr ;
	xllcorner = xll ;
	yllcorner = yll ;
	cellsize = cs ;
	nodata = nd ;
	if (irastr == true)
	{
        pflt_rastr = new double [ nrows * ncols ] ;
		if ( pflt_rastr == NULL)
		{
		 //ShowMessage (L"Not memory for pflt_rastr in  TYrRastr ::TYrRastr(wchar_t *wFileName)") ;
		 //Abort() ;

		}
		for (int i = 0 ; i < ncols * nrows ; i++) pflt_rastr[i] = nodata ;

	}
}

// усли irastr = true то память резервируется
TYrRastr ::TYrRastr(int nc,int nr,double xll,double yll,double cs,const bool irastr)
{
    nodata = NODATA ;
   //	prastr = NULL ;
	pflt_rastr = NULL ;
	strcpy(byteorder, "byteorder     LSBFIRST") ;
	ncols = nc;
	nrows = nr ;
	xllcorner = xll ;
	yllcorner = yll ;
	cellsize = cs ;

	if (irastr == true)
	{
			 pflt_rastr = new double [ nrows * ncols ] ;
		if ( pflt_rastr == NULL)
		{
		 //ShowMessage (L"Not memory for pflt_rastr in  TYrRastr ::TYrRastr(wchar_t *wFileName)") ;
		 //Abort() ;

		}
		for (int i = 0 ; i < ncols * nrows ; i++) pflt_rastr[i] = nodata ;

	}
}

// парам конструктор
TYrRastr ::TYrRastr(int nc,int nr,double xll,double yll,double cs,double *arrData)
{
		nodata = NODATA ;
	 //	prastr = NULL ;
	pflt_rastr = NULL ;
	strcpy(byteorder, "byteorder     LSBFIRST") ;
	ncols = nc;
	nrows = nr ;
	xllcorner = xll ;
	yllcorner = yll ;
	cellsize = cs ;

			 pflt_rastr = new double [ nrows * ncols ] ;
		if ( pflt_rastr == NULL)
		{
		 //ShowMessage (L"Not memory for pflt_rastr in  TYrRastr ::TYrRastr(wchar_t *wFileName)") ;
		 //Abort() ;

		}
		memcpy(pflt_rastr, arrData, sizeof(double) * ncols * nrows);

}
// парам конструктор
TYrRastr ::TYrRastr( TURPolygon plg, const double cs,  const double value)
{
		 plg.calcBoundBox() ;
		 nodata = NODATA ;
		 xllcorner =   plg.Box[0] ;
		 yllcorner =   plg.Box[1] ;
		 nrows = (plg.Box[3] - plg.Box[1])/ cs ;
		 ncols = (plg.Box[2] - plg.Box[0])/ cs ;
		 cellsize = cs ;

		 TYrRastr rastr(ncols, nrows, xllcorner, yllcorner , cs,nodata,true);
		 pflt_rastr = new double [ nrows * ncols ] ;
		if ( pflt_rastr == NULL)
		{
		 //ShowMessage (L"Not memory for pflt_rastr in  TYrRastr ::TYrRastr(wchar_t *wFileName)") ;
		 //Abort() ;

		}
		for (int i = 0 ; i < ncols * nrows ; i++) pflt_rastr[i] = nodata ;




		 for (int i =0; i <  ncols * nrows; i++)
		 {
				TURPointXY pnt =  rastr.getCellCentre(i) ;
				if (plg.PtInPlygon( pnt))
				{
				 pflt_rastr[i] = value;
				}
		 }

 }

 // парам конструктор
 // PNtPixel - точка середины пикселя
TYrRastr ::TYrRastr( TURPolygon plg, const double cs,  const double value, const TURPointXY PNtPixel)
{
		 plg.calcBoundBox() ;
		 nodata = NODATA ;
		 int ic = int((PNtPixel.X - plg.Box[0])/ cs) ;
		 xllcorner =   PNtPixel.X-  ((double)ic)* cs - cs/2.;
		 ic = int((PNtPixel.Y - plg.Box[1])/ cs) ;
		 yllcorner =   PNtPixel.Y-  ((double)ic)* cs - cs/2.;
		 nrows = (plg.Box[3] - yllcorner + cs / 100.)/cs ;
		 ncols = (plg.Box[2] - xllcorner  + cs / 100.)/ cs ;
		 cellsize = cs ;

		 TYrRastr rastr(ncols, nrows, xllcorner, yllcorner , cs,nodata,true);
		 pflt_rastr = new double [ nrows * ncols ] ;
		if ( pflt_rastr == NULL)
		{
		 //ShowMessage (L"Not memory for pflt_rastr in  TYrRastr ::TYrRastr(wchar_t *wFileName)") ;
		 //Abort() ;

	 	}
		for (int i = 0 ; i < ncols * nrows ; i++) pflt_rastr[i] = nodata ;




		 for (int i =0; i <  ncols * nrows; i++)
		 {
				TURPointXY pnt =  rastr.getCellCentre(i) ;
				if (plg.PtInPlygon( pnt))
				{
				 pflt_rastr[i] = value;
				}
		 }

 }

// Конструктор копирования
 TYrRastr::TYrRastr (const TYrRastr &R2)
 {

	 ncols = R2.ncols ;
	  nrows = R2.nrows;
	 xllcorner = R2.xllcorner;
	 yllcorner =R2. yllcorner;
	  cellsize =R2.cellsize;
	 nodata = R2.nodata;
	 strcpy(byteorder,R2.byteorder)  ;
	  if(pflt_rastr)
	  {
        // delete []pflt_rastr;
        // pflt_rastr = NULL;
	  }

	 if ( R2.pflt_rastr != NULL)

	 {

		 pflt_rastr = new double [ncols * nrows] ;

		 if (pflt_rastr == NULL)
		 {
			 //ShowMessage (L"Not memory for pflt_rastr in   TYrRastr::TYrRastr (const TYrRastr &R)") ;
			  //Abort() ;
		 }
		 memcpy(pflt_rastr,R2.pflt_rastr,sizeof(double) * ncols * nrows) ;

	 }

 }
 // оператор присваивания
 TYrRastr &TYrRastr::operator=(const TYrRastr  &R2)
{
	 ncols = R2.ncols ;
	 nrows = R2.nrows;
	 xllcorner = R2.xllcorner;
	 yllcorner =R2. yllcorner;
	 cellsize =R2.cellsize;
	 nodata = R2.nodata;
	 strcpy(byteorder,R2.byteorder)  ;
	  if(pflt_rastr)
	  {
          delete []pflt_rastr;
          // pflt_rastr = NULL;
	  }

	 if(R2.pflt_rastr != NULL)
	 {
	 pflt_rastr = new double [ncols * nrows] ;
	 if (pflt_rastr == NULL)
	 {
		 //ShowMessage (L"Not memory for pflt_rastr in   TYrRastr::TYrRastr (const TYrRastr &R)") ;
          //Abort() ;
	 }
	 memcpy(pflt_rastr,R2.pflt_rastr,sizeof(double) * ncols * nrows) ;
	 }
	 return *this ;
}



bool  TYrRastr:: InitRastr()
{
  if ((ncols <1)|| (nrows <1) )
  {
	  //ShowMessage (L"Not possible to initialuze Rastr") ;
	  return false ;
  }
 

	   return true;
}

 bool  TYrRastr:: CutFltRastr(TYrRastr *dstRastr, TYrRastr *srcRastr,const int nrowfirst
					  ,const int ncolfirst,const int nrowscut, const int ncolscut)
{
   if (((nrowfirst + nrowscut) > (*srcRastr).nrows ) ||
				   ((ncolfirst + ncolscut) > (*srcRastr).ncols ) ) return false ;



  int icols = (*srcRastr).ncols ;
   for (int i = 0; i < nrowscut; i++)
   for (int j = 0 ; j < ncolscut; j++)
   {

   *((*dstRastr).pflt_rastr + i* ncolscut + j)
		=*( (*srcRastr).pflt_rastr +(nrowfirst + i)*icols +ncolfirst + j) ;
		//(*srcRastr).prastr [(nrowfirst + i)*icols +ncolfirst + j] ;

   }
	return true ;
}

  bool  TYrRastr:: FindParamsForCutRastr(const TYrRastr *srcRastr, const double xmin
				 ,const double ymin,const double xmax, const double ymax
				  ,int *nrowfirst,int *ncolfirst, int *nrowscut,int *ncolscut)
// ВХОДНАЯ ИНФОРМАЦИЯ:
//  srcRastr - исходный растр, в котором надо определить какие строки и столбцы следует вырезать
// xmin, ymin - координата левого нижнего угла вырезаемой области
// xmax, ymax - координаты правого верхнего угдла вырезаемой области
// ВЫХОДНАЯ ИНФОРМАЦИЯ:
// nrowfirst, ncolfirst - номер первой  строки и столбца, которые вырезаются
// nrowscut, ncolscut - к-во вырезаемых строк и столбцов
{

   *ncolfirst =  YMAX(0,(xmin - (*srcRastr).xllcorner)  /  (*srcRastr).cellsize );
  int jmax = YMIN((*srcRastr).ncols,(xmax- (*srcRastr).xllcorner)  /  (*srcRastr).cellsize ) ;
  *nrowfirst =  YMAX(0,(ymin - (*srcRastr).yllcorner)  /  (*srcRastr).cellsize );
  int imax =   YMIN((*srcRastr).nrows,(ymax- (*srcRastr).yllcorner)  /  (*srcRastr).cellsize ) ;
  *nrowscut = imax - (*nrowfirst)  ;
  *ncolscut =  jmax - (*ncolfirst) ;
	return true ;
}

 void  TYrRastr:: ShowMe(int i)
 {
	 //String s_22 = L"i= " ;
	 //ShowMessage (s_22 + i +L"\n  ncols = " + ncols + L"nrows = " + nrows + L"xllcorner = " + xllcorner + L"yllcorner  = " + yllcorner + L"cellsize = "  + cellsize) ;

 }

 double  TYrRastr:: get_X(const int i,const int j)
 {
	 return xllcorner + cellsize /2 + j*cellsize ;
 }

 double  TYrRastr:: get_X(const int j)
 {
	 return xllcorner + cellsize /2 + j*cellsize ;
 }

 double  TYrRastr:: get_Y(const int i,const int j)
 {
	 return yllcorner + cellsize /2 + i*cellsize ;
 }

 double  TYrRastr:: get_Y(const int i)
 {
	 return yllcorner + cellsize /2 + i*cellsize ;
 }

 double  TYrRastr:: get_PiksVal(const double x, const double y)
 {
	int i = (y - yllcorner)/cellsize ;
	int j =  (x - xllcorner)/cellsize ;
  //	//String s_22 = L"Iam in  get_PiksVal\n i = ";
   //	//ShowMessage (s_22 +i + L" j = " + j) ;
	 return pflt_rastr[ i * ncols + j] ;
 }

 void  TYrRastr:: ExportRastrExtent(TYrRastr *dstRastr, TYrRastr *srcRastr)
 {
  (*dstRastr).ncols     =(*srcRastr).ncols ;
  (*dstRastr).nrows      = (*srcRastr).nrows ;
  (*dstRastr).xllcorner = (*srcRastr).xllcorner ;
  (*dstRastr).yllcorner = (*srcRastr).yllcorner ;
  (*dstRastr).cellsize  = (*srcRastr).cellsize ;
  (*dstRastr).nodata    = (*srcRastr).nodata ;

 }

// void  TYrRastr:: WriteMeAsFltFile()
 void  TYrRastr::WriteMeAsFltFile(wchar_t *wFileName)
 {
	TYrWrite::WriteMassiveInFltFile(wFileName,pflt_rastr,  nrows,
							ncols,xllcorner ,yllcorner,
							 cellsize,NODATA ) ;
 }

 bool  TYrRastr:: CustomizeToGrid( TYrRastr *srcRastr,  TYrRastr *destRastr)
 {

	   //	//ShowMessage (L"I am in  TYrRastr:: CustomizeToGrid") ;
	 //  (*srcRastr).ShowMe(4) ;
	//  (*destRastr).ShowMe(5)  ;
	 for (int i =0 ; i <  (*destRastr).nrows ; i++)
	 for (int j =0 ; j <(*destRastr).ncols; j++)
	 {
	   double x =  (*destRastr).xllcorner + (*destRastr).cellsize/2 + (*destRastr).cellsize * j ;
	   double y = (*destRastr).yllcorner + (*destRastr).cellsize/2 + (*destRastr).cellsize * i ;
	   //	//String s_22 =L"(*srcRastr).get_PiksVal(x,y) = " ;
	  //	//ShowMessage (s_22 + (*srcRastr).get_PiksVal(x,y)) ;
	   (*destRastr).pflt_rastr[i * (*destRastr).ncols + j] =  (*srcRastr).get_PiksVal(x,y) ;
	 }


	 return true;
 }

 void  TYrRastr:: WriteRastrsMassiveInIkdFile(wchar_t *FileName,TYrRastr *pRastr
				 , const int quanRastrs)
{
	// TYrRastr *pr;
   //	 pr =  pRastr[0] ;
   TYrWrite::WriteHdrForIkdFile(FileName,quanRastrs,(pRastr[0]).nrows,pRastr[0].ncols
		   ,pRastr[0].xllcorner,pRastr[0].yllcorner,pRastr[0].cellsize,NODATA) ;
	  //	TYrWrite::WriteHdrForIkdFile(FileName,quanRastrs,(*pr).nrows,(*pr).ncols
	  //	   ,(*pr).xllcorner,(*pr).yllcorner,(*pr).cellsize,NODATA) ;
	FILE *fw;
	if ((fw = _wfopen(FileName,L"wb"))== NULL)
	{
	 //String St =  FileName ;
	 //ShowMessage (L"TYrRastr:: WriteRastrsMassiveInIkdFile\n ERROR ! Not possible to open " +St) ;

	}
   for (int i =0; i < quanRastrs; i++)
   {
	 // pr = pRastr[i] ;
	 // fwrite((*pr).pflt_rastr,sizeof(double),(*pr).ncols * (*pr).nrows ,fw) ;
	 fwrite(pRastr[i].pflt_rastr,sizeof(double),pRastr[i].ncols * pRastr[i].nrows ,fw) ;
   }



  fclose(fw);
  return ;
}

double TYrRastr::InterpolateZ(/*double * parrZ, const int nrows,const int ncols,const double xllcorner
				   ,const double yllcorner, const double cellsize,const double Nodata */
				   const double x,const double y )
// Интерполяция растра заданного массивом parrZ
// Входная информация:
//  1.parrZ - массив значений(высот)
//  2.nrows, ncols  - к-во строк и столбцов
//  3. xllcorner, yllcorner - координаты левого нижнего угла левого нижнего пиксела
//  4. Nodata - значение высоты в случае отсутствия информации
//  5. x,y - координаты точки, в которой надо получить значений parrZ
// Интерполяцмия производится если точка x,y выходит за пределы первоначального экстента
// не более чем на   cellsize/2  по каждой оси
{
	 double Nodata = nodata  ;
	 double xlb = xllcorner +  cellsize/2 ; // координата x центра левого нижнего пиксела
	 double ylb = yllcorner +  cellsize/2 ; // координата y центра левого нижнего пиксела
	 double x0 = xlb - cellsize ; // Начало координат для интерполяции
	 double y0 = ylb - cellsize ; // Начало координат для интерполяции
	 // //String s_22 = L"xllcorner1 = " ;
	////ShowMessage (s_22 + xllcorner1 +L"yllcorner1 = " +yllcorner1) ;
 // Определение шаблона окружающих точек
	double arrSh[4] = { Nodata,Nodata,Nodata, Nodata} ;
	int jCell = (x- x0)/cellsize ;  //Номер столбца
	int iCell = (y- y0)/cellsize ;   // Номер строки

	 // s_22 = L"Interpolatew x =" ;
////ShowMessage (s_22 + x +L" y =  " +y) ;
	// Выявление случая когда x,y не в экстенте

	if( ((x- x0)< 0 )|| ((x- x0) > (ncols +1)*cellsize ) )
								  return  Nodata;
	if( ((y- y0)< 0 )|| ((y- y0) > (nrows +1)*cellsize ) )
								  return  Nodata;

	// выявление случав когда x,y лежит в крайних угловых ячейках
	// Возвращается значение угловой ячейки
	if ((iCell == 0) && (jCell == 0)) return pflt_rastr[0] ;
   //	if ((jCell == ncols) && (iCell == 0)) return pflt_rastr[ncols-1] ;  //изм 04.06.2011
	if ((jCell == (ncols + 1)) && (iCell == 0)) return pflt_rastr[ncols-1] ; //изм 04.06.2011
  //	if ((jCell == ncols) && (iCell == nrows)) return pflt_rastr[ncols* nrows-1] ;   //изм 04.06.2011
	if ((jCell == (ncols + 1)) && (iCell == (nrows + 1) )) return pflt_rastr[ncols* nrows-1] ; //изм 04.06.2011
  //	if ((jCell == 0) && (iCell == nrows )) return pflt_rastr[ncols* (nrows-1)] ;   //изм 04.06.2011
	if ((jCell == 0) && (iCell == (nrows + 1) )) return pflt_rastr[ncols* (nrows-1)] ;  //изм 04.06.2011
	// формирование шаблона

	// точка слева от растра
	if (jCell == 0)
	{
	  arrSh[0]= arrSh[2]=  Nodata;
	  arrSh[1] = pflt_rastr[ncols * (iCell-1)] ;
	  arrSh[3] =  pflt_rastr[ncols *  iCell ]  ;

	}
	// точка справа  от растра
   //	if (jCell == ncols)
	if (jCell == (ncols + 1))   //изм 04.06.2011
	{
	  arrSh[3]= arrSh[1]=  Nodata;
	  arrSh[0] =  pflt_rastr[ncols * iCell - 1] ;
	  arrSh[3] =  pflt_rastr[ncols * (iCell + 1) - 1] ;

	}
	// точка внизу от растра
	if (iCell == 0)
	{
	  arrSh[0]= arrSh[1]=  Nodata;
	  arrSh[2] = pflt_rastr[jCell - 1] ;
	  arrSh[3] = pflt_rastr[jCell    ] ;

	}
	// точка вверху от растра
 // (iCell == nrows)
	if (iCell == (nrows + 1 ))  //изм 04.06.2011
	{
	  arrSh[2]=  arrSh[3]=  Nodata;
	  arrSh[0] = pflt_rastr[ncols * ( nrows - 1) + jCell - 1] ;
	  arrSh[1] = pflt_rastr[ncols * ( nrows - 1) + jCell   ] ;

	}
	// точка внутри растра
	if( (jCell > 0) && (jCell < (ncols +1) )  && (iCell > 0) && (iCell < (nrows + 1) ) )
	{
	   arrSh[0] = pflt_rastr[(iCell-1) * ncols +jCell -1]  ;
	   arrSh[1] = pflt_rastr[(iCell-1) * ncols +jCell   ]  ;
	   arrSh[2] = pflt_rastr[ iCell * ncols +jCell -1]  ;
	   arrSh[3] = pflt_rastr[ iCell * ncols +jCell   ]  ;
	}


	 int ix = (x-x0)/ cellsize   ;
	 int iy = (y-y0) / cellsize ;
	  double xt = x -x0- ix* cellsize; // координата x в шаблоне
	 double yt = y -y0- iy*cellsize ;   // координата y в шаблоне
         if ((xt < 0)|| (xt >  cellsize) )
	 {
		  //ShowMessage (L"Error_InterpolateZ");

		  //Abort();
	 }
	if ((yt < 0)|| (yt >  cellsize) )
	 {
		  //ShowMessage (L"Error_InterpolateZ ");

		  //Abort();
	 }


	 return LinApprox(arrSh,cellsize, Nodata,xt,yt) ; //Линейная аппроксимация в шаблоне

}

  double TYrRastr::LinApprox(double* arrSh,const double cellsize
			,const double Nodata,const double xt,const double yt)
{
	 if ((xt < 0)|| (xt >  cellsize) )
	 {
		  //ShowMessage (L"Error_LinApprox ");

		  //Abort();
	 }
	if ((yt < 0)|| (yt >  cellsize) )
	 {
		  //ShowMessage (L"Error_LinApprox ");

		  //Abort();
	 }
   // Если ни в одной точке шаблона значение не определено, то возвращается Nodata
	if ((arrSh[0] <  (Nodata + 1)) && (arrSh[1] <  (Nodata + 1))
		&&(arrSh[2] <  (Nodata + 1))&&(arrSh[3] <  (Nodata + 1))) return Nodata;
	// Если хотя бы в одной точке шаблона значение не определено(но по крайней мере
	// в одной определено) то возвращается значение в ближайшей точке

	if ((arrSh[0] <  (Nodata + 1)) || (arrSh[1] <  (Nodata + 1))
		||(arrSh[2] <  (Nodata + 1))||(arrSh[3] <  (Nodata + 1)))
						 return NearestPointValue ( arrSh,cellsize,  Nodata,xt, yt) ;
	else
	// Если во всех точках шаблона значения определены, то линейная интерполяция
	return BilinearValue ( arrSh,cellsize, xt, yt) ;


}

double TYrRastr::NearestPointValue (double* arrSh,const double cellsize
			,const double  Nodata,const double xt,const double yt)
{
  double min = 10 * cellsize * cellsize  ;
	int jmin = -1 ;
	if ((arrSh[0] <  (Nodata + 1)) && (arrSh[1] <  (Nodata + 1))
		&&(arrSh[2] <  (Nodata + 1))&&(arrSh[3] <  (Nodata + 1))) return Nodata;
	 if ((xt * (xt - cellsize)) > EPSSING)
	 {
		  //ShowMessage (L"Error_NearestPointValue ");
		  //Abort();
	 }
	 if ((yt * (yt - cellsize)) > EPSSING)
	 {
		  //ShowMessage (L"Error_NearestPointValue ");
		  //Abort();
	 }


	for (int i = 0; i < 2; i++)
	for (int j =0; j < 2 ; j++)
	 {
	  double x0 = j* cellsize;
	  double y0 = i * cellsize ;
	  double d = (xt -x0)*(xt -x0) + (yt - y0) * (yt - y0);
	  int num = i*2 +j ;
		  if ((d < min)  && (arrSh[num] > (NODATA +1)) )
		  {
		   min = d;
		   jmin = num ;

		  }
	  }
	  if (jmin == -1) return  Nodata;
	  else return  arrSh[jmin] ;



}

double TYrRastr::BilinearValue (double* arrSh,const double cellsize
			,const double xt,const double yt)
{
  double ax = xt/ cellsize ;
  double ay = yt/ cellsize ;
  double z4 = (1 - ay) *  arrSh[0] +  ay * arrSh[2] ;
  double z5 = (1 - ay) *  arrSh[1] +  ay * arrSh[3] ;

  return ( (1- ax) * z4 + ax * z5);

}
   //	int ncols;
   //	int nrows ;
  //	 double xllcorner ;
	// double yllcorner ;
   //	 double cellsize ;
   //	 double nodata ;
   //	 char byteorder[30]  ;
TYrRastr  TYrRastr:: SumOfRastrs(TYrRastr *pRastr1, TYrRastr *pRastr2)
{
   if (
		 ((*pRastr1).ncols != (*pRastr2).ncols )
	  || ((*pRastr1).nrows != (*pRastr2).nrows )
	  || ( fabs((*pRastr1).xllcorner  != (*pRastr2).xllcorner ) > EPS)
	  || (fabs((*pRastr1).yllcorner != (*pRastr2).yllcorner) > EPS)
	  || (fabs((*pRastr1).cellsize != (*pRastr2).cellsize ) > EPS)

	  )
	  {
		  //ShowMessage (L" Not posiible to sum Rastrs") ;
		  //Abort();
	  }
   TYrRastr *DeltaSumstr =  pRastr1;
	for (int i = 0; i < (*DeltaSumstr).nrows * (*DeltaSumstr).ncols; i++)

   {
	   (*DeltaSumstr).pflt_rastr[ i] = NODATA ;
	   if(((*pRastr1).pflt_rastr[ i] != NODATA) && ((*pRastr2).pflt_rastr[ i] != NODATA))
	  (*DeltaSumstr).pflt_rastr[ i] = (*pRastr1).pflt_rastr[ i] + (*pRastr2).pflt_rastr[ i];
   }
   return *DeltaSumstr;
}
TYrRastr  TYrRastr:: MinusOfRastrs(TYrRastr *pRastr1, TYrRastr *pRastr2)
{
   if (
		 ((*pRastr1).ncols != (*pRastr2).ncols )
	  || ((*pRastr1).nrows != (*pRastr2).nrows )
	  || ( fabs((*pRastr1).xllcorner  != (*pRastr2).xllcorner ) > EPS)
	  || (fabs((*pRastr1).yllcorner != (*pRastr2).yllcorner) > EPS)
	  || (fabs((*pRastr1).cellsize != (*pRastr2).cellsize ) > EPS)

	  )
	  {
		  //ShowMessage (L" Not posiible to sum Rastrs") ;
		  //Abort();
	  }
   TYrRastr *MinusRastr =   pRastr1;
		for (int i = 0; i < (*MinusRastr).nrows * (*MinusRastr).ncols; i++)


   {

	 (*MinusRastr).pflt_rastr[ i] = NODATA ;
	   if(((*pRastr1).pflt_rastr[ i] != NODATA) && ((*pRastr2).pflt_rastr[ i] != NODATA) )
	  (*MinusRastr).pflt_rastr[ i] = (*pRastr1).pflt_rastr[ i] + (*pRastr2).pflt_rastr[ i];
	  (*MinusRastr).pflt_rastr[ i] = (*pRastr1).pflt_rastr[ i] - (*pRastr2).pflt_rastr[ i];
   }
   return *MinusRastr;
}
 int TYrRastr::YMIN(const int n, const int m)
	 {
		 return (n < m)?n:m ;
	 }
  int TYrRastr::YMAX (const int n, const int m)
	 {
		 return (n > m)?n:m ;
	 }
bool TYrRastr::IsPointInsideExtent(const double x,const double y )
{
  double xmin,ymin,xmax,ymax ;
  GetExtent(xmin,ymin,xmax,ymax) ;
  return (x >= xmin) && (x <=  xmax) && (y >= ymin) && (y <= ymax );
}

void TYrRastr::GetExtent(double &xmin,double &ymin,double &xmax,double &ymax)
{
  xmin =  xllcorner - cellsize/2;
  ymin =  yllcorner - cellsize/2;
  xmax =  xmin + cellsize * ncols;
  ymax =  ymin + cellsize * nrows;
}
void  TYrRastr:: ModifyOrderOfDataArray()
{
	if (pflt_rastr == NULL) return ;
	double *Ztemp = new double [ncols* nrows ];
	if (Ztemp == NULL)
	{
	//ShowMessage (L"Not memory in TYrRastr:: ModifyOrderOfDataArray") ;
	return ;
	}
	memcpy(Ztemp, pflt_rastr, sizeof(double)*ncols* nrows);
	for ( int i1 = 0; i1 < nrows; i1++)
	for ( int j1 = 0; j1 < ncols; j1++)
	{
		pflt_rastr[i1*ncols + j1]=   Ztemp[(nrows-1-i1)*ncols +j1] ;
	}
	delete []Ztemp ;
}

 bool TYrRastr:: replace(char*str)
  {	 int n = strlen(str);
	 for (int i=0; i < n; i++)
	 {
		 if (str[i] == ',')
		 {
			str[i] = '.';
			return true;
		 }
	 }
	 return false ;
  }

 bool TYrRastr::DigCanyon(const TURPointXY P0,const TURPointXY P1 )

 {
  int i0 = (P0.Y - yllcorner)/cellsize;
  int j0 = (P0.X - xllcorner)/cellsize;
  int i1 = (P1.Y - yllcorner)/cellsize;
  int j1 = (P1.X - xllcorner)/cellsize;
  const double z0 = pflt_rastr[ i0 * ncols + j0 ];
  const double z1 = pflt_rastr[ i1 * ncols + j1 ];

 // int iNNx = fabs(P1.X - P0.X)/ cellsize;
 // int iNNy = fabs(P1.Y - P0.Y)/ cellsize;
  const int NN = 100000;
  int  icur  = i0;
  int  jcur  = j0;
   TURPointXY P00,P01;

   P00= P0;

   double kx = (P1.X - P0.X)/TURPointXY::dist( P0,P1) ;
	double ky = (P1.Y - P0.Y)/TURPointXY::dist( P0,P1) ;
	// подсчет к-ва изменяемых точек   quantN
	int quantN = 0;
	for (int i = 0 ; i < NN; i++)
	{
	 P01  = OutPnt(P00,kx,ky);
	 TURPointXY Pcur(0,0);
	 Pcur.X = (P00.X +P01.X)/2;
	 Pcur.Y = (P00.Y +P01.Y)/2;
	 icur = (Pcur.Y - yllcorner + ky * 0.001)/ cellsize;
	 jcur = (Pcur.X - xllcorner + kx * 0.001)/ cellsize;

	 P00.X  = P01.X + kx * 0.001;
	 P00.Y  = P01.Y + ky * 0.001;
	 icur = (P00.Y - yllcorner + ky * 0.1)/ cellsize;
	 jcur = (P00.X - xllcorner + kx * 0.1)/ cellsize;
	  quantN++;
	 if( (icur == i1)&&(jcur == j1) ) break;


	}

		// внесение изменений в растр
	double delt = YMINd((z0- z1) / quantN,0.01);
	P00= P0;
	for (int i = 0 ; i < quantN; i++)
	{
	 P01  = OutPnt(P00,kx,ky);
	 TURPointXY Pcur(0,0);
	 Pcur.X = (P00.X +P01.X)/2;
	 Pcur.Y = (P00.Y +P01.Y)/2;
	 icur = (Pcur.Y - yllcorner + ky * 0.001)/ cellsize;
	 jcur = (Pcur.X - xllcorner + kx * 0.001)/ cellsize;
   //	 double a = delt *(quantN -1 - i) ;

	 double aMod =  z1 + delt *(quantN  - i);
	 if(aMod > pflt_rastr[icur*ncols + jcur])
	 {
		 //ShowMessage (L"Error in data points");
		 return false;
	 }
	 pflt_rastr[icur*ncols + jcur] =  aMod;
	 P00.X  = P01.X + kx * 0.001;
	 P00.Y  = P01.Y + ky * 0.001;
	 icur = (P00.Y - yllcorner + ky * 0.1)/ cellsize;
	 jcur = (P00.X - xllcorner + kx * 0.1)/ cellsize;

	 if( (icur == i1)&&(jcur == j1) ) break;


	}


	 return true ;
 }
TURPointXY TYrRastr::OutPnt(const TURPointXY P0,const double kx,const double ky)
{
 //int icur,const int jcur
 int i0 = (P0.Y - yllcorner )/ cellsize;
 int j0 = (P0.X - xllcorner )/ cellsize;
 //int ia = ISign(YMAXd(0,kx));
  double tx = (fabs(kx) <= 0.0000001)?10*cellsize:((j0 + ISign(YMAXd(0,kx)))* cellsize + xllcorner - P0.X )/ kx;
  double ty = (fabs(ky) <= 0.0000001)?10*cellsize:((i0 + ISign(YMAXd(0,ky)))* cellsize + yllcorner - P0.Y ) / ky;
  double t =  YMINd(tx,ty);

	return TURPointXY(P0.X + kx *t,P0.Y + ky*t);
}

int  TYrRastr::ISign(const double a)
{
 int ir =0;
	if (a >0 ) ir =1;
		else
		if (a <0) ir =0;


 return ir;
}
double TYrRastr::YMINd(const double n, const double m)
	 {
		 return (n < m)?n:m ;
	 }
  double TYrRastr::YMAXd (const double n, const double m)
	 {
		 return (n > m)?n:m ;
	 }
/*
void TYrRastr::ModifyDEM(TURPointXY *arrP0,TURPointXY *arrP1, const int quantPoints)
{

	double z0,z1;
	for (int i = 0; i < quantPoints; i++)
	{
	   z0 = get_PiksVal(arrP0[i].X, arrP0[i].Y) ;
	   z1 = get_PiksVal(arrP1[i].X, arrP1[i].Y) ;
	   if (!DigCanyon(arrP0[i],arrP1[i],z0,z1))
	   {
		 //String sOut = L"ERROR Point No ";
		 //ShowMessage (sOut + (i+1));
	   }

	}

   return ;
}
  */
void TYrRastr::AdjustDEM( wchar_t *wFileDEM  //исходный  FLT файлом DEM
						 ,wchar_t *wFileSetNull   // исходный  FLT файл с растром потоков типа setnull
						 ,TURPointXY *arrP0,TURPointXY *arrP1, const int quantPoints,TURPointXY *purpntOut)
{

	for (int i = 0; i < quantPoints; i++)
	{
	  // //ShowMessage (i);
	   if (!Link2Streams(arrP0[i],arrP1[i],wFileDEM ,wFileSetNull,&purpntOut[i*2], &purpntOut[i*2 + 1]))
	   {
		 //String sOut = L"ERROR Point No ";
		 //ShowMessage (sOut + (i+1));
	   }

	}

}
bool TYrRastr::Link2Streams(const TURPointXY urpntUpper,const TURPointXY urpntLower
					,wchar_t *wFileDEM ,wchar_t *wFileSetNull
					,TURPointXY *urpntStart,TURPointXY *urpntEnd)
{
	const double   MAX_DIST = 4000;

	TYrRastr rstrDEM(wFileDEM ,urpntUpper,MAX_DIST );
   //	rstrDEM.WriteMeAsFltFile(L"D:\\GIDROPROJECT\\NEW_PROJECT\\Mosaik_1_2_3\\TXT_Files\\rstrDEM.flt") ;
	int quantUp = 100;
	int quantLow = 100;
	int * piarrUpNums = (int*)malloc(quantUp * sizeof(int));
	int * piarrLowNums = (int*)malloc(quantLow * sizeof(int));
	int **ppiarrUpNums =  &piarrUpNums;
	int **ppiarrLowNums =  &piarrLowNums;
	 TYrRastr rstrSetNull =  rstrDEM;
	 if (wFileSetNull) rstrSetNull =  TYrRastr (wFileSetNull,urpntUpper,MAX_DIST );


	// TYrRastr rstrSetNull(wFileSetNull,urpntUpper,MAX_DIST );
	if (wFileSetNull) {


	//создание вырхнего и нижнего кластеоров в нумерации растра setnull
	rstrSetNull.CreateCluster(urpntUpper, ppiarrUpNums,& quantUp);
	rstrSetNull.CreateCluster(urpntLower, ppiarrLowNums ,& quantLow);

	// дл яотладки
  /*	rstrSetNull.WriteMeAsFltFile(L"D:\\GIDROPROJECT\\NEW_PROJECT\\Mosaik_1_2_3\\TXT_Files\\rstrSetNull.flt") ;
	 // дл отл
	 TYrRastr rstrClUp( rstrSetNull.ncols, rstrSetNull.nrows, rstrSetNull.xllcorner, rstrSetNull.yllcorner, rstrSetNull.cellsize, rstrSetNull.nodata,true);
	 rstrSetNull.CreateRasterFromCluster(*ppiarrUpNums , quantUp,rstrClUp)   ;
	 rstrClUp.WriteMeAsFltFile(L"D:\\GIDROPROJECT\\Gidro_C++\\OutputData\\rstrClUp.flt" ) ;  */
	 // перевод кластеров в нумерацию растра DEM



	}
	else
	{
		quantUp = 1;
		quantLow = 1;

		//
		int nr_Up =  (urpntUpper.Y -rstrSetNull.yllcorner)/rstrSetNull.cellsize ;
		int nc_Up =  (urpntUpper.X -rstrSetNull.xllcorner)/rstrSetNull.cellsize ;
		(*ppiarrUpNums)[0] =  nr_Up * rstrSetNull.ncols + nc_Up;
		//
		int nr_Low =  (urpntLower.Y -rstrSetNull.yllcorner)/rstrSetNull.cellsize ;
		int nc_Low =  (urpntLower.X -rstrSetNull.xllcorner)/rstrSetNull.cellsize ;
		(*ppiarrLowNums)[0] =  nr_Low * rstrSetNull.ncols + nc_Low;

    }
	  // перевод кластеров в нумерацию растра DEM
	int * piarrCusterUp = new int [quantUp] ;
	int * piarrCusterLow = new int [quantLow ] ;
	int **ppiarrCusterUp =  &piarrCusterUp;
	int **ppiarrCusterLow=  &piarrCusterLow;
	 for (int i = 0; i < quantUp; i++)
	 {
	   TURPointXY tP =  rstrSetNull.getCellCentre((*ppiarrUpNums)[i]) ;
	   int i0 = (tP.Y - rstrDEM.yllcorner)/ rstrDEM.cellsize;
	   int j0 =  (tP.X - rstrDEM.xllcorner)/ rstrDEM.cellsize;
	   (*ppiarrCusterUp)[i] = i0 * rstrDEM.ncols + j0 ;
	 }
	   for (int i = 0; i < quantLow; i++)
	 {
	   TURPointXY tP =  rstrSetNull.getCellCentre((*ppiarrLowNums)[i]) ;
	   int i0 = (tP.Y - rstrDEM.yllcorner)/ rstrDEM.cellsize;
	   int j0 =  (tP.X - rstrDEM.xllcorner)/ rstrDEM.cellsize;
	   (*ppiarrCusterLow)[i] = i0 * rstrDEM.ncols + j0 ;
	 }
	  free ( piarrUpNums);
	  free ( piarrLowNums);
	  //
	 int indexSink = rstrDEM.FindSinkIndex (ppiarrCusterUp, quantUp); //номер ячейки с синком
		delete [] piarrCusterUp ;
	 double z0 =   rstrDEM.getValue(indexSink)  ;
	 TURPointXY  urpntP0 = rstrDEM.getCellCentre(indexSink) ;

	 int numLowPoint = -1;
	 double dist = MAX_DIST * MAX_DIST;
	 TURPointXY  urpntP1(0,0) ;
	 for (int i = 0; i < quantLow; i++)
	 {
	   int icur = (*ppiarrCusterLow)[i];
	   double z1 =   rstrDEM.getValue(icur)  ;
	   if (z1 >= z0) continue;

		urpntP1 = rstrDEM.getCellCentre(icur) ;
		if (((double)fabs(urpntP1.X - urpntP0.X) > MAX_DIST )|| ((double)fabs(urpntP1.Y - urpntP0.Y) > MAX_DIST ) )continue;
		 if ( !rstrDEM.IsLowerPointSuit(urpntP0,urpntP1 )) continue ;
		 else
		 {
		   double dist1 = TURPointXY::dist(urpntP0,urpntP1) ;
		   if (dist1 < dist)
		   {
			 numLowPoint =  icur;
			 dist = dist1;
		   }
		 }
	 }
	  if (numLowPoint == -1)
	  {
		//ShowMessage (L"Верхний_поток_ниже_нижнего") ;


		 delete [] piarrCusterLow  ;

	   return false;
	  }
	   urpntP1 =  rstrDEM.getCellCentre(numLowPoint) ;
	  rstrDEM.DigCanyon(urpntP0,urpntP1);

	  rstrDEM.InsertRastrInFltFile(wFileDEM)  ;

	 *urpntStart =  urpntP0 ;
	 *urpntEnd = urpntP1;

	 delete [] piarrCusterLow  ;
	return true ;
}

void TYrRastr::CreateRasterFromCluster(int *piarrNums , const int quantNums,TYrRastr &rstrRez)
{
   for (int i = 0; i < rstrRez.nrows; i++)
   for (int j = 0; j < rstrRez.ncols; j++)
   {
	  rstrRez.pflt_rastr[i * rstrRez.ncols + j] = rstrRez.nodata;
   }
   for (int i =0; i < quantNums; i++)
	{
	   rstrRez.pflt_rastr[piarrNums[i] ] = 1;
   }
   return ;
}
void TYrRastr::CreateCluster(const TURPointXY urpntP0, int **ppiarrNums , int *quantNums)
{
   const double CLASTER_DIMENSION = 1500;
   const int iCLAST_DIM =  CLASTER_DIMENSION/ cellsize;
   int lenMemory =  *quantNums;
   int quantCur = 1;
   int nr =  (urpntP0.Y -yllcorner)/cellsize ;
   int nc =  (urpntP0.X -xllcorner)/cellsize ;
   (*ppiarrNums)[0] =  nr * ncols + nc;
	int imin = YMAX(0,nr-iCLAST_DIM);
	int imax = YMIN(nrows,nr + iCLAST_DIM);
	int jmin = YMAX(0,nc-iCLAST_DIM);
	int jmax = YMIN(ncols,nc + iCLAST_DIM);
  bool bProceed   = false;
   while(1)
   {
	   bProceed   = false;
	   for (int i  = imin; i <  imax; i++)
	   {
	   for (int j  = jmin; j < jmax  ; j++)
	   {
		   int numCur = i * ncols + j;
		   if(pflt_rastr[i * ncols + j] == nodata) continue;
			bool bEqual = false;
		   for (int n = 0 ; n < quantCur; n++)
		   {
			   if ((*ppiarrNums)[n] == numCur)
			   {
				bEqual = true;
			   break;
			   }
			}
			 if(bEqual) continue;// ячейка уже входит в кластер
			for (int n = 0 ; n < quantCur; n++)
			{
			  int numRow =  (*ppiarrNums)[n] / ncols;
			  int numCol =  (*ppiarrNums)[n] % ncols;
			  if( (fabs(numRow - i) <= 1 ) && (fabs(numCol - j) <= 1 ) )
			  {
				//добавление ячейки растра в кластер
				if ((quantCur + 1) > lenMemory)
				{
				  (*ppiarrNums) = (int*)realloc( *ppiarrNums,  (lenMemory + 100) * sizeof(int));
				   lenMemory = lenMemory + 100;
				}
				 (*ppiarrNums)[quantCur ] = numCur;
				 quantCur++;
				 bProceed = true;//  надо начинмать цикл по всем точкам растра сначала, т к произошдло добавление в кластер
				 break;
			  }
			  else continue ;


			  }
			if (bProceed ) break;
		   }
		 if (bProceed ) break;

	   }
	   if (!bProceed ) break;
   }
   (*ppiarrNums) = (int*)realloc( *ppiarrNums, quantCur * sizeof(int));
   *quantNums =  quantCur ;
}

int TYrRastr::FindSinkIndex (int **ppiarrNums, const int quantNums)
{
	int iReturn = (*ppiarrNums) [0];
   //	double min = pflt_rastr[ iReturn ] ;
	for (int i = 0; i < quantNums ; i++)
	{
		int j =  (*ppiarrNums) [i];
		if (pflt_rastr[ j] < pflt_rastr[ iReturn ] ) iReturn = j;


	}
	return iReturn  ;
}

double  TYrRastr::getValue(const int iNum)
{
	int iRow= iNum /ncols;
	int iCol =  iNum % ncols;
	return pflt_rastr[ iRow * ncols + iCol];
}

TURPointXY  TYrRastr::getCellCentre(const int iNum)
{
	int iRow = iNum /ncols;
	int iCol =  iNum % ncols;
	return TURPointXY (xllcorner + iCol * cellsize + cellsize/2, yllcorner + iRow * cellsize + cellsize/2 ) ;
}

bool TYrRastr::IsLowerPointSuit(const TURPointXY P0,const TURPointXY P1 )

 {
  int i0 = (P0.Y - yllcorner)/cellsize;
  int j0 = (P0.X - xllcorner)/cellsize;
  int i1 = (P1.Y - yllcorner)/cellsize;
  int j1 = (P1.X - xllcorner)/cellsize;
 // int iNNx = fabs(P1.X - P0.X)/ cellsize;
 // int iNNy = fabs(P1.Y - P0.Y)/ cellsize;
  const double z0 = pflt_rastr[ i0 * ncols + j0 ];
  const double z1 = pflt_rastr[ i1 * ncols + j1 ];
  const int NN = 100000;
  int  icur  = i0;
  int  jcur  = j0;
   TURPointXY P00,P01;

   P00= P0;

   double kx = (P1.X - P0.X)/TURPointXY::dist( P0,P1) ;
	double ky = (P1.Y - P0.Y)/TURPointXY::dist( P0,P1) ;
	// подсчет к-ва изменяемых точек   quantN
	int quantN = 0;
	for (int i = 0 ; i < NN; i++)
	{
	 P01  = OutPnt(P00,kx,ky);
	 TURPointXY Pcur(0,0);
	 Pcur.X = (P00.X +P01.X)/2;
	 Pcur.Y = (P00.Y +P01.Y)/2;
	 icur = (Pcur.Y - yllcorner + ky * 0.001)/ cellsize;
	 jcur = (Pcur.X - xllcorner + kx * 0.001)/ cellsize;

	 P00.X  = P01.X + kx * 0.001;
	 P00.Y  = P01.Y + ky * 0.001;
	 icur = (P00.Y - yllcorner + ky * 0.1)/ cellsize;
	 jcur = (P00.X - xllcorner + kx * 0.1)/ cellsize;
	  quantN++;
	 if( (icur == i1)&&(jcur == j1) ) break;


	}


	double delt = YMINd((z0- z1) / quantN,0.01);
	P00= P0;
	for (int i = 0 ; i < quantN; i++)
	{
	 P01  = OutPnt(P00,kx,ky);
	 TURPointXY Pcur(0,0);
	 Pcur.X = (P00.X +P01.X)/2;
	 Pcur.Y = (P00.Y +P01.Y)/2;
	 icur = (Pcur.Y - yllcorner + ky * 0.001)/ cellsize;
	 jcur = (Pcur.X - xllcorner + kx * 0.001)/ cellsize;
  //	 double a = delt *(quantN -1 - i) ;

	 double aMod =  z1 + delt *(quantN  - i);
	 if(aMod > pflt_rastr[icur*ncols + jcur]) return false;

	 P00.X  = P01.X + kx * 0.001;
	 P00.Y  = P01.Y + ky * 0.001;
	 icur = (P00.Y - yllcorner + ky * 0.1)/ cellsize;
	 jcur = (P00.X - xllcorner + kx * 0.1)/ cellsize;

	 if( (icur == i1)&&(jcur == j1) ) break;
	}
	 return true ;
 }


int TYrRastr::InsertRastrInFltFile(wchar_t*wFileName)
/*float * parrZ, const int nrows,
							 const int ncols,const float xllcorner ,const float yllcorner,
							 const float cellsize,const float NODATA_value ) */
// Для FLOAT массивов
// Функция записывает массив высот parrZ  в файл .flt и формирует файл .hdr
// в формате FLT ESRI. FileName - имя файла с расширением .flt. nrows и  ncols - к-во строк и столбцов
// соответвенно.  xllcorner и yllcorner   - координата x и y левого нижнего угла,
// cellsize- шаг сетки,  NODATA_value - значение, которым заполняется parrZ,
//  если величина Z  не определена
// Массив  parrZ хранится в порядке слева направо и снизу вверх. То есть parrZ[0]
// это нижняя левая точка, а     parrZ[nrows * ncols ] это правая верхняя точка
// В ArcMap считается, что каждая вершина (точка) лежит в центре квадрата со стороной cellsize
// Таким обраэзом, в начале координат находится какбы не сама точка а нижний левый угол
// ее квадрата. Т е начало системы координат оказывается сдвинутым относительно левой нижней
// точки. Координаты левой нижней точки равны (cellsize/2,cellsize/2)
{



	// Чтение .HDR файла
	int len = wcslen(wFileName) ;
	if ( !(( wFileName[len - 1] == 't') && (wFileName[len - 2] == 'l') // проверка, что
	&& (wFileName[len - 3] == 'f') ) )  // указанный файл имеет расширение .flt
	{
	//String St = wFileName ;
	//ShowMessage (L"TYrRastr::InsertRastrInFltFile\nExtention of " + St + L"is wrong") ;

	}
	wchar_t* HdrFileName = new wchar_t[len] ;
	wcscpy( HdrFileName, wFileName) ;
	HdrFileName[len - 1] = 'r';
	HdrFileName[len - 2] = 'd';
	HdrFileName[len - 3] = 'h';

	FILE *fr0 ;	if ((fr0 = _wfopen(HdrFileName,L"r"))== NULL)	{
	//String St =  HdrFileName ;
	//ShowMessage (L" ERROR ! Not possible to open " +St) ;

	}	int ncols1,nrows1;	double xllcorner1,yllcorner1,cellsize1,nodata1 ;	char  str_xll[50],str_yll[50],str_sell[50],str_nodat[50];	if	(	( fscanf(fr0,"ncols         %d\n",&ncols1)== 0)	||(  fscanf(fr0,"nrows         %d\n",&nrows1 ) == 0)	|| ( fscanf(fr0,"xllcorner     %s\n",str_xll) == 0)	|| ( fscanf(fr0,"yllcorner     %s\n",str_yll)== 0 )	|| ( fscanf(fr0,"cellsize      %s\n",str_sell )== 0)	|| ( fscanf(fr0,"NODATA_value  %s\n",str_nodat  ) == 0 )	)	{	//ShowMessage (L"Error in format of HDR File");

	}	replace(str_xll);	replace(str_yll);	replace(str_sell);	replace(str_nodat);	fclose(fr0) ;	delete  [] HdrFileName ;	xllcorner1 =atof(str_xll);	yllcorner1 = atof(str_yll);	cellsize1 = atof(str_sell);	nodata1= atof(str_nodat);

	 // проверка соответствия экстентов
	 double xmin,ymin,xmax,ymax ,xmin1,ymin1,xmax1,ymax1;

	 xmin = xllcorner ;
	 ymin  =yllcorner;
	 xmax  = xllcorner  + cellsize* ncols;
	 ymax  = yllcorner  + cellsize * nrows;

	 xmin1 = xllcorner1 ;
	 ymin1  =yllcorner1;
	 xmax1  = xllcorner1  + cellsize1 * ncols1;
	 ymax1  = yllcorner1  + cellsize1 * nrows1;
	 if ( (xmin < xmin1)
	 || (xmax > xmax1)
	 || ( ymin < ymin1)
	 || (ymax > ymax1) )
	 {
		//ShowMessage (L"TYrRastr::InsertRastrInFltFile\n ERROR ! Extents do not comply each other ") ;
		return 1 ;
	 }
 // 2. Запись .flt
	FILE *fw1 ;
	if ((fw1 = _wfopen(wFileName,L"rb+"))== NULL)
	{
	//String St =  wFileName ;
	//ShowMessage (L"TYrRastr::InsertRastrInFltFile\n ERROR ! Not possible to open " +St) ;
	return 1 ;
	}

	//  int n0 = nrows2 -1 - int(( yllcorner - yllcorner2)/ cellsize );
	int n0 = (yllcorner1 + nrows1 * cellsize1 - yllcorner - nrows * cellsize + cellsize/2)/cellsize;
	int m0 =  int(( xllcorner - xllcorner1 + cellsize/2)/ cellsize );
	long offset0 = (n0  * ncols1 + m0 )* sizeof(float);;
	float * pf = new float [ ncols];
	fseek(fw1,offset0,SEEK_SET);
	for (int i =0 ; i < nrows; i++)
	{
	//offset = ((n0 + i) * ncols1 + m0 )* sizeof(float);

	// fseek(fw1,offset,SEEK_CUR);
	for (int j = 0;j < ncols; j++)
	{
	float val = pflt_rastr[(nrows - i-1)* ncols  + j]  ;
	pf[j] = val;
	if (fabs( val/2 - nodata/2) < 1.) pf[j] = nodata1 ;

	}

	  fwrite(pf,sizeof(float),ncols ,fw1) ;
  //	TYrRastr tRaster( wFileName);
   //	 tRaster.WriteMeAsFltFile(L"D:\\GIDROPROJECT\\Gidro_C++\\InputData\\tRaster.flt") ;
	//offset +=  ncols1;
	offset0 = ((n0 + i+1) * ncols1 + m0 )* sizeof(float);


	if (i < ( nrows -1))  fseek(fw1,offset0,SEEK_SET);
	}

	fclose(fw1);
	delete pf;
	return 0 ;
	}

int TYrRastr::ChangeCellValue(wchar_t*wFileName,const TURPointXY urpntP,const double valZ)
/*float * parrZ, const int nrows,
							 const int ncols,const float xllcorner ,const float yllcorner,
							 const float cellsize,const float NODATA_value ) */
// Для FLOAT массивов
// Функция записывает массив высот parrZ  в файл .flt и формирует файл .hdr
// в формате FLT ESRI. FileName - имя файла с расширением .flt. nrows и  ncols - к-во строк и столбцов
// соответвенно.  xllcorner и yllcorner   - координата x и y левого нижнего угла,
// cellsize- шаг сетки,  NODATA_value - значение, которым заполняется parrZ,
//  если величина Z  не определена
// Массив  parrZ хранится в порядке слева направо и снизу вверх. То есть parrZ[0]
// это нижняя левая точка, а     parrZ[nrows * ncols ] это правая верхняя точка
// В ArcMap считается, что каждая вершина (точка) лежит в центре квадрата со стороной cellsize
// Таким обраэзом, в начале координат находится какбы не сама точка а нижний левый угол
// ее квадрата. Т е начало системы координат оказывается сдвинутым относительно левой нижней
// точки. Координаты левой нижней точки равны (cellsize/2,cellsize/2)
{



	// Чтение .HDR файла
	int len = wcslen(wFileName) ;
	if ( !(( wFileName[len - 1] == 't') && (wFileName[len - 2] == 'l') // проверка, что
	&& (wFileName[len - 3] == 'f') ) )  // указанный файл имеет расширение .flt
	{
	//String St = wFileName ;
	//ShowMessage (L"TYrRastr::InsertRastrInFltFile\nExtention of " + St + L"is wrong") ;

	}
	wchar_t* HdrFileName = new wchar_t[len] ;
	wcscpy( HdrFileName, wFileName) ;
	HdrFileName[len - 1] = 'r';
	HdrFileName[len - 2] = 'd';
	HdrFileName[len - 3] = 'h';

	FILE *fr0 ;	if ((fr0 = _wfopen(HdrFileName,L"r"))== NULL)	{
	//String St =  HdrFileName ;
	//ShowMessage (L" ERROR ! Not possible to open " +St) ;

    }	int ncols1,nrows1;	double xllcorner1,yllcorner1,cellsize1;//,nodata1 ;
    char  str_xll[50],str_yll[50],str_sell[50],str_nodat[50];	if	(	( fscanf(fr0,"ncols         %d\n",&ncols1)== 0)	||(  fscanf(fr0,"nrows         %d\n",&nrows1 ) == 0)	|| ( fscanf(fr0,"xllcorner     %s\n",str_xll) == 0)	|| ( fscanf(fr0,"yllcorner     %s\n",str_yll)== 0 )	|| ( fscanf(fr0,"cellsize      %s\n",str_sell )== 0)	|| ( fscanf(fr0,"NODATA_value  %s\n",str_nodat  ) == 0 )	)	{	//ShowMessage (L"Error in format of HDR File");

    }
    replace(str_xll);	replace(str_yll);	replace(str_sell);	replace(str_nodat);	fclose(fr0) ;
    delete  [] HdrFileName ;
    xllcorner1 =atof(str_xll);	yllcorner1 = atof(str_yll);	cellsize1 = atof(str_sell);
    //	nodata1= atof(str_nodat);

	 // проверка соответствия экстентов

 // 2. Запись .flt
	FILE *fw1 ;
	if ((fw1 = _wfopen(wFileName,L"rb+"))== NULL)
	{
	//String St =  wFileName ;
	//ShowMessage (L"TYrRastr::ChangeCellValue\n ERROR ! Not possible to open " +St) ;
	return 1 ;
	}

	//  int n0 = nrows2 -1 - int(( yllcorner - yllcorner2)/ cellsize );
	int n0 = (yllcorner1 + nrows1 * cellsize1 - urpntP.Y )/cellsize1 ; //    (yllcorner1 + nrows1 * cellsize1 - yllcorner - nrows * cellsize + cellsize/2)/cellsize;
	int m0 =  (urpntP.X -  xllcorner1)/cellsize1 ; // int(( xllcorner - xllcorner1 + cellsize/2)/ cellsize );

	long offset0 = (n0  * ncols1 + m0 )* sizeof(float);
	const float  f = valZ;
   fseek(fw1,offset0,SEEK_SET);
   fwrite(&f,sizeof(float),1 ,fw1) ;

	fclose(fw1);

	return 0 ;
	}

 double  TYrRastr::get_PiksVal(wchar_t*wFileName,const TURPointXY urpntP)
 {
	int ncols1,  nrows1;
	double xllcorner1,yllcorner1, cellsize1, nodata1;
	char pbyteorder1[30] = {0};
	ReadHDRFile (wFileName,&ncols1, &nrows1, &xllcorner1
				 ,&yllcorner1, &cellsize1, &nodata1, pbyteorder1) ;
	int n0 = (yllcorner1 + nrows1 * cellsize1 - urpntP.Y ) /cellsize1 ;
	int m0 =  (urpntP.X - xllcorner1)/cellsize1 ;
	long offset0 = (n0  * ncols1 + m0 )* sizeof(float);
	float frez;
  FILE *fw1 ;
	if ((fw1 = _wfopen(wFileName,L"rb"))== NULL)
	{
	//String St =  wFileName ;
	//ShowMessage (L"TYrRastr::get_PiksVal\n ERROR ! Not possible to open " +St) ;
	return 1 ;
	}
	fseek(fw1,offset0,SEEK_SET);
	fread(&frez,sizeof(float),1 ,fw1) ;
   fclose(fw1) ;
   return (double)frez;

 }
 void TYrRastr::ReadHDRFile (wchar_t*wFileName,int *ncols, int *nrows, double *xllcorner
				 ,double *yllcorner, double *cellsize, double *nodata, char *pbyteorder)
 {
 	// Чтение .HDR файла
	int len = wcslen(wFileName) ;
	if ( !(( wFileName[len - 1] == 't') && (wFileName[len - 2] == 'l') // проверка, что
	&& (wFileName[len - 3] == 'f') ) )  // указанный файл имеет расширение .flt
	{
	//String St = wFileName ;
	//ShowMessage (L"TYrRastr::InsertRastrInFltFile\nExtention of " + St + L"is wrong") ;

	}
	wchar_t* HdrFileName = new wchar_t[len] ;
	wcscpy( HdrFileName, wFileName) ;
	HdrFileName[len - 1] = 'r';
	HdrFileName[len - 2] = 'd';
	HdrFileName[len - 3] = 'h';

	FILE *fr0 ;	if ((fr0 = _wfopen(HdrFileName,L"r"))== NULL)	{
	//String St =  HdrFileName ;
	//ShowMessage (L" ERROR ! Not possible to open " +St) ;

	}	int ncols1,nrows1;	double xllcorner1,yllcorner1,cellsize1,nodata1 ;	char  str_xll[50],str_yll[50],str_sell[50],str_nodat[50];	if	(	( fscanf(fr0,"ncols         %d\n",&ncols1)== 0)	||(  fscanf(fr0,"nrows         %d\n",&nrows1 ) == 0)	|| ( fscanf(fr0,"xllcorner     %s\n",str_xll) == 0)	|| ( fscanf(fr0,"yllcorner     %s\n",str_yll)== 0 )	|| ( fscanf(fr0,"cellsize      %s\n",str_sell )== 0)	|| ( fscanf(fr0,"NODATA_value  %s\n",str_nodat  ) == 0 )	)	{	//ShowMessage (L"Error in format of HDR File");

	}	fgets(pbyteorder,1001,fr0) ;	replace(str_xll);	replace(str_yll);	replace(str_sell);	replace(str_nodat);	fclose(fr0) ;	delete  [] HdrFileName ;	*xllcorner =atof(str_xll);	*yllcorner = atof(str_yll);	*cellsize = atof(str_sell);	*nodata= atof(str_nodat);
	 *ncols = ncols1;
	 *nrows = nrows1;
 }

void TYrRastr::applyKillingRange( const TURPointXY pntFall, const double VAlRad)
{
	for (int i = 0; i < nrows ; i++)
	{
		 double valDelY = get_Y( i) - pntFall.Y;
	   if (fabs(valDelY) >  VAlRad)
	   {
		continue;
	   }
	   for (int j = 0; j < ncols; j++)
	   {
			double valDelX  = get_X( j) - pntFall.X;
			double valPiks = get_PiksVal(get_X( j) , get_Y( i));
		 if ((fabs(valDelX) >  VAlRad)|| (valPiks < (nodata + 1.)))
		 {
		continue;
	   }
	   if (  (valDelX * valDelX +  valDelY * valDelY -VAlRad * VAlRad) <= 0.)
	   pflt_rastr[ i * ncols + j] = 1.;
	   }
	}
}
//--------------------------------------------------------------
// Вычисление к-ва значащих пикселей
int TYrRastr::calcQuantValuablePiksels()
{
	int ireturn = 0.;
	for (int i = 0; i < nrows; i++)
	{
		 for (int j  = 0; j < ncols; j++)
		 {
			if (pflt_rastr[ ncols * i + j] > ( nodata + 0.0001))
			{
				ireturn++;
			}
		 }
	}
	return ireturn ;
}
//--------------------------------------------------------------------------
// Задан порядклвый  номер NUmNotNodata значащего пикселя (не  равного nodata)
// требуется найти естественн?                ?й порядковый номер этого пикселя
//
//
//
//
int TYrRastr::getOrderNum(const int NUmNotNodata)
{
  int iNum = 0; // порядковый номер значащего пикселя
  int i =0 , ireturn = -1;
  for (i =0; i < ncols * nrows; i++)
  {
	if (pflt_rastr[i] < NODATA1)
	{
	  continue;
	}
	if (iNum == NUmNotNodata)
	{
	 ireturn = i;
	 break;
	}
	iNum++;
  }
  return ireturn;
}
//--------------------------------------------------------------------------
// Задана точка   PNt
// требуется найти  порядковый номер этого пикселя
// в котором эта точка находится
// возвращает:
// если точка лежит в экстенте, то номер пикселя в нумерации от 0 до ncols*nrows-1
// если точка не лежит в экстенте, то -1
int TYrRastr::getPixelNum(const TURPointXY PNt)
{
	 if(!IsPointInsideExtent(PNt.X,PNt.Y ) )
	 {
		 return -1;
     }
	int numcol = (PNt.X - xllcorner)/cellsize;
	int numrow = (PNt.Y - yllcorner)/cellsize;
	return numrow * ncols + numcol;
}


