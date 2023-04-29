//---------------------------------------------------------------------------


#pragma hdrstop

#include "Equations.h"
#include "math.h"
#include <float.h>
#include <vcl.h>
#include "Comp.h"
const double EPS = 0.00000001;
//extern double PI;


//***********************************************************************************************
//********* ������� ��� DOUBLE**************************************************************************************
//***********************************************************************************************

// ������� ����������� ��������� a*x*x + b*x + c =0
// ����������
// 0 - 2 �������������� ��������� �����
// 1 - 2 �������������� ������� �����
// 2- ������� �� ������� ���� ���� ������� ������ a!= 0, c=0
// 3 - 2 ���������� ����������� �����
// 4 -  1 �������������� ������ (a =0)
// 5  - �������������� a=b=0, c!=0
// 6 - ��������� )a=b=c=0
int SolvEq2(const double a,const double b,const double c,TComp &x1,TComp &x2)
{
	x1.m_Re = 0;
	x1.m_Im = 0;
	x2.m_Re = 0;
	x2.m_Im = 0;
	if (fabs(a) < 0.000000000001)
	{
	  if (fabs(b) < 0.000000000001)
	  {
		if (fabs(c) < 0.000000000001) return 6; //��������� a=b=c=0

		return 5 ;  // �������������� a=b=0, c!=0
	  }
	  x1.m_Re = -c/b ;  // 1 �������������� ������ (a =0)
	  return 4 ;
	}
	if (fabs(c) < 0.000000000001)
	{
	  x1.m_Re = - b/a;
	 return 2;       // ������� �� ������� ���� ���� ������� ������ a!= 0, c=0
	}

	if(fabs(c) > DBL_MAX/10)
	{
		ShowMessage(L"fabs(c) > DBL_MAX/10");
		return 10;
    }
	double d2 = b * b - 4 * c * a ;
	if (d2 > DBL_MIN)
	{
	 double d = sqrt(d2);
	 x1.m_Re = (-b + d)/ 2/a ;
	 x2.m_Re = (-b - d)/ 2/a ;
	 return 0;

	}
	if (d2 < - DBL_MIN)
	{
	  x1.m_Re = x2.m_Re = -b/2./a ;
	  x1.m_Im = sqrt(-d2)/2./a ;
	  x2.m_Im = -x1.m_Im;
	  return 3;
	}
	x1.m_Re = x2.m_Re =  -b/2./a ;//sqrt(d2);
	return 1;

}

// ������� ����������� ��������� a*x*x + b*x + c =0
// ����������
// 0 - 2 ��������� �����
// 1 - 2  ������� �����
// 2- ������� �� ������� ���� ���� ������� ������ a!= 0, c=0

// 4 -  1  ������ (a =0)
// 5  - �������������� a=b=0, c!=0
// 6 - ��������� )a=b=c=0
int SolvEq2( TComp a, TComp b,  TComp c,TComp &x1,TComp &x2)
{
	x1.m_Re = 0;
	x1.m_Im = 0;
	x2.m_Re = 0;
	x2.m_Im = 0;
	TComp cmpMinus1(-1., 0.);
	if (a.modul() < 0.000000000001)
	{
	  if (b.modul() < 0.000000000001)
	  {
		if (c.modul() < 0.000000000001) return 6; //��������� a=b=c=0

		return 5 ;  // �������������� a=b=0, c!=0
	  }
	  x1 = cmpMinus1* c/b ;  // 1  ������ (a =0)
	  return 4 ;
	}
	if (c.modul() < 0.000000000001)
	{
	  x1 = cmpMinus1* b/a;
	  x2 = TComp(0.,0.);
	 return 2;       // ������� �� ������� ���� ���� ������� ������ a!= 0, c=0
	}

	if(c.modul() > DBL_MAX/10)
	{
		ShowMessage(L"c.modul() > DBL_MAX/10");
		return 10;
	}
	TComp cmp4(4., 0.);
	TComp cmp2(2., 0.);
	TComp d2 = b * b - cmp4 * c * a ;
	if (d2.modul() > DBL_MIN)
	{
	 TComp d = d2.Sqrt_();
	 x1 = ( d -b)/ cmp2/a ;
	 x2 = cmpMinus1 * (b +d)/ cmp2/a ;
	 return 0;

	}
	if (d2.modul()  < - DBL_MIN)
	{
	  x1 = cmpMinus1 * b/cmp2/a ;
	  x2 = x1 ;
	  return 1;
	}

  return 7;
}

