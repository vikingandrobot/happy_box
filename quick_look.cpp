#include "quick_look.hpp"
#include "globals.hpp"

bool QuickLook::interact() {
  delay(50);
  ++this->numberOfCycles;
  if (this->numberOfCycles < 150) {
    int distance = this->distanceSensor->readRangeSingleMillimeters();
    if (this->numberOfCycles == 1 && distance >= THING_PERSONAL_SPACE_DISTANCE) {
      digitalWrite(MOTOR_OUTPUT_PIN, HIGH);
      return false;
    } 

    if (distance < THING_PERSONAL_SPACE_DISTANCE) {
      digitalWrite(MOTOR_OUTPUT_PIN, LOW);
      this->numberOfCycles = 0;
      return true;
    }
  } else {
    // The thing has been looking for long enough
    digitalWrite(MOTOR_OUTPUT_PIN, LOW);
    this->numberOfCycles = 0;
    return true;
  }

  return false;
}
