#pragma once

#include "GlobalVars.h"
#include "Arduino.h"

class YFS201C_S {
public:
  void initialize();
  static void countInts();
  String getWaterSpeed();
  YFS201C_S();
private:
                                                
  float    varQ;
  double flow; //Water flow L/Min 
  int flowsensor = 2; 
  unsigned long currentTime;
  unsigned long lastTime;
  unsigned long pulse_freq;
  double lastFlow;
};
