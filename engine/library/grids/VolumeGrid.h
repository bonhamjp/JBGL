#ifndef DATA_GARDEN_VOLUME_GRID
#define DATA_GARDEN_VOLUME_GRID

#include "DataGarden.h"

#include "core/grid/Grid.h"

namespace DataGarden
{
  class VolumeGrid : public Grid
  {
  public:
    VolumeGrid(float precision);
    virtual ~VolumeGrid();

  private:
    void _CreateBufferObject();
    void _DestroyBufferObject();
  };
} // namespace DataGarden

#endif
