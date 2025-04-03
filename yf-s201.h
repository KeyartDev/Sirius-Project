#pragma once

#include "variables.h"

uint16_t varF=0;                                               
float    varQ;
double flow; //Water flow L/Min 
int flowsensor = 2; 
unsigned long currentTime;
unsigned long lastTime;
unsigned long pulse_freq;

void countInts() {varF++;}

String getWaterSpeed() {
  currentTime = millis();
   // Every second, calculate and print L/Min
   if(currentTime >= (lastTime + 1000))
   {
      lastTime = currentTime; 
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      flow = (varF / 7.5); 
      varF = 0; // Reset Counter
      
      return String(flow);
      
   }
}

namespace yfs201 {
  void init() {
    attachInterrupt(digitalPinToInterrupt(YFS201_PIN), countInts, RISING); 
    varQ=0; varF=0;
  }
}

