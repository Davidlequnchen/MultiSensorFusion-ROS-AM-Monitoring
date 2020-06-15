import numpy as np
import math

class Velocity():
    def __init__(self):
        self.len = 1
        self.times = []
        self.acceleration_time = []
        self.twist_acceleration_time = []
        self.positions = []
        self.speed = []
        self.twist_speed = []

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
    
    
    def acceleration(self, time, speed):
        if len(self.speed) < self.len:
            acceleration = 0
        else:     
            acceleration = (speed - self.speed.pop()) / (time - self.acceleration_time.pop())
            
        self.acceleration_time.insert(0, time)
        self.speed.insert(0, speed)
        return np.around(acceleration, decimals=5)
    
    
    def twist_acceleration(self, time, twist_speed):
        if len(self.twist_speed) < self.len:
            twist_acceleration = 0
        else:     
            twist_acceleration = (twist_speed - self.twist_speed.pop()) / (time - self.twist_acceleration_time.pop())
            
        self.twist_acceleration_time.insert(0, time)
        self.twist_speed.insert(0, twist_speed)
        return np.around(twist_acceleration, decimals=5)
            
            
            

    def truncate(self, f, n):
        return math.floor(f * (10 ** n)) / (10 ** n)

    '''
    >>> f=1.923328437452
    >>> [truncate(f, n) for n in range(7)]
    [1.0, 1.9, 1.92, 1.923, 1.9233, 1.92332, 1.923328]
    '''


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
