#include "Mesh.h"

#include "core/Engine.h"

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
}
