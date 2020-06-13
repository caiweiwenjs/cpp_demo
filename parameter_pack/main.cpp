#include <iostream>
#include <functional>

template<class CALLABLE, class... ARGS>
void func(CALLABLE cb, ARGS&&... args) {
  cb(std::forward<ARGS>(args)...);
}

void func2(std::function<bool()> fn) {
  fn();  
}

int main() {
  func([](int a) {
      std::cout << a << std::endl; 
      }, 10);
  func([](int a, int b) {
      std::cout << a + b << std::endl; 
      }, 10, 20);
  func([](int&& a, int b) {
      std::cout << a + b << std::endl; 
      }, 10, 20);
//  func2([](){;});
  func2([]() -> bool{ return false;});
 // func2([](bool a){;});
  return 0;  
}
