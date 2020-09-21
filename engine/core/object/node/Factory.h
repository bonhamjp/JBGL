#ifndef DATA_GARDEN_FACTORY
#define DATA_GARDEN_FACTORY

#include "DataGarden.h"

#include "Node.h"

namespace DataGarden
{
  class Factory
  {
  public:
    Factory();
    ~Factory();

    virtual Node* Generate(Node* parentNode) = 0;
  };
}

#endif
