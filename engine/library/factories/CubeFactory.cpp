#include "CubeFactory.h"

#include "core/Engine.h"

#include "core/object/node/Node.h"
#include "core/object/node/Mesh.h"
#include "core/object/node/Material.h"

#include "core/renderer/Texture.h"

#include "library/geometries/CubeGeometry.h"

#include <iostream>

namespace DataGarden
{
	Geometry* CreateCubeGeometry(ResourceDescriptor* descriptor)
  {
    return new CubeGeometry();
  }

	Node* CubeFactory::Create(glm::vec3 position, glm::vec3 scale, glm::vec4 color)
	{
    ResourceDescriptor descriptor = { std::string("Cube") };

    // defers texture loading/creation to mesh creation
    std::vector<TextureDataResourceDescriptor> textureDescriptors;

    // // std::string filename = std::string(fileName.C_Str());
    std::string textureNameBase = std::to_string(color.r) + '/' + std::to_string(color.g) + '/' + std::to_string(color.b);

    // TODO: Use separate textures for ambient/diffuse/specular if desirable
    // TODO: Pass by reference, not value

    TextureDataResourceDescriptor tdrd; 
    tdrd.Name = textureNameBase + std::string("-ambient");
    tdrd.Type = TextureType::Ambient;
    tdrd.ColorOne = color;
    tdrd.ColorTwo = color;
    tdrd.ColorThree = color;
    tdrd.ColorFour = color;
    textureDescriptors.push_back(tdrd);

    // textureDescriptors.push_back(TextureDataResourceDescriptor{ textureNameBase + std::string("-ambient"), TextureType::Ambient, color, color, color, color });
    // textureDescriptors.push_back(TextureDataResourceDescriptor{ textureNameBase + std::string("-diffuse"), TextureType::Diffuse, color, color, color, color });
    // textureDescriptors.push_back(TextureDataResourceDescriptor{ textureNameBase + std::string("-specular"), TextureType::Specular, color, color, color, color });

    // Messy, I want to fix this- the mesh needs a vector of descriptor pointers, because specialized descriptors can be cast
    std::vector<ResourceDescriptor*> descriptorPointers;
    for (auto it = textureDescriptors.begin(); it != textureDescriptors.end(); it++)
    {
      descriptorPointers.push_back((ResourceDescriptor*) & (*it));
    }

    Node* node = new Node();

    node->SetTransform(position);
    node->SetMesh(new Mesh(node, &descriptor, CreateCubeGeometry));
    node->SetMaterial(new Material(node, descriptorPointers, CreateTextureFromData));

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
