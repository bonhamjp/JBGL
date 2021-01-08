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
    m_VisualizationShader = new VisualizationShader(ShaderType::VISUALIZATION);
    m_GridShader = new GridShader(ShaderType::GRID);
    m_UIShader = new UIShader(ShaderType::UI);
  }

  void ShaderManager::_Teardown()
  {
    delete m_VisualizationShader;
    delete m_GridShader;
    delete m_UIShader;
  }
} // namespace DataGarden
