* this folder ("defect_id") is equivalent to "Socket_routine" for ABB
* It receive command send from PC ROS. the command specify whether surface defect occurs or not.
  - **True** --> stop the robot, and performs defects correction algorithm, start the reparing tool path, then go back to original routine   
  - **Flase** no defects --> go back to original deposition tool path
