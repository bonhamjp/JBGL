#ifndef DATA_GARDEN_VERTEX_ARRAY
#define DATA_GARDEN_VERTEX_ARRAY

#include "DataGarden.h"

namespace DataGarden
{
  // forward declarations
  class VertexBuffer;
  class IndexBuffer;

  class VertexArray
  {
  public:
    VertexArray();
    ~VertexArray();

    inline unsigned int GetID() const { return m_ID; };

    void AddVertexLayout(VertexBuffer *vertexBuffer);
    void AddIndexLayout(IndexBuffer *indexBuffer);

    void Bind();
    void Unbind();

  private:
    unsigned int m_ID;
  };
} // namespace DataGarden

#endif
