/*
 * Sensor an Hardware belegung:
 * pO2-Sensor_1 an Hardware-Pfad /dev/ttyUSB3 -> initialisierung als port_3 --> NEU: /dev/ttyUSB4
 * pO2-Sensor_2 an Hardware-Pfad /dev/ttyUSB5 -> initialisierung als port_5 --> NEU: /dev/ttyUSB2
 *
 * pCO2-Sensor_1 an Hardware-Pfad /dev/ttyUSB4 -> initialisierung als port_4 --> NEU: /dev/ttyUSB0
 * pCO2-Sensor_2 an Hardware-Pfad /dev/ttyUSB1 -> initialisierung als port_1 --> NEU: /dev/ttyUSB5
 *
 *
 * ph-Sensor_1 an Hardware-Pfad /dev/ttyUSB0 -> initialisierung als port_0 --> NEU: /dev/ttyUSB1
 * ph-Sensor_2 an Hardware-Pfad /dev/ttyUSB2 -> initialisierung als port_2 --> NEU: /dev/ttyUSB3
 *
 * 04.11.2020, Dresden:
 * PCO2-Sensor 1 --> N03    ttyUSB0 --> port_4
 *
 * pH-Sensor 1   --> N05    ttyUSB1 --> port_0
 *
 * ttyUSB2 -> PO2-Sensor 2  --> N02 --> port_5
 *
 * ttyUSB3 -> pH-Sensor 2 --> N06 --> port_2
 *
 * ttyUSB4 -> PO2-Sensor 1  --> N01 --> port_3
 *
 * ttyUSB5 -> PCO2-Sensor 2 --> N04 --> port_1
 *
 *
 */


/***************************************************************************++
 *
 * TODOs:   - logfile rohdaten                  --> ok
 *          - stoppe messung button             --> ok
 *          - automatische, sichere zuordnung der Nxx zu den port_xx im sensor_init
 *
 *          - o2 und co2 keine Nachkommastellen auf Anzeige Buttons --> ok
 *          - ph mit zwei nachkomma stellen --> ok
 *
 *          - größere Werte auf Buttons         --> ok
 *          - Start_Tab to Setup                --> ok
 *          - Klammern weg                      --> ok
 *
 *          - Admin Tab mit 1 Point calibration und befehls input für die sensoren
 *          - graphen (!)
 *
 *
 *
 *********************************************************************************/


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    setFontsizesAndBackgroundColors();

    rawVectorInit();

    // wait for 10 seconds to make sure the sensors are started
//  delay(10);

    setupSensors();

    delay(1);

    setHardwareAddressToId();

    setPreInit();

    startDialog();
}

MainWindow::~MainWindow()
{
    QString modeset = "mode0001\r";
    QByteArray out = modeset.toLatin1();

    port_0.write(out);
    port_1.write(out);
    port_2.write(out);
    port_3.write(out);
    port_4.write(out);
    port_5.write(out);

    port_0.close();
    port_1.close();
    port_2.close();
    port_3.close();
    port_4.close();
    port_5.close();

    delete activation;
    delete ui;
}

