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


import pyqtgraph as pg
pg.setConfigOptions(imageAxisOrder='row-major')


from python_qt_binding import loadUi
# from python_qt_binding import QtGui
from python_qt_binding import QtCore
from python_qt_binding import QtWidgets



# ros related packages
import rospy
import rospkg
from sensor_msgs.msg import Image
from infratec_image_processing.msg import MsgROISize
from infratec_image_processing.msg import MsgThreshold
from infratec_image_processing.msg import MsgMeltpoolWidth
from opencv_apps.msg import RotatedRectArrayStamped # the list of ellipse
from opencv_apps.msg import RotatedRectArray 
from opencv_apps.msg import RotatedRect # single
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

        #-----------------------ROS Topic Publisher and Subscriber-----------------------------------------------
        # subscribe the image topic and use callback function for further process
        rospy.Subscriber("/infratec/image_meltpool_bin", Image, self.cb_image, queue_size=1)
        rospy.Subscriber("/infratec/meltpool_size", MsgROISize, self.cb_meltpoolsize, queue_size=1)
        rospy.Subscriber("/general_contours/image", Image, self.cb_contour_image, queue_size=1)
        rospy.Subscriber("/general_contours/ellipses", RotatedRectArrayStamped, self.cb_ellipses, queue_size=2)
        self.pub_meltpool_threshold_temp = rospy.Publisher('/infratec/meltpool_threshold', MsgThreshold, queue_size=1)
        self.pub_meltpool_width = rospy.Publisher('/infratec/melt_pool_wdith', MsgMeltpoolWidth, queue_size=1)

        self.bridge = CvBridge()
        self.msg_meltpool_threshold = MsgThreshold()
        self.msg_melpoolwidth = MsgMeltpoolWidth()
        #-----------------------------------------------------------------------------------------------------------

        #------------------------set up plot widget for melt pool binary image------------------------------------
        self.plotwindow = QtWidgets.QVBoxLayout(self.ImageWidget)
        self.image = pg.ImageView()
        self.plotwindow.addWidget(self.image)
        self.np_img = np.zeros((640,480))
        #------------------------------- plot widget for melt pool contour image----------------------------------
        self.plotwindow_contour = QtWidgets.QVBoxLayout(self.ContourImageWidget)
        self.image_contour = pg.ImageView()
        self.plotwindow_contour.addWidget(self.image_contour)
        self.np_img_contour = np.ones((640,480))
        #----------------------------------------------------------------------------------------------------------

        #------------------------set up plot widget for melt pool size data--------------------------------------
        self.plotwindow = QtWidgets.QVBoxLayout(self.MPSPlotWidget)
        self.mps_plotwidget = pg.PlotWidget()
        self.mpw_plotwidget = pg.PlotWidget()
        self.plotwindow.addWidget(self.mps_plotwidget)
        self.plotwindow.addWidget(self.mpw_plotwidget)
        self.mps_curve_plot = self.mps_plotwidget.plot(
                     pen=pg.mkPen('b', width=2) # colour of the plot
                    )
        self.mpw_curve_plot = self.mpw_plotwidget.plot(
                     pen=pg.mkPen('r', width=2) # colour of the plot
                    )

        self.mps_plotwidget.setTitle("Melt Pool Size Plot",color='008080',size='10pt')
        # self.mps_plotwidget.setLabel("left","Melt Pool Size [mm^2]" ,size='5pt')
        self.mps_plotwidget.setLabel("bottom","Time [sec]",size='5pt')
        # self.mps_plotwidget.setYRange(min=0, # minimum Y value
        #                             max=10000)  # maximum Y value
        self.mps_plotwidget.setBackground('w') ## white
        self.mps_plotwidget.showGrid(x=True, y=True)

        self.mpw_plotwidget.setTitle("Melt Pool Width Plot",color='008080',size='10pt')
        # self.mpw_plotwidget.setLabel("left","[mm^2]" ,size='5pt')
        self.mpw_plotwidget.setLabel("bottom","Time [sec]",size='5pt')
        # self.mps_plotwidget.setYRange(min=0, # minimum Y value
        #                             max=10000)  # maximum Y value
        self.mpw_plotwidget.setBackground('w') ## white
        self.mpw_plotwidget.showGrid(x=True, y=True)
        #------------------------------------------------------------------------------------------------
        self.mps = 0
        self.mpw = 0
        self.stamp_now = rospy.Time.now().to_sec()
        #------------------------set up plot widget for melt pool size data--------------------------------------


        #------------------------set up Qt button and backend communications -------------------------------------------
        self.MeltPoolThresholdAcceptButton.clicked.connect(self.MeltPoolThresholdAcceptButtonClicked)
        self.AcceptLensButton.clicked.connect(self.AcceptLensButtonClicked)
        self.mps_curve_plot.scene().sigMouseMoved.connect(self.mouseover)

        # initialize variables
        self.pixel_size = 0.26*0.26 #mm
        self.i = 0
        self.i_list = []
        self.time_stamp_list = []
        self.mps_list = []
        self.mpw_list = []

        # ----------------------------start the timer for updating the pyqtgraphs----------------------------
        # self.timer = QtCore.QTimer()
        # self.timer.timeout.connect(self.updateImage)
        # self.timer.start(30) # refresh every xxx miliseconds (0.001 seconds)
        # start the timer
        self.mps_timer = QtCore.QTimer()
        self.mps_timer.timeout.connect(self.updateMPSPlot)
        self.mps_timer.start(30) # refresh every xxx miliseconds (0.001 seconds)

        # self.mpw_timer = QtCore.QTimer()
        # self.mpw_timer.timeout.connect(self.updateMPWPlot)
        # self.mpw_timer.start(30) # refresh every xxx miliseconds (0.001 seconds)

        

    def cb_ellipses(self, ellipses_msg):
        stamp = ellipses_msg.header.stamp
        # ellipses_msg.rects is a list of ellipse instance
        # areas = [cv2.contourArea(contour) for contour in contours]
        if ellipses_msg.rects: # only process it if the list is not empty
            areas = [ellipse_msg.size.width*ellipse_msg.size.height for ellipse_msg in ellipses_msg.rects]
            if np.max(areas) > 5:
                largest_ellipse = ellipses_msg.rects[np.argmax(areas)]
                self.mpw = largest_ellipse.size.width
                self.msg_melpoolwidth.melt_pool_width = self.mpw
                self.pub_meltpool_width.publish(self.msg_melpoolwidth)


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
            self.timer_image = threading.Thread(target=self.updateImage,daemon=True)
            self.timer_image.start()
 
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


    def cb_contour_image(self,msg_image):
        try:
            stamp = msg_image.header.stamp
            # convert the ros image to OpenCV image for processing
            self.np_img_contour = ros_numpy.numpify(msg_image)
            self.image_contour.setImage(self.np_img_contour)
            self.image_contour.ui.histogram.hide()
            self.image_contour.ui.roiBtn.hide()
            self.image_contour.ui.roiPlot.hide()
            self.image_contour.ui.normGroup.hide()
            self.image_contour.ui.menuBtn.setVisible(False)
            self.timer_contour = threading.Thread(target=self.updateContourImage,daemon=True)
            # self.timer_contour.timeout.connect(self.updateContourImage)
            self.timer_contour.start()
 
        except CvBridgeError as e:
            rospy.loginfo("CvBridge Exception")


    def updateContourImage(self):
        self.image_contour.setImage(self.np_img_contour)
        self.image_contour.ui.histogram.hide()
        self.image_contour.ui.roiBtn.hide()
        self.image_contour.ui.roiPlot.hide()
        self.image_contour.ui.normGroup.hide()
        self.image_contour.ui.menuBtn.setVisible(False)
        time.sleep(30)



    def cb_meltpoolsize(self, msg_mps):
        # self.stamp_now = (rospy.Time.now()).to_sec() * 0.000000001
        # self.mps = int(msg_mps.pixels) * self.pixel_size 
        self.mps = int(msg_mps.pixels)
        self.lblmps.setText(str(self.mps))
        if self.mps < 100:
            self.lblLaserStatus.setText('Laser OFF')
            self.lblLaserStatus.setStyleSheet("background-color: rgb(200, 0, 0); color: rgb(255, 255, 255);")
        else:
            self.lblLaserStatus.setText('Laser ON')
            self.lblLaserStatus.setStyleSheet("background-color: rgb(0, 200, 0); color: rgb(255, 255, 255);")


    def updateMPSPlot(self):
        self.i +=1 * 0.03
        self.i_list.append(self.i)
        self.mps_list.append(self.mps)
        self.mpw_list.append(self.mpw)
        self.mps_curve_plot.setData(self.i_list, self.mps_list)
        self.mpw_curve_plot.setData(self.i_list, self.mpw_list)
        # self.mpw_plotwidget.setGeometry(self.mps_plotwidget.vb.sceneBoundingRect())

    def updateMPWPlot(self):
        self.mpw_curve_plot.setData(self.i_list, self.mpw_list)
        



    def mouseover(self,pos):
        # 参数pos 是像素坐标，需要 转化为  刻度坐标
        act_pos = self.mps_curve_plot.mapFromScene(pos)
        if type(act_pos) != QtCore.QPointF:
            return
        print(act_pos.x(),act_pos.y())

        # 有了 刻度坐标值，下面就可以根据该值处理一些信息
        # 比如状态栏展示 该处的 日期等

    def MeltPoolThresholdAcceptButtonClicked(self):
        self.meltpool_threshold_temperature = float(self.MeltpoolThreshold.text())
        self.msg_meltpool_threshold.threshold = self.meltpool_threshold_temperature
        self.pub_meltpool_threshold_temp.publish(self.msg_meltpool_threshold)

    def AcceptLensButtonClicked(self):
        index = self.CameraLensCombox.currentIndex()
        if index==0:
            self.pixel_size = 0.26*0.26 #mm^2
        elif index==1:
            self.pixel_size = 0.12*0.12
        elif index==2:
            self.pixel_size = 0.08*0.08 #mm^2
            
            
            



   

if __name__ == '__main__':
    rospy.init_node('ros_image_visualizer')
    app = QtWidgets.QApplication(sys.argv)
    
    visualizer = ros_image_visualizer()
    visualizer.show()
    
    app.exec_()



    