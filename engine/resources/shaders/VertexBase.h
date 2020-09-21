#ifndef DATA_GARDEN_VERTEX_BASE
#define DATA_GARDEN_VERTEX_BASE

#include <string>

const std::string BASE_VERTEX_SHADER_SOURCE = R"( 
precision mediump float;
 
varying vec4 v_positionWithOffset;
 
void main() {
  vec4 color = v_positionWithOffset * 0.5 + 0.5
  gl_FragColor = color;
}
)";

#endif
