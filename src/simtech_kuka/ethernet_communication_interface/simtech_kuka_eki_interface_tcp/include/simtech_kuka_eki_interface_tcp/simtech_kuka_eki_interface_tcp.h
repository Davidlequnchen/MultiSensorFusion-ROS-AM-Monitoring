// Author: Chen Lequn


#ifndef SIMTECH_KUKA_EKI_INTERFACE_TCP
#define SIMTECH_KUKA_EKI_INTERFACE_TCP

#include <vector>
#include <string>

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>


namespace simtech_kuka_eki_interface_tcp
{

class KukaEkiHardwareInterface : public hardware_interface::RobotHW
{
  typedef boost::shared_ptr<boost::asio::ip::tcp::socket> sock_ptr;
  typedef KukaEkiHardwareInterface this_type;
private:
  ros::NodeHandle nh_;

  const unsigned int n_dof_ = 6;
  std::vector<std::string> joint_names_;
  std::vector<double> joint_position_;
  std::vector<double> joint_velocity_;
  std::vector<double> joint_effort_;
  std::vector<double> joint_position_command_;
  std::vector<double> command_parameters; // the parameter list, e.g., X,Y,Z,A,B,C
  int instruction_code; // the unique instruction code
  int routine_command_; // the routine_command read from eki kuka controller server 
  const int max_parameter = 10;
  float temperature;

  // EKI
  unsigned short robot_port;
  boost::asio::ip::address robot_ip_address;
  std::string eki_server_address_;
  std::string eki_server_port_;
  int eki_cmd_buff_len_;
  int eki_max_cmd_buff_len_ = 5;  // by default, limit command buffer to 5 (size of advance run in KRL)

  // Timing
  ros::Duration control_period_;
  ros::Duration elapsed_time_;
  double loop_hz_;

  // Interfaces
  hardware_interface::JointStateInterface joint_state_interface_;


  // EKI socket read/write
  int eki_read_state_timeout_ = 10;  // [s]; settable by parameter (default = 5)
  boost::asio::io_service ios_;
  boost::asio::deadline_timer deadline_;
  boost::asio::ip::tcp::endpoint eki_server_endpoint_;
  boost::asio::ip::tcp::socket eki_client_socket_;
  void eki_check_read_state_deadline();
  static void eki_handle_receive(const boost::system::error_code &ec, size_t length,
                                 boost::system::error_code* out_ec, size_t* out_length);
  // bool eki_read_state(std::vector<double> &joint_position, std::vector<double> &joint_velocity,
  //                     std::vector<double> &joint_effort, int &cmd_buff_len);
    bool eki_read_state(std::vector<double> &joint_position, int &cmd_buff_len, int &routine);
  // bool eki_write_command(const std::vector<double> &joint_position, const float &temperature);
  

public:

  KukaEkiHardwareInterface();
  ~KukaEkiHardwareInterface();

  void init();
  void start();
  void read(const ros::Time &time, const ros::Duration &period);
  // void write(const ros::Time &time, const ros::Duration &period);
  void writeTemp(const float temp);
  // bool send_command(const int &instruction_code, const std::vector<double> &command_parameters, 
  //                   const float &temperature);
  bool send_command(const int &instruction_code, const std::vector<double> &command_parameters);
  int read_routine_command();

};

} // namespace simtech_kuka_eki_interface_tcp

#endif  // SIMTECH_KUKA_EKI_INTERFACE_TCP