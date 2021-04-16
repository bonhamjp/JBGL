#ifndef DATA_GARDEN_MAIN_CONTROLS_UI
#define DATA_GARDEN_MAIN_CONTROLS_UI

#include "DataGarden.h"

#include "core/ui/UI.h"

namespace DataGarden
{
  class MainControlsUI : public UI
  {
  public:
    MainControlsUI();
    virtual ~MainControlsUI();

    virtual void Update() override;
    virtual void Render() override;
  private:
  };
}

#endif
