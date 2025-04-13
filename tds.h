#pragma once

#include "GlobalVars.h"
#include "Arduino.h"

class TDS_S {
public:
  void initialize();
  String getTDSData();
  TDS_S();
private:
  const double VREF = 5.0;
  int analogBuffer[30];     
  int analogBufferTemp[30];
  int analogBufferIndex = 0;
  int copyIndex = 0;
    
  float averageVoltage = 0;
  float tdsValue = 0;
  float temperature = 16;

  int getMedianNum(int bArray[], int iFilterLen);
  
  
};
