#include <Arduino.h>

const int BUZZER_PIN = 8; // Use const for fixed pins to save memory
const int BUTTON_PIN = 2;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // Invert the button reading since LOW means pressed
  digitalWrite(BUZZER_PIN, !digitalRead(BUTTON_PIN)); 
}
f