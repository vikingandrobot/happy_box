#include "mood.hpp"


#ifndef curious_but_shy_h
#define curious_but_shy_h

class CuriousButShy : public Mood {
  public:
    CuriousButShy(
      VL53L0X* distanceSensor
    ) : Mood(distanceSensor) {
    }

    bool interact();
};

#endif // curious_but_shy_h
