#ifndef DATA_GARDEN_CUBE_FACTORY
#define DATA_GARDEN_CUBE_FACTORY

#include <glm/glm.hpp>

#include "DataGarden.h"

#include "core/object/node/Factory.h"

namespace DataGarden
{
	class CubeFactory : Factory
	{
	public:
		static Node* Create(glm::vec3 position, glm::vec3 scale, glm::vec4 color);
    static Node* Create(glm::vec3 position, glm::vec3 scale, glm::vec4 colorOne, glm::vec4 colorTwo);
	};
}

#endif
