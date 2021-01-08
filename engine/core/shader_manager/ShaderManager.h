#ifndef DATA_GARDEN_SHADER_MANAGER
#define DATA_GARDEN_SHADER_MANAGER

#include "DataGarden.h"

#include "library/shaders/VisualizationShader.h"
#include "library/shaders/GridShader.h"
#include "library/shaders/UIShader.h"

namespace DataGarden
{
  class ShaderManager
  {
  public:
    ShaderManager();
    ~ShaderManager();

    inline VisualizationShader *GetVisualizationShader() { return m_VisualizationShader; };
    inline GridShader *GetGridShader() { return m_GridShader; };
    inline UIShader *GetUIShader() { return m_UIShader; };

  private:
    VisualizationShader *m_VisualizationShader;
    GridShader *m_GridShader;
    UIShader *m_UIShader;

    void _Setup();
    void _Teardown();
  };
} // namespace DataGarden

#endif
