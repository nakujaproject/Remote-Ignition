#include <Arduino.h>

#include "global.h"
#include "relay.h"
#include "radio.h"

void setup(){
  Serial.begin(9600);
  wifiSetup();
  setupRadio();
}

void loop(){
  rx();
}