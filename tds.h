#pragma once

#include "variables.h"

int analogBuffer[SCOUNT];     
int analogBufferTemp[SCOUNT];
int analogBufferIndex = 0;
int copyIndex = 0;

float averageVoltage = 0;
float tdsValue = 0;
float temperature = 16;

int getMedianNum(int bArray[], int iFilterLen){
  int bTab[iFilterLen];
  for (byte i = 0; i<iFilterLen; i++)
  bTab[i] = bArray[i];
  int i, j, bTemp;
  for (j = 0; j < iFilterLen - 1; j++) {
    for (i = 0; i < iFilterLen - j - 1; i++) {
      if (bTab[i] > bTab[i + 1]) {
        bTemp = bTab[i];
        bTab[i] = bTab[i + 1];
        bTab[i + 1] = bTemp;
      }
    }
  }
  if ((iFilterLen & 1) > 0){
    bTemp = bTab[(iFilterLen - 1) / 2];
  }
  else {
    bTemp = (bTab[iFilterLen / 2] + bTab[iFilterLen / 2 - 1]) / 2;
  }
  return bTemp;
}

String getTDSData() {
  static unsigned long analogSampleTimepoint = millis();
     
  analogSampleTimepoint = millis();
  analogBuffer[analogBufferIndex] = analogRead(TdsSensorPin);    
  analogBufferIndex++;
  if(analogBufferIndex == SCOUNT){ 
    analogBufferIndex = 0;
  }
     
  
  static unsigned long printTimepoint = millis();
  
    
  for(copyIndex=0; copyIndex<SCOUNT; copyIndex++){
    analogBufferTemp[copyIndex] = analogBuffer[copyIndex];
      
      // read the analog value more stable by the median filtering algorithm, and convert to voltage value
    averageVoltage = getMedianNum(analogBufferTemp,SCOUNT) * (float)VREF / 1024.0;
      
      //temperature compensation formula: fFinalResult(25^C) = fFinalResult(current)/(1.0+0.02*(fTP-25.0)); 
    float compensationCoefficient = 1.0+0.02*(temperature-25.0);
      //temperature compensation
    float compensationVoltage=averageVoltage/compensationCoefficient;
      
      //convert voltage value to tds value
    tdsValue=(133.42*compensationVoltage*compensationVoltage*compensationVoltage - 255.86*compensationVoltage*compensationVoltage + 857.39*compensationVoltage)*0.5;
    
    return String(tdsValue);
  }
} 


namespace tds {
  void init() {
    pinMode(TdsSensorPin,INPUT);
  }
}

