// Auto-generated. Do not edit!

// (in-package infratec_image_processing.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class TemperatureFeature {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.highest = null;
      this.lowest = null;
      this.variance = null;
      this.kurtosis = null;
      this.skewness = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('highest')) {
        this.highest = initObj.highest
      }
      else {
        this.highest = 0.0;
      }
      if (initObj.hasOwnProperty('lowest')) {
        this.lowest = initObj.lowest
      }
      else {
        this.lowest = 0.0;
      }
      if (initObj.hasOwnProperty('variance')) {
        this.variance = initObj.variance
      }
      else {
        this.variance = 0.0;
      }
      if (initObj.hasOwnProperty('kurtosis')) {
        this.kurtosis = initObj.kurtosis
      }
      else {
        this.kurtosis = 0.0;
      }
      if (initObj.hasOwnProperty('skewness')) {
        this.skewness = initObj.skewness
      }
      else {
        this.skewness = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type TemperatureFeature
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [highest]
    bufferOffset = _serializer.float32(obj.highest, buffer, bufferOffset);
    // Serialize message field [lowest]
    bufferOffset = _serializer.float32(obj.lowest, buffer, bufferOffset);
    // Serialize message field [variance]
    bufferOffset = _serializer.float32(obj.variance, buffer, bufferOffset);
    // Serialize message field [kurtosis]
    bufferOffset = _serializer.float64(obj.kurtosis, buffer, bufferOffset);
    // Serialize message field [skewness]
    bufferOffset = _serializer.float64(obj.skewness, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type TemperatureFeature
    let len;
    let data = new TemperatureFeature(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [highest]
    data.highest = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [lowest]
    data.lowest = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [variance]
    data.variance = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [kurtosis]
    data.kurtosis = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [skewness]
    data.skewness = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 28;
  }

  static datatype() {
    // Returns string type for a message object
    return 'infratec_image_processing/TemperatureFeature';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '25f0a9823d69014b82344a62ef84f03d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    float32 highest
    float32 lowest
    float32 variance # measure of the spread of a distribution
    float64 kurtosis # measure of non-guassianity
    float64 skewness
    # skewness = 0 : normally distributed.
    # skewness > 0 : more weight in the left tail of the distribution.
    # skewness < 0 : more weight in the right tail of the distribution. 
    
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new TemperatureFeature(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.highest !== undefined) {
      resolved.highest = msg.highest;
    }
    else {
      resolved.highest = 0.0
    }

    if (msg.lowest !== undefined) {
      resolved.lowest = msg.lowest;
    }
    else {
      resolved.lowest = 0.0
    }

    if (msg.variance !== undefined) {
      resolved.variance = msg.variance;
    }
    else {
      resolved.variance = 0.0
    }

    if (msg.kurtosis !== undefined) {
      resolved.kurtosis = msg.kurtosis;
    }
    else {
      resolved.kurtosis = 0.0
    }

    if (msg.skewness !== undefined) {
      resolved.skewness = msg.skewness;
    }
    else {
      resolved.skewness = 0.0
    }

    return resolved;
    }
};

module.exports = TemperatureFeature;
