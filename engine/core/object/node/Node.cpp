#include "Node.h"

#include "component/Component.h"

#include "core/Engine.h"

#include "Mesh.h"
#include "Material.h"

namespace DataGarden
{
  Node::Node() :
  Object()
  {
    m_Active = true;
    m_ChildCount = 0;
  }

  Node::Node(Node* parentNode) :
  Object()
  {
    m_Parent = parentNode;

    m_Active = true;
    m_ChildCount = 0;
  }
  
  Node::~Node()
  {}
  
  void Node::Update(glm::mat4 space)
  {
    // sets model space for frame
    m_Transform.UpdateModel(space);

    // update components first
    auto it = m_Components.begin();
    while (it != m_Components.end())
    {
      it->second->Update();

      it++;
    }

    // update children next
    for (int i = 0; i < m_ChildCount; i++)
    {
      // TODO: Pass by const reference, instead of copying matrix
      m_Children[i]->Update(m_Transform.GetModel());
    }

    // remove children marked for deletion
    ClearChildren();
  }

  void Node::Render()
  {
    // if (m_CanRender)
    // {
    //   Engine::Get().GetRenderer().RenderNode(this);
    // }

    // // render children next
    // for (int i = 0; i < m_ChildCount; i++)
    // {
    //   m_Children[i]->Render();
    // }
  }

  void Node::PushChild(Node* childNode)
  {
    m_Children[m_ChildCount++] = childNode;
  }

  void Node::ClearChildren()
  {
    for (int i = 0; i < m_ChildCount; i++)
    {
      if (i <= m_ChildCount && m_Children[i]->ShouldRemove())
      {
        _ClearChildAtIndex(i);
      }
    }
  }

  void Node::Destroy()
  {
    m_Active = false;
  }

  void Node::_ClearChildAtIndex(unsigned int childIndex)
  {
    delete m_Children[childIndex];

    for (int i = childIndex; i < m_ChildCount - 1; i++)
    {
      m_Children[i] = m_Children[i + 1];
    }

    m_ChildCount--;
  }
}