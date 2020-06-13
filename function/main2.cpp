#include <iostream>
#include <functional>


void fn(std::function<void()> cb) {
  if (cb) {
    std::cout << "cb() == true" << std::endl;  
  } else {
    std::cout << "cb() == false" << std::endl;  
  }
  if (cb == nullptr) {
    std::cout << "cb == nullptr" << std::endl;  
  } else {
    std::cout << "cb != nullptr" << std::endl;  
  }
  try {
    cb();   
  } catch (const std::bad_function_call& e) {
     std::cout << e.what() << std::endl;
  }
}

int main() {
  fn(nullptr);
  std::cout << "=====================" << std::endl;
  fn(0);
  std::cout << "=====================" << std::endl;
  //fn(false); // compile error
  //fn(true); // compile error
  fn([]() {
      return;
  });
  return 0;  
}
