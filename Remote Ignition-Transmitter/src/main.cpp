#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include "hx7.h"
#include "radio.h"
#include "global.h"

void setup()
{
  Serial.begin(9600);
  setupHX711();
  setupRadio();
  
}
int count = 0;

void loop()
{
  count++;
  //Send message to receiver
  String payload = String(count)+","+String(getMass());
  debugln(payload);
  tx(payload);
}