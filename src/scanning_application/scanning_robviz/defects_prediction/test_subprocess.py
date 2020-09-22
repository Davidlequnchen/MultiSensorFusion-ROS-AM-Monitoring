import subprocess





process = subprocess.Popen(['python', 'Plane_defect_machine_learning.py', 'P2_seg.pcd', 'distance_P2.txt', '/home/chenlequn/SIMTech_ws/src/scanning_application/scanning_robviz/config/KNN.pkl'], stdout=subprocess.PIPE)

stdout = process.communicate()[0]

# print ('STDOUT:{}'.format(stdout))


print(stdout)
    
