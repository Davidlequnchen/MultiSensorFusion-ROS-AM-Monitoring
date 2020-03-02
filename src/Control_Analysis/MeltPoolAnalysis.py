"""
This file reads melt pool minor axis data,
perform Fast fourer transform and visualize it

@author: Chen Lequn
"""
# from scipy import fft
from scipy.fftpack import fft, ifft, fftfreq, fftshift
import numpy as np
import os
import glob
from matplotlib.pyplot import specgram
import matplotlib.pyplot as plt
from matplotlib.pyplot import figure

import statistics
from scipy.stats import logistic
from scipy import signal
import scipy.signal
from scipy import fftpack

import pyfftw

# %matplotlib inline




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
    


class SignalProcessing():
    def __init__(self):
        # empty list to store filtered data after signal processing
        # data after FIR filtering       
        self.lfilter_data1 = []
        self.lfilter_data2 = []
        self.filtfilt = []
        self.sampling_rate = 10 # should be ROS topic rate, here we assume 10Hz



    def fir_filter(self, xn):
        # input: original data xn
        # reference: https://docs.scipy.org/doc/scipy/reference/generated/scipy.signal.lfilter.html
        # ------ FIR filter----------------------
        #Create an order 3 lowpass butterworth filter:
        b, a = signal.butter(3, 0.05)
        #Apply the filter to original data(input xn). Use lfilter_zi to choose the initial condition of the filter:
        zi = signal.lfilter_zi(b, a)
        self.lfilter_data1, _ = signal.lfilter(b, a, xn, zi=zi*xn[0])
        #Apply the filter again, to have a result filtered at an order the same as filtfilt:
        self.lfilter_data2, _ = signal.lfilter(b, a, self.lfilter_data1, zi=zi*self.lfilter_data1[0])

        #Use filtfilt to apply the filter:
        self.filtfilt = signal.filtfilt(b, a, xn)
        #------------------------- end of calculation, start visualization-----------
        
        
        font = {'family': 'serif',
            'color':  'darkred',
            'weight': 'normal',
            'size': 16,
            }

        #Plot the original signal and the various filtered versions:
        plt.figure(1,figsize=(18,8))

        plt.subplot(2, 1, 1)    
        plt.xlabel("Time stamp", fontdict=font)
        plt.ylabel("Major/Minor axis (pixel)", fontdict=font)
        plt.title('Plot of data filtering', fontdict=font)
        plt.grid(True)
        plt.plot(xn, 'b', alpha=0.75) # original data visualization
        plt.plot( self.lfilter_data1, 'r--', self.lfilter_data2, 'r', self.filtfilt, 'k')
        plt.legend(('noisy signal', 'lfilter, once', 'lfilter, twice',
                    'filtfilt'), loc='lower left')
        plt.subplots_adjust(left=0.2)
        #----------------------------------------
  
        plt.subplot(2,1,2)
        plt.xlabel("Time stamp", fontdict=font)
        plt.ylabel("Filtered data", fontdict=font)
        plt.title('Plot of data FIR filter result', fontdict=font)
        plt.grid(True)
        plt.plot(self.filtfilt, 'k')
        plt.legend(('filtfilt'),loc='best')
        plt.subplots_adjust(left=0.2)
        

        plt.tight_layout()
        plt.show()

    

    def create_fft(self, data):
    #     # this function perform fast fourier transform for input data
    #     # reference : https://docs.scipy.org/doc/scipy/reference/generated/scipy.fftpack.fft.html
    #     # step 1: fast fourier transform: Return discrete Fourier transform of real or complex sequence.
    #     # fft_transformed : complex ndarray, 
    #     # A[1:n/2] contains the positive-frequency terms, and A[n/2:] contains the negative-frequency terms, in order of decreasingly negative frequency. 
    #     fft_transformed = fft(data) 
    #     # step 2: fftshift: To rearrange the fft output so that the zero-frequency component is centered, like [-4, -3, -2, -1, 0, 1, 2, 3]
    #     centered_fft =  fftshift (fft_transformed)
    #     # frequency, fftfreq: Return the Discrete Fourier Transform sample frequencies.
    #     frequency = fftfreq (data)
    #     centered_frequency = fftshift (frequency)

    #     plt.figure(1, figsize=(18,5))
    #     plt.plot(centered_frequency, centered_fft.real, centered_frequency, centered_fft.imag)
    #     plt.legend("real", "imaginary")
    #     plt.xlabel("frequency")
    #     plt.ylabel("fast fourier transform")
    #     plt.show()


        plt.figure(figsize=(18,5))  
        Pxx, freqs, bins, im  = specgram(data, Fs = self.sampling_rate, Fc=0, xextent = (0,16))
        # The `specgram` method returns 4 objects. They are:
        # - Pxx: the periodogram
        # - freqs: the frequency vector
        # - bins: the centers of the time bins
        # - im: the matplotlib.image.AxesImage instance representing the data in the plot
        plt.xlabel('Time [s]')
        plt.ylabel('Frequency [kHz]')
        
        plt.show()


    def fast_fourier_transform(self,data):
        # API docs for pyFFTW: https://hgomersall.github.io/pyFFTW/sphinx/tutorial.html
        # length = len(data)
        # a = pyfftw.empty_aligned(length, dtype='complex128') # initialize a aligned array for 1 demensional fft
        # b = pyfftw.empty_aligned(length, dtype='complex128')

        # a = data # set input data
        
        # # fft_object = pyfftw.builders.fft (a) # create a fft object
        # # fft_result = fft_object()

        # scipy.fftpack = pyfftw.interfaces.scipy_fftpack
        # scipy.signal.fftconvolve(a, b) # We cheat a bit by doing the planning first

        # # Turn on the cache for optimum performance
        # pyfftw.interfaces.cache.enable()
        #---------------------------------------------------------
        # reference: https://www.oreilly.com/library/view/elegant-scipy/9781491922927/ch04.html
        f_s = 10 #sampling rate, number of measurements per second

        X = fftpack.fft(data)
        freqs = fftpack.fftfreq(len(data)) * f_s

        # fig, ax = plt.subplots()

        # ax.stem(freqs, np.abs(X))
        # ax.set_xlabel('Frequency in Hertz [Hz]')
        # ax.set_ylabel('Frequency Domain (Spectrum) Magnitude')
        # ax.set_xlim(-f_s / 2, f_s / 2)
        # ax.set_ylim(-5, 110)
        plt.figure(1, figsize=(18,8))
        plt.subplot(1, 1, 1)  #subplot(nrows, ncols, index, **kwargs)  
        plt.xlabel('Frequency in Hertz [Hz]')
        plt.ylabel('Frequency Domain (Spectrum) Magnitude')
        # plt.title('Plot of melt-pool minor/major axis', fontdict=font)
        plt.grid(True)
        # data_xi = list(range(len(data_x)))
        # reference https://matplotlib.org/2.1.1/api/_as_gen/matplotlib.plt.plot.html
        plt.plot(freqs, np.abs(X))
   
        # # generate legends   
        # plt.legend(('minor axis', 'major axis'),loc='best')
        plt.subplots_adjust(left=0.2)
        #-----------------------------
        
        
        
        
        
        
        
        plt.show()

        


        # # visualization---------------
        # plt.figure (figsize=(18,5))
        # plt.plot(b)
        # plt.show()





        










