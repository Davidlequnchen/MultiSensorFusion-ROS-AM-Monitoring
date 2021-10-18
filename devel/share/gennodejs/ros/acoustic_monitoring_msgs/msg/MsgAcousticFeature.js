// Auto-generated. Do not edit!

// (in-package acoustic_monitoring_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class MsgAcousticFeature {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.rms_energy = null;
      this.amplitude_envelope = null;
      this.zero_crossing_rate = null;
      this.mfccs_mean = null;
      this.mfccs_variance = null;
      this.spectral_centroids = null;
      this.spectral_rolloff = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('rms_energy')) {
        this.rms_energy = initObj.rms_energy
      }
      else {
        this.rms_energy = 0.0;
      }
      if (initObj.hasOwnProperty('amplitude_envelope')) {
        this.amplitude_envelope = initObj.amplitude_envelope
      }
      else {
        this.amplitude_envelope = 0.0;
      }
      if (initObj.hasOwnProperty('zero_crossing_rate')) {
        this.zero_crossing_rate = initObj.zero_crossing_rate
      }
      else {
        this.zero_crossing_rate = 0.0;
      }
      if (initObj.hasOwnProperty('mfccs_mean')) {
        this.mfccs_mean = initObj.mfccs_mean
      }
      else {
        this.mfccs_mean = 0.0;
      }
      if (initObj.hasOwnProperty('mfccs_variance')) {
        this.mfccs_variance = initObj.mfccs_variance
      }
      else {
        this.mfccs_variance = 0.0;
      }
      if (initObj.hasOwnProperty('spectral_centroids')) {
        this.spectral_centroids = initObj.spectral_centroids
      }
      else {
        this.spectral_centroids = 0.0;
      }
      if (initObj.hasOwnProperty('spectral_rolloff')) {
        this.spectral_rolloff = initObj.spectral_rolloff
      }
      else {
        this.spectral_rolloff = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MsgAcousticFeature
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [rms_energy]
    bufferOffset = _serializer.float32(obj.rms_energy, buffer, bufferOffset);
    // Serialize message field [amplitude_envelope]
    bufferOffset = _serializer.float32(obj.amplitude_envelope, buffer, bufferOffset);
    // Serialize message field [zero_crossing_rate]
    bufferOffset = _serializer.float32(obj.zero_crossing_rate, buffer, bufferOffset);
    // Serialize message field [mfccs_mean]
    bufferOffset = _serializer.float32(obj.mfccs_mean, buffer, bufferOffset);
    // Serialize message field [mfccs_variance]
    bufferOffset = _serializer.float32(obj.mfccs_variance, buffer, bufferOffset);
    // Serialize message field [spectral_centroids]
    bufferOffset = _serializer.float32(obj.spectral_centroids, buffer, bufferOffset);
    // Serialize message field [spectral_rolloff]
    bufferOffset = _serializer.float32(obj.spectral_rolloff, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MsgAcousticFeature
    let len;
    let data = new MsgAcousticFeature(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [rms_energy]
    data.rms_energy = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [amplitude_envelope]
    data.amplitude_envelope = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [zero_crossing_rate]
    data.zero_crossing_rate = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [mfccs_mean]
    data.mfccs_mean = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [mfccs_variance]
    data.mfccs_variance = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [spectral_centroids]
    data.spectral_centroids = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [spectral_rolloff]
    data.spectral_rolloff = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 28;
  }

  static datatype() {
    // Returns string type for a message object
    return 'acoustic_monitoring_msgs/MsgAcousticFeature';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c14a16b80445b9cad4c6f29ce8f94aa6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    # time-domain features
    float32 rms_energy
    float32 amplitude_envelope
    float32 zero_crossing_rate
    # frequency-domain features
    # float32 mfccs
    float32 mfccs_mean
    float32 mfccs_variance
    float32 spectral_centroids
    float32 spectral_rolloff
    
    
    # spectral_centroid computes the "average" frequency at each frame, where frequencies are weighted relatively by their energy.
    # spectral_bandwidth similar to centroid, but for variance (or other moments).
    # spectral_rolloff essentially the maximum: finds the frequency f such that almost all of the energy (by default, 85%)
    
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MsgAcousticFeature(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.rms_energy !== undefined) {
      resolved.rms_energy = msg.rms_energy;
    }
    else {
      resolved.rms_energy = 0.0
    }

    if (msg.amplitude_envelope !== undefined) {
      resolved.amplitude_envelope = msg.amplitude_envelope;
    }
    else {
      resolved.amplitude_envelope = 0.0
    }

    if (msg.zero_crossing_rate !== undefined) {
      resolved.zero_crossing_rate = msg.zero_crossing_rate;
    }
    else {
      resolved.zero_crossing_rate = 0.0
    }

    if (msg.mfccs_mean !== undefined) {
      resolved.mfccs_mean = msg.mfccs_mean;
    }
    else {
      resolved.mfccs_mean = 0.0
    }

    if (msg.mfccs_variance !== undefined) {
      resolved.mfccs_variance = msg.mfccs_variance;
    }
    else {
      resolved.mfccs_variance = 0.0
    }

    if (msg.spectral_centroids !== undefined) {
      resolved.spectral_centroids = msg.spectral_centroids;
    }
    else {
      resolved.spectral_centroids = 0.0
    }

    if (msg.spectral_rolloff !== undefined) {
      resolved.spectral_rolloff = msg.spectral_rolloff;
    }
    else {
      resolved.spectral_rolloff = 0.0
    }

    return resolved;
    }
};

module.exports = MsgAcousticFeature;
