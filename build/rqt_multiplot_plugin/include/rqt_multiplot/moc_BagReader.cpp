/****************************************************************************
** Meta object code from reading C++ file 'BagReader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/BagReader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BagReader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__BagReader_t {
    QByteArrayData data[15];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__BagReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__BagReader_t qt_meta_stringdata_rqt_multiplot__BagReader = {
    {
QT_MOC_LITERAL(0, 0, 24), // "rqt_multiplot::BagReader"
QT_MOC_LITERAL(1, 25, 14), // "readingStarted"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 11), // "messageRead"
QT_MOC_LITERAL(4, 53, 5), // "topic"
QT_MOC_LITERAL(5, 59, 7), // "Message"
QT_MOC_LITERAL(6, 67, 7), // "message"
QT_MOC_LITERAL(7, 75, 22), // "readingProgressChanged"
QT_MOC_LITERAL(8, 98, 8), // "progress"
QT_MOC_LITERAL(9, 107, 15), // "readingFinished"
QT_MOC_LITERAL(10, 123, 13), // "readingFailed"
QT_MOC_LITERAL(11, 137, 5), // "error"
QT_MOC_LITERAL(12, 143, 13), // "threadStarted"
QT_MOC_LITERAL(13, 157, 14), // "threadFinished"
QT_MOC_LITERAL(14, 172, 23) // "queryAboutToBeDestroyed"

    },
    "rqt_multiplot::BagReader\0readingStarted\0"
    "\0messageRead\0topic\0Message\0message\0"
    "readingProgressChanged\0progress\0"
    "readingFinished\0readingFailed\0error\0"
    "threadStarted\0threadFinished\0"
    "queryAboutToBeDestroyed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__BagReader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    2,   55,    2, 0x06 /* Public */,
       7,    1,   60,    2, 0x06 /* Public */,
       9,    0,   63,    2, 0x06 /* Public */,
      10,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   67,    2, 0x08 /* Private */,
      13,    0,   68,    2, 0x08 /* Private */,
      14,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5,    4,    6,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void rqt_multiplot::BagReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BagReader *_t = static_cast<BagReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readingStarted(); break;
        case 1: _t->messageRead((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const Message(*)>(_a[2]))); break;
        case 2: _t->readingProgressChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->readingFinished(); break;
        case 4: _t->readingFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->threadStarted(); break;
        case 6: _t->threadFinished(); break;
        case 7: _t->queryAboutToBeDestroyed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BagReader::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BagReader::readingStarted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BagReader::*_t)(const QString & , const Message & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BagReader::messageRead)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BagReader::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BagReader::readingProgressChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (BagReader::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BagReader::readingFinished)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (BagReader::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BagReader::readingFailed)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::BagReader::staticMetaObject = {
    { &MessageBroker::staticMetaObject, qt_meta_stringdata_rqt_multiplot__BagReader.data,
      qt_meta_data_rqt_multiplot__BagReader,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::BagReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::BagReader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__BagReader.stringdata0))
        return static_cast<void*>(this);
    return MessageBroker::qt_metacast(_clname);
}

int rqt_multiplot::BagReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MessageBroker::qt_metacall(_c, _id, _a);
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
void rqt_multiplot::BagReader::readingStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void rqt_multiplot::BagReader::messageRead(const QString & _t1, const Message & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rqt_multiplot::BagReader::readingProgressChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void rqt_multiplot::BagReader::readingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void rqt_multiplot::BagReader::readingFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
