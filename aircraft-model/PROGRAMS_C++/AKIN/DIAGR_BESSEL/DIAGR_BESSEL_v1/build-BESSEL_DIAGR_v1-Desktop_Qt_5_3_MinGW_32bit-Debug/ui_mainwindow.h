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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox;
    QComboBox *comboBox;
    QFrame *frame_2;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QDoubleSpinBox *doubleSpinBox_10;
    QPushButton *pushButton_3;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_7;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(798, 467);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 50, 221, 241));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        doubleSpinBox_3 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setEnabled(true);
        doubleSpinBox_3->setContextMenuPolicy(Qt::CustomContextMenu);
        doubleSpinBox_3->setToolTipDuration(3);
        doubleSpinBox_3->setDecimals(0);

        gridLayout->addWidget(doubleSpinBox_3, 4, 0, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setToolTipDuration(-14);

        gridLayout->addWidget(doubleSpinBox_4, 3, 0, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setEnabled(true);
        doubleSpinBox_2->setContextMenuPolicy(Qt::CustomContextMenu);
        doubleSpinBox_2->setToolTipDuration(3);

        gridLayout->addWidget(doubleSpinBox_2, 2, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setToolTipDuration(-14);

        gridLayout->addWidget(doubleSpinBox, 1, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 350, 571, 51));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(1);
        frame_2->setMidLineWidth(1);
        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(520, 10, 41, 31));
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(70, 10, 441, 31));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 61, 31));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(620, 280, 77, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(240, 20, 221, 301));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        doubleSpinBox_6 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setEnabled(true);
        doubleSpinBox_6->setContextMenuPolicy(Qt::CustomContextMenu);
        doubleSpinBox_6->setToolTipDuration(3);

        gridLayout_2->addWidget(doubleSpinBox_6, 1, 0, 1, 1);

        doubleSpinBox_8 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setEnabled(true);
        doubleSpinBox_8->setContextMenuPolicy(Qt::CustomContextMenu);
        doubleSpinBox_8->setToolTipDuration(3);

        gridLayout_2->addWidget(doubleSpinBox_8, 3, 0, 1, 1);

        doubleSpinBox_9 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        doubleSpinBox_9->setEnabled(true);
        doubleSpinBox_9->setContextMenuPolicy(Qt::CustomContextMenu);
        doubleSpinBox_9->setToolTipDuration(3);

        gridLayout_2->addWidget(doubleSpinBox_9, 8, 0, 1, 1);

        doubleSpinBox_10 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));
        doubleSpinBox_10->setEnabled(true);
        doubleSpinBox_10->setContextMenuPolicy(Qt::CustomContextMenu);
        doubleSpinBox_10->setToolTipDuration(3);
        doubleSpinBox_10->setMinimum(-180);
        doubleSpinBox_10->setMaximum(180);

        gridLayout_2->addWidget(doubleSpinBox_10, 7, 0, 1, 1);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 5, 0, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setEnabled(true);
        doubleSpinBox_5->setContextMenuPolicy(Qt::CustomContextMenu);
        doubleSpinBox_5->setToolTipDuration(3);

        gridLayout_2->addWidget(doubleSpinBox_5, 0, 0, 1, 1);

        doubleSpinBox_7 = new QDoubleSpinBox(groupBox_2);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setEnabled(true);
        doubleSpinBox_7->setContextMenuPolicy(Qt::CustomContextMenu);
        doubleSpinBox_7->setToolTipDuration(3);

        gridLayout_2->addWidget(doubleSpinBox_7, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 798, 21));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\230\320\241\320\245\320\236\320\224\320\235\320\253\320\225 \320\224\320\220\320\235\320\235\320\253\320\225 \320\220\320\235\320\242\320\225\320\235\320\235\320\253", 0));
        doubleSpinBox_3->setPrefix(QApplication::translate("MainWindow", "\320\232-\320\262\320\276 \320\270\320\267\320\273\321\203\321\207: ", 0));
        doubleSpinBox_3->setSuffix(QString());
        doubleSpinBox_4->setPrefix(QApplication::translate("MainWindow", "\320\240\320\260\320\264. \320\260\320\275\321\202\320\265\320\275\320\275\321\213 ", 0));
        doubleSpinBox_4->setSuffix(QApplication::translate("MainWindow", " \321\201\320\274", 0));
        doubleSpinBox_2->setPrefix(QApplication::translate("MainWindow", "\320\224\320\270\320\260\320\274 \320\270\320\267\320\273 ", 0));
        doubleSpinBox_2->setSuffix(QApplication::translate("MainWindow", " c\320\274", 0));
        doubleSpinBox->setPrefix(QApplication::translate("MainWindow", "\320\224\320\273. \320\262\320\276\320\273\320\275\321\213  ", 0));
        doubleSpinBox->setSuffix(QApplication::translate("MainWindow", " \321\201\320\274", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\232\320\276\320\273\321\214\321\206\320\265\320\262\320\260\321\217", 0)
         << QApplication::translate("MainWindow", "\320\234\320\260\321\202\321\200\320\270\321\207\320\275\320\260\321\217", 0)
        );
        pushButton_4->setText(QApplication::translate("MainWindow", "...", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272\320\270:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "receiver diagr", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "PushButton", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\220\320\234\320\237\320\233\320\230\320\242 \320\240\320\220\320\227\320\235\320\236\320\241\320\242\320\235\320\253\320\231 \320\234\320\225\320\242\320\236\320\224", 0));
        doubleSpinBox_6->setPrefix(QApplication::translate("MainWindow", "\321\202\320\265\321\202 \321\201\320\272\320\260\320\275: ", 0));
        doubleSpinBox_6->setSuffix(QApplication::translate("MainWindow", " \320\263\321\200\320\260\320\264", 0));
        doubleSpinBox_8->setPrefix(QApplication::translate("MainWindow", "q \321\206\320\265\320\273\320\270: ", 0));
        doubleSpinBox_8->setSuffix(QApplication::translate("MainWindow", " \320\263\321\200\320\260\320\264", 0));
        doubleSpinBox_9->setPrefix(QApplication::translate("MainWindow", "tet \320\270\320\267\320\274: ", 0));
        doubleSpinBox_9->setSuffix(QApplication::translate("MainWindow", " \320\263\321\200\320\260\320\264", 0));
        doubleSpinBox_10->setPrefix(QApplication::translate("MainWindow", "q \320\270\320\267\320\274: ", 0));
        doubleSpinBox_10->setSuffix(QApplication::translate("MainWindow", " \320\263\321\200\320\260\320\264", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "ant diagr", 0));
        doubleSpinBox_5->setPrefix(QApplication::translate("MainWindow", "q \321\201\320\272\320\260\320\275: ", 0));
        doubleSpinBox_5->setSuffix(QApplication::translate("MainWindow", " \320\263\321\200\320\260\320\264", 0));
        doubleSpinBox_7->setPrefix(QApplication::translate("MainWindow", "\321\202\320\265\321\202 \321\206\320\265\320\273\320\270: ", 0));
        doubleSpinBox_7->setSuffix(QApplication::translate("MainWindow", " \320\263\321\200\320\260\320\264", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
