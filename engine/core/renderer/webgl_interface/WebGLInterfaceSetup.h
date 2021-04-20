#ifndef DATA_GARDEN_WEBGL_INTERFACE_SETUP
#define DATA_GARDEN_WEBGL_INTERFACE_SETUP

#include <emscripten.h>

EM_JS(void, webGLInterfaceSetupContext, (), {
  var canvasNode = document.createElement("canvas");
  canvasNode.setAttribute("id", "visualization-canvas");
  canvasNode.setAttribute("width", window.innerWidth + "px");
  canvasNode.setAttribute("height", window.innerHeight + "px");
  document.body.appendChild(canvasNode);

  canvasElement = document.getElementById("visualization-canvas");

  // // Event listeners
  // canvasElement.addEventListener("mouseenter", function(e){
  //                                                  // Module._onMouseEnter();
  //                                              });

  // canvasElement.addEventListener("mouseleave", function(e){
  //                                                  // Module._onMouseLeave();
  //                                              });

  canvasElement.addEventListener(
      "mouseup", function(e) {
        Module._onMouseUp(1);
      });

  canvasElement.addEventListener(
      "mousedown", function(e) {
        Module._onMouseDown(1);
      });

  // Firefex handles pointer lock differently, so must be configured here
  canvasElement.requestPointerLock =
      canvasElement.requestPointerLock ||
      canvasElement.mozRequestPointerLock ||
      canvasElement.webkitRequestPointerLock;

  // TODO: Setup in a better way, and arrange both on and off pointer lock
  // in a clean way
  function mouseChangeCallback(e)
  {
  }

  function mouseMoveCallback(e)
  {
    var movementX = e.movementX ||
                    e.mozMovementX ||
                    e.webkitMovementX ||
                    0;
    var movementY = e.movementY ||
                    e.mozMovementY ||
                    e.webkitMovementY ||
                    0;

    Module._onMouseMove(movementX, movementY);
  }

  document.addEventListener("pointerlockchange", mouseChangeCallback, false);
  document.addEventListener("mozpointerlockchange", mouseChangeCallback, false);
  document.addEventListener("webkitpointerlockchange", mouseChangeCallback, false);
  document.addEventListener("mousemove", mouseMoveCallback, false);

  // Begin with pointer lock
  canvasElement.requestPointerLock();

  // TODO: Hook up mechanism to get out of pointer lock

  // TODO: Set this up somewhere else, this function should only setup WebGL stuff
  window.addEventListener(
      "resize", function(e) {
        Module._onCanvasDimensionChange(e.target.innerWidth, e.target.innerHeight);
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
  webGLModule["textures"] = [];
  webGLModule["textureCount"] = 0;

  document.webGLModule = webGLModule;

  // Must have WebGL Context setup before this can be called
  Module._onCanvasDimensionChange(window.innerWidth, window.innerHeight);
});

// TODO: Bind listeners to WebGL context

EM_JS(void, webGLInterfaceTeardownContext, (), {
  // TODO: Clear up Webgl state

  document.webGLModule = null;
});

// TODO: Unbind listeners to WebGL context

#endif
