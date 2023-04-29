/********************************************************************************
** Form generated from reading UI file 'form1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM1_H
#define UI_FORM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form1
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *Form1)
    {
        if (Form1->objectName().isEmpty())
            Form1->setObjectName(QString::fromUtf8("Form1"));
        Form1->resize(400, 300);
        pushButton = new QPushButton(Form1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 260, 75, 23));

        retranslateUi(Form1);

        QMetaObject::connectSlotsByName(Form1);
    } // setupUi

    void retranslateUi(QWidget *Form1)
    {
        Form1->setWindowTitle(QApplication::translate("Form1", "Form", nullptr));
        pushButton->setText(QApplication::translate("Form1", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form1: public Ui_Form1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM1_H
