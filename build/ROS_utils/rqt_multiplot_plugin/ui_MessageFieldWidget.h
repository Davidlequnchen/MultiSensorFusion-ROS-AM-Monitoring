/********************************************************************************
** Form generated from reading UI file 'MessageFieldWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEFIELDWIDGET_H
#define UI_MESSAGEFIELDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <rqt_multiplot/MessageFieldLineEdit.h>
#include <rqt_multiplot/MessageFieldTreeWidget.h>

QT_BEGIN_NAMESPACE

class Ui_MessageFieldWidget
{
public:
    QGridLayout *gridLayout;
    rqt_multiplot::MessageFieldLineEdit *lineEdit;
    rqt_multiplot::MessageFieldTreeWidget *treeWidget;

    void setupUi(QWidget *MessageFieldWidget)
    {
        if (MessageFieldWidget->objectName().isEmpty())
            MessageFieldWidget->setObjectName(QStringLiteral("MessageFieldWidget"));
        MessageFieldWidget->resize(415, 486);
        gridLayout = new QGridLayout(MessageFieldWidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(5);
        lineEdit = new rqt_multiplot::MessageFieldLineEdit(MessageFieldWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        treeWidget = new rqt_multiplot::MessageFieldTreeWidget(MessageFieldWidget);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->header()->setDefaultSectionSize(100);

        gridLayout->addWidget(treeWidget, 1, 0, 1, 1);


        retranslateUi(MessageFieldWidget);

        QMetaObject::connectSlotsByName(MessageFieldWidget);
    } // setupUi

    void retranslateUi(QWidget *MessageFieldWidget)
    {
        MessageFieldWidget->setWindowTitle(QApplication::translate("MessageFieldWidget", "Form", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MessageFieldWidget", "Type", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("MessageFieldWidget", "Name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MessageFieldWidget: public Ui_MessageFieldWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEFIELDWIDGET_H
