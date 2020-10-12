#ifndef DATA_GARDEN_WEBGL_INTERFACE_SETUP
#define DATA_GARDEN_WEBGL_INTERFACE_SETUP

#include <emscripten.h>

EM_JS(void, webGLInterfaceSetupContext, (), {
  var canvasNode = document.createElement("canvas");
  canvasNode.setAttribute("id", "visualization-canvas");
  document.body.appendChild(canvasNode);

  canvasElement = document.getElementById("visualization-canvas");
  
  // Event listeners
  canvasElement.addEventListener("mouseenter", function(e) {
    // Module._onMouseEnter();
  });

  canvasElement.addEventListener("mouseleave", function(e) {
    // Module._onMouseLeave();
  });

  canvasElement.addEventListener("mouseup", function(e) {
    Module._onMouseUp(1);
  });

  canvasElement.addEventListener("mousedown", function(e) {
    Module._onMouseDown(1);
  });

  canvasElement.addEventListener("mousemove", function(e) {
    Module._onMouseMove(e.screenX, e.screenY);
  });

  // WebGL setup, and global state store
  var webGLContext = canvasElement.getContext("webgl2");

  var webGLModule = {};
  webGLModule["context"] = webGLContext;
  webGLModule["programs"] = [];
  webGLModule["programCount"] = 0;
  webGLModule["shaders"] = [];
  webGLModule["shaderCount"] = 0;
  webGLModule["buffers"] = [];
  webGLModule["bufferCount"] = 0;
  webGLModule["vertexArrays"] = [];
  webGLModule["vertexArrayCount"] = 0;

  document.webGLModule = webGLModule;
});

// TODO: Bind listeners to WebGL context

EM_JS(void, webGLInterfaceTeardownContext, (), {
  // TODO: Clear up Webgl state
  
  document.webGLModule = null;
});

// TODO: Unbind listeners to WebGL context


#endif
