"""
a wrapper for the irbgrab dll
"""
# -*- coding: utf-8 -*-
import numpy as np
import os
import ctypes as ct
import pathlib as pl

try:
    import IRBGrab.hirbgrab as hirb
except ImportError:
    # print('HERE')
    import hirbgrab as hirb
    
import pkg_resources as pkgrsrc

# import itconf if it exists
skipTry = False
try:
    from itconf import itconf
except ImportError:
    skipTry = True
    
MASK = hirb.IRBG_RET_TYPE_MASK #um aus 64int 32int zu machen 

CHAR_BUFFER_SIZE = 1024
def getDLLHandle(irbgrab_path = None):    
    libdir  = pl.Path(__file__).parent.resolve()
    
    print(skipTry)
    
    if 'win' in os.name or 'nt' in os.name:
        irbgrab_path = libdir
        # for frozen apps the dll is included and specified via the itconf module
        # the local name is shared through the dllconf module
        if not skipTry:
            try:
                assert(itconf._irbgrab_resrc is not None)
                irbgrab_path = pl.Path(itconf._irbgrab_resrc)
                # DEBUG
                # print('fbs import scheme')
            except (AttributeError, AssertionError) as e:
                print(e)
                print('dll path not specified via the itconf module')
        # search inside pkg if installed,
        # does not work if called as main script
        if not irbgrab_path.is_file():
            if not (__name__ == "__main__") and pkgrsrc.resource_exists(__name__, "irbgrab_win64.dll"):
                irbgrab_path = pl.Path(pkgrsrc.resource_filename(__name__, "irbgrab_win64.dll"))
                print('pkgrsrc import scheme') 
        # fallbacks for non-frozen apps without IT-Python-Entwicklertools pkg            
        if not irbgrab_path.is_file():
            irbgrab_path = libdir / 'irbgrab_win64.dll'
            print('standard rel. path import scheme') 
        if not irbgrab_path.is_file():
            libdir = pl.Path(r"C:\Program Files\InfraTec\IRBGRAB_SDK\v4")
            irbgrab_path = libdir / 'irbgrab_win64.dll'
            print('SDK Program Files import scheme')
        if not irbgrab_path.is_file():
            libdir = pl.Path(r"C:\Programme\InfraTec\IRBGRAB_SDK\v4")
            irbgrab_path = libdir / 'irbgrab_win64.dll'
            print('SDK Programs importlib_resources import scheme')          
        irbgrab_dll = ct.windll.LoadLibrary(str(irbgrab_path))
        
    elif 'posix' in os.name:
        if not irbgrab_path:
            irbgrab_path = '/usr/lib/infratec/libirbgrab_linux.so'       
        irbgrab_dll = ct.cdll.LoadLibrary(irbgrab_path)
    else:
        raise Exception('Unknown operating system: {}'.format(os.name))
    
    irbgrab_dll.irbgrab_dll_version.argtypes = [ct.POINTER(ct.c_char*CHAR_BUFFER_SIZE), ct.c_int]
    irbgrab_dll.irbgrab_dll_init.argtypes = []
    irbgrab_dll.irbgrab_dll_uninit.argtypes = []
    irbgrab_dll.irbgrab_dll_isinit.argtypes = [ct.POINTER(ct.c_int)]
    irbgrab_dll.irbgrab_dll_devicetypenames.argtypes = [ct.POINTER(ct.c_char*CHAR_BUFFER_SIZE), ct.c_int]
    irbgrab_dll.irbgrab_dev_create.argtypes = [ct.POINTER(ct.c_uint64), ct.c_int, ct.POINTER(ct.c_char*CHAR_BUFFER_SIZE)]
    irbgrab_dll.irbgrab_dev_free.argtypes = [ct.c_uint64]
    irbgrab_dll.irbgrab_dev_search.argtypes = [ct.c_uint64, ct.POINTER(ct.c_int)]
    irbgrab_dll.irbgrab_dev_connect.argtypes = [ct.c_uint64, ct.POINTER(ct.c_char*CHAR_BUFFER_SIZE)]
    irbgrab_dll.irbgrab_dev_disconnect.argtypes = [ct.c_uint64]
    irbgrab_dll.irbgrab_dev_startgrab.argtypes = [ct.c_uint64, ct.c_int]
    irbgrab_dll.irbgrab_dev_stopgrab.argtypes = [ct.c_uint64, ct.c_int]
    irbgrab_dll.irbgrab_dev_setparam.argtypes = [ct.c_uint64, ct.c_int, ct.c_void_p, ct.c_uint32]
    irbgrab_dll.irbgrab_dev_getparam.argtypes = [ct.c_uint64, ct.c_int, ct.c_void_p, ct.c_uint32]
    irbgrab_dll.irbgrab_dev_getdata.argtypes = [ct.c_uint64, ct.c_int, ct.POINTER(ct.c_uint64)]
    irbgrab_dll.irbgrab_dev_getstate.argtypes = [ct.c_uint64]
    irbgrab_dll.irbgrab_dev_clearringbuffer.argtypes = [ct.c_uint64]
    irbgrab_dll.irbgrab_mem_getdimension.argtypes = [ct.c_uint64, ct.POINTER(ct.c_uint32), ct.POINTER(ct.c_uint32), ct.POINTER(ct.c_uint32)]
    irbgrab_dll.irbgrab_mem_getdataptr.argtypes = [ct.c_uint64, ct.c_void_p, ct.POINTER(ct.c_int)]
    irbgrab_dll.irbgrab_mem_getheaderptr.argtypes = [ct.c_uint64, ct.c_void_p, ct.POINTER(ct.c_int)]
    irbgrab_dll.irbgrab_mem_getirvalues.argtypes = [ct.c_uint64, ct.POINTER(ct.c_float), ct.POINTER(ct.c_float), ct.POINTER(ct.c_float), ct.POINTER(ct.c_float)]
    irbgrab_dll.irbgrab_mem_getdigitalvalues.argtypes = [ct.c_uint64, ct.POINTER(ct.c_uint16), ct.POINTER(ct.c_uint16)]
    irbgrab_dll.irbgrab_mem_gettimestamp.argtypes = [ct.c_uint64, ct.POINTER(ct.c_double)]
    irbgrab_dll.irbgrab_mem_getinfo.argtypes = [ct.c_uint64, ct.POINTER(hirb.TIRBG_MemInfo)]
