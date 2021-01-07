// Auto-generated. Do not edit!

// (in-package camera_measures.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class MsgTwist {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.linear_x = null;
      this.linear_y = null;
      this.linear_z = null;
      this.linear_speed = null;
      this.speed_averaged = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('linear_x')) {
        this.linear_x = initObj.linear_x
      }
      else {
        this.linear_x = 0.0;
      }
      if (initObj.hasOwnProperty('linear_y')) {
        this.linear_y = initObj.linear_y
      }
      else {
        this.linear_y = 0.0;
      }
      if (initObj.hasOwnProperty('linear_z')) {
        this.linear_z = initObj.linear_z
      }
      else {
        this.linear_z = 0.0;
      }
      if (initObj.hasOwnProperty('linear_speed')) {
        this.linear_speed = initObj.linear_speed
      }
      else {
        this.linear_speed = 0.0;
      }
      if (initObj.hasOwnProperty('speed_averaged')) {
        this.speed_averaged = initObj.speed_averaged
      }
      else {
        this.speed_averaged = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MsgTwist
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [linear_x]
    bufferOffset = _serializer.float32(obj.linear_x, buffer, bufferOffset);
    // Serialize message field [linear_y]
    bufferOffset = _serializer.float32(obj.linear_y, buffer, bufferOffset);
    // Serialize message field [linear_z]
    bufferOffset = _serializer.float32(obj.linear_z, buffer, bufferOffset);
    // Serialize message field [linear_speed]
    bufferOffset = _serializer.float32(obj.linear_speed, buffer, bufferOffset);
    // Serialize message field [speed_averaged]
    bufferOffset = _serializer.float32(obj.speed_averaged, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MsgTwist
    let len;
    let data = new MsgTwist(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [linear_x]
    data.linear_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [linear_y]
    data.linear_y = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [linear_z]
    data.linear_z = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [linear_speed]
    data.linear_speed = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [speed_averaged]
    data.speed_averaged = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'camera_measures/MsgTwist';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c8ac0f689767f9a8e47b7244c6d20dfc';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    float32 linear_x
    float32 linear_y
    float32 linear_z
    float32 linear_speed
    float32 speed_averaged
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
    const resolved = new MsgTwist(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.linear_x !== undefined) {
      resolved.linear_x = msg.linear_x;
    }
    else {
      resolved.linear_x = 0.0
    }

    if (msg.linear_y !== undefined) {
      resolved.linear_y = msg.linear_y;
    }
    else {
      resolved.linear_y = 0.0
    }

    if (msg.linear_z !== undefined) {
      resolved.linear_z = msg.linear_z;
    }
    else {
      resolved.linear_z = 0.0
    }

    if (msg.linear_speed !== undefined) {
      resolved.linear_speed = msg.linear_speed;
    }
    else {
      resolved.linear_speed = 0.0
    }

    if (msg.speed_averaged !== undefined) {
      resolved.speed_averaged = msg.speed_averaged;
    }
    else {
      resolved.speed_averaged = 0.0
    }

    return resolved;
    }
};

module.exports = MsgTwist;
