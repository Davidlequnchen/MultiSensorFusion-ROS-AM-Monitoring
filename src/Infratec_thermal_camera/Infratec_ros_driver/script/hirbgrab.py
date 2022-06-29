"""
header for the irbgrab dll python wrapper
"""
#!/usr/bin/env python
# Filename: hirbgrab.py

#import sys
import ctypes as ct
import os
#from _ctypes import FreeLibrary

'Parameter for SET/GETPARAM'
IRBG_PARAM_OnNewFrame           = 103# IRBG_DATATYPE_CALLBACK Mit diesen Parameter wird die CallBack für neue Bilder übergeben. Der Aufbau der Callback-Funktion ist in Kapitel 2.2.1 onNewFrame (IRBG_PARAM_OnNewFrame) beschrieben.
IRBG_PARAM_RemoteWindow         = 111# Int32 mit IRBG_WINDOW_xxx (Kapitel 1.2.2)
IRBG_PARAM_LiveWindow           = 113# Int32 mit IRBG_WINDOW_xxx (Kapitel 1.2.2)
IRBG_PARAM_Calib_FlipH          = 114# DATATYPE_INT32 as Boolean (just get) IRBG_PARAM_Calib_FlipV = 115# DATATYPE_INT32 as Boolean (just get)
IRBG_PARAM_Calib_Window         = 116# IRBG_WindowMode (just get)
IRBG_PARAM_Calib_MaxFrameRate   = 117# IRBG_DATATYPE_SINGLE [Hz] (just get)
IRBG_PARAM_Calib_Changed        = 118# keine Parameter
IRBG_PARAM_Calib_Count          = 119# IRBG_DATATYPE_INT32 (just get)
IRBG_PARAM_Calib_Index          = 120# IRBG_DATATYPE_INT32 oder IRBG_DATATYPE_IDXINT32 set/get Calib
IRBG_PARAM_Calib_Name           = 121# IRBG_DATATYPE_IDXString
IRBG_PARAM_Calib_InvalidCount   = 122# IRBG_DATATYPE_INT32 Falls beim Laden der Kalibrierung inkonsistenzen aufgetreten sind, kann die Anzahl der Fehler mit diesen Paramter abgerufen warden.
IRBG_PARAM_Calib_InvalidName    = 123# IRBG_DATATYPE_IDXString Mit diesen Paramter wird der Fehler näher beschrieben. [0 <= Index < IRBG_PARAM_CALIB_InvalidCount]
IRBG_PARAM_Calib_Framerate      = 127# IRBG_DATATYPE_INT32 as Boolean If True, the frequency stored in the calib file is set when changing calibs
IRBG_PARAM_SDK_SpeedTest        = 180# IRBG_DATATYPE_INT32 as Boolean If the value is TRUE, no image is transferred to the CallBack function. ShowWindow shows the possible frame rate without any influence from the user program.
IRBG_PARAM_SDK_NeedBitmap32     = 181# IRBG_DATATYPE_INT32 as Boolean Should be set to TRUE if IRBG_MEMOBJ_BITMAP32 is needed.

