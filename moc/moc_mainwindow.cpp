/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[70];
    char stringdata0[1679];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "radioButton_0_toggled"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 21), // "radioButton_1_toggled"
QT_MOC_LITERAL(4, 56, 21), // "radioButton_2_toggled"
QT_MOC_LITERAL(5, 78, 21), // "radioButton_3_toggled"
QT_MOC_LITERAL(6, 100, 21), // "radioButton_4_toggled"
QT_MOC_LITERAL(7, 122, 21), // "radioButton_5_toggled"
QT_MOC_LITERAL(8, 144, 13), // "get_timeStamp"
QT_MOC_LITERAL(9, 158, 23), // "get_sensor_value_port_0"
QT_MOC_LITERAL(10, 182, 23), // "get_sensor_value_port_1"
QT_MOC_LITERAL(11, 206, 23), // "get_sensor_value_port_2"
QT_MOC_LITERAL(12, 230, 23), // "get_sensor_value_port_3"
QT_MOC_LITERAL(13, 254, 23), // "get_sensor_value_port_4"
QT_MOC_LITERAL(14, 278, 23), // "get_sensor_value_port_5"
QT_MOC_LITERAL(15, 302, 13), // "write_to_file"
QT_MOC_LITERAL(16, 316, 17), // "write_to_file_raw"
QT_MOC_LITERAL(17, 334, 16), // "setActiveSensor0"
QT_MOC_LITERAL(18, 351, 16), // "setActiveSensor1"
QT_MOC_LITERAL(19, 368, 16), // "setActiveSensor2"
QT_MOC_LITERAL(20, 385, 16), // "setActiveSensor3"
QT_MOC_LITERAL(21, 402, 16), // "setActiveSensor4"
QT_MOC_LITERAL(22, 419, 16), // "setActiveSensor5"
QT_MOC_LITERAL(23, 436, 5), // "delay"
QT_MOC_LITERAL(24, 442, 31), // "setFontsizesAndBackgroundColors"
QT_MOC_LITERAL(25, 474, 12), // "setupSensors"
QT_MOC_LITERAL(26, 487, 11), // "startDialog"
QT_MOC_LITERAL(27, 499, 10), // "setPreInit"
QT_MOC_LITERAL(28, 510, 30), // "on_quitButtonStartMain_clicked"
QT_MOC_LITERAL(29, 541, 37), // "on_initialize_sensor_0_button..."
QT_MOC_LITERAL(30, 579, 37), // "on_initialize_sensor_1_button..."
QT_MOC_LITERAL(31, 617, 37), // "on_initialize_sensor_2_button..."
QT_MOC_LITERAL(32, 655, 37), // "on_initialize_sensor_3_button..."
QT_MOC_LITERAL(33, 693, 37), // "on_initialize_sensor_4_button..."
QT_MOC_LITERAL(34, 731, 37), // "on_initialize_sensor_5_button..."
QT_MOC_LITERAL(35, 769, 24), // "on_set_f1_button_clicked"
QT_MOC_LITERAL(36, 794, 23), // "on_set_m_button_clicked"
QT_MOC_LITERAL(37, 818, 27), // "on_set_dPhi1_button_clicked"
QT_MOC_LITERAL(38, 846, 27), // "on_set_dPhi2_button_clicked"
QT_MOC_LITERAL(39, 874, 27), // "on_set_dKSV1_button_clicked"
QT_MOC_LITERAL(40, 902, 27), // "on_set_dKSV2_button_clicked"
QT_MOC_LITERAL(41, 930, 32), // "on_quitButtonStartMain_2_clicked"
QT_MOC_LITERAL(42, 963, 20), // "on_allSet_o2_clicked"
QT_MOC_LITERAL(43, 984, 12), // "set_f1_value"
QT_MOC_LITERAL(44, 997, 26), // "on_set_lmin_button_clicked"
QT_MOC_LITERAL(45, 1024, 26), // "on_set_lmax_button_clicked"
QT_MOC_LITERAL(46, 1051, 25), // "on_set_pH0_button_clicked"
QT_MOC_LITERAL(47, 1077, 25), // "on_set_dpH_button_clicked"
QT_MOC_LITERAL(48, 1103, 26), // "on_set_temp_button_clicked"
QT_MOC_LITERAL(49, 1130, 32), // "on_quitButtonStartMain_3_clicked"
QT_MOC_LITERAL(50, 1163, 20), // "on_allSet_pH_clicked"
QT_MOC_LITERAL(51, 1184, 24), // "on_set_A1_button_clicked"
QT_MOC_LITERAL(52, 1209, 24), // "on_set_A2_button_clicked"
QT_MOC_LITERAL(53, 1234, 24), // "on_set_x0_button_clicked"
QT_MOC_LITERAL(54, 1259, 24), // "on_set_dx_button_clicked"
QT_MOC_LITERAL(55, 1284, 21), // "on_allSet_cO2_clicked"
QT_MOC_LITERAL(56, 1306, 32), // "on_quitButtonStartMain_4_clicked"
QT_MOC_LITERAL(57, 1339, 35), // "on_start_measurement_button_c..."
QT_MOC_LITERAL(58, 1375, 23), // "set_main_output_buttons"
QT_MOC_LITERAL(59, 1399, 33), // "on_stopMeassurementButton_cli..."
QT_MOC_LITERAL(60, 1433, 21), // "on_quitButton_clicked"
QT_MOC_LITERAL(61, 1455, 30), // "on_set_temp_co2_button_clicked"
QT_MOC_LITERAL(62, 1486, 13), // "rawVectorInit"
QT_MOC_LITERAL(63, 1500, 25), // "on_lineEdit_returnPressed"
QT_MOC_LITERAL(64, 1526, 11), // "setupGraphs"
QT_MOC_LITERAL(65, 1538, 29), // "on_quitButtonSensor_1_clicked"
QT_MOC_LITERAL(66, 1568, 29), // "on_quitButtonSensor_2_clicked"
QT_MOC_LITERAL(67, 1598, 29), // "on_quitButtonSensor_3_clicked"
QT_MOC_LITERAL(68, 1628, 29), // "on_plotButtonSensor_1_clicked"
QT_MOC_LITERAL(69, 1658, 20) // "append_to_plotSeries"

    },
    "MainWindow\0radioButton_0_toggled\0\0"
    "radioButton_1_toggled\0radioButton_2_toggled\0"
    "radioButton_3_toggled\0radioButton_4_toggled\0"
    "radioButton_5_toggled\0get_timeStamp\0"
    "get_sensor_value_port_0\0get_sensor_value_port_1\0"
    "get_sensor_value_port_2\0get_sensor_value_port_3\0"
    "get_sensor_value_port_4\0get_sensor_value_port_5\0"
    "write_to_file\0write_to_file_raw\0"
    "setActiveSensor0\0setActiveSensor1\0"
    "setActiveSensor2\0setActiveSensor3\0"
    "setActiveSensor4\0setActiveSensor5\0"
    "delay\0setFontsizesAndBackgroundColors\0"
    "setupSensors\0startDialog\0setPreInit\0"
    "on_quitButtonStartMain_clicked\0"
    "on_initialize_sensor_0_button_clicked\0"
    "on_initialize_sensor_1_button_clicked\0"
    "on_initialize_sensor_2_button_clicked\0"
    "on_initialize_sensor_3_button_clicked\0"
    "on_initialize_sensor_4_button_clicked\0"
    "on_initialize_sensor_5_button_clicked\0"
    "on_set_f1_button_clicked\0"
    "on_set_m_button_clicked\0"
    "on_set_dPhi1_button_clicked\0"
    "on_set_dPhi2_button_clicked\0"
    "on_set_dKSV1_button_clicked\0"
    "on_set_dKSV2_button_clicked\0"
    "on_quitButtonStartMain_2_clicked\0"
    "on_allSet_o2_clicked\0set_f1_value\0"
    "on_set_lmin_button_clicked\0"
    "on_set_lmax_button_clicked\0"
    "on_set_pH0_button_clicked\0"
    "on_set_dpH_button_clicked\0"
    "on_set_temp_button_clicked\0"
    "on_quitButtonStartMain_3_clicked\0"
    "on_allSet_pH_clicked\0on_set_A1_button_clicked\0"
    "on_set_A2_button_clicked\0"
    "on_set_x0_button_clicked\0"
    "on_set_dx_button_clicked\0on_allSet_cO2_clicked\0"
    "on_quitButtonStartMain_4_clicked\0"
    "on_start_measurement_button_clicked\0"
    "set_main_output_buttons\0"
    "on_stopMeassurementButton_clicked\0"
    "on_quitButton_clicked\0"
    "on_set_temp_co2_button_clicked\0"
    "rawVectorInit\0on_lineEdit_returnPressed\0"
    "setupGraphs\0on_quitButtonSensor_1_clicked\0"
    "on_quitButtonSensor_2_clicked\0"
    "on_quitButtonSensor_3_clicked\0"
    "on_plotButtonSensor_1_clicked\0"
    "append_to_plotSeries"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      68,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  354,    2, 0x06 /* Public */,
       3,    1,  357,    2, 0x06 /* Public */,
       4,    1,  360,    2, 0x06 /* Public */,
       5,    1,  363,    2, 0x06 /* Public */,
       6,    1,  366,    2, 0x06 /* Public */,
       7,    1,  369,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  372,    2, 0x0a /* Public */,
       9,    0,  373,    2, 0x0a /* Public */,
      10,    0,  374,    2, 0x0a /* Public */,
      11,    0,  375,    2, 0x0a /* Public */,
      12,    0,  376,    2, 0x0a /* Public */,
      13,    0,  377,    2, 0x0a /* Public */,
      14,    0,  378,    2, 0x0a /* Public */,
      15,    1,  379,    2, 0x0a /* Public */,
      16,    1,  382,    2, 0x0a /* Public */,
      17,    1,  385,    2, 0x0a /* Public */,
      18,    1,  388,    2, 0x0a /* Public */,
      19,    1,  391,    2, 0x0a /* Public */,
      20,    1,  394,    2, 0x0a /* Public */,
      21,    1,  397,    2, 0x0a /* Public */,
      22,    1,  400,    2, 0x0a /* Public */,
      23,    1,  403,    2, 0x08 /* Private */,
      24,    0,  406,    2, 0x08 /* Private */,
      25,    0,  407,    2, 0x08 /* Private */,
      26,    0,  408,    2, 0x08 /* Private */,
      27,    0,  409,    2, 0x08 /* Private */,
      28,    0,  410,    2, 0x08 /* Private */,
      29,    0,  411,    2, 0x08 /* Private */,
      30,    0,  412,    2, 0x08 /* Private */,
      31,    0,  413,    2, 0x08 /* Private */,
      32,    0,  414,    2, 0x08 /* Private */,
      33,    0,  415,    2, 0x08 /* Private */,
      34,    0,  416,    2, 0x08 /* Private */,
      35,    0,  417,    2, 0x08 /* Private */,
      36,    0,  418,    2, 0x08 /* Private */,
      37,    0,  419,    2, 0x08 /* Private */,
      38,    0,  420,    2, 0x08 /* Private */,
      39,    0,  421,    2, 0x08 /* Private */,
      40,    0,  422,    2, 0x08 /* Private */,
      41,    0,  423,    2, 0x08 /* Private */,
      42,    0,  424,    2, 0x08 /* Private */,
      43,    1,  425,    2, 0x08 /* Private */,
      44,    0,  428,    2, 0x08 /* Private */,
      45,    0,  429,    2, 0x08 /* Private */,
      46,    0,  430,    2, 0x08 /* Private */,
      47,    0,  431,    2, 0x08 /* Private */,
      48,    0,  432,    2, 0x08 /* Private */,
      49,    0,  433,    2, 0x08 /* Private */,
      50,    0,  434,    2, 0x08 /* Private */,
      51,    0,  435,    2, 0x08 /* Private */,
      52,    0,  436,    2, 0x08 /* Private */,
      53,    0,  437,    2, 0x08 /* Private */,
      54,    0,  438,    2, 0x08 /* Private */,
      55,    0,  439,    2, 0x08 /* Private */,
      56,    0,  440,    2, 0x08 /* Private */,
      57,    0,  441,    2, 0x08 /* Private */,
      58,    0,  442,    2, 0x08 /* Private */,
      59,    0,  443,    2, 0x08 /* Private */,
      60,    0,  444,    2, 0x08 /* Private */,
      61,    0,  445,    2, 0x08 /* Private */,
      62,    0,  446,    2, 0x08 /* Private */,
      63,    0,  447,    2, 0x08 /* Private */,
      64,    0,  448,    2, 0x08 /* Private */,
      65,    0,  449,    2, 0x08 /* Private */,
      66,    0,  450,    2, 0x08 /* Private */,
      67,    0,  451,    2, 0x08 /* Private */,
      68,    0,  452,    2, 0x08 /* Private */,
      69,    0,  453,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->radioButton_0_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->radioButton_1_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->radioButton_2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->radioButton_3_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->radioButton_4_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->radioButton_5_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: { QString _r = _t->get_timeStamp();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->get_sensor_value_port_0(); break;
        case 8: _t->get_sensor_value_port_1(); break;
        case 9: _t->get_sensor_value_port_2(); break;
        case 10: _t->get_sensor_value_port_3(); break;
        case 11: _t->get_sensor_value_port_4(); break;
        case 12: _t->get_sensor_value_port_5(); break;
        case 13: _t->write_to_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->write_to_file_raw((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->setActiveSensor0((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->setActiveSensor1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->setActiveSensor2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->setActiveSensor3((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->setActiveSensor4((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->setActiveSensor5((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->delay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->setFontsizesAndBackgroundColors(); break;
        case 23: _t->setupSensors(); break;
        case 24: _t->startDialog(); break;
        case 25: _t->setPreInit(); break;
        case 26: _t->on_quitButtonStartMain_clicked(); break;
        case 27: _t->on_initialize_sensor_0_button_clicked(); break;
        case 28: _t->on_initialize_sensor_1_button_clicked(); break;
        case 29: _t->on_initialize_sensor_2_button_clicked(); break;
        case 30: _t->on_initialize_sensor_3_button_clicked(); break;
        case 31: _t->on_initialize_sensor_4_button_clicked(); break;
        case 32: _t->on_initialize_sensor_5_button_clicked(); break;
        case 33: _t->on_set_f1_button_clicked(); break;
        case 34: _t->on_set_m_button_clicked(); break;
        case 35: _t->on_set_dPhi1_button_clicked(); break;
        case 36: _t->on_set_dPhi2_button_clicked(); break;
        case 37: _t->on_set_dKSV1_button_clicked(); break;
        case 38: _t->on_set_dKSV2_button_clicked(); break;
        case 39: _t->on_quitButtonStartMain_2_clicked(); break;
        case 40: _t->on_allSet_o2_clicked(); break;
        case 41: _t->set_f1_value((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 42: _t->on_set_lmin_button_clicked(); break;
        case 43: _t->on_set_lmax_button_clicked(); break;
        case 44: _t->on_set_pH0_button_clicked(); break;
        case 45: _t->on_set_dpH_button_clicked(); break;
        case 46: _t->on_set_temp_button_clicked(); break;
        case 47: _t->on_quitButtonStartMain_3_clicked(); break;
        case 48: _t->on_allSet_pH_clicked(); break;
        case 49: _t->on_set_A1_button_clicked(); break;
        case 50: _t->on_set_A2_button_clicked(); break;
        case 51: _t->on_set_x0_button_clicked(); break;
        case 52: _t->on_set_dx_button_clicked(); break;
        case 53: _t->on_allSet_cO2_clicked(); break;
        case 54: _t->on_quitButtonStartMain_4_clicked(); break;
        case 55: _t->on_start_measurement_button_clicked(); break;
        case 56: _t->set_main_output_buttons(); break;
        case 57: _t->on_stopMeassurementButton_clicked(); break;
        case 58: _t->on_quitButton_clicked(); break;
        case 59: _t->on_set_temp_co2_button_clicked(); break;
        case 60: _t->rawVectorInit(); break;
        case 61: _t->on_lineEdit_returnPressed(); break;
        case 62: _t->setupGraphs(); break;
        case 63: _t->on_quitButtonSensor_1_clicked(); break;
        case 64: _t->on_quitButtonSensor_2_clicked(); break;
        case 65: _t->on_quitButtonSensor_3_clicked(); break;
        case 66: _t->on_plotButtonSensor_1_clicked(); break;
        case 67: _t->append_to_plotSeries(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::radioButton_0_toggled)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::radioButton_1_toggled)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::radioButton_2_toggled)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::radioButton_3_toggled)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::radioButton_4_toggled)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::radioButton_5_toggled)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 68)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 68;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 68)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 68;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::radioButton_0_toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::radioButton_1_toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::radioButton_2_toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::radioButton_3_toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::radioButton_4_toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::radioButton_5_toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
