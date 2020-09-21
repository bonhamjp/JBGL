#ifndef DATA_GARDEN_MESH
#define DATA_GARDEN_MESH

#include "DataGarden.h"

#include "core/resource_manager/ResourceManager.h"

#include "core/renderer/Geometry.h"

namespace DataGarden
{
  // forward declarations
  class Node;

  class Mesh
  {
  public:
    Mesh(Node* node);
    Mesh(Node* node, ResourceDescriptor* geometryDescriptor, Geometry(*Geometry)(ResourceDescriptor* descriptor));
    ~Mesh();

    inline Geometry* GetGeometry() { return m_Geometry; };

  private:
    Node* m_Node;
    Geometry* m_Geometry;
  };
}

#endif
