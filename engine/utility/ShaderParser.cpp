#include "DataGarden.h"

#include "ShaderParser.h"

#include "resources/shaders/Visualization3DVertexShaderSource.h"
#include "resources/shaders/Visualization3DFragmentShaderSource.h"
#include "resources/shaders/Overlay3DVertexShaderSource.h"
#include "resources/shaders/Overlay3DFragmentShaderSource.h"
#include "resources/shaders/Visualization2DVertexShaderSource.h"
#include "resources/shaders/Visualization2DFragmentShaderSource.h"
#include "resources/shaders/Overlay2DVertexShaderSource.h"
#include "resources/shaders/Overlay2DFragmentShaderSource.h"
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
    case ShaderType::VISUALIZATION_3D:
      return VISUALIZATION_3D_VERTEX_SHADER_SOURCE;
      break;

    case ShaderType::OVERLAY_3D:
      return OVERLAY_3D_VERTEX_SHADER_SOURCE;
      break;

    case ShaderType::VISUALIZATION_2D:
      return VISUALIZATION_2D_VERTEX_SHADER_SOURCE;
      break;

    case ShaderType::OVERLAY_2D:
      return OVERLAY_2D_VERTEX_SHADER_SOURCE;
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
    case ShaderType::VISUALIZATION_3D:
      return VISUALIZATION_3D_FRAGMENT_SHADER_SOURCE;
      break;

    case ShaderType::OVERLAY_3D:
      return OVERLAY_3D_FRAGMENT_SHADER_SOURCE;
      break;

    case ShaderType::VISUALIZATION_2D:
      return VISUALIZATION_2D_FRAGMENT_SHADER_SOURCE;
      break;

    case ShaderType::OVERLAY_2D:
      return OVERLAY_2D_FRAGMENT_SHADER_SOURCE;
      break;

    case ShaderType::UI:
      return UI_FRAGMENT_SHADER_SOURCE;
      break;
    }

    return "";
  }
} // namespace DataGarden
