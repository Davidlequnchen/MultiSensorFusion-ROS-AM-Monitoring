#!/usr/bin/env python3

import rospy
import rospkg
from sensor_msgs.msg import Image
# from opencv_apps.msg import RotatedRectArrayStamped # the list of ellipse
from cv_bridge import CvBridge, CvBridgeError
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


from opencv_apps.msg import MaxContourArea, ContourArea
from collections import deque
from acoustic_monitoring_msgs.msg import (
    AudioDataStamped,
    MsgAcousticFeature,
)

def callback(context,*args):#, aHandle, aStreamIndex):
    context.set_image()

path = rospkg.RosPack().get_path('multisense_gui')
multimodal_monitoring_path = rospkg.RosPack().get_path('multimodal_monitoring')


class AudioVisualFeatureVisualize(QtWidgets.QWidget):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        loadUi(os.path.join(path, 'resources', 'key_feature_visualizer.ui'), self)

        # Initialize CV bridge for image conversion
        self.bridge = CvBridge()

        # Initialize a QTimer for updating the image
        self.image_timer = QTimer()
        self.image_timer.timeout.connect(self.updateImage)
        self.image_timer.start(33)  # Update approximately every 33ms (about 30 FPS)

        self.audio_feature_timer = QTimer()
        self.audio_feature_timer.timeout.connect(self.updateAudioFeature)
        self.audio_feature_timer.start(10) # refresh every 10 ms 
        self.visual_feature_timer = QTimer()
        self.visual_feature_timer.timeout.connect(self.updateVisualFeature)
        self.visual_feature_timer.start(10) # refresh every 10 ms 

        # -----------------Initialize plot for audio signal---------------------------------
        self.audio_feature_plot_window = QtWidgets.QVBoxLayout(self.AudioFeaturePlotWidget)
        self.audio_feature_plotwidget = pg.PlotWidget()
        self.audio_feature_plot_window.addWidget(self.audio_feature_plotwidget)
        self.audio_feature_curve = self.audio_feature_plotwidget.plot(pen=pg.mkPen('b', width=1))
        self.audio_feature_plotwidget.setBackground('w')
        # self.audio_feature_plotwidget.setXRange(0, 1)
        # self.audio_feature_plotwidget.setYRange(-1, 1)
        self.audio_feature_plotwidget.setTitle("Audio Feature Visualization", color='#008080', size='10pt')
        self.audio_feature_plotwidget.setLabel("bottom","Time [sec]",size='5pt')
        self.audio_feature_plotwidget.showGrid(x=True, y=True)

        legend_audio = pg.LegendItem((60, 30), offset=(0, 20)) 
        legend_audio.setParentItem(self.audio_feature_plotwidget.graphicsItem())
        legend_audio.addItem(self.audio_feature_curve, 'RMS Energy')
        # legend_audio.setPen(pg.mkPen(color=(0, 0, 0)))  # Set border color to black
        legend_audio.setBrush(pg.mkBrush((255, 255, 255, 50)))  # Set background color to white and semi-transparent (50% opacity)

        # ----------------- Initialize plot for visual feature-----------------
        self.visual_feature_plot_window = QtWidgets.QVBoxLayout(self.VisualFeaturePlotWidget)
        self.ellipse_plotwidget = pg.PlotWidget()
        self.visual_feature_plot_window.addWidget(self.ellipse_plotwidget)
        # Create curves for both ellipse width and height
        self.ellipse_width_curve = self.ellipse_plotwidget.plot(pen=pg.mkPen('b', width=1.5), name="Ellipse Width")
        self.ellipse_height_curve = self.ellipse_plotwidget.plot(pen=pg.mkPen('r', width=1.5), name="Ellipse Height")
        # Customize the plot
        self.ellipse_plotwidget.setBackground('w')
        self.ellipse_plotwidget.setTitle("Visual Feature Visualization", color='#008080', size='10pt')
        self.ellipse_plotwidget.setLabel("bottom","Time [sec]",size='4pt')
        self.ellipse_plotwidget.showGrid(x=True, y=True)
 
        # Add a legend to the upper right corner
        legend = pg.LegendItem((50, 20), offset=(0, 30)) 
        legend.setParentItem(self.ellipse_plotwidget.graphicsItem())
        legend.addItem(self.ellipse_width_curve, 'Ellipse Width')
        legend.addItem(self.ellipse_height_curve, 'Ellipse Height')
        # legend.setPen(pg.mkPen(color=(0, 0, 0)))  # Set border color to black
        legend.setBrush(pg.mkBrush((255, 255, 255, 50)))  # Set background color to white and semi-transparent (50% opacity)
       

        
        # -----------------  Initialize plot widget for melt pool image----------------- 
        self.plotwindow = QtWidgets.QVBoxLayout(self.ImageFeatureWidget)
        self.image = pg.ImageView()
        self.plotwindow.addWidget(self.image)
        self.np_img = np.zeros((640,480))

        font = QtGui.QFont()
        font.setPointSize(12) 
        self.label_9.setFont(font)

        # ROS subscribers
        self.image_subscriber = rospy.Subscriber('/general_contours/image', Image, self.image_callback, queue_size=10)
        self.max_contour_area_subscriber = rospy.Subscriber('/general_contours/max_contour_area', MaxContourArea, self.cb_max_contour_area, queue_size=10)
        self.convex_hull_subscriber = rospy.Subscriber('/convex_hull/hull_area', ContourArea, self.cb_convex_hull, queue_size=10)
        self.audio_feature_subscriber = rospy.Subscriber('/acoustic_feature', MsgAcousticFeature, self.audio_feauture_callback, queue_size=10)


        self.visual_time = []
        self.audio_time = []
        self.ellipse_width_data = []
        self.ellipse_height_data = []
        self.convex_hull_data = []
        self.spectral_centroid_data = []


        
        

    def image_callback(self, msg_image):
        try:
            self.np_img = self.bridge.imgmsg_to_cv2(msg_image, "rgb8")
            self.image.ui.histogram.hide()
            self.image.ui.roiBtn.hide()
            self.image.ui.roiPlot.hide()
            self.image.ui.normGroup.hide()
            self.image.ui.menuBtn.setVisible(False)
        except CvBridgeError as e:
            print(e)
            return

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

    def cb_max_contour_area(self, msg_max_contour):
        # Get current time stamp from ROS header
        current_time = msg_max_contour.header.stamp.to_sec()
        # If it's the first data point, initialize visual_start_time
        if not hasattr(self, 'visual_start_time'):
            self.visual_start_time = current_time
        # Compute elapsed time relative to the first timestamp
        elapsed_time = current_time - self.visual_start_time
        # Append the new data
        self.visual_time.append(elapsed_time)
        self.max_contour_area = msg_max_contour.meltpool_contour_area
        self.ellipse_width_data.append(msg_max_contour.ellipse_width)
        self.ellipse_height_data.append(msg_max_contour.ellipse_height)
        # self.rectangle_width = msg_max_contour.rectangle_width
        # self.rectangle_height = msg_max_contour.rectangle_height

    def cb_convex_hull(self, msg_convex_hull):
        self.convex_hull_data.append(msg_convex_hull.area[0])

    def audio_feauture_callback(self, msg_audio_feature):
        current_time = msg_audio_feature.header.stamp.to_sec()
        # If it's the first data point, initialize start_time
        if not hasattr(self, 'audio_start_time'):
            self.audio_start_time = current_time
        elapsed_time = current_time - self.audio_start_time
        self.audio_time.append(elapsed_time)
        self.spectral_centroid_data.append(msg_audio_feature.rms_energy)
  

    def updateAudioFeature(self):
        self.audio_feature_curve.setData(self.audio_time, self.spectral_centroid_data)
        self.audio_feature_plotwidget.setXRange(min(self.audio_time), max(self.audio_time))
        self.audio_feature_plotwidget.setYRange(min(self.spectral_centroid_data), max(self.spectral_centroid_data))


    def updateVisualFeature(self):
        self.ellipse_width_curve.setData(self.visual_time, self.ellipse_width_data)
        self.ellipse_height_curve.setData(self.visual_time, self.ellipse_height_data)
        # Update the axes if you have data
        if self.visual_time:
            self.ellipse_plotwidget.setXRange(min(self.visual_time), max(self.visual_time))
            min_y = min(min(self.ellipse_width_data), min(self.ellipse_height_data))
            max_y = max(max(self.ellipse_width_data), max(self.ellipse_height_data))
            self.ellipse_plotwidget.setYRange(min_y, max_y)
            self.ellipse_plotwidget.addLegend()


    


if __name__ == '__main__':
    rospy.init_node('audio_image_feature_visualizer')
    app = QtWidgets.QApplication(sys.argv)
    
    visualizer = AudioVisualFeatureVisualize()
    visualizer.show()
    
    app.exec_()



    