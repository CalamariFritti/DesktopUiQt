/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label_7;
    QPushButton *saveAndExit_pushButton;
    QLabel *label;
    QCheckBox *checkBox_0;
    QLabel *label_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_2;
    QLabel *label_5;
    QCheckBox *checkBox_1;
    QLabel *label_2;
    QCheckBox *checkBox_5;
    QLabel *label_4;
    QCheckBox *checkBox_3;
    QLabel *label_6;
    QLabel *label_8;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(800, 480);
        Dialog->setStyleSheet(QString::fromUtf8("background-image : url(~/viveApp_2/DesktopUiQt/img/2019-11-13_01-Favicon_VIVE-MedTech.png);"));
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(90, 30, 601, 41));
        label_7->setScaledContents(false);
        label_7->setAlignment(Qt::AlignCenter);
        saveAndExit_pushButton = new QPushButton(Dialog);
        saveAndExit_pushButton->setObjectName(QString::fromUtf8("saveAndExit_pushButton"));
        saveAndExit_pushButton->setGeometry(QRect(650, 410, 111, 50));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 90, 150, 50));
        label->setAlignment(Qt::AlignCenter);
        checkBox_0 = new QCheckBox(Dialog);
        checkBox_0->setObjectName(QString::fromUtf8("checkBox_0"));
        checkBox_0->setGeometry(QRect(300, 90, 180, 50));
        checkBox_0->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"     width: 32px;\n"
"     height: 32px;\n"
"}"));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 300, 150, 50));
        label_3->setAlignment(Qt::AlignCenter);
        checkBox_4 = new QCheckBox(Dialog);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(300, 300, 180, 50));
        checkBox_4->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"     width: 32px;\n"
"     height: 32px;\n"
"}"));
        checkBox_2 = new QCheckBox(Dialog);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(300, 200, 180, 50));
        checkBox_2->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"     width: 32px;\n"
"     height: 32px;\n"
"}"));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 200, 150, 50));
        label_5->setAlignment(Qt::AlignCenter);
        checkBox_1 = new QCheckBox(Dialog);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setGeometry(QRect(300, 150, 180, 50));
        checkBox_1->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"     width: 32px;\n"
"     height: 32px;\n"
"}"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 150, 150, 50));
        label_2->setAlignment(Qt::AlignCenter);
        checkBox_5 = new QCheckBox(Dialog);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(300, 360, 180, 50));
        checkBox_5->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"     width: 32px;\n"
"     height: 32px;\n"
"}"));
        checkBox_5->setIconSize(QSize(16, 16));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 360, 150, 50));
        label_4->setAlignment(Qt::AlignCenter);
        checkBox_3 = new QCheckBox(Dialog);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(300, 250, 180, 50));
        checkBox_3->setStyleSheet(QString::fromUtf8("QCheckBox::indicator {\n"
"     width: 32px;\n"
"     height: 32px;\n"
"}"));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 250, 150, 50));
        label_6->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(Dialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(660, 10, 131, 121));
        label_8->setScaledContents(false);
        label_8->raise();
        label_7->raise();
        saveAndExit_pushButton->raise();
        label->raise();
        checkBox_0->raise();
        label_3->raise();
        checkBox_4->raise();
        checkBox_2->raise();
        label_5->raise();
        checkBox_1->raise();
        label_2->raise();
        checkBox_5->raise();
        label_4->raise();
        checkBox_3->raise();
        label_6->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog", "BItte aktivieren Sie alle Sensoren, die f\303\274r die Messung ben\303\266tigt werden:", nullptr));
        saveAndExit_pushButton->setText(QCoreApplication::translate("Dialog", "Speichern und\n"
" Verlassen", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Sauerstoff-Sensor 01", nullptr));
        checkBox_0->setText(QCoreApplication::translate("Dialog", "O2-Sensor 01 inaktiv ", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "CO2-Sensor 01", nullptr));
        checkBox_4->setText(QCoreApplication::translate("Dialog", "CO2-Sensor 01 inaktiv ", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Dialog", "pH-Sensor 01 inaktiv ", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "pH-Sensor 01", nullptr));
        checkBox_1->setText(QCoreApplication::translate("Dialog", "O2-Sensor 02 inaktiv ", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Sauerstoff-Sensor 02", nullptr));
        checkBox_5->setText(QCoreApplication::translate("Dialog", "CO2-Sensor 02 inaktiv ", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "CO2-Sensor 02", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Dialog", "pH-Sensor 02 inaktiv ", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog", "pH-Sensor 02", nullptr));
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
