#include "Component.h"

#include "core/object/node/Node.h" 

namespace DataGarden
{
  Component::Component(Node* node)
  {
    m_Node = node;
  }

  Component::~Component()
  {}
}

