#include <iostream>

#include "DataGarden.h"

#include "TestScene.h"

#include "core/object/node/Node.h"

#include "utility/ColorTools.h"

#include "library/cameras/FreeCamera.h"

#include "library/lights/PointLight.h"
#include "library/lights/DirectionLight.h"
#include "library/lights/SpotLight.h"

#include "library/factories/CubeFactory.h"

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
      LightType::Directional, 
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

    Node* cube = CubeFactory::Create(
      glm::vec3(-1.0f, 2.0f, 3.0f),
      glm::vec3(1.0f),
      ColorFromHex(0x06AED5)
    );
    m_NodeGraph->PushNode(cube);
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
