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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFrame *frame_4;
    QFrame *frame_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label_41;
    QPushButton *pushButton_3;
    QFrame *frame;
    QPushButton *pushButton_4;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QFrame *frame_3;
    QPushButton *pushButton_5;
    QDoubleSpinBox *doubleSpinBox_12;
    QDoubleSpinBox *doubleSpinBox_13;
    QDoubleSpinBox *doubleSpinBox_14;
    QDoubleSpinBox *doubleSpinBox_15;
    QSpinBox *spinBox_2;
    QDoubleSpinBox *doubleSpinBox_11;
    QFrame *frame_5;
    QPushButton *pushButton_6;
    QDoubleSpinBox *doubleSpinBox_16;
    QDoubleSpinBox *doubleSpinBox_17;
    QDoubleSpinBox *doubleSpinBox_18;
    QDoubleSpinBox *doubleSpinBox_19;
    QSpinBox *spinBox_3;
    QDoubleSpinBox *doubleSpinBox_20;
    QDoubleSpinBox *doubleSpinBox_21;
    QDoubleSpinBox *doubleSpinBox_22;
    QDoubleSpinBox *doubleSpinBox_23;
    QDoubleSpinBox *doubleSpinBox_24;
    QPushButton *pushButton_7;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1272, 797);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        MainWindow->setTabletTracking(true);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(1290, 0, 31, 761));
        scrollArea->setLineWidth(3);
        scrollArea->setMidLineWidth(1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 16, 738));
        scrollArea->setWidget(scrollAreaWidgetContents);
        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(40, 70, 1221, 651));
        frame_4->setFrameShape(QFrame::Panel);
        frame_4->setFrameShadow(QFrame::Plain);
        frame_4->setLineWidth(3);
        frame_4->setMidLineWidth(3);
        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(30, 70, 861, 91));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(3);
        frame_2->setMidLineWidth(1);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 271, 31));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(520, 30, 81, 31));
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(310, 30, 191, 31));
        label_41 = new QLabel(frame_4);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(260, 30, 131, 20));
        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 180, 191, 41));
        frame = new QFrame(frame_4);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(310, 170, 291, 451));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Plain);
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 110, 181, 41));
        doubleSpinBox_4 = new QDoubleSpinBox(frame);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(20, 200, 231, 22));
        doubleSpinBox_4->setReadOnly(true);
        doubleSpinBox_4->setDecimals(4);
        doubleSpinBox_4->setMaximum(1000000.000000000000000);
        doubleSpinBox_4->setValue(0.000000000000000);
        doubleSpinBox_5 = new QDoubleSpinBox(frame);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        doubleSpinBox_5->setGeometry(QRect(20, 160, 231, 22));
        doubleSpinBox_5->setMaximum(200.000000000000000);
        doubleSpinBox_5->setValue(0.000000000000000);
        doubleSpinBox_6 = new QDoubleSpinBox(frame);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        doubleSpinBox_6->setGeometry(QRect(20, 280, 231, 22));
        doubleSpinBox_6->setReadOnly(true);
        doubleSpinBox_6->setDecimals(4);
        doubleSpinBox_6->setMinimum(-100000000.000000000000000);
        doubleSpinBox_6->setMaximum(1000000.000000000000000);
        doubleSpinBox_6->setValue(0.000000000000000);
        doubleSpinBox_7 = new QDoubleSpinBox(frame);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));
        doubleSpinBox_7->setGeometry(QRect(20, 240, 231, 22));
        doubleSpinBox_7->setReadOnly(true);
        doubleSpinBox_7->setDecimals(4);
        doubleSpinBox_7->setMinimum(-100000000.000000000000000);
        doubleSpinBox_7->setMaximum(1000000.000000000000000);
        doubleSpinBox_7->setValue(0.000000000000000);
        doubleSpinBox_8 = new QDoubleSpinBox(frame);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));
        doubleSpinBox_8->setGeometry(QRect(20, 320, 231, 22));
        doubleSpinBox_8->setReadOnly(true);
        doubleSpinBox_8->setDecimals(2);
        doubleSpinBox_8->setMinimum(-1000000.000000000000000);
        doubleSpinBox_8->setMaximum(1000000.000000000000000);
        doubleSpinBox_8->setValue(0.000000000000000);
        doubleSpinBox_9 = new QDoubleSpinBox(frame);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
        doubleSpinBox_9->setGeometry(QRect(20, 360, 231, 22));
        doubleSpinBox_9->setReadOnly(true);
        doubleSpinBox_9->setDecimals(3);
        doubleSpinBox_9->setMaximum(1000000.000000000000000);
        doubleSpinBox_9->setValue(0.000000000000000);
        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 400, 231, 22));
        doubleSpinBox = new QDoubleSpinBox(frame);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(30, 10, 231, 22));
        doubleSpinBox->setMaximum(1000.000000000000000);
        doubleSpinBox->setValue(100.000000000000000);
        doubleSpinBox_2 = new QDoubleSpinBox(frame);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(30, 40, 231, 22));
        doubleSpinBox_2->setMaximum(1000000.000000000000000);
        doubleSpinBox_2->setValue(720.000000000000000);
        doubleSpinBox_3 = new QDoubleSpinBox(frame);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(30, 70, 231, 22));
        doubleSpinBox_3->setMaximum(1000000.000000000000000);
        doubleSpinBox_3->setValue(18000.000000000000000);
        frame_3 = new QFrame(frame_4);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(630, 170, 291, 321));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Plain);
        pushButton_5 = new QPushButton(frame_3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 70, 181, 41));
        doubleSpinBox_12 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_12->setObjectName(QString::fromUtf8("doubleSpinBox_12"));
        doubleSpinBox_12->setGeometry(QRect(10, 160, 261, 22));
        doubleSpinBox_12->setReadOnly(true);
        doubleSpinBox_12->setDecimals(4);
        doubleSpinBox_12->setMinimum(-100000000.000000000000000);
        doubleSpinBox_12->setMaximum(1000000.000000000000000);
        doubleSpinBox_12->setValue(0.000000000000000);
        doubleSpinBox_13 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_13->setObjectName(QString::fromUtf8("doubleSpinBox_13"));
        doubleSpinBox_13->setGeometry(QRect(10, 120, 261, 22));
        doubleSpinBox_13->setReadOnly(true);
        doubleSpinBox_13->setDecimals(4);
        doubleSpinBox_13->setMinimum(-100000000.000000000000000);
        doubleSpinBox_13->setMaximum(1000000.000000000000000);
        doubleSpinBox_13->setValue(0.000000000000000);
        doubleSpinBox_14 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_14->setObjectName(QString::fromUtf8("doubleSpinBox_14"));
        doubleSpinBox_14->setGeometry(QRect(10, 200, 261, 22));
        doubleSpinBox_14->setReadOnly(true);
        doubleSpinBox_14->setDecimals(5);
        doubleSpinBox_14->setMinimum(-1000000.000000000000000);
        doubleSpinBox_14->setMaximum(1000000.000000000000000);
        doubleSpinBox_14->setValue(0.000000000000000);
        doubleSpinBox_15 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_15->setObjectName(QString::fromUtf8("doubleSpinBox_15"));
        doubleSpinBox_15->setGeometry(QRect(10, 240, 261, 22));
        doubleSpinBox_15->setReadOnly(true);
        doubleSpinBox_15->setDecimals(3);
        doubleSpinBox_15->setMaximum(1000000.000000000000000);
        doubleSpinBox_15->setValue(0.000000000000000);
        spinBox_2 = new QSpinBox(frame_3);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(10, 280, 261, 22));
        doubleSpinBox_11 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_11->setObjectName(QString::fromUtf8("doubleSpinBox_11"));
        doubleSpinBox_11->setGeometry(QRect(10, 20, 231, 31));
        doubleSpinBox_11->setMaximum(1000000.000000000000000);
        doubleSpinBox_11->setValue(12.699999999999999);
        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(940, 80, 261, 551));
        frame_5->setFrameShape(QFrame::Panel);
        frame_5->setFrameShadow(QFrame::Plain);
        pushButton_6 = new QPushButton(frame_5);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 120, 181, 41));
        doubleSpinBox_16 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_16->setObjectName(QString::fromUtf8("doubleSpinBox_16"));
        doubleSpinBox_16->setGeometry(QRect(20, 380, 231, 22));
        doubleSpinBox_16->setReadOnly(true);
        doubleSpinBox_16->setDecimals(1);
        doubleSpinBox_16->setMinimum(-100000000.000000000000000);
        doubleSpinBox_16->setMaximum(1000000.000000000000000);
        doubleSpinBox_16->setValue(0.000000000000000);
        doubleSpinBox_17 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_17->setObjectName(QString::fromUtf8("doubleSpinBox_17"));
        doubleSpinBox_17->setGeometry(QRect(20, 340, 231, 22));
        doubleSpinBox_17->setReadOnly(true);
        doubleSpinBox_17->setDecimals(2);
        doubleSpinBox_17->setMinimum(-100000000.000000000000000);
        doubleSpinBox_17->setMaximum(1000000.000000000000000);
        doubleSpinBox_17->setValue(0.000000000000000);
        doubleSpinBox_18 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_18->setObjectName(QString::fromUtf8("doubleSpinBox_18"));
        doubleSpinBox_18->setGeometry(QRect(20, 420, 231, 22));
        doubleSpinBox_18->setReadOnly(true);
        doubleSpinBox_18->setDecimals(2);
        doubleSpinBox_18->setMinimum(-1000000.000000000000000);
        doubleSpinBox_18->setMaximum(1000000.000000000000000);
        doubleSpinBox_18->setValue(0.000000000000000);
        doubleSpinBox_19 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_19->setObjectName(QString::fromUtf8("doubleSpinBox_19"));
        doubleSpinBox_19->setGeometry(QRect(20, 460, 231, 22));
        doubleSpinBox_19->setReadOnly(true);
        doubleSpinBox_19->setDecimals(3);
        doubleSpinBox_19->setMaximum(1000000.000000000000000);
        doubleSpinBox_19->setValue(0.000000000000000);
        spinBox_3 = new QSpinBox(frame_5);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(20, 500, 231, 22));
        doubleSpinBox_20 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_20->setObjectName(QString::fromUtf8("doubleSpinBox_20"));
        doubleSpinBox_20->setGeometry(QRect(10, 20, 231, 31));
        doubleSpinBox_20->setMaximum(1000000.000000000000000);
        doubleSpinBox_20->setValue(30.000000000000000);
        doubleSpinBox_21 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_21->setObjectName(QString::fromUtf8("doubleSpinBox_21"));
        doubleSpinBox_21->setGeometry(QRect(10, 70, 231, 31));
        doubleSpinBox_21->setDecimals(1);
        doubleSpinBox_21->setMaximum(1000000.000000000000000);
        doubleSpinBox_21->setValue(127.000000000000000);
        doubleSpinBox_22 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_22->setObjectName(QString::fromUtf8("doubleSpinBox_22"));
        doubleSpinBox_22->setGeometry(QRect(20, 300, 231, 22));
        doubleSpinBox_22->setReadOnly(true);
        doubleSpinBox_22->setDecimals(2);
        doubleSpinBox_22->setMinimum(-100000000.000000000000000);
        doubleSpinBox_22->setMaximum(1000000.000000000000000);
        doubleSpinBox_22->setValue(0.000000000000000);
        doubleSpinBox_23 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_23->setObjectName(QString::fromUtf8("doubleSpinBox_23"));
        doubleSpinBox_23->setGeometry(QRect(20, 220, 231, 22));
        doubleSpinBox_23->setReadOnly(true);
        doubleSpinBox_23->setDecimals(4);
        doubleSpinBox_23->setMinimum(-100000000.000000000000000);
        doubleSpinBox_23->setMaximum(1000000.000000000000000);
        doubleSpinBox_23->setValue(0.000000000000000);
        doubleSpinBox_24 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_24->setObjectName(QString::fromUtf8("doubleSpinBox_24"));
        doubleSpinBox_24->setGeometry(QRect(20, 260, 231, 22));
        doubleSpinBox_24->setReadOnly(true);
        doubleSpinBox_24->setDecimals(4);
        doubleSpinBox_24->setMinimum(-100000000.000000000000000);
        doubleSpinBox_24->setMaximum(1000000.000000000000000);
        doubleSpinBox_24->setValue(0.000000000000000);
        pushButton_7 = new QPushButton(frame_4);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(30, 240, 191, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1272, 26));
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

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\277\321\203\321\202\321\214 \320\272 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\270 \321\204\320\260\320\271\320\273\320\260\320\274\320\270 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\276\320\262", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_41->setText(QApplication::translate("MainWindow", "CALCULATIONS", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "DO SECTIONS GRAPHS", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "ANALYSIS WIND", nullptr));
        doubleSpinBox_4->setPrefix(QApplication::translate("MainWindow", "JY:  ", nullptr));
        doubleSpinBox_4->setSuffix(QApplication::translate("MainWindow", " \320\272\320\263*\320\274*\320\274", nullptr));
        doubleSpinBox_5->setPrefix(QApplication::translate("MainWindow", "\320\234:  ", nullptr));
        doubleSpinBox_5->setSuffix(QApplication::translate("MainWindow", "  \320\272\320\263", nullptr));
        doubleSpinBox_6->setPrefix(QApplication::translate("MainWindow", "M:   ", nullptr));
        doubleSpinBox_6->setSuffix(QApplication::translate("MainWindow", "  \320\235*\320\234", nullptr));
        doubleSpinBox_7->setPrefix(QApplication::translate("MainWindow", "F:  ", nullptr));
        doubleSpinBox_7->setSuffix(QApplication::translate("MainWindow", "  \320\235", nullptr));
        doubleSpinBox_8->setPrefix(QApplication::translate("MainWindow", "MAX(Sig/ [Sig]):  ", nullptr));
        doubleSpinBox_8->setSuffix(QString());
        doubleSpinBox_9->setPrefix(QApplication::translate("MainWindow", "Z \320\276\320\277\320\260\321\201\320\275\320\276\320\265:   ", nullptr));
        doubleSpinBox_9->setSuffix(QApplication::translate("MainWindow", " \320\274", nullptr));
        spinBox->setSuffix(QString());
        spinBox->setPrefix(QApplication::translate("MainWindow", " Section No : ", nullptr));
        doubleSpinBox->setPrefix(QApplication::translate("MainWindow", " Wind V  :  ", nullptr));
        doubleSpinBox->setSuffix(QApplication::translate("MainWindow", "  m/s", nullptr));
        doubleSpinBox_2->setPrefix(QApplication::translate("MainWindow", "Omega:  ", nullptr));
        doubleSpinBox_2->setSuffix(QApplication::translate("MainWindow", "  grad/s", nullptr));
        doubleSpinBox_3->setPrefix(QApplication::translate("MainWindow", "Om aceller:  ", nullptr));
        doubleSpinBox_3->setSuffix(QApplication::translate("MainWindow", "  grad/s/s", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "ANALYSIS ICE", nullptr));
        doubleSpinBox_12->setPrefix(QApplication::translate("MainWindow", "M:   ", nullptr));
        doubleSpinBox_12->setSuffix(QApplication::translate("MainWindow", "  \320\235*\320\234", nullptr));
        doubleSpinBox_13->setPrefix(QApplication::translate("MainWindow", "F:  ", nullptr));
        doubleSpinBox_13->setSuffix(QApplication::translate("MainWindow", "  \320\235", nullptr));
        doubleSpinBox_14->setPrefix(QApplication::translate("MainWindow", "MAX(Sig/ [Sig]):  ", nullptr));
        doubleSpinBox_14->setSuffix(QString());
        doubleSpinBox_15->setPrefix(QApplication::translate("MainWindow", "Z \320\276\320\277\320\260\321\201\320\275\320\276\320\265:   ", nullptr));
        doubleSpinBox_15->setSuffix(QApplication::translate("MainWindow", " \320\274", nullptr));
        spinBox_2->setSuffix(QString());
        spinBox_2->setPrefix(QApplication::translate("MainWindow", " Section No : ", nullptr));
        doubleSpinBox_11->setPrefix(QApplication::translate("MainWindow", "P: ", nullptr));
        doubleSpinBox_11->setSuffix(QApplication::translate("MainWindow", "  \320\272\320\263\321\201/\320\274/\320\274", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "ANALYSIS HAIL", nullptr));
        doubleSpinBox_16->setPrefix(QApplication::translate("MainWindow", "Eff H:   ", nullptr));
        doubleSpinBox_16->setSuffix(QApplication::translate("MainWindow", " m", nullptr));
        doubleSpinBox_17->setPrefix(QApplication::translate("MainWindow", "V0:  ", nullptr));
        doubleSpinBox_17->setSuffix(QApplication::translate("MainWindow", " m/c", nullptr));
        doubleSpinBox_18->setPrefix(QApplication::translate("MainWindow", "MAX(Sig/ [Sig]):  ", nullptr));
        doubleSpinBox_18->setSuffix(QString());
        doubleSpinBox_19->setPrefix(QApplication::translate("MainWindow", "Z \320\276\320\277\320\260\321\201\320\275\320\276\320\265:   ", nullptr));
        doubleSpinBox_19->setSuffix(QApplication::translate("MainWindow", " \320\274", nullptr));
        spinBox_3->setSuffix(QString());
        spinBox_3->setPrefix(QApplication::translate("MainWindow", " Section No : ", nullptr));
        doubleSpinBox_20->setPrefix(QApplication::translate("MainWindow", "Diam: ", nullptr));
        doubleSpinBox_20->setSuffix(QApplication::translate("MainWindow", "  mm", nullptr));
        doubleSpinBox_21->setPrefix(QApplication::translate("MainWindow", "Z Blow: ", nullptr));
        doubleSpinBox_21->setSuffix(QApplication::translate("MainWindow", " cm", nullptr));
        doubleSpinBox_22->setPrefix(QApplication::translate("MainWindow", "Mass:  ", nullptr));
        doubleSpinBox_22->setSuffix(QApplication::translate("MainWindow", " gr", nullptr));
        doubleSpinBox_23->setPrefix(QApplication::translate("MainWindow", "F:  ", nullptr));
        doubleSpinBox_23->setSuffix(QApplication::translate("MainWindow", "  \320\235", nullptr));
        doubleSpinBox_24->setPrefix(QApplication::translate("MainWindow", "M:   ", nullptr));
        doubleSpinBox_24->setSuffix(QApplication::translate("MainWindow", "  \320\235*\320\234", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "PICT_1", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
