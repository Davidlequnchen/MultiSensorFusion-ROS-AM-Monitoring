/********************************************************************************
** Form generated from reading UI file 'PlotLegendConfigWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTLEGENDCONFIGWIDGET_H
#define UI_PLOTLEGENDCONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlotLegendConfigWidget
{
public:
    QGridLayout *gridLayout;
    QCheckBox *checkBoxVisible;

    void setupUi(QWidget *PlotLegendConfigWidget)
    {
        if (PlotLegendConfigWidget->objectName().isEmpty())
            PlotLegendConfigWidget->setObjectName(QStringLiteral("PlotLegendConfigWidget"));
        PlotLegendConfigWidget->resize(632, 29);
        gridLayout = new QGridLayout(PlotLegendConfigWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        checkBoxVisible = new QCheckBox(PlotLegendConfigWidget);
        checkBoxVisible->setObjectName(QStringLiteral("checkBoxVisible"));

        gridLayout->addWidget(checkBoxVisible, 0, 0, 1, 1);


        retranslateUi(PlotLegendConfigWidget);

        QMetaObject::connectSlotsByName(PlotLegendConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *PlotLegendConfigWidget)
    {
        PlotLegendConfigWidget->setWindowTitle(QApplication::translate("PlotLegendConfigWidget", "Form", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        checkBoxVisible->setToolTip(QApplication::translate("PlotLegendConfigWidget", "Show/hide legend", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkBoxVisible->setText(QApplication::translate("PlotLegendConfigWidget", "Show", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlotLegendConfigWidget: public Ui_PlotLegendConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTLEGENDCONFIGWIDGET_H
