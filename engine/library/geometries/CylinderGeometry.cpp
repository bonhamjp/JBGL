#include "CylinderGeometry.h"

#include "core/renderer/BufferLayout.h"

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

namespace DataGarden
{
  CylinderGeometry::CylinderGeometry(unsigned int subdivisions)
  {
    m_Subdivisions = subdivisions;

    m_VertexCount = (m_Subdivisions + 1) * 2;
    m_VertexStride = 8;
    m_IndexCount = (m_Subdivisions * 3) * 2;

    m_GeometryBuffer.Vertices = nullptr;
    m_GeometryBuffer.Indices = nullptr;

    _CreateBufferObject();

    _Initialize();
  }

  CylinderGeometry::~CylinderGeometry()
  {
    _DestroyBufferObject();
  }

  BufferLayout CylinderGeometry::GetLayout()
  {
    return BufferLayout({{BufferDataType::Float3, "v_Position"},
                         {BufferDataType::Float3, "v_Normal"},
                         {BufferDataType::Float2, "v_TextureCoordinates"}});
  }

  void CylinderGeometry::_CreateBufferObject()
  {
    // TODO: Use triangle fans, for single primitive caps

    glm::vec3 topCenter = glm::vec3(0.0f, 0.5f, 0.0f);

    // top and bottom caps, without y set
    float *capOuterPoints = new float[3 * m_Subdivisions];

    // start on positive x axis
    glm::vec3 currentPosition = glm::vec3(0.5f, 0.0f, 0.0f);

    // figure even increment for full rotation, and add subdivision points
    float angleIncrement = (glm::pi<float>() * 2.0f) / ((float)m_Subdivisions);
    float currentAngle = 0.0f;

    for (unsigned int i = 0; i < m_Subdivisions; i++)
    {
      currentPosition = glm::normalize(glm::vec3(glm::cos(currentAngle) + -glm::sin(currentAngle), 0.0f, glm::sin(currentAngle) + glm::cos(currentAngle)));

      unsigned int capBufferOffset = 3 * i;
      capOuterPoints[capBufferOffset] = currentPosition.x;
      capOuterPoints[capBufferOffset + 1] = currentPosition.y;
      capOuterPoints[capBufferOffset + 2] = currentPosition.z;

      currentAngle += angleIncrement;
    }

    m_GeometryBuffer.Vertices = new float[m_VertexStride * m_VertexCount];

    // center top
    m_GeometryBuffer.Vertices[0] = 0.0f;
    m_GeometryBuffer.Vertices[1] = 1.0f;
    m_GeometryBuffer.Vertices[2] = 0.0f;
    m_GeometryBuffer.Vertices[3] = 0.0f;
    m_GeometryBuffer.Vertices[4] = 0.0f;
    m_GeometryBuffer.Vertices[5] = 0.0f;
    m_GeometryBuffer.Vertices[6] = 1.0f;
    m_GeometryBuffer.Vertices[7] = 0.0f;

    // center bottom
    m_GeometryBuffer.Vertices[8] = 0.0f;
    m_GeometryBuffer.Vertices[9] = -1.0f;
    m_GeometryBuffer.Vertices[10] = 0.0f;
    m_GeometryBuffer.Vertices[11] = 0.0f;
    m_GeometryBuffer.Vertices[12] = 0.0f;
    m_GeometryBuffer.Vertices[13] = 0.0f;
    m_GeometryBuffer.Vertices[14] = 1.0f;
    m_GeometryBuffer.Vertices[15] = 0.0f;

    for (unsigned int i = 0; i < m_Subdivisions; i++)
    {
      unsigned int capBufferOffset = 3 * i;

      // offset after center vertices
      unsigned int vertexBufferOffsetOne = (m_VertexStride * 2) + (m_VertexStride * i);

      // top cap point
      m_GeometryBuffer.Vertices[vertexBufferOffsetOne] = capOuterPoints[capBufferOffset];
      m_GeometryBuffer.Vertices[vertexBufferOffsetOne + 1] = 1.0f;
      m_GeometryBuffer.Vertices[vertexBufferOffsetOne + 2] = capOuterPoints[capBufferOffset + 2];
      m_GeometryBuffer.Vertices[vertexBufferOffsetOne + 3] = 0.0f;
      m_GeometryBuffer.Vertices[vertexBufferOffsetOne + 4] = 0.0f;
      m_GeometryBuffer.Vertices[vertexBufferOffsetOne + 5] = 0.0f;
      m_GeometryBuffer.Vertices[vertexBufferOffsetOne + 6] = 1.0f;
      m_GeometryBuffer.Vertices[vertexBufferOffsetOne + 7] = 0.0f;

      unsigned int offsetFromTop = (m_VertexStride * 2) + (m_VertexStride * m_Subdivisions);
      unsigned int vertexBufferOffsetTwo = offsetFromTop + (m_VertexStride * i);

      // // bottom cap point
      m_GeometryBuffer.Vertices[vertexBufferOffsetTwo] = capOuterPoints[capBufferOffset];
      m_GeometryBuffer.Vertices[vertexBufferOffsetTwo + 1] = -1.0f;
      m_GeometryBuffer.Vertices[vertexBufferOffsetTwo + 2] = capOuterPoints[capBufferOffset + 2];
      m_GeometryBuffer.Vertices[vertexBufferOffsetTwo + 3] = 0.0f;
      m_GeometryBuffer.Vertices[vertexBufferOffsetTwo + 4] = 0.0f;
      m_GeometryBuffer.Vertices[vertexBufferOffsetTwo + 5] = 0.0f;
      m_GeometryBuffer.Vertices[vertexBufferOffsetTwo + 6] = -1.0f;
      m_GeometryBuffer.Vertices[vertexBufferOffsetTwo + 7] = 0.0f;

      // TODO: Add side points, with calculated normals

      // TODO: Add normals and texture coords
    }

    m_GeometryBuffer.Indices = new unsigned int[(long long)m_IndexCount];
    unsigned int currentIndexTop = 0;
    unsigned int currentIndexBottom = m_IndexCount / 2;

    for (int i = 0; i < m_Subdivisions; i++)
    {
      unsigned int indexBufferOffset = 3 * i;

      // TODO: Add indices for bottom cap, and sides

      // always index into center of cap first
      m_GeometryBuffer.Indices[currentIndexTop++] = 0;
      m_GeometryBuffer.Indices[currentIndexTop++] = i + 2;

      unsigned int offsetFromTop = m_Subdivisions + 2;

      m_GeometryBuffer.Indices[currentIndexBottom++] = 1;
      m_GeometryBuffer.Indices[currentIndexBottom++] = i + offsetFromTop;

      // last point wraps back to first
      if (i == (m_Subdivisions - 1))
      {
        m_GeometryBuffer.Indices[currentIndexTop++] = 2;
        m_GeometryBuffer.Indices[currentIndexBottom++] = 2 + offsetFromTop;
      }
      else
      {
        m_GeometryBuffer.Indices[currentIndexTop++] = i + 3;
        m_GeometryBuffer.Indices[currentIndexBottom++] = i + offsetFromTop + 1;
      }
    }
  }

  void CylinderGeometry::_DestroyBufferObject()
  {
    delete[] m_GeometryBuffer.Vertices;
    delete[] m_GeometryBuffer.Indices;
  }
} // namespace DataGarden
