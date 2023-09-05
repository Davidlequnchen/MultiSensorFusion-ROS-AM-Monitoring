import numpy as np


class Jason():
    def __init__(self):
        self.tool = None
        self.workobject = None

        self.carrier = None
        self.stirrer = None
        self.turntable = None

        self.speed = None
        self.power = None

    def load_commands(self, filename):
        try:
            with open(filename, 'r') as f:
                cmds = [line.rstrip('\n') for line in f.readlines()]
        except IOError:
            cmds = []
        return cmds

    def save_commands(self, filename, cmds):
        try:
            with open(filename, 'w') as f:
                f.writelines('\n'.join(cmds))
        except IOError:
            pass

    def path2cmds(self, path):
        lens = np.array([len(point) for point in path])
        commands = []
        commands.append(self.tool)
        commands.append(self.workobject)
        if np.any(lens == 3):
            commands.append('{"laser": true}')
            commands.append(self.power)
            commands.append(self.carrier)
            commands.append(self.turntable)
            commands.append(self.stirrer)
            commands.append('{"speed": 50}')
            commands.append('{"move":[[-50, -50, 125], [1.0, 0.0, 0.0, 0.0]]}')
            commands.append('{"move":[[0, -25, 100], [1.0, 0.0, 0.0, 0.0]]}')
            commands.append('{"powder": true}')
            commands.append('{"wait": 1}')
            commands.append(self.speed)
            commands.extend([self.get_command_pose(pose) for pose in path])
            commands.append('{"speed": 50}')
            commands.append('{"move": [[-25, 0, 125], [1, 0, 0, 0]]}')
            commands.append('{"powder": false}')
            commands.append('{"move": [[-50, -50, 125], [1, 0, 0, 0]]}')
            commands.append('{"laser": false}')
        else:
            commands.append('{"speed": 10}')
            commands.append('{"move":[[-25, -50, 125], [1.0, 0.0, 0.0, 0.0]]}')
            commands.extend([self.get_command_pose(pose) for pose in path])
            commands.append('{"move":[[-25, -50, 125], [1.0, 0.0, 0.0, 0.0]]}')
        return commands

    def set_tool(self, tool):
        position = np.float32(tool[0])
        orientation = np.float32(tool[1])
        x, y, z = np.round(position * 1000, 1)
        qx, qy, qz, qw = orientation.round(4)
        self.tool = '{"tool": [[%.1f, %.1f, %.1f], [%.4f, %.4f, %.4f, %.4f]]}' % (x, y, z, qw, qx, qy, qz)

    def set_workobject(self, workobject):
        position = np.float32(workobject[0])
        orientation = np.float32(workobject[1])
        x, y, z = np.round(position * 1000, 1)
        qx, qy, qz, qw = orientation.round(4)
        self.workobject = '{"workobject": [[%.1f, %.1f, %.1f], [%.4f, %.4f, %.4f, %.4f]]}' % (x, y, z, qw, qx, qy, qz)

    def set_powder(self, carrier, stirrer, turntable):
        self.carrier = '{"carrier": %.1f}' % carrier
        self.stirrer = '{"stirrer": %.1f}' % stirrer
        self.turntable = '{"turntable": %.1f}' % turntable

    def set_process(self, speed, power):
        self.speed = '{"speed": %.1f}' % speed
        self.power = '{"power": %.1f}' % power

    def get_command_pose(self, pose):
        x, y, z = np.float32(pose[0]).round(1)
        qx, qy, qz, qw = np.float32(pose[1]).round(4)
        if len(pose) == 3:
            laser = pose[2]
            if laser:
                cmd = '{"move": [[%.1f, %.1f, %.1f], [%.4f, %.4f, %.4f, %.4f], true]}' %(x, y, z, qw, qx, qy, qz)
            else:
                cmd = '{"move": [[%.1f, %.1f, %.1f], [%.4f, %.4f, %.4f, %.4f], false]}' %(x, y, z, qw, qx, qy, qz)
        else:
            cmd = '{"move": [[%.1f, %.1f, %.1f], [%.4f, %.4f, %.4f, %.4f]]}' %(x, y, z, qw, qx, qy, qz)
        return cmd

    def get_reset_commands(self):
        commands = ['{"reset_laser":1}',
                    '{"reset_powder":1}',
                    '{"reset_wire":1}']
        return commands

    def get_cancel_commands(self):
        commands = ['{"reset_laser":1}',
                    '{"reset_powder":1}',
                    '{"reset_wire":1}',
                    '{"cancel":1}']
        return commands


if __name__ == '__main__':
    routine = Jason()
    path = [[[800, 0, 800], [0, 0, 0, 1]],
            [[1000, 0, 800], [0, 0, 0, 1]],
            [[1000, 0, 1000], [0, 0, 0, 1]]]
    filename = '../../routines/proper.jas'
    routine.set_tool([[215.7, -22.4, 473.8], [0.5, 0.0, -0.8660254, 0.0]])
    routine.set_workobject([[1655, -87, 932], [1, 0, 0, 0]])
    routine.set_powder(3, 20, 20)
    routine.set_process(8, 1000)
    cmds = routine.path2cmds(path)
    routine.save_commands(filename, cmds)
    print(cmds)
