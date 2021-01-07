#ifndef DATA_GARDEN_POINT_LIGHT
#define DATA_GARDEN_POINT_LIGHT

#include "DataGarden.h"

#include "core/object/light/Light.h"

namespace DataGarden
{
  // forward declarations
  class LightListOfType;

  class PointLight : public Light
  {
  public:
    PointLight();
    PointLight(Transform transform);
    PointLight(Transform transform, glm::vec4 color);
    PointLight(Transform transform, glm::vec4 color, float constant, float linear, float quadtratic);
    PointLight(Transform transform, glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, float constant, float linear, float quadtratic);
    ~PointLight();

    inline void SetTransform(Transform transform) { m_Transform = transform; };
    inline Transform &GetTransform() { return m_Transform; };

    inline float GetConstant() { return m_Constant; };
    inline float GetLinear() { return m_Linear; };
    inline float GetQuadratic() { return m_Quadratic; };

  private:
    Transform m_Transform;
    float m_Constant;
    float m_Linear;
    float m_Quadratic;
  };

  // TODO: Implement as a class method
  void UpdatePointLightUniforms(LightListOfType pointLightList);
} // namespace DataGarden

#endif
