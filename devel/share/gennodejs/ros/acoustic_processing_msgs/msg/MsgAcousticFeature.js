// Auto-generated. Do not edit!

// (in-package acoustic_processing_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class MsgAcousticFeature {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.spectral_centroids = null;
      this.fft = null;
    }
    else {
      if (initObj.hasOwnProperty('spectral_centroids')) {
        this.spectral_centroids = initObj.spectral_centroids
      }
      else {
        this.spectral_centroids = 0.0;
      }
      if (initObj.hasOwnProperty('fft')) {
        this.fft = initObj.fft
      }
      else {
        this.fft = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MsgAcousticFeature
    // Serialize message field [spectral_centroids]
    bufferOffset = _serializer.float32(obj.spectral_centroids, buffer, bufferOffset);
    // Serialize message field [fft]
    bufferOffset = _serializer.float32(obj.fft, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MsgAcousticFeature
    let len;
    let data = new MsgAcousticFeature(null);
    // Deserialize message field [spectral_centroids]
    data.spectral_centroids = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [fft]
    data.fft = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'acoustic_processing_msgs/MsgAcousticFeature';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'dceaefa1e58f133ccf0968427c39fdf1';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 spectral_centroids
    float32 fft
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MsgAcousticFeature(null);
    if (msg.spectral_centroids !== undefined) {
      resolved.spectral_centroids = msg.spectral_centroids;
    }
    else {
      resolved.spectral_centroids = 0.0
    }

    if (msg.fft !== undefined) {
      resolved.fft = msg.fft;
    }
    else {
      resolved.fft = 0.0
    }

    return resolved;
    }
};

module.exports = MsgAcousticFeature;
