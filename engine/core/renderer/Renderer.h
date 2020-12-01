#ifndef DATA_GARDEN_RENDERER
#define DATA_GARDEN_RENDERER

#include "Shader.h"

#include "core/object/node/Node.h"

#include "core/object/camera/Camera.h"

namespace DataGarden
{
	class Renderer
	{
	public:
    Renderer();
		~Renderer();

		void PreRender();
    void PostRender();

    void SetBufferColor(float r, float g, float b, float a);
    void ClearBuffer();

    void SetViewport();

    unsigned int CreateProgram();
    void UseProgram(unsigned int programID);
    void AttachShader(unsigned int programID, unsigned int shaderID);
    void LinkProgram(unsigned int programID);
    void StopProgram();
    void DeleteProgram(unsigned int programID);

    unsigned int CreateVertexShader();
    unsigned int CreateFragmentShader();
    void ShaderSource(unsigned int programID, std::string shaderSourceString);
    void CompileShader(unsigned int shaderID);
    void DeleteShader(unsigned int shaderID);

    unsigned int CreateBuffer();
    void DeleteBuffer(unsigned int bufferID);
    
    void BindVertexBuffer(unsigned int bufferID);
    void VertexBufferData(float* vertexData, unsigned int vertexLength);
    void UnbindVertexBuffer();

    void BindIndexBuffer(unsigned int bufferID);
    void IndexBufferData(unsigned int* indexData, unsigned int indexLength);
    void UnbindIndexBuffer();

    unsigned int CreateVertexArray();
    void BindVertexArray(unsigned int vertexArrayID);
    void EnableVertexAttribArray(unsigned int vertexAttribPosition);
    void VertexAttribPointer(unsigned int vertexAttribPosition, unsigned int size, unsigned int type, bool normalize, unsigned int stride, unsigned int offset);
    void UnbindVertexArray();
    void DeleteVertexArray(unsigned int vertexArrayID);

    void SetUniformMatrix4fv(unsigned int programID, const char* uniformName, glm::mat4 uniformMatrix);
		void SetUniform4fv(unsigned int programID, const char* uniformName, glm::vec4 uniformVector);
		void SetUniform3fv(unsigned int programID, const char* uniformName, glm::vec3 uniformVector);
		void SetUniform1f(unsigned int programID, const char* uniformName, float uniformFloat);
		void SetUniform1i(unsigned int programID, const char* uniformName, int uniformInteger);
		
    void DrawIndexed(unsigned int count);

    inline unsigned int GetMainProgramID() { return m_Shader->GetProgramID(); };

  private:
		// glm::vec4 m_ClearColor;
    
    // Scope<RenderCommandQueue> m_CommandQueue

    // TODO: Allow custom shaders
    Shader* m_Shader;

    void _Setup();

    void _SetGlobalGraphicsState();

    void _Teardown();
  };
}

#endif
