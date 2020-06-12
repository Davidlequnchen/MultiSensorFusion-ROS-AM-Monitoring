#!/usr/bin/env python
import sys
import cv2
import rospy
import numpy as np

from python_qt_binding import QtGui
from python_qt_binding import QtCore


from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

from tachyon.tachyon import LUT_IRON


class QtDisplay(QtGui.QWidget):
    def __init__(self, parent=None, size=64):
        super(QtDisplay, self).__init__(parent)
        self.setMinimumSize(240, 240)
        self.setMaximumSize(300, 300)

        layout = QtGui.QVBoxLayout()
        layout.setContentsMargins(1, 1, 1, 1)
        self.setLayout(layout)

        self.lblCamera = QtGui.QLabel()
        self.lblCamera.setStyleSheet(
            'background-color: rgb(127,127,127); border: 3px solid rgb(63, 63, 63)')
        self.lblCamera.setSizePolicy(
            QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred,
                              QtGui.QSizePolicy.Expanding))
        self.lblCamera.setAlignment(QtCore.Qt.AlignCenter)
        self.lblCamera.mousePressEvent = self.mousePressEvent
        layout.addWidget(self.lblCamera)

        size = 32
        self.bridge = CvBridge()
        self.pixmap = QtGui.QPixmap()
        self.image = np.zeros((size, size, 3), dtype=np.uint8)

        timer = QtCore.QTimer(self)
        timer.timeout.connect(self.timeoutRunning)
        timer.start(20)

    def subscribeTopic(self, image_topic):
        rospy.Subscriber(image_topic, Image, self.cbImage, queue_size=1)

    def paintFrame(self, image):
        if len(image.shape) == 2:
            image = LUT_IRON[image]
        height, width, channels = image.shape
        width, height = 2 * width, 2 * height
        image = cv2.resize(image, (width, height))
        image = QtGui.QImage(image.tostring(), width, height,
                             channels * width, QtGui.QImage.Format_RGB888)
        self.pixmap.convertFromImage(image)
        pixmap = self.pixmap.scaled(self.lblCamera.size(),
                                    QtCore.Qt.KeepAspectRatio)
        painter = QtGui.QPainter()
        painter.begin(self.pixmap)
        painter.setWindow(0, 0, 32, 32)
        painter.end()
        self.lblCamera.setPixmap(pixmap)

    def timeoutRunning(self):
        self.paintFrame(self.image)

    def cbImage(self, msg_image):
        try:
            frame = self.bridge.imgmsg_to_cv2(msg_image)
            if msg_image.encoding == "bgr8":
                frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            self.image = frame
        except CvBridgeError, e:
            print e


if __name__ == '__main__':
    rospy.init_node('display')

    app = QtGui.QApplication(sys.argv)
    qt_display = QtDisplay()
    qt_display.subscribeTopic('/tachyon/image')
    qt_display.show()
    app.exec_()
