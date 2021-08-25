#include "mainwindow.h"
#include "file.h"

File::File(QString filepath) :
    QFile()
{
    QFile * newfile = new QFile(filepath);
    newfile->open(QFile::WriteOnly |QFile::Append | QFile::Text);
    newfile->close();
}

File::~File()
{
    delete this;
}