IRBG_PARAM_CameraDevice_Count       = 200# IRBG_DATATYPE_INT32 (just get)
IRBG_PARAM_CameraDevice_Info        = 201# IRBG_DATATYPE_IDXString [0 <= Index < IRBG_PARAM_CameraDevice_Count] Der String-Wert enthält die Kamerainformationen.
IRBG_PARAM_CameraDevice_ConnectStr  = 202# IRBG_DATATYPE_IDXString (just get) Kann bei der Funktion irbgrab_dev_connect (Kapitel 2.3.5) als Parameter übergeben werden.
IRBG_PARAM_CameraName               = 203# IRBG_DATATYPE_String (just get)
IRBG_PARAM_Camera_Connected         = 210# IRBG_DATATYPE_INT32 as Boolean (just get)
IRBG_PARAM_Camera_SerialNum         = 211# IRBG_DATATYPE_INT64 (just get)
IRBG_PARAM_Camera_State             = 212# IRBG_DATATYPE_INT32
IRBG_PARAM_Camera_Temperature       = 213# IRBG_DATATYPE_IDXSingle [Kelvin]
IRBG_PARAM_Camera_Temperature_Name  = 214# IRBG_DATATYPE_IDXSingle
IRBG_PARAM_Camera_Standby           = 215# IRBG_DATATYPE_INT32 as Boolean
IRBG_PARAM_Camera_Version           = 216# IRBG_DATATYPE_IDXString 'Object###Version'
IRBG_PARAM_Camera_Temp_Housing      = 217# IRBG_DATATYPE_SINGLE [Kelvin]
IRBG_PARAM_Camera_Temp_Shutter      = 218# IRBG_DATATYPE_SINGLE [Kelvin]
IRBG_PARAM_Camera_NUC               = 220# IRBG_DATATYPE_INT32 (as Boolean)
IRBG_PARAM_Camera_BPR               = 222# IRBG_DATATYPE_INT32 (as Boolean)
IRBG_PARAM_Stream_Count             = 229# IRBG_DATATYPE_INT32
IRBG_PARAM_SendCommand              = 231# IRBG_DATATYPE_SENDCMD
IRBG_PARAM_Framerate_Hz             = 240# IRBG_DATATYPE_SINGLE [Hz]
IRBG_PARAM_Framerate_Max            = 241# IRBG_DATATYPE_SINGLE [Hz]
IRBG_PARAM_MIT_Count                = 260# IRBG_DATATYPE_INT32
IRBG_PARAM_MIT_MAX_Count            = 261# IRBG_DATATYPE_INT32
IRBG_PARAM_IntegTime                = 262# IRBG_DATATYPE_IDXINT32 Value [uSec]
IRBG_PARAM_MIT_Name                 = 263# IRBG_DATATYPE_STRING
IRBG_PARAM_Sensor_Width             = 280# IRBG_DATATYPE_INT32
IRBG_PARAM_Sensor_Height            = 281# IRBG_DATATYPE_INT32
IRBG_PARAM_Frame_FlipH              = 290# IRBG_DATATYPE_INT32 als Boolean
IRBG_PARAM_Frame_FlipV              = 291# IRBG_DATATYPE_INT32 als Boolean
IRBG_PARAM_Frame_Offsetx            = 292# IRBG_DATATYPE_INT32
IRBG_PARAM_Frame_Offsety            = 293# IRBG_DATATYPE_INT32
IRBG_PARAM_Frame_Width              = 294# IRBG_DATATYPE_INT32
IRBG_PARAM_Frame_Height             = 295# IRBG_DATATYPE_INT32

