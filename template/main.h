#pragma once
#include <vector>


namespace tpl {
  template<class T>
  class Cache;


  template<class T>
  struct Cached<T>::Params;

  struct Params2;
}


namespace my_space {

  class Test {
   public:
//    static std::vector<int> createIntCache(std::shared_ptr<tpl::Cache<int>::Params> params);
   std::vector<int> createIntCache(std::shared_ptr<tpl::Params2> params);
    std::vector<int> createIntCache();
   private:
    std::shared_ptr<tpl::Cache<int>> m_data;
  };
    
}
