#pragma once

#include "variables.h"

String getTurbidity() {
  int sensorValue = analogRead(DATCHIK_MUTNOSTI_PIN);
  return String(map(sensorValue, 0, 750, 100, 0));
}

