#ifndef DATA_GARDEN_DEBUG_UI
#define DATA_GARDEN_DEBUG_UI

#include "DataGarden.h"

#include "core/ui/UI.h"

namespace DataGarden
{
  class DebugUI : public UI
  {
  public:
    DebugUI();
    virtual ~DebugUI();

    virtual void Update() override;
    virtual void Render() override;
  private:
  };
}

#endif
