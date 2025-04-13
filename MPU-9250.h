#pragma once

#include <MPU9250_WE.h>
#include <Wire.h>
#include "Arduino.h"
#include "GlobalVars.h"

class MPU9250_S {
public:
  xyzFloat getGyroValues();
  xyzFloat getAxelValues();
  String getMpuTemp();
  float getResultantAxel();
  void initialize();
  MPU9250_S();
private:
  MPU9250_WE myMPU9250;
};
