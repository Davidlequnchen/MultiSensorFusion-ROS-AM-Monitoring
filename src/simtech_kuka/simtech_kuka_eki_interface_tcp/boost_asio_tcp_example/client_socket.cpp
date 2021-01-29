/* An example of tcp/ip socket programming by C++ boost asio library
- The client socket program 
- the client specifies an address for client at which it makes a request to server.
- a client that requests server.
Adapted from: https://www.codeproject.com/Articles/1264257/Socket-Programming-in-Cplusplus-using-boost-asio-T
*/

#include <iostream>
#include <boost/asio.hpp>


// define the ip address and port
std::string ip_ = "127.0.0.1"; // the local address of PC
int port_ = 1234;

// main function
int main() 
{
    // io_service is mandatory
    boost::asio::io_service io_service;
    //socket creation
    boost::asio::ip::tcp::socket socket_client(io_service);
    //client should establish the connection. Need to specify: ip and port
    socket_client.connect( boost::asio::ip::tcp::endpoint( boost::asio::ip::address::from_string(ip_), port_ ));
    
    // request/message from client
    const std::string msg = "Hello from Client!\n";
    boost::system::error_code error;
    // function for sending message
    boost::asio::write( socket_client, boost::asio::buffer(msg), error );
    if( !error ) {
        std::cout << "Client sent hello message!" << std::endl;
    }
    else {
        std::cout << "send failed: " << error.message() << std::endl;
    }
    
    // getting response from server
    boost::asio::streambuf receive_buffer;
    // function for read message
    boost::asio::read(socket_client, receive_buffer, boost::asio::transfer_all(), error);
    if( error && error != boost::asio::error::eof ) {
        std::cout << "receive failed: " << error.message() << std::endl;
    }
    else {
        const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
        std::cout << data << std::endl;
    }
    return 0;
}