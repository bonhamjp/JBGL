#ifndef DATA_GARDEN_NORMAL_GENERATOR
#define DATA_GARDEN_NORMAL_GENERATOR

#include "DataGarden.h"

namespace DataGarden
{
  // requires position in first 3 slots, and normal to be stored in last 3 slots
  void GenerateSurfaceNormals(float *vertices, unsigned int *indices, unsigned int indexCount, unsigned int vertexStride);
  // requires position in first 3 slots, and normal to be stored in last 3 slots
  void GeneratePointNormals(float *vertices, unsigned int *indices, unsigned int indexCount, unsigned int vertexStride);
}

#endif
