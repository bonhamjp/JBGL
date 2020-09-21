#include "DataGarden.h"

#include "ShaderParser.h"

#include "resources/shaders/VertexBase.h"
#include "resources/shaders/FragmentBase.h"

#include <iostream>

namespace DataGarden
{
	ShaderSource ShaderParser::RetrieveShaders(const ShaderVertexSource vertexSource, const ShaderFragmentSource fragmentSource)
	{
    std::string vertexSourceString = _RetrieveVertexShader(vertexSource);
    std::string fragmentSourceString = _RetrieveFragmentShader(fragmentSource);

    return ShaderSource{ vertexSourceString, fragmentSourceString };
	}

  std::string ShaderParser::_RetrieveVertexShader(const ShaderVertexSource vertexSource)
  {
    switch(vertexSource) {
      case ShaderVertexSource::BASE:
        return BASE_VERTEX_SHADER_SOURCE;
        break;

    }

    return "";
  }

  std::string ShaderParser::_RetrieveFragmentShader(const ShaderFragmentSource fragmentSource)
  {
    switch(fragmentSource) {
      case ShaderFragmentSource::BASE:
        return BASE_FRAGMENT_SHADER_SOURCE;
        break;

    }

    return "";
  }
}
