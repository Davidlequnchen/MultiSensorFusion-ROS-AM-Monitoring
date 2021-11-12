/********************************************************************************
** Form generated from reading UI file 'PlotConfigWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTCONFIGWIDGET_H
#define UI_PLOTCONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <rqt_multiplot/CurveListWidget.h>
#include <rqt_multiplot/PlotAxesConfigWidget.h>
#include <rqt_multiplot/PlotLegendConfigWidget.h>

QT_BEGIN_NAMESPACE

class Ui_PlotConfigWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *line_2;
    QLabel *label;
    rqt_multiplot::PlotLegendConfigWidget *legendConfigWidget;
    QFrame *line;
    rqt_multiplot::CurveListWidget *curveListWidget;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBoxPlotRate;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QFrame *line_3;
    rqt_multiplot::PlotAxesConfigWidget *axesConfigWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonAddCurve;
    QPushButton *pushButtonEditCurve;
    QPushButton *pushButtonRemoveCurves;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonCopyCurves;
    QPushButton *pushButtonPasteCurves;
    QLabel *label_7;
    QLabel *label_4;
    QFrame *line_4;
    QLineEdit *lineEditTitle;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *PlotConfigWidget)
    {
        if (PlotConfigWidget->objectName().isEmpty())
            PlotConfigWidget->setObjectName(QStringLiteral("PlotConfigWidget"));
        PlotConfigWidget->resize(726, 551);
        gridLayout = new QGridLayout(PlotConfigWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        gridLayout->setVerticalSpacing(-1);
        line_2 = new QFrame(PlotConfigWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 4, 0, 1, 2);

        label = new QLabel(PlotConfigWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        legendConfigWidget = new rqt_multiplot::PlotLegendConfigWidget(PlotConfigWidget);
        legendConfigWidget->setObjectName(QStringLiteral("legendConfigWidget"));

        gridLayout->addWidget(legendConfigWidget, 8, 1, 1, 1);

        line = new QFrame(PlotConfigWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 2);

        curveListWidget = new rqt_multiplot::CurveListWidget(PlotConfigWidget);
        curveListWidget->setObjectName(QStringLiteral("curveListWidget"));
        curveListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        curveListWidget->setResizeMode(QListView::Fixed);
        curveListWidget->setSpacing(0);

        gridLayout->addWidget(curveListWidget, 3, 1, 1, 1);

        label_3 = new QLabel(PlotConfigWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 23));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 8, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(PlotConfigWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        doubleSpinBoxPlotRate = new QDoubleSpinBox(PlotConfigWidget);
        doubleSpinBoxPlotRate->setObjectName(QStringLiteral("doubleSpinBoxPlotRate"));
        doubleSpinBoxPlotRate->setMinimum(0.01);
        doubleSpinBoxPlotRate->setMaximum(9999.99);

        horizontalLayout_2->addWidget(doubleSpinBoxPlotRate);

        label_6 = new QLabel(PlotConfigWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 10, 1, 1, 1);

        label_2 = new QLabel(PlotConfigWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        line_3 = new QFrame(PlotConfigWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 9, 0, 1, 2);

        axesConfigWidget = new rqt_multiplot::PlotAxesConfigWidget(PlotConfigWidget);
        axesConfigWidget->setObjectName(QStringLiteral("axesConfigWidget"));
        axesConfigWidget->setMinimumSize(QSize(0, 23));

        gridLayout->addWidget(axesConfigWidget, 5, 1, 2, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonAddCurve = new QPushButton(PlotConfigWidget);
        pushButtonAddCurve->setObjectName(QStringLiteral("pushButtonAddCurve"));
        pushButtonAddCurve->setMinimumSize(QSize(22, 22));
        pushButtonAddCurve->setMaximumSize(QSize(22, 22));
        pushButtonAddCurve->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral("../resource/16x16/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAddCurve->setIcon(icon);
        pushButtonAddCurve->setIconSize(QSize(16, 16));
        pushButtonAddCurve->setFlat(true);

        horizontalLayout->addWidget(pushButtonAddCurve);

        pushButtonEditCurve = new QPushButton(PlotConfigWidget);
        pushButtonEditCurve->setObjectName(QStringLiteral("pushButtonEditCurve"));
        pushButtonEditCurve->setMinimumSize(QSize(22, 22));
        pushButtonEditCurve->setMaximumSize(QSize(22, 22));
        pushButtonEditCurve->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../resource/16x16/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonEditCurve->setIcon(icon1);
        pushButtonEditCurve->setIconSize(QSize(16, 16));
        pushButtonEditCurve->setFlat(true);

        horizontalLayout->addWidget(pushButtonEditCurve);

        pushButtonRemoveCurves = new QPushButton(PlotConfigWidget);
        pushButtonRemoveCurves->setObjectName(QStringLiteral("pushButtonRemoveCurves"));
        pushButtonRemoveCurves->setMinimumSize(QSize(22, 22));
        pushButtonRemoveCurves->setMaximumSize(QSize(22, 22));
        pushButtonRemoveCurves->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../resource/22x22/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRemoveCurves->setIcon(icon2);
        pushButtonRemoveCurves->setIconSize(QSize(16, 16));
        pushButtonRemoveCurves->setFlat(true);

        horizontalLayout->addWidget(pushButtonRemoveCurves);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonCopyCurves = new QPushButton(PlotConfigWidget);
        pushButtonCopyCurves->setObjectName(QStringLiteral("pushButtonCopyCurves"));
        pushButtonCopyCurves->setMinimumSize(QSize(22, 22));
        pushButtonCopyCurves->setMaximumSize(QSize(22, 22));
        pushButtonCopyCurves->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../resource/16x16/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCopyCurves->setIcon(icon3);
        pushButtonCopyCurves->setIconSize(QSize(16, 16));
        pushButtonCopyCurves->setFlat(true);

        horizontalLayout->addWidget(pushButtonCopyCurves);

        pushButtonPasteCurves = new QPushButton(PlotConfigWidget);
        pushButtonPasteCurves->setObjectName(QStringLiteral("pushButtonPasteCurves"));
        pushButtonPasteCurves->setMinimumSize(QSize(22, 22));
        pushButtonPasteCurves->setMaximumSize(QSize(22, 22));
        pushButtonPasteCurves->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../resource/16x16/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonPasteCurves->setIcon(icon4);
        pushButtonPasteCurves->setIconSize(QSize(16, 16));
        pushButtonPasteCurves->setFlat(true);

        horizontalLayout->addWidget(pushButtonPasteCurves);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);

        label_7 = new QLabel(PlotConfigWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(0, 23));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        label_4 = new QLabel(PlotConfigWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 10, 0, 1, 1);

        line_4 = new QFrame(PlotConfigWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 7, 0, 1, 2);

        lineEditTitle = new QLineEdit(PlotConfigWidget);
        lineEditTitle->setObjectName(QStringLiteral("lineEditTitle"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditTitle->sizePolicy().hasHeightForWidth());
        lineEditTitle->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEditTitle, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);


        retranslateUi(PlotConfigWidget);

        QMetaObject::connectSlotsByName(PlotConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *PlotConfigWidget)
    {
        PlotConfigWidget->setWindowTitle(QApplication::translate("PlotConfigWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("PlotConfigWidget", "Title:", Q_NULLPTR));
        label_3->setText(QApplication::translate("PlotConfigWidget", "Legend:", Q_NULLPTR));
        label_5->setText(QApplication::translate("PlotConfigWidget", "Plot rate:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        doubleSpinBoxPlotRate->setToolTip(QApplication::translate("PlotConfigWidget", "Limit rate of replot operations in [Hz]", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("PlotConfigWidget", "Hz", Q_NULLPTR));
        label_2->setText(QApplication::translate("PlotConfigWidget", "Curves:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonAddCurve->setToolTip(QApplication::translate("PlotConfigWidget", "Add curve", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonAddCurve->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonEditCurve->setToolTip(QApplication::translate("PlotConfigWidget", "Edit curve", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonEditCurve->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonRemoveCurves->setToolTip(QApplication::translate("PlotConfigWidget", "Remove curve", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonRemoveCurves->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonCopyCurves->setToolTip(QApplication::translate("PlotConfigWidget", "Copy curve", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonCopyCurves->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonPasteCurves->setToolTip(QApplication::translate("PlotConfigWidget", "Paste curve", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonPasteCurves->setText(QString());
        label_7->setText(QApplication::translate("PlotConfigWidget", "Axes:", Q_NULLPTR));
        label_4->setText(QApplication::translate("PlotConfigWidget", "Misc:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlotConfigWidget: public Ui_PlotConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTCONFIGWIDGET_H
