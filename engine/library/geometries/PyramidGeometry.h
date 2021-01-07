#ifndef DATA_GARDEN_PYRAMID_GEOMETRY
#define DATA_GARDEN_PYRAMID_GEOMETRY

#include "DataGarden.h"

#include "core/object/Geometry.h"

namespace DataGarden
{
  class PyramidGeometry : public Geometry
  {
  public:
    PyramidGeometry();
    virtual ~PyramidGeometry();

    virtual BufferLayout GetLayout() override;

  private:
    void _CreateBufferObject();
    void _DestroyBufferObject();
  };
} // namespace DataGarden

#endif
