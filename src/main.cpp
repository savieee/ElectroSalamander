#include <Arduino.h>
#include <Servo.h>

Servo servo_FR;
Servo servo_FL;

Servo servo_BR;
Servo servo_BL;

int efforts = 0;

int servoPin_FR = 5;
int servoPin_FL = 6;
int servoPin_BR = 10;
int servoPin_BL = 11;

void setup()
{
  servo_FR.attach(servoPin_FR);
  servo_FL.attach(servoPin_FL);
  servo_BR.attach(servoPin_BR);
  servo_BL.attach(servoPin_BL);
}

void loop()
{

  servo_FR.write(efforts);
  delay(1000);

  
  servo_FL.write(efforts);
  delay(1000);

  servo_BR.write(efforts);
  delay(1000);

  
  servo_BL.write(efforts);
  delay(1000);

}

