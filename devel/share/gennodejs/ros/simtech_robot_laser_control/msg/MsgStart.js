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

class MsgStart {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.control = null;
      this.setpoint = null;
    }
    else {
      if (initObj.hasOwnProperty('control')) {
        this.control = initObj.control
      }
      else {
        this.control = false;
      }
      if (initObj.hasOwnProperty('setpoint')) {
        this.setpoint = initObj.setpoint
      }
      else {
        this.setpoint = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MsgStart
    // Serialize message field [control]
    bufferOffset = _serializer.bool(obj.control, buffer, bufferOffset);
    // Serialize message field [setpoint]
    bufferOffset = _serializer.float32(obj.setpoint, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MsgStart
    let len;
    let data = new MsgStart(null);
    // Deserialize message field [control]
    data.control = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [setpoint]
    data.setpoint = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'simtech_robot_laser_control/MsgStart';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e881025c4deef3846ab5aed40f4f106e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool control
    float32 setpoint
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MsgStart(null);
    if (msg.control !== undefined) {
      resolved.control = msg.control;
    }
    else {
      resolved.control = false
    }

    if (msg.setpoint !== undefined) {
      resolved.setpoint = msg.setpoint;
    }
    else {
      resolved.setpoint = 0.0
    }

    return resolved;
    }
};

module.exports = MsgStart;
