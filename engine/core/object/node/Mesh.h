#ifndef DATA_GARDEN_MESH
#define DATA_GARDEN_MESH

#include "DataGarden.h"

#include "core/resource_manager/ResourceManager.h"

namespace DataGarden
{
  // forward declarations
  class Node;
  class Geometry;

  class Mesh
  {
  public:
    Mesh(Node* node, ResourceDescriptor* geometryDescriptor, Geometry*(*f)(ResourceDescriptor* descriptor));
    ~Mesh();

    inline Geometry* GetGeometry() { return m_Geometry; };

    void PrepareForRender();

  private:
    Node* m_Node;
    Geometry* m_Geometry;
  };
}

#endif
