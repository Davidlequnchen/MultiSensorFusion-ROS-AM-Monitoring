// Auto-generated. Do not edit!

// (in-package camera_control_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class SetIntegerValueRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.value = null;
    }
    else {
      if (initObj.hasOwnProperty('value')) {
        this.value = initObj.value
      }
      else {
        this.value = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SetIntegerValueRequest
    // Serialize message field [value]
    bufferOffset = _serializer.int32(obj.value, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetIntegerValueRequest
    let len;
    let data = new SetIntegerValueRequest(null);
    // Deserialize message field [value]
    data.value = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'camera_control_msgs/SetIntegerValueRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b3087778e93fcd34cc8d65bc54e850d1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Used by :
    # - set_black_level ROS service. (value = new targeted black level).
    # - set_acquisition_frame_count ROS service (value = new targeted frame count).
    # - set_offset_x ROS service (value = targeted offset in x-axis)
    # - set_offset_y ROS service (value = targeted offset in y-axis)
    # - set_demosaicing_mode ROS Service (value : 0 = Simple, 1 = Basler PGI)
    # - set_light_source_preset ROS service (value : 0 = Off, 1 = Daylight5000K, 2 = Daylight6500K, 3 = Tungsten2800K)
    # - set_balance_white_auto ROS service (value : 0 = Off, 1 = Once, 2 = Continuous)
    # - set_sensor_readout_mode ROS service (value : 0 = Normal, 1 = Fast)
    # - set_trigger_selector ROS service (value : 	0 = Frame start, 1 = Frame burst start (ace USB cameras) / Acquisition Start (ace GigE cameras))
    # - set_trigger_source ROS service (value : 0 = Software, 1 = Line1, 2 = Line3, 3 = Line4, 4 = Action1 (only selected GigE Camera))
    # - set_trigger_activation ROS service (value : 0 = RigingEdge, 1 = FallingEdge)
    # - set_line_selector ROS service (value : 0 = Line1, 1 = Line2, 2 = Line3, 3 = Line4)
    # - set_line_mode ROS service (value : 0 = Input, 1 = Output)
    # - set_line_source ROS sevice (value : 0 = Exposure Active, 1 = FrameTriggerWait, 2 = UserOutput1, 3 = Timer1Active, 4 = FlashWindow)
    # - set_device_link_throughput_limit ROS service (value = new targeted throughput limit in Bytes/sec.).
    # - select_user_set ROS service (value : 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw)
    # - select_default_user_set ROS service (value : 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw)
    # - set_gamma_selector (value: 0 = User, 1 = sRGB)
    
    int32 value 		# value to be setted
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SetIntegerValueRequest(null);
    if (msg.value !== undefined) {
      resolved.value = msg.value;
    }
    else {
      resolved.value = 0
    }

    return resolved;
    }
};

class SetIntegerValueResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.success = null;
      this.message = null;
    }
    else {
      if (initObj.hasOwnProperty('success')) {
        this.success = initObj.success
      }
      else {
        this.success = false;
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
    // Serializes a message object of type SetIntegerValueResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    // Serialize message field [message]
    bufferOffset = _serializer.string(obj.message, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetIntegerValueResponse
    let len;
    let data = new SetIntegerValueResponse(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [message]
    data.message = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.message.length;
    return length + 5;
  }

  static datatype() {
    // Returns string type for a service object
    return 'camera_control_msgs/SetIntegerValueResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '937c9679a518e3a18d831e57125ea522';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool success   # indicate successful run of triggered service
    string message # informational, e.g. for error messages
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SetIntegerValueResponse(null);
    if (msg.success !== undefined) {
      resolved.success = msg.success;
    }
    else {
      resolved.success = false
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

module.exports = {
  Request: SetIntegerValueRequest,
  Response: SetIntegerValueResponse,
  md5sum() { return 'f17b32d87dddbe303f3f462e91a430a4'; },
  datatype() { return 'camera_control_msgs/SetIntegerValue'; }
};
