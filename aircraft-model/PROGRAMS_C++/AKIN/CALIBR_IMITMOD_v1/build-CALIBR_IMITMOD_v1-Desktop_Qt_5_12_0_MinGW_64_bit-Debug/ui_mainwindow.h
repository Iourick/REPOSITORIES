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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
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
    QFrame *frame_9;
    QLabel *label_8;
    QTableWidget *tableWidget_6;
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
    QDoubleSpinBox *doubleSpinBox_11;
    QDoubleSpinBox *doubleSpinBox_12;
    QFrame *frame_7;
    QLabel *label_59;
    QComboBox *comboBox_4;
    QDoubleSpinBox *doubleSpinBox_30;
    QCheckBox *checkBox;
    QDoubleSpinBox *doubleSpinBox_14;
    QPushButton *pushButton_3;
    QFrame *frame_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QFrame *frame_13;
    QLabel *label_9;
    QTableWidget *tableWidget_7;
    QFrame *frame_14;
    QLabel *label_13;
    QTableWidget *tableWidget_5;
    QFrame *frame_8;
    QLabel *label_60;
    QComboBox *comboBox_5;
    QFrame *frame_6;
    QPushButton *pushButton_5;
    QLabel *label_26;
    QLineEdit *lineEdit_3;
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
    QDoubleSpinBox *doubleSpinBox_15;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButtonStartTask;
    QLabel *labelTaskInfo1;
    QSpacerItem *horizontalSpacer;
    QLabel *labelTaskInfo3;
    QProgressBar *progressBar;
    QLabel *labelTaskInfo4;
    QPushButton *pushButtonStopTask;
    QLabel *labelTaskInfo2;
    QDoubleSpinBox *doubleSpinBox_31;
    QGroupBox *groupBox_3;
    QComboBox *comboBox_8;
    QDoubleSpinBox *doubleSpinBox_16;
    QDoubleSpinBox *doubleSpinBox_17;
    QGroupBox *groupBox_4;
    QDoubleSpinBox *doubleSpinBox_19;
    QDoubleSpinBox *doubleSpinBox_32;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1160, 828);
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
        frame_3->setGeometry(QRect(10, 10, 1151, 771));
        frame_3->setLayoutDirection(Qt::LeftToRight);
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Plain);
        frame_3->setLineWidth(2);
        frame_3->setMidLineWidth(4);
        frame_9 = new QFrame(frame_3);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setGeometry(QRect(10, 150, 311, 141));
        frame_9->setFrameShape(QFrame::Box);
        frame_9->setFrameShadow(QFrame::Raised);
        frame_9->setLineWidth(4);
        label_8 = new QLabel(frame_9);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(80, 10, 211, 16));
        tableWidget_6 = new QTableWidget(frame_9);
        if (tableWidget_6->columnCount() < 3)
            tableWidget_6->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget_6->rowCount() < 3)
            tableWidget_6->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_6->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_6->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_6->setVerticalHeaderItem(2, __qtablewidgetitem5);
        tableWidget_6->setObjectName(QString::fromUtf8("tableWidget_6"));
        tableWidget_6->setGeometry(QRect(10, 30, 291, 101));
        tableWidget_6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_6->setRowCount(3);
        tableWidget_6->setColumnCount(3);
        tableWidget_6->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_6->horizontalHeader()->setHighlightSections(false);
        tableWidget_6->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget_6->verticalHeader()->setDefaultSectionSize(23);
        frame_10 = new QFrame(frame_3);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setGeometry(QRect(330, 150, 551, 141));
        frame_10->setFrameShape(QFrame::Box);
        frame_10->setFrameShadow(QFrame::Raised);
        frame_10->setLineWidth(4);
        label_11 = new QLabel(frame_10);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(90, 10, 401, 16));
        tableWidget_4 = new QTableWidget(frame_10);
        if (tableWidget_4->columnCount() < 6)
            tableWidget_4->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        if (tableWidget_4->rowCount() < 3)
            tableWidget_4->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(2, __qtablewidgetitem14);
        tableWidget_4->setObjectName(QString::fromUtf8("tableWidget_4"));
        tableWidget_4->setGeometry(QRect(10, 30, 531, 101));
        tableWidget_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_4->setRowCount(3);
        tableWidget_4->setColumnCount(6);
        tableWidget_4->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_4->horizontalHeader()->setHighlightSections(false);
        tableWidget_4->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget_4->verticalHeader()->setDefaultSectionSize(23);
        frame_11 = new QFrame(frame_3);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setGeometry(QRect(170, 10, 271, 101));
        frame_11->setFrameShape(QFrame::Box);
        frame_11->setFrameShadow(QFrame::Raised);
        frame_11->setLineWidth(4);
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
        label_61->setGeometry(QRect(50, 10, 181, 20));
        frame_12 = new QFrame(frame_3);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setGeometry(QRect(440, 10, 321, 101));
        frame_12->setFrameShape(QFrame::Box);
        frame_12->setFrameShadow(QFrame::Raised);
        frame_12->setLineWidth(4);
        doubleSpinBox_9 = new QDoubleSpinBox(frame_12);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
        doubleSpinBox_9->setGeometry(QRect(10, 40, 151, 22));
        doubleSpinBox_9->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_9->setDecimals(1);
        doubleSpinBox_9->setMaximum(100.000000000000000);
        doubleSpinBox_9->setSingleStep(0.010000000000000);
        doubleSpinBox_9->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        doubleSpinBox_9->setValue(10.000000000000000);
        doubleSpinBox_10 = new QDoubleSpinBox(frame_12);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));
        doubleSpinBox_10->setGeometry(QRect(170, 40, 141, 22));
        doubleSpinBox_10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_10->setMaximum(1000.000000000000000);
        doubleSpinBox_10->setSingleStep(0.010000000000000);
        doubleSpinBox_10->setValue(1.160000000000000);
        label_12 = new QLabel(frame_12);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(100, 10, 171, 16));
        doubleSpinBox_11 = new QDoubleSpinBox(frame_12);
        doubleSpinBox_11->setObjectName(QString::fromUtf8("doubleSpinBox_11"));
        doubleSpinBox_11->setGeometry(QRect(10, 70, 151, 22));
        doubleSpinBox_11->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_11->setMaximum(1000.000000000000000);
        doubleSpinBox_11->setSingleStep(0.010000000000000);
        doubleSpinBox_11->setValue(0.200000000000000);
        doubleSpinBox_12 = new QDoubleSpinBox(frame_12);
        doubleSpinBox_12->setObjectName(QString::fromUtf8("doubleSpinBox_12"));
        doubleSpinBox_12->setGeometry(QRect(170, 70, 141, 22));
        doubleSpinBox_12->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_12->setDecimals(0);
        doubleSpinBox_12->setMaximum(100000.000000000000000);
        doubleSpinBox_12->setSingleStep(1.000000000000000);
        doubleSpinBox_12->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        doubleSpinBox_12->setValue(50.000000000000000);
        frame_7 = new QFrame(frame_3);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(10, 80, 151, 61));
        frame_7->setFrameShape(QFrame::Panel);
        frame_7->setFrameShadow(QFrame::Raised);
        label_59 = new QLabel(frame_7);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(10, 0, 131, 20));
        comboBox_4 = new QComboBox(frame_7);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(20, 30, 100, 25));
        comboBox_4->setToolTipDuration(-1);
        comboBox_4->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBox_4->setModelColumn(0);
        doubleSpinBox_30 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_30->setObjectName(QString::fromUtf8("doubleSpinBox_30"));
        doubleSpinBox_30->setGeometry(QRect(170, 120, 131, 31));
        doubleSpinBox_30->setReadOnly(false);
        doubleSpinBox_30->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_30->setDecimals(1);
        doubleSpinBox_30->setMinimum(0.000000000000000);
        doubleSpinBox_30->setMaximum(20.000000000000000);
        doubleSpinBox_30->setSingleStep(0.100000000000000);
        doubleSpinBox_30->setValue(0.000000000000000);
        checkBox = new QCheckBox(frame_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(980, 10, 131, 31));
        checkBox->setCheckable(true);
        checkBox->setChecked(true);
        doubleSpinBox_14 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_14->setObjectName(QString::fromUtf8("doubleSpinBox_14"));
        doubleSpinBox_14->setGeometry(QRect(310, 120, 151, 31));
        doubleSpinBox_14->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_14->setDecimals(0);
        doubleSpinBox_14->setMaximum(100000.000000000000000);
        doubleSpinBox_14->setSingleStep(1.000000000000000);
        doubleSpinBox_14->setValue(10000.000000000000000);
        pushButton_3 = new QPushButton(frame_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(1070, 640, 71, 51));
        frame_2 = new QFrame(frame_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 300, 301, 51));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(3);
        frame_2->setMidLineWidth(1);
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 10, 41, 31));
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 10, 81, 31));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 121, 31));
        frame_13 = new QFrame(frame_3);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setGeometry(QRect(30, 580, 381, 161));
        frame_13->setInputMethodHints(Qt::ImhNone);
        frame_13->setFrameShape(QFrame::Box);
        frame_13->setFrameShadow(QFrame::Raised);
        frame_13->setLineWidth(4);
        label_9 = new QLabel(frame_13);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 10, 291, 16));
        tableWidget_7 = new QTableWidget(frame_13);
        if (tableWidget_7->columnCount() < 3)
            tableWidget_7->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        if (tableWidget_7->rowCount() < 3)
            tableWidget_7->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_7->setVerticalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_7->setVerticalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_7->setVerticalHeaderItem(2, __qtablewidgetitem20);
        tableWidget_7->setObjectName(QString::fromUtf8("tableWidget_7"));
        tableWidget_7->setGeometry(QRect(30, 30, 331, 121));
        tableWidget_7->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_7->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_7->setRowCount(3);
        tableWidget_7->setColumnCount(3);
        tableWidget_7->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_7->horizontalHeader()->setHighlightSections(false);
        tableWidget_7->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget_7->verticalHeader()->setDefaultSectionSize(30);
        frame_14 = new QFrame(frame_3);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setGeometry(QRect(410, 580, 551, 161));
        frame_14->setFrameShape(QFrame::Box);
        frame_14->setFrameShadow(QFrame::Raised);
        frame_14->setLineWidth(4);
        label_13 = new QLabel(frame_14);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(50, 10, 451, 16));
        tableWidget_5 = new QTableWidget(frame_14);
        if (tableWidget_5->columnCount() < 6)
            tableWidget_5->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(2, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(3, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(4, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(5, __qtablewidgetitem26);
        if (tableWidget_5->rowCount() < 3)
            tableWidget_5->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(2, __qtablewidgetitem29);
        tableWidget_5->setObjectName(QString::fromUtf8("tableWidget_5"));
        tableWidget_5->setGeometry(QRect(10, 30, 531, 121));
        tableWidget_5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_5->setRowCount(3);
        tableWidget_5->setColumnCount(6);
        tableWidget_5->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_5->horizontalHeader()->setHighlightSections(false);
        tableWidget_5->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget_5->verticalHeader()->setDefaultSectionSize(30);
        frame_8 = new QFrame(frame_3);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(10, 10, 151, 61));
        frame_8->setFrameShape(QFrame::Panel);
        frame_8->setFrameShadow(QFrame::Raised);
        label_60 = new QLabel(frame_8);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(30, 0, 131, 20));
        comboBox_5 = new QComboBox(frame_8);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(20, 30, 89, 25));
        comboBox_5->setToolTipDuration(-1);
        comboBox_5->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBox_5->setModelColumn(0);
        frame_6 = new QFrame(frame_3);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(10, 430, 301, 51));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Plain);
        frame_6->setLineWidth(3);
        frame_6->setMidLineWidth(1);
        pushButton_5 = new QPushButton(frame_6);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(250, 10, 41, 31));
        label_26 = new QLabel(frame_6);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 10, 211, 20));
        lineEdit_3 = new QLineEdit(frame_6);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 10, 81, 31));
        doubleSpinBox_33 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_33->setObjectName(QString::fromUtf8("doubleSpinBox_33"));
        doubleSpinBox_33->setGeometry(QRect(480, 120, 141, 31));
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
        frame_15->setGeometry(QRect(890, 150, 191, 141));
        frame_15->setFrameShape(QFrame::Box);
        frame_15->setFrameShadow(QFrame::Raised);
        frame_15->setLineWidth(4);
        label_10 = new QLabel(frame_15);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 10, 171, 16));
        tableWidget_8 = new QTableWidget(frame_15);
        if (tableWidget_8->columnCount() < 2)
            tableWidget_8->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(1, __qtablewidgetitem31);
        if (tableWidget_8->rowCount() < 3)
            tableWidget_8->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_8->setVerticalHeaderItem(0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_8->setVerticalHeaderItem(1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_8->setVerticalHeaderItem(2, __qtablewidgetitem34);
        tableWidget_8->setObjectName(QString::fromUtf8("tableWidget_8"));
        tableWidget_8->setGeometry(QRect(10, 30, 171, 101));
        tableWidget_8->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_8->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_8->setRowCount(3);
        tableWidget_8->setColumnCount(2);
        tableWidget_8->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_8->horizontalHeader()->setHighlightSections(false);
        tableWidget_8->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget_8->verticalHeader()->setDefaultSectionSize(23);
        doubleSpinBox_34 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_34->setObjectName(QString::fromUtf8("doubleSpinBox_34"));
        doubleSpinBox_34->setGeometry(QRect(980, 80, 151, 31));
        doubleSpinBox_34->setLayoutDirection(Qt::RightToLeft);
        doubleSpinBox_34->setAutoFillBackground(false);
        doubleSpinBox_34->setReadOnly(false);
        doubleSpinBox_34->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_34->setDecimals(4);
        doubleSpinBox_34->setMinimum(-10.000000000000000);
        doubleSpinBox_34->setMaximum(10000.000000000000000);
        doubleSpinBox_34->setSingleStep(0.100000000000000);
        doubleSpinBox_34->setValue(1.161000000000000);
        frame_16 = new QFrame(frame_3);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setGeometry(QRect(770, 10, 151, 61));
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
        frame_17->setGeometry(QRect(10, 360, 301, 61));
        frame_17->setFrameShape(QFrame::Panel);
        frame_17->setFrameShadow(QFrame::Raised);
        label_63 = new QLabel(frame_17);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(10, 0, 321, 20));
        comboBox_7 = new QComboBox(frame_17);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));
        comboBox_7->setGeometry(QRect(100, 30, 62, 25));
        comboBox_7->setToolTipDuration(-1);
        comboBox_7->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBox_7->setModelColumn(0);
        doubleSpinBox_15 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_15->setObjectName(QString::fromUtf8("doubleSpinBox_15"));
        doubleSpinBox_15->setGeometry(QRect(980, 40, 151, 31));
        doubleSpinBox_15->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_15->setDecimals(0);
        doubleSpinBox_15->setMaximum(100000.000000000000000);
        doubleSpinBox_15->setSingleStep(1.000000000000000);
        doubleSpinBox_15->setValue(1.000000000000000);
        groupBox = new QGroupBox(frame_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(500, 300, 641, 251));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButtonStartTask = new QPushButton(groupBox);
        pushButtonStartTask->setObjectName(QString::fromUtf8("pushButtonStartTask"));

        gridLayout->addWidget(pushButtonStartTask, 0, 0, 1, 1);

        labelTaskInfo1 = new QLabel(groupBox);
        labelTaskInfo1->setObjectName(QString::fromUtf8("labelTaskInfo1"));

        gridLayout->addWidget(labelTaskInfo1, 2, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        labelTaskInfo3 = new QLabel(groupBox);
        labelTaskInfo3->setObjectName(QString::fromUtf8("labelTaskInfo3"));

        gridLayout->addWidget(labelTaskInfo3, 4, 0, 1, 1);

        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 6, 0, 1, 3);

        labelTaskInfo4 = new QLabel(groupBox);
        labelTaskInfo4->setObjectName(QString::fromUtf8("labelTaskInfo4"));

        gridLayout->addWidget(labelTaskInfo4, 5, 0, 1, 1);

        pushButtonStopTask = new QPushButton(groupBox);
        pushButtonStopTask->setObjectName(QString::fromUtf8("pushButtonStopTask"));

        gridLayout->addWidget(pushButtonStopTask, 0, 1, 1, 1);

        labelTaskInfo2 = new QLabel(groupBox);
        labelTaskInfo2->setObjectName(QString::fromUtf8("labelTaskInfo2"));

        gridLayout->addWidget(labelTaskInfo2, 3, 0, 1, 1);

        pushButtonStartTask->raise();
        pushButtonStopTask->raise();
        progressBar->raise();
        labelTaskInfo1->raise();
        labelTaskInfo3->raise();
        labelTaskInfo4->raise();
        labelTaskInfo2->raise();
        doubleSpinBox_31 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_31->setObjectName(QString::fromUtf8("doubleSpinBox_31"));
        doubleSpinBox_31->setGeometry(QRect(630, 120, 131, 31));
        doubleSpinBox_31->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_31->setDecimals(1);
        doubleSpinBox_31->setMinimum(0.000000000000000);
        doubleSpinBox_31->setMaximum(1000.000000000000000);
        doubleSpinBox_31->setSingleStep(0.100000000000000);
        doubleSpinBox_31->setValue(1.500000000000000);
        groupBox_3 = new QGroupBox(frame_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(330, 410, 151, 121));
        comboBox_8 = new QComboBox(groupBox_3);
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->setObjectName(QString::fromUtf8("comboBox_8"));
        comboBox_8->setGeometry(QRect(10, 30, 89, 25));
        comboBox_8->setToolTipDuration(-1);
        comboBox_8->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBox_8->setModelColumn(0);
        doubleSpinBox_16 = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_16->setObjectName(QString::fromUtf8("doubleSpinBox_16"));
        doubleSpinBox_16->setGeometry(QRect(10, 90, 121, 22));
        doubleSpinBox_16->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_16->setDecimals(2);
        doubleSpinBox_16->setMaximum(100.000000000000000);
        doubleSpinBox_16->setSingleStep(1.000000000000000);
        doubleSpinBox_16->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        doubleSpinBox_16->setValue(1.000000000000000);
        doubleSpinBox_17 = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_17->setObjectName(QString::fromUtf8("doubleSpinBox_17"));
        doubleSpinBox_17->setGeometry(QRect(10, 60, 121, 22));
        doubleSpinBox_17->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_17->setDecimals(5);
        doubleSpinBox_17->setMaximum(1000.000000000000000);
        doubleSpinBox_17->setSingleStep(1.000000000000000);
        doubleSpinBox_17->setValue(10.000000000000000);
        groupBox_4 = new QGroupBox(frame_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(330, 310, 151, 91));
        doubleSpinBox_19 = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_19->setObjectName(QString::fromUtf8("doubleSpinBox_19"));
        doubleSpinBox_19->setGeometry(QRect(10, 30, 121, 22));
        doubleSpinBox_19->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_19->setDecimals(3);
        doubleSpinBox_19->setMaximum(2.000000000000000);
        doubleSpinBox_19->setSingleStep(0.001000000000000);
        doubleSpinBox_19->setValue(0.250000000000000);
        doubleSpinBox_32 = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_32->setObjectName(QString::fromUtf8("doubleSpinBox_32"));
        doubleSpinBox_32->setGeometry(QRect(10, 60, 121, 21));
        doubleSpinBox_32->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_32->setDecimals(0);
        doubleSpinBox_32->setMinimum(0.000000000000000);
        doubleSpinBox_32->setMaximum(200.000000000000000);
        doubleSpinBox_32->setSingleStep(1.000000000000000);
        doubleSpinBox_32->setValue(40.000000000000000);
        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1000, 580, 111, 51));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1160, 21));
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

        comboBox_4->setCurrentIndex(5);
        comboBox_5->setCurrentIndex(2);
        comboBox_6->setCurrentIndex(0);
        comboBox_7->setCurrentIndex(0);
        comboBox_8->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\237\320\240\320\225\320\237\320\233\320\236\320\242", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_6->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_6->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_6->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_6->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\270\320\275\320\260, \320\274 ", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_6->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\260, \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_6->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\220\320\277\321\200.\320\276\321\206., \320\274", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\253 \320\237\320\236\320\227\320\230\320\246\320\230\320\236\320\235\320\230\320\240\320\236\320\222\320\220\320\235\320\230\320\257 \320\220\320\235\320\242\320\225\320\235\320\235 \320\222 \320\237\320\241\320\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Bet", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_4->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Eps", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_4->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Alf", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_4->verticalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\270\320\275\320\260   (\320\274, \320\263\321\200.)", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_4->verticalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\260 (\320\274, \320\274\321\200\320\260\320\264)", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_4->verticalHeaderItem(2);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "\320\220\320\277\321\200.\320\276\321\206.  (\320\274,\320\263\321\200\320\260\320\264)", nullptr));
        doubleSpinBox_7->setPrefix(QApplication::translate("MainWindow", " \320\232\320\243: ", nullptr));
        doubleSpinBox_7->setSuffix(QApplication::translate("MainWindow", " \320\274\321\200\320\260\320\264", nullptr));
        doubleSpinBox_8->setPrefix(QApplication::translate("MainWindow", " dT: ", nullptr));
        doubleSpinBox_8->setSuffix(QApplication::translate("MainWindow", " \320\274\321\201", nullptr));
        doubleSpinBox_13->setPrefix(QApplication::translate("MainWindow", "\320\243\320\234: ", nullptr));
        doubleSpinBox_13->setSuffix(QApplication::translate("MainWindow", " \320\274\321\200\320\260\320\264", nullptr));
        label_61->setText(QApplication::translate("MainWindow", "\320\237\320\236\320\223\320\240\320\225\320\250\320\235\320\236\320\241\320\242\320\230  \320\220\320\235\320\242\320\225\320\235\320\235", nullptr));
        doubleSpinBox_9->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 \321\203\320\263.:   ", nullptr));
        doubleSpinBox_9->setSuffix(QApplication::translate("MainWindow", " \320\274\321\200\320\260\320\264", nullptr));
        doubleSpinBox_10->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 V \321\203\320\263.: ", nullptr));
        doubleSpinBox_10->setSuffix(QApplication::translate("MainWindow", " \320\274\321\200\320\260\320\264/\321\201", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\253 \320\241\320\230\320\235\320\241", nullptr));
        doubleSpinBox_11->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 V: ", nullptr));
        doubleSpinBox_11->setSuffix(QApplication::translate("MainWindow", " \320\274/\321\201", nullptr));
        doubleSpinBox_12->setPrefix(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277: ", nullptr));
        doubleSpinBox_12->setSuffix(QApplication::translate("MainWindow", " \320\223\321\206", nullptr));
        label_59->setText(QApplication::translate("MainWindow", "\320\242\321\200\320\260\320\265\320\272\321\202. \320\272\320\276\321\200\320\260\320\261\320\273\321\217:", nullptr));
        comboBox_4->setItemText(0, QApplication::translate("MainWindow", "6 \321\202\320\276\321\207\320\265\320\272", nullptr));
        comboBox_4->setItemText(1, QApplication::translate("MainWindow", "7 \321\202\320\276\321\207\320\265\320\272", nullptr));
        comboBox_4->setItemText(2, QApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));
        comboBox_4->setItemText(3, QApplication::translate("MainWindow", "\320\227\320\270\320\263\320\267\320\260\320\263", nullptr));
        comboBox_4->setItemText(4, QApplication::translate("MainWindow", "\320\224\320\270\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        comboBox_4->setItemText(5, QApplication::translate("MainWindow", "6 \320\273\320\270\320\275\320\270\320\271", nullptr));

        comboBox_4->setCurrentText(QApplication::translate("MainWindow", "6 \320\273\320\270\320\275\320\270\320\271", nullptr));
        doubleSpinBox_30->setPrefix(QApplication::translate("MainWindow", "\320\222\320\265\321\202\320\265\321\200: ", nullptr));
        doubleSpinBox_30->setSuffix(QApplication::translate("MainWindow", " \320\274/\321\201", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\320\221\320\225\320\227 \320\250\320\243\320\234\320\236\320\222", nullptr));
        doubleSpinBox_14->setPrefix(QApplication::translate("MainWindow", "N \320\230\320\227\320\234.:  ", nullptr));
        doubleSpinBox_14->setSuffix(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "RUN", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\236\320\246\320\225\320\235\320\232\320\220 \320\237\320\236\320\233\320\236\320\226\320\225\320\235\320\230\320\257 \320\234\320\220\320\257\320\232\320\220 \320\222 \320\223\320\241\320\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_7->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_7->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_7->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_7->verticalHeaderItem(0);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "\320\236\321\206\320\265\320\275\320\272\320\260, \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_7->verticalHeaderItem(1);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\260, \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_7->verticalHeaderItem(2);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "\320\241\320\232\320\236, \320\274", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\236\320\246\320\225\320\235\320\232\320\220 \320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\236\320\222 \320\237\320\236\320\227\320\230\320\246\320\230\320\236\320\235\320\230\320\240\320\236\320\222\320\220\320\235\320\230\320\257 \320\223\320\240\320\233\320\241 \320\222 \320\237\320\241\320\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_5->horizontalHeaderItem(1);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_5->horizontalHeaderItem(2);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_5->horizontalHeaderItem(3);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "Bet", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_5->horizontalHeaderItem(4);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "Eps", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_5->horizontalHeaderItem(5);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "Alf", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_5->verticalHeaderItem(0);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "\320\236\321\206\320\265\320\275\320\272\320\260   (\320\274, \320\263\321\200.)", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_5->verticalHeaderItem(1);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\260 (\320\274, \320\274\321\200\320\260\320\264)", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_5->verticalHeaderItem(2);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "\320\241\320\232\320\236        (\320\274,\320\263\321\200\320\260\320\264)", nullptr));
        label_60->setText(QApplication::translate("MainWindow", "\320\242\320\230\320\237 \320\220\320\235\320\242\320\225\320\235\320\235\320\253", nullptr));
        comboBox_5->setItemText(0, QApplication::translate("MainWindow", "LBL", nullptr));
        comboBox_5->setItemText(1, QApplication::translate("MainWindow", "USBL-2D", nullptr));
        comboBox_5->setItemText(2, QApplication::translate("MainWindow", "USBL-3D", nullptr));

        comboBox_5->setCurrentText(QApplication::translate("MainWindow", "USBL-3D", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273 <*.000> ", nullptr));
        doubleSpinBox_33->setPrefix(QApplication::translate("MainWindow", "R \320\277\321\200\320\270\320\265\320\274\320\260: ", nullptr));
        doubleSpinBox_33->setSuffix(QApplication::translate("MainWindow", " \320\274", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\320\237\320\236\320\233\320\236\320\226. GPS \320\222 \320\237\320\241\320\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_8->horizontalHeaderItem(0);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "\320\230\320\241\320\242\320\230\320\235\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_8->horizontalHeaderItem(1);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "\320\236\320\246\320\225\320\235\320\232\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_8->verticalHeaderItem(0);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_8->verticalHeaderItem(1);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_8->verticalHeaderItem(2);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "Z", nullptr));
        doubleSpinBox_34->setPrefix(QApplication::translate("MainWindow", "T  \320\276\320\261\321\200\320\260\320\261: ", nullptr));
        doubleSpinBox_34->setSuffix(QApplication::translate("MainWindow", " c", nullptr));
        label_62->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\260\320\273\321\214\320\275\321\213\320\271 \320\277\321\200\320\276\321\204\320\270\320\273\321\214:", nullptr));
        comboBox_6->setItemText(0, QApplication::translate("MainWindow", "\320\241\320\276\320\262\320\277\320\260\320\264\320\260\320\265\321\202", nullptr));
        comboBox_6->setItemText(1, QApplication::translate("MainWindow", "+ 1%", nullptr));
        comboBox_6->setItemText(2, QApplication::translate("MainWindow", "-1%", nullptr));
        comboBox_6->setItemText(3, QApplication::translate("MainWindow", "\320\241\320\270\320\263\320\274\320\260 0,33%", nullptr));
        comboBox_6->setItemText(4, QApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271", nullptr));

        comboBox_6->setCurrentText(QApplication::translate("MainWindow", "\320\241\320\276\320\262\320\277\320\260\320\264\320\260\320\265\321\202", nullptr));
        label_63->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 \321\204\320\276\321\200\320\274\320\260\321\202\320\260 \321\204\320\260\320\271\320\273\320\260 <*.000> c \320\277\321\200\320\276\321\204\320\270\320\273\320\265\320\274", nullptr));
        comboBox_7->setItemText(0, QApplication::translate("MainWindow", "1 var", nullptr));
        comboBox_7->setItemText(1, QApplication::translate("MainWindow", "2 var", nullptr));

        comboBox_7->setCurrentText(QApplication::translate("MainWindow", "1 var", nullptr));
        doubleSpinBox_15->setPrefix(QApplication::translate("MainWindow", "V \321\201\321\203\320\264\320\275\320\260:  ", nullptr));
        doubleSpinBox_15->setSuffix(QApplication::translate("MainWindow", " \320\274/c", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Thread progress", nullptr));
        pushButtonStartTask->setText(QApplication::translate("MainWindow", "Start", nullptr));
        labelTaskInfo1->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        labelTaskInfo3->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        labelTaskInfo4->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButtonStopTask->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        labelTaskInfo2->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        doubleSpinBox_31->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 GPS: ", nullptr));
        doubleSpinBox_31->setSuffix(QApplication::translate("MainWindow", " \320\274", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 USBL", nullptr));
        comboBox_8->setItemText(0, QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\261\320\276\321\200", nullptr));
        comboBox_8->setItemText(1, QApplication::translate("MainWindow", "\320\235\321\214\321\216\321\202\320\276\320\275", nullptr));

        comboBox_8->setCurrentText(QApplication::translate("MainWindow", "\320\235\321\214\321\216\321\202\320\276\320\275", nullptr));
        doubleSpinBox_16->setPrefix(QApplication::translate("MainWindow", "Step: ", nullptr));
        doubleSpinBox_16->setSuffix(QApplication::translate("MainWindow", " \320\263\321\200", nullptr));
        doubleSpinBox_17->setPrefix(QApplication::translate("MainWindow", "Gape: ", nullptr));
        doubleSpinBox_17->setSuffix(QApplication::translate("MainWindow", " \320\263\321\200", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 LBL", nullptr));
        doubleSpinBox_19->setPrefix(QApplication::translate("MainWindow", "\320\232\320\276\321\215\321\204: ", nullptr));
        doubleSpinBox_19->setSuffix(QString());
        doubleSpinBox_32->setPrefix(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201. \320\270\321\202.: ", nullptr));
        doubleSpinBox_32->setSuffix(QString());
        pushButton->setText(QApplication::translate("MainWindow", "\320\222\320\227\320\257\320\242\320\254 \320\227\320\220 \320\230\320\224", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
