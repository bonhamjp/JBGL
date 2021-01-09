#ifndef DATA_GARDEN_SCENE
#define DATA_GARDEN_SCENE

#include "DataGarden.h"

#include "core/ui/UI.h"

#include "core/object/light/LightList.h"
#include "core/object/node/NodeGraph.h"
#include "core/object/camera/Camera.h"

#define MAX_UI_COUNT 8

namespace DataGarden
{
  enum class RenderMode
  {
    THREE_DIMENSIONS = 0,
    TWO_DIMENSIONS
  };

  enum class MainShader
  {
    LIGHTING = 0,
    FLAT
  };

  class Scene
  {
  public:
    Scene();
    virtual ~Scene();

    virtual void PreUpdate() = 0;
    void Update();
    virtual void PostUpdate() = 0;

    virtual void PreRender() = 0;
    void Render();
    virtual void PostRender() = 0;

    RenderMode GetRenderMode() { return m_RenderMode; };
    inline void SetRenderMode(RenderMode renderMode) { m_RenderMode = renderMode; };

    MainShader GetMainShader() { return m_MainShader; };
    inline void SetMainShader(MainShader mainShader) { m_MainShader = mainShader; };

    void PushUi(UI *ui);

    inline Camera *Get3DCamera() { return m_3DCamera; };
    void Set3DCamera(Camera *camera);

    inline Camera *Get2DCamera() { return m_2DCamera; };
    void Set2DCamera(Camera *camera);

  protected:
    RenderMode m_RenderMode;
    MainShader m_MainShader;

    // TODO: Move UI management to a specific place
    unsigned int m_UI_Count;
    UI *m_UIS[MAX_UI_COUNT];

    LightList *m_LightList;

    NodeGraph *m_NodeGraph;

    // TODO: Move Overlay management to a specific place

    // TODO: Move camera management to a specific place
    Camera *m_3DCamera;
    Camera *m_2DCamera;

  private:
    void _UpdateScene();
    void _UpdateUIs();

    void _RenderScene();
    void _RenderUIs();

    void _DeleteCameras();

    void _SetupScene();
    void _TeardownScene();
  };
} // namespace DataGarden

#endif
