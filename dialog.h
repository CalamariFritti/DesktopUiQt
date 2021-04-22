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
    void checkBox_0_toggled(bool);
    void checkBox_1_toggled(bool);
    void checkBox_2_toggled(bool);
    void checkBox_3_toggled(bool);
    void checkBox_4_toggled(bool);
    void checkBox_5_toggled(bool);

public slots:


private slots:

    void on_saveAndExit_pushButton_clicked();
    void on_checkBox_0_toggled(bool checked);
    void on_checkBox_1_toggled(bool checked);
    void on_checkBox_2_toggled(bool checked);
    void on_checkBox_3_toggled(bool checked);
    void on_checkBox_4_toggled(bool checked);
    void on_checkBox_5_toggled(bool checked);

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
