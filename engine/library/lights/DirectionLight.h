#ifndef DATA_GARDEN_DIRECTION_LIGHT
#define DATA_GARDEN_DIRECTION_LIGHT

#include "DataGarden.h"

#include "core/object/light/Light.h"

namespace DataGarden
{
  class DirectionLight : public Light
  {
  public:
    DirectionLight();
    DirectionLight(glm::vec4 direction);
    DirectionLight(glm::vec4 direction, glm::vec4 color);
    DirectionLight(glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, glm::vec4 direction);
    ~DirectionLight();
    
  private:
    glm::vec4 m_Direction;
  };
}

#endif
