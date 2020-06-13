#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void func(std::promise<int> p) {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  p.set_value(10);
}

int main() {
  std::promise<int> p;
  std::future<int> f = p.get_future();
  std::thread t(func, std::move(p));
  t.detach();
  std::cout << f.get() << std::endl;

  return 0;  
}
