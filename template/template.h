#pragma once

#include <vector>

namespace tpl {

  template <typename T>
  class Cache {
    public:
      struct Params {
        bool flag = false;  
      };

      Cache(const std::vector<T>& data, const Params& params = Params()) 
        : m_data(data), m_params(params) {}

    private:
      std::vector<T> m_data;
      Params m_params;
  };

  struct Params2 {
    bool ff = false;  
  };

  typedef Cache<int> CacheI;

  template <typename T> using Cache<T>::Params;


  class Cache2 {
    public:
      struct Params {
        bool flag = false;   
      };
  };
}
