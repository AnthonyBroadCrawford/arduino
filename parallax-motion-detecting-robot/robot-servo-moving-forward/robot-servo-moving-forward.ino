#include <Servo.h>

//Servo board pin mounts
const int SERVO_BOARD_LEFT_MOTOR_PIN = 13;
const int SERVO_BOARD_RIGHT_MOTOR_PIN = 12;

//Motor instructions
const int FULL_SPEED_CLOCKWISE = 1300;
const int HALT = 1500;
const int FULL_SPEED_COUNTERCLOCKWISE = 1700;

//Motors
Servo rightMotor;
Servo leftMotor;

void setup() {
  say_hello();

  leftMotor.attach(SERVO_BOARD_LEFT_MOTOR_PIN);
  rightMotor.attach(SERVO_BOARD_RIGHT_MOTOR_PIN);

  //Move fullspeed ahead
  counterclockwise(leftMotor);
  clockwise(rightMotor);
  delay(8000);

  halt(leftMotor);
  halt(rightMotor);
  delay(2000);

  leftMotor.detach();
  rightMotor.detach();
}

void halt(Servo motor){
  execute_motor_instruction(motor, HALT);
}

void counterclockwise(Servo motor){
  execute_motor_instruction(motor, FULL_SPEED_COUNTERCLOCKWISE);
}

void clockwise(Servo motor){
  execute_motor_instruction(motor, FULL_SPEED_CLOCKWISE);
}

void execute_motor_instruction(Servo motor, int instruction){
  motor.writeMicroseconds(instruction);
}

void say_hello(){
  tone(4, 2000, 2000);
}

void loop() {}
