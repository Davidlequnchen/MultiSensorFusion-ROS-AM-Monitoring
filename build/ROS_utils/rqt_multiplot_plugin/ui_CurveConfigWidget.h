/********************************************************************************
** Form generated from reading UI file 'CurveConfigWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVECONFIGWIDGET_H
#define UI_CURVECONFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include <rqt_multiplot/CurveAxisConfigWidget.h>
#include <rqt_multiplot/CurveColorConfigWidget.h>
#include <rqt_multiplot/CurveDataConfigWidget.h>
#include "rqt_multiplot/CurveStyleConfigWidget.h"

QT_BEGIN_NAMESPACE

class Ui_CurveConfigWidget
{
public:
    QGridLayout *gridLayout;
    QFrame *line_5;
    QLabel *label_5;
    QLineEdit *lineEditTitle;
    rqt_multiplot::CurveDataConfigWidget *curveDataConfigWidget;
    QLabel *label;
    rqt_multiplot::CurveColorConfigWidget *curveColorConfigWidget;
    QLabel *label_2;
    QLabel *label_9;
    QFrame *line;
    rqt_multiplot::CurveStyleConfigWidget *curveStyleConfigWidget;
    rqt_multiplot::CurveAxisConfigWidget *curveAxisConfigWidgetY;
    rqt_multiplot::CurveAxisConfigWidget *curveAxisConfigWidgetX;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QSpinBox *spinBoxSubscriberQueueSize;
    QSpacerItem *horizontalSpacer;
    QLabel *label_8;
    QLabel *label_6;
    QFrame *line_4;
    QFrame *line_6;
    QFrame *line_2;
    QPushButton *pushButtonSwap;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QPushButton *pushButtonCopyRight;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonCopyLeft;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *CurveConfigWidget)
    {
        if (CurveConfigWidget->objectName().isEmpty())
            CurveConfigWidget->setObjectName(QStringLiteral("CurveConfigWidget"));
        CurveConfigWidget->resize(760, 464);
        gridLayout = new QGridLayout(CurveConfigWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        line_5 = new QFrame(CurveConfigWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 10, 0, 1, 4);

        label_5 = new QLabel(CurveConfigWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 23));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 17, 0, 1, 1);

        lineEditTitle = new QLineEdit(CurveConfigWidget);
        lineEditTitle->setObjectName(QStringLiteral("lineEditTitle"));

        gridLayout->addWidget(lineEditTitle, 0, 1, 1, 3);

        curveDataConfigWidget = new rqt_multiplot::CurveDataConfigWidget(CurveConfigWidget);
        curveDataConfigWidget->setObjectName(QStringLiteral("curveDataConfigWidget"));
        curveDataConfigWidget->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(curveDataConfigWidget, 14, 1, 1, 3);

        label = new QLabel(CurveConfigWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        curveColorConfigWidget = new rqt_multiplot::CurveColorConfigWidget(CurveConfigWidget);
        curveColorConfigWidget->setObjectName(QStringLiteral("curveColorConfigWidget"));

        gridLayout->addWidget(curveColorConfigWidget, 7, 1, 1, 3);

        label_2 = new QLabel(CurveConfigWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 24));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_9 = new QLabel(CurveConfigWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(0, 23));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 14, 0, 1, 1);

        line = new QFrame(CurveConfigWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 4);

        curveStyleConfigWidget = new rqt_multiplot::CurveStyleConfigWidget(CurveConfigWidget);
        curveStyleConfigWidget->setObjectName(QStringLiteral("curveStyleConfigWidget"));
        curveStyleConfigWidget->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(curveStyleConfigWidget, 11, 1, 2, 3);

        curveAxisConfigWidgetY = new rqt_multiplot::CurveAxisConfigWidget(CurveConfigWidget);
        curveAxisConfigWidgetY->setObjectName(QStringLiteral("curveAxisConfigWidgetY"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(curveAxisConfigWidgetY->sizePolicy().hasHeightForWidth());
        curveAxisConfigWidgetY->setSizePolicy(sizePolicy);

        gridLayout->addWidget(curveAxisConfigWidgetY, 3, 3, 1, 1);

        curveAxisConfigWidgetX = new rqt_multiplot::CurveAxisConfigWidget(CurveConfigWidget);
        curveAxisConfigWidgetX->setObjectName(QStringLiteral("curveAxisConfigWidgetX"));
        sizePolicy.setHeightForWidth(curveAxisConfigWidgetX->sizePolicy().hasHeightForWidth());
        curveAxisConfigWidgetX->setSizePolicy(sizePolicy);

        gridLayout->addWidget(curveAxisConfigWidgetX, 3, 1, 1, 1);

        line_3 = new QFrame(CurveConfigWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 4, 0, 1, 4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(CurveConfigWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        spinBoxSubscriberQueueSize = new QSpinBox(CurveConfigWidget);
        spinBoxSubscriberQueueSize->setObjectName(QStringLiteral("spinBoxSubscriberQueueSize"));
        spinBoxSubscriberQueueSize->setMinimum(1);
        spinBoxSubscriberQueueSize->setMaximum(9999);

        horizontalLayout->addWidget(spinBoxSubscriberQueueSize);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 17, 1, 1, 3);

        label_8 = new QLabel(CurveConfigWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(0, 23));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 11, 0, 1, 1);

        label_6 = new QLabel(CurveConfigWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(0, 23));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        line_4 = new QFrame(CurveConfigWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 13, 0, 1, 4);

        line_6 = new QFrame(CurveConfigWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 16, 0, 1, 4);

        line_2 = new QFrame(CurveConfigWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy2);
        line_2->setMinimumSize(QSize(0, 0));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 3, 2, 1, 1);

        pushButtonSwap = new QPushButton(CurveConfigWidget);
        pushButtonSwap->setObjectName(QStringLiteral("pushButtonSwap"));
        pushButtonSwap->setMinimumSize(QSize(22, 22));
        pushButtonSwap->setMaximumSize(QSize(22, 22));
        pushButtonSwap->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral("../resource/22x22/arrows_right_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSwap->setIcon(icon);
        pushButtonSwap->setIconSize(QSize(22, 22));
        pushButtonSwap->setFlat(true);

        gridLayout->addWidget(pushButtonSwap, 2, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(22, 19, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_3 = new QLabel(CurveConfigWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        pushButtonCopyRight = new QPushButton(CurveConfigWidget);
        pushButtonCopyRight->setObjectName(QStringLiteral("pushButtonCopyRight"));
        pushButtonCopyRight->setMinimumSize(QSize(22, 22));
        pushButtonCopyRight->setMaximumSize(QSize(22, 22));
        pushButtonCopyRight->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../resource/22x22/arrow_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCopyRight->setIcon(icon1);
        pushButtonCopyRight->setIconSize(QSize(22, 22));
        pushButtonCopyRight->setFlat(true);

        horizontalLayout_2->addWidget(pushButtonCopyRight);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonCopyLeft = new QPushButton(CurveConfigWidget);
        pushButtonCopyLeft->setObjectName(QStringLiteral("pushButtonCopyLeft"));
        pushButtonCopyLeft->setMinimumSize(QSize(22, 22));
        pushButtonCopyLeft->setMaximumSize(QSize(22, 22));
        pushButtonCopyLeft->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../resource/22x22/arrow_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonCopyLeft->setIcon(icon2);
        pushButtonCopyLeft->setIconSize(QSize(22, 22));
        pushButtonCopyLeft->setFlat(true);

        horizontalLayout_3->addWidget(pushButtonCopyLeft);

        label_4 = new QLabel(CurveConfigWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(22, 19, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_3, 2, 3, 1, 1);


        retranslateUi(CurveConfigWidget);

        QMetaObject::connectSlotsByName(CurveConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *CurveConfigWidget)
    {
        CurveConfigWidget->setWindowTitle(QApplication::translate("CurveConfigWidget", "Form", Q_NULLPTR));
        label_5->setText(QApplication::translate("CurveConfigWidget", "Misc:", Q_NULLPTR));
        label->setText(QApplication::translate("CurveConfigWidget", "Title:", Q_NULLPTR));
        label_2->setText(QApplication::translate("CurveConfigWidget", "Axes:", Q_NULLPTR));
        label_9->setText(QApplication::translate("CurveConfigWidget", "Data:", Q_NULLPTR));
        label_7->setText(QApplication::translate("CurveConfigWidget", "Subscriber queue size:", Q_NULLPTR));
        label_8->setText(QApplication::translate("CurveConfigWidget", "Style:", Q_NULLPTR));
        label_6->setText(QApplication::translate("CurveConfigWidget", "Color:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonSwap->setToolTip(QApplication::translate("CurveConfigWidget", "Swap axis configurations", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonSwap->setText(QString());
        label_3->setText(QApplication::translate("CurveConfigWidget", "X-Axis", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonCopyRight->setToolTip(QApplication::translate("CurveConfigWidget", "Copy to y-axis configuration", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonCopyRight->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonCopyLeft->setToolTip(QApplication::translate("CurveConfigWidget", "Copy to x-axis configuration", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonCopyLeft->setText(QString());
        label_4->setText(QApplication::translate("CurveConfigWidget", "Y-Axis", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CurveConfigWidget: public Ui_CurveConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVECONFIGWIDGET_H
