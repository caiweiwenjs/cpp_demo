#include <iostream>

int fact(int n) {
  // need c++14 to support recursive lambda
  auto iter = [n](int i, int m, auto& iter_ref) {
     if (i > n) {
       return m;  
     } else {
       return iter_ref(i + 1, i * m, iter_ref);   
     }
  };
  return iter(1, 1, iter); 
}

int main() {
  std::cout << fact(1) << std::endl;
  std::cout << fact(2) << std::endl;
  std::cout << fact(3) << std::endl;
  std::cout << fact(4) << std::endl;
  std::cout << fact(5) << std::endl;
  return 0;
}
