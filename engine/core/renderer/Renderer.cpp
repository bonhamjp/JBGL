#include <iostream>

#include <emscripten.h>

#include "WebGLInterface.h"

#include "Renderer.h"

#include "core/Engine.h"
#include "core/canvas/Canvas.h"

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
  {}

  void Renderer::SetBufferColor(float r, float g, float b, float a)
  {
    glSetBufferColor(r, g, b, a);
  }
  
  void Renderer::ClearBuffer()
  {
    glClearBuffer();
  }

  void Renderer::SetViewport()
  {
    Canvas& canvas = Engine::Get().GetCanvas();

    glSetViewport(0, 0, canvas.GetWidth(), canvas.GetHeight());
  }

  unsigned int Renderer::CreateProgram()
  {
    return glCreateProgram();
  }

  void Renderer::UseProgram(unsigned int programID)
  {
    glUseProgram(programID);
  }

  void Renderer::AttachShader(unsigned int programID, unsigned int shaderID)
  {
    glAttachShader(programID, shaderID);
  }
  
  void Renderer::LinkProgram(unsigned int programID)
  {
    glLinkProgram(programID);
  }

  void Renderer::StopProgram()
  {
    glStopProgram();
  }

  void Renderer::DeleteProgram(unsigned int programID)
  {
    glDeleteProgram(programID);
  }

  unsigned int Renderer::CreateVertexShader()
  {
    return glCreateVertexShader();
  }

  unsigned int Renderer::CreateFragmentShader()
  {
    return glCreateFragmentShader();
  }
    
  void Renderer::ShaderSource(unsigned int programID, std::string shaderSourceString)
  {
    char* shaderSource = (char*) shaderSourceString.c_str();
    glShaderSource(programID, shaderSource);
  }
  
  void Renderer::CompileShader(unsigned int shaderID)
  {
    glCompileShader(shaderID);
  }

  void Renderer::DeleteShader(unsigned int shaderID)
  {
    glDeleteShader(shaderID);
  }

  unsigned int Renderer::CreateBuffer()
  {
    return glCreateBuffer();
  }

  void Renderer::DeleteBuffer(unsigned int bufferID)
  {
    glDeleteBuffer(bufferID);
  }

  void Renderer::BindVertexBuffer(unsigned int bufferID)
  {
    glBindVertexBuffer(bufferID);
  }

  void Renderer::VertexBufferData(float* vertexData)
  {
    glVertexBufferData(vertexData);
  }

  void Renderer::UnbindVertexBuffer()
  {
    glBindVertexBuffer(0);
  }

  void Renderer::BindIndexBuffer(unsigned int bufferID)
  {
    glBindIndexBuffer(bufferID);
  }

  void Renderer::IndexBufferData(unsigned int* indexData)
  {
    glIndexBufferData(indexData);
  }

  void Renderer::UnbindIndexBuffer()
  {
    glBindIndexBuffer(0);
  }

  unsigned int Renderer::CreateVertexArray()
  {
    return glCreateVertexArray();
  }

  void Renderer::BindVertexArray(unsigned int vertexArrayID)
  {
    glBindVertexArray(vertexArrayID);
  }

  void Renderer::unbindVertexArray()
  {
    glBindVertexArray(0);
  }

    void Renderer::DeleteVertexArray(unsigned int vertexArrayID)
  {
    glDeleteVertexArray(vertexArrayID);
  }

  void Renderer::_Setup()
  {
    new Shader(ShaderVertexSource::BASE, ShaderFragmentSource::BASE);
  
    glSetBufferColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClearBuffer();
  }

  void Renderer::_Teardown()
  {
    delete m_Shader;
  }
}