/*  http://algolist.manual.ru/maths/findroot/cubic.php
Cubic equation solution. Real coefficients case.
  x3+a*x2+b*x+c=0.
   int Cubic(double *x,double a,double b,double c);
   Parameters:
   x - solution array (size 3). On output:
       3 real roots -> then x is filled with them;
       1 real + 2 complex -> x[0] is real, x[1] is real part of
                             complex roots, x[2] - non-negative
                             imaginary part.
   a, b, c - coefficients, as described
   Returns:
			3 - 3 real different roots;
			2 - 2 real root
			1 - 1 real root ;
			0 - 1 real root + 2 complex;


*/

// ����� ����������� �����  ������� arrKInp 3� 3


// arrLamb[3]  ������ ������ ���������
int   CalcProper_Numbers_R3(double * arrKInp, double *arrLamb)
{
	 // ������� ������������������� ��-� ��� �������  arrKInp


	 double a = - ( arrKInp [0] + arrKInp [4]  + arrKInp [8] ) ;
	 double b =  arrKInp [0] * arrKInp [4] +  arrKInp [0] * arrKInp [8] + arrKInp [4] * arrKInp [8]
			   - arrKInp [5] * arrKInp [5] - arrKInp [1] * arrKInp [1] - arrKInp [2] * arrKInp [2] ;
	 double c = -( arrKInp [0] * arrKInp [4]  * arrKInp [8] + 2 *  arrKInp [5] * arrKInp [1] * arrKInp [2]
			 - arrKInp [0] * arrKInp [5] * arrKInp [5] - arrKInp [8] * arrKInp [1] * arrKInp [1] - arrKInp [4] * arrKInp [2] * arrKInp [2]) ;


	return Cubic(arrLamb, a, b, c) ;
}


