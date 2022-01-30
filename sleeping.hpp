#include "mood.hpp"
#include "globals.hpp"


#ifndef sleeping_h
#define sleeping_h

class Sleeping : public Mood {
  
  public:
    Sleeping(
      VL53L0X* distanceSensor
    ) : Mood(distanceSensor) {
      
    }

    bool interact();
};

#endif // sleeping_h
