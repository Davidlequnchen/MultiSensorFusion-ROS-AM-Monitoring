#!/usr/bin/env python
import os
import sys
import rospy
import rospkg

from camera_measures.msg import MsgVelocity
from velocity_control.msg import MsgSpeedOverride
# contains control(True/Flase), and mode(manual/auto)
from velocity_control.msg import MsgVelocityControl  


from python_qt_binding import loadUi
from python_qt_binding import QtGui
from python_qt_binding import QtCore
# from python_qt_binding.QtWidgets import QtWidget
from python_qt_binding import QtWidgets 


MANUAL = 0
AUTOMATIC = 1
path = rospkg.RosPack().get_path('velocity_control')


class QtControl(QtWidgets.QWidget):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        loadUi(os.path.join(path, 'resources', 'velocity_control.ui'), self)


        self.btnMode.activated.connect(self.btnModeClicked)
        #self.btnAuto.activated.connect(self.btnAutoClicked)
        self.btnControl.clicked.connect(self.btnControlClicked)

        # this topic contains velocity control parameters: whether control has start, and the current mode is MANUAL or AUTOMATIC
        self.pub_control = rospy.Publisher(
            '/velocity_control/mode_and_start', MsgVelocityControl, queue_size=10)
        

        self.mode = MANUAL #initial set the mode to be manual

        # to show whether the the control has changed, if click the button accept parameters, this value will be true
        self.msg_velocity_control = MsgVelocityControl()
    
        self.SpeedOverride = 0
        self.control = False

        self.track_number= 0
        self.time_control = 0


        rospy.Subscriber(
            '/velocity_control/SpeedOverride', MsgSpeedOverride, self.cb_SpeedOverride, queue_size=1)
       

        self.btnModeClicked()

        self.tmrInfo = QtCore.QTimer(self)
        self.tmrInfo.timeout.connect(self.tmrInfoEvent)
        self.tmrInfo.start(500)

        self.setPIDparameters(rospy.get_param('/speed_control_parameters/pid_parameters'))
        self.setSpeedControlParameters(rospy.get_param('/speed_control_parameters/SpeedOverrideLimit'))
        self.setManualParameters(rospy.get_param('/speed_control_parameters/manual'))
        self.setAutoParameters(rospy.get_param('/speed_control_parameters/automatic'))
        self.btnControlClicked()

  
    def setPIDparameters(self, params):
        self.sbKp.setValue(params['Kp'])
        self.sbKi.setValue(params['Ki'])
        self.sbKd.setValue(params['Kd'])

    def getParameters(self):
        params = {'Kd': self.sbKd.value(),
                  'Ki': self.sbKi.value(),
                  'Kp': self.sbKp.value()}
        return params

    def setManualParameters(self, params):
        self.sbCurrentSpeedOverride.setValue(params['CurrentSpeedOverride'])

    def getManualParameters(self):
        params = {'CurrentSpeedOverride': self.sbCurrentSpeedOverride.value()}
        return params

    def setAutoParameters(self, params):
        self.sbNominaloverride.setValue(params['NominalOverride'])
        self.sbsbSpeedSet.setValue(params['speedSet'])
        self.sbnominalSpeed.setValue(params['nominalSpeed'])

    def getAutoParameters(self):
        params = {'NominalOverride': self.sbNominaloverride.value(),
                  'speedSet': self.sbsbSpeedSet.value(),
                  'nominalSpeed': self.self.sbnominalSpeed.value()}
        return params

    def btnModeClicked(self):
        if self.btnMode.currentText() == "Manual":
            self.lblStatus.setText("Manual")
            self.lblStatus.setStyleSheet(
                "background-color: rgb(255, 220, 0); color: rgb(0, 0, 0);")
            self.mode = MANUAL
            self.tbParams.setCurrentIndex(1)
        elif self.btnMode.currentText() == "Automatic":
            self.lblStatus.setText("Auto")
            self.lblStatus.setStyleSheet(
                "background-color: rgb(0, 0, 255); color: rgb(255, 255, 255);")
            self.mode = AUTOMATIC
            self.tbParams.setCurrentIndex(0)


    def btnAutoClicked(self):
        if self.btnAuto.currentText() == "Continuous":
            self.auto_mode = 0
            self.sbTrack.setEnabled(True)
        elif self.btnAuto.currentText() == "Tracks":
            self.sbTrack.setValue(0)
            self.auto_mode = 1
            self.sbTrack.setEnabled(False)


    def btnControlClicked(self):
        param = self.getParameters()
        rospy.set_param('/speed_control_parameters/pid_parameters', param)

        manual = self.getManualParameters()
        rospy.set_param('/speed_control_parameters/manual', manual)

        auto = self.getAutoParameters()
        rospy.set_param('/speed_control_parameters/automatic', auto)

        self.msg_control.change = True
        self.msg_control.value = self.mode
        self.pub_control.publish(self.msg_control)
        self.msg_emission.emission = True                                                    #20191011
        self.pub_emission.publish(self.msg_emission)


    def cb_geometry(self, msg_geometry):
        self.minor_axis = msg_geometry.minor_axis
        self.major_axis = msg_geometry.major_axis

    def cb_power(self, msg_power):
        self.power = msg_power.value

    def cb_info(self, msg_info):
        self.track_number = msg_info.track_number
        self.time_control = msg_info.time

    def cb_start(self, msg_start):
        self.control = msg_start.control
        if self.control is True:
            self.sbWidth.setValue(msg_start.setpoint)
            auto = self.getAutoParameters()
            rospy.set_param('/control_parameters/automatic', auto)

    def tmrInfoEvent(self):
        self.lblInfo.setText(
            "Minor axis: %.2f<br>Major axis: %.2f<br><b>Power: %.0f</b>" % (
                self.minor_axis, self.major_axis, self.power))
        self.lblNumber.setText(str(self.track_number))
        self.lblTime_2.setText('%.2f' % float(self.time_control))
        if self.control is True:
            self.lblControl.setText("Activated")
            self.lblControl.setStyleSheet(
                 "background-color: rgb(0, 0, 128); color: rgb(255, 255, 255);")
        else:
            self.lblControl.setText("Stopped")
            self.lblControl.setStyleSheet(
                 "background-color: rgb(255, 0, 0); color: rgb(255, 255, 255);")


if __name__ == '__main__':
    rospy.init_node('control_panel')
    #app = QtGui.QApplication(sys.argv)
    app=QtWidgets.QApplication(sys.argv)
    qt_control = QtControl()
    qt_control.show()
    app.exec_()
