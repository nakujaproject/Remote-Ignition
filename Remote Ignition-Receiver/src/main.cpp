// SimpleRx - the slave or the receiver

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define CE_PIN   9
#define CSN_PIN 10
#define LED 7

const byte thisSlaveAddress[5] = {'R','x','A','A','A'};
bool value;

RF24 radio(CE_PIN, CSN_PIN);

char dataReceived[10]; // this must match dataToSend in the TX
bool newData = false;

//===========

void setup() {

    Serial.begin(9600);
    pinMode(LED,OUTPUT);
    Serial.println("SimpleRx Starting");
    radio.begin();
    radio.setCRCLength(RF24_CRC_16);
    radio.setChannel(35);
    radio.setPALevel(RF24_PA_MAX);
    radio.setDataRate( RF24_250KBPS );
    radio.openReadingPipe(1, thisSlaveAddress);
    radio.startListening();
}




void loop() {
     if ( radio.available() ) {
        radio.read( &value, sizeof(value) );
        digitalWrite(LED,value);
    }
}

//==============


