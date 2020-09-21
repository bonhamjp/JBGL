#include "Geometry.h"

namespace DataGarden
{
  Geometry::Geometry()
  {}

  Geometry::~Geometry()
  {}

  void Geometry::_Initialize()
  {
    // m_VertexBuffer = Scope<VertexBuffer>(VertexBuffer::Create(m_GeometryBuffer.Vertices, GetVertexSize()));
    // m_VertexBuffer->SetLayout(GetLayout());

    // m_IndexBuffer = Scope<IndexBuffer>(IndexBuffer::Create(m_GeometryBuffer.Indices, m_IndexCount));

    // m_VertexArray = Scope<VertexArray>(VertexArray::Create());

    // m_VertexArray->AddVertexLayout(m_VertexBuffer.get());
    // m_VertexArray->AddIndexLayout(m_IndexBuffer.get());
  }

  void Geometry::_TearDown()
  {
    // TODO: Cleanup textures
  }
}
