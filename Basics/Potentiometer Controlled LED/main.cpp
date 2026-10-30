const int POT_PIN = A0;  // ADC pin
const int LED_PIN = 9;   // PWM capable pin

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  // ADC pins are inputs by default in Arduino C++
}

void loop() {
  // Read 10-bit ADC value (0 to 1023)
  int potValue = analogRead(POT_PIN);

  // Map 10-bit ADC (0-1023) to 8-bit PWM duty cycle (0-255)
  int brightness = map(potValue, 0, 1023, 0, 255);

  // Write PWM signal to LED
  analogWrite(LED_PIN, brightness);

  // Debug output
  Serial.print("Raw: ");
  Serial.print(potValue);
  Serial.print("\t Brightness: ");
  Serial.println(brightness);

  delay(50); // Small stability pause
}