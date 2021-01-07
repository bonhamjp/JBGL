#include <iostream>

#include <emscripten.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Renderer.h"

#include "webgl_interface/WebGLInterface.h"

#include "VertexArray.h"
#include "IndexBuffer.h"

#include "utility/ColorTools.h"

#include "core/Engine.h"
#include "core/canvas/Canvas.h"

#include "core/object/node/Mesh.h"
#include "core/object/node/Material.h"

#include "core/object/Geometry.h"

namespace DataGarden
{
  Renderer::Renderer()
  {
    // float* testVertices = new float[6];
    // testVertices[0] = 4.2f;
    // testVertices[1] = 4.3f;
    // testVertices[2] = 4.4f;
    // testVertices[3] = 4.5f;
    // testVertices[4] = 4.6f;
    // testVertices[5] = 4.75f;

    // em_Test(testVertices, 6);

    // delete testVertices;

    // em_Test_String("SNOOTCHIES!!!");

    _Setup();
  }

  Renderer::~Renderer()
  {
    _Teardown();
  }

  void Renderer::PreRender()
  {
    ClearBuffer();
  }

  void Renderer::PostRender()
  {
  }

  void Renderer::SetBufferColor(float r, float g, float b, float a)
  {
    webGLInterfaceSetBufferColor(r, g, b, a);
  }

  void Renderer::ClearBuffer()
  {
    webGLInterfaceClearBuffer();
  }

  void Renderer::SetViewport()
  {
    Canvas &canvas = Engine::Get().GetCanvas();

    webGLInterfaceSetViewport(0, 0, canvas.GetWidth(), canvas.GetHeight());
  }

  unsigned int Renderer::CreateProgram()
  {
    return webGLInterfaceCreateProgram();
  }

  void Renderer::UseProgram(unsigned int programID)
  {
    webGLInterfaceUseProgram(programID);
  }

  void Renderer::AttachShader(unsigned int programID, unsigned int shaderID)
  {
    webGLInterfaceAttachShader(programID, shaderID);
  }

  void Renderer::LinkProgram(unsigned int programID)
  {
    webGLInterfaceLinkProgram(programID);
  }

  void Renderer::StopProgram()
  {
    webGLInterfaceStopProgram();
  }

  void Renderer::DeleteProgram(unsigned int programID)
  {
    webGLInterfaceDeleteProgram(programID);
  }

  unsigned int Renderer::CreateVertexShader()
  {
    return webGLInterfaceCreateVertexShader();
  }

  unsigned int Renderer::CreateFragmentShader()
  {
    return webGLInterfaceCreateFragmentShader();
  }

  void Renderer::ShaderSource(unsigned int programID, std::string shaderSourceString)
  {
    char *shaderSource = (char *)shaderSourceString.c_str();
    webGLInterfaceShaderSource(programID, shaderSource, strlen(shaderSource));
  }

  void Renderer::CompileShader(unsigned int shaderID)
  {
    webGLInterfaceCompileShader(shaderID);
  }

  void Renderer::DeleteShader(unsigned int shaderID)
  {
    webGLInterfaceDeleteShader(shaderID);
  }

  unsigned int Renderer::CreateBuffer()
  {
    return webGLInterfaceCreateBuffer();
  }

  void Renderer::DeleteBuffer(unsigned int bufferID)
  {
    webGLInterfaceDeleteBuffer(bufferID);
  }

  void Renderer::BindVertexBuffer(unsigned int bufferID)
  {
    webGLInterfaceBindVertexBuffer(bufferID);
  }

  void Renderer::VertexBufferData(float *vertexData, unsigned int vertexLength)
  {
    webGLInterfaceVertexBufferData(vertexData, vertexLength);
  }

  void Renderer::UnbindVertexBuffer()
  {
    webGLInterfaceBindVertexBuffer(-1);
  }

  void Renderer::BindIndexBuffer(unsigned int bufferID)
  {
    webGLInterfaceBindIndexBuffer(bufferID);
  }

  void Renderer::IndexBufferData(unsigned int *indexData, unsigned int indexLength)
  {
    webGLInterfaceIndexBufferData(indexData, indexLength);
  }

  void Renderer::UnbindIndexBuffer()
  {
    webGLInterfaceBindIndexBuffer(-1);
  }

  unsigned int Renderer::CreateVertexArray()
  {
    return webGLInterfaceCreateVertexArray();
  }

  void Renderer::BindVertexArray(unsigned int vertexArrayID)
  {
    webGLInterfaceBindVertexArray(vertexArrayID);
  }

  void Renderer::EnableVertexAttribArray(unsigned int vertexAttribPosition)
  {
    webGLInterfaceEnableVertexAttribArray(vertexAttribPosition);
  }

