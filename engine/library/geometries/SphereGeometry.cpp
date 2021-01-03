#include "SphereGeometry.h"

#include "core/renderer/BufferLayout.h"

namespace DataGarden
{
  SphereGeometry::SphereGeometry(unsigned int subdivisions)
  {
    m_Subdivisions = subdivisions;

    m_VertexCount = _VerticesForSubdivisions(m_Subdivisions);
    m_VertexStride = 8;
    m_IndexCount = _IndicesForSubdivisions(m_Subdivisions);

    m_GeometryBuffer.Vertices = nullptr;
    m_GeometryBuffer.Indices = nullptr;

    _CreateBufferObject();

    _Initialize();
  }

	SphereGeometry::~SphereGeometry()
	{
		_DestroyBufferObject();
	}

  BufferLayout SphereGeometry::GetLayout()
	{
		return BufferLayout({
			{ BufferDataType::Float3, "v_Position" },
			{ BufferDataType::Float3, "v_Normal"},
      { BufferDataType::Float2, "v_TextureCoordinates" }
		});
	}

  glm::vec3 SphereGeometry::_GetVectorAtIndex(unsigned int vertexIndex)
  {
    // must account for vertex stride of input buffer
    unsigned int vertexOffset = vertexIndex * m_VertexStride;
    return glm::vec3(
      m_GeometryBuffer.Vertices[vertexOffset],
      m_GeometryBuffer.Vertices[vertexOffset + 1],
      m_GeometryBuffer.Vertices[vertexOffset + 2]
    );
  }

  unsigned int SphereGeometry::_GetHalfPointIndex(unsigned int vectorAIndex, unsigned int vectorBIndex)
  {
    // first check if we have it already
    bool firstIsSmaller = vectorAIndex < vectorBIndex;
    unsigned int smallerIndex = firstIsSmaller ? vectorAIndex : vectorBIndex;
    unsigned int greaterIndex = firstIsSmaller ? vectorBIndex : vectorAIndex;

    long long key = ((long long)smallerIndex << 32) + (long long)greaterIndex;

    // create point, and add index, if it does not exist
    if (m_HalfPointIndexCache.find(key) == m_HalfPointIndexCache.end())
    {
      glm::vec3 vectorA = _GetVectorAtIndex(vectorAIndex);
      glm::vec3 vectorB = _GetVectorAtIndex(vectorBIndex);

      glm::vec3 newVector = glm::normalize(glm::vec3((vectorA.x + vectorB.x) / 2.0f, (vectorA.y + vectorB.y) / 2.0f, (vectorA.z + vectorB.z) / 2.0f));

      // add to buffer at next index
      unsigned int bufferOffset = m_VertexStride * m_CurrentIndex;
      m_GeometryBuffer.Vertices[bufferOffset] = newVector.x;
      m_GeometryBuffer.Vertices[bufferOffset + 1] = newVector.y;
      m_GeometryBuffer.Vertices[bufferOffset + 2] = newVector.z;
      m_GeometryBuffer.Vertices[bufferOffset + 3] = 0.0f;
      m_GeometryBuffer.Vertices[bufferOffset + 4] = 0.0f;
      m_GeometryBuffer.Vertices[bufferOffset + 5] = 0.0f;
      m_GeometryBuffer.Vertices[bufferOffset + 6] = 0.0f;
      m_GeometryBuffer.Vertices[bufferOffset + 7] = 0.0f;

      // store index
      m_HalfPointIndexCache[key] = m_CurrentIndex;

      // ensure next new point goes to next index
      m_CurrentIndex++;
    }

    return m_HalfPointIndexCache[key];
  }

  unsigned int SphereGeometry::_VerticesForSubdivisions(unsigned int subdivision)
  {
    if (subdivision == 0)
    {
      return m_BaseVertexCount;
    }
    else
    {
      return (_VerticesForSubdivisions(subdivision - 1) * 4.0f);
    }
  }

  unsigned int SphereGeometry::_IndicesForSubdivisions(unsigned int subdivision)
  {
    if (subdivision == 0)
    {
      return m_BaseIndexCount;
    }
    else
    {
      return (_IndicesForSubdivisions(subdivision - 1) / 3.0f * 12.0f);
    }
  }

