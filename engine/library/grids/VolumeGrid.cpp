#include "VolumeGrid.h"

#include "core/renderer/BufferLayout.h"

#include <iostream>

namespace DataGarden
{
  VolumeGrid::VolumeGrid(float precision) : Grid(precision)
  {
    // TODO: Re-use 4 shared vertices
    m_VertexCount = 3 * 2 * m_Precision;
    m_IndexCount = 3 * 2 * m_Precision; // Each axis has two points for each line of precision

    m_GridBuffer.Vertices = nullptr;
    m_GridBuffer.Indices = nullptr;

    _CreateBufferObject();

    _Initialize();
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
    for (int i = 0; i < m_VertexStride * m_VertexCount; i += 18)
    {
      float offset = lineNumber * spacing;

      // X-Axis
      m_GridBuffer.Vertices[i] = offset;   // x
      m_GridBuffer.Vertices[i + 1] = 0.0f; // y
      m_GridBuffer.Vertices[i + 2] = 0.0f; // z

      m_GridBuffer.Vertices[i + 3] = offset; // x
      m_GridBuffer.Vertices[i + 4] = 0.0f;   // y
      m_GridBuffer.Vertices[i + 5] = 1.0f;   // z

      // Y-Axis
      m_GridBuffer.Vertices[i + 6] = offset; // x
      m_GridBuffer.Vertices[i + 7] = 0.0f;   // y
      m_GridBuffer.Vertices[i + 8] = 0.0f;   // z

      m_GridBuffer.Vertices[i + 9] = offset; // x
      m_GridBuffer.Vertices[i + 10] = 1.0f;  // y
      m_GridBuffer.Vertices[i + 11] = 0.0f;  // z

      // Z-Axis
      m_GridBuffer.Vertices[i + 12] = 0.0f;   // x
      m_GridBuffer.Vertices[i + 13] = 0.0f;   // y
      m_GridBuffer.Vertices[i + 14] = offset; // z

      m_GridBuffer.Vertices[i + 15] = 1.0f;   // x
      m_GridBuffer.Vertices[i + 16] = 0.0f;   // y
      m_GridBuffer.Vertices[i + 17] = offset; // z

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