IRBG_PARAM_WindowMode_Prop              = 310# IRBG_DATATYPE_WINDOWMODE
IRBG_PARAM_WindowMode_Idx               = 311# IRBG_DATATYPE_INT32
IRBG_PARAM_Filter_Count                 = 320# IRBG_DATATYPE_INT32
IRBG_PARAM_Filter_PosIdx                = 321# IRBG_DATATYPE_INT32
IRBG_PARAM_Filter_PosIdxLive            = 322# IRBG_DATATYPE_INT32
IRBG_PARAM_Aperture_Count               = 330# IRBG_DATATYPE_INT32
IRBG_PARAM_Aperture_PosIdx              = 331# IRBG_DATATYPE_INT32
IRBG_PARAM_Aperture_PosIdxLive          = 332# IRBG_DATATYPE_INT32
IRBG_PARAM_Trigger_GateItemCount        = 340# IRBG_DATATYPE_INT32 = Anzahl der TriggerGate-Optionen
IRBG_PARAM_Trigger_GateItem             = 341# IRBG_DATATYPE_IDXString = Index muss gesetzt sein
IRBG_PARAM_Trigger_GateIdx              = 342# IRBG_DATATYPE_INT32 = Index
IRBG_PARAM_Trigger_MarkItemCount        = 343# IRBG_DATATYPE_INT32 = Anzahl der TriggerMark-Optionen
IRBG_PARAM_Trigger_MarkItem             = 344# IRBG_DATATYPE_IDXString = Index muss gesetzt sein
IRBG_PARAM_Trigger_MarkIdx              = 345# IRBG_DATATYPE_INT32 = Index
IRBG_PARAM_Trigger_SyncItemCount        = 346# IRBG_DATATYPE_INT32 = Anzahl der TriggerSync-Optionen
IRBG_PARAM_Trigger_SyncItem             = 347# IRBG_DATATYPE_IDXString = Index muss gesetzt sein
IRBG_PARAM_Trigger_SyncIdx              = 348# IRBG_DATATYPE_INT32 = Index
IRBG_PARAM_Trigger_Out1Name             = 349# IRBG_DATATYPE_String
IRBG_PARAM_Trigger_Out1ItemCount        = 350# IRBG_DATATYPE_INT32 = Anzahl der TriggerOut1-Optionen
IRBG_PARAM_Trigger_Out1Item             = 351# IRBG_DATATYPE_IDXString = Index muss gesetzt sein
IRBG_PARAM_Trigger_Out1Idx              = 352# IRBG_DATATYPE_INT32 = Index
IRBG_PARAM_Trigger_Out2Name             = 353# IRBG_DATATYPE_String
IRBG_PARAM_Trigger_Out2ITemCount        = 354# IRBG_DATATYPE_INT32 = Anzahl der TriggerOut2-Optionen
IRBG_PARAM_Trigger_Out2Item             = 355# IRBG_DATATYPE_IDXString = Index muss gesetzt sein
IRBG_PARAM_Trigger_Out2Idx              = 356# IRBG_DATATYPE_INT32 = Index
IRBG_PARAM_TriggerImg_ValueItemCnt      = 357# IRBG_DATATYPE_INT32
IRBG_PARAM_TriggerImg_ValueItem         = 358# IRBG_DATATYPE_IDXString = Index muss gesetzt sein
IRBG_PARAM_TriggerImg_ValueIdx          = 359# IRBG_DATATYPE_INT32 = Index
IRBG_PARAM_TriggerImg_OperationItemCnt  = 360# IRBG_DATATYPE_INT32
IRBG_PARAM_TriggerImg_OperationItem     = 361# IRBG_DATATYPE_IDXString
IRBG_PARAM_TriggerImg_OperationIndex    = 362# IRBG_DATATYPE_INT32
IRBG_PARAM_TriggerImg_Threshold         = 363# IRBG_DATATYPE_SINGLE [Kelvin]
IRBG_PARAM_TriggerImg_LivePixelCount    = 364# IRBG_DATATYPE_INT32
IRBG_PARAM_TriggerImg_LivePixelFast     = 365# IRBG_DATATYPE_INT32 als Bool
IRBG_PARAM_TriggerImg_SyncModeItemCnt   = 366# IRBG_DATATYPE_INT32
IRBG_PARAM_TriggerImg_SyncModeItem      = 367# IRBG_DATATYPE_IDXString
IRBG_PARAM_TriggerImg_SyncModeIndex     = 368# IRBG_DATATYPE_INT32
IRBG_PARAM_TriggerImg_Invert            = 369# IRBG_DATATYPE_INT32 als Bool
IRBG_PARAM_TriggerImg_DelayLow          = 370# IRBG_DATATYPE_INT32
IRBG_PARAM_TriggerImg_DelayHigh         = 371# IRBG_DATATYPE_INT32
IRBG_PARAM_Trigger_Divider              = 372# IRBG_DATATYPE_INT32
IRBG_PARAM_Acq_FrameCount               = 380# IRBG_DATATYPE_INT32 <0 AcqModulo ausgeschaltet# MaxFrameCount = abs(Value)
IRBG_PARAM_Acq_Trigger                  = 381# IRBG_DATATYPE_INT32 als Boolean
IRBG_PARAM_Acq_LineCount                = 382# IRBG_DATATYPE_INT32
IRBG_PARAM_Acq_LineIndex                = 383# IRBG_DATATYPE_INT32
IRBG_PARAM_Acq_Waterfall                = 384# IRBG_DATATYPE_INT32 Waterfall = Value <> 0
IRBG_PARAM_Acq_useFrameCount            = 385# IRBG_DATATYPE_INT32
IRBG_PARAM_Acq_useLineCount             = 386# IRBG_DATATYPE_INT32
IRBG_PARAM_Acq_useLineIndex             = 387# IRBG_DATATYPE_INT32

