/********************************************************************************
** Form generated from reading UI file 'PlotConfigDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTCONFIGDIALOG_H
#define UI_PLOTCONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <rqt_multiplot/PlotConfigWidget.h>

QT_BEGIN_NAMESPACE

class Ui_PlotConfigDialog
{
public:
    QGridLayout *gridLayout_2;
    rqt_multiplot::PlotConfigWidget *widgetPlotConfig;
    QDialogButtonBox *buttonBox;
    QFrame *line;

    void setupUi(QDialog *PlotConfigDialog)
    {
        if (PlotConfigDialog->objectName().isEmpty())
            PlotConfigDialog->setObjectName(QStringLiteral("PlotConfigDialog"));
        PlotConfigDialog->resize(885, 606);
        PlotConfigDialog->setSizeGripEnabled(false);
        gridLayout_2 = new QGridLayout(PlotConfigDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(5);
        widgetPlotConfig = new rqt_multiplot::PlotConfigWidget(PlotConfigDialog);
        widgetPlotConfig->setObjectName(QStringLiteral("widgetPlotConfig"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetPlotConfig->sizePolicy().hasHeightForWidth());
        widgetPlotConfig->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(widgetPlotConfig, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(PlotConfigDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 2, 0, 1, 1);

        line = new QFrame(PlotConfigDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 1, 0, 1, 1);


        retranslateUi(PlotConfigDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PlotConfigDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PlotConfigDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PlotConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *PlotConfigDialog)
    {
        PlotConfigDialog->setWindowTitle(QApplication::translate("PlotConfigDialog", "Configure Plot", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlotConfigDialog: public Ui_PlotConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTCONFIGDIALOG_H
