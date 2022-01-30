#include <Arduino.h>
#include "curious_but_shy.hpp"
#include "globals.hpp"

short ANGRY_DISTANCE_LIMIT = 50;

bool CuriousButShy::interact() {
  int distance = this->distanceSensor->readRangeSingleMillimeters();

  if (distance < THING_SIGHT_DISTANCE) {
    digitalWrite(MOTOR_OUTPUT_PIN, HIGH);
    delay(2000);
    digitalWrite(MOTOR_OUTPUT_PIN, LOW);
    return true;
  }

  delay(10);
  return false;
}
