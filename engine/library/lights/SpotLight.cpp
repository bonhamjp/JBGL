#include "SpotLight.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "core/object/light/LightList.h"

namespace DataGarden
{
  SpotLight::SpotLight() :
  Light()
  {
		m_Position = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
		m_Direction = glm::vec4(0.0f, 0.0f, -1.0f, 0.0f); // points forward in z-axis

		m_Constant = 1.0f;
		m_Linear = 0.2f;
		m_Quadratic = 0.02f;

		m_InnerCutoff = 14.0f;
		m_OuterCutoff = 17.5f;
  }

	SpotLight::SpotLight(glm::vec4 position, glm::vec4 direction) :
	Light()
	{
		m_Position = position;
		m_Direction = direction;

		m_Constant = 1.0f;
		m_Linear = 0.2f;
		m_Quadratic = 0.02f;

		m_InnerCutoff = 14.0f;
		m_OuterCutoff = 17.5f;
	}

	SpotLight::SpotLight(glm::vec4 position, glm::vec4 direction, glm::vec4 color) :
	Light(color)
	{
		m_Position = position;
		m_Direction = direction;

		m_Constant = 1.0f;
		m_Linear = 0.2f;
		m_Quadratic = 0.02f;

		m_InnerCutoff = 14.0f;
		m_OuterCutoff = 17.5f;
	}

  SpotLight::SpotLight(glm::vec4 position, glm::vec4 direction, glm::vec4 color, float constant, float linear, float quadratic, float innerCutoff, float outerCutoff) :
  Light(color)
  {
		m_Position = position;
		m_Direction = direction;

		m_Constant = constant;
		m_Linear = linear;
		m_Quadratic = quadratic;

		m_InnerCutoff = innerCutoff;
		m_OuterCutoff = outerCutoff;
  }

  SpotLight::SpotLight(glm::vec4 position, glm::vec4 direction, glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength, float constant, float linear, float quadratic, float innerCutoff, float outerCutoff) :
  Light(color, ambientStrength, diffuseStrength, specularStrength)
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
  {}

	void UpdateSpotLightUniforms(LightListOfType spotLightList)
  {
    Renderer& renderer = Engine::Get().GetRenderer();
    unsigned int programID = renderer.GetMainProgramID();

    renderer.SetUniform1i(programID, "u_SpotLightCount", spotLightList.LightCount);
    
    for (int i = 0; i < spotLightList.LightCount; i++)
    {
			std::string iStr = std::to_string(i);

      SpotLight* spotLight = (SpotLight*) spotLightList.Lights[i];

      std::string positionName = "u_SpotLights[" + iStr + "].Position";
			renderer.SetUniform4fv(programID, positionName.c_str(), spotLight->GetPosition());
			
			std::string directionName = "u_SpotLights[" + iStr + "].Direction";
			renderer.SetUniform4fv(programID, directionName.c_str(), spotLight->GetDirection());

			std::string ambientName = "u_SpotLights[" + iStr + "].AmbientColor";
      renderer.SetUniform4fv(programID, ambientName.c_str(), spotLight->GetAmbientColor());

			std::string diffuseName = "u_SpotLights[" + iStr + "].DiffuseColor";
      renderer.SetUniform4fv(programID, diffuseName.c_str(), spotLight->GetDiffuseColor());

			std::string specularName = "u_SpotLights[" + iStr + "].SpecularColor";
      renderer.SetUniform4fv(programID, specularName.c_str(), spotLight->GetSpecularColor());

			std::string constantName = "u_SpotLights[" + iStr + "].ConstantS";
      renderer.SetUniform1f(programID, constantName.c_str(), spotLight->GetConstant());

			std::string linearName = "u_SpotLights[" + iStr + "].LinearS";
      renderer.SetUniform1f(programID, linearName.c_str(), spotLight->GetLinear());

			std::string quadraticName = "u_SpotLights[" + iStr + "].QuadraticS";
      renderer.SetUniform1f(programID, quadraticName.c_str(), spotLight->GetQuadratic());

			std::string innerCutoffName = "u_SpotLights[" + iStr + "].InnerCuttof";
      renderer.SetUniform1f(programID, innerCutoffName.c_str(), spotLight->GetInnerCutoff());

			std::string outerCutoffName = "u_SpotLights[" + iStr + "].OuterCutoff";
      renderer.SetUniform1f(programID, outerCutoffName.c_str(), spotLight->GetOuterCutoff());
    }
  }
}
