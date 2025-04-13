#include "YF-S201C.h"

uint16_t varF=0; 

void YFS201C_S::initialize() {
  attachInterrupt(digitalPinToInterrupt(YFS201C_PIN), countInts, RISING); 
  varQ=0; varF=0;
  Serial.println("YF-S201C successfully connected!");
}

void YFS201C_S::countInts() {
  varF++;
}

String YFS201C_S::getWaterSpeed() {
  currentTime = millis();
  // Every second, calculate and print L/Min
  if(currentTime >= (lastTime + 1000))
  {
     lastTime = currentTime; 
     // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
     flow = (varF / 7.5); 
     varF = 0; // Reset Counter
      
     return String(flow); 
  } else {
    return String(lastFlow);
  }
}

YFS201C_S::YFS201C_S() {
  pinMode(YFS201C_PIN, INPUT);
}
