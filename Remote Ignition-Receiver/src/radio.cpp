#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include "relay.h"
#include "global.h"

//create an RF24 object
RF24 radio(4, 5);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setupRadio(){
    radio.begin();
    //set the address
    radio.openReadingPipe(0, address);
    //Set module as receiver
    radio.startListening();
}
void tx(){}
void rx(){
    //Read the data if available in buffer
    if (radio.available()){
        char text[32] = {0};
        radio.read(&text, sizeof(text));
        sendData(text);
        debugln(text);
    }
}