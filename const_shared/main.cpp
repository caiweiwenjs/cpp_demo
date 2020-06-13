#include <iostream>
#include <memory>


void func(std::shared_ptr<const int> p) {
  //*p = 100; //ERROR: cannot assign to return value because function 'operator*' returns a const value
}

int main() {
  std::shared_ptr<int> a = std::make_shared<int>(10);
  func(a);
  
  return 0;  
}
