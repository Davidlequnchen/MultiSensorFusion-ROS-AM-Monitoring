/****************************************************************************
** Meta object code from reading C++ file 'PlotConfigWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/rqt_multiplot_plugin/include/rqt_multiplot/PlotConfigWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlotConfigWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rqt_multiplot__PlotConfigWidget_t {
    QByteArrayData data[19];
    char stringdata0[406];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rqt_multiplot__PlotConfigWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rqt_multiplot__PlotConfigWidget_t qt_meta_stringdata_rqt_multiplot__PlotConfigWidget = {
    {
QT_MOC_LITERAL(0, 0, 31), // "rqt_multiplot::PlotConfigWidget"
QT_MOC_LITERAL(1, 32, 18), // "configTitleChanged"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 5), // "title"
QT_MOC_LITERAL(4, 58, 21), // "configPlotRateChanged"
QT_MOC_LITERAL(5, 80, 4), // "rate"
QT_MOC_LITERAL(6, 85, 28), // "lineEditTitleEditingFinished"
QT_MOC_LITERAL(7, 114, 25), // "pushButtonAddCurveClicked"
QT_MOC_LITERAL(8, 140, 26), // "pushButtonEditCurveClicked"
QT_MOC_LITERAL(9, 167, 29), // "pushButtonRemoveCurvesClicked"
QT_MOC_LITERAL(10, 197, 27), // "pushButtonCopyCurvesClicked"
QT_MOC_LITERAL(11, 225, 28), // "pushButtonPasteCurvesClicked"
QT_MOC_LITERAL(12, 254, 35), // "curveListWidgetItemSelectionC..."
QT_MOC_LITERAL(13, 290, 32), // "curveListWidgetItemDoubleClicked"
QT_MOC_LITERAL(14, 323, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(15, 340, 4), // "item"
QT_MOC_LITERAL(16, 345, 33), // "doubleSpinBoxPlotRateValueCha..."
QT_MOC_LITERAL(17, 379, 5), // "value"
QT_MOC_LITERAL(18, 385, 20) // "clipboardDataChanged"

    },
    "rqt_multiplot::PlotConfigWidget\0"
    "configTitleChanged\0\0title\0"
    "configPlotRateChanged\0rate\0"
    "lineEditTitleEditingFinished\0"
    "pushButtonAddCurveClicked\0"
    "pushButtonEditCurveClicked\0"
    "pushButtonRemoveCurvesClicked\0"
    "pushButtonCopyCurvesClicked\0"
    "pushButtonPasteCurvesClicked\0"
    "curveListWidgetItemSelectionChanged\0"
    "curveListWidgetItemDoubleClicked\0"
    "QListWidgetItem*\0item\0"
    "doubleSpinBoxPlotRateValueChanged\0"
    "value\0clipboardDataChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rqt_multiplot__PlotConfigWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    1,   77,    2, 0x08 /* Private */,
       6,    0,   80,    2, 0x08 /* Private */,
       7,    0,   81,    2, 0x08 /* Private */,
       8,    0,   82,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    1,   87,    2, 0x08 /* Private */,
      16,    1,   90,    2, 0x08 /* Private */,
      18,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Double,   17,
    QMetaType::Void,

       0        // eod
};

void rqt_multiplot::PlotConfigWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlotConfigWidget *_t = static_cast<PlotConfigWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->configTitleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->configPlotRateChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->lineEditTitleEditingFinished(); break;
        case 3: _t->pushButtonAddCurveClicked(); break;
        case 4: _t->pushButtonEditCurveClicked(); break;
        case 5: _t->pushButtonRemoveCurvesClicked(); break;
        case 6: _t->pushButtonCopyCurvesClicked(); break;
        case 7: _t->pushButtonPasteCurvesClicked(); break;
        case 8: _t->curveListWidgetItemSelectionChanged(); break;
        case 9: _t->curveListWidgetItemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->doubleSpinBoxPlotRateValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->clipboardDataChanged(); break;
        default: ;
        }
    }
}

const QMetaObject rqt_multiplot::PlotConfigWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_rqt_multiplot__PlotConfigWidget.data,
      qt_meta_data_rqt_multiplot__PlotConfigWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rqt_multiplot::PlotConfigWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rqt_multiplot::PlotConfigWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rqt_multiplot__PlotConfigWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int rqt_multiplot::PlotConfigWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
