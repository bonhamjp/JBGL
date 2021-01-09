#ifndef DATA_GARDEN_PAN_CAMERA
#define DATA_GARDEN_PAN_CAMERA

#include "Camera2D.h"

namespace DataGarden
{
  class PanCamera : public Camera2D
  {
  public:
    PanCamera(float viewAngle, float nearClipping, float farClipping);
    ~PanCamera();

    virtual void Update() override;

  private:
    float m_MovementSensitivity = 36.0f;
    float m_LookSensitivity = 0.5f;
  };
} // namespace DataGarden

#endif
