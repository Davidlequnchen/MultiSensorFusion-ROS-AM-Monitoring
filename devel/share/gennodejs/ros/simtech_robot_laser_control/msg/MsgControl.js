// Auto-generated. Do not edit!

// (in-package simtech_robot_laser_control.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class MsgControl {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.change = null;
      this.value = null;
    }
    else {
      if (initObj.hasOwnProperty('change')) {
        this.change = initObj.change
      }
      else {
        this.change = false;
      }
      if (initObj.hasOwnProperty('value')) {
        this.value = initObj.value
      }
      else {
        this.value = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MsgControl
    // Serialize message field [change]
    bufferOffset = _serializer.bool(obj.change, buffer, bufferOffset);
    // Serialize message field [value]
    bufferOffset = _serializer.int32(obj.value, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MsgControl
    let len;
    let data = new MsgControl(null);
    // Deserialize message field [change]
    data.change = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [value]
    data.value = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'simtech_robot_laser_control/MsgControl';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c0714776f3b1ecd3928d4fe859ff95f8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # /control/parameters topic 
    bool change
    int32 value
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MsgControl(null);
    if (msg.change !== undefined) {
      resolved.change = msg.change;
    }
    else {
      resolved.change = false
    }

    if (msg.value !== undefined) {
      resolved.value = msg.value;
    }
    else {
      resolved.value = 0
    }

    return resolved;
    }
};

module.exports = MsgControl;
