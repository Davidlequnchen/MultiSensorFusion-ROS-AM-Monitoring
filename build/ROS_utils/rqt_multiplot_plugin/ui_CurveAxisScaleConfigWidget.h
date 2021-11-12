/********************************************************************************
** Form generated from reading UI file 'CurveAxisScaleConfigWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVEAXISSCALECONFIGWIDGET_H
#define UI_CURVEAXISSCALECONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CurveAxisScaleConfigWidget
{
public:
    QGridLayout *gridLayout;
    QRadioButton *radioButtonAbsolute;
    QRadioButton *radioButtonAuto;
    QRadioButton *radioButtonRelative;
    QLabel *label;
    QLineEdit *lineEditAbsoluteMinimum;
    QLineEdit *lineEditAbsoluteMaximum;
    QLineEdit *lineEditRelativeMinimum;
    QLineEdit *lineEditRelativeMaximum;
    QLabel *label_2;

    void setupUi(QWidget *CurveAxisScaleConfigWidget)
    {
        if (CurveAxisScaleConfigWidget->objectName().isEmpty())
            CurveAxisScaleConfigWidget->setObjectName(QStringLiteral("CurveAxisScaleConfigWidget"));
        CurveAxisScaleConfigWidget->resize(427, 75);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CurveAxisScaleConfigWidget->sizePolicy().hasHeightForWidth());
        CurveAxisScaleConfigWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(CurveAxisScaleConfigWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        radioButtonAbsolute = new QRadioButton(CurveAxisScaleConfigWidget);
        radioButtonAbsolute->setObjectName(QStringLiteral("radioButtonAbsolute"));

        gridLayout->addWidget(radioButtonAbsolute, 0, 0, 1, 1);

        radioButtonAuto = new QRadioButton(CurveAxisScaleConfigWidget);
        radioButtonAuto->setObjectName(QStringLiteral("radioButtonAuto"));

        gridLayout->addWidget(radioButtonAuto, 2, 0, 1, 1);

        radioButtonRelative = new QRadioButton(CurveAxisScaleConfigWidget);
        radioButtonRelative->setObjectName(QStringLiteral("radioButtonRelative"));

        gridLayout->addWidget(radioButtonRelative, 1, 0, 1, 1);

        label = new QLabel(CurveAxisScaleConfigWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 2, 1, 1);

        lineEditAbsoluteMinimum = new QLineEdit(CurveAxisScaleConfigWidget);
        lineEditAbsoluteMinimum->setObjectName(QStringLiteral("lineEditAbsoluteMinimum"));

        gridLayout->addWidget(lineEditAbsoluteMinimum, 0, 1, 1, 1);

        lineEditAbsoluteMaximum = new QLineEdit(CurveAxisScaleConfigWidget);
        lineEditAbsoluteMaximum->setObjectName(QStringLiteral("lineEditAbsoluteMaximum"));

        gridLayout->addWidget(lineEditAbsoluteMaximum, 0, 3, 1, 1);

        lineEditRelativeMinimum = new QLineEdit(CurveAxisScaleConfigWidget);
        lineEditRelativeMinimum->setObjectName(QStringLiteral("lineEditRelativeMinimum"));

        gridLayout->addWidget(lineEditRelativeMinimum, 1, 1, 1, 1);

        lineEditRelativeMaximum = new QLineEdit(CurveAxisScaleConfigWidget);
        lineEditRelativeMaximum->setObjectName(QStringLiteral("lineEditRelativeMaximum"));

        gridLayout->addWidget(lineEditRelativeMaximum, 1, 3, 1, 1);

        label_2 = new QLabel(CurveAxisScaleConfigWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 2, 1, 1);


        retranslateUi(CurveAxisScaleConfigWidget);

        QMetaObject::connectSlotsByName(CurveAxisScaleConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *CurveAxisScaleConfigWidget)
    {
        CurveAxisScaleConfigWidget->setWindowTitle(QApplication::translate("CurveAxisScaleConfigWidget", "Form", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        radioButtonAbsolute->setToolTip(QApplication::translate("CurveAxisScaleConfigWidget", "Absolute axis scale", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        radioButtonAbsolute->setText(QApplication::translate("CurveAxisScaleConfigWidget", "Absolute", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        radioButtonAuto->setToolTip(QApplication::translate("CurveAxisScaleConfigWidget", "Automatic axis scale", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        radioButtonAuto->setText(QApplication::translate("CurveAxisScaleConfigWidget", "Automatic", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        radioButtonRelative->setToolTip(QApplication::translate("CurveAxisScaleConfigWidget", "Relative axis scale", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        radioButtonRelative->setText(QApplication::translate("CurveAxisScaleConfigWidget", "Relative", Q_NULLPTR));
        label->setText(QApplication::translate("CurveAxisScaleConfigWidget", "-", Q_NULLPTR));
        label_2->setText(QApplication::translate("CurveAxisScaleConfigWidget", "-", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CurveAxisScaleConfigWidget: public Ui_CurveAxisScaleConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVEAXISSCALECONFIGWIDGET_H
