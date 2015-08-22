#include <Servo.h>

//Breakboard pin mounts
const int LEFT_MOTOR_PIN = 13;
const int RIGHT_MOTOR_PIN = 12;

//Motor directions
const int FULL_SPEED_CLOCKWISE = 1300;
const int FULL_SPEED_COUNTERCLOCKWISE = 1700;
const int STAND_STILL = 1500;
const int SLOW_SPEED_CLOCKWISE = 1520;
const int SLOW_SPEED_COUNTERCLOCKWISE = 1480;

//Rotors (motors)
Servo rightMotor;
Servo leftMotor;

void setup() {
  rightMotor.attach(RIGHT_MOTOR_PIN);
  leftMotor.attach(LEFT_MOTOR_PIN);

  sub_system_test_rotate_then_stand_still();
}

void loop() {
}

void sub_system_test_rotate_then_stand_still(){
  leftMotor.writeMicroseconds(FULL_SPEED_CLOCKWISE);
  rightMotor.writeMicroseconds(FULL_SPEED_COUNTERCLOCKWISE);

  delay(3000); //three seconds

  leftMotor.writeMicroseconds(STAND_STILL);
  rightMotor.writeMicroseconds(STAND_STILL);
}

void sub_system_test_slow_rotation(){
  leftMotor.writeMicroseconds(SLOW_SPEED_CLOCKWISE);
  rightMotor.writeMicroseconds(SLOW_SPEED_COUNTERCLOCKWISE);
}

void sub_system_test_standard_rotation(){
  rightMotor.writeMicroseconds(FULL_SPEED_CLOCKWISE);
  leftMotor.writeMicroseconds(FULL_SPEED_COUNTERCLOCKWISE);

  delay(5000);

  rightMotor.writeMicroseconds(FULL_SPEED_COUNTERCLOCKWISE);
  leftMotor.writeMicroseconds(FULL_SPEED_CLOCKWISE);

  delay(5000);
}
