#pragma once

#include "GlobalVars.h"
#include "Arduino.h"

class Holl_S {
public:
  void initialize();
  String getWindSpeed();
  static void onSwitch();
  Holl_S();
private:
  
};
