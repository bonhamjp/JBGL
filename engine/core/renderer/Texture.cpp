#include "Texture.h"

namespace DataGarden
{
  Texture::Texture(TextureType type, const std::string& source)
  {
    m_FilePath = source;

    // glGenTextures(1, &m_ID);
    // glBindTexture(GL_TEXTURE_2D, m_ID);

    // // TODO: Provide customization of texture wrapping/filtering options
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    _LoadTexture(m_FilePath);
  }

  Texture::Texture(TextureType type, glm::vec4 colorOne, glm::vec4 colorTwo, glm::vec4 colorThree, glm::vec4 colorFour)
  {
    // glGenTextures(1, &m_ID);
    // glBindTexture(GL_TEXTURE_2D, m_ID);

    // // TODO: Provide customization of texture wrapping/filtering options
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    _LoadTexture(m_FilePath);
  }

  Texture::~Texture()
  {
    // glDeleteTextures(1, &m_ID);
  }

  void Texture::Bind()
  {
    // switch (m_Type)
    // {
    // case TextureType::Ambient:
    //   glActiveTexture(GL_TEXTURE0);
    //   break;

    // case TextureType::Diffuse:
    //   glActiveTexture(GL_TEXTURE1);
    //   break;

    // case TextureType::Specular:
    //   glActiveTexture(GL_TEXTURE2);
    //   break;
    // }

    // glBindTexture(GL_TEXTURE_2D, m_ID);
  }

  void Texture::Unbind()
  {
    // glBindTexture(GL_TEXTURE_2D, 0);
  }

  std::string Texture::GetPath()
  {
    return m_FilePath;
  }

  void Texture::_LoadTexture(const std::string& source)
  {
    // int width;
    // int height;
    // int numberChannels;

    // unsigned char* textureData = stbi_load(source.c_str(), &width, &height, &numberChannels, 0);

    // GLenum format;
    // if (numberChannels == 1)
    // {
    //   format = GL_RED;
    // }
    // else if (numberChannels == 3)
    // {
    //   format = GL_RGB;
    // }
    // else if (numberChannels == 4)
    // {
    //   format = GL_RGBA;
    // }

    // Bind();

    // glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, textureData);
    // glGenerateMipmap(GL_TEXTURE_2D);

    // stbi_image_free(textureData);
  }

  // Texture* CreateTextureFromFile(ResourceDescriptor* descriptor)
  // {
  //   TextureFileResourceDescriptor* textureDescriptor = (TextureFileResourceDescriptor*)descriptor;

  //   TextureType type = textureDescriptor->Type;
  //   std::string filePath = textureDescriptor->FilePath;

  //   return new Texture(type, filePath);
  // }

  Texture* CreateTextureFromData(ResourceDescriptor* descriptor)
  {
    TextureDataResourceDescriptor* textureDescriptor = (TextureDataResourceDescriptor*)descriptor;

    TextureType type = textureDescriptor->Type;
    glm::vec4 colorOne = textureDescriptor->ColorOne;
    glm::vec4 colorTwo = textureDescriptor->ColorTwo;
    glm::vec4 colorThree = textureDescriptor->ColorThree;
    glm::vec4 colorFour = textureDescriptor->ColorFour;

    return new Texture(type, colorOne, colorTwo, colorThree, colorFour);
  }
}