void MainWindow::delay(int seconds)
{
    QTime dieTime= QTime::currentTime().addSecs(seconds);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
/********************************
 *
 * edits stylesheets of various ui elements
 *
 *********************************/
void MainWindow::setFontsizesAndBackgroundColors()
{
    // upper row of output buttons in main tab are set to blue
    // these are Sensors: o2-1, CO2-1, pH-1
    ui->pO2DisplayButton->setStyleSheet("font:  28pt; background-color: rgb(85, 85, 255);");
    ui->pCO2DisplayButton->setStyleSheet("font:  28pt; background-color: rgb(85, 85, 255);");
    ui->pHDisplayButton->setStyleSheet("font:  28pt; background-color: rgb(85, 85, 255);");

    // upper row of output buttons in main tab are set to light-red
    // these are Sensors: o2-2, CO2-2, pH-2
    ui->pO2DisplayButton_2->setStyleSheet("font:  28pt;\nbackground-color: rgb(255, 85, 127);");
    ui->pCO2DisplayButton_2->setStyleSheet("font:  28pt;\nbackground-color: rgb(255, 85, 127);");
    ui->pHDisplayButton_2->setStyleSheet("font:  28pt;\nbackground-color: rgb(255, 85, 127);");
}

void MainWindow::rawVectorInit()
{
    for(int i = 0; i < 1; i++){
        raw_o2_1.append("O2-Sensor 01");
        raw_o2_2.append("O2-Sensor 02");
        raw_co2_1.append("CO2-Sensor 01");
        raw_co2_2.append("CO2-Sensor 02");
        raw_ph_1.append("pH-Sensor 01");
        raw_ph_2.append("pH-Sensor 01");
    }
}

void MainWindow::setupSensors()
{
    list_of_ports.append(&port_0);
    list_of_ports.append(&port_1);
    list_of_ports.append(&port_2);
    list_of_ports.append(&port_3);
    list_of_ports.append(&port_4);
    list_of_ports.append(&port_5);


    QString turn_off_sensors = "mode0001\r";
    QByteArray out = turn_off_sensors.toLatin1();

    // setup ports to output mode 0001 -> sending only on request ("data<CR>")
    qDebug() << "port 0 is on this one: " << port_0_system_location;
    port_0.setPortName(port_0_system_location);
    qDebug() << " portname set to: " << port_0.portName();
    port_0.open(QSerialPort::ReadWrite);
     qDebug() << "first open sets open:" << port_0.isOpen();
    port_0.setBaudRate(QSerialPort::Baud19200);     // default for presens EOM
    qDebug() << "baud set to 19200";
    port_0.setDataBits(QSerialPort::Data8);         // default for presens EOM
    qDebug() << "Data8 set";
    port_0.setFlowControl(QSerialPort::NoFlowControl);  // default for presens EOM
    qDebug() << "noFlow Contr set";
    port_0.setParity(QSerialPort::NoParity);            // default for presens EOM
    qDebug() << "no parity set";
    port_0.setStopBits(QSerialPort::OneStop);           // default for presens EOM
    qDebug() << "onestop set";

    port_0.open(QSerialPort::ReadWrite);
    qDebug() << "is the port really open?" << port_0.isOpen();
    port_0.write(out);
    qDebug() << out;
    qDebug() << "port_0 in mode 0001";
    qDebug() << "------------------------------------------------------------------";
    qDebug() << "is closed: " << port_0.isOpen();

    // port 1
    qDebug() << "port 1 is on this one: " << port_1_system_location;
    port_1.setPortName(port_1_system_location);
    qDebug() << " portname set";
    port_1.open(QSerialPort::ReadWrite);
    qDebug() << "open, set to ReadWrite";
    port_1.setBaudRate(QSerialPort::Baud19200);     // default for presens EOM
    qDebug() << "baud set to 19200";
    port_1.setDataBits(QSerialPort::Data8);         // default for presens EOM
    qDebug() << "Data8 set";
    port_1.setFlowControl(QSerialPort::NoFlowControl);  // default for presens EOM
    qDebug() << "noFlow Contr set";
    port_1.setParity(QSerialPort::NoParity);            // default for presens EOM
    qDebug() << "no parity set";
    port_1.setStopBits(QSerialPort::OneStop);           // default for presens EOM
    qDebug() << "onestop set";
    port_1.open(QSerialPort::ReadWrite);
    qDebug() << "is port_1 open?" << port_1.isOpen();
    port_1.write(out);
    qDebug() << "port_1 in mode 0001";
    qDebug() << "------------------------------------------------------------------";

    qDebug() << "is closed: " << port_1.isOpen();

    // port 2
    qDebug() << "port 2 is on this one: " << port_2_system_location;
    port_2.setPortName(port_2_system_location);
    qDebug() << " portname set";
    port_2.open(QSerialPort::ReadWrite);
    qDebug() << "open, set to ReadWrite";
    port_2.setBaudRate(QSerialPort::Baud19200);     // default for presens EOM
    qDebug() << "baud set to 29200";
    port_2.setDataBits(QSerialPort::Data8);         // default for presens EOM
    qDebug() << "Data8 set";
    port_2.setFlowControl(QSerialPort::NoFlowControl);  // default for presens EOM
    qDebug() << "noFlow Contr set";
    port_2.setParity(QSerialPort::NoParity);            // default for presens EOM
    qDebug() << "no parity set";
    port_2.setStopBits(QSerialPort::OneStop);           // default for presens EOM
    qDebug() << "onestop set";
    port_2.open(QSerialPort::ReadWrite);
    qDebug() << "is port_2 open?" << port_2.isOpen();
    port_2.write(out);
    qDebug() << "port_2 in mode 0002";
    qDebug() << "------------------------------------------------------------------";

    qDebug() << "is closed: " << port_2.isOpen();

    // port 3
    qDebug() << "port 3 is on this one: " << port_3_system_location;
    port_3.setPortName(port_3_system_location);
    qDebug() << " portname set";
    port_3.open(QSerialPort::ReadWrite);
    qDebug() << "open, set to ReadWrite";
    port_3.setBaudRate(QSerialPort::Baud19200);     // default for presens EOM
    qDebug() << "baud set to 19200";
    port_3.setDataBits(QSerialPort::Data8);         // default for presens EOM
    qDebug() << "Data8 set";
    port_3.setFlowControl(QSerialPort::NoFlowControl);  // default for presens EOM
    qDebug() << "noFlow Contr set";
    port_3.setParity(QSerialPort::NoParity);            // default for presens EOM
    qDebug() << "no parity set";
    port_3.setStopBits(QSerialPort::OneStop);           // default for presens EOM
    qDebug() << "onestop set";
    port_3.open(QSerialPort::ReadWrite);
    qDebug() << "is port_3 open?" << port_3.isOpen();
    port_3.write(out);
    qDebug() << "port_3 in mode 0001";
    qDebug() << "------------------------------------------------------------------";

    qDebug() << "is closed: " << port_3.isOpen();

    // port 4
    qDebug() << "port 4 is on this one: " << port_4_system_location;
    port_4.setPortName(port_4_system_location);
    qDebug() << " portname set";
    port_4.open(QSerialPort::ReadWrite);
    qDebug() << "open, set to ReadWrite";
    port_4.setBaudRate(QSerialPort::Baud19200);     // default for presens EOM
    qDebug() << "baud set to 19200";
    port_4.setDataBits(QSerialPort::Data8);         // default for presens EOM
    qDebug() << "Data8 set";
    port_4.setFlowControl(QSerialPort::NoFlowControl);  // default for presens EOM
    qDebug() << "noFlow Contr set";
    port_4.setParity(QSerialPort::NoParity);            // default for presens EOM
    qDebug() << "no parity set";
    port_4.setStopBits(QSerialPort::OneStop);           // default for presens EOM
    qDebug() << "onestop set";
    port_4.open(QSerialPort::ReadWrite);
    qDebug() << "is port_4 open?" << port_4.isOpen();
    port_4.write(out);
    qDebug() << "port_4 in mode 0001";
    qDebug() << "------------------------------------------------------------------";

    qDebug() << "true -> open; false -> closed: " << port_4.isOpen();

    // port 5
    qDebug() << "port 5 is on this one: " << port_5_system_location;
    port_5.setPortName(port_5_system_location);
    qDebug() << " portname set";
    port_5.open(QSerialPort::ReadWrite);
    qDebug() << "open, set to ReadWrite";
    port_5.setBaudRate(QSerialPort::Baud19200);     // default for presens EOM
    qDebug() << "baud set to 19200";
    port_5.setDataBits(QSerialPort::Data8);         // default for presens EOM
    qDebug() << "Data8 set";
    port_5.setFlowControl(QSerialPort::NoFlowControl);  // default for presens EOM
    qDebug() << "noFlow Contr set";
    port_5.setParity(QSerialPort::NoParity);            // default for presens EOM
    qDebug() << "no parity set";
    port_5.setStopBits(QSerialPort::OneStop);           // default for presens EOM
    qDebug() << "onestop set";
    port_5.open(QSerialPort::ReadWrite);
    qDebug() << "is port_5 open?" << port_5.isOpen();
    port_5.write(out);
    qDebug() << "port_5 in mode 0001";
    qDebug() << "------------------------------------------------------------------";
    qDebug() << "is closed: " << port_5.isOpen();

}

void MainWindow::setHardwareAddressToId()
{
    QString send_data = "data\r";
    QByteArray data_out = send_data.toLatin1();

    QString send_stopp = "mode0001\r";
    QByteArray stopp_out = send_stopp.toLatin1();


    //find if the ports are on the "correct" hardware adress
    QObject::connect(&port_0, &QSerialPort::readyRead, this, &MainWindow::getHwAdddress_port_0);
    QObject::connect(&port_1, &QSerialPort::readyRead, this, &MainWindow::getHwAdddress_port_1);
    QObject::connect(&port_2, &QSerialPort::readyRead, this, &MainWindow::getHwAdddress_port_2);
    QObject::connect(&port_3, &QSerialPort::readyRead, this, &MainWindow::getHwAdddress_port_3);
    QObject::connect(&port_4, &QSerialPort::readyRead, this, &MainWindow::getHwAdddress_port_4);
    QObject::connect(&port_5, &QSerialPort::readyRead, this, &MainWindow::getHwAdddress_port_5);

    delay(1);

    port_0.write(data_out);
    port_1.write(data_out);
    port_2.write(data_out);
    port_3.write(data_out);
    port_4.write(data_out);
    port_5.write(data_out);

    // delay for 2 seconds to make sure the siganls are received and int port_index[] is filled.
    delay(3);
    qDebug() << "delay for 1 sec!";

    serial_input_port_0 = port_0.readAll();
    input_buffer_port_0 += QString::fromStdString(serial_input_port_0.toStdString());
    qDebug() << "neu rausgeholt:" << input_buffer_port_0;
    QString add_0 = input_buffer_port_0.mid(2,1);
    int hw_id_0 = add_0.toInt();
    qDebug() << "neu rausgeholt:" << hw_id_0;
    port_index[0] = hw_id_0;

    serial_input_port_1 = port_1.readAll();
    input_buffer_port_1 += QString::fromStdString(serial_input_port_1.toStdString());
    qDebug() << "neu rausgeholt:" << input_buffer_port_1;
    QString add_1 = input_buffer_port_1.mid(2,1);
    int hw_id_1 = add_1.toInt();
    qDebug() << "neu rausgeholt:" << hw_id_1;
    port_index[1] = hw_id_1;

    serial_input_port_2 = port_2.readAll();
    input_buffer_port_2 += QString::fromStdString(serial_input_port_2.toStdString());
    qDebug() << "neu rausgeholt:" << input_buffer_port_2;
    QString add_2 = input_buffer_port_2.mid(2,1);
    int hw_id_2 = add_2.toInt();
    qDebug() << "neu rausgeholt:" << hw_id_2;
    port_index[2] = hw_id_2;

    serial_input_port_3 = port_3.readAll();
    input_buffer_port_3 += QString::fromStdString(serial_input_port_3.toStdString());
    qDebug() << "neu rausgeholt:" << input_buffer_port_3;
    QString add_3 = input_buffer_port_3.mid(2,1);
    int hw_id_3 = add_3.toInt();
    qDebug() << "neu rausgeholt:" << hw_id_3;
    port_index[3] = hw_id_3;

    serial_input_port_4 = port_4.readAll();
    input_buffer_port_4 += QString::fromStdString(serial_input_port_4.toStdString());
    qDebug() << "neu rausgeholt:" << input_buffer_port_4;
    QString add_4 = input_buffer_port_4.mid(2,1);
    int hw_id_4 = add_4.toInt();
    qDebug() << "neu rausgeholt:" << hw_id_4;
    port_index[4] = hw_id_4;

    serial_input_port_5 = port_5.readAll();
    input_buffer_port_5 += QString::fromStdString(serial_input_port_5.toStdString());
    qDebug() << "neu rausgeholt:" << input_buffer_port_5;
    QString add_5 = input_buffer_port_5.mid(2,1);
    int hw_id_5 = add_5.toInt();
    qDebug() << "neu rausgeholt:" << hw_id_5;
    port_index[5] = hw_id_5;

    QString x = QString::number(port_index[0]);
    QString y = QString::number(port_index[1]);
    QString z = QString::number(port_index[2]);
    QString a = QString::number(port_index[3]);
    QString b = QString::number(port_index[4]);
    QString c = QString::number(port_index[5]);

    qDebug() << "port index_port_0:" << x;
    qDebug() << "port index_port_1:" << y;
    qDebug() << "port index_port_2:" << z;
    qDebug() << "port index_port_3:" << a;
    qDebug() << "port index_port_4:" << b;
    qDebug() << "port index_port_5:" << c;

    QObject::disconnect(&port_0, &QSerialPort::readyRead, this, &MainWindow::getHwAdddress_port_0);
    QObject::disconnect(&port_1, &QSerialPort::readyRead, this, &MainWindow::getHwAdddress_port_1);
    QObject::disconnect(&port_2, &QSerialPort::readyRead, this, &MainWindow::getHwAdddress_port_2);
    QObject::disconnect(&port_3, &QSerialPort::readyRead, this, &MainWindow::getHwAdddress_port_3);
    QObject::disconnect(&port_4, &QSerialPort::readyRead, this, &MainWindow::getHwAdddress_port_4);
    QObject::disconnect(&port_5, &QSerialPort::readyRead, this, &MainWindow::getHwAdddress_port_5);

//    setCorrectHarwareAddress_port_0(port_index);
//    setCorrectHarwareAddress_port_1(port_index);
//    setCorrectHarwareAddress_port_2(port_index);
//    setCorrectHarwareAddress_port_3(port_index);
//    setCorrectHarwareAddress_port_4(port_index);
//    setCorrectHarwareAddress_port_5(port_index);

    port_0.write(stopp_out);
    port_1.write(stopp_out);
    port_2.write(stopp_out);
    port_3.write(stopp_out);
    port_4.write(stopp_out);
    port_5.write(stopp_out);
}


void MainWindow::getHwAdddress_port_0()
{
    //qDebug() << "trying to get hardware id ('NOx') from port_0";
    QString x = ";";
    if(!input_buffer_port_0.contains(x)){
        serial_input_port_0 = port_0.readAll();
        input_buffer_port_0 += QString::fromStdString(serial_input_port_0.toStdString());
        //qDebug() << input_buffer_port_0;
        //int hw_id_0 = input_buffer_port_0.mid(2,1).toInt();
        //qDebug() << hw_id_0;
    } else {
        //QString address = QString::fromStdString(input_buffer_port_0::toStdString()).mid(2,1);
        //int hw_id_0 = address.toInt();
        int hw_id_0 = input_buffer_port_0.mid(2,1).toInt();
        qDebug() << "i got this integer as hardware-id of port_0:" << hw_id_0;
        port_index[0] = hw_id_0;

    }
}

void MainWindow::getHwAdddress_port_1()
{
    QString x = ";";
    if(!input_buffer_port_1.contains(x)){
        serial_input_port_1 = port_1.readAll();
        input_buffer_port_1 += QString::fromStdString(serial_input_port_1.toStdString());
    }else {
        QString address = QString::fromStdString(serial_input_port_1.toStdString()).mid(2,1);
        int hw_id_1 = address.toInt();

        //int hw_id_1 = input_buffer_port_1.mid(2,3).toInt();
        qDebug() << "i got this integer as hardware-id of port_1:" << hw_id_1;
        port_index[1] = hw_id_1;
    }
}
void MainWindow::getHwAdddress_port_2()
{
    QString x = ",";
    if(!input_buffer_port_2.contains(x)){
        serial_input_port_2 = port_2.readAll();
        input_buffer_port_2 += QString::fromStdString(serial_input_port_2.toStdString());
    }else {
        //QString address = QString::fromStdString(input_buffer_port_2::toStdString()).mid(2,1);
        //int hw_id_2 = address.toInt();

        int hw_id_2 = input_buffer_port_2.mid(2,1).toInt();
        qDebug() << "i got this integer as hardware-id of port_2:" << hw_id_2;
        port_index[2] = hw_id_2;
    }
}
void MainWindow::getHwAdddress_port_3()
{
    if(!input_buffer_port_3.contains(",")){
        serial_input_port_3 = port_3.readAll();
        input_buffer_port_3 += QString::fromStdString(serial_input_port_3.toStdString());
    }else {
        //QString address = QString::fromStdString(input_buffer_port_3::toStdString()).mid(2,1);
        //int hw_id_3_2 = address.toInt();

        int hw_id_3 = input_buffer_port_3.mid(2,1).toInt();
        qDebug() << "i got this integer as hardware-id of port_3:" << hw_id_3;
        port_index[3] = hw_id_3;
    }
}
void MainWindow::getHwAdddress_port_4()
{
    if(!input_buffer_port_4.contains(",")){
        serial_input_port_4 = port_4.readAll();
        input_buffer_port_4 += QString::fromStdString(serial_input_port_4.toStdString());
    }else {
        //QString address = QString::fromStdString(input_buffer_port_4::toStdString()).mid(2,1);
        //int hw_id_4_2 = address.toInt();

        int hw_id_4 = input_buffer_port_4.mid(2,1).toInt();
        qDebug() << "i got this integer as hardware-id of port_4:" << hw_id_4;
        port_index[4] = hw_id_4;
    }
}
void MainWindow::getHwAdddress_port_5()
{
    if(!input_buffer_port_5.contains(",")){
        serial_input_port_5 = port_5.readAll();
        input_buffer_port_5 += QString::fromStdString(serial_input_port_5.toStdString());
    }else {
        //QString address = QString::fromStdString(input_buffer_port_5::toStdString()).mid(2,1);
        //int hw_id_5_2 = address.toInt();

        int hw_id_5 = input_buffer_port_5.mid(2,1).toInt();
        qDebug() << "i got this integer as hardware-id of port_5:" << hw_id_5;
        port_index[5] = hw_id_5;
    }
}

void MainWindow::setCorrectHarwareAddress_port_0(int arr[6])
{
    switch(arr[0]){
    case 1:
        qDebug() << "old hw address of port_2: " << port_3.portName();
        port_3.setPortName(port_0.portName());
        qDebug() << "reset port_3 hw address to :" << port_3.portName();
        break;
    case 2 :
        qDebug() << "old hw address of port_2: " << port_5.portName();
        port_5.setPortName(port_0.portName());
        qDebug() << "reset port_5 hw address to :" << port_5.portName();
        break;
    case 3 :
        qDebug() << "old hw address of port_2: " << port_4.portName();
        port_3.setPortName(port_0.portName());
        qDebug() << "reset port_4 hw address to :" << port_4.portName();
        break;
    case 4 :
        qDebug() << "old hw address of port_2: " << port_1.portName();
        port_1.setPortName(port_0.portName());
        qDebug() << "reset port_1 hw address to :" << port_1.portName();
        break;
    case 5 :
        break;
    case 6 :
        qDebug() << "old hw address of port_2: " << port_2.portName();
        port_2.setPortName(port_0.portName());
        qDebug() << "reset port_2 hw address to :" << port_2.portName();
        break;
    }

}

void MainWindow::setCorrectHarwareAddress_port_1(int arr[6])
{
    switch(arr[0]){
    case 1:
        qDebug() << "old hw address of port_2: " << port_3.portName();
        port_3.setPortName(port_0.portName());
        qDebug() << "reset port_3 hw address to :" << port_3.portName();
        break;
    case 2 :
        qDebug() << "old hw address of port_2: " << port_5.portName();
        port_5.setPortName(port_0.portName());
        qDebug() << "reset port_5 hw address to :" << port_5.portName();
        break;
    case 3 :
        qDebug() << "old hw address of port_2: " << port_4.portName();
        port_3.setPortName(port_0.portName());
        qDebug() << "reset port_4 hw address to :" << port_4.portName();
        break;
    case 4 :
        qDebug() << "old hw address of port_2: " << port_1.portName();
        port_1.setPortName(port_0.portName());
        qDebug() << "reset port_1 hw address to :" << port_1.portName();
        break;
    case 5 :
        break;
    case 6 :
        qDebug() << "old hw address of port_2: " << port_2.portName();
        port_2.setPortName(port_0.portName());
        qDebug() << "reset port_2 hw address to :" << port_2.portName();
        break;
    }

}
void MainWindow::setCorrectHarwareAddress_port_2(int arr[6])
{
    switch(arr[0]){
    case 1:
        qDebug() << "old hw address of port_2: " << port_3.portName();
        port_3.setPortName(port_0.portName());
        qDebug() << "reset port_3 hw address to :" << port_3.portName();
        break;
    case 2 :
        qDebug() << "old hw address of port_2: " << port_5.portName();
        port_5.setPortName(port_0.portName());
        qDebug() << "reset port_5 hw address to :" << port_5.portName();
        break;
    case 3 :
        qDebug() << "old hw address of port_2: " << port_4.portName();
        port_3.setPortName(port_0.portName());
        qDebug() << "reset port_4 hw address to :" << port_4.portName();
        break;
    case 4 :
        qDebug() << "old hw address of port_2: " << port_1.portName();
        port_1.setPortName(port_0.portName());
        qDebug() << "reset port_1 hw address to :" << port_1.portName();
        break;
    case 5 :
        break;
    case 6 :
        qDebug() << "old hw address of port_2: " << port_2.portName();
        port_2.setPortName(port_0.portName());
        qDebug() << "reset port_2 hw address to :" << port_2.portName();
        break;
    }

}
void MainWindow::setCorrectHarwareAddress_port_3(int arr[6])
{
    switch(arr[0]){
    case 1:
        qDebug() << "old hw address of port_2: " << port_3.portName();
        port_3.setPortName(port_0.portName());
        qDebug() << "reset port_3 hw address to :" << port_3.portName();
        break;
    case 2 :
        qDebug() << "old hw address of port_2: " << port_5.portName();
        port_5.setPortName(port_0.portName());
        qDebug() << "reset port_5 hw address to :" << port_5.portName();
        break;
    case 3 :
        qDebug() << "old hw address of port_2: " << port_4.portName();
        port_3.setPortName(port_0.portName());
        qDebug() << "reset port_4 hw address to :" << port_4.portName();
        break;
    case 4 :
        qDebug() << "old hw address of port_2: " << port_1.portName();
        port_1.setPortName(port_0.portName());
        qDebug() << "reset port_1 hw address to :" << port_1.portName();
        break;
    case 5 :
        break;
    case 6 :
        qDebug() << "old hw address of port_2: " << port_2.portName();
        port_2.setPortName(port_0.portName());
        qDebug() << "reset port_2 hw address to :" << port_2.portName();
        break;
    }

}
void MainWindow::setCorrectHarwareAddress_port_4(int arr[6])
{
    switch(arr[0]){
    case 1:
        qDebug() << "old hw address of port_2: " << port_3.portName();
        port_3.setPortName(port_0.portName());
        qDebug() << "reset port_3 hw address to :" << port_3.portName();
        break;
    case 2 :
        qDebug() << "old hw address of port_2: " << port_5.portName();
        port_5.setPortName(port_0.portName());
        qDebug() << "reset port_5 hw address to :" << port_5.portName();
        break;
    case 3 :
        qDebug() << "old hw address of port_2: " << port_4.portName();
        port_3.setPortName(port_0.portName());
        qDebug() << "reset port_4 hw address to :" << port_4.portName();
        break;
    case 4 :
        qDebug() << "old hw address of port_2: " << port_1.portName();
        port_1.setPortName(port_0.portName());
        qDebug() << "reset port_1 hw address to :" << port_1.portName();
        break;
    case 5 :
        break;
    case 6 :
        qDebug() << "old hw address of port_2: " << port_2.portName();
        port_2.setPortName(port_0.portName());
        qDebug() << "reset port_2 hw address to :" << port_2.portName();
        break;
    }

}void MainWindow::setCorrectHarwareAddress_port_5(int arr[6])
{
    switch(arr[0]){
    case 1:
        qDebug() << "old hw address of port_2: " << port_3.portName();
        port_3.setPortName(port_0.portName());
        qDebug() << "reset port_3 hw address to :" << port_3.portName();
        break;
    case 2 :
        qDebug() << "old hw address of port_2: " << port_5.portName();
        port_5.setPortName(port_0.portName());
        qDebug() << "reset port_5 hw address to :" << port_5.portName();
        break;
    case 3 :
        qDebug() << "old hw address of port_2: " << port_4.portName();
        port_3.setPortName(port_0.portName());
        qDebug() << "reset port_4 hw address to :" << port_4.portName();
        break;
    case 4 :
        qDebug() << "old hw address of port_2: " << port_1.portName();
        port_1.setPortName(port_0.portName());
        qDebug() << "reset port_1 hw address to :" << port_1.portName();
        break;
    case 5 :
        break;
    case 6 :
        qDebug() << "old hw address of port_2: " << port_2.portName();
        port_2.setPortName(port_0.portName());
        qDebug() << "reset port_2 hw address to :" << port_2.portName();
        break;
    }

}

void MainWindow::setPreInit()
{
    // show correct tab, disable rest for now
    ui->tabWidget_2->setCurrentIndex(0);
    for(int i = 1; i < 4; i++){ui->tabWidget_2->setTabEnabled(i, false);}

    //show start tab
    ui->tabWidget->setCurrentIndex(1);
    //disable all tabs except start tab
    ui->tabWidget->setTabEnabled(0, false);
    for(int i = 2; i < 6; i++){ ui->tabWidget->setTabEnabled(i, false);}

    // only sensors chosen in dialog will be enabled
    ui->initialize_sensor_0_button->setDisabled(true);
    ui->initialize_sensor_1_button->setDisabled(true);
    ui->initialize_sensor_2_button->setDisabled(true);
    ui->initialize_sensor_3_button->setDisabled(true);
    ui->initialize_sensor_4_button->setDisabled(true);
    ui->initialize_sensor_5_button->setDisabled(true);
}


/******************************************************************************************************
 *
 * with these functions the initial vote on which sensors are active for a new meassurement are handled
 *
 *****************************************************************************************************/
void MainWindow::startDialog()
{
    Dialog * activation = new Dialog();

    QObject::connect(activation, &Dialog::checkBox_0_toggled, this, &MainWindow::setActiveSensor0);
    QObject::connect(activation, &Dialog::checkBox_1_toggled, this, &MainWindow::setActiveSensor1);
    QObject::connect(activation, &Dialog::checkBox_2_toggled, this, &MainWindow::setActiveSensor2);
    QObject::connect(activation, &Dialog::checkBox_3_toggled, this, &MainWindow::setActiveSensor3);
    QObject::connect(activation, &Dialog::checkBox_4_toggled, this, &MainWindow::setActiveSensor4);
    QObject::connect(activation, &Dialog::checkBox_5_toggled, this, &MainWindow::setActiveSensor5);
    activation->setWindowFlags(Qt::WindowStaysOnTopHint);
    //   activation->setWindowState(Qt::WindowFullScreen);
    activation->show();

}

// on activation, set buttons enabled accordingly
void MainWindow::setActiveSensor0(bool checked)
{
    activatedSensor_0 = checked;
    ui->initialize_sensor_0_button->setDisabled(!activatedSensor_0);
    //ui->sensor_1_init_label->setStyleSheet("QLabel { background-color : green}");
}

void MainWindow::setActiveSensor1(bool checked)
{
    activatedSensor_1 = checked;
    ui->initialize_sensor_1_button->setDisabled(!activatedSensor_1);
}

void MainWindow::setActiveSensor2(bool checked)
{
    activatedSensor_2 = checked;
    ui->initialize_sensor_2_button->setDisabled(!activatedSensor_2);
}

void MainWindow::setActiveSensor3(bool checked)
{
    activatedSensor_3 = checked;
    ui->initialize_sensor_3_button->setDisabled(!activatedSensor_3);
}

void MainWindow::setActiveSensor4(bool checked)
{
    activatedSensor_4 = checked;
    ui->initialize_sensor_4_button->setDisabled(!activatedSensor_4);
}

void MainWindow::setActiveSensor5(bool checked)
{
    activatedSensor_5 = checked;
    ui->initialize_sensor_5_button->setDisabled(!activatedSensor_5);
}

/**************************************************************************
 *
 * with init-buttons pressed change tabs to respective initialisation form
 *
 **************************************************************************/

void MainWindow::on_initialize_sensor_0_button_clicked()
{
    sensor_0_is_available = true;
    ui->allSet_o2->setEnabled(false);
    ui->tabWidget_2->setTabEnabled(1, true);
    ui->tabWidget_2->setTabEnabled(0, false);
    ui->tabWidget_2->setCurrentIndex(1);
}

void MainWindow::on_initialize_sensor_1_button_clicked()
{
    sensor_1_is_available = true;
    qDebug() << "initialise_ sensor_1: " <<sensor_1_is_available;
    ui->allSet_o2->setEnabled(false);
    ui->tabWidget_2->setTabEnabled(1, true);
    ui->tabWidget_2->setTabEnabled(0, false);
    ui->tabWidget_2->setCurrentIndex(1);
}

void MainWindow::on_initialize_sensor_2_button_clicked()
{
    sensor_2_is_available = true;
    ui->allSet_pH->setEnabled(false);
    ui->tabWidget_2->setTabEnabled(3, true);
    ui->tabWidget_2->setTabEnabled(0, false);
    ui->tabWidget_2->setCurrentIndex(3);
}

void MainWindow::on_initialize_sensor_3_button_clicked()
{
    sensor_3_is_available = true;
    ui->allSet_pH->setEnabled(false);
    ui->tabWidget_2->setTabEnabled(3, true);
    ui->tabWidget_2->setTabEnabled(0, false);
    ui->tabWidget_2->setCurrentIndex(3);
}

void MainWindow::on_initialize_sensor_4_button_clicked()
{
    sensor_4_is_available = true;
    ui->allSet_cO2->setEnabled(false);
    ui->tabWidget_2->setTabEnabled(2, true);
    ui->tabWidget_2->setTabEnabled(0, false);
    ui->tabWidget_2->setCurrentIndex(2);
}

void MainWindow::on_initialize_sensor_5_button_clicked()
{
    sensor_5_is_available = true;
    ui->allSet_cO2->setEnabled(false);
    ui->tabWidget_2->setTabEnabled(2, true);
    ui->tabWidget_2->setTabEnabled(0, false);
    ui->tabWidget_2->setCurrentIndex(2);
}
/**************************************************************************
 *
 * handling user input for initialisation of O2-sensors
 *
 **************************************************************************/

/***
 * getting user inputand transforming to output readable by sensor
 * building output string with eight digits for positive values and seven digits with leading "-"
 * for negative values
 * decimal point is at 5 digits from the right
 * output must be in this format: "scfoXXXXXXXX\r" example: scfo00080700 sets to f1 =  0.807 for positive numbers
 * output must be in this format: "scfo-XXXXXXX\r" example: scfo-0080700 sets to f1 = -0.807 for negative numbers
 ***/
void MainWindow::on_set_f1_button_clicked()
{
    int padUpTo = 8;        // eight digits for values > 0
    double f1 = QInputDialog::getDouble(this,
                                         "Sensorkonstante f1",
                                         "Wert eingeben:",
                                         0.808, -99.99999, 999.99999, 5);
    ui->f1_textbrowser->clear();
    ui->f1_textbrowser->append(QString::number(f1, 'f', 5));

    QString prepend = "";
    if (f1 < 0){
        prepend = "scfo-";
        padUpTo = 7;        // change to seven digits for values < 0
    }else{
        prepend = "scfo";
    }

    qDebug() << "f1: " << f1;
    qDebug() << "f1-string formatting: " << QString::number(f1, 'f');

    // build string QString::number(numeral, output format 'f' for NOT sientific, precision)
    QString f1_to_sensor = prepend + QString::number(f1, 'f', 5).remove('-').remove('.').rightJustified(padUpTo, '0') + "\r";
    QByteArray out = f1_to_sensor.toLatin1();

    qDebug() << "f1_to_sensor: " << f1_to_sensor;

    if(sensor_0_is_available){
        port_3.write(out);
        qDebug() << "send to port_3" << port_3.write(out);
        f1_1 = true;
    }else if(sensor_1_is_available){
        port_5.write(out);
        qDebug() << "send to port_5" << port_5.write(out);
        f1_2 = true;
    }

    if(f1_1 && m_1 && dPhi1_1 && dPhi2_1 && dKSV1_1 && dKSV2_1){
        ui->allSet_o2->setEnabled(true);
        port_3_is_initiated = true;
    }
    else if (f1_2 && m_2 && dPhi1_2 && dPhi2_2 && dKSV1_2 && dKSV2_2) {
        ui->allSet_o2->setEnabled(true);
        port_5_is_initiated = true;
    }
}

/*
 * decimal point is at three digits from the right
 * output must be in this format: "scfoXXXXXXXX\r" example: scfo00032110 sets to f1 =  32.11 for positive numbers
 * output must be in this format: "scfo-XXXXXXX\r" example: scfo-0032110 sets to f1 = -32.11 for negative numbers
 */
void MainWindow::on_set_m_button_clicked()
{
    int padUpTo = 8;         // eight digits for values > 0
    double m = QInputDialog::getDouble(this,
                                         "Sensorkonstante m",
                                         "Wert eingeben:",
                                         30, -9999.999, 99999.999, 3);
    ui->m_textbrowser->clear();
    ui->m_textbrowser->append(QString::number(m, 'f', 3));

    QString prepend = "";
    if (m < 0){
        prepend = "scmm-";
        padUpTo = 7;        // change to seven digits for values < 0
    }else{
        prepend = "scmm";
    }

    QString m_to_sensor = prepend + QString::number(m, 'f', 3).remove('.').remove('-').rightJustified(padUpTo, '0') + "\r";
    qDebug() << m_to_sensor;
    QByteArray out = m_to_sensor.toLatin1();

    if(sensor_0_is_available){
        port_3.write(out);
        m_1 = true;
    }else if(sensor_1_is_available){
        port_5.write(out);
        m_2 = true;
        qDebug() << "sensor 01: m_2" << m_2;
    }

    if(f1_1 && m_1 && dPhi1_1 && dPhi2_1 && dKSV1_1 && dKSV2_1){
        ui->allSet_o2->setEnabled(true);
        port_3_is_initiated = true;
    }
    else if (f1_2 && m_2 && dPhi1_2 && dPhi2_2 && dKSV1_2 && dKSV2_2) {
        ui->allSet_o2->setEnabled(true);
        port_5_is_initiated = true;
    }

}

/*
 * decimal point is at six digits from the right
 * output must be in this format: "scpoXXXXXXXX\r" example: scpo0061710 sets to dPhi1 =  0.06171 for positive numbers
 * output must be in this format: "scpo-XXXXXXX\r" example: scpo-0061710 sets to dPhi1 = -0.06171 for negative numbers
 */
void MainWindow::on_set_dPhi1_button_clicked()
{
    int padUpTo = 8;         // eight digits for values > 0
    double dPhi1 = QInputDialog::getDouble(this,
                                         "Sensorkonstante dPhi1",
                                         "Wert eingeben:",
                                         -0.068, -9.999999, 99.999999, 6);
    ui->dPhi1_textbrowser->clear();
    ui->dPhi1_textbrowser->append(QString::number(dPhi1, 'f', 6));

    QString prepend = "";
    if (dPhi1 < 0){
        prepend = "scpo-";
        padUpTo = 7;        // change to seven digits for values < 0
    }else{
        prepend = "scpo";
    }

    QString dPhi1_to_sensor = prepend + QString::number(dPhi1, 'f', 6).remove('.').remove('-').rightJustified(padUpTo, '0') + "\r";
    qDebug() << dPhi1_to_sensor;
    QByteArray out = dPhi1_to_sensor.toLatin1();

    if(sensor_0_is_available){
        port_3.write(out);
        dPhi1_1 = true;
    }else if(sensor_1_is_available){
        port_5.write(out);
        dPhi1_2 = true;
        qDebug() << "sensor 01: dPhi1_2" << dPhi1_2;
    }

    if(f1_1 && m_1 && dPhi1_1 && dPhi2_1 && dKSV1_1 && dKSV2_1){
        ui->allSet_o2->setEnabled(true);
        port_3_is_initiated = true;
    }
    else if (f1_2 && m_2 && dPhi1_2 && dPhi2_2 && dKSV1_2 && dKSV2_2) {
        ui->allSet_o2->setEnabled(true);
        port_5_is_initiated = true;
    }

}
/*
 * decimal point is at six digits from the right
 * output must be in this format: "scptXXXXXXXX\r" example: scpt0061710 sets to dPhi2 =  0.06171 for positive numbers
 * output must be in this format: "scpt-XXXXXXX\r" example: scpt-0061710 sets to dPhi2 = -0.06171 for negative numbers
 */
void MainWindow::on_set_dPhi2_button_clicked()
{
    int padUpTo = 8;         // eight digits for values > 0
    double dPhi2 = QInputDialog::getDouble(this,
                                         "Sensorkonstante dPhi2",
                                         "Wert eingeben:",
                                         -0.00035, -9.999999, 99.999999, 6);
    qDebug() << dPhi2;

    ui->dPhi2_textbrowser->clear();
    ui->dPhi2_textbrowser->append(QString::number(dPhi2, 'f', 6));

    QString prepend = "";
    if (dPhi2 < 0){
        prepend = "scpt-";
        padUpTo = 7;        // change to seven digits for values < 0
    }else{
        prepend = "scpt";
    }

    QString dPhi2_to_sensor = prepend + QString::number(dPhi2, 'f', 6).remove('.').remove('-').rightJustified(padUpTo, '0') + "\r";
    qDebug() << dPhi2_to_sensor;
    QByteArray out = dPhi2_to_sensor.toLatin1();


    if(sensor_0_is_available){
        port_3.write(out);
        dPhi2_1 = true;
    }else if(sensor_1_is_available){
        port_5.write(out);
        dPhi2_2 = true;
        qDebug() << "sensor 01: dPhi2_2" << dPhi2_2;
    }

    if(f1_1 && m_1 && dPhi1_1 && dPhi2_1 && dKSV1_1 && dKSV2_1){
        ui->allSet_o2->setEnabled(true);
        port_3_is_initiated = true;
    }
    else if (f1_2 && m_2 && dPhi1_2 && dPhi2_2 && dKSV1_2 && dKSV2_2) {
        ui->allSet_o2->setEnabled(true);
        port_5_is_initiated = true;
    }


}
/*
 * decimal point is at six digits from the right
 * output must be in this format: "scksXXXXXXXX\r" example: scks00000486 sets to dKSV1 =  0.000486 for positive numbers
 * output must be in this format: "scks-XXXXXXX\r" example: scks-0000486 sets to dKSV1 = -0.000486 for negative numbers
 */
void MainWindow::on_set_dKSV1_button_clicked()
{
    int padUpTo = 8;         // eight digits for values > 0
    double dKSV1 = QInputDialog::getDouble(this,
                                         "Sensorkonstante dKSV1",
                                         "Wert eingeben:",
                                         0.000371, -9.999999, 99.999999, 6);

    qDebug() << dKSV1 << "parse QString: " << QString::number(dKSV1, 'f', 6);

    ui->dKSV1_textbrowser->clear();
    ui->dKSV1_textbrowser->append(QString::number(dKSV1,'f', 6));

    QString prepend = "";
    if (dKSV1 < 0){
        prepend = "scks-";
        padUpTo = 7;        // change to seven digits for values < 0
    }else{
        prepend = "scks";
    }

    QString dKSV1_to_sensor = prepend + QString::number(dKSV1, 'f', 6).remove('.').remove('-').rightJustified(padUpTo, '0') + "\r";
    qDebug() << dKSV1_to_sensor;
    QByteArray out = dKSV1_to_sensor.toLatin1();

    if(sensor_0_is_available){
        port_3.write(out);
        dKSV1_1 = true;
    }else if(sensor_1_is_available){
        port_5.write(out);
        dKSV1_2 = true;
            qDebug() << "sensor 01: dKSV1_2" << dKSV1_2;
    }

    // all values set?
    if(f1_1 && m_1 && dPhi1_1 && dPhi2_1 && dKSV1_1 && dKSV2_1){
        ui->allSet_o2->setEnabled(true);
        port_3_is_initiated = true;
    }
    else if (f1_2 && m_2 && dPhi1_2 && dPhi2_2 && dKSV1_2 && dKSV2_2) {
        ui->allSet_o2->setEnabled(true);
        port_5_is_initiated = true;
    }

}

/*
 * decimal point is at six digits from the right
 * output must be in this format: "sckvXXXXXXXX\r" example: sckv00000486 sets to dKSV2 =  0.000486 for positive numbers
 * output must be in this format: "sckv-XXXXXXX\r" example: sckv-0000486 sets to dKSV2 = -0.000486 for negative numbers
 */
void MainWindow::on_set_dKSV2_button_clicked()
{
    int padUpTo = 8;        // eight digits for values > 0
    double dKSV2 = QInputDialog::getDouble(this,
                                         "Sensorkonstante dKSV2",
                                         "Wert eingeben:",
                                         0, -9.999999, 99.999999, 6);
    ui->dKSV2_textbrowser->clear();
    ui->dKSV2_textbrowser->append(QString::number(dKSV2, 'f', 6));

    QString prepend = "";
    if (dKSV2 < 0){
        prepend = "sckv-";
        padUpTo = 7;        // change to seven digits for values < 0
    }else{
        prepend = "sckv";
    }

    QString dKSV2_to_sensor = prepend + QString::number(dKSV2, 'f', 6).remove('.').remove('-').rightJustified(padUpTo, '0') + "\r";
    qDebug() << dKSV2_to_sensor;
    QByteArray out = dKSV2_to_sensor.toLatin1();


    if(sensor_0_is_available){
        port_3.write(out);
        dKSV2_1 = true;
    }else if(sensor_1_is_available){
        port_5.write(out);
        dKSV2_2 = true;
                qDebug() << "sensor 01: dKSV2_2" << dKSV2_2;
    }

    // all values set?
    if(f1_1 && m_1 && dPhi1_1 && dPhi2_1 && dKSV1_1 && dKSV2_1){
        ui->allSet_o2->setEnabled(true);
        port_3_is_initiated = true;
    }
    else if (f1_2 && m_2 && dPhi1_2 && dPhi2_2 && dKSV1_2 && dKSV2_2) {
        ui->allSet_o2->setEnabled(true);
        port_5_is_initiated = true;
    }

}


/**************************************************************************
 *
 * once all data for initialisation of o2-sensor is set, th ok button is enabled:
 * on button pressed, mode is set to 0000 -> constant output of values
 * the connects are set and sensor is marked as initialised in the UI
 *
 **************************************************************************/
void MainWindow::on_allSet_o2_clicked()
{
    // mode0000 -> send constant output from sensor
    QString mode_set = "mode0000\r";
    // make string readable by sensor
    QByteArray out = mode_set.toLatin1();
    // actiavte drawing tab for o2
    if(port_3_is_initiated && !sensor_1_is_available){
        port_3.write(out);
        ui->sensor_1_init_label->setStyleSheet("background-color : green");
        ui->sensor_1_init_label->setText("O2-Sensor initialisiert!");
    }
    if(port_5_is_initiated){
        port_5.write(out);
        ui->sensor_2_init_label->setStyleSheet("background-color : green");
        ui->sensor_2_init_label->setText("O2-Sensor initialisiert!");

    }
    // set f1 back to false, or the second sensor will never become initiated
    f1_1 = false; f1_2 = false;

    sensor_0_is_available = false;
    sensor_1_is_available = false;

    ui->tabWidget_2->setTabEnabled(1, false);
    ui->tabWidget_2->setTabEnabled(0, true);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->f1_textbrowser->clear();
    ui->m_textbrowser->clear();
    ui->dPhi1_textbrowser->clear();
    ui->dPhi2_textbrowser->clear();
    ui->dKSV1_textbrowser->clear();
    ui->dKSV2_textbrowser->clear();
}

/**************************************************************************
 *
 * handling user input for initialisation of pH-sensors
 *
 **************************************************************************/

void MainWindow::on_set_lmin_button_clicked()
{
    double lmin = QInputDialog::getDouble(this,
                                         "Sensorkonstante lmin",
                                         "Wert eingeben:",
                                         55.96, 0, 90, 2);
    ui->lmin_textbrowser->clear();
    ui->lmin_textbrowser->append(QString::number(lmin, 'f', 2));

    QString lmin_to_sensor = "kmin" + QString::number(lmin, 'f', 2).remove('.').rightJustified(4, '0') + "\r";
    qDebug() << lmin_to_sensor;
    QByteArray out = lmin_to_sensor.toLatin1();

    if(sensor_2_is_available){
        port_0.write(out);
        lmin_1 = true;
    }else if(sensor_3_is_available){
        port_2.write(out);
        lmin_2 = true;
    }

    // all values set?
    if(lmin_1 && lmax_1 && pH0_1 && dpH_1 && temp_1){
        ui->allSet_pH->setEnabled(true);
        port_0_is_initiated = true;
    }
    else if (lmin_2 && lmax_2 && pH0_2 && dpH_2 && temp_2) {
        ui->allSet_pH->setEnabled(true);
        port_2_is_initiated = true;
    }
}

void MainWindow::on_set_lmax_button_clicked()
{
    double lmax = QInputDialog::getDouble(this,
                                         "Sensorkonstante lmax",
                                         "Wert eingeben:",
                                         21.56, 0, 90, 2);
    ui->lmax_textbrowser->clear();
    ui->lmax_textbrowser->append(QString::number(lmax, 'f', 2));

    QString lmax_to_sensor = "kmax" + QString::number(lmax, 'f', 2).remove('.').rightJustified(4, '0') + "\r";
    qDebug() << lmax_to_sensor;
    QByteArray out = lmax_to_sensor.toLatin1();

    if(sensor_2_is_available){
        port_0.write(out);
        lmax_1 = true;
    }else if(sensor_3_is_available){
        port_2.write(out);
        lmax_2 = true;
    }

    // all values set?
    if(lmin_1 && lmax_1 && pH0_1 && dpH_1 && temp_1){
        ui->allSet_pH->setEnabled(true);
        port_0_is_initiated = true;
    }
    else if (lmin_2 && lmax_2 && pH0_2 && dpH_2 && temp_2) {
        ui->allSet_pH->setEnabled(true);
        port_2_is_initiated = true;
    }
}

void MainWindow::on_set_pH0_button_clicked()
{
    double pH0 = QInputDialog::getDouble(this,
                                         "pH0 eingeben",
                                         "valide Werte: 6.0 - 8.0",
                                         6.54, 0, 50, 2);
    ui->pH0_textbrowser->clear();
    ui->pH0_textbrowser->append(QString::number(pH0, 'f', 2));
    QString pH0_to_sensor = "kpho" + QString::number(pH0, 'f', 2).remove('.').rightJustified(4, '0') + "\r";
    qDebug() << pH0_to_sensor;
    QByteArray out = pH0_to_sensor.toLatin1();

    if(sensor_2_is_available){
        port_0.write(out);
        pH0_1 = true;
    }else if(sensor_3_is_available){
        port_2.write(out);
        pH0_2 = true;
    }

    // all values set?
    if(lmin_1 && lmax_1 && pH0_1 && dpH_1 && temp_1){
        ui->allSet_pH->setEnabled(true);
        port_0_is_initiated = true;
    }
    else if (lmin_2 && lmax_2 && pH0_2 && dpH_2 && temp_2) {
        ui->allSet_pH->setEnabled(true);
        port_2_is_initiated = true;
    }
}
/*
 * decimal point is at two digits from the right
 * output must be in this format: "kdphXXXX\r" example: kdp0059 sets to dph0 =  0.59
 */
void MainWindow::on_set_dpH_button_clicked()
{
    double dpH = QInputDialog::getDouble(this,
                                         "Sensoronstante dpH ",
                                         "Wert eingeben:",
                                         0.51, 0, 10, 2);
    ui->dpH_textbrowser->clear();
    ui->dpH_textbrowser->append(QString::number(dpH,'f', 2));

    QString dpH_to_sensor = "kdph" + QString::number(dpH, 'f', 2).remove('.').rightJustified(4, '0') + "\r";
    qDebug() << dpH_to_sensor;
    QByteArray out = dpH_to_sensor.toLatin1();

    if(sensor_2_is_available){
        port_0.write(out);
        dpH_1 = true;
    }else if(sensor_3_is_available){
        port_2.write(out);
        dpH_2 = true;
    }

    // all values set?
    if(lmin_1 && lmax_1 && pH0_1 && dpH_1 && temp_1){
        ui->allSet_pH->setEnabled(true);
        port_0_is_initiated = true;
    }
    else if (lmin_2 && lmax_2 && pH0_2 && dpH_2 && temp_2) {
        ui->allSet_pH->setEnabled(true);
        port_2_is_initiated = true;
    }
}

void MainWindow::on_set_temp_button_clicked()
{
    int padUpTo = 4;
    double temp = QInputDialog::getDouble(this,
                                         "Sensorkonstante Temp",
                                         "Werte eingeben:",
                                         37, -9.99, 60, 2);
    ui->temp_textbrowser->clear();
    ui->temp_textbrowser->append(QString::number(temp, 'f', 2));

    QString prepend = "";
    if(temp < 0){
        prepend = "ktem-";
        padUpTo = 3;
    }else{
        prepend = "ktem";
    }

    QString temp_to_sensor = prepend + QString::number(temp, 'f', 2).remove('.').remove('-').rightJustified(padUpTo, '0') + "\r";
    qDebug() << temp_to_sensor;
    QByteArray out = temp_to_sensor.toLatin1();

    if(sensor_2_is_available){
        port_0.write(out);
        temp_1 = true;
    }else if (sensor_3_is_available){
        port_2.write(out);
        temp_2 = true;
    }

    // all values set?
    if(lmin_1 && lmax_1 && pH0_1 && dpH_1 && temp_1){
        ui->allSet_pH->setEnabled(true);
        port_0_is_initiated = true;
    }
    else if (lmin_2 && lmax_2 && pH0_2 && dpH_2 && temp_2) {
        ui->allSet_pH->setEnabled(true);
        port_2_is_initiated = true;
    }
}

/**************************************************************************
 *
 * once all data for initialisation of o2-sensor is set, th ok button is enabled:
 * on button pressed, mode is set to 0000 -> constant output of values
 * the connects are set and sensor is marked as initialised in the UI
 *
 **************************************************************************/

void MainWindow::on_allSet_pH_clicked()
{
    QString mode_set = "mode0000\r";
    QByteArray out = mode_set.toLatin1();
    if(port_0_is_initiated && !sensor_3_is_available){
        port_0.open(QSerialPort::ReadWrite);
        port_0.write(out);
        ui->sensor_3_init_label->setStyleSheet("background-color : green");
        ui->sensor_3_init_label->setText("pH-Sensor initialisiert!");
    }
    if(port_2_is_initiated){
        port_2.write(out);
        qDebug() << "connect set for port 2";
        ui->sensor_4_init_label->setStyleSheet("background-color : green");
        ui->sensor_4_init_label->setText("pH-Sensor initialisiert!");

    }
    // set f1 back to false, or the second sensor will never become initiated
    lmin_1 = false; lmin_2 = false;

    sensor_2_is_available = false;
    sensor_3_is_available = false;

    ui->tabWidget_2->setTabEnabled(2, false);
    ui->tabWidget_2->setTabEnabled(3, false);
    ui->tabWidget_2->setTabEnabled(0, true);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->lmin_textbrowser->clear();
    ui->lmax_textbrowser->clear();
    ui->pH0_textbrowser->clear();
    ui->dpH_textbrowser->clear();
    ui->temp_textbrowser->clear();
}

/**************************************************************************
 *
 * handling user input for initialisation of CO2-sensors
 *
 **************************************************************************/

/*
 * decimal point is at six digits from the right
 * output must be in this format: "ctaoXXXXXXXX\r" example: ctao00003900 sets to A1 =  0.003900 for positive numbers
 * output must be in this format: "ctao-XXXXXXX\r" example: ctao-0003900 sets to A1 = -0.003900 for negative numbers
 */
void MainWindow::on_set_A1_button_clicked()
{
    int padUpTo = 8;
    double a1 = QInputDialog::getDouble(this,
                                         "Sensorkonstante A1",
                                         "Wert eingeben:",
                                         8.65, -9.99999, 99.99999, 6);
    ui->A1_textbrowser->clear();
    ui->A1_textbrowser->append(QString::number(a1, 'f', 6));

    QString prepend = "";
    if(a1 < 0){
        prepend = "ctao-";
        padUpTo = 7;
    }else{
        prepend = "ctao";
    }

    QString a1_to_sensor = prepend + QString::number(a1, 'f', 6).remove('.').remove('-').rightJustified(padUpTo,'0') + "\r";
    qDebug() << a1_to_sensor;
    QByteArray out = a1_to_sensor.toLatin1();

    if(sensor_4_is_available){
        port_4.write(out);
        A1_1 = true;
    }else if(sensor_5_is_available){
        port_1.write(out);
        A1_2 = true;
        qDebug() << "sensor 01: A1_2" << A1_2;
    }

    if(A1_1 && A2_1 && x0_1 && dx_1 && temp_co2_1){
        ui->allSet_cO2->setEnabled(true);
        port_4_is_initiated = true;
    }
    else if (A1_2 && A2_2 && x0_2 && dx_2 && temp_co2_2) {
        ui->allSet_cO2->setEnabled(true);
        port_1_is_initiated = true;
    }
}

void MainWindow::on_set_A2_button_clicked()
{
    double a2 = QInputDialog::getDouble(this,
                                         "a2 eingeben",
                                         "valide Werte: -",
                                         56.08, 46, 66, 8);
    ui->A2_textbrowser->clear();
    ui->A2_textbrowser->append(QString::number(a2));
    QString a2_to_sensor = "ctat" + QString::number(a2).remove('.').leftJustified(8, '0') + "\r";
    qDebug() << a2_to_sensor;
    QByteArray out = a2_to_sensor.toLatin1();


    if(sensor_4_is_available){
        port_4.write(out);
        A2_1 = true;
    }else if(sensor_5_is_available){
        port_1.write(out);
        A2_2 = true;
        qDebug() << "sensor 01: a2_2" << A2_2;
    }

    if(A1_1 && A2_1 && x0_1 && dx_1 && temp_co2_1){
        ui->allSet_cO2->setEnabled(true);
        port_4_is_initiated = true;
    }
    else if (A1_2 && A2_2 && x0_2 && dx_2 && temp_co2_2) {
        ui->allSet_cO2->setEnabled(true);
        port_1_is_initiated = true;
    }
}

void MainWindow::on_set_x0_button_clicked()
{
    double x0 = QInputDialog::getDouble(this,
                                         "x0 eingeben",
                                         "valide Werte: -",
                                         1.41, 0.5, 1.7, 8);
    ui->x0_textbrowser->clear();
    ui->x0_textbrowser->append(QString::number(x0));
    // input string manipulation removes '.' and pads the right with zeores if necessary
    QString x0_to_sensor = "ctxo0" + QString::number(x0).remove('.').leftJustified(7, '0') + "\r";
    qDebug() << x0_to_sensor;
    QByteArray out = x0_to_sensor.toLatin1();

    if(sensor_4_is_available){
        port_4.write(out);
        x0_1 = true;
    }else if(sensor_5_is_available){
        port_1.write(out);
        x0_2 = true;
        qDebug() << "sensor 01: x0_2" << x0_2;
    }

    if(A1_1 && A2_1 && x0_1 && dx_1 && temp_co2_1){
        ui->allSet_cO2->setEnabled(true);
        port_4_is_initiated = true;
    }
    else if (A1_2 && A2_2 && x0_2 && dx_2 && temp_co2_2) {
        ui->allSet_cO2->setEnabled(true);
        port_1_is_initiated = true;
    }
}

void MainWindow::on_set_dx_button_clicked()
{
    double dx = QInputDialog::getDouble(this,
                                         "dx eingeben",
                                         "valide Werte: -",
                                         0.45, 0.3, 0.6, 8);
    ui->dx_textbrowser->clear();
    ui->dx_textbrowser->append(QString::number(dx));
    // adjusting and left padding with zeros to always have 7 characters
    // output must be in this format: "ctdx-XXXXXXX\r" example: ctdx-0000100 sets to dKSV2 = -0.0001
    QString dx_to_sensor = "ctdx0" + QString::number(dx).remove('.').leftJustified(7, '0') + "\r";
    qDebug() << "dx-Wert gesezt: " << dx_to_sensor;
    QByteArray out = dx_to_sensor.toLatin1();
    QString temp_to_sensor = "catp3710";
    QByteArray out_2 = temp_to_sensor.toLatin1();


    if(sensor_4_is_available){
        port_4.write(out);
        port_4.write(out_2);
        dx_1 = true;
    }else if(sensor_5_is_available){
        port_1.write(out);
        port_1.write(out_2);
        dx_2 = true;
        qDebug() << "sensor 01: dx_2" << dx_2;
    }

    if(A1_1 && A2_1 && x0_1 && dx_1 && temp_co2_1){
        ui->allSet_cO2->setEnabled(true);
        port_4_is_initiated = true;
    }
    else if (A1_2 && A2_2 && x0_2 && dx_2 && temp_co2_2) {
        ui->allSet_cO2->setEnabled(true);
        port_1_is_initiated = true;
    }

}

void MainWindow::on_set_temp_co2_button_clicked()
{
    double temp = QInputDialog::getDouble(this,
                                         "Temperatur eingeben",
                                         "valide Werte: ",
                                         37.1, 15, 45, 2);
    ui->temp_co2_textbrowser->clear();
    ui->temp_co2_textbrowser->append(QString::number(temp));
    // adjusting and left padding with zeros to always have 7 characters
    // output must be in this format: "catpXXXX\r" example: catp3710 sets to temp = 37.1
    QString temp_to_sensor = "catp" + QString::number(temp).remove('.').leftJustified(4, '0') + "\r";
    qDebug() << temp_to_sensor;
    QByteArray out = temp_to_sensor.toLatin1();

    if(sensor_4_is_available){
        port_4.write(out);
        temp_co2_1 = true;
    }else if(sensor_5_is_available){
        port_1.write(out);
        temp_co2_2 = true;
        qDebug() << "sensor 01: temp_co2_2" << temp_co2_2;
    }

    if(A1_1 && A2_1 && x0_1 && dx_1 && temp_co2_1){
        ui->allSet_cO2->setEnabled(true);
        port_4_is_initiated = true;
    }
    else if (A1_2 && A2_2 && x0_2 && dx_2 && temp_co2_2) {
        ui->allSet_cO2->setEnabled(true);
        port_1_is_initiated = true;
    }
}

/**************************************************************************
 *
 * once all data for initialisation of o2-sensor is set, th ok button is enabled:
 * on button pressed, mode is set to 0000 -> constant output of values
 * the connects are set and sensor is marked as initialised in the UI
 *
 **************************************************************************/

void MainWindow::on_allSet_cO2_clicked()
{
    QString mode_set = "mode0000\r";
    QByteArray out = mode_set.toLatin1();
    if(port_4_is_initiated && !sensor_5_is_available){
        port_4.write(out);
        ui->sensor_5_init_label->setStyleSheet("background-color : green");
        ui->sensor_5_init_label->setText("pH-Sensor initialisiert!");
    }
    if(port_1_is_initiated){
        port_1.write(out);
        qDebug() << "connect set for port 2";
        ui->sensor_6_init_label->setStyleSheet("background-color : green");
        ui->sensor_6_init_label->setText("pH-Sensor initialisiert!");

    }
    // set f1 back to false, or the second sensor will never become initiated
    A1_1 = false; A1_2 = false;

    sensor_4_is_available = false;
    sensor_5_is_available = false;

    ui->tabWidget_2->setTabEnabled(2, false);
    ui->tabWidget_2->setTabEnabled(0, true);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->A1_textbrowser->clear();
    ui->A2_textbrowser->clear();
    ui->x0_textbrowser->clear();
    ui->dx_textbrowser->clear();
    ui->temp_co2_textbrowser->clear();
}

/**************************************************************************
 *
 * measurement is started
 *
 **************************************************************************/
void MainWindow::on_start_measurement_button_clicked()
{
    ui->tabWidget->setTabEnabled(0, true);
    ui->tabWidget->setTabEnabled(2, true);
    ui->tabWidget->setTabEnabled(3, true);
    ui->tabWidget->setTabEnabled(4, true);
    ui->tabWidget->setCurrentIndex(0);

    /*********************************
     * setup output-stream for log
     *********************************/
    QString timeStamp = get_timeStamp();
    QString filepath = dir + "/log/" + timeStamp + "_log.txt";
    QString raw_filepath =dir + "/log_raw/" + timeStamp + "_log_raw.txt";
    qDebug() << filepath;
    QFile * log = new QFile(filepath);
    if(!log->isOpen())
    {
        log->open(QFile::WriteOnly |QFile::Append | QFile::Text);
        qDebug() << "file created";
    }

    /*********************************
     *
     * setup connects for all initiated sensors
     *
     *********************************/

    QString mode_set = "mode0000\r";
    QByteArray out = mode_set.toLatin1();

    if(port_0_is_initiated){
        port_0.open(QSerialPort::ReadWrite);
        qDebug() << "port_0 is open in messurement mode: " << port_0.isOpen();
        port_0.write(out);
        QObject::connect(&port_0, &QSerialPort::readyRead, this, &MainWindow::get_sensor_value_port_0);
    }

    if(port_1_is_initiated){
        port_1.open(QSerialPort::ReadWrite);
        port_1.write(out);
        QObject::connect(&port_1, &QSerialPort::readyRead, this, &MainWindow::get_sensor_value_port_1);
    }

    if(port_2_is_initiated){
        port_2.open(QSerialPort::ReadWrite);
        port_2.write(out);
        QObject::connect(&port_2, &QSerialPort::readyRead, this, &MainWindow::get_sensor_value_port_2);
    }

    if(port_3_is_initiated){
        port_3.open(QSerialPort::ReadWrite);
        port_3.write(out);
        QObject::connect(&port_3, &QSerialPort::readyRead, this, &MainWindow::get_sensor_value_port_3);
    }

    if(port_4_is_initiated){
        port_4.open(QSerialPort::ReadWrite);
        port_4.write(out);
        QObject::connect(&port_4, &QSerialPort::readyRead, this, &MainWindow::get_sensor_value_port_4);
    }

    if(port_5_is_initiated){
        port_5.open(QSerialPort::ReadWrite);
        port_5.write(out);
        QObject::connect(&port_5, &QSerialPort::readyRead, this, &MainWindow::get_sensor_value_port_5);
    }

    /*********************************
     *
     * timer starts here to write an output every second
     *
     *********************************/
    timer_for_output = new QTimer(this);

    QObject::connect(timer_for_output, &QTimer::timeout, this, [this, filepath, raw_filepath]{

        set_main_output_buttons();
        write_to_file(filepath);
        write_to_file_raw(raw_filepath);

    });

    timer_for_output->start(1000);

    QList<QString> hardware_id;


    QList<QSerialPort> port_list;
}

void MainWindow::set_main_output_buttons()
{
    // values fro the vectors are shown on the main-tab buttons,
    // o2 values are rounded -> no decimals
    // co2 values are rounded -> no decimals
    // ph values are 'rounded' to two decimals
    ui->pO2DisplayButton->setText(QString::number(round(qv_o2_1[qv_o2_1.size() -1])));
    ui->pO2DisplayButton_2->setText(QString::number(round(qv_o2_2[qv_o2_2.size() -1])));
    ui->pCO2DisplayButton->setText(QString::number(round(qv_co2_1[qv_co2_1.size() -1])));
    ui->pCO2DisplayButton_2->setText(QString::number(round(qv_co2_2[qv_co2_2.size() -1])));
    int ph_int_1 =(int)(qv_ph_1[qv_ph_1.size() -1] * 100);
    double ph_dou_1 = (double)ph_int_1;
    ph_dou_1 = ph_dou_1 / 100;
    ui->pHDisplayButton->setText(QString::number(qv_ph_1[qv_ph_1.size() -1]));

    int ph_int_2 =(int)(qv_ph_2[qv_ph_2.size() -1] * 100);
    double ph_dou_2 = (double)ph_int_2;
    ph_dou_2 = ph_dou_2 / 100;
    ui->pHDisplayButton_2->setText(QString::number(qv_ph_2[qv_ph_2.size() -1]));
}

/**************************************************************************
 *
 * continuously writes data to lag and raw datastring to raw
 *
 * *************************************************************************/
void MainWindow::write_to_file(QString filepath)
{
    QFile * file = new QFile(filepath);
    file->open(QFile::WriteOnly | QFile::Append | QFile::Text);
    QTextStream out(file);
    out << get_timeStamp() << ",";
    out << qv_o2_1[qv_o2_1.size() -1] << ",";
    out << qv_o2_2[qv_o2_2.size() -1] << ",";
    out << qv_co2_1[qv_co2_1.size() -1] << ",";
    out << qv_co2_2[qv_co2_2.size() -1] << ",";
    out << qv_ph_1[qv_ph_1.size() -1] << ",";
    out << qv_ph_2[qv_ph_2.size() -1] << ",";
    out << "\n";
    qDebug() << "write_to_file is running";
    file->close();
}

void MainWindow::write_to_file_raw(QString raw_filepath)
{
    qDebug() << "entered write_raw";
    QFile * file_raw = new QFile(raw_filepath);
    qDebug() << "file_raw created";
    file_raw->open(QFile::WriteOnly | QFile::Append | QFile::Text);
    qDebug() << "file is open? " << file_raw->isOpen();
    QTextStream out_raw(file_raw);
    qDebug() << "textstream open";
    out_raw << get_timeStamp() << ",";
    qDebug() << "timeStamp send to textStream";
    qDebug() << "content of String Vector:" << raw_o2_1[raw_o2_1.size() -1];
    out_raw << raw_o2_1[raw_o2_1.size() -1] << ",";
    out_raw << raw_o2_2[raw_o2_2.size() -1] << ",";
    out_raw << raw_co2_1[raw_co2_1.size() -1] << ",";
    out_raw << raw_co2_2[raw_co2_2.size() -1] << ",";
    out_raw << raw_ph_1[raw_ph_1.size() -1] << ",";
    out_raw << raw_ph_2[raw_ph_2.size() -1] << ",";
    out_raw << "\n";
    qDebug() << "write_to_file_raw is running";
    file_raw->close();

}

/***************************************************************
 * for output strings to log files
 ***************************************************************/

QString MainWindow::get_timeStamp()
{
     return QDateTime::currentDateTime().toString("dd.MM.yyyy_HH:mm:ss");
}

/**********************************************************************
 * ph-Sensor 1: collects to buffer until <LF><CR> signal
 * gets data string from buffer and saves value extracted from string
 * to QVector
 *
 * appends raw data string to
 **********************************************************************/
void MainWindow::get_sensor_value_port_0()
{
    // standard output string for ph sensro:
    // N01;A0019615;P4009;T2150;H00071520;E00000000;D0970 <LF><CR>

    if(!input_buffer_port_0.contains("\n\r")){
        serial_input_port_0 = port_0.readAll();
        input_buffer_port_0 += QString::fromStdString(serial_input_port_0.toStdString());
    }else {
        qDebug()<< "fertig port_0: " << input_buffer_port_0;
        raw_ph_1.append(QString::fromStdString(input_buffer_port_0.toStdString()));
        qDebug() << "raw data string saved to file from pot_0: " << raw_ph_1[raw_ph_1.size() -1];
        int index = input_buffer_port_0.indexOf("H");
        QString value = input_buffer_port_0.mid(index + 1, 8);
        value.insert(4, ".");
        qDebug() << value;
        qDebug() << value.toDouble();
        qv_ph_1.append(value.toDouble());
        input_buffer_port_0 = "";
    }

}

/**********************************************************************
 * CO2-Sensor 2
 **********************************************************************/
void MainWindow::get_sensor_value_port_1()
{

    // standard output string for co2 sensro:
    // N01;A0019615;P4009;T2150;H00071520;E00000000;D0970 <LF><CR>

    if(!input_buffer_port_1.contains("\n\r")){
        serial_input_port_1 = port_1.readAll();
        input_buffer_port_1 += QString::fromStdString(serial_input_port_1.toStdString());
    }else {
        qDebug()<< "fertig port_1: " << input_buffer_port_1;
        raw_co2_2.append(QString::fromStdString(input_buffer_port_1.toStdString()));
        qDebug() << "raw data string saved to file from pot_1: " << raw_co2_2;
        int index = input_buffer_port_1.indexOf("C");
        QString value = input_buffer_port_1.mid(index + 1, 8);
        value.insert(4, ".");
        qDebug() << value;
        qDebug() << value.toDouble();
        qv_co2_2.append(value.toDouble());
        input_buffer_port_1 = "";
    }
}

/**********************************************************************
 * ph-Sensor 2
 **********************************************************************/
void MainWindow::get_sensor_value_port_2()
{

    qDebug() << "connect set";
    // standard output string for ph sensro:
    // N01;A0019615;P4009;T2150;H00071520;E00000000;D0970 <LF><CR>

    if(!input_buffer_port_2.contains("\n\r")){
        serial_input_port_2 = port_2.readAll();
        input_buffer_port_2 += QString::fromStdString(serial_input_port_2.toStdString());
    }else {
        qDebug()<< "fertig_port_2: " << input_buffer_port_2;
        raw_ph_2.append(QString::fromStdString(input_buffer_port_2.toStdString()));
        qDebug() << "raw data string saved to file from pot_2: " << raw_ph_2;
        int index = input_buffer_port_2.indexOf("H");
        QString value = input_buffer_port_2.mid(index + 1, 8);
        value.insert(4, ".");
        qDebug() << value;
        qDebug() << value.toDouble();
        qv_ph_2.append(value.toDouble());
        input_buffer_port_2 = "";
    }
}

/**********************************************************************
 * O2-Sensor 1
 **********************************************************************/
void MainWindow::get_sensor_value_port_3()
{
    // standard output string for o2 sensor:
    // N01;A0019615;P4009;T2150;H00071520;E00000000;D0970 <LF><CR>

    if(!input_buffer_port_3.contains("\n\r")){
        serial_input_port_3 = port_3.readAll();
        input_buffer_port_3 += QString::fromStdString(serial_input_port_3.toStdString());
    }else {
        qDebug()<< "fertig_port_3: " << input_buffer_port_3;
        QString raw_value = QString::fromStdString(input_buffer_port_3.toStdString());
        raw_o2_1.append(raw_value);
        qDebug() << "raw data string saved to file from pot_3: " << raw_o2_1[raw_o2_1.size() - 1];
        int index = input_buffer_port_3.indexOf("O");
        QString value = input_buffer_port_3.mid(index + 1, 6);
        value.insert(4, ".");
        qDebug() << value;
        qDebug() << value.toDouble();
        qv_o2_1.append(value.toDouble());
        input_buffer_port_3 = "";
    }
}

/**********************************************************************
 * CO2-Sensor 1
 **********************************************************************/
void MainWindow::get_sensor_value_port_4()
{
     // standard output string for co2 sensor:
    // N01;A0019615;P4009;T2150;H00071520;E00000000;D0970 <LF><CR>

    if(!input_buffer_port_4.contains("\n\r")){
        serial_input_port_4 = port_4.readAll();
        input_buffer_port_4 += QString::fromStdString(serial_input_port_4.toStdString());
    }else {
        qDebug()<< "fertig_port_4: " << input_buffer_port_4;
        raw_co2_1.append(QString::fromStdString(input_buffer_port_4.toStdString()));
        qDebug() << "raw data string saved to file from pot_4: " << raw_co2_1;
        int index = input_buffer_port_4.indexOf("C");
        QString value = input_buffer_port_4.mid(index + 1, 8);
        value.insert(4, ".");
        qDebug() << value;
        qDebug() << value.toDouble();
        qv_co2_1.append(value.toDouble());
        input_buffer_port_4 = "";
    }
}

/**********************************************************************
 * O2-Sensor 2
 **********************************************************************/
void MainWindow::get_sensor_value_port_5()
{

    // standard output string for o2 sensor:
    // N01;A0019615;P4009;T2150;H00071520;E00000000;D0970 <LF><CR>

    if(!input_buffer_port_5.contains("\n\r")){
        serial_input_port_5 = port_5.readAll();
        input_buffer_port_5 += QString::fromStdString(serial_input_port_5.toStdString());
    }else {
        qDebug()<< "fertig_port_5: " << input_buffer_port_5;
        raw_o2_2.append(QString::fromStdString(input_buffer_port_5.toStdString()));
        qDebug() << "raw data string saved to file from pot_5: " << raw_o2_2;
        int index = input_buffer_port_5.indexOf("H");
        QString value = input_buffer_port_5.mid(index + 1, 8);
        value.insert(4, ".");
        qDebug() << value;
        qDebug() << value.toDouble();
        qv_o2_2.append(value.toDouble());
        input_buffer_port_5 = "";
    }
}

/*************************************************************
 *
 * to stop meassuring set ports to mode0001 -> datastring
 * only is send on "data\r"-command from host
 *
 ***********************************************************/
void MainWindow::on_stopMeassurementButton_clicked()
{
    // to stop meassuring, stop timer to stop writing to file
    // set all sensors to mode0001 -> "mode0001\r"
    QString turn_off_sensors= "mode0001\r";
    QByteArray out = turn_off_sensors.toLatin1();

    timer_for_output->stop();

    port_0.write(out);
    port_1.write(out);
    port_2.write(out);
    port_3.write(out);
    port_4.write(out);
    port_5.write(out);

}

/**************************************************************************
 *
 * close buttons
 *
 **************************************************************************/

void MainWindow::on_quitButtonStartMain_clicked()
{
    close();
}

void MainWindow::on_quitButtonStartMain_2_clicked()
{
    close();
}

void MainWindow::on_quitButtonStartMain_3_clicked()
{
    close();
}

void MainWindow::on_quitButtonStartMain_4_clicked()
{
    close();
}

void MainWindow::on_quitButton_clicked()
{
    close();
}
