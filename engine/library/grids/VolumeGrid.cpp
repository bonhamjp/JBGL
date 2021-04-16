#include "VolumeGrid.h"

#include "core/renderer/BufferLayout.h"

#include <iostream>

namespace DataGarden
{
  VolumeGrid::VolumeGrid(glm::vec3 primaryColor, glm::vec3 secondaryColor, float precision) : Grid(primaryColor, secondaryColor, precision)
  {
    // TODO: Re-use 4 shared vertices
    m_VertexCount = 6 * 2 * m_Precision;
    m_IndexCount = 6 * 2 * m_Precision; // Each axis has two points for each line of precision

    m_GridBuffer.Vertices = nullptr;
    m_GridBuffer.Indices = nullptr;

    _CreateBufferObject();

    _Initialize();
  }

  VolumeGrid::VolumeGrid(glm::vec3 primaryColor, float precision) : VolumeGrid(primaryColor, primaryColor, precision)
  {

  }

  VolumeGrid::~VolumeGrid()
  {
    _DestroyBufferObject();
  }

  void VolumeGrid::_CreateBufferObject()
  {
    m_GridBuffer.Vertices = new float[(long long)m_VertexStride * (long long)m_VertexCount];

    // Model space is unit size, so it can easily be scaled
    float spacing = 1.0f / m_Precision;
    float lineNumber = 0.0f;

    // Build each axis at once
    for (int i = 0; i < m_VertexStride * m_VertexCount; i += 36)
    {
      float offset = lineNumber * spacing;

      m_GridBuffer.Vertices[i] = offset;   // x
      m_GridBuffer.Vertices[i + 1] = 0.0f; // y
      m_GridBuffer.Vertices[i + 2] = 0.0f; // z

      m_GridBuffer.Vertices[i + 3] = offset; // x
      m_GridBuffer.Vertices[i + 4] = 1.0f;   // y
      m_GridBuffer.Vertices[i + 5] = 0.0f;   // z

      m_GridBuffer.Vertices[i + 6] = offset; // x
      m_GridBuffer.Vertices[i + 7] = 0.0f;   // y
      m_GridBuffer.Vertices[i + 8] = 0.0f;   // z

      m_GridBuffer.Vertices[i + 9] = offset; // x
      m_GridBuffer.Vertices[i + 10] = 0.0f;  // y
      m_GridBuffer.Vertices[i + 11] = 1.0f;  // z

      m_GridBuffer.Vertices[i + 12] = 0.0f;   // x
      m_GridBuffer.Vertices[i + 13] = offset; // y
      m_GridBuffer.Vertices[i + 14] = 0.0;    // z

      m_GridBuffer.Vertices[i + 15] = 0.0f;   // x
      m_GridBuffer.Vertices[i + 16] = offset; // y
      m_GridBuffer.Vertices[i + 17] = 1.0;    // z

      m_GridBuffer.Vertices[i + 18] = 0.0f;   // x
      m_GridBuffer.Vertices[i + 19] = offset; // y
      m_GridBuffer.Vertices[i + 20] = 0.0f;   // z

      m_GridBuffer.Vertices[i + 21] = 1.0f;   // x
      m_GridBuffer.Vertices[i + 22] = offset; // y
      m_GridBuffer.Vertices[i + 23] = 0.0f;   // z

      m_GridBuffer.Vertices[i + 24] = 0.0f;   // x
      m_GridBuffer.Vertices[i + 25] = 0.0f;   // y
      m_GridBuffer.Vertices[i + 26] = offset; // z

      m_GridBuffer.Vertices[i + 27] = 1.0f;   // x
      m_GridBuffer.Vertices[i + 28] = 0.0f;   // y
      m_GridBuffer.Vertices[i + 29] = offset; // z

      m_GridBuffer.Vertices[i + 30] = 0.0f;   // x
      m_GridBuffer.Vertices[i + 31] = 0.0f;   // y
      m_GridBuffer.Vertices[i + 32] = offset; // z

      m_GridBuffer.Vertices[i + 33] = 0.0f;   // x
      m_GridBuffer.Vertices[i + 34] = 1.0f;   // y
      m_GridBuffer.Vertices[i + 35] = offset; // z

      lineNumber++;
    }

    m_GridBuffer.Indices = new unsigned int[(long long)m_IndexCount];

    for (int i = 0; i < m_IndexCount; i++)
    {
      m_GridBuffer.Indices[i] = i;
    }
  }

  void VolumeGrid::_DestroyBufferObject()
  {
    delete[] m_GridBuffer.Vertices;
    delete[] m_GridBuffer.Indices;
  }
} // namespace DataGarden
