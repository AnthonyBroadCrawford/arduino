const int PRIMAYRY_LED_PIN = 13;
const int SECONDARY_LED_PIN = 12;
const int TIMING = 500;

void setup() {
  pinMode(PRIMAYRY_LED_PIN, OUTPUT);
  pinMode(SECONDARY_LED_PIN, OUTPUT);
}

void loop() {

  digitalWrite(PRIMAYRY_LED_PIN, HIGH);
  digitalWrite(SECONDARY_LED_PIN, LOW);
  delay(TIMING);
  digitalWrite(PRIMAYRY_LED_PIN, LOW);
  digitalWrite(SECONDARY_LED_PIN, HIGH);
  delay(TIMING);
}
