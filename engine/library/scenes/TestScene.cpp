#include <iostream>

#include "DataGarden.h"

#include "TestScene.h"

#include "utility/ColorTools.h"

#include "core/object/node/Node.h"
#include "core/object/node/Factory.h"

#include "library/cameras/3d/FreeCamera.h"
#include "library/cameras/2d/Camera2D.h"

#include "library/lights/PointLight.h"
#include "library/lights/DirectionalLight.h"
#include "library/lights/SpotLight.h"

#include "library/components/RotationComponent.h"

namespace DataGarden
{
  TestScene::TestScene() : Scene()
  {
    FreeCamera *freeCamera = new FreeCamera(45.0f, 0.1f, 100.0f);
    freeCamera->SetTransform(
        Transform(glm::vec3(-6.0f, 0.0f, 3.0f),
                  glm::vec3(1.0f, 1.0f, 1.0f), 0.0f, 0.0f, 0.0f));
    Set3DCamera(freeCamera);

    Camera2D *camera2D = new Camera2D(0.0f, 0.0f, 0.0f);
    Set2DCamera(camera2D);

    glm::vec4 whiteLight = glm::vec4(0.2f, 0.2f, 0.2f, 1.0f);

    m_LightList->PushLightOfType(
        LightType::Directional,
        new DirectionalLight(glm::vec4(0.0f, 0.0f, -1.0f, 0.0f), whiteLight));

    m_LightList->PushLightOfType(
        LightType::Point,
        new PointLight(Transform(glm::vec3(-4.0f, 8.0f, -4.0f)), whiteLight, 1.0f, 0.045f, 0.0075f));

    m_LightList->PushLightOfType(
        LightType::Point,
        new PointLight(Transform(glm::vec3(6.0f, 0.0f, 6.0f)), whiteLight, 1.0f, 0.045f, 0.0075f));

    m_LightList->PushLightOfType(
        LightType::Spot,
        new SpotLight(
            glm::vec4(3.0f, 3.0f, 3.0f, 0.0f),
            glm::vec4(1.0f, 0.0f, 0.0f, 0.0f),
            whiteLight, 1.0f, 0.045f, 0.0075f, 12.5f, 17.5f));

    Node *cube = Factory::Create(
        FactoryType::Cube,
        glm::vec3(-1.0f, 2.0f, 3.0f),
        glm::vec3(1.5f),
        ColorFromHex(0xE6C79C));
    cube->AddComponent<RotationComponent>(cube, 1.2f);
    m_NodeGraph->PushNode(cube);

    Node *cube2 = Factory::Create(
        FactoryType::Cube,
        glm::vec3(0.0f, -3.0f, 2.0f),
        glm::vec3(3.0f),
        ColorFromHex(0xCDDFA0));
    cube2->AddComponent<RotationComponent>(cube2, 0.6f);
    m_NodeGraph->PushNode(cube2);

    Node *cube3 = Factory::Create(
        FactoryType::Cube,
        glm::vec3(3.0f, -1.0f, 0.0f),
        glm::vec3(1.0f),
        ColorFromHex(0x6FD08C));
    cube3->AddComponent<RotationComponent>(cube3, 0.85f);
    m_NodeGraph->PushNode(cube3);

    Node *sphere1 = Factory::Create(
        FactoryType::Sphere,
        glm::vec3(-2.0f, 1.0f, 1.0f),
        glm::vec3(1.0f),
        ColorFromHex(0x7B9EA8));
    m_NodeGraph->PushNode(sphere1);

    Node *pyramid = Factory::Create(
        FactoryType::Pyramid,
        glm::vec3(-6.0f, 0.0f, 1.0f),
        glm::vec3(3.0f),
        ColorFromHex(0x6FD08C));
    pyramid->AddComponent<RotationComponent>(pyramid, 1.0f);
    m_NodeGraph->PushNode(pyramid);

    Node *cylinder = Factory::Create(
        FactoryType::Cylinder,
        glm::vec3(6.0f, 0.0f, 0.0f),
        glm::vec3(1.0f),
        ColorFromHex(0xE6C79C));
    m_NodeGraph->PushNode(cylinder);

    Node *plane = Factory::Create(
        FactoryType::Plane,
        glm::vec3(0.0f, -7.0f, 0.0f),
        glm::vec3(50.0f),
        ColorFromHex(0x7B9EA8));
    m_NodeGraph->PushNode(plane);
  }

  TestScene::~TestScene()
  {
  }

  void TestScene::PreUpdate()
  {
  }

  void TestScene::PostUpdate()
  {
  }

  void TestScene::PreRender()
  {
  }

  void TestScene::PostRender()
  {
  }
} // namespace DataGarden
