#include "mainwindow.h"
#include "sensor.h"

Sensor::Sensor(QObject * parent)
{
    this->setBaudRate(preSensBaudRate);
    this->setDataBits(preSensDataBits);
}


