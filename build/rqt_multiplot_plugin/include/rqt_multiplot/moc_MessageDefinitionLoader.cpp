/****************************************************************************
** Meta object code from reading C++ file 'MessageDefinitionLoader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/MessageDefinitionLoader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageDefinitionLoader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__MessageDefinitionLoader_t {
    QByteArrayData data[8];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__MessageDefinitionLoader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__MessageDefinitionLoader_t qt_meta_stringdata_rqt_multiplot__MessageDefinitionLoader = {
    {
QT_MOC_LITERAL(0, 0, 38), // "rqt_multiplot::MessageDefinit..."
QT_MOC_LITERAL(1, 39, 14), // "loadingStarted"
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 15), // "loadingFinished"
QT_MOC_LITERAL(4, 71, 13), // "loadingFailed"
QT_MOC_LITERAL(5, 85, 5), // "error"
QT_MOC_LITERAL(6, 91, 13), // "threadStarted"
QT_MOC_LITERAL(7, 105, 14) // "threadFinished"

    },
    "rqt_multiplot::MessageDefinitionLoader\0"
    "loadingStarted\0\0loadingFinished\0"
    "loadingFailed\0error\0threadStarted\0"
    "threadFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__MessageDefinitionLoader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    1,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void rqt_multiplot::MessageDefinitionLoader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MessageDefinitionLoader *_t = static_cast<MessageDefinitionLoader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadingStarted(); break;
        case 1: _t->loadingFinished(); break;
        case 2: _t->loadingFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->threadStarted(); break;
        case 4: _t->threadFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MessageDefinitionLoader::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageDefinitionLoader::loadingStarted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MessageDefinitionLoader::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageDefinitionLoader::loadingFinished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MessageDefinitionLoader::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageDefinitionLoader::loadingFailed)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::MessageDefinitionLoader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rqt_multiplot__MessageDefinitionLoader.data,
      qt_meta_data_rqt_multiplot__MessageDefinitionLoader,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::MessageDefinitionLoader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::MessageDefinitionLoader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__MessageDefinitionLoader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int rqt_multiplot::MessageDefinitionLoader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void rqt_multiplot::MessageDefinitionLoader::loadingStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void rqt_multiplot::MessageDefinitionLoader::loadingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void rqt_multiplot::MessageDefinitionLoader::loadingFailed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
