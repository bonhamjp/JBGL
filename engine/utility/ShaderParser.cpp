#include "DataGarden.h"

#include "ShaderParser.h"

#include "resources/shaders/VisualizationVertexShaderSource.h"
#include "resources/shaders/VisualizationFragmentShaderSource.h"
#include "resources/shaders/GridVertexShaderSource.h"
#include "resources/shaders/GridFragmentShaderSource.h"
#include "resources/shaders/UIVertexShaderSource.h"
#include "resources/shaders/UIFragmentShaderSource.h"

#include <iostream>

namespace DataGarden
{
  ShaderSource ShaderParser::RetrieveShaders(ShaderType shaderType)
  {
    std::string vertexSourceString = _RetrieveVertexShader(shaderType);
    std::string fragmentSourceString = _RetrieveFragmentShader(shaderType);

    return ShaderSource{vertexSourceString, fragmentSourceString};
  }

  std::string ShaderParser::_RetrieveVertexShader(ShaderType shaderType)
  {
    switch (shaderType)
    {
    case ShaderType::VISUALIZATION:
      return VISUALIZATION_VERTEX_SHADER_SOURCE;
      break;

    case ShaderType::GRID:
      return GRID_VERTEX_SHADER_SOURCE;
      break;

    case ShaderType::UI:
      return UI_VERTEX_SHADER_SOURCE;
      break;
    }

    return "";
  }

  std::string ShaderParser::_RetrieveFragmentShader(ShaderType shaderType)
  {
    switch (shaderType)
    {
    case ShaderType::VISUALIZATION:
      return VISUALIZATION_FRAGMENT_SHADER_SOURCE;
      break;

    case ShaderType::GRID:
      return GRID_FRAGMENT_SHADER_SOURCE;
      break;

    case ShaderType::UI:
      return UI_FRAGMENT_SHADER_SOURCE;
      break;
    }

    return "";
  }
} // namespace DataGarden
