#ifndef DATA_GARDEN_FRAGMENT_BASE
#define DATA_GARDEN_FRAGMENT_BASE

#include <string>

const std::string BASE_FRAGMENT_SHADER_SOURCE = R"(#version 300 es

precision highp float;

in vec4 f_Position;
in vec4 f_FragPosition;
in vec3 f_Normal;
in vec2 f_TextureCoordinates;

out vec4 o_Color;

struct Material
{
  float Shininess;
};
uniform Material u_Material;

uniform int u_AmbientTextures;
uniform sampler2D u_AmbientTexture;
uniform int u_DiffuseTextures;
uniform sampler2D u_DiffuseTexture;
uniform int u_SpecularTextures;
uniform sampler2D u_SpecularTexture;

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

vec4 CalculatePointLight(PointLight light, vec3 normal, vec3 fragPosition, vec3 viewDirection, vec4 ambientColor, vec4 diffuseColor, vec4 specularColor)
{
  // Calculations
  float distance = length(vec3(light.Position) - fragPosition);
  vec3 lightDirection = normalize(vec3(light.Position) - fragPosition);
  vec3 lightReflection = reflect(-lightDirection, normal);

  // Attenuation
  float attenuation = 1.0 / (light.ConstantS + light.LinearS * distance + light.QuadraticS * (distance * distance));

  // Ambient
  vec4 ambient = (light.AmbientColor * ambientColor) * attenuation;

  // Diffuse
  float lightNormalAngle = max(dot(normal, lightDirection), 0.0);
  vec4 diffuse = (light.DiffuseColor * (lightNormalAngle * diffuseColor)) * attenuation;

  // Specular
  float specularHighlight = pow(max(dot(viewDirection, lightReflection), 0.0), u_Material.Shininess);
  vec4 specular = (light.SpecularColor * (specularHighlight * specularColor)) * attenuation;

  return ambient + diffuse + specular;
}

vec4 CalculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDirection, vec4 ambientColor, vec4 diffuseColor, vec4 specularColor)
{
  // Calculations
  vec3 fragmentTowardsLightDirection = normalize(vec3(-light.Direction));
  vec3 lightReflection = reflect(-fragmentTowardsLightDirection, normal);

  // Ambient
  vec4 ambient = light.AmbientColor * ambientColor;

  // Diffuse
  float lightAngle = max(dot(normal, fragmentTowardsLightDirection), 0.0);
  vec4 diffuse = light.DiffuseColor * (lightAngle * diffuseColor);

  // Specular
  float specularHighlight = pow(max(dot(viewDirection, lightReflection), 0.0), u_Material.Shininess);
  vec4 specular = light.SpecularColor * (specularHighlight * specularColor);

  return ambient + diffuse + specular;
}

vec4 CalculateSpotLight(SpotLight light, vec3 normal, vec3 fragPosition, vec3 viewDirection, vec4 ambientColor, vec4 diffuseColor, vec4 specularColor)
{
  // Calculations
  float distance = length(vec3(light.Position) - fragPosition);
  vec3 lightDirection = normalize(vec3(light.Position) - fragPosition);
  vec3 lightReflection = reflect(-lightDirection, normal);

  // Attenuation
  float attenuation = 1.0 / (light.ConstantS + light.LinearS * distance + light.QuadraticS * (distance * distance));

  // Spotlight boundries
  float theta = dot(lightDirection, normalize(vec3(-light.Direction)));
  float epsilon = light.InnerCutoff - light.OuterCutoff;
  float intensity = clamp((theta - light.OuterCutoff) / epsilon, 0.0, 1.0);

  // Ambient
  vec4 ambient = (light.AmbientColor * ambientColor) * attenuation;

  // Diffuse
  float lightNormalAngle = max(dot(normal, lightDirection), 0.0);
  vec4 diffuse = (light.DiffuseColor * (lightNormalAngle * diffuseColor)) * attenuation * intensity;

  // Specular
  float specularHighlight = pow(max(dot(viewDirection, lightReflection), 0.0), u_Material.Shininess);
  vec4 specular = (light.SpecularColor * (specularHighlight * specularColor)) * attenuation * intensity;

  return ambient + diffuse + specular;
}

void main() {
  vec3 normal = normalize(vec3(f_Normal));
  vec3 viewDirection = normalize(vec3(f_Position) - vec3(f_FragPosition));

  o_Color = vec4(0.0f, 0.0f, 0.0f, 1.0f);

  // // FIX: Specular color does not work correctly
  // vec4 specularColor = vec4(0.0f, 0.0f, 0.0f, 1.0f); //texture(u_SpecularTexture, f_TextureCoordinates);

  vec4 ambientColor = texture(u_AmbientTexture, f_TextureCoordinates);
  vec4 diffuseColor = texture(u_DiffuseTexture, f_TextureCoordinates);

  // FIX: Specular color does not work correctly
  vec4 specularColor = vec4(0.0f, 0.0f, 0.0f, 1.0f); //texture(u_SpecularTexture, f_TextureCoordinates);

  for (int i = 0; i < u_PointLightCount; i++)
  {
    o_Color += CalculatePointLight(u_PointLights[i], normal, vec3(f_FragPosition), viewDirection, ambientColor, diffuseColor, specularColor);
  }

  for (int i = 0; i < u_DirectionalLightCount; i++)
  {
    o_Color += CalculateDirectionalLight(u_DirectionalLights[i], normal, viewDirection, ambientColor, diffuseColor, specularColor);
  }

  for (int i = 0; i < u_SpotLightCount; i++)
  {
    o_Color += CalculateSpotLight(u_SpotLights[i], normal, vec3(f_FragPosition), viewDirection, ambientColor, diffuseColor, specularColor);
  }
}
)";

#endif
