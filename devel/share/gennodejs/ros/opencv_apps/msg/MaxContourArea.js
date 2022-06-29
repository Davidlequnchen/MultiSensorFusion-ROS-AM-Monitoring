// Auto-generated. Do not edit!

// (in-package opencv_apps.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class MaxContourArea {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.meltpool_contour_area = null;
      this.ellipse_angle = null;
      this.ellipse_x = null;
      this.ellipse_y = null;
      this.ellipse_width = null;
      this.ellipse_height = null;
      this.rectangle_angle = null;
      this.rectangle_x = null;
      this.rectangle_y = null;
      this.rectangle_width = null;
      this.rectangle_height = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('meltpool_contour_area')) {
        this.meltpool_contour_area = initObj.meltpool_contour_area
      }
      else {
        this.meltpool_contour_area = 0.0;
      }
      if (initObj.hasOwnProperty('ellipse_angle')) {
        this.ellipse_angle = initObj.ellipse_angle
      }
      else {
        this.ellipse_angle = 0.0;
      }
      if (initObj.hasOwnProperty('ellipse_x')) {
        this.ellipse_x = initObj.ellipse_x
      }
      else {
        this.ellipse_x = 0.0;
      }
      if (initObj.hasOwnProperty('ellipse_y')) {
        this.ellipse_y = initObj.ellipse_y
      }
      else {
        this.ellipse_y = 0.0;
      }
      if (initObj.hasOwnProperty('ellipse_width')) {
        this.ellipse_width = initObj.ellipse_width
      }
      else {
        this.ellipse_width = 0.0;
      }
      if (initObj.hasOwnProperty('ellipse_height')) {
        this.ellipse_height = initObj.ellipse_height
      }
      else {
        this.ellipse_height = 0.0;
      }
      if (initObj.hasOwnProperty('rectangle_angle')) {
        this.rectangle_angle = initObj.rectangle_angle
      }
      else {
        this.rectangle_angle = 0.0;
      }
      if (initObj.hasOwnProperty('rectangle_x')) {
        this.rectangle_x = initObj.rectangle_x
      }
      else {
        this.rectangle_x = 0.0;
      }
      if (initObj.hasOwnProperty('rectangle_y')) {
        this.rectangle_y = initObj.rectangle_y
      }
      else {
        this.rectangle_y = 0.0;
      }
      if (initObj.hasOwnProperty('rectangle_width')) {
        this.rectangle_width = initObj.rectangle_width
      }
      else {
        this.rectangle_width = 0.0;
      }
      if (initObj.hasOwnProperty('rectangle_height')) {
        this.rectangle_height = initObj.rectangle_height
      }
      else {
        this.rectangle_height = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MaxContourArea
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [meltpool_contour_area]
    bufferOffset = _serializer.float64(obj.meltpool_contour_area, buffer, bufferOffset);
    // Serialize message field [ellipse_angle]
    bufferOffset = _serializer.float64(obj.ellipse_angle, buffer, bufferOffset);
    // Serialize message field [ellipse_x]
    bufferOffset = _serializer.float64(obj.ellipse_x, buffer, bufferOffset);
    // Serialize message field [ellipse_y]
    bufferOffset = _serializer.float64(obj.ellipse_y, buffer, bufferOffset);
    // Serialize message field [ellipse_width]
    bufferOffset = _serializer.float64(obj.ellipse_width, buffer, bufferOffset);
    // Serialize message field [ellipse_height]
    bufferOffset = _serializer.float64(obj.ellipse_height, buffer, bufferOffset);
    // Serialize message field [rectangle_angle]
    bufferOffset = _serializer.float64(obj.rectangle_angle, buffer, bufferOffset);
    // Serialize message field [rectangle_x]
    bufferOffset = _serializer.float64(obj.rectangle_x, buffer, bufferOffset);
    // Serialize message field [rectangle_y]
    bufferOffset = _serializer.float64(obj.rectangle_y, buffer, bufferOffset);
    // Serialize message field [rectangle_width]
    bufferOffset = _serializer.float64(obj.rectangle_width, buffer, bufferOffset);
    // Serialize message field [rectangle_height]
    bufferOffset = _serializer.float64(obj.rectangle_height, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MaxContourArea
    let len;
    let data = new MaxContourArea(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [meltpool_contour_area]
    data.meltpool_contour_area = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ellipse_angle]
    data.ellipse_angle = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ellipse_x]
    data.ellipse_x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ellipse_y]
    data.ellipse_y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ellipse_width]
    data.ellipse_width = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ellipse_height]
    data.ellipse_height = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [rectangle_angle]
    data.rectangle_angle = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [rectangle_x]
    data.rectangle_x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [rectangle_y]
    data.rectangle_y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [rectangle_width]
    data.rectangle_width = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [rectangle_height]
    data.rectangle_height = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 88;
  }

  static datatype() {
    // Returns string type for a message object
    return 'opencv_apps/MaxContourArea';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c924e5f1e96fc91c0132097ca211cda0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    float64 meltpool_contour_area
    float64 ellipse_angle
    float64 ellipse_x
    float64 ellipse_y
    float64 ellipse_width
    float64 ellipse_height
    float64 rectangle_angle
    float64 rectangle_x
    float64 rectangle_y
    float64 rectangle_width
    float64 rectangle_height
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
    const resolved = new MaxContourArea(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.meltpool_contour_area !== undefined) {
      resolved.meltpool_contour_area = msg.meltpool_contour_area;
    }
    else {
      resolved.meltpool_contour_area = 0.0
    }

    if (msg.ellipse_angle !== undefined) {
      resolved.ellipse_angle = msg.ellipse_angle;
    }
    else {
      resolved.ellipse_angle = 0.0
    }

    if (msg.ellipse_x !== undefined) {
      resolved.ellipse_x = msg.ellipse_x;
    }
    else {
      resolved.ellipse_x = 0.0
    }

    if (msg.ellipse_y !== undefined) {
      resolved.ellipse_y = msg.ellipse_y;
    }
    else {
      resolved.ellipse_y = 0.0
    }

    if (msg.ellipse_width !== undefined) {
      resolved.ellipse_width = msg.ellipse_width;
    }
    else {
      resolved.ellipse_width = 0.0
    }

    if (msg.ellipse_height !== undefined) {
      resolved.ellipse_height = msg.ellipse_height;
    }
    else {
      resolved.ellipse_height = 0.0
    }

    if (msg.rectangle_angle !== undefined) {
      resolved.rectangle_angle = msg.rectangle_angle;
    }
    else {
      resolved.rectangle_angle = 0.0
    }

    if (msg.rectangle_x !== undefined) {
      resolved.rectangle_x = msg.rectangle_x;
    }
    else {
      resolved.rectangle_x = 0.0
    }

    if (msg.rectangle_y !== undefined) {
      resolved.rectangle_y = msg.rectangle_y;
    }
    else {
      resolved.rectangle_y = 0.0
    }

    if (msg.rectangle_width !== undefined) {
      resolved.rectangle_width = msg.rectangle_width;
    }
    else {
      resolved.rectangle_width = 0.0
    }

    if (msg.rectangle_height !== undefined) {
      resolved.rectangle_height = msg.rectangle_height;
    }
    else {
      resolved.rectangle_height = 0.0
    }

    return resolved;
    }
};

module.exports = MaxContourArea;
