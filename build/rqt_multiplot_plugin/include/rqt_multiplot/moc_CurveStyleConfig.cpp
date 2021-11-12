/****************************************************************************
** Meta object code from reading C++ file 'CurveStyleConfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/CurveStyleConfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CurveStyleConfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__CurveStyleConfig_t {
    QByteArrayData data[19];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__CurveStyleConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__CurveStyleConfig_t qt_meta_stringdata_rqt_multiplot__CurveStyleConfig = {
    {
QT_MOC_LITERAL(0, 0, 31), // "rqt_multiplot::CurveStyleConfig"
QT_MOC_LITERAL(1, 32, 11), // "typeChanged"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 4), // "type"
QT_MOC_LITERAL(4, 50, 23), // "linesInterpolateChanged"
QT_MOC_LITERAL(5, 74, 11), // "interpolate"
QT_MOC_LITERAL(6, 86, 24), // "sticksOrientationChanged"
QT_MOC_LITERAL(7, 111, 11), // "orientation"
QT_MOC_LITERAL(8, 123, 21), // "sticksBaselineChanged"
QT_MOC_LITERAL(9, 145, 8), // "baseline"
QT_MOC_LITERAL(10, 154, 18), // "stepsInvertChanged"
QT_MOC_LITERAL(11, 173, 6), // "invert"
QT_MOC_LITERAL(12, 180, 15), // "penWidthChanged"
QT_MOC_LITERAL(13, 196, 6), // "size_t"
QT_MOC_LITERAL(14, 203, 5), // "width"
QT_MOC_LITERAL(15, 209, 15), // "penStyleChanged"
QT_MOC_LITERAL(16, 225, 5), // "style"
QT_MOC_LITERAL(17, 231, 22), // "renderAntialiasChanged"
QT_MOC_LITERAL(18, 254, 9) // "antialias"

    },
    "rqt_multiplot::CurveStyleConfig\0"
    "typeChanged\0\0type\0linesInterpolateChanged\0"
    "interpolate\0sticksOrientationChanged\0"
    "orientation\0sticksBaselineChanged\0"
    "baseline\0stepsInvertChanged\0invert\0"
    "penWidthChanged\0size_t\0width\0"
    "penStyleChanged\0style\0renderAntialiasChanged\0"
    "antialias"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__CurveStyleConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,
       8,    1,   63,    2, 0x06 /* Public */,
      10,    1,   66,    2, 0x06 /* Public */,
      12,    1,   69,    2, 0x06 /* Public */,
      15,    1,   72,    2, 0x06 /* Public */,
      17,    1,   75,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Bool,   18,

       0        // eod
};

void rqt_multiplot::CurveStyleConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CurveStyleConfig *_t = static_cast<CurveStyleConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->typeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->linesInterpolateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sticksOrientationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sticksBaselineChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->stepsInvertChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->penWidthChanged((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 6: _t->penStyleChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->renderAntialiasChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CurveStyleConfig::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveStyleConfig::typeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CurveStyleConfig::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveStyleConfig::linesInterpolateChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CurveStyleConfig::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveStyleConfig::sticksOrientationChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CurveStyleConfig::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveStyleConfig::sticksBaselineChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CurveStyleConfig::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveStyleConfig::stepsInvertChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (CurveStyleConfig::*_t)(size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveStyleConfig::penWidthChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (CurveStyleConfig::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveStyleConfig::penStyleChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (CurveStyleConfig::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveStyleConfig::renderAntialiasChanged)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::CurveStyleConfig::staticMetaObject = {
    { &Config::staticMetaObject, qt_meta_stringdata_rqt_multiplot__CurveStyleConfig.data,
      qt_meta_data_rqt_multiplot__CurveStyleConfig,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::CurveStyleConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::CurveStyleConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__CurveStyleConfig.stringdata0))
        return static_cast<void*>(this);
    return Config::qt_metacast(_clname);
}

int rqt_multiplot::CurveStyleConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Config::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void rqt_multiplot::CurveStyleConfig::typeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rqt_multiplot::CurveStyleConfig::linesInterpolateChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rqt_multiplot::CurveStyleConfig::sticksOrientationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void rqt_multiplot::CurveStyleConfig::sticksBaselineChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void rqt_multiplot::CurveStyleConfig::stepsInvertChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void rqt_multiplot::CurveStyleConfig::penWidthChanged(size_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void rqt_multiplot::CurveStyleConfig::penStyleChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void rqt_multiplot::CurveStyleConfig::renderAntialiasChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