#    irbgrab_dll.irbgrab_mem_getheaderinfo.argtypes = [ct.c_uint64, ct.POINTER(TIRBG_HeaderInfo)]
    irbgrab_dll.irbgrab_mem_savetofile.argtypes = [ct.c_uint64, ct.POINTER(hirb.TIRBG_SaveStruct)]
    irbgrab_dll.irbgrab_mem_free.argtypes = [ct.POINTER(ct.c_uint64)]
#    irbgrab_dll.irbgrab_pollframefuncptr.argtypes = [ct.c_void_p]
#    irbgrab_dll.irbgrab_pollframegrab.argtypes = [ct.POINTER(ct.c_uint64), ct.POINTER(ct.c_int), ct.c_int]
#    irbgrab_dll.irbgrab_pollframefinish.argtypes = []


    if irbgrab_dll is None:
        raise Exception('DLL could not be loaded')
    return irbgrab_dll

class irbgrab_obj(object):
#Interface zur irbgrab_w64.dll
    def __init__(self,dll_handle):
        super().__init__() 
        
        self._handle = None
        self._img_pointer = ct.c_uint64(0)
        self.irbgrab_dll=dll_handle
        print(dll_handle)
        self.irbgrab_dll.irbgrab_dll_init()
        
        
#        self.irbgrab_dll.irbgrab_mem_getdimension.argtypes  = [ct.c_int64]+[ct.POINTER(ct.c_uint32)]*3
#        self.irbgrab_dll.irbgrab_mem_getdataptr.argtypes = [ct.c_int64, 
#                                                            ct.POINTER(ct.c_uint64),
#                                                            ct.POINTER(ct.c_uint32)
#                                                            ]
#        self.irbgrab_dll.irbgrab_mem_getinfo.argtypes = [
#                ct.c_uint64,
#                ct.POINTER(TIRBG_MemInfo)
#                ]
    def __del__(self):
        if self._handle!=None:
            self.irbgrab_dll.irbgrab_dev_disconnect(self._handle)
            self.irbgrab_dll.irbgrab_dev_free(self._handle)
        self.irbgrab_dll.irbgrab_dll_uninit()
    
    def version(self):
        buffer=(ct.c_char*CHAR_BUFFER_SIZE)()
        self.irbgrab_dll.irbgrab_dll_version(ct.byref(buffer),CHAR_BUFFER_SIZE)
        return (buffer.value).decode('ascii')
    
    '''Beginn Verbindungsaufbau'''
    
    def availabledevices(self):
        buffer=(ct.c_char*1024)()
        res=self.irbgrab_dll.irbgrab_dll_devicetypenames(ct.byref(buffer),1024)
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS:
            dev_list=((buffer.value).decode('ascii')).split(';')
            dev_list.pop()
            return (hex(res),dev_list)
        else: return (hex(res),)
       
    def create(self,dev_number,ini_path):
        ini_path_c=ct.create_string_buffer(ini_path.encode('utf-8'), size = CHAR_BUFFER_SIZE)
        dev_handle=ct.c_uint64(0)
        res=self.irbgrab_dll.irbgrab_dev_create(ct.byref(dev_handle),dev_number,ct.byref(ini_path_c))
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS:    
            self._handle=dev_handle.value
            # DEBUG
            # print(self._handle)
        return hex(res)
    
    def search(self):
        number=ct.c_int()
        # DEBUG
        # print(self._handle)
        res=self.irbgrab_dll.irbgrab_dev_search(self._handle,ct.pointer(number))
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS: return (hex(res),number.value)
        else: return (hex(res),)
        
    def get_search_strings(self): #listet alle Search_strings zu den verfügbaren Kameras auf
        ret_arr=[]
        i=0
        res=self.getparam_idx_string(202,i)
        while res[0]==hex(hirb.IRBG_RET_SUCCESS):
            ret_arr.append(res[1])
            i=i+1
            res=self.getparam_idx_string(202,i)
        return ret_arr

    def get_state(self):
        try: #in simulator nicht implementiert
            res=self.irbgrab_dll.irbgrab_dev_getstate(self._handle)
            return hex(res & MASK)
        except: return '0x80000002'
        
    def connect(self,search_string): #search_strings über get_search_strings
