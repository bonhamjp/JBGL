#include "RotationComponent.h"

#include "core/object/node/Node.h"

#include "core/Engine.h"
#include "core/clock/Clock.h"

namespace DataGarden
{
  RotationComponent::RotationComponent(Node *node, float yawMultiplier) : Component(node)
  {
    m_YawMultiplier = yawMultiplier;
  }

  RotationComponent::~RotationComponent()
  {
  }

  void RotationComponent::Setup()
  {
  }

  void RotationComponent::Update()
  {
    Clock &clock = Engine::Get().GetClock();
    float newRad = clock.GetCurrentTime() * m_YawMultiplier;

    m_Node->GetTransform().SetYaw(newRad);
  }
} // namespace DataGarden