IRBG_PARAM_DateTime                     = 400# IRBG_DATATYPE_DOUBLE
IRBG_PARAM_DateTime_IRIG                = 401# IRBG_DATATYPE_DOUBLE
IRBG_PARAM_NUC_active                   = 410# IRBG_DATATYPE_INT32 als Boolen
IRBG_PARAM_NUC_Interval                 = 415# IRBG_DATATYPE_INT32 in Sekunden (0=off)
IRBG_PARAM_BPR_Active                   = 430# IRBG_DATATYPE_INT32 als Boolen BPR = BadPixelReplacement
IRBG_PARAM_Focus_DeviceCount            = 460# IRBG_DATATYPE_INT32
IRBG_PARAM_Focus_DeviceIndex            = 461# IRBG_DATATYPE_INT32
IRBG_PARAM_Focus_Init                   = 462# IRBG_DATATYPE_INT32 = DeviceIndex
IRBG_PARAM_Focus_DistRange              = 463# IRBG_DATATYPE_SINGLE
IRBG_PARAM_Focus_PosRel                 = 464# IRBG_DATATYPE_SINGLE [0..100%]
IRBG_PARAM_Focus_PosRelSpeed            = 465# IRBG_DATATYPE_SINGLE [0..100%]
IRBG_PARAM_Focus_PosDistWant            = 466# IRBG_DATATYPE_SINGLE [m] setzt Entfernung
IRBG_PARAM_Focus_PosDistLive            = 467# IRBG_DATATYPE_SINGLE [m] holt die aktuelle Entfernung
IRBG_PARAM_Focus_MoveRel                = 468# IRBG_DATATYPE_SINGLE [-1..0=Stopp..1] definiert Geschwindigkeit und Richtung
IRBG_PARAM_Focus_Auto                   = 469# kein Parameter
IRBG_PARAM_ProcIO_AnalogInCount         = 490# IRBG_DATATYPE_INT32
IRBG_PARAM_ProcIO_AnalogInActive        = 491# IRBG_DATATYPE_IDXINT32 as Boolean
IRBG_PARAM_ProcIO_AnalogOutCount        = 492# IRBG_DATATYPE_INT32
IRBG_PARAM_ProcIO_AnalogOutChModeCnt    = 493# IRBG_DATATYPE_IDXINT32
IRBG_PARAM_ProcIO_AnalogOutChModeName   = 494# IRBG_DATATYPE_2IdxString
IRBG_PARAM_ProcIO_AnalogOutChModeIdx    = 495# IRBG_DATATYPE_IDXINT32
IRBG_PARAM_ProcIO_AnalogOutChFreq       = 496# IRBG_DATATYPE_IDXSingle
IRBG_PARAM_ProcIO_AnalogOutChVolt       = 497# IRBG_DATATYPE_IDXSingle

IRBG_PARAM_ScaleForm_TempUnit       = 600# IRBG_DATATYPE_INT32 setzt/holt die Temperatureinheit (siehe IRBG_TEMPUNIT_XXX)
IRBG_PARAM_ScaleForm_TempRangeMode  = 601# IRBG_DATATYPE_INT32 sets / gets the temperature range mode (see IRBG_TEMP_RNG_MODE_XXX)
IRBG_PARAM_ScaleForm_TempRangeTill  = 602# IRBG_DATATYPE_DOUBLE sets / fetches the upper temperature of the pallet
IRBG_PARAM_ScaleForm_TempRangeFrom  = 603# IRBG_DATATYPE_DOUBLE sets / fetches the lower temperature of the pallet
IRBG_PARAM_ScaleForm_PaletteCount   = 604# IRBG_DATATYPE_INT32 gets the number of available pallets
IRBG_PARAM_ScaleForm_PaletteName    = 605# IRBG_DATATYPE_IDXString gets the name of the pallet via index
IRBG_PARAM_ScaleForm_PaletteIdx     = 606# IRBG_DATATYPE_INT32 sets / fetches the index of the pallet

IRBG_PARAM_IRBcorr_ObjEps           = 700# IRBG_DATATYPE_IDXSingle idxLoWord = 0 --> Global Corr
IRBG_PARAM_IRBcorr_ObjTau           = 701# IRBG_DATATYPE_IDXSingle idxHiWord = 0 --> Global Corr
IRBG_PARAM_IRBcorr_ObjRho           = 702# ITCAM_DATATYPE_IDXSingle idx = 0 --> Global Corr
IRBG_PARAM_IRBcorr_ObjTempEnv       = 703# IRBG_DATATYPE_IDXSingle idx = 0 --> Global Corr
IRBG_PARAM_IRBcorr_ObjTempBackGrd   = 704# IRBG_DATATYPE_IDXSingle idx = 0 --> Global Corr
IRBG_PARAM_IRBCorr_PathCount       = 705# IRBG_DATATYPE_IDXINT32 idx = 0 --> Global Corr else CorrShape
IRBG_PARAM_IRBcorr_SimpleEps       = 706# IRBG_DATATYPE_IDXSingle idx = 0 --> Global Corr else CorrShape
IRBG_PARAM_IRBcorr_SimpleTau       = 707# IRBG_DATATYPE_IDXSingle idx = 0 --> Global Corr else CorrShape
IRBG_PARAM_IRBcorr_SimpleEnvTemp   = 708# IRBG_DATATYPE_IDXSingle idx = 0 --> Global Corr else CorrShape
IRBG_PARAM_IRBcorr_SimplePathTemp  = 709# IRBG_DATATYPE_IDXSingle idx = 0 --> Global Corr else CorrShape

'Temperature unit constants'
IRBG_TEMPUNIT_Kelvin        = 1#
IRBG_TEMPUNIT_Celsius       = 2#
IRBG_TEMPUNIT_Fahrenheit    = 3#
IRBG_TEMPUNIT_DigitalValue  = 9#
IRBG_TEMPUNIT_MilliKelvin   = 10#

