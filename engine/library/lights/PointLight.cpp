#include "PointLight.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "core/scene/Scene.h"

#include "core/object/light/LightList.h"

#include "library/shaders/Visualization3DShader.h"

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
    Visualization3DShader *m_Visualization3DShader = Engine::Get().GetShaderManager().GetVisualization3DShader();

    m_Visualization3DShader->SetPointLightUniforms(pointLightList);
  }
} // namespace DataGarden
