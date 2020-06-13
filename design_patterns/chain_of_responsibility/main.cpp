#include <iostream>
#include <memory>


class Number {
  public:
    Number(int number) : m_number(number) {}

    int GetValue() {
      return m_number;  
    }

  private:
    int m_number;
};

class NumberHandler {
  public:
    NumberHandler(std::shared_ptr<NumberHandler> next) {
       m_next = next;
    }

    void add(std::shared_ptr<NumberHandler> next) {
      if (m_next) {
        m_next->add(next);  
      } else {
        m_next = next;  
      }
    }

    virtual void process(std::shared_ptr<Number> number) {
      if (m_next) {
        m_next->process(number);  
      }
    }

  private:
    std::shared_ptr<NumberHandler> m_next;
};

class PositiveNumberHandler : public NumberHandler {
  public:
    PositiveNumberHandler(std::shared_ptr<NumberHandler> next) : NumberHandler(next) {}

    void process(std::shared_ptr<Number> number) override {
       if (number->GetValue() > 0) {
         std::cout << "PositiveNumberHandler value = " << number->GetValue() << std::endl;  
       } else {
         NumberHandler::process(number);  
       }
    }
};

class ZeroNumberHandler : public NumberHandler {
  public:
    ZeroNumberHandler(std::shared_ptr<NumberHandler> next) : NumberHandler(next) {}
    void process(std::shared_ptr<Number> number) override {
      if (number->GetValue() == 0) {
         std::cout << "ZeroNumberHandler value = " << number->GetValue() << std::endl;  
       } else {
         NumberHandler::process(number);  
       }
    }
    
};

class NegativeNumberHandler : public NumberHandler {
  public:
    NegativeNumberHandler(std::shared_ptr<NumberHandler> next) : NumberHandler(next) {}
    void process(std::shared_ptr<Number> number) override {
      if (number->GetValue() < 0) {
         std::cout << "NegativeNumberHandler value = " << number->GetValue() << std::endl;  
       } else {
         NumberHandler::process(number);  
       }
    }
};
    

int main() {
  std::shared_ptr<NumberHandler> nh = std::make_shared<PositiveNumberHandler>(std::make_shared<ZeroNumberHandler>(std::make_shared<NegativeNumberHandler>(nullptr)));
  nh->process(std::make_shared<Number>(0));
  nh->process(std::make_shared<Number>(1));
  nh->process(std::make_shared<Number>(-1));
  std::shared_ptr<NumberHandler> nh2 = std::make_shared<PositiveNumberHandler>(nullptr);
  nh2->add(std::make_shared<ZeroNumberHandler>(nullptr));
  nh2->add(std::make_shared<NegativeNumberHandler>(nullptr));
  nh2->process(std::make_shared<Number>(0));
  nh2->process(std::make_shared<Number>(1));
  nh2->process(std::make_shared<Number>(-1));

  return 0;  
}
