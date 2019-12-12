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

class MsgEmission {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.emission = null;
    }
    else {
      if (initObj.hasOwnProperty('emission')) {
        this.emission = initObj.emission
      }
      else {
        this.emission = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MsgEmission
    // Serialize message field [emission]
    bufferOffset = _serializer.bool(obj.emission, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MsgEmission
    let len;
    let data = new MsgEmission(null);
    // Deserialize message field [emission]
    data.emission = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a message object
    return 'simtech_robot_laser_control/MsgEmission';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b41438f20140254925ccd78f3541f322';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool emission
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MsgEmission(null);
    if (msg.emission !== undefined) {
      resolved.emission = msg.emission;
    }
    else {
      resolved.emission = false
    }

    return resolved;
    }
};

module.exports = MsgEmission;