'Camera status constants'
IRBG_STATE_Unknown              = 0#  User defined
IRBG_STATE_Cooling              = 1#  Kamera befindet sich im Einkühlen
IRBG_STATE_Standby              = 2#  Kamera befindet sich im StandBy
IRBG_STATE_Initialization       = 3#  Kamera befindet sich in der Initialisierung
IRBG_STATE_Working              = 4#  Kamera betriebsbereit
IRBG_STATE_ErrorTempCooler      = 5#  Kamera-Kühler-Temperatur ist kritisch
IRBG_STATE_ErrorTempCamera      = 6#  Kamera-Temperatur ist kritisch
IRBG_STATE_Error                = 7#  allgemeiner undefinierter Fehler
IRBG_STATE_notFound             = 8#  Kamera wurde nicht gefunden
IRBG_STATE_invalidCalibration   = 9#  Kalibrierung ist ungültig

'DLL-Temperature range modes constants'
IRBG_TEMP_RNG_MODE_USER         = 0#  User defined
IRBG_TEMP_RNG_MODE_AutoImg      = 1#  unique ObjectTemp
IRBG_TEMP_RNG_MODE_ObjTemp      = 2#  continuous spread over min / max of the scene
IRBG_TEMP_RNG_MODE_RangeShot    = 3#  as it was captured on the camera

'Storage object constants'
IRBG_MEMOBJ_NONE                = 0#
IRBG_MEMOBJ_BITMAP32            = 1# Bitmap with 32Bit per pixel (A, R, G, B) Only works if LiveWindow is active or IRBG_PARAM_SDK_NeedBitmap32 (= 181) switched on
IRBG_MEMOBJ_IR_DIGITFRAME       = 2# IR image with RAW 16 bits per pixel
IRBG_MEMOBJ_TEMPERATURES        = 3# IR image with Kelvin (single) per pixel
IRBG_MEMOBJ_8BITDATA            = 4# 8Bit-Daten (0 = minTemp # 255 = maxTemp)
IRBG_MEMOBJ_FLIPV               = 0x01000000# mirrors the frame vertically (y = height-y) Only works with ORed IRBG_MEMOBJ_BITMAP32

'DLL-Window constants'
IRBG_WINDOW_CLOSE               = -1# close the window
IRBG_WINDOW_TOGGLE              = 0# changes the status (closed  is opened, opened  is closed)
IRBG_WINDOW_SHOW                = 1# open the window
IRBG_WINDOW_MINIMIZE            = 2# minimizes the window
IRBG_WINDOW_RESTORE             = 3# restores windows after minimizing


'Rückgabewert Konstanten'

TIRBG_RetDef = {  '0x00000000': 'Undef',
                  '0x10000001': 'Success',
                  '0x20000001': 'StatusOk',
                  '0x20000002': 'Connecting',
                  '0x20000003': 'Connected',
                  '0x20000004': 'Running',
                  '0x20000005': 'CommunicationError',
                  '0x20000006': 'Disconnected',
                  '0x80000001': 'Error',
                  '0x80000002': 'NotSupported',
                  '0x80000003': 'NotFound',
                  '0x80000004': 'OutOfRange',
                  '0x80000005': 'Timeout',
                  '0x80000006': 'Blocked',
                  '0x80000007': 'Unassigned',
                  '0x80000008': 'Incompatible',
                  '0x80000009': 'BufferTooSmall',
                  '0x8000000A': 'ConfigError',
                  '0x8000000B': 'ConnectionError',
                  '0x8000000C': 'InvalidHandle',
                  '0x8000000D': 'InvalidDataSize',
                  '0x8000000E': 'InvalidDataPointer',
                  '0x8000000F': 'InvalidParameter',
                  '0x80000010': 'Terminated',
                  '0x80000012': 'HarddriveError',
                  '0x80000013': 'RamError',
                  '0x80000017': 'Invalid Licence'
                }

