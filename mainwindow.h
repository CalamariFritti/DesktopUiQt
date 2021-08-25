#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QInputDialog>
#include <QMainWindow>

#include <QApplication>
#include <QCoreApplication>
#include <QtCharts>
#include <QDebug>
#include <QFile>
#include <QList>
#include <QMainWindow>
#include <QMessageBox>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTextStream>
#include <QTime>
#include <QTimer>
#include <QThread>
#include <QProxyStyle>
#include <QStyleOptionTab>
#include <QInputDialog>


#include "dialog.h"
#include "sensor.h"
#include "file.h"
#include "keyboard.h"

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

        explicit MainWindow(QWidget *parent = 0);

        Dialog *activaton;
        Keyboard * key;

        QList<QSerialPort*> list_of_ports;

        ~MainWindow();

public slots:

        QString get_timeStamp();
        void get_sensor_value_port_0();
        void get_sensor_value_port_1();
        void get_sensor_value_port_2();
        void get_sensor_value_port_3();
        void get_sensor_value_port_4();
        void get_sensor_value_port_5();


        void write_to_file(QString);
        void write_to_file_raw(QString);

        void setActiveSensor0(bool);
        void setActiveSensor1(bool);
        void setActiveSensor2(bool);
        void setActiveSensor3(bool);
        void setActiveSensor4(bool);
        void setActiveSensor5(bool);

signals:
        void radioButton_0_toggled(bool);
        void radioButton_1_toggled(bool);
        void radioButton_2_toggled(bool);
        void radioButton_3_toggled(bool);
        void radioButton_4_toggled(bool);
        void radioButton_5_toggled(bool);

private slots:

        void delay(int);

        void setFontsizesAndBackgroundColors();

        void setupSensors();

        void startDialog();

        void setPreInit();

        void on_quitButtonStartMain_clicked();

        void on_initialize_sensor_0_button_clicked();
        void on_initialize_sensor_1_button_clicked();
        void on_initialize_sensor_2_button_clicked();
        void on_initialize_sensor_3_button_clicked();
        void on_initialize_sensor_4_button_clicked();
        void on_initialize_sensor_5_button_clicked();

    // initialisation of o2-sensor
        void on_set_f1_button_clicked();
        void on_set_m_button_clicked();
        void on_set_dPhi1_button_clicked();
        void on_set_dPhi2_button_clicked();
        void on_set_dKSV1_button_clicked();
        void on_set_dKSV2_button_clicked();
        void on_quitButtonStartMain_2_clicked();
        void on_allSet_o2_clicked();

        void set_f1_value(double);


    // inititalisation of ph-sensor
        void on_set_lmin_button_clicked();
        void on_set_lmax_button_clicked();
        void on_set_pH0_button_clicked();
        void on_set_dpH_button_clicked();
        void on_set_temp_button_clicked();
        void on_quitButtonStartMain_3_clicked();
        void on_allSet_pH_clicked();

    // initialisation of co2-sensor
        void on_set_A1_button_clicked();
        void on_set_A2_button_clicked();
        void on_set_x0_button_clicked();
        void on_set_dx_button_clicked();
        void on_allSet_cO2_clicked();
        void on_quitButtonStartMain_4_clicked();

        void on_start_measurement_button_clicked();

        void set_main_output_buttons();

        void on_stopMeassurementButton_clicked();

        void on_quitButton_clicked();

        void on_set_temp_co2_button_clicked();

        void rawVectorInit();

        void on_lineEdit_returnPressed();

        void setupGraphs();

        void on_quitButtonSensor_1_clicked();

        void on_quitButtonSensor_2_clicked();

        void on_quitButtonSensor_3_clicked();

        void on_plotButtonSensor_1_clicked();

        void append_to_plotSeries();

        void startStorageReader();

        void setupSensor485();
