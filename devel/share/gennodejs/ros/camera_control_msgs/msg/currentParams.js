// Auto-generated. Do not edit!

// (in-package camera_control_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let sensor_msgs = _finder('sensor_msgs');

//-----------------------------------------------------------

class currentParams {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.offset_x = null;
      this.offset_y = null;
      this.reverse_x = null;
      this.reverse_y = null;
      this.black_level = null;
      this.pgi_mode = null;
      this.demosaicing_mode = null;
      this.noise_reduction = null;
      this.sharpness_enhancement = null;
      this.light_source_preset = null;
      this.balance_white_auto = null;
      this.sensor_readout_mode = null;
      this.acquisition_frame_count = null;
      this.trigger_selector = null;
      this.trigger_mode = null;
      this.trigger_source = null;
      this.trigger_activation = null;
      this.trigger_delay = null;
      this.user_set_selector = null;
      this.user_set_default_selector = null;
      this.is_sleeping = null;
      this.brightness = null;
      this.exposure = null;
      this.gain = null;
      this.gamma = null;
      this.binning_x = null;
      this.binning_y = null;
      this.roi = null;
      this.available_image_encoding = null;
      this.current_image_encoding = null;
      this.current_image_ros_encoding = null;
      this.sucess = null;
      this.message = null;
    }
    else {
      if (initObj.hasOwnProperty('offset_x')) {
        this.offset_x = initObj.offset_x
      }
      else {
        this.offset_x = 0;
      }
      if (initObj.hasOwnProperty('offset_y')) {
        this.offset_y = initObj.offset_y
      }
      else {
        this.offset_y = 0;
      }
      if (initObj.hasOwnProperty('reverse_x')) {
        this.reverse_x = initObj.reverse_x
      }
      else {
        this.reverse_x = false;
      }
      if (initObj.hasOwnProperty('reverse_y')) {
        this.reverse_y = initObj.reverse_y
      }
      else {
        this.reverse_y = false;
      }
      if (initObj.hasOwnProperty('black_level')) {
        this.black_level = initObj.black_level
      }
      else {
        this.black_level = 0;
      }
      if (initObj.hasOwnProperty('pgi_mode')) {
        this.pgi_mode = initObj.pgi_mode
      }
      else {
        this.pgi_mode = 0;
      }
      if (initObj.hasOwnProperty('demosaicing_mode')) {
        this.demosaicing_mode = initObj.demosaicing_mode
      }
      else {
        this.demosaicing_mode = 0;
      }
      if (initObj.hasOwnProperty('noise_reduction')) {
        this.noise_reduction = initObj.noise_reduction
      }
      else {
        this.noise_reduction = 0.0;
      }
      if (initObj.hasOwnProperty('sharpness_enhancement')) {
        this.sharpness_enhancement = initObj.sharpness_enhancement
      }
      else {
        this.sharpness_enhancement = 0.0;
      }
      if (initObj.hasOwnProperty('light_source_preset')) {
        this.light_source_preset = initObj.light_source_preset
      }
      else {
        this.light_source_preset = 0;
      }
      if (initObj.hasOwnProperty('balance_white_auto')) {
        this.balance_white_auto = initObj.balance_white_auto
      }
      else {
        this.balance_white_auto = 0;
      }
      if (initObj.hasOwnProperty('sensor_readout_mode')) {
        this.sensor_readout_mode = initObj.sensor_readout_mode
      }
      else {
        this.sensor_readout_mode = 0;
      }
      if (initObj.hasOwnProperty('acquisition_frame_count')) {
        this.acquisition_frame_count = initObj.acquisition_frame_count
      }
      else {
        this.acquisition_frame_count = 0;
      }
      if (initObj.hasOwnProperty('trigger_selector')) {
        this.trigger_selector = initObj.trigger_selector
      }
      else {
        this.trigger_selector = 0;
      }
      if (initObj.hasOwnProperty('trigger_mode')) {
        this.trigger_mode = initObj.trigger_mode
      }
      else {
        this.trigger_mode = 0;
      }
      if (initObj.hasOwnProperty('trigger_source')) {
        this.trigger_source = initObj.trigger_source
      }
      else {
        this.trigger_source = 0;
      }
      if (initObj.hasOwnProperty('trigger_activation')) {
        this.trigger_activation = initObj.trigger_activation
      }
      else {
        this.trigger_activation = 0;
      }
      if (initObj.hasOwnProperty('trigger_delay')) {
        this.trigger_delay = initObj.trigger_delay
      }
      else {
        this.trigger_delay = 0.0;
      }
      if (initObj.hasOwnProperty('user_set_selector')) {
        this.user_set_selector = initObj.user_set_selector
      }
      else {
        this.user_set_selector = 0;
      }
      if (initObj.hasOwnProperty('user_set_default_selector')) {
        this.user_set_default_selector = initObj.user_set_default_selector
      }
      else {
        this.user_set_default_selector = 0;
      }
      if (initObj.hasOwnProperty('is_sleeping')) {
        this.is_sleeping = initObj.is_sleeping
      }
      else {
        this.is_sleeping = false;
      }
      if (initObj.hasOwnProperty('brightness')) {
        this.brightness = initObj.brightness
      }
      else {
        this.brightness = 0.0;
      }
      if (initObj.hasOwnProperty('exposure')) {
        this.exposure = initObj.exposure
      }
      else {
        this.exposure = 0.0;
      }
      if (initObj.hasOwnProperty('gain')) {
        this.gain = initObj.gain
      }
      else {
        this.gain = 0.0;
      }
      if (initObj.hasOwnProperty('gamma')) {
        this.gamma = initObj.gamma
      }
      else {
        this.gamma = 0.0;
      }
      if (initObj.hasOwnProperty('binning_x')) {
        this.binning_x = initObj.binning_x
      }
      else {
        this.binning_x = 0;
      }
      if (initObj.hasOwnProperty('binning_y')) {
        this.binning_y = initObj.binning_y
      }
      else {
        this.binning_y = 0;
      }
      if (initObj.hasOwnProperty('roi')) {
        this.roi = initObj.roi
      }
      else {
        this.roi = new sensor_msgs.msg.RegionOfInterest();
      }
      if (initObj.hasOwnProperty('available_image_encoding')) {
        this.available_image_encoding = initObj.available_image_encoding
      }
      else {
        this.available_image_encoding = [];
      }
      if (initObj.hasOwnProperty('current_image_encoding')) {
        this.current_image_encoding = initObj.current_image_encoding
      }
      else {
        this.current_image_encoding = '';
      }
      if (initObj.hasOwnProperty('current_image_ros_encoding')) {
        this.current_image_ros_encoding = initObj.current_image_ros_encoding
      }
      else {
        this.current_image_ros_encoding = '';
      }
      if (initObj.hasOwnProperty('sucess')) {
        this.sucess = initObj.sucess
      }
      else {
        this.sucess = false;
      }
      if (initObj.hasOwnProperty('message')) {
        this.message = initObj.message
      }
      else {
        this.message = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type currentParams
    // Serialize message field [offset_x]
    bufferOffset = _serializer.uint32(obj.offset_x, buffer, bufferOffset);
    // Serialize message field [offset_y]
    bufferOffset = _serializer.uint32(obj.offset_y, buffer, bufferOffset);
    // Serialize message field [reverse_x]
    bufferOffset = _serializer.bool(obj.reverse_x, buffer, bufferOffset);
    // Serialize message field [reverse_y]
    bufferOffset = _serializer.bool(obj.reverse_y, buffer, bufferOffset);
    // Serialize message field [black_level]
    bufferOffset = _serializer.int32(obj.black_level, buffer, bufferOffset);
    // Serialize message field [pgi_mode]
    bufferOffset = _serializer.int32(obj.pgi_mode, buffer, bufferOffset);
    // Serialize message field [demosaicing_mode]
    bufferOffset = _serializer.int32(obj.demosaicing_mode, buffer, bufferOffset);
    // Serialize message field [noise_reduction]
    bufferOffset = _serializer.float32(obj.noise_reduction, buffer, bufferOffset);
    // Serialize message field [sharpness_enhancement]
    bufferOffset = _serializer.float32(obj.sharpness_enhancement, buffer, bufferOffset);
    // Serialize message field [light_source_preset]
    bufferOffset = _serializer.int32(obj.light_source_preset, buffer, bufferOffset);
    // Serialize message field [balance_white_auto]
    bufferOffset = _serializer.int32(obj.balance_white_auto, buffer, bufferOffset);
    // Serialize message field [sensor_readout_mode]
    bufferOffset = _serializer.int32(obj.sensor_readout_mode, buffer, bufferOffset);
    // Serialize message field [acquisition_frame_count]
    bufferOffset = _serializer.int32(obj.acquisition_frame_count, buffer, bufferOffset);
    // Serialize message field [trigger_selector]
    bufferOffset = _serializer.int32(obj.trigger_selector, buffer, bufferOffset);
    // Serialize message field [trigger_mode]
    bufferOffset = _serializer.int32(obj.trigger_mode, buffer, bufferOffset);
    // Serialize message field [trigger_source]
    bufferOffset = _serializer.int32(obj.trigger_source, buffer, bufferOffset);
    // Serialize message field [trigger_activation]
    bufferOffset = _serializer.int32(obj.trigger_activation, buffer, bufferOffset);
    // Serialize message field [trigger_delay]
    bufferOffset = _serializer.float32(obj.trigger_delay, buffer, bufferOffset);
    // Serialize message field [user_set_selector]
    bufferOffset = _serializer.int32(obj.user_set_selector, buffer, bufferOffset);
    // Serialize message field [user_set_default_selector]
    bufferOffset = _serializer.int32(obj.user_set_default_selector, buffer, bufferOffset);
    // Serialize message field [is_sleeping]
    bufferOffset = _serializer.bool(obj.is_sleeping, buffer, bufferOffset);
    // Serialize message field [brightness]
    bufferOffset = _serializer.float32(obj.brightness, buffer, bufferOffset);
    // Serialize message field [exposure]
    bufferOffset = _serializer.float32(obj.exposure, buffer, bufferOffset);
    // Serialize message field [gain]
    bufferOffset = _serializer.float32(obj.gain, buffer, bufferOffset);
    // Serialize message field [gamma]
    bufferOffset = _serializer.float32(obj.gamma, buffer, bufferOffset);
    // Serialize message field [binning_x]
    bufferOffset = _serializer.uint32(obj.binning_x, buffer, bufferOffset);
    // Serialize message field [binning_y]
    bufferOffset = _serializer.uint32(obj.binning_y, buffer, bufferOffset);
    // Serialize message field [roi]
    bufferOffset = sensor_msgs.msg.RegionOfInterest.serialize(obj.roi, buffer, bufferOffset);
    // Serialize message field [available_image_encoding]
    bufferOffset = _arraySerializer.string(obj.available_image_encoding, buffer, bufferOffset, null);
    // Serialize message field [current_image_encoding]
    bufferOffset = _serializer.string(obj.current_image_encoding, buffer, bufferOffset);
    // Serialize message field [current_image_ros_encoding]
    bufferOffset = _serializer.string(obj.current_image_ros_encoding, buffer, bufferOffset);
    // Serialize message field [sucess]
    bufferOffset = _serializer.bool(obj.sucess, buffer, bufferOffset);
    // Serialize message field [message]
    bufferOffset = _serializer.string(obj.message, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type currentParams
    let len;
    let data = new currentParams(null);
    // Deserialize message field [offset_x]
    data.offset_x = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [offset_y]
    data.offset_y = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [reverse_x]
    data.reverse_x = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [reverse_y]
    data.reverse_y = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [black_level]
    data.black_level = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [pgi_mode]
    data.pgi_mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [demosaicing_mode]
    data.demosaicing_mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [noise_reduction]
    data.noise_reduction = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [sharpness_enhancement]
    data.sharpness_enhancement = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [light_source_preset]
    data.light_source_preset = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [balance_white_auto]
    data.balance_white_auto = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [sensor_readout_mode]
    data.sensor_readout_mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [acquisition_frame_count]
    data.acquisition_frame_count = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [trigger_selector]
    data.trigger_selector = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [trigger_mode]
    data.trigger_mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [trigger_source]
    data.trigger_source = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [trigger_activation]
    data.trigger_activation = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [trigger_delay]
    data.trigger_delay = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [user_set_selector]
    data.user_set_selector = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [user_set_default_selector]
    data.user_set_default_selector = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [is_sleeping]
    data.is_sleeping = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [brightness]
    data.brightness = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [exposure]
    data.exposure = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [gain]
    data.gain = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [gamma]
    data.gamma = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [binning_x]
    data.binning_x = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [binning_y]
    data.binning_y = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [roi]
    data.roi = sensor_msgs.msg.RegionOfInterest.deserialize(buffer, bufferOffset);
    // Deserialize message field [available_image_encoding]
    data.available_image_encoding = _arrayDeserializer.string(buffer, bufferOffset, null)
    // Deserialize message field [current_image_encoding]
    data.current_image_encoding = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [current_image_ros_encoding]
    data.current_image_ros_encoding = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [sucess]
    data.sucess = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [message]
    data.message = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.available_image_encoding.forEach((val) => {
      length += 4 + val.length;
    });
    length += object.current_image_encoding.length;
    length += object.current_image_ros_encoding.length;
    length += object.message.length;
    return length + 133;
  }

  static datatype() {
    // Returns string type for a message object
    return 'camera_control_msgs/currentParams';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0bd1503e3cdf30ac14ba73c781326a32';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 offset_x # -20000 = Error	
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
    
    # True if a distinct rectified ROI should be calculated from the "raw"
    # ROI in this message. Typically this should be False if the full image
    # is captured (ROI not used), and True if a subwindow is captured (ROI
    # used).
    bool do_rectify
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new currentParams(null);
    if (msg.offset_x !== undefined) {
      resolved.offset_x = msg.offset_x;
    }
    else {
      resolved.offset_x = 0
    }

    if (msg.offset_y !== undefined) {
      resolved.offset_y = msg.offset_y;
    }
    else {
      resolved.offset_y = 0
    }

    if (msg.reverse_x !== undefined) {
      resolved.reverse_x = msg.reverse_x;
    }
    else {
      resolved.reverse_x = false
    }

    if (msg.reverse_y !== undefined) {
      resolved.reverse_y = msg.reverse_y;
    }
    else {
      resolved.reverse_y = false
    }

    if (msg.black_level !== undefined) {
      resolved.black_level = msg.black_level;
    }
    else {
      resolved.black_level = 0
    }

    if (msg.pgi_mode !== undefined) {
      resolved.pgi_mode = msg.pgi_mode;
    }
    else {
      resolved.pgi_mode = 0
    }

    if (msg.demosaicing_mode !== undefined) {
      resolved.demosaicing_mode = msg.demosaicing_mode;
    }
    else {
      resolved.demosaicing_mode = 0
    }

    if (msg.noise_reduction !== undefined) {
      resolved.noise_reduction = msg.noise_reduction;
    }
    else {
      resolved.noise_reduction = 0.0
    }

    if (msg.sharpness_enhancement !== undefined) {
      resolved.sharpness_enhancement = msg.sharpness_enhancement;
    }
    else {
      resolved.sharpness_enhancement = 0.0
    }

    if (msg.light_source_preset !== undefined) {
      resolved.light_source_preset = msg.light_source_preset;
    }
    else {
      resolved.light_source_preset = 0
    }

    if (msg.balance_white_auto !== undefined) {
      resolved.balance_white_auto = msg.balance_white_auto;
    }
    else {
      resolved.balance_white_auto = 0
    }

    if (msg.sensor_readout_mode !== undefined) {
      resolved.sensor_readout_mode = msg.sensor_readout_mode;
    }
    else {
      resolved.sensor_readout_mode = 0
    }

    if (msg.acquisition_frame_count !== undefined) {
      resolved.acquisition_frame_count = msg.acquisition_frame_count;
    }
    else {
      resolved.acquisition_frame_count = 0
    }

    if (msg.trigger_selector !== undefined) {
      resolved.trigger_selector = msg.trigger_selector;
    }
    else {
      resolved.trigger_selector = 0
    }

    if (msg.trigger_mode !== undefined) {
      resolved.trigger_mode = msg.trigger_mode;
    }
    else {
      resolved.trigger_mode = 0
    }

    if (msg.trigger_source !== undefined) {
      resolved.trigger_source = msg.trigger_source;
    }
    else {
      resolved.trigger_source = 0
    }

    if (msg.trigger_activation !== undefined) {
      resolved.trigger_activation = msg.trigger_activation;
    }
    else {
      resolved.trigger_activation = 0
    }

    if (msg.trigger_delay !== undefined) {
      resolved.trigger_delay = msg.trigger_delay;
    }
    else {
      resolved.trigger_delay = 0.0
    }

    if (msg.user_set_selector !== undefined) {
      resolved.user_set_selector = msg.user_set_selector;
    }
    else {
      resolved.user_set_selector = 0
    }

    if (msg.user_set_default_selector !== undefined) {
      resolved.user_set_default_selector = msg.user_set_default_selector;
    }
    else {
      resolved.user_set_default_selector = 0
    }

    if (msg.is_sleeping !== undefined) {
      resolved.is_sleeping = msg.is_sleeping;
    }
    else {
      resolved.is_sleeping = false
    }

    if (msg.brightness !== undefined) {
      resolved.brightness = msg.brightness;
    }
    else {
      resolved.brightness = 0.0
    }

    if (msg.exposure !== undefined) {
      resolved.exposure = msg.exposure;
    }
    else {
      resolved.exposure = 0.0
    }

    if (msg.gain !== undefined) {
      resolved.gain = msg.gain;
    }
    else {
      resolved.gain = 0.0
    }

    if (msg.gamma !== undefined) {
      resolved.gamma = msg.gamma;
    }
    else {
      resolved.gamma = 0.0
    }

    if (msg.binning_x !== undefined) {
      resolved.binning_x = msg.binning_x;
    }
    else {
      resolved.binning_x = 0
    }

    if (msg.binning_y !== undefined) {
      resolved.binning_y = msg.binning_y;
    }
    else {
      resolved.binning_y = 0
    }

    if (msg.roi !== undefined) {
      resolved.roi = sensor_msgs.msg.RegionOfInterest.Resolve(msg.roi)
    }
    else {
      resolved.roi = new sensor_msgs.msg.RegionOfInterest()
    }

    if (msg.available_image_encoding !== undefined) {
      resolved.available_image_encoding = msg.available_image_encoding;
    }
    else {
      resolved.available_image_encoding = []
    }

    if (msg.current_image_encoding !== undefined) {
      resolved.current_image_encoding = msg.current_image_encoding;
    }
    else {
      resolved.current_image_encoding = ''
    }

    if (msg.current_image_ros_encoding !== undefined) {
      resolved.current_image_ros_encoding = msg.current_image_ros_encoding;
    }
    else {
      resolved.current_image_ros_encoding = ''
    }

    if (msg.sucess !== undefined) {
      resolved.sucess = msg.sucess;
    }
    else {
      resolved.sucess = false
    }

    if (msg.message !== undefined) {
      resolved.message = msg.message;
    }
    else {
      resolved.message = ''
    }

    return resolved;
    }
};

module.exports = currentParams;
