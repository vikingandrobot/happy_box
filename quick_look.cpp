#include "quick_look.hpp"

bool QuickLook::interact() {
  for (short angle = SERVO_MAX_ANGLE; angle >= SERVO_MIN_ANGLE; --angle) {
    this->servo->write(angle);
    delay(20);
  }

  this->servo->write(SERVO_MIN_ANGLE + 3);

  delay(2000);

  this->servo->write(SERVO_MAX_ANGLE);

  delay(1000);

  return false;
}
