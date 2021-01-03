#include "Factory.h"

#include "core/Engine.h"

#include "core/object/node/Node.h"
#include "core/object/node/Mesh.h"
#include "core/object/node/Material.h"

#include "core/renderer/Texture.h"

#include "library/geometries/CubeGeometry.h"
#include "library/geometries/PlaneGeometry.h"
#include "library/geometries/SphereGeometry.h"
#include "library/geometries/PyramidGeometry.h"
#include "library/geometries/CylinderGeometry.h"

#include <iostream>

namespace DataGarden
{
  const std::string AMBIENT_SUFFIX = "-ambient";
  const std::string DIFFUSE_SUFFIX = "-diffuse";
  const std::string SPECULAR_SUFFIX = "-specular";

  const std::string CUBE_DESCRIPTOR_NAME = "cube";

  struct FactoryBuilder
	{
    ResourceDescriptor descriptor;
    Geometry*(*f)(ResourceDescriptor* descriptor);
  };

  TextureDataResourceDescriptor CreateTextureResourceDescriptor(std::string& textureName, TextureType textureType, glm::vec4 color)
  {
    TextureDataResourceDescriptor textureResourceDescriptor;
    textureResourceDescriptor.Name = textureName;
    textureResourceDescriptor.Type = textureType;
    textureResourceDescriptor.ColorOne = color;
    textureResourceDescriptor.ColorTwo = color;
    textureResourceDescriptor.ColorThree = color;
    textureResourceDescriptor.ColorFour = color;

    return textureResourceDescriptor;
  }

  TextureDataResourceDescriptor CreateTextureResourceDescriptor(std::string& textureName, TextureType textureType, glm::vec4 colorOne, glm::vec4 colorTwo)
  {
    TextureDataResourceDescriptor textureResourceDescriptor;
    textureResourceDescriptor.Name = textureName;
    textureResourceDescriptor.Type = textureType;
    textureResourceDescriptor.ColorOne = colorOne;
    textureResourceDescriptor.ColorTwo = colorOne;
    textureResourceDescriptor.ColorThree = colorTwo;
    textureResourceDescriptor.ColorFour = colorTwo;

    return textureResourceDescriptor;
  }

  TextureDataResourceDescriptor CreateTextureResourceDescriptor(std::string& textureName, TextureType textureType, glm::vec4 colorOne, glm::vec4 colorTwo, glm::vec4 colorThree, glm::vec4 colorFour)
  {
    TextureDataResourceDescriptor textureResourceDescriptor;
    textureResourceDescriptor.Name = textureName;
    textureResourceDescriptor.Type = textureType;
    textureResourceDescriptor.ColorOne = colorOne;
    textureResourceDescriptor.ColorTwo = colorTwo;
    textureResourceDescriptor.ColorThree = colorThree;
    textureResourceDescriptor.ColorFour = colorFour;

    return textureResourceDescriptor;
  }

  std::vector<TextureDataResourceDescriptor> TexturesForColor(glm::vec4 color)
  {
    std::string colorPartName = std::to_string(color.r) + '/' + std::to_string(color.g) + '/' + std::to_string(color.b);

    std::vector<TextureDataResourceDescriptor> textureDescriptors;

    std::string ambientTextureName = colorPartName + AMBIENT_SUFFIX;
    textureDescriptors.push_back(CreateTextureResourceDescriptor(ambientTextureName, TextureType::Ambient, color));

    std::string diffuseTextureName = colorPartName + DIFFUSE_SUFFIX;
    textureDescriptors.push_back(CreateTextureResourceDescriptor(diffuseTextureName, TextureType::Diffuse, color));

    std::string specularTextureName = colorPartName + SPECULAR_SUFFIX;
    textureDescriptors.push_back(CreateTextureResourceDescriptor(specularTextureName, TextureType::Specular, color));

    return textureDescriptors;
  }

  std::vector<TextureDataResourceDescriptor> TexturesForColors(glm::vec4 colorOne, glm::vec4 colorTwo)
  {
    std::string colorPartName = std::to_string(colorOne.r) + '/' + std::to_string(colorOne.g) + '/' + std::to_string(colorOne.b);
    colorPartName = colorPartName + '-' + std::to_string(colorTwo.r) + '/' + std::to_string(colorTwo.g) + '/' + std::to_string(colorTwo.b);

    std::vector<TextureDataResourceDescriptor> textureDescriptors;

    std::string ambientTextureName = colorPartName + AMBIENT_SUFFIX;
    textureDescriptors.push_back(CreateTextureResourceDescriptor(ambientTextureName, TextureType::Ambient, colorOne, colorTwo));

    std::string diffuseTextureName = colorPartName + DIFFUSE_SUFFIX;
    textureDescriptors.push_back(CreateTextureResourceDescriptor(diffuseTextureName, TextureType::Diffuse, colorOne, colorTwo));

    std::string specularTextureName = colorPartName + SPECULAR_SUFFIX;
    textureDescriptors.push_back(CreateTextureResourceDescriptor(specularTextureName, TextureType::Specular, colorOne, colorTwo));

    return textureDescriptors;
  }

