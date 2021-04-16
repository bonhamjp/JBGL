#include "PyramidGeometry.h"

#include "core/renderer/BufferLayout.h"

#include "utility/NormalGenerator.h"

#include <glm/glm.hpp>

namespace DataGarden
{
  PyramidGeometry::PyramidGeometry()
  {
    m_VertexCount = 18;
    m_VertexStride = 8;
    m_IndexCount = 18;

    m_GeometryBuffer.Vertices = nullptr;
    m_GeometryBuffer.Indices = nullptr;

    _CreateBufferObject();

    _Initialize();
  }

  PyramidGeometry::~PyramidGeometry()
  {
    _DestroyBufferObject();
  }

  BufferLayout PyramidGeometry::GetLayout()
  {
    return BufferLayout({{BufferDataType::Float3, "v_Position"},
                         {BufferDataType::Float3, "v_Normal"},
                         {BufferDataType::Float2, "v_TextureCoordinates"}});
  }

  void PyramidGeometry::_CreateBufferObject()
  {
    glm::vec3 backLeft = glm::vec3(-0.5f, -0.5f, 0.5f);
    glm::vec3 backRight = glm::vec3(0.5f, -0.5f, 0.5f);
    glm::vec3 frontLeft = glm::vec3(-0.5f, -0.5f, -0.5f);
    glm::vec3 frontRight = glm::vec3(0.5f, -0.5f, -0.5f);
    glm::vec3 top = glm::vec3(0.0f, 0.5f, 0.0f);

    // counter clockwise winding
    // TODO just add in normals, instead of calculating, more efficient that way
    float defaultPyramid[] = {
        // back face
        // backRight.x, backRight.y, backRight.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 1
        // backLeft.x, backLeft.y, backLeft.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,    // 0
        // top.x, top.y, top.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,                   // 4
        backLeft.x, backLeft.y, backLeft.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 1
        backRight.x, backRight.y, backRight.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,    // 0
        top.x, top.y, top.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,                   // 4
        // front face
        frontLeft.x, frontLeft.y, frontLeft.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,    // 2
        frontRight.x, frontRight.y, frontRight.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 3
        top.x, top.y, top.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,                      // 4
        // left face
        backLeft.x, backLeft.y, backLeft.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,    // 0
        frontLeft.x, frontLeft.y, frontLeft.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 2
        top.x, top.y, top.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,                   // 4
        // right face
        backRight.x, backRight.y, backRight.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,    // 1
        frontRight.x, frontRight.y, frontRight.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 3
        top.x, top.y, top.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,                      // 4
        // bottom face
        frontRight.x, frontRight.y, frontRight.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 3
        backRight.x, backRight.y, backRight.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,    // 1
        backLeft.x, backLeft.y, backLeft.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,       // 0
        backLeft.x, backLeft.y, backLeft.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,       // 0
        frontLeft.x, frontLeft.y, frontLeft.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,    // 2
        frontRight.x, frontRight.y, frontRight.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 3
    };

    m_GeometryBuffer.Vertices = new float[(long long)m_VertexStride * (long long)m_VertexCount];

    for (int i = 0; i < m_VertexStride * m_VertexCount; i++)
    {
      m_GeometryBuffer.Vertices[i] = defaultPyramid[i];
    }

    unsigned int defaultIndices[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};

    m_GeometryBuffer.Indices = new unsigned int[(long long)m_IndexCount];

    for (int i = 0; i < m_IndexCount; i++)
    {
      m_GeometryBuffer.Indices[i] = defaultIndices[i];
    }

    GenerateSurfaceNormals(GetVertices(), GetIndices(), GetIndexCount(), GetVertexStride());
  }

  void PyramidGeometry::_DestroyBufferObject()
  {
    delete[] m_GeometryBuffer.Vertices;
    delete[] m_GeometryBuffer.Indices;
  }
} // namespace DataGarden
