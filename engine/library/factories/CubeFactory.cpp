#include "CubeFactory.h"

#include "core/Engine.h"

#include "core/renderer/Texture.h"

// #include "core/object/entity/Entity.h"
// #include "core/object/entity/geometry/CubeGeometry.h"

namespace DataGarden
{
	// Ref<Geometry> CreateCubeGeometry(ResourceDescriptor* descriptor)
  // {
  //   return Ref<Geometry>(new CubeGeometry());
  // }

	Node* CubeFactory::Create(glm::vec3 position, glm::vec3 scale, glm::vec4 color)
	{
    // ResourceDescriptor descriptor = { std::string("Cube") };

    // // defers texture loading/creation to mesh creation
    // std::vector<TextureDataResourceDescriptor> textureDescriptors;

    // // std::string filename = std::string(fileName.C_Str());
    // std::string textureNameBase = std::to_string(color.r) + '/' + std::to_string(color.g) + '/' + std::to_string(color.b);

    // // TODO: Use separate textures for ambient/diffuse/specular if desirable
    // // TODO: Pass by reference, not value
    // textureDescriptors.push_back(TextureDataResourceDescriptor{ textureNameBase + std::string("-ambient"), TextureType::Ambient, color, color, color, color });
    // textureDescriptors.push_back(TextureDataResourceDescriptor{ textureNameBase + std::string("-diffuse"), TextureType::Diffuse, color, color, color, color });
    // textureDescriptors.push_back(TextureDataResourceDescriptor{ textureNameBase + std::string("-specular"), TextureType::Specular, color, color, color, color });

    // // Messy, I want to fix this- the mesh needs a vector of descriptor pointers, because specialized descriptors can be cast
    // std::vector<ResourceDescriptor*> descriptorPointers;
    // for (auto it = textureDescriptors.begin(); it != textureDescriptors.end(); it++)
    // {
    //   descriptorPointers.push_back((ResourceDescriptor*) & (*it));
    // }

    // Entity* entity = new Entity(
    //   Transform(position, scale, 0.0f, 0.0f, 0.0f),
    //   new Mesh(&descriptor, CreateCubeGeometry),
    //   new Material(descriptorPointers, CreateTextureFromData)
    // );

		// EntityNode* node = new EntityNode(entity);

    Node* node = new Node();

		return node;
	}

  Node* CubeFactory::Create(glm::vec3 position, glm::vec3 scale, glm::vec4 colorOne, glm::vec4 colorTwo)
  {
    // ResourceDescriptor descriptor = { std::string("Cube") };

    // // defers texture loading/creation to mesh creation
    // std::vector<TextureDataResourceDescriptor> textureDescriptors;

    // // std::string filename = std::string(fileName.C_Str());
    // std::string textureNameBase = std::to_string(colorOne.r) + '/' + std::to_string(colorOne.g) + '/' + std::to_string(colorTwo.b);

    // // TODO: Use separate textures for ambient/diffuse/specular if desirable
    // // TODO: Pass by reference, not value
    // textureDescriptors.push_back(TextureDataResourceDescriptor{ textureNameBase + std::string("-ambient"), TextureType::Ambient, colorOne, colorOne, colorTwo, colorTwo });
    // textureDescriptors.push_back(TextureDataResourceDescriptor{ textureNameBase + std::string("-diffuse"), TextureType::Diffuse, colorOne, colorOne, colorTwo, colorTwo });
    // textureDescriptors.push_back(TextureDataResourceDescriptor{ textureNameBase + std::string("-specular"), TextureType::Specular, colorOne, colorOne, colorTwo, colorTwo });

    // // Messy, I want to fix this- the mesh needs a vector of descriptor pointers, because specialized descriptors can be cast
    // std::vector<ResourceDescriptor*> descriptorPointers;
    // for (auto it = textureDescriptors.begin(); it != textureDescriptors.end(); it++)
    // {
    //   descriptorPointers.push_back((ResourceDescriptor*) & (*it));
    // }

    // Entity* entity = new Entity(
    //   Transform(position, scale, 0.0f, 0.0f, 0.0f),
    //   new Mesh(&descriptor, CreateCubeGeometry),
    //   new Material(descriptorPointers, CreateTextureFromData)
    // );

    // EntityNode* node = new EntityNode(entity);

    Node* node = new Node();

    return node;
  }
}
