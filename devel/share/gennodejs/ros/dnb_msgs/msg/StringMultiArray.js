// Auto-generated. Do not edit!

// (in-package dnb_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class StringMultiArray {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.layout = null;
      this.data = null;
    }
    else {
      if (initObj.hasOwnProperty('layout')) {
        this.layout = initObj.layout
      }
      else {
        this.layout = new std_msgs.msg.MultiArrayLayout();
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
    // Serializes a message object of type StringMultiArray
    // Serialize message field [layout]
    bufferOffset = std_msgs.msg.MultiArrayLayout.serialize(obj.layout, buffer, bufferOffset);
    // Serialize message field [data]
    bufferOffset = _arraySerializer.string(obj.data, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type StringMultiArray
    let len;
    let data = new StringMultiArray(null);
    // Deserialize message field [layout]
    data.layout = std_msgs.msg.MultiArrayLayout.deserialize(buffer, bufferOffset);
    // Deserialize message field [data]
    data.data = _arrayDeserializer.string(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.MultiArrayLayout.getMessageSize(object.layout);
    object.data.forEach((val) => {
      length += 4 + val.length;
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'dnb_msgs/StringMultiArray';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '77f374096c7ec9d15c35d6d0e5287e6b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/MultiArrayLayout layout
    string[] data
    ================================================================================
    MSG: std_msgs/MultiArrayLayout
    # The multiarray declares a generic multi-dimensional array of a
    # particular data type.  Dimensions are ordered from outer most
    # to inner most.
    
    MultiArrayDimension[] dim # Array of dimension properties
    uint32 data_offset        # padding elements at front of data
    
    # Accessors should ALWAYS be written in terms of dimension stride
    # and specified outer-most dimension first.
    # 
    # multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]
    #
    # A standard, 3-channel 640x480 image with interleaved color channels
    # would be specified as:
    #
    # dim[0].label  = "height"
    # dim[0].size   = 480
    # dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)
    # dim[1].label  = "width"
    # dim[1].size   = 640
    # dim[1].stride = 3*640 = 1920
    # dim[2].label  = "channel"
    # dim[2].size   = 3
    # dim[2].stride = 3
    #
    # multiarray(i,j,k) refers to the ith row, jth column, and kth channel.
    
    ================================================================================
    MSG: std_msgs/MultiArrayDimension
    string label   # label of given dimension
    uint32 size    # size of given dimension (in type units)
    uint32 stride  # stride of given dimension
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new StringMultiArray(null);
    if (msg.layout !== undefined) {
      resolved.layout = std_msgs.msg.MultiArrayLayout.Resolve(msg.layout)
    }
    else {
      resolved.layout = new std_msgs.msg.MultiArrayLayout()
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

module.exports = StringMultiArray;
