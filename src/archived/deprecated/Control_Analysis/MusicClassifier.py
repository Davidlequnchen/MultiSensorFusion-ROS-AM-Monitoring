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
from sklearn.linear_model import LogisticRegression

#Function to extract FFT features
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
genre_test_dir = "D:\Anaconda\BuildingMLSysWithPy\MusicClassifier\Test"
genre_list = ["classical", "metal"]
#Function to load FFT features into arrays for processing
def read_fft(genre_list, base_dir =  genre_dir ):
    X = []
    y = []
    for label, genre in enumerate(genre_list):
        genre_dir = os.path.join(base_dir, genre, "*.fft.npy")
        file_list = glob.glob(genre_dir)
        print file_list
        for fn in file_list:
            fft_features = np.load(fn)
            X.append(fft_features[:1000])
            y.append(label)
            #print "Reached end of read fft"
    return np.array(X), np.array(y)
	
#Use the below functions once to create .fft.npy files
#for song in glob.glob('classical//*.wav'):
#    fn = song
#    print fn    
#    create_fft(fn)
    
#for song in glob.glob('metal//*.wav'):
#    fn = song
#    print fn    
#    create_fft(fn)

#Train and predict using Logistic Regression model
X_array, y_array = read_fft(genre_list)
lr = LogisticRegression()
lr.fit(X_array, y_array)

X_test, y_test = read_fft(genre_list, base_dir = genre_test_dir)

print lr.predict_proba(X_test[:])

#Expected output
#[[  9.99999929e-01   7.08642353e-08]
# [  1.00000000e+00   5.42847369e-36]
# [  1.00000000e+00   1.77777708e-10]
# [  7.76634927e-01   2.23365073e-01]
# [  1.00000000e+00   4.60352077e-11]
# [  8.25307934e-01   1.74692066e-01]
# [  9.99999989e-01   1.05443659e-08]
# [  1.00000000e+00   7.54182396e-15]
# [  9.99999997e-01   3.17403977e-09]
# [  9.96087321e-01   3.91267949e-03]
# [  0.00000000e+00   1.00000000e+00]
# [  2.61003421e-03   9.97389966e-01]
# [  0.00000000e+00   1.00000000e+00]
# [  0.00000000e+00   1.00000000e+00]
# [  5.77539202e-04   9.99422461e-01]
# [  2.59835042e-10   1.00000000e+00]
# [  2.29031959e-03   9.97709680e-01]
# [  6.14431445e-01   3.85568555e-01]
# [  1.10931268e-02   9.88906873e-01]
# [  2.53439307e-04   9.99746561e-01]]