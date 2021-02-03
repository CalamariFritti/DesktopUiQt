#include "calibrationo2.h"
#include "ui_calibrationo2.h"

#include "mainwindow.h"

CalibrationO2::CalibrationO2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalibrationO2)
{
    ui->setupUi(this);
}

CalibrationO2::~CalibrationO2()
{
    delete ui;
}


void CalibrationO2::on_set_pressure_button_clicked()
{
    /*

    double press_atmo_meas = QInputDialog::getDouble(this,
                                         "Druck eingeben",
                                         "in hPa:",
                                         973, 0, 2000, 0);
    ui->pressure_textbrowser->clear();
    ui->pressure_textbrowser->append(QString::number(press_atmo_meas));
    // output must be in this format: "malpXXXX\r" example: malp0973 sets to pressure = 973 hPa
    QString press_to_sensor = "malp" + QString::number(press_atmo_meas).rightJustified(4,'0') + "\r";
    qDebug() << press_to_sensor;
    QByteArray out = press_to_sensor.toUtf8().toBase64();


    if(sensor_0_is_available){
        port_3.write(out);
        pressure_measure_1 = true;
    }else if(sensor_1_is_available){
        port_5.write(out);
        pressure_measure_2 = true;
                qDebug() << "sensor 01: pressure measurement: " << pressure_measure_2;
    }

    // all values set?
    if(f1_1 && m_1 && dPhi1_1 && dPhi2_1 && dKSV1_1 && dKSV2_1){
        ui->allSet_o2->setEnabled(true);
        port_3_is_initiated = true;
    }
    else if (f1_2 && m_2 && dPhi1_2 && dPhi2_2 && dKSV1_2 && dKSV2_2) {
        ui->allSet_o2->setEnabled(true);
        port_5_is_initiated = true;
    }
    */
}

void CalibrationO2::on_set_cal0_button_clicked()
{
    /*
    double cal0 = QInputDialog::getDouble(this,
                                         "set 0% oxygen phase value",
                                         "",
                                         55, 0, 180, 2);
    ui->cal0_textbrowser->clear();
    ui->cal0_textbrowser->append(QString::number(cal0));
    // output must be in this format: "clzpXXXX\r" example: clzp5673 sets to 56,73°
    QString cal0_to_sensor = "clzp" + QString::number(cal0).remove('.').leftJustified(4, '0') + "\r";
    qDebug() << cal0_to_sensor;
    QByteArray out = cal0_to_sensor.toUtf8().toBase64();


    if(sensor_0_is_available){
        port_3.write(out);
        cal0_1 = true;
    }else if(sensor_1_is_available){
        port_5.write(out);
        cal0_2 = true;
                qDebug() << "sensor 01: pressure measurement: " << pressure_measure_2;
    }

    // all values set?
    if(f1_1 && m_1 && dPhi1_1 && dPhi2_1 && dKSV1_1 && dKSV2_1){
        ui->allSet_o2->setEnabled(true);
        port_3_is_initiated = true;
    }
    else if (f1_2 && m_2 && dPhi1_2 && dPhi2_2 && dKSV1_2 && dKSV2_2) {
        ui->allSet_o2->setEnabled(true);
        port_5_is_initiated = true;
    }
    */
}

void CalibrationO2::on_comboBox_2_activated(const QString &arg1)
{
    qDebug() << arg1;

    /*
    QString humidity_to_sensor;
    QString calibration_to_sensor;
    QString humid = "Humid";
    QString dry = "Dry";

    //humid: calt0000  dry: calt0001
    if(arg1 == humid)
    {
        humidity_to_sensor = "calt0000\r";
        calibration_to_sensor = "malt0000\r";
    }else if(arg1 == dry)
    {
        humidity_to_sensor = "calt0001\r";
        calibration_to_sensor = "calt0001\r";
    }

    QByteArray out = humidity_to_sensor.toUtf8().toBase64();
    QByteArray out_2 = calibration_to_sensor.toUtf8().toBase64();

    if(sensor_0_is_available){
        port_3.write(out);
        port_3.write(out_2);
        humidity_1 = true;
        qDebug() << "sensor 01: humidity: " << out << humidity_to_sensor;
    }else if(sensor_1_is_available){
        port_5.write(out);
        port_5.write(out_2);
        humidity_2 = true;
        qDebug() << "sensor 01: humidity: " << out << humidity_to_sensor;
    }

    // all values set?
    if(f1_1 && m_1 && dPhi1_1 && dPhi2_1 && dKSV1_1 && dKSV2_1){
        ui->allSet_o2->setEnabled(true);
        port_3_is_initiated = true;
    }
    else if (f1_2 && m_2 && dPhi1_2 && dPhi2_2 && dKSV1_2 && dKSV2_2) {
        ui->allSet_o2->setEnabled(true);
        port_5_is_initiated = true;
    }
    */
}
