#include "PH.h"

void PH_S::initialize() {
  Serial.println("PH successfuly connected!");
}

String PH_S::getPH() {
  analogData=analogRead(PH_PIN);
  delay(30);
 
  avgval=0;
  for(int i=2;i<8;i++)
  avgval=analogData;
  float volt=(float)avgval*5.0/1024/6;
  float ph_act = -5.70 * volt + calibration_value;

  return String(ph_act);
}

PH_S::PH_S() {
  pinMode(PH_PIN, INPUT);
}
