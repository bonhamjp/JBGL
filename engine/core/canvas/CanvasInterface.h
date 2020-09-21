#ifndef DATA_GARDEN_CANVAS_INTERFACE
#define DATA_GARDEN_CANVAS_INTERFACE

#include <emscripten.h>

#include "core/Engine.h"

#include "Canvas.h"

#include "core/scene/Scene.h"
#include "core/object/camera/Camera.h"

// exported for use in javascript
extern "C"
{
  void onCanvasDimensionChange(float width, float height)
  {
    DataGarden::Canvas canvas = DataGarden::Engine::Get().GetCanvas();
    canvas.SetDimensions(width, height);

    DataGarden::Camera camera = DataGarden::Engine::Get().GetScene().GetCamera();
    camera.RefreshForDimensionChange();
  }
}

#endif
