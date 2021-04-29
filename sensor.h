#ifndef SENSOR_H
#define SENSOR_H

#include "mainwindow.h"

#include <QMainWindow>

class Sensor : public QSerialPort
{
public:
    explicit Sensor(QString portName);
    ~Sensor();

private:
    qint32 preSensBaudRate = 19200;
    DataBits preSensDataBits = Data8;
    FlowControl preSensFlowControl = NoFlowControl;
    Parity preSensParity = NoParity;
    StopBits preSensStopBits = OneStop;

};

#endif // SENSOR_H
