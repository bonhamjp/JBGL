#ifndef DATA_GARDEN_CLOCK
#define DATA_GARDEN_CLOCK

#include "DataGarden.h"

namespace DataGarden
{
  class Clock
  {
  public:
    Clock();
    ~Clock();

    void Update();

    inline double GetCurrentTime() const { return m_CurrentTime; };
    inline double GetPreviousTime() const { return m_PreviousTime; };
    inline double GetDeltaTime() const { return m_DeltaTime; };

    void Reset();

  private:
    double m_CurrentTime;
    double m_PreviousTime;
    double m_DeltaTime;

    void _Start();
  };
} // namespace DataGarden

#endif
