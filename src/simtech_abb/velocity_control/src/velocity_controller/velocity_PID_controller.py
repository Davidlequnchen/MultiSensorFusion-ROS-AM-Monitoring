
import yaml
import numpy as np
import rospy
import time

class ControlSet():
    def __init__(self):
        self.pid = PIDController()

    def load_conf(self, filename):
        with open(filename, 'r') as f:
            data = yaml.load(f)
        Kp = data['/speed_control_parameters/pid_parameters']['Kp']
        Ki = data['/speed_control_parameters/pid_parameters']['Ki']
        Kd = data['/speed_control_parameters/pid_parameters']['Kd']
        SpeedOverride_min = data['/speed_control_parameters/SpeedOverrideLimit']['min']
        SpeedOverride_max = data['/speed_control_parameters/SpeedOverrideLimit']['max']
        self.pid.set_parameters(Kp, Ki, Kd)
        self.pid.set_limits(SpeedOverride_min, SpeedOverride_max)
        return data

    def save_conf(self, filename):
        Kp, Ki, Kd = self.pid.Kp, self.pid.Ki, self.pid.Kd
        SpeedOverride_min, SpeedOverride_max = self.pid.SpeedOverride_min, self.pid.SpeedOverride_max
        data = dict(parameters=dict(Kp=Kp, Ki=Ki, Kd=Kd),
                    SpeedOverride=dict(min=SpeedOverride_min, max=SpeedOverride_max))
        with open(filename, 'w') as f:
            f.write(yaml.dump(data))
        return data

    def output(self, SpeedOverride):
        if SpeedOverride > self.pid.SpeedOverride_max:
            SpeedOverride = self.pid.SpeedOverride_max
        if SpeedOverride < self.pid.SpeedOverride_min:
            SpeedOverride = self.pid.SpeedOverride_min
        return SpeedOverride


class PIDController():
    def __init__(self):
        self.set_parameters(0.0, 0.0, 0.0)
        self.set_limits(0, 100)
        self.setpoint = 0.0
        self.error = 0.0
        self.time = None
        #self.output = 0.0
        self.output = rospy.get_param('/speed_control_parameters/CurrentSpeedOverride')['CurrentSpeedOverride']


    def set_setpoint(self, setpoint):
        self.setpoint = setpoint

    def set_parameters(self, Kp, Ki, Kd):
        self.Kp = Kp
        self.Ki = Ki
        self.Kd = Kd

    def set_limits(self, SpeedOverride_min, SpeedOverride_max):
        self.SpeedOverride_min = SpeedOverride_min
        self.SpeedOverride_max = SpeedOverride_max

    def SpeedOverride(self, value):
        self.time = None
        self.output = value
        return self.output

    def control_update(self, value, time):
        if self.time is None:
            output = self.output
            '''
        else:
            error = self.setpoint - value
            delta = time - self.time
            # this output is the delta value for output
            output = self.Kp * (error - self.error) + self.Ki * error * delta + self.Kd * (error - self.error) / delta
            if output > 55:
                output = 55
            if output < -55:
                output = -55
            output = self.output + output
            print 'P', self.Kp * (error - self.error), 'I', self.Ki * error * delta, 'D', self.Kd * (error - self.error) / delta
            self.error = error
            print 'SetPoint', self.setpoint, 'Value', value, 'Time', time
            print 'Delta time', delta, 'Error', error, 'Output', output
            if output > self.SpeedOverride_max:
                output = self.SpeedOverride_max
            if output < self.SpeedOverride_min:
                output = self.SpeedOverride_min
        self.time = time
        self.output = output
        return output
            '''

        elif value < self.setpoint - 0.1:
            self.output = self.SpeedOverride_max
        elif value > self.setpoint + 0.1:
            self.output = self.SpeedOverride_min
        else:
            self.output = rospy.get_param('/speed_control_parameters/CurrentSpeedOverride')['CurrentSpeedOverride']
        self.time = time
        return self.output



if __name__ == '__main__':
    filename = '../../config/velocity_control_parameters.yaml'
    control = ControlSet()
    control.save_conf(filename)
    print control.load_conf(filename)
