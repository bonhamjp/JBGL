#include "Material.h"

#include "core/object/node/Node.h"

namespace DataGarden
{
  Material::Material(Node* node)
  {}

  Material::Material(Node* node, ResourceDescriptor* meshDescriptor, Texture(*texture)(ResourceDescriptor* descriptor))
  {}

  Material::~Material()
  {}
}
