#include "Material.h"

#include "core/Engine.h"

#include "core/object/node/Node.h"

#include "core/renderer/Texture.h"

#include <iostream>

namespace DataGarden
{
  Material::Material(Node *node, std::vector<TextureDataResourceDescriptor> textureDescriptors)
  {
    m_Shininess = 32.0f;

    for (auto it = textureDescriptors.begin(); it != textureDescriptors.end(); it++)
    {
      _CreateTextureFromData(*it);
    }
  }

  Material::~Material()
  {
  }

  bool Material::HasTexture(TextureType textureType, std::string texturePath)
  {
    if (m_Textures.count(textureType) == 0)
    {
      return false;
    }

    std::vector<Texture *> texturesOfType = m_Textures.find(textureType)->second;

    for (auto &texture : texturesOfType)
    {
      if (texture->GetPath().compare(texturePath) == 0)
      {
        return true;
      }
    }

    return false;
  }

  void Material::SetMaterialUniforms()
  {
    VisualizationShader *visualizationShader = Engine::Get().GetShaderManager().GetVisualizationShader();
    visualizationShader->Bind();

    visualizationShader->SetMaterialShininessUniform(m_Shininess);

    // TODO: Support multiple textures of each type
    auto ambientTextures = GetTextures(TextureType::Ambient);
    visualizationShader->SetAmbientTexturesUniform(ambientTextures.size());
    if (ambientTextures.size() > 0)
    {
      ambientTextures[0]->Bind();
    }

    auto diffuseTextures = GetTextures(TextureType::Diffuse);
    visualizationShader->SetDiffuseTexturesUniform(diffuseTextures.size());
    if (diffuseTextures.size() > 0)
    {
      diffuseTextures[0]->Bind();
    }

    auto specularTextures = GetTextures(TextureType::Specular);
    visualizationShader->SetSpecularTexturesUniform(specularTextures.size());
    if (specularTextures.size() > 0)
    {
      specularTextures[0]->Bind();
    }

    visualizationShader->Unbind();
  }

  void Material::_CreateTextureFromData(TextureDataResourceDescriptor textureResourceDescriptor)
  {
    Texture *texture = Engine::Get().GetTextureManager().AddResource((ResourceDescriptor *)&textureResourceDescriptor, CreateTextureFromData);

    TextureType textureType = textureResourceDescriptor.Type;

    // Add list for texture type, if not created yet
    std::vector<Texture *> textures;
    if (m_Textures.count(textureType) > 0)
    {
      textures = m_Textures[textureType];
    }

    textures.push_back(texture);

    m_Textures[textureType] = textures;
  }
} // namespace DataGarden
