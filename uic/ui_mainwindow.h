/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtCharts"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *general;
    QPushButton *stopMeassurementButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pCO2DisplayButton;
    QPushButton *pO2DisplayButton;
    QPushButton *pHDisplayButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pHDisplayButton_2;
    QPushButton *pCO2DisplayButton_2;
    QPushButton *pO2DisplayButton_2;
    QLabel *label_23;
    QPushButton *memoryValueButton;
    QWidget *start;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QPushButton *initialize_sensor_1_button;
    QLabel *sensor_1_init_label;
    QLabel *sensor_3_init_label;
    QPushButton *initialize_sensor_4_button;
    QPushButton *initialize_sensor_3_button;
    QPushButton *initialize_sensor_5_button;
    QLabel *sensor_2_init_label;
    QLabel *sensor_4_init_label;
    QPushButton *initialize_sensor_2_button;
    QLabel *sensor_5_init_label;
    QLabel *sensor_6_init_label;
    QPushButton *initialize_sensor_0_button;
    QPushButton *quitButtonStartMain;
    QPushButton *start_measurement_button;
    QWidget *tab_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *lmax_calibration_6;
    QPushButton *set_f1_button;
    QTextBrowser *f1_textbrowser;
    QLabel *label_8;
    QWidget *lmax_calibration;
    QPushButton *set_m_button;
    QTextBrowser *m_textbrowser;
    QLabel *label_3;
    QWidget *lmax_calibration_2;
    QPushButton *set_dPhi1_button;
    QTextBrowser *dPhi1_textbrowser;
    QLabel *label_5;
    QWidget *lmax_calibration_3;
    QPushButton *set_dPhi2_button;
    QTextBrowser *dPhi2_textbrowser;
    QLabel *label_6;
    QWidget *lmax_calibration_4;
    QPushButton *set_dKSV1_button;
    QTextBrowser *dKSV1_textbrowser;
    QLabel *label_7;
    QWidget *lmax_calibration_7;
    QPushButton *set_dKSV2_button;
    QTextBrowser *dKSV2_textbrowser;
    QLabel *label_9;
    QPushButton *allSet_o2;
    QPushButton *quitButtonStartMain_2;
    QWidget *tab_3;
    QPushButton *allSet_cO2;
    QPushButton *quitButtonStartMain_4;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *lmax_calibration_12;
    QPushButton *set_A1_button;
    QTextBrowser *A1_textbrowser;
    QLabel *label_18;
    QWidget *lmax_calibration_13;
    QPushButton *set_A2_button;
    QTextBrowser *A2_textbrowser;
    QLabel *label_19;
    QWidget *lmax_calibration_14;
    QPushButton *set_x0_button;
    QTextBrowser *x0_textbrowser;
    QLabel *label_20;
    QWidget *lmax_calibration_15;
    QPushButton *set_dx_button;
    QTextBrowser *dx_textbrowser;
    QLabel *label_21;
    QWidget *lmax_calibration_16;
    QPushButton *set_temp_co2_button;
    QTextBrowser *temp_co2_textbrowser;
    QLabel *label_22;
    QWidget *tab_4;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *lmax_calibration_8;
    QPushButton *set_lmin_button;
    QTextBrowser *lmin_textbrowser;
    QLabel *label_13;
    QWidget *lmax_calibration_5;
    QPushButton *set_lmax_button;
    QTextBrowser *lmax_textbrowser;
    QLabel *label_14;
    QWidget *lmax_calibration_9;
    QPushButton *set_pH0_button;
    QTextBrowser *pH0_textbrowser;
    QLabel *label_15;
    QWidget *lmax_calibration_10;
    QPushButton *set_dpH_button;
    QTextBrowser *dpH_textbrowser;
    QLabel *label_16;
    QWidget *lmax_calibration_11;
    QPushButton *set_temp_button;
    QTextBrowser *temp_textbrowser;
    QLabel *label_17;
    QPushButton *allSet_pH;
    QPushButton *quitButtonStartMain_3;
    QWidget *tab_5;
    QTextBrowser *textBrowser;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit;
    QWidget *o2;
    QPushButton *plotButtonSensor_1;
    QPushButton *clearButtonSensor_1;
    QPushButton *mainMenuButtonSensor_1;
    QPushButton *quitButtonSensor_1;
    QChartView *lineGraph_o2;
    QWidget *CO2;
    QPushButton *clearButtonSensor_2;
    QPushButton *plotButtonSensor_2;
    QPushButton *mainMenuButtonSensor_2;
    QPushButton *quitButtonSensor_2;
    QComboBox *comboBox;
    QChartView *lineGraph_co2;
    QWidget *pH;
    QPushButton *plotButtonSensor_3;
    QPushButton *quitButtonSensor_3;
    QPushButton *mainMenuButtonSensor_3;
    QPushButton *clearButtonSensor_3;
    QSpinBox *spinBoxStaticValues_sensor_3;
    QPushButton *showStaticValues_sensor_3;
    QChartView *lineGraph_ph;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 800);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 747));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab { height: 148\n"
"px; width: 120px; font-size: 12pt; };"));
        tabWidget->setTabPosition(QTabWidget::West);
        general = new QWidget();
        general->setObjectName(QString::fromUtf8("general"));
        general->setMinimumSize(QSize(0, 0));
        general->setStyleSheet(QString::fromUtf8(""));
        stopMeassurementButton = new QPushButton(general);
        stopMeassurementButton->setObjectName(QString::fromUtf8("stopMeassurementButton"));
        stopMeassurementButton->setGeometry(QRect(10, 660, 671, 51));
        horizontalLayoutWidget = new QWidget(general);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 100, 1131, 191));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pCO2DisplayButton = new QPushButton(horizontalLayoutWidget);
        pCO2DisplayButton->setObjectName(QString::fromUtf8("pCO2DisplayButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pCO2DisplayButton->sizePolicy().hasHeightForWidth());
        pCO2DisplayButton->setSizePolicy(sizePolicy);
        pCO2DisplayButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(pCO2DisplayButton);

        pO2DisplayButton = new QPushButton(horizontalLayoutWidget);
        pO2DisplayButton->setObjectName(QString::fromUtf8("pO2DisplayButton"));
        sizePolicy.setHeightForWidth(pO2DisplayButton->sizePolicy().hasHeightForWidth());
        pO2DisplayButton->setSizePolicy(sizePolicy);
        pO2DisplayButton->setStyleSheet(QString::fromUtf8(".QWidget {\n"
"background-color : transparent\n"
" }"));

        horizontalLayout->addWidget(pO2DisplayButton);

        pHDisplayButton = new QPushButton(horizontalLayoutWidget);
        pHDisplayButton->setObjectName(QString::fromUtf8("pHDisplayButton"));
        sizePolicy.setHeightForWidth(pHDisplayButton->sizePolicy().hasHeightForWidth());
        pHDisplayButton->setSizePolicy(sizePolicy);
        pHDisplayButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(pHDisplayButton);

        horizontalLayoutWidget_2 = new QWidget(general);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 20, 1131, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_4);

        horizontalLayoutWidget_3 = new QWidget(general);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 310, 1131, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(horizontalLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_10);

        label_11 = new QLabel(horizontalLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_11);

        label_12 = new QLabel(horizontalLayoutWidget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_12);

        horizontalLayoutWidget_4 = new QWidget(general);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(0, 390, 1131, 181));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pHDisplayButton_2 = new QPushButton(horizontalLayoutWidget_4);
        pHDisplayButton_2->setObjectName(QString::fromUtf8("pHDisplayButton_2"));
        sizePolicy.setHeightForWidth(pHDisplayButton_2->sizePolicy().hasHeightForWidth());
        pHDisplayButton_2->setSizePolicy(sizePolicy);
        pHDisplayButton_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(pHDisplayButton_2);

        pCO2DisplayButton_2 = new QPushButton(horizontalLayoutWidget_4);
        pCO2DisplayButton_2->setObjectName(QString::fromUtf8("pCO2DisplayButton_2"));
        sizePolicy.setHeightForWidth(pCO2DisplayButton_2->sizePolicy().hasHeightForWidth());
        pCO2DisplayButton_2->setSizePolicy(sizePolicy);
        pCO2DisplayButton_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(pCO2DisplayButton_2);

        pO2DisplayButton_2 = new QPushButton(horizontalLayoutWidget_4);
        pO2DisplayButton_2->setObjectName(QString::fromUtf8("pO2DisplayButton_2"));
        sizePolicy.setHeightForWidth(pO2DisplayButton_2->sizePolicy().hasHeightForWidth());
        pO2DisplayButton_2->setSizePolicy(sizePolicy);
        pO2DisplayButton_2->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(pO2DisplayButton_2);

        label_23 = new QLabel(general);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(890, 600, 201, 41));
        memoryValueButton = new QPushButton(general);
        memoryValueButton->setObjectName(QString::fromUtf8("memoryValueButton"));
        memoryValueButton->setGeometry(QRect(880, 640, 231, 81));
        QFont font;
        font.setPointSize(25);
        memoryValueButton->setFont(font);
        tabWidget->addTab(general, QString());
        start = new QWidget();
        start->setObjectName(QString::fromUtf8("start"));
        tabWidget_2 = new QTabWidget(start);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 681, 461));
        tabWidget_2->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        initialize_sensor_1_button = new QPushButton(tab);
        initialize_sensor_1_button->setObjectName(QString::fromUtf8("initialize_sensor_1_button"));
        initialize_sensor_1_button->setGeometry(QRect(253, 66, 220, 55));
        sensor_1_init_label = new QLabel(tab);
        sensor_1_init_label->setObjectName(QString::fromUtf8("sensor_1_init_label"));
        sensor_1_init_label->setGeometry(QRect(43, 0, 171, 60));
        sensor_1_init_label->setStyleSheet(QString::fromUtf8("background-color : red;\n"
"font-size: 30;"));
        sensor_1_init_label->setAlignment(Qt::AlignCenter);
        sensor_3_init_label = new QLabel(tab);
        sensor_3_init_label->setObjectName(QString::fromUtf8("sensor_3_init_label"));
        sensor_3_init_label->setGeometry(QRect(43, 130, 171, 55));
        sensor_3_init_label->setStyleSheet(QString::fromUtf8("background-color : red;\n"
"font-size: 30;"));
        sensor_3_init_label->setAlignment(Qt::AlignCenter);
        initialize_sensor_4_button = new QPushButton(tab);
        initialize_sensor_4_button->setObjectName(QString::fromUtf8("initialize_sensor_4_button"));
        initialize_sensor_4_button->setGeometry(QRect(253, 250, 220, 55));
        initialize_sensor_3_button = new QPushButton(tab);
        initialize_sensor_3_button->setObjectName(QString::fromUtf8("initialize_sensor_3_button"));
        initialize_sensor_3_button->setGeometry(QRect(253, 190, 220, 55));
        initialize_sensor_5_button = new QPushButton(tab);
        initialize_sensor_5_button->setObjectName(QString::fromUtf8("initialize_sensor_5_button"));
        initialize_sensor_5_button->setGeometry(QRect(253, 310, 220, 55));
        sensor_2_init_label = new QLabel(tab);
        sensor_2_init_label->setObjectName(QString::fromUtf8("sensor_2_init_label"));
        sensor_2_init_label->setGeometry(QRect(43, 66, 171, 55));
        sensor_2_init_label->setStyleSheet(QString::fromUtf8("background-color : red;\n"
"font-size: 30;"));
        sensor_2_init_label->setAlignment(Qt::AlignCenter);
        sensor_4_init_label = new QLabel(tab);
        sensor_4_init_label->setObjectName(QString::fromUtf8("sensor_4_init_label"));
        sensor_4_init_label->setGeometry(QRect(43, 190, 171, 55));
        sensor_4_init_label->setStyleSheet(QString::fromUtf8("background-color : red;\n"
"font-size: 30;"));
        sensor_4_init_label->setAlignment(Qt::AlignCenter);
        initialize_sensor_2_button = new QPushButton(tab);
        initialize_sensor_2_button->setObjectName(QString::fromUtf8("initialize_sensor_2_button"));
        initialize_sensor_2_button->setGeometry(QRect(253, 130, 220, 55));
        sensor_5_init_label = new QLabel(tab);
        sensor_5_init_label->setObjectName(QString::fromUtf8("sensor_5_init_label"));
        sensor_5_init_label->setGeometry(QRect(43, 250, 171, 55));
        sensor_5_init_label->setStyleSheet(QString::fromUtf8("background-color : red;\n"
"font-size: 30;"));
        sensor_5_init_label->setAlignment(Qt::AlignCenter);
        sensor_6_init_label = new QLabel(tab);
        sensor_6_init_label->setObjectName(QString::fromUtf8("sensor_6_init_label"));
        sensor_6_init_label->setGeometry(QRect(43, 312, 171, 55));
        sensor_6_init_label->setStyleSheet(QString::fromUtf8("background-color : red;\n"
"font-size: 30;"));
        sensor_6_init_label->setAlignment(Qt::AlignCenter);
        initialize_sensor_0_button = new QPushButton(tab);
        initialize_sensor_0_button->setObjectName(QString::fromUtf8("initialize_sensor_0_button"));
        initialize_sensor_0_button->setGeometry(QRect(253, 0, 220, 60));
        quitButtonStartMain = new QPushButton(tab);
        quitButtonStartMain->setObjectName(QString::fromUtf8("quitButtonStartMain"));
        quitButtonStartMain->setGeometry(QRect(560, 330, 90, 30));
        start_measurement_button = new QPushButton(tab);
        start_measurement_button->setObjectName(QString::fromUtf8("start_measurement_button"));
        start_measurement_button->setGeometry(QRect(540, 20, 131, 71));
        tabWidget_2->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        widget = new QWidget(tab_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 541, 371));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lmax_calibration_6 = new QWidget(widget);
        lmax_calibration_6->setObjectName(QString::fromUtf8("lmax_calibration_6"));
        set_f1_button = new QPushButton(lmax_calibration_6);
        set_f1_button->setObjectName(QString::fromUtf8("set_f1_button"));
        set_f1_button->setGeometry(QRect(0, 0, 300, 50));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(set_f1_button->sizePolicy().hasHeightForWidth());
        set_f1_button->setSizePolicy(sizePolicy1);
        f1_textbrowser = new QTextBrowser(lmax_calibration_6);
        f1_textbrowser->setObjectName(QString::fromUtf8("f1_textbrowser"));
        f1_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_8 = new QLabel(lmax_calibration_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(509, 9, 16, 19));
        QFont font1;
        font1.setPointSize(12);
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lmax_calibration_6);

        lmax_calibration = new QWidget(widget);
        lmax_calibration->setObjectName(QString::fromUtf8("lmax_calibration"));
        set_m_button = new QPushButton(lmax_calibration);
        set_m_button->setObjectName(QString::fromUtf8("set_m_button"));
        set_m_button->setGeometry(QRect(0, 0, 300, 50));
        sizePolicy1.setHeightForWidth(set_m_button->sizePolicy().hasHeightForWidth());
        set_m_button->setSizePolicy(sizePolicy1);
        set_m_button->setSizeIncrement(QSize(0, 0));
        set_m_button->setBaseSize(QSize(0, 0));
        set_m_button->setLayoutDirection(Qt::LeftToRight);
        m_textbrowser = new QTextBrowser(lmax_calibration);
        m_textbrowser->setObjectName(QString::fromUtf8("m_textbrowser"));
        m_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_3 = new QLabel(lmax_calibration);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(509, 9, 16, 19));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lmax_calibration);

        lmax_calibration_2 = new QWidget(widget);
        lmax_calibration_2->setObjectName(QString::fromUtf8("lmax_calibration_2"));
        set_dPhi1_button = new QPushButton(lmax_calibration_2);
        set_dPhi1_button->setObjectName(QString::fromUtf8("set_dPhi1_button"));
        set_dPhi1_button->setGeometry(QRect(0, 0, 300, 50));
        sizePolicy1.setHeightForWidth(set_dPhi1_button->sizePolicy().hasHeightForWidth());
        set_dPhi1_button->setSizePolicy(sizePolicy1);
        set_dPhi1_button->setSizeIncrement(QSize(0, 0));
        set_dPhi1_button->setBaseSize(QSize(0, 0));
        set_dPhi1_button->setLayoutDirection(Qt::LeftToRight);
        dPhi1_textbrowser = new QTextBrowser(lmax_calibration_2);
        dPhi1_textbrowser->setObjectName(QString::fromUtf8("dPhi1_textbrowser"));
        dPhi1_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_5 = new QLabel(lmax_calibration_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(509, 9, 16, 19));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lmax_calibration_2);

        lmax_calibration_3 = new QWidget(widget);
        lmax_calibration_3->setObjectName(QString::fromUtf8("lmax_calibration_3"));
        set_dPhi2_button = new QPushButton(lmax_calibration_3);
        set_dPhi2_button->setObjectName(QString::fromUtf8("set_dPhi2_button"));
        set_dPhi2_button->setGeometry(QRect(0, 0, 300, 50));
        sizePolicy1.setHeightForWidth(set_dPhi2_button->sizePolicy().hasHeightForWidth());
        set_dPhi2_button->setSizePolicy(sizePolicy1);
        set_dPhi2_button->setSizeIncrement(QSize(0, 0));
        set_dPhi2_button->setBaseSize(QSize(0, 0));
        set_dPhi2_button->setLayoutDirection(Qt::LeftToRight);
        dPhi2_textbrowser = new QTextBrowser(lmax_calibration_3);
        dPhi2_textbrowser->setObjectName(QString::fromUtf8("dPhi2_textbrowser"));
        dPhi2_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_6 = new QLabel(lmax_calibration_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(509, 9, 16, 19));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lmax_calibration_3);

        lmax_calibration_4 = new QWidget(widget);
        lmax_calibration_4->setObjectName(QString::fromUtf8("lmax_calibration_4"));
        set_dKSV1_button = new QPushButton(lmax_calibration_4);
        set_dKSV1_button->setObjectName(QString::fromUtf8("set_dKSV1_button"));
        set_dKSV1_button->setGeometry(QRect(0, 0, 300, 50));
        sizePolicy1.setHeightForWidth(set_dKSV1_button->sizePolicy().hasHeightForWidth());
        set_dKSV1_button->setSizePolicy(sizePolicy1);
        set_dKSV1_button->setSizeIncrement(QSize(0, 0));
        set_dKSV1_button->setBaseSize(QSize(0, 0));
        set_dKSV1_button->setLayoutDirection(Qt::LeftToRight);
        dKSV1_textbrowser = new QTextBrowser(lmax_calibration_4);
        dKSV1_textbrowser->setObjectName(QString::fromUtf8("dKSV1_textbrowser"));
        dKSV1_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_7 = new QLabel(lmax_calibration_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(509, 9, 16, 19));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lmax_calibration_4);

        lmax_calibration_7 = new QWidget(widget);
        lmax_calibration_7->setObjectName(QString::fromUtf8("lmax_calibration_7"));
        set_dKSV2_button = new QPushButton(lmax_calibration_7);
        set_dKSV2_button->setObjectName(QString::fromUtf8("set_dKSV2_button"));
        set_dKSV2_button->setGeometry(QRect(0, 0, 300, 50));
        sizePolicy1.setHeightForWidth(set_dKSV2_button->sizePolicy().hasHeightForWidth());
        set_dKSV2_button->setSizePolicy(sizePolicy1);
        set_dKSV2_button->setSizeIncrement(QSize(0, 0));
        set_dKSV2_button->setBaseSize(QSize(0, 0));
        set_dKSV2_button->setLayoutDirection(Qt::LeftToRight);
        dKSV2_textbrowser = new QTextBrowser(lmax_calibration_7);
        dKSV2_textbrowser->setObjectName(QString::fromUtf8("dKSV2_textbrowser"));
        dKSV2_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_9 = new QLabel(lmax_calibration_7);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(509, 9, 16, 19));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lmax_calibration_7);

        allSet_o2 = new QPushButton(tab_2);
        allSet_o2->setObjectName(QString::fromUtf8("allSet_o2"));
        allSet_o2->setGeometry(QRect(580, 10, 90, 61));
        quitButtonStartMain_2 = new QPushButton(tab_2);
        quitButtonStartMain_2->setObjectName(QString::fromUtf8("quitButtonStartMain_2"));
        quitButtonStartMain_2->setGeometry(QRect(580, 330, 90, 30));
        tabWidget_2->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        allSet_cO2 = new QPushButton(tab_3);
        allSet_cO2->setObjectName(QString::fromUtf8("allSet_cO2"));
        allSet_cO2->setGeometry(QRect(580, 10, 90, 61));
        quitButtonStartMain_4 = new QPushButton(tab_3);
        quitButtonStartMain_4->setObjectName(QString::fromUtf8("quitButtonStartMain_4"));
        quitButtonStartMain_4->setGeometry(QRect(580, 330, 90, 30));
        widget_3 = new QWidget(tab_3);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 0, 541, 371));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lmax_calibration_12 = new QWidget(widget_3);
        lmax_calibration_12->setObjectName(QString::fromUtf8("lmax_calibration_12"));
        set_A1_button = new QPushButton(lmax_calibration_12);
        set_A1_button->setObjectName(QString::fromUtf8("set_A1_button"));
        set_A1_button->setGeometry(QRect(0, 0, 300, 50));
        sizePolicy1.setHeightForWidth(set_A1_button->sizePolicy().hasHeightForWidth());
        set_A1_button->setSizePolicy(sizePolicy1);
        A1_textbrowser = new QTextBrowser(lmax_calibration_12);
        A1_textbrowser->setObjectName(QString::fromUtf8("A1_textbrowser"));
        A1_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_18 = new QLabel(lmax_calibration_12);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(509, 9, 16, 19));
        label_18->setFont(font1);
        label_18->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lmax_calibration_12);

        lmax_calibration_13 = new QWidget(widget_3);
        lmax_calibration_13->setObjectName(QString::fromUtf8("lmax_calibration_13"));
        set_A2_button = new QPushButton(lmax_calibration_13);
        set_A2_button->setObjectName(QString::fromUtf8("set_A2_button"));
        set_A2_button->setEnabled(true);
        set_A2_button->setGeometry(QRect(0, 0, 300, 50));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(set_A2_button->sizePolicy().hasHeightForWidth());
        set_A2_button->setSizePolicy(sizePolicy2);
        A2_textbrowser = new QTextBrowser(lmax_calibration_13);
        A2_textbrowser->setObjectName(QString::fromUtf8("A2_textbrowser"));
        A2_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_19 = new QLabel(lmax_calibration_13);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(509, 9, 16, 19));
        label_19->setFont(font1);
        label_19->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lmax_calibration_13);

        lmax_calibration_14 = new QWidget(widget_3);
        lmax_calibration_14->setObjectName(QString::fromUtf8("lmax_calibration_14"));
        set_x0_button = new QPushButton(lmax_calibration_14);
        set_x0_button->setObjectName(QString::fromUtf8("set_x0_button"));
        set_x0_button->setGeometry(QRect(0, 0, 300, 50));
        sizePolicy1.setHeightForWidth(set_x0_button->sizePolicy().hasHeightForWidth());
        set_x0_button->setSizePolicy(sizePolicy1);
        x0_textbrowser = new QTextBrowser(lmax_calibration_14);
        x0_textbrowser->setObjectName(QString::fromUtf8("x0_textbrowser"));
        x0_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_20 = new QLabel(lmax_calibration_14);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(509, 9, 16, 19));
        label_20->setFont(font1);
        label_20->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lmax_calibration_14);

        lmax_calibration_15 = new QWidget(widget_3);
        lmax_calibration_15->setObjectName(QString::fromUtf8("lmax_calibration_15"));
        set_dx_button = new QPushButton(lmax_calibration_15);
        set_dx_button->setObjectName(QString::fromUtf8("set_dx_button"));
        set_dx_button->setGeometry(QRect(0, 0, 300, 50));
        sizePolicy1.setHeightForWidth(set_dx_button->sizePolicy().hasHeightForWidth());
        set_dx_button->setSizePolicy(sizePolicy1);
        dx_textbrowser = new QTextBrowser(lmax_calibration_15);
        dx_textbrowser->setObjectName(QString::fromUtf8("dx_textbrowser"));
        dx_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_21 = new QLabel(lmax_calibration_15);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(509, 9, 16, 19));
        label_21->setFont(font1);
        label_21->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lmax_calibration_15);

        lmax_calibration_16 = new QWidget(widget_3);
        lmax_calibration_16->setObjectName(QString::fromUtf8("lmax_calibration_16"));
        set_temp_co2_button = new QPushButton(lmax_calibration_16);
        set_temp_co2_button->setObjectName(QString::fromUtf8("set_temp_co2_button"));
        set_temp_co2_button->setGeometry(QRect(0, 0, 300, 50));
        sizePolicy1.setHeightForWidth(set_temp_co2_button->sizePolicy().hasHeightForWidth());
        set_temp_co2_button->setSizePolicy(sizePolicy1);
        temp_co2_textbrowser = new QTextBrowser(lmax_calibration_16);
        temp_co2_textbrowser->setObjectName(QString::fromUtf8("temp_co2_textbrowser"));
        temp_co2_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_22 = new QLabel(lmax_calibration_16);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(509, 9, 16, 19));
        label_22->setFont(font1);
        label_22->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lmax_calibration_16);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        widget_2 = new QWidget(tab_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 541, 371));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lmax_calibration_8 = new QWidget(widget_2);
        lmax_calibration_8->setObjectName(QString::fromUtf8("lmax_calibration_8"));
        set_lmin_button = new QPushButton(lmax_calibration_8);
        set_lmin_button->setObjectName(QString::fromUtf8("set_lmin_button"));
        set_lmin_button->setGeometry(QRect(0, 0, 300, 50));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(set_lmin_button->sizePolicy().hasHeightForWidth());
        set_lmin_button->setSizePolicy(sizePolicy3);
        lmin_textbrowser = new QTextBrowser(lmax_calibration_8);
        lmin_textbrowser->setObjectName(QString::fromUtf8("lmin_textbrowser"));
        lmin_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_13 = new QLabel(lmax_calibration_8);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(509, 9, 16, 19));
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lmax_calibration_8);

        lmax_calibration_5 = new QWidget(widget_2);
        lmax_calibration_5->setObjectName(QString::fromUtf8("lmax_calibration_5"));
        set_lmax_button = new QPushButton(lmax_calibration_5);
        set_lmax_button->setObjectName(QString::fromUtf8("set_lmax_button"));
        set_lmax_button->setGeometry(QRect(0, 0, 300, 50));
        sizePolicy3.setHeightForWidth(set_lmax_button->sizePolicy().hasHeightForWidth());
        set_lmax_button->setSizePolicy(sizePolicy3);
        set_lmax_button->setMinimumSize(QSize(85, 0));
        lmax_textbrowser = new QTextBrowser(lmax_calibration_5);
        lmax_textbrowser->setObjectName(QString::fromUtf8("lmax_textbrowser"));
        lmax_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_14 = new QLabel(lmax_calibration_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(509, 9, 16, 19));
        label_14->setFont(font1);
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lmax_calibration_5);

        lmax_calibration_9 = new QWidget(widget_2);
        lmax_calibration_9->setObjectName(QString::fromUtf8("lmax_calibration_9"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lmax_calibration_9->sizePolicy().hasHeightForWidth());
        lmax_calibration_9->setSizePolicy(sizePolicy4);
        set_pH0_button = new QPushButton(lmax_calibration_9);
        set_pH0_button->setObjectName(QString::fromUtf8("set_pH0_button"));
        set_pH0_button->setGeometry(QRect(0, 0, 300, 50));
        sizePolicy3.setHeightForWidth(set_pH0_button->sizePolicy().hasHeightForWidth());
        set_pH0_button->setSizePolicy(sizePolicy3);
        pH0_textbrowser = new QTextBrowser(lmax_calibration_9);
        pH0_textbrowser->setObjectName(QString::fromUtf8("pH0_textbrowser"));
        pH0_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_15 = new QLabel(lmax_calibration_9);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(509, 9, 16, 19));
        label_15->setFont(font1);
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lmax_calibration_9);

        lmax_calibration_10 = new QWidget(widget_2);
        lmax_calibration_10->setObjectName(QString::fromUtf8("lmax_calibration_10"));
        set_dpH_button = new QPushButton(lmax_calibration_10);
        set_dpH_button->setObjectName(QString::fromUtf8("set_dpH_button"));
        set_dpH_button->setGeometry(QRect(0, 0, 300, 50));
        sizePolicy3.setHeightForWidth(set_dpH_button->sizePolicy().hasHeightForWidth());
        set_dpH_button->setSizePolicy(sizePolicy3);
        dpH_textbrowser = new QTextBrowser(lmax_calibration_10);
        dpH_textbrowser->setObjectName(QString::fromUtf8("dpH_textbrowser"));
        dpH_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_16 = new QLabel(lmax_calibration_10);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(509, 9, 16, 19));
        label_16->setFont(font1);
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lmax_calibration_10);

        lmax_calibration_11 = new QWidget(widget_2);
        lmax_calibration_11->setObjectName(QString::fromUtf8("lmax_calibration_11"));
        set_temp_button = new QPushButton(lmax_calibration_11);
        set_temp_button->setObjectName(QString::fromUtf8("set_temp_button"));
        set_temp_button->setGeometry(QRect(0, 0, 300, 50));
        sizePolicy3.setHeightForWidth(set_temp_button->sizePolicy().hasHeightForWidth());
        set_temp_button->setSizePolicy(sizePolicy3);
        temp_textbrowser = new QTextBrowser(lmax_calibration_11);
        temp_textbrowser->setObjectName(QString::fromUtf8("temp_textbrowser"));
        temp_textbrowser->setGeometry(QRect(305, 9, 200, 33));
        label_17 = new QLabel(lmax_calibration_11);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(509, 9, 16, 19));
        label_17->setFont(font1);
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lmax_calibration_11);

        allSet_pH = new QPushButton(tab_4);
        allSet_pH->setObjectName(QString::fromUtf8("allSet_pH"));
        allSet_pH->setGeometry(QRect(580, 10, 90, 61));
        quitButtonStartMain_3 = new QPushButton(tab_4);
        quitButtonStartMain_3->setObjectName(QString::fromUtf8("quitButtonStartMain_3"));
        quitButtonStartMain_3->setGeometry(QRect(580, 330, 90, 30));
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        textBrowser = new QTextBrowser(tab_5);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 130, 601, 192));
        comboBox_2 = new QComboBox(tab_5);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(40, 40, 76, 24));
        lineEdit = new QLineEdit(tab_5);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 40, 431, 28));
        tabWidget_2->addTab(tab_5, QString());
        tabWidget->addTab(start, QString());
        o2 = new QWidget();
        o2->setObjectName(QString::fromUtf8("o2"));
        plotButtonSensor_1 = new QPushButton(o2);
        plotButtonSensor_1->setObjectName(QString::fromUtf8("plotButtonSensor_1"));
        plotButtonSensor_1->setGeometry(QRect(10, 405, 90, 30));
        clearButtonSensor_1 = new QPushButton(o2);
        clearButtonSensor_1->setObjectName(QString::fromUtf8("clearButtonSensor_1"));
        clearButtonSensor_1->setGeometry(QRect(150, 405, 90, 30));
        mainMenuButtonSensor_1 = new QPushButton(o2);
        mainMenuButtonSensor_1->setObjectName(QString::fromUtf8("mainMenuButtonSensor_1"));
        mainMenuButtonSensor_1->setGeometry(QRect(350, 405, 130, 30));
        quitButtonSensor_1 = new QPushButton(o2);
        quitButtonSensor_1->setObjectName(QString::fromUtf8("quitButtonSensor_1"));
        quitButtonSensor_1->setGeometry(QRect(570, 405, 90, 30));
        lineGraph_o2 = new QChartView(o2);
        lineGraph_o2->setObjectName(QString::fromUtf8("lineGraph_o2"));
        lineGraph_o2->setGeometry(QRect(0, 0, 680, 400));
        tabWidget->addTab(o2, QString());
        CO2 = new QWidget();
        CO2->setObjectName(QString::fromUtf8("CO2"));
        clearButtonSensor_2 = new QPushButton(CO2);
        clearButtonSensor_2->setObjectName(QString::fromUtf8("clearButtonSensor_2"));
        clearButtonSensor_2->setGeometry(QRect(110, 405, 90, 30));
        plotButtonSensor_2 = new QPushButton(CO2);
        plotButtonSensor_2->setObjectName(QString::fromUtf8("plotButtonSensor_2"));
        plotButtonSensor_2->setGeometry(QRect(10, 405, 90, 30));
        mainMenuButtonSensor_2 = new QPushButton(CO2);
        mainMenuButtonSensor_2->setObjectName(QString::fromUtf8("mainMenuButtonSensor_2"));
        mainMenuButtonSensor_2->setGeometry(QRect(460, 405, 110, 30));
        quitButtonSensor_2 = new QPushButton(CO2);
        quitButtonSensor_2->setObjectName(QString::fromUtf8("quitButtonSensor_2"));
        quitButtonSensor_2->setGeometry(QRect(570, 405, 90, 30));
        comboBox = new QComboBox(CO2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(270, 405, 110, 30));
        lineGraph_co2 = new QChartView(CO2);
        lineGraph_co2->setObjectName(QString::fromUtf8("lineGraph_co2"));
        lineGraph_co2->setGeometry(QRect(0, 0, 680, 400));
        tabWidget->addTab(CO2, QString());
        pH = new QWidget();
        pH->setObjectName(QString::fromUtf8("pH"));
        plotButtonSensor_3 = new QPushButton(pH);
        plotButtonSensor_3->setObjectName(QString::fromUtf8("plotButtonSensor_3"));
        plotButtonSensor_3->setGeometry(QRect(10, 405, 90, 30));
        quitButtonSensor_3 = new QPushButton(pH);
        quitButtonSensor_3->setObjectName(QString::fromUtf8("quitButtonSensor_3"));
        quitButtonSensor_3->setGeometry(QRect(570, 405, 90, 30));
        mainMenuButtonSensor_3 = new QPushButton(pH);
        mainMenuButtonSensor_3->setObjectName(QString::fromUtf8("mainMenuButtonSensor_3"));
        mainMenuButtonSensor_3->setGeometry(QRect(460, 405, 110, 30));
        clearButtonSensor_3 = new QPushButton(pH);
        clearButtonSensor_3->setObjectName(QString::fromUtf8("clearButtonSensor_3"));
        clearButtonSensor_3->setGeometry(QRect(110, 405, 90, 30));
        spinBoxStaticValues_sensor_3 = new QSpinBox(pH);
        spinBoxStaticValues_sensor_3->setObjectName(QString::fromUtf8("spinBoxStaticValues_sensor_3"));
        spinBoxStaticValues_sensor_3->setGeometry(QRect(350, 405, 50, 30));
        spinBoxStaticValues_sensor_3->setValue(60);
        showStaticValues_sensor_3 = new QPushButton(pH);
        showStaticValues_sensor_3->setObjectName(QString::fromUtf8("showStaticValues_sensor_3"));
        showStaticValues_sensor_3->setGeometry(QRect(240, 405, 110, 30));
        lineGraph_ph = new QChartView(pH);
        lineGraph_ph->setObjectName(QString::fromUtf8("lineGraph_ph"));
        lineGraph_ph->setGeometry(QRect(0, 0, 680, 400));
        tabWidget->addTab(pH, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        stopMeassurementButton->setText(QCoreApplication::translate("MainWindow", "Messungen stoppen", nullptr));
        pCO2DisplayButton->setText(QCoreApplication::translate("MainWindow", "<none>", nullptr));
        pO2DisplayButton->setText(QCoreApplication::translate("MainWindow", "<none>", nullptr));
        pHDisplayButton->setText(QCoreApplication::translate("MainWindow", "<none>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "O2 in mmHg Sensor 1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "CO2 in mmHg Sensor 1", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "pH Sensor 1", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "O2 in mmHg Sensor 2", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "CO2 in mmHg Sensor 2", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "pH Sensor 2", nullptr));
        pHDisplayButton_2->setText(QCoreApplication::translate("MainWindow", "<none>", nullptr));
        pCO2DisplayButton_2->setText(QCoreApplication::translate("MainWindow", "<none>", nullptr));
        pO2DisplayButton_2->setText(QCoreApplication::translate("MainWindow", "<none>", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Verf\303\274gbarer Speicher:", nullptr));
        memoryValueButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(general), QCoreApplication::translate("MainWindow", "Main", nullptr));
        initialize_sensor_1_button->setText(QCoreApplication::translate("MainWindow", "Initialisiere 2. O2-Sensor", nullptr));
        sensor_1_init_label->setText(QCoreApplication::translate("MainWindow", "O2-Sensor nicht initialisiert", nullptr));
        sensor_3_init_label->setText(QCoreApplication::translate("MainWindow", "pH-Sensor nicht initialisiert", nullptr));
        initialize_sensor_4_button->setText(QCoreApplication::translate("MainWindow", "Initialisiere 1. CO2-Sensor", nullptr));
        initialize_sensor_3_button->setText(QCoreApplication::translate("MainWindow", "Initialisiere 2. pH-Sensor", nullptr));
        initialize_sensor_5_button->setText(QCoreApplication::translate("MainWindow", "Initialisiere 2. CO2-Sensor", nullptr));
        sensor_2_init_label->setText(QCoreApplication::translate("MainWindow", "O2-Sensor nicht initialisiert", nullptr));
        sensor_4_init_label->setText(QCoreApplication::translate("MainWindow", "pH-Sensor nicht initialisiert", nullptr));
        initialize_sensor_2_button->setText(QCoreApplication::translate("MainWindow", "Initialisiere 1. pH-Sensor", nullptr));
        sensor_5_init_label->setText(QCoreApplication::translate("MainWindow", "CO2-Sensor nicht initialisiert", nullptr));
        sensor_6_init_label->setText(QCoreApplication::translate("MainWindow", "CO2-Sensor nicht initialisiert", nullptr));
        initialize_sensor_0_button->setText(QCoreApplication::translate("MainWindow", "Initialisiere 1. O2-Sensor ", nullptr));
        quitButtonStartMain->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        start_measurement_button->setText(QCoreApplication::translate("MainWindow", "Starte Messungen", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QCoreApplication::translate("MainWindow", "\303\234bersicht", nullptr));
        set_f1_button->setText(QCoreApplication::translate("MainWindow", "Setze f1-Wert f\303\274r O2-Sensor", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        set_m_button->setText(QCoreApplication::translate("MainWindow", "Setze m-Wert f\303\274r O2-Sensor", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        set_dPhi1_button->setText(QCoreApplication::translate("MainWindow", "Setze dPhi1-Wert f\303\274r O2-Sensor", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        set_dPhi2_button->setText(QCoreApplication::translate("MainWindow", "Setze dPhi2-Wert f\303\274r O2-Sensor", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        set_dKSV1_button->setText(QCoreApplication::translate("MainWindow", "Setze dKSV1-Wert f\303\274r O2-Sensor", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        set_dKSV2_button->setText(QCoreApplication::translate("MainWindow", "Setze dKSV2-Wert f\303\274r O2-Sensor", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        allSet_o2->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        quitButtonStartMain_2->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QCoreApplication::translate("MainWindow", "O2 init", nullptr));
        allSet_cO2->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        quitButtonStartMain_4->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        set_A1_button->setText(QCoreApplication::translate("MainWindow", "Setze A1-Wert f\303\274r co2-Sensor", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        set_A2_button->setText(QCoreApplication::translate("MainWindow", "Setze A2-Wert f\303\274r co2-Sensor", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        set_x0_button->setText(QCoreApplication::translate("MainWindow", "Setze x0-Wert f\303\274r co2-Sensor", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        set_dx_button->setText(QCoreApplication::translate("MainWindow", "Setze dx-Wert f\303\274r co2-Sensor", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        set_temp_co2_button->setText(QCoreApplication::translate("MainWindow", "Setze Temperatur f\303\274r co2-Sensor", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QCoreApplication::translate("MainWindow", "CO2 init", nullptr));
        set_lmin_button->setText(QCoreApplication::translate("MainWindow", "Setze lmin-Wert f\303\274r pH-Sensor", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        set_lmax_button->setText(QCoreApplication::translate("MainWindow", "Setze lmax-Wert f\303\274r pH-Sensor", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        set_pH0_button->setText(QCoreApplication::translate("MainWindow", "Setze pH0-Wert f\303\274r pH-Sensor", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        set_dpH_button->setText(QCoreApplication::translate("MainWindow", "Setze dpH-Wert f\303\274r pH-Sensor", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        set_temp_button->setText(QCoreApplication::translate("MainWindow", "Setze Temperatur f\303\274r pH-Sensor", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        allSet_pH->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        quitButtonStartMain_3->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MainWindow", "pH init", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "port0.", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "port1.", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "port2.", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "port3.", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("MainWindow", "port4.", nullptr));
        comboBox_2->setItemText(5, QCoreApplication::translate("MainWindow", "port5.", nullptr));

        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("MainWindow", "-", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(start), QCoreApplication::translate("MainWindow", "Setup", nullptr));
        plotButtonSensor_1->setText(QCoreApplication::translate("MainWindow", "Plot", nullptr));
        clearButtonSensor_1->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        mainMenuButtonSensor_1->setText(QCoreApplication::translate("MainWindow", "Back to General", nullptr));
        quitButtonSensor_1->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(o2), QCoreApplication::translate("MainWindow", "O2", nullptr));
        clearButtonSensor_2->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        plotButtonSensor_2->setText(QCoreApplication::translate("MainWindow", "Plot", nullptr));
        mainMenuButtonSensor_2->setText(QCoreApplication::translate("MainWindow", "Back to General", nullptr));
        quitButtonSensor_2->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Zeige Letzte:", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "10", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "30", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "60", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "120", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "180", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "300", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "Alle ", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(CO2), QCoreApplication::translate("MainWindow", "CO2", nullptr));
        plotButtonSensor_3->setText(QCoreApplication::translate("MainWindow", "Plot", nullptr));
        quitButtonSensor_3->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        mainMenuButtonSensor_3->setText(QCoreApplication::translate("MainWindow", "Back to General", nullptr));
        clearButtonSensor_3->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        showStaticValues_sensor_3->setText(QCoreApplication::translate("MainWindow", "Zeige letzte:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pH), QCoreApplication::translate("MainWindow", "pH", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
