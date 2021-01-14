## Change log
### 08 Jan 2021
* in the xml file: change UDP to TCP. (currently cannot, because PC client is using UDP (C++ boost asio library))
* Add the "defect checking" functionality in "EkiHwInterface.xml"
  --> corresponding to "Socket_routine" in abb
  - Specifically:
  ELEMENT Tag="RobotCommand/Status/@Defects" Type="BOOL" 

--> actually, we need to create a new xml file for new UDP/TCP socket commnunication. 

* test "joint trajectory control" command, find ways using it
* rosrun rqt_controller_manager rqt_controller_manager
* rosrun rqt_joint_trajectory_controller rqt_joint_trajectory_controller


* Where is the "DELCAM" program (the main function, with definition of laser on laser off etc.)
* ros control: publication: S. Chitta, E. Marder-Eppstein, W. Meeussen, V. Pradeep, A. Rodríguez Tsouroukdissian, J. Bohren, D. Coleman, B. Magyar, G. Raiola, M. Lüdtke and E. Fernandez Perdomo "ros_control: A generic and simple control framework for ROS" The Journal of Open Source Software, 2017
　－ https://vimeo.com/187696094
　－ https://vimeo.com/107507546
　－ https://roscon.ros.org/2014/wp-content/uploads/2014/07/ros_control_an_overview.pdf



#### Remaining Problems:
1. Motion command. How to transmit received motion command from sub program to src program and let it run the command. --> need to find a way to define globally shared variable. 
2. Motion command generation: currently, it is using the ros_control package (i.e., using ROS controller manager, joint trajectory controller, joint state contoller), can use rqt controller to manually move the individual joint. But how to acheive cartesian motion for the tcp?
3. for UDP, the socket works the same as TCP. Hopefully, the codes remain almost the same. But it seems using C++ boost library is a better and more reliable way to establish UDP/TCP communication.
4. Actually for laser server, and socket routine etc, we can just use TCP socket. try to use just python for testing.
5. check out the complete manual. look in detail about the ethernet settings.
6. look at __sys.sub__ program


## global varibales, functions, signals
1. Variables and signals defined in __**$CONFIG.DAT**__ (Variables, signals and user-defined data types) are global variable
2. using __global__ keyword in the declaration (only for functions, subprograms, interrupts)
3. __Data list (DAT file)__: insert __public__ keyword into the program header of a data list, then it becomes global
   Using keyword __global__ only for variables, signals, data
4.  __Constants__ must always be declared and, at the same time, initialized in a __data list (DAT file)__. 
5.  Data types defined using the keyword GLOBAL __must not__ be used in $CONFIG.DAT (causing conflicts, because in CONFIG.dat, it is already global)
   
* Signal declarations predefined in the system: $machine.DAT --> KRC:\STEU\MADA