#include "DirectionLight.h"

namespace DataGarden
{
  DirectionLight::DirectionLight() :
  Light()
  {
		m_Direction = glm::vec4(0.0f, 0.0f, -1.0f, 0.0f); // points forward in z-axis
  }

  DirectionLight::DirectionLight(glm::vec4 direction) :
  Light()
  {
    m_Direction = direction;
  }

  DirectionLight::DirectionLight(glm::vec4 direction, glm::vec4 color) :
  Light(color)
  {
    m_Direction = direction;
  }

  DirectionLight::DirectionLight(glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, glm::vec4 direction) :
  Light(color, ambientStrength, specularStrength, diffuseStrength)
  {
    m_Direction = direction;
  }

  DirectionLight::~DirectionLight()
  {}
}
