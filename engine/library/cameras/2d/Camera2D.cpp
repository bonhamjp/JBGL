#include "Camera2D.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "core/canvas/Canvas.h"

#include "library/shaders/VisualizationShader.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <iostream>

namespace DataGarden
{
  Camera2D::Camera2D(float viewAngle, float nearClipping, float farClipping) : Camera(viewAngle, nearClipping, farClipping)
  {
    SetupProjection();
  }

  Camera2D::~Camera2D()
  {
  }

  void Camera2D::SetupProjection()
  {
    Canvas canvas = Engine::Get().GetCanvas();

    float width = canvas.GetWidth();
    float height = canvas.GetHeight();

    m_Projection = glm::mat4(1.0f);

    // TODO: Calculate a width and height to make objects as big as seen in perspective, and lock
    // TODO: Point at origin and remove view up/down angle

    // float aspectRatio = width / height;
    // m_Projection = glm::ortho(0.0f, (width / height) * 10.0f, 0.0f, (height / width) * 10.0f, m_NearClipping, m_FarClipping);
    m_Projection = glm::ortho(0.0f, width / 30.0f, 0.0f, height / 3.0f, m_NearClipping, m_FarClipping);
  }

  void Camera2D::Update()
  {
  }

  void Camera2D::SetCameraUniforms()
  {
    VisualizationShader *visualizationShader = Engine::Get().GetShaderManager().GetVisualizationShader();

    visualizationShader->SetViewProjectionUniform(GetViewProjection());
    visualizationShader->SetViewPositionUniform(m_Transform.GetPosition());
  }
} // namespace DataGarden
