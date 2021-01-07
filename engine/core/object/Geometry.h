#ifndef DATA_GARDEN_GEOMETRY
#define DATA_GARDEN_GEOMETRY

#include "DataGarden.h"

namespace DataGarden
{
  // Forward declarations
  class BufferLayout;
  class VertexArray;
  class VertexBuffer;
  class IndexBuffer;
  struct ResourceDescriptor;

  struct GeometryBufferObject
  {
    float *Vertices;
    unsigned int *Indices;
  };

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

    VertexArray &GetVertexArray();
    VertexBuffer &GetVertexBuffer();
    IndexBuffer &GetIndexBuffer();

    inline int GetIndexCount() { return m_IndexCount; };

    virtual BufferLayout GetLayout() = 0;

  protected:
    int m_VertexCount;
    int m_VertexStride;
    int m_IndexCount;

    GeometryBufferObject m_GeometryBuffer;

    VertexArray *m_VertexArray;
    VertexBuffer *m_VertexBuffer;
    IndexBuffer *m_IndexBuffer;

    // TODO: Add virtual create and delete Buffer Object methods

    void _Initialize();
    void _TearDown();
  };
} // namespace DataGarden

#endif
