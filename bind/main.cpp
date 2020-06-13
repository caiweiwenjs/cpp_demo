#include <iostream>
#include <functional>

template<class CB, class... ARGS>
void fn(CB cb, ARGS... args) {
  auto f = std::bind(cb, args...);  
  f();
}

void ff(int a) {
  std::cout << a << std::endl;  
}

int main() {
  fn(ff, 10);
  int b = 20;
  std::function<void(int)> f1 = [b](int a) {
    std::cout << a + b << std::endl;
  };
  fn(f1, 20);
  std::function<void(int)> f2 = nullptr;
  fn(f2?f2:[](int){}, 20);
  return 0;  
}