int Cubic(double *x,double a,double b,double c)
{
  if (fabs(c) < EPS)
  {
	c = 0 ;
	if (fabs(b) < EPS)
	{
		if (fabs( a )< EPS)
		{
		  // ��� ����� ����� 0
		  x [0] = 0. ;
		  x [1] = 0  ;
		  x [2] = 0 ;
		  return 1 ;
		}
	// ������� ��������� ��������� x * x * x + a * x * x = 0 , ���� 2 ������� �����
	   x [0] = 0. ;
	   x [1] = 0  ;
	   x [2] = -a ;
	   return 2 ;

	}
     // ������� ����� ��������� x * x * x + a * x * x  + b * x = 0, ���� ������� ������
	TComp x1,x2 ;
	switch(SolvEq2(1,a,b,x1,x2) )
	{
	   case 0:   // 0 - 2 �������������� ��������� �����
	   x [0] = 0. ;
	   x [1] = x1.m_Re  ;
	   x [2] = x2.m_Re ;
	   return 3 ;


	   case 1:  // 1 - 2 �������������� ������� �����
	   x [0] = 0. ;
	   x [1] = x1.m_Re  ;
	   x [2] = x [1] ;
	   return 2 ;


	   case 3:  // 3 - 2 ���������� ����������� �����
	   x [0] = 0. ;
	   x [1] = x1.m_Re  ;
	   x [2] = x1.m_Im ;
	   return 0 ;

	   default:
	   break;
    }


  }
  if (fabs(c) < EPS) c = 0 ;
  if (fabs(a) < EPS) a = 0 ;

 /* double q = ( a * a - 3 * b ) / 9. ;
  double r = ( 2 * a * a *a - 9 * a * b + 27 * c )/54.;
  double s = q * q * q - r * r ;  */
  double q = a/9. * a - b  / 3. ;
  double r =  a/ 27. * a *a -  a /6. * b +  c /2.;
  double s =  q - pow(fabs(r), 1/3.) * pow(fabs(r), 1/3.) ;

  if( fabs (s ) < EPS)
  {  // ��������� ���������
	 if (fabs (sqrt(q)< EPS ))
	 {    // ��������� ��������� � ����� 1 ������ ��������� 3
	   x[0] = - 2. * Sign(r) * sqrt (q) - a/ 3. ;
	   x[1] = x[0];
	   x[2] = x[0] ;
	   return 1 ;
	 }
	 else
	 {   // ��������� ��������� � ����� ������ ������ ��������� 2
	  x[0] = - 2. * Sign(r) * sqrt (q) - a/ 3. ;
	  x[1] = Sign(r) * sqrt (q) - a/ 3. ;
	  x[2] = x[1] ;
	  return 2 ;
	 }

  }
  else
  {    if (s > 0)
	   {   // 3 �������������� �����
		 double fi;// = acos(r / sqrt( q * q * q) )/ 3. ;
		 double temp = r / sqrt( q)/ sqrt( q) / sqrt(q);
		 if (temp > 0.999999999999999)
		 {
			fi = 0 ;
		 }
		 else
		 {
			 if (temp < -0.999999999999999)
			 {
			   fi = M_PI/3.;
			 }
			 else
			 {
			   fi = acos(temp )/ 3. ;
             }
         }
		 //double fi = acos(Sign( q ) * r / sqrt( fabs(q))/ sqrt( fabs(q)) / sqrt( fabs(q)) )/ 3. ;
		 x[0] = - 2. * sqrt( q) * cos (fi)  - a/ 3. ;
		 x[1] = - 2. * sqrt( q) * cos (fi + 2 * M_PI/3)  - a/ 3. ;
		 x[2] = - 2. * sqrt( q) * cos (fi - 2 * M_PI/3)  - a/ 3. ;
		return 3 ;

	   }
	   else
	   { //������ 2-� ����������� ������
		 if (fabs (q ) < EPS)
		 {
			x[0] = - pow(c - a * a * a / 27, 1./ 3.)  - a/ 3. ;
			x[1] =  - ( a + x[0])/2 ;
			x[2] = sqrt( fabs(( a - 3 * x [0]) * ( a + x [0]) - 4 * b)) / 2.;
		  return 1 ;
		 }
		 else
		 {
		   if (q > 0 )
		   {   // ?               ath.h?�m �������. � <
			 double t = fabs(r)/sqrt(q * q * q) ;
			 double fi = log( t + sqrt( t * t -1)) /3. ;
			 x[0] = - 2. * Sign(r) * sqrt(q) * cosh(fi) - a / 3. ;
			 x[1] =   Sign(r) * sqrt(q) * cosh(fi) - a / 3. ;
			 x[2] = sqrt(q * 3) * sinh(fi);

			   return 1 ;
		   }
		   else
		   {
			 double t = fabs(r)/sqrt(fabs(q * q * q))  ;
			 double fi = log( t + sqrt( t * t +1 )) /3. ;
			 x[0] = - 2. * Sign(r) * sqrt(fabs(q)) * sinh(fi) - a / 3. ;
			 x[1] =   Sign(r) * sqrt(fabs(q)) * sinh(fi) - a / 3. ;
			 x[2] = sqrt( fabs(q)  * 3) * cosh(fi);

			  return 1 ;
		   }
		  }

	   }

   }
}


