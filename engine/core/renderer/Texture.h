#ifndef DATA_GARDEN_TEXTURE
#define DATA_GARDEN_TEXTURE

#include "DataGarden.h"

#include "core/resource_manager/ResourceManager.h"

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

  class Texture
  {
  public:
    Texture(const std::string& source);
    ~Texture();

    void Bind();
    void Unbind();

    virtual std::string GetPath();

  private:
    unsigned int m_ID;

    std::string m_FilePath;

    void _LoadTexture(const std::string& source);
  };

  Texture* CreateTexture(ResourceDescriptor* descriptor);
}

#endif
