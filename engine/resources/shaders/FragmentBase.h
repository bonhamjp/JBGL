#ifndef DATA_GARDEN_FRAGMENT_BASE
#define DATA_GARDEN_FRAGMENT_BASE

#include <string>

const std::string BASE_FRAGMENT_SHADER_SOURCE = R"( 

#version 100

precision mediump float;

varying vec3 v_Position;
varying vec3 v_Normal;
varying vec2 v_TextureCoordinates;
 
void main() {
  gl_FragColor = vec4(0.18, 0.54, 0.34, 1.0);
}

)";

#endif