/***********************************************************************************

   Original code from
   http://learn.robotgeek.com/robotgeek-101-1/233-servo-primer.html

   Important Functions
    servo.attach()
    servo.write()
    servo.detach()
 *****************************************************************************************/
#include <Servo.h>

const int SERVO_MIN_PULSE = 600;
const int SERVO_MAX_PULSE = 2400;
const int SERVO_CENTER_PULSE = 1500;
const int SERVO_PIN = 9;
const int BUTTON_PIN_STOP = 2;
const int BUTTON_PIN_START = 3;

int servoValue = SERVO_MIN_PULSE;
// value to increment/decrement the servo by
int servoIncrement = 100;
Servo servo1;

void setup() {
  pinMode(BUTTON_PIN_STOP, INPUT);
  pinMode(BUTTON_PIN_START, INPUT);
  
  // attach the servo on pin SERVO_PIN
  attachServo();

  // send the servo to '0' degrees
  servo1.writeMicroseconds(servoValue);
  // wait for the servo to move before moving again
  delay(1500);
}

void loop() {
  servo1.writeMicroseconds(servoValue);     //send the servo to '0' degrees
  servoValue = servoValue + servoIncrement; //update servo value for next loop

  // if the servo is out of bounds,
  if (servoValue <= SERVO_MIN_PULSE || servoValue >= SERVO_MAX_PULSE) {
    // reverse the increment
    servoIncrement = -1 * servoIncrement;
  }

  delay(50);  //wait for the servo to move

  // check if the button has been pressed
  if (digitalRead(BUTTON_PIN_STOP) == HIGH) {
    // detach the servo - this will stop it from receiving commands and turn its torque off.
    servo1.detach();
  }

  // check if the button has been pressed
  if (digitalRead(BUTTON_PIN_START) == HIGH) {
    // attach the servo
    attachServo();
  }
}

void attachServo() {
  servo1.attach(SERVO_PIN);
}

