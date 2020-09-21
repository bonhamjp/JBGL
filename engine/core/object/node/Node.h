#ifndef DATA_GARDEN_NODE
#define DATA_GARDEN_NODE

#include "DataGarden.h"

#include "core/object/Object.h"

#include <map>

#define MAX_CHILD_COUNT 8

namespace DataGarden
{
  // forward declarations
  class Component;
  class Mesh;
  class Material;

  class Node : Object
  {
  public:
    Node();
    Node(Node* parentNode);
    ~Node();

    void Update(glm::mat4 space);
    void Render();

    template<typename T, typename... TArgs>
    T* AddComponent(TArgs&&... args) // TODO: Stop returning raw pointer
    {
      T* newComponent = new T(std::forward<TArgs>(args)...);

      m_Components[ClassID<T>()] = std::unique_ptr<Component>((Component*) newComponent);

      return newComponent;
    }
    
    template<typename T>
    bool HasComponent()
    {
      return m_Components.count(ClassID<T>()) != 0;
    }

    template<typename T>
    T* GetComponent()
    {
      return (T*) m_Components.at(ClassID<T>()).get();
    }

    void PushChild(Node* childNode);
    void ClearChildren();

    inline bool ShouldRemove() { return !m_Active; };
    void Destroy();
    
  protected:
    bool m_Active;

    Mesh* m_Mesh;
    Material* m_Material;

    std::map<unsigned int, Component*> m_Components;

    Node* m_Parent;

    unsigned int m_ChildCount;
    Node* m_Children[MAX_CHILD_COUNT];

  private:
    void _ClearChildAtIndex(unsigned int childIndex);
  };
}

#endif
