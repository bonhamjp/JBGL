#ifndef DATA_GARDEN_ENGINE
#define DATA_GARDEN_ENGINE

#include "DataGarden.h"

#include "core/shader_manager/ShaderManager.h"

#include "core/resource_manager/ResourceManager.h"

namespace DataGarden
{
  // forward declarations
  class Canvas;
  class Scene;
  class Clock;
  class InputManager;
  class Renderer;
  class Texture;
  class Geometry;

  class Engine
  {
  public:
    inline static Engine &Get() { return *s_Instance; }

    Engine();
    ~Engine();

    void LoadScene(Scene *scene);

    void Start();
    void Stop();

    void Update();

    inline Canvas &GetCanvas() { return *m_Canvas; };
    inline Scene &GetScene() { return *m_Scene; };
    inline Clock &GetClock() { return *m_Clock; };
    inline InputManager &GetInputManager() { return *m_InputManager; };
    inline Renderer &GetRenderer() { return *m_Renderer; };

    inline ShaderManager &GetShaderManager() { return *m_ShaderManager; };

    inline ResourceManager<Texture> &GetTextureManager() { return *m_TextureManager; };
    inline ResourceManager<Geometry> &GetGeometryManager() { return *m_GeometryManager; };

  private:
    static Engine *s_Instance;

    bool m_Running;

    Canvas *m_Canvas;
    Scene *m_Scene;
    Clock *m_Clock;
    InputManager *m_InputManager;
    Renderer *m_Renderer;

    ShaderManager *m_ShaderManager;

    ResourceManager<Texture> *m_TextureManager;
    ResourceManager<Geometry> *m_GeometryManager;

    void _SetupSystems();
    void _TeardownSystems();
  };

  Engine *CreateEngine();
  void DeleteEngine();
} // namespace DataGarden

#endif
