//---------------------------------------------------------------------------

 #include <vcl.h>

#pragma hdrstop

#include "URPolygonZ.h"
#include "URPointXY.h"
 #include <stdio.h>
 #include "URPolygon.h"
  #include <math.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)

TURPolygonZ ::TURPolygonZ()
{

	NumParts = 0 ;
	NumPoints = 0 ;
	Parts = NULL ;
	Points = NULL ;
	ZArray = NULL ;
	MArray = NULL ;
}

__fastcall TURPolygonZ::~TURPolygonZ()
{
	if(Parts) delete []Parts ;
	Parts = NULL ;
	if(Points) delete []Points ;
	Points = NULL ;
	if(ZArray) delete []ZArray ;
	ZArray = NULL ;
	if(MArray) delete []MArray ;
	MArray = NULL ;
}

//--------------------------------------------------------------------------------------
 // �������� ������������
 TURPolygonZ &TURPolygonZ::operator=(const TURPolygonZ  &R)
 {
   memcpy(Box,R.Box,4 * sizeof(double));
   NumParts  = R.NumParts ;

   if(R.Parts != NULL)    {
	   Parts = new int[R.NumParts];
	   if(Parts == NULL) 	   {
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
   //



	memcpy(ZRange,R.ZRange,sizeof(double) * 2);
	memcpy(MRange,R.MRange,sizeof(double) * 2);

	if (R.ZArray != NULL)
	{
	  ZArray = new double [ R.NumPoints] ;
	  if( ZArray == NULL)
	  {
		 ShowMessage(L"Not memory for ZArray") ;
		   Abort() ;
	  }
	  memcpy( ZArray,R.ZArray, sizeof(double) * R.NumPoints) ;
	}


	if (R.MArray != NULL)
	{
	  MArray = new double [ R.NumPoints] ;
	  if( MArray == NULL)
	  {
		 ShowMessage(L"Not memory for MArray") ;
		   Abort() ;
	  }
	  memcpy( MArray,R.MArray, sizeof(double) * R.NumPoints) ;
	}

   return *this ;
 }

 // ����������� �����������
 TURPolygonZ::TURPolygonZ (const TURPolygonZ &R)
 {
  memcpy(Box,R.Box,4 * sizeof(double));
   NumParts  = R.NumParts ;

   if(R.Parts != NULL)    {
	   Parts = new int[R.NumParts];
	   if(Parts == NULL) 	   {
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
   //



	memcpy(ZRange,R.ZRange,sizeof(double) * 2);
	memcpy(MRange,R.MRange,sizeof(double) * 2);

	if (R.ZArray != NULL)
	{
	  ZArray = new double [ R.NumPoints] ;
	  if( ZArray == NULL)
	  {
		 ShowMessage(L"Not memory for ZArray") ;
		   Abort() ;
	  }
	  memcpy( ZArray,R.ZArray, sizeof(double) * R.NumPoints) ;
	}
	 memset( ZArray,0, sizeof(double) * R.NumPoints) ;

	if (R.MArray != NULL)
	{
	  MArray = new double [ R.NumPoints] ;
	  if( MArray == NULL)
	  {
		 ShowMessage(L"Not memory for MArray") ;
		   Abort() ;
	  }
	  memcpy( MArray,R.MArray, sizeof(double) * R.NumPoints) ;
	}
 }

 //-----------------------------------------------------------------------------------
 // ����� ������
TURPolygonZ::TURPolygonZ(wchar_t*FileName)
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
  if(! Points )
  {
  ShowMessage(L" Not possuble to create Points") ;
	   Abort() ;

  }

  ZArray = new double  [ NumPoints ] ;
   if(!ZArray )
  {
  ShowMessage(L" Not possuble to create  ZArray") ;
	   Abort() ;

  }
   ReadPolygonZFromASCII(FileName) ;


}
//---------------------------------------------------------------------------
 // ����� ������

TURPolygonZ::TURPolygonZ(const  TURPolygon &R)

{
 memcpy(Box,R.Box,4 * sizeof(double));
   NumParts  = R.NumParts ;

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
   //
   ZRange[0]=0;
   ZRange[1]=0;

   ZArray = new double [ R.NumPoints] ;
	  if( ZArray == NULL)
	  {
		 ShowMessage(L"Not memory for ZArray") ;
		   Abort() ;
	  }
  memset( ZArray,0,sizeof(double)*NumPoints) ;

}

  // ����� ������
TURPolygonZ :: TURPolygonZ( const int iNumParts, const int iNumPoints)

 {
   NumParts = iNumParts ;
   //3
   NumPoints = iNumPoints ;



	   Parts = new int[NumParts];
	   if(Parts == NULL)
	   {
		   ShowMessage(L"Not memory for Parts") ;
		   Abort() ;
	   } 

	   Points = new TURPointXY[iNumPoints];
	   if(Points == NULL)
	   {
		   ShowMessage(L"Not memory for Points") ;

	   }

	ZArray = new double[ iNumPoints]; 
	if(ZArray == NULL)
	   {
		   ShowMessage(L"Not memory for ZArray") ;

	   }

	MArray = new double[ iNumPoints]; 
	if(MArray == NULL)
	   {
		   ShowMessage(L"Not memory for ZArray") ;

	   } 
 }



//-----------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
 int TURPolygonZ::WriteToASCII(wchar_t*FileName)
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


	 for (int i = 0; i < NumParts; i++)
	 {

		fprintf(fw,"%i\n", i+1) ;
		int StartInd = Parts[i] ;
		int EndInd = NumPoints ;
		if(i < NumParts-1) EndInd = Parts[i+1] ;
		for(int j = StartInd; j < EndInd; j++)
		{
		   if( !fprintf(fw,"%f %f %f\n", Points[j].X,Points[j].Y,ZArray [j])) return 2 ;
		}

	   fprintf(fw,"END\n") ;
	 }

	 fprintf(fw,"END\n") ;
	 fclose(fw);


	return 0 ;

}

bool TURPolygonZ::ReadPolygonZFromASCII(wchar_t*FileName)
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
		 //ShowMessage( str) ;
		int StartInd = Parts[i] ;
		int EndInd = NumPoints ;
		if(i < NumParts-1) EndInd = Parts[i+1] ;
		for(int j = StartInd; j < EndInd; j++)
		{
			fgets(str,1001,fr);
			// ShowMessage( str) ;
		   //if( !fprintf(fw,"   %f %f %f\n", Points[j].X,Points[j].Y,ZArray [j])) return 2 ;
		   char *pstr = str;
		   while(pstr[0] == ' ')pstr++;

		   char str1[1000];
		   char *pstr1  = strchr(pstr,' ');
		   pstr1[0] = 0;
		   Points[ numPoint ].X = atof(pstr);
		  // double x =  Points[ numPoint ].X;
		   pstr1++;
			char *pstr2  = strchr(pstr1,' ');
			pstr2[0] = 0 ;
			pstr2++;
			Points[ numPoint ].Y = atof(pstr1);
		   //	double y =  Points[ numPoint ].Y;
			//ShowMessage( pstr2) ;
		  //	int l2 = strlen( pstr2) ;
		   pstr2[strlen(pstr2)-1] = 0;
			//ShowMessage( pstr2) ;
		//  int l1 = strlen( pstr2) ;
		   //	char *pstr3  = strchr(pstr2,' ');
		   // pstr3[0] = 0 ;
			ZArray [ numPoint ] = atof(pstr2);
		  //	double z = ZArray [ numPoint ] ;
		  numPoint++;


		}
		fgets(str,1001,fr);
		// ShowMessage( str) ;
	 }


	 fclose(fr);
	 calcBoundBox();
	 calcZRange();
	 return true ;


}

