/****************************************************************************
** Meta object code from reading C++ file 'MessageFieldWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/MessageFieldWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageFieldWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__MessageFieldWidget_t {
    QByteArrayData data[22];
    char stringdata0[351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__MessageFieldWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__MessageFieldWidget_t qt_meta_stringdata_rqt_multiplot__MessageFieldWidget = {
    {
QT_MOC_LITERAL(0, 0, 33), // "rqt_multiplot::MessageFieldWi..."
QT_MOC_LITERAL(1, 34, 14), // "loadingStarted"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 15), // "loadingFinished"
QT_MOC_LITERAL(4, 66, 13), // "loadingFailed"
QT_MOC_LITERAL(5, 80, 5), // "error"
QT_MOC_LITERAL(6, 86, 10), // "connecting"
QT_MOC_LITERAL(7, 97, 5), // "topic"
QT_MOC_LITERAL(8, 103, 9), // "connected"
QT_MOC_LITERAL(9, 113, 17), // "connectionTimeout"
QT_MOC_LITERAL(10, 131, 7), // "timeout"
QT_MOC_LITERAL(11, 139, 19), // "currentFieldChanged"
QT_MOC_LITERAL(12, 159, 5), // "field"
QT_MOC_LITERAL(13, 165, 20), // "loaderLoadingStarted"
QT_MOC_LITERAL(14, 186, 21), // "loaderLoadingFinished"
QT_MOC_LITERAL(15, 208, 19), // "loaderLoadingFailed"
QT_MOC_LITERAL(16, 228, 25), // "subscriberMessageReceived"
QT_MOC_LITERAL(17, 254, 7), // "Message"
QT_MOC_LITERAL(18, 262, 7), // "message"
QT_MOC_LITERAL(19, 270, 22), // "connectionTimerTimeout"
QT_MOC_LITERAL(20, 293, 27), // "lineEditCurrentFieldChanged"
QT_MOC_LITERAL(21, 321, 29) // "treeWidgetCurrentFieldChanged"

    },
    "rqt_multiplot::MessageFieldWidget\0"
    "loadingStarted\0\0loadingFinished\0"
    "loadingFailed\0error\0connecting\0topic\0"
    "connected\0connectionTimeout\0timeout\0"
    "currentFieldChanged\0field\0"
    "loaderLoadingStarted\0loaderLoadingFinished\0"
    "loaderLoadingFailed\0subscriberMessageReceived\0"
    "Message\0message\0connectionTimerTimeout\0"
    "lineEditCurrentFieldChanged\0"
    "treeWidgetCurrentFieldChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__MessageFieldWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    1,   86,    2, 0x06 /* Public */,
       6,    1,   89,    2, 0x06 /* Public */,
       8,    1,   92,    2, 0x06 /* Public */,
       9,    2,   95,    2, 0x06 /* Public */,
      11,    1,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  103,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    1,  105,    2, 0x08 /* Private */,
      16,    2,  108,    2, 0x08 /* Private */,
      19,    0,  113,    2, 0x08 /* Private */,
      20,    1,  114,    2, 0x08 /* Private */,
      21,    1,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Double,    7,   10,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 17,    7,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void rqt_multiplot::MessageFieldWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MessageFieldWidget *_t = static_cast<MessageFieldWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadingStarted(); break;
        case 1: _t->loadingFinished(); break;
        case 2: _t->loadingFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->connecting((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->connected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->connectionTimeout((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 6: _t->currentFieldChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->loaderLoadingStarted(); break;
        case 8: _t->loaderLoadingFinished(); break;
        case 9: _t->loaderLoadingFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->subscriberMessageReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const Message(*)>(_a[2]))); break;
        case 11: _t->connectionTimerTimeout(); break;
        case 12: _t->lineEditCurrentFieldChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->treeWidgetCurrentFieldChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MessageFieldWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageFieldWidget::loadingStarted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MessageFieldWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageFieldWidget::loadingFinished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MessageFieldWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageFieldWidget::loadingFailed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MessageFieldWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageFieldWidget::connecting)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MessageFieldWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageFieldWidget::connected)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MessageFieldWidget::*_t)(const QString & , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageFieldWidget::connectionTimeout)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MessageFieldWidget::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageFieldWidget::currentFieldChanged)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::MessageFieldWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_rqt_multiplot__MessageFieldWidget.data,
      qt_meta_data_rqt_multiplot__MessageFieldWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::MessageFieldWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::MessageFieldWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__MessageFieldWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int rqt_multiplot::MessageFieldWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void rqt_multiplot::MessageFieldWidget::loadingStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void rqt_multiplot::MessageFieldWidget::loadingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void rqt_multiplot::MessageFieldWidget::loadingFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void rqt_multiplot::MessageFieldWidget::connecting(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void rqt_multiplot::MessageFieldWidget::connected(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void rqt_multiplot::MessageFieldWidget::connectionTimeout(const QString & _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void rqt_multiplot::MessageFieldWidget::currentFieldChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
