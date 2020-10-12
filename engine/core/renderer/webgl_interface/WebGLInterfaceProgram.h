#ifndef DATA_GARDEN_WEBGL_INTERFACE_PROGRAM
#define DATA_GARDEN_WEBGL_INTERFACE_PROGRAM

#include <emscripten.h>

#include "WebGLInterfaceUtility.h"

EM_JS(unsigned int, webGLInterfaceCreateProgram, (), {
  const programID = document.webGLModule.programCount;
  
  document.webGLModule.programs.push(document.webGLModule.context.createProgram());
  document.webGLModule.programCount++;
  
  return programID;
});

EM_JS(void, webGLInterfaceAttachShader, (unsigned int programID, unsigned int shaderID), {
  var program = document.webGLModule.programs[programID];
  var shader = document.webGLModule.shaders[shaderID];
  document.webGLModule.context.attachShader(program, shader);
});

EM_JS(void, webGLInterfaceLinkProgram, (unsigned int programID), {
  var program = document.webGLModule.programs[programID];
  document.webGLModule.context.linkProgram(program);
});

EM_JS(void, webGLInterfaceUseProgram, (unsigned int programID), {
  var program = document.webGLModule.programs[programID];
  document.webGLModule.context.useProgram(program);
});

EM_JS(void, webGLInterfaceStopProgram, (), {
  document.webGLModule.context.useProgram(0);
});

EM_JS(void, webGLInterfaceDeleteProgram, (unsigned int programID), {
  var program = document.webGLModule.programs[programID];
  document.webGLModule.context.deleteProgram(program);

  document.webGLModule.programs[programID] = null;
});

#endif
