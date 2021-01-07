#include "Overlay2DShader.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

namespace DataGarden
{
  Overlay2DShader::Overlay2DShader(ShaderType shaderType) : Shader(shaderType)
  {
    _Setup();
  }

  Overlay2DShader::~Overlay2DShader()
  {
  }

  void Overlay2DShader::_Setup()
  {
  }
} // namespace DataGarden
