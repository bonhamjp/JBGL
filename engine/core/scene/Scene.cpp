#include <iostream>

#include "Scene.h"

#include "core/Engine.h"

namespace DataGarden
{
  Scene::Scene()
  {
    m_RenderMode = RenderMode::THREE_DIMENSIONS;
    m_MainShader = MainShader::LIGHTING;

    m_UI_Count = 0;

    _SetupScene();
  }

  Scene::~Scene()
  {
    _TeardownScene();
  }

  void Scene::Update()
  {
    _UpdateScene();
    _UpdateUIs();
  }

  void Scene::Render()
  {
    _RenderScene();
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

  void Scene::_UpdateScene()
  {
    VisualizationShader *visualizationShader = Engine::Get().GetShaderManager().GetVisualizationShader();
    visualizationShader->Bind();

    switch (m_RenderMode)
    {
    case RenderMode::THREE_DIMENSIONS:
      m_3DCamera->Update();
      break;

    case RenderMode::TWO_DIMENSIONS:
      m_2DCamera->Update();
      break;
    }

    m_NodeGraph->Update();

    visualizationShader->Unbind();
  }

  void Scene::_UpdateUIs()
  {
    for (int i = 0; i < m_UI_Count; i++)
    {
      m_UIS[i]->Update();
    }
  }

  void Scene::_RenderScene()
  {
    m_LightList->UpdateRendererLightUniforms();

    // TODO: Use dirty camera variable to set view projection up only when needed... maybe
    switch (m_RenderMode)
    {
    case RenderMode::THREE_DIMENSIONS:
      m_3DCamera->SetCameraUniforms();
      break;

    case RenderMode::TWO_DIMENSIONS:
      m_2DCamera->SetCameraUniforms();
      break;
    }

    m_NodeGraph->Render();
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
