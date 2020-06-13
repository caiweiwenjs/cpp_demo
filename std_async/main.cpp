#include <iostream>
#include <future>
#include <thread>

int main() {
  std::cout << "main thread id = " << std::this_thread::get_id() << std::endl;
  std::future<std::thread::id> f = std::async(/* std::launch::async | std::launch::deferred, */[]() { 
      return std::this_thread::get_id();
  });
  std::cout << f.get() << std::endl;
  // run at different threads
  std::future<std::thread::id> f2 = std::async(std::launch::async, []() { 
      return std::this_thread::get_id();
  });
  std::cout << f2.get() << std::endl;
  // run at this thread
  std::future<std::thread::id> f3 = std::async(std::launch::deferred, []() {
        return std::this_thread::get_id(); 
  });
  std::cout << f3.get() << std::endl;

  return 0;  
}
