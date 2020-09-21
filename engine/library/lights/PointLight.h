#ifndef DATA_GARDEN_POINT_LIGHT
#define DATA_GARDEN_POINT_LIGHT

#include "DataGarden.h"

#include "core/object/light/Light.h"

namespace DataGarden
{
  class PointLight : Light
  {
  public:
    PointLight();
    PointLight(float constant, float linear, float quadtratic);
    PointLight(glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, float constant, float linear, float quadtratic);
    ~PointLight();
    
  private:
    float m_Constant;
		float m_Linear;
		float m_Quadratic;
  };
}

#endif
