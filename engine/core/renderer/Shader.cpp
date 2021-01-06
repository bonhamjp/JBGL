#include <iostream>

#include "Shader.h"
#include "Renderer.h"

#include "core/Engine.h"

namespace DataGarden
{
  Shader::Shader(const ShaderVertexSource vertexSource, const ShaderFragmentSource fragmentSource)
  {
    Renderer &renderer = Engine::Get().GetRenderer();

    ShaderSource shaderSource = ShaderParser::RetrieveShaders(vertexSource, fragmentSource);

    unsigned int vertexShaderID = _CompileVertexShader(shaderSource.vertexSource);
    unsigned int fragmentShaderID = _CompileFragmentShader(shaderSource.fragmentSource);

    m_ProgramID = renderer.CreateProgram();

    renderer.AttachShader(m_ProgramID, vertexShaderID);
    renderer.AttachShader(m_ProgramID, fragmentShaderID);

    renderer.LinkProgram(m_ProgramID);

    renderer.DeleteShader(vertexShaderID);
    renderer.DeleteShader(fragmentShaderID);

    renderer.UseProgram(m_ProgramID);
  }

  Shader::~Shader()
  {
    Engine::Get().GetRenderer().DeleteProgram(m_ProgramID);
  }

  void Shader::Bind()
  {
    Engine::Get().GetRenderer().UseProgram(m_ProgramID);
  }

  void Shader::Unbind()
  {
    Engine::Get().GetRenderer().UseProgram(0);
  }

  unsigned int Shader::_CompileVertexShader(const std::string &shaderSource)
  {
    Renderer &renderer = Engine::Get().GetRenderer();

    unsigned int id = renderer.CreateVertexShader();
    const char *src = shaderSource.c_str();

    renderer.ShaderSource(id, shaderSource);
    renderer.CompileShader(id);

    return id;
  }

  unsigned int Shader::_CompileFragmentShader(const std::string &shaderSource)
  {
    Renderer &renderer = Engine::Get().GetRenderer();

    unsigned int id = renderer.CreateFragmentShader();
    const char *src = shaderSource.c_str();

    renderer.ShaderSource(id, shaderSource);
    renderer.CompileShader(id);

    return id;
  }
} // namespace DataGarden
