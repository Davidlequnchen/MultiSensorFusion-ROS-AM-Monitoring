/****************************************************************************
** Meta object code from reading C++ file 'CurveDataConfigWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/CurveDataConfigWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CurveDataConfigWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__CurveDataConfigWidget_t {
    QByteArrayData data[17];
    char stringdata0[355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__CurveDataConfigWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__CurveDataConfigWidget_t qt_meta_stringdata_rqt_multiplot__CurveDataConfigWidget = {
    {
QT_MOC_LITERAL(0, 0, 36), // "rqt_multiplot::CurveDataConfi..."
QT_MOC_LITERAL(1, 37, 17), // "configTypeChanged"
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 4), // "type"
QT_MOC_LITERAL(4, 61, 35), // "configCircularBufferCapacityC..."
QT_MOC_LITERAL(5, 97, 6), // "size_t"
QT_MOC_LITERAL(6, 104, 8), // "capacity"
QT_MOC_LITERAL(7, 113, 28), // "configTimeFrameLengthChanged"
QT_MOC_LITERAL(8, 142, 6), // "length"
QT_MOC_LITERAL(9, 149, 24), // "radioButtonVectorToggled"
QT_MOC_LITERAL(10, 174, 7), // "checked"
QT_MOC_LITERAL(11, 182, 22), // "radioButtonListToggled"
QT_MOC_LITERAL(12, 205, 32), // "radioButtonCircularBufferToggled"
QT_MOC_LITERAL(13, 238, 27), // "radioButtonTimeFrameToggled"
QT_MOC_LITERAL(14, 266, 41), // "spinBoxCircularBufferCapacity..."
QT_MOC_LITERAL(15, 308, 5), // "value"
QT_MOC_LITERAL(16, 314, 40) // "doubleSpinBoxTimeFrameLengthV..."

    },
    "rqt_multiplot::CurveDataConfigWidget\0"
    "configTypeChanged\0\0type\0"
    "configCircularBufferCapacityChanged\0"
    "size_t\0capacity\0configTimeFrameLengthChanged\0"
    "length\0radioButtonVectorToggled\0checked\0"
    "radioButtonListToggled\0"
    "radioButtonCircularBufferToggled\0"
    "radioButtonTimeFrameToggled\0"
    "spinBoxCircularBufferCapacityValueChanged\0"
    "value\0doubleSpinBoxTimeFrameLengthValueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__CurveDataConfigWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    1,   62,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
       9,    1,   68,    2, 0x08 /* Private */,
      11,    1,   71,    2, 0x08 /* Private */,
      12,    1,   74,    2, 0x08 /* Private */,
      13,    1,   77,    2, 0x08 /* Private */,
      14,    1,   80,    2, 0x08 /* Private */,
      16,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Double,   15,

       0        // eod
};

void rqt_multiplot::CurveDataConfigWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CurveDataConfigWidget *_t = static_cast<CurveDataConfigWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->configTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->configCircularBufferCapacityChanged((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 2: _t->configTimeFrameLengthChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->radioButtonVectorToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->radioButtonListToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->radioButtonCircularBufferToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->radioButtonTimeFrameToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->spinBoxCircularBufferCapacityValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->doubleSpinBoxTimeFrameLengthValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject rqt_multiplot::CurveDataConfigWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_rqt_multiplot__CurveDataConfigWidget.data,
      qt_meta_data_rqt_multiplot__CurveDataConfigWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::CurveDataConfigWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::CurveDataConfigWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__CurveDataConfigWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int rqt_multiplot::CurveDataConfigWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
