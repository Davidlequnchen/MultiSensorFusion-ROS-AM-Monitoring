/********************************************************************************
** Form generated from reading UI file 'pclviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
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
    QLabel *label_deviation;
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
    QMenuBar *menuBar;
    QMenu *menuSettings;

    void setupUi(QMainWindow *PCLViewer)
    {
        if (PCLViewer->objectName().isEmpty())
            PCLViewer->setObjectName(QStringLiteral("PCLViewer"));
        PCLViewer->resize(500, 641);
        PCLViewer->setMinimumSize(QSize(500, 641));
        PCLViewer->setMaximumSize(QSize(5000, 5000));
        actionLoad = new QAction(PCLViewer);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave = new QAction(PCLViewer);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centerlwidget = new QWidget(PCLViewer);
        centerlwidget->setObjectName(QStringLiteral("centerlwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centerlwidget->sizePolicy().hasHeightForWidth());
        centerlwidget->setSizePolicy(sizePolicy);
        gridLayout_14 = new QGridLayout(centerlwidget);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_14->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        gridLayout_16->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        pushButton_save = new QPushButton(centerlwidget);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_save->sizePolicy().hasHeightForWidth());
        pushButton_save->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(pushButton_save, 0, 1, 1, 1);

        pushButton_load = new QPushButton(centerlwidget);
        pushButton_load->setObjectName(QStringLiteral("pushButton_load"));
        sizePolicy1.setHeightForWidth(pushButton_load->sizePolicy().hasHeightForWidth());
        pushButton_load->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(pushButton_load, 0, 0, 1, 1);


        gridLayout_16->addLayout(gridLayout_7, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centerlwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tab_filters = new QWidget();
        tab_filters->setObjectName(QStringLiteral("tab_filters"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tab_filters->sizePolicy().hasHeightForWidth());
        tab_filters->setSizePolicy(sizePolicy3);
        gridLayout = new QGridLayout(tab_filters);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textBrowser_data = new QTextBrowser(tab_filters);
        textBrowser_data->setObjectName(QStringLiteral("textBrowser_data"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(textBrowser_data->sizePolicy().hasHeightForWidth());
        textBrowser_data->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(textBrowser_data, 4, 0, 1, 3);

        stackedWidget_filter = new QStackedWidget(tab_filters);
        stackedWidget_filter->setObjectName(QStringLiteral("stackedWidget_filter"));
        sizePolicy1.setHeightForWidth(stackedWidget_filter->sizePolicy().hasHeightForWidth());
        stackedWidget_filter->setSizePolicy(sizePolicy1);
        stackedWidget_filter->setFrameShape(QFrame::StyledPanel);
        page_voxel = new QWidget();
        page_voxel->setObjectName(QStringLiteral("page_voxel"));
        gridLayout_2 = new QGridLayout(page_voxel);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(page_voxel);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy5);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        doubleSpinBox_voxel_x = new QDoubleSpinBox(page_voxel);
        doubleSpinBox_voxel_x->setObjectName(QStringLiteral("doubleSpinBox_voxel_x"));
        doubleSpinBox_voxel_x->setDecimals(6);
        doubleSpinBox_voxel_x->setSingleStep(0.0001);
        doubleSpinBox_voxel_x->setValue(0.01);

        gridLayout_2->addWidget(doubleSpinBox_voxel_x, 0, 1, 1, 1);

        label_4 = new QLabel(page_voxel);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        doubleSpinBox_voxel_y = new QDoubleSpinBox(page_voxel);
        doubleSpinBox_voxel_y->setObjectName(QStringLiteral("doubleSpinBox_voxel_y"));
        doubleSpinBox_voxel_y->setDecimals(6);
        doubleSpinBox_voxel_y->setSingleStep(0.0001);
        doubleSpinBox_voxel_y->setValue(0.01);

        gridLayout_2->addWidget(doubleSpinBox_voxel_y, 1, 1, 1, 1);

        label_5 = new QLabel(page_voxel);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        doubleSpinBox_voxel_z = new QDoubleSpinBox(page_voxel);
        doubleSpinBox_voxel_z->setObjectName(QStringLiteral("doubleSpinBox_voxel_z"));
        doubleSpinBox_voxel_z->setDecimals(6);
        doubleSpinBox_voxel_z->setSingleStep(0.0001);
        doubleSpinBox_voxel_z->setValue(0.01);

        gridLayout_2->addWidget(doubleSpinBox_voxel_z, 2, 1, 1, 1);

        stackedWidget_filter->addWidget(page_voxel);
        page_statistical = new QWidget();
        page_statistical->setObjectName(QStringLiteral("page_statistical"));
        gridLayout_3 = new QGridLayout(page_statistical);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(page_statistical);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        doubleSpinBox_filter1_kn = new QDoubleSpinBox(page_statistical);
        doubleSpinBox_filter1_kn->setObjectName(QStringLiteral("doubleSpinBox_filter1_kn"));
        doubleSpinBox_filter1_kn->setDecimals(0);
        doubleSpinBox_filter1_kn->setSingleStep(1);
        doubleSpinBox_filter1_kn->setValue(5);

        gridLayout_3->addWidget(doubleSpinBox_filter1_kn, 0, 1, 1, 1);

        label_deviation = new QLabel(page_statistical);
        label_deviation->setObjectName(QStringLiteral("label_deviation"));

        gridLayout_3->addWidget(label_deviation, 1, 0, 1, 1);

        doubleSpinBox_filter1_desv = new QDoubleSpinBox(page_statistical);
        doubleSpinBox_filter1_desv->setObjectName(QStringLiteral("doubleSpinBox_filter1_desv"));
        doubleSpinBox_filter1_desv->setDecimals(4);
        doubleSpinBox_filter1_desv->setSingleStep(0.0001);
        doubleSpinBox_filter1_desv->setValue(0.01);

        gridLayout_3->addWidget(doubleSpinBox_filter1_desv, 1, 1, 1, 1);

        stackedWidget_filter->addWidget(page_statistical);
        page_radius_search = new QWidget();
        page_radius_search->setObjectName(QStringLiteral("page_radius_search"));
        gridLayout_4 = new QGridLayout(page_radius_search);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_8 = new QLabel(page_radius_search);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy5.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(label_8, 0, 0, 1, 1);

        doubleSpinBox_radio = new QDoubleSpinBox(page_radius_search);
        doubleSpinBox_radio->setObjectName(QStringLiteral("doubleSpinBox_radio"));
        doubleSpinBox_radio->setDecimals(4);
        doubleSpinBox_radio->setSingleStep(0.0001);
        doubleSpinBox_radio->setValue(0.01);

        gridLayout_4->addWidget(doubleSpinBox_radio, 0, 1, 1, 1);

        label_7 = new QLabel(page_radius_search);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        doubleSpinBox_radio_k = new QDoubleSpinBox(page_radius_search);
        doubleSpinBox_radio_k->setObjectName(QStringLiteral("doubleSpinBox_radio_k"));
        doubleSpinBox_radio_k->setDecimals(0);
        doubleSpinBox_radio_k->setSingleStep(1);
        doubleSpinBox_radio_k->setValue(7);

        gridLayout_4->addWidget(doubleSpinBox_radio_k, 1, 1, 1, 1);

        stackedWidget_filter->addWidget(page_radius_search);
        page_resampling = new QWidget();
        page_resampling->setObjectName(QStringLiteral("page_resampling"));
        gridLayout_8 = new QGridLayout(page_resampling);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label_6 = new QLabel(page_resampling);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy5.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy5);

        gridLayout_8->addWidget(label_6, 0, 0, 1, 1);

        doubleSpinBox_smooth = new QDoubleSpinBox(page_resampling);
        doubleSpinBox_smooth->setObjectName(QStringLiteral("doubleSpinBox_smooth"));
        doubleSpinBox_smooth->setDecimals(5);
        doubleSpinBox_smooth->setSingleStep(0.0001);
        doubleSpinBox_smooth->setValue(0.001);

        gridLayout_8->addWidget(doubleSpinBox_smooth, 0, 1, 1, 1);

        stackedWidget_filter->addWidget(page_resampling);
        page_pass = new QWidget();
        page_pass->setObjectName(QStringLiteral("page_pass"));
        gridLayout_10 = new QGridLayout(page_pass);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        comboBox_pass = new QComboBox(page_pass);
        comboBox_pass->setObjectName(QStringLiteral("comboBox_pass"));
        sizePolicy1.setHeightForWidth(comboBox_pass->sizePolicy().hasHeightForWidth());
        comboBox_pass->setSizePolicy(sizePolicy1);

        gridLayout_10->addWidget(comboBox_pass, 0, 0, 1, 2);

        doubleSpinBox_max_pass = new QDoubleSpinBox(page_pass);
        doubleSpinBox_max_pass->setObjectName(QStringLiteral("doubleSpinBox_max_pass"));
        doubleSpinBox_max_pass->setDecimals(3);
        doubleSpinBox_max_pass->setMinimum(-99);
        doubleSpinBox_max_pass->setSingleStep(0.01);

        gridLayout_10->addWidget(doubleSpinBox_max_pass, 2, 1, 1, 1);

        label_12 = new QLabel(page_pass);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy5.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy5);

        gridLayout_10->addWidget(label_12, 1, 0, 1, 1);

        doubleSpinBox_min_pass = new QDoubleSpinBox(page_pass);
        doubleSpinBox_min_pass->setObjectName(QStringLiteral("doubleSpinBox_min_pass"));
        doubleSpinBox_min_pass->setDecimals(3);
        doubleSpinBox_min_pass->setMinimum(-99);
        doubleSpinBox_min_pass->setSingleStep(0.01);

        gridLayout_10->addWidget(doubleSpinBox_min_pass, 1, 1, 1, 1);

        label_13 = new QLabel(page_pass);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_10->addWidget(label_13, 2, 0, 1, 1);

        stackedWidget_filter->addWidget(page_pass);

        gridLayout->addWidget(stackedWidget_filter, 6, 0, 1, 3);

        comboBox_filter = new QComboBox(tab_filters);
        comboBox_filter->setObjectName(QStringLiteral("comboBox_filter"));
        sizePolicy1.setHeightForWidth(comboBox_filter->sizePolicy().hasHeightForWidth());
        comboBox_filter->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_filter, 5, 0, 1, 3);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        pushButton_accept_filter = new QPushButton(tab_filters);
        pushButton_accept_filter->setObjectName(QStringLiteral("pushButton_accept_filter"));

        gridLayout_13->addWidget(pushButton_accept_filter, 0, 0, 1, 1);

        pushButton_undo_filter = new QPushButton(tab_filters);
        pushButton_undo_filter->setObjectName(QStringLiteral("pushButton_undo_filter"));

        gridLayout_13->addWidget(pushButton_undo_filter, 0, 2, 1, 1);

        pushButton_filter = new QPushButton(tab_filters);
        pushButton_filter->setObjectName(QStringLiteral("pushButton_filter"));

        gridLayout_13->addWidget(pushButton_filter, 1, 0, 1, 1);

        pushButton = new QPushButton(tab_filters);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_13->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_apply_filtering = new QPushButton(tab_filters);
        pushButton_apply_filtering->setObjectName(QStringLiteral("pushButton_apply_filtering"));

        gridLayout_13->addWidget(pushButton_apply_filtering, 1, 2, 1, 1);


        gridLayout->addLayout(gridLayout_13, 1, 0, 1, 3);

        tabWidget->addTab(tab_filters, QString());
        tab_fit = new QWidget();
        tab_fit->setObjectName(QStringLiteral("tab_fit"));
        gridLayout_5 = new QGridLayout(tab_fit);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        textBrowser_data_2 = new QTextBrowser(tab_fit);
        textBrowser_data_2->setObjectName(QStringLiteral("textBrowser_data_2"));
        sizePolicy4.setHeightForWidth(textBrowser_data_2->sizePolicy().hasHeightForWidth());
        textBrowser_data_2->setSizePolicy(sizePolicy4);

        gridLayout_5->addWidget(textBrowser_data_2, 6, 0, 1, 3);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        doubleSpinBox_angle = new QDoubleSpinBox(tab_fit);
        doubleSpinBox_angle->setObjectName(QStringLiteral("doubleSpinBox_angle"));
        doubleSpinBox_angle->setDecimals(5);
        doubleSpinBox_angle->setMinimum(-10);
        doubleSpinBox_angle->setMaximum(10);
        doubleSpinBox_angle->setSingleStep(0.1);

        gridLayout_12->addWidget(doubleSpinBox_angle, 1, 4, 1, 1);

        label_15 = new QLabel(tab_fit);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_12->addWidget(label_15, 0, 1, 1, 1);

        doubleSpinBox_2dx = new QDoubleSpinBox(tab_fit);
        doubleSpinBox_2dx->setObjectName(QStringLiteral("doubleSpinBox_2dx"));
        doubleSpinBox_2dx->setMinimum(-500);
        doubleSpinBox_2dx->setMaximum(5000);

        gridLayout_12->addWidget(doubleSpinBox_2dx, 0, 2, 1, 1);

        doubleSpinBox_2dy = new QDoubleSpinBox(tab_fit);
        doubleSpinBox_2dy->setObjectName(QStringLiteral("doubleSpinBox_2dy"));
        doubleSpinBox_2dy->setMinimum(-500);
        doubleSpinBox_2dy->setMaximum(5000);

        gridLayout_12->addWidget(doubleSpinBox_2dy, 0, 4, 1, 1);

        pushButton_2d_place = new QPushButton(tab_fit);
        pushButton_2d_place->setObjectName(QStringLiteral("pushButton_2d_place"));

        gridLayout_12->addWidget(pushButton_2d_place, 0, 0, 2, 1);

        label_16 = new QLabel(tab_fit);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_12->addWidget(label_16, 0, 3, 1, 1);

        label_17 = new QLabel(tab_fit);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_12->addWidget(label_17, 1, 2, 1, 2);


        gridLayout_5->addLayout(gridLayout_12, 7, 0, 1, 3);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        pushButton_accept_fitting = new QPushButton(tab_fit);
        pushButton_accept_fitting->setObjectName(QStringLiteral("pushButton_accept_fitting"));

        gridLayout_9->addWidget(pushButton_accept_fitting, 0, 0, 1, 1);

        pushButton_record_plane = new QPushButton(tab_fit);
        pushButton_record_plane->setObjectName(QStringLiteral("pushButton_record_plane"));

        gridLayout_9->addWidget(pushButton_record_plane, 2, 0, 1, 1);

        pushButton_distances = new QPushButton(tab_fit);
        pushButton_distances->setObjectName(QStringLiteral("pushButton_distances"));

        gridLayout_9->addWidget(pushButton_distances, 1, 1, 1, 1);

        pushButton_reorient = new QPushButton(tab_fit);
        pushButton_reorient->setObjectName(QStringLiteral("pushButton_reorient"));

        gridLayout_9->addWidget(pushButton_reorient, 2, 1, 1, 1);

        pushButton_function_plane_fit = new QPushButton(tab_fit);
        pushButton_function_plane_fit->setObjectName(QStringLiteral("pushButton_function_plane_fit"));

        gridLayout_9->addWidget(pushButton_function_plane_fit, 1, 0, 1, 1);

        pushButton_undo_plane = new QPushButton(tab_fit);
        pushButton_undo_plane->setObjectName(QStringLiteral("pushButton_undo_plane"));

        gridLayout_9->addWidget(pushButton_undo_plane, 0, 1, 1, 1);

        checkBox_points_sup = new QCheckBox(tab_fit);
        checkBox_points_sup->setObjectName(QStringLiteral("checkBox_points_sup"));
        checkBox_points_sup->setChecked(true);
        checkBox_points_sup->setTristate(false);

        gridLayout_9->addWidget(checkBox_points_sup, 3, 0, 1, 1);

        pushButton_center = new QPushButton(tab_fit);
        pushButton_center->setObjectName(QStringLiteral("pushButton_center"));

        gridLayout_9->addWidget(pushButton_center, 3, 1, 1, 1);

        label_14 = new QLabel(tab_fit);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_9->addWidget(label_14, 4, 0, 1, 1);

        doubleSpinBox_ransac_dist = new QDoubleSpinBox(tab_fit);
        doubleSpinBox_ransac_dist->setObjectName(QStringLiteral("doubleSpinBox_ransac_dist"));
        doubleSpinBox_ransac_dist->setDecimals(5);
        doubleSpinBox_ransac_dist->setSingleStep(0.0001);
        doubleSpinBox_ransac_dist->setValue(0.001);

        gridLayout_9->addWidget(doubleSpinBox_ransac_dist, 4, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_9, 0, 0, 1, 3);

        tabWidget->addTab(tab_fit, QString());
        tab_projections = new QWidget();
        tab_projections->setObjectName(QStringLiteral("tab_projections"));
        gridLayout_11 = new QGridLayout(tab_projections);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        pushButton_proj_points = new QPushButton(tab_projections);
        pushButton_proj_points->setObjectName(QStringLiteral("pushButton_proj_points"));
        sizePolicy1.setHeightForWidth(pushButton_proj_points->sizePolicy().hasHeightForWidth());
        pushButton_proj_points->setSizePolicy(sizePolicy1);

        gridLayout_11->addWidget(pushButton_proj_points, 0, 0, 1, 2);

        textBrowser_projection = new QTextBrowser(tab_projections);
        textBrowser_projection->setObjectName(QStringLiteral("textBrowser_projection"));
        sizePolicy4.setHeightForWidth(textBrowser_projection->sizePolicy().hasHeightForWidth());
        textBrowser_projection->setSizePolicy(sizePolicy4);

        gridLayout_11->addWidget(textBrowser_projection, 2, 0, 1, 2);

        tabWidget->addTab(tab_projections, QString());
        tab_align = new QWidget();
        tab_align->setObjectName(QStringLiteral("tab_align"));
        gridLayoutWidget = new QWidget(tab_align);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 321, 71));
        gridLayout_15 = new QGridLayout(gridLayoutWidget);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        pushButton_load_model = new QPushButton(gridLayoutWidget);
        pushButton_load_model->setObjectName(QStringLiteral("pushButton_load_model"));

        gridLayout_15->addWidget(pushButton_load_model, 0, 0, 1, 1);

        pushButton_delete_model = new QPushButton(gridLayoutWidget);
        pushButton_delete_model->setObjectName(QStringLiteral("pushButton_delete_model"));

        gridLayout_15->addWidget(pushButton_delete_model, 0, 1, 1, 1);

        pushButton_fine_alignment = new QPushButton(gridLayoutWidget);
        pushButton_fine_alignment->setObjectName(QStringLiteral("pushButton_fine_alignment"));

        gridLayout_15->addWidget(pushButton_fine_alignment, 1, 1, 1, 1);

        pushButton_init_align = new QPushButton(gridLayoutWidget);
        pushButton_init_align->setObjectName(QStringLiteral("pushButton_init_align"));

        gridLayout_15->addWidget(pushButton_init_align, 1, 0, 1, 1);

        textBrowser_align = new QTextBrowser(tab_align);
        textBrowser_align->setObjectName(QStringLiteral("textBrowser_align"));
        textBrowser_align->setGeometry(QRect(10, 90, 311, 421));
        tabWidget->addTab(tab_align, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        doubleSpinBox_cloud_size = new QDoubleSpinBox(tab);
        doubleSpinBox_cloud_size->setObjectName(QStringLiteral("doubleSpinBox_cloud_size"));
        doubleSpinBox_cloud_size->setDecimals(1);
        doubleSpinBox_cloud_size->setSingleStep(0.1);
        doubleSpinBox_cloud_size->setValue(5);

        gridLayout_6->addWidget(doubleSpinBox_cloud_size, 2, 1, 1, 1);

        doubleSpinBox_mod_size = new QDoubleSpinBox(tab);
        doubleSpinBox_mod_size->setObjectName(QStringLiteral("doubleSpinBox_mod_size"));
        doubleSpinBox_mod_size->setDecimals(1);
        doubleSpinBox_mod_size->setSingleStep(0.1);
        doubleSpinBox_mod_size->setValue(1);

        gridLayout_6->addWidget(doubleSpinBox_mod_size, 3, 1, 1, 1);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_6->addWidget(label_11, 4, 0, 1, 1);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy5.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy5);

        gridLayout_6->addWidget(label_9, 2, 0, 1, 1);

        doubleSpinBox_sel_size = new QDoubleSpinBox(tab);
        doubleSpinBox_sel_size->setObjectName(QStringLiteral("doubleSpinBox_sel_size"));
        doubleSpinBox_sel_size->setDecimals(1);
        doubleSpinBox_sel_size->setSingleStep(0.1);
        doubleSpinBox_sel_size->setValue(1);

        gridLayout_6->addWidget(doubleSpinBox_sel_size, 4, 1, 1, 1);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_6->addWidget(label_10, 3, 0, 1, 1);

        pushButton_test = new QPushButton(tab);
        pushButton_test->setObjectName(QStringLiteral("pushButton_test"));

        gridLayout_6->addWidget(pushButton_test, 0, 0, 1, 2);

        label_18 = new QLabel(tab);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_6->addWidget(label_18, 1, 0, 1, 1);

        spinBox_cluster = new QSpinBox(tab);
        spinBox_cluster->setObjectName(QStringLiteral("spinBox_cluster"));

        gridLayout_6->addWidget(spinBox_cluster, 1, 1, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout_16->addWidget(tabWidget, 1, 0, 1, 1);


        gridLayout_14->addLayout(gridLayout_16, 0, 0, 1, 1);

        PCLViewer->setCentralWidget(centerlwidget);
        menuBar = new QMenuBar(PCLViewer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 966, 25));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
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
        PCLViewer->setWindowTitle(QApplication::translate("PCLViewer", "PCLViewer", Q_NULLPTR));
        actionLoad->setText(QApplication::translate("PCLViewer", "Load", Q_NULLPTR));
        actionSave->setText(QApplication::translate("PCLViewer", "Save", Q_NULLPTR));
        pushButton_save->setText(QApplication::translate("PCLViewer", "Save Cloud", Q_NULLPTR));
        pushButton_load->setText(QApplication::translate("PCLViewer", "Load Cloud", Q_NULLPTR));
        label_2->setText(QApplication::translate("PCLViewer", "Size X", Q_NULLPTR));
        label_4->setText(QApplication::translate("PCLViewer", "Size Y", Q_NULLPTR));
        label_5->setText(QApplication::translate("PCLViewer", "Size Z", Q_NULLPTR));
        label->setText(QApplication::translate("PCLViewer", "K n neighbors:", Q_NULLPTR));
        label_deviation->setText(QApplication::translate("PCLViewer", "Deviation:", Q_NULLPTR));
        label_8->setText(QApplication::translate("PCLViewer", "Radius:", Q_NULLPTR));
        label_7->setText(QApplication::translate("PCLViewer", "Param K:", Q_NULLPTR));
        label_6->setText(QApplication::translate("PCLViewer", "Search Radius", Q_NULLPTR));
        comboBox_pass->clear();
        comboBox_pass->insertItems(0, QStringList()
         << QApplication::translate("PCLViewer", "X filter", Q_NULLPTR)
         << QApplication::translate("PCLViewer", "Y filter", Q_NULLPTR)
         << QApplication::translate("PCLViewer", "Z filter", Q_NULLPTR)
        );
        label_12->setText(QApplication::translate("PCLViewer", "Min:", Q_NULLPTR));
        label_13->setText(QApplication::translate("PCLViewer", "Max:", Q_NULLPTR));
        comboBox_filter->clear();
        comboBox_filter->insertItems(0, QStringList()
         << QApplication::translate("PCLViewer", "Voxel Grid", Q_NULLPTR)
         << QApplication::translate("PCLViewer", "Statistical filter", Q_NULLPTR)
         << QApplication::translate("PCLViewer", "Radius search filter", Q_NULLPTR)
         << QApplication::translate("PCLViewer", "Resampling", Q_NULLPTR)
         << QApplication::translate("PCLViewer", "Pass trough", Q_NULLPTR)
        );
        pushButton_accept_filter->setText(QApplication::translate("PCLViewer", "Accept", Q_NULLPTR));
        pushButton_undo_filter->setText(QApplication::translate("PCLViewer", "Undo", Q_NULLPTR));
        pushButton_filter->setText(QApplication::translate("PCLViewer", "Autofilter", Q_NULLPTR));
        pushButton->setText(QApplication::translate("PCLViewer", "Cloud data", Q_NULLPTR));
        pushButton_apply_filtering->setText(QApplication::translate("PCLViewer", "Apply", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_filters), QApplication::translate("PCLViewer", "Filter", Q_NULLPTR));
        label_15->setText(QApplication::translate("PCLViewer", "X:", Q_NULLPTR));
        pushButton_2d_place->setText(QApplication::translate("PCLViewer", "Place 2d", Q_NULLPTR));
        label_16->setText(QApplication::translate("PCLViewer", "Y:", Q_NULLPTR));
        label_17->setText(QApplication::translate("PCLViewer", "Angle:", Q_NULLPTR));
        pushButton_accept_fitting->setText(QApplication::translate("PCLViewer", "Accept", Q_NULLPTR));
        pushButton_record_plane->setText(QApplication::translate("PCLViewer", "record", Q_NULLPTR));
        pushButton_distances->setText(QApplication::translate("PCLViewer", "Distance", Q_NULLPTR));
        pushButton_reorient->setText(QApplication::translate("PCLViewer", "Reorient", Q_NULLPTR));
        pushButton_function_plane_fit->setText(QApplication::translate("PCLViewer", "Plane fit", Q_NULLPTR));
        pushButton_undo_plane->setText(QApplication::translate("PCLViewer", "Undo", Q_NULLPTR));
        checkBox_points_sup->setText(QApplication::translate("PCLViewer", "Upper", Q_NULLPTR));
        pushButton_center->setText(QApplication::translate("PCLViewer", "Center point", Q_NULLPTR));
        label_14->setText(QApplication::translate("PCLViewer", "Distance threshold:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_fit), QApplication::translate("PCLViewer", "Fit", Q_NULLPTR));
        pushButton_proj_points->setText(QApplication::translate("PCLViewer", "Project points", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_projections), QApplication::translate("PCLViewer", "Pojection", Q_NULLPTR));
        pushButton_load_model->setText(QApplication::translate("PCLViewer", "Load Model", Q_NULLPTR));
        pushButton_delete_model->setText(QApplication::translate("PCLViewer", "Delete", Q_NULLPTR));
        pushButton_fine_alignment->setText(QApplication::translate("PCLViewer", "Fine Alignment", Q_NULLPTR));
        pushButton_init_align->setText(QApplication::translate("PCLViewer", "Initial Alignment", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_align), QApplication::translate("PCLViewer", "Align", Q_NULLPTR));
        label_11->setText(QApplication::translate("PCLViewer", "Sel point cloud", Q_NULLPTR));
        label_9->setText(QApplication::translate("PCLViewer", "Point cloud size", Q_NULLPTR));
        label_10->setText(QApplication::translate("PCLViewer", "Mod point cloud", Q_NULLPTR));
        pushButton_test->setText(QApplication::translate("PCLViewer", "Function Test", Q_NULLPTR));
        label_18->setText(QApplication::translate("PCLViewer", "Cluster:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("PCLViewer", "Test", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("PCLViewer", "Settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PCLViewer: public Ui_PCLViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLVIEWER_H
