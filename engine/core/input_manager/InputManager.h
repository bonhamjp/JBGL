#ifndef DATA_GARDEN_INPUT_MANAGER
#define DATA_GARDEN_INPUT_MANAGER

#include "DataGarden.h"

namespace DataGarden
{
  struct InputFrame
  {
    int mouseX;
    int mouseY;
    int mouseXDelta;
    int mouseYDelta;
    bool mouseLeftPressed;
    bool mouseRightPressed;
    bool mouseMiddlePressed;
    // TODO: More efficient keys pressed encoding- use bitmask, 8 bit would probably suffice for simple controls, or 32 if needed
    bool upPressed;
    bool downPressed;
    bool leftPressed;
    bool rightPressed;
    bool spaceBarPressed;
    bool qPressed;
    bool ePressed;
    bool mPressed;
  };

  class InputManager
  {
  public:
    InputManager();
    ~InputManager();

    void MouseMove(int mouseX, int mouseY);
    int GetDeltaMouseX();
    int GetDeltaMouseY();
    std::pair<int, int> GetDeltaMouseCoords();
    void MousePressed(int clickType);
    void MouseUp(int clickType);

    void KeyDown(int keyCode);
    void KeyUp(int keyCode);

    void Clear();

    bool IsKeyDown(int keyCode);
    bool IsKeyPressed(int keyCode);
    bool IsMouseButtonPressed(int button);
    // std::pair<float, float> GetMousePosition();
    // float GetMouseX();
    // float GetMouseDeltaX();
    // float GetMouseY();
    // float GetMouseDeltaY();

    inline InputFrame &GerInputFrame() { return m_CurrentFrame; }

  private:
    InputFrame m_PreviousFrame;
    InputFrame m_CurrentFrame;

    void _Setup();
    void _Teardown();
  };
} // namespace DataGarden

#endif
