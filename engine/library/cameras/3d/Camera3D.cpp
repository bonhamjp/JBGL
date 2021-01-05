#include "Camera3D.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "core/canvas/Canvas.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace DataGarden
{
  Camera3D::Camera3D(float viewAngle, float nearClipping, float farClipping) :
  Camera(viewAngle, nearClipping, farClipping)
  {
    SetupProjection();
  }

  Camera3D::~Camera3D()
  {}

  void Camera3D::SetupProjection()
  {
    Canvas canvas = Engine::Get().GetCanvas();

    float width = canvas.GetWidth();
    float height = canvas.GetHeight();

    float aspectRatio = width / height;

    float viewAngleRadians = glm::radians(m_ViewAngle);

    m_Projection = glm::mat4(1.0f);
    m_Projection = glm::perspective(viewAngleRadians, aspectRatio, m_NearClipping, m_FarClipping);
  }

  void Camera3D::Update()
  {}

  void Camera3D::SetCameraUniforms()
  {
    Renderer& renderer = Engine::Get().GetRenderer();
    unsigned int programID = renderer.GetMainProgramID();

    renderer.SetUniformMatrix4fv(programID, "u_ViewProjection", GetViewProjection());
    renderer.SetUniform3fv(programID, "u_ViewPosition", m_Transform.GetPosition());
  }
}