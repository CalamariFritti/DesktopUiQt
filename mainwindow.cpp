
#include "mainwindow.h"
#include "ui_mainwindow.h"

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFontsizesAndBackgroundColors();

    rawVectorInit();

    setupGraphs();

    // wait for 10 seconds to make sure the sensors are started
//  delay(10);

// old RS 323
//    setupSensors();

    setupSensor485();

    delay(1);

//  setHardwareAddressToId();

    setPreInit();

    startDialog();

    startStorageReader();

    valueVectorPreparation();

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

    activation->~Dialog();
    key->~Keyboard();
    delete ui;
}

void MainWindow::delay(int seconds)
{
    QTime dieTime= QTime::currentTime().addSecs(seconds);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::startStorageReader(){
    QStorageInfo storage = QStorageInfo::root();
    qDebug() << "Storage avaiable: " << storage.rootPath();
    //byte to GB conversion
    qint64 storAvailable = storage.bytesAvailable()/1024/1024/1024;
    QString stor = QString::number(storAvailable) + " GB";
    ui->stopMeassurementButton->setText(stor);

}

void MainWindow::valueVectorPreparation(){

    for( int i = 0; i < 2; i++){
        list_o2_1.append(0);
        list_o2_2.append(0);
        list_co2_1.append(0);
        list_co2_2.append(0);
        list_ph_1.append(0);
        list_ph_2.append(0);


    }

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

void MainWindow::setupGraphs()
{

    o2_chart = new QChart();
    co2_chart = new QChart();
    ph_chart = new QChart();

    o2_series = new QLineSeries(o2_chart);
    co2_series = new QLineSeries(co2_chart);
    ph_series = new QLineSeries(ph_chart);

    o2_chart_name = "O2 Werte";
    co2_chart_name = "CO2 Werte";
    ph_chart_name = "pH Werte";

    o2_series->setName(o2_chart_name);
    co2_series->setName(co2_chart_name);
    ph_series->setName(ph_chart_name);

    start = QDateTime::currentDateTime();

    o2_chart->addSeries(o2_series);
    co2_chart->addSeries(co2_series);
    ph_chart->addSeries(ph_series);

    // initial setup for ph axises
    axisX = new QDateTimeAxis;
    axisX->setFormat("hh:mm:ss");
    axisX->setTitleText("Zeit");

    axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setRange(-100, 500);
    axisY->setTitleText("Werte");

    // initial setup for ph axises
    co2_axisX = new QDateTimeAxis;
    co2_axisX->setFormat("hh:mm:ss");
    co2_axisX->setTitleText("Zeit");

    co2_axisY = new QValueAxis;
    co2_axisY->setLabelFormat("%i");
    co2_axisY->setRange(-100, 500);
    co2_axisY->setTitleText("Werte");

    // initial setup for ph axises
    ph_axisX = new QDateTimeAxis;
    ph_axisX->setFormat("hh:mm:ss");
    ph_axisX->setTitleText("Zeit");

    ph_axisY = new QValueAxis;
    ph_axisY->setLabelFormat("%i");
    ph_axisY->setRange(-100, 500);
    ph_axisY->setTitleText("Werte");

    // initial setup for o2 chart
    o2_chart->addAxis(axisX, Qt::AlignBottom);
    o2_chart->addAxis(axisY, Qt::AlignLeft);
    o2_series->attachAxis(axisX);
    o2_series->attachAxis(axisY);

    o2_chartView = new QChartView(o2_chart);
    o2_chartView->setRenderHint(QPainter::Antialiasing);

    o2_gridLayout = new QGridLayout();
    ui->lineGraph_o2->setLayout(o2_gridLayout);
    o2_gridLayout->addWidget(o2_chartView, 0, 0);

    // initial setup for o2 chart
    co2_chart->addAxis(co2_axisX, Qt::AlignBottom);
    co2_chart->addAxis(co2_axisY, Qt::AlignLeft);
    co2_series->attachAxis(co2_axisX);
    co2_series->attachAxis(co2_axisY);

    co2_chartView = new QChartView(co2_chart);
    co2_chartView->setRenderHint(QPainter::Antialiasing);

    co2_gridLayout = new QGridLayout();
    ui->lineGraph_co2->setLayout(co2_gridLayout);
    co2_gridLayout->addWidget(co2_chartView, 0, 0);

    // initial setup for pH chart
    ph_chart->addAxis(ph_axisX, Qt::AlignBottom);
    ph_chart->addAxis(ph_axisY, Qt::AlignLeft);
    ph_series->attachAxis(ph_axisX);
    ph_series->attachAxis(ph_axisY);

    ph_chartView = new QChartView(ph_chart);
    ph_chartView->setRenderHint(QPainter::Antialiasing);

    ph_gridLayout = new QGridLayout();
    ui->lineGraph_ph->setLayout(ph_gridLayout);
    ph_gridLayout->addWidget(ph_chartView, 0, 0);


}

void MainWindow::setupSensor485()
{

    port_0.setPortName(port_0_system_location);

    port_0.open(QSerialPort::ReadWrite);
    qDebug() << "RS485 is open? :" << port_0.isOpen();
    port_0.setBaudRate(QSerialPort::Baud19200);
    qDebug() << "RS485 baudrate set to: 19200 ";
    port_0.setDataBits(QSerialPort::Data8);         // default for presens EOM
    qDebug() << "Date bits set to: Data8";
    port_0.setFlowControl(QSerialPort::NoFlowControl);  // default for presens EOM
    qDebug() << "Flow control set to: NoFlowControl";
    port_0.setParity(QSerialPort::NoParity);            // default for presens EOM
    qDebug() << "Parity set to: NoParity";
    port_0.setStopBits(QSerialPort::OneStop);           // default for presens EOM
    qDebug() << "StopBits set to: OneStop";

    port_0.open(QSerialPort::ReadWrite);
    qDebug() << "RS485 reopen to confirm settings? " << port_0.isOpen();
    qDebug() << "------------------------------------------------------------------";

}


// RS323 communication setup, deprecated

void MainWindow::setupSensors()
{
    QString turn_off_sensors = "mode0001\r";
    QByteArray out = turn_off_sensors.toLatin1();

    list_of_ports.append(&port_0);
    list_of_ports.append(&port_1);
    list_of_ports.append(&port_2);
    list_of_ports.append(&port_3);
    list_of_ports.append(&port_4);
    list_of_ports.append(&port_5);

    QListIterator<QSerialPort*> i(list_of_ports);

    qDebug() << "port 0 is on this one: " << port_0_system_location;
    port_0.setPortName(port_0_system_location);
    qDebug() << " portname set to: " << port_0.portName();

    qDebug() << "port 1 is on this one: " << port_1_system_location;
    port_1.setPortName(port_1_system_location);
    qDebug() << " portname set";

    qDebug() << "port 2 is on this one: " << port_2_system_location;
    port_2.setPortName(port_2_system_location);
    qDebug() << " portname set";

    qDebug() << "port 3 is on this one: " << port_3_system_location;
    port_3.setPortName(port_3_system_location);
    qDebug() << " portname set";

    qDebug() << "port 4 is on this one: " << port_4_system_location;
    port_4.setPortName(port_4_system_location);
    qDebug() << " portname set";

    qDebug() << "port 5 is on this one: " << port_5_system_location;
    port_5.setPortName(port_5_system_location);
    qDebug() << " portname set";

    while (i.hasNext())
    {
        QSerialPort *port = i.peekNext();

        port->open(QSerialPort::ReadWrite);
        qDebug() << "first open sets open:" << port->isOpen();
        port->setBaudRate(QSerialPort::Baud19200);
        qDebug() << "set baudrate to 19200: " << port;
        port->setDataBits(QSerialPort::Data8);         // default for presens EOM
        qDebug() << "Data8 set";
        port->setFlowControl(QSerialPort::NoFlowControl);  // default for presens EOM
        qDebug() << "noFlow Contr set";
        port->setParity(QSerialPort::NoParity);            // default for presens EOM
        qDebug() << "no parity set";
        port->setStopBits(QSerialPort::OneStop);           // default for presens EOM
        qDebug() << "onestop set";

        port->open(QSerialPort::ReadWrite);
        qDebug() << "is the port really open?" << port->isOpen();
        port->write(out);
        qDebug() << out;
        qDebug() << port << "in mode 0001";
        qDebug() << port << "is open: " << port->isOpen();
        qDebug() << "------------------------------------------------------------------";


        i.next();
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
    activation->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);
    activation->setWindowState(Qt::WindowFullScreen);
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
/***
*    double f1 = QInputDialog::getDouble(this,
 *                                        "Sensorkonstante f1",
  *                                       "Wert eingeben:",
   *                                      0.808, -99.99999, 999.99999, 5);
    ***/

    Keyboard * key = new Keyboard(0, "0.808", "Bitte f1-Sensorwert eingeben:");
//    key->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);
//    key->setWindowState(Qt::WindowFullScreen);
//    key->setWindowOpacity(0.5);
    key->show();

    QObject::connect(key, &Keyboard::pushButton_ok_clicked, this, &MainWindow::set_f1_value);
}

void MainWindow::set_f1_value(double f1)
{
    int padUpTo = 8;        // eight digits for values > 0

    ui->f1_textbrowser->clear();
    ui->f1_textbrowser->append(QString::number(f1, 'f', 5));

    QString prepend = "";
    if (f1 < 0){
        prepend = "scfo-";
        padUpTo = 7;        // change to seven digits for values < 0
    }else{
        prepend = "scfo";
    }

    // build string QString::number(numeral, output format 'f' for NOT sientific, precision)
    QString f1_to_sensor = prepend + QString::number(f1, 'f', 5).remove('-').remove('.').rightJustified(padUpTo, '0') + "\r";
    QByteArray out = f1_to_sensor.toLatin1();

    qDebug() << "out for f1: " << out;
    qDebug() << out[0] << out[1] << out[2] << out[3];

    if(sensor_0_is_available){
        port_3.write(out);
        qDebug() << "f1-value send to port_3" << out << "length: " << port_3.write(out);
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

    QByteArray out = m_to_sensor.toLatin1();

            qDebug() << "SENSOR = ? "<< sensor_0_is_available;
    if(sensor_0_is_available){
        qDebug() << "SENSOR = ? "<< sensor_0_is_available;
        port_3.write(out);
        qDebug() << "m value send to port_3" << out << "length: " << port_3.write(out);
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
 * output must be in this format: "scpoXXXXXXXX\r" example: scpo00061710 sets to dPhi1 =  0.06171 for positive numbers
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
 * output must be in this format: "scptXXXXXXXX\r" example: scpt00061710 sets to dPhi2 =  0.06171 for positive numbers
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
    int padUpTo = 8;
    double a2 = QInputDialog::getDouble(this,
                                         "Sensorkonstante A2",
                                         "Bitte Wert eingeben:",
                                         56.08, -9.9999999, 99.999999, 6);
    ui->A2_textbrowser->clear();
    ui->A2_textbrowser->append(QString::number(a2, 'f', 6));

    QString prepend = "";
    if(a2 < 0){
        prepend = "ctat-";
        padUpTo = 7;
    }else{
        prepend = "ctat";
    }

    QString a2_to_sensor = prepend + QString::number(a2, 'f', 6).remove('.').remove('-').rightJustified(padUpTo, '0') + "\r";
    qDebug() << a2_to_sensor;
    QByteArray out = a2_to_sensor.toLatin1();


    if(sensor_4_is_available)
    {
        port_4.write(out);
        A2_1 = true;
    }
    else if(sensor_5_is_available)
    {
        port_1.write(out);
        A2_2 = true;
        qDebug() << "sensor 01: a2_2" << A2_2;
    }

    if(A1_1 && A2_1 && x0_1 && dx_1 && temp_co2_1)
    {
        ui->allSet_cO2->setEnabled(true);
        port_4_is_initiated = true;
    }
    else if (A1_2 && A2_2 && x0_2 && dx_2 && temp_co2_2)
    {
        ui->allSet_cO2->setEnabled(true);
        port_1_is_initiated = true;
    }
}

void MainWindow::on_set_x0_button_clicked()
{
    int padUpTo = 8;
    double x0 = QInputDialog::getDouble(this,
                                         "Sensorkonstante x0",
                                         "Bitte Wert eingeben:",
                                         1.41, -9.999999, 99.999999, 6);
    ui->x0_textbrowser->clear();
    ui->x0_textbrowser->append(QString::number(x0, 'f', 6));

    QString prepend = "";
    if(x0 < 0){
        prepend = "ctxo-";
        padUpTo = 7;
    }else{
        prepend = "ctxo";
    }

    QString x0_to_sensor = prepend + QString::number(x0,'f', 6).remove('.').remove('-').rightJustified(padUpTo, '0') + "\r";
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
    int padUpTo = 8;
    double dx = QInputDialog::getDouble(this,
                                         "dx eingeben",
                                         "valide Werte: -",
                                         0.45, -9.999999, 99.999999, 6);
    ui->dx_textbrowser->clear();
    ui->dx_textbrowser->append(QString::number(dx, 'f', 6));

    QString prepend = "";
    if(dx < 0){
        prepend = "ctdx-";
        padUpTo = 7;
    }else{
        prepend = "ctdx";
    }

    // adjusting and left padding with zeros to always have 7 characters
    // output must be in this format: "ctdx-XXXXXXX\r" example: ctdx-0000100 sets to dKSV2 = -0.0001
    QString dx_to_sensor = prepend + QString::number(dx, 'f', 6).remove('.').remove('-').rightJustified(padUpTo, '0') + "\r";
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
    int padUpTo = 4;
    double temp = QInputDialog::getDouble(this,
                                         "Temperatur eingeben",
                                         "valide Werte: ",
                                         37.1, 0, 60.00, 2);
    ui->temp_co2_textbrowser->clear();
    ui->temp_co2_textbrowser->append(QString::number(temp, 'f', 2));

    QString prepend = "";
    if(temp < 0){
        prepend = "catp-";
        padUpTo = 3;
    }else{
        prepend = "catp";
    }

    // adjusting and left padding with zeros to always have 7 characters
    // output must be in this format: "catpXXXX\r" example: catp3710 sets to temp = 37.1
    QString temp_to_sensor = "catp" + QString::number(temp, 'f', 2).remove('.').remove('-').rightJustified(padUpTo, '0') + "\r";
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

        qDebug() << ("----------------------------------------------");
        qDebug() << list_o2_1[list_o2_1.size() - 1];
        qDebug() << list_o2_2[list_o2_2.size() -1];
        qDebug() << list_co2_1[list_co2_1.size() -1];
        qDebug() << list_co2_2[list_co2_2.size() -1];
        qDebug() << list_ph_1[list_ph_1.size() -1];
        qDebug() << list_ph_2[list_ph_2.size() -1];
        qDebug() << ("----------------------------------------------");
        set_main_output_buttons();
        write_to_file(filepath);
        write_to_file_raw(raw_filepath);
        append_to_plotSeries();
        startStorageReader();
    });

    timer_for_output->start(1000);

}

void MainWindow::set_main_output_buttons()
{
    // values fro the vectors are shown on the main-tab buttons,
    // o2 values are rounded -> no decimals
    // co2 values are rounded -> no decimals
    // ph values are 'rounded' to two decimals
    ui->pO2DisplayButton->setText(QString::number(round(list_o2_1[list_o2_1.size() -1])));
    ui->pO2DisplayButton_2->setText(QString::number(round(list_o2_2[list_o2_2.size() -1])));
    ui->pCO2DisplayButton->setText(QString::number(round(list_co2_1[list_co2_1.size() -1])));
    ui->pCO2DisplayButton_2->setText(QString::number(round(list_co2_2[list_co2_2.size() -1])));
    int ph_int_1 =(int)(list_ph_1[list_ph_1.size() -1] * 100);
    double ph_dou_1 = (double)ph_int_1;
    ph_dou_1 = ph_dou_1 / 100;
    ui->pHDisplayButton->setText(QString::number(list_ph_1[list_ph_1.size() -1]));

    int ph_int_2 =(int)(list_ph_2[list_ph_2.size() -1] * 100);
    double ph_dou_2 = (double)ph_int_2;
    ph_dou_2 = ph_dou_2 / 100;
    ui->pHDisplayButton_2->setText(QString::number(list_ph_2[list_ph_2.size() -1]));
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
    out << list_o2_1[list_o2_1.size() -1] << ",";
    out << list_o2_2[list_o2_2.size() -1] << ",";
    out << list_co2_1[list_co2_1.size() -1] << ",";
    out << list_co2_2[list_co2_2.size() -1] << ",";
    out << list_ph_1[list_ph_1.size() -1] << ",";
    out << list_ph_2[list_ph_2.size() -1] << ",";
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
 * appending to series triggers an automated update of the graph
 ***************************************************************/
void MainWindow::append_to_plotSeries()
{
    QDateTime now = QDateTime::currentDateTime();

    axisX->setRange(start, now.addSecs(2));
    co2_axisX->setRange(start, now.addSecs(2));
    ph_axisX->setRange(start, now.addSecs(2));
    o2_series->append(now.toMSecsSinceEpoch(), list_o2_1[list_o2_1.size() -1]);
    co2_series->append(now.toMSecsSinceEpoch(), list_co2_1[list_co2_1.size() -1]);
    ph_series->append(now.toMSecsSinceEpoch(), list_ph_1[list_ph_1.size() -1]);
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
        list_ph_1.append(value.toDouble());
        input_buffer_port_0 = "";
        if(raw_ph_1.size() > 1000){
            raw_ph_1.removeFirst();
            //TODO: sichtbar machen
        }
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
        list_co2_2.append(value.toDouble());
        input_buffer_port_1 = "";
        if(raw_co2_2.size() > 1000){
            raw_co2_2.removeFirst();
        }
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
        list_ph_2.append(value.toDouble());
        input_buffer_port_2 = "";
        if(raw_ph_2.size() > 1000){
            raw_ph_2.removeFirst();
        }
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
        list_o2_1.append(value.toDouble());
        input_buffer_port_3 = "";
        if(raw_o2_1.size() > 1000){
            raw_o2_1.removeFirst();
        }
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
        list_co2_1.append(value.toDouble());
        input_buffer_port_4 = "";
        if(raw_co2_1.size() > 1000){
            raw_co2_1.removeFirst();
        }
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
        list_o2_2.append(value.toDouble());
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
    qDebug() << "all ports set to mode0001";
}

/**************************************************************************
 *
 * close buttons
 *
 **************************************************************************/

void MainWindow::on_quitButtonStartMain_clicked()
{
    on_stopMeassurementButton_clicked();
    close();
}

void MainWindow::on_quitButtonStartMain_2_clicked()
{
    on_stopMeassurementButton_clicked();
    close();
}

void MainWindow::on_quitButtonStartMain_3_clicked()
{
    on_stopMeassurementButton_clicked();
    close();
}

void MainWindow::on_quitButtonStartMain_4_clicked()
{
    on_stopMeassurementButton_clicked();
    close();
}

void MainWindow::on_quitButton_clicked()
{
    on_stopMeassurementButton_clicked();
    close();
}

void MainWindow::on_quitButtonSensor_1_clicked()
{
    on_stopMeassurementButton_clicked();
    close();
}

void MainWindow::on_quitButtonSensor_2_clicked()
{
    on_stopMeassurementButton_clicked();
    close();
}

void MainWindow::on_quitButtonSensor_3_clicked()
{
    on_stopMeassurementButton_clicked();
    close();
}

// in poweruser tab this line edit cann be used for manual command transmission
// all commands go to port_0 as this is the RS485 default port
void MainWindow::on_lineEdit_returnPressed()
{
    QByteArray serial_input;
    QString input_buffer = "" ;

    QString input = ui->lineEdit->text() + "\r";;
    ui->textBrowser->setText("Folgender Befehl wird gesendet:\n" + input);
    QByteArray out = input.toLatin1();
    qDebug() << out;

    port_0.write(out);

    if(!input_buffer.contains("\n\r")){
        serial_input = port_0.readAll();
        qDebug() << serial_input;
        input_buffer += QString::fromStdString(serial_input.toStdString());
        ui->textBrowser->setText(input_buffer);
    }else {
        QString value = input_buffer;
        qDebug() << value;
        ui->textBrowser->append("Gelesene Daten von der Schnittstelle: \n");
        ui->textBrowser->append(value);
        input_buffer = "";
    }
}


void MainWindow::on_plotButtonSensor_1_clicked()
{
    o2_series->remove(0);

    qDebug() << "plot button";
}
