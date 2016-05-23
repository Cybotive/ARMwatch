#include <Adafruit_SSD1306ms.h>
//#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>
//#include <SPI.h>
//#include <GOFi2cOLED.h>
#include <Wire.h>
#define W WHITE
#define B BLACK
int rockX = 70;
int rockY = 30;
int paperX = 80;
int paperY = 15;
int szrX = 60;
int szrY = 5;
int walkX = 20;
int walkY = 40;



//GOFi2cOLED oled;
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  //display.init(0x3C);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  display.clearDisplay();
  rock(rockX, rockY, 0);
  paper2(paperX, paperY, 0, 0);
  szr(szrX, szrY, 0, 0);
  walk(walkX, walkY, 0);
  display.display();
  delay(200);

  rock(rockX, rockY, 0);
  paper2(paperX, paperY, 0, 1);
  szr(szrX, szrY, 0, 1);
  walk(walkX, walkY, 0);
  display.display();
  delay(200);
}

void walk(int x, int y, int color) {
  if (color == 0) {
    display.drawFastVLine(x + 3, y, 5, W);
    display.drawFastVLine(x + 7, y, 5, W);
    display.drawFastHLine(x + 3, y, 5, W);
    display.drawFastHLine(x + 3, y + 4, 5, W);
    display.drawPixel(x + 4, y + 2, W);
    display.drawPixel(x + 6, y + 2, W);
    display.drawPixel(x + 4, y + 5, W);
    display.drawPixel(x + 6, y + 5, W);
    display.drawFastHLine(x + 2, y + 6, 7, W);
    display.drawFastHLine(x + 2, y + 13, 7, W);
    display.drawFastVLine(x + 2, y + 6, 8, W);
    display.drawFastVLine(x + 8, y + 6, 8, W);
    display.drawFastVLine(x, y + 9, 4, W);
    display.drawPixel(x + 1, y + 9, W);
    display.drawFastVLine(x + 10, y + 9, 4, W);
    display.drawPixel(x + 9, y + 9, W);
    display.drawRect(x + 3, y + 14, 2, 4, W);
    display.drawRect(x + 6, y + 14, 2, 4, W);
  }
  if (color == 1) {
    display.drawFastVLine(x + 3, y, 5, B);
    display.drawFastVLine(x + 7, y, 5, B);
    display.drawFastHLine(x + 3, y, 5, B);
    display.drawFastHLine(x + 3, y + 4, 5, B);
    display.drawPixel(x + 4, y + 2, B);
    display.drawPixel(x + 6, y + 2, B);
    display.drawPixel(x + 4, y + 5, B);
    display.drawPixel(x + 6, y + 5, B);
    display.drawFastHLine(x + 2, y + 6, 7, B);
    display.drawFastHLine(x + 2, y + 13, 7, B);
    display.drawFastVLine(x + 2, y + 6, 8, B);
    display.drawFastVLine(x + 8, y + 6, 8, B);
    display.drawFastVLine(x, y + 9, 4, B);
    display.drawPixel(x + 1, y + 9, B);
    display.drawFastVLine(x + 10, y + 9, 4, B);
    display.drawPixel(x + 9, y + 9, B);
    display.drawRect(x + 3, y + 14, 2, 4, B);
    display.drawRect(x + 6, y + 14, 2, 4, B);
  }
}

void rock(int x, int y, int color) {
  display.drawFastHLine(x + 3, y, 2, W);
  display.drawFastHLine(x + 1, y + 1, 5, W);
  display.drawFastHLine(x, y + 2, 8, W);
  display.drawPixel(x + 6, y + 2, B);
  display.drawFastHLine(x, y + 3, 8, W);
  display.drawPixel(x + 5, y + 3, B);
  display.drawFastHLine(x, y + 4, 8, W);
  display.drawFastHLine(x + 1, y + 5, 7, W);
  display.drawFastHLine(x + 3, y + 6, 4, W);
  display.drawFastHLine(x + 4, y + 7, 2, W);
}

