#include "Canvas.h"

#include "canvas_interface/CanvasInterface.h"

namespace DataGarden
{
  Canvas::Canvas()
  {
    // TODO: Figure out why camera loading before these are set
    m_Width = 600.0f;  // 0.0f;
    m_Height = 400.0f; // 0.0f;

    _SetAspectRatio();
  }

  Canvas::~Canvas()
  {
  }

  void Canvas::SetDimensions(float width, float height)
  {
    m_Width = width;
    m_Height = height;
  }

  void Canvas::_SetAspectRatio()
  {
    if (m_Width > 0.0f && m_Height > 0.0f)
    {
      m_AspectRatio = m_Width / m_Height;
    }
  }
} // namespace DataGarden
