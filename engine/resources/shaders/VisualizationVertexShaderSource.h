#ifndef DATA_GARDEN_VISUALIZATION_VERTEX_SHADER_SOURCE
#define DATA_GARDEN_VISUALIZATION_VERTEX_SHADER_SOURCE

#include <string>

const std::string VISUALIZATION_VERTEX_SHADER_SOURCE = R"(#version 300 es

precision highp float;

layout(location = 0) in vec3 v_Position;
layout(location = 1) in vec3 v_Normal;
layout(location = 2) in vec2 v_TextureCoordinates;

out vec4 f_Position;
out vec4 f_FragPosition;
out vec3 f_Normal;
out vec2 f_TextureCoordinates;

uniform mat4 u_ViewProjection;
uniform vec3 u_ViewPosition;

struct Vertex
{
  mat4 Model;
};
uniform Vertex u_Vertex;

void main()
{
  // f_TextureCoordinates = vec2(10.0, 20.0);

  gl_Position = u_ViewProjection * u_Vertex.Model * vec4(v_Position, 1.0f);

  f_Position = u_ViewProjection * u_Vertex.Model * vec4(v_Position, 1.0f);
  f_FragPosition = u_Vertex.Model * vec4(v_Position, 1.0f);

  f_Normal = mat3(transpose(inverse(u_Vertex.Model))) * v_Normal;
}
)";

#endif
