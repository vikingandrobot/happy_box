#include <Arduino.h>
#include <Servo.h>
#include "globals.hpp"

#ifndef mood_h_
#define mood_h_

class Mood {
  public:
    Servo* servo;

    Mood(Servo* servo) {
      this->servo = servo;
    }

    /**
     * Return true if the mood is finished
     */
    virtual bool interact();
};

#endif // mood_h_
