#include "UniformBuffer.h"
#include "Renderer.h"

#include "core/Engine.h"

namespace DataGarden
{
  UniformBuffer::UniformBuffer(float *vertices, uint32_t size)
  {
    // glGenBuffers(1, &m_ID);
    // glBindBuffer(GL_UNIFORM_BUFFER, m_ID);
    // // glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
  }

  UniformBuffer::~UniformBuffer()
  {
    // glDeleteBuffers(1, &m_ID);
  }

  void UniformBuffer::Bind()
  {
    // glBindBuffer(GL_UNIFORM_BUFFER, m_ID);
  }

  void UniformBuffer::Unbind()
  {
    // glBindBuffer(GL_UNIFORM_BUFFER, 0);
  }
} // namespace DataGarden
