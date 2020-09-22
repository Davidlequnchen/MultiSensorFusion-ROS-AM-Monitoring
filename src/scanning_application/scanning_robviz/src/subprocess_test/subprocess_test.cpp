#include <ctime>
#include <sstream>
#include <fstream>
#include <iostream> //std::cout
#include <string>  //std::string, std::to_string
#include <boost/filesystem.hpp>
#include "subprocess.hpp"

namespace sp = subprocess;
namespace fs =boost::filesystem;



// std::string path = ros::package::getPath("scanning_robviz");
std::string path = "/home/chenlequn/SIMTech_ws/src/scanning_application/scanning_robviz";


std::string distanceFile = path + "/defects_prediction/" + "distance_P2";
std::string pcdFile = path + "/defects_prediction/" + "P2_seg.pcd";
             
                    
void subprocess_test()
{
    // --------------subprocess for defects prediction---------------------------------
    std::string prediction_python_exe = path + "/defects_prediction/Plane_defect_machine_learning.py";
    std::string DecisionTree_Model_file = path + "/config/KNN.pkl";

    std::string prediction_exe = "python " + prediction_python_exe + " " + pcdFile + " " + distanceFile + " " + DecisionTree_Model_file;
    // auto predict = sp::Popen({prediction_exe}, output{PIPE});
    auto predict = sp::Popen({"python", prediction_python_exe, pcdFile,distanceFile, DecisionTree_Model_file}, output{"cat_fredirect.txt"});
    auto obuf = predict.communicate().first;
    std::cout << "Data : " << obuf.buf.data() << std::endl;
    std::cout << "Data len: " << obuf.length << std::endl;
    // return obuf.buf.data();
    // auto p = Popen({"ls", "-l"}, output{PIPE});
    // auto obuf = p.communicate().first;
    // std::cout << "Data : " << obuf.buf.data() << std::endl;
    // std::cout << "Data len: " << obuf.length << std::endl;
    // --------------------------------------------------------------------------------
}                    
    
    
                    
                    


int main (int argc, char** argv) {
  subprocess_test();
}