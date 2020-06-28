//Define constants
const int sensorPin = A0;
const float baselineTemp = 28.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   // open a serial port with communication rate of 9600bits/sec 

  // Set all LEDs to OFF and OUTPUT
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
      pinMode(pinNumber, OUTPUT);
      digitalWrite(pinNumber, LOW);
   }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  // convert analog signal from temperature sensor into voltage
  float voltage = (sensorVal / 1024.0) * 5.0;   // Unit: volts
  Serial.print(", Volts: ");
  Serial.print(voltage);

  // convert voltage into temperature. Offset at 0V = -50C. Every +10mV = +1C
  float temperature = (voltage - 0.5) * 100;    // Unit: degree C
  Serial.print(", degrees C: ");
  Serial.println(temperature);

  if (temperature < baselineTemp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW); 
   }
   else if (temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
   }
   else if (temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
   }
   else {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH); 
   }

  // Delay for analog-to-digital converter reading correctly
   delay(1);
}
