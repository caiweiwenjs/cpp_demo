#include <iostream>
#include <string>

int main() {
  std::string a = "sdfds : sdfs : sdfsdf";
  std::string b = "sdfsdf";
  std::string c = "";
  std::cout << a.substr(a.find(":") + 1) << std::endl;
  std::cout << b.substr(b.find(":") + 1) << std::endl;
  std::cout << c.find(":") << std::endl;
  std::cout << b.find(":") << std::endl;
  //std::cout << c.substr(c.find(":") + 1) << std::endl;
  return 0;  
}
