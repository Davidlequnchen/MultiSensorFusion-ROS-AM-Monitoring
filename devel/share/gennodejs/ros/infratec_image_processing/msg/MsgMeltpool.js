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

class MsgMeltpool {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.melt_pool_size = null;
      this.heat_affected_zone = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('melt_pool_size')) {
        this.melt_pool_size = initObj.melt_pool_size
      }
      else {
        this.melt_pool_size = 0.0;
      }
      if (initObj.hasOwnProperty('heat_affected_zone')) {
        this.heat_affected_zone = initObj.heat_affected_zone
      }
      else {
        this.heat_affected_zone = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MsgMeltpool
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [melt_pool_size]
    bufferOffset = _serializer.float32(obj.melt_pool_size, buffer, bufferOffset);
    // Serialize message field [heat_affected_zone]
    bufferOffset = _serializer.float32(obj.heat_affected_zone, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MsgMeltpool
    let len;
    let data = new MsgMeltpool(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [melt_pool_size]
    data.melt_pool_size = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [heat_affected_zone]
    data.heat_affected_zone = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'infratec_image_processing/MsgMeltpool';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '53ff07d859c81343775714d56bbac875';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    float32 melt_pool_size
    float32 heat_affected_zone
    
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
    const resolved = new MsgMeltpool(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.melt_pool_size !== undefined) {
      resolved.melt_pool_size = msg.melt_pool_size;
    }
    else {
      resolved.melt_pool_size = 0.0
    }

    if (msg.heat_affected_zone !== undefined) {
      resolved.heat_affected_zone = msg.heat_affected_zone;
    }
    else {
      resolved.heat_affected_zone = 0.0
    }

    return resolved;
    }
};

module.exports = MsgMeltpool;
