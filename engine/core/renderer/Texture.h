#ifndef DATA_GARDEN_TEXTURE
#define DATA_GARDEN_TEXTURE

#include "DataGarden.h"

#include "core/resource_manager/ResourceManager.h"

#include <glm/glm.hpp>

namespace DataGarden
{
  enum class TextureType
  {
    None = 0, Unknown, Ambient, Diffuse, Displacement, Emissive, Height, LightMap, Normals, Opacity, Reflection, Shinines, Specular
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
    Texture(TextureType type, const std::string& source);
    Texture(TextureType type, glm::vec4 colorOne, glm::vec4 colorTwo, glm::vec4 colorThree, glm::vec4 colorFour);
    ~Texture();

    void Bind();
    void Unbind();

    virtual std::string GetPath();

  private:
    unsigned int m_ID;

    std::string m_FilePath;

    void _LoadTexture(const std::string& source);
  };

  // Texture* CreateTextureFromFile(ResourceDescriptor* descriptor);
  Texture* CreateTextureFromData(ResourceDescriptor* descriptor);
}

#endif
