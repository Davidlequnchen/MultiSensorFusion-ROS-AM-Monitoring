/****************************************************************************
** Meta object code from reading C++ file 'CurveDataSequencer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/CurveDataSequencer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CurveDataSequencer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__CurveDataSequencer_t {
    QByteArrayData data[16];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__CurveDataSequencer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__CurveDataSequencer_t qt_meta_stringdata_rqt_multiplot__CurveDataSequencer = {
    {
QT_MOC_LITERAL(0, 0, 33), // "rqt_multiplot::CurveDataSeque..."
QT_MOC_LITERAL(1, 34, 10), // "subscribed"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 13), // "pointReceived"
QT_MOC_LITERAL(4, 60, 5), // "point"
QT_MOC_LITERAL(5, 66, 12), // "unsubscribed"
QT_MOC_LITERAL(6, 79, 23), // "configAxisConfigChanged"
QT_MOC_LITERAL(7, 103, 32), // "configSubscriberQueueSizeChanged"
QT_MOC_LITERAL(8, 136, 6), // "size_t"
QT_MOC_LITERAL(9, 143, 9), // "queueSize"
QT_MOC_LITERAL(10, 153, 25), // "subscriberMessageReceived"
QT_MOC_LITERAL(11, 179, 5), // "topic"
QT_MOC_LITERAL(12, 185, 7), // "Message"
QT_MOC_LITERAL(13, 193, 7), // "message"
QT_MOC_LITERAL(14, 201, 30), // "subscriberXAxisMessageReceived"
QT_MOC_LITERAL(15, 232, 30) // "subscriberYAxisMessageReceived"

    },
    "rqt_multiplot::CurveDataSequencer\0"
    "subscribed\0\0pointReceived\0point\0"
    "unsubscribed\0configAxisConfigChanged\0"
    "configSubscriberQueueSizeChanged\0"
    "size_t\0queueSize\0subscriberMessageReceived\0"
    "topic\0Message\0message\0"
    "subscriberXAxisMessageReceived\0"
    "subscriberYAxisMessageReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__CurveDataSequencer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       5,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   59,    2, 0x08 /* Private */,
       7,    1,   60,    2, 0x08 /* Private */,
      10,    2,   63,    2, 0x08 /* Private */,
      14,    2,   68,    2, 0x08 /* Private */,
      15,    2,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPointF,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 12,   11,   13,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 12,   11,   13,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 12,   11,   13,

       0        // eod
};

void rqt_multiplot::CurveDataSequencer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CurveDataSequencer *_t = static_cast<CurveDataSequencer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->subscribed(); break;
        case 1: _t->pointReceived((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 2: _t->unsubscribed(); break;
        case 3: _t->configAxisConfigChanged(); break;
        case 4: _t->configSubscriberQueueSizeChanged((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 5: _t->subscriberMessageReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const Message(*)>(_a[2]))); break;
        case 6: _t->subscriberXAxisMessageReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const Message(*)>(_a[2]))); break;
        case 7: _t->subscriberYAxisMessageReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const Message(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CurveDataSequencer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveDataSequencer::subscribed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CurveDataSequencer::*_t)(const QPointF & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveDataSequencer::pointReceived)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CurveDataSequencer::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CurveDataSequencer::unsubscribed)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::CurveDataSequencer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rqt_multiplot__CurveDataSequencer.data,
      qt_meta_data_rqt_multiplot__CurveDataSequencer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::CurveDataSequencer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::CurveDataSequencer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__CurveDataSequencer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int rqt_multiplot::CurveDataSequencer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void rqt_multiplot::CurveDataSequencer::subscribed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void rqt_multiplot::CurveDataSequencer::pointReceived(const QPointF & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rqt_multiplot::CurveDataSequencer::unsubscribed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
