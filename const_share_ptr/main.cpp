#include <iostream>
#include <memory>

class A {
  public:
    int a;
};

void changeSharedPtr(const std::shared_ptr<A>& a) {
  a->a = 10;
}  

int main() {
  auto a = std::make_shared<A>();
  a->a = 1;
  changeSharedPtr(a);
  std::cout << a->a << std::endl;
  return 0;  
}
