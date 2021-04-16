#ifndef DATA_GARDEN_UI
#define DATA_GARDEN_UI

namespace DataGarden
{
  class UI
  {
  public:
    UI();
    virtual ~UI();

    virtual void Update() = 0;
    virtual void Render() = 0;

  protected:
  };
} // namespace DataGarden

#endif
