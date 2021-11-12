/********************************************************************************
** Form generated from reading UI file 'PlotTableConfigWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTTABLECONFIGWIDGET_H
#define UI_PLOTTABLECONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include <rqt_multiplot/ProgressWidget.h>

QT_BEGIN_NAMESPACE

class Ui_PlotTableConfigWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonRun;
    QPushButton *pushButtonPause;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonImportExport;
    rqt_multiplot::ProgressWidget *widgetProgress;
    QCheckBox *checkBoxLinkCursor;
    QLabel *label;
    QLabel *label_3;
    QFrame *line_5;
    QLabel *label_4;
    QFrame *line_2;
    QLabel *label_2;
    QFrame *line_3;
    QFrame *line;
    QFrame *frameBackgroundColor;
    QGridLayout *gridLayout_2;
    QLabel *labelBackgroundColor;
    QCheckBox *checkBoxLinkScale;
    QSpinBox *spinBoxColumns;
    QFrame *line_4;
    QFrame *frameForegroundColor;
    QGridLayout *gridLayout_3;
    QLabel *labelForegroundColor;
    QSpinBox *spinBoxRows;
    QCheckBox *checkBoxTrackPoints;

    void setupUi(QWidget *PlotTableConfigWidget)
    {
        if (PlotTableConfigWidget->objectName().isEmpty())
            PlotTableConfigWidget->setObjectName(QStringLiteral("PlotTableConfigWidget"));
        PlotTableConfigWidget->resize(895, 24);
        gridLayout = new QGridLayout(PlotTableConfigWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonRun = new QPushButton(PlotTableConfigWidget);
        pushButtonRun->setObjectName(QStringLiteral("pushButtonRun"));
        pushButtonRun->setMinimumSize(QSize(22, 22));
        pushButtonRun->setMaximumSize(QSize(22, 22));
        pushButtonRun->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral("../resource/16x16/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRun->setIcon(icon);
        pushButtonRun->setIconSize(QSize(16, 16));
        pushButtonRun->setFlat(true);

        horizontalLayout->addWidget(pushButtonRun);

        pushButtonPause = new QPushButton(PlotTableConfigWidget);
        pushButtonPause->setObjectName(QStringLiteral("pushButtonPause"));
        pushButtonPause->setMinimumSize(QSize(22, 22));
        pushButtonPause->setMaximumSize(QSize(22, 22));
        pushButtonPause->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../resource/16x16/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonPause->setIcon(icon1);
        pushButtonPause->setIconSize(QSize(16, 16));
        pushButtonPause->setFlat(true);

        horizontalLayout->addWidget(pushButtonPause);

        pushButtonClear = new QPushButton(PlotTableConfigWidget);
        pushButtonClear->setObjectName(QStringLiteral("pushButtonClear"));
        pushButtonClear->setMinimumSize(QSize(22, 22));
        pushButtonClear->setMaximumSize(QSize(22, 22));
        pushButtonClear->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../resource/16x16/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonClear->setIcon(icon2);
        pushButtonClear->setIconSize(QSize(16, 16));
        pushButtonClear->setFlat(true);

        horizontalLayout->addWidget(pushButtonClear);

        pushButtonImportExport = new QPushButton(PlotTableConfigWidget);
        pushButtonImportExport->setObjectName(QStringLiteral("pushButtonImportExport"));
        pushButtonImportExport->setMinimumSize(QSize(22, 22));
        pushButtonImportExport->setMaximumSize(QSize(22, 22));
        pushButtonImportExport->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../resource/16x16/eject.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonImportExport->setIcon(icon3);
        pushButtonImportExport->setFlat(true);

        horizontalLayout->addWidget(pushButtonImportExport);


        gridLayout->addLayout(horizontalLayout, 0, 18, 1, 1);

        widgetProgress = new rqt_multiplot::ProgressWidget(PlotTableConfigWidget);
        widgetProgress->setObjectName(QStringLiteral("widgetProgress"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetProgress->sizePolicy().hasHeightForWidth());
        widgetProgress->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widgetProgress, 0, 16, 1, 1);

        checkBoxLinkCursor = new QCheckBox(PlotTableConfigWidget);
        checkBoxLinkCursor->setObjectName(QStringLiteral("checkBoxLinkCursor"));

        gridLayout->addWidget(checkBoxLinkCursor, 0, 10, 1, 1);

        label = new QLabel(PlotTableConfigWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 4, 1, 1);

        label_3 = new QLabel(PlotTableConfigWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        label_3->setFont(font);
        label_3->setMargin(0);

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        line_5 = new QFrame(PlotTableConfigWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 0, 15, 1, 1);

        label_4 = new QLabel(PlotTableConfigWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 13, 1, 1);

        line_2 = new QFrame(PlotTableConfigWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 7, 1, 1);

        label_2 = new QLabel(PlotTableConfigWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 8, 1, 1);

        line_3 = new QFrame(PlotTableConfigWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 0, 12, 1, 1);

        line = new QFrame(PlotTableConfigWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 3, 1, 1);

        frameBackgroundColor = new QFrame(PlotTableConfigWidget);
        frameBackgroundColor->setObjectName(QStringLiteral("frameBackgroundColor"));
        frameBackgroundColor->setMinimumSize(QSize(22, 22));
        frameBackgroundColor->setMaximumSize(QSize(22, 22));
        frameBackgroundColor->setCursor(QCursor(Qt::PointingHandCursor));
        frameBackgroundColor->setFrameShape(QFrame::StyledPanel);
        frameBackgroundColor->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(frameBackgroundColor);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        labelBackgroundColor = new QLabel(frameBackgroundColor);
        labelBackgroundColor->setObjectName(QStringLiteral("labelBackgroundColor"));

        gridLayout_2->addWidget(labelBackgroundColor, 0, 0, 1, 1);


        gridLayout->addWidget(frameBackgroundColor, 0, 5, 1, 1);

        checkBoxLinkScale = new QCheckBox(PlotTableConfigWidget);
        checkBoxLinkScale->setObjectName(QStringLiteral("checkBoxLinkScale"));
        checkBoxLinkScale->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(checkBoxLinkScale, 0, 9, 1, 1);

        spinBoxColumns = new QSpinBox(PlotTableConfigWidget);
        spinBoxColumns->setObjectName(QStringLiteral("spinBoxColumns"));
        spinBoxColumns->setMinimum(1);

        gridLayout->addWidget(spinBoxColumns, 0, 2, 1, 1);

        line_4 = new QFrame(PlotTableConfigWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 0, 17, 1, 1);

        frameForegroundColor = new QFrame(PlotTableConfigWidget);
        frameForegroundColor->setObjectName(QStringLiteral("frameForegroundColor"));
        frameForegroundColor->setMinimumSize(QSize(22, 22));
        frameForegroundColor->setMaximumSize(QSize(22, 22));
        frameForegroundColor->setCursor(QCursor(Qt::PointingHandCursor));
        frameForegroundColor->setFrameShape(QFrame::StyledPanel);
        frameForegroundColor->setFrameShadow(QFrame::Sunken);
        gridLayout_3 = new QGridLayout(frameForegroundColor);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        labelForegroundColor = new QLabel(frameForegroundColor);
        labelForegroundColor->setObjectName(QStringLiteral("labelForegroundColor"));

        gridLayout_3->addWidget(labelForegroundColor, 0, 0, 1, 1);


        gridLayout->addWidget(frameForegroundColor, 0, 6, 1, 1);

        spinBoxRows = new QSpinBox(PlotTableConfigWidget);
        spinBoxRows->setObjectName(QStringLiteral("spinBoxRows"));
        spinBoxRows->setMinimum(1);

        gridLayout->addWidget(spinBoxRows, 0, 0, 1, 1);

        checkBoxTrackPoints = new QCheckBox(PlotTableConfigWidget);
        checkBoxTrackPoints->setObjectName(QStringLiteral("checkBoxTrackPoints"));

        gridLayout->addWidget(checkBoxTrackPoints, 0, 14, 1, 1);


        retranslateUi(PlotTableConfigWidget);

        QMetaObject::connectSlotsByName(PlotTableConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *PlotTableConfigWidget)
    {
        PlotTableConfigWidget->setWindowTitle(QApplication::translate("PlotTableConfigWidget", "Form", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonRun->setToolTip(QApplication::translate("PlotTableConfigWidget", "Run all plots", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonRun->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonPause->setToolTip(QApplication::translate("PlotTableConfigWidget", "Pause all plots", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonPause->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonClear->setToolTip(QApplication::translate("PlotTableConfigWidget", "Clear all plots", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonClear->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonImportExport->setToolTip(QApplication::translate("PlotTableConfigWidget", "Export all plots", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonImportExport->setText(QString());
#ifndef QT_NO_TOOLTIP
        checkBoxLinkCursor->setToolTip(QApplication::translate("PlotTableConfigWidget", "Link plot cursors", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkBoxLinkCursor->setText(QApplication::translate("PlotTableConfigWidget", "Cursor", Q_NULLPTR));
        label->setText(QApplication::translate("PlotTableConfigWidget", "Colors", Q_NULLPTR));
        label_3->setText(QApplication::translate("PlotTableConfigWidget", "x", Q_NULLPTR));
        label_4->setText(QApplication::translate("PlotTableConfigWidget", "Track", Q_NULLPTR));
        label_2->setText(QApplication::translate("PlotTableConfigWidget", "Link", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        frameBackgroundColor->setToolTip(QApplication::translate("PlotTableConfigWidget", "Plot background color", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelBackgroundColor->setToolTip(QApplication::translate("PlotTableConfigWidget", "Plot background color", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        labelBackgroundColor->setText(QString());
#ifndef QT_NO_TOOLTIP
        checkBoxLinkScale->setToolTip(QApplication::translate("PlotTableConfigWidget", "Link plot scales", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkBoxLinkScale->setText(QApplication::translate("PlotTableConfigWidget", "Scale", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spinBoxColumns->setToolTip(QApplication::translate("PlotTableConfigWidget", "Number of plot columns", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        labelForegroundColor->setToolTip(QApplication::translate("PlotTableConfigWidget", "Plot foreground color", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        labelForegroundColor->setText(QString());
#ifndef QT_NO_TOOLTIP
        spinBoxRows->setToolTip(QApplication::translate("PlotTableConfigWidget", "Number of plot rows", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        checkBoxTrackPoints->setToolTip(QApplication::translate("PlotTableConfigWidget", "Track plot points at cursor", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkBoxTrackPoints->setText(QApplication::translate("PlotTableConfigWidget", "Points", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlotTableConfigWidget: public Ui_PlotTableConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTTABLECONFIGWIDGET_H
