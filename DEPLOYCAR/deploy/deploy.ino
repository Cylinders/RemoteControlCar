//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>




//create an RF24 object
RF24 radio(6, 7);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

// Pins used to control direction and speed of motor. Speed Pin should be pwm pin. 
// https://youtube.com/watch?v=JzRiqCpqcb0
// literally the only legible tutorial that I could find



#define MotorDirection 8
#define MotorSpeed 9



void setup()
{
  while (!Serial);
    Serial.begin(9600);
  
  radio.begin();
  
  //set the address
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  
  //Set module as receiver
  radio.startListening();
  pinMode(LED_BUILTIN, OUTPUT); 
}
String readRequest; 
void loop()
{
  //Read the data if available in buffer
  /*
  if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    readRequest = text;

    motorRun(readRequest.substring(0,3), readRequest.substring(7, 9)); 
  }
  */

  if (radio.available()) {
    char text[32] = {0}; 
    radio.read(&text, sizeof(text)); 
     
    
      Serial.println(text); 
      Serial.println("THIS IS THE PACKET");
    
  }
  else 
    Serial.println("FUCK PACKET GONE BYE BYE "); 

}

void motorRun(int speed, bool dir) {

	if (dir) {
		digitalWrite(MotorDirection, HIGH);
		analogWrite(MotorSpeed, speed);
	}
	
	else {
		digitalWrite(MotorDirection, LOW); 
		analogWrite(MotorSpeed, speed);
	}

}
// ALl existing modules have been copy and pasted from various websites; 

// definitely not a reliable long term solution to be entirely honest. 
