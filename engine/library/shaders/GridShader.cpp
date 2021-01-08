#include "GridShader.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

namespace DataGarden
{
  GridShader::GridShader(ShaderType shaderType) : Shader(shaderType)
  {
    _Setup();
  }

  GridShader::~GridShader()
  {
  }

  void GridShader::_Setup()
  {
  }
} // namespace DataGarden
