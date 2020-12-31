#ifndef DATA_GARDEN_WEBGL_INTERFACE_UTILITY
#define DATA_GARDEN_WEBGL_INTERFACE_UTILITY

#include <emscripten.h>

// TODO: Make this more efficient
EM_JS(float*, webGLInterfaceGetFloatData, (float* floatData, unsigned int floatLength), {
  const bytesPerFloat = Float32Array.BYTES_PER_ELEMENT;
  const rawData = new Float32Array(Module.HEAPU8.buffer, floatData, floatLength);

  return rawData;
});

// TODO: Make this more efficient
EM_JS(float*, webGLInterfaceGetUnsignedIntData, (unsigned int* unsignedIntData, unsigned int unsignedIntLength), {
  const bytesPerUnsignedInt = Uint16Array.BYTES_PER_ELEMENT;
  const rawData = new Uint32Array(Module.HEAPU8.buffer, unsignedIntData, unsignedIntLength);

  return rawData;
});

// TODO: Make this more efficient
EM_JS(float*, webGLInterfaceGetCharData, (const char* charData, unsigned int charLength), {
  const bytesPerUnsignedInt = Uint8Array.BYTES_PER_ELEMENT;
  const rawData = new Uint8Array(Module.HEAPU8.buffer, charData, charLength);

  return rawData;
});

// TODO: Make this more efficient
EM_JS(char*, webGLInterfaceGetString, (const char* charData, unsigned int charLength), {
  const bytesPerChar = Uint8Array.BYTES_PER_ELEMENT;
  const rawData = new Uint8Array(Module.HEAPU8.buffer, charData, charLength);

  var outputString = "";
  for (i = 0; i < charLength; i++) {
    outputString += String.fromCharCode(rawData[i]);
  }

  return outputString;
});

#endif
