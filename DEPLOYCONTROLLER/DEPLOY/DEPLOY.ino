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







void setup()
{
  radio.begin();


  pinMode(joystickInputX, INPUT);

  pinMode(joystickInputY, INPUT);

  pinMode(joystickInputB, INPUT);

  //set the address
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);

  radio.setDataRate(RF24_250KBPS);
  //Set module as transmitter
  radio.stopListening();
}

String postRequest;
String sensorReadX;
String sensorReadY;
bool sensorReadB;


void loop()
{
  /*
    sensorReadX = String(analogRead(joystickInputX));

    sensorReadY = String(analogRead(joystickInputX));

    sensorReadB = digitalRead(joystickInputX);

    switch (sizeof(sensorReadX)) {

    case 1:

  	sensorReadX = "00" + sensorReadX;
  	break;

    case 2:

  	sensorReadX = "0" + sensorReadX;
  	break;

    case 3:

  	sensorReadX = sensorReadX;

    }




    switch (sizeof(sensorReadY)) {

    case 1:

  	sensorReadY = "00" + sensorReadY;
  	break;

    case 2:

  	sensorReadX = "0" + sensorReadY;
  	break;

    case 3:

  	sensorReadY = sensorReadY;

    }


    postRequest = sensorReadX + ";" + sensorReadY + ";" + String(sensorReadB);
    postRequest = "HELLO HELLO";

  */
  const char balls[] = "Anu fat";
  radio.write(&balls, sizeof(balls));
  //Send message to receiver
  delay(1000);
}
