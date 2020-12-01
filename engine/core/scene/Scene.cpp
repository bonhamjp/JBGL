#include <iostream>

#include "Scene.h"

#include "core/Engine.h"

namespace DataGarden
{
  Scene::Scene()
  {
    m_UI_Count = 0;

    _SetupScene();
  }

  Scene::~Scene()
  {
    _TeardownScene();
  }

  void Scene::Update()
  {
    m_Camera->Update();

    m_NodeGraph->Update();
    
    // for (int i = 0; i < m_UI_Count; i++)
    // {
    //   m_UIs[i]->Update();
    // }
  }

  void Scene::Render()
  {
    m_LightList->UpdateRendererLightUniforms();
    
    // TODO: Use dirty camera variable to set view projection up only when needed... maybe
    // TODO: Add method on Camera to do Renderer setup
    m_Camera->SetCameraUniforms();
    
    m_NodeGraph->Render();

    // render uis
    // for (int i = 0; i < m_UI_Count; i++)
    // {
    //   m_UIs[i]->Render();
    // }
  }

  void Scene::PushUi(UI* ui)
  {
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
