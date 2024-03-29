#ifndef DATA_GARDEN_UI_SHADER
#define DATA_GARDEN_UI_SHADER

#include "DataGarden.h"

#include "core/renderer/Shader.h"

namespace DataGarden
{
  class UIShader : Shader
  {
  public:
    UIShader(ShaderType shaderType);
    ~UIShader();

  private:
    void _Setup();
  };
} // namespace DataGarden

#endif
