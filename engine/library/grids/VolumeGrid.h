#ifndef DATA_GARDEN_VOLUME_GRID
#define DATA_GARDEN_VOLUME_GRID

#include "DataGarden.h"

#include "core/grid/Grid.h"

namespace DataGarden
{
  class VolumeGrid : public Grid
  {
  public:
    VolumeGrid(glm::vec3 primaryColor, glm::vec3 secondaryColor, float precision);
    VolumeGrid(glm::vec3 primaryColor, float precision);
    virtual ~VolumeGrid();

  private:
    void _CreateBufferObject();
    void _DestroyBufferObject();
  };
} // namespace DataGarden

#endif
