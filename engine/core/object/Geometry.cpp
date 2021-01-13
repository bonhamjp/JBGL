#include "Geometry.h"

#include "core/renderer/BufferLayout.h"
#include "core/renderer/VertexArray.h"
#include "core/renderer/VertexBuffer.h"
#include "core/renderer/IndexBuffer.h"

#include <iostream>

namespace DataGarden
{
  Geometry::Geometry()
  {
  }

  Geometry::~Geometry()
  {
  }

  void Geometry::_Initialize()
  {
    m_VertexBuffer = new VertexBuffer(m_GeometryBuffer.Vertices, GetVertexSize());
    m_VertexBuffer->SetLayout(GetLayout());

    m_IndexBuffer = new IndexBuffer(m_GeometryBuffer.Indices, m_IndexCount);

    m_VertexArray = new VertexArray();

    m_VertexArray->AddVertexLayout(m_VertexBuffer);
    m_VertexArray->AddIndexLayout(m_IndexBuffer);
  }

  void Geometry::_TearDown()
  {
    // TODO: Cleanup WebGL resources
  }
} // namespace DataGarden
