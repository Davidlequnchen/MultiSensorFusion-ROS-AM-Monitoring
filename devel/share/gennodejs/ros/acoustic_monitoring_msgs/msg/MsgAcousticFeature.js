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
      this.mel_spectrogram = null;
      this.mfccs = null;
      this.ber = null;
      this.spectral_centroids = null;
      this.spectral_rolloff = null;
      this.spectral_bandwidth = null;
      this.spectral_flatness = null;
      this.spectral_crest_factor = null;
      this.spectral_kurtosis = null;
      this.spectral_variance = null;
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
      if (initObj.hasOwnProperty('mel_spectrogram')) {
        this.mel_spectrogram = initObj.mel_spectrogram
      }
      else {
        this.mel_spectrogram = [];
      }
      if (initObj.hasOwnProperty('mfccs')) {
        this.mfccs = initObj.mfccs
      }
      else {
        this.mfccs = [];
      }
      if (initObj.hasOwnProperty('ber')) {
        this.ber = initObj.ber
      }
      else {
        this.ber = 0.0;
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
      if (initObj.hasOwnProperty('spectral_bandwidth')) {
        this.spectral_bandwidth = initObj.spectral_bandwidth
      }
      else {
        this.spectral_bandwidth = 0.0;
      }
      if (initObj.hasOwnProperty('spectral_flatness')) {
        this.spectral_flatness = initObj.spectral_flatness
      }
      else {
        this.spectral_flatness = 0.0;
      }
      if (initObj.hasOwnProperty('spectral_crest_factor')) {
        this.spectral_crest_factor = initObj.spectral_crest_factor
      }
      else {
        this.spectral_crest_factor = 0.0;
      }
      if (initObj.hasOwnProperty('spectral_kurtosis')) {
        this.spectral_kurtosis = initObj.spectral_kurtosis
      }
      else {
        this.spectral_kurtosis = 0.0;
      }
      if (initObj.hasOwnProperty('spectral_variance')) {
        this.spectral_variance = initObj.spectral_variance
      }
      else {
        this.spectral_variance = 0.0;
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
    // Serialize message field [mel_spectrogram]
    bufferOffset = _arraySerializer.float32(obj.mel_spectrogram, buffer, bufferOffset, null);
    // Serialize message field [mfccs]
    bufferOffset = _arraySerializer.float32(obj.mfccs, buffer, bufferOffset, null);
    // Serialize message field [ber]
    bufferOffset = _serializer.float32(obj.ber, buffer, bufferOffset);
    // Serialize message field [spectral_centroids]
    bufferOffset = _serializer.float32(obj.spectral_centroids, buffer, bufferOffset);
    // Serialize message field [spectral_rolloff]
    bufferOffset = _serializer.float32(obj.spectral_rolloff, buffer, bufferOffset);
    // Serialize message field [spectral_bandwidth]
    bufferOffset = _serializer.float32(obj.spectral_bandwidth, buffer, bufferOffset);
    // Serialize message field [spectral_flatness]
    bufferOffset = _serializer.float32(obj.spectral_flatness, buffer, bufferOffset);
    // Serialize message field [spectral_crest_factor]
    bufferOffset = _serializer.float32(obj.spectral_crest_factor, buffer, bufferOffset);
    // Serialize message field [spectral_kurtosis]
    bufferOffset = _serializer.float32(obj.spectral_kurtosis, buffer, bufferOffset);
    // Serialize message field [spectral_variance]
    bufferOffset = _serializer.float32(obj.spectral_variance, buffer, bufferOffset);
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
    // Deserialize message field [mel_spectrogram]
    data.mel_spectrogram = _arrayDeserializer.float32(buffer, bufferOffset, null)
    // Deserialize message field [mfccs]
    data.mfccs = _arrayDeserializer.float32(buffer, bufferOffset, null)
    // Deserialize message field [ber]
    data.ber = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [spectral_centroids]
    data.spectral_centroids = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [spectral_rolloff]
    data.spectral_rolloff = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [spectral_bandwidth]
    data.spectral_bandwidth = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [spectral_flatness]
    data.spectral_flatness = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [spectral_crest_factor]
    data.spectral_crest_factor = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [spectral_kurtosis]
    data.spectral_kurtosis = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [spectral_variance]
    data.spectral_variance = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += 4 * object.mel_spectrogram.length;
    length += 4 * object.mfccs.length;
    return length + 52;
  }

  static datatype() {
    // Returns string type for a message object
    return 'acoustic_monitoring_msgs/MsgAcousticFeature';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '57131d07b28013debc0969e0928b0739';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    # time-domain features
    float32 rms_energy
    float32 amplitude_envelope
    float32 zero_crossing_rate
    # freqeuncy domain features
    float32[] mel_spectrogram
    float32[] mfccs
    float32 ber
    float32 spectral_centroids
    float32 spectral_rolloff
    float32 spectral_bandwidth
    float32 spectral_flatness
    float32 spectral_crest_factor
    float32 spectral_kurtosis
    float32 spectral_variance
    
    
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

    if (msg.mel_spectrogram !== undefined) {
      resolved.mel_spectrogram = msg.mel_spectrogram;
    }
    else {
      resolved.mel_spectrogram = []
    }

    if (msg.mfccs !== undefined) {
      resolved.mfccs = msg.mfccs;
    }
    else {
      resolved.mfccs = []
    }

    if (msg.ber !== undefined) {
      resolved.ber = msg.ber;
    }
    else {
      resolved.ber = 0.0
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

    if (msg.spectral_bandwidth !== undefined) {
      resolved.spectral_bandwidth = msg.spectral_bandwidth;
    }
    else {
      resolved.spectral_bandwidth = 0.0
    }

    if (msg.spectral_flatness !== undefined) {
      resolved.spectral_flatness = msg.spectral_flatness;
    }
    else {
      resolved.spectral_flatness = 0.0
    }

    if (msg.spectral_crest_factor !== undefined) {
      resolved.spectral_crest_factor = msg.spectral_crest_factor;
    }
    else {
      resolved.spectral_crest_factor = 0.0
    }

    if (msg.spectral_kurtosis !== undefined) {
      resolved.spectral_kurtosis = msg.spectral_kurtosis;
    }
    else {
      resolved.spectral_kurtosis = 0.0
    }

    if (msg.spectral_variance !== undefined) {
      resolved.spectral_variance = msg.spectral_variance;
    }
    else {
      resolved.spectral_variance = 0.0
    }

    return resolved;
    }
};

module.exports = MsgAcousticFeature;
