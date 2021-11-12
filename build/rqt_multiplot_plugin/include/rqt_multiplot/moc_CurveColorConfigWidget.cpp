/****************************************************************************
** Meta object code from reading C++ file 'CurveColorConfigWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/CurveColorConfigWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CurveColorConfigWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__CurveColorConfigWidget_t {
    QByteArrayData data[9];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__CurveColorConfigWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__CurveColorConfigWidget_t qt_meta_stringdata_rqt_multiplot__CurveColorConfigWidget = {
    {
QT_MOC_LITERAL(0, 0, 37), // "rqt_multiplot::CurveColorConf..."
QT_MOC_LITERAL(1, 38, 19), // "currentColorChanged"
QT_MOC_LITERAL(2, 58, 0), // ""
QT_MOC_LITERAL(3, 59, 5), // "color"
QT_MOC_LITERAL(4, 65, 17), // "configTypeChanged"
QT_MOC_LITERAL(5, 83, 4), // "type"
QT_MOC_LITERAL(6, 88, 25), // "configCurrentColorChanged"
QT_MOC_LITERAL(7, 114, 24), // "checkBoxAutoStateChanged"
QT_MOC_LITERAL(8, 139, 5) // "state"

    },
    "rqt_multiplot::CurveColorConfigWidget\0"
    "currentColorChanged\0\0color\0configTypeChanged\0"
    "type\0configCurrentColorChanged\0"
    "checkBoxAutoStateChanged\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__CurveColorConfigWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       7,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void rqt_multiplot::CurveColorConfigWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CurveColorConfigWidget *_t = static_cast<CurveColorConfigWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->configTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->configCurrentColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 3: _t->checkBoxAutoStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CurveColorConfigWidget::*_t)(const QColor & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveColorConfigWidget::currentColorChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::CurveColorConfigWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_rqt_multiplot__CurveColorConfigWidget.data,
      qt_meta_data_rqt_multiplot__CurveColorConfigWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::CurveColorConfigWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::CurveColorConfigWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__CurveColorConfigWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int rqt_multiplot::CurveColorConfigWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void rqt_multiplot::CurveColorConfigWidget::currentColorChanged(const QColor & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
