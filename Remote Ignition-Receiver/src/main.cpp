#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define EEPROM_SIZE 1

int PRE_IGNITION = 0;
int COUNTDOWN = 1;
int IGNITED = 2;
int STATE;

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup(){
    Serial.begin(9600);
    
    radio.begin();

    //#############################
    radio.openReadingPipe(0, address);
    radio.startListening();
    delay(1500); 
    if(radio.available()){
        STATE = COUNTDOWN;
    }else{
        STATE = PRE_IGNITION;
    }
    radio.closeReadingPipe(0);
    //#############################

    //Set module as transmitter before ignition
    radio.openWritingPipe(address);
    radio.stopListening();
}

void loop(){
    if(STATE==PRE_IGNITION){
        String command;
        while (Serial.available() != 0)
            command = Serial.readStringUntil('\n');
        Serial.println("Command is: "+command);
        radio.write(command.c_str(), command.length());
        if (command=="ignite")
            STATE=COUNTDOWN;
    }

    if(STATE==COUNTDOWN){
        radio.openReadingPipe(0, address);
        radio.startListening();//change nrf to receiving mode
        STATE=IGNITED;
    }

    if(STATE==IGNITED){
        //Read the data if available in buffer
        if (radio.available()){
            char text[32] = {0};
            radio.read(&text, sizeof(text));
            Serial.println(text);
        }
    }
}