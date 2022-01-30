#include <Arduino.h>
#include "sleeping.hpp"
#include "globals.hpp"


bool Sleeping::interact() {

  for (int i = 0; i < 8; i++) {
    int distance = this->distanceSensor->readRangeSingleMillimeters();
    // If the distance is lower than that for 4 seconds, it will wake up the thing
    if (distance > THING_PERSONAL_SPACE_DISTANCE / 2) {
      return false;
    }

    delay(500);
  }
  
  

  // Wake up sequence
  digitalWrite(MOTOR_OUTPUT_PIN, HIGH);
  delay(800);
  digitalWrite(MOTOR_OUTPUT_PIN, LOW);
  delay(800);
  digitalWrite(MOTOR_OUTPUT_PIN, HIGH);
  delay(800);
  digitalWrite(MOTOR_OUTPUT_PIN, LOW);
  delay(800);
  digitalWrite(MOTOR_OUTPUT_PIN, HIGH);
  delay(800);
  digitalWrite(MOTOR_OUTPUT_PIN, LOW);
  delay(800);

  return true;
}
