#include "CJMCU-811.h"

void CJMCU811_S::initialize() {
  Serial.println("CJMCU-811 successfully connected!");
}

String CJMCU811_S::getCarbonDyoxide() {
  if ((millis() - mill) >= 2000) {
    Wire.beginTransmission(CJMCU811_ADDRESS);
    Wire.write(0x02);
    Wire.endTransmission();
    Wire.requestFrom(CJMCU811_ADDRESS, 4);
    if (Wire.available() == 4); {
      int co2High = Wire.read();
      int co2Low = Wire.read();
      mill = millis();
      lastData = String((co2High << 8) + co2Low);
      return String((co2High << 8) + co2Low);
    }
  } else {
    return lastData;
  }
}

CJMCU811_S::CJMCU811_S() {
  pinMode(CJMCU811_PIN, INPUT);
}
