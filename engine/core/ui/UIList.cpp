#include "UIList.h"

#include <assert.h>

namespace DataGarden
{
  UIList::UIList()
  {
    _Setup();
  }

  UIList::~UIList()
  {
    _Teardown();
  }

  void UIList::Update()
  {
    for (unsigned int i = 0; i < m_UICount; i++)
    {
      m_UIs[i]->Update();
    }
  }

  void UIList::Render()
  {
    for (unsigned int i = 0; i < m_UICount; i++)
    {
      m_UIs[i]->Render();
    }
  }

  void UIList::PushUI(UI *ui)
  {
    assert(m_UICount + 1 < MAX_UI_COUNT);

    m_UIs[m_UICount] = ui;
    m_UICount++;
  }

  bool UIList::DeleteUI(UI *ui)
  {
    unsigned int uiIndex = -1;
    for (unsigned int i = 0; i < m_UICount; i++)
    {
      if (ui == m_UIs[i])
      {
        // TODO: End loop if possible when found, maybe with break?
        uiIndex = i;
      }
    }

    if (uiIndex > 0)
    {
      delete m_UIs[uiIndex];
      m_UIs[uiIndex] = nullptr;

      for (unsigned int i = uiIndex + 1; i < m_UICount; i++)
      {
        // shift next UI down one
        m_UIs[i - 1] = m_UIs[i];

        // empty next UI, which will be filled with following ones if present
        delete m_UIs[i];
        m_UIs[i] = nullptr;
      }

      m_UICount--;

      return true;
    }
    else
    {
      return false;
    }
  }

  void UIList::_Setup()
  {
  }

  void UIList::_Teardown()
  {
  }
} // namespace DataGarden
