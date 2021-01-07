#ifndef DATA_GARDEN_MATERIAL_COMPONENT
#define DATA_GARDEN_MATERIAL_COMPONENT

#include "DataGarden.h"

#include "core/resource_manager/ResourceManager.h"

#include "core/renderer/Texture.h"

#include <vector>

namespace DataGarden
{
  // forward declarations
  class Node;

  class Material
  {
  public:
    Material(Node *node, std::vector<TextureDataResourceDescriptor> textureResourceDescriptor);
    ~Material();

    inline void SetShininess(float shininess) { m_Shininess = shininess; };
    inline float GetShininess() { return m_Shininess; };

    bool HasTexture(TextureType textureType, std::string texturePath);

    inline std::vector<Texture *> &GetTextures(TextureType textureType) { return m_Textures[textureType]; };

    void SetMaterialUniforms();

  private:
    float m_Shininess;

    std::map<TextureType, std::vector<Texture *>> m_Textures;

    void _CreateTextureFromData(TextureDataResourceDescriptor textureResourceDescriptor);
  };
} // namespace DataGarden

#endif
