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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QDoubleSpinBox *doubleSpinBoxCourseAng;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxTemperature0;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBoxVVert;
    QFrame *frame;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QFrame *frame_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QDoubleSpinBox *doubleSpinBoxVHor;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_17;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(797, 517);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        MainWindow->setTabletTracking(true);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        doubleSpinBoxCourseAng = new QDoubleSpinBox(centralWidget);
        doubleSpinBoxCourseAng->setObjectName(QString::fromUtf8("doubleSpinBoxCourseAng"));
        doubleSpinBoxCourseAng->setGeometry(QRect(710, 132, 71, 22));
        doubleSpinBoxCourseAng->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBoxCourseAng->setMaximum(100000000.000000000000000);
        doubleSpinBoxCourseAng->setValue(0.000000000000000);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(710, 0, 61, 15));
        label_3->setFrameShape(QFrame::Box);
        label_3->setScaledContents(true);
        doubleSpinBoxTemperature0 = new QDoubleSpinBox(centralWidget);
        doubleSpinBoxTemperature0->setObjectName(QString::fromUtf8("doubleSpinBoxTemperature0"));
        doubleSpinBoxTemperature0->setGeometry(QRect(710, 190, 71, 23));
        doubleSpinBoxTemperature0->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBoxTemperature0->setMaximum(100000000.000000000000000);
        doubleSpinBoxTemperature0->setValue(18.000000000000000);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(710, 13, 71, 15));
        label_4->setFrameShape(QFrame::Box);
        label_4->setScaledContents(true);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(710, 73, 71, 15));
        label_6->setFrameShape(QFrame::Box);
        label_6->setScaledContents(true);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(710, 43, 71, 15));
        label_5->setFrameShape(QFrame::Box);
        label_5->setScaledContents(true);
        doubleSpinBoxVVert = new QDoubleSpinBox(centralWidget);
        doubleSpinBoxVVert->setObjectName(QString::fromUtf8("doubleSpinBoxVVert"));
        doubleSpinBoxVVert->setGeometry(QRect(710, 161, 71, 22));
        doubleSpinBoxVVert->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBoxVVert->setMaximum(100000000.000000000000000);
        doubleSpinBoxVVert->setValue(0.000000000000000);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 0, 681, 171));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(2);
        frame->setMidLineWidth(3);
        gridLayoutWidget = new QWidget(frame);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 58, 651, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 20, 131, 16));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(20, 240, 501, 121));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(3);
        frame_2->setMidLineWidth(1);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 10, 381, 31));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 60, 93, 41));
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 60, 331, 41));
        doubleSpinBoxVHor = new QDoubleSpinBox(centralWidget);
        doubleSpinBoxVHor->setObjectName(QString::fromUtf8("doubleSpinBoxVHor"));
        doubleSpinBoxVHor->setGeometry(QRect(710, 100, 71, 22));
        doubleSpinBoxVHor->setButtonSymbols(QAbstractSpinBox::NoButtons);
        doubleSpinBoxVHor->setMaximum(100000000.000000000000000);
        doubleSpinBoxVHor->setValue(0.000000000000000);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 380, 501, 51));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(670, 270, 75, 23));
        doubleSpinBox_3 = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(180, 190, 81, 31));
        doubleSpinBox_3->setDecimals(2);
        doubleSpinBox_3->setMinimum(0.000000000000000);
        doubleSpinBox_3->setMaximum(10000.000000000000000);
        doubleSpinBox_3->setValue(1000.000000000000000);
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(60, 200, 91, 22));
        label_17->setFrameShape(QFrame::Box);
        label_17->setScaledContents(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 797, 21));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "V \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202., \320\274/\321\201", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\220\320\267\320\270\320\274\321\203\321\202, \320\263\321\200\320\260\320\264.", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277., C", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "V_\320\262\320\265\321\200\321\202\320\270\320\272., \320\274/\321\201", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\220\320\242\320\234\320\236\320\241\320\244\320\225\320\240\320\220", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\277\321\203\321\202\321\214 \320\272 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\270 \321\201 \321\204\320\260\320\271\320\273\320\260\320\274\320\270 \320\263\321\200\320\260\321\204\320\270\320\272\320\276\320\262:", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "...", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\230\320\234\320\230\320\242\320\220\320\246\320\230\320\257 \320\240\320\220\320\221\320\236\320\242\320\253 \320\222\320\236 \320\222\320\235\320\225\320\250\320\235\320\225\320\231 \320\234\320\236\320\224\320\225\320\233\320\230", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273 \320\262\321\200\320\265\320\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