#const
IRBG_RET_TYPE_MASK              = 0xFFFFFFFF
#bits to distinguish return type
IRBG_RET_TYPE_OK                = 0x10000000
IRBG_RET_TYPE_STATUS            = 0x20000000
IRBG_RET_TYPE_RESERVED          = 0x40000000
IRBG_RET_TYPE_ERR               = 0x80000000
#no valid return value (should never be passed as argument or return value)
IRBG_RET_UNDEF                  = 0
#generic ok
IRBG_RET_SUCCESS                = IRBG_RET_TYPE_OK | 0x01
IRBG_RET_OK                     = IRBG_RET_SUCCESS
#status values
#generic ok status
IRBG_RET_STATUS_OK              = IRBG_RET_TYPE_STATUS | 0x01
#in the process of establishing a connection
IRBG_RET_CONNECTING             = IRBG_RET_TYPE_STATUS | 0x02
#connection is established, but no data has been exchanged yet
IRBG_RET_CONNECTED              = IRBG_RET_TYPE_STATUS | 0x03
#communication is up and running
IRBG_RET_RUNNING                = IRBG_RET_TYPE_STATUS | 0x04
#device has been connected and communicating before,
#but lost its connection (e.g. cable has fallen off, peer is down,...)
IRBG_RET_COMM_ERROR             = IRBG_RET_TYPE_STATUS | 0x05
#has been connected before and is gracefully disconnected
IRBG_RET_DISCONNECTED           = IRBG_RET_TYPE_STATUS | 0x06
#generic unspecified error
IRBG_RET_ERROR                  = IRBG_RET_TYPE_ERR | 0x01
#feature is not supported
IRBG_RET_NOT_SUPPORTED          = IRBG_RET_TYPE_ERR | 0x02
#generic "something" could not be found (maybe add some more specific errors later)
IRBG_RET_NOT_FOUND              = IRBG_RET_TYPE_ERR | 0x03
#argument is out of range
IRBG_RET_OUT_OF_RANGE           = IRBG_RET_TYPE_ERR | 0x04
#timeout elapsed
IRBG_RET_TIMEOUT                = IRBG_RET_TYPE_ERR | 0x05
#failed to enter some critical section
IRBG_RET_BLOCKED                = IRBG_RET_TYPE_ERR | 0x06
#something is unset/nil
IRBG_RET_UNASSIGNED             = IRBG_RET_TYPE_ERR | 0x07
#binary incompatibilities detected (e.g. struct sizes differ)
IRBG_RET_INCOMPATIBLE           = IRBG_RET_TYPE_ERR | 0x08
#buffer is too small (is not neccessarily an error)
IRBG_RET_BUFSIZE                = IRBG_RET_TYPE_ERR | 0x09
IRBG_RET_CONFIG_ERROR           = IRBG_RET_TYPE_ERR | 0x0A
#no connection could be established - device has never been connected
IRBG_RET_CONNECTION_ERROR       = IRBG_RET_TYPE_ERR | 0x0B
#invalid Handle
IRBG_RET_INVALID_HANDLE         = IRBG_RET_TYPE_ERR | 0x0C
#invalid DataSize
IRBG_RET_INVALID_DATASIZE       = IRBG_RET_TYPE_ERR | 0x0D
#invalid DataPointer
IRBG_RET_INVALID_DATAPOINTER    = IRBG_RET_TYPE_ERR | 0x0E
#invalid Parameter
IRBG_RET_INVALID_PARAMETER      = IRBG_RET_TYPE_ERR | 0x0F
#Object is Terminated
IRBG_RET_TERMINATED             = IRBG_RET_TYPE_ERR | 0x10


'''Datentypen'''
if 'posix' in os.name:
    IRBG_CALLBACK_FUNC = ct.CFUNCTYPE(ct.c_void_p, ct.py_object) #(c_void_p, c_void_p, c_uint64, c_int)
elif 'win' in os.name or 'nt' in os.name:
    IRBG_CALLBACK_FUNC = ct.WINFUNCTYPE(ct.c_void_p, ct.py_object) #(c_void_p, c_void_p, c_uint64, c_int)
else:
    raise Exception('Unknown operating system {}'.format(os.name))
class TIRBG_String(ct.Structure):
  _pack_ = 1
  _fields_ = [ ("Text", ct.c_char_p),
               ("Len", ct.c_int)]

'Index Datentypen'
class TIRBG_IdxPointer(ct.Structure):
  _pack_ = 1
  _fields_ = [ ("Index", ct.c_int),
					("value", ct.c_void_p)]
  
class TIRBG_IdxHandle(ct.Structure):
  _pack_ = 1
  _fields_ = [ ("Index", ct.c_int),
					("value", ct.c_uint64)]

class TIRBG_IdxInt32(ct.Structure):
  _pack_ = 1
  _fields_ = [ ("Index", ct.c_int),
					("value", ct.c_int32)]

class TIRBG_IdxInt64(ct.Structure):
  _pack_ = 1
  _fields_ = [	("Index", ct.c_int),
					("value", ct.c_int64)]

class TIRBG_IdxSingle(ct.Structure):
  _pack_ = 1
  _fields_ = [	("Index", ct.c_int),
					("value", ct.c_float)]

class TIRBG_IdxDouble(ct.Structure):
  _pack_ = 1
  _fields_ = [	("Index", ct.c_int),
					("value", ct.c_double)]

