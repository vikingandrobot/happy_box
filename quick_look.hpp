#include "mood.hpp"


#ifndef quick_look_h
#define quick_look_h

class QuickLook : Mood {
  public:
    QuickLook(
      Servo* servo
    ) : Mood(servo) {

    }

    bool interact();
};

#endif // quick_look_h
