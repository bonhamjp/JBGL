#include "ShaderManager.h"

namespace DataGarden
{
  ShaderManager::ShaderManager()
  {
    _Setup();
  }

  ShaderManager::~ShaderManager()
  {
    _Teardown();
  }

  void ShaderManager::_Setup()
  {
    m_Visualization3DShader = new Visualization3DShader(ShaderType::VISUALIZATION_3D);
    m_Overlay3DShader = new Overlay3DShader(ShaderType::OVERLAY_3D);
    m_Visualization2DShader = new Visualization2DShader(ShaderType::VISUALIZATION_2D);
    m_Overlay2DShader = new Overlay2DShader(ShaderType::OVERLAY_2D);
    m_UIShader = new UIShader(ShaderType::UI);
  }

  void ShaderManager::_Teardown()
  {
    delete m_Visualization3DShader;
  }
} // namespace DataGarden
