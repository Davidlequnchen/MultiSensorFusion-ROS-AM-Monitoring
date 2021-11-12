/****************************************************************************
** Meta object code from reading C++ file 'BagQuery.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/BagQuery.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BagQuery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__BagQuery_t {
    QByteArrayData data[7];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__BagQuery_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__BagQuery_t qt_meta_stringdata_rqt_multiplot__BagQuery = {
    {
QT_MOC_LITERAL(0, 0, 23), // "rqt_multiplot::BagQuery"
QT_MOC_LITERAL(1, 24, 11), // "messageRead"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 5), // "topic"
QT_MOC_LITERAL(4, 43, 7), // "Message"
QT_MOC_LITERAL(5, 51, 7), // "message"
QT_MOC_LITERAL(6, 59, 18) // "aboutToBeDestroyed"

    },
    "rqt_multiplot::BagQuery\0messageRead\0"
    "\0topic\0Message\0message\0aboutToBeDestroyed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__BagQuery[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       6,    0,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void,

       0        // eod
};

void rqt_multiplot::BagQuery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BagQuery *_t = static_cast<BagQuery *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->messageRead((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const Message(*)>(_a[2]))); break;
        case 1: _t->aboutToBeDestroyed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BagQuery::*_t)(const QString & , const Message & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BagQuery::messageRead)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BagQuery::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BagQuery::aboutToBeDestroyed)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::BagQuery::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rqt_multiplot__BagQuery.data,
      qt_meta_data_rqt_multiplot__BagQuery,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::BagQuery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::BagQuery::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__BagQuery.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int rqt_multiplot::BagQuery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void rqt_multiplot::BagQuery::messageRead(const QString & _t1, const Message & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void rqt_multiplot::BagQuery::aboutToBeDestroyed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
