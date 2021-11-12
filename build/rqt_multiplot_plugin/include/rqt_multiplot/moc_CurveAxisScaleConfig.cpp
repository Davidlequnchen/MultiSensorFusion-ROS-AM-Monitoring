/****************************************************************************
** Meta object code from reading C++ file 'CurveAxisScaleConfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/CurveAxisScaleConfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CurveAxisScaleConfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__CurveAxisScaleConfig_t {
    QByteArrayData data[10];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__CurveAxisScaleConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__CurveAxisScaleConfig_t qt_meta_stringdata_rqt_multiplot__CurveAxisScaleConfig = {
    {
QT_MOC_LITERAL(0, 0, 35), // "rqt_multiplot::CurveAxisScale..."
QT_MOC_LITERAL(1, 36, 11), // "typeChanged"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 4), // "type"
QT_MOC_LITERAL(4, 54, 22), // "absoluteMinimumChanged"
QT_MOC_LITERAL(5, 77, 7), // "minimum"
QT_MOC_LITERAL(6, 85, 22), // "absoluteMaximumChanged"
QT_MOC_LITERAL(7, 108, 8), // "maxnimum"
QT_MOC_LITERAL(8, 117, 22), // "relativeMinimumChanged"
QT_MOC_LITERAL(9, 140, 22) // "relativeMaximumChanged"

    },
    "rqt_multiplot::CurveAxisScaleConfig\0"
    "typeChanged\0\0type\0absoluteMinimumChanged\0"
    "minimum\0absoluteMaximumChanged\0maxnimum\0"
    "relativeMinimumChanged\0relativeMaximumChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__CurveAxisScaleConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,
       8,    1,   48,    2, 0x06 /* Public */,
       9,    1,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    7,

       0        // eod
};

void rqt_multiplot::CurveAxisScaleConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CurveAxisScaleConfig *_t = static_cast<CurveAxisScaleConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->typeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->absoluteMinimumChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->absoluteMaximumChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->relativeMinimumChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->relativeMaximumChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CurveAxisScaleConfig::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveAxisScaleConfig::typeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CurveAxisScaleConfig::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveAxisScaleConfig::absoluteMinimumChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CurveAxisScaleConfig::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveAxisScaleConfig::absoluteMaximumChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CurveAxisScaleConfig::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveAxisScaleConfig::relativeMinimumChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CurveAxisScaleConfig::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveAxisScaleConfig::relativeMaximumChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::CurveAxisScaleConfig::staticMetaObject = {
    { &Config::staticMetaObject, qt_meta_stringdata_rqt_multiplot__CurveAxisScaleConfig.data,
      qt_meta_data_rqt_multiplot__CurveAxisScaleConfig,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::CurveAxisScaleConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::CurveAxisScaleConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__CurveAxisScaleConfig.stringdata0))
        return static_cast<void*>(this);
    return Config::qt_metacast(_clname);
}

int rqt_multiplot::CurveAxisScaleConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Config::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void rqt_multiplot::CurveAxisScaleConfig::typeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rqt_multiplot::CurveAxisScaleConfig::absoluteMinimumChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rqt_multiplot::CurveAxisScaleConfig::absoluteMaximumChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void rqt_multiplot::CurveAxisScaleConfig::relativeMinimumChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void rqt_multiplot::CurveAxisScaleConfig::relativeMaximumChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
