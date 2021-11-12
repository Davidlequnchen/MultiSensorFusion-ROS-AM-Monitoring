/****************************************************************************
** Meta object code from reading C++ file 'MessageTypeComboBox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/MessageTypeComboBox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MessageTypeComboBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__MessageTypeComboBox_t {
    QByteArrayData data[11];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__MessageTypeComboBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__MessageTypeComboBox_t qt_meta_stringdata_rqt_multiplot__MessageTypeComboBox = {
    {
QT_MOC_LITERAL(0, 0, 34), // "rqt_multiplot::MessageTypeCom..."
QT_MOC_LITERAL(1, 35, 13), // "updateStarted"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 14), // "updateFinished"
QT_MOC_LITERAL(4, 65, 18), // "currentTypeChanged"
QT_MOC_LITERAL(5, 84, 4), // "type"
QT_MOC_LITERAL(6, 89, 21), // "registryUpdateStarted"
QT_MOC_LITERAL(7, 111, 22), // "registryUpdateFinished"
QT_MOC_LITERAL(8, 134, 19), // "currentIndexChanged"
QT_MOC_LITERAL(9, 154, 4), // "text"
QT_MOC_LITERAL(10, 159, 23) // "lineEditEditingFinished"

    },
    "rqt_multiplot::MessageTypeComboBox\0"
    "updateStarted\0\0updateFinished\0"
    "currentTypeChanged\0type\0registryUpdateStarted\0"
    "registryUpdateFinished\0currentIndexChanged\0"
    "text\0lineEditEditingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__MessageTypeComboBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

       0        // eod
};

void rqt_multiplot::MessageTypeComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MessageTypeComboBox *_t = static_cast<MessageTypeComboBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateStarted(); break;
        case 1: _t->updateFinished(); break;
        case 2: _t->currentTypeChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->registryUpdateStarted(); break;
        case 4: _t->registryUpdateFinished(); break;
        case 5: _t->currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->lineEditEditingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MessageTypeComboBox::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageTypeComboBox::updateStarted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MessageTypeComboBox::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageTypeComboBox::updateFinished)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MessageTypeComboBox::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MessageTypeComboBox::currentTypeChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject rqt_multiplot::MessageTypeComboBox::staticMetaObject = {
    { &MatchFilterComboBox::staticMetaObject, qt_meta_stringdata_rqt_multiplot__MessageTypeComboBox.data,
      qt_meta_data_rqt_multiplot__MessageTypeComboBox,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::MessageTypeComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::MessageTypeComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__MessageTypeComboBox.stringdata0))
        return static_cast<void*>(this);
    return MatchFilterComboBox::qt_metacast(_clname);
}

int rqt_multiplot::MessageTypeComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MatchFilterComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void rqt_multiplot::MessageTypeComboBox::updateStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void rqt_multiplot::MessageTypeComboBox::updateFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void rqt_multiplot::MessageTypeComboBox::currentTypeChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
