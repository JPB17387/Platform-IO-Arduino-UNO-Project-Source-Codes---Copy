#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed!");
    while (1);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Hello, Jhon Paul");
  display.display();

  delay(3000);

  display.clearDisplay();
    // rect 1
    display.drawRect(17, 13, 91, 43, 1);
    // string 2
    display.setTextColor(1);
    display.setTextWrap(false);
    display.setCursor(21, 22);
    display.print("Smart Study AI ");
    // string 3
    display.setCursor(43, 38);
    display.print("Chatbot");
    display.display();

    delay(5000);

    display.clearDisplay();
    // rect 1
    display.drawRect(2, 1, 123, 62, 1);
    // string 2
    display.setTextColor(1);
    display.setTextWrap(false);
    display.setCursor(6, 5);
    display.print("Focus Mode:");
    // string 3
    display.setCursor(6, 24);
    display.print("Time: 24:53");
    // string 4
    display.setCursor(6, 34);
    display.print("Session: 3");
    // string 5
    display.setCursor(5, 53);
    display.print("Studying........");
    display.display();

    delay(5000);

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

    display.clearDisplay();
    // rect 1
    display.drawRect(1, 1, 124, 62, 1);
    // string 2
    display.setTextColor(1);
    display.setTextWrap(false);
    display.setCursor(4, 5);
    display.print("Idle Mode");
    // string 3
    display.setCursor(5, 29);
    display.print("No Motion Detected");
    // string 4
    display.setCursor(4, 52);
    display.print("Lights still ON?");
    display.display();
}

void loop() {} 