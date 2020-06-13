#include <iostream>
#include <string>
#include <memory>
#include <vector>



std::shared_ptr<std::vector<int>> func() {
  auto a = std::make_shared<std::vector<int>>();
  a->push_back(10);
  a->push_back(10);
  return a;
}


int main() {
  // wrong
  for (auto i: *func()) {
    std::cout << i << std::endl;  
  }
  std::cout << "=============" << std::endl;
  auto a = func();
  for (auto i: *a) {
    std::cout << i << std::endl;  
  }
  return 0;  
}
