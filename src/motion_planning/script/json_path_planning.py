#!/usr/bin/env python
import os
import sys
import logging
import json
import simplejson
import rospy
import rospkg
import numpy as np
from threading import Timer,Thread,Event
import tf.transformations as tf

from motion_planning_jason.srv import SrvRobotCommand
from auto_control.msg import MsgCommand


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


path = rospkg.RosPack().get_path('motion_planning_jason')
'''
This node 'json_path_planning' is similar to the qt_path
it does not use GUI to load the json file
instead, it directly load the json file and run all the commands
'''


log = logging.getLogger(__name__)
log.addHandler(logging.NullHandler())


class perpetualTimer():
    '''
    This class give the same functionality as Qt Qtimer
    it can let the timer execute the function repeatedly in predefined interval
    '''   
    def __init__(self,t,hFunction):
      self.t=t
      self.hFunction = hFunction
      self.thread = Timer(self.t,self.handle_function)

    def handle_function(self):
      self.hFunction() # call the function
      self.thread = Timer(self.t,self.handle_function)
      self.thread.start()

    def start(self):
      self.thread.start()

    def cancel(self):
      self.thread.cancel()

def printer():
    print ('ipsem lorem')



# t = perpetualTimer(0.1,printer)  
# t.start()


class JsonCommand(QtWidgets.QWidget):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        loadUi(os.path.join(path, 'resources', 'command_list.ui'), self)
        rospy.init_node('json_command_panel')

        
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
        
        #------------------------------------------------------------
        ## Subscriber
        rospy.Subscriber(
                '/main_command', MsgCommand, self.cbCommand, queue_size=1)

        tmrInfo = QtCore.QTimer(self)
        tmrInfo.timeout.connect(self.updateStatus)
        tmrInfo.start(100)

        
        self.listWidgetPoses.itemDoubleClicked.connect(self.qlistDoubleClicked)

        self.testing = False
        self.ok_command = "OK"
        self.path_markers = PathMarkers()

        # Parse robot description file
        robot = URDF.from_parameter_server()
        tcp = robot.joint_map['tcp0']
        workobject = robot.joint_map['world-workobject']
        # workobject = robot.joint_map['workobject']

        tool = [tcp.origin.position,
                list(tf.quaternion_from_euler(*tcp.origin.rotation))]
        print ('Tool:', tool)
        workobject = [workobject.origin.position,
                      list(tf.quaternion_from_euler(*workobject.origin.rotation))]
        print ('Workobject:', workobject)
        if rospy.has_param('/powder'):
            powder = rospy.get_param('/powder')
        else:
            print ('/powder param missing, loaded default')
            powder = {'carrier': 5.0, 'shield': 10.0, 'stirrer': 20.0, 'turntable': 4.0}
        print ('Powder:', powder)
        if rospy.has_param('/process'):
            process = rospy.get_param('/process')
        else:
            print ('/process param missing, loaded default')
            process = {'focus': 0, 'power': 1000, 'speed': 8}
        print ('Process:', process)

        self.jason = Jason()
        self.jason.set_tool(tool)
        self.jason.set_workobject(workobject)
        self.jason.set_powder(
            powder['carrier'], powder['stirrer'], powder['turntable'])
        self.jason.set_process(process['speed'], process['power'])


        self.command_message = 0.0 # initial command message, 0 - idle
        self.is_path_load = False
        self.is_run_executed = False

        # -------- create a timer thread, to send (run) the command one by one
        self.tmrRunPath = QtCore.QTimer(self)
        self.tmrRunPath.timeout.connect(self.timeRunPathEvent)
        # self.tmrRunPath = perpetualTimer(0.1,self.timeRunPathEvent) # connect the timer object to the function, execute this function every 0.1s (100ms)

        # another timmer thread, to initiate the updates of the command, run the updateStatus to monitor the when should execute path planning
        tmrInfo = QtCore.QTimer(self)
        tmrInfo.timeout.connect(self.updateStatus)
        tmrInfo.start(100) # start execute the function every 100 ms


    def cbCommand(self, msg_mainCommand):
        self.command_message = msg_mainCommand.command
        
        
        
    def updateStatus(self):
        if self.command_message == 3.0:
            if not self.is_path_load:
                self.load_path()
            if not self.is_run_executed:
                self.run_path()
        else:  # scanning mode
            self.is_path_load = False
            self.is_run_executed = False


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

    # --------- load the whole path (Json file)--------------------------
    def load_path(self): 
        # filename = QtWidgets.QFileDialog.getOpenFileName(
        #     self, 'Load Path Routine', os.path.join(path, 'routines'),
        #     'Jason Routine Files (*.jas)')[0]
        # example: os.path.join(path, 'resources', 'command_list.ui')
        filename = os.path.join(path, 'routines', "raster_2_PROC_v2.jas")
        print ('Load routine:', filename)
        commands = self.jason.load_commands(filename)
        self.loadCommands(commands)
        self.is_path_load = True


    def run_path(self):
        """Start-Stop sending commands to robot from the list of commands."""
        if self.tmrRunPath.isActive():
            if not self.testing:
                self.tmrRunPath.cancel()
                # self.btnRunPath.setText('Run')
                icon = QtGui.QIcon.fromTheme('media-playback-start')
                # self.btnRunPath.setIcon(icon)
                # self.btnRunTest.setEnabled(True)
        else:
            # self.btnRunTest.setEnabled(False)
            self.sendCommand('{"reset_laser":1}')
            self.sendCommand('{"reset_powder":1}')
            self.sendCommand('{"reset_wire":1}')
            # self.btnRunPath.setText('Stop')
            icon = QtGui.QIcon.fromTheme('media-playback-stop')
            # self.btnRunPath.setIcon(icon)
            self.tmrRunPath.start(10)  # time in ms
            
        self.is_run_executed = True

   
   
    def run_step(self):
        n_row = self.listWidgetPoses.count()
        if n_row > 0:
            row = self.listWidgetPoses.currentRow()
            if row == -1:
                row = 0
            item_text = self.listWidgetPoses.item(row)
            #self.pub.publish(item_text.text())
            self.sendCommand(item_text.text())
            if len(self.ok_command.split()) == 0:
                self.invalid_command("No response command")
                return
            if len(self.ok_command.split()) == 1:
                if self.ok_command.split()[0] == "ERR_COMMAND":
                    self.invalid_command("Check the command name")
                    return
                if self.ok_command.split()[0] == "PARAM_ERROR":
                    self.invalid_command("Check the command parameters")
                    return
                if self.ok_command.split()[0] == "NOK":
                    self.invalid_command("Not a Json comand")
                    return
            if len(self.ok_command.split()) == 3:
                if self.ok_command.split()[2] == "BUFFER_FULL":
                    return
            row += 1
            if row == n_row:
                row = 0
            self.listWidgetPoses.setCurrentRow(row)

    def qlistDoubleClicked(self):
        row = self.listWidgetPoses.currentRow()
        item_text = self.listWidgetPoses.item(row)
        str_command = QtWidgets.QInputDialog.getText(
            self, "Load Jason Command", "Comamnd:", text=item_text.text())
        if len(str_command[0]) > 3:
            self.listWidgetPoses.takeItem(row)
            self.insertCommand(str_command[0], insert=True, position=row)

    def btnCancelClicked(self):
        self.sendCommand('{"reset_laser":1}')
        self.sendCommand('{"reset_powder":1}')
        self.sendCommand('{"reset_wire":1}')
        self.sendCommand('{"cancel":1}')
        if self.tmrRunPath.isActive():
            self.tmrRunPath.cancel()
            icon = QtGui.QIcon.fromTheme('media-playback-start')
            # self.btnRunPath.setText('Run')
            # self.btnRunTest.setText('Test')
            # self.btnRunPath.setIcon(icon)
            # self.btnRunTest.setIcon(icon)
            self.testing = False
            # self.btnRunTest.setEnabled(True)
            # self.btnRunPath.setEnabled(True)

    def getMoveCommands(self):                                               # may have bug
        n_row = self.listWidgetPoses.count()
        # row = self.listWidgetPoses.currentRow()
        path = []
        for row in range(n_row):
            item_text = self.listWidgetPoses.item(row)
            try:
                command = json.loads(item_text.text())
                if 'move' in command:
                    path.append(command['move'])
            except:
                log.info("Exception parsing comments json - not leaving comment")
                #return True

        self.path_markers.set_path(path)
        self.pub_marker_array.publish(self.path_markers.marker_array)

    def sendCommand(self, command):
        if self.testing:
            command = command.lower()
            command = command.replace(' ','')
            if command.lower().find('laserReady') == 2:
                return
            if command.lower().find('powder') == 2:
                return
            if command.lower().find('move') == 2:
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
            if len(self.ok_command.split()) == 3:
                if self.ok_command.split()[2] == "BUFFER_FULL":
                    return
            if len(self.ok_command.split()) == 1:
                if self.ok_command.split()[0] == "ERR_COMMAND":
                    if self.testing:
                        # self.btnRunTestClicked()
                        pass
                    else:
                        self.run_path()
                    self.invalid_command("Check the command name")
                    return
                if self.ok_command.split()[0] == "PARAM_ERROR":
                    if self.testing:
                        # self.btnRunTestClicked()
                        pass
                    else:
                        self.run_path()
                    self.invalid_command("Check the command parameters")
                    return
                if self.ok_command.split()[0] == "NOK":
                    if self.testing:
                        # self.btnRunTestClicked()
                        pass
                    else:
                        self.run_path()
                    self.invalid_command("Not a Json comand")
                    return
            if len(self.ok_command.split()) == 0:
                if self.testing:
                    # self.btnRunTestClicked()
                    pass
                else:
                    self.run_path()
                self.invalid_command("No response command")
                return
            row += 1
            if row == n_row:
                row = 0
                if self.testing:
                    self.btnRunTestClicked()
                    pass
                else:
                    self.run_path()
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


            
    


   
            
            
    


#if __name__ == "__main__":
    # rospy.init_node('json_command_panel')

    # app=QtWidgets.QApplication(sys.argv)
    # qt_path = JsonCommand()
    # qt_path.show()
    # qt_path.load_path()
    # qt_path.run_path()
    # app.exec_()


if __name__ == '__main__':
    try:
        app=QtWidgets.QApplication(sys.argv)
        qt_path = JsonCommand()
        qt_path.show()
        app.exec_()
    except rospy.ROSInterruptException:
        pass

