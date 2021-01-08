#ifndef DATA_GARDEN_GRID_SHADER
#define DATA_GARDEN_GRID_SHADER

#include "DataGarden.h"

#include "core/renderer/Shader.h"

namespace DataGarden
{
  class GridShader : Shader
  {
  public:
    GridShader(ShaderType shaderType);
    ~GridShader();

  private:
    void _Setup();
  };
} // namespace DataGarden

#endif
