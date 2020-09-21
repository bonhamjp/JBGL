#include "NodeGraph.h"

namespace DataGarden
{
  NodeGraph::NodeGraph()
  {
    m_RootNode = new Node();
  }

  NodeGraph::~NodeGraph()
  {}
  
  void NodeGraph::Update()
  {
    // TESTING
    m_UpdatedInFrame = true;

    // root node at origin
    m_RootNode->Update(glm::mat4(1.0f));
  }
  
  void NodeGraph::Render()
  {
    m_RootNode->Render();
  }

  void NodeGraph::ResetUpdateStatus()
  {
    m_UpdatedInFrame = false;
  }

  void NodeGraph::PushNode(Node* newNode)
  {
    m_RootNode->PushChild(newNode);
  }
}
