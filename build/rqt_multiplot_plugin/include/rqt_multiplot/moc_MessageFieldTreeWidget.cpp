/****************************************************************************
** Meta object code from reading C++ file 'MessageFieldTreeWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/MessageFieldTreeWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageFieldTreeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__MessageFieldTreeWidget_t {
    QByteArrayData data[10];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__MessageFieldTreeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__MessageFieldTreeWidget_t qt_meta_stringdata_rqt_multiplot__MessageFieldTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 37), // "rqt_multiplot::MessageFieldTr..."
QT_MOC_LITERAL(1, 38, 19), // "currentFieldChanged"
QT_MOC_LITERAL(2, 58, 0), // ""
QT_MOC_LITERAL(3, 59, 5), // "field"
QT_MOC_LITERAL(4, 65, 18), // "currentItemChanged"
QT_MOC_LITERAL(5, 84, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(6, 101, 7), // "current"
QT_MOC_LITERAL(7, 109, 8), // "previous"
QT_MOC_LITERAL(8, 118, 24), // "spinBoxIndexValueChanged"
QT_MOC_LITERAL(9, 143, 5) // "value"

    },
    "rqt_multiplot::MessageFieldTreeWidget\0"
    "currentFieldChanged\0\0field\0"
    "currentItemChanged\0QTreeWidgetItem*\0"
    "current\0previous\0spinBoxIndexValueChanged\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__MessageFieldTreeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   32,    2, 0x08 /* Private */,
       8,    1,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void rqt_multiplot::MessageFieldTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MessageFieldTreeWidget *_t = static_cast<MessageFieldTreeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentFieldChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->currentItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 2: _t->spinBoxIndexValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MessageFieldTreeWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageFieldTreeWidget::currentFieldChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::MessageFieldTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_rqt_multiplot__MessageFieldTreeWidget.data,
      qt_meta_data_rqt_multiplot__MessageFieldTreeWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::MessageFieldTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::MessageFieldTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__MessageFieldTreeWidget.stringdata0))
        return static_cast<void*>(this);
    return QTreeWidget::qt_metacast(_clname);
}

int rqt_multiplot::MessageFieldTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
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
void rqt_multiplot::MessageFieldTreeWidget::currentFieldChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
