#include "IndexBuffer.h"

#include "Renderer.h"

#include "core/Engine.h"

namespace DataGarden
{
  IndexBuffer::IndexBuffer(uint32_t* indices, uint32_t size)
  {
    // glGenBuffers(1, &m_ID);
		// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
		// glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW);

		Renderer& renderer = Engine::Get().GetRenderer();

		m_ID = renderer.CreateBuffer();
  }

	IndexBuffer::~IndexBuffer()
	{
		Engine::Get().GetRenderer().DeleteBuffer(m_ID);
	}

	void IndexBuffer::Bind()
	{
		Engine::Get().GetRenderer().BindIndexBuffer(m_ID);
	}

	void IndexBuffer::Unbind()
	{
		Engine::Get().GetRenderer().UnbindVertexBuffer();
	}
}
