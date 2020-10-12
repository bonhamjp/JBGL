#include "Light.h"

#include "core/Engine.h"

namespace DataGarden
{
  Light::Light()
  {
    m_Active = true;

    m_Color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f); // white default light

    m_AmbientStrength = 0.1f;
    m_DiffuseStrength = 0.5f;
    m_SpecularStrength = 0.75f;
  }

  Light::Light(glm::vec4 color)
  {
    m_Active = true;

    m_Color = color;

    m_AmbientStrength = 0.1f;
    m_DiffuseStrength = 0.5f;
    m_SpecularStrength = 0.75f;
  }

  Light::Light(glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength)
  {
    m_Active = true;

    m_Color = color;

    m_AmbientStrength = ambientStrength;
    m_DiffuseStrength = diffuseStrength;
    m_SpecularStrength = specularStrength;
  }
  
  Light::~Light()
  {}

  void Light::Destroy()
  {
    m_Active = false;
  }
}
