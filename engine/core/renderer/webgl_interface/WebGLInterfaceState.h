#ifndef DATA_GARDEN_WEBGL_INTERFACE_STATE
#define DATA_GARDEN_WEBGL_INTERFACE_STATE

#include <emscripten.h>

#include "WebGLInterfaceUtility.h"

EM_JS(void, webGLInterfaceEnableDepthTest, (), {
  document.webGLModule.context.enable(document.webGLModule.context.DEPTH_TEST);
});

EM_JS(void, webGLInterfaceDisableDepthMask, (), {
  document.webGLModule.context.depthMask(false);
});

EM_JS(void, webGLInterfaceEnableSampleCoverage, (), {
  document.webGLModule.context.enable(document.webGLModule.context.SAMPLE_COVERAGE);
});

EM_JS(void, webGLInterfaceSetSampleCoverage, (float sampleCoverage), {
  document.webGLModule.context.sampleCoverage(sampleCoverage, false);
});

EM_JS(void, webGLInterfaceSetBufferColor, (float r, float g, float b, float a), {
  document.webGLModule.context.clearColor(r, g, b, a);
});

EM_JS(void, webGLInterfaceClearBuffer, (), {
  document.webGLModule.context.clear(document.webGLModule.context.COLOR_BUFFER_BIT);
});

EM_JS(void, webGLInterfaceSetViewport, (unsigned int x, int y, unsigned int width, unsigned int height), {
  document.webGLModule.context.viewport(x, y, width, height);
});

EM_JS(void, webGLInterfaceDrawIndexed, (unsigned int count), {
  document.webGLModule.context.drawElements(document.webGLModule.context.TRIANGLES, count, document.webGLModule.context.UNSIGNED_INT, 0);
});

EM_JS(void, webGLInterfaceDrawIndexedLineStrip, (unsigned int count), {
  document.webGLModule.context.drawElements(document.webGLModule.context.LINE_STRIP, count, document.webGLModule.context.UNSIGNED_INT, 0);
});

#endif
