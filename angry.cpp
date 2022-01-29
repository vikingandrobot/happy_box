#include <Arduino.h>
#include "angry.hpp"
#include "globals.hpp"

bool Angry::interact() {
  delay(100);

  digitalWrite(MOTOR_OUTPUT_PIN, HIGH);

  delay (2000);

  Serial.println(MOTOR_OUTPUT_PIN);

  digitalWrite(MOTOR_OUTPUT_PIN, LOW);

  delay(100);

  return true;
}
