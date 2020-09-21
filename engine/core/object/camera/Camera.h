#ifndef DATA_GARDEN_CAMERA
#define DATA_GARDEN_CAMERA

#include <glm/glm.hpp>

#include "DataGarden.h"

#include "core/object/Object.h"

namespace DataGarden
{
  class Camera : public Object
  {
  public:
    Camera(float viewAngle, float nearClipping, float farClipping);
    ~Camera();
    
    inline float GetViewAngle() { return m_ViewAngle; };
    void SetViewAngle(float viewAngle);

    inline float GetNearClipping() { return m_NearClipping; };
    void SetNearClipping(float nearClipping);

    inline float GetFarClipping() { return m_FarClipping; };
    void SetFarClipping(float farClipping);

    void RefreshForDimensionChange();

    virtual void Update();

  protected:
    float m_ViewAngle;
    float m_NearClipping;
    float m_FarClipping;

    glm::mat4 m_Projection;

    void _SetupProjection();
  };
}

#endif
