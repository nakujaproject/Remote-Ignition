#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include "hx7.h"
#include "global.h"

int PRE_IGNITION = 0;
int COUNTDOWN = 1;
int IGNITED = 2;
int STATE;


//create an RF24 object
RF24 radio(CE_PIN, CSN_PIN);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";


void setup()
{
  STATE = PRE_IGNITION; //set state to preigntion during setup
  Serial.begin(9600);
  setupHX711();

  //Setup radio
  radio.begin();
  //set the address
  radio.openReadingPipe(0, address);
  //Set module as transmitter before ignition
  radio.startListening();
}

int count = 0;

void loop()
{
  if(STATE==PRE_IGNITION){
    //Read the data if available in buffer
    if (radio.available()){
      char text[32] = {0};
      radio.read(&text, sizeof(text));
      Serial.println(text);
     String operand = "ignite";
      if(String(text)==operand){
        Serial.println("Changing to countdown");
        STATE=COUNTDOWN;
      }
        
    }
  }

  if(STATE==COUNTDOWN){
    radio.openWritingPipe(address);
    radio.stopListening();//change nrf to tansmiting mode
    int seconds=20;//countdown set to 10 seconds
    String countdown = "countdown,";
    for (int i = 0; i < seconds*2; i++){
      delay(500);
      radio.write((countdown+String(i)).c_str(),(countdown+String(i)).length());
      Serial.println(i);
    }
      
    digitalWrite(7,HIGH);//turn relay on
    delay(5000);
    digitalWrite(7,LOW);
    STATE=IGNITED;
  }

  if(STATE==IGNITED){
    count++;
    //Send message to receiver
    String payload = String(count)+","+String(getMass());
    debugln(payload); 
    radio.write(payload.c_str(), payload.length());
  }
}