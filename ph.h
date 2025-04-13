#pragma once

#include <Wire.h>
#include "GlobalVars.h"
#include "Arduino.h"

class PH_S {
public:
  void initialize();
  String getPH();
  PH_S();
private:
  float calibration_value = 21.34+10.68;
  int phval = 0; 
  unsigned long int avgval; 
  int buffer_arr[10],temp,analogData;
};
