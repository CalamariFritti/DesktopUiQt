#include "dialog.h"
#include "ui_dialog.h"
#include <QObject>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_radioButton_5_toggled(bool checked)
{

    emit radioButton_5_toggled();
}
