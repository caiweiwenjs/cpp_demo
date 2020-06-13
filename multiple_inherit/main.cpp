#include <iostream>
#include <memory>


class A {
  public:
    virtual void fn() {
      std::cout << "A::fn" << std::endl;  
    }
};

class B {
  public:
    virtual void fn() {
      std::cout << "B::fn" << std::endl;  
    }
};


class C : public A, public B {
  public:
  virtual void fn() override {
    std::cout<< "C::fn" << std::endl;
  }
};

int main() {
  std::shared_ptr<A> c = std::make_shared<C>();
  c->fn();
  std::shared_ptr<B> cc = std::make_shared<C>();
  cc->fn();
  return 0;  
}
