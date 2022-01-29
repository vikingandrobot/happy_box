#include "globals.hpp"
#include "mood.hpp"
#include "quick_look.hpp"
#include "angry.hpp"

Servo servo;

QuickLook quickLook(&servo);
Angry angry(&servo);
Mood* currentMood;

short TOTAL_MOODS = 2;
short currentMoodIndex = 1;

short increment(short moodIndex) {
  if (moodIndex >= TOTAL_MOODS - 1) {
    return 0;
  }
  return moodIndex + 1;
}

Mood* getCurrentMood(short moodIndex) {
  switch(moodIndex){
    case 1:
      return &angry;
    
    case 0:
    default:
      return &quickLook;
  }
}



void setup() {
  // Servo will be controlled using pin 3 
  servo.attach(3);
  servo.write(SERVO_MAX_ANGLE);

  Serial.begin(9600);

  // The pin to use to let electricity flow to the motor
  pinMode(MOTOR_OUTPUT_PIN, OUTPUT);
}

void loop() {

  currentMood = getCurrentMood(currentMoodIndex);

  // put your main code here, to run repeatedly:
  bool result = currentMood->interact();

  if (result) {
    currentMoodIndex = increment(currentMoodIndex);
  }

  delay(2000);
}
