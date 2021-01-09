#include "PanCamera.h"

#include "core/Engine.h"

#include "core/input_manager/InputManager.h"
#include "core/input_manager/KeyCodes.h"

#include "core/clock/Clock.h"

#include "core/canvas/Canvas.h"

#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

namespace DataGarden
{
  PanCamera::PanCamera(float viewAngle, float nearClipping, float farClipping) : Camera2D(viewAngle, nearClipping, farClipping)
  {
  }

  void PanCamera::Update()
  {
    Engine &engine = Engine::Get();

    InputManager &inputManager = engine.GetInputManager();
    Clock &clock = engine.GetClock();

    float deltaTime = (float)clock.GetDeltaTime();

    glm::vec3 front = glm::normalize(m_Transform.LookVector());
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

    float moveSpeed = m_MovementSensitivity * deltaTime;

    if (inputManager.IsKeyDown(KEY_LEFT_CODE))
    {
      m_Transform.SetPosition(m_Transform.GetPosition() - (glm::normalize(glm::cross(front, up)) * moveSpeed));
    }
    if (inputManager.IsKeyDown(KEY_RIGHT_CODE))
    {
      m_Transform.SetPosition(m_Transform.GetPosition() + (glm::normalize(glm::cross(front, up)) * moveSpeed));
    }

    if (inputManager.IsKeyDown(KEY_Q_CODE))
    {
      m_Transform.SetPosition(m_Transform.GetPosition() - (up * moveSpeed));
    }
    if (inputManager.IsKeyDown(KEY_E_CODE))
    {
      m_Transform.SetPosition(m_Transform.GetPosition() + (up * moveSpeed));
    }
  }
} // namespace DataGarden
