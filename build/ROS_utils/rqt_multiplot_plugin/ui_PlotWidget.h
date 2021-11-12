/********************************************************************************
** Form generated from reading UI file 'PlotWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTWIDGET_H
#define UI_PLOTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "rqt_multiplot/QwtPlotCustom.h"

QT_BEGIN_NAMESPACE

class Ui_PlotWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacerLeft;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonRunPause;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonImportExport;
    QPushButton *pushButtonSetup;
    QPushButton *pushButtonState;
    QSpacerItem *horizontalSpacerRight;
    rqt_multiplot::QwtPlotCustom *plot;
    QLineEdit *lineEditTitle;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *PlotWidget)
    {
        if (PlotWidget->objectName().isEmpty())
            PlotWidget->setObjectName(QStringLiteral("PlotWidget"));
        PlotWidget->resize(704, 434);
        gridLayout = new QGridLayout(PlotWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacerLeft = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacerLeft, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonRunPause = new QPushButton(PlotWidget);
        pushButtonRunPause->setObjectName(QStringLiteral("pushButtonRunPause"));
        pushButtonRunPause->setMinimumSize(QSize(22, 22));
        pushButtonRunPause->setMaximumSize(QSize(22, 22));
        pushButtonRunPause->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral("../resource/16x16/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRunPause->setIcon(icon);
        pushButtonRunPause->setFlat(true);

        horizontalLayout->addWidget(pushButtonRunPause);

        pushButtonClear = new QPushButton(PlotWidget);
        pushButtonClear->setObjectName(QStringLiteral("pushButtonClear"));
        pushButtonClear->setMinimumSize(QSize(22, 22));
        pushButtonClear->setMaximumSize(QSize(22, 22));
        pushButtonClear->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../resource/16x16/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonClear->setIcon(icon1);
        pushButtonClear->setFlat(true);

        horizontalLayout->addWidget(pushButtonClear);

        pushButtonImportExport = new QPushButton(PlotWidget);
        pushButtonImportExport->setObjectName(QStringLiteral("pushButtonImportExport"));
        pushButtonImportExport->setMinimumSize(QSize(22, 22));
        pushButtonImportExport->setMaximumSize(QSize(22, 22));
        pushButtonImportExport->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../resource/16x16/eject.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonImportExport->setIcon(icon2);
        pushButtonImportExport->setFlat(true);

        horizontalLayout->addWidget(pushButtonImportExport);

        pushButtonSetup = new QPushButton(PlotWidget);
        pushButtonSetup->setObjectName(QStringLiteral("pushButtonSetup"));
        pushButtonSetup->setMinimumSize(QSize(22, 22));
        pushButtonSetup->setMaximumSize(QSize(22, 22));
        pushButtonSetup->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../resource/16x16/setup.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSetup->setIcon(icon3);
        pushButtonSetup->setFlat(true);

        horizontalLayout->addWidget(pushButtonSetup);

        pushButtonState = new QPushButton(PlotWidget);
        pushButtonState->setObjectName(QStringLiteral("pushButtonState"));
        pushButtonState->setMinimumSize(QSize(22, 22));
        pushButtonState->setMaximumSize(QSize(22, 22));
        pushButtonState->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../resource/16x16/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonState->setIcon(icon4);
        pushButtonState->setFlat(true);

        horizontalLayout->addWidget(pushButtonState);


        gridLayout->addLayout(horizontalLayout, 0, 7, 1, 1);

        horizontalSpacerRight = new QSpacerItem(0, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacerRight, 0, 6, 1, 1);

        plot = new rqt_multiplot::QwtPlotCustom(PlotWidget);
        plot->setObjectName(QStringLiteral("plot"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);
        plot->setFrameShape(QFrame::NoFrame);
        plot->setFrameShadow(QFrame::Plain);
        plot->setLineWidth(1);

        gridLayout->addWidget(plot, 1, 0, 1, 8);

        lineEditTitle = new QLineEdit(PlotWidget);
        lineEditTitle->setObjectName(QStringLiteral("lineEditTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditTitle->sizePolicy().hasHeightForWidth());
        lineEditTitle->setSizePolicy(sizePolicy1);
        lineEditTitle->setMinimumSize(QSize(100, 0));
        lineEditTitle->setFrame(false);
        lineEditTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditTitle, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(110, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 1, 1);


        retranslateUi(PlotWidget);

        QMetaObject::connectSlotsByName(PlotWidget);
    } // setupUi

    void retranslateUi(QWidget *PlotWidget)
    {
        PlotWidget->setWindowTitle(QApplication::translate("PlotWidget", "Form", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonRunPause->setToolTip(QApplication::translate("PlotWidget", "Run/pause plot", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonRunPause->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonClear->setToolTip(QApplication::translate("PlotWidget", "Clear plot", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonClear->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonImportExport->setToolTip(QApplication::translate("PlotWidget", "Export plot", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonImportExport->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonSetup->setToolTip(QApplication::translate("PlotWidget", "Configure plot", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonSetup->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonState->setToolTip(QApplication::translate("PlotWidget", "Maximize/restore plot", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonState->setText(QString());
        lineEditTitle->setInputMask(QString());
        lineEditTitle->setText(QApplication::translate("PlotWidget", "Untitled Plot", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlotWidget: public Ui_PlotWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTWIDGET_H
