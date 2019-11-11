/********************************************************************************
** Form generated from reading UI file 'pclviewer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCLVIEWER_H
#define UI_PCLVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_PCLViewer
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QWidget *centralwidget;
    QGridLayout *gridLayout_14;
    QGridLayout *gridLayout_16;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_gardar;
    QPushButton *pushButton_load;
    QTabWidget *tabWidget;
    QWidget *tab_filtros;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser_datos;
    QStackedWidget *stackedWidget_filtros;
    QWidget *page_voxel;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_voxel_x;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_voxel_y;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_voxel_z;
    QWidget *page_morph;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_filtro1_kn;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_filtro1_desv;
    QWidget *page_filtro_2;
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
    QComboBox *comboBox_filtros;
    QGridLayout *gridLayout_13;
    QPushButton *pushButton_aceptar_filtro;
    QPushButton *pushButton_deshacer_filtro;
    QPushButton *pushButton_filter;
    QPushButton *pushButton;
    QPushButton *pushButton_funcion_1;
    QWidget *tab_fit;
    QGridLayout *gridLayout_5;
    QTextBrowser *textBrowser_datos_2;
    QGridLayout *gridLayout_12;
    QDoubleSpinBox *doubleSpinBox_angle;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_2dx;
    QDoubleSpinBox *doubleSpinBox_2dy;
    QPushButton *pushButton_2d_place;
    QLabel *label_16;
    QLabel *label_17;
    QGridLayout *gridLayout_9;
    QPushButton *pushButton_aceptar_fitting;
    QPushButton *pushButton_recorta_plano;
    QPushButton *pushButton_distances;
    QPushButton *pushButton_reorienta;
    QPushButton *pushButton_funcion_2;
    QPushButton *pushButton_deshacer_plano;
    QCheckBox *checkBox_puntos_sup;
    QPushButton *pushButton_centra;
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
    QGridLayout *gridLayout_17;
    QVTKWidget *qvtkWidget;
    QMenuBar *menuBar;
    QMenu *menuSettings;

    void setupUi(QMainWindow *PCLViewer)
    {
        if (PCLViewer->objectName().isEmpty())
            PCLViewer->setObjectName(QString::fromUtf8("PCLViewer"));
        PCLViewer->resize(966, 641);
        PCLViewer->setMinimumSize(QSize(966, 641));
        PCLViewer->setMaximumSize(QSize(5000, 5000));
        actionLoad = new QAction(PCLViewer);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionSave = new QAction(PCLViewer);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centralwidget = new QWidget(PCLViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout_14 = new QGridLayout(centralwidget);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_14->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_16 = new QGridLayout();
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setSizeConstraint(QLayout::SetFixedSize);
        pushButton_gardar = new QPushButton(centralwidget);
        pushButton_gardar->setObjectName(QString::fromUtf8("pushButton_gardar"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_gardar->sizePolicy().hasHeightForWidth());
        pushButton_gardar->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(pushButton_gardar, 0, 1, 1, 1);

        pushButton_load = new QPushButton(centralwidget);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));
        sizePolicy1.setHeightForWidth(pushButton_load->sizePolicy().hasHeightForWidth());
        pushButton_load->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(pushButton_load, 0, 0, 1, 1);


        gridLayout_16->addLayout(gridLayout_7, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tab_filtros = new QWidget();
        tab_filtros->setObjectName(QString::fromUtf8("tab_filtros"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tab_filtros->sizePolicy().hasHeightForWidth());
        tab_filtros->setSizePolicy(sizePolicy3);
        gridLayout = new QGridLayout(tab_filtros);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser_datos = new QTextBrowser(tab_filtros);
        textBrowser_datos->setObjectName(QString::fromUtf8("textBrowser_datos"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(textBrowser_datos->sizePolicy().hasHeightForWidth());
        textBrowser_datos->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(textBrowser_datos, 4, 0, 1, 3);

        stackedWidget_filtros = new QStackedWidget(tab_filtros);
        stackedWidget_filtros->setObjectName(QString::fromUtf8("stackedWidget_filtros"));
        sizePolicy1.setHeightForWidth(stackedWidget_filtros->sizePolicy().hasHeightForWidth());
        stackedWidget_filtros->setSizePolicy(sizePolicy1);
        stackedWidget_filtros->setFrameShape(QFrame::StyledPanel);
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

        stackedWidget_filtros->addWidget(page_voxel);
        page_morph = new QWidget();
        page_morph->setObjectName(QString::fromUtf8("page_morph"));
        gridLayout_3 = new QGridLayout(page_morph);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(page_morph);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        doubleSpinBox_filtro1_kn = new QDoubleSpinBox(page_morph);
        doubleSpinBox_filtro1_kn->setObjectName(QString::fromUtf8("doubleSpinBox_filtro1_kn"));
        doubleSpinBox_filtro1_kn->setDecimals(0);
        doubleSpinBox_filtro1_kn->setSingleStep(1);
        doubleSpinBox_filtro1_kn->setValue(5);

        gridLayout_3->addWidget(doubleSpinBox_filtro1_kn, 0, 1, 1, 1);

        label_3 = new QLabel(page_morph);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        doubleSpinBox_filtro1_desv = new QDoubleSpinBox(page_morph);
        doubleSpinBox_filtro1_desv->setObjectName(QString::fromUtf8("doubleSpinBox_filtro1_desv"));
        doubleSpinBox_filtro1_desv->setDecimals(4);
        doubleSpinBox_filtro1_desv->setSingleStep(0.0001);
        doubleSpinBox_filtro1_desv->setValue(0.01);

        gridLayout_3->addWidget(doubleSpinBox_filtro1_desv, 1, 1, 1, 1);

        stackedWidget_filtros->addWidget(page_morph);
        page_filtro_2 = new QWidget();
        page_filtro_2->setObjectName(QString::fromUtf8("page_filtro_2"));
        gridLayout_4 = new QGridLayout(page_filtro_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_8 = new QLabel(page_filtro_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy5.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy5);

        gridLayout_4->addWidget(label_8, 0, 0, 1, 1);

        doubleSpinBox_radio = new QDoubleSpinBox(page_filtro_2);
        doubleSpinBox_radio->setObjectName(QString::fromUtf8("doubleSpinBox_radio"));
        doubleSpinBox_radio->setDecimals(4);
        doubleSpinBox_radio->setSingleStep(0.0001);
        doubleSpinBox_radio->setValue(0.01);

        gridLayout_4->addWidget(doubleSpinBox_radio, 0, 1, 1, 1);

        label_7 = new QLabel(page_filtro_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        doubleSpinBox_radio_k = new QDoubleSpinBox(page_filtro_2);
        doubleSpinBox_radio_k->setObjectName(QString::fromUtf8("doubleSpinBox_radio_k"));
        doubleSpinBox_radio_k->setDecimals(0);
        doubleSpinBox_radio_k->setSingleStep(1);
        doubleSpinBox_radio_k->setValue(7);

        gridLayout_4->addWidget(doubleSpinBox_radio_k, 1, 1, 1, 1);

        stackedWidget_filtros->addWidget(page_filtro_2);
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

        stackedWidget_filtros->addWidget(page_resampling);
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

        stackedWidget_filtros->addWidget(page_pass);

        gridLayout->addWidget(stackedWidget_filtros, 6, 0, 1, 3);

        comboBox_filtros = new QComboBox(tab_filtros);
        comboBox_filtros->setObjectName(QString::fromUtf8("comboBox_filtros"));
        sizePolicy1.setHeightForWidth(comboBox_filtros->sizePolicy().hasHeightForWidth());
        comboBox_filtros->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_filtros, 5, 0, 1, 3);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        pushButton_aceptar_filtro = new QPushButton(tab_filtros);
        pushButton_aceptar_filtro->setObjectName(QString::fromUtf8("pushButton_aceptar_filtro"));

        gridLayout_13->addWidget(pushButton_aceptar_filtro, 0, 0, 1, 1);

        pushButton_deshacer_filtro = new QPushButton(tab_filtros);
        pushButton_deshacer_filtro->setObjectName(QString::fromUtf8("pushButton_deshacer_filtro"));

        gridLayout_13->addWidget(pushButton_deshacer_filtro, 0, 2, 1, 1);

        pushButton_filter = new QPushButton(tab_filtros);
        pushButton_filter->setObjectName(QString::fromUtf8("pushButton_filter"));

        gridLayout_13->addWidget(pushButton_filter, 1, 0, 1, 1);

        pushButton = new QPushButton(tab_filtros);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_13->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_funcion_1 = new QPushButton(tab_filtros);
        pushButton_funcion_1->setObjectName(QString::fromUtf8("pushButton_funcion_1"));

        gridLayout_13->addWidget(pushButton_funcion_1, 1, 2, 1, 1);


        gridLayout->addLayout(gridLayout_13, 1, 0, 1, 3);

        tabWidget->addTab(tab_filtros, QString());
        tab_fit = new QWidget();
        tab_fit->setObjectName(QString::fromUtf8("tab_fit"));
        gridLayout_5 = new QGridLayout(tab_fit);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        textBrowser_datos_2 = new QTextBrowser(tab_fit);
        textBrowser_datos_2->setObjectName(QString::fromUtf8("textBrowser_datos_2"));
        sizePolicy4.setHeightForWidth(textBrowser_datos_2->sizePolicy().hasHeightForWidth());
        textBrowser_datos_2->setSizePolicy(sizePolicy4);

        gridLayout_5->addWidget(textBrowser_datos_2, 6, 0, 1, 3);

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
        pushButton_aceptar_fitting = new QPushButton(tab_fit);
        pushButton_aceptar_fitting->setObjectName(QString::fromUtf8("pushButton_aceptar_fitting"));

        gridLayout_9->addWidget(pushButton_aceptar_fitting, 0, 0, 1, 1);

        pushButton_recorta_plano = new QPushButton(tab_fit);
        pushButton_recorta_plano->setObjectName(QString::fromUtf8("pushButton_recorta_plano"));

        gridLayout_9->addWidget(pushButton_recorta_plano, 2, 0, 1, 1);

        pushButton_distances = new QPushButton(tab_fit);
        pushButton_distances->setObjectName(QString::fromUtf8("pushButton_distances"));

        gridLayout_9->addWidget(pushButton_distances, 1, 1, 1, 1);

        pushButton_reorienta = new QPushButton(tab_fit);
        pushButton_reorienta->setObjectName(QString::fromUtf8("pushButton_reorienta"));

        gridLayout_9->addWidget(pushButton_reorienta, 2, 1, 1, 1);

        pushButton_funcion_2 = new QPushButton(tab_fit);
        pushButton_funcion_2->setObjectName(QString::fromUtf8("pushButton_funcion_2"));

        gridLayout_9->addWidget(pushButton_funcion_2, 1, 0, 1, 1);

        pushButton_deshacer_plano = new QPushButton(tab_fit);
        pushButton_deshacer_plano->setObjectName(QString::fromUtf8("pushButton_deshacer_plano"));

        gridLayout_9->addWidget(pushButton_deshacer_plano, 0, 1, 1, 1);

        checkBox_puntos_sup = new QCheckBox(tab_fit);
        checkBox_puntos_sup->setObjectName(QString::fromUtf8("checkBox_puntos_sup"));
        checkBox_puntos_sup->setChecked(true);
        checkBox_puntos_sup->setTristate(false);

        gridLayout_9->addWidget(checkBox_puntos_sup, 3, 0, 1, 1);

        pushButton_centra = new QPushButton(tab_fit);
        pushButton_centra->setObjectName(QString::fromUtf8("pushButton_centra"));

        gridLayout_9->addWidget(pushButton_centra, 3, 1, 1, 1);

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

        gridLayout_17 = new QGridLayout();
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setSizeConstraint(QLayout::SetDefaultConstraint);
        qvtkWidget = new QVTKWidget(centralwidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        QSizePolicy sizePolicy6(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy6);
        qvtkWidget->setSizeIncrement(QSize(1, 1));
        qvtkWidget->setAutoFillBackground(true);

        gridLayout_17->addWidget(qvtkWidget, 0, 0, 1, 1);


        gridLayout_14->addLayout(gridLayout_17, 0, 1, 1, 1);

        PCLViewer->setCentralWidget(centralwidget);
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
        QObject::connect(comboBox_filtros, SIGNAL(currentIndexChanged(int)), stackedWidget_filtros, SLOT(setCurrentIndex(int)));

        tabWidget->setCurrentIndex(0);
        stackedWidget_filtros->setCurrentIndex(4);
        comboBox_filtros->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PCLViewer);
    } // setupUi

    void retranslateUi(QMainWindow *PCLViewer)
    {
        PCLViewer->setWindowTitle(QApplication::translate("PCLViewer", "PCLViewer", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("PCLViewer", "Load", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("PCLViewer", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_gardar->setText(QApplication::translate("PCLViewer", "Save Cloud", 0, QApplication::UnicodeUTF8));
        pushButton_load->setText(QApplication::translate("PCLViewer", "Load Cloud", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PCLViewer", "Size X", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PCLViewer", "Size Y", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PCLViewer", "Size Z", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PCLViewer", "K n neighbors:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PCLViewer", "Deviation:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("PCLViewer", "Radius:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PCLViewer", "Param K:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PCLViewer", "Search Radius", 0, QApplication::UnicodeUTF8));
        comboBox_pass->clear();
        comboBox_pass->insertItems(0, QStringList()
         << QApplication::translate("PCLViewer", "X filter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PCLViewer", "Y filter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PCLViewer", "Z filter", 0, QApplication::UnicodeUTF8)
        );
        label_12->setText(QApplication::translate("PCLViewer", "Min:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("PCLViewer", "Max:", 0, QApplication::UnicodeUTF8));
        comboBox_filtros->clear();
        comboBox_filtros->insertItems(0, QStringList()
         << QApplication::translate("PCLViewer", "Voxel Grid", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PCLViewer", "Statistical filter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PCLViewer", "Radius search filter", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PCLViewer", "Resampling", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PCLViewer", "Pass trough", 0, QApplication::UnicodeUTF8)
        );
        pushButton_aceptar_filtro->setText(QApplication::translate("PCLViewer", "Accept", 0, QApplication::UnicodeUTF8));
        pushButton_deshacer_filtro->setText(QApplication::translate("PCLViewer", "Undo", 0, QApplication::UnicodeUTF8));
        pushButton_filter->setText(QApplication::translate("PCLViewer", "Autofilter", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("PCLViewer", "Cloud data", 0, QApplication::UnicodeUTF8));
        pushButton_funcion_1->setText(QApplication::translate("PCLViewer", "Apply", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_filtros), QApplication::translate("PCLViewer", "Filter", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("PCLViewer", "X:", 0, QApplication::UnicodeUTF8));
        pushButton_2d_place->setText(QApplication::translate("PCLViewer", "Place 2d", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("PCLViewer", "Y:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("PCLViewer", "Angle:", 0, QApplication::UnicodeUTF8));
        pushButton_aceptar_fitting->setText(QApplication::translate("PCLViewer", "Accept", 0, QApplication::UnicodeUTF8));
        pushButton_recorta_plano->setText(QApplication::translate("PCLViewer", "Recorta", 0, QApplication::UnicodeUTF8));
        pushButton_distances->setText(QApplication::translate("PCLViewer", "Distance", 0, QApplication::UnicodeUTF8));
        pushButton_reorienta->setText(QApplication::translate("PCLViewer", "Reorient", 0, QApplication::UnicodeUTF8));
        pushButton_funcion_2->setText(QApplication::translate("PCLViewer", "Plane fit", 0, QApplication::UnicodeUTF8));
        pushButton_deshacer_plano->setText(QApplication::translate("PCLViewer", "Undo", 0, QApplication::UnicodeUTF8));
        checkBox_puntos_sup->setText(QApplication::translate("PCLViewer", "Upper", 0, QApplication::UnicodeUTF8));
        pushButton_centra->setText(QApplication::translate("PCLViewer", "Center point", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("PCLViewer", "Distance threshold:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_fit), QApplication::translate("PCLViewer", "Fit", 0, QApplication::UnicodeUTF8));
        pushButton_proj_points->setText(QApplication::translate("PCLViewer", "Project points", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_projections), QApplication::translate("PCLViewer", "Pojection", 0, QApplication::UnicodeUTF8));
        pushButton_load_model->setText(QApplication::translate("PCLViewer", "Load Model", 0, QApplication::UnicodeUTF8));
        pushButton_delete_model->setText(QApplication::translate("PCLViewer", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_fine_alignment->setText(QApplication::translate("PCLViewer", "Fine Alignment", 0, QApplication::UnicodeUTF8));
        pushButton_init_align->setText(QApplication::translate("PCLViewer", "Initial Alignment", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_align), QApplication::translate("PCLViewer", "Align", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("PCLViewer", "Sel point cloud", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("PCLViewer", "Point cloud size", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("PCLViewer", "Mod point cloud", 0, QApplication::UnicodeUTF8));
        pushButton_test->setText(QApplication::translate("PCLViewer", "Function Test", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("PCLViewer", "Cluster:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("PCLViewer", "Test", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("PCLViewer", "Settings", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PCLViewer: public Ui_PCLViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLVIEWER_H
