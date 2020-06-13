#include <iostream>
#include <map>

class A {
public:

  A() :mp({ {1, 2}, {2, 1}}) {
  }

  void changeMap() {
 //   mp.insert({1, 3}); 
 //   mp[1] = 2;
      std::cout << mp.at(1) << std::endl;

    }

private:
  const std::map<int, int> mp;
  };


int main() {
  auto a = std::make_shared<A>();
  a->changeMap();
  return 0;
}
