#ifndef DATA_GARDEN_INPUT_INTERFACE_EVENT_HANDLERS
#define DATA_GARDEN_INPUT_INTERFACE_EVENT_HANDLERS

#include <iostream>

#include <emscripten.h>

#include "core/Engine.h"

// exported for use in javascript
extern "C"
{
  void onKeyUp(int charCode)
  {
    DataGarden::Engine::Get().GetInputManager().KeyUp(charCode);
  }

  void onKeyDown(int charCode)
  {
    DataGarden::Engine::Get().GetInputManager().KeyDown(charCode);
  }

  void onMouseDown(int clickType)
  {
    DataGarden::Engine::Get().GetInputManager().MousePressed(clickType);
  }

  void onMouseUp(int clickType)
  {
    DataGarden::Engine::Get().GetInputManager().MouseUp(clickType);
  }

  void onMouseEnter()
  {}

  void onMouseLeave()
  {}

  void onMouseMove(int mouseX, int mouseY)
  {
    DataGarden::Engine::Get().GetInputManager().MouseMoved(mouseX, mouseY);
  }
}

#endif