void TURPolygonZ::calcBoundBox()
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
void TURPolygonZ::calcMRange()
{
	double xMin = 1000000000 ;
	 double xMax = -1000000000 ;

	 for (int i =0; i < NumPoints; i++)
	 {
	   if (MArray[i] > xMax) xMax =  MArray[i];
	   if (MArray[i] < xMin) xMin =  MArray[i];

	 }
   MRange[0] =  xMin;
   MRange[1] =  xMax;

}
void TURPolygonZ::calcZRange()
{
	double xMin = 1000000000 ;
	 double xMax = -1000000000 ;

	 for (int i =0; i < NumPoints; i++)
	 {
	   if (ZArray[i] > xMax) xMax =  ZArray[i];
	   if (ZArray[i] < xMin) xMin =  ZArray[i];

	 }
   ZRange[0] =  xMin;
   ZRange[1] =  xMax;

}
double TURPolygonZ::calcVectSq()
{
 double sum = 0;
	for (int n= 0; n < NumParts; n++)
	{
	   sum +=   calcPartSq(n);
	}
	return sum;
}

double TURPolygonZ::calcPartSq(const int n)
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
double TURPolygonZ::calcLeng()
{
 double sum = 0;
	for (int n= 0; n < NumParts; n++)
	{
	   sum +=   calcPartLeng(n);
	}
	return sum;
}

