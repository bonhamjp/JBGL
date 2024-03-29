#include "Node.h"

#include "component/Component.h"

#include "core/Engine.h"

#include "core/scene/Scene.h"

#include "core/renderer/Renderer.h"

#include "core/object/Geometry.h"

#include "library/shaders/VisualizationShader.h"

#include "Mesh.h"
#include "Material.h"

#include <iostream>

namespace DataGarden
{
  Node::Node() : Object()
  {
    m_Active = true;
    m_CanRender = false;

    m_Mesh = nullptr;
    m_Material = nullptr;

    m_ChildCount = 0;
  }

  Node::Node(Node *parentNode) : Object()
  {
    m_Parent = parentNode;

    m_Active = true;
    m_CanRender = false;

    m_Mesh = nullptr;
    m_Material = nullptr;

    m_ChildCount = 0;
  }

  Node::~Node()
  {
  }

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
    if (m_CanRender)
    {
      _SetNodeUniforms();

      // TODO: Batch draw alike Nodes
      _DrawIndexedTriangles();
    }

    // render children next
    for (int i = 0; i < m_ChildCount; i++)
    {
      m_Children[i]->Render();
    }
  }

  void Node::SetMesh(Mesh *mesh)
  {
    m_Mesh = mesh;

    _UpdateCanRender();
  }

  void Node::SetMaterial(Material *material)
  {
    m_Material = material;

    _UpdateCanRender();
  }

  void Node::PushChild(Node *childNode)
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

  void Node::_UpdateCanRender()
  {
    m_CanRender = (m_Mesh != nullptr && m_Material != nullptr);
  }

  void Node::_SetNodeUniforms()
  {
    m_Mesh->PrepareForRender();

    VisualizationShader *visualizationShader = Engine::Get().GetShaderManager().GetVisualizationShader();
    visualizationShader->Bind();
    visualizationShader->SetModelUniform(m_Transform.GetModel());
    visualizationShader->Unbind();

    m_Material->SetMaterialUniforms();
  }

  void Node::_DrawIndexedTriangles()
  {
    Renderer &renderer = Engine::Get().GetRenderer();

    renderer.DrawIndexedTriangles(m_Mesh->GetGeometry()->GetIndexCount());
  }
} // namespace DataGarden
