/**
 *      Data Format - max 32bytes=32 char
 * uint32,float(1)...,float(n)
 * index, hx711_value\n
 */
#include <Arduino.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#include "sendCommand.h"

#define CE_PIN   9
#define CSN_PIN 10
#define LED 7

void setup() {
}

void loop() {
}
