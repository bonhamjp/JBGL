#include <iostream>

#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

#include "FreeCamera.h"

#include "core/Engine.h"

#include "core/input_manager/InputManager.h"
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

		// m_Transform.SetYaw(m_Transform.GetYaw() + (inputManager.GetMouseDeltaX() * m_LookSensitivity));
		// m_Transform.SetPitch(m_Transform.GetPitch() + (input.GetMouseDeltaY() * m_LookSensitivity));

		// // restrict pitch to prevent looking around x axis
		// if (m_Transform.GetPitch() > 60.0f)
		// {
		// 	m_Transform.SetPitch(60.0f);
		// }
		// else if (m_Transform.GetPitch() < -60.0f)
		// {
		// 	m_Transform.SetPitch(-60.0f);
		// }

		// glm::vec3 front = glm::normalize(m_Transform.LookVector());
		// glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

		// float moveSpeed = m_MovementSensitivity * deltaTime;

		// // TODO:
		// // Make setting transform easier
		// if (input.IsKeyPressed(GARDEN_KEY_W))
		// {
		// 	// transform->GetPosition() += front * moveSpeed;
		// 	m_Transform.SetPosition(m_Transform.GetPosition() + (front * moveSpeed));
		// }
		// if (input.IsKeyPressed(GARDEN_KEY_S))
		// {
		// 	// transform->GetPosition() -= front * moveSpeed;
		// 	m_Transform.SetPosition(m_Transform.GetPosition() - (front * moveSpeed));
		// }
		// if (input.IsKeyPressed(GARDEN_KEY_A))
		// {
		// 	// transform->GetPosition() -= glm::normalize(glm::cross(front, up)) * moveSpeed;
		// 	m_Transform.SetPosition(m_Transform.GetPosition() - (glm::normalize(glm::cross(front, up)) * moveSpeed));
		// }
		// if (input.IsKeyPressed(GARDEN_KEY_D))
		// {
		// 	// transform->GetPosition() += glm::normalize(glm::cross(front, up)) * moveSpeed;
		// 	m_Transform.SetPosition(m_Transform.GetPosition() + (glm::normalize(glm::cross(front, up)) * moveSpeed));
		// }

		// if (input.IsKeyPressed(GARDEN_KEY_Q))
		// {
		// 	m_Transform.SetPosition(m_Transform.GetPosition() - (up * moveSpeed));
		// }
		// if (input.IsKeyPressed(GARDEN_KEY_E))
		// {
		// 	m_Transform.SetPosition(m_Transform.GetPosition() + (up * moveSpeed));
		// }
  }
}

