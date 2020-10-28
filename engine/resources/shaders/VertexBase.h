#ifndef DATA_GARDEN_VERTEX_BASE
#define DATA_GARDEN_VERTEX_BASE

#include <string>

const std::string BASE_VERTEX_SHADER_SOURCE = R"(#version 300 es

precision mediump float;
 
// attribute vec3 a_Position;
// attribute vec3 a_Normal;
// attribute vec2 a_TextureCoordinates;

layout(location = 0) in vec3 v_Position;
layout(location = 1) in vec3 v_Normal;
layout(location = 2) in vec2 v_TextureCoordinates;

out vec3 f_Position;
out vec3 f_Normal;
out vec2 f_TextureCoordinates;

uniform mat4 u_ViewProjection;
uniform vec3 u_ViewPosition;

void main()
{
  f_Position = v_Position;
  f_Normal = vec3(1.0, 2.0, 3.0);
  f_TextureCoordinates = vec2(10.0, 20.0);

  gl_Position = vec4(v_Position, 1.0);
}
)";

#endif
