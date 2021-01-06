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

    void PushUi(UI *ui);

    inline Camera *Get3DCamera() { return m_3DCamera; };
    void Set3DCamera(Camera *camera);

    inline Camera *Get2DCamera() { return m_2DCamera; };
    void Set2DCamera(Camera *camera);

  protected:
    // TODO: Extract UI management into class
    unsigned int m_UI_Count;
    UI *m_UIS[MAX_UI_COUNT];

    LightList *m_LightList;

    NodeGraph *m_NodeGraph;

    Camera *m_3DCamera;
    Camera *m_2DCamera;

  private:
    void _Update3DScene();
    void _Update2DScene();
    void _UpdateUIs();

    void _Render3DScene();
    void _Render2DScene();
    void _RenderUIs();

    void _DeleteCameras();

    void _SetupScene();
    void _TeardownScene();
  };
} // namespace DataGarden

#endif
