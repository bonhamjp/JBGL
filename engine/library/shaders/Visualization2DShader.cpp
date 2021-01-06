#include "Visualization2DShader.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

namespace DataGarden
{
  Visualization2DShader::Visualization2DShader(const ShaderVertexSource vertexSource, const ShaderFragmentSource fragmentSource) : Shader(vertexSource, fragmentSource)
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
