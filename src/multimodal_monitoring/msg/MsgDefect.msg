# Definition for a custom message to store predicted defect types
# Possible encoded categories: 0 (laser-off), 1 (defect-free), 2 (crack), 3 (keyhole pores)

Header header  # ROS header to include timestamp
int32 defect   # Encoded defect category
