#ifndef DATA_GARDEN_GRID_VERTEX_SHADER_SOURCE
#define DATA_GARDEN_GRID_VERTEX_SHADER_SOURCE

#include <string>

const std::string GRID_VERTEX_SHADER_SOURCE = R"(#version 300 es

precision highp float;

layout(location = 0) in vec3 v_Position;

out vec4 f_Position;
flat out int f_UsePrimaryColor;

uniform mat4 u_ViewProjection;
uniform vec3 u_ViewPosition;

struct Vertex
{
  mat4 Model;
};
uniform Vertex u_Vertex;

void main()
{
  gl_Position = u_ViewProjection * u_Vertex.Model * vec4(v_Position, 1.0f);

  f_Position = u_ViewProjection * u_Vertex.Model * vec4(v_Position, 1.0f);
  f_UsePrimaryColor = (gl_VertexID % 4) < 2 ? 0 : 1;
}
)";

#endif
