#pragma once

#include <Wire.h>
#include <HMC5883L_Simple.h>
#include "Arduino.h"
#include "GlobalVars.h"

class HMC58831L_S {
public:
  void initialize();
  float getCompassHeading();
  HMC58831L_S();
private:
  HMC5883L_Simple Compass;
};
