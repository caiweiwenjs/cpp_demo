#include <iostream>


class I {
  public:
    static void func();
    static void func2();
};

class A : public I {
};
  void I::func() {
      std::cout << "A::func()" << std::endl;  
    }
    void I::func2() {
      std::cout << "A::func2()" << std::endl;  
    }



int main() {
  I::func();
  I::func2();
  return 0;  
}
