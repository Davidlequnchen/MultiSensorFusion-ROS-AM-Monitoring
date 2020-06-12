#!/usr/bin/env python
import sys
import rospy
import numpy as np

from python_qt_binding import QtGui
from python_qt_binding import QtCore

from matplotlib.figure import Figure
from matplotlib.backends.backend_qt4agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib import gridspec
from matplotlib.lines import Line2D

from mashes_measures.msg import MsgGeometry
from cladplus_control.msg import MsgPower

from measures.filter import Filter


class QtPlot(QtGui.QWidget):
    def __init__(self, parent=None):
        super(QtPlot, self).__init__(parent)

        layout = QtGui.QHBoxLayout()
        layout.setContentsMargins(1, 1, 1, 1)
        self.setLayout(layout)

        self.fig = Figure(figsize=(9, 6), dpi=72, facecolor=(0.76, 0.78, 0.8),
                          edgecolor=(0.1, 0.1, 0.1), linewidth=2)
        self.canvas = FigureCanvas(self.fig)
        layout.addWidget(self.canvas)

        gs = gridspec.GridSpec(2, 1, wspace=0.05, hspace=0.05)
        gs.update(left=0.05, right=0.95, bottom=0.05, top=0.85)
        self.ax1 = self.fig.add_subplot(gs[0, 0])
        self.ax2 = self.fig.add_subplot(gs[1, 0])

        self.min_meas, self.max_meas = 0, 5
        self.min_power, self.max_power = 0, 1500

        self.time = 0
        self.duration = 8
        self.buff_max = 2000
        self.reset_data()

        self.line_width = Line2D(
            self.wtime, self.width, color='b', linewidth=2, animated=True)
        self.text_width = self.ax1.text(
            self.duration-10, 0, '', size=13, ha='right', va='center',
            backgroundcolor='w', color='b', animated=True)
        self.ax1.add_line(self.line_width)

        self.line_power = Line2D(
            self.ptime, self.power, color='r', linewidth=2, animated=True)
        self.text_power = self.ax2.text(
            self.duration-10, 0, '', size=13, ha='right', va='center',
            backgroundcolor='w', color='r', animated=True)
        self.ax2.add_line(self.line_power)

        self.draw_figure()

        rospy.Subscriber('/tachyon/geometry', MsgGeometry, self.cbMeasures)
        rospy.Subscriber('/control/power', MsgPower, self.cbPower)

        tmrMeasures = QtCore.QTimer(self)
        tmrMeasures.timeout.connect(self.timeMeasuresEvent)
        tmrMeasures.start(100)

    def reset_data(self):
        self.width = []
        self.wtime = []
        self.wdistance = 0
        self.width_filter = Filter()
        self.power = []
        self.ptime = []
        self.pdistance = 0
        self.power_filter = Filter()

    def draw_figure(self):
        self.ax1.cla()
        self.ax1.set_title('Melt Pool Measures')

        self.ax1.set_xlim(0, self.duration)
        self.ax1.get_xaxis().set_ticklabels([])
        self.ax1.set_ylabel('Measures (mm)')
        self.ax1.set_ylim(self.min_meas, self.max_meas)
        self.ax1.get_yaxis().set_ticklabels([])
        self.ax1.grid(True)

        self.ax2.set_xlabel('Time (s)')
        self.ax2.set_xlim(0, self.duration)
        self.ax2.get_xaxis().set_ticklabels([])
        self.ax2.set_ylabel('Power (W)')
        self.ax2.set_ylim(self.min_power, self.max_power)
        self.ax2.get_yaxis().set_ticklabels([])
        self.ax2.grid(True)

        self.canvas.draw()

        self.figbackground = self.canvas.copy_from_bbox(self.fig.bbox)
        self.background1 = self.canvas.copy_from_bbox(self.ax1.bbox)
        self.background2 = self.canvas.copy_from_bbox(self.ax2.bbox)

    def resizeEvent(self, event):
        self.figbackground = None
        self.background1 = None
        self.background2 = None

    def _limited_range(self, value, min_value, max_value):
        if value < min_value:
            value = min_value
        elif value > max_value:
            value = max_value
        return value

    def updateWidthMean(self):
        width_mean = np.round(self.width_filter.update(
            self.width[-1], self.wtime[-1]), 1)
        self.text_width.set_text('%.1f' % width_mean)
        self.text_width.set_y(self._limited_range(width_mean, 0.5, 4.5))
        self.text_width.set_x(0.98 * self.duration)

    def cbMeasures(self, msg_geometry):
        time = msg_geometry.header.stamp.to_sec()
        width = msg_geometry.minor_axis
        if self.time == 0 or self.time > time:
            self.time = time
            self.reset_data()
        if time-self.time > self.duration:
            self.wdistance = time-self.time-self.duration
        self.wtime.append(time-self.time)
        self.width.append(width)
        if len(self.width) > self.buff_max:
            self.wtime = self.wtime[-self.buff_max:]
            self.width = self.width[-self.buff_max:]
        self.line_width.set_data(
            np.array(self.wtime)-self.wdistance, np.array(self.width))
        self.updateWidthMean()

    def updatePowerMean(self):
        power_mean = np.round(
            self.power_filter.update(self.power[-1], self.ptime[-1]), 0)
        self.text_power.set_text('%.0f W' % power_mean)
        self.text_power.set_y(self._limited_range(power_mean, 100, 1400))
        self.text_power.set_x(0.98 * self.duration)

    def cbPower(self, msg_power):
        time = msg_power.header.stamp.to_sec()
        power = msg_power.value
        if self.time == 0 or self.time > time:
            self.time = time
            self.reset_data()
        if time-self.time > self.duration:
            self.wdistance = time-self.time-self.duration
        self.ptime.append(time-self.time)
        self.power.append(power)
        if len(self.power) > self.buff_max:
            self.ptime = self.ptime[-self.buff_max:]
            self.power = self.power[-self.buff_max:]
        self.line_power.set_data(
            np.array(self.ptime)-self.wdistance, np.array(self.power))
        self.updatePowerMean()

    def timeMeasuresEvent(self):
        if self.figbackground == None or self.background1 == None or self.background2 == None:
            self.draw_figure()
        self.canvas.restore_region(self.figbackground)
        self.canvas.restore_region(self.background1)
        self.ax1.draw_artist(self.line_width)
        self.ax1.draw_artist(self.text_width)
        self.canvas.blit(self.ax1.bbox)
        self.canvas.restore_region(self.background2)
        self.ax2.draw_artist(self.line_power)
        self.ax2.draw_artist(self.text_power)
        self.canvas.blit(self.ax2.bbox)


if __name__ == "__main__":
    rospy.init_node('plot')

    app = QtGui.QApplication(sys.argv)
    qt_plot = QtPlot()
    qt_plot.show()
    app.exec_()
