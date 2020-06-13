#include <iostream>
#include <memory>

enum class VehicleType {
  VT_TwoWheeler, VT_ThreeWheeler  
};

class TwoWheeler;
class ThreeWheeler;

class Vehicle {
  public:
  static std::shared_ptr<Vehicle> create(VehicleType type) {
    switch (type) {
      case VehicleType::VT_TwoWheeler:
        return std::dynamic_pointer_cast<Vehicle>(std::make_shared<TwoWheeler>());
        break;
      case VehicleType::VT_ThreeWheeler:
        return std::dynamic_pointer_cast<Vehicle>(std::make_shared<ThreeWheeler>());
        break;
      default:
        return nullptr;
    }
    return nullptr;
  }

  virtual void run() = 0;
};

class TwoWheeler : public Vehicle {
  void run() override {
    std::cout << "TwoWheeler::run()" << std::endl;
  }
};

class ThreeWheeler : public Vehicle {
  void run() override {
    std::cout << "ThreeeWheeler::run()" << std::endl;
  }
};

int main() {
  auto tw = Vehicle::create(VehicleType::VT_TwoWheeler);
  tw->run();
  auto tw2 = Vehicle::create(VehicleType::VT_ThreeWheeler);
  tw2->run();
  return 0;  
}
