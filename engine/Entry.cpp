#include <stdio.h>
#include <iostream>

#include <emscripten.h>

#include "DataGarden.h"
#include "Constants.h"

#include "core/Engine.h"

#include "library/scenes/TestScene.h"

DataGarden::Engine* engine;

void mainLoop()
{
  engine->Update();  
}

int main(int argc, char** argv) 
{
  DataGarden::CreateEngine();
  engine = &DataGarden::Engine::Get();

  DataGarden::TestScene* testScene = new DataGarden::TestScene();
  engine->LoadScene(testScene);

  engine->Start();

  emscripten_set_main_loop(mainLoop, FPS, LOOP_TYPE);

  engine->Stop();

  DataGarden::DeleteEngine();

  return EXIT_SUCCESS;
}
