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
    _Update3DScene();
    _Update2DScene();
    _UpdateUIs();
  }

  void Scene::Render()
  {
    _Render3DScene();
    _Render2DScene();
    _RenderUIs();
  }

  void Scene::PushUi(UI *ui)
  {
    m_UIS[m_UI_Count++] = ui;
  }

  void Scene::Set3DCamera(Camera *camera)
  {
    m_3DCamera = camera;
  }

  void Scene::Set2DCamera(Camera *camera)
  {
    m_2DCamera = camera;
  }

  void Scene::_Update3DScene()
  {
    Visualization3DShader* visualization3DShader = Engine::Get().GetShaderManager().GetVisualization3DShader();

    visualization3DShader->Bind();
    m_3DCamera->Update();
    m_NodeGraph->Update();
    visualization3DShader->Unbind();
  }

  void Scene::_Update2DScene()
  {
    m_2DCamera->Update();
  }

  void Scene::_UpdateUIs()
  {
    for (int i = 0; i < m_UI_Count; i++)
    {
      m_UIS[i]->Update();
    }
  }

  void Scene::_Render3DScene()
  {
    m_LightList->UpdateRendererLightUniforms();

    // TODO: Use dirty camera variable to set view projection up only when needed... maybe
    // TODO: Add method on Camera to do Renderer setup
    m_3DCamera->SetCameraUniforms();

    m_NodeGraph->Render();
  }

  void Scene::_Render2DScene()
  {
  }

  void Scene::_RenderUIs()
  {
    for (int i = 0; i < m_UI_Count; i++)
    {
      m_UIS[i]->Render();
    }
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
} // namespace DataGarden
