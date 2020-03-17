// Auto-generated. Do not edit!

// (in-package defects_identification.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class MsgPointDistance {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.point_to_plane_distance = null;
    }
    else {
      if (initObj.hasOwnProperty('point_to_plane_distance')) {
        this.point_to_plane_distance = initObj.point_to_plane_distance
      }
      else {
        this.point_to_plane_distance = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MsgPointDistance
    // Serialize message field [point_to_plane_distance]
    bufferOffset = _arraySerializer.float32(obj.point_to_plane_distance, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MsgPointDistance
    let len;
    let data = new MsgPointDistance(null);
    // Deserialize message field [point_to_plane_distance]
    data.point_to_plane_distance = _arrayDeserializer.float32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.point_to_plane_distance.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'defects_identification/MsgPointDistance';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c24ec51a2bb9c83a98d25173a7416b03';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32[] point_to_plane_distance
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MsgPointDistance(null);
    if (msg.point_to_plane_distance !== undefined) {
      resolved.point_to_plane_distance = msg.point_to_plane_distance;
    }
    else {
      resolved.point_to_plane_distance = []
    }

    return resolved;
    }
};

module.exports = MsgPointDistance;
