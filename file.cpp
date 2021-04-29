#include "mainwindow.h"
#include "file.h"

File::File(QString filepath) :
    QFile()
{

}

File::~File()
{
    delete this;
}
