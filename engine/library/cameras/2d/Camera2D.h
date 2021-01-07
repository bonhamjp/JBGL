#ifndef DATA_GARDEN_CAMERA_2D
#define DATA_GARDEN_CAMERA_2D

#include "core/object/camera/Camera.h"

namespace DataGarden
{
  class Camera2D : public Camera
  {
  public:
    Camera2D(float viewAngle, float nearClipping, float farClipping);
    ~Camera2D();

    virtual void SetupProjection() override;

    virtual void Update() override;

    virtual void SetCameraUniforms() override;

  private:
    float m_MovementSensitivity = 36.0f;
    float m_LookSensitivity = 0.5f;
  };
} // namespace DataGarden

#endif
