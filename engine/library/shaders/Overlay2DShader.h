#ifndef DATA_GARDEN_OVERLAY_2D_SHADER
#define DATA_GARDEN_OVERLAY_2D_SHADER

#include "DataGarden.h"

#include "core/renderer/Shader.h"

namespace DataGarden
{
	class Overlay2DShader : Shader
	{
	public:
		Overlay2DShader(ShaderType shaderType);
		~Overlay2DShader();

  private:
    void _Setup();
	};
}

#endif
