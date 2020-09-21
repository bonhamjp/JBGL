#ifndef DATA_GARDEN_COMPONENT
#define DATA_GARDEN_COMPONENT

#include "DataGarden.h"

namespace DataGarden
{
  // Forward declarations
  class Node;

  class Component
  {
  public:
    Component(Node* node);
    ~Component();

    virtual void Update() = 0;

  protected:
    Node* m_Node;
  };
}

#endif
