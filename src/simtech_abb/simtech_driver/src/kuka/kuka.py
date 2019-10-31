'''
kuka.py: contains classes and support functions which interact with an KUKA Robot
 running our software stack (KRL code module SERVER)


For functions which require targets (XYZ positions with quaternion
orientation), targets can be passed as [[XYZ], [Quats]] OR [XYZ, Quats]

'''

import socket
from collections import deque
import logging
from struct import *

log = logging.getLogger(__name__)
log.addHandler(logging.NullHandler())


class Robot:
    def __init__(self):
        self.control = True
        self.delay = .08

    def connect_logger(self, remote, maxlen=10):
        self.pose = deque(maxlen=maxlen)
        self.joints = deque(maxlen=maxlen)
        self.float_joints = deque(maxlen=maxlen)

        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.s.connect(remote)
        self.s.setblocking(1)

    def read_raw_logger(self):
        '''Unpack data from xml file'''