double TURPolygonZ::calcPartLeng(const int n)
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
double TURPolygonZ::dist(TURPointXY*p0, TURPointXY*p1)
{
  return sqrt(((*p0).X -(*p1).X) * ((*p0).X -(*p1).X) + ((*p0).Y -(*p1).Y) * ((*p0).Y -(*p1).Y)) ;
}

void TURPolygonZ::calcPointsOfPolygonFromASCII(wchar_t*FileName,int *quanParts
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
	  *quanPoints = 0;
	 // int icur = 0;
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

void TURPolygonZ::fillPartsOfPolygonFromASCII(wchar_t*FileName, const int quanParts
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
	   //	fgets(str,1001,fr);
		int iCur = 0;
		for (int i =0; i < quanParts ; i++)
		{
		  //piarrParts[i]  = iCur +1;
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
		  //fgets(str,1001,fr);

		}


	  fclose(fr);
	  return  ;
}

	//http://www.esri.com/library/whitepapers/pdfs/shapefile.pdf
	// http://www.dbase.com/Knowledgebase/INT/db7_file_fmt.htm
	//http://www.clicketyclick.dk/databases/xbase/format/dbf.html#DBF_STRUCT

// ��������� ������� ���������� ������ � 4 ������� ����� (32 ���� ������)
//  input : chstr - ��������� �� ������ char[4]
// output: chstr - ��������� �� ������  char[4] c ���������� �������� ����������
// ������  chstr[0] = chstr[3] ; chstr1] = chstr[2] ;  chstr[2] = chstr[1] ; chstr[3] = chstr[0] ;
void TURPolygonZ::ChangeByteOrder(int * pi0)
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

void TURPolygonZ::WriteSetSHPFiles(wchar_t *wchFileName,TURPolygonZ *purPlg, const int quantPlg)
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
void TURPolygonZ::WriteDBASEFile(wchar_t *wchFileName,TURPolygonZ *purPlg, const int quantPlg)
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
		 // char carr2[20] ={0};
		  double a= purPlg[i].calcLeng();
		  double b = purPlg[i].calcVectSq()  ;
		  sprintf_s(carr1, 40, "%19.11e%19.11e",a,b);

		   fwrite(carr1,1,38 ,fw) ;
	   }
	 fclose(fw);
}

