//---------------------------------------------------------------------------

#pragma hdrstop
#include <vcl.h>
#include "Target.h"
#include <string.h>
#include <math.h>
#include <dir.h>
#include "MatrixProccess.h"
#include "YrWriteShapeFile.h"
#include "Circle.h"




const int QUANT_COLS_BUFF_TARGET = 7;


// �������� ��������� ������������ � Y==1
const TURPointXY  constPnt1(0., 1.);
const TURPointXY  constPnt2(100000., 1.);
//extern TURPolyLine PLnGladk11 ( constPnt1, constPnt2) ;


//��� B, ������,300 �/c
 double arrP_Glad_Garpun300[12]={0.,0.2,0.4,0.6,0.74,0.8,0.86,0.9,0.94,0.96,0.99,1};
 double arr_Dal_Garpun300[12]={0.,300,460,600,800,1000,1250,1500,1750,2000,2500,2660};
// TURPolyLine PLnGladk_Garpun300 (arr_Dal_Garpun300, arrP_Glad_Garpun300, 12) ;
// extern TURPolyLine PLnGladk_Garpun300 (arr_Dal_Garpun300, arrP_Glad_Garpun300, 12) ;
///


 //��� B, ������,700 �/c
 double arrP_Glad_Garpun700[16]={0,0.04,0.1,0.14,0.25,0.26,0.44,0.52,0.62,0.68,0.78,0.8,0.844,0.94,0.96,1};
 double arr_Dal_Garpun700[16]={0,300,460,600,800,1000,1250,1500,1750,2000,2500,2660,3000,4000,5000,6000};
// TURPolyLine PLnGladk_Garpun700 (arr_Dal_Garpun700, arrP_Glad_Garpun700,16) ;
//


// 1.������� �11
int NumPartsPlgC11 = 1 ;
int NumPointsPlgC11 = 5  ;

double PointsPlgC11[10] = {
-3.020081 , 0.183289
, -1.980103 , 0.183289
, -1.980103 , -0.182983
, -3.020081 , -0.183105
, -3.020081 , 0.183289
};

int PartsPlgC11 [1] = {0};

double arrS0_C11[3] = {0.}; // ���������� ������ ���
double arrF_C11[9] = { 1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
										 };
enumTypeTargBody enumTypeTargBody_C11 =  AXIALLY_SYMMETRICAL_BODY;

TURPolygon plgC11 (NumPartsPlgC11,NumPointsPlgC11,  PartsPlgC11, PointsPlgC11);
TPlanePolygon PlanePlgC11( arrS0_C11, arrF_C11, plgC11,  enumTypeTargBody_C11) ;
///

// 2.������� �12
int NumPartsPlgC12 = 1 ;
int NumPointsPlgC12 = 13 ;

double PointsPlgC12[13 * 2] = {
-3.440125 , 0.183289
, -3.440125 , -0.183105
, -3.473511 , -0.183105
, -3.564087 , -0.320007
, -3.789307 , -0.320007
, -3.764099 , -0.188721
, -3.802490 , -0.169495
, -3.802490 , 0.169678
, -3.764099 , 0.188721
, -3.789307 , 0.320129
, -3.564087 , 0.320129
, -3.473511 , 0.183289
, -3.440125 , 0.183289
};
int PartsPlgC12 [1] = {0};


double arrS0_C12[3] = {0.}; // ���������� ������ ���
double arrF_C12[9] = { 1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											};
enumTypeTargBody enumTypeTargBody_C12 =  AXIALLY_SYMMETRICAL_BODY;

TURPolygon plgC12 (NumPartsPlgC12,NumPointsPlgC12,  PartsPlgC12, PointsPlgC12);
TPlanePolygon PlanePlgC12( arrS0_C12, arrF_C12, plgC12,  enumTypeTargBody_C12) ;

///


// 3.������� �13 _1
int NumPartsPlgC13_1 = 1 ;
int NumPointsPlgC13_1 = 6 ;
double PointsPlgC13_1[12] = {
  -1.990112 , -0.109985
, -1.990112 , -0.320190
, -2.377075 , -0.320007
, -2.410095 , -0.228394
, -2.410095 , -0.109985
, -1.990112 , -0.109985
												 };
int PartsPlgC13_1 [1] = {0};


