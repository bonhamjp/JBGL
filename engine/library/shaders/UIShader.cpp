#include "UIShader.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

namespace DataGarden
{
  UIShader::UIShader(ShaderType shaderType) : Shader(shaderType)
  {
    _Setup();
  }

  UIShader::~UIShader()
  {
  }

  void UIShader::_Setup()
  {
  }
} // namespace DataGarden
