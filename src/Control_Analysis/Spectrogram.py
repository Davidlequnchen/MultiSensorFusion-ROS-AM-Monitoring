# -*- coding: utf-8 -*-
"""
Created on Sun Mar 30 19:14:25 2014

@author: Rahul
"""
from scipy.io import wavfile
from scipy import fft
import numpy as np
import os
import glob
from matplotlib.pyplot import specgram

def create_fft(fn):
    sample_rate, X = wavfile.read(fn)
    print sample_rate, X.shape
    fft_features = abs(fft(X)[:1000])
    base_fn, ext = os.path.splitext(fn)
    data_fn = base_fn + ".fft"
    np.save(data_fn, fft_features)
    print data_fn
    #specgram(X, Fs = sample_rate, xextent = (0,10))

genre_dir = "D:\Anaconda\BuildingMLSysWithPy\MusicClassifier"
genre_list = ["classical", "metal"]
def read_fft(genre_list, base_dir =  genre_dir ):
    X = []
    y = []
    for label, genre in enumerate(genre_list):
        genre_dir = os.path.join(base_dir, genre, "*.fft.npy")
        file_list = glob.glob(genre_dir)
        for fn in file_list:
            fft_features = np.load(fn)
            X.append(fft_features[:1000])
            y.append(label)
            print "Reached end of read fft"
    return np.array(X), np.array(y)

#for song in glob.glob('classical//*.wav'):
#    fn = song
#    print fn    
#    create_fft(fn)
    
#for song in glob.glob('metal//*.wav'):
#    fn = song
#    print fn    
#    create_fft(fn)

X_array, y_array = read_fft(genre_list)