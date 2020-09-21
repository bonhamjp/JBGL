#ifndef DATA_GARDEN_GEOMETRY
#define DATA_GARDEN_GEOMETRY

#include <string>

#include "DataGarden.h"

#include "core/resource_manager/ResourceManager.h"

namespace DataGarden
{
  // Forward declarations
  class BufferLayout;
  class VertexArray;
  class VertexBuffer;
  class IndexBuffer;

  enum class GeometryType
  {
    Cube = 0, Plane, Pyramid, Sphere, Cone, Torus, Model 
  };

  struct GeometryBufferObject
  {
    float* Vertices;
    unsigned int* Indices;
  };

  class Geometry
  {
  public:
    Geometry();
    virtual ~Geometry();

    virtual GeometryType GetType() = 0;

    inline float* GetVertices() { return m_GeometryBuffer.Vertices; };
    inline unsigned int* GetIndices() { return m_GeometryBuffer.Indices; };

    inline int GetVertexCount() { return m_VertexCount; };
    inline int GetVertexStride() { return m_VertexStride; };
    inline int GetTriangleCount() { return m_TriangleCount; };
    inline float GetVertexSize() { return m_VertexStride * m_VertexCount * sizeof(float); };

    inline VertexArray* GetVertexArray() { return m_VertexArray; };
    inline VertexBuffer* GetVertexBuffer() { return m_VertexBuffer; };
    inline IndexBuffer* GetIndexBuffer() { return m_IndexBuffer; };

    inline int GetIndexCount() { return m_IndexCount; };

    virtual BufferLayout GetLayout() = 0;

    virtual ResourceDescriptor GetResourceDescriptor() = 0;
    // virtual Ref<Geometry>(*f)(ResourceDescriptor* descriptor) GetResourceGenerator() = 0;

  protected:
    GeometryType m_Type;

    int m_VertexCount;
    int m_VertexStride;
    int m_TriangleCount;
    int m_IndexCount;

    VertexArray* m_VertexArray;
    VertexBuffer* m_VertexBuffer;
    IndexBuffer* m_IndexBuffer;

    GeometryBufferObject m_GeometryBuffer;

    void _Initialize();
    void _TearDown();
  };
}

#endif
