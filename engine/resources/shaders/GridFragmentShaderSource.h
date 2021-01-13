#ifndef DATA_GARDEN_GRID_FRAGMENT_SHADER_SOURCE
#define DATA_GARDEN_GRID_FRAGMENT_SHADER_SOURCE

#include <string>

const std::string GRID_FRAGMENT_SHADER_SOURCE = R"(#version 300 es

precision highp float;

uniform vec3 u_Color;

out vec4 o_Color;

void main()
{
  o_Color = vec4(u_Color, 1.0f);
}
)";

#endif
