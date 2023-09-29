#!/usr/bin/env python3

import rospy
import rospkg
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import sys
import os
import pathlib as pl
from cv_bridge import CvBridge
import numpy as np
import ros_numpy
import threading
import pyqtgraph as pg
pg.setConfigOptions(imageAxisOrder='row-major')

from python_qt_binding import loadUi
from python_qt_binding import QtGui
from python_qt_binding import QtCore
from python_qt_binding import QtWidgets
from QtCore import QTimer

from collections import deque
from acoustic_monitoring_msgs.msg import (
    AudioDataStamped,

)


def callback(context,*args):#, aHandle, aStreamIndex):
    context.set_image()

path = rospkg.RosPack().get_path('multisense_gui')
multimodal_monitoring_path = rospkg.RosPack().get_path('multimodal_monitoring')

class AudioImageVisualizer(QtWidgets.QWidget):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        loadUi(os.path.join(path, 'resources', 'audio_image_visualizer.ui'), self)
        image_topic = rospy.get_param('~image_topic_raw', '/usb_cam/image_raw')
        audio_stamped_topic = rospy.get_param('~audio_stamped_topic', '/audioStamped')

        # Initialize CV bridge for image conversion
        self.bridge = CvBridge()

        # Initialize audio buffer and size
        self.buffer_size = 44100  # 1 second of audio at 44100 Hz
        self.audio_buffer = deque(maxlen=self.buffer_size)
        self.audio_data_buffered = np.zeros(self.buffer_size, dtype=np.float32)
        self.audio_time = np.linspace(0, 1, self.buffer_size)

        # Initialize a QTimer for updating the image
        self.image_timer = QTimer()
        self.image_timer.timeout.connect(self.updateImage)
        self.image_timer.start(33)  # Update approximately every 33ms (about 30 FPS)

        self.audio_timer = QTimer()
        self.audio_timer.timeout.connect(self.updateAudio)
        self.audio_timer.start(33) # refresh every 10 ms 

        # Initialize plot for audio signal
        self.audio_plot_window = QtWidgets.QVBoxLayout(self.AudioPlotWidget)
        self.audio_plotwidget = pg.PlotWidget()
        self.audio_plot_window.addWidget(self.audio_plotwidget)
        self.audio_curve = self.audio_plotwidget.plot(pen=pg.mkPen('b', width=1))
        self.audio_plotwidget.setBackground('w')
        # self.audio_plotwidget.setXRange(0, 1)
        self.audio_plotwidget.setYRange(-1, 1)
        self.audio_plotwidget.setTitle("Real-time Audio", color='#008080', size='12pt')
        self.audio_plotwidget.setLabel("bottom","Time [sec]",size='5pt')
        self.audio_plotwidget.showGrid(x=True, y=True)

        # Initialize plot widget for melt pool image
        self.plotwindow = QtWidgets.QVBoxLayout(self.ImageWidget)
        self.image = pg.ImageView()
        self.plotwindow.addWidget(self.image)
        self.np_img = np.zeros((640,480))

        font = QtGui.QFont()
        font.setPointSize(12) 
        self.label_9.setFont(font)

        # ROS subscribers
        self.image_subscriber = rospy.Subscriber(image_topic, Image, self.image_callback, queue_size=10)
        self.audio_subscriber = rospy.Subscriber(audio_stamped_topic, AudioDataStamped, self.audio_callback, queue_size=10)
        
        

    def image_callback(self, msg_image):
        try:
            self.np_img = self.bridge.imgmsg_to_cv2(msg_image, "bgr8")
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

    # def audio_callback(self, msg_audio):
    #     nbits = 16
    #     scale_factor = 2**(nbits - 1)
    #     audio_data_numpy = (np.frombuffer(msg_audio.data, dtype=np.int16) / scale_factor)
    #     self.audio_buffer.extend(audio_data_numpy)

    #     if len(self.audio_buffer) < self.buffer_size:
    #         self.audio_buffer.extend([0.0] * (self.buffer_size - len(self.audio_buffer)))
    #     elif len(self.audio_buffer) > self.buffer_size:
    #         self.audio_buffer = deque(list(self.audio_buffer)[-self.buffer_size:], maxlen=self.buffer_size)

    #     audio_data_buffered = np.array(self.audio_buffer).astype(np.float32)
    #     self.audio_curve.setData(audio_data_buffered)

    def audio_callback(self, msg_audio):
        nbits = 16
        scale_factor = 2 ** (nbits - 1)
        audio_data_numpy = (np.frombuffer(msg_audio.data, dtype=np.int16) / scale_factor).astype(np.float32)
        self.audio_buffer.extend(audio_data_numpy)
        
        # Remove old data if buffer size exceeds 1 second of audio (44100 samples)
        while len(self.audio_buffer) > self.buffer_size:
            self.audio_buffer.popleft()
            
        # If buffer size is less than 1 second of audio, pad with zeros
        if len(self.audio_buffer) < self.buffer_size:
            self.audio_buffer.extend([0.0] * (self.buffer_size - len(self.audio_buffer)))    
        # Convert to numpy array for plotting
        self.audio_data_buffered = np.array(self.audio_buffer, dtype=np.float32)
  


    def updateAudio(self):
        self.audio_curve.setData(self.audio_time, self.audio_data_buffered)

    def updateImage(self):
        self.image.setImage(self.np_img)
        self.image.ui.histogram.hide()
        self.image.ui.roiBtn.hide()
        self.image.ui.roiPlot.hide()
        self.image.ui.normGroup.hide()
        self.image.ui.menuBtn.setVisible(False)







if __name__ == '__main__':
    rospy.init_node('audio_image_visualizer')
    app = QtWidgets.QApplication(sys.argv)
    
    visualizer = AudioImageVisualizer()
    visualizer.show()
    
    app.exec_()



    