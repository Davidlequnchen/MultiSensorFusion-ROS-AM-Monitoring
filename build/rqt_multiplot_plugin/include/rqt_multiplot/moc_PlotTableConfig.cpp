/****************************************************************************
** Meta object code from reading C++ file 'PlotTableConfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/PlotTableConfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlotTableConfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__PlotTableConfig_t {
    QByteArrayData data[15];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__PlotTableConfig_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__PlotTableConfig_t qt_meta_stringdata_rqt_multiplot__PlotTableConfig = {
    {
QT_MOC_LITERAL(0, 0, 30), // "rqt_multiplot::PlotTableConfig"
QT_MOC_LITERAL(1, 31, 22), // "backgroundColorChanged"
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 5), // "color"
QT_MOC_LITERAL(4, 61, 22), // "foregroundColorChanged"
QT_MOC_LITERAL(5, 84, 15), // "numPlotsChanged"
QT_MOC_LITERAL(6, 100, 6), // "size_t"
QT_MOC_LITERAL(7, 107, 7), // "numRows"
QT_MOC_LITERAL(8, 115, 10), // "numColumns"
QT_MOC_LITERAL(9, 126, 16), // "linkScaleChanged"
QT_MOC_LITERAL(10, 143, 4), // "link"
QT_MOC_LITERAL(11, 148, 17), // "linkCursorChanged"
QT_MOC_LITERAL(12, 166, 18), // "trackPointsChanged"
QT_MOC_LITERAL(13, 185, 5), // "track"
QT_MOC_LITERAL(14, 191, 17) // "plotConfigChanged"

    },
    "rqt_multiplot::PlotTableConfig\0"
    "backgroundColorChanged\0\0color\0"
    "foregroundColorChanged\0numPlotsChanged\0"
    "size_t\0numRows\0numColumns\0linkScaleChanged\0"
    "link\0linkCursorChanged\0trackPointsChanged\0"
    "track\0plotConfigChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__PlotTableConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       5,    2,   55,    2, 0x06 /* Public */,
       9,    1,   60,    2, 0x06 /* Public */,
      11,    1,   63,    2, 0x06 /* Public */,
      12,    1,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   13,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void rqt_multiplot::PlotTableConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlotTableConfig *_t = static_cast<PlotTableConfig *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backgroundColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->foregroundColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 2: _t->numPlotsChanged((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2]))); break;
        case 3: _t->linkScaleChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->linkCursorChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->trackPointsChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->plotConfigChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PlotTableConfig::*_t)(const QColor & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlotTableConfig::backgroundColorChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PlotTableConfig::*_t)(const QColor & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlotTableConfig::foregroundColorChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PlotTableConfig::*_t)(size_t , size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlotTableConfig::numPlotsChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PlotTableConfig::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlotTableConfig::linkScaleChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (PlotTableConfig::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlotTableConfig::linkCursorChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (PlotTableConfig::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlotTableConfig::trackPointsChanged)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::PlotTableConfig::staticMetaObject = {
    { &Config::staticMetaObject, qt_meta_stringdata_rqt_multiplot__PlotTableConfig.data,
      qt_meta_data_rqt_multiplot__PlotTableConfig,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::PlotTableConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::PlotTableConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__PlotTableConfig.stringdata0))
        return static_cast<void*>(this);
    return Config::qt_metacast(_clname);
}

int rqt_multiplot::PlotTableConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Config::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void rqt_multiplot::PlotTableConfig::backgroundColorChanged(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rqt_multiplot::PlotTableConfig::foregroundColorChanged(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rqt_multiplot::PlotTableConfig::numPlotsChanged(size_t _t1, size_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void rqt_multiplot::PlotTableConfig::linkScaleChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void rqt_multiplot::PlotTableConfig::linkCursorChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void rqt_multiplot::PlotTableConfig::trackPointsChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
