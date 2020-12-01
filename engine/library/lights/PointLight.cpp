#include "PointLight.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "core/object/light/LightList.h"

namespace DataGarden
{
  PointLight::PointLight() :
  Light()
  {
    m_Constant = 1.0f;
		m_Linear = 0.2f;
		m_Quadratic = 0.02f;
  }

  PointLight::PointLight(Transform transform) :
  Light()
  {
    m_Transform = transform;
  }

  PointLight::PointLight(Transform transform, glm::vec4 color) :
  Light(color)
  {
    m_Transform = transform;
  }

  PointLight::PointLight(Transform transform, glm::vec4 color, float constant, float linear, float quadtratic) :
  Light(color)
  {
    m_Transform = transform;
    m_Constant = constant;
		m_Linear = linear;
		m_Quadratic = quadtratic;
  }

  PointLight::PointLight(Transform transform, glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, float constant, float linear, float quadtratic) :
  Light(color, ambientStrength, specularStrength, diffuseStrength)
  {
    m_Transform = transform;
    m_Constant = constant;
		m_Linear = linear;
		m_Quadratic = quadtratic;
  }

  PointLight::~PointLight()
  {}

  void UpdatePointLightUniforms(LightListOfType pointLightList)
  {
    Renderer& renderer = Engine::Get().GetRenderer();
    unsigned int programID = renderer.GetMainProgramID();

    renderer.SetUniform1i(programID, "u_PointLightCount", pointLightList.LightCount);
    
    for (int i = 0; i < pointLightList.LightCount; i++)
    {
      std::string iStr = std::to_string(i);

      PointLight* pointLight = (PointLight*) pointLightList.Lights[i];

      std::string positionName = "u_PointLights[" + iStr + "].Position";
			renderer.SetUniform4fv(programID, positionName.c_str(), glm::vec4(pointLight->GetTransform().GetPosition(), 1.0f));

			std::string ambientName = "u_PointLights[" + iStr + "].AmbientColor";
      renderer.SetUniform4fv(programID, ambientName.c_str(), pointLight->GetAmbientColor());

			std::string diffuseName = "u_PointLights[" + iStr + "].DiffuseColor";
      renderer.SetUniform4fv(programID, diffuseName.c_str(), pointLight->GetDiffuseColor());

			std::string specularName = "u_PointLights[" + iStr + "].SpecularColor";
      renderer.SetUniform4fv(programID, specularName.c_str(), pointLight->GetSpecularColor());

			std::string constantName = "u_PointLights[" + iStr + "].ConstantS";
      renderer.SetUniform1f(programID, constantName.c_str(), pointLight->GetConstant());

			std::string linearName = "u_PointLights[" + iStr + "].LinearS";
      renderer.SetUniform1f(programID, linearName.c_str(), pointLight->GetLinear());

			std::string quadraticName = "u_PointLights[" + iStr + "].QuadraticS";
      renderer.SetUniform1f(programID, quadraticName.c_str(), pointLight->GetQuadratic());
    }
  }
}
