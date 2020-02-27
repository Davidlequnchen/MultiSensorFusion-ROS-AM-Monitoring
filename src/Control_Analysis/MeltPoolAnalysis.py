"""
This file reads melt pool minor axis data,
perform Fast fourer transform and visualize it

@author: Chen Lequn
"""
from scipy.io import wavfile
from scipy import fft
import numpy as np
import os
import glob
from matplotlib.pyplot import specgram
from matplotlib import pyplot
from matplotlib.pyplot import figure

import statistics
from scipy.stats import logistic
# from scipy.stats import 

class StatisticalAnalysis():
    def __init__ (self):
        self.minor_axis_mean = []
        self.minor_axis_median = []
        self.minor_axis_std = []
        self.minor_axis_mode = []
        self.minor_axis_pvariance = []
        self.minor_axis_variance = []

    def data_analysis (self,data):
        # reference: https://www.geeksforgeeks.org/python-statistics-variance/
        # reference https://docs.scipy.org/doc/scipy/reference/stats.html

        self.minor_axis_mean = statistics.mean(data) # average value  (arithmetic mean)
        self.minor_axis_median = statistics.median (data) # the middle value
        self.minor_axis_std = statistics.stdev(data)
        self.minor_axis_mode = statistics.mode(data)# the number appears most frequent
        # self.minor_axis_harmonic_mean = statistics.harmonic_mean(data) # only works for python3
        self.minor_axis_pvariance = statistics.pvariance(data) #calculate the variance of an entire population.
        self.minor_axis_variance = statistics.variance(data) #squared deviation of a variable from its mean. statistics.variance(sample, xbar = m)



class MeltPoolAnalyzer():
    def __init__(self):
        # empty list to store the data for time stamp and minor axis value
        self.time_stamp = []
        self.data_minoraxis = []
        self.sampling_rate = 10 # should be ROS topic rate, here we assume 10Hz
        self.statistical_analysis = StatisticalAnalysis()

    # @staticmethod
    def VisualizeData(self, data_x, data_y):
        font = {'family': 'serif',
            'color':  'darkred',
            'weight': 'normal',
            'size': 16,
            }

        self.statistical_analysis.data_analysis (data_y) # calculate several statistical identity
        self.mean = self.statistical_analysis.minor_axis_mean
    
        pyplot.figure(1, figsize=(14,5))    
        pyplot.xlabel("Time stamp", fontdict=font)
        pyplot.ylabel("Minor Axis (pixels)", fontdict=font)
        pyplot.title('Plot of melt-pool minor axis', fontdict=font)
        data_xi = list(range(len(data_x)))
        
        
        pyplot.plot(data_xi, data_y, label='minor_axis')
        pyplot.plot(self.mean,"r-h")

        # pyplot.angle_spectrum(data_y, Fs=2, Fc=0, 
        #          pad_to=None, sides='default')
        pyplot.legend() # generate legends   
        pyplot.subplots_adjust(left=0.2)
        pyplot.show()
    

    def create_fft(self):
        # this function perform fast fourier transform for input data
        X = self.data_minoraxis
        fft_features = abs(fft(X)[:1000])
        # fft_features = abs(fft(X)[:1000])
        # base_fn, ext = os.path.splitext(fn)
        # data_fn = base_fn + ".fft"
        # np.save(data_fn, fft_features)
        # print data_fn
        pyplot.figure(figsize=(14,5))  
        Pxx, freqs, bins, im  = specgram(X, Fs = self.sampling_rate, Fc=0, xextent = (0,16))
        # The `specgram` method returns 4 objects. They are:
        # - Pxx: the periodogram
        # - freqs: the frequency vector
        # - bins: the centers of the time bins
        # - im: the matplotlib.image.AxesImage instance representing the data in the plot
        pyplot.show()

    
    
    def read_from_file(self, filename):
        '''
        read the text file stores rostopic /usb_cam/geomerty,
         extract values of time and minor_axis and store to a list
        '''
        
        f = open(filename,"r") # open the file and read
        lines = f.readlines()[1:]   # read each lines, we neet to skip the 1st line since it's headers, not data
        # loop to extract time and minor axis data in each line, append them to the list
        for line in lines:

            # note: we need change the value from string to float
            self.time_stamp.append(float(line.split(',')[2])) # the third element is time
            self.data_minoraxis.append(float(line.split(',')[5])) # the sixth element is minor axis
        f.close()



if __name__ == "__main__":
    analysis = MeltPoolAnalyzer()
    analysis.read_from_file("/home/chenlequn/SIMTech_ws/src/Control_Analysis/test.txt")
    analysis.VisualizeData(analysis.time_stamp, analysis.data_minoraxis)
    # analysis.VisualizeData(analysis.data_minoraxis)
    # print analysis.data_minoraxis
    analysis.create_fft()

 