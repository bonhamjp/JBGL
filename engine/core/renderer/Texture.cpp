#include "Texture.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

namespace DataGarden
{
  Texture::Texture(TextureDataResourceDescriptor* textureDataResourceDescriptor)
  {
    m_Type = textureDataResourceDescriptor->Type;

    Renderer& renderer = Engine::Get().GetRenderer();

    m_ID = renderer.GenerateTexture();
    renderer.BindTexture(m_ID);

    renderer.TextureParameterITextureMinFilterNearest();
    renderer.TextureParameterITextureMagFilterNearest();
    renderer.TextureParameterITextureWrapSClampToEdge();
    renderer.TextureParameterITextureWrapTClampToEdge();

    _GenerateTextureData(textureDataResourceDescriptor);

    renderer.GenerateMipmap();
  }

  Texture::~Texture()
  {
    Renderer& renderer = Engine::Get().GetRenderer();
    renderer.DeleteTexture(m_ID);
  }

  void Texture::Bind()
  {
    Renderer& renderer = Engine::Get().GetRenderer();

    renderer.activeTexture(m_Type, 0);
    renderer.BindTexture(m_ID);
  }

  void Texture::Unbind()
  {
    Renderer& renderer = Engine::Get().GetRenderer();
    renderer.UnbindTexture();
  }

  std::string Texture::GetPath()
  {
    return m_FilePath;
  }

  void Texture::_GenerateTextureData(TextureDataResourceDescriptor* textureDataResourceDescriptor)
  {
    // 4 bytes per color
    unsigned char* textureData;
    textureData = (unsigned char*) malloc(4 * 4 * sizeof(unsigned char));

    // Top left corner
    textureData[0] = textureDataResourceDescriptor->ColorOne.r * 255.0f;
    textureData[1] = textureDataResourceDescriptor->ColorOne.g * 255.0f;
    textureData[2] = textureDataResourceDescriptor->ColorOne.b * 255.0f;
    textureData[3] = 255.0f;

    // Top right corner
    textureData[4] = textureDataResourceDescriptor->ColorTwo.r * 255.0f;
    textureData[5] = textureDataResourceDescriptor->ColorTwo.g * 255.0f;
    textureData[6] = textureDataResourceDescriptor->ColorTwo.b * 255.0f;
    textureData[7] = 255.0f;

    // Bottom left corner
    textureData[8] = textureDataResourceDescriptor->ColorThree.r * 255.0f;
    textureData[9] = textureDataResourceDescriptor->ColorThree.g * 255.0f;
    textureData[10] = textureDataResourceDescriptor->ColorThree.b * 255.0f;
    textureData[11] = 255.0f;

    // Bottom right corner
    textureData[12] = textureDataResourceDescriptor->ColorFour.r * 255.0f;
    textureData[13] = textureDataResourceDescriptor->ColorFour.g * 255.0f;
    textureData[14] = textureDataResourceDescriptor->ColorFour.b * 255.0f;
    textureData[15] = 255.0f;

    Renderer& renderer = Engine::Get().GetRenderer();
    renderer.TexImage2D(textureData, 16);

    free(textureData);
  }

  Texture* CreateTextureFromData(ResourceDescriptor* descriptor)
  {
    TextureDataResourceDescriptor* textureDataResourceDescriptor = (TextureDataResourceDescriptor*)descriptor;

    return new Texture(textureDataResourceDescriptor);
  }
}
