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
    QFrame *frame_8;
    QLabel *label_8;
    QTableWidget *tableWidget_5;
    QFrame *frame_9;
    QLabel *label_9;
    QTableWidget *tableWidget_9;
    QPushButton *pushButton_2;
    QFrame *frame_7;
    QLabel *label_7;
    QFrame *frame_10;
    QLabel *label_10;
    QTableWidget *tableWidget_7;
    QFrame *frame_11;
    QLabel *label_11;
    QTableWidget *tableWidget_8;
    QFrame *frame_12;
    QLabel *label_12;
    QFrame *frame_13;
    QLabel *label_13;
    QTableWidget *tableWidget_10;
    QFrame *frame_14;
    QLabel *label_14;
    QTableWidget *tableWidget_11;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1302, 735);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(10, 0, 1201, 301));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Plain);
        frame_3->setLineWidth(3);
        frame = new QFrame(frame_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 40, 511, 131));
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
        tableWidget->setGeometry(QRect(10, 30, 481, 91));
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
        frame_2->setGeometry(QRect(580, 40, 531, 131));
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
        tableWidget_2->setGeometry(QRect(20, 30, 481, 91));
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
        label->setGeometry(QRect(400, 10, 261, 21));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        frame_8 = new QFrame(frame_3);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(10, 180, 221, 111));
        frame_8->setFrameShape(QFrame::Box);
        frame_8->setFrameShadow(QFrame::Plain);
        label_8 = new QLabel(frame_8);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 10, 191, 20));
        QFont font2;
        font2.setPointSize(9);
        label_8->setFont(font2);
        tableWidget_5 = new QTableWidget(frame_8);
        if (tableWidget_5->columnCount() < 3)
            tableWidget_5->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        if (tableWidget_5->rowCount() < 1)
            tableWidget_5->setRowCount(1);
        tableWidget_5->setObjectName(QString::fromUtf8("tableWidget_5"));
        tableWidget_5->setGeometry(QRect(10, 30, 201, 71));
        tableWidget_5->setFont(font2);
        tableWidget_5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_5->setRowCount(1);
        tableWidget_5->setColumnCount(3);
        tableWidget_5->horizontalHeader()->setDefaultSectionSize(66);
        tableWidget_5->verticalHeader()->setVisible(false);
        frame_9 = new QFrame(frame_3);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setGeometry(QRect(250, 180, 221, 111));
        frame_9->setFrameShape(QFrame::Box);
        frame_9->setFrameShadow(QFrame::Plain);
        label_9 = new QLabel(frame_9);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 10, 191, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setWeight(50);
        label_9->setFont(font3);
        tableWidget_9 = new QTableWidget(frame_9);
        if (tableWidget_9->columnCount() < 3)
            tableWidget_9->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_9->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_9->setHorizontalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_9->setHorizontalHeaderItem(2, __qtablewidgetitem21);
        if (tableWidget_9->rowCount() < 1)
            tableWidget_9->setRowCount(1);
        tableWidget_9->setObjectName(QString::fromUtf8("tableWidget_9"));
        tableWidget_9->setGeometry(QRect(10, 30, 201, 71));
        tableWidget_9->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_9->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_9->setRowCount(1);
        tableWidget_9->setColumnCount(3);
        tableWidget_9->horizontalHeader()->setVisible(true);
        tableWidget_9->horizontalHeader()->setDefaultSectionSize(66);
        tableWidget_9->verticalHeader()->setVisible(false);
        pushButton_2 = new QPushButton(frame_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(560, 190, 231, 81));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(18);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        pushButton_2->setFont(font4);
        pushButton_2->setLayoutDirection(Qt::LeftToRight);
        pushButton_2->setAutoFillBackground(true);
        frame_7 = new QFrame(centralWidget);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setEnabled(true);
        frame_7->setGeometry(QRect(10, 310, 1201, 181));
        frame_7->setFrameShape(QFrame::Box);
        frame_7->setFrameShadow(QFrame::Plain);
        frame_7->setLineWidth(3);
        label_7 = new QLabel(frame_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(620, 10, 241, 21));
        label_7->setFont(font1);
        frame_10 = new QFrame(frame_7);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setGeometry(QRect(10, 10, 261, 161));
        frame_10->setFrameShape(QFrame::Box);
        frame_10->setFrameShadow(QFrame::Plain);
        label_10 = new QLabel(frame_10);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(40, 10, 221, 20));
        label_10->setFont(font2);
        tableWidget_7 = new QTableWidget(frame_10);
        if (tableWidget_7->columnCount() < 2)
            tableWidget_7->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_7->setHorizontalHeaderItem(1, __qtablewidgetitem23);
        if (tableWidget_7->rowCount() < 3)
            tableWidget_7->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_7->setVerticalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_7->setVerticalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_7->setVerticalHeaderItem(2, __qtablewidgetitem26);
        tableWidget_7->setObjectName(QString::fromUtf8("tableWidget_7"));
        tableWidget_7->setGeometry(QRect(10, 30, 241, 121));
        tableWidget_7->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_7->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_7->setRowCount(3);
        tableWidget_7->setColumnCount(2);
        tableWidget_7->horizontalHeader()->setDefaultSectionSize(75);
        tableWidget_7->horizontalHeader()->setMinimumSectionSize(35);
        tableWidget_7->verticalHeader()->setVisible(true);
        tableWidget_7->verticalHeader()->setDefaultSectionSize(30);
        frame_11 = new QFrame(frame_7);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setGeometry(QRect(280, 40, 911, 131));
        frame_11->setFrameShape(QFrame::Box);
        frame_11->setFrameShadow(QFrame::Plain);
        label_11 = new QLabel(frame_11);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(380, 0, 151, 20));
        label_11->setFont(font2);
        tableWidget_8 = new QTableWidget(frame_11);
        if (tableWidget_8->columnCount() < 9)
            tableWidget_8->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(2, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(3, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(4, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(5, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(6, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(7, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_8->setHorizontalHeaderItem(8, __qtablewidgetitem35);
        if (tableWidget_8->rowCount() < 2)
            tableWidget_8->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_8->setVerticalHeaderItem(0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_8->setVerticalHeaderItem(1, __qtablewidgetitem37);
        tableWidget_8->setObjectName(QString::fromUtf8("tableWidget_8"));
        tableWidget_8->setGeometry(QRect(10, 30, 891, 91));
        tableWidget_8->setFont(font3);
        tableWidget_8->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_8->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_8->setRowCount(2);
        tableWidget_8->setColumnCount(9);
        tableWidget_8->horizontalHeader()->setDefaultSectionSize(90);
        tableWidget_8->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_8->verticalHeader()->setVisible(true);
        tableWidget_8->verticalHeader()->setDefaultSectionSize(30);
        frame_12 = new QFrame(centralWidget);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setEnabled(true);
        frame_12->setGeometry(QRect(10, 490, 1201, 191));
        frame_12->setFrameShape(QFrame::Box);
        frame_12->setFrameShadow(QFrame::Plain);
        frame_12->setLineWidth(3);
        label_12 = new QLabel(frame_12);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(610, 10, 251, 21));
        label_12->setFont(font1);
        frame_13 = new QFrame(frame_12);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setGeometry(QRect(10, 10, 321, 171));
        frame_13->setFrameShape(QFrame::Box);
        frame_13->setFrameShadow(QFrame::Plain);
        label_13 = new QLabel(frame_13);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(40, 10, 251, 20));
        label_13->setFont(font2);
        tableWidget_10 = new QTableWidget(frame_13);
        if (tableWidget_10->columnCount() < 2)
            tableWidget_10->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_10->setHorizontalHeaderItem(0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_10->setHorizontalHeaderItem(1, __qtablewidgetitem39);
        if (tableWidget_10->rowCount() < 3)
            tableWidget_10->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_10->setVerticalHeaderItem(0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_10->setVerticalHeaderItem(1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget_10->setVerticalHeaderItem(2, __qtablewidgetitem42);
        tableWidget_10->setObjectName(QString::fromUtf8("tableWidget_10"));
        tableWidget_10->setGeometry(QRect(10, 30, 281, 131));
        tableWidget_10->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_10->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_10->setRowCount(3);
        tableWidget_10->setColumnCount(2);
        tableWidget_10->horizontalHeader()->setDefaultSectionSize(90);
        tableWidget_10->horizontalHeader()->setMinimumSectionSize(35);
        tableWidget_10->verticalHeader()->setVisible(true);
        tableWidget_10->verticalHeader()->setDefaultSectionSize(30);
        frame_14 = new QFrame(frame_12);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setGeometry(QRect(360, 40, 761, 131));
        frame_14->setFrameShape(QFrame::Box);
        frame_14->setFrameShadow(QFrame::Plain);
        label_14 = new QLabel(frame_14);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(290, 0, 151, 20));
        label_14->setFont(font2);
        tableWidget_11 = new QTableWidget(frame_14);
        if (tableWidget_11->columnCount() < 6)
            tableWidget_11->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_11->setHorizontalHeaderItem(0, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget_11->setHorizontalHeaderItem(1, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget_11->setHorizontalHeaderItem(2, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget_11->setHorizontalHeaderItem(3, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget_11->setHorizontalHeaderItem(4, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget_11->setHorizontalHeaderItem(5, __qtablewidgetitem48);
        if (tableWidget_11->rowCount() < 2)
            tableWidget_11->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget_11->setVerticalHeaderItem(0, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget_11->setVerticalHeaderItem(1, __qtablewidgetitem50);
        tableWidget_11->setObjectName(QString::fromUtf8("tableWidget_11"));
        tableWidget_11->setGeometry(QRect(10, 30, 731, 91));
        tableWidget_11->setFont(font3);
        tableWidget_11->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_11->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_11->setRowCount(2);
        tableWidget_11->setColumnCount(6);
        tableWidget_11->horizontalHeader()->setDefaultSectionSize(95);
        tableWidget_11->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_11->verticalHeader()->setVisible(true);
        tableWidget_11->verticalHeader()->setDefaultSectionSize(30);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1302, 21));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\320\220\320\233\320\254\320\232\320\243\320\233\320\257\320\242\320\236\320\240 \320\241\320\230\320\241\320\242\320\225\320\234\320\220\320\242\320\230\320\247\320\225\320\241\320\232\320\230\320\245 \320\236\320\250\320\230\320\221\320\236\320\232 \320\237\320\240\320\230 \320\256\320\241\320\242\320\230\320\240\320\236\320\222\320\232\320\225", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Bet, \321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Eps, \321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Alf, \321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\270\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\236\321\206\320\265\320\275\320\272\320\260", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\253 \320\237\320\236\320\227\320\230\320\246\320\230\320\236\320\235 \320\240\320\233\320\232 \320\222 \320\237\320\241\320\232, \320\274, \321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Bet, \321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Eps, \321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Alf, \321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\270\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "\320\236\321\206\320\265\320\275\320\272\320\260", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\253 \320\237\320\236\320\227\320\230\320\246\320\230\320\236\320\235 \320\230\320\243 \320\222 \320\237\320\241\320\232, \320\274, \321\200\320\260\320\264", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\230\320\241\320\245\320\236\320\224\320\235\320\253\320\225 \320\224\320\220\320\235\320\235\320\253\320\225", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\237\320\220\320\233\320\243\320\221\320\235\320\253\320\225 \320\243\320\223\320\233\320\253 \320\232\320\236\320\240\320\220\320\221\320\233\320\257, \321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Qk, \320\263\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_5->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Psi, \320\263\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_5->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "Tet, \320\263\321\200\320\260\320\264", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\237\320\236\320\233\320\236\320\226\320\225\320\235\320\230\320\225 \320\246\320\225\320\233\320\230 \320\232\320\223\320\241\320\232, \320\274, \321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_9->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Q\321\206, \321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_9->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "D\321\206, \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_9->horizontalHeaderItem(2);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "H\321\206, \320\274", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\222\320\253\320\247\320\230\320\241\320\233\320\230\320\242\320\254 ", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\232\320\220\320\226\320\243\320\251\320\220\320\257\320\241\320\257 \320\241\320\232 \320\230\320\243", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\320\243\320\223\320\233\320\253 \320\235\320\220\320\222\320\225\320\224\320\225\320\235\320\230\320\257 \320\230\320\243, \320\274\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_7->horizontalHeaderItem(0);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "\320\237\320\243\320\223\320\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_7->horizontalHeaderItem(1);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "\320\237\320\243\320\222\320\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_7->verticalHeaderItem(0);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "\320\230\320\241\320\242\320\230\320\235\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_7->verticalHeaderItem(1);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "\320\236\320\246\320\225\320\235\320\232\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_7->verticalHeaderItem(2);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "\320\236\320\250\320\230\320\221\320\232\320\220", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\320\224\320\230\320\244\320\244\320\225\320\240\320\225\320\235\320\246\320\230\320\220\320\233\320\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_8->horizontalHeaderItem(0);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "X,\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_8->horizontalHeaderItem(1);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "Y \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_8->horizontalHeaderItem(2);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "Z \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_8->horizontalHeaderItem(3);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "Bet \320\240\320\233\320\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_8->horizontalHeaderItem(4);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "Bet \320\230\320\243", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_8->horizontalHeaderItem(5);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "Eps \320\240\320\233\320\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_8->horizontalHeaderItem(6);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "Eps \320\230\320\243", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_8->horizontalHeaderItem(7);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "Alf \320\240\320\233\320\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_8->horizontalHeaderItem(8);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "Alf \320\230\320\243", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_8->verticalHeaderItem(0);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "dBet, \320\274\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_8->verticalHeaderItem(1);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "dEps,\320\274\321\200\320\260\320\264", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "\320\220\320\221\320\241\320\236\320\233\320\256\320\242\320\235\320\220\320\257 \320\241\320\232 \320\230\320\243", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "\320\243\320\223\320\233\320\253 \320\235\320\220\320\222\320\225\320\224\320\225\320\235\320\230\320\257 \320\230\320\243, \320\274\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_10->horizontalHeaderItem(0);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "\320\237\320\243\320\223\320\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_10->horizontalHeaderItem(1);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "\320\237\320\243\320\222\320\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_10->verticalHeaderItem(0);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "\320\230\320\241\320\242\320\230\320\235\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_10->verticalHeaderItem(1);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "\320\236\320\246\320\225\320\235\320\232\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_10->verticalHeaderItem(2);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "\320\236\320\250\320\230\320\221\320\232\320\220", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\224\320\230\320\244\320\244\320\225\320\240\320\225\320\235\320\246\320\230\320\220\320\233\320\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget_11->horizontalHeaderItem(0);
        ___qtablewidgetitem43->setText(QApplication::translate("MainWindow", "X \320\230\320\243,\320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget_11->horizontalHeaderItem(1);
        ___qtablewidgetitem44->setText(QApplication::translate("MainWindow", "Y \320\230\320\243 \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget_11->horizontalHeaderItem(2);
        ___qtablewidgetitem45->setText(QApplication::translate("MainWindow", "Z \320\230\320\243 \320\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget_11->horizontalHeaderItem(3);
        ___qtablewidgetitem46->setText(QApplication::translate("MainWindow", "Bet \320\230\320\243", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget_11->horizontalHeaderItem(4);
        ___qtablewidgetitem47->setText(QApplication::translate("MainWindow", "Eps \320\230\320\243", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget_11->horizontalHeaderItem(5);
        ___qtablewidgetitem48->setText(QApplication::translate("MainWindow", "Alf \320\230\320\243", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget_11->verticalHeaderItem(0);
        ___qtablewidgetitem49->setText(QApplication::translate("MainWindow", "dBet, \320\274\321\200\320\260\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget_11->verticalHeaderItem(1);
        ___qtablewidgetitem50->setText(QApplication::translate("MainWindow", "dEps,\320\274\321\200\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
