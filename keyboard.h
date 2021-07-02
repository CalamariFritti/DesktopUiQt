#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>

namespace Ui {
class Keyboard;
}

class Keyboard : public QWidget
{
    Q_OBJECT

public:
    explicit Keyboard(QWidget *parent = 0, QString input = "", QString title = "<title>");
    ~Keyboard();
signals:
    void pushButton_ok_clicked(double);
private slots:

    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_point_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_backSpace_clicked();
    void on_pushButton_clear_clicked();

    void on_pushButton_ok_clicked();
    void addChar(char);

private:

    QString input;

    bool firstclick = true;

    Ui::Keyboard *ui;

};

#endif // KEYBOARD_H
