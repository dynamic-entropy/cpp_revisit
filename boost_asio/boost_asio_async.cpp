#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <chrono>
#include <iostream>

// void my_coroutine(boost::asio::yield_context yield) {
//   auto ctx = yield.get_executor();
//   boost::asio::steady_timer t(ctx, boost::asio::chrono::seconds(5));
//   t.async_wait([](const boost::system::error_code &ec) {
//     std::cout << "5 Second Timer" << std::endl;
//   });
// }

void my_coroutine(boost::asio::yield_context yield) {
  auto ctx = yield.get_executor();
  boost::asio::steady_timer t(ctx, boost::asio::chrono::seconds(5));
  boost::system::error_code ec;  // Error code to capture any errors
  t.async_wait(yield[ec]);
  if (!ec) {
    std::cout << "5 Second Timer" << std::endl;
  } else {
    std::cout << "Error: " << ec.message() << std::endl;
  }
}

int main() {
  boost::asio::io_context io;

  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
  t.async_wait([](const boost::system::error_code &ec) {
    std::cout << "5 Second Timer" << std::endl;
  });

  boost::asio::spawn(io, my_coroutine);

  io.run();
  return 0;
}
