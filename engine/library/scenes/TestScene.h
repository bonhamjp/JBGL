#ifndef DATA_GARDEN_TEST_SCENE
#define DATA_GARDEN_TEST_SCENE

#include "DataGarden.h"

#include "core/scene/Scene.h"

namespace DataGarden
{
class TestScene : public Scene
{
  public:
    TestScene();
    virtual ~TestScene();

    virtual void PreUpdate() override;
    virtual void PostUpdate() override;

    virtual void PreRender() override;
    virtual void PostRender() override;

  protected:

  };
}

#endif
