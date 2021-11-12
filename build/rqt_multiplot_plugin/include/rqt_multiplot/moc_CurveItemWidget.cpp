/****************************************************************************
** Meta object code from reading C++ file 'CurveItemWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/CurveItemWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CurveItemWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__CurveItemWidget_t {
    QByteArrayData data[8];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__CurveItemWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__CurveItemWidget_t qt_meta_stringdata_rqt_multiplot__CurveItemWidget = {
    {
QT_MOC_LITERAL(0, 0, 30), // "rqt_multiplot::CurveItemWidget"
QT_MOC_LITERAL(1, 31, 18), // "configTitleChanged"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 5), // "title"
QT_MOC_LITERAL(4, 57, 24), // "configXAxisConfigChanged"
QT_MOC_LITERAL(5, 82, 24), // "configYAxisConfigChanged"
QT_MOC_LITERAL(6, 107, 36), // "configColorConfigCurrentColor..."
QT_MOC_LITERAL(7, 144, 5) // "color"

    },
    "rqt_multiplot::CurveItemWidget\0"
    "configTitleChanged\0\0title\0"
    "configXAxisConfigChanged\0"
    "configYAxisConfigChanged\0"
    "configColorConfigCurrentColorChanged\0"
    "color"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__CurveItemWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    1,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,    7,

       0        // eod
};

void rqt_multiplot::CurveItemWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CurveItemWidget *_t = static_cast<CurveItemWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->configTitleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->configXAxisConfigChanged(); break;
        case 2: _t->configYAxisConfigChanged(); break;
        case 3: _t->configColorConfigCurrentColorChanged((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject rqt_multiplot::CurveItemWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_rqt_multiplot__CurveItemWidget.data,
      qt_meta_data_rqt_multiplot__CurveItemWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::CurveItemWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::CurveItemWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__CurveItemWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int rqt_multiplot::CurveItemWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
