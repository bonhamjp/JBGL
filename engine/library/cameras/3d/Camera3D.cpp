#include "Camera3D.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "core/scene/Scene.h"

#include "core/canvas/Canvas.h"

#include "library/shaders/Visualization3DShader.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace DataGarden
{
  Camera3D::Camera3D(float viewAngle, float nearClipping, float farClipping) : Camera(viewAngle, nearClipping, farClipping)
  {
    SetupProjection();
  }

  Camera3D::~Camera3D()
  {
  }

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
  {
  }

  void Camera3D::SetCameraUniforms()
  {
    Visualization3DShader *visualization3DShader = Engine::Get().GetScene().GetShaderManager()->GetVisualization3DShader();

    visualization3DShader->SetViewProjectionUniform(GetViewProjection());
    visualization3DShader->SetViewPositionUniform(m_Transform.GetPosition());
  }
} // namespace DataGarden
