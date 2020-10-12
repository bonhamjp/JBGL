#ifndef DATA_GARDEN_INPUT_INTERFACE_SETUP
#define DATA_GARDEN_INPUT_INTERFACE_SETUP

#include <iostream>

#include <emscripten.h>

#include "InputInterfaceUtility.h"
#include "InputInterfaceEventHandlers.h"

EM_JS(void, inputInterfaceSetup, (), {
  document.addEventListener("keyup", function(e) {
    var convertedKeyCode = inputInterfaceKeyCodeConvert(e.keyCode);
    Module._onKeyUp(convertedKeyCode);
  });

  document.addEventListener("keydown", function(e) {
    var convertedKeyCode = inputInterfaceKeyCodeConvert(e.keyCode);
    Module._onKeyDown(convertedKeyCode);
  });
});

// TODO: Bind listeners to WebGL context

EM_JS(void, inputInterfaceTeardown, (), {
  // TODO: Any input teardown
});

#endif
