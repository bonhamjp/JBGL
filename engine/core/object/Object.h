#ifndef DATA_GARDEN_OBJECT
#define DATA_GARDEN_OBJECT

#include "DataGarden.h"

#include "Transform.h"

namespace DataGarden
{
  class Object
  {
  public:
    Object();
    ~Object();

    inline void SetTransform(Transform transform) { m_Transform = transform; };
    inline Transform &GetTransform() { return m_Transform; };

  protected:
    Transform m_Transform;
  };
} // namespace DataGarden

#endif
