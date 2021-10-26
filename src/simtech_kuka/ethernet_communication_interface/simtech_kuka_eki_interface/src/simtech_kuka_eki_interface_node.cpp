#include <chrono>

#include <simtech_kuka_eki_interface/simtech_kuka_eki_interface.h>
#include <std_msgs/Float64.h>
#include <simtech_kuka_eki_interface/SrvRobotCommand.h>
#include <auto_control/MsgCommand.h>


#include "json.hpp"


using json = nlohmann::json;  // json namespace



class NdKukaRobotInterface {
    private:
        // ros objects declaration
        ros::NodeHandle nh;
        ros::ServiceServer service_command;
        ros::Subscriber sub_temperature;
        ros::Publisher pub_routine_command;

        // varibales
        // Set up timers
        ros::Time timestamp;
        ros::Duration period;
        std::chrono::time_point<std::chrono::steady_clock> stopwatch_last = std::chrono::steady_clock::now();
        std::chrono::time_point<std::chrono::steady_clock> stopwatch_now = stopwatch_last;
        float temperature;



    public:
        // declare hardwre interface object
        simtech_kuka_eki_interface::KukaEkiHardwareInterface hardware_interface;

        // declare a pointer for controller manager
        controller_manager::ControllerManager* controller_manager;
        

        // Class constructor
        NdKukaRobotInterface(){
            // create ROS service server "robot_send_command", with call back function
            // listen to the jason command to be loaded from Qt, and process the command by call back function 'cb_robot_command'.
            // the ROS service client is qt_path, which waits for server service creation
            service_command = nh.advertiseService("robot_send_command", &NdKukaRobotInterface::cb_robot_command, this);
            // ROS subscriber
            sub_temperature = nh.subscribe("/temperature", 10, &NdKukaRobotInterface::tempCallBack, this);
            // ROS pubisher
            pub_routine_command = nh.advertise<auto_control::MsgCommand>("/routine_command", 10);

            // initialize hardwareinterface, register interface handler to be used by controller manager
            // must do this before controller_manager object construction
            hardware_interface.init();

            controller_manager = new controller_manager::ControllerManager(&hardware_interface, nh);

            // start udp socket connection
            hardware_interface.start();

            // Get current time and elapsed time since last read
            timestamp = ros::Time::now();
            stopwatch_now = std::chrono::steady_clock::now();
            period.fromSec(std::chrono::duration_cast<std::chrono::duration<double>>(stopwatch_now - stopwatch_last).count());
            stopwatch_last = stopwatch_now;
        }

        //destructor
        ~NdKukaRobotInterface() {}

        

        int process_command (json &command)
        {
          // iterating member objects from json command
          for (json::iterator it = command.begin(); it != command.end(); ++it)
          { 
            int instruction_code;
            std::vector<double> command_parameters;

            std::cout << "command instruction is: " << it.key() << "\n";
            std::cout << "command parameters are: " << it.value() << "\n";
            
            // check the instruction type
            if (it.key() == "move_xyz")
            {
                // for linear motion command with only xyz coordinate, the instruction code is 1
                instruction_code = 1;
                // convert json object into std::vector, now should be {X,Y,Z}
                command_parameters = it.value().get<std::vector<double>>();
                // check command
                std::cout << "check the command parameter X: " << command_parameters[0] << "\n";
            }
            else if (it.key() == "move_frame")
            {
              // for linear move with full frame: X,Y,Z,A,B，C defined (6 parameters)
              instruction_code = 2;
              // convert json object into std::vector, now should be {X,Y,Z,A,B,C}
              command_parameters = it.value().get<std::vector<double>>();
              // check command
              std::cout << "check the command parameter A: " << command_parameters[3] << "\n";
            }
            else if (it.key() == "motion_complete")
            {
              // indicate if the json command is completed (send from Qt Gui)
              instruction_code = 3;
              // convert json object into std::vector, now should be 0.0 (not complete)/ 1.0 (complete)
              command_parameters = it.value().get<std::vector<double>>();
              // check command
              std::cout << "check the command json complete: " << command_parameters[0] << "\n";
            }
            else if (it.key() == "velocity_linear")
            {
              // set linear velocity
              instruction_code = 4;
              // convert json object into std::vector, now should be (linear speed) m/s (default 0.03)
              command_parameters = it.value().get<std::vector<double>>();
              // check command
              std::cout << "check the command velocity linear: " << command_parameters[0] << "\n";
            }
            else if (it.key() == "velocity_swivel")
            {
              // set swivel velocity (ORT1)
              instruction_code = 5;
              // convert json object into std::vector, now should be (swivel speed) deg/s (default 300)
              command_parameters = it.value().get<std::vector<double>>();
              // check command
              std::cout << "check the command velocity swivel (ORT1): " << command_parameters[0] << "\n";
            }
            else if (it.key() == "velocity_rotation")
            {
              // set rotation velocity ORT2
              instruction_code = 6;
              // convert json object into std::vector, now should be (rotation speed) deg/s (default 300)
              command_parameters = it.value().get<std::vector<double>>();
              // check command
              std::cout << "check the command velocity rotation (ORT2): " << command_parameters[0] << "\n";
            }
            else if (it.key() == "laser_ready")
            {
              // convert json object into std::vector, now should be 0/1
              command_parameters = it.value().get<std::vector<double>>();
              // check command
              std::cout << "check the command laser ready: " << command_parameters[0] << "\n";
              if (command_parameters[0] == 0)
              {
                instruction_code = 7; // laser off
              }
              else{
                instruction_code = 8; // laser on
              }
            }
            else if (it.key() == "laser_emission")
            {
              // convert json object into std::vector, now should be 0/1
              command_parameters = it.value().get<std::vector<double>>();
              // check command
              std::cout << "check the command laser emission: " << command_parameters[0] << "\n";
              if (command_parameters[0] == 0)
              {
                instruction_code = 9; // laser end
              }
              else{
                instruction_code = 10; // laser start
              }
            }
            else if (it.key() == "set_laser_power")
            {
              // set the laser power analog voltage
              instruction_code = 11;
              // convert json object into std::vector, now should be around 0.1 (according to the table)
              command_parameters = it.value().get<std::vector<double>>();
              // check command
              std::cout << "check the command set laser power: " << command_parameters[0] << "\n";
            }
            else if (it.key() == "tool")
            {
              // set the laser power analog voltage
              instruction_code = 12;
              // convert json object into std::vector, 1/2/3.... --> $TOOL=TOOL_DATA[1] ; "LASER"
              command_parameters = it.value().get<std::vector<double>>();
              // check command
              std::cout << "check the command set tool: " << command_parameters[0] << "\n";
            }
            else if (it.key() == "workobject")
            {
              // set the laser power analog voltage
              instruction_code = 13;
              // convert json object into std::vector, $BASE={X 1250.29, Y -1480.35, Z 1247.41, A 90, B 0, C 0}  ; user-defined BASE frame
              command_parameters = it.value().get<std::vector<double>>();
              // check command
              std::cout << "check the command set workobject X value: " << command_parameters[0] << "\n";
            }
            else if (it.key() == "wait")
            {
              // wait time seconds
              instruction_code = 14;
              // convert json object into std::vector
              command_parameters = it.value().get<std::vector<double>>();
              // check command
              std::cout << "check the command wait value: " << command_parameters[0] << "\n";
            }
            else if (it.key() == "transmission_complete")
            {
              // wait time seconds
              instruction_code = 15;
              // convert json object into std::vector
              command_parameters = it.value().get<std::vector<double>>();
              // check command
              std::cout << "check the command transmission_complete value: " << command_parameters[0] << "\n";
            }
            else{
              std::cout << "Invalid command, check the json again \n";
            }

            // return hardware_interface.send_command(instruction_code, command_parameters, temperature);
            return hardware_interface.send_command(instruction_code, command_parameters);
          }
        }


