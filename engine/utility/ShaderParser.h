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

  enum class ShaderType
  {
    VISUALIZATION_3D = 0,
    OVERLAY_3D,
    VISUALIZATION_2D,
    OVERLAY_2D,
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
