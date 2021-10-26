// Author: Chen Lequn

#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>

#include <angles/angles.h>

#include <tinyxml.h>

#include <simtech_kuka_eki_interface_tcp/simtech_kuka_eki_interface_tcp.h>



namespace simtech_kuka_eki_interface_tcp
{

KukaEkiHardwareInterface::KukaEkiHardwareInterface() : joint_position_(n_dof_, 0.0), joint_velocity_(n_dof_, 0.0),
    joint_effort_(n_dof_, 0.0), joint_position_command_(n_dof_, 0.0), joint_names_(n_dof_), deadline_(ios_),command_parameters(max_parameter),
    // eki_server_endpoint_(boost::asio::ip::address::from_string("172.31.1.147"), 54601), 
    eki_client_socket_(ios_)
{

}


KukaEkiHardwareInterface::~KukaEkiHardwareInterface() {}


void KukaEkiHardwareInterface::eki_check_read_state_deadline()
{
  // Check if deadline has already passed
  if (deadline_.expires_at() <= boost::asio::deadline_timer::traits_type::now())
  {
    eki_client_socket_.cancel();
    deadline_.expires_at(boost::posix_time::pos_infin);
  }

  // Sleep until deadline exceeded
  deadline_.async_wait(boost::bind(&KukaEkiHardwareInterface::eki_check_read_state_deadline, this));
}


void KukaEkiHardwareInterface::eki_handle_receive(const boost::system::error_code &ec, size_t length,
                                                  boost::system::error_code* out_ec, size_t* out_length)
{
  *out_ec = ec;
  *out_length = length;
}


bool KukaEkiHardwareInterface::eki_read_state(std::vector<double> &joint_position, int &cmd_buff_len, int &routine)
{
  static boost::array<char, 4096> in_buffer;

  // Read socket buffer (with timeout)
  // Based off of Boost documentation example: doc/html/boost_asio/example/timeouts/blocking_udp_client.cpp
  deadline_.expires_from_now(boost::posix_time::seconds(eki_read_state_timeout_));  // set deadline
  boost::system::error_code ec = boost::asio::error::would_block;
  size_t len = 0;
  eki_client_socket_.async_receive(boost::asio::buffer(in_buffer),
                                   boost::bind(&KukaEkiHardwareInterface::eki_handle_receive, _1, _2, &ec, &len));
  do
    ios_.run_one();
  while (ec == boost::asio::error::would_block);
  if (ec)
    return false;

  // Update joint positions from XML packet (if received)
  if (len == 0)
    return false;

  // Parse XML
  TiXmlDocument xml_in;
  in_buffer[len] = '\0';  // null-terminate data buffer for parsing (expects c-string)
  xml_in.Parse(in_buffer.data());
  TiXmlElement* robot_state = xml_in.FirstChildElement("RobotState");
  if (!robot_state)
    return false;
  TiXmlElement* pos = robot_state->FirstChildElement("Pos");
  // TiXmlElement* vel = robot_state->FirstChildElement("Vel");
  // TiXmlElement* eff = robot_state->FirstChildElement("Eff");
  TiXmlElement* robot_command = robot_state->FirstChildElement("CommandServer");
  TiXmlElement* routine_command = robot_state->FirstChildElement("RoutineCommand");
  // if (!pos || !vel || !eff || !robot_command)
  if (!pos || !robot_command || !routine_command)
    return false;

  // Extract axis positions
  double joint_pos;  // [deg]
  // double joint_vel; // [%max]
  // double joint_eff; // [Nm]
  char axis_name[] = "A1";
  for (int i = 0; i < n_dof_; ++i)
  {
    pos->Attribute(axis_name, &joint_pos);
    joint_position[i] = angles::from_degrees(joint_pos);  // convert deg to rad
    // vel->Attribute(axis_name, &joint_vel);
    // joint_velocity[i] = joint_vel;
    // eff->Attribute(axis_name, &joint_eff);
    // joint_effort[i] = joint_eff;
    axis_name[1]++;
  }

  // Extract number of command elements buffered on robot
  robot_command->Attribute("Size", &cmd_buff_len);

  // Extract the routine command -- 0:idle, 1:scanning, 2:control, 3:json
  routine_command->Attribute("State", &routine);

  return true;
}




// bool KukaEkiHardwareInterface::send_command(const int &instruction_code, const std::vector<double> &command_parameters, 
//                                             const float &temperature)
bool KukaEkiHardwareInterface::send_command(const int &instruction_code, const std::vector<double> &command_parameters)
{
  TiXmlDocument xml_out;
  TiXmlElement* robot_command_server = new TiXmlElement("CommandServer");
  TiXmlElement* parameters = new TiXmlElement("Parameters");
  // TiXmlElement* temp = new TiXmlElement("Temp");
  TiXmlText* empty_text = new TiXmlText("");
  robot_command_server->LinkEndChild(parameters);
  // robot_command_server->LinkEndChild(temp);
  parameters->LinkEndChild(empty_text);  // force <parameters></parameters> format (vs <parameters />)
  char params[] = "P1";
  for (int i = 0; i < n_dof_; ++i)
  {
    // parameters->SetAttribute(params, std::to_string(angles::to_degrees(joint_position_command[i])).c_str());
    parameters->SetAttribute(params, std::to_string(command_parameters[i]).c_str());
    params[1]++;
  }
  robot_command_server->SetAttribute("InstructionCode", instruction_code);
  // temp->SetDoubleAttribute("Laser", temperature);
  xml_out.LinkEndChild(robot_command_server);

  TiXmlPrinter xml_printer;
  xml_printer.SetStreamPrinting();  // no linebreaks
  xml_out.Accept(&xml_printer);

  size_t len = eki_client_socket_.send(boost::asio::buffer(xml_printer.CStr(), xml_printer.Size()));

  return true;
}


void KukaEkiHardwareInterface::init()
{
  // Get controller joint names from parameter server
  if (!nh_.getParam("controller_joint_names", joint_names_))
  {
    ROS_ERROR("Cannot find required parameter 'controller_joint_names' on the parameter server.");
    throw std::runtime_error("Cannot find required parameter 'controller_joint_names' on the parameter server.");
  }

  // // Get EKI parameters from parameter server
  const std::string param_addr = "eki/robot_address";
  const std::string param_port = "eki/robot_port";
  const std::string param_socket_timeout = "eki/socket_timeout";
  const std::string param_max_cmd_buf_len = "eki/max_cmd_buf_len";

  if (nh_.getParam(param_addr, eki_server_address_) &&
      nh_.getParam(param_port, eki_server_port_))
  {
    ROS_INFO_STREAM_NAMED("simtech_kuka_eki_interface_tcp", "Configuring Kuka EKI hardware interface on: "
                          << eki_server_address_ << ", " << eki_server_port_);
  }
  else
  {
    std::string msg = "Failed to get EKI address/port from parameter server (looking for '" + param_addr +
                      "', '" + param_port + "')";
    ROS_ERROR_STREAM(msg);
    throw std::runtime_error(msg);
  }

  if (nh_.getParam(param_socket_timeout, eki_read_state_timeout_))
  {
    ROS_INFO_STREAM_NAMED("simtech_kuka_eki_interface_tcp", "Configuring Kuka EKI hardware interface socket timeout to "
                          << eki_read_state_timeout_ << " seconds");
  }
  else
  {
    ROS_INFO_STREAM_NAMED("simtech_kuka_eki_interface_tcp", "Failed to get EKI socket timeout from parameter server (looking "
                          "for '" + param_socket_timeout + "'), defaulting to " +
                          std::to_string(eki_read_state_timeout_)  + " seconds");
  }

  // if (nh_.getParam(param_max_cmd_buf_len, eki_max_cmd_buff_len_))
  // {
  //   ROS_INFO_STREAM_NAMED("simtech_kuka_eki_interface_tcp", "Configuring Kuka EKI hardware interface maximum command buffer "
  //                         "length to " << eki_max_cmd_buff_len_);
  // }
  // else
  // {
  //   ROS_INFO_STREAM_NAMED("simtech_kuka_eki_interface_tcp", "Failed to get EKI hardware interface maximum command buffer length "
  //                         "from parameter server (looking for '" + param_max_cmd_buf_len + "'), defaulting to " +
  //                         std::to_string(eki_max_cmd_buff_len_));
  // }
  
 
  // Create ros_control interfaces (joint state and position joint for all dof's)
  for (std::size_t i = 0; i < n_dof_; ++i)
  {
    // Joint state interface
    joint_state_interface_.registerHandle(
        hardware_interface::JointStateHandle(joint_names_[i], &joint_position_[i], &joint_velocity_[i],
                                             &joint_effort_[i]));

  }

  // Register interfaces
  registerInterface(&joint_state_interface_);
  
  ROS_INFO_STREAM_NAMED("simtech_kuka_eki_interface_tcp", "Loaded Kuka EKI hardware interface");
}



void KukaEkiHardwareInterface::start()
{
  ROS_INFO_NAMED("simtech_kuka_eki_interface_tcp", "Starting Kuka EKI hardware interface...");
  // Start client
  ROS_INFO_NAMED("simtech_kuka_eki_interface_tcp", "... connecting to robot's EKI server...");
 
  // --------------------------get correct ip address and port for tcp connection------------------------------------
  boost::system::error_code ec;
  robot_ip_address = boost::asio::ip::address::from_string(eki_server_address_, ec);

  if (ec.value() != 0) {
  // Provided IP address is invalid. Breaking execution.
    std::cout 
      << "Failed to parse the IP address. Error code = "
      << ec.value() << ". Message: " << ec.message();
    
    ROS_INFO_NAMED("simtech_kuka_eki_interface_tcp", "Invalid IP address");
  }

  robot_port = std::stoi( eki_server_port_ ); // convert from string to number
  // -----------------------------------establish tcp socket connection-------------------------------------
  // Construct an endpoint using a port number and an IP address
  eki_server_endpoint_ = boost::asio::ip::tcp::endpoint(robot_ip_address, robot_port);
  // create socket, without opening it
  eki_client_socket_ = boost::asio::ip::tcp::socket(ios_);
 
  // ------------------------------------------------------------------------------------------------------
  // wait for connection　
  eki_client_socket_.connect( eki_server_endpoint_);
  if (ec)
  {
    // An error occurred.
    std::string msg = "Failed to accept the socket";
    ROS_ERROR_STREAM(msg);
  }
  ROS_INFO_NAMED("simtech_kuka_eki_interface_tcp", "... socket connection accepted...");
  
  boost::array<char, 1> ini_buf = { 0 };
  eki_client_socket_.send(boost::asio::buffer(ini_buf));  // initiate contact to start server

  // Start persistent actor to check for eki_read_state timeouts
  // No deadline is required until the first socket operation is started. so set to positive infinity
  deadline_.expires_at(boost::posix_time::pos_infin);  // do nothing unit a read is invoked (deadline_ = +inf)
  eki_check_read_state_deadline();

  // Initialize joint_position_command_ from initial robot state (avoid bad (null) commands before controllers come up)
  // if (!eki_read_state(joint_position_, joint_velocity_, joint_effort_, eki_cmd_buff_len_))
  if (!eki_read_state(joint_position_, eki_cmd_buff_len_, routine_command_))
  {
    std::string msg = "Failed to read from robot EKI server within alloted time of "
                      + std::to_string(eki_read_state_timeout_) + " seconds.  Make sure eki_hw_interface is running "
                      "on the robot controller and all configurations are correct.";
    ROS_ERROR_STREAM(msg);
    throw std::runtime_error(msg);
  }
  joint_position_command_ = joint_position_;

  ROS_INFO_NAMED("simtech_kuka_eki_interface_tcp", "... done. EKI hardware interface started!");
}


void KukaEkiHardwareInterface::read(const ros::Time &time, const ros::Duration &period)
{
  // if (!eki_read_state(joint_position_, joint_velocity_, joint_effort_, eki_cmd_buff_len_))
  if (!eki_read_state(joint_position_, eki_cmd_buff_len_, routine_command_))
  {
    std::string msg = "Failed to read from robot EKI server within alloted time of "
                      + std::to_string(eki_read_state_timeout_) + " seconds.  Make sure eki_hw_interface is running "
                      "on the robot controller and all configurations are correct.";
    ROS_ERROR_STREAM(msg);
    throw std::runtime_error(msg);
  }
  // ROS_INFO_STREAM_NAMED("simtech_kuka_eki_interface_tcp", "Received message from hardware interface");
}


int KukaEkiHardwareInterface::read_routine_command()
{
  return this->routine_command_;
}

// void KukaEkiHardwareInterface::write(const ros::Time &time, const ros::Duration &period)
// {
//   // only write if max will not be exceeded
//   if (eki_cmd_buff_len_ < eki_max_cmd_buff_len_)
//     eki_write_command(joint_position_command_, temperature);

//   // underflow/overflow checking
//   // NOTE: this is commented as it results in a lot of logging output and the use of ROS_*
//   //       logging macros breaks incurs (quite) some overhead. Uncomment and rebuild this
//   //       if you'd like to use this anyway.
//   //if (eki_cmd_buff_len_ >= eki_max_cmd_buff_len_)
//   //  ROS_WARN_STREAM("eki_hw_iface RobotCommand buffer overflow (curent size " << eki_cmd_buff_len_
//   //                  << " greater than or equal max allowed " << eki_max_cmd_buff_len_ << ")");
//   //else if (eki_cmd_buff_len_ == 0)
//   //  ROS_WARN_STREAM("eki_hw_iface RobotCommand buffer empty");
// }



void KukaEkiHardwareInterface::writeTemp(const float temp)
{
   temperature = temp;
}


} // namespace simtech_kuka_eki_interface_tcp
