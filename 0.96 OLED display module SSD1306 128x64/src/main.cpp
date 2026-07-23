#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ==============================
// Function Prototypes
// ==============================
void showGreeting();
void showLoadingAnimation();
void showLogo();
void showFocusScreen();
void showBreakScreen();
void showIdleScreen();

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed!");
    while (1);
  }

  showGreeting();
  showLoadingAnimation();
  showLogo();
  showFocusScreen();
  showBreakScreen();
  showIdleScreen();
}

void loop() {
  // Nothing yet
}

// ==============================
// Greeting Screen
// ==============================
void showGreeting() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.setTextWrap(false);
  display.setCursor(47, 17);
  display.print("Hi!");

  display.setTextSize(1);
  display.setCursor(23, 39);
  display.print("Sir, Jhon Paul");

  display.display();
  delay(2000);
}

// ==============================
// Loading Animation
// ==============================
void showLoadingAnimation() {

  for (int dots = 1; dots <= 9; dots++) {

    display.clearDisplay();

    display.setTextColor(SSD1306_WHITE);

    display.setCursor(4, 5);
    display.print("Hello Sir Jhon Paul");

    display.setCursor(2, 28);
    display.print("WELCOME BACK ON TRACK");

    display.setCursor(4, 52);
    display.print("Loading");

    for (int i = 0; i < dots; i++) {
      display.print(".");
    }

    display.display();
    delay(200);
  }

  display.print(" done");
  display.display();

  delay(1500);
}

// ==============================
// Logo Screen
// ==============================
void showLogo() {

  display.clearDisplay();

  display.drawRect(17, 13, 91, 43, SSD1306_WHITE);

  display.setCursor(21, 22);
  display.print("Smart Study AI");

  display.setCursor(43, 38);
  display.print("Platform");

  display.display();

  delay(5000);
}

// ==============================
// Focus Screen
// ==============================
void showFocusScreen() {

  display.clearDisplay();

  display.drawRect(2, 1, 123, 62, SSD1306_WHITE);

  display.setCursor(6, 5);
  display.print("Focus Mode:");

  display.setCursor(6, 24);
  display.print("Time: 24:53");

  display.setCursor(6, 34);
  display.print("Session: 3");

  display.setCursor(5, 53);
  display.print("Studying...");

  display.display();

  delay(5000);
}

// ==============================
// Break Screen
// ==============================
void showBreakScreen() {

  display.clearDisplay();
    // rect 1
    display.drawRect(1, 1, 124, 62, 1);
    // string 2
    display.setTextColor(1);
    display.setTextWrap(false);
    display.setCursor(4, 5);
    display.print("Break Time");
    // string 3
    display.setCursor(14, 29);
    display.print("05:00");
    // string 4
    display.setCursor(4, 52);
    display.print("Stretch a little");
    // circle 5
    display.drawCircle(7, 32, 4, 1);
    display.display();
    delay(5000);
}

void showIdleScreen() {

  display.clearDisplay();

  display.drawRect(1, 1, 124, 62, SSD1306_WHITE);

  display.setCursor(4, 5);
  display.print("Idle Mode");

  display.setCursor(5, 29);
  display.print("No Motion Detected");

  display.setCursor(4, 52);
  display.print("Lights still ON?");

  display.display();

  delay(5000);
}