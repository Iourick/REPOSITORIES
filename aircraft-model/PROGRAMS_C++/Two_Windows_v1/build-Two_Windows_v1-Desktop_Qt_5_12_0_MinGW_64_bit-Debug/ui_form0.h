/********************************************************************************
** Form generated from reading UI file 'form0.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM0_H
#define UI_FORM0_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form0
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *RUN_3;

    void setupUi(QWidget *Form0)
    {
        if (Form0->objectName().isEmpty())
            Form0->setObjectName(QString::fromUtf8("Form0"));
        Form0->resize(400, 300);
        pushButton = new QPushButton(Form0);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 90, 75, 23));
        pushButton_2 = new QPushButton(Form0);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 160, 75, 23));
        RUN_3 = new QPushButton(Form0);
        RUN_3->setObjectName(QString::fromUtf8("RUN_3"));
        RUN_3->setGeometry(QRect(180, 220, 75, 23));

        retranslateUi(Form0);

        QMetaObject::connectSlotsByName(Form0);
    } // setupUi

    void retranslateUi(QWidget *Form0)
    {
        Form0->setWindowTitle(QApplication::translate("Form0", "Form", nullptr));
        pushButton->setText(QApplication::translate("Form0", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("Form0", "RUN", nullptr));
        RUN_3->setText(QApplication::translate("Form0", "RUN_3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form0: public Ui_Form0 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM0_H
