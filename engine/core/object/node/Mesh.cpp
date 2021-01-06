#include "Mesh.h"

#include "core/Engine.h"

#include "core/renderer/BufferLayout.h"
#include "core/renderer/VertexArray.h"
#include "core/renderer/VertexBuffer.h"
#include "core/renderer/IndexBuffer.h"

#include "core/object/node/Node.h"

#include "core/object/Geometry.h"

namespace DataGarden
{
  Mesh::Mesh(Node* node, ResourceDescriptor* geometryDescriptor, Geometry*(*f)(ResourceDescriptor* descriptor))
  {
    m_Geometry = Engine::Get().GetGeometryManager().AddResource(geometryDescriptor, f);

    m_Node = node;
  }

  Mesh::~Mesh()
  {}

  void Mesh::PrepareForRender()
  {
    m_Geometry->GetVertexArray().Bind();
    m_Geometry->GetIndexBuffer().Bind();
  }
}
