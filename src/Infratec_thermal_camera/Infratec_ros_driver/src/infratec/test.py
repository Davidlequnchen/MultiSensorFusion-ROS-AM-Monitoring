
'''
Simple test program for IRB grab program
'''
import sys
import os,time
import ctypes,_ctypes
import threading
import pathlib as pl


# infratec packages
# try importing as namespace package
# try:
#     from IRBGrab import irbgrab as irbg
#     from IRBGrab import hirbgrab as hirb
#     print('namespace-package import')
# except (ImportError, ModuleNotFoundError):
#     print('directory import')
#     # old syspath.append version
#     sys.path.append(r'D:\Python_Entwicklertools\IRBGrab')
#     sys.path.append(r'D:\Python_Entwicklertools\analyseFunctions') 
#     import irbgrab as irbg
#     import hirbgrab as hirb

import hirbgrab as hirb
import irbgrab as irbg

    
t=time.perf_counter()
tLive=t
lock=threading.Lock()
visible=False
dosaveirb=False
ev_has_fname = threading.Event()


class irbgrab_demo():
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
                    # self.statBar.showMessage('Done',2000)
                    # self.control_list[11][0].setEnabled(True) #searchstringliste einblenden
                    # self.control_list[3][0].setEnabled(True) #connect und free_dev einblenden
                    # self.control_list[4][0].setEnabled(True)
                    # self.control_list[1][0].setEnabled(False) #geräteliste, create und free_dll ausblenden
                    # self.control_list[2][0].setEnabled(False) 
                    # self.control_list[10][0].setEnabled(False)
                    print ("Search done")
            else: 
                print('create error: '+hirb.TIRBG_RetDef[res])
        else: 
            print('No Device DLL Available!')


if __name__ == '__main__':
    demo = irbgrab_demo()
    demo.load_dll()
    demo.create_device()

    