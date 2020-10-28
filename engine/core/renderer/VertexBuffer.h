#ifndef DATA_GARDEN_VERTEX_BUFFER
#define DATA_GARDEN_VERTEX_BUFFER

#include "DataGarden.h"

namespace DataGarden
{
  // forward declarations
  class BufferLayout;

	class VertexBuffer
	{
	public:
		VertexBuffer(float* vertices, uint32_t size);
		~VertexBuffer();

		void SetLayout(BufferLayout layout);
		BufferLayout GetLayout();

		void Bind();
		void Unbind();
	
	protected:
		unsigned int m_ID;
		
		BufferLayout m_Layout;
	};
}

#endif
