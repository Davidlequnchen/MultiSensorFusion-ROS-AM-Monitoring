;; Auto-generated. Do not edit!


(when (boundp 'camera_control_msgs::currentParams)
  (if (not (find-package "CAMERA_CONTROL_MSGS"))
    (make-package "CAMERA_CONTROL_MSGS"))
  (shadow 'currentParams (find-package "CAMERA_CONTROL_MSGS")))
(unless (find-package "CAMERA_CONTROL_MSGS::CURRENTPARAMS")
  (make-package "CAMERA_CONTROL_MSGS::CURRENTPARAMS"))

(in-package "ROS")
;;//! \htmlinclude currentParams.msg.html
(if (not (find-package "SENSOR_MSGS"))
  (ros::roseus-add-msgs "sensor_msgs"))


(defclass camera_control_msgs::currentParams
  :super ros::object
  :slots (_offset_x _offset_y _reverse_x _reverse_y _black_level _pgi_mode _demosaicing_mode _noise_reduction _sharpness_enhancement _light_source_preset _balance_white_auto _sensor_readout_mode _acquisition_frame_count _trigger_selector _trigger_mode _trigger_source _trigger_activation _trigger_delay _user_set_selector _user_set_default_selector _is_sleeping _brightness _exposure _gain _gamma _binning_x _binning_y _roi _available_image_encoding _current_image_encoding _current_image_ros_encoding _sucess _message ))

(defmethod camera_control_msgs::currentParams
  (:init
   (&key
    ((:offset_x __offset_x) 0)
    ((:offset_y __offset_y) 0)
    ((:reverse_x __reverse_x) nil)
    ((:reverse_y __reverse_y) nil)
    ((:black_level __black_level) 0)
    ((:pgi_mode __pgi_mode) 0)
    ((:demosaicing_mode __demosaicing_mode) 0)
    ((:noise_reduction __noise_reduction) 0.0)
    ((:sharpness_enhancement __sharpness_enhancement) 0.0)
    ((:light_source_preset __light_source_preset) 0)
    ((:balance_white_auto __balance_white_auto) 0)
    ((:sensor_readout_mode __sensor_readout_mode) 0)
    ((:acquisition_frame_count __acquisition_frame_count) 0)
    ((:trigger_selector __trigger_selector) 0)
    ((:trigger_mode __trigger_mode) 0)
    ((:trigger_source __trigger_source) 0)
    ((:trigger_activation __trigger_activation) 0)
    ((:trigger_delay __trigger_delay) 0.0)
    ((:user_set_selector __user_set_selector) 0)
    ((:user_set_default_selector __user_set_default_selector) 0)
    ((:is_sleeping __is_sleeping) nil)
    ((:brightness __brightness) 0.0)
    ((:exposure __exposure) 0.0)
    ((:gain __gain) 0.0)
    ((:gamma __gamma) 0.0)
    ((:binning_x __binning_x) 0)
    ((:binning_y __binning_y) 0)
    ((:roi __roi) (instance sensor_msgs::RegionOfInterest :init))
    ((:available_image_encoding __available_image_encoding) (let (r) (dotimes (i 0) (push "" r)) r))
    ((:current_image_encoding __current_image_encoding) "")
    ((:current_image_ros_encoding __current_image_ros_encoding) "")
    ((:sucess __sucess) nil)
    ((:message __message) "")
    )
   (send-super :init)
   (setq _offset_x (round __offset_x))
   (setq _offset_y (round __offset_y))
   (setq _reverse_x __reverse_x)
   (setq _reverse_y __reverse_y)
   (setq _black_level (round __black_level))
   (setq _pgi_mode (round __pgi_mode))
   (setq _demosaicing_mode (round __demosaicing_mode))
   (setq _noise_reduction (float __noise_reduction))
   (setq _sharpness_enhancement (float __sharpness_enhancement))
   (setq _light_source_preset (round __light_source_preset))
   (setq _balance_white_auto (round __balance_white_auto))
   (setq _sensor_readout_mode (round __sensor_readout_mode))
   (setq _acquisition_frame_count (round __acquisition_frame_count))
   (setq _trigger_selector (round __trigger_selector))
   (setq _trigger_mode (round __trigger_mode))
   (setq _trigger_source (round __trigger_source))
   (setq _trigger_activation (round __trigger_activation))
   (setq _trigger_delay (float __trigger_delay))
   (setq _user_set_selector (round __user_set_selector))
   (setq _user_set_default_selector (round __user_set_default_selector))
   (setq _is_sleeping __is_sleeping)
   (setq _brightness (float __brightness))
   (setq _exposure (float __exposure))
   (setq _gain (float __gain))
   (setq _gamma (float __gamma))
   (setq _binning_x (round __binning_x))
   (setq _binning_y (round __binning_y))
   (setq _roi __roi)
   (setq _available_image_encoding __available_image_encoding)
   (setq _current_image_encoding (string __current_image_encoding))
   (setq _current_image_ros_encoding (string __current_image_ros_encoding))
   (setq _sucess __sucess)
   (setq _message (string __message))
   self)
  (:offset_x
   (&optional __offset_x)
   (if __offset_x (setq _offset_x __offset_x)) _offset_x)
  (:offset_y
   (&optional __offset_y)
   (if __offset_y (setq _offset_y __offset_y)) _offset_y)
  (:reverse_x
   (&optional __reverse_x)
   (if __reverse_x (setq _reverse_x __reverse_x)) _reverse_x)
  (:reverse_y
   (&optional __reverse_y)
   (if __reverse_y (setq _reverse_y __reverse_y)) _reverse_y)
  (:black_level
   (&optional __black_level)
   (if __black_level (setq _black_level __black_level)) _black_level)
  (:pgi_mode
   (&optional __pgi_mode)
   (if __pgi_mode (setq _pgi_mode __pgi_mode)) _pgi_mode)
  (:demosaicing_mode
   (&optional __demosaicing_mode)
   (if __demosaicing_mode (setq _demosaicing_mode __demosaicing_mode)) _demosaicing_mode)
  (:noise_reduction
   (&optional __noise_reduction)
   (if __noise_reduction (setq _noise_reduction __noise_reduction)) _noise_reduction)
  (:sharpness_enhancement
   (&optional __sharpness_enhancement)
   (if __sharpness_enhancement (setq _sharpness_enhancement __sharpness_enhancement)) _sharpness_enhancement)
  (:light_source_preset
   (&optional __light_source_preset)
   (if __light_source_preset (setq _light_source_preset __light_source_preset)) _light_source_preset)
  (:balance_white_auto
   (&optional __balance_white_auto)
   (if __balance_white_auto (setq _balance_white_auto __balance_white_auto)) _balance_white_auto)
  (:sensor_readout_mode
   (&optional __sensor_readout_mode)
   (if __sensor_readout_mode (setq _sensor_readout_mode __sensor_readout_mode)) _sensor_readout_mode)
  (:acquisition_frame_count
   (&optional __acquisition_frame_count)
   (if __acquisition_frame_count (setq _acquisition_frame_count __acquisition_frame_count)) _acquisition_frame_count)
  (:trigger_selector
   (&optional __trigger_selector)
   (if __trigger_selector (setq _trigger_selector __trigger_selector)) _trigger_selector)
  (:trigger_mode
   (&optional __trigger_mode)
   (if __trigger_mode (setq _trigger_mode __trigger_mode)) _trigger_mode)
  (:trigger_source
   (&optional __trigger_source)
   (if __trigger_source (setq _trigger_source __trigger_source)) _trigger_source)
  (:trigger_activation
   (&optional __trigger_activation)
   (if __trigger_activation (setq _trigger_activation __trigger_activation)) _trigger_activation)
  (:trigger_delay
   (&optional __trigger_delay)
   (if __trigger_delay (setq _trigger_delay __trigger_delay)) _trigger_delay)
  (:user_set_selector
   (&optional __user_set_selector)
   (if __user_set_selector (setq _user_set_selector __user_set_selector)) _user_set_selector)
  (:user_set_default_selector
   (&optional __user_set_default_selector)
   (if __user_set_default_selector (setq _user_set_default_selector __user_set_default_selector)) _user_set_default_selector)
  (:is_sleeping
   (&optional __is_sleeping)
   (if __is_sleeping (setq _is_sleeping __is_sleeping)) _is_sleeping)
  (:brightness
   (&optional __brightness)
   (if __brightness (setq _brightness __brightness)) _brightness)
  (:exposure
   (&optional __exposure)
   (if __exposure (setq _exposure __exposure)) _exposure)
  (:gain
   (&optional __gain)
   (if __gain (setq _gain __gain)) _gain)
  (:gamma
   (&optional __gamma)
   (if __gamma (setq _gamma __gamma)) _gamma)
  (:binning_x
   (&optional __binning_x)
   (if __binning_x (setq _binning_x __binning_x)) _binning_x)
  (:binning_y
   (&optional __binning_y)
   (if __binning_y (setq _binning_y __binning_y)) _binning_y)
  (:roi
   (&rest __roi)
   (if (keywordp (car __roi))
       (send* _roi __roi)
     (progn
       (if __roi (setq _roi (car __roi)))
       _roi)))
  (:available_image_encoding
   (&optional __available_image_encoding)
   (if __available_image_encoding (setq _available_image_encoding __available_image_encoding)) _available_image_encoding)
  (:current_image_encoding
   (&optional __current_image_encoding)
   (if __current_image_encoding (setq _current_image_encoding __current_image_encoding)) _current_image_encoding)
  (:current_image_ros_encoding
   (&optional __current_image_ros_encoding)
   (if __current_image_ros_encoding (setq _current_image_ros_encoding __current_image_ros_encoding)) _current_image_ros_encoding)
  (:sucess
   (&optional __sucess)
   (if __sucess (setq _sucess __sucess)) _sucess)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; uint32 _offset_x
    4
    ;; uint32 _offset_y
    4
    ;; bool _reverse_x
    1
    ;; bool _reverse_y
    1
    ;; int32 _black_level
    4
    ;; int32 _pgi_mode
    4
    ;; int32 _demosaicing_mode
    4
    ;; float32 _noise_reduction
    4
    ;; float32 _sharpness_enhancement
    4
    ;; int32 _light_source_preset
    4
    ;; int32 _balance_white_auto
    4
    ;; int32 _sensor_readout_mode
    4
    ;; int32 _acquisition_frame_count
    4
    ;; int32 _trigger_selector
    4
    ;; int32 _trigger_mode
    4
    ;; int32 _trigger_source
    4
    ;; int32 _trigger_activation
    4
    ;; float32 _trigger_delay
    4
    ;; int32 _user_set_selector
    4
    ;; int32 _user_set_default_selector
    4
    ;; bool _is_sleeping
    1
    ;; float32 _brightness
    4
    ;; float32 _exposure
    4
    ;; float32 _gain
    4
    ;; float32 _gamma
    4
    ;; uint32 _binning_x
    4
    ;; uint32 _binning_y
    4
    ;; sensor_msgs/RegionOfInterest _roi
    (send _roi :serialization-length)
    ;; string[] _available_image_encoding
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _available_image_encoding)) 4
    ;; string _current_image_encoding
    4 (length _current_image_encoding)
    ;; string _current_image_ros_encoding
    4 (length _current_image_ros_encoding)
    ;; bool _sucess
    1
    ;; string _message
    4 (length _message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _offset_x
       (write-long _offset_x s)
     ;; uint32 _offset_y
       (write-long _offset_y s)
     ;; bool _reverse_x
       (if _reverse_x (write-byte -1 s) (write-byte 0 s))
     ;; bool _reverse_y
       (if _reverse_y (write-byte -1 s) (write-byte 0 s))
     ;; int32 _black_level
       (write-long _black_level s)
     ;; int32 _pgi_mode
       (write-long _pgi_mode s)
     ;; int32 _demosaicing_mode
       (write-long _demosaicing_mode s)
     ;; float32 _noise_reduction
       (sys::poke _noise_reduction (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _sharpness_enhancement
       (sys::poke _sharpness_enhancement (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; int32 _light_source_preset
       (write-long _light_source_preset s)
     ;; int32 _balance_white_auto
       (write-long _balance_white_auto s)
     ;; int32 _sensor_readout_mode
       (write-long _sensor_readout_mode s)
     ;; int32 _acquisition_frame_count
       (write-long _acquisition_frame_count s)
     ;; int32 _trigger_selector
       (write-long _trigger_selector s)
     ;; int32 _trigger_mode
       (write-long _trigger_mode s)
     ;; int32 _trigger_source
       (write-long _trigger_source s)
     ;; int32 _trigger_activation
       (write-long _trigger_activation s)
     ;; float32 _trigger_delay
       (sys::poke _trigger_delay (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; int32 _user_set_selector
       (write-long _user_set_selector s)
     ;; int32 _user_set_default_selector
       (write-long _user_set_default_selector s)
     ;; bool _is_sleeping
       (if _is_sleeping (write-byte -1 s) (write-byte 0 s))
     ;; float32 _brightness
       (sys::poke _brightness (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _exposure
       (sys::poke _exposure (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _gain
       (sys::poke _gain (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _gamma
       (sys::poke _gamma (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint32 _binning_x
       (write-long _binning_x s)
     ;; uint32 _binning_y
       (write-long _binning_y s)
     ;; sensor_msgs/RegionOfInterest _roi
       (send _roi :serialize s)
     ;; string[] _available_image_encoding
     (write-long (length _available_image_encoding) s)
     (dolist (elem _available_image_encoding)
       (write-long (length elem) s) (princ elem s)
       )
     ;; string _current_image_encoding
       (write-long (length _current_image_encoding) s) (princ _current_image_encoding s)
     ;; string _current_image_ros_encoding
       (write-long (length _current_image_ros_encoding) s) (princ _current_image_ros_encoding s)
     ;; bool _sucess
       (if _sucess (write-byte -1 s) (write-byte 0 s))
     ;; string _message
       (write-long (length _message) s) (princ _message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _offset_x
     (setq _offset_x (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _offset_y
     (setq _offset_y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _reverse_x
     (setq _reverse_x (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _reverse_y
     (setq _reverse_y (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int32 _black_level
     (setq _black_level (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _pgi_mode
     (setq _pgi_mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _demosaicing_mode
     (setq _demosaicing_mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _noise_reduction
     (setq _noise_reduction (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _sharpness_enhancement
     (setq _sharpness_enhancement (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; int32 _light_source_preset
     (setq _light_source_preset (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _balance_white_auto
     (setq _balance_white_auto (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _sensor_readout_mode
     (setq _sensor_readout_mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _acquisition_frame_count
     (setq _acquisition_frame_count (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _trigger_selector
     (setq _trigger_selector (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _trigger_mode
     (setq _trigger_mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _trigger_source
     (setq _trigger_source (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _trigger_activation
     (setq _trigger_activation (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _trigger_delay
     (setq _trigger_delay (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; int32 _user_set_selector
     (setq _user_set_selector (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _user_set_default_selector
     (setq _user_set_default_selector (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _is_sleeping
     (setq _is_sleeping (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float32 _brightness
     (setq _brightness (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _exposure
     (setq _exposure (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _gain
     (setq _gain (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _gamma
     (setq _gamma (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint32 _binning_x
     (setq _binning_x (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _binning_y
     (setq _binning_y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; sensor_msgs/RegionOfInterest _roi
     (send _roi :deserialize buf ptr-) (incf ptr- (send _roi :serialization-length))
   ;; string[] _available_image_encoding
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _available_image_encoding (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _available_image_encoding i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;; string _current_image_encoding
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _current_image_encoding (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _current_image_ros_encoding
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _current_image_ros_encoding (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; bool _sucess
     (setq _sucess (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get camera_control_msgs::currentParams :md5sum-) "0bd1503e3cdf30ac14ba73c781326a32")
(setf (get camera_control_msgs::currentParams :datatype-) "camera_control_msgs/currentParams")
(setf (get camera_control_msgs::currentParams :definition-)
      "uint32 offset_x # -20000 = Error	
uint32 offset_y # -20000 = Error
bool reverse_x
bool reverse_y

int32 black_level # -10000 = error/not available

int32 pgi_mode # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Off, 1 = On
int32 demosaicing_mode # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Simple, 1 = BaslerPGI
float32 noise_reduction # -20000.0 = Error, -10000.0 = Not available 
float32 sharpness_enhancement # -20000.0 = Error, -10000.0 = Not available 
int32 light_source_preset # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Off, 1 = Daylight5000K, 2 = Daylight6500K, 3 = Tungsten2800K
int32 balance_white_auto # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Off, 1 = Once, 2 = Continuous

int32 sensor_readout_mode # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Normal, 1 = Fast
int32 acquisition_frame_count # -20000 = Error, -10000 = Not available 
int32 trigger_selector # -3 = Unknown, -2 = Error, -1 = Not available, 0 = FrameStart, 1 = FrameBurstStart(USB)/AcquisitionStart(GigE)
int32 trigger_mode # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Off, 1 = On
int32 trigger_source # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Software, 1 = Line1, 2 = Line3, 3 = Line4, 4 = Action1(Selected Gige)
int32 trigger_activation # -3 = Unknown, -2 = Error, -1 = Not available, 0 = RisingEdge, 1 = FallingEdge
float32 trigger_delay # -20000.0 = Error, -10000.0 = Not available 

int32 user_set_selector # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw
int32 user_set_default_selector # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw 

bool is_sleeping
float32 brightness
float32 exposure
float32 gain
float32 gamma 
uint32 binning_x
uint32 binning_y
sensor_msgs/RegionOfInterest roi

string[] available_image_encoding
string current_image_encoding
string current_image_ros_encoding

bool sucess
string message


================================================================================
MSG: sensor_msgs/RegionOfInterest
# This message is used to specify a region of interest within an image.
#
# When used to specify the ROI setting of the camera when the image was
# taken, the height and width fields should either match the height and
# width fields for the associated image; or height = width = 0
# indicates that the full resolution image was captured.

uint32 x_offset  # Leftmost pixel of the ROI
                 # (0 if the ROI includes the left edge of the image)
uint32 y_offset  # Topmost pixel of the ROI
                 # (0 if the ROI includes the top edge of the image)
uint32 height    # Height of ROI
uint32 width     # Width of ROI

# True if a distinct rectified ROI should be calculated from the \"raw\"
# ROI in this message. Typically this should be False if the full image
# is captured (ROI not used), and True if a subwindow is captured (ROI
# used).
bool do_rectify

")



(provide :camera_control_msgs/currentParams "0bd1503e3cdf30ac14ba73c781326a32")


