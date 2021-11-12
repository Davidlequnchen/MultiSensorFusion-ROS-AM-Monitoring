/********************************************************************************
** Form generated from reading UI file 'MultiplotWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLOTWIDGET_H
#define UI_MULTIPLOTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include <rqt_multiplot/MultiplotConfigWidget.h>
#include <rqt_multiplot/PlotTableConfigWidget.h>
#include <rqt_multiplot/PlotTableWidget.h>

QT_BEGIN_NAMESPACE

class Ui_MultiplotWidget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_3;
    rqt_multiplot::PlotTableConfigWidget *plotTableConfigWidget;
    QLabel *label;
    QFrame *frame;
    QGridLayout *gridLayout;
    rqt_multiplot::PlotTableWidget *plotTableWidget;
    QLabel *label_4;
    rqt_multiplot::MultiplotConfigWidget *configWidget;
    QFrame *line;
    QFrame *line_2;

    void setupUi(QWidget *MultiplotWidget)
    {
        if (MultiplotWidget->objectName().isEmpty())
            MultiplotWidget->setObjectName(QStringLiteral("MultiplotWidget"));
        MultiplotWidget->resize(708, 458);
        gridLayout_2 = new QGridLayout(MultiplotWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(5);
        plotTableConfigWidget = new rqt_multiplot::PlotTableConfigWidget(MultiplotWidget);
        plotTableConfigWidget->setObjectName(QStringLiteral("plotTableConfigWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plotTableConfigWidget->sizePolicy().hasHeightForWidth());
        plotTableConfigWidget->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(plotTableConfigWidget, 2, 1, 1, 1);

        label = new QLabel(MultiplotWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 23));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        frame = new QFrame(MultiplotWidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(-1);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plotTableWidget = new rqt_multiplot::PlotTableWidget(frame);
        plotTableWidget->setObjectName(QStringLiteral("plotTableWidget"));

        gridLayout->addWidget(plotTableWidget, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame, 4, 0, 1, 2);

        label_4 = new QLabel(MultiplotWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 23));
        label_4->setFont(font);

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);

        configWidget = new rqt_multiplot::MultiplotConfigWidget(MultiplotWidget);
        configWidget->setObjectName(QStringLiteral("configWidget"));
        sizePolicy.setHeightForWidth(configWidget->sizePolicy().hasHeightForWidth());
        configWidget->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(configWidget, 0, 1, 1, 1);

        line = new QFrame(MultiplotWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 3, 0, 1, 2);

        line_2 = new QFrame(MultiplotWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 1, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout_3, 0, 0, 1, 1);


        retranslateUi(MultiplotWidget);

        QMetaObject::connectSlotsByName(MultiplotWidget);
    } // setupUi

    void retranslateUi(QWidget *MultiplotWidget)
    {
        MultiplotWidget->setWindowTitle(QApplication::translate("MultiplotWidget", "Multiplot", Q_NULLPTR));
        label->setText(QApplication::translate("MultiplotWidget", "Configuration:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MultiplotWidget", "Plot Table:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MultiplotWidget: public Ui_MultiplotWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLOTWIDGET_H
