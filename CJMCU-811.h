#pragma once

#include <Wire.h>
#include "GlobalVars.h"
#include "Arduino.h"

class CJMCU811_S {
public:
  String getCarbonDyoxide();
  void initialize();
  CJMCU811_S();
private:
  int mill=0;
  String lastData="0";
};
