#include <boost/asio.hpp>
#include <iostream>

int main()
{
    // The execution context is the programs link to the OS I/O services
    // The io_context performs the calls to the operating system on requested resources
    // Thus providing "access" to the I/O functionality
    boost::asio::io_context io;

    // The core asio classes provide specific I/O functionality
    // These rely on the io_context
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

    // Block for five seconds
    t.wait();
    std::cout << "Hello World!" << std::endl;

    // Timers have two states: Expired and Not-Expired
    // Calling wait on expired timer will return immediately
    t.wait();
    std::cout << "Calling wait on an expired timer!" << std::endl;

    return 0;
}