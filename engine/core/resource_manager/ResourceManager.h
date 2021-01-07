#ifndef DATA_GARDEN_RESOURCE_MANAGER
#define DATA_GARDEN_RESOURCE_MANAGER

#include "DataGarden.h"

#include <string>
#include <map>

namespace DataGarden
{
  // Subclass to pass any extra arguments to constructor lambdas
  struct ResourceDescriptor
  {
    std::string Name;
  };

  template <typename T>
  class ResourceManager
  {
  public:
    ResourceManager()
    {
    }

    ~ResourceManager()
    {
    }

    bool HasResource(std::string &resourceName)
    {
      if (m_Resources.find(resourceName) != m_Resources.end())
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    int ResourceCount(std::string &resourceName)
    {
      return m_Resources.find(resourceName)->second.Count;
    }

    T *AddResource(ResourceDescriptor *descriptor, T *(*f)(ResourceDescriptor *descriptor))
    {
      if (m_Resources.find(descriptor->Name) != m_Resources.end())
      {
        return m_Resources.find(descriptor->Name)->second; // T*(m_Resources.find(descriptor->Name)->second);
      }
      else
      {
        T *newResource = (*f)(descriptor);

        m_Resources[descriptor->Name] = newResource;

        return newResource;
      }
    }

  private:
    std::map<std::string, T *> m_Resources;
  };
} // namespace DataGarden

#endif
