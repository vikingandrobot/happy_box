#include <Arduino.h>
#include "angry.hpp"
#include "globals.hpp"


bool Angry::interact() {
  if (this->angryScale == 0) {    
    digitalWrite(MOTOR_OUTPUT_PIN, HIGH);
    delay(1500);
    digitalWrite(MOTOR_OUTPUT_PIN, LOW);
  }

  for (short i = 0; i < this->angryScale; ++i) {
    digitalWrite(MOTOR_OUTPUT_PIN, HIGH);
    delay(500);
    digitalWrite(MOTOR_OUTPUT_PIN, LOW);
    delay(800);
  }
  delay(1000);
  int distance = this->distanceSensor->readRangeSingleMillimeters();
  
  if (distance < this->ANGRY_DISTANCE_LIMIT) {
    this->angryScale += 1;
    return false;
  }

  this->angryScale = 0;
  return true;
}
