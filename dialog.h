#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QObject>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

signals:
    void radioButton_5_toggled();

public slots:
    void on_radioButton_5_toggled(bool checked);

private slots:


private:
    Ui::Dialog *ui;


    bool activateSensor_0 = false;
    bool activateSensor_1 = false;
    bool activateSensor_2 = false;
    bool activateSensor_3 = false;
    bool activateSensor_4 = false;
    bool activateSensor_5 = false;

};

#endif // DIALOG_H
