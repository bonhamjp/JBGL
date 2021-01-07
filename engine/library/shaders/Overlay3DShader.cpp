#include "Overlay3DShader.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

namespace DataGarden
{
  Overlay3DShader::Overlay3DShader(ShaderType shaderType) : Shader(shaderType)
  {
    _Setup();
  }

  Overlay3DShader::~Overlay3DShader()
  {
  }

  void Overlay3DShader::_Setup()
  {
  }
} // namespace DataGarden
