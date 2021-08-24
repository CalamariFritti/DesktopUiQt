#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.setWindowState((Qt::WindowFullScreen));
    w.show();

    QString thisMaName = "thisMaName";
    Sensor * sens01 = new Sensor(thisMaName);

    qDebug() << sens01->parity();
    qDebug() << sens01->portName();

    File * f = new File("22");


    return a.exec();
}

enum communication{};
