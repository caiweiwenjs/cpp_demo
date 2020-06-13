#include <iostream>
#include <functional>
#include <vector>


void cps(int x, std::function<void(int)> callback) {
  if (callback) {
    callback(x + 1);
  }
}

int main() {

  cps(1, [](int x) {
      std::cout << "x = " << x << std::endl;
    });
  cps(1, nullptr);

  std::vector<int> vec = { 0};

  vec.erase(vec.begin() + 1, vec.end());

  for (auto i: vec) {
    std::cout << i << std::endl;
  }

  return 0;  
}
