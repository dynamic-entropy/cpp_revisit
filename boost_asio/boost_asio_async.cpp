#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <chrono>
#include <iostream>

void my_coroutine(boost::asio::yield_context yield) {
  auto ctx = yield.get_executor();
  int time = 4;
  boost::asio::steady_timer t(ctx, boost::asio::chrono::seconds(time));
  t.async_wait([time](const boost::system::error_code &ec) {
    if (!ec) {
      std::cout << time << " Second Timer" << std::endl;
    } else {
      std::cout << "Error1: " << ec.message() << std::endl;
    }
  });
  boost::asio::steady_timer t2(ctx, boost::asio::chrono::seconds(2 * time));
  boost::system::error_code ec;  // Error code to capture any errors
  t2.async_wait(yield[ec]);
  if (!ec) {
    std::cout << 2 * time << " Second Timer" << std::endl;
  } else {
    std::cout << "Error2: " << ec.message() << std::endl;
  }
}

// void my_coroutine(boost::asio::yield_context yield) {
//   auto ctx = yield.get_executor();
//   int time = 7;
//   boost::asio::steady_timer t(ctx, boost::asio::chrono::seconds(time));
//   boost::system::error_code ec;  // Error code to capture any errors
//   t.async_wait(yield[ec]);
//   if (!ec) {
//     std::cout << time << " Second Timer" << std::endl;
//   } else {
//     std::cout << "Error: " << ec.message() << std::endl;
//   }
// }

int main() {
  boost::asio::io_context io;

  int time = 3;
  boost::asio::steady_timer t(io.get_executor(),
                              boost::asio::chrono::seconds(time));
  t.async_wait([time](const boost::system::error_code &ec) {
    if (!ec) {
      std::cout << time << " Second Timer" << std::endl;
    } else {
      std::cout << "Error: " << ec.message() << std::endl;
    }
  });

  boost::asio::spawn(io, my_coroutine);

  io.run();
  return 0;
}
