#include <Servo.h>

Servo claw;         // The Claw
Servo xAxis;        //
Servo yAxis;        //
Servo zAxis;        // Swivel Base
int angleValue = 0; // Initial Angle value to micro-servos
int clawCtrl = A0;  // Input to potenciometer to control the claw
int xAxisCtrl = A1; // 
int yAxisCtrl = A2; // 
int zAxisCtrl = A3; // 

void setup() {
  claw.attach(9);   // Setup the micro-servo in the port 9
  xAxis.attach(8);  //
  yAxis.attach(7);  //
  zAxis.attach(6);  //
}

void loop() {
  servoControl(claw, clawCtrl, 50, 90);
  servoControl(xAxis, xAxisCtrl, 10, 90);
  servoControl(yAxis, yAxisCtrl, 50, 178);
  servoControl(zAxis, zAxisCtrl, 0, 178);
}

void servoControl(Servo servo, int potenciometerCtrlPort, int angleMin, int angleMax) {
  angleValue = analogRead(potenciometerCtrlPort);     // Faz a leitura do valor do potenciômetro 
  angleValue = map(angleValue, 0, 1023, 0, 179);  // Associa o valor do potenciômetro ao valor do ângulo
  servo.write(angleValue);                        // Comando para posicionar o servo no ângulo especificado
  delay(5);
  
}
