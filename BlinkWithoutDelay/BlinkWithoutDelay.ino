/* Blink without Delay

 Turns on and off a light emitting diode (LED) connected to a digital
 pin, without using the delay() function.  This means that other code
 can run at the same time without being interrupted by the LED code.

 The circuit:
 * LED attached from pin 13 to ground.
 * Note: on most Arduinos, there is already an LED on the board
 that's attached to pin 13, so no hardware is needed for this example.

 created 2005
 by David A. Mellis
 modified 8 Feb 2010
 by Paul Stoffregen
 modified 11 Nov 2013
 by Scott Fitzgerald
 modified 6 Mar 2016
 by @alismed

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */


const int ledPin =  13;
int ledState = LOW;                // ledState used to set the LED
unsigned long previousMillis = 0;  // will store last time LED was updated
const int interval = 500;          // interval at which to blink (milliseconds)

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    // changed the previousMillis = currentMillis to previousMillis += interval
    previousMillis += interval;

    // if the LED is off turn it on and vice-versa:
    ledState = !ledState;

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}


