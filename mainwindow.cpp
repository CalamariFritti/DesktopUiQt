#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    startDialog();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startDialog()
{
    Dialog activation;
    QObject::connect(&activation, Dialog::radioButton_5_toggled(), this, MainWindow::setActiveSensor5());
  //  newActivation->setWindowState(Qt::WindowFullScreen);
    activation.raise();
    activation.show();
}

void MainWindow::setActiveSensor5()
{
    activatedSensor_5 = true;
    ui->label->setText(QString::number(activatedSensor_5));
}
