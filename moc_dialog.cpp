/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[16];
    char stringdata0[296];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 18), // "checkBox_0_toggled"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 18), // "checkBox_1_toggled"
QT_MOC_LITERAL(4, 46, 18), // "checkBox_2_toggled"
QT_MOC_LITERAL(5, 65, 18), // "checkBox_3_toggled"
QT_MOC_LITERAL(6, 84, 18), // "checkBox_4_toggled"
QT_MOC_LITERAL(7, 103, 18), // "checkBox_5_toggled"
QT_MOC_LITERAL(8, 122, 21), // "on_checkBox_0_toggled"
QT_MOC_LITERAL(9, 144, 7), // "checked"
QT_MOC_LITERAL(10, 152, 21), // "on_checkBox_1_toggled"
QT_MOC_LITERAL(11, 174, 21), // "on_checkBox_2_toggled"
QT_MOC_LITERAL(12, 196, 21), // "on_checkBox_3_toggled"
QT_MOC_LITERAL(13, 218, 21), // "on_checkBox_4_toggled"
QT_MOC_LITERAL(14, 240, 21), // "on_checkBox_5_toggled"
QT_MOC_LITERAL(15, 262, 33) // "on_saveAndExit_pushButton_cli..."

    },
    "Dialog\0checkBox_0_toggled\0\0"
    "checkBox_1_toggled\0checkBox_2_toggled\0"
    "checkBox_3_toggled\0checkBox_4_toggled\0"
    "checkBox_5_toggled\0on_checkBox_0_toggled\0"
    "checked\0on_checkBox_1_toggled\0"
    "on_checkBox_2_toggled\0on_checkBox_3_toggled\0"
    "on_checkBox_4_toggled\0on_checkBox_5_toggled\0"
    "on_saveAndExit_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    1,   82,    2, 0x06 /* Public */,
       4,    1,   85,    2, 0x06 /* Public */,
       5,    1,   88,    2, 0x06 /* Public */,
       6,    1,   91,    2, 0x06 /* Public */,
       7,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   97,    2, 0x0a /* Public */,
      10,    1,  100,    2, 0x0a /* Public */,
      11,    1,  103,    2, 0x0a /* Public */,
      12,    1,  106,    2, 0x0a /* Public */,
      13,    1,  109,    2, 0x0a /* Public */,
      14,    1,  112,    2, 0x0a /* Public */,
      15,    0,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->checkBox_0_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->checkBox_1_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->checkBox_2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->checkBox_3_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->checkBox_4_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->checkBox_5_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_checkBox_0_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_checkBox_1_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_checkBox_2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_checkBox_3_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_checkBox_4_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_checkBox_5_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_saveAndExit_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::checkBox_0_toggled)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::checkBox_1_toggled)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::checkBox_2_toggled)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::checkBox_3_toggled)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::checkBox_4_toggled)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::checkBox_5_toggled)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog.data,
    qt_meta_data_Dialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Dialog::checkBox_0_toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dialog::checkBox_1_toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Dialog::checkBox_2_toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Dialog::checkBox_3_toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Dialog::checkBox_4_toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Dialog::checkBox_5_toggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
