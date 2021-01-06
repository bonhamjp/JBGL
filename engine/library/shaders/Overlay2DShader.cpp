#include "Overlay2DShader.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

namespace DataGarden
{
  Overlay2DShader::Overlay2DShader(const ShaderVertexSource vertexSource, const ShaderFragmentSource fragmentSource) : Shader(vertexSource, fragmentSource)
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
