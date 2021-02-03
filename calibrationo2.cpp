#include "calibrationo2.h"
#include "ui_calibrationo2.h"

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
