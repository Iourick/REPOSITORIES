//---------------------------------------------------------------------------


#pragma hdrstop
#include <float.h>
#include <math.h>
#include <vcl.h>
#include <stdio.h>
#include "Table_1D.h"
#include "URPolyLine.h"

__fastcall TTable_1D::~TTable_1D()
{
	if(mparrArg) delete []mparrArg ;
	mparrArg = NULL ;

	if(mparrVal) delete []mparrVal ;
	mparrVal = NULL ;


}
//---------------------------------------------------------------------------

 // �������� ������������
 TTable_1D &TTable_1D::operator=(const TTable_1D  &R)
 {
	mNumCols = R.mNumCols ;

	if(R.mparrArg != NULL)
	{
		mparrArg = new double[R.mNumCols];
		if(mparrArg == NULL)
		{
		ShowMessage(L"Not memory for mparrArg") ;
		Abort() ;
		}
		memcpy( mparrArg,R.mparrArg, R.mNumCols * sizeof(double));
	}


	if(R.mparrVal != NULL)
	{
		mparrVal = new double[R.mNumCols];
		if(mparrVal == NULL)
		{
		ShowMessage(L"Not memory for mparrVal") ;
		Abort() ;
		}
		memcpy( mparrVal,R.mparrVal, R.mNumCols * sizeof(double));
	}
	return *this ;
 }

 // ����������� �����������
 TTable_1D::TTable_1D (const TTable_1D &R)
 {
	mNumCols = R.mNumCols ;

	if(R.mparrArg != NULL)
	{
		mparrArg = new double[R.mNumCols];
		if(mparrArg == NULL)
		{
		ShowMessage(L"Not memory for mparrArg") ;
		Abort() ;
		}
		memcpy( mparrArg,R.mparrArg, R.mNumCols * sizeof(double));
	}


	if(R.mparrVal != NULL)
	{
		mparrVal = new double[R.mNumCols];
		if(mparrVal == NULL)
		{
		ShowMessage(L"Not memory for mparrVal") ;
		Abort() ;
		}
		memcpy( mparrVal,R.mparrVal, R.mNumCols * sizeof(double));
	}
 }
//-----------------------------------------------------------------------------------
// ����� ������
//--------------------------------------------------------------------------------------
 TTable_1D ::TTable_1D()
{
	mNumCols = 0;
	mparrArg = NULL;
	mparrVal = NULL;
}

 // ����� ������ 1
TTable_1D :: TTable_1D(const  double *parrArg,const  double *parrVal, const int NumCols)

 {
	mNumCols = NumCols ;
	mparrArg = NULL ;
	mparrArg = new double[NumCols];
	if(mparrArg == NULL)
	{
	ShowMessage(L"Not memory for mparrArg") ;
	Abort() ;

	}
	memcpy(mparrArg, parrArg, NumCols * sizeof(double));


	mparrVal = NULL ;
	mparrVal = new double[NumCols];
	if(mparrVal == NULL)
	{
	ShowMessage(L"Not memory for mparrVal") ;
	Abort() ;
	}
	memcpy(mparrVal, parrVal, NumCols * sizeof(double));
 }


  // ����� ������ 2
TTable_1D :: TTable_1D(const  double *parrPoints,  const int NumCols)

 {
	mNumCols = NumCols ;
	mparrArg = NULL ;
	mparrArg = new double[NumCols];
	if(mparrArg == NULL)
	{
	ShowMessage(L"Not memory for mparrArg") ;
	Abort() ;

	}

	mparrVal = NULL ;
	mparrVal = new double[NumCols];
	if(mparrVal == NULL)
	{
	ShowMessage(L"Not memory for mparrVal") ;
	Abort() ;
	}
	for (int i =0; i < NumCols; i++)
	{
	  mparrArg[i]= parrPoints[2 * i];
	  mparrVal[i] = parrPoints[2 * i + 1 ];
	}

 }

 double  TTable_1D ::calcValue(const double x)
 {
	 //TURPolyLine pln(mparrArg,mparrVal,mNumCols );
	// double x =  VAlArg;
	// return pln.LinearValueApprox(x) ;

	 if (mNumCols == 0)
	 {
	 return 0.;
	 }
   if (x < mparrArg[0])
   {
			return mparrVal[0];
   }

   if (x > mparrArg[mNumCols -1])
   {
		return mparrVal[mNumCols -1];
	 }
   ///
   double valReturn = -1.;                               // 11.01.2018
   for (int i =0; i < (mNumCols -1); i++)
   {
			if ((x - mparrArg[i])*(x - mparrArg[i +1]) <= 0.)
			{

				if (fabs(mparrArg[i] -  mparrArg[i +1])< 2.* DBL_MIN)
				{
				 valReturn =  (mparrVal[i] +  mparrVal[i +1]) /2.;
				 break;
				}

				double valTang  =  (mparrVal[i +1] -  mparrVal[i ] )/(mparrArg[i + 1] -  mparrArg[i]);  // 11.01.2018
				valReturn =  valTang * (x -  mparrArg[i]) + mparrVal[i ];                                     // 11.01.2018
				break;                                                                                    // 11.01.2018

			}
	 }

   return valReturn;
 }

 void TTable_1D::ShowMe(wchar_t *FileName)
{

   TURPolyLine line(mparrArg,mparrVal,mNumCols );
   line.WriteSetSHPFiles(FileName,&line, 1 ) ;

}

TURPolyLine  TTable_1D::createPln(const TTable_1D table)
{
 return TURPolyLine (table.mparrArg,table.mparrVal,table.mNumCols );
}
/*
void TTable_1D::calcBoundBox()
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
 */


#pragma package(smart_init)
