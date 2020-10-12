#ifndef DATA_GARDEN_WEBGL_INTERFACE_VERTEX_ARRAY
#define DATA_GARDEN_WEBGL_INTERFACE_VERTEX_ARRAY

#include <emscripten.h>

EM_JS(unsigned int, webGLInterfaceCreateVertexArray, (), {
  const vertexArrayID = document.webGLModule.vertexArrayCount;

  document.webGLModule.vertexArrays.push(document.webGLModule.context.createVertexArray());
  document.webGLModule.vertexArrayCount++;
  
  return vertexArrayID;
});

EM_JS(unsigned int, webGLInterfaceBindVertexArray, (unsigned int vertexArrayID), {
  var vertexArray = document.webGLModule.vertexArrays[vertexArrayID];
  document.webGLModule.context.bindVertexArray(vertexArray);
});

EM_JS(unsigned int, webGLInterfaceDeleteVertexArray, (unsigned int vertexArrayID), {
  var vertexArray = document.webGLModule.vertexArrays[vertexArrayID];
  document.webGLModule.context.deleteVertexArray(vertexArray);
});

#endif
