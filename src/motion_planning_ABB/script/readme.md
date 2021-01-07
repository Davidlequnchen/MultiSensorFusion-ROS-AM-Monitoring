# Json motion planning 

# json_path_planning.py
- an independent ROS node
- subscribe the topic : "defects" (for now, just defaut true, (have defects))
- If is defects, run the path planning algorithm (Xu Peng's part) -- auto generate the json file -- could be a subprocess
- after that, automatically run the json command 