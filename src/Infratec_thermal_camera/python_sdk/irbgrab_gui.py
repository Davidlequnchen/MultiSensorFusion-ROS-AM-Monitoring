"""
Version 0.8



Please note: There may be a deprecation warning caused by the pyqtgraph package
The warning can be ignored or the respective file must be modified:
    
C:\Python37\Lib\site-packages\pyqtgraph\imageview\ImageView.py

line 588: 
                data = data[tuple(sl)]

"""

# Qt 5.
# -*- coding: utf-8 -*-
#
import sys
import os,time
import ctypes,_ctypes
import threading
import pyqtgraph as pg
pg.setConfigOptions(imageAxisOrder='row-major')
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import (QPushButton,QGridLayout,QCheckBox,
                             QWidget,QApplication,QMainWindow,
                             QComboBox,QLabel,QLineEdit,QFrame,
                             )
import pathlib as pl

# infratec packages
# try importing as namespace package
try:
    from IRBGrab import irbgrab as irbg
    from IRBGrab import hirbgrab as hirb
    print('namespace-package import')
except (ImportError, ModuleNotFoundError):
    print('directory import')
    # old syspath.append version
    sys.path.append(r'D:\Python_Entwicklertools\IRBGrab')
    sys.path.append(r'D:\Python_Entwicklertools\analyseFunctions') 
    import irbgrab as irbg
    import hirbgrab as hirb
    
t=time.perf_counter()
tLive=t
lock=threading.Lock()
visible=False
dosaveirb=False
ev_has_fname = threading.Event()

def callback(context,*args):#, aHandle, aStreamIndex):
    context.set_image()
#    global t
#    now=time.perf_counter()
#    print(now-t)
#    t = now
#    if visible and (now-t)>0.04: #25Hz
#        if lock.acquire(False):
#            
#            lock.release()
#            t=now

