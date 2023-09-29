#!/usr/bin/env python3

import rospy
import rospkg
import sys
import os
import pathlib as pl
import numpy as np
import ros_numpy
import threading
import pyqtgraph as pg
pg.setConfigOptions(imageAxisOrder='row-major')
# from python_qt_binding import loadUi, QtGui, QtCore, QtWidgets
from python_qt_binding import loadUi
from python_qt_binding import QtGui
from python_qt_binding import QtCore
from python_qt_binding import QtWidgets
from QtCore import QTimer
from multimodal_monitoring.msg import MsgDefect


def callback(context,*args):#, aHandle, aStreamIndex):
    context.set_image()

path = rospkg.RosPack().get_path('multisense_gui')
multimodal_monitoring_path = rospkg.RosPack().get_path('multimodal_monitoring')


class QualityVisualize(QtWidgets.QWidget):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        loadUi(os.path.join(path, 'resources', 'virtual_quality_map.ui'), self)

        # ROS subscribers
        self.quality_subscriber = rospy.Subscriber('/predicted_quality', MsgDefect, self.cb_quality, queue_size=10)


    def cb_quality(self):
        pass

    

if __name__ == '__main__':
    rospy.init_node('quality_visualizer')
    app = QtWidgets.QApplication(sys.argv)
    
    visualizer = QualityVisualize()
    visualizer.show()
    
    app.exec_()



    