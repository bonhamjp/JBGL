#ifndef DATA_GARDEN_WEBGL_INTERFACE
#define DATA_GARDEN_WEBGL_INTERFACE

#include <emscripten.h>

// void em_Test(float* vertexData, unsigned int vertexLength)
// {
//   EM_ASM_ARGS({
//     const vertexPointer = $0;
//     const vertexLength = $1;

//     const bytesPerFloat = Float32Array.BYTES_PER_ELEMENT;

//     const rawData = new Float32Array(Module.HEAPU8.buffer, vertexPointer, vertexLength);

//     console.log(rawData);
//   }, vertexData, vertexLength);
// }

EM_JS(void, glSetBufferColor, (float r, float g, float b, float a), {
  engineInterface.glSetBufferColor(r, g, b, a);
});

EM_JS(void, glClearBuffer, (), {
  engineInterface.glClearBuffer();
});

EM_JS(void, glSetViewport, (unsigned int x, int y, unsigned int width, unsigned int height), {
  engineInterface.glSetViewport(x, y, width, height);
});

EM_JS(unsigned int, glCreateProgram, (), {
  return engineInterface.glCreateProgram();
});

EM_JS(void, glUseProgram, (unsigned int programID), {
  engineInterface.glUseProgram(programID);
});

EM_JS(void, glAttachShader, (unsigned int programID, unsigned int shaderID), {
  engineInterface.glAttachShader(programID, shaderID);
});

EM_JS(void, glLinkProgram, (unsigned int programID), {
  engineInterface.glLinkProgram(programID);
});

EM_JS(void, glStopProgram, (), {
  engineInterface.glUseProgram(0);
});

EM_JS(void, glDeleteProgram, (unsigned int programID), {
  engineInterface.glDeleteProgram(0);
})

EM_JS(unsigned int, glCreateVertexShader, (), {
  return engineInterface.glCreateVertexShader();
});

EM_JS(unsigned int, glCreateFragmentShader, (), {
  return engineInterface.glCreateFragmentShader();
});

void glShaderSource(unsigned int shaderID, char* shaderSource)
{
  EM_ASM_ARGS({
    const shaderID = $0;
    const shaderSourcePointer = $1;
    const shaderSourceLength = $2;

    const bytesPerChar = Uint8Array.BYTES_PER_ELEMENT;

    const rawData = new Uint8Array(Module.HEAPU8.buffer, shaderSourcePointer, shaderSourceLength);
    
    var outputString = "";
    for (i = 0; i < shaderSourceLength; i++) {
      outputString += String.fromCharCode(rawData[i]);
    }

    engineInterface.glShaderSource(shaderID, outputString);
  }, shaderID, shaderSource, strlen(shaderSource));
}

EM_JS(unsigned int, glCompileShader, (unsigned int shaderID), {
  engineInterface.glCompileShader(shaderID);
});

EM_JS(unsigned int, glDeleteShader, (unsigned int shaderID), {
  engineInterface.glDeleteShader(shaderID);
});

EM_JS(unsigned int, glCreateBuffer, (), {
  return engineInterface.glCreateBuffer();
});

EM_JS(void, glDeleteBuffer, (unsigned int bufferID), {
  engineInterface.glDeleteBuffer(bufferID);
});

EM_JS(void, glBindVertexBuffer, (unsigned int bufferID), {
  engineInterface.glBindVertexBuffer(bufferID);
});

EM_JS(void, glVertexBufferData, (float* vertexData), {
  // webGlContext.bufferData(webGlContext.ARRAY_BUFFER, new Float32Array(vertexData), webGlContext.STATIC_DRAW);
  engineInterface.glVertexBufferData(new Float32Array(vertexData));
});

EM_JS(void, glBindIndexBuffer, (unsigned int bufferID), {
  engineInterface.glBindIndexBuffer(bufferID);
});

EM_JS(void, glIndexBufferData, (unsigned int* indexData), {
  // webGlContext.bufferData(webGlContext.ELEMENT_ARRAY_BUFFER, new Uint16Array(vertexData), webGlContext.STATIC_DRAW);
  engineInterface.glIndexBufferData(new Uint16Array(vertexData));
});

EM_JS(unsigned int, glCreateVertexArray, (), {
  return engineInterface.createVertexArray();
});

EM_JS(void, glBindVertexArray, (unsigned int vertexArrayID), {
  engineInterface.bindVertexArray(vertexArrayID);
});

EM_JS(void, glDeleteVertexArray, (unsigned int vertexArrayID), {

  engineInterface.deleteVertexArray(vertexArrayID);
});

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
