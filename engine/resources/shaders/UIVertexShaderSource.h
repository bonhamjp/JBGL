#ifndef DATA_GARDEN_UI_VERTEX_SHADER_SOURCE
#define DATA_GARDEN_UI_VERTEX_SHADER_SOURCE

#include <string>

const std::string UI_VERTEX_SHADER_SOURCE = R"(#version 300 es

precision highp float;

void main()
{
  gl_Position = vec4(1.0f);
}
)";

#endif
