#!/usr/bin/env python3
'''
Some reference from website: https://www.geeksforgeeks.org/pyqtgraph-roi-clicked-signal-of-image-view/
'''
import sys
import os,time
import ctypes,_ctypes
import threading
import pathlib as pl
import cv2
from cv_bridge import CvBridge
import numpy as np
import ros_numpy
# import PySide2

import pyqtgraph as pg
pg.setConfigOptions(imageAxisOrder='row-major')


from python_qt_binding import loadUi
from python_qt_binding import QtGui
from python_qt_binding import QtCore
from python_qt_binding import QtWidgets
# from qt_gui.plugin import Plugin


# ros related packages
import rospy
import rospkg
from sensor_msgs.msg import Image
from infratec_image_processing.msg import MsgROISize
from cv_bridge import CvBridge, CvBridgeError


# t=time.perf_counter()
# tLive=t
# lock=threading.Lock()
# visible=False
# dosaveirb=False
# ev_has_fname = threading.Event()

def callback(context,*args):#, aHandle, aStreamIndex):
    context.set_image()

path = rospkg.RosPack().get_path('infratec_ros_driver')


class ros_image_visualizer(QtWidgets.QWidget):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        loadUi(os.path.join(path, 'resources', 'image_visualizer.ui'), self)

        #------------------------set up plot widget for melt pool binary image------------------------------------
        self.plotwindow = QtGui.QVBoxLayout(self.ImageWidget)
        self.image = pg.ImageView()
        self.plotwindow.addWidget(self.image)
        self.np_img = np.zeros((640,480))
        #------------------------set up plot widget for melt pool binary image------------------------------------

        #------------------------set up plot widget for melt pool size data--------------------------------------
        self.mps_plotwindow = QtGui.QVBoxLayout(self.MPSPlotWidget)
        self.mps_plotwidget = pg.PlotWidget()
        self.mps_plotwidget.setTitle("Melt Pool Size Plot",color='008080',size='12pt')
        self.mps_plotwidget.setLabel("left","Melt Pool Size [mm^2]")
        self.mps_plotwidget.setLabel("bottom","Time")
        # self.mps_plotwidget.setYRange(min=0, # minimum Y value
        #                             max=10000)  # maximum Y value
        self.mps_plotwidget.setBackground('w') ## white
        self.mps_plotwidget.showGrid(x=True, y=True)
        self.mps_curve_plot = self.mps_plotwidget.plot(
                     pen=pg.mkPen('b', width=2) # colour of the plot
                    )
        self.mps_plotwindow.addWidget(self.mps_plotwidget)
        self.mps = 0
        self.stamp_now = rospy.Time.now().to_sec()
         #------------------------set up plot widget for melt pool size data--------------------------------------
        self.pixel_size = 0.26*0.26 #mm
        self.i = 0
        self.i_list = []
        self.time_stamp_list = []
        self.mps_list = []

        self.bridge = CvBridge()

        # subscribe the image topic and use callback function for further process
        rospy.Subscriber("/infratec/image_meltpool_bin", Image, self.cb_image, queue_size=1)
        rospy.Subscriber("/infratec/meltpool_size", MsgROISize, self.cb_meltpoolsize, queue_size=2)

        # start the timer
        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self.updateImage)
        self.timer.start(10) # refresh every xxx miliseconds (0.001 seconds)
        # start the timer
        self.mps_timer = QtCore.QTimer()
        self.mps_timer.timeout.connect(self.updateMPSPlot)
        self.mps_timer.start(10) # refresh every xxx miliseconds (0.001 seconds)

        self.mps_curve_plot.scene().sigMouseMoved.connect(self.mouseover)
        

        

    def cb_image(self, msg_image):
        try:
            stamp = msg_image.header.stamp
            # convert the ros image to OpenCV image for processing
            # frame = self.bridge.imgmsg_to_cv2(msg_image) 
            # if msg_image.encoding == 'mono8' or 'mono16':
            self.np_img = ros_numpy.numpify(msg_image)
            self.image.setImage(self.np_img)
            self.image.ui.histogram.hide()
            self.image.ui.roiBtn.hide()
            self.image.ui.roiPlot.hide()
            self.image.ui.normGroup.hide()
            self.image.ui.menuBtn.setVisible(False)
 
        except CvBridgeError as e:
            rospy.loginfo("CvBridge Exception")

    def updateImage(self):
        self.image.setImage(self.np_img)
        self.image.ui.histogram.hide()
        self.image.ui.roiBtn.hide()
        self.image.ui.roiPlot.hide()
        self.image.ui.normGroup.hide()
        self.image.ui.menuBtn.setVisible(False)
        # self.image.ui.normBtn.hide() 

    def cb_meltpoolsize(self, msg_mps):
        self.stamp_now = (rospy.Time.now()).to_sec() * 0.000000001
        self.mps = int(msg_mps.pixels) * self.pixel_size
        

    def updateMPSPlot(self):
        self.i +=1 * 0.01
        self.i_list.append(self.i)
        self.mps_list.append(self.mps)
        self.mps_curve_plot.setData(self.i_list, self.mps_list)



    def mouseover(self,pos):
        # 参数pos 是像素坐标，需要 转化为  刻度坐标
        act_pos = self.mps_curve_plot.mapFromScene(pos)
        if type(act_pos) != QtCore.QPointF:
            return
        print(act_pos.x(),act_pos.y())

        # 有了 刻度坐标值，下面就可以根据该值处理一些信息
        # 比如状态栏展示 该处的 日期等

    


   

if __name__ == '__main__':
    rospy.init_node('ros_image_visualizer')
    app = QtWidgets.QApplication(sys.argv)
    
    visualizer = ros_image_visualizer()
    visualizer.show()
    
    app.exec_()



    