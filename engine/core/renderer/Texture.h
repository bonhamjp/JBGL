#ifndef DATA_GARDEN_TEXTURE
#define DATA_GARDEN_TEXTURE

#include "DataGarden.h"

#include "core/resource_manager/ResourceManager.h"

#include <glm/glm.hpp>

namespace DataGarden
{
  enum class TextureType
  {
    Unknown = 0,
    Ambient,
    Diffuse,
    Displacement,
    Emissive,
    Height,
    LightMap,
    Normals,
    Opacity,
    Reflection,
    Shinines,
    Specular
  };

  struct TextureResourceDescriptor : ResourceDescriptor
  {
    std::string FilePath;
  };

  struct TextureFileResourceDescriptor : ResourceDescriptor
  {
    TextureType Type;
    std::string FilePath;
  };

  struct TextureDataResourceDescriptor : ResourceDescriptor
  {
    TextureType Type;
    glm::vec4 ColorOne;
    glm::vec4 ColorTwo;
    glm::vec4 ColorThree;
    glm::vec4 ColorFour;
  };

  class Texture
  {
  public:
    Texture(TextureDataResourceDescriptor *textureDataResourceDescriptor);
    ~Texture();

    void Bind();
    void Unbind();

    std::string GetPath();

  private:
    unsigned int m_ID;

    TextureType m_Type;
    std::string m_FilePath;

    void _GenerateTextureData(TextureDataResourceDescriptor *textureDataResourceDescriptor);
  };

  Texture *CreateTextureFromData(ResourceDescriptor *descriptor);
} // namespace DataGarden

#endif
