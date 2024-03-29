#ifndef DATA_GARDEN_VISUALIZATION_SHADER
#define DATA_GARDEN_VISUALIZATION_SHADER

#include "DataGarden.h"

#include "core/renderer/Shader.h"

#include "core/object/light/LightList.h"

#include <glm/glm.hpp>

namespace DataGarden
{
  class VisualizationShader : public Shader
  {
  public:
    VisualizationShader(ShaderType shaderType);
    ~VisualizationShader();

    void SetViewProjectionUniform(glm::mat4 viewProjection);
    void SetViewPositionUniform(glm::vec3 viewPosition);

    void SetModelUniform(glm::mat4 model);

    void SetMaterialShininessUniform(float shininess);

    void SetAmbientTexturesUniform(int ambientTextures);
    void SetDiffuseTexturesUniform(int diffuseTextures);
    void SetSpecularTexturesUniform(int specularTextures);

    // TODO: Make these uniform lookups more efficient
    void SetDirectionalLightUniforms(LightListOfType directionalLightList);
    void SetPointLightUniforms(LightListOfType pointLightList);
    void SetSpotLightUniforms(LightListOfType spotLightList);

  private:
    void _Setup();
  };
} // namespace DataGarden

#endif
