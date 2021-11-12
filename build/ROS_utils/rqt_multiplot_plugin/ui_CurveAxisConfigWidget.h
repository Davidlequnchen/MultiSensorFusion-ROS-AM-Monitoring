/********************************************************************************
** Form generated from reading UI file 'CurveAxisConfigWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURVEAXISCONFIGWIDGET_H
#define UI_CURVEAXISCONFIGWIDGET_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <rqt_multiplot/CurveAxisScaleConfigWidget.h>
#include <rqt_multiplot/MessageFieldWidget.h>
#include <rqt_multiplot/MessageTopicComboBox.h>
#include <rqt_multiplot/MessageTypeComboBox.h>
#include <rqt_multiplot/StatusWidget.h>

QT_BEGIN_NAMESPACE

class Ui_CurveAxisConfigWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QFrame *line_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_7;
    rqt_multiplot::MessageTypeComboBox *comboBoxType;
    rqt_multiplot::StatusWidget *statusWidgetType;
    QHBoxLayout *horizontalLayout_3;
    rqt_multiplot::MessageTopicComboBox *comboBoxTopic;
    rqt_multiplot::StatusWidget *statusWidgetTopic;
    QFrame *line;
    QLabel *label_3;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QFrame *line_3;
    QGridLayout *gridLayout_2;
    rqt_multiplot::StatusWidget *statusWidgetField;
    rqt_multiplot::MessageFieldWidget *widgetField;
    QCheckBox *checkBoxFieldReceiptTime;
    QGridLayout *gridLayout_3;
    rqt_multiplot::StatusWidget *statusWidgetScale;
    rqt_multiplot::CurveAxisScaleConfigWidget *widgetScale;

    void setupUi(QWidget *CurveAxisConfigWidget)
    {
        if (CurveAxisConfigWidget->objectName().isEmpty())
            CurveAxisConfigWidget->setObjectName(QStringLiteral("CurveAxisConfigWidget"));
        CurveAxisConfigWidget->resize(422, 589);
        gridLayout = new QGridLayout(CurveAxisConfigWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        label_2 = new QLabel(CurveAxisConfigWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        line_2 = new QFrame(CurveAxisConfigWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 8, 0, 1, 2);

        label_4 = new QLabel(CurveAxisConfigWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(5);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        comboBoxType = new rqt_multiplot::MessageTypeComboBox(CurveAxisConfigWidget);
        comboBoxType->setObjectName(QStringLiteral("comboBoxType"));
        comboBoxType->setInputMethodHints(Qt::ImhExclusiveInputMask);
        comboBoxType->setEditable(true);
        comboBoxType->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_7->addWidget(comboBoxType);

        statusWidgetType = new rqt_multiplot::StatusWidget(CurveAxisConfigWidget);
        statusWidgetType->setObjectName(QStringLiteral("statusWidgetType"));
        statusWidgetType->setMinimumSize(QSize(22, 22));
        statusWidgetType->setMaximumSize(QSize(22, 22));

        horizontalLayout_7->addWidget(statusWidgetType);


        gridLayout->addLayout(horizontalLayout_7, 2, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        comboBoxTopic = new rqt_multiplot::MessageTopicComboBox(CurveAxisConfigWidget);
        comboBoxTopic->setObjectName(QStringLiteral("comboBoxTopic"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxTopic->sizePolicy().hasHeightForWidth());
        comboBoxTopic->setSizePolicy(sizePolicy);
        comboBoxTopic->setInputMethodHints(Qt::ImhExclusiveInputMask);
        comboBoxTopic->setEditable(true);
        comboBoxTopic->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_3->addWidget(comboBoxTopic);

        statusWidgetTopic = new rqt_multiplot::StatusWidget(CurveAxisConfigWidget);
        statusWidgetTopic->setObjectName(QStringLiteral("statusWidgetTopic"));
        statusWidgetTopic->setMinimumSize(QSize(22, 22));
        statusWidgetTopic->setMaximumSize(QSize(22, 22));

        horizontalLayout_3->addWidget(statusWidgetTopic);


        gridLayout->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        line = new QFrame(CurveAxisConfigWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 2);

        label_3 = new QLabel(CurveAxisConfigWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(label_3, 10, 0, 1, 1);

        label = new QLabel(CurveAxisConfigWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        line_3 = new QFrame(CurveAxisConfigWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 1, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(5);
        statusWidgetField = new rqt_multiplot::StatusWidget(CurveAxisConfigWidget);
        statusWidgetField->setObjectName(QStringLiteral("statusWidgetField"));
        statusWidgetField->setMinimumSize(QSize(22, 22));
        statusWidgetField->setMaximumSize(QSize(22, 22));

        gridLayout_2->addWidget(statusWidgetField, 0, 1, 1, 1);

        widgetField = new rqt_multiplot::MessageFieldWidget(CurveAxisConfigWidget);
        widgetField->setObjectName(QStringLiteral("widgetField"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetField->sizePolicy().hasHeightForWidth());
        widgetField->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(widgetField, 0, 0, 2, 1);

        checkBoxFieldReceiptTime = new QCheckBox(CurveAxisConfigWidget);
        checkBoxFieldReceiptTime->setObjectName(QStringLiteral("checkBoxFieldReceiptTime"));

        gridLayout_2->addWidget(checkBoxFieldReceiptTime, 2, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 4, 1, 2, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(5);
        statusWidgetScale = new rqt_multiplot::StatusWidget(CurveAxisConfigWidget);
        statusWidgetScale->setObjectName(QStringLiteral("statusWidgetScale"));
        statusWidgetScale->setMinimumSize(QSize(22, 22));
        statusWidgetScale->setMaximumSize(QSize(22, 22));

        gridLayout_3->addWidget(statusWidgetScale, 0, 1, 1, 1);

        widgetScale = new rqt_multiplot::CurveAxisScaleConfigWidget(CurveAxisConfigWidget);
        widgetScale->setObjectName(QStringLiteral("widgetScale"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widgetScale->sizePolicy().hasHeightForWidth());
        widgetScale->setSizePolicy(sizePolicy2);
        widgetScale->setMinimumSize(QSize(0, 50));

        gridLayout_3->addWidget(widgetScale, 0, 0, 2, 1);


        gridLayout->addLayout(gridLayout_3, 10, 1, 2, 1);


        retranslateUi(CurveAxisConfigWidget);

        QMetaObject::connectSlotsByName(CurveAxisConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *CurveAxisConfigWidget)
    {
        CurveAxisConfigWidget->setWindowTitle(QApplication::translate("CurveAxisConfigWidget", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("CurveAxisConfigWidget", "Field:", Q_NULLPTR));
        label_4->setText(QApplication::translate("CurveAxisConfigWidget", "Type:", Q_NULLPTR));
        label_3->setText(QApplication::translate("CurveAxisConfigWidget", "Scale:", Q_NULLPTR));
        label->setText(QApplication::translate("CurveAxisConfigWidget", "Topic:", Q_NULLPTR));
        checkBoxFieldReceiptTime->setText(QApplication::translate("CurveAxisConfigWidget", "Message Receipt Time", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CurveAxisConfigWidget: public Ui_CurveAxisConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURVEAXISCONFIGWIDGET_H
