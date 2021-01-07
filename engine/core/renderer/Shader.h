#ifndef DATA_GARDEN_SHADER
#define DATA_GARDEN_SHADER

#include "DataGarden.h"

#include "utility/ShaderParser.h"

namespace DataGarden
{
  class Shader
  {
  public:
    Shader(ShaderType shaderType);
    ~Shader();

    void Bind();
    void Unbind();

    inline unsigned int GetProgramID() { return m_ProgramID; };

  protected:
    unsigned int m_ProgramID;

    unsigned int _CompileVertexShader(const std::string &shaderSource);
    unsigned int _CompileFragmentShader(const std::string &shaderSource);
  };
} // namespace DataGarden

#endif
