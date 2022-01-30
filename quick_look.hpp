#include "mood.hpp"


#ifndef quick_look_h
#define quick_look_h

class QuickLook : public Mood {
  private:
    short numberOfCycles;
  
  public:
    QuickLook(
      VL53L0X* distanceSensor
    ) : Mood(distanceSensor) {
      numberOfCycles = 0;
    }

    bool interact();
};

#endif // quick_look_h
