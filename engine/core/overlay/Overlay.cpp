#include "Overlay.h"

namespace DataGarden
{
  Overlay::Overlay()
  {
    m_Precision = 1.0f;
  }

  Overlay::Overlay(float precision)
  {
    m_Precision = precision;
  }

  Overlay::~Overlay()
  {
  }
} // namespace DataGarden