// ������� ����������� ��������� � ������������ ��������������
//  a*z^3 + b * z^2 + c* z + d =0
// Input:
//cmpa, cmpb, cmpc, cmpd - ������������
// OUTPUT:
// cmparrZ[3] - ������ ������
// RETURN:
// 0 - 2 ��������� ����� (cmpa =0)
// 1 - 2  ������� �����  (cmpa =0)
// 2- ������� �� ������� ���� ���� ������� ������ (cmpa =0 cmpb!= 0, cmpd =0
// 4 -  1  ������ (cmpa =0, cmpb= 0)
// 5  - �������������� cmpa =0, cmpb= 0,cmpc =0, cmpd!=0
// 6 - ��������� cmpa =0, cmpb= 0,cmpc =0, cmpd =0
// 7 -  cmpa !=0, cmpb= 0,cmpc =0, cmpd =0 3 ������� �����
// 8 -  cmpa !=0, cmpb != 0,cmpc =0, cmpd =0 2 ������� ����� � ���� �� �������
// 9 - ������� ���� ������� ������
// 10 - ������� ��� ������� ������
// 11 - ������� 3 �����
int SolvEq3(TComp *cmparrZ,TComp cmpa,TComp cmpb,TComp cmpc,TComp cmpd)
{
   if (cmpa.modul()< EPS)
   {
		// ������� ����������� ��������� a*x*x + b*x + c =0
		// ����������
		// 0 - 2 ��������� �����
		// 1 - 2  ������� �����
		// 2- ������� �� ������� ���� ���� ������� ������ a!= 0, c=0

		// 4 -  1  ������ (a =0)
		// 5  - �������������� a=b=0, c!=0
		// 6 - ��������� )a=b=c=0
	  return   SolvEq2(  cmpb,  cmpc,   cmpd, cmparrZ[0],cmparrZ[1]);
   }
   TComp a = cmpb/ cmpa;
   TComp b = cmpc/ cmpa;
   TComp c = cmpd/ cmpa;
  if (c.modul() < EPS)
  {

	if (b.modul() < EPS)
	{
		if (a.modul()< EPS)
		{
		  // ��� ����� ����� 0
		  cmparrZ[0] = TComp(0.,0.);
		  cmparrZ[1] = TComp(0.,0.);
		  cmparrZ[2] = TComp(0.,0.);
		  return 7 ;
		}
	// ������� ��������� ��������� x * x * x + a * x * x = 0 , ���� 2 ������� �����
	   cmparrZ[0] = TComp(0.,0.);
	   cmparrZ[1] = TComp(0.,0.);
	   cmparrZ[2] = a * TComp(-1.,0.);
	   return 8 ;

	}
	 // ������� ����� ��������� x * x  + a * x  + b  = 0, ���� ������� ������
	TComp x1,x2 ;
	cmparrZ[0] = TComp(0.,0.);
	TComp cmp1(1.,0.);

		// 0 - 2 ��������� �����
		// 1 - 2  ������� �����
		// 2- ������� �� ������� ���� ���� ������� ������ a!= 0, c=0

		// 4 -  1  ������ (a =0) �� ����� ����
		// 5  - �������������� a=b=0, c!=0  �� ����� ����
		// 6 - ��������� )a=b=c=0    �� ����� ����
	switch(SolvEq2(cmp1,a,b,cmparrZ[1],cmparrZ[2]) )
	{
	   case 0:   // 0 - 2  ��������� �����
	   case 1:  // 1 - 2 � ������� �����
	   return 9 ;


	   case 2:  // 3 - 2 ���������� ����������� �����

	   return 10 ;

	   default:
	   return -1;
	 //  break;
    }


  }
 if (c.modul() < EPS) c = TComp(0.,0.) ;
 if (a.modul() < EPS) a = TComp(0.,0.) ;



  TComp p =  b  - a * a / TComp(3.,0.) ;
  TComp  q =  c - a * b / TComp(3.,0.) + TComp(2.,0.) * a *a*a/TComp(27.,0.);

  TComp alfCub(0.,0.), betCub(0.,0.);
  TComp discr = q * q / TComp(4.,0.) + p * p * p / TComp(27.,0.);
  TComp root = discr.Sqrt_() ;
  alfCub = q / TComp(-2.,0.) + root ;
  betCub = q / TComp(-2.,0.) - root ;

  TComp cmparrAlf[3],cmparrBet[3];
  alfCub.root3(cmparrAlf);
  betCub.root3(cmparrBet);

  // ����� ����� �����
  TComp cmpBet1;
  for (int i = 0; i < 3; i++)
  {
	TComp cmpT = cmparrAlf[0] * cmparrBet[i] + p / TComp(3.,0.);
	if (cmpT.modul() < EPS)
	{
	 cmpBet1 = cmparrBet[i];
	 break;
	}
  }
  TComp cmpEps (cos (2. * M_PI/ 3.), sin (2. * M_PI/ 3.));
   cmparrBet[0] = cmpBet1;
   cmparrAlf[1] = cmparrAlf[0] * cmpEps;
   cmparrAlf[2] = cmparrAlf[1] * cmpEps;
   cmparrBet[2] = cmparrBet[0] * cmpEps;
   cmparrBet[1] = cmparrBet[2] * cmpEps;

   // ����� ��������� ����������� ���������
   TComp cmparrX[3];
   for (int i = 0; i < 3; i++)
   {
	 cmparrX[i] = cmparrAlf[i] + cmparrBet[i];
   }
  ///

  // ����� ���������
  for (int i = 0; i < 3; i++)
   {
	 cmparrZ[i] = cmparrX[i] - a / TComp(3.,0.);
   }
  return 11;

}

