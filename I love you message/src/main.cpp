// Define Arduino pins for segments A through G
const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;
const int pinG = 8;

// Set true if Common Anode, false if Common Cathode
const bool commonAnode = true; 

void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
}

void loop() {
  // Test by turning on segments A, B, C, D, E, F, G one by one
  segmentOn(pinA); delay(500);
  segmentOn(pinB); delay(500);
  segmentOn(pinC); delay(500);
  segmentOn(pinD); delay(500);
  segmentOn(pinE); delay(500);
  segmentOn(pinF); delay(500);
  segmentOn(pinG); delay(500);
  
  // Display the number '8'
  digitalWrite(pinA, !commonAnode);
  digitalWrite(pinB, !commonAnode);
  digitalWrite(pinC, !commonAnode);
  digitalWrite(pinD, !commonAnode);
  digitalWrite(pinE, !commonAnode);
  digitalWrite(pinF, !commonAnode);
  digitalWrite(pinG, !commonAnode);
  delay(2000);

  // Turn all segments off
  digitalWrite(pinA, commonAnode);
  digitalWrite(pinB, commonAnode);
  digitalWrite(pinC, commonAnode);
  digitalWrite(pinD, commonAnode);
  digitalWrite(pinE, commonAnode);
  digitalWrite(pinF, commonAnode);
  digitalWrite(pinG, commonAnode);
  delay(1000);
}

void segmentOn(int pin) {
  // Turns on a single segment safely based on display type
  digitalWrite(pin, !commonAnode);
  delay(500);
  digitalWrite(pin, commonAnode);
}
