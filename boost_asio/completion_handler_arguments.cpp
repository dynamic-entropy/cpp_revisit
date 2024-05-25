#include <boost/asio.hpp>
#include <functional>
#include <iostream>

//

void print(const boost::system::error_code &ec, const std::chrono::steady_clock::time_point *start,
           boost::asio::steady_timer *t, int *count)
{
    auto now = std::chrono::steady_clock::now();
    std::cout << "Print start: " << *count << " : "
              << std::chrono::duration_cast<std::chrono::seconds>(now - *start).count() << std::endl;
    if (*count < 5)
    {
        std::cout << *count << std::endl;
        (*count)++;
        t->expires_at(t->expires_at() + boost::asio::chrono::seconds(5 - *count));
        t->async_wait(std::bind(print, boost::asio::placeholders::error, start, t, count));
    }
    now = std::chrono::steady_clock::now();
    std::cout << "Print end: " << *count - 1 << " : "
              << std::chrono::duration_cast<std::chrono::seconds>(now - *start).count() << std::endl
              << std::endl;
}

int main()
{
    boost::asio::io_context io;
    int count = 1;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));

    auto start = std::chrono::steady_clock::now();
    t.async_wait(std::bind(print, boost::asio::placeholders::error, &start, &t, &count));

    io.run();

    std::cout << "Final count is: " << count << std::endl;
}