#        p_search_string=ct.c_char_p(bytes(search_string,'ascii'), size = CHAR_BUFFER_SIZE)
        search_string=ct.create_string_buffer(search_string.encode('utf-8'), 
                                                  size = CHAR_BUFFER_SIZE)
        
        res=self.irbgrab_dll.irbgrab_dev_connect(self._handle,search_string)
        res=res & MASK
        return hex(res)
        
    def startgrab(self,stream_index):
        res=self.irbgrab_dll.irbgrab_dev_startgrab(self._handle, stream_index)
        res=res & MASK
        return hex(res)
    
    '''Ende Verbindungsaufbau'''
    
    '''Start of getparam / setparam with various ready-made data types'''
    
    def getparam_int32(self, number):
        value=ct.c_int32(0)
        res=self.irbgrab_dll.irbgrab_dev_getparam(self._handle, number, ct.byref(value), hirb.IRBG_DATATYPE_INT32)
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS: return (hex(res),value.value) 
        else: return (hex(res),) 
    
    def setparam_int32(self, number, value):
        val=ct.c_int32(value)
        res=self.irbgrab_dll.irbgrab_dev_setparam(self._handle, number, ct.byref(val), hirb.IRBG_DATATYPE_INT32)
        res=res & MASK
        return hex(res) 
    
    def getparam_int64(self, number):
        value=ct.c_int64(0)
        res=self.irbgrab_dll.irbgrab_dev_getparam(self._handle, number, ct.byref(value), hirb.IRBG_DATATYPE_INT64)
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS: return (hex(res),value.value)
        else: return (hex(res),)
        
    def setparam_int64(self, number, value):
        val=ct.c_int64(value)
        res=self.irbgrab_dll.irbgrab_dev_setparam(self._handle, number, ct.byref(val), hirb.IRBG_DATATYPE_INT64)
        res=res & MASK
        return hex(res)
        
    def getparam_double(self, number):
        value=ct.c_double(0.0)
        res=self.irbgrab_dll.irbgrab_dev_getparam(self._handle, number, ct.byref(value), hirb.IRBG_DATATYPE_DOUBLE)
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS: return (hex(res),value.value)
        else: return (hex(res),)
    
    def setparam_double(self, number, value):
        val=ct.c_double(value)
        res=self.irbgrab_dll.irbgrab_dev_setparam(self._handle, number, ct.byref(val), hirb.IRBG_DATATYPE_DOUBLE)
        res=res & MASK
        return hex(res)
    
    def getparam_single(self, number):
        value=ct.c_float(0.0)
        res=self.irbgrab_dll.irbgrab_dev_getparam(self._handle, number, ct.byref(value), hirb.IRBG_DATATYPE_SINGLE)
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS: return (hex(res),value.value)
        else: return (hex(res),)
    
    def setparam_single(self, number, value):
        val=ct.c_float(value)
        res=self.irbgrab_dll.irbgrab_dev_setparam(self._handle, number, ct.byref(val), hirb.IRBG_DATATYPE_SINGLE)
        res=res & MASK
        return hex(res)
    
    def getparam_string(self, number):
        string=hirb.TIRBG_String()
        buffer=ct.create_string_buffer(1024*1024)
        string.Text=ct.c_char_p(ct.addressof(buffer))
        string.Len=ct.sizeof(buffer)
        res=self.irbgrab_dll.irbgrab_dev_getparam(self._handle, number, ct.byref(string), hirb.IRBG_DATATYPE_STRING)
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS: return (hex(res),str(ct.string_at(string.Text),'ascii'))
        else: return (hex(res),)
    
    def setparam_string(self, number, astring):
        string=hirb.TIRBG_String()
        buffer=ct.create_string_buffer(bytes(astring,'ascii'))
        string.Text=ct.c_char_p(ct.addressof(buffer))
        string.Len=ct.sizeof(buffer)
        res=self.irbgrab_dll.irbgrab_dev_setparam(self._handle, number, ct.byref(string), hirb.IRBG_DATATYPE_STRING)
        res=res & MASK
        return hex(res)
    
    def getparam_idx_int32(self, number, index):
        idx_int32=hirb.TIRBG_IdxInt32()
        idx_int32.Index = index
        idx_int32.value = ct.c_int32(0)
        res=self.irbgrab_dll.irbgrab_dev_getparam(self._handle, number, ct.byref(idx_int32), hirb.IRBG_DATATYPE_IDXINT32)
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS: return (hex(res),idx_int32.value) 
        else: return (hex(res),)
        
    def setparam_idx_int32(self, number, index, value):
        idx_int32=hirb.TIRBG_IdxInt32()
        idx_int32.Index = index
        idx_int32.value = ct.c_int32(value)
        res=self.irbgrab_dll.irbgrab_dev_setparam(self._handle, number, ct.byref(idx_int32), hirb.IRBG_DATATYPE_IDXINT32)
        res=res & MASK
        return hex(res)

    def getparam_idx_string(self, number, index):
        idx_string=hirb.TIRBG_IdxString()
        idx_string.Index=index
        buffer=ct.create_string_buffer(1024)
        #idx_string.Value=TIRBG_String()
        idx_string.value.Text=ct.c_char_p(ct.addressof(buffer))
        idx_string.value.Len=1024
        res=self.irbgrab_dll.irbgrab_dev_getparam(self._handle, number, ct.byref(idx_string), hirb.IRBG_DATATYPE_IDXString)
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS: return (hex(res),str(ct.string_at(idx_string.value.Text),'utf-8')) 
        else: return (hex(res),)
    
    def setparam_idx_string(self, number, index, string):
        idx_string=hirb.TIRBG_IdxString()
        buffer=ct.create_string_buffer(bytes(string,'utf-8'))
        idx_string.value.Text=ct.c_char_p(ct.addressof(buffer))
        idx_string.value.Len=len(string)
        idx_string.Index=index
        res=self.irbgrab_dll.irbgrab_dev_setparam(self._handle, number, ct.byref(idx_string), hirb.IRBG_DATATYPE_IDXString)
        res=res & MASK
        return hex(res)
        
    #Allgemein, struct (ct) und param_type müssen selbst erstellt werden
    
    def getparam(self, number, struct, param_type): 
        res=self.irbgrab_dll.irbgrab_dev_getparam(self._handle, number, ct.byref(struct), param_type)
        res=res & MASK
        return hex(res)
    
    def setparam(self, number, struct, param_type): 
        res=self.irbgrab_dll.irbgrab_dev_setparam(self._handle, number, ct.byref(struct), param_type)
        res=res & MASK
        return hex(res)
    
    '''End of setparam / getparam''' 
    
    '''Start of image acquisition'''
    
    def set_callback_func(self, func, context):
        self._callback=hirb.IRBG_CALLBACK_FUNC(func) #func als Callback Fkt. verpacken, Callback garantiert aktiv solange Referenz gehalten wird
        CallB=hirb.TIRBG_CallBack()
        CallB.Context=ct.py_object(context) #python object kann übergeben werden
        CallB.FuncPtr=self._callback
        res = self.irbgrab_dll.irbgrab_dev_setparam(self._handle, hirb.IRBG_PARAM_OnNewFrame, ct.byref(CallB), hirb.IRBG_DATATYPE_CALLBACK)
        res = res & MASK
        return hex(res)
    
    def get_data(self,img_type):
        img_handle=ct.c_uint64(0)
        if img_type==1: #for bitmap data, IRBG_PARAM_SDK_NeedBitmap32 must be set 
            res=int(self.setparam_int32(181,1),16)
            if res!=hirb.IRBG_RET_SUCCESS: return hex(res)
        res=self.irbgrab_dll.irbgrab_dev_getdata(self._handle,
                                                 img_type,
                                                 ct.byref(img_handle))
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS: self._img_pointer=img_handle
        return hex(res)
        
    def get_dimensions(self):
        width=ct.c_uint32(0)
        height=ct.c_uint32(0)
        data_type=ct.c_uint32(0)
        res=self.irbgrab_dll.irbgrab_mem_getdimension(self._img_pointer,
                                                      width,
                                                      height,
                                                      data_type
                                                      )
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS: return (hex(res),width.value,height.value,hex(data_type.value))
        else: return (hex(res),)
        
    def get_dataptr(self):
        size=ct.c_int(0)
        address=ct.c_uint64(0)
        res=self.irbgrab_dll.irbgrab_mem_getdataptr(self._img_pointer,
                                                    ct.byref(address),
                                                    ct.byref(size))
        res=res&MASK
        if res==hirb.IRBG_RET_SUCCESS: return (hex(res),address.value,size.value)
        else: return (hex(res),)
        
    def get_info(self):
        mem_info=hirb.TIRBG_MemInfo()
        mem_info.Triggered=ct.c_int(0)
        mem_info.TimeStamp=ct.c_double(0)
        mem_info.ImageNum=ct.c_int64(0)
        mem_info.MissedPackets=ct.c_int(0)
        mem_info.StructSize=ct.c_int(ct.sizeof(mem_info))
        
        
        res=self.irbgrab_dll.irbgrab_mem_getinfo(self._img_pointer, ct.byref(mem_info))
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS: 
            if mem_info.Triggered!=0: return (hex(res), mem_info.Triggered, mem_info.TimeStamp, mem_info.ImageNum, mem_info.MissedPackets)
            else: return (hex(res),  mem_info.Triggered, mem_info.TimeStamp, mem_info.ImageNum, mem_info.MissedPackets)
        else: return (hex(res),)
            
    def free_mem(self):
