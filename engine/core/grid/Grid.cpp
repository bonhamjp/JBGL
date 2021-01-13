#include "Grid.h"

#include "core/Engine.h"

#include "core/renderer/Renderer.h"

#include "core/shader_manager/ShaderManager.h"

#include "core/renderer/BufferLayout.h"
#include "core/renderer/VertexArray.h"
#include "core/renderer/VertexBuffer.h"
#include "core/renderer/IndexBuffer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/vec3.hpp>

#include <iostream>

namespace DataGarden
{
  Grid::Grid(float precision)
  {
    m_Precision = precision;

    m_VertexStride = 3; // position
  }

  Grid::~Grid()
  {
  }

  void Grid::Render()
  {
    m_VertexArray->Bind();
    m_IndexBuffer->Bind();

    _SetGridUniforms();

    // TODO: Batch draw
    _DrawIndexedLines();
  }

  BufferLayout Grid::GetLayout()
  {
    return BufferLayout({{BufferDataType::Float3, "v_Position"}});
  }

  void Grid::_SetGridUniforms()
  {
    GridShader *gridShader = Engine::Get().GetShaderManager().GetGridShader();
    gridShader->Bind();
    // TODO: Store transform on in Grid for model, so that it can be propery scaled and positioned
    m_Transform.SetScale(glm::vec3(100.0f));
    m_Transform.SetPosition(glm::vec3(-50.0f, -50.0f, -50.0f));
    m_Transform.UpdateModel(glm::mat4(1.0f));
    gridShader->SetModelUniform(m_Transform.GetModel());
    // TODO: Store colors, at least a secondary and primary
    gridShader->SetColorUniform(glm::vec3(0.0f, 0.5f, 0.0f));
    gridShader->Unbind();
  }

  void Grid::_DrawIndexedLines()
  {
    GridShader *gridShader = Engine::Get().GetShaderManager().GetGridShader();
    gridShader->Bind();

    Renderer &renderer = Engine::Get().GetRenderer();

    renderer.DrawIndexedLines(m_IndexCount);

    gridShader->Unbind();
  }

  void Grid::_Initialize()
  {
    m_VertexBuffer = new VertexBuffer(m_GridBuffer.Vertices, GetVertexSize());
    m_VertexBuffer->SetLayout(GetLayout());

    m_IndexBuffer = new IndexBuffer(m_GridBuffer.Indices, m_IndexCount);

    m_VertexArray = new VertexArray();

    m_VertexArray->AddVertexLayout(m_VertexBuffer);
    m_VertexArray->AddIndexLayout(m_IndexBuffer);
  }

  void Grid::_TearDown()
  {
    // TODO: Cleanup WebGL resources
  }
} // namespace DataGarden
