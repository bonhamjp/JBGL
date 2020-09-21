#ifndef DATA_GARDEN_SPOT_LIGHT
#define DATA_GARDEN_SPOT_LIGHT

#include "DataGarden.h"

#include "core/object/light/Light.h"

namespace DataGarden
{
  class SpotLight : Light
  {
  public:
    SpotLight();
    SpotLight(glm::vec4 direction, float constant, float linear, float quadratic, float innerCutoff, float outerCutoff);
    SpotLight(glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, glm::vec4 direction, float constant, float linear, float quadratic, float innerCutoff, float outerCutoff);
    ~SpotLight();
    
  private:
		glm::vec4 m_Direction;

		float m_Constant;
		float m_Linear;
		float m_Quadratic;

		float m_InnerCutoff;
		float m_OuterCutoff;
  };
}

#endif