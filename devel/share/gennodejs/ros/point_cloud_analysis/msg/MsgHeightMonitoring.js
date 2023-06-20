// Auto-generated. Do not edit!

// (in-package point_cloud_analysis.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class MsgHeightMonitoring {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.plane_id = null;
      this.height_std = null;
      this.height_mean = null;
      this.heighest_max_min_difference = null;
      this.tilt_angle = null;
    }
    else {
      if (initObj.hasOwnProperty('plane_id')) {
        this.plane_id = initObj.plane_id
      }
      else {
        this.plane_id = 0;
      }
      if (initObj.hasOwnProperty('height_std')) {
        this.height_std = initObj.height_std
      }
      else {
        this.height_std = 0.0;
      }
      if (initObj.hasOwnProperty('height_mean')) {
        this.height_mean = initObj.height_mean
      }
      else {
        this.height_mean = 0.0;
      }
      if (initObj.hasOwnProperty('heighest_max_min_difference')) {
        this.heighest_max_min_difference = initObj.heighest_max_min_difference
      }
      else {
        this.heighest_max_min_difference = 0.0;
      }
      if (initObj.hasOwnProperty('tilt_angle')) {
        this.tilt_angle = initObj.tilt_angle
      }
      else {
        this.tilt_angle = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MsgHeightMonitoring
    // Serialize message field [plane_id]
    bufferOffset = _serializer.int32(obj.plane_id, buffer, bufferOffset);
    // Serialize message field [height_std]
    bufferOffset = _serializer.float32(obj.height_std, buffer, bufferOffset);
    // Serialize message field [height_mean]
    bufferOffset = _serializer.float32(obj.height_mean, buffer, bufferOffset);
    // Serialize message field [heighest_max_min_difference]
    bufferOffset = _serializer.float32(obj.heighest_max_min_difference, buffer, bufferOffset);
    // Serialize message field [tilt_angle]
    bufferOffset = _serializer.float32(obj.tilt_angle, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MsgHeightMonitoring
    let len;
    let data = new MsgHeightMonitoring(null);
    // Deserialize message field [plane_id]
    data.plane_id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [height_std]
    data.height_std = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [height_mean]
    data.height_mean = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [heighest_max_min_difference]
    data.heighest_max_min_difference = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [tilt_angle]
    data.tilt_angle = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'point_cloud_analysis/MsgHeightMonitoring';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd5dba450528743fdd28379753715b42a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 plane_id         # the id for the scanning
    float32 height_std
    float32 height_mean
    float32 heighest_max_min_difference
    float32 tilt_angle
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MsgHeightMonitoring(null);
    if (msg.plane_id !== undefined) {
      resolved.plane_id = msg.plane_id;
    }
    else {
      resolved.plane_id = 0
    }

    if (msg.height_std !== undefined) {
      resolved.height_std = msg.height_std;
    }
    else {
      resolved.height_std = 0.0
    }

    if (msg.height_mean !== undefined) {
      resolved.height_mean = msg.height_mean;
    }
    else {
      resolved.height_mean = 0.0
    }

    if (msg.heighest_max_min_difference !== undefined) {
      resolved.heighest_max_min_difference = msg.heighest_max_min_difference;
    }
    else {
      resolved.heighest_max_min_difference = 0.0
    }

    if (msg.tilt_angle !== undefined) {
      resolved.tilt_angle = msg.tilt_angle;
    }
    else {
      resolved.tilt_angle = 0.0
    }

    return resolved;
    }
};

module.exports = MsgHeightMonitoring;
