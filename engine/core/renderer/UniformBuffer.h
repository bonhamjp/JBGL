#ifndef DATA_GARDEN_UNIFORM_BUFFER
#define DATA_GARDEN_UNIFORM_BUFFER

#include "DataGarden.h"

namespace DataGarden
{
  class UniformBuffer
  {
  public:
    // static UniformBuffer* Create(float* vertices, uint32_t size);
    UniformBuffer(float *vertices, uint32_t size);
    ~UniformBuffer();

    inline unsigned int GetID() const { return m_ID; };

    void Bind();
    void Unbind();

  private:
    unsigned int m_ID;
  };
} // namespace DataGarden

#endif
