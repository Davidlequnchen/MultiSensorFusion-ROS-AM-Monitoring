#ifndef _MICROEPSILON_SCANCONTROL_ROS_H_
#define _MICROEPSILON_SCANCONTROL_ROS_H_

#include "llt.h"
#include <vector>
#include <queue>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <math.h>
#include <libpng16/png.h>
#include <fstream>

namespace microepsilon_scancontrol
{
const int SCANNER_RESOLUTION = 640; // points per profile, 2048 for GAS, 640 for SIMTech side
// guint32 resolution;

// class TimeSync
// {
// public:
//   virtual void sync_time(unsigned int profile_counter, double shutter_open, double shutter_close) = 0;
// };


// struct MeasurementField
// {
//   ushort x_start, x_size, z_start, z_size;

//   MeasurementField()
//   {
//     x_start = z_start = 0;
//     x_size = z_size = 65535;
//   }

//   // Each variable defines the part of the border that gets cut off. Min 0.0, Max 1.0
//   MeasurementField(double left, double right, double far, double near)
//   {
//     assert(left >= 0.0);
//     assert(right >= 0.0);
//     assert(far >= 0.0);
//     assert(near >= 0.0);
//     assert(left + right <= 1.0);
//     assert(far + near <= 1.0);
//     ushort umax = 65535;
//     z_start = near * umax;
//     z_size = umax - near * umax - far * umax;
//     x_start = left * umax;
//     x_size = umax - left * umax - right * umax;
//   }
//   MeasurementField(ushort x_start, ushort x_size, ushort z_start, ushort z_size)
//     : x_start(x_start), x_size(x_size), z_start(z_start), z_size(z_size)
//   {
//   }
// };

// //stores x and y , and timestamp information for one profile
// struct ScanProfile
// {
//   guint16 z[SCANNER_RESOLUTION];
//   guint16 x[SCANNER_RESOLUTION];
//   guint16 padding[SCANNER_RESOLUTION - 8];
//   unsigned char timestamp[16];
// };

struct ScanProfileConverted
{
  std::vector<double> x;
  std::vector<double> z;
  unsigned int profile_counter;
  double shutter_open;
  double shutter_close;
};
typedef boost::shared_ptr<ScanProfileConverted> ScanProfileConvertedPtr;


class Notifyee
{
public:
  // virtual void notify() = 0; // for version 1 and 3
  virtual void notify ( ScanProfileConvertedPtr ) = 0; // for second version
};



class Scanner
{
private:
  bool scanning_;
  bool connected_;
  // bool need_time_sync_;

  unsigned int idle_time_;
  unsigned int shutter_time_;
  // unsigned int container_size_;
  // boost::mutex mutex_;
  unsigned int fieldCount_;
  // TimeSync* time_sync_;
  Notifyee* notifyee_;
  // MeasurementField field_;
  std::string serial_number_, path_to_device_properties_;

  //LLT llt_;
  CInterfaceLLT llt_;
  TScannerType m_tscanCONTROLType;
  // Create a device handle
  //CInterfaceLLT llt_ = new CInterfaceLLT(); 


  // std::vector<guint8> container_buffer; 
  // gint32 container_count, needed_container_count;
  // guint32 profile_data_size;
  // event handle
  //EHANDLE *event;

  // temperary profile buffer to read profile in call back function
  // std::vector<unsigned char>ProfileBuffer;
  // profiles to be stored in a container buffer
  // std::vector<ScanProfile> container_buffer_; // which resized to container size when setting class constructor
  // std::queue<ScanProfileConvertedPtr> profile_queue_; // a pointer of array stores a list of profiles
  bool connect();
  bool disconnect();
  bool initialise();


  
 
  //-------------- functions necessary for call back process
  void new_profile_callback(const void* data, size_t data_size);
  static void control_lost_callback_wrapper(ArvGvDevice* gv_device, gpointer user_data);
  void control_lost_callback(ArvGvDevice* gv_device);
  static void new_profile_callback_wrapper(const void* data, size_t data_size, gpointer user_data);
  //--------------
  // bool setMeasuringField(ushort x_start, ushort x_size, ushort z_start, ushort z_size);
  // void WriteCommand(unsigned int command, unsigned int data);
  // void WriteValue2Register(unsigned short value);
  void DisplayProfiles(double *x, double *z, guint32 resolution);
  void DisplayTimestamp(guchar *timestamp);
  
public:
  // ----- version 1
  //  Scanner(TimeSync* time_sync, Notifyee* notifyee, unsigned int shutter_time, unsigned int idle_time,
  //          unsigned int container_size, MeasurementField field, std::string serial_number,
  //          std::string path_to_device_properties); 
  // ------- version 2  -------------
  Scanner ( Notifyee *notifyee, unsigned int shutter_time, unsigned int idle_time,
                     std::string serial_number, std::string path_to_device_properties );
  // ----------version 3------
  // Scanner(TimeSync* time_sync, Notifyee* notifyee, unsigned int shutter_time, unsigned int idle_time,
  //          unsigned int container_size, std::string serial_number,
  //          std::string path_to_device_properties); 
  ~Scanner();

  bool reconnect();
  bool startScanning();
  bool stopScanning();
  bool setLaserPower(bool on);
  // bool hasNewData();
  // ScanProfileConvertedPtr getData();
};

}  // namespace microepsilon_scancontrol
#endif
