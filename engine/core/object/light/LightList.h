#ifndef DATA_GARDEN_LIGHT_LIST
#define DATA_GARDEN_LIGHT_LIST

#include "DataGarden.h"

#include "Light.h"

#define MAX_LIGHT_COUNT 16

namespace DataGarden
{
  struct LightListOfType
  {
    unsigned int LightCount;
    Light** Lights;
  };

  class LightList
  {
  public:
    LightList();
    virtual ~LightList();

    void PushLightOfType(LightType lightType, Light* light);
    void PopLightOfType(LightType lightType);

    void ClearLights();
    void DeleteLightOfTypeAtIndex(LightType, unsigned int index);

    unsigned int GetLightLengthOfType(LightType lightType);
    LightListOfType GetLightListOfType(LightType lightType);

    bool NeedsToUpdateRendererLightUniforms();
    void UpdateRendererLightUniforms();

    void CleanDirtyLists();
    
  private:
    unsigned int m_PointLightCount = 0;
    bool m_PointLightDirty;
    Light* m_PointLights[MAX_LIGHT_COUNT];

    unsigned int m_DirectionLightCount = 0;
    bool m_DirectionLightDirty;
    Light* m_DirectionLights[MAX_LIGHT_COUNT];

    unsigned int m_SpotLightCount = 0;
    bool m_SpotLightDirty;
    Light* m_SpotLights[MAX_LIGHT_COUNT];

    void _MakeLightTypeClean(LightType lightType);
    void _MakeAllLightsClean();

    void _MakeLightTypeDirty(LightType lightType);
    void _MakeAllLightsDirty();

    void _Setup();
    void _Teardown();
  };
}

#endif
