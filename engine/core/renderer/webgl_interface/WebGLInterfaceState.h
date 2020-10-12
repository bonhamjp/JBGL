#ifndef DATA_GARDEN_WEBGL_INTERFACE_STATE
#define DATA_GARDEN_WEBGL_INTERFACE_STATE

#include <emscripten.h>

#include "WebGLInterfaceUtility.h"

EM_JS(void, webGLInterfaceSetBufferColor, (float r, float g, float b, float a), {
  document.webGLModule.context.clearColor(r, g, b, a);
});

EM_JS(void, webGLInterfaceClearBuffer, (), {
  document.webGLModule.context.clear(document.webGLModule.context.COLOR_BUFFER_BIT);
});

EM_JS(void, webGLInterfaceSetViewport, (unsigned int x, int y, unsigned int width, unsigned int height), {
  document.webGLModule.context.viewport(x, y, width, height);
});

#endif