  void Renderer::VertexAttribPointer(unsigned int vertexAttribPosition, unsigned int size, unsigned int type, bool normalize, unsigned int stride, unsigned int offset)
  {
    webGLInterfaceVertexAttribPointer(vertexAttribPosition, size, type, normalize, stride, offset);
  }

  void Renderer::UnbindVertexArray()
  {
    webGLInterfaceBindVertexArray(-1);
  }

  void Renderer::DeleteVertexArray(unsigned int vertexArrayID)
  {
    webGLInterfaceDeleteVertexArray(vertexArrayID);
  }

  unsigned int Renderer::GenerateTexture()
  {
    return webGLInterfaceGenerateTexture();
  }

  void Renderer::TextureParameterITextureMinFilterNearest()
  {
    webGLInterfaceTextureParameterITextureMinFilterNearest();
  }

  void Renderer::TextureParameterITextureMagFilterNearest()
  {
    webGLInterfaceTextureParameterITextureMagFilterNearest();
  }

  void Renderer::TextureParameterITextureWrapSClampToEdge()
  {
    webGLInterfaceTextureParameterITextureWrapSClampToEdge();
  }

  void Renderer::TextureParameterITextureWrapTClampToEdge()
  {
    webGLInterfaceTextureParameterITextureWrapTClampToEdge();
  }

  void Renderer::BindTexture(unsigned int textureID)
  {
    webGLInterfaceBindTexture(textureID);
  }

  void Renderer::TexImage2D(unsigned char *textureData, unsigned int textureDataLength)
  {
    webGLInterfaceTexImage2D(textureData, textureDataLength);
  }

  void Renderer::activeTexture(TextureType textureType, unsigned int index)
  {
    // TODO: Manage Texture indices from Texture class
    unsigned int indicesPerType = 3;
    unsigned int indexMultiplier;

    switch (textureType)
    {
    case TextureType::Ambient:
      indexMultiplier = 0;
      break;

    case TextureType::Diffuse:
      indexMultiplier = 1;
      break;

    case TextureType::Specular:
      indexMultiplier = 2;
      break;

    default:
      std::cout << "Texture type not supported..." << std::endl;
    }

    unsigned int textureIndex = (indicesPerType * indexMultiplier) + index;

    webGLInterfaceActiveTexture(textureIndex);
  }

  void Renderer::UnbindTexture()
  {
    webGLInterfaceBindTexture(-1);
  }

  void Renderer::GenerateMipmap()
  {
    webGLInterfaceGenerateMipmap();
  }

  void Renderer::DeleteTexture(unsigned int textureID)
  {
    webGLInterfaceDeleteTexture(textureID);
  }

  void Renderer::SetUniformMatrix4fv(unsigned int shaderID, const char *uniformName, glm::mat4 uniformMatrix)
  {
    webGLInterfaceSetUniformMatrix4fv(shaderID, uniformName, strlen(uniformName), glm::value_ptr(uniformMatrix));
  }

  void Renderer::SetUniform4fv(unsigned int shaderID, const char *uniformName, glm::vec4 uniformVector)
  {
    webGLInterfaceSetUniform4fv(shaderID, uniformName, strlen(uniformName), glm::value_ptr(uniformVector));
  }

  void Renderer::SetUniform3fv(unsigned int shaderID, const char *uniformName, glm::vec3 uniformVector)
  {
    webGLInterfaceSetUniform3fv(shaderID, uniformName, strlen(uniformName), glm::value_ptr(uniformVector));
  }

  void Renderer::SetUniform1f(unsigned int shaderID, const char *uniformName, float uniformFloat)
  {
    webGLInterfaceSetUniform1f(shaderID, uniformName, strlen(uniformName), uniformFloat);
  }

  void Renderer::SetUniform1i(unsigned int shaderID, const char *uniformName, int uniformInteger)
  {
    webGLInterfaceSetUniform1i(shaderID, uniformName, strlen(uniformName), uniformInteger);
  }

  void Renderer::DrawIndexed(unsigned int count)
  {
    webGLInterfaceDrawIndexed(count);
    // webGLInterfaceDrawIndexedLineStrip(count);
  }

  void Renderer::_Setup()
  {
    _SetGlobalGraphicsState();
  }

  void Renderer::_SetGlobalGraphicsState()
  {
    webGLInterfaceSetupContext();

    webGLInterfaceEnableDepthTest();
    // webGLInterfaceDisableDepthMask();
    webGLInterfaceEnableSampleCoverage();
    webGLInterfaceSetSampleCoverage(4.5f);

    // webGLInterfaceSetBufferColor(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec4 backgroundColor = ColorFromHex(0xDAE4E7);
    webGLInterfaceSetBufferColor(backgroundColor.x, backgroundColor.y, backgroundColor.z, 1.0f);
    webGLInterfaceClearBuffer();
  }

  void Renderer::_Teardown()
  {
    webGLInterfaceTeardownContext();
  }
} // namespace DataGarden
