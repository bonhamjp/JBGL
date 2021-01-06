#ifndef DATA_GARDEN_SHADER_MANAGER
#define DATA_GARDEN_SHADER_MANAGER

#include "DataGarden.h"

#include "library/shaders/Visualization3DShader.h"
#include "library/shaders/Overlay3DShader.h"
#include "library/shaders/Visualization2DShader.h"
#include "library/shaders/Overlay2DShader.h"
#include "library/shaders/UIShader.h"

namespace DataGarden
{
  class ShaderManager
  {
  public:
    ShaderManager();
    ~ShaderManager();

    inline Visualization3DShader *GetVisualization3DShader() { return m_Visualization3DShader; };
    inline Overlay3DShader *GetOverlay3DShader() { return m_Overlay3DShader; };

  private:
    Visualization3DShader *m_Visualization3DShader;
    Overlay3DShader *m_Overlay3DShader;
    Visualization2DShader *m_Visualization2DShader;
    Overlay2DShader *m_Overlay2DShader;
    UIShader *m_UIShader;

    void _Setup();
    void _Teardown();
  };
} // namespace DataGarden

#endif
