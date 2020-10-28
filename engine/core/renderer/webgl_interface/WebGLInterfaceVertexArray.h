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
  webGLInterfaceVertexAttribPointer, (
    unsigned int attribPosition,
    unsigned int size,
    unsigned int type,
    bool normalize,
    unsigned int stride,
    unsigned int offset
  ), {

  var webGLDataType = -1;

  // TODO: Find a way to retrieve this from a method
  switch(type) {
    case 1:
      console.log("WebGL Data typs is FLOAT");
      webGLDataType = document.webGLModule.context.FLOAT;
      break;

    case 2:
      console.log("WebGL Data typs is FLOAT VEC 2");
      webGLDataType = document.webGLModule.context.FLOAT_VEC2;
      break;

    case 3:
      console.log("WebGL Data typs is FLOAT VEC 3");
      webGLDataType = document.webGLModule.context.FLOAT_VEC3;
      break;

    case 4:
      console.log("WebGL Data typs is FLOAT VEC 4");
      webGLDataType = document.webGLModule.context.FLOAT_VEC4;
      break;

    case 5:
      console.log("WebGL Data typs is FLOAT MAT 3");
      webGLDataType = document.webGLModule.context.FLOAT_MAT3;
      break;

    case 6:
      console.log("WebGL Data typs is FLOAT MAT 4");
      webGLDataType = document.webGLModule.context.FLOAT_MAT4;
      break;

    case 7:
      console.log("WebGL Data typs is INT");
      webGLDataType = document.webGLModule.context.INT;
      break;

    case 8:
      console.log("WebGL Data typs is INT VEC 2");
      webGLDataType = document.webGLModule.context.INT_VEC2;
      break;

    case 9:
      console.log("WebGL Data typs is INT VEC 3");
      webGLDataType = document.webGLModule.context.INT_VEC3;
      break;

    case 10:
      console.log("WebGL Data typs is INT VEC 4");
      webGLDataType = document.webGLModule.context.INT_VEC4;
      break;

    case 11:
      console.log("WebGL Data typs is BOOL");
      webGLDataType = document.webGLModule.context.BOOL;
      break;

  }

  // var webGLDataType = webGLInterfaceRetrieveBufferDataType(type);
  
  document.webGLModule.context.vertexAttribPointer(
    attribPosition,
    size,
    webGLDataType,
    normalize,
    stride,
    offset
  );
});

EM_JS(unsigned int, webGLInterfaceDeleteVertexArray, (unsigned int vertexArrayID), {
  var vertexArray = document.webGLModule.vertexArrays[vertexArrayID];
  document.webGLModule.context.deleteVertexArray(vertexArray);
});

EM_JS(unsigned int, webGLInterfaceRetrieveBufferDataType, (unsigned int rawBufferEnum), {
  // TODO: Find a way to safely map BufferLayout enum to the WebGL interface types, to avoid getting out of sync
  switch(rawBufferEnum) {
    case 0:
      console.log("WebGL Data typs is NONE");
      return 0;
      break;

    case 1:
      console.log("WebGL Data typs is FLOAT");
      return document.webGLModule.context.FLOAT;
      break;

    case 2:
      console.log("WebGL Data typs is FLOAT VEC 2");
      return document.webGLModule.context.FLOAT_VEC2;
      break;

    case 3:
      console.log("WebGL Data typs is FLOAT VEC 3");
      return document.webGLModule.context.FLOAT_VEC3;
      break;

    case 4:
      console.log("WebGL Data typs is FLOAT VEC 4");
      return document.webGLModule.context.FLOAT_VEC4;
      break;

    case 5:
      console.log("WebGL Data typs is FLOAT MAT 3");
      return document.webGLModule.context.FLOAT_MAT3;
      break;

    case 6:
      console.log("WebGL Data typs is FLOAT MAT 4");
      return document.webGLModule.context.FLOAT_MAT4;
      break;

    case 7:
      console.log("WebGL Data typs is INT");
      return document.webGLModule.context.INT;
      break;

    case 8:
      console.log("WebGL Data typs is INT VEC 2");
      return document.webGLModule.context.INT_VEC2;
      break;

    case 9:
      console.log("WebGL Data typs is INT VEC 3");
      return document.webGLModule.context.INT_VEC3;
      break;

    case 10:
      console.log("WebGL Data typs is INT VEC 4");
      return document.webGLModule.context.INT_VEC4;
      break;

    case 11:
      console.log("WebGL Data typs is BOOL");
      return document.webGLModule.context.BOOL;
      break;

    default:
      console.log("WebGL Data typs is not found");
      return 0;

  }
});

#endif
