#pragma once

#include "GlobalVars.h"
#include "Arduino.h"

class DM_S {
public:
  String getTurbidity();
  void initialize();
  DM_S();
private:
};
