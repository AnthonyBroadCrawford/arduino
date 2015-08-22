#include <Servo.h>

const int RIGHT_MOTOR = 12;
const int INSTRUCTION_MOTOR_STAY_STILL = 1500;

Servo servoRight;

void setup() {
  servoRight.attach(RIGHT_MOTOR);
  servoRight.writeMicroseconds(INSTRUCTION_MOTOR_STAY_STILL);
}

void loop() {
  // put your main code here, to run repeatedly:

}
