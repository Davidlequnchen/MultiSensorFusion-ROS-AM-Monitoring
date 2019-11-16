#-------------------------------------------------
#
# 
#
#-------------------------------------------------

TARGET += point_cloud_processing
TEMPLATE = app

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets




INCLUDEPATH += -I/usr/local/include/opencv
INCLUDEPATH += -I/usr/local/include
INCLUDEPATH += ../include
LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann
LIBS += -lopencv_nonfree


SOURCES += qt_pcl_processing.cpp pclviewer.cpp LmdFuncs.cpp

HEADERS  += ../include/pclviewer.h ../include/LmdFuncs.h ../include/ui_pclviewer.h

FORMS    += ../resources/pclviewer.ui

