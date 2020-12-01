#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

#include "Camera.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "core/canvas/Canvas.h"

namespace DataGarden
{
  Camera::Camera(float viewAngle, float nearClipping, float farClipping) :
  Object()
  {
    m_ViewAngle = viewAngle;
    m_NearClipping = nearClipping;
    m_FarClipping = farClipping;

    _SetupProjection();
  }

  Camera::~Camera()
  {}

  void Camera::SetViewAngle(float viewAngle)
  {
    m_ViewAngle = viewAngle;

    _SetupProjection();
  }

  void Camera::SetNearClipping(float nearClipping)
  {
    m_NearClipping = nearClipping;

    _SetupProjection();
  }

  void Camera::SetFarClipping(float farClipping)
  {
    m_FarClipping = farClipping;

    _SetupProjection();
  }

  void Camera::RefreshForDimensionChange()
  {
    _SetupProjection();
  }

  void Camera::Update()
  {}

  void Camera::_SetupProjection()
  {
    Canvas canvas = Engine::Get().GetCanvas();

    float width = canvas.GetWidth();
    float height = canvas.GetHeight();

    float aspectRatio = width / height;

    float viewAngleRadians = glm::radians(m_ViewAngle);

    m_Projection = glm::mat4(1.0f);
    m_Projection = glm::perspective(viewAngleRadians, aspectRatio, m_NearClipping, m_FarClipping);
  }

  glm::mat4 Camera::GetViewProjection()
  {
    return m_Projection * m_Transform.ViewMatrix();
  }

  void Camera::SetCameraUniforms()
  {
    Renderer& renderer = Engine::Get().GetRenderer();
    unsigned int programID = renderer.GetMainProgramID();

    renderer.SetUniformMatrix4fv(programID, "u_ViewProjection", GetViewProjection());
    renderer.SetUniform3fv(programID, "u_ViewPosition", m_Transform.GetPosition());
  }
}
