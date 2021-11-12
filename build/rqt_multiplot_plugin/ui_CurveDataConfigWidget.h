/********************************************************************************
** Form generated from reading UI file 'CurveDataConfigWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVEDATACONFIGWIDGET_H
#define UI_CURVEDATACONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CurveDataConfigWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *line_3;
    QRadioButton *radioButtonCircularBuffer;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line;
    QRadioButton *radioButtonList;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBoxCircularBufferCapacity;
    QLabel *label_2;
    QRadioButton *radioButtonVector;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *radioButtonTimeFrame;
    QDoubleSpinBox *doubleSpinBoxTimeFrameLength;
    QLabel *label_3;

    void setupUi(QWidget *CurveDataConfigWidget)
    {
        if (CurveDataConfigWidget->objectName().isEmpty())
            CurveDataConfigWidget->setObjectName(QStringLiteral("CurveDataConfigWidget"));
        CurveDataConfigWidget->resize(848, 27);
        gridLayout = new QGridLayout(CurveDataConfigWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        line_3 = new QFrame(CurveDataConfigWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 0, 8, 1, 1);

        radioButtonCircularBuffer = new QRadioButton(CurveDataConfigWidget);
        radioButtonCircularBuffer->setObjectName(QStringLiteral("radioButtonCircularBuffer"));

        gridLayout->addWidget(radioButtonCircularBuffer, 0, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        line = new QFrame(CurveDataConfigWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 1, 1);

        radioButtonList = new QRadioButton(CurveDataConfigWidget);
        radioButtonList->setObjectName(QStringLiteral("radioButtonList"));

        gridLayout->addWidget(radioButtonList, 0, 2, 1, 1);

        label = new QLabel(CurveDataConfigWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 14, 1, 1);

        spinBoxCircularBufferCapacity = new QSpinBox(CurveDataConfigWidget);
        spinBoxCircularBufferCapacity->setObjectName(QStringLiteral("spinBoxCircularBufferCapacity"));
        spinBoxCircularBufferCapacity->setMinimum(1);
        spinBoxCircularBufferCapacity->setMaximum(999999999);

        gridLayout->addWidget(spinBoxCircularBufferCapacity, 0, 7, 1, 1);

        label_2 = new QLabel(CurveDataConfigWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 11, 1, 1);

        radioButtonVector = new QRadioButton(CurveDataConfigWidget);
        radioButtonVector->setObjectName(QStringLiteral("radioButtonVector"));

        gridLayout->addWidget(radioButtonVector, 0, 0, 1, 1);

        line_2 = new QFrame(CurveDataConfigWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 10, 1, 1);

        radioButtonTimeFrame = new QRadioButton(CurveDataConfigWidget);
        radioButtonTimeFrame->setObjectName(QStringLiteral("radioButtonTimeFrame"));

        gridLayout->addWidget(radioButtonTimeFrame, 0, 9, 1, 1);

        doubleSpinBoxTimeFrameLength = new QDoubleSpinBox(CurveDataConfigWidget);
        doubleSpinBoxTimeFrameLength->setObjectName(QStringLiteral("doubleSpinBoxTimeFrameLength"));
        doubleSpinBoxTimeFrameLength->setMinimum(0.1);
        doubleSpinBoxTimeFrameLength->setMaximum(500);

        gridLayout->addWidget(doubleSpinBoxTimeFrameLength, 0, 12, 1, 1);

        label_3 = new QLabel(CurveDataConfigWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 13, 1, 1);


        retranslateUi(CurveDataConfigWidget);

        QMetaObject::connectSlotsByName(CurveDataConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *CurveDataConfigWidget)
    {
        CurveDataConfigWidget->setWindowTitle(QApplication::translate("CurveDataConfigWidget", "Form", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        radioButtonCircularBuffer->setToolTip(QApplication::translate("CurveDataConfigWidget", "Curve data is stored in a circular buffer with fixed capacity", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        radioButtonCircularBuffer->setText(QApplication::translate("CurveDataConfigWidget", "Circular buffer", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        radioButtonList->setToolTip(QApplication::translate("CurveDataConfigWidget", "Curve data is stored in a list with unbound capacity", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        radioButtonList->setText(QApplication::translate("CurveDataConfigWidget", "List", Q_NULLPTR));
        label->setText(QApplication::translate("CurveDataConfigWidget", "Capacity:", Q_NULLPTR));
        label_2->setText(QApplication::translate("CurveDataConfigWidget", "Length:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        radioButtonVector->setToolTip(QApplication::translate("CurveDataConfigWidget", "Curve data is stored in a vector with unbound capacity", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        radioButtonVector->setText(QApplication::translate("CurveDataConfigWidget", "Vector", Q_NULLPTR));
        radioButtonTimeFrame->setText(QApplication::translate("CurveDataConfigWidget", "Time frame", Q_NULLPTR));
        label_3->setText(QApplication::translate("CurveDataConfigWidget", "s", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CurveDataConfigWidget: public Ui_CurveDataConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVEDATACONFIGWIDGET_H
