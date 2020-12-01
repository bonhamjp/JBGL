#ifndef DATA_GARDEN_SPOT_LIGHT
#define DATA_GARDEN_SPOT_LIGHT

#include "DataGarden.h"

#include "core/object/light/Light.h"

namespace DataGarden
{
  // forward declarations
  class LightListOfType;

  class SpotLight : public Light
  {
  public:
    SpotLight();
    SpotLight(glm::vec4 position, glm::vec4 direction);
    SpotLight(glm::vec4 position, glm::vec4 direction, glm::vec4 color);
    SpotLight(glm::vec4 position, glm::vec4 direction, glm::vec4 color, float constant, float linear, float quadratic, float innerCutoff, float outerCutoff);
    SpotLight(glm::vec4 position, glm::vec4 direction, glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, float constant, float linear, float quadratic, float innerCutoff, float outerCutoff);
    ~SpotLight();

    inline glm::vec4 GetPosition() { return m_Position; };
    inline glm::vec4 GetDirection() { return m_Direction; };

    inline float GetConstant() { return m_Constant; };
    inline float GetLinear() { return m_Linear; };
    inline float GetQuadratic() { return m_Quadratic; };

    inline float GetInnerCutoff() { return m_InnerCutoff; };
    inline float GetOuterCutoff() { return m_OuterCutoff; };
    
  private:
    glm::vec4 m_Position;
		glm::vec4 m_Direction;

		float m_Constant;
		float m_Linear;
		float m_Quadratic;

		float m_InnerCutoff;
		float m_OuterCutoff;
  };

  // TODO: Implement as a class method
  void UpdateSpotLightUniforms(LightListOfType spotLightList);
}

#endif
