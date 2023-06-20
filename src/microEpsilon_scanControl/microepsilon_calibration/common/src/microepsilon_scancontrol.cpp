#include "microepsilon_scancontrol.h"
#include "llt.h"


namespace microepsilon_scancontrol
{
bool Scanner::connect()
{
  if (connected_)
  {
    return true;
  }

  // list all connected microepsilon laser scanners, the maximum number is 5
  std::vector<char *> vcInterfaces(5);
  // std::vector<unsigned int> vuiResolutions(10);
  guint32 uiInterfaceCount = 0;
  int activeDevice = 0;

  // Search for scanners on interface
  int iRetValue = CInterfaceLLT::GetDeviceInterfaces(&vcInterfaces[0], vcInterfaces.size());

  if (iRetValue == ERROR_GETDEVINTERFACE_REQUEST_COUNT)
  {
    std::cout << "There are more than " << vcInterfaces.size() << " scanCONTROL connected \n";
    uiInterfaceCount = vcInterfaces.size();
  }
  else if (iRetValue < 1)
  {
    std::cout << "A error occured during searching for connected scanCONTROL \n";
    uiInterfaceCount = 0;
    return false;
  }
  else
  {
    uiInterfaceCount = iRetValue;
    if (uiInterfaceCount == 0)
      std::cout << "There is no scanCONTROL connected -Exiting\n";
    else if (uiInterfaceCount == 1)
      std::cout << "There is 1 scanCONTROL connected \n";
    else
      std::cout << "There are " << uiInterfaceCount << " scanCONTROL connected \n";
    bool foundSN = false;
    for (int i = 0; i < uiInterfaceCount; ++i)
    {
      std::cout << vcInterfaces[i] << "" << std::endl;
      std::string tempStr = vcInterfaces[i];
      if (serial_number_.size() != 0 &&
          tempStr.compare(tempStr.size() - serial_number_.size(), serial_number_.size(), serial_number_) == 0)
      {
        std::cout << "Found Device with serial number: " << serial_number_ << std::endl;
        foundSN = true;
        activeDevice = i;
        break;
      }
    }
    if (!foundSN && serial_number_.size() != 0)
    {
      std::cout << "Could not find device with S/N: " << serial_number_ << ". Using first device in list." << std::endl;
    }
  }
  // ----------------- this will cause problem so dont use this function!---------------
  //  std::cout << "setting device properties path:\n\t[" << path_to_device_properties_ << "]\n";
  // if ((iRetValue = llt_.SetPathDeviceProperties(path_to_device_properties_.c_str())) < GENERAL_FUNCTION_OK)
  // {
  //   std::cout << "Error setting device properties path:\n\t[" << path_to_device_properties_ << "]\n";
  //     return false;
  // }
  // llt_.SetPathDeviceProperties("./device_properties.dat"); 

  std::cout << "Connecting to " << vcInterfaces[activeDevice] << std::endl;
  if ((llt_.SetDeviceInterface(vcInterfaces[activeDevice])) < GENERAL_FUNCTION_OK)
  {
    std::cout << "Error while setting dev id " << iRetValue << "!\n";
    return false;
  }

  /* Connect to sensor */
  if ((iRetValue = llt_.Connect()) < GENERAL_FUNCTION_OK)
  {
    std::cout << "Error while connecting to camera - Error " << iRetValue << "!\n";
    return false;
  }
  // TScannerType m_tscanCONTROLType;

  if ((iRetValue = llt_.GetLLTType(&m_tscanCONTROLType)) < GENERAL_FUNCTION_OK)
  {
    std::cout << "Error while GetLLTType!\n";
    return false;
  }

  if (iRetValue == GENERAL_FUNCTION_DEVICE_NAME_NOT_SUPPORTED)
  {
    std::cout << "Can't decode scanCONTROL type. Please contact Micro Epsilon for a newer version of the library.\n";
  }
 
 
  if (m_tscanCONTROLType >= scanCONTROL27xx_25 && m_tscanCONTROLType <= scanCONTROL27xx_xxx)
  {
    std::cout << "The scanCONTROL is a scanCONTROL27xx\n" << std::endl;
  }
  else if (m_tscanCONTROLType >= scanCONTROL26xx_25 && m_tscanCONTROLType <= scanCONTROL26xx_xxx)
  {
    std::cout << "The scanCONTROL is a scanCONTROL26xx\n" << std::endl;
  }
  else if (m_tscanCONTROLType >= scanCONTROL29xx_25 && m_tscanCONTROLType <= scanCONTROL29xx_xxx)
  {
    std::cout << "The scanCONTROL is a scanCONTROL29xx\n" << std::endl;
  }
  else if (m_tscanCONTROLType >= scanCONTROL30xx_25 && m_tscanCONTROLType <= scanCONTROL30xx_xxx)
  {
    std::cout << "The scanCONTROL is a scanCONTROL30xx\n" << std::endl;
  }
  else if (m_tscanCONTROLType >= scanCONTROL25xx_25 && m_tscanCONTROLType <= scanCONTROL25xx_xxx)
  {
    std::cout << "The scanCONTROL is a scanCONTROL25xx\n" << std::endl;
  }
  else
  {
    std::cout << "The scanCONTROL is a undefined type\nPlease contact Micro-Epsilon for a newer SDK\n";
  }
  connected_ = true;

  return true;
}

// setup the parameters for me laser scanner
bool Scanner::initialise()
{
  if (!connected_)
  {
    return false;
  }

  // set to default config
  //llt_.ReadWriteUserModes(false, 0);

  if (llt_.SetResolution(SCANNER_RESOLUTION) < GENERAL_FUNCTION_OK)
  {
    std::cout << "Error while setting resolution!\n";
    return false;
  }
  // should be CONTAINER here if you are using container mode!
  if ((llt_.SetProfileConfig(PROFILE)) < GENERAL_FUNCTION_OK)
  {
    std::cout << "Error while setting PROFILE Mode!\n";
    return false;
  }

  // if ((llt_.SetBufferCount(4)) < GENERAL_FUNCTION_OK)
  // {
  //   std::cout << "Error while setting BufferCount!\n";
  //   return false;
  // }

  if (llt_.SetFeature(FEATURE_FUNCTION_IDLE_TIME, idle_time_) < GENERAL_FUNCTION_OK) 
  {
    std::cout << "Error while setting idle_time!\n";
    return false;
  }

 
  if (llt_.SetFeature(FEATURE_FUNCTION_EXPOSURE_TIME, shutter_time_) < GENERAL_FUNCTION_OK)
  {
    std::cout << "Error while setting ShutterTime!\n";
    return false;
  }

  if (llt_.SetFeature(FEATURE_FUNCTION_TRIGGER, TRIG_INTERNAL) < GENERAL_FUNCTION_OK)
  {
    std::cout << "Error while setting trigger!\n";
    return false;
  }

  /// this is necessary for version 1 and 3-, if you are using conatiner mode-----------------------------------------------------------------
  // int iRetValue;
  // // Set the active packet size for the size of the Ethernet streaming packets.
  // std::cout << "Set PacketSize" << std::endl;
  // if ((iRetValue = llt_.SetPacketSize(SCANNER_RESOLUTION)) < GENERAL_FUNCTION_OK)
  // {
  //   std::cout << "Error during SetPacketSize\n" << iRetValue;
  //   return false;
  // }
  
  /* Register Callbacks for profiles */
  std::cout << "Register callbacks for new profile buffer" << std::endl;
  if ((llt_.RegisterBufferCallback((gpointer)&Scanner::new_profile_callback_wrapper, this)) < GENERAL_FUNCTION_OK) 
  //if ((llt_.RegisterBufferCallback((gpointer)&Scanner::NewProfile, this)) < GENERAL_FUNCTION_OK)
  {
    std::cout << "Error while registering buffer callback!\n";
    return false;
  }

  std::cout << "Register callbacks for control lost" << std::endl;
  if ((llt_.RegisterControlLostCallback((gpointer)&Scanner::control_lost_callback_wrapper, this)) < GENERAL_FUNCTION_OK) 
  {
    std::cout << "Error while registering control lost callback!\n";
    return false;
  }

  return true;
}

bool Scanner::disconnect()
{
  if (!connected_)
  {
    return true;
  }
  llt_.Disconnect();
  // CInterfaceLLT::FreeEvent(event);
  connected_ = false;
  return true;
}


void Scanner::control_lost_callback_wrapper(ArvGvDevice *gv_device, gpointer user_data)
{
  ((Scanner *)user_data)->control_lost_callback(gv_device);
}

void Scanner::control_lost_callback(ArvGvDevice *gv_device)
{
  connected_ = false;
  std::cout << "Connection to scanner lost! Trying to reconnect!" << std::endl;
  bool was_scanning = scanning_;
  reconnect();
  if (was_scanning)
  {
    startScanning();
  }
}


//-------------------- new profile callback-----------------------------------------------------
void Scanner::new_profile_callback_wrapper(const void *data, size_t data_size, gpointer user_data)
{
  ((Scanner *)user_data)->new_profile_callback(data, data_size);
}

void Scanner::new_profile_callback(const void *data, size_t data_size)
{
  //   boost::mutex::scoped_lock lock(mutex_);
  //   //needed_container_count = 100;
  //   //if (data != NULL && data_size == container_buffer.size())
  //   if (data != NULL && data_size == SCANNER_RESOLUTION * fieldCount_ * container_size_ * 2)
  //   {
  //     //memcpy(&container_buffer[0], data, data_size); //copy the data into the container
  //     memcpy(&container_buffer_[0], data, data_size); //one profile get into one container buffer element
  //   }
    
    
  //   gint32 ret = 0;
  //   unsigned int profile_counter;
  //   //guint32 polled_data_size = 0;
  //   double shutter_open; // time stamp
  //   double shutter_close; // time stamp of shutter close
  //   // Timestamp extraction function: evaluates the whole timestamp of a profile. It returns the internal timestamp of
  //   // the beginning and the end of the shutter interval and the consecutive profile numbers.
  //   CInterfaceLLT::Timestamp2TimeAndCount(container_buffer_[container_buffer_.size() - 1].timestamp, &shutter_open, &shutter_close,
  //                                             &profile_counter, NULL);
  //   //CInterfaceLLT::Timestamp2TimeAndCount(&container_buffer[(SCANNER_RESOLUTION * container_size_) - 16], &shutter_open, &shutter_close,
  //   //                                      &profile_counter, NULL); // get the last profile counter and shutter time
                                      

  
  //   if (need_time_sync_) // if sensor start scanning, then need time syncronize is true
  //   {
  //     time_sync_->sync_time(profile_counter, shutter_open, shutter_close);
  //     need_time_sync_ = false;
  //   }

   
  //   for (int i = 0; i < container_buffer_.size(); ++i)
  //   //for (int i = 0; i < container_size_; ++i) // for each profile in the container, we will evaluate it and push it into a profile queue
  //   {
  //     ScanProfileConvertedPtr profile(new ScanProfileConverted);
  //     DisplayTimestamp(container_buffer_[i].timestamp); 
  //     CInterfaceLLT::Timestamp2TimeAndCount(container_buffer_[i].timestamp, &profile->shutter_open, &profile->shutter_close,
  //                                            &profile->profile_counter, NULL);
  //       //DisplayTimestamp(&container_buffer[(SCANNER_RESOLUTION * 64) - 16]);
  //       //CInterfaceLLT::Timestamp2TimeAndCount(&container_buffer[(SCANNER_RESOLUTION * i) - 16], &profile->shutter_open, &profile->shutter_close,
  //       //                                      &profile->profile_counter, NULL);//get time info for each profile 
      
  //     for (int j = 0; j < SCANNER_RESOLUTION; ++j) // for each point in one profile
  //     {
  //       if (container_buffer_[i].z[j] != 0) 
  //       {  
  //         //   guint32 rearrangement = 0;
  //         //   llt_.GetFeature(FEATURE_FUNCTION_PROFILE_REARRANGEMENT, &rearrangement);
  //         //   std::vector<double> value_x, value_z; // temporary vector to store x and y in one profile(current one)
  //         //   std::vector<gushort> intens, thres, refl_width;
  //         //   //--------------------------------------------------------------------------------------------
  //         //   // value_x.resize(SCANNER_RESOLUTION * profile_counter);
  //         //   // value_z.resize(SCANNER_RESOLUTION * profile_counter);
  //         //   // intens.resize(SCANNER_RESOLUTION * profile_counter);
  //         //   // thres.resize(SCANNER_RESOLUTION * profile_counter);
  //         //   // refl_width.resize(SCANNER_RESOLUTION * profile_counter);
            
  //         //   // // Extract/convert complete raw data to mm
  //         //   // ret = CInterfaceLLT::ConvertRearrangedContainer2Values(&container_buffer[i], container_buffer.size(), rearrangement,
  //         //   //                                                       profile_counter, m_tscanCONTROLType, 0, &refl_width[0], &intens[0],
  //         //   //                                                       &thres[0], &value_x[0], &value_z[0]);
  //         //   // if (ret != (CONVERT_X | CONVERT_Z | CONVERT_THRESHOLD | CONVERT_WIDTH | CONVERT_MAXIMUM)) {
  //         //   //     std::cout << "Error while extracting profiles" << std::endl;
  //         //   // }
  //         //  //--------------------------------------------------------------------------------------------------
  //         //   value_x.resize(SCANNER_RESOLUTION);
  //         //   value_z.resize(SCANNER_RESOLUTION);
  //         //   //Conversion of profile data in coordinates and further measuring point information. The size
  //         //   // of the data arrays must correspond to the profile resolution
  //         //   if ((ret = CInterfaceLLT::ConvertProfile2Values(&container_buffer[0], container_buffer.size(), SCANNER_RESOLUTION, PROFILE, m_tscanCONTROLType, 0,
  //         //                                           NULL, NULL, NULL, &value_x[0], &value_z[0], NULL, NULL)) !=
  //         //                                           (CONVERT_X | CONVERT_Z)) {
  //         //              std::cout << "Error while extracting profiles" << std::endl;
  //         //       }
  //         //   else{
  //         //     DisplayProfiles(&value_x[0], &value_z[0], SCANNER_RESOLUTION); // print the x and z value in terminal for current profile
  //         //     //DisplayTimestamp(&container_buffer[(SCANNER_RESOLUTION * 64) - 16]); // print the shutter time and profile count information
  //         //     profile->x.push_back(value_x[0]);
  //         //     profile->z.push_back(value_z[0]);
  //         //     }
  //         double scaling, offset;
  //         if ((ret = llt_.GetLLTScalingAndOffset  (&scaling, &offset)) != GENERAL_FUNCTION_OK){
  //             std::cout << "Error while extracting profiles" << std::endl;
  //         }
  //         else{
  //             double x = ((container_buffer_[i].x[j] - (guint16)32768) * scaling) / 1000.0;  // in meter
  //             double z = ((container_buffer_[i].z[j] - (guint16)32768) * scaling + offset) / 1000.0;  // in meter
  //             profile->x.push_back(x);
  //             profile->z.push_back(z);
  //         }
        
            
  //        }
  //     }
  //     // ---------------------------------------------------------------
  //     profile_queue_.push(profile);
  //   }
  // notifyee_->notify(); // publshi ros message, the point cloud message of each profile(640 points/profile as defaut)

//--------------------------------------------------------------------------------------------- version 2-------------------------------
        // save the input data
        std::vector < unsigned char > profile_buffer_;
        profile_buffer_.resize ( SCANNER_RESOLUTION * 64 );
        if ( data != NULL && data_size == profile_buffer_.size() )
        {
          memcpy ( &profile_buffer_[0], data, data_size );
        }

        ScanProfileConvertedPtr profile ( new ScanProfileConverted );
        CInterfaceLLT::Timestamp2TimeAndCount ( &profile_buffer_[0], &( profile->shutter_open ), &(profile->shutter_close), &(profile->profile_counter), NULL );
        // show the time information of the input profile
        std::cout <<"[profile_counter, shutter_open, shutter_close] = [" << profile->profile_counter << ", " << profile->shutter_open << ", " << profile->shutter_close << "]" 
                      << std::endl;
        profile->x.resize ( SCANNER_RESOLUTION );
        profile->z.resize ( SCANNER_RESOLUTION );
        // CInterfaceLLT::ConvertProfile2Values(&profile_buffer_[0], profile_buffer_.size(), &llt_.appData, SCANNER_RESOLUTION, m_tscanCONTROLType, 0,
        //                                          NULL, NULL, NULL, &(profile->x[0]), &(profile->z[0]), NULL, NULL );
        if (( CInterfaceLLT::ConvertProfile2Values(&profile_buffer_[0], profile_buffer_.size(), SCANNER_RESOLUTION, PROFILE, m_tscanCONTROLType, 0,
                                                 NULL, NULL, NULL, &(profile->x[0]), &(profile->z[0]), NULL, NULL )) != 
        
          (CONVERT_X | CONVERT_Z)) {
          std::cout << "Error while extracting profiles" << std::endl;
        }

        // publish the new profile
        notifyee_->notify(profile);

}
//------------------------------------------------------------------------------------------------------------------






void Scanner::DisplayProfiles(double *x, double *z, guint32 resolution)
{
    for (guint32 i = 0; i < resolution; i++) {
        std::cout << "\rX: " << x[i] << "  Z: " << z[i];
        //usleep(1250);
    }
    std::cout << std::endl;
}


void Scanner::DisplayTimestamp(guchar *timestamp)
{
    double shutter_open, shutter_close;
    guint32 profile_count;

    CInterfaceLLT::Timestamp2TimeAndCount(&timestamp[0], &shutter_close, &shutter_open, &profile_count, NULL);

    std::cout.precision(8);
    std::cout << "Profile Count: " << profile_count << " ShutterOpen: " << shutter_open
              << " ShutterClose: " << shutter_close << std::endl;
    std::cout.precision(6);
}


// bool Scanner::hasNewData()
// {
//   boost::mutex::scoped_lock lock(mutex_);
//   bool ret = !profile_queue_.empty();
//   return ret;
// }

// ScanProfileConvertedPtr Scanner::getData()
// {
//   boost::mutex::scoped_lock lock(mutex_);
//   ScanProfileConvertedPtr ptr;
//   if (profile_queue_.empty())
//   {
//     return ptr;
//   }

//   ptr = profile_queue_.front();
//   profile_queue_.pop();
//   return ptr;
// }

bool Scanner::startScanning()
{
   // ------------------------------START SETTING CONTAINER MODE ------------------------------------ for version 1
  // need_time_sync_ = true;
  // if (!connected_)
  // {
  //   return false;
  // }
  // if (scanning_)
  // {
  //   return true;
  // }

  // gint32 iRetValue; // BOOL value for true or false
  // // gint32 profile_count = 256;
  // guint32 dwInquiry = 0; // for function rearangement inqury
  
  // // calculate resolution bitfield for the container-----
  // double tmp_log = 1.0 / log(2.0);
  // gint32 container_resolution = (gint32)floor((log((double)SCANNER_RESOLUTION) * tmp_log) + 0.5);
  // //--------------------------------------------------

  // std::cout << "Demonstrate the container mode with rearrangement" << std::endl;
  // if ((iRetValue = llt_.GetFeature(INQUIRY_FUNCTION_PROFILE_REARRANGEMENT, &dwInquiry)) < GENERAL_FUNCTION_OK) 
  // {
  //   std::cout << "Error during GetFeature";
  //   return iRetValue;
  // }

  // if ((dwInquiry & 0x80000000) == 0)
  // {
  //   std::cout << "\nThe connected scanCONTROL don't support the container mode\n\n";
  //   return iRetValue;
  // }

  // // Extract Z
  // // Extract X
  // // calculation for the points per profile = 9 for 640
  // // Extract only 1th reflection
  // // Extract timestamp in extra field
  //  std::cout << "Set rearrangement parameter" << std::endl;
  //   if ((iRetValue = llt_.SetFeature(FEATURE_FUNCTION_PROFILE_REARRANGEMENT,
  //                               CONTAINER_DATA_INTENS | CONTAINER_DATA_WIDTH | CONTAINER_DATA_THRES | CONTAINER_DATA_X |
  //                               CONTAINER_DATA_Z | CONTAINER_STRIPE_1 | CONTAINER_DATA_LSBF |
  //                               container_resolution << 12)) < GENERAL_FUNCTION_OK) 
  //   // if ((iRetValue = llt_.SetFeature(FEATURE_FUNCTION_PROFILE_REARRANGEMENT, 0x00120c03 | 9 << 12)) < GENERAL_FUNCTION_OK)
  //     {
  //       std::cout << "Error during SetFeature(FEATURE_FUNCTION_PROFILE_REARRANGEMENT)" << std::endl;;
  //       return iRetValue;
  //     }
  


  // std::cout << "Set profile container size\n";
  // //  if ((iRetValue = llt_.SetProfileContainerSize(SCANNER_RESOLUTION * fieldCount_, container_size_)) <<  GENERAL_FUNCTION_OK) 
  // // Set container size: witdth and hight, height  determines number of profiles are transmitted in one container---------------------------------------------------------------
  // if ((iRetValue = llt_.SetProfileContainerSize(0, container_size_)) < GENERAL_FUNCTION_OK)
  // {
  //   std::cout << "Error during SetProfileContainerSize";
  //   return false;
  // }

  // // must be here to resize (confirm)
  // container_buffer.resize(SCANNER_RESOLUTION * container_size_); // container is able to hold 64(defult container size) profile
  // //container_buffer.resize(SCANNER_RESOLUTION * fieldCount_ * profile_count * 2); // will show error,(Error while extracting profiles)
 
 
  // // std::cout << "Set setMeasuringField\n";
  // // if (iRetValue = setMeasuringField(field_.x_start, field_.x_size, field_.z_start, field_.z_size) < GENERAL_FUNCTION_OK)
  // // {
  // //   std::cout << "Error during setMeasuringField";
  // //   return false;
  // // }

  // // //CInterfaceLLT::ResetEvent(event);
  // // Setup transfer of multiple profiles
  // std::cout << "Setup transfer of multiple profile\n";
  // // if ((iRetValue = llt_.TransferProfiles(NORMAL_TRANSFER, true)) < GENERAL_FUNCTION_OK)
  // if ((llt_.TransferProfiles(NORMAL_TRANSFER, true)) < GENERAL_FUNCTION_OK)
  // {
  //   std::cout << "Error in profile transfer!\n";
  //   return iRetValue;
  // }
  // scanning_ = true;
  // return true;
  //-------------------------------------------------------------------------- for  version 2---------
  if ( !connected_ )
    {
      return false;
    }
    if ( scanning_ )
    {
      return true;
    }

    int iRetValue;
    // std::cout << "Setup transfer of multiple profile\n";
    if ( ( iRetValue = llt_.TransferProfiles ( NORMAL_TRANSFER, true ) ) < GENERAL_FUNCTION_OK )
    {
      std::cout << "Error in profile transfer!\n";
      return false;
    }
    scanning_ = true;
    return true;
}

bool Scanner::stopScanning()
{
  if (!connected_)
  {
    scanning_ = false;
    return true;
  }
  if (!scanning_)
  {
    return true;
  }
  if ((llt_.TransferProfiles(NORMAL_TRANSFER, false)) < GENERAL_FUNCTION_OK)
  {
    std::cout << "Error while stopping transmission!\n";
    return false;
  }
  scanning_ = false;
  return true;
}

//scanner constructor------------------------------version 1
// Scanner::Scanner(TimeSync *time_sync, Notifyee *notifyee, unsigned int shutter_time, unsigned int idle_time,
//                  unsigned int container_size, MeasurementField field, std::string serial_number,
//                  std::string path_to_device_properties)
//   : time_sync_(time_sync)
//   , notifyee_(notifyee)
//   , shutter_time_(shutter_time)
//   , idle_time_(idle_time)
//   , container_size_(container_size)
//   , field_(field)
//   , serial_number_(serial_number)
// {
//   connected_ = false;
//   scanning_ = false;
//   fieldCount_ = 3;
//   container_buffer_.resize(container_size_);
//   //container_buffer.resize(SCANNER_RESOLUTION * container_size_ *2); // container is able to hold 64(defult container size) profile
//   path_to_device_properties_ = path_to_device_properties;
//   path_to_device_properties_ += "/device_properties.dat";
//   connect();
//   if (connected_)
//   {
//     if (!initialise())
//     {
//       disconnect();
//       return;
//     }
//     if (!setLaserPower(true))
//     {
//       disconnect();
//       return;
//     }
//   }
// }
// ---------------------------version 2------------------------
Scanner::Scanner ( Notifyee *notifyee, unsigned int shutter_time, unsigned int idle_time, 
                     std::string serial_number, std::string path_to_device_properties )
    : notifyee_ ( notifyee )
    , shutter_time_ ( shutter_time )
    , idle_time_ ( idle_time )
    , serial_number_ ( serial_number )
{
    connected_ = false;
    scanning_ = false;
    path_to_device_properties_ = path_to_device_properties + "/device_properties.dat";

    connect();
    if ( connected_ )
    {
      if ( !initialise() )
      {
        disconnect();
        return;
      }
      if ( !setLaserPower( true ) )
      {
        disconnect();
        return;
      }
    }
}
// --------------------version 3-----------------------------------------------------------
// Scanner::Scanner(TimeSync *time_sync, Notifyee *notifyee, unsigned int shutter_time, unsigned int idle_time,
//                  unsigned int container_size, std::string serial_number,
//                  std::string path_to_device_properties)
//   : time_sync_(time_sync)
//   , notifyee_(notifyee)
//   , shutter_time_(shutter_time)
//   , idle_time_(idle_time)
//   , container_size_(container_size)
//   , serial_number_(serial_number)
// {
//   connected_ = false;
//   scanning_ = false;
//   fieldCount_ = 3;
//   container_buffer_.resize(container_size_);
//   //container_buffer.resize(SCANNER_RESOLUTION * container_size_ *2); // container is able to hold 64(defult container size) profile
//   path_to_device_properties_ = path_to_device_properties;
//   path_to_device_properties_ += "/device_properties.dat";
//   connect();
//   if (connected_)
//   {
//     if (!initialise())
//     {
//       disconnect();
//       return;
//     }
//     if (!setLaserPower(true))
//     {
//       disconnect();
//       return;
//     }
//   }
// }


Scanner::~Scanner()
{
  if (connected_)
  {
    if (scanning_)
    {
      stopScanning();
    }
    setLaserPower(false);
    disconnect();
  }
}

bool Scanner::reconnect()
{
  if (connected_)
  {
    if (scanning_)
    {
      stopScanning();
    }
    setLaserPower(false);
    disconnect();
  }
  connect();
  if (connected_)
  {
    if (!initialise())
    {
      return false;
    }
    if (!setLaserPower(true))
    {
      disconnect();
      return false;
    }
  }
  else
  {
    return false;
  }
  return true;
}

bool Scanner::setLaserPower(bool on)
{
  guint32 value = on ? 0x82000002 : 0x82000000;

  if (llt_.SetFeature(FEATURE_FUNCTION_LASER, value) < GENERAL_FUNCTION_OK)
  {
    std::cout << "Error while setting trigger!\n";
    return false;
  }

  return true;
}

// // Write command for separate registers
// void Scanner::WriteCommand(unsigned int command, unsigned int data)
// {
//   static int toggle = 0;
//   //llt_.SetFeature(FEATURE_FUNCTION_SHARPNESS, (unsigned int)(command << 9) + (toggle << 8) + data); //deprecated
//   llt_.SetFeature(FEATURE_FUNCTION_EXTRA_PARAMETER, (unsigned int)(command << 9) + (toggle << 8) + data);
//   toggle = toggle ? 0 : 1;
// }

// // Write value on register position
// void Scanner::WriteValue2Register(unsigned short value)
// {
//   WriteCommand(1, (unsigned int)(value / 256));
//   WriteCommand(1, (unsigned int)(value % 256));
// }

// bool Scanner::setMeasuringField(ushort x_start, ushort x_size, ushort z_start, ushort z_size)
// {
//   // Activate free measuring field
//   // // llt_.SetFeature(FEATURE_FUNCTION_MEASURINGFIELD, 0x82000800);// this is deprecated
//   llt_.SetFeature(FEATURE_FUNCTION_ROI1_PRESET, MEASFIELD_ACTIVATE_FREE);
  
//   // Set the desired measuring field size

//   // WriteCommand(0, 0);  // reset command
//   // WriteCommand(0, 0);
//   // WriteCommand(2, 8);
//   // WriteValue2Register(z_start);
//   // WriteValue2Register(z_size);
//   // WriteValue2Register(x_start);
//   // WriteValue2Register(x_size);
//   // WriteCommand(0, 0);  // Finish writing


// // -----------------------------set measuring field from example -------------------------------------
//   // // set the desired free measuring field
//   //   ushort z_start = 20000;
//   //   ushort z_size = 25000;
//   //   ushort x_start = 20000;
//   //   ushort x_size = 25000;

//     int ret;
//     // measuring field - possibility 1

//     // write free measuring field settings to sensor
//     std::cout << "Write free measuring field:\n - Start z: " << z_start << "\n - Size z: " << z_size
//               << "\n - Start x: " << x_start << "\n - Size x: " << x_size << std::endl;
//     // enable the free measuring field
//     if ((ret = llt_.SetFeature(FEATURE_FUNCTION_MEASURINGFIELD, ROI1_FREE_REGION)) < GENERAL_FUNCTION_OK) {
//         std::cout << "Error during setting the free measuring field" << ret << std::endl;
//         return ret;
//     }
//     // set the values
//     if ((ret = llt_.SetFreeMeasuringField(z_start, z_size, x_start, x_size)) < GENERAL_FUNCTION_OK) {
//         std::cout << "Error during setting the free measuring field" << ret << std::endl;
//         return ret;
//     }

//     // // measuring field - possibility 2 --> reading parameters with GetFeature also possible
//     // // available since scanCONTROL firmware version v43

//     // // enable the free measuring field
//     if ((ret = llt_.SetFeature(FEATURE_FUNCTION_MEASURINGFIELD, ROI1_FREE_REGION)) < GENERAL_FUNCTION_OK) {
//         std::cout << "Error during setting the free measuring field" << ret << std::endl;
//         return ret;
//     }
//     // write start/size x
//     if ((ret = llt_.SetFeature(FEATURE_FUNCTION_ROI1_POSITION, (x_size << 16) + x_start)) < GENERAL_FUNCTION_OK) {
//         std::cout << "Error during setting the free measuring field" << ret << std::endl;
//         return ret;
//     }
//     // write start/size z
//     if ((ret = llt_.SetFeature(FEATURE_FUNCTION_ROI1_DISTANCE, (z_size << 16) + z_start)) < GENERAL_FUNCTION_OK) {
//         std::cout << "Error during setting the free measuring field" << ret << std::endl;
//         return ret;
//     }
//     // activate settings
//     if ((ret = llt_.SetFeature(FEATURE_FUNCTION_EXTRA_PARAMETER, 0)) < GENERAL_FUNCTION_OK) {
//         std::cout << "Error during setting the free measuring field" << ret << std::endl;
//         return ret;
//     }
//     //-----------------------------------------------------------------------
//     return GENERAL_FUNCTION_OK;
// }

}  // namespace microepsilon_scancontrol
