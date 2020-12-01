#include "LightList.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "library/lights/PointLight.h"
#include "library/lights/DirectionalLight.h"
#include "library/lights/SpotLight.h"

#include <iostream>

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
      
      case LightType::Directional:
        m_DirectionalLights[m_DirectionalLightCount++] = light;

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
      
      case LightType::Directional:
        delete m_DirectionalLights[childIndex];

        for (int i = childIndex; i < m_DirectionalLightCount - 1; i++)
        {
          m_DirectionalLights[i] = m_DirectionalLights[i + 1];
        }

        m_DirectionalLightCount--;

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
      
      case LightType::Directional:
        return m_DirectionalLightCount;
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
      
      case LightType::Directional:
        return LightListOfType { m_DirectionalLightCount, m_DirectionalLights };
        break;

      case LightType::Spot:
        return LightListOfType { m_SpotLightCount, m_SpotLights };
        break;
    }

    return { 0, nullptr };
  }

  void LightList::UpdateRendererLightUniforms()
  {
    if (m_PointLightDirty)
    {
      _UpdateRendererPointLightUniforms();
      _MakeLightTypeClean(LightType::Point);
    }

    if (m_DirectionalLightDirty)
    {
      _UpdateRendererDirectionalLightUniforms();
      _MakeLightTypeClean(LightType::Directional);
    }

    if (m_SpotLightDirty)
    {
      _UpdateRendererSpotLightUniforms();
      _MakeLightTypeClean(LightType::Spot);
    }
  }

  void LightList::_UpdateRendererPointLightUniforms()
  {
    UpdatePointLightUniforms(GetLightListOfType(LightType::Point));
  }

  void LightList::_UpdateRendererDirectionalLightUniforms()
  {
    UpdateDirectionalLightUniforms(GetLightListOfType(LightType::Directional));
  }

  void LightList::_UpdateRendererSpotLightUniforms()
  {
    UpdateSpotLightUniforms(GetLightListOfType(LightType::Spot));
  }

  void LightList::_MakeLightTypeClean(LightType lightType)
  {
    switch(lightType) 
    {
      case LightType::Point:
        m_PointLightDirty = false;
        break;
      
      case LightType::Directional:
        m_DirectionalLightDirty = false;
        break;

      case LightType::Spot:
        m_SpotLightDirty = false;
        break;
    }
  }

  void LightList::_MakeAllLightsClean()
  {
    m_PointLightDirty = false;
    m_DirectionalLightDirty = false;
    m_SpotLightDirty = false;
  }

    void LightList::_MakeLightTypeDirty(LightType lightType)
  {
    switch(lightType) {
      case LightType::Point:
        m_PointLightDirty = true;
        break;
      
      case LightType::Directional:
        m_DirectionalLightDirty = true;
        break;

      case LightType::Spot:
        m_SpotLightDirty = true;
        break;
    }
  }

  void LightList::_MakeAllLightsDirty()
  {
    m_PointLightDirty = true;
    m_DirectionalLightDirty = true;
    m_SpotLightDirty = true;
  }

  void LightList::_Setup()
  {}

  void LightList::_Teardown()
  {
    // TODO: Free all lights
  }
}
