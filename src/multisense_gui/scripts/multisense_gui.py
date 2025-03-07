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

# #from qt_data import QtData
# from qt_scan import QtScan
# #from qt_param import QtParam
# #from qt_part import QtPart
# from qt_path_robviz import QtPath
from qt_image_audio_visualize import AudioImageVisualizer
from qt_image_audio_feature_visualize import AudioVisualFeatureVisualize
from qt_quality_visualize import QualityVisualize


path = rospkg.RosPack().get_path('multisense_gui')


class MyViz(QtWidgets.QWidget):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)

        self.frame = rviz.VisualizationFrame()
        self.frame.setSplashPath("")
        self.frame.initialize()

        reader = rviz.YamlConfigReader()
        config = rviz.Config()

        reader.readFile(config, os.path.join(path, 'config', 'workcell_kuka.rviz'))
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


class Multisense(QtWidgets.QMainWindow):
    def __init__(self):
        super(Multisense, self).__init__()
        rospy.init_node('multisense')

        loadUi(os.path.join(path, 'resources', 'multisense_gui.ui'), self)

        self.boxPlot.addWidget(MyViz())

        # self.qtScan = QtScan(self)
        # self.qtPath = QtPath(self)
        self.audio_image_visualizer = AudioImageVisualizer(self)
        self.audio_visual_feature_visualizer = AudioVisualFeatureVisualize(self)
        self.virtual_quality_visualizer = QualityVisualize(self)

        # self.tabWidget.addTab(self.qtPath, 'Path')
        # self.tabWidget.addTab(self.qtScan, 'Scan')
        self.tabWidget_2.addTab(self.audio_image_visualizer, 'Raw melt pool image audio visualization')
        self.tabWidget_2.addTab(self.audio_visual_feature_visualizer, 'Melt pool audio-visual feature visualization')

        self.tabWidget_3.addTab(self.virtual_quality_visualizer, 'Location-specific quality prediction')

        self.btnQuit.setIcon(QtGui.QIcon.fromTheme('application-exit'))
        self.btnQuit.clicked.connect(self.btnQuitClicked)


    def qtDataAccepted(self):
        self.tabWidget.setCurrentWidget(self.qtParam)

    def qtParamAccepted(self):
        self.tabWidget.setCurrentWidget(self.qtPart)

    def btnQuitClicked(self):
        QtCore.QCoreApplication.instance().quit()


if __name__ == '__main__':
    try:
        app=QtWidgets.QApplication(sys.argv)
        multisense = Multisense()
        multisense.show()
        app.exec_()
    except rospy.ROSInterruptException:
        pass

    

