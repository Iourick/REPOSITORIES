/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
    QFrame *frame_2;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QDoubleSpinBox *doubleSpinBox_10;
    QDoubleSpinBox *doubleSpinBox_11;
    QDoubleSpinBox *doubleSpinBox_13;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_12;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_14;
    QCheckBox *checkBox_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1218, 745);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(10, 40, 1201, 651));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Plain);
        frame_3->setLineWidth(3);
        frame = new QFrame(frame_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 110, 581, 231));
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
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem10);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 40, 551, 181));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setRowCount(5);
        tableWidget->setColumnCount(6);
        tableWidget->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 10, 341, 16));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        label = new QLabel(frame_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 20, 921, 21));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(600, 110, 591, 231));
        frame_4->setAutoFillBackground(false);
        frame_4->setStyleSheet(QStringLiteral(""));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Plain);
        frame_4->setLineWidth(2);
        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 10, 421, 16));
        label_3->setFont(font);
        tableWidget_3 = new QTableWidget(frame_4);
        if (tableWidget_3->columnCount() < 5)
            tableWidget_3->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem15);
        if (tableWidget_3->rowCount() < 10)
            tableWidget_3->setRowCount(10);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(60, 110, 481, 111));
        tableWidget_3->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_3->setRowCount(10);
        tableWidget_3->horizontalHeader()->setDefaultSectionSize(80);
        tableWidget_3->horizontalHeader()->setMinimumSectionSize(30);
        tableWidget_3->verticalHeader()->setDefaultSectionSize(30);
        doubleSpinBox = new QDoubleSpinBox(frame_4);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(160, 40, 121, 31));
        QFont font2;
        font2.setPointSize(10);
        doubleSpinBox->setFont(font2);
        doubleSpinBox->setDecimals(0);
        doubleSpinBox->setMaximum(10000);
        doubleSpinBox->setSingleStep(10);
        doubleSpinBox->setValue(50);
        checkBox_2 = new QCheckBox(frame_4);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 80, 91, 20));
        QFont font3;
        font3.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font3.setPointSize(10);
        checkBox_2->setFont(font3);
        checkBox_2->setLayoutDirection(Qt::RightToLeft);
        checkBox_2->setAutoFillBackground(true);
        doubleSpinBox_2 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(10, 40, 131, 31));
        doubleSpinBox_2->setFont(font2);
        doubleSpinBox_2->setDecimals(0);
        doubleSpinBox_2->setMinimum(0);
        doubleSpinBox_2->setMaximum(10000);
        doubleSpinBox_2->setSingleStep(1);
        doubleSpinBox_2->setValue(3);
        checkBox_3 = new QCheckBox(frame_4);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(120, 80, 191, 20));
        checkBox_3->setFont(font3);
        checkBox_3->setLayoutDirection(Qt::RightToLeft);
        checkBox_3->setAutoFillBackground(true);
        checkBox_4 = new QCheckBox(frame_4);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(360, 80, 191, 20));
        checkBox_4->setFont(font3);
        checkBox_4->setLayoutDirection(Qt::RightToLeft);
        checkBox_4->setAutoFillBackground(true);
        doubleSpinBox_3 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(310, 40, 121, 31));
        doubleSpinBox_3->setFont(font2);
        doubleSpinBox_3->setDecimals(0);
        doubleSpinBox_3->setMaximum(1e+08);
        doubleSpinBox_3->setSingleStep(100);
        doubleSpinBox_3->setValue(5000);
        doubleSpinBox_4 = new QDoubleSpinBox(frame_4);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(460, 40, 121, 31));
        doubleSpinBox_4->setFont(font2);
        doubleSpinBox_4->setDecimals(0);
        doubleSpinBox_4->setMaximum(1e+09);
        doubleSpinBox_4->setSingleStep(100);
        doubleSpinBox_4->setValue(12000);
        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 570, 311, 51));
        QFont font4;
        font4.setFamily(QStringLiteral("Times New Roman"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setItalic(true);
        font4.setWeight(75);
        pushButton->setFont(font4);
        frame_2 = new QFrame(frame_3);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 350, 811, 201));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(2);
        doubleSpinBox_5 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setGeometry(QRect(520, 80, 281, 31));
        doubleSpinBox_5->setFont(font2);
        doubleSpinBox_5->setDecimals(1);
        doubleSpinBox_5->setMaximum(10000);
        doubleSpinBox_5->setSingleStep(10);
        doubleSpinBox_5->setValue(3);
        doubleSpinBox_7 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setGeometry(QRect(10, 70, 221, 31));
        doubleSpinBox_7->setFont(font2);
        doubleSpinBox_7->setKeyboardTracking(true);
        doubleSpinBox_7->setDecimals(2);
        doubleSpinBox_7->setMaximum(10000);
        doubleSpinBox_7->setSingleStep(0.1);
        doubleSpinBox_7->setValue(0.6);
        doubleSpinBox_8 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setGeometry(QRect(260, 70, 211, 31));
        doubleSpinBox_8->setFont(font2);
        doubleSpinBox_8->setDecimals(2);
        doubleSpinBox_8->setMaximum(10000);
        doubleSpinBox_8->setSingleStep(0.01);
        doubleSpinBox_8->setValue(1.16);
        doubleSpinBox_9 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        doubleSpinBox_9->setGeometry(QRect(10, 110, 221, 31));
        doubleSpinBox_9->setFont(font2);
        doubleSpinBox_9->setKeyboardTracking(true);
        doubleSpinBox_9->setDecimals(2);
        doubleSpinBox_9->setMaximum(10000);
        doubleSpinBox_9->setSingleStep(0.1);
        doubleSpinBox_9->setValue(0.44);
        doubleSpinBox_10 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));
        doubleSpinBox_10->setGeometry(QRect(260, 110, 211, 31));
        doubleSpinBox_10->setFont(font2);
        doubleSpinBox_10->setDecimals(2);
        doubleSpinBox_10->setMaximum(10000);
        doubleSpinBox_10->setSingleStep(0.01);
        doubleSpinBox_10->setValue(1.16);
        doubleSpinBox_11 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_11->setObjectName(QStringLiteral("doubleSpinBox_11"));
        doubleSpinBox_11->setGeometry(QRect(10, 150, 221, 31));
        doubleSpinBox_11->setFont(font2);
        doubleSpinBox_11->setKeyboardTracking(true);
        doubleSpinBox_11->setDecimals(2);
        doubleSpinBox_11->setMaximum(10000);
        doubleSpinBox_11->setSingleStep(0.1);
        doubleSpinBox_11->setValue(0.44);
        doubleSpinBox_13 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_13->setObjectName(QStringLiteral("doubleSpinBox_13"));
        doubleSpinBox_13->setGeometry(QRect(260, 150, 211, 31));
        doubleSpinBox_13->setFont(font2);
        doubleSpinBox_13->setDecimals(2);
        doubleSpinBox_13->setMaximum(10000);
        doubleSpinBox_13->setSingleStep(0.01);
        doubleSpinBox_13->setValue(1.16);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 20, 511, 16));
        label_4->setFont(font);
        doubleSpinBox_12 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_12->setObjectName(QStringLiteral("doubleSpinBox_12"));
        doubleSpinBox_12->setGeometry(QRect(520, 120, 281, 31));
        doubleSpinBox_12->setFont(font2);
        doubleSpinBox_12->setDecimals(1);
        doubleSpinBox_12->setMaximum(10000);
        doubleSpinBox_12->setSingleStep(10);
        doubleSpinBox_12->setValue(3);
        doubleSpinBox_6 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setGeometry(QRect(830, 360, 331, 31));
        doubleSpinBox_6->setFont(font2);
        doubleSpinBox_6->setDecimals(0);
        doubleSpinBox_6->setMaximum(10000);
        doubleSpinBox_6->setSingleStep(10);
        doubleSpinBox_6->setValue(1);
        doubleSpinBox_14 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_14->setObjectName(QStringLiteral("doubleSpinBox_14"));
        doubleSpinBox_14->setGeometry(QRect(830, 420, 331, 31));
        doubleSpinBox_14->setFont(font2);
        doubleSpinBox_14->setDecimals(2);
        doubleSpinBox_14->setMaximum(10000);
        doubleSpinBox_14->setSingleStep(10);
        doubleSpinBox_14->setValue(0.5);
        checkBox_5 = new QCheckBox(frame_3);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(40, 70, 161, 20));
        checkBox_5->setFont(font3);
        checkBox_5->setLayoutDirection(Qt::RightToLeft);
        checkBox_5->setAutoFillBackground(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1218, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\320\236\320\236\320\240\320\224\320\230\320\235\320\220\320\242\320\253 \320\232\320\236  \320\230\320\227\320\222\320\225\320\241\320\242\320\235\320\253 ", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "X", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Y", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Z", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Bet", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Eps", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Alf", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\230\321\201\321\202\320\270\320\275\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\262 \320\276\321\206\320\265\320\275\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\320\243\321\202\320\276\321\207\320\275 \320\276\321\206\320\265\320\275\320\272\320\260", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\275\320\276\321\201\321\202\321\214, \320\274, \320\274\321\200\320\260\320\264", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "\320\241\320\232\320\236, \320\274, \320\274\321\200\320\260\320\264", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\253 \320\237\320\236\320\227\320\230\320\246\320\230\320\236\320\235 \320\237\320\240\320\230\320\221\320\236\320\240\320\220 \320\222 \320\237\320\241\320\232, \320\274, \321\200\320\260\320\264", 0));
        label->setText(QApplication::translate("MainWindow", "\320\236\320\246\320\225\320\235\320\232\320\220 \320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\236\320\222 \320\237\320\236\320\227\320\230\320\246\320\230\320\236\320\235\320\230\320\240\320\236\320\222\320\220\320\235\320\230\320\257 \320\237\320\240\320\230\320\221\320\236\320\240\320\220 \320\237\320\236 \320\241\320\225\320\240\320\230\320\230 \320\230\320\227\320\234\320\225\320\240\320\225\320\235\320\230\320\231 \320\232\320\236 \320\242\320\230\320\237\320\220 2", 0));
        label_3->setText(QApplication::translate("MainWindow", "\320\230\320\241\320\242, \320\232\320\236\320\236\320\240\320\224\320\230\320\235\320\220\320\242\320\253 \320\232\320\236 \320\222 \320\232\320\223\320\241\320\232 + \320\243\320\223\320\233\320\253 \320\246\320\232\320\237", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "q \320\232\320\236, \320\263\321\200\320\260\320\264", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "R \320\232\320\236, \320\274", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "\320\243\320\263.  Q,  \320\263\321\200\320\260\320\264", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "\320\243\320\263. Psi, \320\263\321\200\320\260\320\264", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "\320\243\320\263. Tet,, \320\263\321\200\320\260\320\264", 0));
        doubleSpinBox->setPrefix(QApplication::translate("MainWindow", "\320\222\320\253\320\241\320\236\320\242\320\220  ", 0));
        doubleSpinBox->setSuffix(QApplication::translate("MainWindow", "  \320\274", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "\320\227\320\220\320\250\320\243\320\234\320\230\320\242\320\254", 0));
        doubleSpinBox_2->setPrefix(QApplication::translate("MainWindow", "\320\232\320\236\320\233-\320\222\320\236 \320\232\320\236: ", 0));
        doubleSpinBox_2->setSuffix(QString());
        checkBox_3->setText(QApplication::translate("MainWindow", "\320\236\320\246\320\225\320\235\320\230\320\222\320\220\320\242\320\254 \320\242\320\236\320\233\320\254\320\232\320\236 \320\243\320\223\320\233\320\253", 0));
        checkBox_4->setText(QApplication::translate("MainWindow", "\320\241\320\233\320\243\320\247 \320\227\320\220\320\237\320\236\320\233\320\235\320\225\320\235 \320\242\320\220\320\221\320\233\320\230\320\246\320\253", 0));
        doubleSpinBox_3->setPrefix(QApplication::translate("MainWindow", "D \320\276\321\202  ", 0));
        doubleSpinBox_3->setSuffix(QApplication::translate("MainWindow", "  \320\274", 0));
        doubleSpinBox_4->setPrefix(QApplication::translate("MainWindow", "D \320\264\320\276: ", 0));
        doubleSpinBox_4->setSuffix(QApplication::translate("MainWindow", "  \320\274", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\320\243\321\202\320\276\321\207\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\274\320\265\321\202\321\200\321\213 \320\277\321\200\320\270\320\261\320\276\321\200\320\260", 0));
        doubleSpinBox_5->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 \320\237\320\236\320\233\320\236\320\226\320\225\320\235\320\230\320\257 : ", 0));
        doubleSpinBox_5->setSuffix(QApplication::translate("MainWindow", "  \320\274", 0));
        doubleSpinBox_7->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 \320\232\320\243 : ", 0));
        doubleSpinBox_7->setSuffix(QApplication::translate("MainWindow", "  \320\274\321\200\320\260\320\264", 0));
        doubleSpinBox_8->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270 \320\232\320\243 : ", 0));
        doubleSpinBox_8->setSuffix(QApplication::translate("MainWindow", "  \320\274\321\200\320\260\320\264", 0));
        doubleSpinBox_9->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 \321\203\320\263\320\273\320\260 \320\232\320\232 : ", 0));
        doubleSpinBox_9->setSuffix(QApplication::translate("MainWindow", "  \320\274\321\200\320\260\320\264", 0));
        doubleSpinBox_10->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 \321\201\320\272\320\276\321\200 \321\203\320\263\320\273\320\260 \320\232\320\232 : ", 0));
        doubleSpinBox_10->setSuffix(QApplication::translate("MainWindow", "  \320\274\321\200\320\260\320\264", 0));
        doubleSpinBox_11->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 \321\203\320\263\320\273\320\260 \320\221\320\232 : ", 0));
        doubleSpinBox_11->setSuffix(QApplication::translate("MainWindow", "  \320\274\321\200\320\260\320\264", 0));
        doubleSpinBox_13->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 \321\201\320\272\320\276\321\200 \321\203\320\263\320\273\320\260 \320\221\320\232 : ", 0));
        doubleSpinBox_13->setSuffix(QApplication::translate("MainWindow", "  \320\274\321\200\320\260\320\264", 0));
        label_4->setText(QApplication::translate("MainWindow", "\320\237\320\220\320\240\320\220\320\234\320\225\320\242\320\240\320\253 \320\230\320\235\320\225\320\240\320\246\320\230\320\220\320\233\320\254\320\235\320\236\320\231 \320\241\320\230\320\241\320\242\320\225\320\234\320\253 \320\232\320\236\320\240\320\220\320\221\320\233\320\257_\320\235\320\236\320\241\320\230\320\242\320\225\320\233\320\257", 0));
        doubleSpinBox_12->setPrefix(QApplication::translate("MainWindow", "\320\227\320\260\320\264\320\265\321\200\320\266\320\272\320\260 \320\277\320\276 \320\262\321\200\320\265\320\274\320\265\320\275\320\270 \320\264\320\276 : ", 0));
        doubleSpinBox_12->setSuffix(QApplication::translate("MainWindow", "  \320\274\321\201", 0));
        doubleSpinBox_6->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 \320\237\320\236\320\227\320\230\320\246\320\230\320\236\320\235\320\230\320\240\320\236\320\222\320\220\320\235\320\230\320\257 \320\232\320\236 :  ", 0));
        doubleSpinBox_6->setSuffix(QApplication::translate("MainWindow", "  \320\274", 0));
        doubleSpinBox_14->setPrefix(QApplication::translate("MainWindow", "\320\241\320\232\320\236 \320\243\320\223\320\233\320\236\320\222\320\253\320\245 \320\230\320\227\320\234\320\225\320\240\320\225\320\235\320\230\320\231:  ", 0));
        doubleSpinBox_14->setSuffix(QApplication::translate("MainWindow", "  \320\274\321\200\320\260\320\264", 0));
        checkBox_5->setText(QApplication::translate("MainWindow", "\320\237\320\236 \320\237\320\236\320\233\320\257\320\240\320\235\320\236\320\231 \320\227\320\222\320\225\320\227\320\224\320\225", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
