#include "UIShader.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

namespace DataGarden
{
  UIShader::UIShader(const ShaderVertexSource vertexSource, const ShaderFragmentSource fragmentSource) : Shader(vertexSource, fragmentSource)
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
