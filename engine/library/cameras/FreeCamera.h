#ifndef DATA_GARDEN_FREE_CAMERA
#define DATA_GARDEN_FREE_CAMERA

#include "core/object/camera/Camera.h"

namespace DataGarden
{
  class FreeCamera : public Camera
  {
  public:
    FreeCamera(float viewAngle, float nearClipping, float farClipping);
    ~FreeCamera();

    virtual void Update() override;

  private:

  };
}

#endif
