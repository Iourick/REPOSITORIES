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
    QFrame *frame_5;
    QTableWidget *tableWidget;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_3;
    QTableWidget *tableWidget_2;
    QTableWidget *tableWidget_3;
    QTableWidget *tableWidget_6;
    QCheckBox *checkBox;
    QDoubleSpinBox *doubleSpinBox_27;
    QDoubleSpinBox *doubleSpinBox_28;
    QFrame *frame_4;
    QFrame *frame_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label_41;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget_4;
    QLabel *label_55;
    QTableWidget *tableWidget_5;
    QDoubleSpinBox *doubleSpinBox_24;
    QDoubleSpinBox *doubleSpinBox_23;
    QDoubleSpinBox *doubleSpinBox_22;
    QFrame *frame_7;
    QComboBox *comboBox;
    QLabel *label_53;
    QDoubleSpinBox *doubleSpinBox_25;
    QDoubleSpinBox *doubleSpinBox_26;
    QFrame *frame_6;
    QLabel *label_58;
    QComboBox *comboBox_3;
    QFrame *frame_8;
    QLabel *label_57;
    QDoubleSpinBox *doubleSpinBox_29;
    QDoubleSpinBox *doubleSpinBox_30;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1383, 828);
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 16, 742));
        scrollArea->setWidget(scrollAreaWidgetContents);
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(20, 0, 1261, 311));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Plain);
        frame_3->setLineWidth(2);
        frame_3->setMidLineWidth(4);
        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(0, 20, 1241, 281));
        frame_5->setLayoutDirection(Qt::RightToLeft);
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_5->setLineWidth(4);
        tableWidget = new QTableWidget(frame_5);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem9);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 40, 1221, 101));
        tableWidget->setBaseSize(QSize(0, 0));
        tableWidget->setLayoutDirection(Qt::LeftToRight);
        tableWidget->setFrameShape(QFrame::Box);
        tableWidget->setLineWidth(2);
        tableWidget->setMidLineWidth(2);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget->setAutoScroll(false);
        tableWidget->setIconSize(QSize(15, 30));
        tableWidget->setSortingEnabled(false);
        tableWidget->setRowCount(2);
        tableWidget->setColumnCount(9);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(125);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(47);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tableWidget->verticalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setMinimumSectionSize(30);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);
        label_7 = new QLabel(frame_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(270, 20, 211, 16));
        doubleSpinBox_3 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(870, 340, 81, 31));
        doubleSpinBox_3->setDecimals(2);
        doubleSpinBox_3->setMinimum(0.000000000000000);
        doubleSpinBox_3->setMaximum(10000.000000000000000);
        doubleSpinBox_3->setValue(1000.000000000000000);
        tableWidget_2 = new QTableWidget(frame_5);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        if (tableWidget_2->rowCount() < 2)
            tableWidget_2->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem15);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setEnabled(true);
        tableWidget_2->setGeometry(QRect(480, 150, 451, 101));
        tableWidget_2->setLayoutDirection(Qt::LeftToRight);
        tableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_2->setRowCount(2);
        tableWidget_2->setColumnCount(4);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_2->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_3 = new QTableWidget(frame_5);
        if (tableWidget_3->columnCount() < 1)
            tableWidget_3->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        if (tableWidget_3->rowCount() < 2)
            tableWidget_3->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(1, __qtablewidgetitem18);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(200, 150, 231, 101));
        tableWidget_3->setLayoutDirection(Qt::LeftToRight);
        tableWidget_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_3->setAutoScrollMargin(16);
        tableWidget_3->setRowCount(2);
        tableWidget_3->setColumnCount(1);
        tableWidget_3->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_3->horizontalHeader()->setMinimumSectionSize(46);
        tableWidget_3->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_3->verticalHeader()->setMinimumSectionSize(30);
        tableWidget_6 = new QTableWidget(frame_5);
        if (tableWidget_6->columnCount() < 1)
            tableWidget_6->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        if (tableWidget_6->rowCount() < 2)
            tableWidget_6->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_6->setVerticalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_6->setVerticalHeaderItem(1, __qtablewidgetitem21);
        tableWidget_6->setObjectName(QString::fromUtf8("tableWidget_6"));
        tableWidget_6->setEnabled(true);
        tableWidget_6->setGeometry(QRect(20, 150, 161, 101));
        tableWidget_6->setLayoutDirection(Qt::LeftToRight);
        tableWidget_6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_6->setRowCount(2);
        tableWidget_6->setColumnCount(1);
        tableWidget_6->verticalHeader()->setDefaultSectionSize(30);
        checkBox = new QCheckBox(frame_5);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(970, 210, 161, 17));
        checkBox->setCheckable(true);
        checkBox->setChecked(true);
        doubleSpinBox_27 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_27->setObjectName(QString::fromUtf8("doubleSpinBox_27"));
        doubleSpinBox_27->setGeometry(QRect(960, 150, 211, 41));
        doubleSpinBox_27->setLayoutDirection(Qt::LeftToRight);
        doubleSpinBox_27->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_27->setDecimals(0);
        doubleSpinBox_27->setMinimum(0.000000000000000);
        doubleSpinBox_27->setMaximum(100000000.000000000000000);
        doubleSpinBox_27->setSingleStep(0.100000000000000);
        doubleSpinBox_27->setValue(20000.000000000000000);
        doubleSpinBox_28 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_28->setObjectName(QString::fromUtf8("doubleSpinBox_28"));
        doubleSpinBox_28->setGeometry(QRect(970, 240, 221, 30));
        doubleSpinBox_28->setLayoutDirection(Qt::LeftToRight);
        doubleSpinBox_28->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_28->setDecimals(3);
        doubleSpinBox_28->setMinimum(0.000000000000000);
        doubleSpinBox_28->setMaximum(10.000000000000000);
        doubleSpinBox_28->setSingleStep(0.000100000000000);
        doubleSpinBox_28->setValue(0.010000000000000);
        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(20, 410, 1271, 361));
        frame_4->setFrameShape(QFrame::Panel);
        frame_4->setFrameShadow(QFrame::Plain);
        frame_4->setLineWidth(3);
        frame_4->setMidLineWidth(3);
        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(30, 70, 631, 61));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(3);
        frame_2->setMidLineWidth(1);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 271, 31));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(520, 10, 81, 31));
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(310, 10, 191, 31));
        label_41 = new QLabel(frame_4);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(90, 30, 241, 20));
        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 20, 171, 41));
        tableWidget_4 = new QTableWidget(frame_4);
        if (tableWidget_4->columnCount() < 10)
            tableWidget_4->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(2, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(3, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(4, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(5, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(6, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(7, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(8, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(9, __qtablewidgetitem31);
        if (tableWidget_4->rowCount() < 3)
            tableWidget_4->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(2, __qtablewidgetitem34);
        tableWidget_4->setObjectName(QString::fromUtf8("tableWidget_4"));
        tableWidget_4->setGeometry(QRect(10, 200, 1141, 141));
        tableWidget_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_4->setRowCount(3);
        tableWidget_4->setColumnCount(10);
        tableWidget_4->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_4->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_4->verticalHeader()->setMinimumSectionSize(20);
        label_55 = new QLabel(frame_4);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(260, 170, 411, 20));
        tableWidget_5 = new QTableWidget(frame_4);
        if (tableWidget_5->columnCount() < 4)
            tableWidget_5->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(1, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(2, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(3, __qtablewidgetitem38);
        if (tableWidget_5->rowCount() < 2)
            tableWidget_5->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(1, __qtablewidgetitem40);
        tableWidget_5->setObjectName(QString::fromUtf8("tableWidget_5"));
        tableWidget_5->setEnabled(true);
        tableWidget_5->setGeometry(QRect(670, 10, 451, 101));
        tableWidget_5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_5->setRowCount(2);
        tableWidget_5->setColumnCount(4);
        tableWidget_5->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_5->horizontalHeader()->setMinimumSectionSize(40);
        tableWidget_5->verticalHeader()->setDefaultSectionSize(30);
        doubleSpinBox_24 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_24->setObjectName(QString::fromUtf8("doubleSpinBox_24"));
        doubleSpinBox_24->setGeometry(QRect(940, 130, 171, 41));
        doubleSpinBox_24->setLayoutDirection(Qt::LeftToRight);
        doubleSpinBox_24->setReadOnly(true);
        doubleSpinBox_24->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_24->setDecimals(2);
        doubleSpinBox_24->setMinimum(-20000.000000000000000);
        doubleSpinBox_24->setMaximum(20000000.000000000000000);
        doubleSpinBox_24->setSingleStep(0.100000000000000);
        doubleSpinBox_24->setValue(-1.000000000000000);
        doubleSpinBox_23 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_23->setObjectName(QString::fromUtf8("doubleSpinBox_23"));
        doubleSpinBox_23->setGeometry(QRect(650, 320, 151, 35));
        doubleSpinBox_23->setDecimals(1);
        doubleSpinBox_23->setMinimum(0.000000000000000);
        doubleSpinBox_23->setMaximum(1000.000000000000000);
        doubleSpinBox_23->setSingleStep(0.100000000000000);
        doubleSpinBox_23->setValue(5.000000000000000);
        doubleSpinBox_22 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_22->setObjectName(QString::fromUtf8("doubleSpinBox_22"));
        doubleSpinBox_22->setGeometry(QRect(650, 360, 151, 35));
        doubleSpinBox_22->setDecimals(3);
        doubleSpinBox_22->setMinimum(0.000000000000000);
        doubleSpinBox_22->setMaximum(1000.000000000000000);
        doubleSpinBox_22->setSingleStep(0.010000000000000);
        doubleSpinBox_22->setValue(15.000000000000000);
        frame_7 = new QFrame(centralWidget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(20, 320, 231, 61));
        frame_7->setFrameShape(QFrame::WinPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        comboBox = new QComboBox(frame_7);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 30, 198, 25));
        comboBox->setToolTipDuration(-1);
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBox->setModelColumn(0);
        label_53 = new QLabel(frame_7);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(20, 10, 151, 20));
        doubleSpinBox_25 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_25->setObjectName(QString::fromUtf8("doubleSpinBox_25"));
        doubleSpinBox_25->setGeometry(QRect(260, 320, 151, 35));
        doubleSpinBox_25->setDecimals(1);
        doubleSpinBox_25->setMinimum(0.000000000000000);
        doubleSpinBox_25->setMaximum(1000.000000000000000);
        doubleSpinBox_25->setSingleStep(0.100000000000000);
        doubleSpinBox_25->setValue(5.000000000000000);
        doubleSpinBox_26 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_26->setObjectName(QString::fromUtf8("doubleSpinBox_26"));
        doubleSpinBox_26->setGeometry(QRect(260, 360, 151, 35));
        doubleSpinBox_26->setDecimals(1);
        doubleSpinBox_26->setMinimum(0.000000000000000);
        doubleSpinBox_26->setMaximum(1000.000000000000000);
        doubleSpinBox_26->setSingleStep(0.100000000000000);
        doubleSpinBox_26->setValue(5.000000000000000);
        frame_6 = new QFrame(centralWidget);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(430, 320, 201, 41));
        frame_6->setFrameShape(QFrame::WinPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_58 = new QLabel(frame_6);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(10, 10, 71, 20));
        comboBox_3 = new QComboBox(frame_6);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(90, 10, 92, 25));
        comboBox_3->setToolTipDuration(-1);
        comboBox_3->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBox_3->setModelColumn(0);
        frame_8 = new QFrame(centralWidget);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(910, 320, 371, 81));
        frame_8->setFrameShape(QFrame::WinPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        label_57 = new QLabel(frame_8);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(150, 0, 51, 20));
        doubleSpinBox_29 = new QDoubleSpinBox(frame_8);
        doubleSpinBox_29->setObjectName(QString::fromUtf8("doubleSpinBox_29"));
        doubleSpinBox_29->setGeometry(QRect(20, 30, 151, 35));
        doubleSpinBox_29->setDecimals(1);
        doubleSpinBox_29->setMinimum(0.000000000000000);
        doubleSpinBox_29->setMaximum(1000.000000000000000);
        doubleSpinBox_29->setSingleStep(0.100000000000000);
        doubleSpinBox_29->setValue(0.000000000000000);
        doubleSpinBox_30 = new QDoubleSpinBox(frame_8);
        doubleSpinBox_30->setObjectName(QString::fromUtf8("doubleSpinBox_30"));
        doubleSpinBox_30->setGeometry(QRect(210, 30, 151, 35));
        doubleSpinBox_30->setDecimals(1);
        doubleSpinBox_30->setMinimum(0.000000000000000);
        doubleSpinBox_30->setMaximum(1000.000000000000000);
        doubleSpinBox_30->setSingleStep(0.100000000000000);
        doubleSpinBox_30->setValue(0.000000000000000);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1383, 21));
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

        comboBox->setCurrentIndex(3);
        comboBox_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "L, \320\274\320\223", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "R, \320\236\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Psi_f", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Jrot", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Mresid", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Jload", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "C_om", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "OmStat", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\260\320\273\320\270\320\267", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\253 \320\237\320\240\320\230\320\222\320\236\320\224\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Lamb1", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Lamb2", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Lamb3", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Lamb4", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Re", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "Im", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207. \321\203\321\201\320\273\320\276\320\262\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_3->verticalHeaderItem(0);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_3->verticalHeaderItem(1);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "\320\243\320\263. \321\201\320\272\320\276\321\200., \320\263\321\200\320\260\320\264/\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_6->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_6->verticalHeaderItem(0);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "Tetta, \320\263\321\200.", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_6->verticalHeaderItem(1);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "Om, \320\263\321\200/\321\201", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\320\221\320\225\320\227 \320\250\320\243\320\234\320\236\320\222", nullptr));
        doubleSpinBox_27->setPrefix(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277 \321\203\320\277\321\200\320\260\320\262\320\273 ", nullptr));
        doubleSpinBox_27->setSuffix(QApplication::translate("MainWindow", " \320\223\321\206", nullptr));
        doubleSpinBox_28->setPrefix(QApplication::translate("MainWindow", "\320\234\320\276\320\274 \321\201\321\203\321\205 \321\202\321\200\320\265\320\275\320\270\321\217 ", nullptr));
        doubleSpinBox_28->setSuffix(QApplication::translate("MainWindow", " \320\275\320\274", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\277\321\203\321\202\321\214 \320\272 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\270 \321\204\320\260\320\271\320\273\320\260\320\274\320\270 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\276\320\262", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_41->setText(QApplication::translate("MainWindow", "\320\237\320\236\320\241\320\242\320\240\320\236\320\225\320\235\320\230\320\225 \320\242\320\240\320\220\320\225\320\232\320\242\320\236\320\240\320\230\320\231", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "RUN", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "Tet, \320\263\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "Om, \320\263\321\200\320\260\320\264/\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "I_d, ma", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "I_qu, ma", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_4->horizontalHeaderItem(4);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "U_d", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_4->horizontalHeaderItem(5);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "U_qu", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_4->horizontalHeaderItem(6);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "Tet Syst, \320\274\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_4->horizontalHeaderItem(7);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "Tet CKZ, \320\274\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_4->horizontalHeaderItem(8);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "Om Syst, \320\274\321\200\320\260\320\264/\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_4->horizontalHeaderItem(9);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "Om SKZ, \320\274\321\200\320\260\320\264/\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_4->verticalHeaderItem(0);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\202 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_4->verticalHeaderItem(1);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "\320\224\320\270\321\204. \321\203\321\200.", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_4->verticalHeaderItem(2);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\260\320\273 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        label_55->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\270\320\262\321\210\320\265\320\263\320\276\321\201\321\217 \320\264\320\262\320\270\320\266\320\265\320\275\320\270\321\217 :", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "Lamb1", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_5->horizontalHeaderItem(1);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "Lamb2", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_5->horizontalHeaderItem(2);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "Lamb3", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_5->horizontalHeaderItem(3);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "Lamb4", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_5->verticalHeaderItem(0);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "Re", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_5->verticalHeaderItem(1);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "Im", nullptr));
        doubleSpinBox_24->setPrefix(QApplication::translate("MainWindow", "T \320\277\320\265\321\200\320\265\321\205: ", nullptr));
        doubleSpinBox_24->setSuffix(QApplication::translate("MainWindow", " \320\274\321\201", nullptr));
        doubleSpinBox_23->setPrefix(QApplication::translate("MainWindow", "Max Uqu ", nullptr));
        doubleSpinBox_23->setSuffix(QApplication::translate("MainWindow", " \320\222", nullptr));
        doubleSpinBox_22->setPrefix(QApplication::translate("MainWindow", "Time.: ", nullptr));
        doubleSpinBox_22->setSuffix(QApplication::translate("MainWindow", " \321\201", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202 \320\262\321\200\320\260\321\211 \320\242\320\220\320\240", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202 \320\262\321\200\320\260\321\211 \320\242\320\220\320\240 +\320\261\321\213\321\201\321\202\321\200", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\242\320\220\320\240", nullptr));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "\320\241\320\273\320\265\320\266\320\265\320\275\320\270\320\265", nullptr));
        comboBox->setItemText(4, QApplication::translate("MainWindow", "\320\232\320\276\321\200\321\200\320\265\320\272\321\206\320\270\321\217 \320\277\320\276 M \320\270 R", nullptr));
        comboBox->setItemText(5, QApplication::translate("MainWindow", "\320\232\320\276\321\200\321\200\320\265\320\272\321\206\320\270\321\217 \320\277\320\276 W", nullptr));
        comboBox->setItemText(6, QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202 \320\262\321\200\320\260\321\211 \321\202\321\200\320\260\320\264\320\270\321\206", nullptr));

        comboBox->setCurrentText(QApplication::translate("MainWindow", "\320\241\320\273\320\265\320\266\320\265\320\275\320\270\320\265", nullptr));
        label_53->setText(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276 :", nullptr));
        doubleSpinBox_25->setPrefix(QApplication::translate("MainWindow", "Trenew ", nullptr));
        doubleSpinBox_25->setSuffix(QApplication::translate("MainWindow", "  c", nullptr));
        doubleSpinBox_26->setPrefix(QApplication::translate("MainWindow", "IntegrT ", nullptr));
        doubleSpinBox_26->setSuffix(QApplication::translate("MainWindow", "  c", nullptr));
        label_58->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\263\321\200\321\203\320\267\320\272\320\260", nullptr));
        comboBox_3->setItemText(0, QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217", nullptr));
        comboBox_3->setItemText(1, QApplication::translate("MainWindow", "\320\221\320\240\320\233\320\241", nullptr));

        comboBox_3->setCurrentText(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217", nullptr));
        label_57->setText(QApplication::translate("MainWindow", "\320\222\320\225\320\242\320\225\320\240", nullptr));
        doubleSpinBox_29->setPrefix(QApplication::translate("MainWindow", "\320\235\320\260\320\277\321\200. ", nullptr));
        doubleSpinBox_29->setSuffix(QApplication::translate("MainWindow", " \320\263\321\200\320\260\320\264", nullptr));
        doubleSpinBox_30->setPrefix(QApplication::translate("MainWindow", "\320\241\320\270\320\273\320\260 ", nullptr));
        doubleSpinBox_30->setSuffix(QApplication::translate("MainWindow", " \320\274/\321\201", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
