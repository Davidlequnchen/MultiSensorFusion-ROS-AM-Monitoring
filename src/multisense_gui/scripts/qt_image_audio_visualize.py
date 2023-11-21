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
import struct
from collections import deque


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

    ############-------------Original Method----------------#################
    # def audio_callback(self, msg_audio):
    #     nbits = 16
    #     scale_factor = 2 ** (nbits - 1)
    #     audio_data_numpy = (np.frombuffer(msg_audio.data, dtype=np.int16) / scale_factor).astype(np.float32)
    #     self.audio_buffer.extend(audio_data_numpy)
        
    #     # Remove old data if buffer size exceeds 1 second of audio (44100 samples)
    #     while len(self.audio_buffer) > self.buffer_size:
    #         self.audio_buffer.popleft()
            
    #     # If buffer size is less than 1 second of audio, pad with zeros
    #     if len(self.audio_buffer) < self.buffer_size:
    #         self.audio_buffer.extend([0.0] * (self.buffer_size - len(self.audio_buffer)))    
    #     # Convert to numpy array for plotting
    #     self.audio_data_buffered = np.array(self.audio_buffer, dtype=np.float32)


    ############-------------Mehtod: Numpy For Loop-----------------#################
    # def audio_callback(self, msg_audio):
    #     nbits = 24
    #     scale_factor = 2 ** (nbits - 1)

    #     # Read the data as bytes, then convert to 32-bit integers
    #     byte_data = np.frombuffer(msg_audio.data, dtype=np.uint8)
    #     audio_data_int32 = np.zeros(len(byte_data) // 3, dtype=np.int32)

    #     # Convert 3 bytes to a 32-bit integer (24-bit data)
    #     for i in range(len(audio_data_int32)):
    #         audio_data_int32[i] = byte_data[3*i] + (byte_data[3*i+1] << 8) + (byte_data[3*i+2] << 16)
    #         if audio_data_int32[i] & 0x800000:  # Adjust for signed 24-bit data
    #             audio_data_int32[i] -= 0x1000000
  
    #     # Normalize to float32
    #     audio_data_float = audio_data_int32.astype(np.float32) / scale_factor

    #     # Split into two channels
    #     left_channel = audio_data_float[0::2]
    #     right_channel = audio_data_float[1::2]

    #     # Extend the buffers for each channel
    #     self.audio_buffer.extend(left_channel)
    #     # self.right_audio_buffer.extend(right_channel)

    #     # Adjust buffer management for stereo data
    #     # Assuming self.buffer_size is per channel
    #     while len(self.audio_buffer) > self.buffer_size:
    #         self.audio_buffer.popleft()
    #         # self.right_audio_buffer.popleft()

    #     if len(self.audio_buffer) < self.buffer_size:
    #         padding = [0.0] * (self.buffer_size - len(self.audio_buffer))
    #         self.audio_buffer.extend(padding)
    #         # self.right_audio_buffer.extend(padding)

    #     # Convert to numpy array for plotting (if needed)
    #     # Note: You now have two channels to handle
    #     self.audio_data_buffered = np.array(self.audio_buffer, dtype=np.float32)


    ############-------------Mehtod: Numpy Vectorized-----------------#################
    # def audio_callback(self, msg_audio):
    #     nbits = 24
    #     scale_factor = 2 ** (nbits - 1)

    #     # Read the data as bytes
    #     byte_data = np.frombuffer(msg_audio.data, dtype=np.uint8)

    #     # Reshape the data to process 3 bytes at a time
    #     reshaped_data = byte_data.reshape(-1, 3)

    #     # Convert the 24-bit data to 32-bit integers
    #     audio_data_int32 = reshaped_data[:, 0].astype(np.int32) + \
    #                     (reshaped_data[:, 1].astype(np.int32) << 8) + \
    #                     (reshaped_data[:, 2].astype(np.int32) << 16)

    #     # Adjust for signed 24-bit data
    #     audio_data_int32 = np.where(audio_data_int32 & 0x800000, audio_data_int32 - 0x1000000, audio_data_int32)

    #     # Normalize to float32
    #     audio_data_float = audio_data_int32.astype(np.float32) / scale_factor

    #     # Split into two channels
    #     left_channel = audio_data_float[0::2]
    #     # right_channel = audio_data_float[1::2]

    #     # Extend the buffers for each channel
    #     self.audio_buffer.extend(left_channel)

    #     while len(self.audio_buffer) > self.buffer_size:
    #         self.audio_buffer.popleft()
    #         # self.right_audio_buffer.popleft()

    #     if len(self.audio_buffer) < self.buffer_size:
    #         padding = [0.0] * (self.buffer_size - len(self.audio_buffer))
    #         self.audio_buffer.extend(padding)
    #         # self.right_audio_buffer.extend(padding)

    #     # Convert to numpy array for plotting (if needed)
    #     # Note: You now have two channels to handle
    #     self.audio_data_buffered = np.array(self.audio_buffer, dtype=np.float32)

    
    ############------------------------------#################
    ############-------------Mehtod: Struct-----------------#################
    def audio_callback(self, msg_audio):
        # Read the data as bytes
        byte_data = msg_audio.data

        # Initialize lists to hold unpacked data for each channel
        left_channel_data = []
        right_channel_data = []

        # Process the data
        for i in range(0, len(byte_data), 6):
            # Left channel (first 3 bytes)
            left_padded_data = byte_data[i:i+3] + b'\x00'
            left_unpacked_data = struct.unpack('<i', left_padded_data)[0]
            if left_unpacked_data & 0x800000:  # Adjust for signed 24-bit data
                left_unpacked_data -= 0x1000000
            left_channel_data.append(left_unpacked_data)

            # Right channel (next 3 bytes)
            right_padded_data = byte_data[i+3:i+6] + b'\x00'
            right_unpacked_data = struct.unpack('<i', right_padded_data)[0]
            if right_unpacked_data & 0x800000:  # Adjust for signed 24-bit data
                right_unpacked_data -= 0x1000000
            right_channel_data.append(right_unpacked_data)

        # Normalize the data
        left_channel_data = [sample / float(2 ** 23 - 1) for sample in left_channel_data]
        right_channel_data = [sample / float(2 ** 23 - 1) for sample in right_channel_data]

        # Extend the buffers for each channel
        self.audio_buffer.extend(left_channel_data)

        while len(self.audio_buffer) > self.buffer_size:
            self.audio_buffer.popleft()
            # self.right_audio_buffer.popleft()

        if len(self.audio_buffer) < self.buffer_size:
            padding = [0.0] * (self.buffer_size - len(self.audio_buffer))
            self.audio_buffer.extend(padding)
            # self.right_audio_buffer.extend(padding)

        # Convert to numpy array for plotting (if needed)
        # Note: You now have two channels to handle
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



    