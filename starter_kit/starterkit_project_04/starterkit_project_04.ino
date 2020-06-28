// Set the PINs to use for the LEDS
const int greenLEDpin = 9;
const int redLEDpin = 10;
const int blueLEDpin = 11;

// Set which captors is linked to which PIN
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;


void setup() {
  Serial.begin(9600);

  pinMode(greenLEDpin, OUTPUT);
  pinMode(redLEDpin, OUTPUT);
  pinMode(blueLEDpin, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  Serial.print("Raw Sensor Values \t red: ");
  Serial.print(redSensorValue);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t blue: ");
  Serial.println(blueSensorValue);

  redValue = redSensorValue / 4;
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;

  Serial.print("Mapped Sensor Values \t red: ");
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue: ");
  Serial.println(blueValue);

  analogWrite(greenLEDpin, greenValue);
  analogWrite(redLEDpin, redValue);
  analogWrite(blueLEDpin, blueValue);


}
