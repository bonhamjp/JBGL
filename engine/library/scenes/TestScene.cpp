#include <iostream>

#include "TestScene.h"

#include "core/object/node/Node.h"

#include "library/cameras/FreeCamera.h"

// #include "../factories/MolequleFactory.h"

namespace DataGarden
{
  TestScene::TestScene() :
  Scene()
  {
    FreeCamera* freeCamera = new FreeCamera(0.0f, 1.0f, 2.0f);
    SetCamera(freeCamera);

    // WaterBear::Entity* camera = PlayerCameraFactory().Generate(m_EntityManager->RootEntity());
    // m_EntityManager->PushEntity(camera); // Should not be needed if attached to entity already in manager...
    // RegisterCameraEntity(camera);
  
    // WaterBear::Entity* molequle = MolequleFactory().Generate(m_EntityManager->RootEntity());
    // m_EntityManager->PushEntity(molequle);
    // molequle->GetTransform().SetPosition(glm::vec3(-1.0f, 2.0f, 3.0f));
  }

  TestScene::~TestScene()
  {}

  void TestScene::PreUpdate()
  {}

  void TestScene::PostUpdate()
  {}

  void TestScene::PreRender()
  {}

  void TestScene::PostRender()
  {}
}