class MeltPoolAnalyzer():
    def __init__(self):
        # empty list to store the original data for time stamp and minor axis value
        self.time_stamp = []
        self.data_minoraxis = []
        self.data_majoraxis = []
        self.data_orientation = []

        # self.sampling_rate = 10 # should be ROS topic rate, here we assume 10Hz
        # self.statistical_analysis = StatisticalAnalysis()
        # self.signal_processing = SignalProcessing()
        


    def VisualizeData(self,time_stamp, minor_axis, major_axis, orientation):
        # visulization of minor axis, major axis, and orientation of the melt pool
        font = {'family': 'serif',
            'color':  'darkred',
            'weight': 'normal',
            'size': 16,
            }
        plt.figure(1, figsize=(18,8))


        plt.subplot(2, 1, 1)  #subplot(nrows, ncols, index, **kwargs)  
        plt.xlabel("Time stamp", fontdict=font)
        plt.ylabel("Major/Minor axis (pixel)", fontdict=font)
        plt.title('Plot of melt-pool minor/major axis', fontdict=font)
        plt.grid(True)
        # data_xi = list(range(len(data_x)))
        # reference https://matplotlib.org/2.1.1/api/_as_gen/matplotlib.plt.plot.html
        plt.plot(time_stamp, minor_axis , 'b-', time_stamp, major_axis, 'm-')
   
        # # generate legends   
        # first_legend = plt.legend(handles=[line1], loc='upper right')
        # # Add the legend manually to the current Axes.
        # ax = plt.gca().add_artist(first_legend)
        plt.legend(('minor axis', 'major axis'),loc='best')
        plt.subplots_adjust(left=0.2)
        #--------------------------------------------------------------------
        plt.subplot(2, 1, 2)
            
        plt.xlabel("Time stamp", fontdict=font)
        plt.ylabel("orientation (radians)", fontdict=font)
        plt.title('Plot of melt-pool orientation', fontdict=font)
        plt.grid(True)
        # data_xi = list(range(len(data_x)))
        
        # reference https://matplotlib.org/2.1.1/api/_as_gen/matplotlib.plt.plot.html
        plt.plot(time_stamp,orientation, label="orientation", linestyle='-')

        plt.legend() # generate legends   
        plt.subplots_adjust(left=0.2)

        plt.tight_layout()
        plt.show()


    
    
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
            self.data_majoraxis.append(float(line.split(',')[4]))
            self.data_orientation.append(float(line.split(',')[6]))
        f.close()



if __name__ == "__main__":
    analysis = MeltPoolAnalyzer()
    analysis.read_from_file("/home/chenlequn/SIMTech_ws/src/Data/MeltPool_Control_2020/meltpol_data_202028/10.txt")
    # visualize original data
    # analysis.VisualizeData(analysis.time_stamp, analysis.data_minoraxis)
    # analysis.VisualizeData(analysis.time_stamp, analysis.data_minoraxis, analysis.data_majoraxis, analysis.data_orientation)

    # signal processing
    signal_processing = SignalProcessing()
    # signal_processing.fir_filter(analysis.data_minoraxis)
    signal_processing.create_fft(analysis.data_minoraxis)
    signal_processing.fast_fourier_transform(analysis.data_minoraxis)

 