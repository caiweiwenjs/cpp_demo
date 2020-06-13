#include <iostream>

// c++14
auto sumCpp14() {
  return 0;  
}

template <typename T1, typename... T2>
T1 sumCpp14(T1 a1, T2... args) {
  return a1 + sumCpp14(args...);
}

// c++17
template<typename ...Args> auto sumCpp17(Args ...args)
{
    return (args + ...);
}

int main() {
  std::cout << sumCpp14(1, 2, 3) << std::endl;
  std::cout << sumCpp14(1, 2, 3, 4) << std::endl;
  std::cout << sumCpp14(1.0, 2, 3, 4) << std::endl;
  std::cout << sumCpp17(1.0, 2, 3, 4) << std::endl;
  return 0;  
}
