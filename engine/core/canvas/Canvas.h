#ifndef DATA_GARDEN_CANVAS
#define DATA_GARDEN_CANVAS

#include "DataGarden.h"

namespace DataGarden
{
  class Canvas
  {
  public:
    Canvas();
    ~Canvas();

    inline float GetWidth() { return m_Width; };
    inline float GetHeight() { return m_Height; };
    inline float GetAspectRatio() { return m_AspectRatio; };

    void SetDimensions(float width, float height);

  private:
    float m_Width;
    float m_Height;
    float m_AspectRatio;

    void _SetAspectRatio();
  };

} // namespace DataGarden

#endif
