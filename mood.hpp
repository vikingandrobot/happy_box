#include <Arduino.h>
#include <VL53L0X.h>

#ifndef mood_h_
#define mood_h_

/**
 * A Mood implementation defines how the Thing will interact with the world.
 */
class Mood {
  public:
    VL53L0X* distanceSensor;

    Mood(VL53L0X* distanceSensor) {
      this->distanceSensor = distanceSensor;
    }

    /**
     * Method to call to keep the Mood interacting with the world.
     * It will return true when it is done.
     */
    virtual bool interact();
};

#endif // mood_h_
