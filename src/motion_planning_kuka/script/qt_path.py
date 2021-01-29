#!/usr/bin/env python
import os
import sys
import logging
import json
import simplejson
import rospy
import rospkg
import numpy as np
import tf.transformations as tf

from motion_planning_kuka.srv import SrvRobotCommand

from visualization_msgs.msg import Marker
from visualization_msgs.msg import MarkerArray
from markers import PathMarkers
#from planning.markers import PathMarkers

from urdf_parser_py.urdf import URDF

from python_qt_binding import loadUi
from python_qt_binding import QtGui
from python_qt_binding import QtCore
from python_qt_binding import QtWidgets

from jason.jason import Jason


path = rospkg.RosPack().get_path('motion_planning_kuka')
'''
This node 'path_panel' is a Client, it wait for the ROS service 'robot_send_command' to be created and send command
to the ROS service(request) to the (nd_robot_command),
i.e. it calls the service 'robot_send_command' by rospy.ServiceProxy
call rospy.wait_for_service() to block until a service is available.
'''


log = logging.getLogger(__name__)
log.addHandler(logging.NullHandler())


class QtPath(QtWidgets.QWidget):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        loadUi(os.path.join(path, 'resources', 'path.ui'), self)

        try:
            rospy.wait_for_service('robot_send_command', timeout=5)
            self.send_command = rospy.ServiceProxy(
                'robot_send_command', SrvRobotCommand)
        except:
            rospy.loginfo('ERROR connecting to service robot_send_command.')
        #self.pub = rospy.Publisher(
        #    import tf'robot_command_json', MsgRobotCommand, queue_size=10)

        self.pub_marker_array = rospy.Publisher(
            'visualization_marker_array', MarkerArray, queue_size=10)

        self.btnLoadPath.clicked.connect(self.btnLoadPathClicked)
        icon = QtGui.QIcon.fromTheme('document-open')
        self.btnLoadPath.setIcon(icon)
        self.btnSavePath.clicked.connect(self.btnSavePathClicked)
        icon = QtGui.QIcon.fromTheme('document-save')
        self.btnSavePath.setIcon(icon)
        self.btnRunPath.clicked.connect(self.btnRunPathClicked)
        icon = QtGui.QIcon.fromTheme('media-playback-start')
        self.btnRunPath.setIcon(icon)
        self.btnRunTest.clicked.connect(self.btnRunTestClicked)
        self.btnRunTest.setIcon(icon)

        self.btnDelete.clicked.connect(self.btnDeleteClicked)
        self.btnLoadPose.clicked.connect(self.btnLoadPoseClicked)
        self.btnStep.clicked.connect(self.btnStepClicked)
        self.btnCancel.clicked.connect(self.btnCancelClicked)

        # self.listWidgetPoses.itemSelectionChanged.connect(self.lstPosesClicked)
        self.listWidgetPoses.itemDoubleClicked.connect(self.qlistDoubleClicked)

        self.testing = False
        self.ok_command = "OK"
        self.path_markers = PathMarkers()

        # Parse robot description file
        robot = URDF.from_parameter_server()
        # tcp = robot.joint_map['tcp0']
        # workobject = robot.joint_map['world-workobject']


        # tool = [tcp.origin.position,
        #         list(tf.quaternion_from_euler(*tcp.origin.rotation))]
        # print ('Tool:', tool)
        # workobject = [workobject.origin.position,
        #               list(tf.quaternion_from_euler(*workobject.origin.rotation))]
        # print ('Workobject:', workobject)
        # if rospy.has_param('/powder'):
        #     powder = rospy.get_param('/powder')
        # else:
        #     print ('/powder param missing, loaded default')
        #     powder = {'carrier': 5.0, 'shield': 10.0, 'stirrer': 20.0, 'turntable': 4.0}
        # print ('Powder:', powder)
        # if rospy.has_param('/process'):
        #     process = rospy.get_param('/process')
        # else:
        #     print ('/process param missing, loaded default')
        #     process = {'focus': 0, 'power': 1000, 'speed': 8}
        # print ('Process:', process)

        self.jason = Jason()
        # self.jason.set_tool(tool)
        # self.jason.set_workobject(workobject)
        # self.jason.set_powder(
        #     powder['carrier'], powder['stirrer'], powder['turntable'])
        # self.jason.set_process(process['speed'], process['power'])

        self.tmrRunPath = QtCore.QTimer(self)
        self.tmrRunPath.timeout.connect(self.timeRunPathEvent)

    def insertPose(self, pose):
        (x, y, z), (qx, qy, qz, qw) = pose
        str_pose = '((%.3f, %.3f, %.3f), (%.4f, %.4f, %.4f, %.4f))' %(x, y, z, qx, qy, qz, qw)
        #item = QtGui.QListWidgetItem('item_text')
        #self.listWidgetPoses.addItem(item)
        self.listWidgetPoses.addItem(str_pose)
        #self.listWidgetPoses.insertItem(0, '0, 1, 2')

    def insertCommand(self, command, insert=False, position=0):
        if not insert:
            self.listWidgetPoses.addItem(command)
        else:
            self.listWidgetPoses.insertItem(position, command)

    def removeComamnd(self):
        item = self.listWidgetPoses.takeItem(0)
        if item:
            print (item.text())
            return item.text()
        else:
            return None

    def loadCommands(self, commands):
        self.listWidgetPoses.clear()
        [self.insertCommand(cmd) for cmd in commands]
        self.arr = []
        self.getMoveCommands()

    def btnLoadPathClicked(self):
        filename = QtWidgets.QFileDialog.getOpenFileName(
            self, 'Load Path Routine', os.path.join(path, 'routines'),
            'Jason Routine Files (*.jas)')[0]
        print ('Load routine:', filename)
        commands = self.jason.load_commands(filename)
        self.loadCommands(commands)

    def btnSavePathClicked(self):
        filename = QtWidgets.QFileDialog.getSaveFileName(
            self, 'Load Path Routine', os.path.join(path, 'routines'),
            'Jason Routine Files (*.jas)')[0]
        n_row = self.listWidgetPoses.count()
        if n_row > 0:
            cmds = [str(self.listWidgetPoses.item(row).text()) for row in range(n_row)]
            self.jason.save_commands(filename, cmds)
        print ('Saved routine:', filename)

    def btnRunPathClicked(self):
        """Start-Stop sending commands to robot from the list of commands."""
        if self.tmrRunPath.isActive():
            if not self.testing:
                self.tmrRunPath.stop()
                self.btnRunPath.setText('Run')
                icon = QtGui.QIcon.fromTheme('media-playback-start')
                self.btnRunPath.setIcon(icon)
                self.btnRunTest.setEnabled(True)
        else:
            self.btnRunTest.setEnabled(False)
            # self.sendCommand('{"reset_laser":1}')
            # self.sendCommand('{"reset_powder":1}')
            # self.sendCommand('{"reset_wire":1}')
            self.btnRunPath.setText('Stop')
            icon = QtGui.QIcon.fromTheme('media-playback-stop')
            self.btnRunPath.setIcon(icon)
            self.tmrRunPath.start(300)  # time in ms (originally 100 ms)

    def btnRunTestClicked(self):
        """Start-Stop sending test commands to robot from the list of commands."""
        if self.tmrRunPath.isActive():
            if self.testing:
                self.tmrRunPath.stop()
                self.btnRunTest.setText('Test')
                icon = QtGui.QIcon.fromTheme('media-playback-start')
                self.btnRunTest.setIcon(icon)
                self.testing = False
                self.btnRunPath.setEnabled(True)
        else:
            self.testing = True
            self.btnRunPath.setEnabled(False)
            # self.sendCommand('{"reset_laser":1}')
            # self.sendCommand('{"reset_powder":1}')
            # self.sendCommand('{"reset_wire":1}')
            self.btnRunTest.setText('Stop')
            icon = QtGui.QIcon.fromTheme('media-playback-stop')
            self.btnRunTest.setIcon(icon)
            self.tmrRunPath.start(100)  # time in ms

    def btnDeleteClicked(self):
        row = self.listWidgetPoses.currentRow()
        self.listWidgetPoses.takeItem(row)
        #self.listWidgetPoses.clear()

    def btnLoadPoseClicked(self):
        rob_pose = self.send_command('{"get_pose":1}')
        default_command = '{"move_frame":' + rob_pose.response + '}'
        str_command = QtWidgets.QInputDialog.getText(
            self, "Load Jason Command", "Comamnd:", text=default_command)
        row = self.listWidgetPoses.currentRow()
        if len(str_command[0]) > 3:
            self.insertCommand(str_command[0], insert=True, position=row)
        print (str_command)

    def btnStepClicked(self):
        n_row = self.listWidgetPoses.count()
        if n_row > 0:
            row = self.listWidgetPoses.currentRow()
            if row == -1:
                row = 0
            item_text = self.listWidgetPoses.item(row)
            #self.pub.publish(item_text.text())
            self.sendCommand(item_text.text())
            # if len(self.ok_command.split()) == 0:
            #     self.invalid_command("No response command")
            #     return
            # if len(self.ok_command.split()) == 1:
            #     if self.ok_command.split()[0] == "ERR_COMMAND":
            #         self.invalid_command("Check the command name")
            #         return
            #     if self.ok_command.split()[0] == "PARAM_ERROR":
            #         self.invalid_command("Check the command parameters")
            #         return
            #     if self.ok_command.split()[0] == "NOK":
            #         self.invalid_command("Not a Json comand")
            #         return
            # if len(self.ok_command.split()) == 3:
            #     if self.ok_command.split()[2] == "BUFFER_FULL":
            #         return
            row += 1
            if row == n_row:
                row = 0
            self.listWidgetPoses.setCurrentRow(row)

    def lstPosesClicked(self):
        row = self.listWidgetPoses.currentRow()
        item_text = self.listWidgetPoses.item(row)
        command = json.loads(item_text.text())
        pose = None
        if 'move' in command:
            orientation = np.array([command["move"][1][1],
                                    command["move"][1][2],
                                    command["move"][1][3],
                                    command["move"][1][0]])
            position = np.array(command["move"][0]) * 0.001
            pose = (position, orientation)
        self.path_markers.set_pose(pose)
        self.pub_marker_array.publish(self.path_markers.marker_array)

    def qlistDoubleClicked(self):
        row = self.listWidgetPoses.currentRow()
        item_text = self.listWidgetPoses.item(row)
        str_command = QtWidgets.QInputDialog.getText(
            self, "Load Jason Command", "Comamnd:", text=item_text.text())
        if len(str_command[0]) > 3:
            self.listWidgetPoses.takeItem(row)
            self.insertCommand(str_command[0], insert=True, position=row)

    def btnCancelClicked(self):
        # self.sendCommand('{"reset_laser":1}')
        # self.sendCommand('{"reset_powder":1}')
        # self.sendCommand('{"reset_wire":1}')
        self.sendCommand('{"cancel":1}')
        if self.tmrRunPath.isActive():
            self.tmrRunPath.stop()
            icon = QtGui.QIcon.fromTheme('media-playback-start')
            self.btnRunPath.setText('Run')
            self.btnRunTest.setText('Test')
            self.btnRunPath.setIcon(icon)
            self.btnRunTest.setIcon(icon)
            self.testing = False
            self.btnRunTest.setEnabled(True)
            self.btnRunPath.setEnabled(True)

    def getMoveCommands(self):                                               # may have bug
        n_row = self.listWidgetPoses.count()
        # row = self.listWidgetPoses.currentRow()
        path = []
        for row in range(n_row):
            item_text = self.listWidgetPoses.item(row)
            try:
                command = json.loads(item_text.text())
                if 'move_frame' in command:
                    path.append(command['move_frame'])
            except:
                log.info("Exception parsing comments json - not leaving comment")
                #return True

        # self.path_markers.set_path(path)
        # self.pub_marker_array.publish(self.path_markers.marker_array)

    def sendCommand(self, command):
        if self.testing:
            command = command.lower()
            command = command.replace(' ','')
            if command.lower().find('laserReady') == 2:
                return
            if command.lower().find('powder') == 2:
                return
            if command.lower().find('move_frame') == 2:
                if command.find(',true') > 0:
                    command = command.replace(',true','')
                if command.find(',false') > 0:
                    command = command.replace(',false','')
        rob_response = self.send_command(command)
        print ('Sended command:', command)
        print ('Received response:', rob_response)
        self.ok_command = rob_response.response

    def timeRunPathEvent(self):
        """Sends a command each time event from the list of commands."""
        n_row = self.listWidgetPoses.count()
        if n_row > 0:
            row = self.listWidgetPoses.currentRow()
            if row == -1:
                row = 0
            item_text = self.listWidgetPoses.item(row)
            self.sendCommand(item_text.text())
            # if len(self.ok_command.split()) == 3:
            #     if self.ok_command.split()[2] == "BUFFER_FULL":
            #         return
            # if len(self.ok_command.split()) == 1:
            #     if self.ok_command.split()[0] == "ERR_COMMAND":
            #         if self.testing:
            #             self.btnRunTestClicked()
            #         else:
            #             self.btnRunPathClicked()
            #         self.invalid_command("Check the command name")
            #         return
            #     if self.ok_command.split()[0] == "PARAM_ERROR":
            #         if self.testing:
            #             self.btnRunTestClicked()
            #         else:
            #             self.btnRunPathClicked()
            #         self.invalid_command("Check the command parameters")
            #         return
            #     if self.ok_command.split()[0] == "NOK":
            #         if self.testing:
            #             self.btnRunTestClicked()
            #         else:
            #             self.btnRunPathClicked()
            #         self.invalid_command("Not a Json comand")
            #         return
            # if len(self.ok_command.split()) == 0:
            #     if self.testing:
            #         self.btnRunTestClicked()
            #     else:
            #         self.btnRunPathClicked()
            #     self.invalid_command("No response command")
            #     return
            row += 1
            if row == n_row:
                row = 0
                if self.testing:
                    self.btnRunTestClicked()
                else:
                    self.btnRunPathClicked()
            self.listWidgetPoses.setCurrentRow(row)

    def invalid_command(self, informative):
        msg = QtWidgets.QMessageBox()
        msg.setIcon(QtWidgets.QMessageBox.Warning)
        msg.setText("Invalid command")
        msg.setInformativeText(informative)
        msg.setWindowTitle("Command error")
        #msg.setDetailedText("The details are as follows:")
        msg.setStandardButtons(QtWidgets.QMessageBox.Ok)
        #msg.buttonClicked.connect(msgbtn)
        retval = msg.exec_()

if __name__ == "__main__":
    rospy.init_node('path_panel')

    app=QtWidgets.QApplication(sys.argv)
    qt_path = QtPath()
    qt_path.show()
    app.exec_()
