#ifndef DATA_GARDEN_LIGHT
#define DATA_GARDEN_LIGHT

#include <glm/glm.hpp>

#include "DataGarden.h"

#include "core/object/Object.h"

namespace DataGarden
{
  enum class LightType
  {
    Point = 0, Directional, Spot
  };

  class Light
  {
  public:
    Light();
    Light(glm::vec4 color);
    Light(glm::vec4 color, float ambientStrength, float diffuseStrength, float specularStrength);
    ~Light();

    void Update(glm::mat4 space);
    void Render();

    inline bool ShouldRemove() { return !m_Active; };
    void Destroy();

    inline glm::vec4 GetAmbientColor() { return m_Color; };
    inline glm::vec4 GetDiffuseColor() { return m_Color; };
    inline glm::vec4 GetSpecularColor() { return m_Color; };
    
  private:
    bool m_Active;

    glm::vec4 m_Color;

    float m_AmbientStrength;
    float m_DiffuseStrength;
    float m_SpecularStrength;

		glm::vec4 m_AmbientColor;
		glm::vec4 m_DiffuseColor;
		glm::vec4 m_SpecularColor;

    void _CalculateValues();
  };
}

#endif
