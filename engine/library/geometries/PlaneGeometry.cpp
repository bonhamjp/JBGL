#include "PlaneGeometry.h"

#include "core/renderer/BufferLayout.h"

namespace DataGarden
{
	PlaneGeometry::PlaneGeometry()
	{
    m_VertexCount = 4;
    m_VertexStride = 8;
    m_IndexCount = 6;

    m_GeometryBuffer.Vertices = nullptr;
    m_GeometryBuffer.Indices = nullptr;

    _CreateBufferObject();

    _Initialize();
	}

	PlaneGeometry::~PlaneGeometry()
	{
		_DestroyBufferObject();
	}

  BufferLayout PlaneGeometry::GetLayout()
	{
		return BufferLayout({
			{ BufferDataType::Float3, "v_Position" },
			{ BufferDataType::Float3, "v_Normal"},
      { BufferDataType::Float2, "v_TextureCoordinates" }
		});
	}

	void PlaneGeometry::_CreateBufferObject()
	{
    // counter clockwise winding, facing up
    float defaultPlane[] = {
       0.5f, 0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, // 0
       0.5f, 0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, // 1
      -0.5f, 0.0f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, // 2
      -0.5f, 0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f  // 3
    };

		m_GeometryBuffer.Vertices = new float[(long long)m_VertexStride * (long long)m_VertexCount];

		for (int i = 0; i < m_VertexStride * m_VertexCount; i++)
		{
			m_GeometryBuffer.Vertices[i] = defaultPlane[i];
		}

		unsigned int defaultIndices[] = {
      0, 1, 2, 2, 3, 0
		};

		m_GeometryBuffer.Indices = new unsigned int[(long long)m_IndexCount];

		for (int i = 0; i < m_IndexCount; i++)
		{
			m_GeometryBuffer.Indices[i] = defaultIndices[i];
		}
	}

	void PlaneGeometry::_DestroyBufferObject()
	{
		delete[] m_GeometryBuffer.Vertices;
		delete[] m_GeometryBuffer.Indices;
	}
}
