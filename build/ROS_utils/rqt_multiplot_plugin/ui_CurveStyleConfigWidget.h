/********************************************************************************
** Form generated from reading UI file 'CurveStyleConfigWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVESTYLECONFIGWIDGET_H
#define UI_CURVESTYLECONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include <rqt_multiplot/PenStyleComboBox.h>

QT_BEGIN_NAMESPACE

class Ui_CurveStyleConfigWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *line_5;
    QCheckBox *checkBoxStepsInvert;
    QRadioButton *radioButtonSticksOrientationVertical;
    QCheckBox *checkBoxLinesInterpolate;
    QRadioButton *radioButtonSteps;
    QRadioButton *radioButtonSticksOrientationHorizontal;
    QLineEdit *lineEditSticksBaseline;
    QLabel *labelSticksBaseline;
    QRadioButton *radioButtonLines;
    QGridLayout *gridLayout_2;
    rqt_multiplot::PenStyleComboBox *comboBoxPenStyle;
    QSpinBox *spinBoxPenWidth;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QCheckBox *checkBoxRenderAntialias;
    QSpacerItem *horizontalSpacer;
    QFrame *line_7;
    QFrame *line;
    QRadioButton *radioButtonSticks;
    QRadioButton *radioButtonPoints;

    void setupUi(QWidget *CurveStyleConfigWidget)
    {
        if (CurveStyleConfigWidget->objectName().isEmpty())
            CurveStyleConfigWidget->setObjectName(QStringLiteral("CurveStyleConfigWidget"));
        CurveStyleConfigWidget->resize(705, 98);
        gridLayout = new QGridLayout(CurveStyleConfigWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setVerticalSpacing(-1);
        line_5 = new QFrame(CurveStyleConfigWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 1, 5, 1, 1);

        checkBoxStepsInvert = new QCheckBox(CurveStyleConfigWidget);
        checkBoxStepsInvert->setObjectName(QStringLiteral("checkBoxStepsInvert"));

        gridLayout->addWidget(checkBoxStepsInvert, 2, 3, 1, 1);

        radioButtonSticksOrientationVertical = new QRadioButton(CurveStyleConfigWidget);
        radioButtonSticksOrientationVertical->setObjectName(QStringLiteral("radioButtonSticksOrientationVertical"));

        gridLayout->addWidget(radioButtonSticksOrientationVertical, 1, 4, 1, 1);

        checkBoxLinesInterpolate = new QCheckBox(CurveStyleConfigWidget);
        checkBoxLinesInterpolate->setObjectName(QStringLiteral("checkBoxLinesInterpolate"));

        gridLayout->addWidget(checkBoxLinesInterpolate, 0, 3, 1, 1);

        radioButtonSteps = new QRadioButton(CurveStyleConfigWidget);
        radioButtonSteps->setObjectName(QStringLiteral("radioButtonSteps"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radioButtonSteps->sizePolicy().hasHeightForWidth());
        radioButtonSteps->setSizePolicy(sizePolicy);

        gridLayout->addWidget(radioButtonSteps, 2, 0, 1, 2);

        radioButtonSticksOrientationHorizontal = new QRadioButton(CurveStyleConfigWidget);
        radioButtonSticksOrientationHorizontal->setObjectName(QStringLiteral("radioButtonSticksOrientationHorizontal"));

        gridLayout->addWidget(radioButtonSticksOrientationHorizontal, 1, 3, 1, 1);

        lineEditSticksBaseline = new QLineEdit(CurveStyleConfigWidget);
        lineEditSticksBaseline->setObjectName(QStringLiteral("lineEditSticksBaseline"));
        sizePolicy.setHeightForWidth(lineEditSticksBaseline->sizePolicy().hasHeightForWidth());
        lineEditSticksBaseline->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEditSticksBaseline, 1, 7, 1, 1);

        labelSticksBaseline = new QLabel(CurveStyleConfigWidget);
        labelSticksBaseline->setObjectName(QStringLiteral("labelSticksBaseline"));

        gridLayout->addWidget(labelSticksBaseline, 1, 6, 1, 1);

        radioButtonLines = new QRadioButton(CurveStyleConfigWidget);
        radioButtonLines->setObjectName(QStringLiteral("radioButtonLines"));
        sizePolicy.setHeightForWidth(radioButtonLines->sizePolicy().hasHeightForWidth());
        radioButtonLines->setSizePolicy(sizePolicy);

        gridLayout->addWidget(radioButtonLines, 0, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(5);
        comboBoxPenStyle = new rqt_multiplot::PenStyleComboBox(CurveStyleConfigWidget);
        comboBoxPenStyle->setObjectName(QStringLiteral("comboBoxPenStyle"));
        sizePolicy.setHeightForWidth(comboBoxPenStyle->sizePolicy().hasHeightForWidth());
        comboBoxPenStyle->setSizePolicy(sizePolicy);
        comboBoxPenStyle->setMaximumSize(QSize(16777215, 16777215));
        comboBoxPenStyle->setInsertPolicy(QComboBox::NoInsert);
        comboBoxPenStyle->setIconSize(QSize(50, 16));

        gridLayout_2->addWidget(comboBoxPenStyle, 1, 1, 1, 1);

        spinBoxPenWidth = new QSpinBox(CurveStyleConfigWidget);
        spinBoxPenWidth->setObjectName(QStringLiteral("spinBoxPenWidth"));
        sizePolicy.setHeightForWidth(spinBoxPenWidth->sizePolicy().hasHeightForWidth());
        spinBoxPenWidth->setSizePolicy(sizePolicy);
        spinBoxPenWidth->setMinimum(1);
        spinBoxPenWidth->setMaximum(100);

        gridLayout_2->addWidget(spinBoxPenWidth, 0, 1, 1, 1);

        label_3 = new QLabel(CurveStyleConfigWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(CurveStyleConfigWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);

        checkBoxRenderAntialias = new QCheckBox(CurveStyleConfigWidget);
        checkBoxRenderAntialias->setObjectName(QStringLiteral("checkBoxRenderAntialias"));

        gridLayout_2->addWidget(checkBoxRenderAntialias, 3, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 10, 4, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 8, 1, 1);

        line_7 = new QFrame(CurveStyleConfigWidget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_7, 0, 2, 4, 1);

        line = new QFrame(CurveStyleConfigWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 9, 4, 1);

        radioButtonSticks = new QRadioButton(CurveStyleConfigWidget);
        radioButtonSticks->setObjectName(QStringLiteral("radioButtonSticks"));
        sizePolicy.setHeightForWidth(radioButtonSticks->sizePolicy().hasHeightForWidth());
        radioButtonSticks->setSizePolicy(sizePolicy);

        gridLayout->addWidget(radioButtonSticks, 1, 0, 1, 2);

        radioButtonPoints = new QRadioButton(CurveStyleConfigWidget);
        radioButtonPoints->setObjectName(QStringLiteral("radioButtonPoints"));
        sizePolicy.setHeightForWidth(radioButtonPoints->sizePolicy().hasHeightForWidth());
        radioButtonPoints->setSizePolicy(sizePolicy);

        gridLayout->addWidget(radioButtonPoints, 3, 0, 1, 2);

        radioButtonLines->raise();
        radioButtonLines->raise();
        radioButtonSticks->raise();
        radioButtonSteps->raise();
        radioButtonPoints->raise();
        checkBoxLinesInterpolate->raise();
        radioButtonSticksOrientationHorizontal->raise();
        radioButtonSticksOrientationVertical->raise();
        labelSticksBaseline->raise();
        lineEditSticksBaseline->raise();
        checkBoxStepsInvert->raise();
        line_5->raise();
        line_7->raise();
        line->raise();

        retranslateUi(CurveStyleConfigWidget);

        comboBoxPenStyle->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(CurveStyleConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *CurveStyleConfigWidget)
    {
        CurveStyleConfigWidget->setWindowTitle(QApplication::translate("CurveStyleConfigWidget", "Form", Q_NULLPTR));
        checkBoxStepsInvert->setText(QApplication::translate("CurveStyleConfigWidget", "Invert", Q_NULLPTR));
        radioButtonSticksOrientationVertical->setText(QApplication::translate("CurveStyleConfigWidget", "Vertical", Q_NULLPTR));
        checkBoxLinesInterpolate->setText(QApplication::translate("CurveStyleConfigWidget", "Interpolate", Q_NULLPTR));
        radioButtonSteps->setText(QApplication::translate("CurveStyleConfigWidget", "Steps", Q_NULLPTR));
        radioButtonSticksOrientationHorizontal->setText(QApplication::translate("CurveStyleConfigWidget", "Horizontal", Q_NULLPTR));
        labelSticksBaseline->setText(QApplication::translate("CurveStyleConfigWidget", "Baseline:", Q_NULLPTR));
        radioButtonLines->setText(QApplication::translate("CurveStyleConfigWidget", "Lines", Q_NULLPTR));
        label_3->setText(QApplication::translate("CurveStyleConfigWidget", "Pen style:", Q_NULLPTR));
        label_4->setText(QApplication::translate("CurveStyleConfigWidget", "Pen width:", Q_NULLPTR));
        checkBoxRenderAntialias->setText(QApplication::translate("CurveStyleConfigWidget", "Antialias", Q_NULLPTR));
        radioButtonSticks->setText(QApplication::translate("CurveStyleConfigWidget", "Sticks", Q_NULLPTR));
        radioButtonPoints->setText(QApplication::translate("CurveStyleConfigWidget", "Points", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CurveStyleConfigWidget: public Ui_CurveStyleConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVESTYLECONFIGWIDGET_H
