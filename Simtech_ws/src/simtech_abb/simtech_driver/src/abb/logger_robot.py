import socket
from abb import Robot


class LoggerRobot(Robot):
    def __init__(self):
        #self.robot = abb.Robot()
        Robot.__init__(self)

    def connect(self, ip):
        self.control = True
        self.connect_logger((ip, 5001))

    def disconnect(self):
        self.s.shutdown(socket.SHUT_RDWR)


if __name__ == '__main__':
    logger_robot = LoggerRobot()
    logger_robot.connect('172.20.0.32')
    logger_robot.disconnect()
