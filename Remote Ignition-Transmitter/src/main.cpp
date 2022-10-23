// SimpleTx - the master or the transmitter

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define CE_PIN 9
#define CSN_PIN 10
#define BUTTON 7

const byte slaveAddress[5] = {'R', 'x', 'A', 'A', 'A'};
bool value;

RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

char dataToSend[10] = "Message 0";
char txNum = '0';

unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 1000; // send once per second

void setup()
{
    pinMode(BUTTON,INPUT);
    Serial.begin(9600);

    Serial.println("SimpleTx Starting");

    radio.begin();
    radio.setCRCLength(RF24_CRC_16);
    radio.setChannel(35);
    radio.setPALevel(RF24_PA_MAX);
    radio.setDataRate(RF24_250KBPS);
    radio.setRetries(3, 5); // delay, count
    radio.openWritingPipe(slaveAddress);
    
}



void loop()
{
    value = digitalRead(BUTTON);
    Serial.println(value);
    radio.write( &value, sizeof(value) );
    delay(10);


}


