#include <boost/asio.hpp>
#include <boost/version.hpp>
#include <chrono>
#include <iostream>
#include <thread>

// Completion Tokens
// A function object that is provided by user to the initiating function of the
// asynchronous operation Completion token types:
// https://www.boost.org/doc/libs/1_85_0/doc/html/boost_asio/overview/model/completion_tokens.html
// 1. Function object (eg. Lambda Function):
// - operation begins immediately, result is passed to the lambda
// 2. use_future :
// https://www.boost.org/doc/libs/1_85_0/doc/html/boost_asio/reference/use_future_t.html
// - operation begins immeditely and a future object is returned; this can be
// used to await the result
// 3. use_awaitable:
// https://www.boost.org/doc/libs/1_85_0/doc/html/boost_asio/reference/use_awaitable_t.html
// - operation does not begin immediately, it is launched when the operation is
// co_awaited on the returned awaitable
// 4. yield_context:
// https://www.boost.org/doc/libs/1_85_0/doc/html/boost_asio/reference/yield_context.html
// - operation begins immediately withing the same context of this stackful
// coroutine

// print is a completion handler that is invoked by io.run() when the async task
// completes
void print5(const boost::system::error_code &ec) {
  std::cout << "Hello World! - 5 second timer" << std::endl;
}

void print3(const boost::system::error_code &ec) {
  std::cout << "Hello World! - 3 second timer" << std::endl;
}

int main() {
  std::cout << "Using Boost " << BOOST_VERSION / 100000 << "."  // major version
            << BOOST_VERSION / 100 % 1000 << "."                // minor version
            << BOOST_VERSION % 100                              // patch level
            << std::endl;

  boost::asio::io_context io;
  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
  boost::asio::steady_timer t2(io);
  t2.expires_after(std::chrono::seconds(3));

  auto start = std::chrono::steady_clock::now();
  // Initiate an async task that takes 5 seconds to complete
  t.async_wait(&print5);

  // Inititate another async task that takes 3 seconds to finish
  t2.async_wait(&print3);

  // Perform work that takes 3 seconds to finish
  // std::this_thread::sleep_for(std::chrono::seconds{3});
  // If this sleep is < 5 seconds: io.run() blocks for the remaining duration
  // If this sleep is >=5 seconds: io.run() returns immediately as the work
  // assigned to io context is finished by this time; this work was initiated
  // with t.async_await

  std::cout << "Before io.run()" << std::endl;
  auto before_run = std::chrono::steady_clock::now();
  std::cout << "Time before run: " << (before_run - start).count() << std::endl;
  io.run();
  std::cout << "After io.run()" << std::endl;
  auto after_run = std::chrono::steady_clock::now();
  std::cout << "Time after run: " << (after_run - start).count() << std::endl;

  return 0;
}
