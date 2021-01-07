#include "Camera.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "core/canvas/Canvas.h"

namespace DataGarden
{
  Camera::Camera(float viewAngle, float nearClipping, float farClipping) : Object()
  {
    m_ViewAngle = viewAngle;
    m_NearClipping = nearClipping;
    m_FarClipping = farClipping;
  }

  Camera::~Camera()
  {
  }

  void Camera::SetViewAngle(float viewAngle)
  {
    m_ViewAngle = viewAngle;

    SetupProjection();
  }

  void Camera::SetNearClipping(float nearClipping)
  {
    m_NearClipping = nearClipping;

    SetupProjection();
  }

  void Camera::SetFarClipping(float farClipping)
  {
    m_FarClipping = farClipping;

    SetupProjection();
  }

  void Camera::SetupProjection()
  {
  }

  void Camera::Update()
  {
  }

  glm::mat4 Camera::GetViewProjection()
  {
    return m_Projection * m_Transform.ViewMatrix();
  }

  void Camera::SetCameraUniforms()
  {
  }
} // namespace DataGarden
