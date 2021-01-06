#include "Overlay3DShader.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

namespace DataGarden
{
  Overlay3DShader::Overlay3DShader(const ShaderVertexSource vertexSource, const ShaderFragmentSource fragmentSource) : Shader(vertexSource, fragmentSource)
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
