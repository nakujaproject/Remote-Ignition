#include <Arduino.h>

String getCommand(){//get input from serial monitor for testing
  String command;
  while (Serial.available() != 0)
    command = Serial.readStringUntil('\n');
  Serial.println("Command is: "+command);
  return command.c_str();
}