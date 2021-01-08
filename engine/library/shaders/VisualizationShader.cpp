#include "VisualizationShader.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "library/lights/DirectionalLight.h"
#include "library/lights/PointLight.h"
#include "library/lights/SpotLight.h"

namespace DataGarden
{
  VisualizationShader::VisualizationShader(ShaderType shaderType) : Shader(shaderType)
  {
    _Setup();
  }

  VisualizationShader::~VisualizationShader()
  {
  }

  void VisualizationShader::SetViewProjectionUniform(glm::mat4 viewProjection)
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniformMatrix4fv(m_ProgramID, "u_ViewProjection", viewProjection);
  }

  void VisualizationShader::SetViewPositionUniform(glm::vec3 viewPosition)
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniform3fv(m_ProgramID, "u_ViewPosition", viewPosition);
  }

  void VisualizationShader::SetModelUniform(glm::mat4 model)
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniformMatrix4fv(m_ProgramID, "u_Vertex.Model", model);
  }

  void VisualizationShader::SetMaterialShininessUniform(float shininess)
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniform1f(m_ProgramID, "u_Material.Shininess", shininess);
  }

  void VisualizationShader::SetAmbientTexturesUniform(int ambientTextures)
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniform1i(m_ProgramID, "u_AmbientTextures", ambientTextures);
  }

  void VisualizationShader::SetDiffuseTexturesUniform(int diffuseTextures)
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniform1i(m_ProgramID, "u_DiffuseTextures", diffuseTextures);
  }

  void VisualizationShader::SetSpecularTexturesUniform(int specularTextures)
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniform1i(m_ProgramID, "u_SpecularTextures", specularTextures);
  }

  void VisualizationShader::SetDirectionalLightUniforms(LightListOfType directionalLightList)
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniform1i(m_ProgramID, "u_DirectionalLightCount", directionalLightList.LightCount);
    for (int i = 0; i < directionalLightList.LightCount; i++)
    {
      std::string iStr = std::to_string(i);

      DirectionalLight *directionalLight = (DirectionalLight *)directionalLightList.Lights[i];

      std::string positionName = "u_DirectionalLights[" + iStr + "].Direction";
      renderer.SetUniform4fv(m_ProgramID, positionName.c_str(), directionalLight->GetDirection());

      std::string ambientName = "u_DirectionalLights[" + iStr + "].AmbientColor";
      renderer.SetUniform4fv(m_ProgramID, ambientName.c_str(), directionalLight->GetAmbientColor());

      std::string diffuseName = "u_DirectionalLights[" + iStr + "].DiffuseColor";
      renderer.SetUniform4fv(m_ProgramID, diffuseName.c_str(), directionalLight->GetDiffuseColor());

      std::string specularName = "u_DirectionalLights[" + iStr + "].SpecularColor";
      renderer.SetUniform4fv(m_ProgramID, specularName.c_str(), directionalLight->GetSpecularColor());
    }
  }

  void VisualizationShader::SetPointLightUniforms(LightListOfType pointLightList)
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniform1i(m_ProgramID, "u_PointLightCount", pointLightList.LightCount);
    for (int i = 0; i < pointLightList.LightCount; i++)
    {
      std::string iStr = std::to_string(i);

      PointLight *pointLight = (PointLight *)pointLightList.Lights[i];

      std::string positionName = "u_PointLights[" + iStr + "].Position";
      renderer.SetUniform4fv(m_ProgramID, positionName.c_str(), glm::vec4(pointLight->GetTransform().GetPosition(), 1.0f));

      std::string ambientName = "u_PointLights[" + iStr + "].AmbientColor";
      renderer.SetUniform4fv(m_ProgramID, ambientName.c_str(), pointLight->GetAmbientColor());

      std::string diffuseName = "u_PointLights[" + iStr + "].DiffuseColor";
      renderer.SetUniform4fv(m_ProgramID, diffuseName.c_str(), pointLight->GetDiffuseColor());

      std::string specularName = "u_PointLights[" + iStr + "].SpecularColor";
      renderer.SetUniform4fv(m_ProgramID, specularName.c_str(), pointLight->GetSpecularColor());

      std::string constantName = "u_PointLights[" + iStr + "].ConstantS";
      renderer.SetUniform1f(m_ProgramID, constantName.c_str(), pointLight->GetConstant());

      std::string linearName = "u_PointLights[" + iStr + "].LinearS";
      renderer.SetUniform1f(m_ProgramID, linearName.c_str(), pointLight->GetLinear());

      std::string quadraticName = "u_PointLights[" + iStr + "].QuadraticS";
      renderer.SetUniform1f(m_ProgramID, quadraticName.c_str(), pointLight->GetQuadratic());
    }
  }

  void VisualizationShader::SetSpotLightUniforms(LightListOfType spotLightList)
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniform1i(m_ProgramID, "u_SpotLightCount", spotLightList.LightCount);
    for (int i = 0; i < spotLightList.LightCount; i++)
    {
      std::string iStr = std::to_string(i);

      SpotLight *spotLight = (SpotLight *)spotLightList.Lights[i];

      std::string positionName = "u_SpotLights[" + iStr + "].Position";
      renderer.SetUniform4fv(m_ProgramID, positionName.c_str(), spotLight->GetPosition());

      std::string directionName = "u_SpotLights[" + iStr + "].Direction";
      renderer.SetUniform4fv(m_ProgramID, directionName.c_str(), spotLight->GetDirection());

      std::string ambientName = "u_SpotLights[" + iStr + "].AmbientColor";
      renderer.SetUniform4fv(m_ProgramID, ambientName.c_str(), spotLight->GetAmbientColor());

      std::string diffuseName = "u_SpotLights[" + iStr + "].DiffuseColor";
      renderer.SetUniform4fv(m_ProgramID, diffuseName.c_str(), spotLight->GetDiffuseColor());

      std::string specularName = "u_SpotLights[" + iStr + "].SpecularColor";
      renderer.SetUniform4fv(m_ProgramID, specularName.c_str(), spotLight->GetSpecularColor());

      std::string constantName = "u_SpotLights[" + iStr + "].ConstantS";
      renderer.SetUniform1f(m_ProgramID, constantName.c_str(), spotLight->GetConstant());

      std::string linearName = "u_SpotLights[" + iStr + "].LinearS";
      renderer.SetUniform1f(m_ProgramID, linearName.c_str(), spotLight->GetLinear());

      std::string quadraticName = "u_SpotLights[" + iStr + "].QuadraticS";
      renderer.SetUniform1f(m_ProgramID, quadraticName.c_str(), spotLight->GetQuadratic());

      std::string innerCutoffName = "u_SpotLights[" + iStr + "].InnerCuttof";
      renderer.SetUniform1f(m_ProgramID, innerCutoffName.c_str(), spotLight->GetInnerCutoff());

      std::string outerCutoffName = "u_SpotLights[" + iStr + "].OuterCutoff";
      renderer.SetUniform1f(m_ProgramID, outerCutoffName.c_str(), spotLight->GetOuterCutoff());
    }
  }

  void VisualizationShader::_Setup()
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniform1i(m_ProgramID, "u_AmbientTexture", 0);
    renderer.SetUniform1i(m_ProgramID, "u_DiffuseTexture", 3);
    renderer.SetUniform1i(m_ProgramID, "u_SpecularTexture", 6);
  }
} // namespace DataGarden