double arrS0_C13_1[3] = {0.}; // ���������� ������ ���
double arrF_C13_1[9] = { 1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_C13_1 =  PLANE_BODY;

TURPolygon plgC13_1 (NumPartsPlgC13_1,NumPointsPlgC13_1,  PartsPlgC13_1, PointsPlgC13_1);
TPlanePolygon PlanePlgC13_1( arrS0_C13_1, arrF_C13_1, plgC13_1,  enumTypeTargBody_C13_1) ;

///
 // 4.������� �13_2
int NumPartsPlgC13_2  = 1 ;
int NumPointsPlgC13_2 = 6 ;
double PointsPlgC13_2[12] = {
 -1.990112 , 0.110107
, -2.410095 , 0.110107
, -2.410095 , 0.228699
, -2.377075 , 0.320129
, -1.990112 , 0.320129
, -1.990112 , 0.110107
};
int PartsPlgC13_2 [1] = {0};


double arrS0_C13_2[3] = {0.}; // ���������� ������ ���
double arrF_C13_2[9] = { 1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_C13_2 =  PLANE_BODY;

TURPolygon plgC13_2 (NumPartsPlgC13_2,NumPointsPlgC13_2,  PartsPlgC13_2, PointsPlgC13_2);
TPlanePolygon PlanePlgC13_2( arrS0_C13_2, arrF_C13_2, plgC13_2,  enumTypeTargBody_C13_2) ;


//5. ������� �14_1 (C13 ������������)
int NumPartsPlgC14_1 = 1 ;
int NumPointsPlgC14_1 = 6 ;
double PointsPlgC14_1[12] = {
 -1.990112 , -0.109985
, -1.990112 , -0.320190
, -2.377075 , -0.320007
, -2.410095 , -0.228394
, -2.410095 , -0.109985
, -1.990112 , -0.109985

};
int PartsPlgC14_1 [1] = {0};


double arrS0_C14_1[3] = {0.}; // ���������� ������ ���
double arrF_C14_1[9] = { 1.,0.,0.
											 ,0.,0.,-1.
											 ,0.,1.,0.
											};
enumTypeTargBody enumTypeTargBody_C14_1 =  PLANE_BODY;

TURPolygon plgC14_1 (NumPartsPlgC14_1,NumPointsPlgC14_1,  PartsPlgC14_1, PointsPlgC14_1);
TPlanePolygon PlanePlgC14_1( arrS0_C14_1, arrF_C14_1, plgC14_1,  enumTypeTargBody_C14_1) ;

///
//6. ������� �14 (C13 ������������)
int NumPartsPlgC14_2 = 1 ;
int NumPointsPlgC14_2 = 6 ;
double PointsPlgC14_2[12] = {
 -1.990112 , 0.110107
, -2.410095 , 0.110107
, -2.410095 , 0.228699
, -2.377075 , 0.320129
, -1.990112 , 0.320129
, -1.990112 , 0.110107
};
int PartsPlgC14_2 [1] = {0};


double arrS0_C14_2[3] = {0.}; // ���������� ������ ���
double arrF_C14_2[9] = { 1.,0.,0.
											 ,0.,0.,-1.
											 ,0.,1.,0.
											};
enumTypeTargBody enumTypeTargBody_C14_2 =  PLANE_BODY;

TURPolygon plgC14_2 (NumPartsPlgC14_2,NumPointsPlgC14_2,  PartsPlgC14_2, PointsPlgC14_2);
TPlanePolygon PlanePlgC14_2( arrS0_C14_2, arrF_C14_2, plgC14_2,  enumTypeTargBody_C14_2) ;

///

//7.������� �61
int NumPartsPlgC61 = 1 ;
int NumPointsPlgC61 = 7 ;

double PointsPlgC61[14] = {
-0.260071 , 0.092896
, -0.260071 , -0.092712
, -0.513123 , -0.183105
, -0.900085 , -0.183105
, -0.900085 , 0.183289
, -0.513123 , 0.183289
, -0.260071 , 0.092896
};
int PartsPlgC61 [1] = {0};

double arrS0_C61[3] = {0.}; // ���������� ������ ���
double arrF_C61[9] = { 1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_C61=  AXIALLY_SYMMETRICAL_BODY;

TURPolygon plgC61 (NumPartsPlgC61,NumPointsPlgC61,  PartsPlgC61, PointsPlgC61);
TPlanePolygon PlanePlgC61( arrS0_C61, arrF_C61, plgC61,  enumTypeTargBody_C61) ;

///

//8. ������� �62
int NumPartsPlgC62 = 1 ;
int NumPointsPlgC62 =  11 ;

double PointsPlgC62[22] = {
-3.570129 , -0.328979
, -3.663086 , -0.469727
, -3.816895 , -0.464905
, -3.764099 , -0.188721
, -3.802490 , -0.169495
, -3.802490 , 0.169678
, -3.764099 , 0.188721
, -3.816895 , 0.464905
, -3.663086 , 0.469727
, -3.570129 , 0.329102
, -3.570129 , -0.328979
};

int PartsPlgC62 [1] = {0};

double arrS0_C62[3] = {0.}; // ���������� ������ ���
double arrF_C62[9] = { 1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_C62 =  AXIALLY_SYMMETRICAL_BODY;

TURPolygon plgC62 (NumPartsPlgC62,NumPointsPlgC62,  PartsPlgC62, PointsPlgC62);
TPlanePolygon PlanePlgC62( arrS0_C62, arrF_C62, plgC62,  enumTypeTargBody_C62) ;

///


// 9.������� �71
int NumPartsPlgC71 =  1 ;
int NumPointsPlgC71 =  5 ;

double PointsPlgC71[10] = {
-3.160095 , -0.183105
, -3.440125 , -0.183105
, -3.440125 , 0.183289
, -3.160095 , 0.183289
, -3.160095 , -0.183105
};
int PartsPlgC71 [1] = {0};

double arrS0_C71[3] = {0.}; // ���������� ������ ���
double arrF_C71[9] = { 1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_C71 =  PLANE_BODY;

TURPolygon plgC71 (NumPartsPlgC71,NumPointsPlgC71,  PartsPlgC71, PointsPlgC71);
TPlanePolygon PlanePlgC71( arrS0_C71, arrF_C71, plgC71,  enumTypeTargBody_C71) ;

///


// 10.������� �71VertLeft
int NumPartsPlgC71VertLeft =  1;
int NumPointsPlgC71VertLeft =  5 ;

double PointsPlgC71VertLeft[10] = {
-3.160095 , -0.109985
, -3.440125 , -0.109985
, -3.440125 , 0.110107
, -3.160095 , 0.110107
, -3.160095 , -0.109985
};
int PartsPlgC71VertLeft [1] = {0};
double arrS0_C71VertLeft[3] = {0.,0., 0.21}; // ���������� ������ ���
double arrF_C71VertLeft[9] = { 1.,0.,0.
															,0.,0.,-1.
															,0.,1.,0.
														};
enumTypeTargBody enumTypeTargBody_C71VertLeft =  PLANE_BODY;

TURPolygon plgC71VertLeft (NumPartsPlgC71VertLeft,NumPointsPlgC71VertLeft,  PartsPlgC71VertLeft, PointsPlgC71VertLeft);
TPlanePolygon PlanePlgC71VertLeft( arrS0_C71VertLeft, arrF_C71VertLeft, plgC71VertLeft,  enumTypeTargBody_C71VertLeft) ;
///

// 11.������� �71VertRight
int NumPartsPlgC71VertRight =  1;
int NumPointsPlgC71VertRight =  5 ;

double PointsPlgC71VertRight[10] = {
-3.160095 , -0.109985
, -3.440125 , -0.109985
, -3.440125 , 0.110107
, -3.160095 , 0.110107
, -3.160095 , -0.109985
};
int PartsPlgC71VertRight [1] = {0};
double arrS0_C71VertRight[3] = {0.,0., -0.21}; // ���������� ������ ���
double arrF_C71VertRight[9] = { 1.,0.,0.
															,0.,0.,-1.
															,0.,1.,0.
														};
enumTypeTargBody enumTypeTargBody_C71VertRight =  PLANE_BODY;

TURPolygon plgC71VertRight (NumPartsPlgC71VertRight,NumPointsPlgC71VertRight,  PartsPlgC71VertRight, PointsPlgC71VertRight);
TPlanePolygon PlanePlgC71VertRight( arrS0_C71VertRight, arrF_C71VertRight, plgC71VertRight,  enumTypeTargBody_C71VertRight) ;
///

// 12.������� �21
int NumPartsPlgC21 =  1;
int NumPointsPlgC21 =  5 ;

double PointsPlgC21[10] = {
   -1.9 , -0.12
, -1.9 ,   0.12
, -1. ,    0.12
, -1. ,   -0.12
, -1.9 , -0.12
};
int PartsPlgC21 [1] = {0};
double arrS0_C21[3] = {0.,0., 0.}; // ���������� ������ ���
double arrF_C21[9] ={ 1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_C21 =   AXIALLY_SYMMETRICAL_BODY;

TURPolygon plgC21 (NumPartsPlgC71VertRight,NumPointsPlgC21,  PartsPlgC21, PointsPlgC21);
TPlanePolygon PlanePlgC21( arrS0_C21, arrF_C21, plgC21,  enumTypeTargBody_C21) ;
///

// 13.������� KUKUN
int NumPartsPlgKUKUN =  1;
int NumPointsPlgKUKUN =  22  ;

double PointsPlgKUKUN[44] = {
-0.000000 , 0.000000
, -0.513058 , -0.183193
, -1.890651 , -0.183193
, -2.075503 , -0.438547
, -2.330138 , -0.450543
, -2.426197 , -0.183193
, -3.473423 , -0.183193
, -3.663099 , -0.469742
, -3.816819 , -0.464919
, -3.763982 , -0.188736
, -3.802443 , -0.169537
, -3.802443 , 0.169537
, -3.763982 , 0.188736
, -3.816819 , 0.464919
, -3.663099 , 0.469742
, -3.473423 , 0.183193
, -2.426197 , 0.183193
, -2.330138 , 0.450543
, -2.075503 , 0.438547
, -1.890651 , 0.183193
, -0.513058 , 0.183193
, -0.000000 , 0.000000

};
int PartsPlgKUKUN [1] = {0};
double arrS0_KUKUN[3] = {0.,0., 0.}; // ���������� ������ ���
double arrF_KUKUN[9] ={ 1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_KUKUN =   AXIALLY_SYMMETRICAL_BODY;

TURPolygon plgKUKUN (NumPartsPlgKUKUN,NumPointsPlgKUKUN,  PartsPlgKUKUN, PointsPlgKUKUN);
TPlanePolygon PlanePlgKUKUN( arrS0_KUKUN, arrF_KUKUN, plgKUKUN,  enumTypeTargBody_KUKUN) ;


// 14. ������� KUKUN  FACE

const TURPointXY pointCentre_FaceKukun(0.,0.);
const double VAlR_FaceKukun = 0.26;
const int iNUM_FaceKukun = 20;
TCircle Circle_FaceKukun(pointCentre_FaceKukun, VAlR_FaceKukun);
TURPolygon plg_FaceKukun(Circle_FaceKukun , iNUM_FaceKukun) ;

double arrS0_FaceKukun[3] = {0.,0., 0.}; // ���������� ������ ���
double arrF_FaceKukun[9] = { 0.,0.,1.
													 ,1.,0.,0.
													 ,0.,1.,0.
													 };
enumTypeTargBody enumTypeTargBody_FaceKukun =   PLANE_BODY;


TPlanePolygon PlanePlg_FaceKukun( arrS0_FaceKukun, arrF_FaceKukun, plg_FaceKukun,  enumTypeTargBody_FaceKukun) ;

// 15. ������� Nose
int NumPartsPlgNOSE =  1;
int NumPointsPlgNOSE =  4  ;

double PointsPlgNOSE[8] = {
-0.000000 , 0.000000
,-0.260071 , -0.092896
,-0.260071 , 0.092896
-0.000000 , 0.000000

};
int PartsPlgNOSE [1] = {0};
double arrS0_NOSE[3] = {0.,0., 0.}; // ���������� ������ ���
double arrF_NOSE[9] ={ 1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_NOSE =   AXIALLY_SYMMETRICAL_BODY;

TURPolygon plgNOSE (NumPartsPlgNOSE,NumPointsPlgNOSE,  PartsPlgNOSE, PointsPlgNOSE);
TPlanePolygon PlanePlgNOSE( arrS0_NOSE, arrF_NOSE, plgNOSE,  enumTypeTargBody_NOSE) ;

//---------------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////
///////// F14 ////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
// 1. ��� ������
 int NumPartsPlgF14Krilo =  1 ;
 int NumPointsPlgF14Krilo = 38 ;

double PointsPlgF14Krilo[38*2] ={
 9.430115 , 0.000000
, 7.082275 , -0.373718
, 3.465515 , -0.580505
, 3.410278 , -1.574585
, 2.250916 , -1.629700
, -1.560181 , -3.396790
, -6.254089 , -8.174316
, -7.441895 , -7.980591
, -4.597473 , -2.209595
, -5.287781 , -2.237427
, -8.712097 , -5.053894
, -9.623108 , -4.750122
, -9.070984 , -2.347778
, -8.546082 , -2.098877
, -8.214905 , -2.016602
, -8.739807 , -1.712585
, -8.684326 , -1.104797
, -8.159912 , -0.856506
, -9.429993 , -0.414612
, -9.429993 , 0.414673
, -8.159912 , 0.856506
, -8.684326 , 1.104919
, -8.739807 , 1.712708
, -8.214905 , 2.016724
, -8.546082 , 2.098877
, -9.070984 , 2.347900
, -9.623108 , 4.750122
, -8.712097 , 5.054077
, -5.287781 , 2.237488
, -4.597473 , 2.209717
, -7.441895 , 7.980713
, -6.254089 , 8.174316
, -1.560181 , 3.396912
, 2.250916 , 1.629883
, 3.410278 , 1.574707
, 3.465515 , 0.580505
, 7.331482 , 0.359497
, 9.430115 , 0.000000
};


int PartsPlgF14Krilo[1] = {0};



double arrS0_F14Krilo[3] = { 0.,0., 0.}; // ���������� ������ ���
double arrF_F14Krilo[9] ={1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_F14Krilo =   PLANE_BODY;

TURPolygon plgTypeF14Krilo (NumPartsPlgF14Krilo,NumPointsPlgF14Krilo,  PartsPlgF14Krilo, PointsPlgF14Krilo);
TPlanePolygon PlanePlgF14Krilo( arrS0_F14Krilo, arrF_F14Krilo, plgTypeF14Krilo,  enumTypeTargBody_F14Krilo) ;
///
//--------------------------------------------------------------------
// 2. ��� ����� (���)
int NumPartsPlgF14Fas =  1 ;
int NumPointsPlgF14Fas =  25 ;

double PointsPlgF14Fas[50] ={
9.430000 , 0.564520
, 8.230507 , 0.192122
, 6.008779 , -0.093072
, 3.289781 , 0.012649
, -4.429608 , -0.180276
, -4.473764 , -0.180751
, -4.868320 , -0.707141
, -7.587475 , 0.038605
, -8.859612 , 0.126284
, -8.859612 , 1.134908
, -9.430000 , 3.810383
, -8.421375 , 3.722704
, -5.526545 , 1.310266
, -4.473764 , 1.485466
, -3.728018 , 1.573620
, -2.631556 , 1.704822
, -1.227743 , 1.661299
, 0.087916 , 1.836657
, 1.491730 , 2.363047
, 2.982747 , 2.538247
, 4.167204 , 2.538247
, 5.483022 , 2.187689
, 6.754525 , 1.397787
, 8.289699 , 1.178431
, 9.430000 , 0.564520
};


int PartsPlgF14Fas[1] = {0};

double arrS0_F14Fas[3] = { 0.,0., 0.}; // ���������� ������ ���
double arrF_F14Fas[9] ={1.,0.,0.
					   ,0.,0.,-1.
					   ,0.,1.,0.
					   };
enumTypeTargBody enumTypeTargBody_F14Fas =   PLANE_BODY;

TURPolygon plgTypeF14Fas (NumPartsPlgF14Fas,NumPointsPlgF14Fas,  PartsPlgF14Fas, PointsPlgF14Fas);
TPlanePolygon PlanePlgF14Fas( arrS0_F14Fas, arrF_F14Fas, plgTypeF14Fas,  enumTypeTargBody_F14Fas) ;
//---------------------------------------------------------------------------------
// 3. ��� �������(���)


int NumPartsPlgF14Nos =  1 ;
int NumPointsPlgF14Nos =  98 ;
double PointsPlgF14Nos[98 *2] ={
-8.289205 , 0.501246
, -8.176618 , 0.690533
, -7.927679 , 0.847819
, -7.520572 , 0.926192
, -7.044510 , 0.974191
, -6.637013 , 1.006191
, -6.229907 , 1.006191
, -5.957983 , 1.006191
, -5.776830 , 1.006191
, -5.641647 , 1.211206
, -5.527891 , 1.446865
, -5.437119 , 1.604151
, -5.323753 , 1.841437
, -5.188180 , 2.061638
, -5.007028 , 2.282924
, -4.825875 , 2.472210
, -4.599921 , 2.691870
, -4.350982 , 2.913156
, -4.079058 , 2.991257
, -3.739347 , 3.102170
, -3.399637 , 3.148543
, -2.991362 , 3.180543
, -2.654378 , 3.140408
, -2.290514 , 3.038442
, -2.018590 , 2.913156
, -1.701865 , 2.770784
, -1.415916 , 2.613497
, -1.202818 , 2.456210
, -0.818696 , 2.629497
, -0.466130 , 2.774309
, -0.124083 , 2.851597
, 0.331721 , 2.865970
, 0.639097 , 2.825834
, 1.038802 , 2.755869
, 1.378512 , 2.675870
, 1.651605 , 2.467871
, 1.785619 , 2.345297
, 2.057543 , 2.613497
, 2.464650 , 2.770784
, 2.759559 , 2.881156
, 3.008498 , 2.976070
, 3.461575 , 3.070442
, 3.846086 , 3.102170
, 4.193198 , 3.078307
, 4.525117 , 3.007256
, 4.841842 , 2.865156
, 5.045980 , 2.739869
, 5.250118 , 2.486583
, 5.431271 , 2.234924
, 5.611255 , 1.998724
, 5.725011 , 1.699065
, 5.792797 , 1.352492
, 5.883179 , 1.115478
, 5.996935 , 0.863819
, 6.313660 , 0.847819
, 6.675966 , 0.816905
, 6.901920 , 0.816905
, 7.173844 , 0.816905
, 7.422783 , 0.800905
, 7.740677 , 0.768905
, 8.034417 , 0.706532
, 8.170769 , 0.627618
, 8.222193 , 0.460569
, 8.012601 , 0.186673
, 7.694707 , 0.043760
, 7.287600 , -0.034613
, 6.924905 , -0.081527
, 6.494813 , -0.113527
, 6.064721 , -0.129527
, 5.702026 , -0.159900
, 5.317904 , -0.191899
, 3.438590 , -0.050613
, 1.581481 , 0.013387
, 1.060618 , -0.790674
, 0.630136 , -1.311346
, 0.216796 , -1.522870
, -0.274848 , -1.516632
, -0.818696 , -1.295346
, -1.044651 , -1.043146
, -1.339560 , -0.633387
, -1.565514 , -0.175900
, -1.701865 , -0.065527
, -2.493484 , -0.065527
, -3.014347 , -0.065527
, -3.422622 , -0.113527
, -3.920500 , -0.175900
, -4.418378 , -0.159900
, -4.848860 , -0.145527
, -5.255967 , -0.145527
, -5.663074 , -0.129527
, -6.116540 , -0.097527
, -6.478846 , -0.002613
, -6.841541 , 0.059759
, -7.293449 , 0.107759
, -7.701725 , 0.170673
, -8.018450 , 0.233046
, -8.267389 , 0.359960
, -8.289205 , 0.501246
 };

int PartsPlgF14Nos[1] = {0};

double arrS0_F14Nos[3] = { 0.,0., 0.}; // ���������� ������ ���
double arrF_F14Nos[9] ={0.,0.,1.
						,1.,0.,0.
						,0.,1.,0.
						};
enumTypeTargBody enumTypeTargBody_F14Nos =   PLANE_BODY;

TURPolygon plgTypeF14Nos (NumPartsPlgF14Nos,NumPointsPlgF14Nos,  PartsPlgF14Nos, PointsPlgF14Nos);
TPlanePolygon PlanePlgF14Nos( arrS0_F14Nos, arrF_F14Nos, plgTypeF14Nos,  enumTypeTargBody_F14Nos) ;
///



///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
//////      ARLEIGHT BERK                /////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

		 const double VAl_ARLEIGHT_BERK_BoardX = 153.6;
		 const double VAl_ARLEIGHT_BERK_BoardY = 18.6;
		 const double  VAl_ARLEIGHT_BERK_BoardH = 8.9;
		 const double VAl_ARLEIGHT_BERK_StructureX = 60.;
		 const double VAl_ARLEIGHT_BERK_StructureY = 10.;
		 const double VAl_ARLEIGHT_BERK_StructureH = 9.;
		 const double VAl_ARLEIGHT_BERK_SdvgStructureX = 4.8;

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
//////      ����� ��������� ������ 143    ������            /////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
		 const double VAl_PROJECT_143_BoardX = 38.7;
		 const double VAl_PROJECT_143_BoardY = 7.6;
		 const double  VAl_PROJECT_143_BoardH = 2;
		 const double VAl_PROJECT_143_StructureX = 15.;
		 const double VAl_PROJECT_143_StructureY = 4.;
		 const double VAl_PROJECT_143_StructureH = 3.;
		 const double VAl_PROJECT_143_SdvgStructureX = 0.;

//--------------------------------------------------------------------------------
/////////////////////////////////////////////////////////////////////////////////////////////////////
///////// COAST TARGS ////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

// 1. plgOpenManPower    450x150
int NumPartsPlgOpenManPower =  1;
int NumPointsPlgOpenManPower =  5  ;

double PointsPlgOpenManPower[] ={
	-225. , -75.
, -225. ,  75.
,  225. ,  75.
,  225. , -75.
, -225. , -75.

 //	-50. , -50.
//, -50. ,  50.
//,  50. ,  50.
//,  50. , -50.
//, -50. , -50.
};
int PartsPlgOpenManPower[1] = {0};
double arrS0_OpenManPower[3] = { 0.,0., 0.}; // ���������� ������ ���
double arrF_OpenManPower[9] ={1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_OpenManPower =   PLANE_BODY;

TURPolygon plgTypeOpenManPower (NumPartsPlgOpenManPower,NumPointsPlgOpenManPower,  PartsPlgOpenManPower, PointsPlgOpenManPower);
TPlanePolygon PlanePlgOpenManPower( arrS0_OpenManPower, arrF_OpenManPower, plgTypeOpenManPower,  enumTypeTargBody_OpenManPower) ;
//--------------------------------------------------------------------------------
// 2. plgEntranche  0.6 x 12.0
int NumPartsPlgTranche  =  1;
int NumPointsPlgTranche  =  5  ;

double PointsPlgTranche [] ={
	-0.3 , -6.
, -0.3 ,  6.
,  0.3 ,  6.
,  0.3 , -6.
, -0.3 , -6.
};
int PartsPlgTranche [1] = {0};
double arrS0_Tranche [3] = { 0.,0., 0.}; // ���������� ������ ���
double arrF_Tranche [9] ={1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_Tranche  =   PLANE_BODY;

TURPolygon plgTypeTranche  (NumPartsPlgTranche ,NumPointsPlgTranche ,  PartsPlgTranche , PointsPlgTranche );
TPlanePolygon PlanePlgTranche ( arrS0_Tranche , arrF_Tranche , plgTypeTranche ,  enumTypeTargBody_Tranche ) ;
//--------------------------------------------------------------------------------

// 3. plgEntranche  1.x2.
int NumPartsPlgEntranche  =  1;
int NumPointsPlgEntranche  =  5  ;

double PointsPlgEntranche [] ={
	-0.5 , -1.
, -0.5 ,  1.
,  0.5 ,  1.
,  0.5 , -1.
, -0.5 , -1.
};
int PartsPlgEntranche [1] = {0};
double arrS0_Entranche [3] = { 0.,0., 0.}; // ���������� ������ ���
double arrF_Entranche [9] ={1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_Entranche  =   PLANE_BODY;

TURPolygon plgTypeEntranche  (NumPartsPlgEntranche ,NumPointsPlgEntranche ,  PartsPlgEntranche , PointsPlgEntranche );
TPlanePolygon PlanePlgEntranche ( arrS0_Entranche , arrF_Entranche , plgTypeEntranche ,  enumTypeTargBody_Entranche ) ;
//--------------------------------------------------------------------------------


// 4. plgCarrier  1.x2.
int NumPartsPlgCarrier  =  1;
int NumPointsPlgCarrier  =  5  ;

double PointsPlgCarrier [] ={
	-5 , -2.
, -5. ,  2.
,  5. ,  2.
,  5. , -2.
, -5. , -2.
};
int PartsPlgCarrier [1] = {0};
double arrS0_Carrier [3] = { 0.,0., 0.}; // ���������� ������ ���
double arrF_Carrier [9] ={1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_Carrier  =   PLANE_BODY;

TURPolygon plgTypeCarrier  (NumPartsPlgCarrier ,NumPointsPlgCarrier ,  PartsPlgCarrier , PointsPlgCarrier );
TPlanePolygon PlanePlgCarrier ( arrS0_Carrier , arrF_Carrier , plgTypeCarrier ,  enumTypeTargBody_Carrier ) ;
//--------------------------------------------------------------------------------

// 4. plgCar  1.x2.
int NumPartsPlgCar  =  1;
int NumPointsPlgCar  =  5  ;

double PointsPlgCar [] ={
	-4 , -1.5
, -4. ,  1.5
,  4. ,  1.5
,  4. , -1.5
, -4. , -1.5
};
int PartsPlgCar [1] = {0};
double arrS0_Car [3] = { 0.,0., 0.}; // ���������� ������ ���
double arrF_Car [9] ={1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_Car  =   PLANE_BODY;

TURPolygon plgTypeCar  (NumPartsPlgCar ,NumPointsPlgCar ,  PartsPlgCar , PointsPlgCar );
TPlanePolygon PlanePlgCar ( arrS0_Car , arrF_Car , plgTypeCar ,  enumTypeTargBody_Car ) ;
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------

// 4. plgPlatoonPoint  1.8x 3.6
int NumPartsPlgPlatoonPoint  =  1;
int NumPointsPlgPlatoonPoint  =  5  ;

double PointsPlgPlatoonPoint [] ={
	-1.8 , -0.9
, -1.8 ,  0.9
,  1.8 ,  0.9
,  1.8 , -0.9
, -1.8 , -0.9
};
int PartsPlgPlatoonPoint [1] = {0};
double arrS0_PlatoonPoint [3] = { 0.,0., 0.}; // ���������� ������ ���
double arrF_PlatoonPoint [9] ={1.,0.,0.
											 ,0.,1.,0.
											 ,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_PlatoonPoint  =   PLANE_BODY;

TURPolygon plgTypePlatoonPoint  (NumPartsPlgPlatoonPoint ,NumPointsPlgPlatoonPoint ,  PartsPlgPlatoonPoint , PointsPlgPlatoonPoint );
TPlanePolygon PlanePlgPlatoonPoint ( arrS0_PlatoonPoint , arrF_PlatoonPoint , plgTypePlatoonPoint ,  enumTypeTargBody_PlatoonPoint ) ;
//--------------------------------------------------------------------------------


// 1. DEBUG

double arrS0_DEBUG[3] = {0.,0., 0.}; // ���������� ������ ���
double arrF_DEBUG[9] ={ 1.,0.,0.
													 ,0.,1.,0.
													 ,0.,0.,1.
											    };
enumTypeTargBody enumTypeTargBody_DEBUG =   PLANE_BODY;
const double VAlDEBUG_x = 76.;
const double VAlDEBUG_y = 16.;

const TURPointXY pntTopRight(VAlDEBUG_x, VAlDEBUG_y);
const TURPointXY pntBottomLeft(-VAlDEBUG_x, -VAlDEBUG_y);
TURPolygon plgDEBUG (  pntTopRight,pntBottomLeft);;
// extern TPlanePolygon PlanePlgDEBUG( arrS0_DEBUG, arrF_DEBUG, plgDEBUG,  enumTypeTargBody_DEBUG) ;
 extern TPlanePolygon PlanePlgDEBUG(  arrS0_C21, arrF_C21, plgC21,  enumTypeTargBody_C21) ;


//--------------------------------------------------------------------------------


 TTarget::~TTarget()
{
   if (mparrBuff != NULL)
   {
	 free( mparrBuff) ;
	 mparrBuff = NULL ;
   }
   if ( mpwcharrFoldReport != NULL)
   {
   free( mpwcharrFoldReport );
   mpwcharrFoldReport = NULL ;
	 }

   /*	 if(mpArrPlanePolygon != NULL)
	 {
		 free( mpArrPlanePolygon) ;
		 mpArrPlanePolygon = NULL ;
	 } */
	 mLenArrPlanePolygon = 0;
}
//---------------------------------------------------------------------------


TTarget::TTarget()
{

	mTraject = TTraject() ;

	// ������ ������������
	mplnGlagkovsky = TURPolyLine ( constPnt1, constPnt2) ;
	// ��� ����
	 menumTargetType = JET_F16 ;
	 //  ���:
	 mTargEPR = 1.;
	mpwcharrFoldReport = NULL ;
	mparrBuff   = NULL ;
	mQuantPntReport = 0;
	mLenMemoryAlloc = 0 ;
 //	mpArrPlanePolygon = NULL;
   memset(mpArrPlanePolygon, 0, MAX_POSSIBLE_QUANTS_PLANE_POLYGONS * sizeof(TPlanePolygon));
	mLenArrPlanePolygon = 0;

}

//---------------------------------------------------------------------------


// ����������� �����������
 TTarget ::TTarget (const TTarget &R)
 {
		mTargEPR = R.mTargEPR;
		mTraject = R.mTraject;


		// ������ ������������
		mplnGlagkovsky = R.mplnGlagkovsky;
		// ��� ����
		menumTargetType = R.menumTargetType ;
		// ��� ������
		mLenMemoryAlloc = R.mLenMemoryAlloc ;
		mQuantPntReport = R.mQuantPntReport ;

		 ///
		mparrBuff  = NULL;

		if(R.mparrBuff  != NULL)
		{
			if((mparrBuff  = (double*)malloc( QUANT_COLS_BUFF_TARGET  * R.mLenMemoryAlloc * sizeof(double))) != NULL)
			{
			memcpy( mparrBuff ,R.mparrBuff , QUANT_COLS_BUFF_TARGET  * R.mLenMemoryAlloc * sizeof(double));
			}
			else
			{
			ShowMessage(L"Not memory for mparrBuff ") ;
			Abort() ;
			}
		}

		//
		mpwcharrFoldReport = NULL ;
		if(R.mpwcharrFoldReport != NULL)
		{
			if ((mpwcharrFoldReport = (wchar_t *)malloc(300 * sizeof (wchar_t))) != NULL)
			{
			wcscpy(mpwcharrFoldReport, R.mpwcharrFoldReport);

			}
			else
			{
			ShowMessage(L"Not memory for mpwcharrFoldReport ") ;
			Abort() ;
			}
		}
		///

		mLenArrPlanePolygon = R.mLenArrPlanePolygon;
		memcpy( mpArrPlanePolygon, R.mpArrPlanePolygon, MAX_POSSIBLE_QUANTS_PLANE_POLYGONS * sizeof(TPlanePolygon));
	  /*	if (mpArrPlanePolygon != NULL)
		{
		  free (mpArrPlanePolygon);
		  mpArrPlanePolygon = NULL;
		}


		if(R.mpArrPlanePolygon != NULL)
		{
			if((mpArrPlanePolygon  = (TPlanePolygon*)malloc(R.mLenArrPlanePolygon * sizeof(TPlanePolygon))) != NULL)
			{
			memcpy( mpArrPlanePolygon ,R.mpArrPlanePolygon , R.mLenArrPlanePolygon * sizeof(TPlanePolygon));
			}
			else
			{
			ShowMessage(L"Not memory for mpArrPlanePolygon ����������� �����������") ;
		   	Abort() ;
			}
		}
		*/
 }
 // �������� ������������
 TTarget &TTarget::operator=(const TTarget  &R)
 {
		mTargEPR = R.mTargEPR;
		mTraject = R.mTraject;


		// ������ ������������
		mplnGlagkovsky = R.mplnGlagkovsky;
		// ��� ����
		menumTargetType = R.menumTargetType ;
		// ��� ������
		mLenMemoryAlloc = R.mLenMemoryAlloc ;
		mQuantPntReport = R.mQuantPntReport ;


		mparrBuff  = NULL;
		mpwcharrFoldReport = NULL ;
		if(R.mparrBuff  != NULL)
		{
			if((mparrBuff  = (double*)malloc( QUANT_COLS_BUFF_TARGET  * R.mLenMemoryAlloc * sizeof(double))) != NULL)
			{
			memcpy( mparrBuff ,R.mparrBuff , QUANT_COLS_BUFF_TARGET  * R.mLenMemoryAlloc * sizeof(double));
			}
			else
			{
			ShowMessage(L"Not memory for mparrBuff ") ;
			Abort() ;
			}
		}

		//
		if(R.mpwcharrFoldReport != NULL)
		{
			if ((mpwcharrFoldReport = (wchar_t *)malloc(300 * sizeof (wchar_t))) != NULL)
			{
			wcscpy(mpwcharrFoldReport, R.mpwcharrFoldReport);

			}
			else
			{
			ShowMessage(L"Not memory for mpwcharrFoldReport") ;
			Abort() ;
			}
		}

			///

		mLenArrPlanePolygon = R.mLenArrPlanePolygon;
		memcpy( mpArrPlanePolygon, R.mpArrPlanePolygon, MAX_POSSIBLE_QUANTS_PLANE_POLYGONS * sizeof(TPlanePolygon));
	   /*	if (mpArrPlanePolygon != NULL)
		{
		  free (mpArrPlanePolygon);
		  mpArrPlanePolygon = NULL;
		}


		if(R.mpArrPlanePolygon != NULL)
		{
			if((mpArrPlanePolygon  = (TPlanePolygon*)malloc(R.mLenArrPlanePolygon * sizeof(TPlanePolygon))) != NULL)
			{
			memcpy( mpArrPlanePolygon ,R.mpArrPlanePolygon , R.mLenArrPlanePolygon * sizeof(TPlanePolygon));
			}
			else
			{
			ShowMessage(L"Not memory for mpArrPlanePolygon ����������� �����������") ;
		   	Abort() ;
			}
		} */
	return *this ;
 }

	// ����� �����������
  // Bearing -  ���� ������� ���� � ���
  // TargCourse - ���� ����� ���� � ���
  // TargZenitAng - ���� ����� ������� �������� ���� � ����������� � �����
	// V,R,H - ��������, ���������, ������
	// TargEPR - ���
 TTarget::TTarget (TTraject   Traject	,enumTargetType  EnumTargetType, const double TargEPR, wchar_t* pwcharrFoldReport)
 {
	 mTraject = Traject;

	 mTargEPR = TargEPR;

	 menumTargetType = EnumTargetType;

  // �� �������
	mpwcharrFoldReport = NULL ;
	mparrBuff   = NULL ;


	mQuantPntReport = 0 ;
	mLenMemoryAlloc = 2000 ;


	switch (EnumTargetType)
	{
	case GARPUN_V300:
	mplnGlagkovsky =  TURPolyLine( 1, 12)  ;
	for (int i =0; i < mplnGlagkovsky.NumPoints; i++)
	{
	  mplnGlagkovsky.Points[i].X =  arr_Dal_Garpun300[i];
	  mplnGlagkovsky.Points[i].Y =  arrP_Glad_Garpun300[i];
	}

	break;
	case GARPUN_V700:
	case GARPUN_V1000:
	mplnGlagkovsky =  TURPolyLine( 1, 16)  ;
	for (int i =0; i < mplnGlagkovsky.NumPoints; i++)
	{
	  mplnGlagkovsky.Points[i].X =  arr_Dal_Garpun700[i];
	  mplnGlagkovsky.Points[i].Y =  arrP_Glad_Garpun700[i];
	}
	break;

	default:
	mplnGlagkovsky = TURPolyLine ( constPnt1, constPnt2) ;
	break  ;
	}
	mLenArrPlanePolygon = 0;

  /*	if (mpArrPlanePolygon != NULL)
	{
	  free(mpArrPlanePolygon);
	  mpArrPlanePolygon = NULL;

	} */
  //	mpArrPlanePolygon = NULL;

	switch(EnumTargetType)
	{
		case GARPUN_V300:
		case GARPUN_V700:
		mLenArrPlanePolygon = 15;
	   //	mpArrPlanePolygon = (TPlanePolygon *)malloc( mLenArrPlanePolygon * sizeof(mLenArrPlanePolygon));
		mpArrPlanePolygon[0] =  PlanePlgC11; // PlanePlgC11
		mpArrPlanePolygon[1] =  PlanePlgC12; //PlanePlgC12
		mpArrPlanePolygon[2] =  PlanePlgC13_1;  //PlanePlgC13_1
		mpArrPlanePolygon[3] =  PlanePlgC13_2; //PlanePlgC13_2
		mpArrPlanePolygon[4] =  PlanePlgC14_1; //PlanePlgC14_1
		mpArrPlanePolygon[5] =  PlanePlgC14_2;  //PlanePlgC14_2
		mpArrPlanePolygon[6] =  PlanePlgC61;  //PlanePlgC61
		mpArrPlanePolygon[7] =  PlanePlgC62;  //PlanePlgC62
		mpArrPlanePolygon[8] =  PlanePlgC71; //PlanePlgC71
		mpArrPlanePolygon[9] =  PlanePlgC71VertLeft; //PlanePlgC71VertLeft
		mpArrPlanePolygon[10] = PlanePlgC71VertRight; // PlanePlgC71VertRight
		mpArrPlanePolygon[11] = PlanePlgC21;  // PlanePlgC21
		mpArrPlanePolygon[12] = PlanePlgKUKUN;
		mpArrPlanePolygon[13] = PlanePlg_FaceKukun;
		mpArrPlanePolygon[14] = PlanePlgNOSE;
		break;

		case DESTROYER:
	  	mLenArrPlanePolygon = 10;

		createVesselArrayOfPlanePolygons( VAl_ARLEIGHT_BERK_BoardX,  VAl_ARLEIGHT_BERK_BoardY,  VAl_ARLEIGHT_BERK_BoardH
	, VAl_ARLEIGHT_BERK_StructureX,  VAl_ARLEIGHT_BERK_StructureY,  VAl_ARLEIGHT_BERK_StructureH
	 , VAl_ARLEIGHT_BERK_SdvgStructureX, mpArrPlanePolygon );
	   //	mLenArrPlanePolygon = 1;
	   //	 	mpArrPlanePolygon[0] = PlanePlgDEBUG;

		break;

		case JET_A_10A:
		case JET_F16:
		mLenArrPlanePolygon = 3;
		mpArrPlanePolygon[0] =  PlanePlgF14Krilo;
		mpArrPlanePolygon[1] =  PlanePlgF14Fas;
		mpArrPlanePolygon[2] =  PlanePlgF14Nos;
		break;

		case MOTORBOAT:
		mLenArrPlanePolygon = 10;
		createVesselArrayOfPlanePolygons( VAl_PROJECT_143_BoardX,  VAl_PROJECT_143_BoardY,  VAl_PROJECT_143_BoardH
	, VAl_PROJECT_143_StructureX,  VAl_PROJECT_143_StructureY,  VAl_PROJECT_143_StructureH
	 , VAl_PROJECT_143_SdvgStructureX, mpArrPlanePolygon );
		break;


		case OPEN_MANPOWER_LIE:
		case OPEN_MANPOWER_STAND:
		case BULLET_PROOF_LIE:
		case BULLET_PROOF_STAND:
		mLenArrPlanePolygon = 1;
		mpArrPlanePolygon[0] =  PlanePlgOpenManPower;
		break;

		case COVERED_MANPOWER_ENTRENCH:
		mLenArrPlanePolygon = 1;
		mpArrPlanePolygon[0] =  PlanePlgEntranche;
		break;

		case COVERED_MANPOWER_TRENCH:
		mLenArrPlanePolygon = 1;
		mpArrPlanePolygon[0] =  PlanePlgTranche;
		break;

		case MANPOWER_ARMOURED_CARRIER:
		mLenArrPlanePolygon = 1;
		mpArrPlanePolygon[0] =  PlanePlgCarrier;
		break;

		case MANPOWER_CAR:
		mLenArrPlanePolygon = 1;
		mpArrPlanePolygon[0] =  PlanePlgCar;
		break;

		case PLATOON_POINT:
		mLenArrPlanePolygon = 1;
		mpArrPlanePolygon[0] =  PlanePlgPlatoonPoint;
		break;

		default:
		break;
	}
   if(pwcharrFoldReport != NULL)
   {
	   if ((mpwcharrFoldReport = (wchar_t *)malloc(300 * sizeof (wchar_t))) != NULL)
		{
		wcscpy(mpwcharrFoldReport, pwcharrFoldReport);

		}
		else
		{
		 ShowMessage(L"Not memory for mpwcharrFoldReport") ;
		 Abort() ;
		}

		if((mparrBuff  = (double*)malloc( QUANT_COLS_BUFF_TARGET  * mLenMemoryAlloc * sizeof(double))) != NULL)
		{

		memset( mparrBuff,  0,  QUANT_COLS_BUFF_TARGET  * mLenMemoryAlloc * sizeof(double));
		}
		else
		{
		 ShowMessage(L"Not memory for mparrBuff ") ;
		 Abort() ;
		}
   }
 }
 /////

 //
void TTarget::recalcTrajPoint(const double tNext)
{
		mTraject.recalcTrajPoint(tNext ) ;

		if(mpwcharrFoldReport)  updateReportData() ;
		return ;
}


 // ��������� ���������� � ������� ��� ������
 void TTarget::updateReportData()
 {
  try
  {
	 if (mQuantPntReport ==  mLenMemoryAlloc)
	 {
	   mLenMemoryAlloc += 2000 ;
	   mparrBuff = (double *)realloc(mparrBuff, QUANT_COLS_BUFF_TARGET  * mLenMemoryAlloc * sizeof(double)) ;

	 }
	   int num0 =  mQuantPntReport * QUANT_COLS_BUFF_TARGET ;

	   mparrBuff [num0]    =  mTraject.mTCur  ;

	   mparrBuff [num0 +1]  =  mTraject.marrVectSostGSK[0] ;

	   mparrBuff [num0 +2]  =  mTraject.marrVectSostGSK[1] ;

	   mparrBuff [num0 +3]  =  mTraject.marrVectSostGSK[2] ;

	   mparrBuff [num0 +4]  =  mTraject.marrVectSostGSK[3]  ;

	   mparrBuff [num0 +5]  =  mTraject.marrVectSostGSK[4] ;

	   mparrBuff [num0 +6]  =  mTraject.marrVectSostGSK[5]  ;

	  // mparrBuff [num0 +7]  =  mTraject.marrVS_OSKPSb[0]  ;

	 //  mparrBuff [num0 +8]  =  mTraject.marrVS_OSKPSb[1]  ;

	   mQuantPntReport++ ;
	 }
	 catch(...)
	 {
	   //	 return;
     }

 }

// ����������  ������
void TTarget::WriteReport()
{
	 if (mpwcharrFoldReport == NULL )return ;

	 wchar_t wcharrPath [300] = {0} ;
	 wcscpy(wcharrPath, mpwcharrFoldReport);
	 wcscat(wcharrPath, L"\\TargetReport\\");
	 _wmkdir(wcharrPath);
	 wcscat(wcharrPath, L"\\");

	 wchar_t wcharrFileNames[QUANT_COLS_BUFF_TARGET * 30] = {0};

	 wcscpy( &wcharrFileNames[ 0 * 30], L"t");
	 wcscpy( &wcharrFileNames[ 1 * 30], L"TrgGSK_Real_X");
	 wcscpy( &wcharrFileNames[ 2 * 30], L"TrgGSK_Real_Y");
	 wcscpy( &wcharrFileNames[ 3 * 30], L"TrgGSK_Real_Z");
	 wcscpy( &wcharrFileNames[ 4 * 30], L"TrgGSK_Real_VX");
	 wcscpy( &wcharrFileNames[ 5 * 30], L"TrgGSK_Real_VY");
	 wcscpy( &wcharrFileNames[ 6 * 30], L"TrgGSK_Real_VZ");


	 for (int i = 1; i < QUANT_COLS_BUFF_TARGET; i++)
	 {
	 TYrWriteShapeFile::WriteOneReport(wcharrPath  // ���� � �����
								  ,mparrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS_BUFF_TARGET // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,mQuantPntReport  //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,30// ������������ ����� ����� ����������
								  ,0  // ����� ���������� �� ��� X
								  ,i // ����� ���������� �� ��� Y
								  ,100. //  ������� �� ��� X
								  ,1.  // ������� �� ��� Y
								   )  ;
	 }

	 // ���������� � ��������� OXY
	TYrWriteShapeFile::WriteOneReport(wcharrPath  // ���� � �����
								  ,mparrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS_BUFF_TARGET // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,mQuantPntReport  //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,30// ������������ ����� ����� ����������
								  ,1  // ����� ���������� �� ��� X
								  ,2 // ����� ���������� �� ��� Y
								  ,1. //  ������� �� ��� X
								  ,1.  // ������� �� ��� Y
								   )  ;
	// ���������� � ��������� OXZ
	TYrWriteShapeFile::WriteOneReport(wcharrPath  // ���� � �����
								  ,mparrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS_BUFF_TARGET // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,mQuantPntReport  //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,30// ������������ ����� ����� ����������
								  ,1  // ����� ���������� �� ��� X
								  ,3 // ����� ���������� �� ��� Y
								  ,1. //  ������� �� ��� X
								  ,1.  // ������� �� ��� Y
								   )  ;
	// ���������� � ��������� OYZ
	TYrWriteShapeFile::WriteOneReport(wcharrPath  // ���� � �����
								  ,mparrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS_BUFF_TARGET // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,mQuantPntReport  //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,30// ������������ ����� ����� ����������
								  ,2  // ����� ���������� �� ��� X
								  ,3 // ����� ���������� �� ��� Y
								  ,1. //  ������� �� ��� X
								  ,1.  // ������� �� ��� Y
								   )  ;


	wchar_t wchFileName [300] = {0} ;
	wcscpy(wchFileName, wcharrPath );
	wcscat(wchFileName, L"Axes.shp");
	TYrWriteShapeFile::CreateShpAxes(wchFileName,-40000.,40000,-40000.,40000) ;

 }



// ����������  ������  �������������
 void TTarget::WriteReport(wchar_t *pwcharrPath)
 {
	 if (pwcharrPath == NULL )return ;
	 wchar_t wcharrPath [300] = {0} ;
	 wcscpy(wcharrPath, pwcharrPath);
	 wcscat(wcharrPath, L"\\");


	 wchar_t wcharrFileNames[QUANT_COLS_BUFF_TARGET * 30] = {0};

	 wcscpy( &wcharrFileNames[ 0 * 30], L"t");
	 wcscpy( &wcharrFileNames[ 1 * 30], L"TrgGSK_Real_X");
	 wcscpy( &wcharrFileNames[ 2 * 30], L"TrgGSK_Real_Y");
	 wcscpy( &wcharrFileNames[ 3 * 30], L"TrgGSK_Real_Z");
	 wcscpy( &wcharrFileNames[ 4 * 30], L"TrgGSK_Real_VX");
	 wcscpy( &wcharrFileNames[ 5 * 30], L"TrgGSK_Real_VY");
	 wcscpy( &wcharrFileNames[ 6 * 30], L"TrgGSK_Real_VZ");
	// wcscpy( &wcharrFileNames[ 7 * 30], L"TrgGSK_Real_X_OSKPSb");
 //	 wcscpy( &wcharrFileNames[ 8 * 30], L"TrgGSK_Real_Y_OSKPSb");

	 for (int i = 1; i < QUANT_COLS_BUFF_TARGET; i++)
	 {
	 TYrWriteShapeFile::WriteOneReport(wcharrPath  // ���� � �����
								  ,mparrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS_BUFF_TARGET // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,mQuantPntReport  //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,30// ������������ ����� ����� ����������
								  ,0  // ����� ���������� �� ��� X
								  ,i // ����� ���������� �� ��� Y
								  ,100. //  ������� �� ��� X
								  ,1.  // ������� �� ��� Y
								   )  ;
	 }

	 // ���������� � ��������� OXY
	TYrWriteShapeFile::WriteOneReport(wcharrPath  // ���� � �����
								  ,mparrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS_BUFF_TARGET // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,mQuantPntReport  //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,30// ������������ ����� ����� ����������
								  ,1  // ����� ���������� �� ��� X
								  ,2 // ����� ���������� �� ��� Y
								  ,1. //  ������� �� ��� X
								  ,1.  // ������� �� ��� Y
								   )  ;
	// ���������� � ��������� OXZ
	TYrWriteShapeFile::WriteOneReport(wcharrPath  // ���� � �����
								  ,mparrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS_BUFF_TARGET // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,mQuantPntReport  //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,30// ������������ ����� ����� ����������
								  ,1  // ����� ���������� �� ��� X
								  ,3 // ����� ���������� �� ��� Y
								  ,1. //  ������� �� ��� X
								  ,1.  // ������� �� ��� Y
								   )  ;
	// ���������� � ��������� OYZ
	TYrWriteShapeFile::WriteOneReport(wcharrPath  // ���� � �����
								  ,mparrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS_BUFF_TARGET // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,mQuantPntReport  //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,30// ������������ ����� ����� ����������
								  ,2  // ����� ���������� �� ��� X
								  ,3 // ����� ���������� �� ��� Y
								  ,1. //  ������� �� ��� X
								  ,1.  // ������� �� ��� Y
								   )  ;

   // ���������� � ������
 /*  TYrWriteShapeFile::WriteOneReport(wcharrPath  // ���� � �����
								  ,mparrBuff // ������ � ����������� - ������� nBuffRows x nBuffCols
								  ,QUANT_COLS_BUFF_TARGET // - �-�� ���������� � ������� ��������� ���������� � ������
								  ,mQuantPntReport  //  - �-�� �����
								  ,wcharrFileNames //������� � �������� ���������� - ������� nBuffCols x lenName
								  ,30// ������������ ����� ����� ����������
								  ,7  // ����� ���������� �� ��� X
								  ,8 // ����� ���������� �� ��� Y
								  ,1. //  ������� �� ��� X
								  ,1.  // ������� �� ��� Y
								   )  ; */


	wchar_t wchFileName [300] = {0} ;
	wcscpy(wchFileName, wcharrPath );
	wcscat(wchFileName, L"Axes.shp");
	TYrWriteShapeFile::CreateShpAxes(wchFileName,-40000.,40000,-40000.,40000) ;

 }

// ��������  �������  ��  9  PlanePolygon,  �����������  ������� ����
// INPUT:
// VAlBoardX - ����� �����
// VAlBoardY - ������ ������
// VAlBoardH - ������ �����
// VAlStructureX - ����� ���������� ����� �����
// VAlStructureY - ������  ���������� ����� ������ ������
// VAlStructureH - ������ ����������
// VAlSdvgStructureX -  ����� ���������� ������������� ������
// OUTPUT:
// pPlanePolygonArr [10] - ������  PlanePolygon  �����������  ������� ����
 void TTarget::createVesselArrayOfPlanePolygons(const double VAlBoardX, const double VAlBoardY, const double VAlBoardH
  ,const double VAlStructureX, const double VAlStructureY, const double VAlStructureH
  ,const double VAlSdvgStructureX, TPlanePolygon *pPlanePolygonArr)
{

// 1. plgSpruance0    171.7 x 16.8 x 5.8 , 8.8     ����

TURPointXY pntTopRight (VAlBoardX/2., VAlBoardH/2.);
TURPointXY pntBottomLeft (-VAlBoardX/2., -VAlBoardH/2.);
TURPolygon  plgSpruance0 ( pntTopRight, pntBottomLeft);
double arrS0_Spruance0[3] = {0.};
arrS0_Spruance0[1] = -VAlBoardY /2.;
arrS0_Spruance0[2] = -VAlBoardH /2.;

double arrF_Spruance0[9] ={ 1.,0.,0.
						   ,0.,0.,-1.
						  ,0.,1.,0.
						 };
enumTypeTargBody enumTypeTargBody_Spruance0 =   PLANE_BODY;

pPlanePolygonArr [0] = TPlanePolygon (arrS0_Spruance0, arrF_Spruance0, plgSpruance0,  enumTypeTargBody_Spruance0) ;
//--------------------------------------------------------------------------------
// 2. plgSpruance1    171.7 x 16.8 x 5.8 , 8.8       ����

double arrS0_Spruance1[3] = {0.};
arrS0_Spruance1[1] = VAlBoardY /2.;
arrS0_Spruance1[2] = -VAlBoardH /2.;
pPlanePolygonArr [1] = TPlanePolygon (arrS0_Spruance1, arrF_Spruance0, plgSpruance0,  enumTypeTargBody_Spruance0) ;
//--------------------------------------------------------------------------------
// 3. plgSpruance2    171.7 x 16.8 x 5.8 , 8.8    �����

TURPointXY pntTopRight2 (VAlBoardY/2., VAlBoardH/2.);
TURPointXY pntBottomLeft2 (-VAlBoardY/2., -VAlBoardH/2.);
TURPolygon  plgSpruance2 ( pntTopRight2, pntBottomLeft2);
double arrS0_Spruance2[3] = {0.};
arrS0_Spruance2[0] = -VAlBoardX/2.;
arrS0_Spruance2[2] = -VAlBoardH /2.;

double arrF_Spruance2[9] =   { 0.,0.,1.
													 ,1.,0.,0.
													 ,0.,1.,0.
													 };
/*{ 1.,0.,0.
						   ,0.,0.,-1.
						  ,0.,1.,0.
						 }; */

enumTypeTargBody enumTypeTargBody_Spruance2 =   PLANE_BODY;

pPlanePolygonArr [2] = TPlanePolygon (arrS0_Spruance2, arrF_Spruance2, plgSpruance2,  enumTypeTargBody_Spruance2) ;
//--------------------------------------------------------------------------------
// 4. plgSpruance3    171.7 x 16.8 x 5.8 , 8.8       ���

double arrS0_Spruance3[3] = {0.};
arrS0_Spruance3[0] =  VAlBoardX/2.;
arrS0_Spruance3[2] = -VAlBoardH /2.;

pPlanePolygonArr [3] = TPlanePolygon (arrS0_Spruance3, arrF_Spruance2, plgSpruance2,  enumTypeTargBody_Spruance2) ;
//--------------------------------------------------------------------------------
// 5. plgSpruance4    171.7 x 16.8 x 5.8 , 8.8   ������

TURPointXY pntTopRight4 (VAlBoardX/2., VAlBoardY/2.);
TURPointXY pntBottomLeft4 (-VAlBoardX/2., -VAlBoardY/2.);
TURPolygon plgSpruance4 ( pntTopRight4, pntBottomLeft4);
double arrS0_Spruance4[3] = {0.};

double arrF_Spruance4[9] ={1.,0.,0.
													,0.,1.,0.
													,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_Spruance4 =   PLANE_BODY;

pPlanePolygonArr [4] = TPlanePolygon (arrS0_Spruance4, arrF_Spruance4, plgSpruance4,  enumTypeTargBody_Spruance4) ;
//--------------------------------------------------------------------------------

// 6. plgSpruance5    171.7 x 16.8 x 5.8 , 8.8    ���������� 86 x12 x3 , ����
TURPointXY pntTopRight5 (VAlStructureX/2., VAlStructureH/2.);
TURPointXY pntBottomLeft5 (-VAlStructureX/2., -VAlStructureH/2.);
TURPolygon  plgSpruance5 ( pntTopRight5, pntBottomLeft5);
double arrS0_Spruance5[3] = {0.};
arrS0_Spruance5[0] = VAlSdvgStructureX;
arrS0_Spruance5[1] = -VAlStructureY /2.;
arrS0_Spruance5[2] = VAlStructureH /2.;

double arrF_Spruance5[9] ={ 1.,0.,0.
						   ,0.,0.,-1.
						  ,0.,1.,0.
						 };

pPlanePolygonArr [5] = TPlanePolygon (arrS0_Spruance5, arrF_Spruance5, plgSpruance5,  enumTypeTargBody_Spruance0) ;
//--------------------------------------------------------------------------------

// 7. plgSpruance6    171.7 x 16.8 x 5.8 , 8.8    ���������� 86 x12 x3 , ����
double arrS0_Spruance6[3] = {0.};
arrS0_Spruance6[0] = VAlSdvgStructureX;
arrS0_Spruance6[1] = VAlStructureY /2.;
arrS0_Spruance6[2] = VAlStructureH /2.;
pPlanePolygonArr [6] = TPlanePolygon (arrS0_Spruance6, arrF_Spruance5, plgSpruance5,  enumTypeTargBody_Spruance0) ;
//--------------------------------------------------------------------------------

// 8. plgSpruance7    171.7 x 16.8 x 5.8 , 8.8    ���������� 86 x12 x3 , ���
TURPointXY pntTopRight7 (VAlStructureY/2., VAlStructureH/2.);
TURPointXY pntBottomLeft7 (-VAlStructureY/2., -VAlStructureH/2.);
TURPolygon  plgSpruance7 ( pntTopRight7, pntBottomLeft7);
double arrS0_Spruance7[3] = {0.};
arrS0_Spruance7[0] = VAlStructureX/2. + VAlSdvgStructureX;


double arrF_Spruance7[9] = { 0.,0.,1.
													 ,1.,0.,0.
													 ,0.,1.,0.
													 };
/*{ 1.,0.,0.
						   ,0.,0.,-1.
						  ,0.,1.,0.
						 };*/
enumTypeTargBody enumTypeTargBody_Spruance7 =   PLANE_BODY;

pPlanePolygonArr [7] = TPlanePolygon (arrS0_Spruance7, arrF_Spruance7, plgSpruance7,  enumTypeTargBody_Spruance7) ;
//--------------------------------------------------------------------------------

// 9. plgSpruance8    171.7 x 16.8 x 5.8 , 8.8    ���������� 86 x12 x3 , �����
double arrS0_Spruance8[3] = {0.};
arrS0_Spruance8[0] = -VAlStructureX/2. + VAlSdvgStructureX;
pPlanePolygonArr [8] = TPlanePolygon (arrS0_Spruance8, arrF_Spruance7, plgSpruance7,  enumTypeTargBody_Spruance7) ;

//--------------------------------------------------------------------------------

// 10. plgSpruance9    171.7 x 16.8 x 5.8 , 8.8    ���������� 86 x12 x3 , �����

TURPointXY pntTopRight9 (VAlStructureX/2., VAlStructureY/2.);
TURPointXY pntBottomLeft9 (-VAlStructureX/2.,- VAlStructureY/2.);
TURPolygon  plgSpruance9 ( pntTopRight9, pntBottomLeft9);
double arrS0_Spruance9[3] = {0.};
arrS0_Spruance9[0] =  VAlSdvgStructureX ;
arrS0_Spruance9[2] = VAlStructureH;
double arrF_Spruance9[9] ={1.,0.,0.
													,0.,1.,0.
													,0.,0.,1.
											 };
enumTypeTargBody enumTypeTargBody_Spruance9 =   PLANE_BODY;

pPlanePolygonArr [9] = TPlanePolygon (arrS0_Spruance9, arrF_Spruance9, plgSpruance9,  enumTypeTargBody_Spruance9) ;
}
#pragma package(smart_init)
