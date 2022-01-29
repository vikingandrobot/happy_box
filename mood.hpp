#include <Arduino.h>
#include <Servo.h>

#ifndef mood_h_
#define mood_h_

/**
 * A Mood implementation defines how the Thing will interact with the world.
 */
class Mood {
  public:
    Servo* servo;

    Mood(Servo* servo) {
      this->servo = servo;
    }

    /**
     * Method to call to keep the Mood interacting with the world.
     * It will return true when it is done.
     */
    virtual bool interact();
};

#endif // mood_h_
