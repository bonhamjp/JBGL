#ifndef DATA_GARDEN_SHADER_PARSER
#define DATA_GARDEN_SHADER_PARSER

#include "DataGarden.h"

#include <string>

namespace DataGarden
{
  enum class ShaderType
  {
    VISUALIZATION = 0,
    GRID,
    UI
  };

  struct ShaderSource
  {
    std::string vertexSource;
    std::string fragmentSource;
  };

  class ShaderParser
  {
  public:
    static ShaderSource RetrieveShaders(ShaderType shaderType);

  private:
    static std::string _RetrieveVertexShader(ShaderType shaderType);
    static std::string _RetrieveFragmentShader(ShaderType shaderType);
  };
} // namespace DataGarden

#endif
