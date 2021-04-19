#ifndef SENSOR_H
#define SENSOR_H

#include "mainwindow.h"

#include <QMainWindow>

namespace Ui {
class Sensor;
}


class Sensor : public QSerialPort
{
    Q_OBJECT
public:
    explicit Sensor(QSerialPort *parent = 0);

signals:

public slots:

};

#endif // SENSOR_H
