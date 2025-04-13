#include "20240415.h"

void DM_S::initialize() {
  Serial.println("20240415 successfully connected!");
}

String DM_S::getTurbidity() {
  int sensorValue = analogRead(0);
  return String(map(sensorValue, 0, 750, 100, 0));
}

DM_S::DM_S() {
  pinMode(DM_PIN, INPUT);
}
