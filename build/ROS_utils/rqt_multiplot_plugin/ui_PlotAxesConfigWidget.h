/********************************************************************************
** Form generated from reading UI file 'PlotAxesConfigWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTAXESCONFIGWIDGET_H
#define UI_PLOTAXESCONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <rqt_multiplot/PlotAxisConfigWidget.h>

QT_BEGIN_NAMESPACE

class Ui_PlotAxesConfigWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    rqt_multiplot::PlotAxisConfigWidget *plotAxisConfigWidgetX;
    rqt_multiplot::PlotAxisConfigWidget *plotAxisConfigWidgetY;
    QFrame *line;

    void setupUi(QWidget *PlotAxesConfigWidget)
    {
        if (PlotAxesConfigWidget->objectName().isEmpty())
            PlotAxesConfigWidget->setObjectName(QStringLiteral("PlotAxesConfigWidget"));
        PlotAxesConfigWidget->resize(582, 58);
        gridLayout = new QGridLayout(PlotAxesConfigWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        label = new QLabel(PlotAxesConfigWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 23));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(PlotAxesConfigWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 23));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        plotAxisConfigWidgetX = new rqt_multiplot::PlotAxisConfigWidget(PlotAxesConfigWidget);
        plotAxisConfigWidgetX->setObjectName(QStringLiteral("plotAxisConfigWidgetX"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plotAxisConfigWidgetX->sizePolicy().hasHeightForWidth());
        plotAxisConfigWidgetX->setSizePolicy(sizePolicy);
        plotAxisConfigWidgetX->setMinimumSize(QSize(0, 23));

        gridLayout->addWidget(plotAxisConfigWidgetX, 1, 0, 1, 1);

        plotAxisConfigWidgetY = new rqt_multiplot::PlotAxisConfigWidget(PlotAxesConfigWidget);
        plotAxisConfigWidgetY->setObjectName(QStringLiteral("plotAxisConfigWidgetY"));
        sizePolicy.setHeightForWidth(plotAxisConfigWidgetY->sizePolicy().hasHeightForWidth());
        plotAxisConfigWidgetY->setSizePolicy(sizePolicy);
        plotAxisConfigWidgetY->setMinimumSize(QSize(0, 23));

        gridLayout->addWidget(plotAxisConfigWidgetY, 1, 2, 1, 1);

        line = new QFrame(PlotAxesConfigWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 2, 1);


        retranslateUi(PlotAxesConfigWidget);

        QMetaObject::connectSlotsByName(PlotAxesConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *PlotAxesConfigWidget)
    {
        PlotAxesConfigWidget->setWindowTitle(QApplication::translate("PlotAxesConfigWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("PlotAxesConfigWidget", "X-Axis:", Q_NULLPTR));
        label_2->setText(QApplication::translate("PlotAxesConfigWidget", "Y-Axis:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlotAxesConfigWidget: public Ui_PlotAxesConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTAXESCONFIGWIDGET_H
