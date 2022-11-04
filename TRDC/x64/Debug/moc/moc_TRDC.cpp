/****************************************************************************
** Meta object code from reading C++ file 'TRDC.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../inc/TRDC.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TRDC.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TRDC_t {
    QByteArrayData data[18];
    char stringdata0[352];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TRDC_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TRDC_t qt_meta_stringdata_TRDC = {
    {
QT_MOC_LITERAL(0, 0, 4), // "TRDC"
QT_MOC_LITERAL(1, 5, 6), // "signal"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 11), // "TRData::Ptr"
QT_MOC_LITERAL(4, 25, 4), // "data"
QT_MOC_LITERAL(5, 30, 14), // "ScanActivePort"
QT_MOC_LITERAL(6, 45, 21), // "sPeriodicallySendData"
QT_MOC_LITERAL(7, 67, 11), // "sTimeUpdate"
QT_MOC_LITERAL(8, 79, 25), // "on_pushButtonOpen_clicked"
QT_MOC_LITERAL(9, 105, 36), // "on_checkBoxPeriodicSend_state..."
QT_MOC_LITERAL(10, 142, 4), // "arg1"
QT_MOC_LITERAL(11, 147, 31), // "on_checkBoxReVTime_stateChanged"
QT_MOC_LITERAL(12, 179, 25), // "on_pushButtonSend_clicked"
QT_MOC_LITERAL(13, 205, 29), // "on_pushButtonClearRev_clicked"
QT_MOC_LITERAL(14, 235, 30), // "on_pushButtonClearSend_clicked"
QT_MOC_LITERAL(15, 266, 28), // "on_pushButtonStopRev_clicked"
QT_MOC_LITERAL(16, 295, 27), // "on_pushButtonRdFile_clicked"
QT_MOC_LITERAL(17, 323, 28) // "on_pushButtonSaveRev_clicked"

    },
    "TRDC\0signal\0\0TRData::Ptr\0data\0"
    "ScanActivePort\0sPeriodicallySendData\0"
    "sTimeUpdate\0on_pushButtonOpen_clicked\0"
    "on_checkBoxPeriodicSend_stateChanged\0"
    "arg1\0on_checkBoxReVTime_stateChanged\0"
    "on_pushButtonSend_clicked\0"
    "on_pushButtonClearRev_clicked\0"
    "on_pushButtonClearSend_clicked\0"
    "on_pushButtonStopRev_clicked\0"
    "on_pushButtonRdFile_clicked\0"
    "on_pushButtonSaveRev_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TRDC[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   82,    2, 0x08 /* Private */,
       6,    0,   85,    2, 0x08 /* Private */,
       7,    0,   86,    2, 0x08 /* Private */,
       8,    0,   87,    2, 0x08 /* Private */,
       9,    1,   88,    2, 0x08 /* Private */,
      11,    1,   91,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,
      16,    0,   98,    2, 0x08 /* Private */,
      17,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TRDC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TRDC *_t = static_cast<TRDC *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal((*reinterpret_cast< const TRData::Ptr(*)>(_a[1]))); break;
        case 1: _t->ScanActivePort((*reinterpret_cast< TRData::Ptr(*)>(_a[1]))); break;
        case 2: _t->sPeriodicallySendData(); break;
        case 3: _t->sTimeUpdate(); break;
        case 4: _t->on_pushButtonOpen_clicked(); break;
        case 5: _t->on_checkBoxPeriodicSend_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_checkBoxReVTime_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_pushButtonSend_clicked(); break;
        case 8: _t->on_pushButtonClearRev_clicked(); break;
        case 9: _t->on_pushButtonClearSend_clicked(); break;
        case 10: _t->on_pushButtonStopRev_clicked(); break;
        case 11: _t->on_pushButtonRdFile_clicked(); break;
        case 12: _t->on_pushButtonSaveRev_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TRDC::*_t)(const TRData::Ptr );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TRDC::signal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TRDC::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TRDC.data,
      qt_meta_data_TRDC,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TRDC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TRDC::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TRDC.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TRDC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void TRDC::signal(const TRData::Ptr _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
