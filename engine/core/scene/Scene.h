#ifndef DATA_GARDEN_SCENE
#define DATA_GARDEN_SCENE

#include "DataGarden.h"

#include "core/ui/UIList.h"

#include "core/grid/Grid.h"

#include "core/object/light/LightList.h"
#include "core/object/node/NodeGraph.h"
#include "core/object/camera/Camera.h"

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

    inline UIList *GetUIList() { return m_UIList; };

    inline Grid *GetGrid() { return m_Grid; };
    void SetGrid(Grid *grid);

    inline Camera *Get3DCamera() { return m_3DCamera; };
    void Set3DCamera(Camera *camera);

    inline Camera *Get2DCamera() { return m_2DCamera; };
    void Set2DCamera(Camera *camera);

  protected:
    RenderMode m_RenderMode;
    MainShader m_MainShader;

    UIList *m_UIList;

    Grid* m_Grid;

    LightList *m_LightList;

    NodeGraph *m_NodeGraph;

    Camera *m_3DCamera;
    Camera *m_2DCamera;

  private:
    void _UpdateGrid();
    void _UpdateVisualization();
    void _UpdateUIList();

    void _RenderGrid();
    void _RenderVisualization();
    void _RenderUIList();

    void _DeleteCameras();

    void _SetupScene();
    void _TeardownScene();
  };
} // namespace DataGarden

#endif
