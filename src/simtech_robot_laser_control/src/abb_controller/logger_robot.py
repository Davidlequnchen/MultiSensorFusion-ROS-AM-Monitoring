import socket
from abb_controller.abb_robot import Robot


class LoggerRobot(Robot):
    def __init__(self):
        #self.robot = abb.Robot()
        Robot.__init__(self)

    def connect(self, ip):
        self.control = True
        self.connect_logger((ip, 11002))

    def disconnect(self):
        self.s.shutdown(socket.SHUT_RDWR)


if __name__ == '__main__':
    logger_robot = LoggerRobot()
    logger_robot.connect('192.168.125.1')
    logger_robot.disconnect()
