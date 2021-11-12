#!/usr/bin/env python3
import os
import sys
import rospy
import rospkg
from sensor_msgs.msg import Image
from infratec_image_processing.msg import MsgHistogram
from cv_bridge import CvBridge, CvBridgeError

from python_qt_binding import loadUi
from python_qt_binding import QtGui
from python_qt_binding import QtCore
from python_qt_binding import QtWidgets 

from qt_infratec import irbgrab_demo

path = rospkg.RosPack().get_path('infratec_ros_driver')


class ThermalViz(QtWidgets.QMainWindow):
    def __init__(self):
        super(ThermalViz, self).__init__()
        rospy.init_node('ThermalViz')

        loadUi(os.path.join(path, 'resources', 'infratec_insitu_viz.ui'), self)

        rospy.Subscriber('/infratec/image_raw', Image, self.cbRawImage, queue_size=2)
        rospy.Subscriber('/infratec/heat_affected_zone', Image, self.cbHeatAffectedZone, queue_size=2)

        self.qtInfratec = irbgrab_demo(self)

        self.tabWidget.addTab(self.qtInfratec, 'Infratec Camera')
        
        # self.qtInfratec.accepted.connect(self.qtInfratecAccepted)
 

        self.btnQuit.setIcon(QtGui.QIcon.fromTheme('application-exit'))
        self.btnQuit.clicked.connect(self.btnQuitClicked)


        # tmrInfo = QtCore.QTimer(self)
        # tmrInfo.timeout.connect(self.updateStatus)
        # tmrInfo.start(100)

    def cbRawImage(self, msg_raw_image):
        pass


    def cbHeatAffectedZone(self, msg_HAZ):
        pass



    def qtInfratecAccepted(self):
        self.tabWidget.setCurrentWidget(self.qtInfratec)

    def btnQuitClicked(self):
        QtCore.QCoreApplication.instance().quit()


if __name__ == '__main__':
    try:
        app=QtWidgets.QApplication(sys.argv)
        thermalviz = ThermalViz()
        thermalviz.show()
        app.exec_()
    except rospy.ROSInterruptException:
        pass

    

