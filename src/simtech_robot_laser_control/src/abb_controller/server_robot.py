from abb import Robot


class ServerRobot(Robot):
    def __init__(self):
        Robot.__init__(self)
        self.instructionCount = 0
        self.laser = 'ipg'

    def connect(self, ip):
        self.connect_motion((ip, 11000))
        self.set_units('millimeters', 'degrees')
        self.set_tool()
        self.set_workobject()
        self.set_speed()
        self.set_zone()

    def set_laser_type(self, laser_type):
        self.laser = laser_type.lower()
        if self.laser == 'ipg':
            return self.configure_laser(0)
        else:
            return self.configure_laser(1)

    def set_feeder_type(self, feeder_type):
        self.feeder = feeder_type.lower()
        if self.feeder == 'powder':
            return self.configure_feeder(0)
        else:
            return self.configure_feeder(1)

    def disconnect(self):
        self.close()

    def SetTool(self, tool_obj):
        return self.set_tool(tool_obj)

    def workobject(self, work_obj):
        return self.set_workobject(work_obj)

    # def configure(self, filename):
    #     print filename

    def move(self, pose, movel=True):
        """Linear movement to cartestian coordiantes when movel=True."""
        if len(pose) == 2:
            return self.set_cartesian(pose, linear=movel)
        elif len(pose) == 3:
            return self.set_cartesian_trigg(pose[:2], trigger=pose[2])
        else:
            print 'Invalid command format'
            return ''

    def move_ext(self, dato):
        """Move external axis (axis, position, speed)."""
        if len(dato) == 3:
            return self.move_ext_axis(dato[0], dato[1], dato[2])
        else:
            print 'Invalid command format'
            return ''

    def speed(self, speed):
        return self.set_speed([speed, 50, 50, 100])

    def zone(self, zone):
        if len(zone) == 3:
            return self.set_zone(manual_zone=zone)
        else:
            print 'Invalid command format'
            return ''

    def zone_set(self, zone):
        if zone == "fine":
            return self.zone_choice(1)
        elif zone == "z0":
            return self.zone_choice(0)
        else:
            print 'Invalid zone choice command'
            return ''

    def get_pose(self):
        return self.get_cartesian()

    def wait(self, time):
        return self.wait_time(time)

    def set_digital(self, digital):
        """
        Dato digital 0 = Valor
        Dato digital 1 = Numero de salida
        """
        if len(digital) == 2:
            return self.set_dio(digital[0], digital[1])
        else:
            print 'Invalid command format'
            return ''

    def force_digital(self, digital):
        """
        Dato digital 0 = Valor
        Dato digital 1 = Numero de salida
        """
        if len(digital) == 2:
            return self.force_dio(digital[0], digital[1])
        else:
            print 'Invalid command format'
            return ''

    def set_analog(self, analog):
        """
        Dato analogico 0 = Valor
        Dato analogico 1 = Numero de salida
        """
        if len(analog) == 2:
            analog = list(analog)
            if analog[0] > 100:
                analog[0] = 100
            return self.set_ao(analog[0], analog[1])
        else:
            print 'Invalid command format'
            return ''

    def force_analog(self, analog):
        """
        Dato analogico 0 = Valor
        Dato analogico 1 = Numero de salida
        """
        if len(analog) == 2:
            analog = list(analog)
            if analog[0] > 100:
                analog[0] = 100
            return self.force_ao(analog[0], analog[1])
        else:
            print 'Invalid command format'
            return ''

    def set_group(self, digital):
        if len(digital) == 2:
            if (type(digital[0]) == int) and (type(digital[1]) == int):
                digital = list(digital)
                if digital[1] == 0:
                    if digital[0] > 31:
                        digital[0] = 31
                if digital[1] == 1:
                    if digital[0] > 65535:
                        digital[0] = 65535
                return self.set_gdo(digital[0], digital[1])
        else:
            print 'Invalid command format'
            return ''

    def force_group(self, digital):
        if len(digital) == 2:
            if (type(digital[0]) == int) and (type(digital[1]) == int):
                digital = list(digital)
                if digital[1] == 0:
                    if digital[0] > 31:
                        digital[0] = 31
                if digital[1] == 1:
                    if digital[0] > 65535:
                        digital[0] = 65535
                return self.force_gdo(digital[0], digital[1])
        else:
            print 'Invalid command format'
            return ''

    def laser_ready_fl015(self, ready):
        if ready:
            if self.instructionCount == 0:
                r = self.set_digital((1, 2))  # laser_main: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 1:
                r = self.set_digital((1, 3))  # laser_standby: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 2:
                r = self.wait_input(1, 0)  # wait_standby: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 3:
                r = self.wait_input(0, 1)  # wait_generalfault: 0
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount = 0
                return r
        else:
            return self.set_digital((0, 3))  # laser_standby: 0

    def laser_ready_trudisk(self, ready):
        if ready:
            if self.instructionCount == 0:
                r = self.set_digital((1, 15))  # TdoExtActiv: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 1:
                r = self.wait_input(1, 2)  # TdiExtActiv: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 2:
                r = self.set_digital((1, 14))  # TdoLaserOn: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 3:
                r = self.wait_input(1, 3)  # TdiLaserOn: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 4:
                r = self.set_digital((1, 16))  # TdoStandBy: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 5:
                r = self.set_digital((1, 17))  # TdoActLaser: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 6:
                r = self.set_group((28, 3))  # TGOPROGRAM_No: 100
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 7:
                r = self.wait_input(1, 4)  # TdiLaserAsig: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 8:
                r = self.wait_input(1, 5)  # TdiLaserReady: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
        else:
            if self.instructionCount == 0:
                r = self.set_digital((0, 17))  # TdoActLaser: 0
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 1:
                r = self.set_digital((0, 16))  # TdoStandBy: 0
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 2:
                r = self.set_digital((0, 14))  # TdoLaserOn: 0
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 3:
                r = self.set_digital((0, 15))  # TdoExtActiv: 0
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r

        



    def laser_ready(self, ready):                                     ############20191021
        '''
        if self.laser == 'rofin':
            return self.laser_ready_fl015(ready)
        else:
            return self.laser_ready_trudisk(ready)
        '''
        return self.laser_ready_ipg(ready)


    def laser_emission(self, start_emission):
        return self.laser_emission_ipg(start_emission)


    def set_motion_complete(self, motion):
        return self.json_motion_complete(motion)





    def laser_power(self, power):
        
        if self.laser == 'rofin':
            self.set_group((11, 0))  # laser program 11
            pwr = int((power * 65535) / 1500)  # digital value
            return self.set_group((pwr, 1))  # laser power
        

    def wire_set(self, state):
        if state:
            if self.instructionCount == 0:
                r = self.set_digital((1, 7))  # doTPSReset: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 1:
                r = self.wait_time(0.5)
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 2:
                r = self.set_digital((0, 7))  # doTPSReset: 0
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 3:
                r = self.set_digital((1, 8))  # doTPSReady: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 4:
                r = self.set_digital((1, 9))  # doTPSOP0: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 5:
                r = self.set_digital((0, 10))  # doTPSOP1: 0
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 6:
                r = self.set_digital((1, 11))  # doTPSOP2: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 7:
                r = self.set_group((100, 2))  # GoTPSJobL: 100
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount = 0
                return r
        else:
            r = self.set_digital((0, 8))  # doTPSReady: 0
            return r

    def powder(self, state):
        if state:
            if self.instructionCount == 0:
                r = self.set_digital((1, 4))  # weldgas: 1
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 1:
                r = self.set_digital((0, 1))  # gtv_stop
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 2:
                r = self.set_digital((1, 0))  # gtv_start
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount = 0
                return r
        else:
            if self.instructionCount == 0:
                r = self.set_digital((1, 1))  # gtv_stop
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 1:
                r = self.set_digital((0, 0))  # gtv_start
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount += 1
                else:
                    return r
            if self.instructionCount == 2:
                r = self.set_digital((0, 4))  # weldgas: 0
                if r.split()[2] == 'BUFFER_OK':
                    self.instructionCount = 0
                return r

    def carrier(self, carrierflow):
        if self.feeder == 'powder':
            carrier = int((carrierflow * 100) / 15)  # digital value
            return self.set_analog((carrier, 1))  # gtv_massflow

    def turntable(self, turntablespeed):
        if self.feeder == 'powder':
            turntable = int((turntablespeed * 100) / 10)  # digital value
            return self.set_analog((turntable, 0))  # gtv_disk

    def cancel(self):
        return self.cancel_motion()

    def reset_laser(self):
        return self.r_laser()

    def reset_powder(self):
        if self.feeder == 'powder':
            return self.r_powder()

    def reset_wire(self):
        if self.feeder == 'wire':
            return self.r_wire()


if __name__ == '__main__':
    server_robot = ServerRobot()
    server_robot.connect('192.168.125.1')
    # server_robot.workobject([[1.655, -0.087, 0.932], [1, 0, 0, 0]])
    # server_robot.tool([[0.216, -0.022, 0.474], [0.5, 0, -0.866025, 0]])
    # server_robot.speed(50)
    # server_robot.move([[1000, 0, 1000], [0, 0, 1, 0]])
    # server_robot.speed(100)
    # server_robot.move([[900, 0, 900], [0, 0, 1, 0]])
    # server_robot.load_file('puntos.txt')
    server_robot.set_digital(1)
    server_robot.set_analog(50)
    server_robot.disconnect()
