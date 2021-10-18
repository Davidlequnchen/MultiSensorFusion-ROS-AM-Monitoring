// Auto-generated. Do not edit!

// (in-package dnb_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ComponentStatus {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.status_id = null;
      this.status_msg = null;
    }
    else {
      if (initObj.hasOwnProperty('status_id')) {
        this.status_id = initObj.status_id
      }
      else {
        this.status_id = 0;
      }
      if (initObj.hasOwnProperty('status_msg')) {
        this.status_msg = initObj.status_msg
      }
      else {
        this.status_msg = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ComponentStatus
    // Serialize message field [status_id]
    bufferOffset = _serializer.int8(obj.status_id, buffer, bufferOffset);
    // Serialize message field [status_msg]
    bufferOffset = _serializer.string(obj.status_msg, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ComponentStatus
    let len;
    let data = new ComponentStatus(null);
    // Deserialize message field [status_id]
    data.status_id = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [status_msg]
    data.status_msg = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.status_msg.length;
    return length + 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'dnb_msgs/ComponentStatus';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3edf5da01aa562198fec3c468cecb80b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # component id; it must be unique among all registered components
    # @TODO: use on one topic and identify by id
    #string component_id
    
    # the official status id of the component
    # possible values are
    int8 INITIALIZED = 0
    int8 STOPPED = 1
    int8 RUNNING = 2
    int8 CONFIG_NEEDED = 3
    int8 ERROR = 4
    int8 INTERACTION_REQUEST = 5
    int8 DEACTIVATED = 6
    int8 status_id
    
    # an individual message for config or error cases
    # it should describe the type of needed config or occurred error briefly
    # it should be possible to extract automaticly subsequent actions/instructions from the message if this is needed
    string status_msg
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ComponentStatus(null);
    if (msg.status_id !== undefined) {
      resolved.status_id = msg.status_id;
    }
    else {
      resolved.status_id = 0
    }

    if (msg.status_msg !== undefined) {
      resolved.status_msg = msg.status_msg;
    }
    else {
      resolved.status_msg = ''
    }

    return resolved;
    }
};

// Constants for message
ComponentStatus.Constants = {
  INITIALIZED: 0,
  STOPPED: 1,
  RUNNING: 2,
  CONFIG_NEEDED: 3,
  ERROR: 4,
  INTERACTION_REQUEST: 5,
  DEACTIVATED: 6,
}

module.exports = ComponentStatus;