#        img_pointer=ct.POINTER(ct.c_int64(self._img_pointer))
        res=self.irbgrab_dll.irbgrab_mem_free(ct.byref(self._img_pointer))
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS: self._img_pointer=None
        return hex(res)
    
    def get_data_easy(self,img_type): #possibly check whether the previous image has been processed
        res=self.get_data(img_type)
        if int(res,16)==hirb.IRBG_RET_SUCCESS:
            dim=self.get_dimensions()
            if int(dim[0],16)==hirb.IRBG_RET_SUCCESS:
                img_shape=(dim[2],dim[1])
                ptr=self.get_dataptr()
                if int(ptr[0],16)==hirb.IRBG_RET_SUCCESS:                    
                    if img_type==1 or img_type==int('01000000',16): data_ptr=ct.cast(ptr[1],ct.POINTER(ct.c_uint32))
                    elif img_type==2: data_ptr=ct.cast(ptr[1],ct.POINTER(ct.c_uint16))
                    elif img_type==3: data_ptr=ct.cast(ptr[1],ct.POINTER(ct.c_float))
                    elif img_type==4: data_ptr=ct.cast(ptr[1],ct.POINTER(ct.c_uint8))
                    elif img_type==0: data_ptr=None #???
                    image=np.ctypeslib.as_array(data_ptr,shape=img_shape).copy()
                    res=self.free_mem() 
                    return (res, image)
                else: return (ptr[0],)
            else: return (dim[0],)
        else: return (res,)
        
    def get_data_easy_noFree(self,img_type): #possibly check whether the previous image has been processed
        res=self.get_data(img_type)
        if int(res,16)==hirb.IRBG_RET_SUCCESS:
            dim=self.get_dimensions()
            if int(dim[0],16)==hirb.IRBG_RET_SUCCESS:
                img_shape=(dim[2],dim[1])
                ptr=self.get_dataptr()
                if int(ptr[0],16)==hirb.IRBG_RET_SUCCESS:                    
                    if img_type==1 or img_type==int('01000000',16): data_ptr=ct.cast(ptr[1],ct.POINTER(ct.c_uint32))
                    elif img_type==2: data_ptr=ct.cast(ptr[1],ct.POINTER(ct.c_uint16))
                    elif img_type==3: data_ptr=ct.cast(ptr[1],ct.POINTER(ct.c_float))
                    elif img_type==4: data_ptr=ct.cast(ptr[1],ct.POINTER(ct.c_uint8))
                    elif img_type==0: data_ptr=None #???
                    try:
                        image=np.ctypeslib.as_array(data_ptr,shape=img_shape).copy()
                        return (hex(hirb.IRBG_RET_SUCCESS), image)
                    except NotImplementedError:
                        return (hex(hirb.IRBG_RET_ERROR),)
                    # res=self.free_mem() 
                else: return (ptr[0],)
            else: return (dim[0],)
        else: return (res,)
    
    '''End of image acquisition'''
    
    def isinit(self):
        """
        Um zu ermitteln wie oft die Init-Funktion aufgerufen wurde, kann mittels der Funktion
        IsInit diese Anzahl abgerufen werden. Ein Wert größer Null weist auf eine initialisierte DLL
        hin.
        """
        i = ct.c_int32()
        
        self.irbgrab_dll.irbgrab_dll_isinit(ct.byref(i))
        return i.value
    
    def toggle_window(self,state): #state=0 -> close, state=1 -> open
        if state: res=self.setparam_int32(hirb.IRBG_PARAM_LiveWindow, hirb.IRBG_WINDOW_SHOW)
        else: res=self.setparam_int32(hirb.IRBG_PARAM_LiveWindow, hirb.IRBG_WINDOW_CLOSE)
        return res
    def show_remote(self, state):
        if state: res=self.setparam_int32(hirb.IRBG_PARAM_RemoteWindow, hirb.IRBG_WINDOW_SHOW)
        else: res=self.setparam_int32(hirb.IRBG_PARAM_RemoteWindow, hirb.IRBG_WINDOW_CLOSE)
        return res
    '''Start of disconnection'''
    
    def stopgrab(self,index):
        res=self.irbgrab_dll.irbgrab_dev_stopgrab(self._handle, index)
        res=res & MASK
        return hex(res)
    
    def disconnect(self):
        res=self.irbgrab_dll.irbgrab_dev_disconnect(self._handle)
        res=res & MASK
        return hex(res)
        
    def free(self):
        res=self.irbgrab_dll.irbgrab_dev_free(self._handle)
        res=res & MASK
        if res==hirb.IRBG_RET_SUCCESS: self._handle=None
        return hex(res)
    
    '''Ende Verbindungsabbau'''    


def test():
    """
    For this example to work, you need at least the PSM and CIM!
    """
    irbgrab_dll = getDLLHandle()
    irbgrab=irbgrab_obj(irbgrab_dll)
    print(irbgrab.version())
    #irbgrab.create(0,"E:\Projekte\Python\QtPython3.6\irbgrab\itcamimgir32_win64.ini")
    #irbgrab.connect('')
    #irbgrab.startgrab(0)
    #irbgrab.toggle_window()
    #irbgrab.setparam_int32(111,1)
    print('available devices: {}'.format(irbgrab.availabledevices()))
    print('creating device: {}'.format(irbgrab.create(2,'')))
    print('searching for cameras: {}'.format(irbgrab.search()))
    print('connecting to camera: {}'.format(irbgrab.connect('')))
    print('camera Serial #: {}'.format(irbgrab.getparam_int64(211)))
    # irbgrab.startgrab(0)
    # irbgrab.toggle_window(1)
    irbgrab.setparam_int32(113,1)
    # return irbgrab

if __name__ == '__main__':
    pass
    x = test()

