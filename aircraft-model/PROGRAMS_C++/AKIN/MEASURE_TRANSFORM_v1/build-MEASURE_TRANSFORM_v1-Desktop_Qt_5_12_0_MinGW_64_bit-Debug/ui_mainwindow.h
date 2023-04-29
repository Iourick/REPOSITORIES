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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFrame *frame_3;
    QFrame *frame_10;
    QLabel *label_11;
    QTableWidget *tableWidget_4;
    QFrame *frame_11;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_13;
    QLabel *label_61;
    QFrame *frame_12;
    QDoubleSpinBox *doubleSpinBox_9;
    QDoubleSpinBox *doubleSpinBox_10;
    QLabel *label_12;
    QFrame *frame_7;
    QLabel *label_59;
    QTableWidget *tableWidget_9;
    QDoubleSpinBox *doubleSpinBox_30;
    QDoubleSpinBox *doubleSpinBox_31;
    QCheckBox *checkBox;
    QPushButton *pushButton_3;
    QFrame *frame_13;
    QLabel *label_9;
    QTableWidget *tableWidget_7;
    QFrame *frame_14;
    QLabel *label_13;
    QTableWidget *tableWidget_5;
    QDoubleSpinBox *doubleSpinBox_32;
    QDoubleSpinBox *doubleSpinBox_33;
    QFrame *frame_15;
    QLabel *label_10;
    QTableWidget *tableWidget_8;
    QDoubleSpinBox *doubleSpinBox_34;
    QFrame *frame_16;
    QLabel *label_62;
    QComboBox *comboBox_6;
    QFrame *frame_17;
    QLabel *label_63;
    QComboBox *comboBox_7;
    QFrame *frame_6;
    QPushButton *pushButton_5;
    QLabel *label_26;
    QLineEdit *lineEdit_3;
    QFrame *frame_9;
    QLabel *label_8;
    QTableWidget *tableWidget_6;
    QFrame *frame_18;
    QLabel *label_64;
    QComboBox *comboBox_8;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1073, 828);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        MainWindow->setTabletTracking(true);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(1160, 0, 181, 761));
        scrollArea->setLineWidth(3);
        scrollArea->setMidLineWidth(1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 162, 759));
        scrollArea->setWidget(scrollAreaWidgetContents);
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(30, 10, 1001, 651));
        frame_3->setLayoutDirection(Qt::LeftToRight);
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Plain);
        frame_3->setLineWidth(2);
        frame_3->setMidLineWidth(4);
        frame_10 = new QFrame(frame_3);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setGeometry(QRect(10, 220, 531, 131));
        frame_10->setFrameShape(QFrame::Box);
        frame_10->setFrameShadow(QFrame::Raised);
        frame_10->setLineWidth(2);
        label_11 = new QLabel(frame_10);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(60, 10, 421, 16));
        tableWidget_4 = new QTableWidget(frame_10);
        if (tableWidget_4->columnCount() < 6)
            tableWidget_4->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget_4->rowCount() < 2)
            tableWidget_4->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(1, __qtablewidgetitem7);
        tableWidget_4->setObjectName(QString::fromUtf8("tableWidget_4"));
        tableWidget_4->setGeometry(QRect(10, 30, 511, 91));
        tableWidget_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_4->setRowCount(2);
        tableWidget_4->setColumnCount(6);
        tableWidget_4->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_4->horizontalHeader()->setHighlightSections(false);
        tableWidget_4->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget_4->verticalHeader()->setDefaultSectionSize(30);
        frame_11 = new QFrame(frame_3);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setGeometry(QRect(10, 10, 271, 101));
        frame_11->setFrameShape(QFrame::Box);
        frame_11->setFrameShadow(QFrame::Raised);
        frame_11->setLineWidth(2);
        doubleSpinBox_7 = new QDoubleSpinBox(frame_11);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));
        doubleSpinBox_7->setGeometry(QRect(140, 40, 121, 22));
        doubleSpinBox_7->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_7->setDecimals(1);
        doubleSpinBox_7->setMaximum(100.000000000000000);
        doubleSpinBox_7->setSingleStep(1.000000000000000);
        doubleSpinBox_7->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        doubleSpinBox_7->setValue(10.000000000000000);
        doubleSpinBox_8 = new QDoubleSpinBox(frame_11);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));
        doubleSpinBox_8->setGeometry(QRect(10, 40, 111, 22));
        doubleSpinBox_8->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_8->setMaximum(1000.000000000000000);
        doubleSpinBox_8->setSingleStep(1.000000000000000);
        doubleSpinBox_8->setValue(1.000000000000000);
        doubleSpinBox_13 = new QDoubleSpinBox(frame_11);
        doubleSpinBox_13->setObjectName(QString::fromUtf8("doubleSpinBox_13"));
        doubleSpinBox_13->setGeometry(QRect(70, 70, 121, 22));
        doubleSpinBox_13->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_13->setDecimals(1);
        doubleSpinBox_13->setMaximum(100.000000000000000);
        doubleSpinBox_13->setSingleStep(1.000000000000000);
        doubleSpinBox_13->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        doubleSpinBox_13->setValue(10.000000000000000);
        label_61 = new QLabel(frame_11);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(50, 10, 211, 20));
        frame_12 = new QFrame(frame_3);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setGeometry(QRect(290, 10, 201, 101));
        frame_12->setFrameShape(QFrame::Box);
        frame_12->setFrameShadow(QFrame::Raised);
        frame_12->setLineWidth(2);
        doubleSpinBox_9 = new QDoubleSpinBox(frame_12);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
        doubleSpinBox_9->setGeometry(QRect(10, 40, 171, 22));
        doubleSpinBox_9->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_9->setDecimals(1);
        doubleSpinBox_9->setMaximum(100000000.000000000000000);
        doubleSpinBox_9->setSingleStep(0.010000000000000);
        doubleSpinBox_9->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        doubleSpinBox_9->setValue(6.000000000000000);
        doubleSpinBox_10 = new QDoubleSpinBox(frame_12);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));
        doubleSpinBox_10->setGeometry(QRect(10, 70, 171, 22));
        doubleSpinBox_10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_10->setMaximum(1000.000000000000000);
        doubleSpinBox_10->setSingleStep(0.010000000000000);
        doubleSpinBox_10->setValue(6.000000000000000);
        label_12 = new QLabel(frame_12);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 10, 171, 16));
        frame_7 = new QFrame(frame_3);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(10, 120, 371, 91));
        frame_7->setFrameShape(QFrame::Box);
        frame_7->setFrameShadow(QFrame::Raised);
        frame_7->setLineWidth(2);
        label_59 = new QLabel(frame_7);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(70, 10, 251, 20));
        tableWidget_9 = new QTableWidget(frame_7);
        if (tableWidget_9->columnCount() < 5)
            tableWidget_9->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_9->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_9->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_9->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_9->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_9->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        if (tableWidget_9->rowCount() < 1)
            tableWidget_9->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_9->setVerticalHeaderItem(0, __qtablewidgetitem13);
        tableWidget_9->setObjectName(QString::fromUtf8("tableWidget_9"));
        tableWidget_9->setGeometry(QRect(10, 30, 351, 51));
        tableWidget_9->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_9->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_9->setRowCount(1);
        tableWidget_9->setColumnCount(5);
        tableWidget_9->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_9->horizontalHeader()->setHighlightSections(false);
        tableWidget_9->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget_9->verticalHeader()->setVisible(false);
        tableWidget_9->verticalHeader()->setDefaultSectionSize(30);
        doubleSpinBox_30 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_30->setObjectName(QString::fromUtf8("doubleSpinBox_30"));
        doubleSpinBox_30->setGeometry(QRect(390, 120, 131, 31));
        doubleSpinBox_30->setReadOnly(false);
        doubleSpinBox_30->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_30->setDecimals(1);
        doubleSpinBox_30->setMinimum(0.000000000000000);
        doubleSpinBox_30->setMaximum(1000.000000000000000);
        doubleSpinBox_30->setSingleStep(0.100000000000000);
        doubleSpinBox_30->setValue(0.000000000000000);
        doubleSpinBox_31 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_31->setObjectName(QString::fromUtf8("doubleSpinBox_31"));
        doubleSpinBox_31->setGeometry(QRect(500, 10, 131, 31));
        doubleSpinBox_31->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_31->setDecimals(1);
        doubleSpinBox_31->setMinimum(0.000000000000000);
        doubleSpinBox_31->setMaximum(1000.000000000000000);
        doubleSpinBox_31->setSingleStep(0.100000000000000);
        doubleSpinBox_31->setValue(1.500000000000000);
        checkBox = new QCheckBox(frame_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(500, 50, 131, 31));
        checkBox->setCheckable(true);
        checkBox->setChecked(true);
        pushButton_3 = new QPushButton(frame_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 460, 371, 51));
        frame_13 = new QFrame(frame_3);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setGeometry(QRect(590, 520, 331, 131));
        frame_13->setInputMethodHints(Qt::ImhNone);
        frame_13->setFrameShape(QFrame::Box);
        frame_13->setFrameShadow(QFrame::Raised);
        frame_13->setLineWidth(2);
        label_9 = new QLabel(frame_13);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 10, 221, 16));
        tableWidget_7 = new QTableWidget(frame_13);
        if (tableWidget_7->columnCount() < 4)
            tableWidget_7->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        if (tableWidget_7->rowCount() < 2)
            tableWidget_7->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_7->setVerticalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_7->setVerticalHeaderItem(1, __qtablewidgetitem19);
        tableWidget_7->setObjectName(QString::fromUtf8("tableWidget_7"));
        tableWidget_7->setGeometry(QRect(10, 30, 311, 91));
        tableWidget_7->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_7->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_7->setRowCount(2);
        tableWidget_7->setColumnCount(4);
        tableWidget_7->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_7->horizontalHeader()->setHighlightSections(false);
        tableWidget_7->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget_7->verticalHeader()->setDefaultSectionSize(30);
        frame_14 = new QFrame(frame_3);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setGeometry(QRect(0, 520, 581, 131));
        frame_14->setFrameShape(QFrame::Box);
        frame_14->setFrameShadow(QFrame::Raised);
        frame_14->setLineWidth(2);
        label_13 = new QLabel(frame_14);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(200, 10, 161, 16));
        tableWidget_5 = new QTableWidget(frame_14);
        if (tableWidget_5->columnCount() < 7)
            tableWidget_5->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(4, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(5, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(6, __qtablewidgetitem26);
        if (tableWidget_5->rowCount() < 2)
            tableWidget_5->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(1, __qtablewidgetitem28);
        tableWidget_5->setObjectName(QString::fromUtf8("tableWidget_5"));
        tableWidget_5->setGeometry(QRect(10, 30, 561, 91));
        tableWidget_5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_5->setRowCount(2);
        tableWidget_5->setColumnCount(7);
        tableWidget_5->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_5->horizontalHeader()->setHighlightSections(false);
        tableWidget_5->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget_5->verticalHeader()->setDefaultSectionSize(30);
        doubleSpinBox_32 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_32->setObjectName(QString::fromUtf8("doubleSpinBox_32"));
        doubleSpinBox_32->setGeometry(QRect(390, 160, 151, 31));
        doubleSpinBox_32->setLayoutDirection(Qt::RightToLeft);
        doubleSpinBox_32->setAutoFillBackground(false);
        doubleSpinBox_32->setReadOnly(true);
        doubleSpinBox_32->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_32->setDecimals(1);
        doubleSpinBox_32->setMinimum(0.000000000000000);
        doubleSpinBox_32->setMaximum(10000.000000000000000);
        doubleSpinBox_32->setSingleStep(0.100000000000000);
        doubleSpinBox_32->setValue(99.000000000000000);
        doubleSpinBox_33 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_33->setObjectName(QString::fromUtf8("doubleSpinBox_33"));
        doubleSpinBox_33->setGeometry(QRect(540, 120, 141, 31));
        doubleSpinBox_33->setLayoutDirection(Qt::RightToLeft);
        doubleSpinBox_33->setAutoFillBackground(false);
        doubleSpinBox_33->setReadOnly(true);
        doubleSpinBox_33->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_33->setDecimals(1);
        doubleSpinBox_33->setMinimum(0.000000000000000);
        doubleSpinBox_33->setMaximum(10000.000000000000000);
        doubleSpinBox_33->setSingleStep(0.100000000000000);
        doubleSpinBox_33->setValue(99.000000000000000);
        frame_15 = new QFrame(frame_3);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setGeometry(QRect(690, 80, 261, 131));
        frame_15->setFrameShape(QFrame::Box);
        frame_15->setFrameShadow(QFrame::Raised);
        frame_15->setLineWidth(2);
        label_10 = new QLabel(frame_15);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 10, 161, 16));
        tableWidget_8 = new QTableWidget(frame_15);
        if (tableWidget_8->columnCount() < 3)
            tableWidget_8->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(1, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(2, __qtablewidgetitem31);
        if (tableWidget_8->rowCount() < 2)
            tableWidget_8->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_8->setVerticalHeaderItem(0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_8->setVerticalHeaderItem(1, __qtablewidgetitem33);
        tableWidget_8->setObjectName(QString::fromUtf8("tableWidget_8"));
        tableWidget_8->setGeometry(QRect(10, 30, 241, 91));
        tableWidget_8->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_8->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_8->setRowCount(2);
        tableWidget_8->setColumnCount(3);
        tableWidget_8->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_8->horizontalHeader()->setHighlightSections(false);
        tableWidget_8->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget_8->verticalHeader()->setDefaultSectionSize(30);
        doubleSpinBox_34 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_34->setObjectName(QString::fromUtf8("doubleSpinBox_34"));
        doubleSpinBox_34->setGeometry(QRect(550, 160, 131, 31));
        doubleSpinBox_34->setLayoutDirection(Qt::RightToLeft);
        doubleSpinBox_34->setAutoFillBackground(false);
        doubleSpinBox_34->setReadOnly(false);
        doubleSpinBox_34->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_34->setDecimals(6);
        doubleSpinBox_34->setMinimum(-10.000000000000000);
        doubleSpinBox_34->setMaximum(10000.000000000000000);
        doubleSpinBox_34->setSingleStep(0.000010000000000);
        doubleSpinBox_34->setValue(2.000000000000000);
        frame_16 = new QFrame(frame_3);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setGeometry(QRect(640, 10, 151, 61));
        frame_16->setFrameShape(QFrame::Panel);
        frame_16->setFrameShadow(QFrame::Raised);
        label_62 = new QLabel(frame_16);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(0, 0, 141, 20));
        comboBox_6 = new QComboBox(frame_16);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setGeometry(QRect(20, 30, 123, 25));
        comboBox_6->setToolTipDuration(-1);
        comboBox_6->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBox_6->setModelColumn(0);
        frame_17 = new QFrame(frame_3);
        frame_17->setObjectName(QString::fromUtf8("frame_17"));
        frame_17->setGeometry(QRect(800, 10, 151, 61));
        frame_17->setFrameShape(QFrame::Panel);
        frame_17->setFrameShadow(QFrame::Raised);
        label_63 = new QLabel(frame_17);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(10, 0, 131, 20));
        comboBox_7 = new QComboBox(frame_17);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));
        comboBox_7->setGeometry(QRect(20, 30, 62, 25));
        comboBox_7->setToolTipDuration(-1);
        comboBox_7->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBox_7->setModelColumn(0);
        frame_6 = new QFrame(frame_3);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(10, 400, 941, 51));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Plain);
        frame_6->setLineWidth(3);
        frame_6->setMidLineWidth(1);
        pushButton_5 = new QPushButton(frame_6);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(810, 10, 111, 31));
        label_26 = new QLabel(frame_6);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 10, 291, 20));
        lineEdit_3 = new QLineEdit(frame_6);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(330, 10, 471, 31));
        frame_9 = new QFrame(frame_3);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setGeometry(QRect(540, 220, 291, 131));
        frame_9->setFrameShape(QFrame::Box);
        frame_9->setFrameShadow(QFrame::Raised);
        frame_9->setLineWidth(2);
        label_8 = new QLabel(frame_9);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 10, 181, 16));
        tableWidget_6 = new QTableWidget(frame_9);
        if (tableWidget_6->columnCount() < 3)
            tableWidget_6->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(1, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(2, __qtablewidgetitem36);
        if (tableWidget_6->rowCount() < 2)
            tableWidget_6->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_6->setVerticalHeaderItem(0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_6->setVerticalHeaderItem(1, __qtablewidgetitem38);
        tableWidget_6->setObjectName(QString::fromUtf8("tableWidget_6"));
        tableWidget_6->setGeometry(QRect(10, 30, 271, 91));
        tableWidget_6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_6->setRowCount(2);
        tableWidget_6->setColumnCount(3);
        tableWidget_6->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_6->horizontalHeader()->setHighlightSections(false);
        tableWidget_6->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget_6->verticalHeader()->setVisible(true);
        tableWidget_6->verticalHeader()->setDefaultSectionSize(30);
        frame_18 = new QFrame(frame_3);
        frame_18->setObjectName(QString::fromUtf8("frame_18"));
        frame_18->setGeometry(QRect(840, 220, 151, 81));
        frame_18->setFrameShape(QFrame::Box);
        frame_18->setFrameShadow(QFrame::Sunken);
        frame_18->setLineWidth(2);
        frame_18->setMidLineWidth(2);
        label_64 = new QLabel(frame_18);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        label_64->setGeometry(QRect(10, 10, 131, 20));
        comboBox_8 = new QComboBox(frame_18);
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->setObjectName(QString::fromUtf8("comboBox_8"));
        comboBox_8->setGeometry(QRect(30, 40, 69, 25));
        comboBox_8->setToolTipDuration(-1);
        comboBox_8->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBox_8->setModelColumn(0);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1073, 21));
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

        comboBox_6->setCurrentIndex(0);
        comboBox_7->setCurrentIndex(0);
        comboBox_8->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\253 \320\237\320\236\320\227\320\230\320\246\320\230\320\236\320\235\320\230\320\240\320\236\320\222\320\220\320\235\320\230\320\257 \320\220\320\235\320\242\320\225\320\235\320\235\320\253 \320\222 \320\237\320\241\320\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Bet", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_4->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Eps", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_4->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Alf", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_4->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202   (\320\274, \320\263\321\200.)", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_4->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\236\321\206 (\320\274, \320\263\321\200\320\260\320\264)", nullptr));
        doubleSpinBox_7->setPrefix(QApplication::translate("MainWindow", " \320\232\320\243: ", nullptr));
        doubleSpinBox_7->setSuffix(QApplication::translate("MainWindow", " \320\274\321\200\320\260\320\264", nullptr));
        doubleSpinBox_8->setPrefix(QApplication::translate("MainWindow", " dT: ", nullptr));
        doubleSpinBox_8->setSuffix(QApplication::translate("MainWindow", " \320\274\321\201", nullptr));
        doubleSpinBox_13->setPrefix(QApplication::translate("MainWindow", "\320\243\320\234: ", nullptr));
        doubleSpinBox_13->setSuffix(QApplication::translate("MainWindow", " \320\274\321\200\320\260\320\264", nullptr));
        label_61->setText(QApplication::translate("MainWindow", "\320\237\320\236\320\223\320\240\320\225\320\250\320\235\320\236\320\241\320\242\320\230  \320\220\320\235\320\242\320\225\320\235\320\235\320\253", nullptr));
        doubleSpinBox_9->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 Q.:   ", nullptr));
        doubleSpinBox_9->setSuffix(QApplication::translate("MainWindow", " \320\274\321\200\320\260\320\264", nullptr));
        doubleSpinBox_10->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 Psi,Tet.: ", nullptr));
        doubleSpinBox_10->setSuffix(QApplication::translate("MainWindow", " \320\274\321\200\320\260\320\264", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\237\320\236\320\223\320\240\320\225\320\250\320\235\320\236\320\241\320\242\320\230 \320\241\320\230\320\235\320\241", nullptr));
        label_59->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\265 \320\277\320\276\320\273\320\276\320\266. \320\272\320\276\321\200\320\260\320\261\320\273\321\217 \320\223\320\241\320\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_9->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "X, \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_9->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Y, \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_9->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Z, \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_9->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "\320\232\321\203\321\200\321\201, \320\263\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_9->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "V, \320\274/\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_9->verticalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "X", nullptr));
        doubleSpinBox_30->setPrefix(QApplication::translate("MainWindow", "\320\222\320\265\321\202\320\265\321\200: ", nullptr));
        doubleSpinBox_30->setSuffix(QApplication::translate("MainWindow", " \320\274/\321\201", nullptr));
        doubleSpinBox_31->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 GPS: ", nullptr));
        doubleSpinBox_31->setSuffix(QApplication::translate("MainWindow", " \320\274", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\320\221\320\225\320\227 \320\250\320\243\320\234\320\236\320\222", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "RUN", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\321\200\320\265\320\275\320\270\320\265 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\274\320\260\321\217\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_7->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "T", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_7->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_7->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_7->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_7->verticalHeaderItem(0);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_7->verticalHeaderItem(1);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "\320\236\321\206", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\272\320\276\321\200\320\260\320\261\320\273\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "T", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_5->horizontalHeaderItem(1);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_5->horizontalHeaderItem(2);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_5->horizontalHeaderItem(3);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_5->horizontalHeaderItem(4);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "Q", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_5->horizontalHeaderItem(5);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "Psi", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_5->horizontalHeaderItem(6);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "Tet", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_5->verticalHeaderItem(0);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\264\320\260\321\207\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_5->verticalHeaderItem(1);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\265\320\274", nullptr));
        doubleSpinBox_32->setPrefix(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201. \320\263\320\273\321\203\320\261.: ", nullptr));
        doubleSpinBox_32->setSuffix(QApplication::translate("MainWindow", " \320\274", nullptr));
        doubleSpinBox_33->setPrefix(QApplication::translate("MainWindow", "R \320\277\321\200\320\270\320\265\320\274\320\260: ", nullptr));
        doubleSpinBox_33->setSuffix(QApplication::translate("MainWindow", " \320\274", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\320\237\320\236\320\233\320\236\320\226. GPS \320\222 \320\237\320\241\320\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_8->horizontalHeaderItem(0);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_8->horizontalHeaderItem(1);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_8->horizontalHeaderItem(2);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_8->verticalHeaderItem(0);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_8->verticalHeaderItem(1);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "\320\236\321\206", nullptr));
        doubleSpinBox_34->setPrefix(QApplication::translate("MainWindow", "T  \320\276\320\261\321\200\320\260\320\261: ", nullptr));
        doubleSpinBox_34->setSuffix(QString());
        label_62->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\260\320\273\321\214\320\275\321\213\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214:", nullptr));
        comboBox_6->setItemText(0, QApplication::translate("MainWindow", "\320\241\320\276\320\262\320\277\320\260\320\264\320\260\320\265\321\202", nullptr));
        comboBox_6->setItemText(1, QApplication::translate("MainWindow", "+ 1%", nullptr));
        comboBox_6->setItemText(2, QApplication::translate("MainWindow", "-1%", nullptr));
        comboBox_6->setItemText(3, QApplication::translate("MainWindow", "\320\241\320\270\320\263\320\274\320\260 0,33%", nullptr));
        comboBox_6->setItemText(4, QApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271", nullptr));

        comboBox_6->setCurrentText(QApplication::translate("MainWindow", "\320\241\320\276\320\262\320\277\320\260\320\264\320\260\320\265\321\202", nullptr));
        label_63->setText(QApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260\321\202 <*.000>", nullptr));
        comboBox_7->setItemText(0, QApplication::translate("MainWindow", "1 var", nullptr));
        comboBox_7->setItemText(1, QApplication::translate("MainWindow", "2 var", nullptr));

        comboBox_7->setCurrentText(QApplication::translate("MainWindow", "1 var", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\320\222\320\253\320\221\320\236\320\240 \320\244\320\220\320\231\320\233\320\220 <*.000> \320\241 \320\237\320\240\320\236\320\244\320\230\320\233\320\225\320\234", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274.\320\264\320\262\320\270\320\266.\320\274\320\260\321\217\320\272\320\260 \320\223\320\241\320\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_6->horizontalHeaderItem(0);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_6->horizontalHeaderItem(1);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_6->horizontalHeaderItem(2);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_6->verticalHeaderItem(0);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\276\320\266. ", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_6->verticalHeaderItem(1);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200.", nullptr));
        label_64->setText(QApplication::translate("MainWindow", "\320\232\320\243\320\224\320\220 \320\237\320\225\320\240\320\225\320\241\320\247\320\225\320\242", nullptr));
        comboBox_8->setItemText(0, QApplication::translate("MainWindow", "\320\223\320\241\320\232", nullptr));
        comboBox_8->setItemText(1, QApplication::translate("MainWindow", "\320\220\320\241\320\237\320\232", nullptr));

        comboBox_8->setCurrentText(QApplication::translate("MainWindow", "\320\223\320\241\320\232", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