  std::vector<TextureDataResourceDescriptor> TexturesForColors(glm::vec4 colorOne, glm::vec4 colorTwo, glm::vec4 colorThree, glm::vec4 colorFour)
  {
    std::string colorPartName = std::to_string(colorOne.r) + '/' + std::to_string(colorOne.g) + '/' + std::to_string(colorOne.b);
    colorPartName = colorPartName + '-' + std::to_string(colorTwo.r) + '/' + std::to_string(colorTwo.g) + '/' + std::to_string(colorTwo.b);
    colorPartName = colorPartName + '-' + std::to_string(colorThree.r) + '/' + std::to_string(colorThree.g) + '/' + std::to_string(colorThree.b);
    colorPartName = colorPartName + '-' + std::to_string(colorFour.r) + '/' + std::to_string(colorFour.g) + '/' + std::to_string(colorFour.b);

    std::vector<TextureDataResourceDescriptor> textureDescriptors;

    std::string ambientTextureName = colorPartName + AMBIENT_SUFFIX;
    textureDescriptors.push_back(CreateTextureResourceDescriptor(ambientTextureName, TextureType::Ambient, colorOne, colorTwo, colorThree, colorFour));

    std::string diffuseTextureName = colorPartName + DIFFUSE_SUFFIX;
    textureDescriptors.push_back(CreateTextureResourceDescriptor(diffuseTextureName, TextureType::Diffuse, colorOne, colorTwo, colorThree, colorFour));

    std::string specularTextureName = colorPartName + SPECULAR_SUFFIX;
    textureDescriptors.push_back(CreateTextureResourceDescriptor(specularTextureName, TextureType::Specular, colorOne, colorTwo, colorThree, colorFour));

    return textureDescriptors;
  }

  Geometry* CreateCubeGeometry(ResourceDescriptor* descriptor)
  {
    return new CubeGeometry();
  }

  Geometry* CreatePlaneGeometry(ResourceDescriptor* descriptor)
  {
    return new PlaneGeometry();
  }

  Geometry* CreateSphereGeometry(ResourceDescriptor* descriptor)
  {
    return new SphereGeometry(3);
  }

  Geometry* CreatePyramidGeometry(ResourceDescriptor* descriptor)
  {
    return new PyramidGeometry();
  }

  Geometry* CreateCylinderGeometry(ResourceDescriptor* descriptor)
  {
    return new CylinderGeometry(40);
  }

  FactoryBuilder CreateFactoryBuilderForType(FactoryType factoryType)
  {
    FactoryBuilder factoryBuilder;

    switch(factoryType) {
      case FactoryType::Cube:
        factoryBuilder.descriptor = { std::string("Cube") };
        factoryBuilder.f = CreateCubeGeometry;
        break;

      case FactoryType::Plane:
        factoryBuilder.descriptor = { std::string("Plane") };
        factoryBuilder.f = CreatePlaneGeometry;
        break;

      case FactoryType::Sphere:
        factoryBuilder.descriptor = { std::string("Sphere") };
        factoryBuilder.f = CreateSphereGeometry;
        break;

      case FactoryType::Pyramid:
        factoryBuilder.descriptor = { std::string("Pyramid") };
        factoryBuilder.f = CreatePyramidGeometry;
        break;

      case FactoryType::Cylinder:
        factoryBuilder.descriptor = { std::string("Cylinder") };
        factoryBuilder.f = CreateCylinderGeometry;
        break;
    }

    return factoryBuilder;
  }

	Node* Factory::Create(FactoryType factoryType, glm::vec3 position, glm::vec3 scale, glm::vec4 color)
	{
    Node* node = new Node();

    // TODO: Use scale
    Transform transform = Transform(position, scale);
    node->SetTransform(transform);

    FactoryBuilder factoryBuilder = CreateFactoryBuilderForType(factoryType);
    node->SetMesh(new Mesh(node, &factoryBuilder.descriptor, factoryBuilder.f));

    node->SetMaterial(new Material(node, TexturesForColor(color)));

    return node;
	}

  Node* Factory::Create(FactoryType factoryType, glm::vec3 position, glm::vec3 scale, glm::vec4 colorOne, glm::vec4 colorTwo)
  {
    Node* node = new Node();

    return node;
  }
}
