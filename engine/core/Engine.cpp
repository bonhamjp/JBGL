#include <iostream>

#include "Engine.h"

#include "core/canvas/Canvas.h"

#include "core/scene/Scene.h"

#include "core/clock/Clock.h"

#include "core/input_manager/InputManager.h"

#include "core/renderer/Renderer.h"
#include "core/renderer/Texture.h"
#include "core/renderer/Geometry.h"

namespace DataGarden
{
  Engine* Engine::s_Instance = nullptr;
	
	Engine* CreateEngine()
	{
    return new Engine();
	}
	
	void DeleteEngine()
	{
    delete &Engine::Get();
	}
	
	Engine::Engine()
	{
		s_Instance = this;
    
    m_Running = false;

    _SetupSystems();
  }
  
  Engine::~Engine()
  {
    _TeardownSystems();
  }

  void Engine::LoadScene(Scene* scene)
  {
    if (m_Scene != nullptr)
    {
      delete m_Scene;
    }

    m_Scene = scene;
  }

  void Engine::Start()
  {
    m_Running = true;
  }

  void Engine::Stop()
  {
    m_Running = false;
  }

  void Engine::Update()
  {
    m_Clock->Update();

    m_Renderer->PreRender();
    
    m_Scene->PreUpdate();
    m_Scene->Update();
    m_Scene->PostUpdate();

    m_Scene->PreRender();
    m_Scene->Render();
    m_Scene->PostRender();

    m_Renderer->PostRender();

    m_InputManager->Clear();
  }

  void Engine::_SetupSystems()
  {
    m_Canvas = new Canvas();

    m_Clock = new Clock();

    m_InputManager = new InputManager();

    m_Renderer = new Renderer();

    m_TextureManager = new ResourceManager<Texture>();
    m_GeometryManager = new ResourceManager<Geometry>();
  }

  void Engine::_TeardownSystems()
  {
    delete m_Canvas;
    delete m_Clock;
    delete m_InputManager;
    delete m_Renderer;

    delete m_TextureManager;
    delete m_GeometryManager;
  }
}
