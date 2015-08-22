//
// Challenges found at http://learn.parallax.com/node/190
//
#include <Servo.h>

//Servo board pin mounts
const int SERVO_BOARD_LEFT_MOTOR_PIN = 13;
const int SERVO_BOARD_RIGHT_MOTOR_PIN = 12;

//Bread board pin mounts
const int PRIMAYRY_LED_PIN = 12;
const int SECONDARY_LED_PIN = 13;

//Motor instructions
const int MOTOR_INSTRUCTION_FULL_SPEED_CLOCKWISE = 1300;
const int MOTOR_INSTRUCTION_STAND_STILL = 1500;
const int MOTOR_INSTRUCTION_FULL_SPEED_COUNTERCLOCKWISE = 1700;

//Motors
Servo leftMotor;
Servo rightMotor;


void setup() {
  leftMotor.attach(SERVO_BOARD_LEFT_MOTOR_PIN);
  rightMotor.attach(SERVO_BOARD_RIGHT_MOTOR_PIN);


  challenge_multi_direction_motors_multi_times();
}

void loop() {
  // put your main code here, to run repeatedly:
}

//
//Write a loop function that makes an LED blink 5 times per second, with an on time that’s 1/3rd of its off time.
//(Disconnect the servos for this exercise!)
//
void challenge_one_led_manipulation(){

}


//
//Write a setup function that makes the pin 13 servo turn full speed clockwise for 1.2 seconds, while the pin 12
//servo stays still.  After that, set both servos to stop.
//
void challenge_multi_direction_motors(){
  leftMotor.writeMicroseconds(MOTOR_INSTRUCTION_FULL_SPEED_CLOCKWISE);
  rightMotor.writeMicroseconds(MOTOR_INSTRUCTION_STAND_STILL);
  delay(1200);

  leftMotor.writeMicroseconds(MOTOR_INSTRUCTION_STAND_STILL);
  rightMotor.writeMicroseconds(MOTOR_INSTRUCTION_STAND_STILL);
}


//
//Write a setup function that makes one servo turn the same direction for 3 seconds.
//The other servo should turn the opposite direction for the first 1.5 seconds and the
//same direction for the second 1.5 seconds.  Then, make both servos stop.
//
void challenge_multi_direction_motors_multi_times(){
  leftMotor.writeMicroseconds(MOTOR_INSTRUCTION_FULL_SPEED_CLOCKWISE);

  rightMotor.writeMicroseconds(MOTOR_INSTRUCTION_FULL_SPEED_COUNTERCLOCKWISE);
  delay(1500);
  rightMotor.writeMicroseconds(MOTOR_INSTRUCTION_FULL_SPEED_CLOCKWISE);
  delay(1500);

  leftMotor.writeMicroseconds(MOTOR_INSTRUCTION_STAND_STILL);
  rightMotor.writeMicroseconds(MOTOR_INSTRUCTION_STAND_STILL);
}
