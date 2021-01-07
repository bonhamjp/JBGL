#ifndef DATA_GARDEN_OVERLAY
#define DATA_GARDEN_OVERLAY

#include "DataGarden.h"

namespace DataGarden
{
	class Overlay
	{
	public:
    Overlay();
    Overlay(float precision);
		~Overlay();

		virtual void Update();

    float GetPrecision() { return m_Precision; };
    inline void SetPrecision(float precision) { m_Precision = precision; };

  private:
    float m_Precision;
  };
}

#endif
