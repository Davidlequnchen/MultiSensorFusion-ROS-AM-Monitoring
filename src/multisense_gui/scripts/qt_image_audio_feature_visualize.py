#!/usr/bin/env python3

import rospy
import rospkg
from sensor_msgs.msg import Image
# from opencv_apps.msg import RotatedRectArrayStamped # the list of ellipse
from cv_bridge import CvBridge, CvBridgeError
import sys
import os
import joblib
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
from coaxial_melt_pool_monitoring.msg import MsgCoaxialMeltPoolFeatures
from collections import deque
from acoustic_monitoring_msgs.msg import (
    AudioDataStamped,
    MsgAcousticFeature,
)

def callback(context,*args):#, aHandle, aStreamIndex):
    context.set_image()

# Normalize function
def normalize(data):
    min_val = min(data)
    max_val = max(data)
    return [(x - min_val) / (max_val - min_val) for x in data]

path = rospkg.RosPack().get_path('multisense_gui')
multimodal_monitoring_path = rospkg.RosPack().get_path('multimodal_monitoring')
dirname = rospkg.RosPack().get_path('multimodal_monitoring')

class AudioVisualFeatureVisualize(QtWidgets.QWidget):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        loadUi(os.path.join(path, 'resources', 'key_feature_visualizer.ui'), self)

        self.scaler = joblib.load(os.path.join(dirname, 'config', 'StandardScaler_All_Features.pkl'))

        # Initialize CV bridge for image conversion
        self.bridge = CvBridge()

        # Initialize a QTimer for updating the image
        self.image_timer = QTimer()
        self.image_timer.timeout.connect(self.updateMomentImage)
        self.image_timer.timeout.connect(self.updateConvexHullImage)
        self.image_timer.timeout.connect(self.updateContourImage)
        self.image_timer.timeout.connect(self.updateBinarizeImage)
        self.image_timer.start(1)  # Update approximately every 33ms (about 30 FPS)

        self.audio_feature_timer = QTimer()
        self.audio_feature_timer.timeout.connect(self.updateAudioFeature)
        self.audio_feature_timer.start(1) # refresh every 1 ms 
        self.visual_feature_timer = QTimer()
        self.visual_feature_timer.timeout.connect(self.updateVisualFeature)
        self.visual_feature_timer.start(1) # refresh every 1 ms 

        # ---------------- Pre-calculate scaler factors ----------------
        mfcc_1_mean_index = 60
        mfcc_3_mean_index = 64
        self.mfcc_1_mean_mean = self.scaler.mean_[mfcc_1_mean_index]
        self.mfcc_1_mean_scale = self.scaler.scale_[mfcc_1_mean_index]
        self.mfcc_3_mean_mean = self.scaler.mean_[mfcc_3_mean_index]
        self.mfcc_3_mean_scale = self.scaler.scale_[mfcc_3_mean_index]

        # Pre-calculate scaler factors for visual features
        self.visual_feature_indices = {
            'max_contour_area': 84, 
            'ellipse_width': 89, 
            'ellipse_height': 90, 
            'max_hull_area': 91, 
            'nu02': 111
        }
        self.visual_feature_scaler_factors = {
            key: (self.scaler.mean_[index], self.scaler.scale_[index]) for key, index in self.visual_feature_indices.items()
        }
        self.visual_features_data = {key: [] for key in self.visual_feature_indices.keys()}


        # -----------------Initialize plot for audio signal---------------------------------
        self.audio_feature_plot_window = QtWidgets.QVBoxLayout(self.AudioFeaturePlotWidget)
        self.audio_feature_plotwidget = pg.PlotWidget()
        self.audio_feature_plot_window.addWidget(self.audio_feature_plotwidget)
        self.audio_feature_mfcc_1_mean_curve = self.audio_feature_plotwidget.plot(pen=pg.mkPen('b', width=1.5), name="MFCC1 Mean")
        self.audio_feature_mfcc_3_mean_curve = self.audio_feature_plotwidget.plot(pen=pg.mkPen('r', width=1.5), name="MFCC3 Mean")
        self.audio_feature_plotwidget.setBackground('w')
        self.audio_feature_plotwidget.setTitle("Audio Feature Visualization", color='#008080', size='10pt')
        self.audio_feature_plotwidget.setLabel("bottom","Time [sec]",size='5pt')
        self.audio_feature_plotwidget.showGrid(x=True, y=True)

        legend_audio = pg.LegendItem((60, 30), offset=(0, 20)) 
        legend_audio.setParentItem(self.audio_feature_plotwidget.graphicsItem())
        legend_audio.addItem(self.audio_feature_mfcc_1_mean_curve, 'MFCC1 Mean')
        legend_audio.addItem(self.audio_feature_mfcc_3_mean_curve, 'MFCC3 Mean')
        # legend_audio.setPen(pg.mkPen(color=(0, 0, 0)))  # Set border color to black
        legend_audio.setBrush(pg.mkBrush((255, 255, 255, 50)))  # Set background color to white and semi-transparent (50% opacity)

        # ----------------- Initialize plot for visual feature-----------------
        self.visual_feature_plot_window = QtWidgets.QVBoxLayout(self.VisualFeaturePlotWidget)
        self.ellipse_plotwidget = pg.PlotWidget()
        self.visual_feature_plot_window.addWidget(self.ellipse_plotwidget)
        # Create curves for both ellipse width and height
        self.ellipse_width_curve = self.ellipse_plotwidget.plot(pen=pg.mkPen('b', width=1.5), name="Ellipse Width")
        self.ellipse_height_curve = self.ellipse_plotwidget.plot(pen=pg.mkPen('r', width=1.5), name="Ellipse Height")
        # self.max_contour_curve = self.ellipse_plotwidget.plot(pen=pg.mkPen('g', width=1.5), name="Max Contour Area")
        self.nu02_curve = self.ellipse_plotwidget.plot(pen=pg.mkPen('g', width=1.5), name="Nu 02")
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
        # legend.addItem(self.max_contour_curve, 'Max Contour Area')
        legend.addItem(self.nu02_curve, 'Nu 02')
        # legend.setPen(pg.mkPen(color=(0, 0, 0)))  # Set border color to black
        legend.setBrush(pg.mkBrush((255, 255, 255, 50)))  # Set background color to white and semi-transparent (50% opacity)
       

        
        # -----------------  Initialize plot widget for melt pool image----------------- 
        self.plotwindow_1 = QtWidgets.QVBoxLayout(self.ImageFeatureWidget)
        self.convex_hull_image = pg.ImageView()
        self.plotwindow_1.addWidget(self.convex_hull_image)
        self.np_img_convex_hull = np.zeros((640,480))

        self.plotwindow_2 = QtWidgets.QVBoxLayout(self.ImageFeatureWidget_2)
        self.binarize_image = pg.ImageView()
        self.plotwindow_2.addWidget(self.binarize_image)
        self.np_img_binarize = np.zeros((640,480))

        self.plotwindow_3 = QtWidgets.QVBoxLayout(self.ImageFeatureWidget_3)
        self.contour_image = pg.ImageView()
        self.plotwindow_3.addWidget(self.contour_image)
        self.np_img_contour = np.zeros((640,480))

        self.plotwindow_5 = QtWidgets.QVBoxLayout(self.ImageFeatureWidget_5)
        self.moment_image = pg.ImageView()
        self.plotwindow_5.addWidget(self.moment_image)
        self.np_img_moment = np.zeros((640,480))

    

        font = QtGui.QFont()
        font.setPointSize(12) 
        self.label_9.setFont(font)

        # ROS subscribers
        self.image_subscriber = rospy.Subscriber('/image_moment_extract', Image, self.moment_image_callback, queue_size=10) # /image_moment_extract, image_general_contour
        self.image_subscriber = rospy.Subscriber('/image_convex_hull', Image, self.convex_hull_image_callback, queue_size=10) # /image_moment_extract, image_general_contour
        self.image_subscriber = rospy.Subscriber('/image_general_contour', Image, self.contour_image_callback, queue_size=10) # /image_moment_extract, image_general_contour
        self.image_subscriber = rospy.Subscriber('/image_binarize', Image, self.binarize_image_callback, queue_size=10) # /image_moment_extract, image_general_contour
        self.coaxial_visual_feature_subscriber = rospy.Subscriber('/coaxial_melt_pool_features', MsgCoaxialMeltPoolFeatures, self.cb_coaxial_visual_features, queue_size=10)
        self.audio_feature_subscriber = rospy.Subscriber('/acoustic_feature', MsgAcousticFeature, self.audio_feauture_callback, queue_size=10)


        self.visual_time = []
        self.audio_time = []
        self.max_contour_area_data = []
        self.ellipse_width_data = []
        self.ellipse_height_data = []
        self.convex_hull_data = []
        self.nu02_data = []
        self.mfcc_3_mean_data = []
        self.mfcc_1_mean_data = []

        
    def moment_image_callback(self, msg_image):
        try:
            self.np_img_moment = self.bridge.imgmsg_to_cv2(msg_image, "rgb8")
            self.moment_image.ui.histogram.hide()
            self.moment_image.ui.roiBtn.hide()
            self.moment_image.ui.roiPlot.hide()
            self.moment_image.ui.normGroup.hide()
            self.moment_image.ui.menuBtn.setVisible(False)
        except CvBridgeError as e:
            print(e)
            return

    def contour_image_callback(self, msg_image):
        try:
            self.np_img_convex_hull = self.bridge.imgmsg_to_cv2(msg_image, "rgb8")
            self.convex_hull_image.ui.histogram.hide()
            self.convex_hull_image.ui.roiBtn.hide()
            self.convex_hull_image.ui.roiPlot.hide()
            self.convex_hull_image.ui.normGroup.hide()
            self.convex_hull_image.ui.menuBtn.setVisible(False)
        except CvBridgeError as e:
            print(e)
            return

    def convex_hull_image_callback(self, msg_image):
        try:
            self.np_img_contour = self.bridge.imgmsg_to_cv2(msg_image, "rgb8")
            self.contour_image.ui.histogram.hide()
            self.contour_image.ui.roiBtn.hide()
            self.contour_image.ui.roiPlot.hide()
            self.contour_image.ui.normGroup.hide()
            self.contour_image.ui.menuBtn.setVisible(False)
        except CvBridgeError as e:
            print(e)
            return

    def binarize_image_callback(self, msg_image):
        try:
            self.np_img_binarize = self.bridge.imgmsg_to_cv2(msg_image, "rgb8")
            self.binarize_image.ui.histogram.hide()
            self.binarize_image.ui.roiBtn.hide()
            self.binarize_image.ui.roiPlot.hide()
            self.binarize_image.ui.normGroup.hide()
            self.binarize_image.ui.menuBtn.setVisible(False)
        except CvBridgeError as e:
            print(e)
            return

    # def cb_image(self, msg_image):
    #     try:
    #         stamp = msg_image.header.stamp
    #         # convert the ros image to OpenCV image for processing
    #         # frame = self.bridge.imgmsg_to_cv2(msg_image) 
    #         # if msg_image.encoding == 'mono8' or 'mono16':
    #         self.np_img = ros_numpy.numpify(msg_image)
    #         self.image.setImage(self.np_img)
    #         self.image.ui.histogram.hide()
    #         self.image.ui.roiBtn.hide()
    #         self.image.ui.roiPlot.hide()
    #         self.image.ui.normGroup.hide()
    #         self.image.ui.menuBtn.setVisible(False)
    #         self.timer_image = threading.Thread(target=self.updateImage,daemon=True)
    #         self.timer_image.start()
 
    #     except CvBridgeError as e:
    #         rospy.loginfo("CvBridge Exception")


    def updateMomentImage(self):
        self.moment_image.setImage(self.np_img_moment)
        self.moment_image.ui.histogram.hide()
        self.moment_image.ui.roiBtn.hide()
        self.moment_image.ui.roiPlot.hide()
        self.moment_image.ui.normGroup.hide()
        self.moment_image.ui.menuBtn.setVisible(False)

    def updateConvexHullImage(self):
        self.convex_hull_image.setImage(self.np_img_convex_hull)
        self.convex_hull_image.ui.histogram.hide()
        self.convex_hull_image.ui.roiBtn.hide()
        self.convex_hull_image.ui.roiPlot.hide()
        self.convex_hull_image.ui.normGroup.hide()
        self.convex_hull_image.ui.menuBtn.setVisible(False)

    def updateContourImage(self):
        self.contour_image.setImage(self.np_img_contour)
        self.contour_image.ui.histogram.hide()
        self.contour_image.ui.roiBtn.hide()
        self.contour_image.ui.roiPlot.hide()
        self.contour_image.ui.normGroup.hide()
        self.contour_image.ui.menuBtn.setVisible(False)

    def updateBinarizeImage(self):
        self.binarize_image.setImage(self.np_img_binarize)
        self.binarize_image.ui.histogram.hide()
        self.binarize_image.ui.roiBtn.hide()
        self.binarize_image.ui.roiPlot.hide()
        self.binarize_image.ui.normGroup.hide()
        self.binarize_image.ui.menuBtn.setVisible(False)


    def cb_coaxial_visual_features(self, msg_coaxial_features):
        current_time = msg_coaxial_features.header.stamp.to_sec()

        # Standardize and append data for each feature
        for feature, (mean, scale) in self.visual_feature_scaler_factors.items():
            feature_value = getattr(msg_coaxial_features, feature)
            standardized_value = (feature_value - mean) / scale
            self.visual_features_data[feature].append(standardized_value)

        # If it's the first data point, initialize visual_start_time
        if not hasattr(self, 'visual_start_time'):
            self.visual_start_time = current_time
        # Compute elapsed time relative to the first timestamp
        elapsed_time = current_time - self.visual_start_time
        # Append the new data
        self.visual_time.append(elapsed_time)
        self.max_contour_area_data.append(self.visual_features_data["max_contour_area"])
        self.ellipse_width_data.append(self.visual_features_data["ellipse_width"])
        self.ellipse_height_data.append(self.visual_features_data["ellipse_height"])
        self.convex_hull_data.append(self.visual_features_data["max_hull_area"])
        self.nu02_data.append(self.visual_features_data["nu02"])


    def audio_feauture_callback(self, msg_audio_feature):
        current_time = msg_audio_feature.header.stamp.to_sec()

        standardized_mfcc_1_mean = (msg_audio_feature.mfcc_1_mean - self.mfcc_1_mean_mean) / self.mfcc_1_mean_scale
        standardized_mfcc_3_mean = (msg_audio_feature.mfcc_3_mean - self.mfcc_3_mean_mean) / self.mfcc_3_mean_scale

        # If it's the first data point, initialize start_time
        if not hasattr(self, 'audio_start_time'):
            self.audio_start_time = current_time
        elapsed_time = current_time - self.audio_start_time
        self.audio_time.append(elapsed_time)
        self.mfcc_1_mean_data.append(standardized_mfcc_1_mean) # msg_audio_feature.mfcc_1_mean, standardized_mfcc_1_mean
        self.mfcc_3_mean_data.append(standardized_mfcc_3_mean)
  

    # def updateAudioFeature(self):
    #     # Ensure that x and y data have the same length
    #     min_len = min(len(self.audio_time), len(self.mfcc_1_mean_data), len(self.mfcc_3_mean_data))
    #     truncated_time = self.audio_time[:min_len]
    #     truncated_mfcc_1_mean_data = self.mfcc_1_mean_data[:min_len]
    #     truncated_mfcc_3_mean_data = self.mfcc_3_mean_data[:min_len]
    #     # Update the plot curves
    #     self.audio_feature_mfcc_1_mean_curve.setData(truncated_time, truncated_mfcc_1_mean_data)
    #     self.audio_feature_mfcc_3_mean_curve.setData(truncated_time, truncated_mfcc_3_mean_data)
    #     # Update the axes if you have data
    #     if self.audio_time:
    #         self.audio_feature_plotwidget.setXRange(min(self.audio_time), max(self.audio_time))
    #         min_y = min(min(self.mfcc_1_mean_data), min(self.mfcc_3_mean_data))
    #         max_y = max(max(self.mfcc_1_mean_data), max(self.mfcc_3_mean_data))
    #         self.audio_feature_plotwidget.setYRange(min_y, max_y)
    #         self.audio_feature_plotwidget.addLegend()

    def updateAudioFeature(self):
        # Ensure that x and y data have the same length
        min_len = min(len(self.audio_time), len(self.mfcc_1_mean_data), len(self.mfcc_3_mean_data))
        truncated_time = self.audio_time[:min_len]

        # Normalize and truncate data
        truncated_mfcc_1_mean_data = normalize(self.mfcc_1_mean_data)[:min_len]
        truncated_mfcc_3_mean_data = normalize(self.mfcc_3_mean_data)[:min_len]

        # Update the plot curves
        self.audio_feature_mfcc_1_mean_curve.setData(truncated_time, truncated_mfcc_1_mean_data)
        self.audio_feature_mfcc_3_mean_curve.setData(truncated_time, truncated_mfcc_3_mean_data)

        # Update the axes if you have data
        if self.audio_time:
            self.audio_feature_plotwidget.setXRange(min(self.audio_time), max(self.audio_time))
            self.audio_feature_plotwidget.setYRange(0, 1)  # Set y-axis range from 0 to 1 for normalization
            self.audio_feature_plotwidget.addLegend()



    # def updateVisualFeature(self):
    #     # Ensure that x and y data have the same length
    #     min_len = min(len(self.visual_time), len(self.ellipse_width_data), len(self.ellipse_height_data),  len(self.nu02_data))
    #     truncated_time = self.visual_time[:min_len]
    #     truncated_width_data = self.visual_features_data["ellipse_width"][:min_len] #self.ellipse_width_data[:min_len]
    #     truncated_height_data =  self.visual_features_data["ellipse_height"][:min_len] # self.ellipse_height_data[:min_len]
    #     # truncated_max_contour_data = self.max_contour_area_data[:min_len]
    #     truncated_nu02_data = self.visual_features_data["nu02"][:min_len]  # self.nu02_data[:min_len]

    #     # Update the plot curves
    #     self.ellipse_width_curve.setData(truncated_time, truncated_width_data)
    #     self.ellipse_height_curve.setData(truncated_time, truncated_height_data)
    #     # self.max_contour_curve.setData(truncated_time, truncated_max_contour_data)
    #     self.nu02_curve.setData(truncated_time, truncated_nu02_data)
    
    #     # Update the axes if you have data
    #     if self.visual_time:
    #         self.ellipse_plotwidget.setXRange(min(self.visual_time), max(self.visual_time))
    #         min_y = min(min(self.visual_features_data["ellipse_width"]), min(self.visual_features_data["ellipse_height"]), min(self.visual_features_data["nu02"]))
    #         max_y = max(max(self.visual_features_data["ellipse_width"]), max(self.visual_features_data["ellipse_height"]), max(self.visual_features_data["nu02"]))
    #         self.ellipse_plotwidget.setYRange(min_y, max_y)
    #         self.ellipse_plotwidget.addLegend()

    def updateVisualFeature(self):
        # Ensure that x and y data have the same length
        min_len = min(len(self.visual_time), len(self.visual_features_data["ellipse_width"]), 
                    len(self.visual_features_data["ellipse_height"]), len(self.visual_features_data["nu02"]))
        truncated_time = self.visual_time[:min_len]

        # Normalize and truncate data
        truncated_width_data = normalize(self.visual_features_data["ellipse_width"])[:min_len]
        truncated_height_data = normalize(self.visual_features_data["ellipse_height"])[:min_len]
        truncated_nu02_data = normalize(self.visual_features_data["nu02"])[:min_len]

        # Update the plot curves
        self.ellipse_width_curve.setData(truncated_time, truncated_width_data)
        self.ellipse_height_curve.setData(truncated_time, truncated_height_data)
        self.nu02_curve.setData(truncated_time, truncated_nu02_data)

        # Update the axes if you have data
        if self.visual_time:
            self.ellipse_plotwidget.setXRange(min(self.visual_time), max(self.visual_time))
            self.ellipse_plotwidget.setYRange(0, 1)  # Set y-axis range from 0 to 1 for normalization
            self.ellipse_plotwidget.addLegend()



    


if __name__ == '__main__':
    rospy.init_node('audio_image_feature_visualizer')
    app = QtWidgets.QApplication(sys.argv)
    
    visualizer = AudioVisualFeatureVisualize()
    visualizer.show()
    
    app.exec_()



    