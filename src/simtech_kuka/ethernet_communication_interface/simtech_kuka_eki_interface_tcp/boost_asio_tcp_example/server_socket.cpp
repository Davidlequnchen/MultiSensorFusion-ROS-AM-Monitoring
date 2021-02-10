/* An example of tcp/ip socket programming by C++ boost asio library
- The server socket program 
- the server specifies an address for client at which it makes a request to server.
- Server listens for the new connection and responds accordingly.
Adapted from: https://www.codeproject.com/Articles/1264257/Socket-Programming-in-Cplusplus-using-boost-asio-T
*/


// ------ import required libraries ---------------
#include <iostream>
#include <boost/asio.hpp>


// Server socket: receive message from client and then respond back. 
// Function for read data from client
// return: the received data in string
std::string read_(boost::asio::ip::tcp::socket & socket) 
{
    boost::asio::streambuf buf;
    boost::asio::read_until( socket, buf, "\n" );
    std::string data = boost::asio::buffer_cast<const char*>(buf.data());
    return data;
}

// Function to send data to client
void send_(boost::asio::ip::tcp::socket & socket, const std::string& message) 
{
    const std::string msg = message + "\n";
    boost::asio::write( socket, boost::asio::buffer(message) );
}


int main() 
{
    // oo_service object is mandatory whenever a program is using asio  
    boost::asio::io_service io_service;
    // decalare port
    int port = 1234;

    // listen for new connection
    // end point of connection being initialised to ipv4 and port 1234 
    boost::asio::ip::tcp::acceptor acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));

    //socket creation 
    boost::asio::ip::tcp::socket socket_(io_service);
    
    //waiting for connection
    acceptor_.accept(socket_);
    
    //read operation
    std::string message = read_(socket_);
    std::cout << message << std::endl;
    
    //write operation
    send_(socket_, "Hello From Server!");
    std::cout << "Server sent Hello message to Client!" << std::endl;
    
    return 0;
}