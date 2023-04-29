﻿//---------------------------------------------------------------------------


#pragma hdrstop

#include "FloatRastr.h"

  #include <//String.h>
  #include <stdio.h>
 #include "YrWrite.h"
 #include <math.h>
 #include "UrPointXY.h"
//---------------------------------------------------------------------------

extern const double NOdata = -999999.0;
const double NOdata1 = -999998.0;

const double DNIL  = -1000000001.0;
const double DNIL1 = -100000000.0 ;
const double EPSSING = 1.0E-32  ;
const double EPS  = 0.0000000000000001 ;
#pragma package(smart_init)
 TFloatRastr ::TFloatRastr()
:   mCols(0)
   , mRows (0)
   ,mXllcorner(0)
   ,mYllcorner(0)
   ,mCellSize(0)
   ,mNodata(mNodata)
   ,mparrFlt(NULL)

{
  strcpy(mcharrByteorder, "byteorder     LSBFIRST") ;
}

//
TFloatRastr ::TFloatRastr(wchar_t *wFileName)
{
	mNodata = mNodata ;
	mparrFlt = NULL ;
	strcpy(mcharrByteorder, "byteorder     LSBFIRST") ;

	double nodata_t;

	// Чтение .HDR файла
	int len = wcslen(wFileName) ;
	if ( !(( wFileName[len - 1] == 't') && (wFileName[len - 2] == 'l') // проверка, что
	&& (wFileName[len - 3] == 'f') ) )  // указанный файл имеет расширение .flt
	{
	//String St = wFileName ;
   //	//ShowMessage(L"TYrRead::ReadHdrFileFromFltFile\nExtention of " + St + L"is wrong") ;

	}
	wchar_t* HdrFileName = new wchar_t[len] ;
	wcscpy( HdrFileName, wFileName) ;
	HdrFileName[len - 1] = 'r';
	HdrFileName[len - 2] = 'd';
	HdrFileName[len - 3] = 'h';

	FILE *fr0 ;	if ((fr0 = _wfopen(HdrFileName,L"r"))== NULL)	{
	//String St =  HdrFileName ;
   //	//ShowMessage(L" ERROR ! Not possible to open " +St) ;

	}
	int ncols1,nrows1;
	double xllcorner1,yllcorner1,cellsize1,NODATA_value1 ;	char  str_xll[50],str_yll[50],str_sell[50],str_nodat[50];	if	(	( fscanf(fr0,"ncols         %d\n",&ncols1)== 0)	||(  fscanf(fr0,"nrows         %d\n",&nrows1 ) == 0)	|| ( fscanf(fr0,"xllcorner     %s\n",str_xll) == 0)	|| ( fscanf(fr0,"yllcorner     %s\n",str_yll)== 0 )	|| ( fscanf(fr0,"cellsize      %s\n",str_sell )== 0)	|| ( fscanf(fr0,"NODATA_value  %s\n",str_nodat  ) == 0 )	)	{   //	//ShowMessage(L"Error in format of HDR File");

	}	replace(str_xll);	replace(str_yll);	replace(str_sell);	replace(str_nodat);	fclose(fr0) ;	delete  [] HdrFileName ;	mCols =ncols1;	mRows =nrows1;	mXllcorner =atof(str_xll);	mYllcorner = atof(str_yll);	mCellSize = atof(str_sell);	nodata_t = atof(str_nodat);
	// Конец чтения
	mparrFlt = new float [ mRows * mCols ] ;
	if ( mparrFlt == NULL)
	{
   //	//ShowMessage(L"Not memory for mparrFlt in  TYrRastr ::TYrRastr(wchar_t *wFileName)") ;
	//Abort() ;

	}


	FILE *fr ;
	if (	(fr=_wfopen(wFileName,L"rb")) == NULL)
	{
	//String s_22 =  L"TYrRead::ReadFltFile\nNot possible to open file" ;
   //	//ShowMessage(s_22) ;

	}
	fread(mparrFlt,sizeof(float),mRows * mCols,fr) ;
	fclose(fr);
	int i1 = 0;
	int j1 = 0;

	for ( i1 = 0; i1 < mRows; i1++)
	for ( j1 = 0; j1 < mCols; j1++)
	{
	if (fabs( mparrFlt[i1* mCols + j1]/2.  - nodata_t/2) < 1.) mparrFlt[i1* mCols + j1] = mNodata ;

	}

}


// парам конструктор создания из файла float
TFloatRastr ::TFloatRastr(int nc,int nr,double xll,double yll,double cs,double nd,float *arrData)
{
	mNodata = NOdata ;
	mparrFlt = NULL ;
	strcpy(mcharrByteorder, "byteorder     LSBFIRST") ;
	mCols = nc;
	mRows  = nr ;
	mXllcorner = xll ;
	mYllcorner = yll ;
	mCellSize = cs ;
	mNodata = nd ;
	// Конец чтения
	mparrFlt = new float [ mRows * mCols ] ;
	if ( mparrFlt == NULL)
	{
   //	//ShowMessage(L"Not memory for mparrFlt in  TYrRastr ::TYrRastr(wchar_t *wFileName)") ;
	//Abort() ;

	}
	memcpy(mparrFlt, arrData, sizeof(float)* nc * nr);

}

// парам конструктор создания из файла double
TFloatRastr ::TFloatRastr(int nc,int nr,double xll,double yll,double cs,double nd,double *arrData)
{
	mNodata = NOdata ;
	mparrFlt = NULL ;
	strcpy(mcharrByteorder, "byteorder     LSBFIRST") ;
	mCols = nc;
	mRows  = nr ;
	mXllcorner = xll ;
	mYllcorner = yll ;
	mCellSize = cs ;
	mNodata = nd ;
	// Конец чтения
	mparrFlt = new float [ mRows * mCols ] ;
	if ( mparrFlt == NULL)
	{
   //	//ShowMessage(L"Not memory for mparrFlt in  TYrRastr ::TYrRastr(wchar_t *wFileName)") ;
	//Abort() ;

	}

	float *parrFlt = new float [nc * nr];
	for (int i = 0; i < nc * nr; i++)
	{
	   parrFlt [i] = ((float) arrData[i]);
	}
	memcpy(mparrFlt, parrFlt, sizeof(float)* nc * nr);
	delete parrFlt;

}


// усли irastr = true то память резервируется
TFloatRastr ::TFloatRastr(int nc,int nr,double xll,double yll,double cs,double nd,const bool irastr)
{
	mNodata = NOdata ;
	mparrFlt = NULL ;
	strcpy(mcharrByteorder, "byteorder     LSBFIRST") ;
	mCols = nc;
	mRows  = nr ;
	mXllcorner = xll ;
	mYllcorner = yll ;
	mCellSize = cs ;
	mNodata = nd ;
	if (irastr == true)
	{
	   mparrFlt = new float [ mRows  * mCols ] ;
	  if ( mparrFlt == NULL)
	  {
		// //ShowMessage(L"Not memory for mparrFlt in  TFloatRastr ::TFloatRastr(wchar_t *wFileName)") ;
		 //Abort() ;

	  }
	  for (int i = 0 ; i < mCols * mRows  ; i++) mparrFlt[i] = mNodata ;

	}
}

