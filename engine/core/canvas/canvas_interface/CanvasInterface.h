#ifndef DATA_GARDEN_CANVAS_INTERFACE
#define DATA_GARDEN_CANVAS_INTERFACE

#include <emscripten.h>

#include "core/Engine.h"

#include "core/canvas/Canvas.h"

#include "core/renderer/Renderer.h"

#include "core/scene/Scene.h"
#include "core/object/camera/Camera.h"

#include <iostream>

// exported for use in javascript
extern "C"
{
  void onCanvasDimensionChange(float width, float height)
  {
    DataGarden::Canvas& canvas = DataGarden::Engine::Get().GetCanvas();
    canvas.SetDimensions(width, height);

    DataGarden::Canvas& canvas2 = DataGarden::Engine::Get().GetCanvas();

    width = canvas2.GetWidth();
    height = canvas2.GetHeight();

    DataGarden::Camera& camera = DataGarden::Engine::Get().GetScene().GetCamera();
    camera.RefreshForDimensionChange();

    DataGarden::Renderer& renderer = DataGarden::Engine::Get().GetRenderer();
    renderer.SetViewport();
  }
}

#endif
