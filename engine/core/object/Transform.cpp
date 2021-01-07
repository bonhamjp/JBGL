#include "Transform.h"

#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/string_cast.hpp>

namespace DataGarden
{
  Transform::Transform()
  {
    m_Position = glm::vec3(0.0f);
    m_Scale = glm::vec3(1.0f);

    m_Yaw = 0.0;
    m_Pitch = 0.0;
    m_Roll = 0.0;

    m_Model = glm::mat4(1.0f);
  }

  Transform::Transform(glm::vec3 position)
  {
    m_Position = position;
    m_Scale = glm::vec3(1.0f);

    m_Yaw = 0.0;
    m_Pitch = 0.0;
    m_Roll = 0.0;

    m_Model = glm::mat4(1.0f);
  }

  Transform::Transform(glm::vec3 position, glm::vec3 scale)
  {
    m_Position = position;
    m_Scale = scale;

    m_Yaw = 0.0;
    m_Pitch = 0.0;
    m_Roll = 0.0;

    m_Model = glm::mat4(1.0f);
  }

  Transform::Transform(glm::vec3 position, glm::vec3 scale, float yaw, float pitch, float roll)
  {
    m_Position = position;
    m_Scale = scale;

    m_Yaw = yaw;
    m_Pitch = pitch;
    m_Roll = roll;

    m_Model = glm::mat4(1.0f);
  }

  Transform::~Transform()
  {
  }

  void Transform::UpdateModel(glm::mat4 translationMatrix)
  {
    glm::mat4 transform = glm::translate(translationMatrix, m_Position);

    transform = glm::rotate(transform, m_Yaw, glm::vec3(0.0f, 1.0f, 0.0f));   // Yaw is along Y-axis
    transform = glm::rotate(transform, m_Pitch, glm::vec3(1.0f, 0.0f, 0.0f)); // Pitch is along X-axis
    transform = glm::rotate(transform, m_Roll, glm::vec3(0.0f, 0.0f, 1.0f));  // Roll is along Z-axis

    transform = glm::scale(transform, m_Scale);

    m_Model = transform;
  }

  glm::vec3 Transform::LookVector()
  {
    glm::vec3 lookDirection;

    // x calculated by change of angle along y and z
    lookDirection.x = cos(glm::radians(m_Pitch)) * cos(glm::radians(m_Yaw));

    // y calculated by change of angle along x
    lookDirection.y = sin(glm::radians(m_Pitch));

    // z calculated by change of angle along y and x
    lookDirection.z = cos(glm::radians(m_Pitch)) * sin(glm::radians(m_Yaw));

    return lookDirection;
  }

  glm::mat4x4 Transform::ViewMatrix()
  {
    glm::vec3 front = glm::normalize(LookVector());
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

    return glm::lookAt(m_Position, m_Position + front, up);
  }
} // namespace DataGarden
