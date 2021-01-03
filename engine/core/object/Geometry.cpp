#include "Geometry.h"

#include "core/renderer/BufferLayout.h"
#include "core/renderer/VertexArray.h"
#include "core/renderer/VertexBuffer.h"
#include "core/renderer/IndexBuffer.h"

#include <iostream>

namespace DataGarden
{
  Geometry::Geometry()
  {}

  Geometry::~Geometry()
  {}

  VertexArray& Geometry::GetVertexArray()
  {
    return *m_VertexArray;
  }

  VertexBuffer& Geometry::GetVertexBuffer()
  {
    return *m_VertexBuffer;
  }

  IndexBuffer& Geometry::GetIndexBuffer()
  {
    return *m_IndexBuffer;
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
    // TODO: Cleanup textures
  }
}
