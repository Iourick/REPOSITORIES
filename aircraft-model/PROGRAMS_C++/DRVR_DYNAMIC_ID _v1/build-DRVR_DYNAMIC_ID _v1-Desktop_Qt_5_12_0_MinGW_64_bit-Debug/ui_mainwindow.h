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
    QFrame *frame_4;
    QFrame *frame_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label_41;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget_4;
    QLabel *label_55;
    QTableWidget *tableWidget_2;
    QLabel *label_54;
    QTableWidget *tableWidget_3;
    QTableWidget *tableWidget_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFrame *frame_3;
    QFrame *frame_5;
    QTableWidget *tableWidget;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_22;
    QDoubleSpinBox *doubleSpinBox_23;
    QFrame *frame_6;
    QComboBox *comboBox_3;
    QLabel *label_58;
    QFrame *frame_8;
    QComboBox *comboBox_2;
    QLabel *label_57;
    QPushButton *pushButton;
    QDoubleSpinBox *doubleSpinBox_25;
    QDoubleSpinBox *doubleSpinBox_26;
    QDoubleSpinBox *doubleSpinBox_27;
    QDoubleSpinBox *doubleSpinBox_28;
    QFrame *frame;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QLabel *label_56;
    QDoubleSpinBox *doubleSpinBox_29;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1381, 797);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        MainWindow->setTabletTracking(true);
        MainWindow->setWindowOpacity(5.000000000000000);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(10, 370, 1281, 361));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Plain);
        frame_4->setLineWidth(3);
        frame_4->setMidLineWidth(3);
        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 60, 631, 91));
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
        label_41->setGeometry(QRect(510, 10, 261, 20));
        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(570, 300, 281, 41));
        tableWidget_4 = new QTableWidget(frame_4);
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
        if (tableWidget_4->rowCount() < 3)
            tableWidget_4->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(2, __qtablewidgetitem8);
        tableWidget_4->setObjectName(QString::fromUtf8("tableWidget_4"));
        tableWidget_4->setGeometry(QRect(10, 180, 611, 101));
        tableWidget_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_4->setAutoScrollMargin(16);
        tableWidget_4->setRowCount(3);
        tableWidget_4->setColumnCount(6);
        tableWidget_4->horizontalHeader()->setDefaultSectionSize(88);
        tableWidget_4->horizontalHeader()->setMinimumSectionSize(24);
        tableWidget_4->verticalHeader()->setDefaultSectionSize(30);
        label_55 = new QLabel(frame_4);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(100, 150, 391, 20));
        tableWidget_2 = new QTableWidget(frame_4);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        if (tableWidget_2->rowCount() < 2)
            tableWidget_2->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem14);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setEnabled(true);
        tableWidget_2->setGeometry(QRect(790, 70, 341, 91));
        tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_2->setRowCount(2);
        tableWidget_2->setColumnCount(4);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(78);
        tableWidget_2->horizontalHeader()->setMinimumSectionSize(36);
        tableWidget_2->verticalHeader()->setDefaultSectionSize(30);
        label_54 = new QLabel(frame_4);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(910, 40, 71, 20));
        tableWidget_3 = new QTableWidget(frame_4);
        if (tableWidget_3->columnCount() < 1)
            tableWidget_3->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        if (tableWidget_3->rowCount() < 2)
            tableWidget_3->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(1, __qtablewidgetitem17);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(950, 180, 261, 101));
        tableWidget_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_3->setAutoScrollMargin(16);
        tableWidget_3->setRowCount(2);
        tableWidget_3->setColumnCount(1);
        tableWidget_3->horizontalHeader()->setDefaultSectionSize(104);
        tableWidget_3->horizontalHeader()->setMinimumSectionSize(41);
        tableWidget_3->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_3->verticalHeader()->setMinimumSectionSize(21);
        tableWidget_6 = new QTableWidget(frame_4);
        if (tableWidget_6->columnCount() < 1)
            tableWidget_6->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_6->setHorizontalHeaderItem(0, __qtablewidgetitem18);
        if (tableWidget_6->rowCount() < 2)
            tableWidget_6->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_6->setVerticalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_6->setVerticalHeaderItem(1, __qtablewidgetitem20);
        tableWidget_6->setObjectName(QString::fromUtf8("tableWidget_6"));
        tableWidget_6->setEnabled(true);
        tableWidget_6->setGeometry(QRect(690, 180, 211, 101));
        tableWidget_6->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_6->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_6->setRowCount(2);
        tableWidget_6->setColumnCount(1);
        tableWidget_6->verticalHeader()->setDefaultSectionSize(30);
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
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 0, 1281, 361));
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Plain);
        frame_3->setLineWidth(2);
        frame_3->setMidLineWidth(4);
        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(10, 0, 1261, 351));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Raised);
        frame_5->setLineWidth(4);
        tableWidget = new QTableWidget(frame_5);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem28);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem30);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 45, 1111, 111));
        tableWidget->setBaseSize(QSize(0, 0));
        tableWidget->setFrameShape(QFrame::Box);
        tableWidget->setLineWidth(2);
        tableWidget->setMidLineWidth(2);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget->setAutoScroll(false);
        tableWidget->setIconSize(QSize(15, 30));
        tableWidget->setSortingEnabled(false);
        tableWidget->setRowCount(2);
        tableWidget->setColumnCount(10);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(104);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(42);
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
        doubleSpinBox_3->setGeometry(QRect(20, 300, 201, 31));
        doubleSpinBox_3->setReadOnly(true);
        doubleSpinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBox_3->setDecimals(4);
        doubleSpinBox_3->setMinimum(0.000000000000000);
        doubleSpinBox_3->setMaximum(10000.000000000000000);
        doubleSpinBox_3->setValue(0.000000000000000);
        doubleSpinBox_22 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_22->setObjectName(QString::fromUtf8("doubleSpinBox_22"));
        doubleSpinBox_22->setGeometry(QRect(490, 240, 171, 41));
        doubleSpinBox_22->setDecimals(2);
        doubleSpinBox_22->setMinimum(0.000000000000000);
        doubleSpinBox_22->setMaximum(1000.000000000000000);
        doubleSpinBox_22->setSingleStep(0.010000000000000);
        doubleSpinBox_22->setValue(4.000000000000000);
        doubleSpinBox_23 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_23->setObjectName(QString::fromUtf8("doubleSpinBox_23"));
        doubleSpinBox_23->setGeometry(QRect(300, 240, 171, 41));
        doubleSpinBox_23->setDecimals(2);
        doubleSpinBox_23->setMinimum(0.000000000000000);
        doubleSpinBox_23->setMaximum(1000.000000000000000);
        doubleSpinBox_23->setSingleStep(0.100000000000000);
        doubleSpinBox_23->setValue(5.000000000000000);
        frame_6 = new QFrame(frame_5);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(20, 240, 211, 41));
        frame_6->setFrameShape(QFrame::WinPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        comboBox_3 = new QComboBox(frame_6);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(90, 10, 113, 30));
        comboBox_3->setToolTipDuration(-1);
        comboBox_3->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBox_3->setModelColumn(0);
        label_58 = new QLabel(frame_6);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(10, 10, 71, 20));
        frame_8 = new QFrame(frame_5);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(20, 170, 301, 61));
        frame_8->setFrameShape(QFrame::WinPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        comboBox_2 = new QComboBox(frame_8);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(10, 30, 150, 30));
        comboBox_2->setToolTipDuration(-1);
        comboBox_2->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBox_2->setModelColumn(0);
        label_57 = new QLabel(frame_8);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(10, 0, 131, 20));
        pushButton = new QPushButton(frame_8);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 22, 101, 31));
        doubleSpinBox_25 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_25->setObjectName(QString::fromUtf8("doubleSpinBox_25"));
        doubleSpinBox_25->setGeometry(QRect(670, 240, 171, 41));
        doubleSpinBox_25->setDecimals(2);
        doubleSpinBox_25->setMinimum(0.000000000000000);
        doubleSpinBox_25->setMaximum(1000.000000000000000);
        doubleSpinBox_25->setSingleStep(0.010000000000000);
        doubleSpinBox_25->setValue(4.500000000000000);
        doubleSpinBox_26 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_26->setObjectName(QString::fromUtf8("doubleSpinBox_26"));
        doubleSpinBox_26->setGeometry(QRect(670, 290, 171, 41));
        doubleSpinBox_26->setDecimals(0);
        doubleSpinBox_26->setMinimum(0.000000000000000);
        doubleSpinBox_26->setMaximum(1000.000000000000000);
        doubleSpinBox_26->setSingleStep(0.010000000000000);
        doubleSpinBox_26->setValue(1.000000000000000);
        doubleSpinBox_27 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_27->setObjectName(QString::fromUtf8("doubleSpinBox_27"));
        doubleSpinBox_27->setGeometry(QRect(490, 290, 161, 41));
        doubleSpinBox_27->setDecimals(3);
        doubleSpinBox_27->setMinimum(0.000000000000000);
        doubleSpinBox_27->setMaximum(1000.000000000000000);
        doubleSpinBox_27->setSingleStep(0.100000000000000);
        doubleSpinBox_27->setValue(0.000000000000000);
        doubleSpinBox_28 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_28->setObjectName(QString::fromUtf8("doubleSpinBox_28"));
        doubleSpinBox_28->setGeometry(QRect(300, 290, 171, 41));
        doubleSpinBox_28->setDecimals(1);
        doubleSpinBox_28->setMinimum(-10000.000000000000000);
        doubleSpinBox_28->setMaximum(1000.000000000000000);
        doubleSpinBox_28->setSingleStep(0.100000000000000);
        doubleSpinBox_28->setValue(180.000000000000000);
        frame = new QFrame(frame_5);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(890, 180, 331, 151));
        frame->setToolTipDuration(-1);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(2);
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 50, 31, 17));
        checkBox->setCheckable(true);
        checkBox->setChecked(true);
        checkBox_2 = new QCheckBox(frame);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(120, 50, 41, 17));
        checkBox_2->setChecked(true);
        checkBox_3 = new QCheckBox(frame);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 77, 81, 20));
        checkBox_3->setChecked(true);
        checkBox_4 = new QCheckBox(frame);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(10, 110, 51, 17));
        checkBox_4->setChecked(true);
        checkBox_5 = new QCheckBox(frame);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(210, 110, 81, 17));
        checkBox_5->setChecked(true);
        checkBox_7 = new QCheckBox(frame);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(120, 110, 81, 17));
        checkBox_7->setChecked(true);
        checkBox_8 = new QCheckBox(frame);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setGeometry(QRect(120, 80, 71, 17));
        checkBox_8->setChecked(true);
        checkBox_9 = new QCheckBox(frame);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setGeometry(QRect(210, 80, 81, 17));
        checkBox_9->setChecked(true);
        checkBox_10 = new QCheckBox(frame);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setGeometry(QRect(220, 50, 81, 17));
        checkBox_10->setChecked(true);
        label_56 = new QLabel(frame);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(40, 10, 281, 20));
        doubleSpinBox_29 = new QDoubleSpinBox(frame_5);
        doubleSpinBox_29->setObjectName(QString::fromUtf8("doubleSpinBox_29"));
        doubleSpinBox_29->setGeometry(QRect(380, 180, 231, 41));
        doubleSpinBox_29->setLayoutDirection(Qt::LeftToRight);
        doubleSpinBox_29->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        doubleSpinBox_29->setSuffix(QString::fromUtf8(" \320\275\320\274"));
        doubleSpinBox_29->setDecimals(3);
        doubleSpinBox_29->setMinimum(0.000000000000000);
        doubleSpinBox_29->setMaximum(1000.000000000000000);
        doubleSpinBox_29->setSingleStep(0.100000000000000);
        doubleSpinBox_29->setValue(0.010000000000000);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1381, 26));
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

        comboBox_3->setCurrentIndex(0);
        comboBox_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DYNAMIC_ID", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\277\321\203\321\202\321\214 \320\272 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\270 \321\204\320\260\320\271\320\273\320\260\320\274\320\270 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\276\320\262", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_41->setText(QApplication::translate("MainWindow", "\320\237\320\236\320\241\320\242\320\240\320\236\320\225\320\235\320\230\320\225 \320\242\320\240\320\220\320\225\320\232\320\242\320\236\320\240\320\230\320\231", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "RUN", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Tetta, \320\263\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Omega, \320\263\321\200\320\260\320\264/\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "I_d, ma", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "I_qu, ma", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_4->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "U_d", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_4->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "U_qu", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_4->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\202 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_4->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\224\320\270\321\204. \321\203\321\200.", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_4->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\260\320\273 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        label_55->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\270\320\262\321\210\320\265\320\263\320\276\321\201\321\217 \320\264\320\262\320\270\320\266\320\265\320\275\320\270\321\217 :", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Lamb1", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Lamb2", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Lamb3", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Lamb4", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Re", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Im", nullptr));
        label_54->setText(QApplication::translate("MainWindow", "\320\232\320\276\321\200\320\275\320\270 :", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207. \321\203\321\201\320\273\320\276\320\262\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_3->verticalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_3->verticalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "\320\243\320\263. \321\201\320\272\320\276\321\200., \320\263\321\200\320\260\320\264/\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_6->horizontalHeaderItem(0);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_6->verticalHeaderItem(0);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Tetta, \320\263\321\200.", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_6->verticalHeaderItem(1);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "Om, \320\263\321\200/\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "L, \320\274\320\223", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "R, \320\236\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "Psi_f", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "Jrot", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "Mresid", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "Jload", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "C_om", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "OmStat", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\264\320\265\320\273\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\260\320\273\320\270\320\267", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\253 \320\237\320\240\320\230\320\222\320\236\320\224\320\220", nullptr));
        doubleSpinBox_3->setPrefix(QApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264. \320\275\320\265\320\262\321\217\320\267\320\272\320\260 ", nullptr));
        doubleSpinBox_22->setPrefix(QApplication::translate("MainWindow", "Time U.: ", nullptr));
        doubleSpinBox_22->setSuffix(QApplication::translate("MainWindow", " \321\201", nullptr));
        doubleSpinBox_23->setPrefix(QApplication::translate("MainWindow", "ModU    ", nullptr));
        doubleSpinBox_23->setSuffix(QApplication::translate("MainWindow", " \320\222", nullptr));
        comboBox_3->setItemText(0, QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217", nullptr));
        comboBox_3->setItemText(1, QApplication::translate("MainWindow", "\320\221\320\240\320\233\320\241", nullptr));

        comboBox_3->setCurrentText(QApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202\320\276\320\262\320\260\321\217", nullptr));
        label_58->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\263\321\200\321\203\320\267\320\272\320\260", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("MainWindow", "\320\237\320\276 \321\201\321\202\320\260\321\206 \321\200\320\265\321\210", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("MainWindow", "\320\237\320\276 \320\264\320\270\320\275\320\260\320\274\320\270\320\272\320\265", nullptr));

        comboBox_2->setCurrentText(QApplication::translate("MainWindow", "\320\237\320\276 \321\201\321\202\320\260\321\206 \321\200\320\265\321\210", nullptr));
        label_57->setText(QApplication::translate("MainWindow", "\320\230\320\264\320\265\320\275\321\202. \320\277\320\260\321\200\320\260\320\274.", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "RUN", nullptr));
        doubleSpinBox_25->setPrefix(QApplication::translate("MainWindow", "TMoving.: ", nullptr));
        doubleSpinBox_25->setSuffix(QApplication::translate("MainWindow", " \321\201", nullptr));
        doubleSpinBox_26->setPrefix(QApplication::translate("MainWindow", "N Ispit  ", nullptr));
        doubleSpinBox_26->setSuffix(QString());
        doubleSpinBox_27->setPrefix(QApplication::translate("MainWindow", "Tetta0    ", nullptr));
        doubleSpinBox_27->setSuffix(QApplication::translate("MainWindow", " \320\263\321\200\320\260\320\264", nullptr));
        doubleSpinBox_28->setPrefix(QApplication::translate("MainWindow", "TrgOm ", nullptr));
        doubleSpinBox_28->setSuffix(QApplication::translate("MainWindow", " \320\263\321\200\320\260\320\264", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "L", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindow", "R", nullptr));
        checkBox_3->setText(QApplication::translate("MainWindow", "M_Out", nullptr));
        checkBox_4->setText(QApplication::translate("MainWindow", "Cv", nullptr));
        checkBox_5->setText(QApplication::translate("MainWindow", "PhHrm", nullptr));
        checkBox_7->setText(QApplication::translate("MainWindow", "AHrm", nullptr));
        checkBox_8->setText(QApplication::translate("MainWindow", "J_Load", nullptr));
        checkBox_9->setText(QApplication::translate("MainWindow", "ComX", nullptr));
        checkBox_10->setText(QApplication::translate("MainWindow", "Psi_f", nullptr));
        label_56->setText(QApplication::translate("MainWindow", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\321\200\321\203\320\265\320\274\321\213\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 :", nullptr));
        doubleSpinBox_29->setPrefix(QApplication::translate("MainWindow", "\320\234\320\276\320\274 \321\201\321\203\321\205 \321\202\321\200  ", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
