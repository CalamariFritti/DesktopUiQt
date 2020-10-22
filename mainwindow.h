#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void setActiveSensor5();

signals:
    void radioButton_5_toggled();

private slots:
    void startDialog();

private:
    Ui::MainWindow *ui;

    // keep pointer to activation window
    Dialog* activation;

    bool activatedSensor_0;
    bool activatedSensor_1;
    bool activatedSensor_2;
    bool activatedSensor_3;
    bool activatedSensor_4;
    bool activatedSensor_5;
};

#endif // MAINWINDOW_H
