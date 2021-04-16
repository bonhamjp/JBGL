#ifndef DATA_GARDEN_UI_LIST
#define DATA_GARDEN_UI_LIST

#include "UI.h"

#define MAX_UI_COUNT 32

namespace DataGarden
{
  class UIList
  {
  public:
    UIList();
    ~UIList();

    void Update();
    void Render();

    void PushUI(UI *ui);
    bool DeleteUI(UI *ui);

  private:
    unsigned int m_UICount = 0;
    UI *m_UIs[MAX_UI_COUNT];

    void _Setup();
    void _Teardown();
  };
} // namespace DataGarden

#endif
