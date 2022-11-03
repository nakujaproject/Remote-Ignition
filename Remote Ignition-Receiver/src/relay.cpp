// relay.cpp -> sends data to server
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

#include "global.h"
#include "radio.h"

#define server_addr "192.168.100.12"
#define MSG_BUFFER_SIZE	(50)

const char* ssid     = "FABIAN";
const char* password = "Gisore@123";
char msg[MSG_BUFFER_SIZE];
int value = 0;
bool receiveFlag = false; //no message received

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    message+=(char)payload[i];
  }
  //commands received in message
  Serial.println(message);
  tx(message);//transmite received command over nrf

  receiveFlag=true;
}
void wifiSetup(){
    debugln();
    debugln();
    debug("Connecting to ");
    debugln(ssid);

    WiFi.begin(ssid, password);

    while(WiFi.status() != WL_CONNECTED){
      debug('.');
      delay(100);
    }

    if (WiFi.status() == WL_CONNECTED){
      debugln("");
      debugln("WiFi connected.");
      debugln("IP address: ");
      debugln(WiFi.localIP());
    }

    client.setServer(server_addr, 1883);
    client.setCallback(callback);
    client.subscribe("command");
}

void sendData(String payload){
  //Attempt connection
  String clientId = "ESP32";
  const char *topic = "thrust";
  client.publish(topic, payload.c_str());
}