class TIRBG_IdxString(ct.Structure):
  _pack_ = 1
  _fields_ = [	("Index", ct.c_int),
					("value", TIRBG_String)]
    
'2er Datentypen'
class TIRBG_2Pointer(ct.Structure):
  _pack_ = 1
  _fields_ = [ ("FuncPtr", ct.c_void_p),
					("Context", ct.c_void_p)]

class TIRBG_2Int32(ct.Structure):
  _pack_ = 1
  _fields_ = [	("value1", ct.c_int32),
					("value2", ct.c_int32)]

class TIRBG_2Int64(ct.Structure):
  _pack_ = 1
  _fields_ = [	("value1", ct.c_int64),
					("value2", ct.c_int64)]

class TIRBG_2Single(ct.Structure):
  _pack_ = 1
  _fields_ = [	("value1", ct.c_float),
					("value2", ct.c_float)]

class  TIRBG_2Double(ct.Structure):
  _pack_ = 1
  _fields_ = [ ("value1", ct.c_double),
					("value2", ct.c_double)]

class  TIRBG_2String(ct.Structure):
  _pack_ = 1
  _fields_ = [ ("Text1", ct.c_char_p),
					("Len1", ct.c_int),
					("Text2", ct.c_char_p),
					("Len2", ct.c_int)]

class  TIRBG_2IdxString(ct.Structure):
  _pack_ = 1
  _fields_ = [	("val1", TIRBG_IdxString),
					("val2", TIRBG_IdxString)]
  
'other data types'
class TIRBG_CallBack(ct.Structure):
    _pack_ = 1
    _fields_ = [("FuncPtr", IRBG_CALLBACK_FUNC),
                ("Context", ct.py_object)]
    
class TIRBG_MemInfo(ct.Structure):
    _pack_ = 1
    _fields_ = [("StructSize", ct.c_int),
                ("Triggered", ct.c_int), #<> 0 --> getriggert
                ("TimeStamp", ct.c_double), #relative milliseconds
                ("ImageNum", ct.c_int64),
                ("MissedPackets", ct.c_int)]
class TIRBG_HeaderInfo(ct.Structure):
    _pack_ = 1
    _fields_ = [("StructSize", ct.c_int),
                ("AI", ct.c_float*8), # analogIn
                ("DI", ct.c_byte*8), #digitalIn
                ]
class  TIRBG_SendCommand(ct.Structure):
  _pack_ = 1
  _fields_ = [	("Command", ct.c_char_p),
					("Answer", ct.c_char_p),
					("AnswerSize", ct.c_int),
					("TimeoutMS", ct.c_int)]

class  TIRBG_WindowMode(ct.Structure):
    _pack_ = 1
    _fields_ = [
        ("Index", ct.c_int),
   		("CamIndex", ct.c_int),
   		("Offx", ct.c_int),
   	    ("Offy", ct.c_int),
   		("Width", ct.c_int),
   		("Height", ct.c_int),
		("Name", ct.c_char*32)
               ]

class TIRBG_SaveStruct(ct.Structure):
    _pack_ = 1
    _fields_ = [
        ('StructLength', ct.c_uint32),
        ('FileName', (ct.c_char*256)),
        ('WriteMode', ct.c_uint32),
        ('MaxFileSizeMB', ct.c_int64),
        ('MaxFrames', ct.c_int),
        ('MinDriveSizeMB', ct.c_int64),
            ]
  
