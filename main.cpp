#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
//    w.setWindowFlags(Qt::FramelessWindowHint);
//    w.setWindowState((Qt::WindowFullScreen));
    w.show();

    Sensor * sens01 = new Sensor();

    qDebug() << sens01->parity();

    return a.exec();
}

