//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";



// Change these depending on what pins are used for what in the actual RC CAR

int joystickInputX = A0;

int joystickInputY = A0;

// The button input should be wired to a digital pin, not an analog pin. 

int joystickInputB = 0; 


int sensorReadX; 
int sensorReadY; 
bool sensorReadB; 





void setup()
{
  radio.begin();
	

  pinmode(joystickInputX, INPUT);y
  
  pinmode(joystickInputY, INPUT);y
  
  pinmode(joystickInputB, INPUT);y
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
}

String postRequest;  

void loop()
{
  sensorReadX = analogRead(joystickInputX)

  sensorReadY = analogRead(joystickInputX)

  sensorReadB = digitalRead(joystickInputX)

  postRequest = String(sensorReadX) + ";" + String(sensorReadY) + ";" + String(sensorReadB); 

  //Send message to receiver
  radio.write(&postRequest, postRequest.length());
  
  delay(100);
}
