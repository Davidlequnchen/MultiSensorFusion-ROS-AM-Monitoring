/****************************************************************************
** Meta object code from reading C++ file 'CurveDataConfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/CurveDataConfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CurveDataConfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__CurveDataConfig_t {
    QByteArrayData data[9];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__CurveDataConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__CurveDataConfig_t qt_meta_stringdata_rqt_multiplot__CurveDataConfig = {
    {
QT_MOC_LITERAL(0, 0, 30), // "rqt_multiplot::CurveDataConfig"
QT_MOC_LITERAL(1, 31, 11), // "typeChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 4), // "type"
QT_MOC_LITERAL(4, 49, 29), // "circularBufferCapacityChanged"
QT_MOC_LITERAL(5, 79, 6), // "size_t"
QT_MOC_LITERAL(6, 86, 8), // "capacity"
QT_MOC_LITERAL(7, 95, 22), // "timeFrameLengthChanged"
QT_MOC_LITERAL(8, 118, 6) // "length"

    },
    "rqt_multiplot::CurveDataConfig\0"
    "typeChanged\0\0type\0circularBufferCapacityChanged\0"
    "size_t\0capacity\0timeFrameLengthChanged\0"
    "length"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__CurveDataConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,
       7,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Double,    8,

       0        // eod
};

void rqt_multiplot::CurveDataConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CurveDataConfig *_t = static_cast<CurveDataConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->typeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->circularBufferCapacityChanged((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 2: _t->timeFrameLengthChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CurveDataConfig::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveDataConfig::typeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CurveDataConfig::*_t)(size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveDataConfig::circularBufferCapacityChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CurveDataConfig::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveDataConfig::timeFrameLengthChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::CurveDataConfig::staticMetaObject = {
    { &Config::staticMetaObject, qt_meta_stringdata_rqt_multiplot__CurveDataConfig.data,
      qt_meta_data_rqt_multiplot__CurveDataConfig,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::CurveDataConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::CurveDataConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__CurveDataConfig.stringdata0))
        return static_cast<void*>(this);
    return Config::qt_metacast(_clname);
}

int rqt_multiplot::CurveDataConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Config::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void rqt_multiplot::CurveDataConfig::typeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rqt_multiplot::CurveDataConfig::circularBufferCapacityChanged(size_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rqt_multiplot::CurveDataConfig::timeFrameLengthChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
