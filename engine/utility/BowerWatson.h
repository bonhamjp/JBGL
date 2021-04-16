
#ifndef DATA_GARDEN_BOWER_WATSON
#define DATA_GARDEN_BOWER_WATSON

#include "DataGarden.h"

namespace DataGarden
{
  struct BowerWatson
  {
    unsigned int vertexCount;
    float *Vertices;
  };

  BowerWatson GenerateTrianglesUsingBowerWatson(float *vertices, unsigned int vertexCount);
}

#endif