#ifndef DATA_GARDEN_INDEX_BUFFER
#define DATA_GARDEN_INDEX_BUFFER

#include "DataGarden.h"

namespace DataGarden
{
	class IndexBuffer
	{
	public:
		IndexBuffer(uint32_t* indices, uint32_t count);
		~IndexBuffer();

		void Bind();
		void Unbind();

  private:
  	unsigned int m_ID;
	};
}

#endif
