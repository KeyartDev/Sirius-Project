#pragma once

#include <Wire.h>
#include <iarduino_Pressure_BMP.h>
#include "variables.h"

//iarduino_Pressure_BMP sensor;
iarduino_Pressure_BMP bmp;

String getBMPPressure() {
  if (bmp.read(2)) {
    return bmp.pressure == 0 ? String(bmp.pressure) : ERR;
  } else {
    return ERR;
  }
}

namespace bmp180 {
  void init() {
    bmp.begin(&Wire);
    delay(200);
  }
}

