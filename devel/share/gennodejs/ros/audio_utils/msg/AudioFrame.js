// Auto-generated. Do not edit!

// (in-package audio_utils.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class AudioFrame {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.format = null;
      this.channel_count = null;
      this.sampling_frequency = null;
      this.frame_sample_count = null;
      this.data = null;
    }
    else {
      if (initObj.hasOwnProperty('format')) {
        this.format = initObj.format
      }
      else {
        this.format = '';
      }
      if (initObj.hasOwnProperty('channel_count')) {
        this.channel_count = initObj.channel_count
      }
      else {
        this.channel_count = 0;
      }
      if (initObj.hasOwnProperty('sampling_frequency')) {
        this.sampling_frequency = initObj.sampling_frequency
      }
      else {
        this.sampling_frequency = 0;
      }
      if (initObj.hasOwnProperty('frame_sample_count')) {
        this.frame_sample_count = initObj.frame_sample_count
      }
      else {
        this.frame_sample_count = 0;
      }
      if (initObj.hasOwnProperty('data')) {
        this.data = initObj.data
      }
      else {
        this.data = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type AudioFrame
    // Serialize message field [format]
    bufferOffset = _serializer.string(obj.format, buffer, bufferOffset);
    // Serialize message field [channel_count]
    bufferOffset = _serializer.uint32(obj.channel_count, buffer, bufferOffset);
    // Serialize message field [sampling_frequency]
    bufferOffset = _serializer.uint32(obj.sampling_frequency, buffer, bufferOffset);
    // Serialize message field [frame_sample_count]
    bufferOffset = _serializer.uint32(obj.frame_sample_count, buffer, bufferOffset);
    // Serialize message field [data]
    bufferOffset = _arraySerializer.uint8(obj.data, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type AudioFrame
    let len;
    let data = new AudioFrame(null);
    // Deserialize message field [format]
    data.format = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [channel_count]
    data.channel_count = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [sampling_frequency]
    data.sampling_frequency = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [frame_sample_count]
    data.frame_sample_count = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [data]
    data.data = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.format);
    length += object.data.length;
    return length + 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'audio_utils/AudioFrame';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '82adf6775a8307ce59815e86a751d73c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Supported formats (all formats are little endian): 
    # - "signed_8"
    # - "signed_16"
    # - "signed_24"
    # - "signed_padded_24"
    # - "signed_32"
    # - "unsigned_8"
    # - "unsigned_16"
    # - "unsigned_24"
    # - "unsigned_padded_24"
    # - "unsigned_32"
    # - "float"
    # - "double"
    string format
    uint32 channel_count
    uint32 sampling_frequency
    uint32 frame_sample_count
    
    uint8[] data
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new AudioFrame(null);
    if (msg.format !== undefined) {
      resolved.format = msg.format;
    }
    else {
      resolved.format = ''
    }

    if (msg.channel_count !== undefined) {
      resolved.channel_count = msg.channel_count;
    }
    else {
      resolved.channel_count = 0
    }

    if (msg.sampling_frequency !== undefined) {
      resolved.sampling_frequency = msg.sampling_frequency;
    }
    else {
      resolved.sampling_frequency = 0
    }

    if (msg.frame_sample_count !== undefined) {
      resolved.frame_sample_count = msg.frame_sample_count;
    }
    else {
      resolved.frame_sample_count = 0
    }

    if (msg.data !== undefined) {
      resolved.data = msg.data;
    }
    else {
      resolved.data = []
    }

    return resolved;
    }
};

module.exports = AudioFrame;
