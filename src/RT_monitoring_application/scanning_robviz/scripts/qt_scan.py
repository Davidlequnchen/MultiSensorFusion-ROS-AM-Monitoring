#!/usr/bin/env python
import os
import sys
import rospy
import rospkg
import numpy as np

import sensor_msgs.point_cloud2 as pc2
from sensor_msgs.msg import PointCloud2
import std_msgs

from visualization_msgs.msg import MarkerArray
from markers import ScanMarkers

from python_qt_binding import loadUi
from python_qt_binding import QtGui
from python_qt_binding import QtCore
from python_qt_binding import QtWidgets

from camera_measures.msg import MsgVelocityStatus

from planning.planning import Planning
from cloud.contours import Segmentation
import cloud.contours as contours
import cloud.distance as distance


dirname = rospkg.RosPack().get_path('scanning_robviz')


class QtScan(QtWidgets.QWidget):
    accepted = QtCore.pyqtSignal(list)

    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        loadUi(os.path.join(dirname, 'resources', 'scan.ui'), self)

        rospy.Subscriber(
            '/microepsilon/cloud_transformed', PointCloud2, self.cbPointCloud, queue_size=1)
        rospy.Subscriber(
            '/supervisor/velocity_status', MsgVelocityStatus, self.cbStatus, queue_size=1)
        # rospy.Subscriber(
        #     '/microepsilon/zheight', std_msgs.msg.Float32, self.cbHeight, queue_size=1)

        self.pub_marker_array = rospy.Publisher(
            'visualization_marker_array', MarkerArray, queue_size=10)

        self.btnPlane.clicked.connect(self.btnPlaneClicked)
        self.btnRecord.clicked.connect(self.btnRecordClicked)
        self.btnZmap.clicked.connect(self.btnZmapClicked)
        self.btnPath.clicked.connect(self.btnPathClicked)
        self.btnScan.clicked.connect(self.btnScanClicked)

        self.sbPositionX.valueChanged.connect(self.changePosition)
        self.sbPositionY.valueChanged.connect(self.changePosition)
        self.sbPositionZ.valueChanged.connect(self.changePosition)

        self.sbSizeX.valueChanged.connect(self.changeSize)
        self.sbSizeY.valueChanged.connect(self.changeSize)
        self.sbSizeZ.valueChanged.connect(self.changeSize)

        self.filename = ''
        self.status = False
        self.running = False
        self.recording = False

        self.path = []
        self.scan_markers = None
        self.planning = Planning()
        self.position = np.array([0, 0, 10])
        self.size = np.array([100, 200, 0])
        self.segmentation = Segmentation()

        self.zmax = 0.0
        self.new_h = False

        rospy.Timer(rospy.Duration(5), self.timer_callback)

    def timer_callback(self, event):
        if self.new_h:
            self.new_h = False
        else:
            self.lcdZ.setEnabled(False)

    # def cbHeight(self, msg_float):
    #     self.lcdZ.display(float(msg_float.data * 1000.0)) #from meter to mm, will display the height message on ui.
    #     self.lcdZ.setEnabled(True)

    def cbPointCloud(self, msg_cloud):
        points = pc2.read_points(msg_cloud, skip_nans=False)
        self.points3d = np.float32([point for point in points])
        # if it is recording now, will save the point cloud into the data folder as a .xyz file.(only of button recording clicked)
        if self.recording:
            with open(self.filename, 'a') as f: # a means append data to a file
                np.savetxt(f, self.points3d, fmt='%.6f')

    def cbStatus(self, msg_status):
        status = msg_status.running
        if not self.status and status:  #self.running means running the recording functionality
            if self.running:           # self.running will be true only when button recording clicked, then the text will tell you you are recording now.
                self.recording = True
                self.btnRecord.setText('Recording...')
        elif self.status and not status: 
            self.running = False
            self.recording = False
            self.btnRecord.setText('Record Cloud')
        self.status = status

    def updatePlane(self):
        (x, y, z), (w, h, t) = self.position, self.size
        plane = np.array([[x, y, z], [x+w, y, z], [x+w, y+h, z], [x, y+h, z]])
        slice = [plane - np.array([0, 50, 0])]  # laser stripe offset
        path = self.planning.get_path_from_slices(
            [slice], track_distance=100, focus=100, degrees=0.0)
        self.path = [[pos, ori] for pos, ori, bol in path]
        self.scan_markers.set_plane_size(self.size)
        self.scan_markers.set_plane_position(self.position)
        self.scan_markers.set_path(self.path)
        self.pub_marker_array.publish(self.scan_markers.marker_array)

    def changePosition(self):
        self.position = np.array([self.sbPositionX.value(),
                                  self.sbPositionY.value(),
                                  self.sbPositionZ.value()])
        self.updatePlane()

    def changeSize(self):
        self.size = np.array([self.sbSizeX.value(),
                              self.sbSizeY.value(),
                              self.sbSizeZ.value()])
        self.updatePlane()

    def btnPlaneClicked(self):
        self.scan_markers = ScanMarkers()
        self.updatePlane()

    def btnRecordClicked(self):
        if self.running:
            self.running = False
            self.recording = False
            self.btnRecord.setText('Record Cloud')
        else:
            # try:
            filename = QtWidgets.QFileDialog.getSaveFileName(
                self, 'Save file', os.path.join(dirname, 'data', 'test.xyz'),
                'Point Cloud Files (*.xyz)')[0]
            self.filename = filename
            # with open(self.filename, 'w') as f:
            #     pass
            self.running = True
            self.recording = True
            self.btnRecord.setText('Stop recording...')
            # except IOError as error:
            #     print error

    def btnZmapClicked(self):
        filename = QtWidgets.QFileDialog.getOpenFileName(
            self, 'Load file', os.path.join(dirname, 'data', 'test.xyz'),
            'Point Cloud Files (*.xyz)')[0]
        name, extension = os.path.splitext(filename)
        if os.path.isfile(filename):
            cloud = contours.read_cloud(filename)
            self.zmap = contours.zmap_from_cloud(cloud)
            self.zmap = contours.fill_zmap(self.zmap, size=7)
            self.zmap = contours.erode_zmap(self.zmap, size=5, iterations=5)
            contours.save_zmap('%s.tif' % name, self.zmap)
            self.segmentation.plot_zmap(self.zmap)
        else:
            print 'Create Zmap: Incorrect filename'

    def btnPathClicked(self):
        try:
            slice = contours.slice_of_contours(self.zmap, self.segmentation.contours)
            path = self.planning.get_path_from_slices([slice], track_distance=1.3, focus=0)
            #contours.show_path_from_slice(slice)
            self.path = path
            #self.path = [[pos, ori] for pos, ori, bol in path]
            self.scan_markers.set_path(self.path)
            self.pub_marker_array.publish(self.scan_markers.marker_array)
        except AttributeError as error:
            print error

    def btnScanClicked(self):
        self.accepted.emit(self.path)


if __name__ == "__main__":
    rospy.init_node('scan_panel')

    app = QtWidgets.QApplication(sys.argv)
    qt_scan = QtScan()
    qt_scan.show()
    app.exec_()
