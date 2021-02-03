#ifndef CALIBRATIONO2_H
#define CALIBRATIONO2_H

#include <QDialog>

namespace Ui {
class CalibrationO2;
}

class CalibrationO2 : public QDialog
{
    Q_OBJECT

public:
    explicit CalibrationO2(QWidget *parent = 0);
    ~CalibrationO2();

private:
    Ui::CalibrationO2 *ui;
};

#endif // CALIBRATIONO2_H
