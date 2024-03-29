#include "PointLight.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "core/scene/Scene.h"

#include "core/object/light/LightList.h"

#include "library/shaders/VisualizationShader.h"

namespace DataGarden
{
  PointLight::PointLight() : Light()
  {
    m_Constant = 1.0f;
    m_Linear = 0.2f;
    m_Quadratic = 0.02f;
  }

  PointLight::PointLight(Transform transform) : Light()
  {
    m_Transform = transform;
  }

  PointLight::PointLight(Transform transform, glm::vec4 color) : Light(color)
  {
    m_Transform = transform;
  }

  PointLight::PointLight(Transform transform, glm::vec4 color, float constant, float linear, float quadtratic) : Light(color)
  {
    m_Transform = transform;
    m_Constant = constant;
    m_Linear = linear;
    m_Quadratic = quadtratic;
  }

  PointLight::PointLight(Transform transform, glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, float constant, float linear, float quadtratic) : Light(color, ambientStrength, specularStrength, diffuseStrength)
  {
    m_Transform = transform;
    m_Constant = constant;
    m_Linear = linear;
    m_Quadratic = quadtratic;
  }

  PointLight::~PointLight()
  {
  }

  void UpdatePointLightUniforms(LightListOfType pointLightList)
  {
    VisualizationShader *visualizationShader = Engine::Get().GetShaderManager().GetVisualizationShader();
    visualizationShader->Bind();
    visualizationShader->SetPointLightUniforms(pointLightList);
    visualizationShader->Unbind();
  }
} // namespace DataGarden
