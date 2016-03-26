/*
  16 character 2 line I2C Display

  Get the LCD I2C Library here:
  https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
  original code from http://yourduino.com/
*/

#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 4);

void setup() {
  // Used to type in characters
  Serial.begin(9600);

  lcd.init();

  // blink effect on start
  for (int i = 0; i < 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
  }

  // set the blink cursor
  lcd.blink();
  lcd.backlight();

  // welcome message
  lcd.setCursor(0, 0); //Start at character 4 on line 0
  lcd.print("Hello!");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("Welcome");
  

  // Wait and then tell user they can start the Serial Monitor 
  // and type in characters to Display.
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Use Serial Mon");
  lcd.setCursor(0, 1);
  lcd.print("Type to display");
}

void loop() {
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    lcd.clear();

    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }
}



