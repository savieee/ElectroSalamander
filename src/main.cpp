#include <Arduino.h>
#include <Servo.h>

Servo servo;

int servoPin = 9;

void setup()
{
  servo.attach(servoPin);

}

void loop()
{
  servo.write(0);
  delay(1000);

  servo.write(90);
  delay(1000);

  servo.write(0);
  delay(1000);


}