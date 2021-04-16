#ifndef DATA_GARDEN_GRID_FRAGMENT_SHADER_SOURCE
#define DATA_GARDEN_GRID_FRAGMENT_SHADER_SOURCE

#include <string>

const std::string GRID_FRAGMENT_SHADER_SOURCE = R"(#version 300 es

precision highp float;

uniform vec3 u_PrimaryColor;
uniform vec3 u_SecondaryColor;

flat in int f_UsePrimaryColor;

out vec4 o_Color;

void main()
{
  if (f_UsePrimaryColor == 0)
  {
    o_Color = vec4(u_PrimaryColor, 1.0f);
  }
  else
  {
    o_Color = vec4(u_SecondaryColor, 1.0f);
  }
}
)";

#endif
