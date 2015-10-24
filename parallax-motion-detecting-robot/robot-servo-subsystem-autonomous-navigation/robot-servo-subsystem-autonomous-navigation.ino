//
// This is it, the show.  This subystem test has a complete
// runthrough of whiskers, servos, and navigation location.
//
#include <Servo.h>

//Motors
Servo motorLeft;
Servo motorRight;

//Motor board pin mounts
const int MOTOR_LEFT_PIN = 13;
const int MOTOR_RIGHT_PIN = 12;

//Whisker PIN binding
const int WHISKER_LEFT = 5;
const int WHISKER_RIGHT = 7;

//LED Whisker PIN binding
const int WHISKER_LEFT_LED = 8;
const int WHISKER_RIGHT_LED = 2;

//Directions (a hack around a typedef'd enum for this hobbled version of C)
const int CONTACT_BOTH = 1000;
const int CONTACT_LEFT = 1001;
const int CONTACT_RIGHT = 1002;
const int CONTACT_NONE = 1003;

//Whisker contact
const int WHISKER_CONTACT = 0;

void setup() {
  //bind whiskers
  pinMode(WHISKER_LEFT, INPUT);
  pinMode(WHISKER_RIGHT, INPUT);

  //bind whisker LED's
  pinMode(WHISKER_LEFT_LED, OUTPUT);
  pinMode(WHISKER_RIGHT_LED, OUTPUT);

  motorLeft.attach(MOTOR_LEFT_PIN);
  motorRight.attach(MOTOR_RIGHT_PIN);

  Serial.begin(9600);
}

void loop() {
  byte left_whisker_data = digitalRead(WHISKER_LEFT);
  byte right_whisker_data = digitalRead(WHISKER_RIGHT);

  int contact = determine_contact(left_whisker_data, right_whisker_data);
  navigate(contact);
}

int determine_contact(byte leftWhiskerInput, byte rightWhiskerInput){

  broadcast_whisker_state(leftWhiskerInput, WHISKER_LEFT_LED);
  broadcast_whisker_state(rightWhiskerInput, WHISKER_RIGHT_LED);

  Serial.print(leftWhiskerInput);
  Serial.print(rightWhiskerInput);

  if(leftWhiskerInput == WHISKER_CONTACT && rightWhiskerInput == WHISKER_CONTACT){
    return CONTACT_BOTH;
  }

  if(leftWhiskerInput == WHISKER_CONTACT && rightWhiskerInput != WHISKER_CONTACT){
    return CONTACT_LEFT;
  }

  if(rightWhiskerInput == WHISKER_CONTACT && leftWhiskerInput != WHISKER_CONTACT){
    return CONTACT_RIGHT;
  }

  return CONTACT_NONE;
}

void broadcast_whisker_state(byte whisker_state, int whisker_led_pin){
  int led_state = LOW;
  if(whisker_state == WHISKER_CONTACT){
    led_state = HIGH;
  }

  digitalWrite(whisker_led_pin, led_state);
}

void navigate(int contact){

  switch(contact){

    case CONTACT_BOTH :
      move_backward();
      turn_left();
      turn_left();
      break;

    case CONTACT_LEFT :
      move_backward();
      turn_right();
      break;

    case CONTACT_RIGHT :
      move_backward();
      turn_left();
      break;

    default:
      move_forward();
  }
}

void turn_right(){
  motorLeft.writeMicroseconds(1700);
  motorRight.writeMicroseconds(1700);
  delay(400);
}

void turn_left(){
  motorLeft.writeMicroseconds(1300);
  motorRight.writeMicroseconds(1300);
  delay(400);
}

void move_backward(){
  motorLeft.writeMicroseconds(1300);         
  motorRight.writeMicroseconds(1700);       
  delay(2000);
}

void move_forward(){
  motorLeft.writeMicroseconds(1700);
  motorRight.writeMicroseconds(1300);
  delay(20);
}
