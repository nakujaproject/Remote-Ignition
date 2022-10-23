/**
 * @file relay.cpp
 * @author Paradox
 * @brief Relays data from nrf24 to a PC over WiFi
 * @version 0.1
 * @date 2022-10-23
 * 
 * @copyright MIT 2022
 * 
 */
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#define server_addr "192.168.100.18" //server address

bool runHTTPclient(String timestamp,String payload){
  const int    HTTP_PORT   = 5000;
  const String HTTP_METHOD = "GET"; // or "POST"
  const String PATH_NAME   = "";
  String queryString = "/gateway?time="+timestamp+"&payload="+payload;

  WiFiClient client;
  if(client.connect(server_addr, HTTP_PORT)) {
    Serial.println("Connected to server");
    // send HTTP request header
    client.println("GET " + PATH_NAME + queryString + " HTTP/1.1");
    client.println("Host: " + String(server_addr));
    client.println("Connection: close");
    client.println(); // end HTTP header
    return true;
  } else {
    Serial.println("HTTP connection failed");
    return false;
  }
}