'Datentyp constant'
IRBG_TYPE_RAW               = 0x00000000
IRBG_TYPE_POINTER           = 0x10000000
IRBG_TYPE_INT8              = 0x20000000
IRBG_TYPE_INT16             = 0x30000000
IRBG_TYPE_INT32             = 0x40000000
IRBG_TYPE_INT64             = 0x50000000
IRBG_TYPE_UINT8             = 0x60000000
IRBG_TYPE_UINT16            = 0x70000000
IRBG_TYPE_UINT32            = 0x80000000
IRBG_TYPE_UINT64            = 0x90000000
IRBG_TYPE_FLOAT32           = 0xA0000000
IRBG_TYPE_FLOAT64           = 0xB0000000
IRBG_TYPE_RECORD            = 0xE0000000 
IRBG_TYPE_STRING            = 0xF0000000# String wird immer als PAnsiChar + Len(integer) übergeben
IRBG_EXTTYP_MASK            = 0x0F000000
IRBG_EXTYPE_NONE            = 0x00000000
IRBG_EXTYPE_INDEX           = 0x01000000# besteht immer aus einen Index (Int32) + Wert
IRBG_EXTYPE_ARRAY           = 0x02000000# Array of DataType
IRBG_EXTYPE_IDXARRAY        = IRBG_EXTYPE_INDEX | IRBG_EXTYPE_ARRAY# Array of (Index(Int32) + Wert)
IRBG_EXTYPE_ARRAY2          = IRBG_EXTYPE_ARRAY | 0x00020000# Array[0..1] of DataType
IRBG_DATATYPE_POINTER       = IRBG_TYPE_POINTER | ct.sizeof(ct.c_void_p)
IRBG_DATATYPE_HANDLE        = IRBG_DATATYPE_POINTER
IRBG_DATATYPE_INT32         = IRBG_TYPE_INT32 | ct.sizeof(ct.c_int32)
IRBG_DATATYPE_INT64         = IRBG_TYPE_INT64 | ct.sizeof(ct.c_int64)
IRBG_DATATYPE_UINT16        = IRBG_TYPE_UINT16 | ct.sizeof(ct.c_uint16)
IRBG_DATATYPE_SINGLE        = IRBG_TYPE_FLOAT32 | ct.sizeof(ct.c_float)
IRBG_DATATYPE_DOUBLE        = IRBG_TYPE_FLOAT64 | ct.sizeof(ct.c_double)
IRBG_DATATYPE_STRING        = IRBG_TYPE_STRING | ct.sizeof(TIRBG_String)
IRBG_DATATYPE_IDXPOINTER    = IRBG_EXTYPE_INDEX | IRBG_TYPE_POINTER | ct.sizeof(TIRBG_IdxPointer)
IRBG_DATATYPE_IDXINT32      = IRBG_EXTYPE_INDEX | IRBG_TYPE_INT32 | ct.sizeof(TIRBG_IdxInt32)
IRBG_DATATYPE_IDXINT64      = IRBG_EXTYPE_INDEX | IRBG_TYPE_INT64 | ct.sizeof(TIRBG_IdxInt64)
IRBG_DATATYPE_IDXSingle     = IRBG_EXTYPE_INDEX | IRBG_TYPE_FLOAT32 | ct.sizeof(TIRBG_IdxSingle)
IRBG_DATATYPE_IDXDouble     = IRBG_EXTYPE_INDEX | IRBG_TYPE_FLOAT64 | ct.sizeof(TIRBG_IdxDouble)
IRBG_DATATYPE_IDXString     = IRBG_EXTYPE_INDEX | IRBG_TYPE_STRING | ct.sizeof(TIRBG_IdxString)
IRBG_DATATPYE_2POINTER      = IRBG_EXTYPE_ARRAY2 | IRBG_TYPE_POINTER | ct.sizeof(TIRBG_2Pointer)
IRBG_DATATYPE_2INT32        = IRBG_EXTYPE_ARRAY2 | IRBG_TYPE_INT32 | ct.sizeof(TIRBG_2Int32)
IRBG_DATATYPE_2INT64        = IRBG_EXTYPE_ARRAY2 | IRBG_TYPE_INT64 | ct.sizeof(TIRBG_2Int64)
IRBG_DATATYPE_2Single       = IRBG_EXTYPE_ARRAY2 | IRBG_TYPE_FLOAT32 | ct.sizeof(TIRBG_2Single)
IRBG_DATATYPE_2Double       = IRBG_EXTYPE_ARRAY2 | IRBG_TYPE_FLOAT64 | ct.sizeof(TIRBG_2Double)
IRBG_DATATYPE_2String       = IRBG_EXTYPE_ARRAY2 | IRBG_TYPE_STRING | ct.sizeof(TIRBG_2String)
IRBG_DATATYPE_2IdxString    = IRBG_EXTYPE_ARRAY2 | IRBG_DATATYPE_IDXString | ct.sizeof(TIRBG_2IdxString)
IRBG_DATATYPE_CALLBACK      = IRBG_DATATPYE_2POINTER
IRBG_DATATYPE_WINDOWMODE    = IRBG_TYPE_RECORD | ct.sizeof(TIRBG_WindowMode)
IRBG_DATATYPE_SENDCMD       = IRBG_TYPE_RECORD | ct.sizeof(TIRBG_SendCommand)




'''
def loadIRBGrabDll(pfad):
    libirbgrab = windll.LoadLibrary(pfad)
    return libirbgrab

def freeIRBGrabDll(libirbgrab):
    libirbgrab.irbgrab_dll_uninit()
    libHandle = libirbgrab._handle
    print( 'freeIRBGrabDll', libirbgrab, libHandle )
    # clean up by removing reference to the ctypes library object
    #unload the DLL
    #windll.kernel32.argtypes=[c_void_p]
    try:
        FreeLibrary(libHandle)
        del( libirbgrab )
        return True
    except:
        return False
'''    
    
