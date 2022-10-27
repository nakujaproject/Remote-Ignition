// receives command via http then relays via nrf
#include <Arduino.h>
#include <WiFi.h>

#include "global.h"

WiFiServer server(80);
void setupServer(){
    server.begin();
}

String getCommand(){
  String command;
  if(DEBUG && false){//Get command from serial monitor if debugging
    while (Serial.available() != 0)
    command = Serial.readStringUntil('\n');
    debugln("Command is: "+command);
  }else{
    WiFiClient client = server.available();   // listen for incoming clients
    if(client){
    debugln("New Client.");
    while (client.connected()){
        String request;
        if(client.available()){ //receive client request
          request = client.readString();
          debugln(request);
        }
        String identifier = "Command: ";
        if(request.indexOf(identifier)>0){
          //extract actual command
          int charIndex = request.indexOf(identifier)+identifier.length();
          while(request.charAt(charIndex)!='\r'){
            command+=request.charAt(charIndex);
            charIndex++;
          }
          //send response
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/json");
          client.println();//end of header

          if(command=="Test")
            client.print("{\"Test\":\"Hello server\"}");

          client.println();//end of response
          break;
        }
      }
    }
  }
  return command.c_str();
}