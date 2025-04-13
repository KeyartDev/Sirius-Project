#pragma once

#include <iarduino_DHT.h>
#include "GlobalVars.h"
#include "Arduino.h"

class DHT11_S {
public:
  String gethumidity();
  void initialize();
  DHT11_S();
private:
  iarduino_DHT sensor;
};
