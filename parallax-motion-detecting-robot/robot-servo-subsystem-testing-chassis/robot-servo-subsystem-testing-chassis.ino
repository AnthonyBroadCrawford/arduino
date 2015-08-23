#include <Servo.h>

//Servo board pin mounts
const int SERVO_BOARD_LEFT_MOTOR_PIN = 13;
const int SERVO_BOARD_RIGHT_MOTOR_PIN = 12;

//Bread board pin mounts
const int PRIMAYRY_LED_PIN = 12;
const int SECONDARY_LED_PIN = 13;

//Motor instructions
const int CLOCKWISE_ROTATION = 1300;
const int STOP_ALL_MOTION = 1500;
const int COUNTERCLOCKWISE_ROTATION = 1700;

//Motors
Servo rightMotor;
Servo leftMotor;

void setup() {

  rightMotor.attach(SERVO_BOARD_RIGHT_MOTOR_PIN);
  leftMotor.attach(SERVO_BOARD_LEFT_MOTOR_PIN);

  clockwise_rotation(rightMotor, 3000);
  halt_all_rotation(rightMotor, 1000);
  counterclockwise_rotation(rightMotor, 3000);
  halt_all_rotation(rightMotor, 1000);

  clockwise_rotation(leftMotor, 3000);
  halt_all_rotation(leftMotor, 1000);
  counterclockwise_rotation(leftMotor, 3000);
  halt_all_rotation(leftMotor, 1000);
}

void clockwise_rotation(Servo motor, int duration){
  execute_motor_instruction(motor, CLOCKWISE_ROTATION, duration);
}

void counterclockwise_rotation(Servo motor, int duration){
  execute_motor_instruction(motor, COUNTERCLOCKWISE_ROTATION, duration);
}

void halt_all_rotation(Servo motor, int duration){
  execute_motor_instruction(motor, STOP_ALL_MOTION, duration);
}

void execute_motor_instruction(Servo motor, int instruction, int duration){
  motor.writeMicroseconds(instruction);
  delay(duration);
}

void loop() {
  // put your main code here, to run repeatedly:
}
