#include "quick_look.h" 

Servo servo;

QuickLook quickLook(&servo);

void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  quickLook.interact();
}
