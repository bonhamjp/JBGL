#include <iostream>

#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

#include "FreeCamera.h"

#include "core/Engine.h"

#include "core/input_manager/InputManager.h"
#include "core/input_manager/KeyCodes.h"
#include "core/clock/Clock.h"
#include "core/canvas/Canvas.h"

namespace DataGarden
{
  FreeCamera::FreeCamera(float viewAngle, float nearClipping, float farClipping) :
  Camera(viewAngle, nearClipping, farClipping)
  {}

  void FreeCamera::Update()
  {
    Engine& engine = Engine::Get();

		InputManager& inputManager = engine.GetInputManager();
		Clock& clock = engine.GetClock();

		float deltaTime = (float)clock.GetDeltaTime();

		// Why is Y delta different than the GLFW version? Is it actually?
		float mouseDeltaX = inputManager.GetDeltaMouseX();
		float mouseDeltaY = -(inputManager.GetDeltaMouseY());

		m_Transform.SetYaw(m_Transform.GetYaw() + (mouseDeltaX * m_LookSensitivity));
		m_Transform.SetPitch(m_Transform.GetPitch() + (mouseDeltaY * m_LookSensitivity));

		// restrict pitch to prevent looking around x axis
		// TODO: Make restrictions customizable
    if (m_Transform.GetPitch() > 80.0f)
		{
			m_Transform.SetPitch(60.0f);
		}
		else if (m_Transform.GetPitch() < -80.0f)
		{
			m_Transform.SetPitch(-60.0f);
		}

		glm::vec3 front = glm::normalize(m_Transform.LookVector());
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

		float moveSpeed = m_MovementSensitivity * deltaTime;

    if (inputManager.IsKeyPressed(KEY_UP_CODE))
		{
			m_Transform.SetPosition(m_Transform.GetPosition() + (front * moveSpeed));
		}
		if (inputManager.IsKeyPressed(KEY_DOWN_CODE))
		{
			m_Transform.SetPosition(m_Transform.GetPosition() - (front * moveSpeed));
		}
		if (inputManager.IsKeyPressed(KEY_LEFT_CODE))
		{
			m_Transform.SetPosition(m_Transform.GetPosition() - (glm::normalize(glm::cross(front, up)) * moveSpeed));
		}
		if (inputManager.IsKeyPressed(KEY_RIGHT_CODE))
		{
			m_Transform.SetPosition(m_Transform.GetPosition() + (glm::normalize(glm::cross(front, up)) * moveSpeed));
		}

		if (inputManager.IsKeyPressed(KEY_Q_CODE))
		{
			m_Transform.SetPosition(m_Transform.GetPosition() - (up * moveSpeed));
		}
		if (inputManager.IsKeyPressed(KEY_E_CODE))
		{
			m_Transform.SetPosition(m_Transform.GetPosition() + (up * moveSpeed));
		}
  }
}