double Sign(double a)
{
	if (fabs (a)< EPS) return 0;

	return (a > 0)?1:-1;
}

int fCompare (const void *e1, const void *e2)
{

	double *p1 =  (double*)e1 ;
	double *p2 =  (double*) e2 ;
	double e = (*p1) - (*p2) ;
	if (fabs (e) < EPS) return 0 ;
	 return ( e > 0 )?1 : -1;

}

//***********************************************************************************************
//********* ������� ��� LONG DOUBLE**************************************************************************************
//***********************************************************************************************
 // ������� ����������� ��������� a*x*x + b*x + c =0
// ����������
// 0 - 2 �������������� ��������� �����
// 1 - 2 �������������� ������� �����
// 2- ������� �� ������� ���� ���� ������� ������ a!= 0, c=0
// 3 - 2 ���������� ����������� �����
// 4 -  1 �������������� ������ (a =0)
// 5  - �������������� a=b=0, c!=0
// 6 - ��������� )a=b=c=0
int SolvEq2(const long double a,const long double b,const long double c,TCompLong &x1,TCompLong &x2)
{
	x1.m_Re = 0;
	x1.m_Im = 0;
	x2.m_Re = 0;
	x2.m_Im = 0;
	if (fabsl(a) < 0.000000000001)
	{
	  if (fabsl(b) < 0.000000000001)
	  {
		if (fabsl(c) < 0.000000000001) return 6; //��������� a=b=c=0

		return 5 ;  // �������������� a=b=0, c!=0
	  }
	  x1.m_Re = -c/b ;  // 1 �������������� ������ (a =0)
	  return 4 ;
	}
	if (fabsl(c) < 0.000000000001)
	{
	  x1.m_Re = - b/a;
	 return 2;       // ������� �� ������� ���� ���� ������� ������ a!= 0, c=0
	}

	if(fabsl(c) > DBL_MAX/10)
	{
		ShowMessage(L"fabsl(c) > DBL_MAX/10");
		return 10;
    }
	long double d2 = b * b - 4 * c * a ;
	if (d2 > DBL_MIN)
	{
	 long double d = sqrtl(d2);
	 x1.m_Re = (-b + d)/ 2/a ;
	 x2.m_Re = (-b - d)/ 2/a ;
	 return 0;

	}
	if (d2 < - DBL_MIN)
	{
	  x1.m_Re = x2.m_Re = -b/2/a ;
	  x1.m_Im = sqrtl(-d2);
	  x2.m_Im = -x1.m_Im;
	  return 3;
	}
	x1.m_Re = x2.m_Re =  -b/2/a ;//sqrt(d2);
	return 1;

}



