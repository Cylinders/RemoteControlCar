// Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>


// create an RF24 object
RF24 radio(9, 8); // CE, CSN


// create a servo object

Servo steeringServoMotor;

// address through which two modules communicate.
const byte address[6] = "00001";
// what pin is pwm and what pin is dir. 
int pwm; 
int dir; 


// STEERING PIN : PWM DIGITAL OUTPUT;
int steeringPin;



void setup()
{
  while (!Serial)
    ;
  Serial.begin(9600);

  radio.begin();

  // set the address
  radio.openReadingPipe(0, address);

  // Set module as receiver
  radio.startListening();
  steeringServoMotor.start(steeringPin);
}
String readRequest;
int pushSpeed; 
int steeringAngle; 
int pwmRecieve; 

void loop()
{
  // Read the data if available in buffer
  if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    readRequest = text;
  }
  digitalWrite(pwm,HIGH);		// always set PWM to HIGH

   		//fast to slow, slow to stop, stop to slow, slow to fast
   analogWrite(dir,i);
   delay(500);
   Serial.println(i);

   

   while(1) continue;        //avoid loop
}

// ALl existing modules have been copy and pasted from various websites;

// definitely not a reliable long term solution to be entirely honest.



/*
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
*/
