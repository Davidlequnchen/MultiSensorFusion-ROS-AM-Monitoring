#!/usr/bin/env python3
import os
import sys
import rospy
import rospkg

from python_qt_binding import loadUi
from python_qt_binding import QtGui
from python_qt_binding import QtCore
from python_qt_binding import QtWidgets

from rviz import bindings as rviz

from camera_measures.msg import MsgVelocityStatus

#from qt_data import QtData
from qt_scan import QtScan
#from qt_param import QtParam
#from qt_part import QtPart
from qt_path_robviz import QtPath


path = rospkg.RosPack().get_path('scanning_robviz')


class MyViz(QtWidgets.QWidget):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)

        self.frame = rviz.VisualizationFrame()
        self.frame.setSplashPath("")
        self.frame.initialize()

        reader = rviz.YamlConfigReader()
        config = rviz.Config()

        reader.readFile(config, os.path.join(path, 'config', 'workcell.rviz'))
        self.frame.load(config)

        self.setWindowTitle(config.mapGetChild("Title").getValue())

        self.frame.setMenuBar(None)
        self.frame.setHideButtonVisibility(False)

        self.manager = self.frame.getManager()
        self.grid_display = self.manager.getRootDisplayGroup().getDisplayAt(0)

        layout = QtWidgets.QVBoxLayout()
        layout.setContentsMargins(9, 0, 9, 0)
        self.setLayout(layout)

        h_layout = QtWidgets.QHBoxLayout()
        layout.addLayout(h_layout)

        orbit_button = QtWidgets.QPushButton("Orbit View")
        orbit_button.clicked.connect(self.onOrbitButtonClick)
        h_layout.addWidget(orbit_button)

        front_button = QtWidgets.QPushButton("Front View")
        front_button.clicked.connect(self.onFrontButtonClick)
        h_layout.addWidget(front_button)

        right_button = QtWidgets.QPushButton("Rigth View")
        right_button.clicked.connect(self.onRightButtonClick)
        h_layout.addWidget(right_button)

        top_button = QtWidgets.QPushButton("Top View")
        top_button.clicked.connect(self.onTopButtonClick)
        h_layout.addWidget(top_button)

        layout.addWidget(self.frame)

    def switchToView(self, view_name):
        view_man = self.manager.getViewManager()
        for i in range(view_man.getNumViews()):
            if view_man.getViewAt(i).getName() == view_name:
                view_man.setCurrentFrom(view_man.getViewAt(i))
                return
        print("Did not find view named %s." % view_name)

    def onOrbitButtonClick(self):
        self.switchToView("Orbit View")

    def onFrontButtonClick(self):
        self.switchToView("Front View")

    def onRightButtonClick(self):
        self.switchToView("Right View")

    def onTopButtonClick(self):
        self.switchToView("Top View")


class Robviz(QtWidgets.QMainWindow):
    def __init__(self):
        #rospy.init_node('robviz')
        super(Robviz, self).__init__()
        rospy.init_node('robviz')

        loadUi(os.path.join(path, 'resources', 'robviz.ui'), self)

        rospy.Subscriber(
            '/supervisor/velocity_status', MsgVelocityStatus, self.cbStatus, queue_size=1)

        self.boxPlot.addWidget(MyViz())

        self.qtScan = QtScan(self)
        self.qtPath = QtPath(self)

        self.tabWidget.addTab(self.qtPath, 'Path')
        self.tabWidget.addTab(self.qtScan, 'Scan')

        
        self.qtScan.accepted.connect(self.qtScanAccepted)
 

        self.btnQuit.setIcon(QtGui.QIcon.fromTheme('application-exit'))
        self.btnQuit.clicked.connect(self.btnQuitClicked)

        self.speed = 0
        #self.power = 0
        self.running = False
        #self.laser_on = False

        # tmrInfo = QtCore.QTimer(self)
        # tmrInfo.timeout.connect(self.updateStatus)
        # tmrInfo.start(100)

    def cbStatus(self, msg_status):
        self.running = msg_status.running
        #self.laser_on = msg_status.laser_on
        self.speed = msg_status.speed
        #self.power = msg_status.power

    # def updateStatus(self):
    #     self.lblSpeed.setText("Speed: %.1f mm/s" % (self.speed))
    #     #self.lblPower.setText("Power: %i W" % (self.power))
    #     if self.running:
    #         self.lblStatus.setText('Running')
    #         self.lblStatus.setStyleSheet(
    #             "background-color: rgb(0, 255, 0); color: rgb(0, 0, 0);")
    #     else:
    #         self.lblStatus.setText('Stopped')
    #         self.lblStatus.setStyleSheet(
    #             "background-color: rgb(255, 0, 0); color: rgb(0, 0, 0);")
    #     '''
    #     if self.laser_on:
    #         self.lblLaser.setText('Laser ON')
    #         self.lblLaser.setStyleSheet(
    #             "background-color: rgb(255, 255, 0); color: rgb(0, 0, 0);")
    #     else:
    #         self.lblLaser.setText('Laser OFF')
    #         self.lblLaser.setStyleSheet(
    #             "background-color: rgb(0, 0, 255); color: rgb(0, 0, 0);")
    #     '''

    def qtDataAccepted(self):
        self.tabWidget.setCurrentWidget(self.qtParam)

    def qtParamAccepted(self):
        self.tabWidget.setCurrentWidget(self.qtPart)

    def qtScanAccepted(self, path):
        print('Path:', path)
        # commands = self.qtPath.jason.path2cmds(path)
        # print('Commands:', commands
        # self.qtPath.loadCommands(commands)
        # self.tabWidget.setCurrentWidget(self.qtPath)

    # def qtPartAccepted(self, path):
    #     commands = self.qtPath.jason.path2cmds(path)
    #     self.qtPath.loadCommands(commands)
    #     self.tabWidget.setCurrentWidget(self.qtPath)

    def btnQuitClicked(self):
        QtCore.QCoreApplication.instance().quit()


if __name__ == '__main__':
    try:
        app=QtWidgets.QApplication(sys.argv)
        robviz = Robviz()
        robviz.show()
        app.exec_()
    except rospy.ROSInterruptException:
        pass

    

