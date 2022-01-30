#include "mood.hpp"
#include "globals.hpp"


#ifndef angry_h
#define angry_h

class Angry : public Mood {
  private:
    short angryScale;
    int ANGRY_DISTANCE_LIMIT;
  
  public:
    Angry(
      VL53L0X* distanceSensor
    ) : Mood(distanceSensor) {
      angryScale = 0;
      this->ANGRY_DISTANCE_LIMIT = THING_PERSONAL_SPACE_DISTANCE / 2.0;
    }

    bool interact();
};

#endif // angry_h