/*  http://algolist.manual.ru/maths/findroot/cubic.php
Cubic equation solution. Real coefficients case.
  x3+a*x2+b*x+c=0.
   int Cubic(long double *x,long double a,long double b,long double c);
   Parameters:
   x - solution array (size 3). On output:
       3 real roots -> then x is filled with them;
       1 real + 2 complex -> x[0] is real, x[1] is real part of
                             complex roots, x[2] - non-negative
                             imaginary part.
   a, b, c - coefficients, as described
   Returns:
			3 - 3 real different roots;
			2 - 2 real root
			1 - 1 real root ;
			0 - 1 real root + 2 complex;


*/

// ����� ����������� �����  ������� arrKInp 3� 3


// arrLamb[3]  ������ ������ ���������
int   CalcProper_Numbers_R3(long double * arrKInp, long double *arrLamb)
{
	 // ������� ������������������� ��-� ��� �������  arrKInp


	 long double a = - ( arrKInp [0] + arrKInp [4]  + arrKInp [8] ) ;
	 long double b =  arrKInp [0] * arrKInp [4] +  arrKInp [0] * arrKInp [8] + arrKInp [4] * arrKInp [8]
			   - arrKInp [5] * arrKInp [5] - arrKInp [1] * arrKInp [1] - arrKInp [2] * arrKInp [2] ;
	 long double c = -( arrKInp [0] * arrKInp [4]  * arrKInp [8] + 2 *  arrKInp [5] * arrKInp [1] * arrKInp [2]
			 - arrKInp [0] * arrKInp [5] * arrKInp [5] - arrKInp [8] * arrKInp [1] * arrKInp [1] - arrKInp [4] * arrKInp [2] * arrKInp [2]) ;


	return Cubic(arrLamb, a, b, c) ;
}


