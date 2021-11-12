/********************************************************************************
** Form generated from reading UI file 'CurveColorConfigWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVECOLORCONFIGWIDGET_H
#define UI_CURVECOLORCONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CurveColorConfigWidget
{
public:
    QGridLayout *gridLayout;
    QCheckBox *checkBoxAuto;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *labelColor;

    void setupUi(QWidget *CurveColorConfigWidget)
    {
        if (CurveColorConfigWidget->objectName().isEmpty())
            CurveColorConfigWidget->setObjectName(QStringLiteral("CurveColorConfigWidget"));
        CurveColorConfigWidget->resize(400, 23);
        gridLayout = new QGridLayout(CurveColorConfigWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        checkBoxAuto = new QCheckBox(CurveColorConfigWidget);
        checkBoxAuto->setObjectName(QStringLiteral("checkBoxAuto"));
        checkBoxAuto->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(checkBoxAuto, 0, 2, 1, 1);

        frame = new QFrame(CurveColorConfigWidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(0, 23));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        labelColor = new QLabel(frame);
        labelColor->setObjectName(QStringLiteral("labelColor"));
        labelColor->setCursor(QCursor(Qt::PointingHandCursor));
        labelColor->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelColor, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 0, 1, 1, 1);


        retranslateUi(CurveColorConfigWidget);

        QMetaObject::connectSlotsByName(CurveColorConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *CurveColorConfigWidget)
    {
        CurveColorConfigWidget->setWindowTitle(QApplication::translate("CurveColorConfigWidget", "Form", Q_NULLPTR));
        checkBoxAuto->setText(QApplication::translate("CurveColorConfigWidget", "Auto", Q_NULLPTR));
        labelColor->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CurveColorConfigWidget: public Ui_CurveColorConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVECOLORCONFIGWIDGET_H
