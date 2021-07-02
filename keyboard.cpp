#include "keyboard.h"
#include "ui_keyboard.h"
#include "main.cpp"

Keyboard::Keyboard(QWidget *parent, QString defaultValue, QString title) :
    QWidget(parent),
    ui(new Ui::Keyboard)
{
    ui->setupUi(this);
    ui->number_browser->setText(defaultValue);
    ui->label->setText(title);
    this->input = defaultValue;
}

Keyboard::~Keyboard()
{
    delete ui;
}

void Keyboard::on_pushButton_0_clicked()     { addChar('0');}
void Keyboard::on_pushButton_1_clicked()     { addChar('1');}
void Keyboard::on_pushButton_2_clicked()     { addChar('2');}
void Keyboard::on_pushButton_3_clicked()     { addChar('3');}
void Keyboard::on_pushButton_4_clicked()     { addChar('4');}
void Keyboard::on_pushButton_5_clicked()     { addChar('5');}
void Keyboard::on_pushButton_6_clicked()     { addChar('6');}
void Keyboard::on_pushButton_7_clicked()     { addChar('7');}
void Keyboard::on_pushButton_8_clicked()     { addChar('8');}
void Keyboard::on_pushButton_9_clicked()     { addChar('9');}
void Keyboard::on_pushButton_point_clicked()
{
    if(!input.contains('.')){addChar('.');}
}

void Keyboard::on_pushButton_plus_clicked()
{
    if(input[0] == '-')
    {
        input.remove('-');
        ui->number_browser->setText(input);
    }
}

void Keyboard::on_pushButton_minus_clicked()
{
    if(input[0] != '-')
    {
        input.prepend('-');
        ui->number_browser->setText(input);
    }
}

void Keyboard::on_pushButton_backSpace_clicked()
{
    if(input.length() > 0)
    {
        input.remove(input.length() - 1, 1);
        ui->number_browser->setText(input);
    }
}

void Keyboard::on_pushButton_clear_clicked()
{
    input = "";
    ui->number_browser->setText(input);
}

void Keyboard::addChar(char c)
{
    if(firstclick)
    {
        ui->number_browser->clear();
        firstclick = false;
    }

    input.append(c);
    ui->number_browser->setText(input);
}

void Keyboard::on_pushButton_ok_clicked()
{
    double emitIt = input.toDouble();
    emit pushButton_ok_clicked(emitIt);
    this->~Keyboard();
}
