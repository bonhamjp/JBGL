#include "DirectionalLight.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "core/scene/Scene.h"

#include "core/object/light/LightList.h"

#include "library/shaders/VisualizationShader.h"

namespace DataGarden
{
  DirectionalLight::DirectionalLight() : Light()
  {
    m_Direction = glm::vec4(0.0f, 0.0f, -1.0f, 0.0f); // points forward in z-axis
  }

  DirectionalLight::DirectionalLight(glm::vec4 direction) : Light()
  {
    m_Direction = direction;
  }

  DirectionalLight::DirectionalLight(glm::vec4 direction, glm::vec4 color) : Light(color)
  {
    m_Direction = direction;
  }

  DirectionalLight::DirectionalLight(glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, glm::vec4 direction) : Light(color, ambientStrength, specularStrength, diffuseStrength)
  {
    m_Direction = direction;
  }

  DirectionalLight::~DirectionalLight()
  {
  }

  void UpdateDirectionalLightUniforms(LightListOfType directionalLightList)
  {
    VisualizationShader *visualizationShader = Engine::Get().GetShaderManager().GetVisualizationShader();
    visualizationShader->Bind();
    visualizationShader->SetDirectionalLightUniforms(directionalLightList);
    visualizationShader->Unbind();
  }
} // namespace DataGarden
