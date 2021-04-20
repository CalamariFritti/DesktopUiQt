#ifndef SENSOR_H
#define SENSOR_H

#include "mainwindow.h"

#include <QMainWindow>

class Sensor : public QSerialPort
{
public:
    explicit Sensor(QObject * parent = 0);
};

#endif // SENSOR_H
