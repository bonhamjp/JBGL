#ifndef DATA_GARDEN_GEOMETRY
#define DATA_GARDEN_GEOMETRY

#include "DataGarden.h"

#include "core/renderer/BufferLayout.h"

namespace DataGarden
{
  // Forward declarations
  class VertexArray;
  class VertexBuffer;
  class IndexBuffer;

  class Geometry
  {
  public:
    Geometry();
    virtual ~Geometry();

    // TODO: Add base Vertex stride/Vertex Attrib definition, since it should be the same for all Geometry

    inline float *GetVertices() { return m_GeometryBuffer.Vertices; };
    inline unsigned int *GetIndices() { return m_GeometryBuffer.Indices; };

    inline int GetVertexCount() { return m_VertexCount; };
    inline int GetVertexStride() { return m_VertexStride; };
    inline float GetVertexSize() { return m_VertexStride * m_VertexCount * sizeof(float); };

    inline VertexArray &GetVertexArray() { return *m_VertexArray; };
    inline VertexBuffer &GetVertexBuffer() { return *m_VertexBuffer; };
    inline IndexBuffer &GetIndexBuffer() { return *m_IndexBuffer; };

    inline int GetIndexCount() { return m_IndexCount; };

    virtual BufferLayout GetLayout() = 0;

  protected:
    int m_VertexCount;
    int m_VertexStride;
    int m_IndexCount;

    BufferObject m_GeometryBuffer;

    VertexArray *m_VertexArray;
    VertexBuffer *m_VertexBuffer;
    IndexBuffer *m_IndexBuffer;

    // TODO: Add virtual create and delete Buffer Object methods

    void _Initialize();
    void _TearDown();
  };
} // namespace DataGarden

#endif
