#include "Material.h"

#include "core/Engine.h"

#include "core/object/node/Node.h"

#include "core/renderer/Texture.h"

namespace DataGarden
{
  Material::Material(Node* node, std::vector<ResourceDescriptor*> descriptors, Texture*(*f)(ResourceDescriptor* descriptor))
  {
    m_Shininess = 32.0f;

    for (auto it = descriptors.begin(); it != descriptors.end(); it++)
    {
      _CreateTexture(*it, f);
    }
  }

  Material::~Material()
  {}

  bool Material::HasTexture(TextureType textureType, std::string texturePath)
  {
    if (m_Textures.count(textureType) == 0)
    {
      return false;
    }

    std::vector<Texture*> texturesOfType = m_Textures.find(textureType)->second;

    for (auto& texture : texturesOfType) {
      if (texture->GetPath().compare(texturePath) == 0)
      {
        return true;
      }
    }

    return false;
  }
  
  void Material::_CreateTexture(ResourceDescriptor * descriptor, Texture*(*f)(ResourceDescriptor * descriptor))
  {
    Texture* texture = Engine::Get().GetTextureManager().AddResource(descriptor, f);

    // Add list for texture type, if not created yet
    std::vector<Texture*> textures;

    // TODO: Cast this differently depending on if for file or data
    // TextureType textureType = ((TextureFileResourceDescriptor*)descriptor)->Type;
    TextureType textureType = ((TextureDataResourceDescriptor*)descriptor)->Type;

    if (m_Textures.count(textureType) > 0)
    {
      textures = m_Textures[textureType];
    }

    textures.push_back(texture);

    // TODO: Change this to something that probably is more efficient?
    m_Textures[textureType] = textures;
  }
}
