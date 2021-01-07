#ifndef DATA_GARDEN_FACTORY
#define DATA_GARDEN_FACTORY

#include <glm/glm.hpp>

#include "DataGarden.h"

#include "core/object/node/Node.h"

namespace DataGarden
{
  enum class FactoryType
  {
    Cube = 0,
    Plane,
    Sphere,
    Pyramid,
    Cylinder
  };

  class Factory
  {
  public:
    static Node *Create(FactoryType factoryType, glm::vec3 position, glm::vec3 scale, glm::vec4 color);
    static Node *Create(FactoryType factoryType, glm::vec3 position, glm::vec3 scale, glm::vec4 colorOne, glm::vec4 colorTwo);
  };
} // namespace DataGarden

#endif
