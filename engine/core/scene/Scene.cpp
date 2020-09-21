#include <iostream>

#include "Scene.h"

#include "core/Engine.h"

namespace DataGarden
{
  Scene::Scene()
  {
    m_UI_Count = 0;

    _SetupScene();

    // m_Camera = new Entity(); // Scope<Camera>(new Camera("Final Camera", 45.0f, 0.1f, 100.0f));
    // m_Camera->AddTransform(glm::vec3(-6.0f, 0.0f, 3.0f), glm::vec3(1.0f, 1.0f, 1.0f), 0.0f, 0.0f, 0.0f);
  }

  Scene::~Scene()
  {
    _TeardownScene();
  }

  // void Scene::PreUpdate()
  // {}

  void Scene::Update()
  {
    m_Camera->Update();

    // m_EntityManager->Update();
    // m_LightManager->Update();

    // m_EntityManager.Update();

    // for (int i = 0; i < m_UI_Count; i++)
    // {
    //   m_UIs[i]->Update();
    // }
  }

  // void Scene::PostUpdate()
  // {}

  // void Scene::PreRender()
  // {}

  void Scene::Render()
  {
    // Renderer& renderer = Engine::Get().GetRenderer();
   
    // set camera projection first
    // renderer.SetViewProjection(m_CameraEntity);
    
    // TODO: figure out a way to only dynamically update lights, but attach lights to entities
    // set lighting
    // if (m_LightManager->UpdatedInFrame())
    // {
    //   renderer.SetLights(m_LightManager.get());
    // }
    // renderer.SetLights(m_LightManager.get());
    
    // render entities
    // m_EntityManager->Render();

    // render uis
    // for (int i = 0; i < m_UI_Count; i++)
    // {
    //   m_UIs[i]->Render();
    // }
  }

  // void Scene::PostRender()
  // {
  //   // m_EntityManager->ResetUpdateStatus();
  //   // m_LightManager->ResetUpdateStatus();
  // }

  void Scene::PushUi(UI* ui)
  {
    // WATER_BEAR_ASSERT(m_UI_Count + 1 < (MAX_UI_COUNT), "UI limit exceeded");

    // m_UIs[m_UI_Count++] = std::unique_ptr<Ui>(ui);
  }

  void Scene::SetCamera(Camera* camera)
  {
    m_Camera = camera;
  }

  void Scene::_DeleteCamera()
  {
    delete m_Camera;
  }

  void Scene::_SetupScene()
  {
    m_NodeGraph = new NodeGraph();
    m_LightList = new LightList();
    m_Camera = new Camera(45.0f, 0.1f, 100.0f);
  }

  void Scene::_TeardownScene()
  {
    delete m_NodeGraph;
    delete m_LightList;
    delete m_Camera;
  }
}
