#include "mainwindow.h"
#include "file.h"

File::File(QString filepath) :
    QFile()
{
<<<<<<< HEAD
    QFile * newfile = new QFile(filepath);
    newfile->open(QFile::WriteOnly |QFile::Append | QFile::Text);
    newfile->close();
||||||| merged common ancestors

=======
    QFile * newfile = new QFile(filepath);
    newfile->open(QFile::ReadWrite | QFile::Append | QFile::Text);
    newfile->close();
>>>>>>> 730137463809bc515a3239a88548f430ec36d951
}

File::~File()
{
    delete this;
}
