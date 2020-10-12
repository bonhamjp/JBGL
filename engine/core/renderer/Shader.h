#ifndef DATA_GARDEN_SHADER
#define DATA_GARDEN_SHADER

#include "DataGarden.h"

#include "utility/ShaderParser.h"

namespace DataGarden
{
	class Shader
	{
	public:
		Shader(const ShaderVertexSource vertexSource, const ShaderFragmentSource fragmentSource);
		~Shader();

		void Bind();
		void Unbind();

		inline unsigned int GetProgramID() { return m_ProgramID; };
  
  private:
    unsigned int m_ProgramID;

		unsigned int _CompileVertexShader(const std::string& shaderSource);
		unsigned int _CompileFragmentShader(const std::string& shaderSource);
	};
}

#endif
