# Methodology: integrate __SERVER_motion.mod__ into the common printing job

# Explanation:
## 1. SERVER_motion.mod
- This part is adpoted from OpenLMD with some minor modifications. This program should be used inside the robot motion task (i.e., TROB1). The functionality of this program is: to issue specific motion command to the robot (e.g, MOVL). Other commands such as MOVJ or move external axis are also available to use.
- This program must be used together with the __SERVER_command.md__ (inside the simtech abb package), which is a socket (a semistatic background task) listening to the PC client. The PC issues command in JSON file format, and the __SERVER_command.md__ do some processings and converting them for the usage of __SERVER_motion.md__. 
- The __SERVER_motion.mod__ previously was the only program used for motion planning. Now considering we need to do motion planning during the process (i.e., print some layers -> if defects found, generate new new path, --> then after finishing the new path, go back to the normal printing routine again), the __SERVER_motion.mod__ is now only a ___function___ to be inserted/called inside the Common printing routine program (E.g., a20x40_wo_profile.mod)

## 2. Common printing routine (E.g., a20x40_wo_profile.mod)
- This is the main prorgam of the DED process. The interrupt routine method is already explanied in __AutoDED__ package. (i.e., set up interrupt for point cloud scanning during the process and go back to print again.)





## 3. Integration/How to use SERVER_motion inside the main program (E.g., a20x40_profile_planning.mod)
- After the point cloud scanning has completed, the PC will process the point cloud and output the defects identificaiton results. If there exist defects, PC program will then generate tool path to fix the defects. 

### 3.1 New variables added:
- PERS bool is_defect := FALSE;
  - __is_defect__ is used in a20x40_wo_profile.mod to trigger the function __SERVER_motion()__ when is true
  - it is ___set___ in Socket_routine.mod, which is a tcp socket, value is got from PC side.

- PERS bool path_finished :=FALSE;
  - path_finished variable is to indicate whether the generated JSON command path is finished
 while path_fihished is false, the SERVER_motion will stay in the while loop to waiting for the new motion command to execute
 - path_finished should be set by SERVER_command.mod, which is a signal issued from the PC 
indicate the start and end of the execution of path



# Experiment on Sep 12-13
- The stand alone SERVER_motion.mod with SERVER_command.mod + JSON command python. -- To verify the capability of JSON path command 
- Store the point cloud data into one pcd file (from the start of scanning to the end of scanning -- the whole surface)
- Test the new prorgam on combination of Main printing path with JSON planned routine.