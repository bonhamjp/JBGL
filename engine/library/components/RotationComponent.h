#ifndef DATA_GARDEN_ROTATION_COMPONENT
#define DATA_GARDEN_ROTATION_COMPONENT

#include "DataGarden.h"

#include "core/object/node/component/Component.h"

namespace DataGarden
{
  // Forward declarations
  class Node;

  class RotationComponent : Component
  {
  public:
    RotationComponent(Node *node, float yawMultiplier);
    ~RotationComponent();

    virtual void Setup() override;

    virtual void Update() override;

  private:
    float m_YawMultiplier;
  };
} // namespace DataGarden

#endif
