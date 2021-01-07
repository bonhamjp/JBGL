#ifndef DATA_GARDEN_VISUALIZATION_2D_FRAGMENT_SHADER_SOURCE
#define DATA_GARDEN_VISUALIZATION_2D_FRAGMENT_SHADER_SOURCE

#include <string>

const std::string VISUALIZATION_2D_FRAGMENT_SHADER_SOURCE = R"(#version 300 es

precision highp float;

out vec4 o_Color;

void main()
{
  o_Color = vec4(0.0f, 0.0f, 0.0f, 1.0f);
}
)";

#endif
