#ifndef DATA_GARDEN_DIRECTIONAL_LIGHT
#define DATA_GARDEN_DIRECTIONAL_LIGHT

#include "DataGarden.h"

#include "core/object/light/Light.h"

namespace DataGarden
{
  // forward declarations
  class LightListOfType;

  class DirectionalLight : public Light
  {
  public:
    DirectionalLight();
    DirectionalLight(glm::vec4 direction);
    DirectionalLight(glm::vec4 direction, glm::vec4 color);
    DirectionalLight(glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, glm::vec4 direction);
    ~DirectionalLight();

    inline glm::vec4 GetDirection() { return m_Direction; };

  private:
    glm::vec4 m_Direction;
  };

  // TODO: Implement as a class method
  void UpdateDirectionalLightUniforms(LightListOfType directionalLightList);
} // namespace DataGarden

#endif
