#include "NormalGenerator.h"

#include <assert.h>
#include <iostream>

#include <glm/glm.hpp>

#include <iostream>

namespace DataGarden
{
  unsigned int GetVertexOffset(unsigned int index, unsigned int vertexStride)
  {
    return index * vertexStride;
  }

  glm::vec3 GetPositionAtIndex(float *vertices, unsigned int index, unsigned int vertexStride)
  {
    unsigned int vertexOffset = GetVertexOffset(index, vertexStride);
    return glm::vec3(vertices[vertexOffset], vertices[vertexOffset + 1], vertices[vertexOffset + 2]);
  }

  void AddNormalToVertex(float *vertices, unsigned int index, unsigned int vertexStride, glm::vec3 *normal)
  {
    unsigned int vertexOffset = GetVertexOffset(index, vertexStride);
    // adding stride goes one past the end of the vertex so -1 -2 and -3 are the last three position in vertex
    vertices[vertexOffset + vertexStride - 3] = normal->x;
    vertices[vertexOffset + vertexStride - 2] = normal->y;
    vertices[vertexOffset + vertexStride - 1] = normal->z;
  }

  void GenerateSurfaceNormals(float *vertices, unsigned int *indices, unsigned int indexCount, unsigned int vertexStride)
  {
    assert(indexCount % 3 == 0);

    for (unsigned int i = 0; i < indexCount; i += 3)
    {
      glm::vec3 position1 = GetPositionAtIndex(vertices, indices[i], vertexStride);
      glm::vec3 position2 = GetPositionAtIndex(vertices, indices[i + 1], vertexStride);
      glm::vec3 position3 = GetPositionAtIndex(vertices, indices[i + 2], vertexStride);

      glm::vec3 normal = glm::normalize(glm::cross(position1 - position2, position1 - position3));

      std::cout << "NORMAL: (" << normal.x << ", " << normal.y << ", " << normal.z << ")" << std::endl;

      AddNormalToVertex(vertices, indices[i], vertexStride, &normal);
      AddNormalToVertex(vertices, indices[i + 1], vertexStride, &normal);
      AddNormalToVertex(vertices, indices[i + 2], vertexStride, &normal);
    }
  }

  void GeneratePointNormals(float *vertices, unsigned int *indices, unsigned int indexCount, unsigned int vertexStride)
  {
    assert(indexCount % 3 == 0);
  }
}
