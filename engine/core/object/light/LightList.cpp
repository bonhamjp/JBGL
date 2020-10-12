#include "LightList.h"

#include "core/Engine.h"

namespace DataGarden
{
  LightList::LightList()
  {
    _MakeAllLightsClean();

    _Setup();
  }
  
  LightList::~LightList()
  {
    _Teardown();
  }
  
  void LightList::PushLightOfType(LightType lightType, Light* light)
  {
    switch(lightType) 
    {
      case LightType::Point:
        m_PointLights[m_PointLightCount++] = light;

        _MakeLightTypeDirty(lightType);
        break;
      
      case LightType::Direction:
        m_DirectionLights[m_DirectionLightCount++] = light;

        _MakeLightTypeDirty(lightType);
        break;

      case LightType::Spot:
        m_SpotLights[m_SpotLightCount++] = light;

        _MakeLightTypeDirty(lightType);
        break;
    }
  }

  void LightList::ClearLights()
  {
    
  }

  void LightList::DeleteLightOfTypeAtIndex(LightType lightType, unsigned int childIndex)
  {
    switch(lightType) 
    {
      case LightType::Point:
        delete m_PointLights[childIndex];

        for (int i = childIndex; i < m_PointLightCount - 1; i++)
        {
          m_PointLights[i] = m_PointLights[i + 1];
        }

        m_PointLightCount--;

        _MakeLightTypeDirty(lightType);
        break;
      
      case LightType::Direction:
        delete m_DirectionLights[childIndex];

        for (int i = childIndex; i < m_DirectionLightCount - 1; i++)
        {
          m_DirectionLights[i] = m_DirectionLights[i + 1];
        }

        m_DirectionLightCount--;

        _MakeLightTypeDirty(lightType);
        break;

      case LightType::Spot:
        delete m_SpotLights[childIndex];

        for (int i = childIndex; i < m_SpotLightCount - 1; i++)
        {
          m_SpotLights[i] = m_SpotLights[i + 1];
        }

        m_SpotLightCount--;

        _MakeLightTypeDirty(lightType);
        break;
    }
  }

  unsigned int LightList::GetLightLengthOfType(LightType lightType)
  {
    switch(lightType) 
    {
      case LightType::Point:
        return m_PointLightCount;
        break;
      
      case LightType::Direction:
        return m_DirectionLightCount;
        break;

      case LightType::Spot:
        return m_SpotLightCount;
        break;
    }

    return 0;
  }

  LightListOfType LightList::GetLightListOfType(LightType lightType)
  {
    switch(lightType) 
    {
      case LightType::Point:
        return LightListOfType { m_PointLightCount, m_PointLights };
        break;
      
      case LightType::Direction:
        return LightListOfType { m_DirectionLightCount, m_DirectionLights };
        break;

      case LightType::Spot:
        return LightListOfType { m_SpotLightCount, m_SpotLights };
        break;
    }

    return { 0, nullptr };
  }

  bool LightList::NeedsToUpdateRendererLightUniforms()
  {
    return m_PointLightDirty || m_DirectionLightDirty || m_SpotLightDirty;
  }

  void LightList::UpdateRendererLightUniforms()
  {
    
  }

  void LightList::CleanDirtyLists()
  {
    _MakeAllLightsClean();
  }

  void LightList::_MakeLightTypeClean(LightType lightType)
  {
    switch(lightType) 
    {
      case LightType::Point:
        m_PointLightDirty = false;
        break;
      
      case LightType::Direction:
        m_DirectionLightDirty = false;
        break;

      case LightType::Spot:
        m_SpotLightDirty = false;
        break;
    }
  }

  void LightList::_MakeAllLightsClean()
  {
    m_PointLightDirty = false;
    m_DirectionLightDirty = false;
    m_SpotLightDirty = false;
  }

    void LightList::_MakeLightTypeDirty(LightType lightType)
  {
    switch(lightType) {
      case LightType::Point:
        m_PointLightDirty = true;
        break;
      
      case LightType::Direction:
        m_DirectionLightDirty = true;
        break;

      case LightType::Spot:
        m_SpotLightDirty = true;
        break;
    }
  }

  void LightList::_MakeAllLightsDirty()
  {
    m_PointLightDirty = true;
    m_DirectionLightDirty = true;
    m_SpotLightDirty = true;
  }

  void LightList::_Setup()
  {}

  void LightList::_Teardown()
  {
    // TODO: Free all lights
  }
}
