
//Whisker PIN binding
const int WHISKER_LEFT = 5;
const int WHISKER_RIGHT = 7;

//LED -> Whisker PIN binding
const int WHISKER_LEFT_LED = 8;
const int WHISKER_RIGHT_LED = 2;

//byte read from chassis regarding whisker contact
const int WHISKER_CONTACT_MADE = 0;

void setup() {
  //bind the LED's
  pinMode(WHISKER_LEFT_LED, OUTPUT);
  pinMode(WHISKER_RIGHT_LED, OUTPUT);

  //bind the whiskers
  pinMode(WHISKER_LEFT, INPUT);
  pinMode(WHISKER_RIGHT, INPUT);
}

void loop() {

  //read whisker data
  byte left = digitalRead(WHISKER_LEFT);
  byte right = digitalRead(WHISKER_RIGHT);

  broadcast_whisker_state(left, WHISKER_LEFT_LED);
  broadcast_whisker_state(right, WHISKER_RIGHT_LED);

  delay(50);
}

void broadcast_whisker_state(byte whisker_state, int whisker_led_pin){
  int led_state = LOW;
  if(whisker_state == WHISKER_CONTACT_MADE){
    led_state = HIGH;
  }

  digitalWrite(whisker_led_pin, led_state);
}
