#include "Mesh.h"

#include "core/Engine.h"

#include "core/object/node/Node.h"

namespace DataGarden
{
  Mesh::Mesh(Node* node)
  {
    // TODO: Remove, needs geometry descriptor
    m_Node = node;
  }

  Mesh::Mesh(Node* node, ResourceDescriptor* geometryDescriptor, Geometry(*Geometry)(ResourceDescriptor* descriptor))
  {
    // m_Geometry = Engine::Get().GetGeometryManager().AddResource(meshDescriptor, meshF);
    m_Node = node;
  }
  
  Mesh::~Mesh()
  {}
}
