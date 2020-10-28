#include <iostream>

#include <emscripten.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include "Renderer.h"

#include "webgl_interface/WebGLInterface.h"

#include "VertexArray.h"
#include "IndexBuffer.h"

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

    m_Shader->Bind();
  }

  void Renderer::PostRender()
  {}

  void Renderer::SetBufferColor(float r, float g, float b, float a)
  {
    webGLInterfaceSetBufferColor(r, g, b, a);
  }

  void Renderer::SetViewProjection(Camera* camera)
  {
    glm::mat4 viewProjection = camera->GetViewProjection() * camera->GetTransform().ViewMatrix();
    SetUniformMatrix4fv(m_Shader->GetProgramID(), "u_ViewProjection", viewProjection);

    glm::vec3 position = camera->GetTransform().GetPosition();
    SetUniform3fv(m_Shader->GetProgramID(), "u_ViewPosition", position);
  }

  void Renderer::RenderNode(Node* node)
  {
    Mesh* mesh = node->GetMesh();
    Material* material = node->GetMaterial();

    Geometry* geometry = mesh->GetGeometry();

    geometry->GetVertexArray().Bind();
    geometry->GetIndexBuffer().Bind();

    glm::mat4 model = node->GetTransform().GetModel();
		SetUniformMatrix4fv(m_Shader->GetProgramID(), "m_Vertex.Model", model);

    // TODO: Move shader implementation to better place
		// Fragment data
		SetUniform1f(m_Shader->GetProgramID(), "u_Material.Shininess", material->GetShininess());

		DrawIndexed(geometry->GetIndexCount());



    // Mesh& mesh = entity->GetMesh();
    // Material& material = entity->GetMaterial();

    // Geometry* geometry = mesh.GetGeometry();
    
    // geometry->GetVertexArray().Bind();

		// // TODO: Move shader implementation to better place
		// // Vertex data
		// glm::mat4 model = entity->GetTransform().GetModel();
		// Render::SetUniformMatrix4fv(m_BaseShader.get(), model, "m_Vertex.Model");
    
		// // TODO: Move shader implementation to better place
		// // Fragment data
		// Render::SetUniform1f(m_BaseShader.get(), material.GetShininess(), "u_Material.Shininess");

    // auto ambientTextures = material.GetTextures(TextureType::Ambient);
    // Render::SetUniform1i(m_BaseShader.get(), ambientTextures.size(), "u_AmbientTextures");
    // if (ambientTextures.size() > 0)
    // {
    //   ambientTextures[0]->Bind();
    // }
    
    // auto diffuseTextures = material.GetTextures(TextureType::Diffuse);
    // Render::SetUniform1i(m_BaseShader.get(), diffuseTextures.size(), "u_DiffuseTextures");
    // if (diffuseTextures.size() > 0)
    // { 
    //   diffuseTextures[0]->Bind();
    // }
    
    // auto specularTextures = material.GetTextures(TextureType::Specular);
    // Render::SetUniform1i(m_BaseShader.get(), specularTextures.size(), "u_SpecularTextures");
    // if (specularTextures.size() > 0)
    // {
    //   specularTextures[0]->Bind();
    // }

    // geometry->GetIndexBuffer().Bind();

		// Render::DrawIndexed(geometry->GetIndexCount());
  }
  
  void Renderer::ClearBuffer()
  {
    webGLInterfaceClearBuffer();
  }

  void Renderer::SetViewport()
  {
    Canvas& canvas = Engine::Get().GetCanvas();

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
    char* shaderSource = (char*) shaderSourceString.c_str();
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

  void Renderer::VertexBufferData(float* vertexData, unsigned int vertexLength)
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

  void Renderer::IndexBufferData(unsigned int* indexData, unsigned int indexLength)
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

  void Renderer::SetUniformMatrix4fv(unsigned int shaderID, const char* uniformName, glm::mat4 uniformMatrix)
  {
    webGLInterfaceSetUniformMatrix4fv(shaderID, uniformName, strlen(uniformName), glm::value_ptr(uniformMatrix));
  }

  void Renderer::SetUniform4fv(unsigned int shaderID, const char* uniformName, glm::vec4 uniformVector)
  {
    webGLInterfaceSetUniform4fv(shaderID, uniformName, strlen(uniformName), glm::value_ptr(uniformVector));
  }

  void Renderer::SetUniform3fv(unsigned int shaderID, const char* uniformName, glm::vec3 uniformVector)
  {
    webGLInterfaceSetUniform3fv(shaderID, uniformName, strlen(uniformName), glm::value_ptr(uniformVector));
  }

  void Renderer::SetUniform1f(unsigned int shaderID, const char* uniformName, float uniformFloat)
  {

  }

  void Renderer::SetUniform1i(unsigned int shaderID, const char* uniformName, int uniformInteger)
  {

  }

  void Renderer::DrawIndexed(unsigned int count)
  {
    // glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
  }

  void Renderer::_Setup()
  {
    webGLInterfaceSetupContext();

    m_Shader = new Shader(ShaderVertexSource::BASE, ShaderFragmentSource::BASE);
  
    webGLInterfaceSetBufferColor(0.0f, 0.0f, 0.0f, 1.0f);
    webGLInterfaceClearBuffer();
  }

  void Renderer::_Teardown()
  {
    delete m_Shader;

    webGLInterfaceTeardownContext();
  }
}