// Конструктор копирования
 TFloatRastr::TFloatRastr (const TFloatRastr &R2)
 {
	mCols = R2.mCols ;
	mRows  = R2.mRows ;
	mXllcorner = R2.mXllcorner;
	mYllcorner =R2. mYllcorner;
	mCellSize =R2.mCellSize;
	mNodata = R2.mNodata;
	strcpy(mcharrByteorder,R2.mcharrByteorder)  ;

	mparrFlt = NULL;
	if ( R2.mparrFlt != NULL)
	{
	mparrFlt = new float [mCols * mRows ] ;

		if (mparrFlt == NULL)
		{
		 //ShowMessage(L"Not memory for mparrFlt in   TFloatRastr::TFloatRastr (const TFloatRastr &R)") ;
		  //Abort() ;
		}
	memcpy(mparrFlt,R2.mparrFlt,sizeof(float) * mCols * mRows ) ;
	}
 }
 // оператор присваивания
 TFloatRastr TFloatRastr::operator=(TFloatRastr  R2)
{
	mCols = R2.mCols ;
	mRows  = R2.mRows ;
	mXllcorner = R2.mXllcorner;
	mYllcorner =R2. mYllcorner;
	mCellSize =R2.mCellSize;
	mNodata = R2.mNodata;
	strcpy(mcharrByteorder,R2.mcharrByteorder)  ;

	mparrFlt = NULL;
	if ( R2.mparrFlt != NULL)
	{
	mparrFlt = new float [mCols * mRows ] ;

		if (mparrFlt == NULL)
		{
		 //ShowMessage(L"Not memory for mparrFlt in   TFloatRastr::TFloatRastr (const TFloatRastr &R)") ;
		  //Abort() ;
		}
	memcpy(mparrFlt,R2.mparrFlt,sizeof(float) * mCols * mRows ) ;
	}
 return *this ;
}

TFloatRastr::~ TFloatRastr()
{

 if( mparrFlt != NULL) delete [] mparrFlt ;
 // mparrFlt = NULL;
}

// извлечение растра с центом в точке pntP0 и длиной 2 * do
TFloatRastr::TFloatRastr(wchar_t *wFileName,const TURPointXY pntP0,const double d0)
{
	int ncols2, nrows2;
	double   xllcorner2,yllcorner2;
	char  pbyteorder[50];
	ReadHDRFile (wFileName,&ncols2, &nrows2, &xllcorner2,&yllcorner2, &mCellSize, &mNodata, pbyteorder)  ;

	mCols =(int)( 2 * d0/ mCellSize);
	mRows =  mCols;
	int ii1 =  (pntP0.X - d0 - xllcorner2)/ mCellSize ;
	int jj1 =  (pntP0.Y - d0 - yllcorner2)/ mCellSize ;

	mXllcorner =  ((double)ii1)  * mCellSize + xllcorner2 ;
	mYllcorner =  ((double)jj1)  * mCellSize + yllcorner2;

	mXllcorner = ( mXllcorner >= xllcorner2)?mXllcorner :xllcorner2;
	mYllcorner = ( mYllcorner >= yllcorner2)?mYllcorner :yllcorner2;

	if(( mXllcorner + 2. *d0) > (xllcorner2 + ncols2 * mCellSize))
	{
	mCols = (xllcorner2 + ncols2 * mCellSize -mXllcorner) /mCellSize;
	}
	if(( mYllcorner + 2. *d0) > (yllcorner2 + nrows2 * mCellSize))
	{
	mRows = (yllcorner2 + nrows2 * mCellSize -mYllcorner) /mCellSize;
	}



	mparrFlt = new float [ mRows * mCols ] ;
	if ( mparrFlt == NULL)
	{
	//ShowMessage(L"Not memory for pflt_rastr in  TYrRastr ::TYrRastr(wchar_t *wFileName)") ;
	//Abort() ;

	}
	// Чтение FLT файла
	//   В файле . flt массив хранится в порядке слева направо, сверху вниз

	FILE *fr ;
	if (	(fr=_wfopen(wFileName,L"rb")) == NULL)
	{
	//String s_22 =  L"TYrRead::ReadFltFile\nNot possible to open file" ;
  //	//ShowMessage(s_22) ;

	}

	int n0 = (yllcorner2 + nrows2 * mCellSize - mYllcorner - mRows * mCellSize + mCellSize /2.)/mCellSize;
	int m0 =  int(( mXllcorner - xllcorner2 + mCellSize/2. )/ mCellSize );
	long offset;
	float * pf = new float [ mCols];
	for (int i =0 ; i < mRows; i++)
	{
	offset = ((n0 + mRows - 1 - i) * ncols2 + m0 )* sizeof(float);
	fseek(fr,offset,SEEK_SET);
	fread(pf,sizeof(float), mCols,fr) ;
		for (int j = 0; j < mCols; j++)
		{
		mparrFlt[i* mCols  + j] = pf[j];
		if (fabs( mparrFlt[i* mCols  + j]/2. - mNodata/2.) < 1.) mparrFlt[i* mCols  + j] = mNodata ;
		}
	}

	fclose(fr);
	delete pf;
}


