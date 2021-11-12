/********************************************************************************
** Form generated from reading UI file 'CurveItemWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVEITEMWIDGET_H
#define UI_CURVEITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CurveItemWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *labelYAxis;
    QLabel *labelTitle;
    QLabel *labelXAxis;
    QFrame *frameColor;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *CurveItemWidget)
    {
        if (CurveItemWidget->objectName().isEmpty())
            CurveItemWidget->setObjectName(QStringLiteral("CurveItemWidget"));
        CurveItemWidget->resize(581, 61);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CurveItemWidget->sizePolicy().hasHeightForWidth());
        CurveItemWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(CurveItemWidget);
        gridLayout->setContentsMargins(4, 4, 4, 4);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        labelYAxis = new QLabel(CurveItemWidget);
        labelYAxis->setObjectName(QStringLiteral("labelYAxis"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelYAxis->sizePolicy().hasHeightForWidth());
        labelYAxis->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(labelYAxis, 4, 3, 1, 1);

        labelTitle = new QLabel(CurveItemWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);

        gridLayout->addWidget(labelTitle, 2, 2, 1, 2);

        labelXAxis = new QLabel(CurveItemWidget);
        labelXAxis->setObjectName(QStringLiteral("labelXAxis"));
        sizePolicy1.setHeightForWidth(labelXAxis->sizePolicy().hasHeightForWidth());
        labelXAxis->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(labelXAxis, 3, 3, 1, 1);

        frameColor = new QFrame(CurveItemWidget);
        frameColor->setObjectName(QStringLiteral("frameColor"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frameColor->sizePolicy().hasHeightForWidth());
        frameColor->setSizePolicy(sizePolicy2);
        frameColor->setMinimumSize(QSize(80, 0));
        frameColor->setFrameShape(QFrame::Box);
        frameColor->setFrameShadow(QFrame::Plain);
        gridLayout_2 = new QGridLayout(frameColor);
        gridLayout_2->setContentsMargins(4, 4, 4, 4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));

        gridLayout->addWidget(frameColor, 2, 1, 3, 1);

        label_2 = new QLabel(CurveItemWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 3, 2, 1, 1);

        label_3 = new QLabel(CurveItemWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 4, 2, 1, 1);


        retranslateUi(CurveItemWidget);

        QMetaObject::connectSlotsByName(CurveItemWidget);
    } // setupUi

    void retranslateUi(QWidget *CurveItemWidget)
    {
        CurveItemWidget->setWindowTitle(QApplication::translate("CurveItemWidget", "Form", Q_NULLPTR));
        labelYAxis->setText(QString());
        labelTitle->setText(QApplication::translate("CurveItemWidget", "Curve Title", Q_NULLPTR));
        labelXAxis->setText(QString());
        label_2->setText(QApplication::translate("CurveItemWidget", "X:", Q_NULLPTR));
        label_3->setText(QApplication::translate("CurveItemWidget", "Y:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CurveItemWidget: public Ui_CurveItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVEITEMWIDGET_H
