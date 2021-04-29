#include "mainwindow.h"
#include "sensor.h"

Sensor::Sensor(QString portName) :
    QSerialPort()
{
    this->setPortName(portName);
}

Sensor::~Sensor()
{
    delete this;
}