class irbgrab_demo(QMainWindow):
    
    def __init__(self,*args):
        super().__init__(*args)
        self.control_list=[[QPushButton('Load DLL'),        (0,0),(1,1)],#0
                           [QPushButton('Free DLL'),        (0,1),(1,1)],#1
                           [QPushButton('Create Device'),   (2,0),(1,1)],#2
                           [QPushButton('Free Device'),     (2,1),(1,1)],#3
                           [QPushButton('Connect'),         (4,0),(1,1)],#4
                           [QPushButton('Disconnect'),      (4,1),(1,1)],#5
                           [QPushButton('Get Param'),       (9,0),(1,1)],#6
                           [QPushButton('Set Param'),       (9,1),(1,1)],#7
                           [QPushButton('Show Window'),     (10,0),(1,1)],#8
                           [QPushButton('Show Live'),       (10,1),(1,1)],#9
                           [QComboBox(self),                (1,0),(1,2)],#10 #available_devices
                           [QComboBox(self),                (3,0),(1,2)],#11 #search_strings    
                           [QComboBox(self),                (5,0),(1,2)],#12 #datatyp
                           [QLabel('Parameter Nr.',self),   (6,0),(1,1)],#13
                           [QLabel('Parameter Wert',self),  (7,0),(1,1)],#14
                           [QLabel('Index',self),           (8,0),(1,1)],#15
                           [QLineEdit(self),                (6,1),(1,1)],#16 #number
                           [QLineEdit(self),                (7,1),(1,1)], #17 #value
                           [QLineEdit(self),                (8,1),(1,1)], #18 #index
                           [QCheckBox('AutoLevel',self),    (11,0),(1,1)], #19
                           [QCheckBox('Save',self),         (12,0),(1,1)], #20
                           [QLineEdit('D:\sdk_savedata\savedata.irb', self), (12,1),(1,1)] #21
                          ] #[[Obj,(pos),(space)],..]

        for i in range(1,20): #alles bis auf LoadDll ausblenden
            self.control_list[i][0].setEnabled(False)
            
        self.control_list[8][0].setCheckable(True)
        self.control_list[9][0].setCheckable(True)
        self.control_list[12][0].addItem("Int32")       #0
        self.control_list[12][0].addItem("Int64")       #1
        self.control_list[12][0].addItem("Single")      #2
        self.control_list[12][0].addItem("Double")      #3
        self.control_list[12][0].addItem("String")      #4
        self.control_list[12][0].addItem("IdxInt32")    #5
        self.control_list[12][0].addItem("IdxString")   #6
        self.control_list[0][0].clicked.connect(self.load_dll)
        self.control_list[1][0].clicked.connect(self.free_dll)
        self.control_list[2][0].clicked.connect(self.create_device) 
        self.control_list[3][0].clicked.connect(self.free_device)
        self.control_list[4][0].clicked.connect(self.connect)
        self.control_list[5][0].clicked.connect(self.disconnect)
        self.control_list[6][0].clicked.connect(self.get_param)
        self.control_list[7][0].clicked.connect(self.set_param)
        self.control_list[8][0].clicked.connect(self.show_window)
        self.control_list[9][0].clicked.connect(self.show_live)
        self.control_list[19][0].clicked.connect(self.autolevel_checked)
        self.control_list[12][0].currentIndexChanged.connect(self.datatyp_changed)
        self.control_list[20][0].setCheckable(True)
        self.control_list[20][0].clicked.connect(self.startstop_savedata)
        grid=QGridLayout()
        grid.setSpacing(10)
        grid.setColumnStretch(0,1)
        grid.setColumnStretch(1,1)
        for i in range(22):
            grid.addWidget(self.control_list[i][0],*self.control_list[i][1],*self.control_list[i][2])
        centralWidget=QFrame()
        centralWidget.setFrameShape(QFrame.StyledPanel)
        centralWidget.setFrameShadow(QFrame.Plain)
        centralWidget.setLayout(grid)
        self.setCentralWidget(centralWidget)
        self.statBar=self.statusBar()
        self.setGeometry(300, 300, 250, 400)
        self.setWindowTitle('IRBGrab Demo') 
        self.setAttribute(Qt.WA_DeleteOnClose)
        self.show()
        
        self.autolevel_checked_val=False

        
    def load_dll(self):
        self.irbgrab_dll = irbg.getDLLHandle()
        self.irbgrab_object=irbg.irbgrab_obj(self.irbgrab_dll)
        inits=self.irbgrab_object.isinit()
        if inits!=0:   
            #verfügbare geräte anzeigen
            res=self.irbgrab_object.availabledevices()
            if res[0]=='0x10000001': 
                for i in res[1]: self.control_list[10][0].addItem(i)
                self.control_list[0][0].setEnabled(False) #alles bis auf FreeDLL und CreateDevice ausblenden
                self.control_list[1][0].setEnabled(True)
                self.control_list[2][0].setEnabled(True) 
                self.control_list[10][0].setEnabled(True)
                self.statBar.showMessage('Done',2000) 
            else: self.statBar.showMessage('Failed',2000)
        else: self.statBar.showMessage('Failed',2000)
        
    def free_dll(self):
        try:
            del self.irbgrab_object #Objekt löschen
            if 'win' in os.name or 'nt' in os.name: 
                _ctypes.FreeLibrary( self.irbgrab_dll._libraryhandle) #DLL löschen
            else:
                _ctypes.dlclose(self.irbgrab_dll._libraryhandle) 
            del self.irbgrab_dll    
            self.statBar.showMessage('Done',2000)
            self.control_list[0][0].setEnabled(True) #alles bis auf LoadDll ausblenden
            self.control_list[1][0].setEnabled(False)
            self.control_list[2][0].setEnabled(False) 
            self.control_list[10][0].setEnabled(False)
            self.control_list[10][0].clear()
        except:
            self.statBar.showMessage('Failed',2000)
            
    def create_device(self):
        nr_device=self.control_list[10][0].currentIndex()
        if nr_device!=-1: 
            res=self.irbgrab_object.create(nr_device,'')
            if hirb.TIRBG_RetDef[res]=='Success':
                res=self.irbgrab_object.search()
                success=False
                if hirb.TIRBG_RetDef[res[0]]=='Success':
                    if res[1]!=0:
                        success=True
                        self.searchstrings=self.irbgrab_object.get_search_strings()
                        for i in self.searchstrings: self.control_list[11][0].addItem(i)
                    else: self.statBar.showMessage('No Device Available!',2000)
                elif hirb.TIRBG_RetDef[res[0]]=='NotSupported': success=True #für Simulator                   
                else: self.statBar.showMessage('search error: '+hirb.TIRBG_RetDef[res[0]],2000)
                if success:
                    self.statBar.showMessage('Done',2000)
                    self.control_list[11][0].setEnabled(True) #searchstringliste einblenden
                    self.control_list[3][0].setEnabled(True) #connect und free_dev einblenden
                    self.control_list[4][0].setEnabled(True)
                    self.control_list[1][0].setEnabled(False) #geräteliste, create und free_dll ausblenden
                    self.control_list[2][0].setEnabled(False) 
                    self.control_list[10][0].setEnabled(False)
            else: self.statBar.showMessage('create error: '+hirb.TIRBG_RetDef[res],2000)
        else: self.statBar.showMessage('No Device DLL Available!',2000)
    
    def free_device(self):
        res=self.irbgrab_object.free()
        if hirb.TIRBG_RetDef[res]=='Success':
            self.statBar.showMessage('Done',2000)
            self.control_list[11][0].setEnabled(False) #searchstringliste ausblenden
            self.control_list[11][0].clear()
            self.control_list[3][0].setEnabled(False) #connect und free_dev ausblenden
            self.control_list[4][0].setEnabled(False)
            self.control_list[1][0].setEnabled(True) #geräteliste, create und free_dll einblenden
            self.control_list[2][0].setEnabled(True) 
            self.control_list[10][0].setEnabled(True)
        else: self.statBar.showMessage('Failed',2000)

    def connect(self):
        # known bug comes back with an error. res=self.irbgrab_object.get_state() 
        # workaround for this version is to simply set to irbg.TIRBG_RetDef[res]=='Running' and ignore getstate
        res='0x20000004'
        if hirb.TIRBG_RetDef[res]=='Running' or hirb.TIRBG_RetDef[res]=='NotSupported':
            if self.control_list[11][0].count()!=0:
                cam_nr=self.control_list[11][0].currentIndex()
                res=self.irbgrab_object.connect(self.searchstrings[cam_nr]) 
            else:
                res=self.irbgrab_object.connect('')
            if hirb.TIRBG_RetDef[res]=='Success':
                res=self.irbgrab_object.startgrab(0) #hier noch abfrage des StreamIndex????
                if hirb.TIRBG_RetDef[res]=='Success':
                    res=self.irbgrab_object.set_callback_func(callback,self)
                    if hirb.TIRBG_RetDef[res]=='Success':
                        self.statBar.showMessage('Done',2000)
                        for i in range(5,19): self.control_list[i][0].setEnabled(True) #alles einblenden
                        self.control_list[3][0].setEnabled(False) #connect und free_dev ausblenden
                        self.control_list[4][0].setEnabled(False)   
                        self.control_list[10][0].setEnabled(False) #serachstring und geräteliste ausblenden
                        self.control_list[11][0].setEnabled(False)
                        self.control_list[15][0].setEnabled(False) #index ausblenden
                        self.control_list[18][0].setEnabled(False) 
                    else:  self.statBar.showMessage('set callback error: '+hirb.TIRBG_RetDef[res],2000)
                else:  self.statBar.showMessage('startgrab error: '+hirb.TIRBG_RetDef[res],2000)
            else: self.statBar.showMessage('connect error: '+hirb.TIRBG_RetDef[res],2000)
        else: self.statBar.showMessage('state error: '+hirb.TIRBG_RetDef[res],2000) 
            
    def disconnect(self):
        res=self.irbgrab_object.stopgrab(0)
        if hirb.TIRBG_RetDef[res]=='Success':
            res=self.irbgrab_object.disconnect()
            if hirb.TIRBG_RetDef[res]=='Success':
                self.statBar.showMessage('Done',2000)
                for i in range(5,19): self.control_list[i][0].setEnabled(False) #alles ausblenden
                self.control_list[3][0].setEnabled(True) #connect und free_dev einblenden
                self.control_list[4][0].setEnabled(True)   
                self.control_list[11][0].setEnabled(True) #searchstring einblenden
            else: self.statBar.showMessage('disconnect error: '+hirb.TIRBG_RetDef[res],2000) 
        else:  self.statBar.showMessage('stopgrab error: '+hirb.TIRBG_RetDef[res],2000)
        
    def autolevel_checked(self):
        self.autolevel_checked_val=self.control_list[19][0].isChecked()
    
    def saveImage(self, filename, memHandle):
        sstruct = hirb.TIRBG_SaveStruct()
        sstruct.StructLength = ctypes.sizeof(hirb.TIRBG_SaveStruct)
        sstruct.WriteMode = 2 # 0: Add, 1: Overwrite, 2: Sequence

        if filename != '':
            filename = os.path.abspath(filename)

        bfname = ctypes.create_string_buffer(filename.encode(), 255).value
        sstruct.FileName = bfname
        sstruct.MaxFileSizeMB = 2048
        sstruct.MaxFrames = 2048
        sstruct.MinDriveSizeMB = 2048

        print('calling dll save file')
        # ps = ct.pointer(sstruct)
        ret = self.irbgrab_dll.irbgrab_mem_savetofile(
                memHandle,
                ctypes.byref(sstruct)
                )
        print('done')
        return hex(ret&hirb.IRBG_RET_TYPE_MASK)
        
    def set_image(self):
        global t
        global tLive
        now=time.perf_counter()
        # print(now-t)
        t = now
        
        #handle every image
        res=self.irbgrab_object.get_data_easy_noFree(2)
        #display live image
        if hirb.TIRBG_RetDef[res[0]]=='Success':
            if lock.acquire(False):
                if visible and (t-tLive) > 0.04: # 0.04                        
                    if self.autolevel_checked_val: self.image.setImage(res[1], autoRange=False)
                    else: self.image.setImage(res[1], autoRange=False, autoLevels=False)
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
        if self.control_list[9][0].isChecked():     
            self.control_list[19][0].setEnabled(True)
            self.plotwindow=QWidget(self,Qt.Window)
            self.image=pg.ImageView(self.plotwindow)
            self.plotwindow.setWindowTitle('IRBGrab Demo - ShowLive')
            self.plotwindow.show()
            if lock.acquire(blocking=True, timeout=2):
                res=self.irbgrab_object.get_data_easy(2)
                if hirb.TIRBG_RetDef[res[0]]=='Success':
                    self.image.setImage(res[1],autoRange=True)
                lock.release()
            visible=True
        else: 
            self.control_list[19][0].setEnabled(False) #LevelCheckBox
            self.plotwindow.close()
            # try:
            #     self.irbgrab_object.free_mem()
            # except TypeError as e:
            #     if self.irbgrab_object._img_pointer is not None:
            #         raise e
            visible=False
        
        
    def show_window(self):
        #self.plotw=pg.plot('tatile')
        if self.control_list[8][0].isChecked(): state=True
        else: state=False
        res=self.irbgrab_object.show_remote(state)
        if hirb.TIRBG_RetDef[res]=='Success': self.statBar.showMessage('Done',2000)
        else: self.statBar.showMessage('show window error: '+hirb.TIRBG_RetDef[res],2000) 
    
    def datatyp_changed(self, index):
        if index==5 or index==6:
            self.control_list[15][0].setEnabled(True)
            self.control_list[18][0].setEnabled(True)
        else:
            self.control_list[15][0].setEnabled(False)
            self.control_list[18][0].setEnabled(False)
    
    def get_param(self):
        index=self.control_list[12][0].currentIndex()
        try: 
            param_nr=int(self.control_list[16][0].text())
            if index==5 or index==6: param_index=int(self.control_list[18][0].text())
        except: 
            self.statBar.showMessage('parameter format incorrect',2000)
            return

        if index==0:
            res=self.irbgrab_object.getparam_int32(param_nr)
        elif index==1:
            res=self.irbgrab_object.getparam_int64(param_nr)
        elif index==2:
            res=self.irbgrab_object.getparam_single(param_nr)
        elif index==3:
            res=self.irbgrab_object.getparam_double(param_nr)
        elif index==4:
            res=self.irbgrab_object.getparam_string(param_nr)
        elif index==5:
            res=self.irbgrab_object.getparam_idx_int32(param_nr,param_index)
        elif index==6:
            res=self.irbgrab_object.getparam_idx_string(param_nr,param_index)
        if hirb.TIRBG_RetDef[res[0]]=='Success':
            self.control_list[17][0].setText(str(res[1]))
            self.statBar.showMessage('Done',2000) 
        else: self.statBar.showMessage('getparam error: '+hirb.TIRBG_RetDef[res[0]],2000) 
        
    def set_param(self):
        index=self.control_list[12][0].currentIndex()
        try: 
            param_nr=int(self.control_list[16][0].text())
            if index==0 or index==1 or index==5: param_val_int=int(self.control_list[17][0].text())
            elif index==2 or index==3: param_val_float=float(self.control_list[17][0].text())
            else: param_val_str=str(self.control_list[17][0].text())
            if index==5 or index==6: param_index=int(self.control_list[18][0].text())
        except: 
            self.statBar.showMessage('parameter format incorrect',2000)
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
            self.statBar.showMessage('Done',2000) 
        else: self.statBar.showMessage('setparam error: '+hirb.TIRBG_RetDef[res],2000) 
    
    def closeEvent(self, *args):
        #stopgrab
        if self.control_list[5][0].isEnabled(): 
            self.disconnect()
            print('disconnect')
        if self.control_list[3][0].isEnabled(): 
            self.free_device()
            print('free device')
        if self.control_list[1][0].isEnabled(): 
            self.free_dll()
            print('free dll')
        super().closeEvent(*args)
        
    def startstop_savedata(self):       
        global dosaveirb
        
        ev_has_fname.clear()
        self.sfilename=str(pl.Path(self.control_list[21][0].text()))
        dosaveirb=self.control_list[20][0].isChecked()
        ev_has_fname.set()
        if dosaveirb==True:
            print('Start save irb data: '+self.sfilename)
            self.control_list[21][0].setEnabled(False)
        else:
            print('Stop save irb data: '+self.sfilename)
            if lock.acquire():
                try:
                    self.irbgrab_object.free_mem()
                except TypeError as e:
                    if self.irbgrab_object._img_pointer is not None:
                        raise e
                self.saveImage(self.sfilename, 0) # close file
                self.control_list[21][0].setEnabled(True)
                lock.release()

    # called in a locked context from the callback thread when disk is full
    def stop_savedata(self):
        global dosaveirb
        
        dosaveirb = False
        print('Stop save irb data: '+self.sfilename)
        self.control_list[20][0].setCheckState(False)
        # try:
        #     self.irbgrab_object.free_mem()
        # except TypeError as e:
        #     if self.irbgrab_object._img_pointer is not None:
        #         raise e
        self.saveImage(self.sfilename, 0) # close file
        self.control_list[21][0].setEnabled(True)
        
        
if __name__ == '__main__':
    if not QApplication.instance():
        app = QApplication(sys.argv)
    else:
        app = QApplication.instance() 
    demo = irbgrab_demo()
    sys.exit(app.exec_())
