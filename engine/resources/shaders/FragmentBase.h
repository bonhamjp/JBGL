#ifndef DATA_GARDEN_FRAGMENT_BASE
#define DATA_GARDEN_FRAGMENT_BASE

#include <string>

const std::string BASE_FRAGMENT_SHADER_SOURCE = R"(#version 300 es

precision mediump float;

in vec3 f_Position;
in vec3 f_Normal;
in vec2 f_TextureCoordinates;

out vec4 o_Color;
 
void main() {
  o_Color = vec4(0.18, 0.54, 0.34, 1.0);
}
)";

#endif