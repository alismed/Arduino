/*
   original code from http://www.instructables.com/id/PacMan-and-custom-characters-on-Arduino-with-a-16x
   use http://mikeyancey.com/hamcalc/lcd_characters.php to write characteres
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// set the LCD address to 0x27(Cooperate with 3 short circuit caps) for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

int backlightState = LOW;
long previousMillis = 0;
long interval = 1000;
int x = 0;
int y = 0;
int px = 0;
int py = 0;

// make some custom characters:

byte pac1Def[8] = {
  B00000,
  B01110,
  B11011,
  B11111,
  B11111,
  B01110,
  B00000,
  B00000
};
byte pac2Def[8] = {
  B00000,
  B01110,
  B10100,
  B11000,
  B11100,
  B01110,
  B00000,
  B00000
};
byte pillDef[8] = {
  B00000,
  B00000,
  B00000,
  B01100,
  B01100,
  B00000,
  B00000,
  B00000
};

const byte pac1 = 0x0;
const byte pac2 = 0x1;
const byte pill = 0x2;
const int del = 250;

void setup() {
  // initialize the lcd
  lcd.init();
  lcd.backlight();

  lcd.home();

  // create a new character
  lcd.createChar(0, pac1Def);
  // create a new character
  lcd.createChar(1, pac2Def);
  // create a new character
  lcd.createChar(2, pillDef);
  // set up the lcd's number of columns and rows:

  lcd.begin(16, 2);
  // fill the display
  fill();
}

void loop() {
  anim();
  x++;
  if (x > 15 && y == 0)
  {
    x = 0;
    y = 1;
  }
  else if (x > 15 && y == 1)
  {
    x = 0;
    y = 0;
    fill();
  }
}

