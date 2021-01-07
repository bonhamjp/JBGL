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

EM_JS(unsigned int, webGLInterfaceEnableVertexAttribArray, (unsigned int attribPosition), {
  document.webGLModule.context.enableVertexAttribArray(attribPosition);
});

EM_JS(
    unsigned int,
    webGLInterfaceVertexAttribPointer, (unsigned int attribPosition, unsigned int size, unsigned int type, bool normalize, unsigned int stride, unsigned int offset), {
      var webGLDataType = webGLInterfaceRetrieveBufferDataType(type);

      document.webGLModule.context.vertexAttribPointer(
          attribPosition,
          size,
          webGLDataType,
          normalize,
          stride,
          offset);
    });

EM_JS(unsigned int, webGLInterfaceDeleteVertexArray, (unsigned int vertexArrayID), {
  var vertexArray = document.webGLModule.vertexArrays[vertexArrayID];
  document.webGLModule.context.deleteVertexArray(vertexArray);
});

EM_JS(unsigned int, webGLInterfaceRetrieveBufferDataType, (unsigned int rawBufferEnum), {
  // TODO: Find a way to safely map BufferLayout enum to the WebGL interface types, to avoid getting out of sync
  switch (rawBufferEnum)
  {
  case 0:
    console.log("WebGL Data typs is NONE");
    return 0;
    break;

  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
    return document.webGLModule.context.FLOAT;
    break;

  case 7:
  case 8:
  case 9:
  case 10:
    return document.webGLModule.context.INT;
    break;

  case 11:
    return document.webGLModule.context.BOOL;
    break;

  default:
    console.log("WebGL Data typs is not found");
    return 0;
  }
});

#endif
