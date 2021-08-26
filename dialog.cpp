#include "dialog.h"
#include "ui_dialog.h"
#include <QObject>
#include <QDebug>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
//o2-Sensor_01
void Dialog::on_checkBox_0_toggled(bool checked)
{
    //show status in text (in additon to checkBox-dot)
    if(checked){
        ui->checkBox_0->setText("O2-Sensor 01 aktiv");
    }else{
        ui->checkBox_0->setText("O2-Sensor 01 inaktiv");
    }
    //emit signal to connect in mainwindow.cpp
    emit checkBox_0_toggled(checked);
}
//o2-Sensor_02
void Dialog::on_checkBox_1_toggled(bool checked)
{
    if(checked){
        ui->checkBox_1->setText("O2-Sensor 02 aktiv");
    }else{
        ui->checkBox_1->setText("O2-Sensor 02 inaktiv");
    }
    emit checkBox_1_toggled(checked);
}
//
void Dialog::on_checkBox_2_toggled(bool checked)
{
    if(checked){
        ui->checkBox_2->setText("pH-Sensor 01 aktiv");
    }else{
        ui->checkBox_2->setText("pH-Sensor 01 inaktiv");
    }
    emit checkBox_2_toggled(checked);
}
void Dialog::on_checkBox_3_toggled(bool checked)
{
    if(checked){
        ui->checkBox_3->setText("pH-Sensor 02 aktiv");
    }else{
        ui->checkBox_3->setText("pH-Sensor 02 inaktiv");
    }
    emit checkBox_3_toggled(checked);
}
void Dialog::on_checkBox_4_toggled(bool checked)
{
    if(checked){
        ui->checkBox_4->setText("CO2-Sensor 01 aktiv");
    }else{
        ui->checkBox_4->setText("CO2-Sensor 01 inaktiv");
    }
    emit checkBox_4_toggled(checked);
}

void Dialog::on_checkBox_5_toggled(bool checked)
{
    if(checked){
        ui->checkBox_5->setText("CO2-Sensor 02 aktiv");
    }else{
        ui->checkBox_5->setText("CO2-Sensor 02 inaktiv");
    }
    emit checkBox_5_toggled(checked);

}


void Dialog::on_saveAndExit_pushButton_clicked()
{
    close();
}

