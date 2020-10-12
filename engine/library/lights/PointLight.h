#ifndef DATA_GARDEN_POINT_LIGHT
#define DATA_GARDEN_POINT_LIGHT

#include "DataGarden.h"

#include "core/object/light/Light.h"

namespace DataGarden
{
  class PointLight : public Light
  {
  public:
    PointLight();
    PointLight(Transform transform);
    PointLight(Transform transform, glm::vec4 color);
    PointLight(Transform transform, glm::vec4 color, float constant, float linear, float quadtratic);
    PointLight(Transform transform, glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, float constant, float linear, float quadtratic);
    ~PointLight();
    
  private:
    Transform m_Transform;
    float m_Constant;
		float m_Linear;
		float m_Quadratic;
  };
}

#endif
