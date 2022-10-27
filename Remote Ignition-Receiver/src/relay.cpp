// relay.cpp -> sends data to server
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>

#include "global.h"

#define server_addr "192.168.100.12"

const char* ssid     = "FABIAN";
const char* password = "Gisore@123";

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
}

void sendData(String payload){
  const int    HTTP_PORT   = 5000;
  const String HTTP_METHOD = "GET"; // or "POST"
  const String PATH_NAME   = "";
  String queryString = "/gateway?payload="+payload;

  WiFiClient client;
  if(client.connect(server_addr, HTTP_PORT)) {
    debugln("Connected to server");
    // send HTTP request header
    client.println("GET " + PATH_NAME + queryString + " HTTP/1.1");
    client.println("Host: " + String(server_addr));
    client.println("Connection: close");
    client.println(); // end HTTP header
  } else {
    debugln("HTTP connection failed");
  }
}