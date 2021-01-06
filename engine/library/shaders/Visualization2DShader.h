#ifndef DATA_GARDEN_VISUALIZATION_2D_SHADER
#define DATA_GARDEN_VISUALIZATION_2D_SHADER

#include "DataGarden.h"

#include "core/renderer/Shader.h"

namespace DataGarden
{
  class Visualization2DShader : Shader
  {
  public:
    Visualization2DShader(const ShaderVertexSource vertexSource, const ShaderFragmentSource fragmentSource);
    ~Visualization2DShader();

  private:
    void _Setup();
  };
} // namespace DataGarden

#endif
