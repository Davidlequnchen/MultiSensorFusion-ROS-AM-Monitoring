#!/usr/bin/env python3
'''
Simple test program for IRB grab program
'''
import sys
import os,time
import ctypes,_ctypes
import threading
import pathlib as pl
import cv2
from cv_bridge import CvBridge
import numpy as np

### Qt Packages
# from PyQt5.QtCore import Qt
# from PyQt5.QtWidgets import (QPushButton,QGridLayout,QCheckBox,
#                              QWidget,QApplication,QMainWindow,
#                              QComboBox,QLabel,QLineEdit,QFrame,
#                              )
import pyqtgraph as pg
pg.setConfigOptions(imageAxisOrder='row-major')
from python_qt_binding import loadUi
from python_qt_binding import QtGui
from python_qt_binding import QtCore
from python_qt_binding import QtWidgets
# from qt_gui.plugin import Plugin


import irbgrab as irbg
import hirbgrab as hirb


# ros related packages
import rospy
import rospkg
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError


    
t=time.perf_counter()
tLive=t
lock=threading.Lock()
visible=False
dosaveirb=False
ev_has_fname = threading.Event()

def callback(context,*args):#, aHandle, aStreamIndex):
    context.set_image()

path = rospkg.RosPack().get_path('infratec_ros_driver')

