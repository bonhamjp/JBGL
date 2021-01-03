#include "PyramidGeometry.h"

#include "core/renderer/BufferLayout.h"

#include <glm/glm.hpp>

namespace DataGarden
{
	PyramidGeometry::PyramidGeometry()
	{
		m_VertexCount = 16;
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
		return BufferLayout({
			{ BufferDataType::Float3, "v_Position" },
			{ BufferDataType::Float3, "v_Normal"},
      { BufferDataType::Float2, "v_TextureCoordinates" }
		});
	}

	void PyramidGeometry::_CreateBufferObject()
	{
    glm::vec3 top = glm::vec3(0.0f, 0.5f, 0.0f);

    glm::vec3 backLeft = glm::vec3(-0.5f, -0.5f, -0.5f);
    glm::vec3 backRight = glm::vec3(0.5f, -0.5f, -0.5f);
    glm::vec3 backNormal = glm::normalize(glm::cross(backLeft - backRight, top - backLeft));

    glm::vec3 frontLeft = glm::vec3(-0.5f, -0.5f, 0.5f);
    glm::vec3 frontRight = glm::vec3(0.5f, -0.5f, 0.5f);
    glm::vec3 frontNormal = glm::normalize(glm::cross(frontRight - frontLeft, top - frontRight));

    glm::vec3 leftBack = glm::vec3(-0.5f, -0.5f, -0.5f);
    glm::vec3 leftFront = glm::vec3(-0.5f, -0.5f, 0.5f);
    glm::vec3 leftNormal = glm::normalize(glm::cross(leftBack - leftFront, top - leftBack));

    glm::vec3 rightBack = glm::vec3(0.5f, -0.5f, 0.5f);
    glm::vec3 rightFront = glm::vec3(0.5f, -0.5f, -0.5f);
    glm::vec3 rightNormal = glm::normalize(glm::cross(rightFront - rightBack, top - rightFront));

    // TODO: Fix normals, they appear to be incorrect
    // counter clockwise winding
    float defaultPyramid[] = {
      // back face
      backRight.x, backRight.y, backRight.z, 0.0f, 0.0f, backNormal.x, backNormal.y, backNormal.z, // 0
      backLeft.x,  backLeft.y,  backLeft.z,  0.0f, 0.0f, backNormal.x, backNormal.y, backNormal.z, // 1
      top.x,       top.y,       top.z,       0.0f, 0.0f, backNormal.x, backNormal.y, backNormal.z, // 2

      // front face
      frontLeft.x,  frontLeft.y,  frontLeft.z,  0.0f, 0.0f, frontNormal.x, frontNormal.y, frontNormal.z, // 3
      frontRight.x, frontRight.y, frontRight.z, 0.0f, 0.0f, frontNormal.x, frontNormal.y, frontNormal.z, // 4
      top.x,        top.y,        top.z,        0.0f, 0.0f, frontNormal.x, frontNormal.y, frontNormal.z, // 5

      // left face
      leftBack.x,  leftBack.y,  leftBack.z,  -1.0f, 0.0f, leftNormal.x, leftNormal.y, leftNormal.z, // 6
      leftFront.x, leftFront.y, leftFront.z, -1.0f, 0.0f, leftNormal.x, leftNormal.y, leftNormal.z, // 7
      top.x,       top.y,       top.z,        0.0f, 0.0f, leftNormal.x, leftNormal.y, leftNormal.z, // 8

      // right face
      rightFront.x, rightFront.y, rightFront.z, 1.0f, 0.0f, rightNormal.x, rightNormal.y, rightNormal.z, // 9
      rightBack.x,  rightBack.y,  rightBack.z,  1.0f, 0.0f, rightNormal.x, rightNormal.y, rightNormal.z, // 10
      top.x,        top.y,        top.z,        0.0f, 0.0f, rightNormal.x, rightNormal.y, rightNormal.z, // 11

      // bottom face
      -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f, // 12
       0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // 13
       0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // 14
      -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f, // 15
    };

    m_GeometryBuffer.Vertices = new float[(long long)m_VertexStride * (long long)m_VertexCount];

    for (int i = 0; i < m_VertexStride * m_VertexCount; i++)
    {
      m_GeometryBuffer.Vertices[i] = defaultPyramid[i];
    }

    unsigned int defaultIndices[] = {
      // back face
      0, 1, 2,

      // front face
      3, 4, 5,

      // left face
      6, 7, 8,

      // right face
      9, 10, 11,

      // bottom face
      12, 13, 14, 14, 15, 12
    };

    m_GeometryBuffer.Indices = new unsigned int[(long long)m_IndexCount];

    for (int i = 0; i < m_IndexCount; i++)
    {
      m_GeometryBuffer.Indices[i] = defaultIndices[i];
    }
	}

	void PyramidGeometry::_DestroyBufferObject()
	{
		delete[] m_GeometryBuffer.Vertices;
		delete[] m_GeometryBuffer.Indices;
	}
}
