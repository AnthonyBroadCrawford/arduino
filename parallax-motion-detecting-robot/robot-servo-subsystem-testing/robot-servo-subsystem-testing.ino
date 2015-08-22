#include <Servo.h>

//Breakboard pin mounts
const int LEFT_MOTOR_PIN = 13;
const int RIGHT_MOTOR_PIN = 12;

//Motor directions
const int FULL_SPEED_CLOCKWISE = 1300;
const int FULL_SPEED_COUNTERCLOCKWISE = 1700;

//Rotors (motors)
Servo rightMotor;
Servo leftMotor;

void setup() {
  rightMotor.attach(RIGHT_MOTOR_PIN);
  leftMotor.attach(LEFT_MOTOR_PIN);
}

void loop() {
  rightMotor.writeMicroseconds(FULL_SPEED_CLOCKWISE);
  leftMotor.writeMicroseconds(FULL_SPEED_COUNTERCLOCKWISE);
  
  delay(5000);
  
  rightMotor.writeMicroseconds(FULL_SPEED_COUNTERCLOCKWISE);
  leftMotor.writeMicroseconds(FULL_SPEED_CLOCKWISE);
  
  delay(5000);
  
  rightMotor.writeMicroseconds(FULL_SPEED_CLOCKWISE);
  leftMotor.writeMicroseconds(FULL_SPEED_CLOCKWISE);

}
