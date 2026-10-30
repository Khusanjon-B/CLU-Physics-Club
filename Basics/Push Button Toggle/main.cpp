const int BUTTON_PIN = 2;
const int LED_PIN = 13;

bool ledState = LOW;
int lastButtonState = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // LOW when pressed, HIGH when released
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int currentReading = digitalRead(BUTTON_PIN);

  // Detect falling edge (transition from unpressed HIGH to pressed LOW)
  if (lastButtonState == HIGH && currentReading == LOW) {
    ledState = !ledState;               // Toggle state
    digitalWrite(LED_PIN, ledState);
    delay(50);                          // Simple software debounce delay
  }

  lastButtonState = currentReading;
}