const int PRIMARY_LED_PIN = 13;

void setup() {
  pinMode(PRIMARY_LED_PIN, OUTPUT);
}

void loop() {
  
  digitalWrite(PRIMARY_LED_PIN, HIGH);
  delay(17);
  
  digitalWrite(PRIMARY_LED_PIN, LOW);
  delay(183);
}