bool TFloatRastr:: replace(char*str)
  {	 int n = strlen(str);
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

void TFloatRastr::ReadHDRFile (wchar_t*wFileName,int *ncols, int *nrows, double *xllcorner
				 ,double *yllcorner, double *cellsize, double *nodata, char *pbyteorder)
 {
 	// Чтение .HDR файла
	int len = wcslen(wFileName) ;
	if ( !(( wFileName[len - 1] == 't') && (wFileName[len - 2] == 'l') // проверка, что
	&& (wFileName[len - 3] == 'f') ) )  // указанный файл имеет расширение .flt
	{
	//String St = wFileName ;
   //	//ShowMessage(L"TYrRastr::InsertRastrInFltFile\nExtention of " + St + L"is wrong") ;

	}
	wchar_t* HdrFileName = new wchar_t[len] ;
	wcscpy( HdrFileName, wFileName) ;
	HdrFileName[len - 1] = 'r';
	HdrFileName[len - 2] = 'd';
	HdrFileName[len - 3] = 'h';

	FILE *fr0 ;	if ((fr0 = _wfopen(HdrFileName,L"r"))== NULL)	{
	//String St =  HdrFileName ;
////ShowMessage(L" ERROR ! Not possible to open " +St) ;

	}	int ncols1,nrows1;	double xllcorner1,yllcorner1,cellsize1,nodata1 ;	char  str_xll[50],str_yll[50],str_sell[50],str_nodat[50];	if	(	( fscanf(fr0,"ncols         %d\n",&ncols1)== 0)	||(  fscanf(fr0,"nrows         %d\n",&nrows1 ) == 0)	|| ( fscanf(fr0,"xllcorner     %s\n",str_xll) == 0)	|| ( fscanf(fr0,"yllcorner     %s\n",str_yll)== 0 )	|| ( fscanf(fr0,"cellsize      %s\n",str_sell )== 0)	|| ( fscanf(fr0,"NODATA_value  %s\n",str_nodat  ) == 0 )	)	{	//ShowMessage(L"Error in format of HDR File");

	}	fgets(pbyteorder,1001,fr0) ;	replace(str_xll);	replace(str_yll);	replace(str_sell);	replace(str_nodat);	fclose(fr0) ;	delete  [] HdrFileName ;	*xllcorner =atof(str_xll);	*yllcorner = atof(str_yll);	*cellsize = atof(str_sell);	*nodata= atof(str_nodat);
	 *ncols = ncols1;
	 *nrows = nrows1;
 }

 double  TFloatRastr:: get_X(const int i,const int j)
 {
	 return mXllcorner + mCellSize /2. + j*mCellSize ;
 }

 double  TFloatRastr:: get_Y(const int i,const int j)
 {
	 return mYllcorner + mCellSize /2. + i*mCellSize ;
 }

 double  TFloatRastr:: get_PiksVal(const double x, const double y)
 {
	int i = (y - mYllcorner)/mCellSize ;
	int j =  (x - mXllcorner)/mCellSize ;
  //	//String s_22 = L"Iam in  get_PiksVal\n i = ";
   //	//ShowMessage(s_22 +i + L" j = " + j) ;
	 return ((double)mparrFlt[ i * mCols + j]) ;
 }

 void  TFloatRastr::WriteMeAsFltFile(wchar_t *wFileName)
 {
	WriteMassiveInFltFile(wFileName,mparrFlt,  mRows ,
							mCols,mXllcorner ,mYllcorner,
							 mCellSize,mNodata ) ;
 }


int TFloatRastr::WriteMassiveInFltFile(wchar_t*FileName,float * parrZ, const int nrows,
							 const int ncols,const float xllcorner ,const float yllcorner,
							 const float cellsize,const float NODATA_value )
// Для FLOAT массивов
// Функция записывает массив высот parrZ  в файл .flt и формирует файл .hdr
// в формате FLT ESRI. FileName - имя файла с расширением .flt. nrows и  ncols - к-во строк и столбцов
// соответвенно.  xllcorner и yllcorner   - координата x и y левого нижнего угла,
// cellsize- шаг сетки,  NODATA_value - значение, которым заполняется parrZ,
//  если величина Z  не определена
// Массив  parrZ хранится в порядке слева направо и сверху вниз.
// В ArcMap считается, что каждая вершина (точка) лежит в центре квадрата со стороной cellsize
// Таким обраэзом, в начале координат находится какбы не сама точка а нижний левый угол
// ее квадрата. Т е начало системы координат оказывается сдвинутым относительно левой нижней
// точки. Координаты левой нижней точки равны (cellsize/2,cellsize/2)
{
	// 1. Формирование .hdr
	int len = wcslen(FileName) ;
	if ( !( (FileName[len - 1] == 't') && (FileName[len - 2] == 'l') // проверка, что
	&& (FileName[len - 3] == 'f') ) )  // указанный файл имеет расширение .flt
	{
	//String St =  FileName ;
   //	//ShowMessage(L"TYrWrite::WriteMassiveInFltFile\nExtention of " + St + L" is wrong") ;
	return 1 ;
	}
	wchar_t* HdrFileName = new wchar_t[len] ;
	wcscpy( HdrFileName, FileName) ;
	HdrFileName[len - 1] = L'r';
	HdrFileName[len - 2] = L'd';
	HdrFileName[len - 3] = L'h';

	FILE *fw ;


	if ((fw = _wfopen(HdrFileName,L"w"))== NULL)
	{
	//String St =  HdrFileName ;
   //	//ShowMessage(L"TYrWrite::WriteMassiveInFltFile\nERROR ! Not possible to open " +St) ;
	return 1 ;
	}
	fprintf(fw,"ncols         %i\n",ncols);
	fprintf(fw,"nrows         %i\n",nrows);
	fprintf(fw,"xllcorner     %f\n",xllcorner);
	fprintf(fw,"yllcorner     %f\n",yllcorner);
	fprintf(fw,"cellsize      %f\n",cellsize);
	fprintf(fw,"NODATA_value  %f\n",NODATA_value);
	fprintf(fw,"byteorder     LSBFIRST");
	delete [] HdrFileName ;
	fclose(fw);

	// 2. Запись .flt
	FILE *fw1 ;
	if ((fw1 = _wfopen(FileName,L"wb"))== NULL)
	{
	//String St =  FileName ;
   //	//ShowMessage(L"TYrWrite::WriteMassiveInFltFile\n ERROR ! Not possible to open " +St) ;
	return 1 ;
	}

	  fwrite(parrZ,sizeof(float),ncols * nrows,fw1) ;
	fclose(fw1);

	return 0 ;

}

///


int TFloatRastr::ChangeCellValue(wchar_t*wFileName,const TURPointXY urpntP,const double valZ)
//float * parrZ, const int mRows ,
 //							 const int mCols,const float mXllcorner ,const float mYllcorner,
 //							 const float mCellSize,const float mNodata_value )
// Для FLOAT массивов
// Функция записывает массив высот parrZ  в файл .flt и формирует файл .hdr
// в формате FLT ESRI. FileName - имя файла с расширением .flt. mRows  и  mCols - к-во строк и столбцов
// соответвенно.  mXllcorner и mYllcorner   - координата x и y левого нижнего угла,
// mCellSize- шаг сетки,  mNodata_value - значение, которым заполняется parrZ,
//  если величина Z  не определена

// В ArcMap считается, что каждая вершина (точка) лежит в центре квадрата со стороной mCellSize
// Таким обраэзом, в начале координат находится какбы не сама точка а нижний левый угол
// ее квадрата. Т е начало системы координат оказывается сдвинутым относительно левой нижней
// точки. Координаты левой нижней точки равны (mCellSize/2,mCellSize/2)
{



	// Чтение .HDR файла
	int len = wcslen(wFileName) ;
	if ( !(( wFileName[len - 1] == 't') && (wFileName[len - 2] == 'l') // проверка, что
	&& (wFileName[len - 3] == 'f') ) )  // указанный файл имеет расширение .flt
	{
	//String St = wFileName ;
  //	//ShowMessage(L"TFloatRastr::InsertRastrInFltFile\nExtention of " + St + L"is wrong") ;

	}
	wchar_t* HdrFileName = new wchar_t[len] ;
	wcscpy( HdrFileName, wFileName) ;
	HdrFileName[len - 1] = 'r';
	HdrFileName[len - 2] = 'd';
	HdrFileName[len - 3] = 'h';

	FILE *fr0 ;	if ((fr0 = _wfopen(HdrFileName,L"r"))== NULL)	{
	//String St =  HdrFileName ;
   //	//ShowMessage(L" ERROR ! Not possible to open " +St) ;

	}	int ncols1,nrows1;	double xllcorner1,yllcorner1,cellsize1;//,nodata1 ;	char  str_xll[50],str_yll[50],str_sell[50],str_nodat[50];	if	(	( fscanf(fr0,"ncols         %d\n",&ncols1)== 0)	||(  fscanf(fr0,"nrows         %d\n",&nrows1 ) == 0)	|| ( fscanf(fr0,"xllcorner     %s\n",str_xll) == 0)	|| ( fscanf(fr0,"yllcorner     %s\n",str_yll)== 0 )	|| ( fscanf(fr0,"cellsize      %s\n",str_sell )== 0)	|| ( fscanf(fr0,"NODATA_value  %s\n",str_nodat  ) == 0 )	)	{	//ShowMessage(L"Error in format of HDR File");

	}	replace(str_xll);	replace(str_yll);	replace(str_sell);	replace(str_nodat);	fclose(fr0) ;	delete  [] HdrFileName ;	xllcorner1 =atof(str_xll);	yllcorner1 = atof(str_yll);	cellsize1 = atof(str_sell);  //	nodata1= atof(str_nodat);

// 2. Запись .flt	FILE *fw1 ;
	if ((fw1 = _wfopen(wFileName,L"rb+"))== NULL)
	{
	//String St =  wFileName ;
   //	//ShowMessage(L"TYrRastr::ChangeCellValue\n ERROR ! Not possible to open " +St) ;
	return 1 ;
	}


	int n0 = (yllcorner1 + nrows1 * cellsize1 - urpntP.Y )/cellsize1 ; //    (yllcorner1 + nrows1 * cellsize1 - yllcorner - nrows * cellsize + cellsize/2)/cellsize;
	int m0 =  (urpntP.X -  xllcorner1)/cellsize1 ; // int(( xllcorner - xllcorner1 + cellsize/2)/ cellsize );

	long offset0 = (n0  * ncols1 + m0 )* sizeof(float);
	const float  f = valZ;
	fseek(fw1,offset0,SEEK_SET);
	 fwrite(&f,sizeof(float),1 ,fw1) ;

	fclose(fw1);

	return 0 ; }

 ///

 double  TFloatRastr::get_PiksVal(wchar_t*wFileName,const TURPointXY urpntP)
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
	/////ShowMessage(L"TYrRastr::get_PiksVal\n ERROR ! Not possible to open " +St) ;
	return 1 ;
	}
	fseek(fw1,offset0,SEEK_SET);
	fread(&frez,sizeof(float),1 ,fw1) ;
   fclose(fw1) ;
   return (double)frez;

 }

    //	int mCols;
   //	int mRows  ;
  //	 double mXllcorner ;
	// double mYllcorner ;
   //	 double mCellSize ;
   //	 double mNodata ;
   //	 char mcharrByteorder[30]  ;