void paper(int x, int y, int color) {
  display.fillRect(x, y, 8, 8, B);
  display.drawPixel(x + 2, y + 1, B);
  display.drawPixel(x + 4, y + 1, B);
  display.drawPixel(x + 6, y + 1, B);
  display.drawPixel(x + 1, y + 2, B);
  display.drawPixel(x + 3, y + 2, B);
  display.drawPixel(x + 5, y + 2, B);
  display.drawPixel(x + 2, y + 4, B);
  display.drawPixel(x + 4, y + 4, B);
  display.drawPixel(x + 6, y + 4, B);
  display.drawPixel(x + 1, y + 5, B);
  display.drawPixel(x + 3, y + 5, B);
  display.drawPixel(x + 5, y + 5, B);
}

void paper2(int x, int y, int color, int stage) {
  if (stage == 0) {
    display.fillRect(x, y, 8, 8, B);
    display.drawFastHLine(x, y, 7, W);
    display.drawFastHLine(x, y + 1, 7, W);
    display.drawFastHLine(x + 1, y + 2, 7, W);
    display.drawFastHLine(x + 1, y + 3, 7, W);
    display.drawFastHLine(x + 1, y + 4, 7, W);
    display.drawFastHLine(x, y + 5, 8, W);
    display.drawFastHLine(x, y + 6, 7, W);
    display.drawFastHLine(x, y + 7, 6, W);
    display.drawPixel(x + 3, y + 1, B);
    display.drawPixel(x + 5, y + 1, B);
    display.drawPixel(x + 2, y + 2, B);
    display.drawPixel(x + 4, y + 2, B);
    display.drawPixel(x + 3, y + 4, B);
    display.drawPixel(x + 5, y + 4, B);
    display.drawPixel(x + 2, y + 5, B);
    display.drawPixel(x + 4, y + 5, B);
  }
  if (stage == 1) {
    display.fillRect(x, y, 8, 8, B);
    display.drawFastHLine(x, y, 7, W);
    display.drawFastHLine(x, y + 1, 7, W);
    display.drawFastHLine(x + 1, y + 2, 7, W);
    display.drawFastHLine(x + 1, y + 3, 7, W);
    display.drawFastHLine(x + 1, y + 4, 7, W);
    display.drawFastHLine(x + 1, y + 5, 7, W);
    display.drawFastHLine(x + 1, y + 6, 7, W);
    display.drawFastHLine(x + 2, y + 7, 6, W);
    display.drawPixel(x + 3, y + 1, B);
    display.drawPixel(x + 5, y + 1, B);
    display.drawPixel(x + 2, y + 2, B);
    display.drawPixel(x + 4, y + 2, B);
    display.drawPixel(x + 3, y + 4, B);
    display.drawPixel(x + 5, y + 4, B);
    display.drawPixel(x + 2, y + 5, B);
    display.drawPixel(x + 4, y + 5, B);
  }
}

void szr(int x, int y, int color, int stage) {
  if (stage == 0) {
    display.fillRect(x, y, 8, 8, B);
    display.drawFastHLine(x + 6, y, 2, W);
    display.drawFastHLine(x + 5, y + 1, 2, W);
    display.drawFastHLine(x + 4, y + 2, 2, W);
    display.drawFastHLine(x + 2, y + 3, 2, W);
    display.drawFastHLine(x + 3, y + 4, 2, W);
    display.drawFastHLine(x + 4, y + 5, 2, W);
    display.drawFastHLine(x + 5, y + 6, 2, W);
    display.drawFastHLine(x + 6, y + 7, 2, W);
    display.drawRect(x, y, 3, 3, W);
    display.drawRect(x, y + 5, 3, 3, W);
  }
  if (stage == 1) {
    display.fillRect(x, y, 8, 8, B);
    display.drawRect(x, y, 3, 3, W);
    display.drawRect(x, y + 4, 3, 3, W);
    display.drawPixel(x + 2, y + 4, B);
    display.drawFastHLine(x + 2, y + 3, 2, W);
    display.drawFastHLine(x + 4, y + 2, 4, W);
    display.drawFastHLine(x + 3, y + 4, 5, W);
  }
}
