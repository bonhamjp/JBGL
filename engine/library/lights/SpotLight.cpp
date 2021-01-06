#include "SpotLight.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "core/scene/Scene.h"

#include "core/object/light/LightList.h"

#include "library/shaders/Visualization3DShader.h"

namespace DataGarden
{
  SpotLight::SpotLight() : Light()
  {
    m_Position = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
    m_Direction = glm::vec4(0.0f, 0.0f, -1.0f, 0.0f); // points forward in z-axis

    m_Constant = 1.0f;
    m_Linear = 0.2f;
    m_Quadratic = 0.02f;

    m_InnerCutoff = 14.0f;
    m_OuterCutoff = 17.5f;
  }

  SpotLight::SpotLight(glm::vec4 position, glm::vec4 direction) : Light()
  {
    m_Position = position;
    m_Direction = direction;

    m_Constant = 1.0f;
    m_Linear = 0.2f;
    m_Quadratic = 0.02f;

    m_InnerCutoff = 14.0f;
    m_OuterCutoff = 17.5f;
  }

  SpotLight::SpotLight(glm::vec4 position, glm::vec4 direction, glm::vec4 color) : Light(color)
  {
    m_Position = position;
    m_Direction = direction;

    m_Constant = 1.0f;
    m_Linear = 0.2f;
    m_Quadratic = 0.02f;

    m_InnerCutoff = 14.0f;
    m_OuterCutoff = 17.5f;
  }

  SpotLight::SpotLight(glm::vec4 position, glm::vec4 direction, glm::vec4 color, float constant, float linear, float quadratic, float innerCutoff, float outerCutoff) : Light(color)
  {
    m_Position = position;
    m_Direction = direction;

    m_Constant = constant;
    m_Linear = linear;
    m_Quadratic = quadratic;

    m_InnerCutoff = innerCutoff;
    m_OuterCutoff = outerCutoff;
  }

  SpotLight::SpotLight(glm::vec4 position, glm::vec4 direction, glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, float constant, float linear, float quadratic, float innerCutoff, float outerCutoff) : Light(color, ambientStrength, diffuseStrength, specularStrength)
  {
    m_Position = position;
    m_Direction = direction;

    m_Constant = constant;
    m_Linear = linear;
    m_Quadratic = quadratic;

    m_InnerCutoff = innerCutoff;
    m_OuterCutoff = outerCutoff;
  }

  SpotLight::~SpotLight()
  {
  }

  void UpdateSpotLightUniforms(LightListOfType spotLightList)
  {
    Visualization3DShader *m_Visualization3DShader = Engine::Get().GetScene().GetShaderManager()->GetVisualization3DShader();

    m_Visualization3DShader->SetSpotLightUniforms(spotLightList);
  }
} // namespace DataGarden