TFloatRastr  TFloatRastr:: SumOfRastrs(TFloatRastr *pRastr1, TFloatRastr *pRastr2)
{
   if (
		 ((*pRastr1).mCols != (*pRastr2).mCols )
	  || ((*pRastr1).mRows  != (*pRastr2).mRows  )
	  || ( fabs((*pRastr1).mXllcorner  != (*pRastr2).mXllcorner ) > EPS)
	  || (fabs((*pRastr1).mYllcorner != (*pRastr2).mYllcorner) > EPS)
	  || (fabs((*pRastr1).mCellSize != (*pRastr2).mCellSize ) > EPS)

	  )
	  {
		  //ShowMessage(L" Not posiible to sum Rastrs") ;
		  //Abort();
	  }
   TFloatRastr *DeltaSumstr =  pRastr1;
	for (int i = 0; i < (*DeltaSumstr).mRows  * (*DeltaSumstr).mCols; i++)

   {
	   (*DeltaSumstr).mparrFlt[ i] = NOdata ;
	   if(((*pRastr1).mparrFlt[ i] != NOdata) && ((*pRastr2).mparrFlt[ i] != NOdata))
	  (*DeltaSumstr).mparrFlt[ i] = (*pRastr1).mparrFlt[ i] + (*pRastr2).mparrFlt[ i];
   }
   return *DeltaSumstr;
}

///

TFloatRastr  TFloatRastr:: MinusOfRastrs(TFloatRastr *pRastr1, TFloatRastr *pRastr2)
{
   if (
		 ((*pRastr1).mCols != (*pRastr2).mCols )
	  || ((*pRastr1).mRows  != (*pRastr2).mRows  )
	  || ( fabs((*pRastr1).mXllcorner  != (*pRastr2).mXllcorner ) > EPS)
	  || (fabs((*pRastr1).mYllcorner != (*pRastr2).mYllcorner) > EPS)
	  || (fabs((*pRastr1).mCellSize != (*pRastr2).mCellSize ) > EPS)

	  )
	  {
		  //ShowMessage(L" Not posiible to sum Rastrs") ;
		  //Abort();
	  }
   TFloatRastr *MinusRastr =   pRastr1;
		for (int i = 0; i < (*MinusRastr).mRows  * (*MinusRastr).mCols; i++)


   {

	 (*MinusRastr).mparrFlt[ i] = NOdata ;
	   if(((*pRastr1).mparrFlt[ i] != NOdata) && ((*pRastr2).mparrFlt[ i] != NOdata) )
	  (*MinusRastr).mparrFlt[ i] = (*pRastr1).mparrFlt[ i] + (*pRastr2).mparrFlt[ i];
	  (*MinusRastr).mparrFlt[ i] = (*pRastr1).mparrFlt[ i] - (*pRastr2).mparrFlt[ i];
   }
   return *MinusRastr;
}
///

 int TFloatRastr::YMIN(const int n, const int m)
	 {
		 return (n < m)?n:m ;
	 }

	 ///

  int TFloatRastr::YMAX (const int n, const int m)
	 {
		 return (n > m)?n:m ;
	 }

	 ///

bool TFloatRastr::IsPointInsideExtent(const double x,const double y )
{
  double xmin,ymin,xmax,ymax ;
  GetExtent(xmin,ymin,xmax,ymax) ;
  return (x >= xmin) && (x <=  xmax) && (y >= ymin) && (y <= ymax );
}
 ///

void TFloatRastr::GetExtent(double &xmin,double &ymin,double &xmax,double &ymax)
{
  xmin =  mXllcorner - mCellSize/2;
  ymin =  mYllcorner - mCellSize/2;
  xmax =  xmin + mCellSize * mCols;
  ymax =  ymin + mCellSize * mRows ;
}

///

int  TFloatRastr::ISign(const double a)
{
 int ir =0;
	if (a >0 ) ir =1;
		else
		if (a <0) ir =0;
 return ir;
}
///
double TFloatRastr::YMINd(const double n, const double m)
{
 return (n < m)?n:m ;
}
///
double TFloatRastr::YMAXd (const double n, const double m)
{
		 return (n > m)?n:m ;
}

