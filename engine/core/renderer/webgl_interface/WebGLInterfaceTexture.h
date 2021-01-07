#ifndef DATA_GARDEN_WEBGL_INTERFACE_TEXTURE
#define DATA_GARDEN_WEBGL_INTERFACE_TEXTURE

#include <emscripten.h>

EM_JS(unsigned int, webGLInterfaceGenerateTexture, (), {
  const textureID = document.webGLModule.textureCount;

  document.webGLModule.textures.push(document.webGLModule.context.createTexture());
  document.webGLModule.textureCount++;

  return textureID;
});

EM_JS(unsigned int, webGLInterfaceTextureParameterITextureMinFilterNearest, (), {
  document.webGLModule.context.texParameteri(
      document.webGLModule.context.TEXTURE_2D,
      document.webGLModule.context.TEXTURE_MIN_FILTER,
      document.webGLModule.context.NEAREST);
});

EM_JS(unsigned int, webGLInterfaceTextureParameterITextureMagFilterNearest, (), {
  document.webGLModule.context.texParameteri(
      document.webGLModule.context.TEXTURE_2D,
      document.webGLModule.context.TEXTURE_MAG_FILTER,
      document.webGLModule.context.NEAREST);
});

EM_JS(unsigned int, webGLInterfaceTextureParameterITextureWrapSClampToEdge, (), {
  document.webGLModule.context.texParameteri(
      document.webGLModule.context.TEXTURE_2D,
      document.webGLModule.context.TEXTURE_WRAP_S,
      document.webGLModule.context.CLAMP_TO_EDGE);
});

EM_JS(unsigned int, webGLInterfaceTextureParameterITextureWrapTClampToEdge, (), {
  document.webGLModule.context.texParameteri(
      document.webGLModule.context.TEXTURE_2D,
      document.webGLModule.context.TEXTURE_WRAP_T,
      document.webGLModule.context.CLAMP_TO_EDGE);
});

EM_JS(unsigned int, webGLInterfaceBindTexture, (unsigned int textureID), {
  var texture = document.webGLModule.textures[textureID];
  // TODO: Support other texture types
  document.webGLModule.context.bindTexture(document.webGLModule.context.TEXTURE_2D, texture);
});

EM_JS(unsigned int, webGLInterfaceTexImage2D, (unsigned char *textureData, unsigned int textureDataLength), {
  var context = document.webGLModule.context;
  var texture = new Uint8Array(webGLInterfaceGetCharData(textureData, textureDataLength));

  // context.bufferData(context.ELEMENT_ARRAY_BUFFER, indices, context.STATIC_DRAW);

  context.texImage2D(
      context.TEXTURE_2D,
      0,
      context.RGBA,
      2,
      2,
      0,
      context.RGBA,
      context.UNSIGNED_BYTE,
      texture);
});

EM_JS(unsigned int, webGLInterfaceActiveTexture, (unsigned int textureIndex), {
  var webGLTexturePosition = webGLInterfaceRetrieveTexturePosition(textureIndex);

  document.webGLModule.context.activeTexture(webGLTexturePosition);
});

EM_JS(unsigned int, webGLInterfaceGenerateMipmap, (), {
  document.webGLModule.context.generateMipmap(document.webGLModule.context.TEXTURE_2D);
});

EM_JS(unsigned int, webGLInterfaceDeleteTexture, (unsigned int textureID), {
  var texture = document.webGLModule.textures[textureID];
  document.webGLModule.context.deleteTexture(texture);

  document.webGLModule.textures[textureID] = null;
});

EM_JS(unsigned int, webGLInterfaceRetrieveTexturePosition, (unsigned int textureIndex), {
  switch (textureIndex)
  {
  case 0:
    return document.webGLModule.context.TEXTURE0;
    break;

  case 1:
    return document.webGLModule.context.TEXTURE1;
    break;

  case 2:
    return document.webGLModule.context.TEXTURE2;
    break;

  case 3:
    return document.webGLModule.context.TEXTURE3;
    break;

  case 4:
    return document.webGLModule.context.TEXTURE4;
    break;

  case 5:
    return document.webGLModule.context.TEXTURE5;
    break;

  case 6:
    return document.webGLModule.context.TEXTURE6;
    break;

  case 7:
    return document.webGLModule.context.TEXTURE7;
    break;

  case 8:
    return document.webGLModule.context.TEXTURE8;
    break;

  case 9:
    return document.webGLModule.context.TEXTURE9;
    break;

  case 10:
    return document.webGLModule.context.TEXTURE10;
    break;

  case 11:
    return document.webGLModule.context.TEXTURE11;
    break;
  }
});

#endif
