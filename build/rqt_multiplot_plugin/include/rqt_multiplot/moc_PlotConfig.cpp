/****************************************************************************
** Meta object code from reading C++ file 'PlotConfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/PlotConfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlotConfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__PlotConfig_t {
    QByteArrayData data[15];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__PlotConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__PlotConfig_t qt_meta_stringdata_rqt_multiplot__PlotConfig = {
    {
QT_MOC_LITERAL(0, 0, 25), // "rqt_multiplot::PlotConfig"
QT_MOC_LITERAL(1, 26, 12), // "titleChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 5), // "title"
QT_MOC_LITERAL(4, 46, 10), // "curveAdded"
QT_MOC_LITERAL(5, 57, 6), // "size_t"
QT_MOC_LITERAL(6, 64, 5), // "index"
QT_MOC_LITERAL(7, 70, 12), // "curveRemoved"
QT_MOC_LITERAL(8, 83, 13), // "curvesCleared"
QT_MOC_LITERAL(9, 97, 18), // "curveConfigChanged"
QT_MOC_LITERAL(10, 116, 15), // "plotRateChanged"
QT_MOC_LITERAL(11, 132, 4), // "rate"
QT_MOC_LITERAL(12, 137, 20), // "curveConfigDestroyed"
QT_MOC_LITERAL(13, 158, 17), // "axesConfigChanged"
QT_MOC_LITERAL(14, 176, 19) // "legendConfigChanged"

    },
    "rqt_multiplot::PlotConfig\0titleChanged\0"
    "\0title\0curveAdded\0size_t\0index\0"
    "curveRemoved\0curvesCleared\0"
    "curveConfigChanged\0plotRateChanged\0"
    "rate\0curveConfigDestroyed\0axesConfigChanged\0"
    "legendConfigChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__PlotConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,
       8,    0,   73,    2, 0x06 /* Public */,
       9,    1,   74,    2, 0x06 /* Public */,
      10,    1,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Double,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void rqt_multiplot::PlotConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlotConfig *_t = static_cast<PlotConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->titleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->curveAdded((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 2: _t->curveRemoved((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 3: _t->curvesCleared(); break;
        case 4: _t->curveConfigChanged((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 5: _t->plotRateChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->curveConfigChanged(); break;
        case 7: _t->curveConfigDestroyed(); break;
        case 8: _t->axesConfigChanged(); break;
        case 9: _t->legendConfigChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PlotConfig::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlotConfig::titleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PlotConfig::*_t)(size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlotConfig::curveAdded)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PlotConfig::*_t)(size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlotConfig::curveRemoved)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PlotConfig::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlotConfig::curvesCleared)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (PlotConfig::*_t)(size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlotConfig::curveConfigChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (PlotConfig::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlotConfig::plotRateChanged)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::PlotConfig::staticMetaObject = {
    { &Config::staticMetaObject, qt_meta_stringdata_rqt_multiplot__PlotConfig.data,
      qt_meta_data_rqt_multiplot__PlotConfig,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::PlotConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::PlotConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__PlotConfig.stringdata0))
        return static_cast<void*>(this);
    return Config::qt_metacast(_clname);
}

int rqt_multiplot::PlotConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Config::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void rqt_multiplot::PlotConfig::titleChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rqt_multiplot::PlotConfig::curveAdded(size_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rqt_multiplot::PlotConfig::curveRemoved(size_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void rqt_multiplot::PlotConfig::curvesCleared()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void rqt_multiplot::PlotConfig::curveConfigChanged(size_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void rqt_multiplot::PlotConfig::plotRateChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
