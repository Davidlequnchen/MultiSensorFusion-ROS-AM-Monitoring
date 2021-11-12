/****************************************************************************
** Meta object code from reading C++ file 'CurveConfigWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/CurveConfigWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CurveConfigWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__CurveConfigWidget_t {
    QByteArrayData data[17];
    char stringdata0[326];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__CurveConfigWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__CurveConfigWidget_t qt_meta_stringdata_rqt_multiplot__CurveConfigWidget = {
    {
QT_MOC_LITERAL(0, 0, 32), // "rqt_multiplot::CurveConfigWidget"
QT_MOC_LITERAL(1, 33, 18), // "configTitleChanged"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 5), // "title"
QT_MOC_LITERAL(4, 59, 32), // "configSubscriberQueueSizeChanged"
QT_MOC_LITERAL(5, 92, 6), // "size_t"
QT_MOC_LITERAL(6, 99, 9), // "queueSize"
QT_MOC_LITERAL(7, 109, 28), // "configAxisConfigTopicChanged"
QT_MOC_LITERAL(8, 138, 5), // "topic"
QT_MOC_LITERAL(9, 144, 27), // "configAxisConfigTypeChanged"
QT_MOC_LITERAL(10, 172, 4), // "type"
QT_MOC_LITERAL(11, 177, 28), // "lineEditTitleEditingFinished"
QT_MOC_LITERAL(12, 206, 26), // "pushButtonCopyRightClicked"
QT_MOC_LITERAL(13, 233, 25), // "pushButtonCopyLeftClicked"
QT_MOC_LITERAL(14, 259, 21), // "pushButtonSwapClicked"
QT_MOC_LITERAL(15, 281, 38), // "spinBoxSubscriberQueueSizeVal..."
QT_MOC_LITERAL(16, 320, 5) // "value"

    },
    "rqt_multiplot::CurveConfigWidget\0"
    "configTitleChanged\0\0title\0"
    "configSubscriberQueueSizeChanged\0"
    "size_t\0queueSize\0configAxisConfigTopicChanged\0"
    "topic\0configAxisConfigTypeChanged\0"
    "type\0lineEditTitleEditingFinished\0"
    "pushButtonCopyRightClicked\0"
    "pushButtonCopyLeftClicked\0"
    "pushButtonSwapClicked\0"
    "spinBoxSubscriberQueueSizeValueChanged\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__CurveConfigWidget[] = {

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
      11,    0,   71,    2, 0x08 /* Private */,
      12,    0,   72,    2, 0x08 /* Private */,
      13,    0,   73,    2, 0x08 /* Private */,
      14,    0,   74,    2, 0x08 /* Private */,
      15,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void rqt_multiplot::CurveConfigWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CurveConfigWidget *_t = static_cast<CurveConfigWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->configTitleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->configSubscriberQueueSizeChanged((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 2: _t->configAxisConfigTopicChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->configAxisConfigTypeChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->lineEditTitleEditingFinished(); break;
        case 5: _t->pushButtonCopyRightClicked(); break;
        case 6: _t->pushButtonCopyLeftClicked(); break;
        case 7: _t->pushButtonSwapClicked(); break;
        case 8: _t->spinBoxSubscriberQueueSizeValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject rqt_multiplot::CurveConfigWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_rqt_multiplot__CurveConfigWidget.data,
      qt_meta_data_rqt_multiplot__CurveConfigWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::CurveConfigWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::CurveConfigWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__CurveConfigWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int rqt_multiplot::CurveConfigWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
