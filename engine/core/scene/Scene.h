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
  // // forward declarations
  // class UI;
  // class LightList;
  // class NodeGraph;

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

    void PushUi(UI* ui);

    inline Camera& GetCamera() { return *m_Camera; };
    void SetCamera(Camera* camera);

  protected:
    unsigned int m_UI_Count;
    UI* m_UIS[MAX_UI_COUNT];

    LightList* m_LightList;
    NodeGraph* m_NodeGraph;
    Camera* m_Camera;

  private:
    void _DeleteCamera();

    void _SetupScene();
    void _TeardownScene();
  };
}

#endif
