#ifndef FILE_H
#define FILE_H

#include <QObject>

#include "mainwindow.h"

class File : public QFile
{
public:
    explicit File(QString filepath);
};

#endif // FILE_H
