// IMPORT STATEMENTS
#include <Servo.h> 

// ANALOG PINS
int xPin = A1; 
int yPin = A0; 
// DIGITAL PINS 
int bPin = 6; 
int servoPin = 4; 
Servo steeringServoMotor; 
void setup() {
  pinMode(xPin, INPUT); 
  pinMode(yPin, INPUT); 
  pinMode(bPin, INPUT); 
  Serial.begin(9600);
  steeringServoMotor.attach(servoPin);
  
}
String returnVal = "";
void loop() {  
  returnVal = ""; 
  returnVal = returnVal + String(analogRead(xPin)) + ",";
  returnVal = returnVal + String(analogRead(yPin)) + ",";
  returnVal = returnVal + String(digitalRead(bPin)) + ",";
  Serial.println(returnVal); 
  
}
