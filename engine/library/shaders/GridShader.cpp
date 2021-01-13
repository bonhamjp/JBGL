#include "GridShader.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

namespace DataGarden
{
  GridShader::GridShader(ShaderType shaderType) : Shader(shaderType)
  {
    _Setup();
  }

  GridShader::~GridShader()
  {
  }

  void GridShader::SetViewProjectionUniform(glm::mat4 viewProjection)
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniformMatrix4fv(m_ProgramID, "u_ViewProjection", viewProjection);
  }

  void GridShader::SetViewPositionUniform(glm::vec3 viewPosition)
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniform3fv(m_ProgramID, "u_ViewPosition", viewPosition);
  }

  void GridShader::SetModelUniform(glm::mat4 model)
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniformMatrix4fv(m_ProgramID, "u_Vertex.Model", model);
  }

  void GridShader::SetColorUniform(glm::vec3 color)
  {
    Renderer &renderer = Engine::Get().GetRenderer();
    renderer.SetUniform3fv(m_ProgramID, "u_Color", color);
  }

  void GridShader::_Setup()
  {
  }
} // namespace DataGarden
