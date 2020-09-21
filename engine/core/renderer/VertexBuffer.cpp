#include "VertexBuffer.h"
#include "BufferLayout.h"

#include "Renderer.h"

#include "core/Engine.h"

namespace DataGarden
{
  VertexBuffer::VertexBuffer(float* vertices, uint32_t size)
  {
		// glGenBuffers(1, &m_ID);
		// glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		// glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

		Renderer& renderer = Engine::Get().GetRenderer();

		m_ID = renderer.CreateBuffer();
  }

	VertexBuffer::~VertexBuffer()
	{
		Engine::Get().GetRenderer().DeleteBuffer(m_ID);
	}

  void VertexBuffer::SetLayout(BufferLayout* layout)
  {
    m_Layout = layout;
  }

  BufferLayout* VertexBuffer::GetLayout()
  {
    return m_Layout;
  }

	void VertexBuffer::Bind()
	{
		Engine::Get().GetRenderer().BindVertexBuffer(m_ID);
	}

	void VertexBuffer::Unbind()
	{
		Engine::Get().GetRenderer().UnbindVertexBuffer();
	}
}
