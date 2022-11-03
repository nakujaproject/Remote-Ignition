#include <Arduino.h>
// https://github.com/bogde/HX711
#include <HX711.h>

#include "global.h"

HX711 scale;
//TO DO
//set reference and offseet
void setupHX711() {
    float unit = -4452.50;
    float reference_i = 210.0;
    float deviation = 3.40;
    scale.begin(DT_PIN, SCK_PIN);
    debugln(scale.get_units(10));

    scale.set_scale(unit/reference_i); //set reference units
    debugln(scale.get_units(10));
    scale.tare();
    debugln(scale.get_units(10));

    //scale.set_offset(deviation); //definition of offset?

    debugln(scale.get_units(10));
    debugln("here");
}


float getMass() {
  return scale.get_units(1);
}