private:
    Ui::MainWindow *ui;

    // keep pointer to activation window
    Dialog * activation;

    // current directory for output
    QString dir = QCoreApplication::applicationDirPath();

    QTimer * timer_for_output;

    // for drawing purposes, holding charts, serieses and values(vector)
    QChart *o2_chart;
    QChart *co2_chart;
    QChart *ph_chart;

    QChartView *o2_chartView;
    QChartView *co2_chartView;
    QChartView *ph_chartView;

    QGridLayout *o2_gridLayout;
    QGridLayout *co2_gridLayout;
    QGridLayout *ph_gridLayout;

    QList<QChart> list_of_charts;

    QString o2_chart_name;
    QString co2_chart_name;
    QString ph_chart_name;

    QLineSeries *o2_series;
    QLineSeries *co2_series;
    QLineSeries *ph_series;

    QDateTimeAxis *axisX;
    QValueAxis *axisY;

    QDateTimeAxis *co2_axisX;
    QValueAxis *co2_axisY;

    QDateTimeAxis *ph_axisX;
    QValueAxis *ph_axisY;

    QVector<double> qv_o2_1, qv_o2_2, qv_co2_1, qv_co2_2, qv_ph_1, qv_ph_2;

    QDateTime start;

    // for raw log file values
    QList<QString> raw_o2_1, raw_o2_2, raw_co2_1, raw_co2_2, raw_ph_1, raw_ph_2;

    // this array is for determining the hw_address (/dev/ttyUSB0,...) match the hw_id's (N01, N02, ...)
    // index of the array is hw_id, value is hw_address -> port_index[0]: 4 means /dev/ttyUSB0 was distributed to N04
    int port_index[6];

// port_0 is new port for RS 485 comm.
    QSerialPort port_0;

// deprecated RS 323, no longer in use
    QSerialPort port_1;
    QSerialPort port_2;
    QSerialPort port_3;
    QSerialPort port_4;
    QSerialPort port_5;

// serialport Object for RS 485, not yet in use
    QSerialPort port_485;

    QSerialPort * ptr_port_0 = &port_0;

    // setting system_locations to hardware addresses
    //QString port_0_system_location = "/dev/pts/3";
    QString port_0_system_location = "/dev/ttyUSB1";
    QString port_1_system_location = "/dev/ttyUSB5";
    QString port_2_system_location = "/dev/ttyUSB3";
    QString port_3_system_location = "/dev/ttyUSB4";
    QString port_4_system_location = "/dev/ttyUSB0";
    QString port_5_system_location = "/dev/ttyUSB2";

    QString input_buffer_port_0;
    QString input_buffer_port_1;
    QString input_buffer_port_2;
    QString input_buffer_port_3;
    QString input_buffer_port_4;
    QString input_buffer_port_5;
    QByteArray serial_input_port_0;
    QByteArray serial_input_port_1;
    QByteArray serial_input_port_2;
    QByteArray serial_input_port_3;
    QByteArray serial_input_port_4;
    QByteArray serial_input_port_5;

    // these get set to true if the sensor is to be initiated
    // by the user (picked in initial dialog)
    bool activatedSensor_0;
    bool activatedSensor_1;
    bool activatedSensor_2;
    bool activatedSensor_3;
    bool activatedSensor_4;
    bool activatedSensor_5;

    // these get set true once the initate_sensor_x_button is clicked
    // to distinguish between the two available sensors of each type
    bool sensor_0_is_available = false;
    bool sensor_1_is_available = false;
    bool sensor_2_is_available = false;
    bool sensor_3_is_available = false;
    bool sensor_4_is_available = false;
    bool sensor_5_is_available = false;

    // are the ports already initiated
    bool port_0_is_initiated = false;
    bool port_1_is_initiated = false;
    bool port_2_is_initiated = false;
    bool port_3_is_initiated = false;
    bool port_4_is_initiated = false;
    bool port_5_is_initiated = false;

    /*
     *  ports can only be initiated once all constants are set
     */

    // constants for o2-sensors
    bool f1_1 = false;
    bool m_1 = false;
    bool dPhi1_1 = false;
    bool dPhi2_1 = false;
    bool dKSV1_1 = false;
    bool dKSV2_1 = false;

    bool f1_2 = false;
    bool m_2 = false;
    bool dPhi1_2 = false;
    bool dPhi2_2 = false;
    bool dKSV1_2 = false;
    bool dKSV2_2 = false;

    bool humidity_1 = false;
    bool humidity_2 = false;
    bool pressure_measure_1 = false;
    bool pressure_measure_2 = false;
    bool cal0_1 = false;
    bool cal0_2 = false;

    // constants for pH-sensors
    bool lmin_1 = false;
    bool lmax_1 = false;
    bool pH0_1 = false;
    bool dpH_1 = false;
    bool temp_1 = false;

    bool lmin_2 = false;
    bool lmax_2 = false;
    bool pH0_2 = false;
    bool dpH_2 = false;
    bool temp_2 = false;

    // constants for co2-sensors
    bool A1_1 = false;
    bool A2_1 = false;
    bool x0_1 = false;
    bool dx_1 = false;
    bool temp_co2_1 = false;

    bool A1_2 = false;
    bool A2_2 = false;
    bool x0_2 = false;
    bool dx_2 = false;
    bool temp_co2_2 = false;

};

#endif // MAINWINDOW_H
