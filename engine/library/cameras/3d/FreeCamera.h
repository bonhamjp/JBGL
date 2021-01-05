#ifndef DATA_GARDEN_FREE_CAMERA
#define DATA_GARDEN_FREE_CAMERA

#include "Camera3D.h"

namespace DataGarden
{
  class FreeCamera : public Camera3D
  {
  public:
    FreeCamera(float viewAngle, float nearClipping, float farClipping);
    ~FreeCamera();

    virtual void Update() override;

  private:
    float m_MovementSensitivity = 36.0f;
		float m_LookSensitivity = 0.5f;

  };
}

#endif
