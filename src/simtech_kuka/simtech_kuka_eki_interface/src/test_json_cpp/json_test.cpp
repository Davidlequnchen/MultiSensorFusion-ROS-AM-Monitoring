#include <iostream>
#include <thread>
#include <vector>
#include <algorithm> 
#include <fstream>
#include <string>
#include <typeinfo>
#include <iomanip>
#include <numeric>
#include <chrono>

#include "json.hpp"
using json = nlohmann::json;

// --------------
// -----Main-----
// --------------
int main (int argc, char** argv)
{
    /*
    // create an empty structure (null)
    json j;

    // add a number that is stored as double (note the implicit conversion of j to an object)
    j["pi"] = 3.141;

    // add a Boolean that is stored as bool
    j["happy"] = true;

    // add a string that is stored as std::string
    j["name"] = "Niels";

    // add another null object by passing nullptr
    j["nothing"] = nullptr;

    // add an object inside the object
    j["answer"]["everything"] = 42;

    // add an array that is stored as std::vector (using an initializer list)
    j["list"] = { 1, 0, 2 };

    // add another object (using an initializer list of pairs)
    j["object"] = { {"currency", "USD"}, {"value", 42.99} };

    // instead, you could also write (which looks very similar to the JSON above)
    json j2 = {
    {"pi", 3.141},
    {"happy", true},
    {"name", "Niels"},
    {"nothing", nullptr},
    {"answer", {
        {"everything", 42}
    }},
    {"list", {1, 0, 2}},
    {"object", {
        {"currency", "USD"},
        {"value", 42.99}
    }}
    };

    std::cout << "Test1: Create simple json objects \n";
    std::cout << "json1 is " << j << std::endl;;
    std::cout << "json2 is " << j2 << std::endl;;
    */

    json motion_command_1 = {"move", {10.0, 0.0, 0.0, 180.0, 0.0, 180}} ; // json format
    std::string motion_command_1_str = "{\"move\":[0.0, 0.0, 10.0, 180.0, 0.0, 180]}"; // a raw string, just like received from ROS service
    // std::string laser_on_off = "{\"laser_start\"}";
    
    std::cout << "motion_command_1 by json format is " << motion_command_1 << std::endl;;
    std::cout << "JSON Command received in string1 " << motion_command_1_str << std::endl;;
    

    json command = json::parse(motion_command_1_str); // get command as json structure
    std::cout << "string command 2 converted to json " << command << std::endl;;

    // for (json::iterator it = command.begin(); it != command.end(); ++it) {
    //     std::cout << "iterate command element " << *it << '\n';
    //     std::cout << "print out command values " <<it.value() << '\n';
    // }


    // ----------------------------------------------------------------------------------------------------------
    //----------------------------------------example of json & std::vector type conversion-----------------
    std::vector<double> c_vector {1, 2, 3, 4};                                           //create a vector
    json j_vec(c_vector);                                                                // convert to json 
    std::cout << "j vector " << j_vec << '\n';
    auto f_converted = j_vec.get<std::vector<double>>();                                  // json convert to std::vector
    std::cout << "j vector converted: " << f_converted[1] << '\n';
    std::cout << "j vector converted to type: " << typeid(f_converted).name() << '\n';
    // ----------------------------------------------------------------------------------------------------------

    // // range-based for
    // for (auto& element : command) {
    //     std::cout << "range-based for loop" << element << '\n';
    // }
    // find an entry
    // if (o.contains("foo")) {
    // // there is an entry with key "foo"
    // }

    // // or via find and an iterator
    // if (o.find("foo") != o.end()) {
    // // there is an entry with key "foo"
    // }

    // special iterator member functions for objects
    for (json::iterator it = command.begin(); it != command.end(); ++it) {
        std::cout << "command instruction is: " << it.key() << "\n";
        std::cout << "command parameters are: " << it.value() << "\n";

        // std::string instruction = command.get<std::string>();
        std::string instruction = it.key();
        std::cout << "string instruction: " << instruction << "\n";
        int instruction_code;
        std::vector<double> command_parameters;

        if (instruction == "move")
        {
            instruction_code = 1;
            auto f_converted = it.value().get<std::vector<double>>();
            std::cout << "parameter type is " << typeid(it.value()).name() << std::endl;
            std::cout << "parameter converted type becomes " << typeid(f_converted).name() << std::endl;
            command_parameters = it.value().get<std::vector<double>>();
            std::cout << "command parameters stored in vector are: " << command_parameters[3] << "\n";

 
        }

    }

    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
    std::cout << "data type of chrono clock " << typeid(start).name() << "\n";



    return 0;
}