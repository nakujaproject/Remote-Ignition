#include <Arduino.h>

#include "global.h"
#include "relay.h"
#include "radio.h"
#include "getCommand.h"

void setup(){
  Serial.begin(9600);
  wifiSetup();
  setupRadio();
  setupServer();
}

void loop(){
  rx();
  // tx(getCommand());
}