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
    m_Visualization3DShader = new Visualization3DShader(ShaderVertexSource::BASE, ShaderFragmentSource::BASE);
  }

  void ShaderManager::_Teardown()
  {
    delete m_Visualization3DShader;
  }
} // namespace DataGarden
