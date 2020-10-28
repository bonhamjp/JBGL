#ifndef DATA_GARDEN_WEBGL_INTERFACE_SHADER
#define DATA_GARDEN_WEBGL_INTERFACE_SHADER

#include <emscripten.h>

#include "WebGLInterfaceUtility.h"

EM_JS(unsigned int, webGLInterfaceCreateVertexShader, (), {
  const shaderID = document.webGLModule.shaderCount;
  
  document.webGLModule.shaders.push(document.webGLModule.context.createShader(document.webGLModule.context.VERTEX_SHADER));
  document.webGLModule.shaderCount++;
  
  console.log("VERTEX SHADER");
  console.log("-------------------");

  return shaderID;
});

EM_JS(unsigned int, webGLInterfaceCreateFragmentShader, (), {
  const shaderID = document.webGLModule.shaderCount;
  
  document.webGLModule.shaders.push(document.webGLModule.context.createShader(document.webGLModule.context.FRAGMENT_SHADER));
  document.webGLModule.shaderCount++;
  
  console.log("FRAGMENT SHADER");
  console.log("-------------------");

  return shaderID;
});

EM_JS(unsigned int, webGLInterfaceShaderSource, (unsigned int shaderID, char* shaderSource, unsigned int shaderSourceLength), {
  var shader = document.webGLModule.shaders[shaderID];
  var source = webGLInterfaceGetCharData(shaderSource, shaderSourceLength);
  document.webGLModule.context.shaderSource(shader, source);

  // console.log("Shder Source: \n" + source);
});

EM_JS(unsigned int, webGLInterfaceCompileShader, (unsigned int shaderID), {
  var shader = document.webGLModule.shaders[shaderID];
  document.webGLModule.context.compileShader(shader);

  var error = document.webGLModule.context.getShaderInfoLog(shader);
  console.log(error);
});

EM_JS(unsigned int, webGLInterfaceDeleteShader, (unsigned int shaderID), {
  var shader = document.webGLModule.shaders[shaderID];
  document.webGLModule.context.deleteShader(shader);

  document.webGLModule.shaders[shaderID] = null;
});

#endif
