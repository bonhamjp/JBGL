#include <iostream>

#include "InputManager.h"

#include "input_interface/InputInterface.h"

#include "KeyCodes.h"

#include "core/renderer/Renderer.h"

namespace DataGarden
{
  void copyInputFrame(InputFrame &inputFrameA, InputFrame &inputFrameB)
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

  void clearInputFrame(InputFrame &inputFrame)
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
    _Setup();

    clearInputFrame(m_PreviousFrame);
    clearInputFrame(m_CurrentFrame);
  }

  InputManager::~InputManager()
  {
    _Teardown();
  }

  void InputManager::MouseMoved(int mouseX, int mouseY)
  {
    m_CurrentFrame.mouseX = mouseX;
    m_CurrentFrame.mouseY = mouseY;
  }

  int InputManager::GetDeltaMouseX()
  {
    return m_CurrentFrame.mouseX - m_PreviousFrame.mouseX;
  }

  int InputManager::GetDeltaMouseY()
  {
    return m_CurrentFrame.mouseY - m_PreviousFrame.mouseY;
  }

  std::pair<int, int> InputManager::GetDeltaMouseCoords()
  {
    return {GetDeltaMouseX(), GetDeltaMouseY()};
  }

  void InputManager::MousePressed(int clickType)
  {
    // TODO: Make enums for clickType
    switch (clickType)
    {
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
    switch (clickType)
    {
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
    Renderer &renderer = Engine::Get().GetRenderer();

    // float r = ((float) (rand() % 255)) / 255.0f;
    // float g = ((float) (rand() % 255)) / 255.0f;
    // float b = ((float) (rand() % 255)) / 255.0f;

    // renderer.SetBufferColor(r, g, b, 1);
    // renderer.ClearBuffer();

    switch (keyCode)
    {
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

    case KEY_Q_CODE:
      m_CurrentFrame.qPressed = true;
      break;

    case KEY_E_CODE:
      m_CurrentFrame.ePressed = true;
      break;
    }
  }

  void InputManager::KeyUp(int keyCode)
  {
    switch (keyCode)
    {
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

    case KEY_Q_CODE:
      m_CurrentFrame.qPressed = false;
      break;

    case KEY_E_CODE:
      m_CurrentFrame.ePressed = false;
      break;
    }
  }

  void InputManager::Clear()
  {
    copyInputFrame(m_PreviousFrame, m_CurrentFrame);
  }

  bool InputManager::IsKeyPressed(int keyCode)
  {
    switch (keyCode)
    {
    case KEY_UP_CODE:
      return m_CurrentFrame.upPressed;
      break;

    case KEY_DOWN_CODE:
      return m_CurrentFrame.downPressed;
      break;

    case KEY_LEFT_CODE:
      return m_CurrentFrame.leftPressed;
      break;

    case KEY_RIGHT_CODE:
      return m_CurrentFrame.rightPressed;
      break;

    case KEY_SPACE_BAR_CODE:
      return m_CurrentFrame.spaceBarPressed;
      break;

    case KEY_Q_CODE:
      return m_CurrentFrame.qPressed;
      break;

    case KEY_E_CODE:
      return m_CurrentFrame.ePressed;
      break;
    }

    return false;
  }

  bool InputManager::IsMouseButtonPressed(int button)
  {
    return false;
  }

  void InputManager::_Setup()
  {
    inputInterfaceSetup();
  }

  void InputManager::_Teardown()
  {
    inputInterfaceTeardown();
  }
} // namespace DataGarden
