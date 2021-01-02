#include "CubeGeometry.h"

#include "core/renderer/BufferLayout.h"

namespace DataGarden
{
	CubeGeometry::CubeGeometry()
	{
		m_VertexCount = 24;
		m_VertexStride = 8;
		m_IndexCount = 36;

		m_GeometryBuffer.Vertices = nullptr;
		m_GeometryBuffer.Indices = nullptr;

		_CreateBufferObject();

    _Initialize();
	}

	CubeGeometry::~CubeGeometry()
	{
		_DestroyBufferObject();
	}

  std::string& CubeGeometry::GetName()
  {
    std::string name = std::string("Cube");
    return name;
  }

	BufferLayout CubeGeometry::GetLayout()
	{
		return BufferLayout({
			{ BufferDataType::Float3, "v_Position" },
			{ BufferDataType::Float3, "v_Normal"},
      { BufferDataType::Float2, "v_TextureCoordinates" }
		});
	}

	void CubeGeometry::_CreateBufferObject()
	{
    // counter clockwise winding
    float defaultBox[] = {
      // back face
      0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f,  // 0
      0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f,  // 1
      -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f, // 2
      -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f, // 3

      // front face
      -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f, // 4
       0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f, // 5
       0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f, // 6
      -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // 7

      // left face
      -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // 8
      -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // 9
      -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f, // 10
      -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f, // 11

      // right face
       0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // 12
       0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // 13
       0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // 14
       0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // 15

      // bottom face
      -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f, // 16
       0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // 17
       0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // 18
      -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f, // 19

      // top face
       0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f, // 20
       0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f, // 21
      -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // 22
      -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f  // 23
    };

		m_GeometryBuffer.Vertices = new float[(long long)m_VertexStride * (long long)m_VertexCount];

		for (int i = 0; i < m_VertexStride * m_VertexCount; i++)
		{
			m_GeometryBuffer.Vertices[i] = defaultBox[i];
		}

		unsigned int defaultIndices[] = {
			// back face
			0, 1, 2, 2, 3, 0,

			// front face
			4, 5, 6, 6, 7, 4,

			// left face
			8, 9, 10, 10, 11, 8,

			// right face
			12, 13, 14, 14, 15, 12,

			// bottom face
			16, 17, 18, 18, 19, 16,

			// top face
			20, 21, 22, 22, 23, 20
		};

		m_GeometryBuffer.Indices = new unsigned int[(long long)m_IndexCount];

		for (int i = 0; i < m_IndexCount; i++)
		{
			m_GeometryBuffer.Indices[i] = defaultIndices[i];
		}
	}

	void CubeGeometry::_DestroyBufferObject()
	{
		delete[] m_GeometryBuffer.Vertices;
		delete[] m_GeometryBuffer.Indices;
	}
}
