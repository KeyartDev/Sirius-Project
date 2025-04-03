#pragma once

#include <Wire.h>
#include "variables.h"

int mill = 0;

String getCarbonDyoxide() {
  if ((millis() - mill) >= 2000) {
    Wire.beginTransmission(CJMCU_811_ADDRESS);
    Wire.write(0x02);
    Wire.endTransmission();
    Wire.requestFrom(CJMCU_811_ADDRESS, 4);
    if (Wire.available() == 4); {
      int co2High = Wire.read();
      int co2Low = Wire.read();
      mill = millis();
      return String((co2High << 8) + co2Low);
    }
  }
}

namespace cjmcu811 {
  void init() {
    pinMode(2, OUTPUT); 
    digitalWrite(2, LOW);
  }
}

