#include "main.h"
#include "template.h"

#include <memory>

namespace my_space { 

  /*
std::vector<int> Test::createIntCache(std::shared_ptr<tpl::Params> params) {
  return {};
}
*/

std::vector<int> Test::createIntCache() {
  std::shared_ptr<tpl::Cache<int>> a(new tpl::Cache<int>({1, 2, 3}));// = std::make_shared<tpl::Cache<int>>();
  m_data = a;
  return {};
}

std::vector<int> Test::createIntCache(std::shared_ptr<tpl::Params2> params) {
  return {};
}

}


int main() {
//  auto params = std::make_shared<tpl::Params>();
//  auto a = my_space::Test::createIntCache(params);
  auto test = my_space::Test();
  auto a = test.createIntCache();
  auto params2 = std::make_shared<tpl::Params2>();
  auto b = test.createIntCache(params2);
  return 0;  
}

