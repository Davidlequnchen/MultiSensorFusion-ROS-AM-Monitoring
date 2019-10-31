import numpy as np


class Velocity():
    def __init__(self):
        self.len = 10
        self.times = []
        self.positions = []

    def instantaneous(self, time, position):
        if len(self.positions) < self.len:
            vel = np.array([0, 0, 0])
            speed = 0
        else:
            vel = (position - self.positions.pop()) / (time - self.times.pop())
            speed = np.sqrt(np.sum(vel * vel))
        self.times.insert(0, time)
        self.positions.insert(0, position)
        return np.around(speed, decimals=4), np.around(vel, decimals=5)


if __name__ == '__main__':
    t1 = 1448535428.73
    p1 = np.array([1.64148, 0.043086, 0.944961])
    q1 = np.array([0.00566804, 0.000861386, -0.0100175, 0.999933])

    t2 = 1448535428.75
    p2 = np.array([1.64148, 0.043865, 0.944964])
    q2 = np.array([0.00566161, 0.000860593, -0.0100132, 0.999933])

    t3 = 1448535429.22
    p3 = np.array([1.64148, 0.047131, 0.944964])
    q3 = np.array([0.00566494, 0.000858606, -0.0100118, 0.999933])

    velocity = Velocity()
    speed, vector = velocity.instantaneous(t1, p1)
    print "First:", vector
    speed, vector = velocity.instantaneous(t2, p2)
    print "Second:", vector
    speed, vector = velocity.instantaneous(t3, p3)
    print "Third:", vector
