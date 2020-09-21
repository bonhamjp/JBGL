#ifndef DATA_GARDEN_FRAGMENT_BASE
#define DATA_GARDEN_FRAGMENT_BASE

#include <string>

const std::string BASE_FRAGMENT_SHADER_SOURCE = R"( 
attribute vec4 a_position;
 
uniform vec4 u_offset;
 
varying vec4 v_positionWithOffset;
 
void main() {
  gl_Position = a_position + u_offset;
  v_positionWithOffset = a_position + u_offset;
}
)";

#endif