int Cubic(long double *x,long double a,long double b,long double c)
{
  if (fabsl(c) < EPS)
  {
	c = 0 ;
	if (fabsl(b) < EPS)
	{
		if (fabsl( a )< EPS)
		{
		  // ��� ����� ����� 0
		  x [0] = 0. ;
		  x [1] = 0  ;
		  x [2] = 0 ;
		  return 1 ;
		}
	// ������� ��������� ��������� x * x * x + a * x * x = 0 , ���� 2 ������� �����
	   x [0] = 0. ;
	   x [1] = 0  ;
	   x [2] = -a ;
	   return 2 ;

	}
     // ������� ����� ��������� x * x * x + a * x * x  + b * x = 0, ���� ������� ������
	TCompLong x1,x2 ;
	switch(SolvEq2(1,a,b,x1,x2) )
	{
	   case 0:   // 0 - 2 �������������� ��������� �����
	   x [0] = 0. ;
	   x [1] = x1.m_Re  ;
	   x [2] = x2.m_Re ;
	   return 3 ;

	   case 1:  // 1 - 2 �������������� ������� �����
	   x [0] = 0. ;
	   x [1] = x1.m_Re  ;
	   x [2] = x [1] ;
	   return 2 ;


	   case 3:  // 3 - 2 ���������� ����������� �����
	   x [0] = 0. ;
	   x [1] = x1.m_Re  ;
	   x [2] = x1.m_Im ;
	   return 0 ;

	   default:
	   break;
    }


  }
  if (fabsl(c) < EPS) c = 0 ;
  if (fabsl(a) < EPS) a = 0 ;

 /* long double q = ( a * a - 3 * b ) / 9. ;
  long double r = ( 2 * a * a *a - 9 * a * b + 27 * c )/54.;
  long double s = q * q * q - r * r ;  */
  long double q = a/9. * a - b  / 3. ;
  long double r =  a/ 27. * a *a -  a /6. * b +  c /2.;
  long double s =  q - powl(fabsl(r), 1/3.) * powl(fabsl(r), 1/3.) ;

  if( fabsl (s ) < EPS)
  {  // ��������� ���������
	 if (fabs (sqrtl(q)< EPS ))
	 {    // ��������� ��������� � ����� 1 ������ ��������� 3
	   x[0] = - 2. * Sign(r) * sqrtl (q) - a/ 3. ;
	   x[1] = x[0];
	   x[2] = x[0] ;
	   return 1 ;
	 }
	 else
	 {   // ��������� ��������� � ����� ������ ������ ��������� 2
	  x[0] = - 2. * Sign(r) * sqrtl (q) - a/ 3. ;
	  x[1] = Sign(r) * sqrtl (q) - a/ 3. ;
	  x[2] = x[1] ;
	  return 2 ;
	 }

  }
  else
  {    if (s > 0)
	   {   // 3 �������������� �����
		 long double fi;// = acos(r / sqrt( q * q * q) )/ 3. ;
		 long double temp = r / sqrtl( q)/ sqrtl( q) / sqrtl(q);
		 if (temp > 0.999999999999999)
		 {
			fi = 0 ;
		 }
		 else
		 {
			 if (temp < -0.999999999999999)
			 {
			   fi = M_PI/3.;
			 }
			 else
			 {
			   fi = acosl(temp )/ 3. ;
             }
         }
		 //long double fi = acos(Sign( q ) * r / sqrt( fabs(q))/ sqrt( fabs(q)) / sqrt( fabs(q)) )/ 3. ;
		 x[0] = - 2. * sqrtl( q) * cosl (fi)  - a/ 3. ;
		 x[1] = - 2. * sqrtl( q) * cosl (fi + 2 * M_PI/3)  - a/ 3. ;
		 x[2] = - 2. * sqrtl( q) * cosl (fi - 2 * M_PI/3)  - a/ 3. ;
		return 3 ;

	   }
	   else
	   { //������ 2-� ����������� ������
		 if (fabsl (q ) < EPS)
		 {
			x[0] = - powl(c - a * a * a / 27, 1./ 3.)  - a/ 3. ;
			x[1] =  - ( a + x[0])/2 ;
			x[2] = sqrtl( fabsl(( a - 3 * x [0]) * ( a + x [0]) - 4 * b)) / 2.;
		  return 1 ;
		 }
		 else
		 {
		   if (q > 0 )
		   {   // ?               ath.h?�m �������. � <
			 long double t = fabsl(r)/sqrtl(q * q * q) ;
			 long double fi = logl( t + sqrtl( t * t -1)) /3. ;
			 x[0] = - 2. * Sign(r) * sqrtl(q) * coshl(fi) - a / 3. ;
			 x[1] =   Sign(r) * sqrtl(q) * coshl(fi) - a / 3. ;
			 x[2] = sqrtl(q * 3) * sinhl(fi);

			   return 1 ;
		   }
		   else
		   {
			 long double t = fabsl(r)/sqrtl(fabsl(q * q * q))  ;
			 long double fi = logl( t + sqrtl( t * t +1 )) /3. ;
			 x[0] = - 2. * Sign(r) * sqrtl(fabsl(q)) * sinhl(fi) - a / 3. ;
			 x[1] =   Sign(r) * sqrtl(fabs(q)) * sinhl(fi) - a / 3. ;
			 x[2] = sqrtl( fabsl(q)  * 3) * coshl(fi);

			  return 1 ;
		   }
		  }

	   }

   }
}

long double Sign(long double a)
{
	if (fabsl (a)< EPS) return 0;

	return (a > 0)?1:-1;
}
#pragma package(smart_init)
