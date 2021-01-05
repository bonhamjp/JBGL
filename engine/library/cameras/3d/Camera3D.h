#ifndef DATA_GARDEN_CAMERA_3D
#define DATA_GARDEN_CAMERA_3D

#include "core/object/camera/Camera.h"

namespace DataGarden
{
  class Camera3D : public Camera
  {
  public:
    Camera3D(float viewAngle, float nearClipping, float farClipping);
    ~Camera3D();

    virtual void SetupProjection() override;

    virtual void Update() override;

    virtual void SetCameraUniforms() override;

  private:
    float m_MovementSensitivity = 36.0f;
		float m_LookSensitivity = 0.5f;
  };
}

#endif
