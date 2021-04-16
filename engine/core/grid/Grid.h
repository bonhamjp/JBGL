#ifndef DATA_GARDEN_GRID
#define DATA_GARDEN_GRID

#include "DataGarden.h"

#include "core/renderer/BufferLayout.h"

#include "core/object/Transform.h"

#include <glm/vec3.hpp>

namespace DataGarden
{
  // Forward declarations
  class VertexArray;
  class VertexBuffer;
  class IndexBuffer;

  class Grid
  {
  public:
    Grid(glm::vec3 primaryColor, glm::vec3 secondaryColor, float precision);
    Grid(glm::vec3 primaryColor, float precision);
    ~Grid();

    virtual void Update();

    void Render();

    inline float GetPrecision() { return m_Precision; };
    inline void SetPrecision(float precision) { m_Precision = precision; };

    // TODO: All of this Vertex and Index code is shared with Geometry, give them a base class to share
    inline float *GetVertices() { return m_GridBuffer.Vertices; };
    inline unsigned int *GetIndices() { return m_GridBuffer.Indices; };

    inline int GetVertexCount() { return m_VertexCount; };
    inline int GetVertexStride() { return m_VertexStride; };
    inline float GetVertexSize() { return m_VertexStride * m_VertexCount * sizeof(float); };

    inline VertexArray &GetVertexArray() { return *m_VertexArray; };
    inline VertexBuffer &GetVertexBuffer() { return *m_VertexBuffer; };
    inline IndexBuffer &GetIndexBuffer() { return *m_IndexBuffer; };

    inline int GetIndexCount() { return m_IndexCount; };

    BufferLayout GetLayout();

  protected:
    glm::vec3 m_PrimaryColor;
    glm::vec3 m_SecondaryColor;

    Transform m_Transform;

    float m_Precision;

    int m_VertexCount;
    int m_VertexStride;
    int m_IndexCount;

    BufferObject m_GridBuffer;

    VertexArray *m_VertexArray;
    VertexBuffer *m_VertexBuffer;
    IndexBuffer *m_IndexBuffer;

    void _SetPosition();

    void _SetGridUniforms();

    void _DrawIndexedLines();

    void _Initialize();
    void _TearDown();
  };
} // namespace DataGarden

#endif
