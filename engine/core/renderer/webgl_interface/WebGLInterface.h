#ifndef DATA_GARDEN_WEBGL_INTERFACE
#define DATA_GARDEN_WEBGL_INTERFACE

#include <emscripten.h>

#include "WebGLInterfaceSetup.h"
#include "WebGLInterfaceState.h"
#include "WebGLInterfaceProgram.h"
#include "WebGLInterfaceShader.h"
#include "WebGLInterfaceBuffer.h"
#include "WebGLInterfaceVertexArray.h"
#include "WebGLInterfaceUniform.h"

// Executed from JavaScript
extern "C"
{
  void importModel(float* vertexData, unsigned int vertexLength, unsigned int* indexData, unsigned int indexLength, unsigned int* textureCoordinateData, unsigned int textureCoordinateLength)
  {
    std::cout << "Vertex Length: " << vertexLength << std::endl;
    for (unsigned int i = 0; i < vertexLength; i++)
    {
      std::cout << "vertexData[" << i << "] = " << vertexData[i] << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;

    std::cout << "Index Length: " << indexLength << std::endl;
    for (unsigned int i = 0; i < indexLength; i++)
    {
      std::cout << "indexData[" << i << "] = " << indexData[i] << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;

    std::cout << "Texture Coordinate Length: " << textureCoordinateLength << std::endl;
    for (unsigned int i = 0; i < textureCoordinateLength; i++)
    {
      std::cout << "textureCoordinateData[" << i << "] = " << textureCoordinateData[i] << std::endl;
    }
    std::cout << "-----------------------------------------------" << std::endl;
  }
}

#endif
