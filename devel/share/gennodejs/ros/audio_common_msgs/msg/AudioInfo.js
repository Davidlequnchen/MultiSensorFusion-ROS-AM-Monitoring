// Auto-generated. Do not edit!

// (in-package audio_common_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class AudioInfo {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.channels = null;
      this.sample_rate = null;
      this.sample_format = null;
      this.bitrate = null;
      this.coding_format = null;
    }
    else {
      if (initObj.hasOwnProperty('channels')) {
        this.channels = initObj.channels
      }
      else {
        this.channels = 0;
      }
      if (initObj.hasOwnProperty('sample_rate')) {
        this.sample_rate = initObj.sample_rate
      }
      else {
        this.sample_rate = 0;
      }
      if (initObj.hasOwnProperty('sample_format')) {
        this.sample_format = initObj.sample_format
      }
      else {
        this.sample_format = '';
      }
      if (initObj.hasOwnProperty('bitrate')) {
        this.bitrate = initObj.bitrate
      }
      else {
        this.bitrate = 0;
      }
      if (initObj.hasOwnProperty('coding_format')) {
        this.coding_format = initObj.coding_format
      }
      else {
        this.coding_format = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type AudioInfo
    // Serialize message field [channels]
    bufferOffset = _serializer.uint8(obj.channels, buffer, bufferOffset);
    // Serialize message field [sample_rate]
    bufferOffset = _serializer.uint32(obj.sample_rate, buffer, bufferOffset);
    // Serialize message field [sample_format]
    bufferOffset = _serializer.string(obj.sample_format, buffer, bufferOffset);
    // Serialize message field [bitrate]
    bufferOffset = _serializer.uint32(obj.bitrate, buffer, bufferOffset);
    // Serialize message field [coding_format]
    bufferOffset = _serializer.string(obj.coding_format, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type AudioInfo
    let len;
    let data = new AudioInfo(null);
    // Deserialize message field [channels]
    data.channels = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [sample_rate]
    data.sample_rate = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [sample_format]
    data.sample_format = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [bitrate]
    data.bitrate = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [coding_format]
    data.coding_format = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.sample_format.length;
    length += object.coding_format.length;
    return length + 17;
  }

  static datatype() {
    // Returns string type for a message object
    return 'audio_common_msgs/AudioInfo';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9413d9b7029680d3b1db6ed0ae535f88';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This message contains the audio meta data
    
    # Number of channels
    uint8 channels
    # Sampling rate [Hz]
    uint32 sample_rate
    # Audio format (e.g. S16LE)
    string sample_format
    # Amount of audio data per second [bits/s]
    uint32 bitrate
    # Audio coding format (e.g. WAVE, MP3)
    string coding_format
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new AudioInfo(null);
    if (msg.channels !== undefined) {
      resolved.channels = msg.channels;
    }
    else {
      resolved.channels = 0
    }

    if (msg.sample_rate !== undefined) {
      resolved.sample_rate = msg.sample_rate;
    }
    else {
      resolved.sample_rate = 0
    }

    if (msg.sample_format !== undefined) {
      resolved.sample_format = msg.sample_format;
    }
    else {
      resolved.sample_format = ''
    }

    if (msg.bitrate !== undefined) {
      resolved.bitrate = msg.bitrate;
    }
    else {
      resolved.bitrate = 0
    }

    if (msg.coding_format !== undefined) {
      resolved.coding_format = msg.coding_format;
    }
    else {
      resolved.coding_format = ''
    }

    return resolved;
    }
};

module.exports = AudioInfo;
