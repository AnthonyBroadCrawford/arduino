#include <Servo.h>

const int PRIMARY_PIN = 13;                            //At the time of this sketch a red LED is attached to this pin.
const int SECONDARY_PIN = 12;                          //At the time of this sketch a red LED is attached to this pin.

//Servo motor instructions
const int STAY_STILL_SERVO_MOTOR_INSTRUCTION = 1500;   //1.5 ms "stay still" signal

Servo servoLeft;
Servo servoRight;

void setup() {
  servoLeft.attach(PRIMARY_PIN);
  servoRight.attach(SECONDARY_PIN);

  servoLeft.writeMicroseconds(STAY_STILL_SERVO_MOTOR_INSTRUCTION);
  servoRight.writeMicroseconds(STAY_STILL_SERVO_MOTOR_INSTRUCTION);

}
void loop() {
  // put your main code here, to run repeatedly:

}
