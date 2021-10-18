// Auto-generated. Do not edit!

// (in-package scanning_robviz.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class MsgPointCloudScan {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ready = null;
      this.scanning_count = null;
    }
    else {
      if (initObj.hasOwnProperty('ready')) {
        this.ready = initObj.ready
      }
      else {
        this.ready = false;
      }
      if (initObj.hasOwnProperty('scanning_count')) {
        this.scanning_count = initObj.scanning_count
      }
      else {
        this.scanning_count = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MsgPointCloudScan
    // Serialize message field [ready]
    bufferOffset = _serializer.bool(obj.ready, buffer, bufferOffset);
    // Serialize message field [scanning_count]
    bufferOffset = _serializer.int32(obj.scanning_count, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MsgPointCloudScan
    let len;
    let data = new MsgPointCloudScan(null);
    // Deserialize message field [ready]
    data.ready = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [scanning_count]
    data.scanning_count = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'scanning_robviz/MsgPointCloudScan';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e17f7c935aac21da9daa560a5aff6392';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool ready # to tell the analysis node ready or not
    int32 scanning_count # No. of scan
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MsgPointCloudScan(null);
    if (msg.ready !== undefined) {
      resolved.ready = msg.ready;
    }
    else {
      resolved.ready = false
    }

    if (msg.scanning_count !== undefined) {
      resolved.scanning_count = msg.scanning_count;
    }
    else {
      resolved.scanning_count = 0
    }

    return resolved;
    }
};

module.exports = MsgPointCloudScan;