void TURPolygonZ::WriteMainFile(wchar_t *wchFileName,TURPolygonZ *purPlg, const int quantPlg)
{
   const int SHAPE_TYPE =15 ;
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
		   iFileLeng += 8 + 44 + 4 * purPlg[i].NumParts + 16 * purPlg[i].NumPoints
				  + 16 + 8* purPlg[i].NumPoints+ 16 + 8* purPlg[i].NumPoints;
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
		Box[4] = purPlg[0].ZRange[0] ; Box[5] = purPlg[0].ZRange[1] ;
		Box[6] = purPlg[0].MRange[0] ; Box[7] = purPlg[0].MRange[1] ;
		for (int i =0 ; i < quantPlg; i++)
		{
		   purPlg[i].calcBoundBox()  ;
		   purPlg[i].calcMRange() ;
		   purPlg[i].calcZRange() ;
		   if (purPlg[i].Box[0] <  Box[0]) Box[0] =  purPlg[i].Box[0];
		   if (purPlg[i].Box[1] <  Box[1]) Box[1] =  purPlg[i].Box[1];
		   if (purPlg[i].Box[2] >  Box[2]) Box[2] =  purPlg[i].Box[2];
		   if (purPlg[i].Box[3] >  Box[3]) Box[3] =  purPlg[i].Box[3];
		   if (purPlg[i].ZRange[0] <  Box[4]) Box[4] =  purPlg[i].ZRange[0];
		   if (purPlg[i].ZRange[1] >  Box[5]) Box[5] =  purPlg[i].ZRange[1];
		   if (purPlg[i].MRange[0] <  Box[6]) Box[6] =  purPlg[i].MRange[0];
		   if (purPlg[i].MRange[1] >  Box[7]) Box[7] =  purPlg[i].MRange[1];

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
		   int iContLeng = (44 + 4 * purPlg[i].NumParts + 16 * purPlg[i].NumPoints
				  + 16 + 8* purPlg[i].NumPoints+ 16 + 8* purPlg[i].NumPoints)/2 ;
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
			    fwrite(&(purPlg[i].ZRange), sizeof(double),2 ,fw) ;
			    fwrite(&(purPlg[i].ZArray), sizeof(double),purPlg[i].NumPoints ,fw) ;
			    fwrite(&(purPlg[i].MRange), sizeof(double),2 ,fw) ;
			    fwrite(&(purPlg[i].MArray), sizeof(double),purPlg[i].NumPoints ,fw) ;
	   }

  fclose(fw);
}
void TURPolygonZ::WriteIndexFile(wchar_t *wchFileName,TURPolygonZ *purPlg, const int quantPlg)
{
  FILE  *fw ;
	const int SHAPE_TYPE = 15;
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
		// 4. Bounding box
		double Box[8] = {0};
		purPlg[0].calcBoundBox()  ;
		memcpy(Box,purPlg[0].Box,4 * sizeof(double));
		Box[4] = purPlg[0].ZRange[0] ; Box[5] = purPlg[0].ZRange[1] ;
		Box[6] = purPlg[0].MRange[0] ; Box[7] = purPlg[0].MRange[1] ;
		for (int i =0 ; i < quantPlg; i++)
		{
		   purPlg[i].calcBoundBox()  ;
		   purPlg[i].calcMRange() ;
		   purPlg[i].calcZRange() ;
		   if (purPlg[i].Box[0] <  Box[0]) Box[0] =  purPlg[i].Box[0];
		   if (purPlg[i].Box[1] <  Box[1]) Box[1] =  purPlg[i].Box[1];
		   if (purPlg[i].Box[2] >  Box[2]) Box[2] =  purPlg[i].Box[2];
		   if (purPlg[i].Box[3] >  Box[3]) Box[3] =  purPlg[i].Box[3];
		   if (purPlg[i].ZRange[0] <  Box[4]) Box[4] =  purPlg[i].ZRange[0];
		   if (purPlg[i].ZRange[1] >  Box[5]) Box[5] =  purPlg[i].ZRange[1];
		   if (purPlg[i].MRange[0] <  Box[6]) Box[6] =  purPlg[i].MRange[0];
		   if (purPlg[i].MRange[1] >  Box[7]) Box[7] =  purPlg[i].MRange[1];

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
		   int iContLeng = (44 + 4 * purPlg[i].NumParts + 16 * purPlg[i].NumPoints
				  + 16 + 8* purPlg[i].NumPoints+ 16 + 8* purPlg[i].NumPoints)/2 ;
		   ChangeByteOrder(& iContLeng);
			fwrite(&ioffset,sizeof(int),1 ,fw) ;
			fwrite(&iContLeng,sizeof(int),1 ,fw) ;
		   offset +=  52  + 4 * purPlg[i].NumParts + 16 * purPlg[i].NumPoints
				  + 16 + 8* purPlg[i].NumPoints+ 16 + 8* purPlg[i].NumPoints;
	   }

	   fclose(fw);

}
void TURPolygonZ::ReadSHPFile(wchar_t *wchFileName,TURPolygonZ **ppurPlg,  int *pquantPlg)
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
	 if(!fr0) ShowMessage (L"TURPolygonZ::ReadSHPFile\nFile is not opened !") ;
	  int offset0 = 32;
	  int ishapetype = -1;

	  fseek(fr0,offset0,SEEK_SET);
	  fread(&ishapetype ,sizeof(int), 1,fr0) ;
	  if (ishapetype != 15)
	  {
		ShowMessage(L" There is not polygonZ in shape file") ;
		 return;
	  }
	  offset0 = 24;
	  fseek(fr0,offset0,SEEK_SET);
	  int lenSHXFile = -1;
	  fread(&lenSHXFile ,sizeof(int), 1,fr0) ;
	  ChangeByteOrder( &lenSHXFile);
	  int quantPlg =( 2 *  lenSHXFile - 100 )/ 8 ;
	   *ppurPlg = (TURPolygonZ *)realloc( *ppurPlg, quantPlg * sizeof( TURPolygonZ)) ;
	   *pquantPlg =  quantPlg ;

		FILE  *fr1 ;

	 fr1=_wfopen(wchFileName,L"rb");
	 if(!fr1) ShowMessage (L"TURPolygonZ::ReadSHPFile\nFile is not opened !") ;
	 int offset1 = -1;
	 int iNumParts = -1;
	 int iNumPoints = -1 ;
	 for (int i = 0; i < quantPlg; i++)
	 {
	   offset0 = 100 + 8 * i;
	   fseek(fr0,offset0,SEEK_SET);
	   fread(&offset1 ,sizeof(int), 1,fr0) ;
	   ChangeByteOrder( &offset1);
	   offset1 = 2 * offset1 ;
	   // �������i� ����� ������ � ������ i
	   // ������ ����� ������������ ������ � MArray, � ������ MArray �� ������������
	   int lengContent = -1;
	   int offset11 = offset1 + 4 ;
	   fseek(fr1,offset11,SEEK_SET);
	   fread(&lengContent ,sizeof(int), 1,fr1) ;
	   ChangeByteOrder( &lengContent);
	   lengContent = 2 * lengContent ;
	   //
	   // �������� , ����, ��� ��� �� NULL feature
		offset11 = offset1 + 8 ;
		fseek(fr1,offset11,SEEK_SET);
	   int ishapeCurr = -1 ;
	   fread(&ishapeCurr ,sizeof(int), 1,fr1) ;
	   if (ishapeCurr == 0) continue ;
		//
	   offset1 =  offset1 + 44;
	   fseek(fr1,offset1,SEEK_SET);
	   fread(&iNumParts ,sizeof(int), 1,fr1) ;
	   fread(&iNumPoints ,sizeof(int), 1,fr1) ;
	  // (*ppurPlg)[i ] = TURPolygonZ ( iNumParts, iNumPoints);
		TURPolygonZ pPlg( iNumParts, iNumPoints);
	   fread(pPlg.Parts ,sizeof(int), iNumParts,fr1) ;
	   for (int j = 0; j < iNumPoints; j++)
	   {
		 double x,y;
		// st = fread(& ((*ppurPlg)[i ].Points[j].X) ,sizeof(double), 1,fr1) ;
		// st = fread(& ((*ppurPlg)[i ].Points[j].Y) ,sizeof(double), 1,fr1) ;
		 fread(& x ,sizeof(double), 1,fr1) ;
		 fread(& y ,sizeof(double), 1,fr1) ;

		 pPlg.Points[j].X  = x;
		 pPlg.Points[j].Y  = y;
		// ((*ppurPlg)[i ].Points)[j].Y = y;
	   }
	   fread(pPlg.ZRange ,sizeof(double), 2,fr1) ;
	   fread(pPlg.ZArray ,sizeof(double), iNumPoints,fr1) ;

	   if (lengContent == (44 + 4 * iNumParts + 16 * iNumPoints
				  + 16 + 8* iNumPoints+ 16 + 8* iNumPoints))
	   {
		fread(pPlg.MRange ,sizeof(double), 2,fr1) ;
		fread(pPlg.MArray ,sizeof(double), iNumPoints,fr1) ;
 
	   }
		(*ppurPlg)[i ] = pPlg;

	 }

	 fclose(fr0);
	 fclose(fr1);

}
