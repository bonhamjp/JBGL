#include <iostream>

#include "Shader.h"
#include "Renderer.h"

#include "core/Engine.h"

namespace DataGarden
{
  Shader::Shader(const ShaderVertexSource vertexSource, const ShaderFragmentSource fragmentSource)
  {
    Renderer& renderer = Engine::Get().GetRenderer();

		m_ID = renderer.CreateProgram();

		ShaderSource shaderSource = ShaderParser::RetrieveShaders(vertexSource, fragmentSource);

		unsigned int vertexShaderID = _CompileVertexShader(shaderSource.vertexSource);
		unsigned int fragmentShaderID = _CompileFragmentShader(shaderSource.fragmentSource);

		renderer.AttachShader(m_ID, vertexShaderID);
		renderer.AttachShader(m_ID, fragmentShaderID);

		renderer.LinkProgram(m_ID);

		renderer.DeleteShader(vertexShaderID);
		renderer.DeleteShader(fragmentShaderID);
  }

	Shader::~Shader()
	{
		Engine::Get().GetRenderer().DeleteProgram(m_ID);
	}

	void Shader::Bind()
	{
		Engine::Get().GetRenderer().UseProgram(m_ID);
	}

	void Shader::Unbind()
	{
		Engine::Get().GetRenderer().UseProgram(0);
	}

  unsigned int Shader::_CompileVertexShader(const std::string& shaderSource)
	{
		Renderer& renderer = Engine::Get().GetRenderer();

		unsigned int id = renderer.CreateVertexShader();
		const char* src = shaderSource.c_str();

		renderer.ShaderSource(id, shaderSource);
		renderer.CompileShader(id);

		return id;
	}

	unsigned int Shader::_CompileFragmentShader(const std::string& shaderSource)
	{
		Renderer& renderer = Engine::Get().GetRenderer();

		unsigned int id = renderer.CreateFragmentShader();
		const char* src = shaderSource.c_str();

		renderer.ShaderSource(id, shaderSource);
		renderer.CompileShader(id);

		return id;
	}
}
