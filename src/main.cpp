#include <Arduino.h>

int airvalvePin = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(airvalvePin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(airvalvePin, LOW);
  delay(4000);
  Serial.print("Analog sensor value: Low ");
  digitalWrite(airvalvePin, HIGH);
  delay(4000);
  Serial.print("Analog sensor value: High ");

}

