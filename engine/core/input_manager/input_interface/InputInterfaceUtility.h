#ifndef DATA_GARDEN_INPUT_INTERFACE_UTILITY
#define DATA_GARDEN_INPUT_INTERFACE_UTILITY

#include <iostream>

#include <emscripten.h>

EM_JS(void, inputInterfaceKeyCodeConvert, (int keyCode), {
  var convertedKeyCode = keyCode;
  if (keyCode === 87) // up
  {
    convertedKeyCode = 119;
  }
  else if (keyCode === 83) // down
  {
    convertedKeyCode = 115;
  }
  else if (keyCode === 65) // left
  {
    convertedKeyCode = 97;
  }
  else if (keyCode === 68) // right
  {
    convertedKeyCode = 100;
  }

  return convertedKeyCode;
});

#endif
