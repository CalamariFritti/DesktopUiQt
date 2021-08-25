#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
//    w.setWindowFlags(Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);
//    w.setWindowState((Qt::WindowFullScreen));
    w.show();

    return a.exec();
}

enum communication{};
