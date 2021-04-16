#ifndef DATA_GARDEN_GRID_SHADER
#define DATA_GARDEN_GRID_SHADER

#include "DataGarden.h"

#include "core/renderer/Shader.h"

#include <glm/glm.hpp>

namespace DataGarden
{
  class GridShader : public Shader
  {
  public:
    GridShader(ShaderType shaderType);
    ~GridShader();

    void SetViewProjectionUniform(glm::mat4 viewProjection);
    void SetViewPositionUniform(glm::vec3 viewPosition);

    void SetModelUniform(glm::mat4 model);

    void SetPrimaryColorUniform(glm::vec3 color);
    void SetSecondaryColorUniform(glm::vec3 color);

  private:
    void _Setup();
  };
} // namespace DataGarden

#endif
