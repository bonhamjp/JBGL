#ifndef DATA_GARDEN_WEBGL_INTERFACE_UNIFORM
#define DATA_GARDEN_WEBGL_INTERFACE_UNIFORM

#include <emscripten.h>

EM_JS(
  unsigned int, 
  webGLInterfaceSetUniformMatrix4fv, (
    unsigned int programID, 
    const char* uniformName, 
    unsigned int uniformNameLength, 
    float* matrixData
  ), {
  
  var program = document.webGLModule.programs[programID];
  
  // TODO: Store Uniform Location somewhere so that parsing string is not needed every call
  var name = webGLInterfaceGetCharData(uniformName, uniformNameLength);
  var location = document.webGLModule.context.getUniformLocation(program, name);
  
  var matrix = new Float32Array(webGLInterfaceGetFloatData(matrixData, 16));

  document.webGLModule.context.uniformMatrix4fv(location, false, matrix);
});

EM_JS(
  unsigned int, 
  webGLInterfaceSetUniform4fv, (
    unsigned int programID, 
    const char* uniformName, 
    unsigned int uniformNameLength, 
    float* vectorData
  ), {
  
  var program = document.webGLModule.programs[programID];
  
  // TODO: Store Uniform Location somewhere so that parsing string is not needed every call
  var name = webGLInterfaceGetCharData(uniformName, uniformNameLength);
  var location = document.webGLModule.context.getUniformLocation(program, name);
  
  var vector = new Float32Array(webGLInterfaceGetFloatData(vectorData, 4));

  document.webGLModule.context.uniform4fv(location, vector);
});

EM_JS(
  unsigned int, 
  webGLInterfaceSetUniform3fv, (
    unsigned int programID, 
    const char* uniformName, 
    unsigned int uniformNameLength,
    float* vectorData
  ), {
  
  var program = document.webGLModule.programs[programID];
  
  // TODO: Store Uniform Location somewhere so that parsing string is not needed every call
  var name = webGLInterfaceGetCharData(uniformName, uniformNameLength);
  var location = document.webGLModule.context.getUniformLocation(program, name);
  
  var vector = new Float32Array(webGLInterfaceGetFloatData(vectorData, 3));

  // document.webGLModule.context.uniform3fv(location, false, vector);
  document.webGLModule.context.uniform3fv(location, vector);
});

EM_JS(
  unsigned int, 
  webGLInterfaceSetUniform1f, (
    unsigned int programID, 
    const char* uniformName, 
    unsigned int uniformNameLength, 
    float floatData
  ), {
  
  var program = document.webGLModule.programs[programID];
  
  // TODO: Store Uniform Location somewhere so that parsing string is not needed every call
  var name = webGLInterfaceGetCharData(uniformName, uniformNameLength);
  var location = document.webGLModule.context.getUniformLocation(program, name);
  
  document.webGLModule.context.uniform1f(location, floatData);
});

EM_JS(
  unsigned int, 
  webGLInterfaceSetUniform1i, (
    unsigned int programID, 
    const char* uniformName, 
    unsigned int uniformNameLength, 
    unsigned int intData
  ), {
  
  var program = document.webGLModule.programs[programID];
  
  // TODO: Store Uniform Location somewhere so that parsing string is not needed every call
  var name = webGLInterfaceGetCharData(uniformName, uniformNameLength);
  var location = document.webGLModule.context.getUniformLocation(program, name);
  
  document.webGLModule.context.uniform1i(location, intData);
});

#endif
