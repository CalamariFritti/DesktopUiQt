#ifndef SENSORS_H
#define SENSORS_H

#include <QObject>
#include "mainwindow.h"

class Sensors : public QSerialPort
{
public:
    explicit Sensors(QObject *parent = 0);
};

#endif // SENSORS_H
