#include "mood.hpp"


#ifndef angry_h
#define angry_h

class Angry : public Mood {
  public:
    Angry(
      Servo* servo
    ) : Mood(servo) {

    }

    bool interact();
};

#endif // angry_h
