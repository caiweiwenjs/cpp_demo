#include <iostream>
#include <functional>

std::function<int()> func() {
  int a = 10;
  return [a]() mutable {
    a = a + 1;
    return a;  
  };
}

int main() {
  auto fn = func();
  auto fn2 = func();
  std::cout << fn() << std::endl;
  std::cout << fn() << std::endl;
  std::cout << fn() << std::endl;
  std::cout << fn2() << std::endl;
  return 0;  
}