///
double  TFloatRastr::getValue(const int iNum)
{
	int iRow= iNum /mCols;
	int iCol =  iNum % mCols;
	return mparrFlt[ iRow * mCols + iCol];
}
///
TURPointXY  TFloatRastr::getCellCentre(const int iNum)
{
	int iRow = iNum /mCols;
	int iCol =  iNum % mCols;
	return TURPointXY (mXllcorner + iCol * mCellSize + mCellSize/2., mYllcorner + iRow * mCellSize + mCellSize/2. ) ;
}


 /*
bool  TFloatRastr:: InitRastr()
{
  if ((mCols <1)|| (mRows  <1) )
  {
	  //ShowMessage(L"Not possible to initialuze Rastr") ;
	  return false ;
  }


	   return true;
}

 bool  TFloatRastr:: CutFltRastr(TFloatRastr *dstRastr, TFloatRastr *srcRastr,const int nrowfirst
					  ,const int ncolfirst,const int mRowscut, const int mColscut)
{
   if (((nrowfirst + mRows cut) > (*srcRastr).mRows  ) ||
				   ((ncolfirst + mColscut) > (*srcRastr).mCols ) ) return false ;



  int icols = (*srcRastr).mCols ;
   for (int i = 0; i < mRows cut; i++)
   for (int j = 0 ; j < mColscut; j++)
   {

   *((*dstRastr).mparrFlt + i* mColscut + j)
		=*( (*srcRastr).mparrFlt +(nrowfirst + i)*icols +ncolfirst + j) ;
		//(*srcRastr).prastr [(nrowfirst + i)*icols +ncolfirst + j] ;

   }
	return true ;
}

  bool  TFloatRastr:: FindParamsForCutRastr(const TFloatRastr *srcRastr, const double xmin
				 ,const double ymin,const double xmax, const double ymax
				  ,int *nrowfirst,int *ncolfirst, int *mRows cut,int *mColscut)
// ВХОДНАЯ ИНФОРМАЦИЯ:
//  srcRastr - исходный растр, в котором надо определить какие строки и столбцы следует вырезать
// xmin, ymin - координата левого нижнего угла вырезаемой области
// xmax, ymax - координаты правого верхнего угдла вырезаемой области
// ВЫХОДНАЯ ИНФОРМАЦИЯ:
// nrowfirst, ncolfirst - номер первой  строки и столбца, которые вырезаются
// mRows cut, mColscut - к-во вырезаемых строк и столбцов
{

   *ncolfirst =  YMAX(0,(xmin - (*srcRastr).mXllcorner)  /  (*srcRastr).mCellSize );
  int jmax = YMIN((*srcRastr).mCols,(xmax- (*srcRastr).mXllcorner)  /  (*srcRastr).mCellSize ) ;
  *nrowfirst =  YMAX(0,(ymin - (*srcRastr).mYllcorner)  /  (*srcRastr).mCellSize );
  int imax =   YMIN((*srcRastr).mRows ,(ymax- (*srcRastr).mYllcorner)  /  (*srcRastr).mCellSize ) ;
  *mRows cut = imax - (*nrowfirst)  ;
  *mColscut =  jmax - (*ncolfirst) ;
	return true ;
}

 void  TFloatRastr:: ShowMe(int i)
 {
	 //String s_22 = L"i= " ;
	 //ShowMessage(s_22 + i +L"\n  mCols = " + mCols + L"mRows  = " + mRows  + L"mXllcorner = " + mXllcorner + L"mYllcorner  = " + mYllcorner + L"mCellSize = "  + mCellSize) ;

 }



 void  TFloatRastr:: ExportRastrExtent(TFloatRastr *dstRastr, TFloatRastr *srcRastr)
 {
  (*dstRastr).mCols     =(*srcRastr).mCols ;
  (*dstRastr).mRows       = (*srcRastr).mRows  ;
  (*dstRastr).mXllcorner = (*srcRastr).mXllcorner ;
  (*dstRastr).mYllcorner = (*srcRastr).mYllcorner ;
  (*dstRastr).mCellSize  = (*srcRastr).mCellSize ;
  (*dstRastr).mNodata    = (*srcRastr).mNodata ;

 }




 bool  TFloatRastr:: CustomizeToGrid( TFloatRastr *srcRastr,  TFloatRastr *destRastr)
 {

	   //	//ShowMessage(L"I am in  TFloatRastr:: CustomizeToGrid") ;
	 //  (*srcRastr).ShowMe(4) ;
	//  (*destRastr).ShowMe(5)  ;
	 for (int i =0 ; i <  (*destRastr).mRows  ; i++)
	 for (int j =0 ; j <(*destRastr).mCols; j++)
	 {
	   double x =  (*destRastr).mXllcorner + (*destRastr).mCellSize/2 + (*destRastr).mCellSize * j ;
	   double y = (*destRastr).mYllcorner + (*destRastr).mCellSize/2 + (*destRastr).mCellSize * i ;
	   //	//String s_22 =L"(*srcRastr).get_PiksVal(x,y) = " ;
	  //	//ShowMessage(s_22 + (*srcRastr).get_PiksVal(x,y)) ;
	   (*destRastr).mparrFlt[i * (*destRastr).mCols + j] =  (*srcRastr).get_PiksVal(x,y) ;
	 }


	 return true;
 }



double TFloatRastr::InterpolateZ(const double x,const double y )
// Интерполяция растра заданного массивом parrZ
// Входная информация:
//  1.parrZ - массив значений(высот)
//  2.mRows , mCols  - к-во строк и столбцов
//  3. mXllcorner, mYllcorner - координаты левого нижнего угла левого нижнего пиксела
//  4. mNodata - значение высоты в случае отсутствия информации
//  5. x,y - координаты точки, в которой надо получить значений parrZ
// Интерполяцмия производится если точка x,y выходит за пределы первоначального экстента
// не более чем на   mCellSize/2  по каждой оси
{
	 double mNodata = mNodata  ;
	 double xlb = mXllcorner +  mCellSize/2 ; // координата x центра левого нижнего пиксела
	 double ylb = mYllcorner +  mCellSize/2 ; // координата y центра левого нижнего пиксела
	 double x0 = xlb - mCellSize ; // Начало координат для интерполяции
	 double y0 = ylb - mCellSize ; // Начало координат для интерполяции
	 // //String s_22 = L"mXllcorner1 = " ;
	////ShowMessage(s_22 + mXllcorner1 +L"mYllcorner1 = " +mYllcorner1) ;
 // Определение шаблона окружающих точек
	double arrSh[4] = { mNodata,mNodata,mNodata, mNodata} ;
	int jCell = (x- x0)/mCellSize ;  //Номер столбца
	int iCell = (y- y0)/mCellSize ;   // Номер строки

	 // s_22 = L"Interpolatew x =" ;
////ShowMessage(s_22 + x +L" y =  " +y) ;
	// Выявление случая когда x,y не в экстенте

	if( ((x- x0)< 0 )|| ((x- x0) > (mCols +1)*mCellSize ) )
								  return  mNodata;
	if( ((y- y0)< 0 )|| ((y- y0) > (mRows  +1)*mCellSize ) )
								  return  mNodata;

	// выявление случав когда x,y лежит в крайних угловых ячейках
	// Возвращается значение угловой ячейки
	if ((iCell == 0) && (jCell == 0)) return mparrFlt[0] ;
   //	if ((jCell == mCols) && (iCell == 0)) return mparrFlt[mCols-1] ;  //изм 04.06.2011
	if ((jCell == (mCols + 1)) && (iCell == 0)) return mparrFlt[mCols-1] ; //изм 04.06.2011
  //	if ((jCell == mCols) && (iCell == mRows )) return mparrFlt[mCols* mRows -1] ;   //изм 04.06.2011
	if ((jCell == (mCols + 1)) && (iCell == (mRows  + 1) )) return mparrFlt[mCols* mRows -1] ; //изм 04.06.2011
  //	if ((jCell == 0) && (iCell == mRows  )) return mparrFlt[mCols* (mRows -1)] ;   //изм 04.06.2011
	if ((jCell == 0) && (iCell == (mRows  + 1) )) return mparrFlt[mCols* (mRows -1)] ;  //изм 04.06.2011
	// формирование шаблона

	// точка слева от растра
	if (jCell == 0)
	{
	  arrSh[0]= arrSh[2]=  mNodata;
	  arrSh[1] = mparrFlt[mCols * (iCell-1)] ;
	  arrSh[3] =  mparrFlt[mCols *  iCell ]  ;

	}
	// точка справа  от растра
   //	if (jCell == mCols)
	if (jCell == (mCols + 1))   //изм 04.06.2011
	{
	  arrSh[3]= arrSh[1]=  mNodata;
	  arrSh[0] =  mparrFlt[mCols * iCell - 1] ;
	  arrSh[3] =  mparrFlt[mCols * (iCell + 1) - 1] ;

	}
	// точка внизу от растра
	if (iCell == 0)
	{
	  arrSh[0]= arrSh[1]=  mNodata;
	  arrSh[2] = mparrFlt[jCell - 1] ;
	  arrSh[3] = mparrFlt[jCell    ] ;

	}
	// точка вверху от растра
 // (iCell == mRows )
	if (iCell == (mRows  + 1 ))  //изм 04.06.2011
	{
	  arrSh[2]=  arrSh[3]=  mNodata;
	  arrSh[0] = mparrFlt[mCols * ( mRows  - 1) + jCell - 1] ;
	  arrSh[1] = mparrFlt[mCols * ( mRows  - 1) + jCell   ] ;

	}
	// точка внутри растра
	if( (jCell > 0) && (jCell < (mCols +1) )  && (iCell > 0) && (iCell < (mRows  + 1) ) )
	{
	   arrSh[0] = mparrFlt[(iCell-1) * mCols +jCell -1]  ;
	   arrSh[1] = mparrFlt[(iCell-1) * mCols +jCell   ]  ;
	   arrSh[2] = mparrFlt[ iCell * mCols +jCell -1]  ;
	   arrSh[3] = mparrFlt[ iCell * mCols +jCell   ]  ;
	}


	 int ix = (x-x0)/ mCellSize   ;
	 int iy = (y-y0) / mCellSize ;
	  double xt = x -x0- ix* mCellSize; // координата x в шаблоне
	 double yt = y -y0- iy*mCellSize ;   // координата y в шаблоне
         if ((xt < 0)|| (xt >  mCellSize) )
	 {
		  //ShowMessage(L"Error_InterpolateZ");

		  //Abort();
	 }
	if ((yt < 0)|| (yt >  mCellSize) )
	 {
		  //ShowMessage(L"Error_InterpolateZ ");

		  //Abort();
	 }


	 return LinApprox(arrSh,mCellSize, mNodata,xt,yt) ; //Линейная аппроксимация в шаблоне

}

  double TFloatRastr::LinApprox(double* arrSh,const double mCellSize
			,const double mNodata,const double xt,const double yt)
{
	 if ((xt < 0)|| (xt >  mCellSize) )
	 {
		  //ShowMessage(L"Error_LinApprox ");

		  //Abort();
	 }
	if ((yt < 0)|| (yt >  mCellSize) )
	 {
		  //ShowMessage(L"Error_LinApprox ");

		  //Abort();
	 }
   // Если ни в одной точке шаблона значение не определено, то возвращается mNodata
	if ((arrSh[0] <  (mNodata + 1)) && (arrSh[1] <  (mNodata + 1))
		&&(arrSh[2] <  (mNodata + 1))&&(arrSh[3] <  (mNodata + 1))) return mNodata;
	// Если хотя бы в одной точке шаблона значение не определено(но по крайней мере
	// в одной определено) то возвращается значение в ближайшей точке

	if ((arrSh[0] <  (mNodata + 1)) || (arrSh[1] <  (mNodata + 1))
		||(arrSh[2] <  (mNodata + 1))||(arrSh[3] <  (mNodata + 1)))
						 return NearestPointValue ( arrSh,mCellSize,  mNodata,xt, yt) ;
	else
	// Если во всех точках шаблона значения определены, то линейная интерполяция
	return BilinearValue ( arrSh,mCellSize, xt, yt) ;


}

double TFloatRastr::NearestPointValue (double* arrSh,const double mCellSize
			,const double  mNodata,const double xt,const double yt)
{
  double min = 10 * mCellSize * mCellSize  ;
	int jmin = -1 ;
	if ((arrSh[0] <  (mNodata + 1)) && (arrSh[1] <  (mNodata + 1))
		&&(arrSh[2] <  (mNodata + 1))&&(arrSh[3] <  (mNodata + 1))) return mNodata;
	 if ((xt * (xt - mCellSize)) > EPSSING)
	 {
		  //ShowMessage(L"Error_NearestPointValue ");
		  //Abort();
	 }
	 if ((yt * (yt - mCellSize)) > EPSSING)
	 {
		  //ShowMessage(L"Error_NearestPointValue ");
		  //Abort();
	 }


	for (int i = 0; i < 2; i++)
	for (int j =0; j < 2 ; j++)
	 {
	  double x0 = j* mCellSize;
	  double y0 = i * mCellSize ;
	  double d = (xt -x0)*(xt -x0) + (yt - y0) * (yt - y0);
	  int num = i*2 +j ;
		  if ((d < min)  && (arrSh[num] > (mNodata +1)) )
		  {
		   min = d;
		   jmin = num ;

		  }
	  }
	  if (jmin == -1) return  mNodata;
	  else return  arrSh[jmin] ;



}

double TFloatRastr::BilinearValue (double* arrSh,const double mCellSize
			,const double xt,const double yt)
{
  double ax = xt/ mCellSize ;
  double ay = yt/ mCellSize ;
  double z4 = (1 - ay) *  arrSh[0] +  ay * arrSh[2] ;
  double z5 = (1 - ay) *  arrSh[1] +  ay * arrSh[3] ;

  return ( (1- ax) * z4 + ax * z5);

}

void  TFloatRastr:: ModifyOrderOfDataArray()
{
	if (mparrFlt == NULL) return ;
	double *Ztemp = new double [mCols* mRows  ];
	if (Ztemp == NULL)
	{
	//ShowMessage(L"Not memory in TFloatRastr:: ModifyOrderOfDataArray") ;
	return ;
	}
	memcpy(Ztemp, mparrFlt, sizeof(double)*mCols* mRows );
	for ( int i1 = 0; i1 < mRows ; i1++)
	for ( int j1 = 0; j1 < mCols; j1++)
	{
		mparrFlt[i1*mCols + j1]=   Ztemp[(mRows -1-i1)*mCols +j1] ;
	}
	delete []Ztemp ;
}



 bool TFloatRastr::DigCanyon(const TURPointXY P0,const TURPointXY P1 )

 {
  int i0 = (P0.Y - mYllcorner)/mCellSize;
  int j0 = (P0.X - mXllcorner)/mCellSize;
  int i1 = (P1.Y - mYllcorner)/mCellSize;
  int j1 = (P1.X - mXllcorner)/mCellSize;
  const double z0 = mparrFlt[ i0 * mCols + j0 ];
  const double z1 = mparrFlt[ i1 * mCols + j1 ];

  int iNNx = fabs(P1.X - P0.X)/ mCellSize;
  int iNNy = fabs(P1.Y - P0.Y)/ mCellSize;
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
	 icur = (Pcur.Y - mYllcorner + ky * 0.001)/ mCellSize;
	 jcur = (Pcur.X - mXllcorner + kx * 0.001)/ mCellSize;

	 P00.X  = P01.X + kx * 0.001;
	 P00.Y  = P01.Y + ky * 0.001;
	 icur = (P00.Y - mYllcorner + ky * 0.1)/ mCellSize;
	 jcur = (P00.X - mXllcorner + kx * 0.1)/ mCellSize;
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
	 icur = (Pcur.Y - mYllcorner + ky * 0.001)/ mCellSize;
	 jcur = (Pcur.X - mXllcorner + kx * 0.001)/ mCellSize;
	 double a = delt *(quantN -1 - i) ;

	 double aMod =  z1 + delt *(quantN  - i);
	 if(aMod > mparrFlt[icur*mCols + jcur])
	 {
		 //ShowMessage(L"Error in data points");
		 return false;
	 }
	 mparrFlt[icur*mCols + jcur] =  aMod;
	 P00.X  = P01.X + kx * 0.001;
	 P00.Y  = P01.Y + ky * 0.001;
	 icur = (P00.Y - mYllcorner + ky * 0.1)/ mCellSize;
	 jcur = (P00.X - mXllcorner + kx * 0.1)/ mCellSize;

	 if( (icur == i1)&&(jcur == j1) ) break;


	}


	 return true ;
 }

void TFloatRastr::AdjustDEM( wchar_t *wFileDEM  //исходный  FLT файлом DEM
						 ,wchar_t *wFileSetNull   // исходный  FLT файл с растром потоков типа setnull
						 ,TURPointXY *arrP0,TURPointXY *arrP1, const int quantPoints,TURPointXY *purpntOut)
{

	for (int i = 0; i < quantPoints; i++)
	{
	  // //ShowMessage(i);
	   if (!Link2Streams(arrP0[i],arrP1[i],wFileDEM ,wFileSetNull,&purpntOut[i*2], &purpntOut[i*2 + 1]))
	   {
		 //String sOut = L"ERROR Point No ";
		 //ShowMessage(sOut + (i+1));
	   }

	}

}
bool TFloatRastr::Link2Streams(const TURPointXY urpntUpper,const TURPointXY urpntLower
					,wchar_t *wFileDEM ,wchar_t *wFileSetNull
					,TURPointXY *urpntStart,TURPointXY *urpntEnd)
{
	const double   MAX_DIST = 4000;

	TFloatRastr rstrDEM(wFileDEM ,urpntUpper,MAX_DIST );
   //	rstrDEM.WriteMeAsFltFile(L"D:\\GIDROPROJECT\\NEW_PROJECT\\Mosaik_1_2_3\\TXT_Files\\rstrDEM.flt") ;
	int quantUp = 100;
	int quantLow = 100;
	int * piarrUpNums = (int*)malloc(quantUp * sizeof(int));
	int * piarrLowNums = (int*)malloc(quantLow * sizeof(int));
	int **ppiarrUpNums =  &piarrUpNums;
	int **ppiarrLowNums =  &piarrLowNums;
	 TFloatRastr rstrSetNull =  rstrDEM;
	 if (wFileSetNull) rstrSetNull =  TFloatRastr (wFileSetNull,urpntUpper,MAX_DIST );


	// TFloatRastr rstrSetNull(wFileSetNull,urpntUpper,MAX_DIST );
	if (wFileSetNull) {


	//создание вырхнего и нижнего кластеоров в нумерации растра setnull
	rstrSetNull.CreateCluster(urpntUpper, ppiarrUpNums,& quantUp);
	rstrSetNull.CreateCluster(urpntLower, ppiarrLowNums ,& quantLow);

	}
	else
	{
		quantUp = 1;
		quantLow = 1;

		//
		int nr_Up =  (urpntUpper.Y -rstrSetNull.mYllcorner)/rstrSetNull.mCellSize ;
		int nc_Up =  (urpntUpper.X -rstrSetNull.mXllcorner)/rstrSetNull.mCellSize ;
		(*ppiarrUpNums)[0] =  nr_Up * rstrSetNull.mCols + nc_Up;
		//
		int nr_Low =  (urpntLower.Y -rstrSetNull.mYllcorner)/rstrSetNull.mCellSize ;
		int nc_Low =  (urpntLower.X -rstrSetNull.mXllcorner)/rstrSetNull.mCellSize ;
		(*ppiarrLowNums)[0] =  nr_Low * rstrSetNull.mCols + nc_Low;

    }
	  // перевод кластеров в нумерацию растра DEM
	int * piarrCusterUp = new int [quantUp] ;
	int * piarrCusterLow = new int [quantLow ] ;
	int **ppiarrCusterUp =  &piarrCusterUp;
	int **ppiarrCusterLow=  &piarrCusterLow;
	 for (int i = 0; i < quantUp; i++)
	 {
	   TURPointXY tP =  rstrSetNull.getCellCentre((*ppiarrUpNums)[i]) ;
	   int i0 = (tP.Y - rstrDEM.mYllcorner)/ rstrDEM.mCellSize;
	   int j0 =  (tP.X - rstrDEM.mXllcorner)/ rstrDEM.mCellSize;
	   (*ppiarrCusterUp)[i] = i0 * rstrDEM.mCols + j0 ;
	 }
	   for (int i = 0; i < quantLow; i++)
	 {
	   TURPointXY tP =  rstrSetNull.getCellCentre((*ppiarrLowNums)[i]) ;
	   int i0 = (tP.Y - rstrDEM.mYllcorner)/ rstrDEM.mCellSize;
	   int j0 =  (tP.X - rstrDEM.mXllcorner)/ rstrDEM.mCellSize;
	   (*ppiarrCusterLow)[i] = i0 * rstrDEM.mCols + j0 ;
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
		//ShowMessage(L"Верхний_поток_ниже_нижнего") ;


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

void TFloatRastr::CreateRasterFromCluster(int *piarrNums , const int quantNums,TFloatRastr &rstrRez)
{
   for (int i = 0; i < rstrRez.mRows ; i++)
   for (int j = 0; j < rstrRez.mCols; j++)
   {
	  rstrRez.mparrFlt[i * rstrRez.mCols + j] = rstrRez.mNodata;
   }
   for (int i =0; i < quantNums; i++)
	{
	   rstrRez.mparrFlt[piarrNums[i] ] = 1;
   }
   return ;
}
void TFloatRastr::CreateCluster(const TURPointXY urpntP0, int **ppiarrNums , int *quantNums)
{
   const double CLASTER_DIMENSION = 1500;
   const int iCLAST_DIM =  CLASTER_DIMENSION/ mCellSize;
   int lenMemory =  *quantNums;
   int quantCur = 1;
   int nr =  (urpntP0.Y -mYllcorner)/mCellSize ;
   int nc =  (urpntP0.X -mXllcorner)/mCellSize ;
   (*ppiarrNums)[0] =  nr * mCols + nc;
	int imin = YMAX(0,nr-iCLAST_DIM);
	int imax = YMIN(mRows ,nr + iCLAST_DIM);
	int jmin = YMAX(0,nc-iCLAST_DIM);
	int jmax = YMIN(mCols,nc + iCLAST_DIM);
  bool bProceed   = false;
   while(1)
   {
	   bProceed   = false;
	   for (int i  = imin; i <  imax; i++)
	   {
	   for (int j  = jmin; j < jmax  ; j++)
	   {
		   int numCur = i * mCols + j;
		   if(mparrFlt[i * mCols + j] == mNodata) continue;
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
			  int numRow =  (*ppiarrNums)[n] / mCols;
			  int numCol =  (*ppiarrNums)[n] % mCols;
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

int TFloatRastr::FindSinkIndex (int **ppiarrNums, const int quantNums)
{
	int iReturn = (*ppiarrNums) [0];
	double min = mparrFlt[ iReturn ] ;
	for (int i = 0; i < quantNums ; i++)
	{
		int j =  (*ppiarrNums) [i];
		if (mparrFlt[ j] < mparrFlt[ iReturn ] ) iReturn = j;


	}
	return iReturn  ;
}

bool TFloatRastr::IsLowerPointSuit(const TURPointXY P0,const TURPointXY P1 )

 {
  int i0 = (P0.Y - mYllcorner)/mCellSize;
  int j0 = (P0.X - mXllcorner)/mCellSize;
  int i1 = (P1.Y - mYllcorner)/mCellSize;
  int j1 = (P1.X - mXllcorner)/mCellSize;
  int iNNx = fabs(P1.X - P0.X)/ mCellSize;
  int iNNy = fabs(P1.Y - P0.Y)/ mCellSize;
  const double z0 = mparrFlt[ i0 * mCols + j0 ];
  const double z1 = mparrFlt[ i1 * mCols + j1 ];
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
	 icur = (Pcur.Y - mYllcorner + ky * 0.001)/ mCellSize;
	 jcur = (Pcur.X - mXllcorner + kx * 0.001)/ mCellSize;

	 P00.X  = P01.X + kx * 0.001;
	 P00.Y  = P01.Y + ky * 0.001;
	 icur = (P00.Y - mYllcorner + ky * 0.1)/ mCellSize;
	 jcur = (P00.X - mXllcorner + kx * 0.1)/ mCellSize;
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
	 icur = (Pcur.Y - mYllcorner + ky * 0.001)/ mCellSize;
	 jcur = (Pcur.X - mXllcorner + kx * 0.001)/ mCellSize;
	 double a = delt *(quantN -1 - i) ;

	 double aMod =  z1 + delt *(quantN  - i);
	 if(aMod > mparrFlt[icur*mCols + jcur]) return false;

	 P00.X  = P01.X + kx * 0.001;
	 P00.Y  = P01.Y + ky * 0.001;
	 icur = (P00.Y - mYllcorner + ky * 0.1)/ mCellSize;
	 jcur = (P00.X - mXllcorner + kx * 0.1)/ mCellSize;

	 if( (icur == i1)&&(jcur == j1) ) break;
	}
	 return true ;
 }


int TFloatRastr::InsertRastrInFltFile(wchar_t*wFileName)
//float * parrZ, const int mRows ,
 //					 const int mCols,const float mXllcorner ,const float mYllcorner,
 //							 const float mCellSize,const float mNodata_value )
// Для FLOAT массивов
// Функция записывает массив высот parrZ  в файл .flt и формирует файл .hdr
// в формате FLT ESRI. FileName - имя файла с расширением .flt. mRows  и  mCols - к-во строк и столбцов
// соответвенно.  mXllcorner и mYllcorner   - координата x и y левого нижнего угла,
// mCellSize- шаг сетки,  mNodata_value - значение, которым заполняется parrZ,
//  если величина Z  не определена
// Массив  parrZ хранится в порядке слева направо и снизу вверх. То есть parrZ[0]
// это нижняя левая точка, а     parrZ[mRows  * mCols ] это правая верхняя точка
// В ArcMap считается, что каждая вершина (точка) лежит в центре квадрата со стороной mCellSize
// Таким обраэзом, в начале координат находится какбы не сама точка а нижний левый угол
// ее квадрата. Т е начало системы координат оказывается сдвинутым относительно левой нижней
// точки. Координаты левой нижней точки равны (mCellSize/2,mCellSize/2)
{



	// Чтение .HDR файла
	int len = wcslen(wFileName) ;
	if ( !(( wFileName[len - 1] == 't') && (wFileName[len - 2] == 'l') // проверка, что
	&& (wFileName[len - 3] == 'f') ) )  // указанный файл имеет расширение .flt
	{
	//String St = wFileName ;
	//ShowMessage(L"TFloatRastr::InsertRastrInFltFile\nExtention of " + St + L"is wrong") ;

	}
	wchar_t* HdrFileName = new wchar_t[len] ;
	wcscpy( HdrFileName, wFileName) ;
	HdrFileName[len - 1] = 'r';
	HdrFileName[len - 2] = 'd';
	HdrFileName[len - 3] = 'h';

	FILE *fr0 ;	if ((fr0 = _wfopen(HdrFileName,L"r"))== NULL)	{
	//String St =  HdrFileName ;
	//ShowMessage(L" ERROR ! Not possible to open " +St) ;

	}	int mCols1,mRows 1;	double mXllcorner1,mYllcorner1,mCellSize1,mNodata1 ;	char  str_xll[50],str_yll[50],str_sell[50],str_nodat[50];	if	(	( fscanf(fr0,"mCols         %d\n",&mCols1)== 0)	||(  fscanf(fr0,"mRows          %d\n",&mRows 1 ) == 0)	|| ( fscanf(fr0,"mXllcorner     %s\n",str_xll) == 0)	|| ( fscanf(fr0,"mYllcorner     %s\n",str_yll)== 0 )	|| ( fscanf(fr0,"mCellSize      %s\n",str_sell )== 0)	|| ( fscanf(fr0,"mNodata_value  %s\n",str_nodat  ) == 0 )	)	{	//ShowMessage(L"Error in format of HDR File");

	}	replace(str_xll);	replace(str_yll);	replace(str_sell);	replace(str_nodat);	fclose(fr0) ;	delete  [] HdrFileName ;	mXllcorner1 =atof(str_xll);	mYllcorner1 = atof(str_yll);	mCellSize1 = atof(str_sell);	mNodata1= atof(str_nodat);

	 // проверка соответствия экстентов
	 double xmin,ymin,xmax,ymax ,xmin1,ymin1,xmax1,ymax1;

	 xmin = mXllcorner ;
	 ymin  =mYllcorner;
	 xmax  = mXllcorner  + mCellSize* mCols;
	 ymax  = mYllcorner  + mCellSize * mRows ;

	 xmin1 = mXllcorner1 ;
	 ymin1  =mYllcorner1;
	 xmax1  = mXllcorner1  + mCellSize1 * mCols1;
	 ymax1  = mYllcorner1  + mCellSize1 * mRows 1;
	 if ( (xmin < xmin1)
	 || (xmax > xmax1)
	 || ( ymin < ymin1)
	 || (ymax > ymax1) )
	 {
		//ShowMessage(L"TFloatRastr::InsertRastrInFltFile\n ERROR ! Extents do not comply each other ") ;
		return 1 ;
	 }
 // 2. Запись .flt
	FILE *fw1 ;
	if ((fw1 = _wfopen(wFileName,L"rb+"))== NULL)
	{
	//String St =  wFileName ;
	//ShowMessage(L"TFloatRastr::InsertRastrInFltFile\n ERROR ! Not possible to open " +St) ;
	return 1 ;
	}

	//  int n0 = mRows 2 -1 - int(( mYllcorner - mYllcorner2)/ mCellSize );
	int n0 = (mYllcorner1 + mRows 1 * mCellSize1 - mYllcorner - mRows  * mCellSize + mCellSize/2)/mCellSize;
	int m0 =  int(( mXllcorner - mXllcorner1 + mCellSize/2)/ mCellSize );
	long offset0 = (n0  * mCols1 + m0 )* sizeof(float);;
	float * pf = new float [ mCols];
   int iseek =	fseek(fw1,offset0,SEEK_SET);
	for (int i =0 ; i < mRows ; i++)
	{
	//offset = ((n0 + i) * mCols1 + m0 )* sizeof(float);

	// fseek(fw1,offset,SEEK_CUR);
	for (int j = 0;j < mCols; j++)
	{
	float val = mparrFlt[(mRows  - i-1)* mCols  + j]  ;
	pf[j] = val;
	if (fabs( val/2 - mNodata/2) < 1.) pf[j] = mNodata1 ;

	}

	size_t ss =  fwrite(pf,sizeof(float),mCols ,fw1) ;
  //	TFloatRastr tRaster( wFileName);
   //	 tRaster.WriteMeAsFltFile(L"D:\\GIDROPROJECT\\Gidro_C++\\InputData\\tRaster.flt") ;
	//offset +=  mCols1;
	offset0 = ((n0 + i+1) * mCols1 + m0 )* sizeof(float);


	if (i < ( mRows  -1)) iseek = fseek(fw1,offset0,SEEK_SET);
	}

	fclose(fw1);
	delete pf;
	return 0 ;
	}


TURPointXY TFloatRastr::OutPnt(const TURPointXY P0,const double kx,const double ky)
{
 //int icur,const int jcur
 int i0 = (P0.Y - mYllcorner )/ mCellSize;
 int j0 = (P0.X - mXllcorner )/ mCellSize;
 int ia = ISign(YMAXd(0,kx));
  double tx = (fabs(kx) <= 0.0000001)?10*mCellSize:((j0 + ISign(YMAXd(0,kx)))* mCellSize + mXllcorner - P0.X )/ kx;
  double ty = (fabs(ky) <= 0.0000001)?10*mCellSize:((i0 + ISign(YMAXd(0,ky)))* mCellSize + mYllcorner - P0.Y ) / ky;
  double t =  YMINd(tx,ty);

	return TURPointXY(P0.X + kx *t,P0.Y + ky*t);
}

 */
#pragma package(smart_init)
