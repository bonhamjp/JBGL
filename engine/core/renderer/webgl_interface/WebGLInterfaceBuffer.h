#ifndef DATA_GARDEN_WEBGL_INTERFACE_BUFFER
#define DATA_GARDEN_WEBGL_INTERFACE_BUFFER

#include <emscripten.h>

EM_JS(unsigned int, webGLInterfaceCreateBuffer, (), {
  const bufferID = document.webGLModule.bufferCount;

  document.webGLModule.buffers.push(document.webGLModule.context.createBuffer());
  document.webGLModule.bufferCount++;

  return bufferID;
});

EM_JS(void, webGLInterfaceBindVertexBuffer, (unsigned int bufferID), {
  var buffer = document.webGLModule.buffers[bufferID];
  document.webGLModule.context.bindBuffer(document.webGLModule.context.ARRAY_BUFFER, buffer);
});

EM_JS(void, webGLInterfaceVertexBufferData, (float *vertexData, unsigned int vertexLength), {
  var context = document.webGLModule.context;
  var vertices = new Float32Array(webGLInterfaceGetFloatData(vertexData, vertexLength));
  context.bufferData(context.ARRAY_BUFFER, vertices, context.STATIC_DRAW);
});

EM_JS(void, webGLInterfaceBindIndexBuffer, (unsigned int bufferID), {
  var buffer = document.webGLModule.buffers[bufferID];
  document.webGLModule.context.bindBuffer(document.webGLModule.context.ELEMENT_ARRAY_BUFFER, buffer);
});

EM_JS(void, webGLInterfaceIndexBufferData, (unsigned int *indexData, unsigned int indexLength), {
  var context = document.webGLModule.context;
  var indices = new Uint32Array(webGLInterfaceGetUnsignedIntData(indexData, indexLength));
  context.bufferData(context.ELEMENT_ARRAY_BUFFER, indices, context.STATIC_DRAW);
});

EM_JS(void, webGLInterfaceDeleteBuffer, (unsigned int bufferID), {
  var buffer = document.webGLModule.buffers[bufferID];
  document.webGLModule.context.deleteBuffer(buffer);

  document.webGLModule.buffers[bufferID] = null;
});

#endif
