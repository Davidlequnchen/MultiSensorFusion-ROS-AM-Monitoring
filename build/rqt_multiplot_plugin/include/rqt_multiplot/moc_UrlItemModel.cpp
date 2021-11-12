/****************************************************************************
** Meta object code from reading C++ file 'UrlItemModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/UrlItemModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UrlItemModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__UrlItemModel_t {
    QByteArrayData data[9];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__UrlItemModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__UrlItemModel_t qt_meta_stringdata_rqt_multiplot__UrlItemModel = {
    {
QT_MOC_LITERAL(0, 0, 27), // "rqt_multiplot::UrlItemModel"
QT_MOC_LITERAL(1, 28, 9), // "urlLoaded"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 3), // "url"
QT_MOC_LITERAL(4, 43, 18), // "schemeResetStarted"
QT_MOC_LITERAL(5, 62, 19), // "schemeResetFinished"
QT_MOC_LITERAL(6, 82, 16), // "schemePathLoaded"
QT_MOC_LITERAL(7, 99, 4), // "host"
QT_MOC_LITERAL(8, 104, 4) // "path"

    },
    "rqt_multiplot::UrlItemModel\0urlLoaded\0"
    "\0url\0schemeResetStarted\0schemeResetFinished\0"
    "schemePathLoaded\0host\0path"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__UrlItemModel[] = {

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
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    2,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,

       0        // eod
};

void rqt_multiplot::UrlItemModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UrlItemModel *_t = static_cast<UrlItemModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->urlLoaded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->schemeResetStarted(); break;
        case 2: _t->schemeResetFinished(); break;
        case 3: _t->schemePathLoaded((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (UrlItemModel::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UrlItemModel::urlLoaded)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::UrlItemModel::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_rqt_multiplot__UrlItemModel.data,
      qt_meta_data_rqt_multiplot__UrlItemModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::UrlItemModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::UrlItemModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__UrlItemModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int rqt_multiplot::UrlItemModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
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
void rqt_multiplot::UrlItemModel::urlLoaded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
