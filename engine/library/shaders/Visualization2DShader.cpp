#include "Visualization2DShader.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

namespace DataGarden
{
  Visualization2DShader::Visualization2DShader(ShaderType shaderType) : Shader(shaderType)
  {
    _Setup();
  }

  Visualization2DShader::~Visualization2DShader()
  {
  }

  void Visualization2DShader::_Setup()
  {
  }
} // namespace DataGarden
