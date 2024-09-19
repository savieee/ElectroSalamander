#include <Arduino.h>
#include <Servo.h>

// Declare servo objects for each leg
Servo servo_FR;  // Front Right leg
Servo servo_FL;  // Front Left leg
Servo servo_BR;  // Back Right leg
Servo servo_BL;  // Back Left leg

// Pin assignments for each servo
int servoPin_FR = 5;
int servoPin_FL = 6;
int servoPin_BR = 10;
int servoPin_BL = 11;

// Variables to store the positions of the servos (in degrees)
int restPosition = 90;    // Resting position (middle, leg down)
int liftPosition = 45;    // Lifted position (leg raised)
int stepPosition = 135;   // Step forward position

// Movement speed (smaller values for smoother movement)
int movementDelay = 500;

void setup()
{
  // Attach the servos to the assigned pins
  servo_FR.attach(servoPin_FR);
  servo_FL.attach(servoPin_FL);
  servo_BR.attach(servoPin_BR);
  servo_BL.attach(servoPin_BL);

  // Set all servos to the resting position at startup
  servo_FR.write(restPosition);
  servo_FL.write(restPosition);
  servo_BR.write(restPosition);
  servo_BL.write(restPosition);

  delay(2000); // Small delay before starting
}

void loop()
{
  // Step 1: Move Front Left (FL) and Back Right (BR) legs together (diagonal pair)
  servo_FL.write(liftPosition);  // Lift the front left leg
  servo_BR.write(liftPosition);  // Lift the back right leg
  delay(movementDelay);          // Wait for the legs to lift

  servo_FL.write(stepPosition);  // Move front left leg forward
  servo_BR.write(stepPosition);  // Move back right leg forward
  delay(movementDelay);          // Wait for the legs to step

  servo_FL.write(restPosition);  // Return front left leg to resting position
  servo_BR.write(restPosition);  // Return back right leg to resting position
  delay(movementDelay);          // Stabilize the robot

  // Step 2: Move Front Right (FR) and Back Left (BL) legs together (diagonal pair)
  servo_FR.write(liftPosition);  // Lift the front right leg
  servo_BL.write(liftPosition);  // Lift the back left leg
  delay(movementDelay);          // Wait for the legs to lift

  servo_FR.write(stepPosition);  // Move front right leg forward
  servo_BL.write(stepPosition);  // Move back left leg forward
  delay(movementDelay);          // Wait for the legs to step

  servo_FR.write(restPosition);  // Return front right leg to resting position
  servo_BL.write(restPosition);  // Return back left leg to resting position
  delay(movementDelay);          // Stabilize the robot

  // Repeat the cycle to simulate walking
}
