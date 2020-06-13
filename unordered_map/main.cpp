#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>



int main() {
  std::unordered_map<std::string, std::vector<std::string>> mp;
  mp.insert({"abc", {"123"}});
  mp.insert({"abc1", {"1sdf", "dd"}});
  //mp.insert({"abc", {"1234", "233"}});
  mp["abc"] = {"1234", "233"};

  for (const auto& item: mp) {
    std::cout << "---" << item.first  << "-->" << std::endl;
    for (const auto& i:item.second) {
      std::cout << i << std::endl;
        
    }
  }
  return 0;  
}
