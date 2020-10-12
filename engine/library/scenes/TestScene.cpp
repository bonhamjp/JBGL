#include <iostream>

#include "DataGarden.h"

#include "TestScene.h"

#include "core/object/node/Node.h"

#include "library/cameras/FreeCamera.h"
#include "library/lights/PointLight.h"
#include "library/lights/DirectionLight.h"
#include "library/lights/SpotLight.h"

namespace DataGarden
{
  TestScene::TestScene() :
  Scene()
  {
    FreeCamera* freeCamera = new FreeCamera(45.0f, 0.1f, 100.0f);
    freeCamera->SetTransform(
      Transform(glm::vec3(-6.0f, 0.0f, 3.0f), 
      glm::vec3(1.0f, 1.0f, 1.0f), 0.0f, 0.0f, 0.0f)
    );
    SetCamera(freeCamera);

    glm::vec4 whiteLight = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

    m_LightList->PushLightOfType(
      LightType::Direction, 
      new DirectionLight(glm::vec4(0.0f, 0.0f, -1.0f, 0.0f), whiteLight)
    );
    
    m_LightList->PushLightOfType(
      LightType::Point, 
      new PointLight(Transform(glm::vec3(-4.0f, 8.0f, -4.0f)), whiteLight, 1.0f, 0.045f, 0.0075f)
    );

    m_LightList->PushLightOfType(
      LightType::Spot,
      new SpotLight(glm::vec4(3.0f, 3.0f, 3.0f, 0.0f), whiteLight, 1.0f, 0.045f, 0.0075f, 12.5f, 17.5f)
    );

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
