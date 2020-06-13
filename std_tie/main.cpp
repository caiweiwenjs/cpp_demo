#include <iostream>
#include <tuple>

std::tuple<int, std::string, bool> func(int a, const std::string& b, bool c) {
  return std::make_tuple(a + 1, b + "abc", !c);
}

int main() {
  int a;
  std::string b;
  bool c;
  std::tie(a, b, c) = func(10, "sdf", false);
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;
  return 0;  
}
