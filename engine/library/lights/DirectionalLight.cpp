#include "DirectionalLight.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "core/object/light/LightList.h"

namespace DataGarden
{
  DirectionalLight::DirectionalLight() :
  Light()
  {
		m_Direction = glm::vec4(0.0f, 0.0f, -1.0f, 0.0f); // points forward in z-axis
  }

  DirectionalLight::DirectionalLight(glm::vec4 direction) :
  Light()
  {
    m_Direction = direction;
  }

  DirectionalLight::DirectionalLight(glm::vec4 direction, glm::vec4 color) :
  Light(color)
  {
    m_Direction = direction;
  }

  DirectionalLight::DirectionalLight(glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, glm::vec4 direction) :
  Light(color, ambientStrength, specularStrength, diffuseStrength)
  {
    m_Direction = direction;
  }

  DirectionalLight::~DirectionalLight()
  {}

  void UpdateDirectionalLightUniforms(LightListOfType directionalLightList)
  {
    Renderer& renderer = Engine::Get().GetRenderer();
    unsigned int programID = renderer.GetMainProgramID();

    renderer.SetUniform1i(programID, "u_DirectionalLightCount", directionalLightList.LightCount);
    
    for (int i = 0; i < directionalLightList.LightCount; i++)
    {
      std::string iStr = std::to_string(i);

      DirectionalLight* directionalLight = (DirectionalLight*) directionalLightList.Lights[i];

      std::string positionName = "u_DirectionalLights[" + iStr + "].Direction";
			renderer.SetUniform4fv(programID, positionName.c_str(), directionalLight->GetDirection());

			std::string ambientName = "u_DirectionalLights[" + iStr + "].AmbientColor";
      renderer.SetUniform4fv(programID, ambientName.c_str(), directionalLight->GetAmbientColor());

			std::string diffuseName = "u_DirectionalLights[" + iStr + "].DiffuseColor";
      renderer.SetUniform4fv(programID, diffuseName.c_str(), directionalLight->GetDiffuseColor());

			std::string specularName = "u_DirectionalLights[" + iStr + "].SpecularColor";
      renderer.SetUniform4fv(programID, specularName.c_str(), directionalLight->GetSpecularColor());
    }
  }
}
