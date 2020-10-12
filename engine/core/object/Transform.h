#ifndef DATA_GARDEN_TRANSFORM
#define DATA_GARDEN_TRANSFORM

#include <glm/glm.hpp>

#include "DataGarden.h"

namespace DataGarden
{
  class Transform
  {
  public:
    Transform();
    Transform(glm::vec3 position);
    Transform(glm::vec3 position, glm::vec3 scale, float yaw, float pitch, float roll);
    ~Transform();

    // TODO: Implement return by reference, for easier manipulation

    inline glm::vec3 GetPosition() { return m_Position; };
    inline void SetPosition(glm::vec3 position) { m_Position = position; };

    inline glm::vec3 GetScale() { return m_Scale; };
    inline void SetScale(glm::vec3 scale) { m_Scale = scale; };

    inline float GetYaw() { return m_Yaw; };
    inline void SetYaw(float yaw) { m_Yaw = yaw; };

    inline float GetPitch() { return m_Pitch; };
    inline void SetPitch(float pitch) { m_Pitch = pitch; };

    inline float GetRoll() { return m_Roll; };
    inline void SetRoll(float roll) { m_Roll = roll; };

    void UpdateModel(glm::mat4 translationMatrix);
    inline glm::mat4 GetModel() { return m_Model; };

    glm::vec3 LookVector();
    glm::mat4x4 ViewMatrix();

  private:
    glm::vec3 m_Position;
    glm::vec3 m_Scale;
    
    float m_Yaw;
    float m_Pitch;
    float m_Roll;

    glm::mat4 m_Model;

  };
}

#endif
