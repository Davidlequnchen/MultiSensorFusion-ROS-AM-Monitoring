#!/usr/bin/env python3
import json
import rospy

from simtech_robot_laser_control.srv import SrvRobotCommand
from simtech_robot_laser_control.srv import SrvRobotCommandResponse

from abb_controller.server_robot import ServerRobot
'''
This node 'robot_service_server' is a server. It creates the 'robot_service_server' ROS service,
listen to the jason command to be loaded, and process the command by call back function 'cb_robot_command'.
'server_robot' is a client socket, it connects to the robot controller(server).
The ServerRobot will try to send request(command) to the server(Laser and robot), then the robot controller
will execute the command.

In rospy, you provide a Service by creating a rospy.Service instance with a callback to invoke when new requests are received.
Each inbound request is handled in its own thread, so services must be thread-safe.
'''


class NdRobotServer():
    def __init__(self):
        rospy.init_node('robot_service_server', anonymous=False)

        # create a service called 'robot_send_command'
        self.service = rospy.Service(
            'robot_send_command', SrvRobotCommand, self.cb_robot_command)

        robot_ip = rospy.get_param('~robot_ip', '192.168.125.1')
        laser_type = rospy.get_param('~laser_type', 'ipg')
        feeder_type = rospy.get_param('~feeder_type', 'powder')
        self.server_robot = ServerRobot()
        self.server_robot.connect(robot_ip)
        print (self.server_robot.set_laser_type(laser_type))
        print (self.server_robot.set_feeder_type(feeder_type))

        rospy.on_shutdown(self.server_robot.disconnect)
        rospy.spin()

    def cb_robot_command(self, data):
        rospy.loginfo(rospy.get_caller_id() + " I heard %s", data.command)
        try:
            command = json.loads(data.command.lower()) # convert to lower case charactor
            if 'get_pose' in command:
                pose_rob = self.process_command(command)
                return SrvRobotCommandResponse(str(pose_rob))
            response = self.process_command(command)
            return SrvRobotCommandResponse(response)
        except ValueError, e:
            print ("Command is not json", e)
            return SrvRobotCommandResponse("NOK")

    def process_command(self, command):
        for cmd in sorted(command, reverse=True):
            if cmd == 'tool':
                return self.server_robot.SetTool(command[cmd])
            elif cmd == 'workobject':
                return self.server_robot.workobject(command[cmd])
            elif cmd == 'speed':
                return self.server_robot.speed(command[cmd])
            elif cmd == 'move':
                return self.server_robot.move(command[cmd])
            elif cmd == 'movej':
                return self.server_robot.move(command[cmd], movel=False)
            elif cmd == 'move_ext':
                return self.server_robot.move_ext(command[cmd])
            elif cmd == 'get_pose':
                return self.server_robot.get_pose()
            elif cmd == 'wait':
                return self.server_robot.wait(command[cmd])
            elif cmd == 'program':
                return self.server_robot.set_group((command[cmd], 0))  # laser program 11
            elif cmd == 'laserready':
                return self.server_robot.laser_ready(command[cmd])
            elif cmd == 'laseremission':
                return self.server_robot.laser_emission(command[cmd])
            elif cmd == 'set_zone_manual':
                return self.server_robot.zone(command[cmd])      # set_zone manually [x,y,z]
            elif cmd == 'set_zone':
                return self.server_robot.zone_set(command[cmd])      # set_zone z0 or fine
            elif cmd == 'setpower':
                return self.server_robot.laser_power(command[cmd])
            
            elif cmd == 'motion_complete':
                return self.server_robot.set_motion_complete(command[cmd])

            elif cmd == 'wire':
                return self.server_robot.wire_set(command[cmd])
            elif cmd == 'powder':
                return self.server_robot.powder(command[cmd])
            elif cmd == 'carrier':
                return self.server_robot.carrier(command[cmd])
            elif cmd == 'turntable':
                return self.server_robot.turntable(command[cmd])
            elif cmd == 'stirrer':
                stirrer = int((command[cmd] * 100) / 100)
                return '0 0'

            elif cmd == 'cancel':
                return self.server_robot.cancel()
            elif cmd == 'reset_laser':
                return self.server_robot.reset_laser()
            elif cmd == 'reset_powder':
                return self.server_robot.reset_powder()
            elif cmd == 'reset_wire':
                return self.server_robot.reset_wire()
            else:
                return 'ERR_COMMAND'
                print ('Unknown command:', cmd)


if __name__ == '__main__':
    try:
        NdRobotServer()
    except rospy.ROSInterruptException:
        pass
