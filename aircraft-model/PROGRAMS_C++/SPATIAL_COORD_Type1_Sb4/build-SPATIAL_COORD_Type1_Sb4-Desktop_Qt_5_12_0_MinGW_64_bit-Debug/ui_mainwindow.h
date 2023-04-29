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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame_3;
    QFrame *frame;
    QTableWidget *tableWidget;
    QLabel *label_2;
    QFrame *frame_2;
    QTableWidget *tableWidget_2;
    QLabel *label_4;
    QLabel *label;
    QFrame *frame_4;
    QLabel *label_3;
    QTableWidget *tableWidget_3;
    QDoubleSpinBox *doubleSpinBox;
    QCheckBox *checkBox_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QPushButton *pushButton;
    QFrame *frame_5;
    QLabel *label_5;
    QTableWidget *tableWidget_4;
    QFrame *frame_7;
    QLabel *label_7;
    QFrame *frame_11;
    QLabel *label_11;
    QTableWidget *tableWidget_8;
    QLabel *label_10;
    QTableWidget *tableWidget_7;
    QFrame *frame_6;
    QTableWidget *tableWidget_9;
    QTableWidget *tableWidget_5;
    QPushButton *pushButton_3;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_12;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1351, 774);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 10, 1311, 331));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Plain);
        frame_3->setLineWidth(3);
        frame = new QFrame(frame_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 40, 551, 141));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(2);
        tableWidget = new QTableWidget(frame);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem7);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 40, 521, 91));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setRowCount(2);
        tableWidget->setColumnCount(6);
        tableWidget->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 10, 341, 16));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        frame_2 = new QFrame(frame_3);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 180, 551, 141));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(2);
        tableWidget_2 = new QTableWidget(frame_2);
        if (tableWidget_2->columnCount() < 6)
            tableWidget_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        if (tableWidget_2->rowCount() < 2)
            tableWidget_2->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem15);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(10, 40, 521, 91));
        tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_2->setRowCount(2);
        tableWidget_2->setColumnCount(6);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_2->horizontalHeader()->setMinimumSectionSize(30);
        tableWidget_2->verticalHeader()->setDefaultSectionSize(30);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 10, 331, 16));
        label_4->setFont(font);
        label = new QLabel(frame_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 10, 261, 21));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(570, 40, 731, 281));
        frame_4->setAutoFillBackground(false);
        frame_4->setStyleSheet(QString::fromUtf8(""));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Plain);
        frame_4->setLineWidth(2);
        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 10, 361, 16));
        label_3->setFont(font);
        tableWidget_3 = new QTableWidget(frame_4);
        if (tableWidget_3->columnCount() < 5)
            tableWidget_3->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem20);
        if (tableWidget_3->rowCount() < 10)
            tableWidget_3->setRowCount(10);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(10, 110, 551, 161));
        tableWidget_3->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_3->setRowCount(10);
        tableWidget_3->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_3->horizontalHeader()->setMinimumSectionSize(30);
        tableWidget_3->verticalHeader()->setDefaultSectionSize(30);
        doubleSpinBox = new QDoubleSpinBox(frame_4);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(190, 40, 161, 31));
        QFont font2;
        font2.setPointSize(10);
        doubleSpinBox->setFont(font2);
        doubleSpinBox->setDecimals(0);
        doubleSpinBox->setMaximum(10000.000000000000000);
        doubleSpinBox->setSingleStep(10.000000000000000);
        doubleSpinBox->setValue(3000.000000000000000);
        checkBox_2 = new QCheckBox(frame_4);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 80, 121, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font3.setPointSize(10);
        checkBox_2->setFont(font3);
        checkBox_2->setLayoutDirection(Qt::RightToLeft);
        checkBox_2->setAutoFillBackground(true);
        doubleSpinBox_2 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(20, 40, 151, 31));
        doubleSpinBox_2->setFont(font2);
        doubleSpinBox_2->setDecimals(0);
        doubleSpinBox_2->setMinimum(0.000000000000000);
        doubleSpinBox_2->setMaximum(10000.000000000000000);
        doubleSpinBox_2->setSingleStep(1.000000000000000);
        doubleSpinBox_2->setValue(3.000000000000000);
        checkBox_3 = new QCheckBox(frame_4);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(150, 80, 251, 20));
        checkBox_3->setFont(font3);
        checkBox_3->setLayoutDirection(Qt::RightToLeft);
        checkBox_3->setAutoFillBackground(true);
        checkBox_3->setChecked(false);
        checkBox_4 = new QCheckBox(frame_4);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(430, 80, 271, 20));
        checkBox_4->setFont(font3);
        checkBox_4->setLayoutDirection(Qt::RightToLeft);
        checkBox_4->setAutoFillBackground(true);
        doubleSpinBox_3 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(370, 40, 141, 31));
        doubleSpinBox_3->setFont(font2);
        doubleSpinBox_3->setDecimals(0);
        doubleSpinBox_3->setMaximum(100000000.000000000000000);
        doubleSpinBox_3->setSingleStep(100.000000000000000);
        doubleSpinBox_3->setValue(5000.000000000000000);
        doubleSpinBox_4 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(530, 40, 141, 31));
        doubleSpinBox_4->setFont(font2);
        doubleSpinBox_4->setDecimals(0);
        doubleSpinBox_4->setMaximum(1000000000.000000000000000);
        doubleSpinBox_4->setSingleStep(100.000000000000000);
        doubleSpinBox_4->setValue(12000.000000000000000);
        pushButton = new QPushButton(frame_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(570, 120, 121, 51));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        pushButton->setFont(font4);
        frame_5 = new QFrame(centralWidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(10, 350, 611, 251));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Plain);
        frame_5->setLineWidth(3);
        label_5 = new QLabel(frame_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 581, 21));
        label_5->setFont(font1);
        tableWidget_4 = new QTableWidget(frame_5);
        if (tableWidget_4->columnCount() < 6)
            tableWidget_4->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(2, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(3, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(4, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(5, __qtablewidgetitem26);
        if (tableWidget_4->rowCount() < 4)
            tableWidget_4->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(2, __qtablewidgetitem29);
        tableWidget_4->setObjectName(QString::fromUtf8("tableWidget_4"));
        tableWidget_4->setGeometry(QRect(10, 40, 591, 151));
        tableWidget_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_4->setRowCount(4);
        tableWidget_4->setColumnCount(6);
        tableWidget_4->horizontalHeader()->setDefaultSectionSize(80);
        tableWidget_4->horizontalHeader()->setMinimumSectionSize(80);
        tableWidget_4->verticalHeader()->setDefaultSectionSize(40);
        frame_7 = new QFrame(centralWidget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setEnabled(true);
        frame_7->setGeometry(QRect(630, 350, 691, 361));
        frame_7->setFrameShape(QFrame::Box);
        frame_7->setFrameShadow(QFrame::Plain);
        frame_7->setLineWidth(3);
        label_7 = new QLabel(frame_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(230, 10, 191, 21));
        label_7->setFont(font1);
        frame_11 = new QFrame(frame_7);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setGeometry(QRect(10, 220, 641, 131));
        frame_11->setFrameShape(QFrame::Box);
        frame_11->setFrameShadow(QFrame::Plain);
        label_11 = new QLabel(frame_11);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(250, 10, 151, 20));
        QFont font5;
        font5.setPointSize(9);
        label_11->setFont(font5);
        tableWidget_8 = new QTableWidget(frame_11);
        if (tableWidget_8->columnCount() < 6)
            tableWidget_8->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(3, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(4, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(5, __qtablewidgetitem35);
        if (tableWidget_8->rowCount() < 2)
            tableWidget_8->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_8->setVerticalHeaderItem(0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_8->setVerticalHeaderItem(1, __qtablewidgetitem37);
        tableWidget_8->setObjectName(QString::fromUtf8("tableWidget_8"));
        tableWidget_8->setGeometry(QRect(10, 30, 621, 91));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Times New Roman"));
        font6.setPointSize(9);
        font6.setBold(false);
        font6.setWeight(50);
        tableWidget_8->setFont(font6);
        tableWidget_8->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_8->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_8->setRowCount(2);
        tableWidget_8->setColumnCount(6);
        tableWidget_8->horizontalHeader()->setDefaultSectionSize(90);
        tableWidget_8->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_8->verticalHeader()->setVisible(true);
        tableWidget_8->verticalHeader()->setDefaultSectionSize(30);
        label_10 = new QLabel(frame_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(450, 30, 231, 20));
        label_10->setFont(font5);
        tableWidget_7 = new QTableWidget(frame_7);
        if (tableWidget_7->columnCount() < 2)
            tableWidget_7->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(1, __qtablewidgetitem39);
        if (tableWidget_7->rowCount() < 5)
            tableWidget_7->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_7->setVerticalHeaderItem(0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_7->setVerticalHeaderItem(1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget_7->setVerticalHeaderItem(2, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_7->setVerticalHeaderItem(3, __qtablewidgetitem43);
        tableWidget_7->setObjectName(QString::fromUtf8("tableWidget_7"));
        tableWidget_7->setGeometry(QRect(450, 60, 221, 151));
        tableWidget_7->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_7->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_7->setRowCount(5);
        tableWidget_7->setColumnCount(2);
        tableWidget_7->horizontalHeader()->setDefaultSectionSize(72);
        tableWidget_7->horizontalHeader()->setMinimumSectionSize(35);
        tableWidget_7->verticalHeader()->setVisible(true);
        tableWidget_7->verticalHeader()->setDefaultSectionSize(30);
        frame_6 = new QFrame(frame_7);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(10, 40, 431, 171));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Sunken);
        frame_6->setLineWidth(4);
        tableWidget_9 = new QTableWidget(frame_6);
        if (tableWidget_9->columnCount() < 3)
            tableWidget_9->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget_9->setHorizontalHeaderItem(0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget_9->setHorizontalHeaderItem(1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget_9->setHorizontalHeaderItem(2, __qtablewidgetitem46);
        if (tableWidget_9->rowCount() < 1)
            tableWidget_9->setRowCount(1);
        tableWidget_9->setObjectName(QString::fromUtf8("tableWidget_9"));
        tableWidget_9->setGeometry(QRect(210, 60, 201, 61));
        tableWidget_9->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_9->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_9->setRowCount(1);
        tableWidget_9->setColumnCount(3);
        tableWidget_9->horizontalHeader()->setVisible(true);
        tableWidget_9->horizontalHeader()->setDefaultSectionSize(66);
        tableWidget_9->verticalHeader()->setVisible(false);
        tableWidget_5 = new QTableWidget(frame_6);
        if (tableWidget_5->columnCount() < 3)
            tableWidget_5->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(1, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(2, __qtablewidgetitem49);
        if (tableWidget_5->rowCount() < 1)
            tableWidget_5->setRowCount(1);
        tableWidget_5->setObjectName(QString::fromUtf8("tableWidget_5"));
        tableWidget_5->setGeometry(QRect(10, 60, 201, 61));
        tableWidget_5->setFont(font5);
        tableWidget_5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_5->setRowCount(1);
        tableWidget_5->setColumnCount(3);
        tableWidget_5->horizontalHeader()->setDefaultSectionSize(66);
        tableWidget_5->verticalHeader()->setVisible(false);
        pushButton_3 = new QPushButton(frame_6);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(140, 130, 111, 31));
        pushButton_3->setFont(font4);
        pushButton_3->setLayoutDirection(Qt::LeftToRight);
        pushButton_3->setAutoFillBackground(true);
        label_8 = new QLabel(frame_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 40, 131, 16));
        label_8->setFont(font5);
        label_9 = new QLabel(frame_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(230, 40, 161, 20));
        label_9->setFont(font6);
        label_12 = new QLabel(frame_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(140, 10, 181, 16));
        QFont font7;
        font7.setPointSize(9);
        font7.setBold(true);
        font7.setWeight(75);
        label_12->setFont(font7);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1351, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\320\236\320\236\320\240\320\224\320\230\320\235\320\220\320\242\320\253 \320\232\320\236 \320\235\320\225 \320\230\320\227\320\222\320\225\320\241\320\242\320\235\320\253  \320\241\320\221. 2020_06_05", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Bet", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Eps", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Alf", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\270\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\262 \320\276\321\206\320\265\320\275\320\272\320\260", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\253 \320\237\320\236\320\227\320\230\320\246\320\230\320\236\320\235 \320\240\320\233\320\232 \320\222 \320\237\320\241\320\232, \320\274, \321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Bet", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Eps", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Alf", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\270\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\262 \320\276\321\206\320\265\320\275\320\272\320\260", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\253 \320\237\320\236\320\227\320\230\320\246\320\230\320\236\320\235 \320\230\320\243 \320\222 \320\237\320\241\320\232, \320\274, \321\200\320\260\320\264", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\230\320\241\320\245\320\236\320\224\320\235\320\253\320\225 \320\224\320\220\320\235\320\235\320\253\320\225", nullptr));
        label_3->setText(QApplication::translate("MainWindow", " \320\232\320\236\320\236\320\240\320\224\320\230\320\235\320\220\320\242\320\253 \320\232\320\236 \320\222 \320\232\320\223\320\241\320\232 + \320\243\320\223\320\233\320\253 \320\246\320\232\320\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "q \320\232\320\236, \320\263\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "R \320\232\320\236, \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "\320\243\320\263.  Q,  \320\263\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "\320\243\320\263. Psi, \320\263\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "\320\243\320\263. Tet,, \320\263\321\200\320\260\320\264", nullptr));
        doubleSpinBox->setPrefix(QApplication::translate("MainWindow", "\320\222\320\253\320\241\320\236\320\242\320\220  ", nullptr));
        doubleSpinBox->setSuffix(QApplication::translate("MainWindow", "  \320\274", nullptr));
        checkBox_2->setText(QApplication::translate("MainWindow", "\320\227\320\220\320\250\320\243\320\234\320\230\320\242\320\254", nullptr));
        doubleSpinBox_2->setPrefix(QApplication::translate("MainWindow", "\320\232\320\236\320\233-\320\222\320\236 \320\232\320\236: ", nullptr));
        doubleSpinBox_2->setSuffix(QString());
        checkBox_3->setText(QApplication::translate("MainWindow", "\320\236\320\246\320\225\320\235\320\230\320\222\320\220\320\242\320\254 \320\242\320\236\320\233\320\254\320\232\320\236 \320\243\320\223\320\233\320\253", nullptr));
        checkBox_4->setText(QApplication::translate("MainWindow", "\320\241\320\233\320\243\320\247 \320\227\320\220\320\237\320\236\320\233\320\235\320\225\320\235\320\230\320\225 \320\242\320\220\320\221\320\233\320\230\320\246\320\253", nullptr));
        doubleSpinBox_3->setPrefix(QApplication::translate("MainWindow", "D \320\276\321\202  ", nullptr));
        doubleSpinBox_3->setSuffix(QApplication::translate("MainWindow", "  \320\274", nullptr));
        doubleSpinBox_4->setPrefix(QApplication::translate("MainWindow", "D \320\264\320\276: ", nullptr));
        doubleSpinBox_4->setSuffix(QApplication::translate("MainWindow", "  \320\274", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "RUN", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\240\320\225\320\227\320\243\320\233\320\254\320\242\320\220\320\242 \320\236\320\246\320\225\320\235\320\232\320\230 \320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\236\320\222 \320\237\320\236\320\227\320\230\320\246\320\230\320\236\320\235\320\230\320\240.  \320\240\320\233\320\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "X, \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "Y, \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "Z, \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "Bet ,\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_4->horizontalHeaderItem(4);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "Eps ,\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_4->horizontalHeaderItem(5);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "Alf , \321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_4->verticalHeaderItem(0);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "\320\236\321\206\320\265\320\275\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_4->verticalHeaderItem(1);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "\320\241\320\232\320\236, \320\274, \320\274\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_4->verticalHeaderItem(2);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "\320\242\320\276\321\207\320\275\320\276\320\265 \321\200\320\265\321\210.", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\232\320\220\320\233\320\254\320\232\320\243\320\233\320\257\320\242\320\236\320\240", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\320\224\320\230\320\244\320\244\320\225\320\240\320\225\320\235\320\246\320\230\320\220\320\233\320\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_8->horizontalHeaderItem(0);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "X,\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_8->horizontalHeaderItem(1);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "Y \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_8->horizontalHeaderItem(2);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "Z \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_8->horizontalHeaderItem(3);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "Bet, \320\274\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_8->horizontalHeaderItem(4);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "Eps, \320\274\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_8->horizontalHeaderItem(5);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "Alf, \320\274\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_8->verticalHeaderItem(0);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "dBet, \320\274\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_8->verticalHeaderItem(1);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "dEps,\320\274\321\200\320\260\320\264", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\320\243\320\223. \320\235\320\220\320\222\320\225\320\224. \320\222 \320\232\320\220\320\226\320\243\320\251\320\225\320\231\320\241\320\257 \320\241\320\232, \320\274\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_7->horizontalHeaderItem(0);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "\320\237\320\243\320\223\320\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_7->horizontalHeaderItem(1);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "\320\237\320\243\320\222\320\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_7->verticalHeaderItem(0);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "\320\230\320\241\320\242\320\230\320\235\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_7->verticalHeaderItem(1);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "\320\236\320\246\320\225\320\235\320\232\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_7->verticalHeaderItem(2);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "\320\236\320\250\320\230\320\221\320\232\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget_7->verticalHeaderItem(3);
        ___qtablewidgetitem43->setText(QApplication::translate("MainWindow", "\320\237\320\225\320\240\320\222 \320\236\320\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget_9->horizontalHeaderItem(0);
        ___qtablewidgetitem44->setText(QApplication::translate("MainWindow", "Q\321\206, \321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget_9->horizontalHeaderItem(1);
        ___qtablewidgetitem45->setText(QApplication::translate("MainWindow", "D\321\206, \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget_9->horizontalHeaderItem(2);
        ___qtablewidgetitem46->setText(QApplication::translate("MainWindow", "H\321\206, \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem47->setText(QApplication::translate("MainWindow", "Qk", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget_5->horizontalHeaderItem(1);
        ___qtablewidgetitem48->setText(QApplication::translate("MainWindow", "Psi", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget_5->horizontalHeaderItem(2);
        ___qtablewidgetitem49->setText(QApplication::translate("MainWindow", "Tet", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "RUN", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\237\320\220\320\233\320\243\320\221\320\235\320\253\320\225 \320\243\320\223\320\233\320\253, \321\200\320\260\320\264", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\237\320\225\320\233\320\225\320\235\320\223 \320\246\320\225\320\233\320\230 \320\232\320\223\320\241\320\232, \320\274, \321\200\320\260\320\264", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\230\320\241\320\245\320\236\320\224\320\235\320\253\320\225 \320\224\320\220\320\235\320\235\320\253\320\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
