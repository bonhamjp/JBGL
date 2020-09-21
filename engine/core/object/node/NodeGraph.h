#ifndef DATA_GARDEN_ENTITY_MANAGER
#define DATA_GARDEN_ENTITY_MANAGER

#include "DataGarden.h"

#include "Node.h"

namespace DataGarden
{
  class NodeGraph
  {
  public:
    NodeGraph();
    virtual ~NodeGraph();

    void Update();

    void Render();

    void ResetUpdateStatus();

    inline bool UpdatedInFrame() { return m_UpdatedInFrame; };

    // TODO: Add a way to lookup specific entities
    inline Node& GetRootNode() { return *m_RootNode; };
    void PushNode(Node* newNode); // takes ownership

  private:
    bool m_UpdatedInFrame;

    Node* m_RootNode;              
  };
}

#endif
