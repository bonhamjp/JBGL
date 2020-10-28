#include "IndexBuffer.h"

#include "Renderer.h"

#include "core/Engine.h"

namespace DataGarden
{
  IndexBuffer::IndexBuffer(uint32_t* indices, uint32_t size)
  {
    Renderer& renderer = Engine::Get().GetRenderer();

		m_ID = renderer.CreateBuffer();

		renderer.BindIndexBuffer(m_ID);
		renderer.IndexBufferData(indices, size);
		renderer.UnbindIndexBuffer();
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
