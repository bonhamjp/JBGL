#ifndef DATA_GARDEN_UI
#define DATA_GARDEN_UI

namespace DataGarden
{
  class UI
  {
  public:
    UI();
    virtual ~UI();

    virtual void Update();
    virtual void Render();

  protected:
  };
}

#endif
