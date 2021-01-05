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
    m_3DCamera->Update();
    m_2DCamera->Update();

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
    m_3DCamera->SetCameraUniforms();

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

  void Scene::Set3DCamera(Camera* camera)
  {
    m_3DCamera = camera;
  }

  void Scene::Set2DCamera(Camera* camera)
  {
    m_2DCamera = camera;
  }

  void Scene::_DeleteCameras()
  {
    delete m_3DCamera;
    delete m_2DCamera;
  }

  void Scene::_SetupScene()
  {
    m_NodeGraph = new NodeGraph();
    m_LightList = new LightList();
  }

  void Scene::_TeardownScene()
  {
    delete m_NodeGraph;
    delete m_LightList;

    _DeleteCameras();
  }
}
