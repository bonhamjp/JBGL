#include "BufferLayout.h"
#include "VertexBuffer.h"

#include "Renderer.h"

#include "core/Engine.h"

namespace DataGarden
{
  VertexBuffer::VertexBuffer(float *vertices, uint32_t size)
  {
    Renderer &renderer = Engine::Get().GetRenderer();

    m_ID = renderer.CreateBuffer();

    renderer.BindVertexBuffer(m_ID);
    renderer.VertexBufferData(vertices, size);
    renderer.UnbindVertexBuffer();
  }

  VertexBuffer::~VertexBuffer()
  {
    Engine::Get().GetRenderer().DeleteBuffer(m_ID);
  }

  void VertexBuffer::SetLayout(BufferLayout layout)
  {
    m_Layout = layout;
  }

  BufferLayout VertexBuffer::GetLayout()
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
} // namespace DataGarden
