#ifndef DATA_GARDEN_FRAGMENT_BASE
#define DATA_GARDEN_FRAGMENT_BASE

#include <string>

const std::string BASE_FRAGMENT_SHADER_SOURCE = R"(#version 300 es

precision highp float;

in vec4 f_Position;
in vec3 f_Normal;
in vec2 f_TextureCoordinates;

out vec4 o_Color;

#define NUMBER_OF_POINT_LIGHTS 32 
uniform int u_PointLightCount;
struct PointLight
{
  vec4 Position;

  vec4 AmbientColor;
  vec4 DiffuseColor;
  vec4 SpecularColor;

  float ConstantS;
  float LinearS;
  float QuadraticS;
};
uniform PointLight u_PointLights[NUMBER_OF_POINT_LIGHTS];

#define NUMBER_OF_DIRECTIONAL_LIGHTS 32
uniform int u_DirectionalLightCount;
struct DirectionalLight
{
  vec4 Direction;

  vec4 AmbientColor;
  vec4 DiffuseColor;
  vec4 SpecularColor;

  float cutOff;
};
uniform DirectionalLight u_DirectionalLights[NUMBER_OF_DIRECTIONAL_LIGHTS];

#define NUMBER_OF_Spot_LIGHTS 32 
uniform int u_SpotLightCount;
struct SpotLight
{
  vec4 Position;
  vec4 Direction;

  vec4 AmbientColor;
  vec4 DiffuseColor;
  vec4 SpecularColor;

  float ConstantS;
  float LinearS;
  float QuadraticS;

  // For blending edges of light boundry
  float InnerCutoff;
  float OuterCutoff;
};
uniform SpotLight u_SpotLights[NUMBER_OF_POINT_LIGHTS];

float clampColor(float color)
{
  float clampedColor = color;
  if (clampedColor < 0.0f)
  {
    clampedColor = 0.0f;
  }
  else if (clampedColor > 1.0f)
  {
    clampedColor = 1.0f;
  }
  return clampedColor;
}

void main() {
  o_Color = vec4(0.0, 0.5, 0.0, 1.0);

  // gl_FragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);
}
)";

#endif