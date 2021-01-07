#include <iostream>

#include <emscripten.h>

#include "Clock.h"

namespace DataGarden
{
  Clock::Clock()
  {
    _Start();
  }

  Clock::~Clock()
  {
  }

  void Clock::Update()
  {
    double currentTime = emscripten_get_now() / 1000.0f;

    m_PreviousTime = m_CurrentTime;
    m_CurrentTime = (float)currentTime;
    m_DeltaTime = m_CurrentTime - m_PreviousTime;
  }

  void Clock::Reset()
  {
    this->_Start();
  }

  void Clock::_Start()
  {
    m_PreviousTime = 0.0;
    m_CurrentTime = 0.0;
    m_DeltaTime = 0.0;
  }
} // namespace DataGarden