        void tempCallBack(const std_msgs::Float64 &temp)
        {
          this->temperature = temp.data;
          // this->robot_state_refresh();
        }


        bool cb_robot_command(simtech_kuka_eki_interface::SrvRobotCommand::Request  &req,
                              simtech_kuka_eki_interface::SrvRobotCommand::Response &res)
        {
            try{
                //create a json object, based on the nlomann json library "json.hpp" (from githubd)
                json command;
                int response;

                // ROS_INFO("JSON Command received %s", req.command);
                // "move"
                // parse command string to json structure
                command = json::parse(req.command); 
                std::cout << "command by json format is: " << command << std::endl;;
                // if (command.find("get_pose") != command.end()) {
                //   pose_rob = self.process_command(command)
                //   res.response = "OK";
                // }
                // processing the received json command
                response = NdKukaRobotInterface::process_command(command); 
                // issue a feedback message to the ROS service client
                res.response = "OK";
            } catch (...){
                res.response = "NOK";
            }

            // ros::Duration().sleep();

            return true;
        }

        void robot_state_refresh()
        {
          // Receive current state from robot
          hardware_interface.read(timestamp, period);

          // read routine command send from EKI server
          auto_control::MsgCommand routine;
          int command_received = hardware_interface.read_routine_command();
          routine.command = float(command_received);
          pub_routine_command.publish(routine);

          // Get current time and elapsed time since last read
          timestamp = ros::Time::now();
          stopwatch_now = std::chrono::steady_clock::now();
          period.fromSec(std::chrono::duration_cast<std::chrono::duration<double>>(stopwatch_now - stopwatch_last).count());
          stopwatch_last = stopwatch_now;

          // Update the controllers (not used by simtech program)
          controller_manager->update(timestamp, period);

          // Send new setpoint to robot (not used by simtech program)
          hardware_interface.writeTemp(temperature);
          hardware_interface.send_thermocouple_temperature_command (temperature);
          // hardware_interface.write(timestamp, period);
        }

};



int main(int argc, char** argv)
{
  ros::init(argc, argv, "simtech_kuka_eki_interface");

  NdKukaRobotInterface nd_kuka_robot_interface;

  //Sets the loop to publish at a rate of 90Hz
  // ros::Rate rate(100);

  ros::AsyncSpinner spinner(6);
  spinner.start();

  // ros::MultiThreadedSpinner spinner(8); // 8 = 4 per controller
  // spinner.spin();


  while (ros::ok())
  {
    nd_kuka_robot_interface.robot_state_refresh();
    //Delays until it is time to send another message
    // ros::spinOnce();
    // rate.sleep();
  }
  
  // ros::spin();

  spinner.stop();
  ROS_INFO_STREAM_NAMED("simtech_kuka_eki_interface", "Shutting down.");

  return 0;

}