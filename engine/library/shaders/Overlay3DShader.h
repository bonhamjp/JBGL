#ifndef DATA_GARDEN_OVERLAY_3D_SHADER
#define DATA_GARDEN_OVERLAY_3D_SHADER

#include "DataGarden.h"

#include "core/renderer/Shader.h"

namespace DataGarden
{
	class Overlay3DShader : Shader
	{
	public:
		Overlay3DShader(const ShaderVertexSource vertexSource, const ShaderFragmentSource fragmentSource);
		~Overlay3DShader();

  private:
    void _Setup();
	};
}

#endif