  void SphereGeometry::_NormalizeVertices()
  {
    for (unsigned int i = 0; i < m_CurrentIndex; i++)
    {
      unsigned int vertexOffset = i * m_VertexStride;

      float* rVert = &m_GeometryBuffer.Vertices[vertexOffset];

      glm::vec3 pointInCircle = glm::vec3(rVert[0], rVert[1], rVert[2]);
      glm::vec3 pointNormal = glm::normalize(glm::vec3(0.0f) - pointInCircle); // This shouldn't need to be normalized, since from unit circle

      // normal goes after coords
      rVert[3] = pointNormal.x;
      rVert[4] = pointNormal.y;
      rVert[5] = pointNormal.z;
    }
  }

	void SphereGeometry::_CreateBufferObject()
	{
    float t = (1.0f + sqrt(5.0f)) / 2.0f;

    // xy plane
    glm::vec3 vectorXYA = glm::normalize(glm::vec3(-1.0f, t, 0.0f));
    glm::vec3 vectorXYB = glm::normalize(glm::vec3(1.0f, t, 0.0f));
    glm::vec3 vectorXYC = glm::normalize(glm::vec3(-1.0f, -t, 0.0f));
    glm::vec3 vectorXYD = glm::normalize(glm::vec3(1.0f, -t, 0.0f));

    // yz plane
    glm::vec3 vectorYZA = glm::normalize(glm::vec3(0.0f, -1.0f, t));
    glm::vec3 vectorYZB = glm::normalize(glm::vec3(0.0f, 1.0f, t));
    glm::vec3 vectorYZC = glm::normalize(glm::vec3(0.0f, -1.0f, -t));
    glm::vec3 vectorYZD = glm::normalize(glm::vec3(0.0f, 1.0f, -t));

    // xz plane
    glm::vec3 vectorXZA = glm::normalize(glm::vec3(t, 0.0f, -1.0f));
    glm::vec3 vectorXZB = glm::normalize(glm::vec3(t, 0.0f, 1.0f));
    glm::vec3 vectorXZC = glm::normalize(glm::vec3(-t, 0.0f, -1.0f));
    glm::vec3 vectorXZD = glm::normalize(glm::vec3(-t, 0.0f, 1.0f));

    // counter clockwise winding
    float defaultIcosphere[] = {
      // xy plane
      vectorXYA.x, vectorXYA.y, vectorXYA.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,  // 0
      vectorXYB.x, vectorXYB.y, vectorXYB.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,  // 1
      vectorXYC.x, vectorXYC.y, vectorXYC.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,  // 2
      vectorXYD.x, vectorXYD.y, vectorXYD.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,  // 3

      // yz plane
      vectorYZA.x, vectorYZA.y, vectorYZA.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,  // 4
      vectorYZB.x, vectorYZB.y, vectorYZB.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,  // 5
      vectorYZC.x, vectorYZC.y, vectorYZC.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,  // 6
      vectorYZD.x, vectorYZD.y, vectorYZD.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,  // 7

       // xz plane
       vectorXZA.x, vectorXZA.y, vectorXZA.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 8
       vectorXZB.x, vectorXZB.y, vectorXZB.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 9
       vectorXZC.x, vectorXZC.y, vectorXZC.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, // 10
       vectorXZD.x, vectorXZD.y, vectorXZD.z, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f  // 11
    };

    m_GeometryBuffer.Vertices = new float[m_VertexStride * m_VertexCount];

    for (int i = 0; i < m_VertexStride * m_BaseVertexCount; i++)
    {
      m_GeometryBuffer.Vertices[i] = defaultIcosphere[i];
    }

    unsigned int defaultIndices[] = {
      0, 11, 5,
      0, 5, 1,
      0, 1, 7,
      0, 7, 10,
      0, 10, 11,
      1, 5, 9,
      5, 11, 4,
      11, 10, 2,
      10, 7, 6,
      7, 1, 8,
      3, 9, 4,
      3, 4, 2,
      3, 2, 6,
      3, 6, 8,
      3, 8, 9,
      4, 9, 5,
      2, 4, 11,
      6, 2, 10,
      8, 6, 7,
      9, 8, 1
    };

    m_CurrentIndex = 12;

    m_GeometryBuffer.Indices = new unsigned int[m_IndexCount];

    // I could use the m_GeometryBuffer.Indices as second swap buffer to prevent allocating two additional array
    // but they are only used in construction, and they make things more clear
    unsigned int* indexSwapBufferA = new unsigned int[m_IndexCount];
    unsigned int* indexSwapBufferB = new unsigned int[m_IndexCount];

    // for keeping track of which buffer is being read to/from
    unsigned int* indexInBuffer;
    unsigned int* indexOutBuffer;

    for (int i = 0; i < m_BaseIndexCount; i++)
    {
      indexSwapBufferA[i] = defaultIndices[i];
      indexSwapBufferB[i] = defaultIndices[i];
    }

    for (unsigned int subdivision = 1; subdivision <= m_Subdivisions; subdivision++)
    {
      // alternate in and out index buffers
      if (subdivision % 2 > 0)
      {
        indexInBuffer = indexSwapBufferA;
        indexOutBuffer = indexSwapBufferB;
      }
      else
      {
        indexInBuffer = indexSwapBufferB;
        indexOutBuffer = indexSwapBufferA;
      }

      unsigned int previousIndexCount = _IndicesForSubdivisions(subdivision - 1);

      unsigned int outputIndexBufferIndex = 0;

      for (unsigned int j = 0; j < previousIndexCount; j += 3)
      {
        // outer triangle indices
        unsigned int indexA = indexInBuffer[j];
        unsigned int indexB = indexInBuffer[j + 1];
        unsigned int indexC = indexInBuffer[j + 2];

        unsigned int halfIndexAB = _GetHalfPointIndex(indexA, indexB);
        unsigned int halfIndexBC = _GetHalfPointIndex(indexB, indexC);
        unsigned int halfIndexCA = _GetHalfPointIndex(indexC, indexA);

        // lower left triangle
        indexOutBuffer[outputIndexBufferIndex] = indexA;
        indexOutBuffer[outputIndexBufferIndex + 1] = halfIndexAB;
        indexOutBuffer[outputIndexBufferIndex + 2] = halfIndexCA;

        // lower right triangle
        indexOutBuffer[outputIndexBufferIndex + 3] = indexB;
        indexOutBuffer[outputIndexBufferIndex + 4] = halfIndexBC;
        indexOutBuffer[outputIndexBufferIndex + 5] = halfIndexAB;

        // top triangle
        indexOutBuffer[outputIndexBufferIndex + 8] = halfIndexBC;
        indexOutBuffer[outputIndexBufferIndex + 6] = indexC;
        indexOutBuffer[outputIndexBufferIndex + 7] = halfIndexCA;

        // middle triangle
        indexOutBuffer[outputIndexBufferIndex + 9] = halfIndexAB;
        indexOutBuffer[outputIndexBufferIndex + 10] = halfIndexBC;
        indexOutBuffer[outputIndexBufferIndex + 11] = halfIndexCA;

        outputIndexBufferIndex += 12;
      }
    }

    // determine which index buffer holds final indices,
    // based on how many iterations there were
    unsigned int* outputIndexBuffer;
    if (m_Subdivisions % 2 == 0)
    {
      outputIndexBuffer = indexSwapBufferA;
    }
    else
    {
      outputIndexBuffer = indexSwapBufferB;
    }

    // write calculated indices to geometry object
    for (unsigned int i = 0; i < m_IndexCount; i++)
    {
      m_GeometryBuffer.Indices[i] = outputIndexBuffer[i];
    }

    delete[] indexSwapBufferA;
    delete[] indexSwapBufferB;

    _NormalizeVertices();
	}

	void SphereGeometry::_DestroyBufferObject()
	{
		delete[] m_GeometryBuffer.Vertices;
		delete[] m_GeometryBuffer.Indices;
	}
}
