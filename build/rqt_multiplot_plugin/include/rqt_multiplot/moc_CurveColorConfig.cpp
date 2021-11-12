/****************************************************************************
** Meta object code from reading C++ file 'CurveColorConfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/CurveColorConfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CurveColorConfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__CurveColorConfig_t {
    QByteArrayData data[9];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__CurveColorConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__CurveColorConfig_t qt_meta_stringdata_rqt_multiplot__CurveColorConfig = {
    {
QT_MOC_LITERAL(0, 0, 31), // "rqt_multiplot::CurveColorConfig"
QT_MOC_LITERAL(1, 32, 11), // "typeChanged"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 4), // "type"
QT_MOC_LITERAL(4, 50, 21), // "autoColorIndexChanged"
QT_MOC_LITERAL(5, 72, 5), // "index"
QT_MOC_LITERAL(6, 78, 18), // "customColorChanged"
QT_MOC_LITERAL(7, 97, 5), // "color"
QT_MOC_LITERAL(8, 103, 19) // "currentColorChanged"

    },
    "rqt_multiplot::CurveColorConfig\0"
    "typeChanged\0\0type\0autoColorIndexChanged\0"
    "index\0customColorChanged\0color\0"
    "currentColorChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__CurveColorConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       8,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::UChar,    5,
    QMetaType::Void, QMetaType::QColor,    7,
    QMetaType::Void, QMetaType::QColor,    7,

       0        // eod
};

void rqt_multiplot::CurveColorConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CurveColorConfig *_t = static_cast<CurveColorConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->typeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->autoColorIndexChanged((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 2: _t->customColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 3: _t->currentColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CurveColorConfig::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveColorConfig::typeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CurveColorConfig::*_t)(unsigned char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveColorConfig::autoColorIndexChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CurveColorConfig::*_t)(const QColor & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveColorConfig::customColorChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CurveColorConfig::*_t)(const QColor & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveColorConfig::currentColorChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::CurveColorConfig::staticMetaObject = {
    { &Config::staticMetaObject, qt_meta_stringdata_rqt_multiplot__CurveColorConfig.data,
      qt_meta_data_rqt_multiplot__CurveColorConfig,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::CurveColorConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::CurveColorConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__CurveColorConfig.stringdata0))
        return static_cast<void*>(this);
    return Config::qt_metacast(_clname);
}

int rqt_multiplot::CurveColorConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Config::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void rqt_multiplot::CurveColorConfig::typeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rqt_multiplot::CurveColorConfig::autoColorIndexChanged(unsigned char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rqt_multiplot::CurveColorConfig::customColorChanged(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void rqt_multiplot::CurveColorConfig::currentColorChanged(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
