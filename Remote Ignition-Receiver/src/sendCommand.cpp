// receives command via http then relays via nrf
#include <Arduino.h>

#include "global.h"

String getCommand(){
  String command;
  if(DEBUG){//Get command from serial monitor if debugging
    while (Serial.available() != 0)
    command = Serial.readStringUntil('\n');
    debugln("Command is: "+command);
  }else{}
  return command.c_str();
}