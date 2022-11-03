#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include "global.h"

//create an RF24 object
RF24 radio(CE_PIN, CSN_PIN);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setupRadio(){
    radio.begin();
  
    //set the address
    radio.openWritingPipe(address);
    
    //Set module as transmitter
    radio.stopListening();
}

void tx(String payload){
    debug(".");
    radio.write(payload.c_str(), payload.length());
}