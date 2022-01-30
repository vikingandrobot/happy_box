#include "globals.hpp"
#include "mood.hpp"
#include "sleeping.hpp"
#include "quick_look.hpp"
#include "angry.hpp"
#include "curious_but_shy.hpp"

VL53L0X distanceSensor;

#define QUICK_LOOK 0
#define ANGRY 1
#define CURIOUS_BUT_SHY 2

// Different available moods
Sleeping sleeping(&distanceSensor);
QuickLook quickLook(&distanceSensor);
Angry angry(&distanceSensor);
CuriousButShy curiousButShy(&distanceSensor);
Mood* currentMood;

short currentMoodIndex = -1;

bool isMoodFinished = false;

/**
 * return the mood that has triggered, -1 if there are no mood available.
 */
short waitForMoodToTrigger() {
  int distance = distanceSensor.readRangeSingleMillimeters();

  if (distance < THING_PERSONAL_SPACE_DISTANCE / 2) {
    return ANGRY;
  } else if (distance > THING_PERSONAL_SPACE_DISTANCE && distance < THING_SIGHT_DISTANCE) {
    return QUICK_LOOK;
  } else if (distance > THING_PERSONAL_SPACE_DISTANCE) {
    return CURIOUS_BUT_SHY;
  }

  return -1;
}

Mood* getCurrentMood(short moodIndex) {
  switch(moodIndex){

    case 2:
      return &curiousButShy;
    
    case 1:
      return &angry;
    
    case 0:
      return &quickLook;

    // -1 
    default:
      return &sleeping;
  }
}



void setup() {
  Serial.begin(9600);

  // The pin to use to let electricity flow to the motor
  pinMode(MOTOR_OUTPUT_PIN, OUTPUT);

  // Set up the distance sensor
  Wire.begin();
  if (!distanceSensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {
      delay(10);
    }
  }
}

void loop() {
  if (isMoodFinished) {
    delay(2000);
    currentMoodIndex = waitForMoodToTrigger();
    Serial.println("Chosen mood index");
    Serial.println(currentMoodIndex);
    if (currentMoodIndex < 0) {
      // If we didn't find a mood, we do nothing.
      delay(10);
      return;
    }
    isMoodFinished = false;
    return;
  }


  currentMood = getCurrentMood(currentMoodIndex);
  isMoodFinished = currentMood->interact();
}
