/********************************************************************************
** Form generated from reading UI file 'pclviewer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCLVIEWER_H
#define UI_PCLVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <QtWidgets/QSizePolicy>
//#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PCLViewer
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QWidget *centerlwidget;
    QGridLayout *gridLayout_14;
    QGridLayout *gridLayout_16;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_save;
    QPushButton *pushButton_load;
    QTabWidget *tabWidget;
    QWidget *tab_filters;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser_data;
    QStackedWidget *stackedWidget_filter;
    QWidget *page_voxel;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_voxel_x;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_voxel_y;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_voxel_z;
    QWidget *page_statistical;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_filter1_kn;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_filter1_desv;
    QWidget *page_radius_search;
    QGridLayout *gridLayout_4;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_radio;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_radio_k;
    QWidget *page_resampling;
    QGridLayout *gridLayout_8;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_smooth;
    QWidget *page_pass;
    QGridLayout *gridLayout_10;
    QComboBox *comboBox_pass;
    QDoubleSpinBox *doubleSpinBox_max_pass;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_min_pass;
    QLabel *label_13;
    QComboBox *comboBox_filter;
    QGridLayout *gridLayout_13;
    QPushButton *pushButton_accept_filter;
    QPushButton *pushButton_undo_filter;
    QPushButton *pushButton_filter;
    QPushButton *pushButton;
    QPushButton *pushButton_apply_filtering;
    QWidget *tab_fit;
    QGridLayout *gridLayout_5;
    QTextBrowser *textBrowser_data_2;
    QGridLayout *gridLayout_12;
    QDoubleSpinBox *doubleSpinBox_angle;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_2dx;
    QDoubleSpinBox *doubleSpinBox_2dy;
    QPushButton *pushButton_2d_place;
    QLabel *label_16;
    QLabel *label_17;
    QGridLayout *gridLayout_9;
    QPushButton *pushButton_accept_fitting;
    QPushButton *pushButton_record_plane;
    QPushButton *pushButton_distances;
    QPushButton *pushButton_reorient;
    QPushButton *pushButton_function_plane_fit;
    QPushButton *pushButton_undo_plane;
    QCheckBox *checkBox_points_sup;
    QPushButton *pushButton_center;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBox_ransac_dist;
    QWidget *tab_projections;
    QGridLayout *gridLayout_11;
    QPushButton *pushButton_proj_points;
    QTextBrowser *textBrowser_projection;
    QWidget *tab_align;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_15;
    QPushButton *pushButton_load_model;
    QPushButton *pushButton_delete_model;
    QPushButton *pushButton_fine_alignment;
    QPushButton *pushButton_init_align;
    QTextBrowser *textBrowser_align;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QDoubleSpinBox *doubleSpinBox_cloud_size;
    QDoubleSpinBox *doubleSpinBox_mod_size;
    QLabel *label_11;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_sel_size;
    QLabel *label_10;
    QPushButton *pushButton_test;
    QLabel *label_18;
    QSpinBox *spinBox_cluster;
    //QGridLayout *gridLayout_17;
    //QVTKWidget *qvtkWidget;
    QMenuBar *menuBar;
    QMenu *menuSettings;

    void setupUi(QMainWindow *PCLViewer)
    {
        if (PCLViewer->objectName().isEmpty())
            PCLViewer->setObjectName(QString::fromUtf8("PCLViewer"));
        PCLViewer->resize(500, 641);
        PCLViewer->setMinimumSize(QSize(500, 641));
        PCLViewer->setMaximumSize(QSize(5000, 5000));
        actionLoad = new QAction(PCLViewer);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionSave = new QAction(PCLViewer);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centerlwidget = new QWidget(PCLViewer);
        centerlwidget->setObjectName(QString::fromUtf8("centerlwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centerlwidget->sizePolicy().hasHeightForWidth());
        centerlwidget->setSizePolicy(sizePolicy);
        gridLayout_14 = new QGridLayout(centerlwidget);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        pushButton_save = new QPushButton(centerlwidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_save->sizePolicy().hasHeightForWidth());
        pushButton_save->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(pushButton_save, 0, 1, 1, 1);

        pushButton_load = new QPushButton(centerlwidget);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));
        sizePolicy1.setHeightForWidth(pushButton_load->sizePolicy().hasHeightForWidth());
        pushButton_load->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(pushButton_load, 0, 0, 1, 1);


        gridLayout_16->addLayout(gridLayout_7, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centerlwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tab_filters = new QWidget();
        tab_filters->setObjectName(QString::fromUtf8("tab_filters"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tab_filters->sizePolicy().hasHeightForWidth());
        tab_filters->setSizePolicy(sizePolicy3);
        gridLayout = new QGridLayout(tab_filters);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser_data = new QTextBrowser(tab_filters);
        textBrowser_data->setObjectName(QString::fromUtf8("textBrowser_data"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(textBrowser_data->sizePolicy().hasHeightForWidth());
        textBrowser_data->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(textBrowser_data, 4, 0, 1, 3);

        stackedWidget_filter = new QStackedWidget(tab_filters);
        stackedWidget_filter->setObjectName(QString::fromUtf8("stackedWidget_filter"));
        sizePolicy1.setHeightForWidth(stackedWidget_filter->sizePolicy().hasHeightForWidth());
        stackedWidget_filter->setSizePolicy(sizePolicy1);
        stackedWidget_filter->setFrameShape(QFrame::StyledPanel);
        page_voxel = new QWidget();
        page_voxel->setObjectName(QString::fromUtf8("page_voxel"));
        gridLayout_2 = new QGridLayout(page_voxel);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(page_voxel);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy5);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        doubleSpinBox_voxel_x = new QDoubleSpinBox(page_voxel);
        doubleSpinBox_voxel_x->setObjectName(QString::fromUtf8("doubleSpinBox_voxel_x"));
        doubleSpinBox_voxel_x->setDecimals(6);
        doubleSpinBox_voxel_x->setSingleStep(0.0001);
        doubleSpinBox_voxel_x->setValue(0.01);

        gridLayout_2->addWidget(doubleSpinBox_voxel_x, 0, 1, 1, 1);

        label_4 = new QLabel(page_voxel);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        doubleSpinBox_voxel_y = new QDoubleSpinBox(page_voxel);
        doubleSpinBox_voxel_y->setObjectName(QString::fromUtf8("doubleSpinBox_voxel_y"));
        doubleSpinBox_voxel_y->setDecimals(6);
        doubleSpinBox_voxel_y->setSingleStep(0.0001);
        doubleSpinBox_voxel_y->setValue(0.01);

        gridLayout_2->addWidget(doubleSpinBox_voxel_y, 1, 1, 1, 1);

        label_5 = new QLabel(page_voxel);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        doubleSpinBox_voxel_z = new QDoubleSpinBox(page_voxel);
        doubleSpinBox_voxel_z->setObjectName(QString::fromUtf8("doubleSpinBox_voxel_z"));
        doubleSpinBox_voxel_z->setDecimals(6);
        doubleSpinBox_voxel_z->setSingleStep(0.0001);
        doubleSpinBox_voxel_z->setValue(0.01);

        gridLayout_2->addWidget(doubleSpinBox_voxel_z, 2, 1, 1, 1);

        stackedWidget_filter->addWidget(page_voxel);
        page_statistical = new QWidget();
        page_statistical->setObjectName(QString::fromUtf8("page_statistical"));
        gridLayout_3 = new QGridLayout(page_statistical);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(page_statistical);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        doubleSpinBox_filter1_kn = new QDoubleSpinBox(page_statistical);
        doubleSpinBox_filter1_kn->setObjectName(QString::fromUtf8("doubleSpinBox_filter1_kn"));
        doubleSpinBox_filter1_kn->setDecimals(0);
        doubleSpinBox_filter1_kn->setSingleStep(1);
        doubleSpinBox_filter1_kn->setValue(5);

        gridLayout_3->addWidget(doubleSpinBox_filter1_kn, 0, 1, 1, 1);

        label_3 = new QLabel(page_statistical);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        doubleSpinBox_filter1_desv = new QDoubleSpinBox(page_statistical);
        doubleSpinBox_filter1_desv->setObjectName(QString::fromUtf8("doubleSpinBox_filter1_desv"));
        doubleSpinBox_filter1_desv->setDecimals(4);
        doubleSpinBox_filter1_desv->setSingleStep(0.0001);
        doubleSpinBox_filter1_desv->setValue(0.01);

        gridLayout_3->addWidget(doubleSpinBox_filter1_desv, 1, 1, 1, 1);

        stackedWidget_filter->addWidget(page_statistical);
        page_radius_search = new QWidget();
        page_radius_search->setObjectName(QString::fromUtf8("page_radius_search"));
        gridLayout_4 = new QGridLayout(page_radius_search);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_8 = new QLabel(page_radius_search);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy5.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(label_8, 0, 0, 1, 1);

        doubleSpinBox_radio = new QDoubleSpinBox(page_radius_search);
        doubleSpinBox_radio->setObjectName(QString::fromUtf8("doubleSpinBox_radio"));
        doubleSpinBox_radio->setDecimals(4);
        doubleSpinBox_radio->setSingleStep(0.0001);
        doubleSpinBox_radio->setValue(0.01);

        gridLayout_4->addWidget(doubleSpinBox_radio, 0, 1, 1, 1);

        label_7 = new QLabel(page_radius_search);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        doubleSpinBox_radio_k = new QDoubleSpinBox(page_radius_search);
        doubleSpinBox_radio_k->setObjectName(QString::fromUtf8("doubleSpinBox_radio_k"));
        doubleSpinBox_radio_k->setDecimals(0);
        doubleSpinBox_radio_k->setSingleStep(1);
        doubleSpinBox_radio_k->setValue(7);

        gridLayout_4->addWidget(doubleSpinBox_radio_k, 1, 1, 1, 1);

        stackedWidget_filter->addWidget(page_radius_search);
        page_resampling = new QWidget();
        page_resampling->setObjectName(QString::fromUtf8("page_resampling"));
        gridLayout_8 = new QGridLayout(page_resampling);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_6 = new QLabel(page_resampling);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy5.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy5);

        gridLayout_8->addWidget(label_6, 0, 0, 1, 1);

        doubleSpinBox_smooth = new QDoubleSpinBox(page_resampling);
        doubleSpinBox_smooth->setObjectName(QString::fromUtf8("doubleSpinBox_smooth"));
        doubleSpinBox_smooth->setDecimals(5);
        doubleSpinBox_smooth->setSingleStep(0.0001);
        doubleSpinBox_smooth->setValue(0.001);

        gridLayout_8->addWidget(doubleSpinBox_smooth, 0, 1, 1, 1);

        stackedWidget_filter->addWidget(page_resampling);
        page_pass = new QWidget();
        page_pass->setObjectName(QString::fromUtf8("page_pass"));
        gridLayout_10 = new QGridLayout(page_pass);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        comboBox_pass = new QComboBox(page_pass);
        comboBox_pass->setObjectName(QString::fromUtf8("comboBox_pass"));
        sizePolicy1.setHeightForWidth(comboBox_pass->sizePolicy().hasHeightForWidth());
        comboBox_pass->setSizePolicy(sizePolicy1);

        gridLayout_10->addWidget(comboBox_pass, 0, 0, 1, 2);

        doubleSpinBox_max_pass = new QDoubleSpinBox(page_pass);
        doubleSpinBox_max_pass->setObjectName(QString::fromUtf8("doubleSpinBox_max_pass"));
        doubleSpinBox_max_pass->setDecimals(3);
        doubleSpinBox_max_pass->setMinimum(-99);
        doubleSpinBox_max_pass->setSingleStep(0.01);

        gridLayout_10->addWidget(doubleSpinBox_max_pass, 2, 1, 1, 1);

        label_12 = new QLabel(page_pass);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy5.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy5);

        gridLayout_10->addWidget(label_12, 1, 0, 1, 1);

        doubleSpinBox_min_pass = new QDoubleSpinBox(page_pass);
        doubleSpinBox_min_pass->setObjectName(QString::fromUtf8("doubleSpinBox_min_pass"));
        doubleSpinBox_min_pass->setDecimals(3);
        doubleSpinBox_min_pass->setMinimum(-99);
        doubleSpinBox_min_pass->setSingleStep(0.01);

        gridLayout_10->addWidget(doubleSpinBox_min_pass, 1, 1, 1, 1);

        label_13 = new QLabel(page_pass);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_10->addWidget(label_13, 2, 0, 1, 1);

        stackedWidget_filter->addWidget(page_pass);

        gridLayout->addWidget(stackedWidget_filter, 6, 0, 1, 3);

        comboBox_filter = new QComboBox(tab_filters);
        comboBox_filter->setObjectName(QString::fromUtf8("comboBox_filter"));
        sizePolicy1.setHeightForWidth(comboBox_filter->sizePolicy().hasHeightForWidth());
        comboBox_filter->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_filter, 5, 0, 1, 3);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        pushButton_accept_filter = new QPushButton(tab_filters);
        pushButton_accept_filter->setObjectName(QString::fromUtf8("pushButton_accept_filter"));

        gridLayout_13->addWidget(pushButton_accept_filter, 0, 0, 1, 1);

        pushButton_undo_filter = new QPushButton(tab_filters);
        pushButton_undo_filter->setObjectName(QString::fromUtf8("pushButton_undo_filter"));

        gridLayout_13->addWidget(pushButton_undo_filter, 0, 2, 1, 1);

        pushButton_filter = new QPushButton(tab_filters);
        pushButton_filter->setObjectName(QString::fromUtf8("pushButton_filter"));

        gridLayout_13->addWidget(pushButton_filter, 1, 0, 1, 1);

        pushButton = new QPushButton(tab_filters);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_13->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_apply_filtering = new QPushButton(tab_filters);
        pushButton_apply_filtering->setObjectName(QString::fromUtf8("pushButton_apply_filtering"));

        gridLayout_13->addWidget(pushButton_apply_filtering, 1, 2, 1, 1);


        gridLayout->addLayout(gridLayout_13, 1, 0, 1, 3);

        tabWidget->addTab(tab_filters, QString());
        tab_fit = new QWidget();
        tab_fit->setObjectName(QString::fromUtf8("tab_fit"));
        gridLayout_5 = new QGridLayout(tab_fit);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        textBrowser_data_2 = new QTextBrowser(tab_fit);
        textBrowser_data_2->setObjectName(QString::fromUtf8("textBrowser_data_2"));
        sizePolicy4.setHeightForWidth(textBrowser_data_2->sizePolicy().hasHeightForWidth());
        textBrowser_data_2->setSizePolicy(sizePolicy4);

        gridLayout_5->addWidget(textBrowser_data_2, 6, 0, 1, 3);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        doubleSpinBox_angle = new QDoubleSpinBox(tab_fit);
        doubleSpinBox_angle->setObjectName(QString::fromUtf8("doubleSpinBox_angle"));
        doubleSpinBox_angle->setDecimals(5);
        doubleSpinBox_angle->setMinimum(-10);
        doubleSpinBox_angle->setMaximum(10);
        doubleSpinBox_angle->setSingleStep(0.1);

        gridLayout_12->addWidget(doubleSpinBox_angle, 1, 4, 1, 1);

        label_15 = new QLabel(tab_fit);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_12->addWidget(label_15, 0, 1, 1, 1);

        doubleSpinBox_2dx = new QDoubleSpinBox(tab_fit);
        doubleSpinBox_2dx->setObjectName(QString::fromUtf8("doubleSpinBox_2dx"));
        doubleSpinBox_2dx->setMinimum(-500);
        doubleSpinBox_2dx->setMaximum(5000);

        gridLayout_12->addWidget(doubleSpinBox_2dx, 0, 2, 1, 1);

        doubleSpinBox_2dy = new QDoubleSpinBox(tab_fit);
        doubleSpinBox_2dy->setObjectName(QString::fromUtf8("doubleSpinBox_2dy"));
        doubleSpinBox_2dy->setMinimum(-500);
        doubleSpinBox_2dy->setMaximum(5000);

        gridLayout_12->addWidget(doubleSpinBox_2dy, 0, 4, 1, 1);

        pushButton_2d_place = new QPushButton(tab_fit);
        pushButton_2d_place->setObjectName(QString::fromUtf8("pushButton_2d_place"));

        gridLayout_12->addWidget(pushButton_2d_place, 0, 0, 2, 1);

        label_16 = new QLabel(tab_fit);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_12->addWidget(label_16, 0, 3, 1, 1);

        label_17 = new QLabel(tab_fit);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_12->addWidget(label_17, 1, 2, 1, 2);


        gridLayout_5->addLayout(gridLayout_12, 7, 0, 1, 3);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        pushButton_accept_fitting = new QPushButton(tab_fit);
        pushButton_accept_fitting->setObjectName(QString::fromUtf8("pushButton_accept_fitting"));

        gridLayout_9->addWidget(pushButton_accept_fitting, 0, 0, 1, 1);

        pushButton_record_plane = new QPushButton(tab_fit);
        pushButton_record_plane->setObjectName(QString::fromUtf8("pushButton_record_plane"));

        gridLayout_9->addWidget(pushButton_record_plane, 2, 0, 1, 1);

        pushButton_distances = new QPushButton(tab_fit);
        pushButton_distances->setObjectName(QString::fromUtf8("pushButton_distances"));

        gridLayout_9->addWidget(pushButton_distances, 1, 1, 1, 1);

        pushButton_reorient = new QPushButton(tab_fit);
        pushButton_reorient->setObjectName(QString::fromUtf8("pushButton_reorient"));

        gridLayout_9->addWidget(pushButton_reorient, 2, 1, 1, 1);

        pushButton_function_plane_fit = new QPushButton(tab_fit);
        pushButton_function_plane_fit->setObjectName(QString::fromUtf8("pushButton_function_plane_fit"));

        gridLayout_9->addWidget(pushButton_function_plane_fit, 1, 0, 1, 1);

        pushButton_undo_plane = new QPushButton(tab_fit);
        pushButton_undo_plane->setObjectName(QString::fromUtf8("pushButton_undo_plane"));

        gridLayout_9->addWidget(pushButton_undo_plane, 0, 1, 1, 1);

        checkBox_points_sup = new QCheckBox(tab_fit);
        checkBox_points_sup->setObjectName(QString::fromUtf8("checkBox_points_sup"));
        checkBox_points_sup->setChecked(true);
        checkBox_points_sup->setTristate(false);

        gridLayout_9->addWidget(checkBox_points_sup, 3, 0, 1, 1);

        pushButton_center = new QPushButton(tab_fit);
        pushButton_center->setObjectName(QString::fromUtf8("pushButton_center"));

        gridLayout_9->addWidget(pushButton_center, 3, 1, 1, 1);

        label_14 = new QLabel(tab_fit);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_9->addWidget(label_14, 4, 0, 1, 1);

        doubleSpinBox_ransac_dist = new QDoubleSpinBox(tab_fit);
        doubleSpinBox_ransac_dist->setObjectName(QString::fromUtf8("doubleSpinBox_ransac_dist"));
        doubleSpinBox_ransac_dist->setDecimals(5);
        doubleSpinBox_ransac_dist->setSingleStep(0.0001);
        doubleSpinBox_ransac_dist->setValue(0.001);

        gridLayout_9->addWidget(doubleSpinBox_ransac_dist, 4, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_9, 0, 0, 1, 3);

        tabWidget->addTab(tab_fit, QString());
        tab_projections = new QWidget();
        tab_projections->setObjectName(QString::fromUtf8("tab_projections"));
        gridLayout_11 = new QGridLayout(tab_projections);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        pushButton_proj_points = new QPushButton(tab_projections);
        pushButton_proj_points->setObjectName(QString::fromUtf8("pushButton_proj_points"));
        sizePolicy1.setHeightForWidth(pushButton_proj_points->sizePolicy().hasHeightForWidth());
        pushButton_proj_points->setSizePolicy(sizePolicy1);

        gridLayout_11->addWidget(pushButton_proj_points, 0, 0, 1, 2);

        textBrowser_projection = new QTextBrowser(tab_projections);
        textBrowser_projection->setObjectName(QString::fromUtf8("textBrowser_projection"));
        sizePolicy4.setHeightForWidth(textBrowser_projection->sizePolicy().hasHeightForWidth());
        textBrowser_projection->setSizePolicy(sizePolicy4);

        gridLayout_11->addWidget(textBrowser_projection, 2, 0, 1, 2);

        tabWidget->addTab(tab_projections, QString());
        tab_align = new QWidget();
        tab_align->setObjectName(QString::fromUtf8("tab_align"));
        gridLayoutWidget = new QWidget(tab_align);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 321, 71));
        gridLayout_15 = new QGridLayout(gridLayoutWidget);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        pushButton_load_model = new QPushButton(gridLayoutWidget);
        pushButton_load_model->setObjectName(QString::fromUtf8("pushButton_load_model"));

        gridLayout_15->addWidget(pushButton_load_model, 0, 0, 1, 1);

        pushButton_delete_model = new QPushButton(gridLayoutWidget);
        pushButton_delete_model->setObjectName(QString::fromUtf8("pushButton_delete_model"));

        gridLayout_15->addWidget(pushButton_delete_model, 0, 1, 1, 1);

        pushButton_fine_alignment = new QPushButton(gridLayoutWidget);
        pushButton_fine_alignment->setObjectName(QString::fromUtf8("pushButton_fine_alignment"));

        gridLayout_15->addWidget(pushButton_fine_alignment, 1, 1, 1, 1);

        pushButton_init_align = new QPushButton(gridLayoutWidget);
        pushButton_init_align->setObjectName(QString::fromUtf8("pushButton_init_align"));

        gridLayout_15->addWidget(pushButton_init_align, 1, 0, 1, 1);

        textBrowser_align = new QTextBrowser(tab_align);
        textBrowser_align->setObjectName(QString::fromUtf8("textBrowser_align"));
        textBrowser_align->setGeometry(QRect(10, 90, 311, 421));
        tabWidget->addTab(tab_align, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        doubleSpinBox_cloud_size = new QDoubleSpinBox(tab);
        doubleSpinBox_cloud_size->setObjectName(QString::fromUtf8("doubleSpinBox_cloud_size"));
        doubleSpinBox_cloud_size->setDecimals(1);
        doubleSpinBox_cloud_size->setSingleStep(0.1);
        doubleSpinBox_cloud_size->setValue(1);

        gridLayout_6->addWidget(doubleSpinBox_cloud_size, 2, 1, 1, 1);

        doubleSpinBox_mod_size = new QDoubleSpinBox(tab);
        doubleSpinBox_mod_size->setObjectName(QString::fromUtf8("doubleSpinBox_mod_size"));
        doubleSpinBox_mod_size->setDecimals(1);
        doubleSpinBox_mod_size->setSingleStep(0.1);
        doubleSpinBox_mod_size->setValue(1);

        gridLayout_6->addWidget(doubleSpinBox_mod_size, 3, 1, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_6->addWidget(label_11, 4, 0, 1, 1);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy5.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy5);

        gridLayout_6->addWidget(label_9, 2, 0, 1, 1);

        doubleSpinBox_sel_size = new QDoubleSpinBox(tab);
        doubleSpinBox_sel_size->setObjectName(QString::fromUtf8("doubleSpinBox_sel_size"));
        doubleSpinBox_sel_size->setDecimals(1);
        doubleSpinBox_sel_size->setSingleStep(0.1);
        doubleSpinBox_sel_size->setValue(1);

        gridLayout_6->addWidget(doubleSpinBox_sel_size, 4, 1, 1, 1);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_6->addWidget(label_10, 3, 0, 1, 1);

        pushButton_test = new QPushButton(tab);
        pushButton_test->setObjectName(QString::fromUtf8("pushButton_test"));

        gridLayout_6->addWidget(pushButton_test, 0, 0, 1, 2);

        label_18 = new QLabel(tab);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_6->addWidget(label_18, 1, 0, 1, 1);

        spinBox_cluster = new QSpinBox(tab);
        spinBox_cluster->setObjectName(QString::fromUtf8("spinBox_cluster"));

        gridLayout_6->addWidget(spinBox_cluster, 1, 1, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout_16->addWidget(tabWidget, 1, 0, 1, 1);


        gridLayout_14->addLayout(gridLayout_16, 0, 0, 1, 1);

        //gridLayout_17 = new QGridLayout();
        //gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        //gridLayout_17->setSizeConstraint(QLayout::SetDefaultConstraint);
        //qvtkWidget = new QVTKWidget(centerlwidget);
        //qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        //QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        //sizePolicy6.setHorizontalStretch(0);
        //sizePolicy6.setVerticalStretch(0);
        //sizePolicy6.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        //qvtkWidget->setSizePolicy(sizePolicy6);
        //qvtkWidget->setSizeIncrement(QSize(1, 1));
        //qvtkWidget->setAutoFillBackground(true);

        //gridLayout_17->addWidget(qvtkWidget, 0, 0, 1, 1);


        //gridLayout_14->addLayout(gridLayout_17, 0, 1, 1, 1);

        PCLViewer->setCentralWidget(centerlwidget);
        menuBar = new QMenuBar(PCLViewer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 966, 25));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        PCLViewer->setMenuBar(menuBar);

        menuBar->addAction(menuSettings->menuAction());
        menuSettings->addAction(actionLoad);
        menuSettings->addAction(actionSave);

        retranslateUi(PCLViewer);
        QObject::connect(comboBox_filter, SIGNAL(currentIndexChanged(int)), stackedWidget_filter, SLOT(setCurrentIndex(int)));

        tabWidget->setCurrentIndex(0);
        stackedWidget_filter->setCurrentIndex(4);
        comboBox_filter->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PCLViewer);
    } // setupUi

    void retranslateUi(QMainWindow *PCLViewer)
    {
        PCLViewer->setWindowTitle(QApplication::translate("PCLViewer", "PCLViewer", 0));
        actionLoad->setText(QApplication::translate("PCLViewer", "Load", 0));
        actionSave->setText(QApplication::translate("PCLViewer", "Save", 0));
        pushButton_save->setText(QApplication::translate("PCLViewer", "Save Cloud", 0));
        pushButton_load->setText(QApplication::translate("PCLViewer", "Load Cloud", 0));
        label_2->setText(QApplication::translate("PCLViewer", "Size X", 0));
        label_4->setText(QApplication::translate("PCLViewer", "Size Y", 0));
        label_5->setText(QApplication::translate("PCLViewer", "Size Z", 0));
        label->setText(QApplication::translate("PCLViewer", "K n neighbors:", 0));
        label_3->setText(QApplication::translate("PCLViewer", "Deviation:", 0));
        label_8->setText(QApplication::translate("PCLViewer", "Radius:", 0));
        label_7->setText(QApplication::translate("PCLViewer", "Param K:", 0));
        label_6->setText(QApplication::translate("PCLViewer", "Search Radius", 0));
        comboBox_pass->clear();
        comboBox_pass->insertItems(0, QStringList()
         << QApplication::translate("PCLViewer", "X filter", 0)
         << QApplication::translate("PCLViewer", "Y filter", 0)
         << QApplication::translate("PCLViewer", "Z filter", 0)
        );
        label_12->setText(QApplication::translate("PCLViewer", "Min:", 0));
        label_13->setText(QApplication::translate("PCLViewer", "Max:", 0));
        comboBox_filter->clear();
        comboBox_filter->insertItems(0, QStringList()
         << QApplication::translate("PCLViewer", "Voxel Grid", 0)
         << QApplication::translate("PCLViewer", "Statistical filter", 0)
         << QApplication::translate("PCLViewer", "Radius search filter", 0)
         << QApplication::translate("PCLViewer", "Resampling", 0)
         << QApplication::translate("PCLViewer", "Pass trough", 0)
        );
        pushButton_accept_filter->setText(QApplication::translate("PCLViewer", "Accept", 0));
        pushButton_undo_filter->setText(QApplication::translate("PCLViewer", "Undo", 0));
        pushButton_filter->setText(QApplication::translate("PCLViewer", "Autofilter", 0));
        pushButton->setText(QApplication::translate("PCLViewer", "Cloud data", 0));
        pushButton_apply_filtering->setText(QApplication::translate("PCLViewer", "Apply", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_filters), QApplication::translate("PCLViewer", "Filter", 0));
        label_15->setText(QApplication::translate("PCLViewer", "X:", 0));
        pushButton_2d_place->setText(QApplication::translate("PCLViewer", "Place 2d", 0));
        label_16->setText(QApplication::translate("PCLViewer", "Y:", 0));
        label_17->setText(QApplication::translate("PCLViewer", "Angle:", 0));
        pushButton_accept_fitting->setText(QApplication::translate("PCLViewer", "Accept", 0));
        pushButton_record_plane->setText(QApplication::translate("PCLViewer", "record", 0));
        pushButton_distances->setText(QApplication::translate("PCLViewer", "Distance", 0));
        pushButton_reorient->setText(QApplication::translate("PCLViewer", "Reorient", 0));
        pushButton_function_plane_fit->setText(QApplication::translate("PCLViewer", "Plane fit", 0));
        pushButton_undo_plane->setText(QApplication::translate("PCLViewer", "Undo", 0));
        checkBox_points_sup->setText(QApplication::translate("PCLViewer", "Upper", 0));
        pushButton_center->setText(QApplication::translate("PCLViewer", "Center point", 0));
        label_14->setText(QApplication::translate("PCLViewer", "Distance threshold:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_fit), QApplication::translate("PCLViewer", "Fit", 0));
        pushButton_proj_points->setText(QApplication::translate("PCLViewer", "Project points", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_projections), QApplication::translate("PCLViewer", "Pojection", 0));
        pushButton_load_model->setText(QApplication::translate("PCLViewer", "Load Model", 0));
        pushButton_delete_model->setText(QApplication::translate("PCLViewer", "Delete", 0));
        pushButton_fine_alignment->setText(QApplication::translate("PCLViewer", "Fine Alignment", 0));
        pushButton_init_align->setText(QApplication::translate("PCLViewer", "Initial Alignment", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_align), QApplication::translate("PCLViewer", "Align", 0));
        label_11->setText(QApplication::translate("PCLViewer", "Sel point cloud", 0));
        label_9->setText(QApplication::translate("PCLViewer", "Point cloud size", 0));
        label_10->setText(QApplication::translate("PCLViewer", "Mod point cloud", 0));
        pushButton_test->setText(QApplication::translate("PCLViewer", "Function Test", 0));
        label_18->setText(QApplication::translate("PCLViewer", "Cluster:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("PCLViewer", "Test", 0));
        menuSettings->setTitle(QApplication::translate("PCLViewer", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class PCLViewer: public Ui_PCLViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLVIEWER_H
