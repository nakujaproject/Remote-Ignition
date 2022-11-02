#include <Arduino.h>

#define DEBUG 1

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif

//Pins
#define CE_PIN 9
#define CSN_PIN 10
const int DT_PIN = 2;
const int SCK_PIN = 3;