#include <Arduino.h>
#include "sender.h"
#include "receiver.h"

void setup() {
  Serial.begin(115200)
  setupSender();
  setupReceiver();
}

void loop() {
  // put your main code here, to run repeatedly:
}