#ifndef DATA_GARDEN_VERTEX_BASE
#define DATA_GARDEN_VERTEX_BASE

#include <string>

const std::string BASE_VERTEX_SHADER_SOURCE = R"( 

#version 100

precision mediump float;
 
attribute vec3 a_Position;
attribute vec3 a_Normal;
attribute vec2 a_TextureCoordinates;

varying vec3 v_Position;
varying vec3 v_Normal;
varying vec2 v_TextureCoordinates;

// out vec3 f_FragPosition;
// out vec3 f_Normal;
// out vec2 f_TextureCoordinates;

uniform mat4 u_ViewProjection;

void main()
{
  v_Position = a_Position;
  v_Normal = vec3(1.0, 2.0, 3.0);
  v_TextureCoordinates = vec2(10.0, 20.0);

  gl_Position = vec4(v_Position, 1.0);
}

)";

#endif
