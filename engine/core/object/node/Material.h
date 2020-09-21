#ifndef DATA_GARDEN_MATERIAL_COMPONENT
#define DATA_GARDEN_MATERIAL_COMPONENT

#include "DataGarden.h"

#include "core/resource_manager/ResourceManager.h"

#include "core/renderer/Texture.h"

namespace DataGarden
{
  // forward declarations
  class Node;

  class Material
  {
  public:
    Material(Node* node);
    Material(Node* node, ResourceDescriptor* meshDescriptor, Texture(*texture)(ResourceDescriptor* descriptor));
    ~Material();

    inline Texture* GetTexture() { return m_Texture; };

  private:
    Texture* m_Texture;
  };
}

#endif
