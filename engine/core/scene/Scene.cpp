#include <iostream>

#include "Scene.h"

#include "core/Engine.h"

namespace DataGarden
{
  Scene::Scene()
  {
    m_RenderMode = RenderMode::THREE_DIMENSIONS;
    m_MainShader = MainShader::LIGHTING;

    m_UIList = nullptr;

    m_Grid = nullptr;

    m_3DCamera = nullptr;
    m_2DCamera = nullptr;

    _SetupScene();
  }

  Scene::~Scene()
  {
    _TeardownScene();
  }

  void Scene::Update()
  {
    _UpdateGrid();
    _UpdateVisualization();
    _UpdateUIList();
  }

  void Scene::Render()
  {
    _RenderGrid();
    _RenderVisualization();
    _RenderUIList();
  }

  void Scene::SetGrid(Grid *grid)
  {
    if (m_Grid != nullptr)
    {
      delete m_Grid;
    }

    m_Grid = grid;
  }

  void Scene::Set3DCamera(Camera *camera)
  {
    if (m_3DCamera != nullptr)
    {
      delete m_3DCamera;
    }

    m_3DCamera = camera;
  }

  void Scene::Set2DCamera(Camera *camera)
  {
    if (m_2DCamera != nullptr)
    {
      delete m_2DCamera;
    }

    m_2DCamera = camera;
  }

  void Scene::_UpdateGrid()
  {
    // TODO: Allow Grid to be turned off
    if (m_Grid != nullptr)
    {

    }
  }

  void Scene::_UpdateVisualization()
  {
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
  }

  void Scene::_UpdateUIList()
  {
    m_UIList->Update();
  }

  void Scene::_RenderGrid()
  {
    GridShader *gridShader = Engine::Get().GetShaderManager().GetGridShader();
    gridShader->Bind();

    // TODO: Allow Grid to be turned off
    if (m_Grid != nullptr)
    {
      m_Grid->Render();
    }

    gridShader->Unbind();
  }

  void Scene::_RenderVisualization()
  {
    VisualizationShader *visualizationShader = Engine::Get().GetShaderManager().GetVisualizationShader();
    visualizationShader->Bind();

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

    visualizationShader->Unbind();
  }

  void Scene::_RenderUIList()
  {
    m_UIList->Render();
  }

  void Scene::_DeleteCameras()
  {
    delete m_3DCamera;
    delete m_2DCamera;
  }

  void Scene::_SetupScene()
  {
    m_UIList = new UIList();
    m_NodeGraph = new NodeGraph();
    m_LightList = new LightList();
  }

  void Scene::_TeardownScene()
  {
    delete m_UIList;
    delete m_NodeGraph;
    delete m_LightList;

    _DeleteCameras();
  }
} // namespace DataGarden
