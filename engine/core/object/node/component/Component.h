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
    Component(Node *node);
    ~Component();

    void AttachNode(Node *node) { m_Node = node; };

    virtual void Setup() = 0;

    virtual void Update() = 0;

  protected:
    Node *m_Node;
  };
} // namespace DataGarden

#endif
