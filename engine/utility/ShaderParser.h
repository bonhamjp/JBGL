#ifndef DATA_GARDEN_SHADER_PARSER
#define DATA_GARDEN_SHADER_PARSER

#include "DataGarden.h"

#include <string>

namespace DataGarden
{
	enum class ShaderSourceType
	{
		VERTEX = 0,
		FRAGMENT = 1
	};

  enum class ShaderVertexSource
  {
    BASE = 0
  };

  enum class ShaderFragmentSource
  {
    BASE = 0
  };
	
	struct ShaderSource
	{
		std::string vertexSource;
		std::string fragmentSource;
	};
	
	class ShaderParser
	{
	public:
		static ShaderSource RetrieveShaders(const ShaderVertexSource vertexSource, const ShaderFragmentSource fragmentSource);

  private:
    static std::string _RetrieveVertexShader(const ShaderVertexSource vertexSource);
    static std::string _RetrieveFragmentShader(const ShaderFragmentSource fragmentSource);
	};
}

#endif
