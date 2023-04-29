/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBoxVHor;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxTemperature0;
    QLabel *label_5;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxCourseAng;
    QLabel *label_6;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxVVert;
    QFrame *frame_4;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_16;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QDoubleSpinBox *doubleSpinBox_10;
    QDoubleSpinBox *doubleSpinBox_11;
    QDoubleSpinBox *doubleSpinBox_12;
    QDoubleSpinBox *doubleSpinBox_13;
    QDoubleSpinBox *doubleSpinBox_14;
    QDoubleSpinBox *doubleSpinBox_16;
    QPushButton *pushButton_3;
    QLabel *label_42;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_10;
    QLabel *label_43;
    QDoubleSpinBox *doubleSpinBox_17;
    QLabel *label_44;
    QDoubleSpinBox *doubleSpinBox_18;
    QFrame *frame_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_6;
    QFrame *frame_5;
    QComboBox *comboBox;
    QLabel *label_45;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLabel *label_46;
    QLabel *label_47;
    QDoubleSpinBox *doubleSpinBox_20;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1259, 798);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        MainWindow->setTabletTracking(true);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 0, 691, 141));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        frame->setMidLineWidth(3);
        gridLayoutWidget = new QWidget(frame);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 651, 91));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        doubleSpinBoxVHor = new QDoubleSpinBox(gridLayoutWidget);
        doubleSpinBoxVHor->setObjectName(QString::fromUtf8("doubleSpinBoxVHor"));
        doubleSpinBoxVHor->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBoxVHor->setMinimum(-10000000.000000000000000);
        doubleSpinBoxVHor->setMaximum(100000000.000000000000000);
        doubleSpinBoxVHor->setValue(0.000000000000000);

        gridLayout->addWidget(doubleSpinBoxVHor, 0, 0, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 20, 131, 16));
        doubleSpinBoxTemperature0 = new QDoubleSpinBox(frame);
        doubleSpinBoxTemperature0->setObjectName(QString::fromUtf8("doubleSpinBoxTemperature0"));
        doubleSpinBoxTemperature0->setGeometry(QRect(590, 210, 71, 23));
        doubleSpinBoxTemperature0->setWrapping(true);
        doubleSpinBoxTemperature0->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBoxTemperature0->setMinimum(-500.000000000000000);
        doubleSpinBoxTemperature0->setMaximum(500.000000000000000);
        doubleSpinBoxTemperature0->setValue(18.000000000000000);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(590, 63, 71, 23));
        label_5->setFrameShape(QFrame::Box);
        label_5->setScaledContents(true);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(590, 4, 61, 22));
        label_3->setFrameShape(QFrame::Box);
        label_3->setScaledContents(true);
        doubleSpinBoxCourseAng = new QDoubleSpinBox(frame);
        doubleSpinBoxCourseAng->setObjectName(QString::fromUtf8("doubleSpinBoxCourseAng"));
        doubleSpinBoxCourseAng->setGeometry(QRect(590, 152, 71, 22));
        doubleSpinBoxCourseAng->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBoxCourseAng->setMinimum(-360.000000000000000);
        doubleSpinBoxCourseAng->setMaximum(360.000000000000000);
        doubleSpinBoxCourseAng->setSingleStep(0.010000000000000);
        doubleSpinBoxCourseAng->setValue(0.000000000000000);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(590, 93, 71, 22));
        label_6->setFrameShape(QFrame::Box);
        label_6->setScaledContents(true);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(590, 33, 71, 23));
        label_4->setFrameShape(QFrame::Box);
        label_4->setScaledContents(true);
        doubleSpinBoxVVert = new QDoubleSpinBox(frame);
        doubleSpinBoxVVert->setObjectName(QString::fromUtf8("doubleSpinBoxVVert"));
        doubleSpinBoxVVert->setGeometry(QRect(590, 181, 71, 22));
        doubleSpinBoxVVert->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBoxVVert->setMinimum(-100.000000000000000);
        doubleSpinBoxVVert->setMaximum(100.000000000000000);
        doubleSpinBoxVVert->setValue(0.000000000000000);
        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(10, 160, 1051, 561));
        frame_4->setFrameShape(QFrame::Panel);
        frame_4->setFrameShadow(QFrame::Plain);
        frame_4->setLineWidth(3);
        frame_4->setMidLineWidth(1);
        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 193, 55, 16));
        label_12 = new QLabel(frame_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(250, 193, 55, 16));
        label_13 = new QLabel(frame_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(140, 193, 55, 16));
        label_16 = new QLabel(frame_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(460, 193, 55, 16));
        label_32 = new QLabel(frame_4);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(360, 193, 55, 16));
        label_33 = new QLabel(frame_4);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(600, 193, 55, 16));
        label_39 = new QLabel(frame_4);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(190, 163, 281, 31));
        label_40 = new QLabel(frame_4);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(70, 350, 271, 31));
        label_41 = new QLabel(frame_4);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(200, 20, 301, 20));
        doubleSpinBox_5 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        doubleSpinBox_5->setGeometry(QRect(10, 213, 91, 31));
        doubleSpinBox_5->setDecimals(1);
        doubleSpinBox_5->setMinimum(-1000000.000000000000000);
        doubleSpinBox_5->setMaximum(900000.000000000000000);
        doubleSpinBox_7 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));
        doubleSpinBox_7->setGeometry(QRect(590, 213, 91, 31));
        doubleSpinBox_7->setDecimals(2);
        doubleSpinBox_7->setMinimum(-1000000.000000000000000);
        doubleSpinBox_7->setMaximum(9000.000000000000000);
        doubleSpinBox_7->setValue(0.000000000000000);
        doubleSpinBox_8 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));
        doubleSpinBox_8->setGeometry(QRect(230, 213, 91, 31));
        doubleSpinBox_8->setDecimals(1);
        doubleSpinBox_8->setMinimum(-1000000.000000000000000);
        doubleSpinBox_8->setMaximum(900000.000000000000000);
        doubleSpinBox_8->setValue(0.000000000000000);
        doubleSpinBox_9 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
        doubleSpinBox_9->setGeometry(QRect(450, 213, 91, 31));
        doubleSpinBox_9->setDecimals(2);
        doubleSpinBox_9->setMinimum(-1000000.000000000000000);
        doubleSpinBox_9->setMaximum(9000.000000000000000);
        doubleSpinBox_10 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));
        doubleSpinBox_10->setGeometry(QRect(340, 213, 91, 31));
        doubleSpinBox_10->setDecimals(2);
        doubleSpinBox_10->setMinimum(-1000000.000000000000000);
        doubleSpinBox_10->setMaximum(9000.000000000000000);
        doubleSpinBox_10->setValue(40.000000000000000);
        doubleSpinBox_11 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_11->setObjectName(QString::fromUtf8("doubleSpinBox_11"));
        doubleSpinBox_11->setGeometry(QRect(120, 213, 91, 31));
        doubleSpinBox_11->setDecimals(1);
        doubleSpinBox_11->setMinimum(-1000000.000000000000000);
        doubleSpinBox_11->setMaximum(9000.000000000000000);
        doubleSpinBox_11->setValue(300.000000000000000);
        doubleSpinBox_12 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_12->setObjectName(QString::fromUtf8("doubleSpinBox_12"));
        doubleSpinBox_12->setGeometry(QRect(140, 390, 141, 31));
        doubleSpinBox_12->setDecimals(1);
        doubleSpinBox_12->setMaximum(9000.000000000000000);
        doubleSpinBox_12->setValue(40.000000000000000);
        doubleSpinBox_13 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_13->setObjectName(QString::fromUtf8("doubleSpinBox_13"));
        doubleSpinBox_13->setGeometry(QRect(20, 390, 111, 31));
        doubleSpinBox_13->setDecimals(1);
        doubleSpinBox_13->setMaximum(9000.000000000000000);
        doubleSpinBox_13->setValue(1000.000000000000000);
        doubleSpinBox_14 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_14->setObjectName(QString::fromUtf8("doubleSpinBox_14"));
        doubleSpinBox_14->setGeometry(QRect(180, 290, 131, 31));
        doubleSpinBox_14->setDecimals(3);
        doubleSpinBox_14->setMinimum(-100.000000000000000);
        doubleSpinBox_14->setMaximum(9000.000000000000000);
        doubleSpinBox_16 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_16->setObjectName(QString::fromUtf8("doubleSpinBox_16"));
        doubleSpinBox_16->setGeometry(QRect(20, 293, 131, 31));
        doubleSpinBox_16->setDecimals(3);
        doubleSpinBox_16->setMinimum(-100.000000000000000);
        doubleSpinBox_16->setMaximum(9000.000000000000000);
        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(810, 450, 171, 91));
        label_42 = new QLabel(frame_4);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(10, 70, 231, 20));
        lineEdit_2 = new QLineEdit(frame_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(250, 60, 211, 41));
        pushButton_10 = new QPushButton(frame_4);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(480, 60, 93, 41));
        label_43 = new QLabel(frame_4);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(290, 110, 161, 31));
        doubleSpinBox_17 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_17->setObjectName(QString::fromUtf8("doubleSpinBox_17"));
        doubleSpinBox_17->setGeometry(QRect(470, 110, 91, 31));
        doubleSpinBox_17->setDecimals(0);
        doubleSpinBox_17->setMaximum(10000000.000000000000000);
        doubleSpinBox_17->setValue(1.000000000000000);
        label_44 = new QLabel(frame_4);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(20, 110, 111, 31));
        doubleSpinBox_18 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_18->setObjectName(QString::fromUtf8("doubleSpinBox_18"));
        doubleSpinBox_18->setGeometry(QRect(140, 110, 91, 31));
        doubleSpinBox_18->setDecimals(0);
        doubleSpinBox_18->setMaximum(10000000.000000000000000);
        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(20, 450, 721, 91));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(3);
        frame_2->setMidLineWidth(1);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 381, 31));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 30, 81, 31));
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(390, 30, 191, 31));
        label_17 = new QLabel(frame_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(810, 290, 81, 22));
        label_17->setFrameShape(QFrame::Box);
        label_17->setScaledContents(true);
        doubleSpinBox_3 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(900, 280, 81, 31));
        doubleSpinBox_3->setDecimals(2);
        doubleSpinBox_3->setMinimum(0.000000000000000);
        doubleSpinBox_3->setMaximum(10000.000000000000000);
        doubleSpinBox_3->setValue(1000.000000000000000);
        doubleSpinBox_4 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(290, 390, 161, 31));
        doubleSpinBox_4->setMinimum(-100000000.000000000000000);
        doubleSpinBox_4->setMaximum(9999999999.000000000000000);
        doubleSpinBox_4->setValue(675.000000000000000);
        doubleSpinBox_6 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        doubleSpinBox_6->setGeometry(QRect(460, 390, 171, 31));
        doubleSpinBox_6->setDecimals(2);
        doubleSpinBox_6->setMinimum(-360.000000000000000);
        doubleSpinBox_6->setMaximum(360.000000000000000);
        doubleSpinBox_6->setSingleStep(0.010000000000000);
        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(690, 10, 341, 261));
        frame_5->setFrameShape(QFrame::Panel);
        frame_5->setFrameShadow(QFrame::Plain);
        comboBox = new QComboBox(frame_5);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 50, 143, 25));
        comboBox->setToolTipDuration(-1);
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBox->setModelColumn(0);
        label_45 = new QLabel(frame_5);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(10, 20, 231, 20));
        comboBox_2 = new QComboBox(frame_5);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(20, 130, 141, 31));
        comboBox_3 = new QComboBox(frame_5);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(20, 210, 141, 31));
        label_46 = new QLabel(frame_5);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(20, 180, 231, 20));
        label_47 = new QLabel(frame_5);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(20, 100, 231, 20));
        doubleSpinBox_20 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_20->setObjectName(QString::fromUtf8("doubleSpinBox_20"));
        doubleSpinBox_20->setGeometry(QRect(350, 290, 161, 31));
        doubleSpinBox_20->setDecimals(3);
        doubleSpinBox_20->setMinimum(-100.000000000000000);
        doubleSpinBox_20->setSingleStep(0.000000000000000);
        doubleSpinBox = new QDoubleSpinBox(frame_4);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(550, 291, 201, 31));
        doubleSpinBox->setDecimals(3);
        doubleSpinBox->setMinimum(-10.000000000000000);
        doubleSpinBox->setMaximum(10.000000000000000);
        doubleSpinBox->setSingleStep(0.001000000000000);
        doubleSpinBox_2 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(830, 391, 201, 31));
        doubleSpinBox_2->setDecimals(3);
        doubleSpinBox_2->setMinimum(-10.000000000000000);
        doubleSpinBox_2->setMaximum(10.000000000000000);
        doubleSpinBox_2->setSingleStep(0.001000000000000);
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(1250, 0, 31, 761));
        scrollArea->setLineWidth(3);
        scrollArea->setMidLineWidth(1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 16, 742));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(740, 10, 441, 51));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(740, 72, 431, 41));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(740, 130, 401, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1259, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        comboBox->setCurrentIndex(0);
        comboBox_2->setCurrentIndex(1);
        comboBox_3->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\220\320\242\320\234\320\236\320\241\320\244\320\225\320\240\320\220", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "V_\320\262\320\265\321\200\321\202\320\270\320\272., \320\274/\321\201", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "V \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202., \320\274/\321\201", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\321\216 T0, C", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\220\320\267\320\270\320\274\321\203\321\202, \320\263\321\200\320\260\320\264.", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "X", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Z", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Y", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Vy", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "Vx", nullptr));
        label_33->setText(QApplication::translate("MainWindow", "Vz", nullptr));
        label_39->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\271 \321\204\320\260\320\267\320\276\320\262\321\213\320\271 \320\262\320\265\320\272\321\202\320\276\321\200", nullptr));
        label_40->setText(QApplication::translate("MainWindow", "\320\226\320\265\320\273\320\260\320\265\320\274\321\213\320\271 \321\204\320\260\320\267\320\276\320\262\321\213\320\271 \320\262\320\265\320\272\321\202\320\276\321\200", nullptr));
        label_41->setText(QApplication::translate("MainWindow", "\320\237\320\236\320\241\320\242\320\240\320\236\320\225\320\235\320\230\320\225 \320\242\320\240\320\220\320\225\320\232\320\242\320\236\320\240\320\230\320\231", nullptr));
        doubleSpinBox_12->setPrefix(QApplication::translate("MainWindow", "Vx: ", nullptr));
        doubleSpinBox_12->setSuffix(QApplication::translate("MainWindow", " m/c", nullptr));
        doubleSpinBox_13->setPrefix(QApplication::translate("MainWindow", "Y: ", nullptr));
        doubleSpinBox_13->setSuffix(QApplication::translate("MainWindow", " m", nullptr));
        doubleSpinBox_14->setPrefix(QApplication::translate("MainWindow", "Nu ", nullptr));
        doubleSpinBox_14->setSuffix(QApplication::translate("MainWindow", "  rad", nullptr));
        doubleSpinBox_16->setPrefix(QApplication::translate("MainWindow", "Gamma ", nullptr));
        doubleSpinBox_16->setSuffix(QApplication::translate("MainWindow", "  rad", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        label_42->setText(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273 \321\201 \320\277\320\265\321\200\320\265\320\264. \321\207\320\270\321\201\320\273\320\260\320\274\320\270:", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_43->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\275\320\260\320\261\320\276\321\200 No :", nullptr));
        label_44->setText(QApplication::translate("MainWindow", "\320\222\321\201\320\265\320\263\320\276 \320\275\320\260\320\261\320\276\321\200\320\276\320\262", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\277\321\203\321\202\321\214 \320\272 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\270 \321\204\320\260\320\271\320\273\320\260\320\274\320\270 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\276\320\262", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273 \320\262\321\200\320\265\320\274", nullptr));
        doubleSpinBox_4->setPrefix(QApplication::translate("MainWindow", "\320\240\320\260\320\264\320\270\321\203\321\201: ", nullptr));
        doubleSpinBox_4->setSuffix(QApplication::translate("MainWindow", "  m", nullptr));
        doubleSpinBox_6->setPrefix(QApplication::translate("MainWindow", "\320\243\320\263. \321\201\320\272\320\276\320\273\321\214. : ", nullptr));
        doubleSpinBox_6->setSuffix(QApplication::translate("MainWindow", "  \321\200\320\260\320\264", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\320\273\320\270\320\275\320\265\320\271\320\275\320\276\320\265", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "\320\222\320\270\321\200\320\260\320\266", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "\320\222\320\270\321\201\320\265\320\275\320\270\320\265", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", nullptr));

        comboBox->setCurrentText(QApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\320\273\320\270\320\275\320\265\320\271\320\275\320\276\320\265", nullptr));
        label_45->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\270\320\277 \321\202\321\200\320\260\320\265\320\272\321\202\320\276\321\200\320\270\320\270 :", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\276\321\211\320\265\320\275\320\275\320\260\321\217", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\275\320\260\321\217", nullptr));

        comboBox_3->setItemText(0, QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\276\321\211\320\265\320\275\320\275\321\213\320\271", nullptr));
        comboBox_3->setItemText(1, QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\275\321\213\320\271", nullptr));

        label_46->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\274\320\276\320\264\320\265\320\273\321\214 \320\262\320\270\320\275\321\202\320\260 :", nullptr));
        label_47->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\270\320\277 \320\260\321\215\321\200\320\276\320\264\320\270\320\275\320\260\320\274\320\270\320\272\320\270 :", nullptr));
        doubleSpinBox_20->setPrefix(QApplication::translate("MainWindow", "Psi: ", nullptr));
        doubleSpinBox_20->setSuffix(QApplication::translate("MainWindow", "   rad", nullptr));
        doubleSpinBox->setPrefix(QApplication::translate("MainWindow", "dPsi:  ", nullptr));
        doubleSpinBox->setSuffix(QApplication::translate("MainWindow", "  rad/c", nullptr));
        doubleSpinBox_2->setPrefix(QApplication::translate("MainWindow", "dPsi0:  ", nullptr));
        doubleSpinBox_2->setSuffix(QApplication::translate("MainWindow", " rad/c", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\236\320\246\320\230\320\244\320\240\320\236\320\222\320\232\320\220 \320\223\320\240\320\220\320\244\320\230\320\232\320\236\320\222 \320\240\320\233\320\255", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273. \320\272\320\276\320\276\321\200\320\264\320\270\320\275\321\202\320\260\321\202 \320\246\320\234 \320\277\320\276 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\265 7.28 ", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
