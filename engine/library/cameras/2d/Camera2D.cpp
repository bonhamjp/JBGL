#include "Camera2D.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "core/canvas/Canvas.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace DataGarden
{
  Camera2D::Camera2D(float viewAngle, float nearClipping, float farClipping) : Camera(viewAngle, nearClipping, farClipping)
  {
  }

  Camera2D::~Camera2D()
  {
  }

  void Camera2D::SetupProjection()
  {
  }

  void Camera2D::Update()
  {
  }

  void Camera2D::SetCameraUniforms()
  {
  }
} // namespace DataGarden
