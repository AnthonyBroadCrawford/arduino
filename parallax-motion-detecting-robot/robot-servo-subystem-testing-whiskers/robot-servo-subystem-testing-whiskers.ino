
//Whisker PIN binding
const int WHISKER_LEFT = 5;
const int WHISKER_RIGHT = 7;

void setup() {
  tone(4, 3000, 1000);        //burst sound to know we're alive (or reborn in case of a brown out)
  delay(1000);

  pinMode(WHISKER_RIGHT, INPUT);
  pinMode(WHISKER_LEFT, INPUT);

  Serial.begin(9600);
}

void loop() {

  byte left = digitalRead(WHISKER_LEFT);
  byte right = digitalRead(WHISKER_RIGHT);

  Serial.print(left);
  Serial.print(right);

  delay(1000);
}
