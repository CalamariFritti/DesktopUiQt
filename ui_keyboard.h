/********************************************************************************
** Form generated from reading UI file 'keyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARD_H
#define UI_KEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Keyboard
{
public:
    QTextBrowser *number_browser;
    QPushButton *pushButton_ok;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_0;
    QPushButton *pushButton_point;
    QPushButton *pushButton_backSpace;
    QPushButton *pushButton_clear;
    QWidget *widget;

    void setupUi(QWidget *Keyboard)
    {
        if (Keyboard->objectName().isEmpty())
            Keyboard->setObjectName(QString::fromUtf8("Keyboard"));
        Keyboard->resize(800, 480);
        Keyboard->setStyleSheet(QString::fromUtf8(""));
        number_browser = new QTextBrowser(Keyboard);
        number_browser->setObjectName(QString::fromUtf8("number_browser"));
        number_browser->setGeometry(QRect(179, 59, 381, 51));
        QFont font;
        font.setPointSize(27);
        number_browser->setFont(font);
        pushButton_ok = new QPushButton(Keyboard);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));
        pushButton_ok->setGeometry(QRect(580, 380, 191, 80));
        QFont font1;
        font1.setPointSize(30);
        pushButton_ok->setFont(font1);
        label = new QLabel(Keyboard);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 10, 381, 41));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(20);
        label->setFont(font2);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(Keyboard);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(180, 120, 380, 340));
        layoutWidget->setFont(font1);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(0, 80));
        pushButton_7->setFont(font1);

        gridLayout->addWidget(pushButton_7, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(0, 80));
        pushButton_8->setFont(font1);

        gridLayout->addWidget(pushButton_8, 0, 1, 1, 1);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(0, 80));
        pushButton_9->setFont(font1);

        gridLayout->addWidget(pushButton_9, 0, 2, 1, 1);

        pushButton_minus = new QPushButton(layoutWidget);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        pushButton_minus->setMinimumSize(QSize(0, 80));
        pushButton_minus->setFont(font1);

        gridLayout->addWidget(pushButton_minus, 0, 3, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 80));
        pushButton_4->setFont(font1);

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 80));
        pushButton_5->setFont(font1);

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(0, 80));
        pushButton_6->setFont(font1);

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_plus = new QPushButton(layoutWidget);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        pushButton_plus->setMinimumSize(QSize(0, 80));
        pushButton_plus->setFont(font1);

        gridLayout->addWidget(pushButton_plus, 1, 3, 1, 1);

        pushButton_1 = new QPushButton(layoutWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(0, 80));
        pushButton_1->setFont(font1);

        gridLayout->addWidget(pushButton_1, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 80));
        pushButton_2->setFont(font1);

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 80));
        pushButton_3->setFont(font1);

        gridLayout->addWidget(pushButton_3, 2, 2, 1, 1);

        pushButton_0 = new QPushButton(layoutWidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setMinimumSize(QSize(0, 80));
        pushButton_0->setFont(font1);

        gridLayout->addWidget(pushButton_0, 3, 1, 1, 1);

        pushButton_point = new QPushButton(layoutWidget);
        pushButton_point->setObjectName(QString::fromUtf8("pushButton_point"));
        pushButton_point->setMinimumSize(QSize(0, 80));
        pushButton_point->setFont(font1);

        gridLayout->addWidget(pushButton_point, 3, 2, 1, 1);

        pushButton_backSpace = new QPushButton(layoutWidget);
        pushButton_backSpace->setObjectName(QString::fromUtf8("pushButton_backSpace"));
        pushButton_backSpace->setMinimumSize(QSize(0, 80));
        pushButton_backSpace->setFont(font1);

        gridLayout->addWidget(pushButton_backSpace, 3, 0, 1, 1);

        pushButton_clear = new QPushButton(layoutWidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setMinimumSize(QSize(0, 80));
        pushButton_clear->setFont(font1);

        gridLayout->addWidget(pushButton_clear, 3, 3, 1, 1);

        widget = new QWidget(Keyboard);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 801, 480));
        widget->setStyleSheet(QString::fromUtf8("background-color : rgba( 255, 255, 255, 20% );"));
        widget->raise();
        number_browser->raise();
        pushButton_ok->raise();
        label->raise();
        layoutWidget->raise();

        retranslateUi(Keyboard);

        QMetaObject::connectSlotsByName(Keyboard);
    } // setupUi

    void retranslateUi(QWidget *Keyboard)
    {
        Keyboard->setWindowTitle(QCoreApplication::translate("Keyboard", "Form", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("Keyboard", "OK", nullptr));
        label->setText(QCoreApplication::translate("Keyboard", "default_value", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Keyboard", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Keyboard", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Keyboard", "9", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("Keyboard", "-", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Keyboard", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Keyboard", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Keyboard", "6", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("Keyboard", "+", nullptr));
        pushButton_1->setText(QCoreApplication::translate("Keyboard", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Keyboard", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Keyboard", "3", nullptr));
        pushButton_0->setText(QCoreApplication::translate("Keyboard", "0", nullptr));
        pushButton_point->setText(QCoreApplication::translate("Keyboard", ",", nullptr));
        pushButton_backSpace->setText(QCoreApplication::translate("Keyboard", "<-", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("Keyboard", "Neu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Keyboard: public Ui_Keyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARD_H
