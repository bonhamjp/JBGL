#ifndef DATA_GARDEN_UNIVERSAL
#define DATA_GARDEN_UNIVERSAL

#include <memory>

#define BIT(x) (1 << x)

#define BIND_EVENT_FUNCTION(function) std::bind(&function, this, std::placeholders::_1)

namespace DataGarden
{
  static unsigned int u_ID = 0;

  template<typename T>
  using Scope = std::unique_ptr<T>;

  template<typename T>
  using Ref = std::shared_ptr<T>;

  template<typename T>
  using Weak = std::weak_ptr<T>;

  template<typename T>
  unsigned int ClassID()
  {
    static unsigned int classID = u_ID++;

    return classID;
  }
}

#endif
