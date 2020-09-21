#include "PointLight.h"

namespace DataGarden
{
  PointLight::PointLight() :
  Light()
  {
    m_Constant = 1.0f;
		m_Linear = 0.2f;
		m_Quadratic = 0.02f;
  }

  PointLight::PointLight(float constant, float linear, float quadtratic) :
  Light()
  {
    m_Constant = constant;
		m_Linear = linear;
		m_Quadratic = quadtratic;
  }

  PointLight::PointLight(glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, float constant, float linear, float quadtratic) :
  Light(color, ambientStrength, specularStrength, diffuseStrength)
  {
    m_Constant = constant;
		m_Linear = linear;
		m_Quadratic = quadtratic;
  }

  PointLight::~PointLight()
  {}
}