class irbgrab_demo(QtWidgets.QWidget):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        self.ui = loadUi(os.path.join(path, 'resources', 'infratec.ui'), self)

        # self.load_dll()
        self.autolevel_checked_val=False
        self.show_live_stream = False

        self.pub_image = rospy.Publisher(
            '/infratec/image_raw', Image, queue_size=10)
        self.msg_infratec_image = Image()

        self.StartButton.clicked.connect(self.StartButtonClicked)
        self.StopButton.clicked.connect(self.StopButtonClicked)
        self.LiveButton.clicked.connect(self.toggle_live_window) # equivalent to self.set_param(0,113,1)
        self.RemoteButton.clicked.connect(self.show_remote_window) # equivalent to self.set_param(0,113,1)
        self.StreamingButton.clicked.connect(self.StreamingButtonClicked)
        self.ROSPubButton.clicked.connect(self.ROSPubButtonClicked)
        self.AcceptParamButton.clicked.connect(self.AcceptParamButtonClicked)
        self.AcceptEpsButton.clicked.connect(self.AcceptEpsButtonClicked)
        # self.show_realtime_image()


        # start the timer
        # self.timer = QtCore.QTimer()
        # self.timer.timeout.connect(self.updateImage)
        # self.timer.start(10) # refresh every xxx miliseconds (0.001 seconds)
    
    '''
    def show_realtime_image(self):
        self.plot_window=QtWidgets.QWidget()
        # self.plot_window=QtGui.QWidget(self,Qt.Window) ##self,QtCore.Window
        self.realtime_image = pg.ImageView(self.plot_window)
        # self.plot_window.setTitle("Thermal Camera Live")
        self.plot_window.setWindowTitle('IRBGrab - ShowLive')
        self.plot_window.show()
        res=self.irbgrab_object.get_data_easy(3) 
        if hirb.TIRBG_RetDef[res[0]]=='Success':
            self.realtime_image.setImage(res[1],autoRange=True)
            self.msg_infratec_image.data = res[1]
            self.pub_image.publish(self.msg_infratec_image)
            # print(res[1])

    def updateImage(self):
        #handle every image
        res=self.irbgrab_object.get_data_easy_noFree(3)
        #display live image
        if hirb.TIRBG_RetDef[res[0]]=='Success':
            self.realtime_image.setImage(res[1], autoRange=False, autoLevels=False)
            self.msg_infratec_image.data = res[1]
            self.pub_image.publish(self.msg_infratec_image)
            # print(res[1])
            # cv2.imshow('CV2 window', res[1])
            # cv2.waitKey(0) # waits until a key is pressed
            # cv2.destroyAllWindows() # destroys the window showing image
            self.irbgrab_object.free_mem()
    '''

    def StartButtonClicked(self):
        self.load_dll()
        self.create_device()
        self.connect()
        self.lblStatus.setText('Camera Status: Camera Connected!')
        self.lblStatus.setStyleSheet(
                "background-color: rgb(0, 200, 0); color: rgb(255, 255, 255);")


    def StopButtonClicked(self):
        self.disconnect()
        self.free_device()
        self.free_dll()
        self.lblStatus.setText('Camera Status: Done, Disconect Camera!')
        self.lblStatus.setStyleSheet(
                "background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);")

    def StreamingButtonClicked(self):
        demo.show_live_stream = True
        demo.show_live()

    def ROSPubButtonClicked(self):
        res=self.irbgrab_object.get_data_easy_noFree(3) ### rect[3] is numpy array
        # h,w = res[1].shape
        # vis2 = cv2.CreateMat(h, w, cv.CV_32FC3)
        # vis0 = cv2.fromarray(vis)
        # cv.CvtColor(vis0, vis2, cv.CV_GRAY2BGR)
        # new_image = res[1].astype(np.uint8)
        bridge = CvBridge()
        imgMsg = bridge.cv2_to_imgmsg(res[1]) ##can be rgb8
        self.pub_image.publish(imgMsg)
        self.lblStatus.setText(str(res[1]))

        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self.updateData)
        self.timer.start(30) #unit: milisecond, 0.001 second
    
    def updateData(self):
        res=self.irbgrab_object.get_data_easy_noFree(3)
        # new_image = res[1].astype(np.uint8)
        bridge = CvBridge()
        imgMsg = bridge.cv2_to_imgmsg(res[1]) ##can be rgb8,mono8
        self.pub_image.publish(imgMsg)

    def load_dll(self):
        self.irbgrab_dll = irbg.getDLLHandle()
        self.irbgrab_object=irbg.irbgrab_obj(self.irbgrab_dll)
        inits=self.irbgrab_object.isinit()
        if inits!=0:   
            #verfügbare geräte anzeigen
            res=self.irbgrab_object.availabledevices()
            print('available devices: {}'.format(res))
            if res[0]=='0x10000001': 
                self.nr_devices = 0
                for i in res[1]: 
                    print ("Successfully load available devices " + i)
                    self.nr_devices = self.nr_devices + 1
            else: print ("Failed")
        else: print ("Failed - not initiaed")

    def create_device(self):
        # self.nr_device=self.control_list[10][0].currentIndex()
        if self.nr_devices!=-1: 
            res=self.irbgrab_object.create(2,'')
            print('creating device: {}'.format(res))
            if (hirb.TIRBG_RetDef[res]=='Success'):
                res=self.irbgrab_object.search()
                success=False
                if hirb.TIRBG_RetDef[res[0]]=='Success':
                    if res[1]!=0:
                        success=True
                        self.searchstrings=self.irbgrab_object.get_search_strings()
                        for i in self.searchstrings: 
                            # self.control_list[11][0].addItem(i)
                            print ("Add search string " + i)
                    else: 
                        print('No Device Available!')
                elif hirb.TIRBG_RetDef[res[0]]=='NotSupported': success=True #für Simulator                   
                else: 
                    print('search error: '+hirb.TIRBG_RetDef[res[0]])
                if success:
                    print ("Search done!")
            else: 
                print('create error: '+hirb.TIRBG_RetDef[res])
        else: 
            print('No Device DLL Available!')

    def connect(self):
        # known bug comes back with an error. res=self.irbgrab_object.get_state() 
        # workaround for this version is to simply set to irbg.TIRBG_RetDef[res]=='Running' and ignore getstate
        res='0x20000004'
        if hirb.TIRBG_RetDef[res]=='Running' or hirb.TIRBG_RetDef[res]=='NotSupported':
            if self.searchstrings!=0:
                # cam_nr=self.control_list[11][0].currentIndex()
                res=self.irbgrab_object.connect(self.searchstrings[0]) 
            else:
                res=self.irbgrab_object.connect('')
            if hirb.TIRBG_RetDef[res]=='Success':
                res=self.irbgrab_object.startgrab(0) #Here you can still query the StreamIndex????
                if hirb.TIRBG_RetDef[res]=='Success':
                    print ("Done! Connection established")
                    res=self.irbgrab_object.set_callback_func(callback,self)
                    if hirb.TIRBG_RetDef[res]=='Success':
                        print ("Done! Connection established")
                    else:  print('set callback error: '+hirb.TIRBG_RetDef[res])
                else:  print('startgrab error: '+hirb.TIRBG_RetDef[res])
            else: print('connect error: '+hirb.TIRBG_RetDef[res])
        else: print('state error: '+hirb.TIRBG_RetDef[res]) 

    def set_image(self):
        global t
        global tLive
        now=time.perf_counter()
        # print(now-t)
        t = now
        
        #handle every image
        res=self.irbgrab_object.get_data_easy_noFree(3)
        #display live image
        if hirb.TIRBG_RetDef[res[0]]=='Success':
            if lock.acquire(False):
                if visible and (t-tLive) > 0.04: # 0.04                        
                    if self.autolevel_checked_val: 
                        self.image.setImage(res[1], autoRange=False)
                        # print(res[1])
                    else: 
                        self.image.setImage(res[1], autoRange=False, autoLevels=False)
                    tLive=t
                if dosaveirb:
                    if not ev_has_fname.wait(0.1): # wait until main thread has written the sfilename
                        print('synchronization error')
                    memHandle = self.irbgrab_object._img_pointer
                    # DEBUG
                    # print(self.sfilename, memHandle)
                    if memHandle is not None:
                        res = self.saveImage(self.sfilename, memHandle)
                        res_readable = hirb.TIRBG_RetDef[res]
                        # the following catches the DiskFull Error
                        if not res_readable =='Success':
                            print(res_readable)
                            print('error occurred during saving: stopping save')
                            self.stop_savedata() 
                # free memory                    

                self.irbgrab_object.free_mem()

                lock.release()
            # DEBUG
            # print('memory freed')
        else:
            print('Error when getting image: {}'.format(res[0]))

    def show_live(self):  
        global visible
        if self.show_live_stream == True:     
            # self.plotwindow=QtGui.QWidget(self,Qt.Window)
            # self.plotwindow=QtWidgets.QWidget()
            # Add image widget
            self.plotwindow = QtGui.QVBoxLayout(self.ImageWidget)
            self.image = pg.ImageView()
            self.plotwindow.addWidget(self.image)
            # self.plotwindow = self.ImageWidget
            # self.image=pg.ImageView(self.plotwindow)
            # self.plotwindow.setWindowTitle('IRBGrab Demo - ShowLive')
            # self.plotwindow.show()
            if lock.acquire(blocking=True, timeout=2):
                res=self.irbgrab_object.get_data_easy(3) 
                # print(res[1]) 
                if hirb.TIRBG_RetDef[res[0]]=='Success':
                    self.image.setImage(res[1],autoRange=True)
                    print(res[1])
                lock.release()
            visible=True
        else: 
            self.plotwindow.close()
            # try:
            #     self.irbgrab_object.free_mem()
            # except TypeError as e:
            #     if self.irbgrab_object._img_pointer is not None:
            #         raise e
            visible=False

    def show_remote_window(self):
        #self.plotw=pg.plot('tatile')
        res=self.irbgrab_object.show_remote(True)
        if hirb.TIRBG_RetDef[res]=='Success': print('Show remote window done!')
        else: print('show window error: '+hirb.TIRBG_RetDef[res]) 

    def toggle_live_window(self):
        self.irbgrab_object.toggle_window(1)

    def get_image_data(self):
        res=self.irbgrab_object.get_data_easy(3)
        print(res)

    def AcceptParamButtonClicked(self):
        # index: 0,1,5 int, 2,3 - float, 4, 6-string
        # index, param_nr, param_value
        index = self.datatypeCombox.currentIndex()
        try: 
            param_nr=int(self.ParmNumEdit.text())
            if index==0 or index==1 or index==5: param_val_int=int(self.ParmValueEdit.text())
            elif index==2 or index==3: param_val_float=float(self.ParmValueEdit.text())
            else: param_val_str=str(self.ParmValueEdit.text())
            if index==5 or index==6: param_index=int(self.control_list[18][0].text())
        except: 
            print('parameter format incorrect, close')
            return
        
        if index==0:
            res=self.irbgrab_object.setparam_int32(param_nr,param_val_int)
        elif index==1:
            res=self.irbgrab_object.setparam_int64(param_nr,param_val_int)
        elif index==2:
            res=self.irbgrab_object.setparam_single(param_nr,param_val_float)
        elif index==3:
            res=self.irbgrab_object.setparam_double(param_nr,param_val_float)
        elif index==4:
            res=self.irbgrab_object.setparam_string(param_nr,param_val_str)
        elif index==5:
            res=self.irbgrab_object.setparam_idx_int32(param_nr,param_index,param_val_int)
        elif index==6:
            res=self.irbgrab_object.setparam_idx_string(param_nr,param_index,param_val_str)
        if hirb.TIRBG_RetDef[res]=='Success':
            self.lblStatus.setText('Status: Succesfully set parameter!')
            self.lblStatus.setStyleSheet(
                "background-color: rgb(0, 200, 0); color: rgb(255, 255, 255);") 
        else: 
            self.lblStatus.setText('Set parameter error: '+ str(hirb.TIRBG_RetDef[res]))
            self.lblStatus.setStyleSheet(
                "background-color: rgb(200, 0, 0); color: rgb(255, 255, 255);")  
    
    def AcceptEpsButtonClicked(self):
        self.global_emissivity = float(self.SetGlobalEps.text())
        res=self.irbgrab_object.setparam_single(hirb.IRBG_PARAM_IRBcorr_ObjEps, self.global_emissivity)
        if hirb.TIRBG_RetDef[res]=='Success':
            self.lblStatus.setText('Status: Succesfully set emissivity value!')
            self.lblStatus.setStyleSheet(
                "background-color: rgb(0, 200, 0); color: rgb(255, 255, 255);") 
        else: 
            self.lblStatus.setText('Set emissivity error: '+ str(hirb.TIRBG_RetDef[res]))
            self.lblStatus.setStyleSheet(
                "background-color: rgb(200, 0, 0); color: rgb(255, 255, 255);") 

    def disconnect(self):
        res=self.irbgrab_object.stopgrab(0)
        if hirb.TIRBG_RetDef[res]=='Success':
            res=self.irbgrab_object.disconnect()
            if hirb.TIRBG_RetDef[res]=='Success':
                print('Done! Disconnected',2000)
            else: print('disconnect error: '+hirb.TIRBG_RetDef[res]) 
        else:  print('stopgrab error: '+hirb.TIRBG_RetDef[res])
        
    def free_device(self):
        res=self.irbgrab_object.free()
        if hirb.TIRBG_RetDef[res]=='Success':
            print('Free Device')
        else: print('Failed to free device')

    def free_dll(self):
        try:
            del self.irbgrab_object #Delete object
            if 'win' in os.name or 'nt' in os.name: 
                _ctypes.FreeLibrary( self.irbgrab_dll._libraryhandle) #Delete DLL
            else:
                _ctypes.dlclose(self.irbgrab_dll._libraryhandle) 
            del self.irbgrab_dll    
            print('free dll')
        except:
            print('Failed to free dll')

    def closeEvent(self, *args):
        #stopgrab
        self.disconnect()
        print('disconnect')
        self.free_device()
        print('free device')
        self.free_dll()
        print('free dll')
        super().closeEvent(*args)



if __name__ == '__main__':
    rospy.init_node('infratec_driver')
    app = QtWidgets.QApplication(sys.argv)
    # if not QApplication.instance():
    #     app = QApplication(sys.argv)
    # else:
    #     app = QApplication.instance() 
    demo = irbgrab_demo()
    demo.show()
    # demo.show()
    # demo.load_dll()
    # demo.create_device()
    # demo.connect()
    # demo.show()
    # demo.irbgrab_object.setparam_int32(113,1)
    # demo.show_live_stream = True
    # demo.show_live()
    # demo.get_image_data()
    
    # demo.toggle_live_window(1)  ### this is exactly the same as demo.set_param(0,113,1)
    # demo.set_param(0,113,1)   #### ------ this works well, open the live RGB window automatically

    # demo.show_remote_window()        ### --------this works well, automatically open the remote control window
    app.exec_()
    # sys.exit(app.exec_())


    