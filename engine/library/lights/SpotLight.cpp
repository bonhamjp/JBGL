#include "SpotLight.h"

namespace DataGarden
{
  SpotLight::SpotLight() :
  Light()
  {
		m_Direction = glm::vec4(0.0f, 0.0f, -1.0f, 0.0f); // points forward in z-axis

		m_Constant = 1.0f;
		m_Linear = 0.2f;
		m_Quadratic = 0.02f;

		m_InnerCutoff = 14.0f;
		m_OuterCutoff = 17.5f;
  }

  SpotLight::SpotLight(glm::vec4 direction, float constant, float linear, float quadratic, float innerCutoff, float outerCutoff) :
  Light()
  {
		m_Direction = direction;

		m_Constant = constant;
		m_Linear = linear;
		m_Quadratic = quadratic;

		m_InnerCutoff = innerCutoff;
		m_OuterCutoff = outerCutoff;
  }

  SpotLight::SpotLight(glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, glm::vec4 direction, float constant, float linear, float quadratic, float innerCutoff, float outerCutoff) :
  Light(color, ambientStrength, diffuseStrength, specularStrength)
  {
		m_Direction = direction;

		m_Constant = constant;
		m_Linear = linear;
		m_Quadratic = quadratic;

		m_InnerCutoff = innerCutoff;
		m_OuterCutoff = outerCutoff;
  }

  SpotLight::~SpotLight()
  {}
}
