#include <iostream>

#include "InputManager.h"

#include "InputInterface.h"
#include "KeyCodes.h"

namespace DataGarden
{
  void copyInputFrame(InputFrame& inputFrameA, InputFrame& inputFrameB)
  {
    inputFrameA.mouseX = inputFrameB.mouseX;
    inputFrameA.mouseY = inputFrameB.mouseY;
    inputFrameA.mouseLeftPressed = inputFrameB.mouseLeftPressed;
    inputFrameA.mouseRightPressed = inputFrameB.mouseRightPressed;
    inputFrameA.mouseMiddlePressed = inputFrameB.mouseMiddlePressed;
    inputFrameA.upPressed = inputFrameB.upPressed;
    inputFrameA.downPressed = inputFrameB.downPressed;
    inputFrameA.leftPressed = inputFrameB.leftPressed;
    inputFrameA.rightPressed = inputFrameB.rightPressed;
    inputFrameA.spaceBarPressed = inputFrameB.spaceBarPressed;
  }

  void clearInputFrame(InputFrame& inputFrame)
  {
    inputFrame.mouseX = 0;
    inputFrame.mouseY = 0;
    inputFrame.mouseLeftPressed = false;
    inputFrame.mouseRightPressed = false;
    inputFrame.mouseMiddlePressed = false;
    inputFrame.upPressed = false;
    inputFrame.downPressed = false;
    inputFrame.leftPressed = false;
    inputFrame.rightPressed = false;
    inputFrame.spaceBarPressed = false;
  }

  InputManager::InputManager()
	{
    clearInputFrame(m_PreviousFrame);
    clearInputFrame(m_CurrentFrame);
  }

  InputManager::~InputManager()
  {}

  void InputManager::MouseMoved(int mouseX, int mouseY)
  {
    m_CurrentFrame.mouseX = mouseX;
    m_CurrentFrame.mouseY = mouseY;
  }

  std::pair<int, int> InputManager::GetDeltaMouseCoords()
  {
    return { m_CurrentFrame.mouseX - m_PreviousFrame.mouseX, m_CurrentFrame.mouseY - m_PreviousFrame.mouseY };
  }
  
  void InputManager::MousePressed(int clickType)
  {
    // TODO: Make enums for clickType
    switch(clickType) {
      case 1:
        m_CurrentFrame.mouseLeftPressed = true;
        break;

      case 2:
        m_CurrentFrame.mouseRightPressed = true;
        break;

      case 3:
        m_CurrentFrame.mouseMiddlePressed = true;
        break;
    }
  }

  void InputManager::MouseUp(int clickType)
  {
    // TODO: Make enums for clickType
    switch(clickType) {
      case 1:
        m_CurrentFrame.mouseLeftPressed = false;
        break;

      case 2:
        m_CurrentFrame.mouseRightPressed = false;
        break;

      case 3:
        m_CurrentFrame.mouseMiddlePressed = false;
        break;
    }
  }

  void InputManager::KeyDown(int keyCode)
  {
    switch(keyCode) {
      case KEY_UP_CODE:
        m_CurrentFrame.upPressed = true;
        break;

      case KEY_DOWN_CODE:
        m_CurrentFrame.downPressed = true;
        break;

      case KEY_LEFT_CODE:
        m_CurrentFrame.leftPressed = true;
        break;

      case KEY_RIGHT_CODE:
        m_CurrentFrame.rightPressed = true;
        break;

      case KEY_SPACE_BAR_CODE:
        m_CurrentFrame.spaceBarPressed = true;
        break;
    }
  }

  void InputManager::KeyUp(int keyCode)
  {
    switch(keyCode) {
      case KEY_UP_CODE:
        m_CurrentFrame.upPressed = false;
        break;

      case KEY_DOWN_CODE:
        m_CurrentFrame.downPressed = false;
        break;

      case KEY_LEFT_CODE:
        m_CurrentFrame.leftPressed = false;
        break;

      case KEY_RIGHT_CODE:
        m_CurrentFrame.rightPressed = false;
        break;

      case KEY_SPACE_BAR_CODE:
        m_CurrentFrame.spaceBarPressed = false;
        break;
    }
  }

  void InputManager::Clear()
  {
    copyInputFrame(m_PreviousFrame, m_CurrentFrame);
  }
}
