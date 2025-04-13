#pragma once

#include <Wire.h>
#include <iarduino_Pressure_BMP.h>
#include "GlobalVars.h"
#include "Arduino.h"

class BMP_S {
public:
  String getBmpPressure();
  void initialize();
  BMP_S();
private:
  iarduino_Pressure_BMP bmp;
};
